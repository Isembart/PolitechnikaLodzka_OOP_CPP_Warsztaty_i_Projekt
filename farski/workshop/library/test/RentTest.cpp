#include <boost/test/unit_test.hpp>
#include <boost/date_time.hpp>
#include "model/Rent.h"

namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

struct TestSuiteRentFixture {
    unsigned int testId;
    Client* testClient;
    Vehicle* testVehicle;
    unsigned int testRentCost = 0;    

    pt::ptime testStartTime = pt::ptime (gr::date(2020,10,2),pt::minutes(10));

 TestSuiteRentFixture() {
    testClient = new Client("Jonasz","Pudzianowski",151413,new Address("warszawa","smolna","22"));
    testVehicle = new Vehicle("WZY1514",20);
 }

 ~TestSuiteRentFixture() {
    delete testClient;
    delete testVehicle;
 }

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRent,TestSuiteRentFixture)

    BOOST_AUTO_TEST_CASE(ParameterConstrutorTestDefaultBeginTime) {

        Rent* r = new Rent(testId, testClient, testVehicle, pt::not_a_date_time);

        pt::ptime now = pt::second_clock::local_time(); //hope this takes no longer than 59 secs...
        BOOST_TEST_REQUIRE(!r->getBeginTime().is_not_a_date_time()); //if this isn't met, the next check doesn't make sense...
        pt::time_period skew = pt::time_period(r->getBeginTime(), now);
        BOOST_TEST((skew.length().hours()==0 && skew.length().minutes()==0));

        delete r;
    }
    
    BOOST_AUTO_TEST_CASE(ParameterConstrutorTestSpecificBeginTime) {

        Rent* r = new Rent(testId, testClient, testVehicle, testStartTime);

        BOOST_TEST(r->getBeginTime()==testStartTime);

        delete r;
    }

    BOOST_AUTO_TEST_CASE(EndRentTestBasic) {
        Rent* rent = new Rent(testId,testClient, testVehicle, testStartTime);
        rent->endRent(pt::not_a_date_time);
        BOOST_TEST(rent->getEndTime() == pt::second_clock::local_time());
        delete rent;
    }

    BOOST_AUTO_TEST_CASE(EndRentTestSetCurrentTime) {
        Rent* rent = new Rent(testId,testClient, testVehicle, testStartTime);
        rent->endRent(pt::second_clock::local_time());
        BOOST_TEST(rent->getEndTime() == pt::second_clock::local_time());
        delete rent;
    }

    BOOST_AUTO_TEST_CASE(EndRentTestSetGivenEndTimeAfterBeginTime) {
        Rent* rent = new Rent(testId,testClient, testVehicle, testStartTime);
        pt::ptime endTime = pt::ptime ( gr::date(2020,10,10),pt::hours(12));
        rent->endRent(endTime);
        BOOST_TEST(rent->getEndTime() == endTime);
        delete rent;
    }

    BOOST_AUTO_TEST_CASE(EndRentTestSetGivenEndTimeEqualsBeginTime) {
        Rent* rent = new Rent(testId,testClient, testVehicle, testStartTime);
        rent->endRent(testStartTime);
        BOOST_TEST(rent->getEndTime() == testStartTime);
        delete rent;
    }
    BOOST_AUTO_TEST_CASE(EndRentTestSetGivenEndTimeBeforeBeginTime) {
        Rent* rent = new Rent(testId,testClient, testVehicle, testStartTime);
        rent->endRent(testStartTime - pt::minutes(20));
        BOOST_TEST(rent->getEndTime() == rent->getBeginTime());
        delete rent; 
    }
    BOOST_AUTO_TEST_CASE(RentDaysTestRentNotEnded) { 
        Rent* rent = new Rent(testId,testClient, testVehicle, testStartTime);
        BOOST_TEST(rent->getRentDays() == 0);
    }
    BOOST_AUTO_TEST_CASE(RentDaysTestRentEndedWithinMinute) {
        Rent* rent = new Rent(testId,testClient, testVehicle, testStartTime);
        rent->endRent(testStartTime + pt::seconds(60));
        BOOST_TEST(rent->getRentDays() == 0); 
    }

    BOOST_AUTO_TEST_CASE(RentDaysTestRentEndedAfter1m) {
        Rent* rent = new Rent(testId,testClient, testVehicle, testStartTime);
        rent->endRent(testStartTime + pt::seconds(80));
        BOOST_TEST(rent->getRentDays() == 1);  
    }
    BOOST_AUTO_TEST_CASE(RentDaysTestRentEndedAfter23h59m) { 
        Rent* rent = new Rent(testId,testClient, testVehicle, testStartTime);
        rent->endRent(testStartTime + pt::minutes(59) + pt::hours(23));
        BOOST_TEST(rent->getRentDays() == 1);  
    }
    BOOST_AUTO_TEST_CASE(RentDaysTestRentEndedAfter24h0m) {
        Rent* rent = new Rent(testId,testClient, testVehicle, testStartTime);
        rent->endRent(testStartTime + pt::hours(24));
        BOOST_TEST(rent->getRentDays() == 2);   
    }

    BOOST_AUTO_TEST_CASE(RentDaysTestRentTryEndRentAlreadyEnded) {
        Rent* rent = new Rent(testId,testClient, testVehicle, testStartTime);
        rent->endRent(testStartTime);
        rent->endRent(testStartTime + pt::hours(700));
        BOOST_TEST(rent->getRentDays() == 0);       
    }

    BOOST_AUTO_TEST_CASE(RentCostTestRentDaysIs0) {
        Rent* rent = new Rent(testId,testClient, testVehicle, testStartTime);
        rent->endRent(testStartTime);
        BOOST_TEST_REQUIRE(rent->getRentDays() == 0);        
        BOOST_TEST(rent->getRentCost() == 0);
    }
    BOOST_AUTO_TEST_CASE(RentCostTestRentDaysIsPositive) {
        Rent* rent = new Rent(testId,testClient, testVehicle, testStartTime);
        rent->endRent(testStartTime + pt::hours(24));
        BOOST_TEST(rent->getVehicle()->getBasePrice() * rent->getRentDays() == rent->getRentCost()) ;
    }

    BOOST_AUTO_TEST_CASE(RentCostTestRentCostIsPermanentWhenVehiclePriceChanged) {
        Rent* rent = new Rent(testId,testClient, testVehicle, testStartTime);
        rent->endRent(testStartTime + pt::hours(24));
        unsigned int newPrice = rent->getVehicle()->getBasePrice() + 900;
        unsigned int oldPrice = rent->getVehicle()->getBasePrice();
        rent->getVehicle()->setBasePrice(newPrice); 
        
        BOOST_TEST(oldPrice * rent->getRentDays() == rent->getRentCost()) ;
    }


BOOST_AUTO_TEST_SUITE_END()