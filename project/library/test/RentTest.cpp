#include <boost/test/unit_test.hpp>
#include <boost/date_time.hpp>
#include "model/Rent.h"
#include "model/Vehicles/Car.h"
#include "model/ClientTypes/Default.h"
#include "typyedefs.h"


namespace pt = boost::posix_time;
namespace gr = boost::gregorian;

struct TestSuiteRentFixture {
    unsigned int testId;
    ClientPtr testClient;
    VehiclePtr testVehicle;
    unsigned int testRentCost = 0;    

    pt::ptime testStartTime = pt::ptime (gr::date(2020,10,2),pt::minutes(10));

 TestSuiteRentFixture() {
    testClient = std::make_shared<Client>("Jonasz","Pudzianowski",151413, std::make_shared<Address>("warszawa","smolna","22"),std::make_shared<Default>());
    testVehicle = std::make_shared<Car>("WZY1514",20,1600,Segment(D));
 }

 ~TestSuiteRentFixture() {
 }

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRent,TestSuiteRentFixture)

    BOOST_AUTO_TEST_CASE(ParameterConstrutorTestDefaultBeginTime) {

        RentPtr r = std::make_shared<Rent>(testId, testClient, testVehicle, pt::not_a_date_time);

        pt::ptime now = pt::second_clock::local_time(); //hope this takes no longer than 59 secs...
        BOOST_TEST_REQUIRE(!r->getBeginTime().is_not_a_date_time()); //if this isn't met, the next check doesn't make sense...
        pt::time_period skew = pt::time_period(r->getBeginTime(), now);
        BOOST_TEST((skew.length().hours()==0 && skew.length().minutes()==0));
    }
    
    BOOST_AUTO_TEST_CASE(ParameterConstrutorTestSpecificBeginTime) {

        RentPtr r = std::make_shared<Rent>(testId, testClient, testVehicle, testStartTime);

        BOOST_TEST(r->getBeginTime()==testStartTime);
    
    }

    BOOST_AUTO_TEST_CASE(EndRentTestBasic) {
        RentPtr r = std::make_shared<Rent>(testId,testClient, testVehicle, testStartTime);
        r->endRent(pt::not_a_date_time);
        BOOST_TEST(r->getEndTime() == pt::second_clock::local_time());
    }

    BOOST_AUTO_TEST_CASE(EndRentTestSetCurrentTime) {
        RentPtr r = std::make_shared<Rent>(testId,testClient, testVehicle, testStartTime);
        r->endRent(pt::second_clock::local_time());
        BOOST_TEST(r->getEndTime() == pt::second_clock::local_time());
    }

    BOOST_AUTO_TEST_CASE(EndRentTestSetGivenEndTimeAfterBeginTime) {
        RentPtr r = std::make_shared<Rent>(testId,testClient, testVehicle, testStartTime);
        pt::ptime endTime = pt::ptime ( gr::date(2020,10,10),pt::hours(12));
        r->endRent(endTime);
        BOOST_TEST(r->getEndTime() == endTime);
    }

    BOOST_AUTO_TEST_CASE(EndRentTestSetGivenEndTimeEqualsBeginTime) {
        RentPtr r = std::make_shared<Rent>(testId,testClient, testVehicle, testStartTime);
        r->endRent(testStartTime);
        BOOST_TEST(r->getEndTime() == testStartTime);
    }
    BOOST_AUTO_TEST_CASE(EndRentTestSetGivenEndTimeBeforeBeginTime) {
        RentPtr r = std::make_shared<Rent>(testId,testClient, testVehicle, testStartTime);
        r->endRent(testStartTime - pt::minutes(20));
        BOOST_TEST(r->getEndTime() == r->getBeginTime());
    }
    BOOST_AUTO_TEST_CASE(RentDaysTestRentNotEnded) { 
        RentPtr rent = std::make_shared<Rent>(testId,testClient, testVehicle, testStartTime);
        BOOST_TEST(rent->getRentDays() == 0);
    }
    BOOST_AUTO_TEST_CASE(RentDaysTestRentEndedWithinMinute) {
        RentPtr rent = std::make_shared<Rent>(testId,testClient, testVehicle, testStartTime);
        rent->endRent(testStartTime + pt::seconds(60));
        BOOST_TEST(rent->getRentDays() == 0); 
    }

    BOOST_AUTO_TEST_CASE(RentDaysTestRentEndedAfter1m) {
        RentPtr rent = std::make_shared<Rent>(testId,testClient, testVehicle, testStartTime);
        rent->endRent(testStartTime + pt::seconds(80));
        BOOST_TEST(rent->getRentDays() == 1);  
    }
    BOOST_AUTO_TEST_CASE(RentDaysTestRentEndedAfter23h59m) { 
        RentPtr rent = std::make_shared<Rent>(testId,testClient, testVehicle, testStartTime);
        rent->endRent(testStartTime + pt::minutes(59) + pt::hours(23));
        BOOST_TEST(rent->getRentDays() == 1);  
    }
    BOOST_AUTO_TEST_CASE(RentDaysTestRentEndedAfter24h0m) {
        RentPtr rent = std::make_shared<Rent>(testId,testClient, testVehicle, testStartTime);
        rent->endRent(testStartTime + pt::hours(24));
        BOOST_TEST(rent->getRentDays() == 2);   
    }

    BOOST_AUTO_TEST_CASE(RentDaysTestRentTryEndRentAlreadyEnded) {
        RentPtr rent = std::make_shared<Rent>(testId,testClient, testVehicle, testStartTime);
        rent->endRent(testStartTime);
        rent->endRent(testStartTime + pt::hours(700));
        BOOST_TEST(rent->getRentDays() == 0);       
    }

    BOOST_AUTO_TEST_CASE(RentCostTestRentDaysIs0) {
        RentPtr rent = std::make_shared<Rent>(testId,testClient, testVehicle, testStartTime);
        rent->endRent(testStartTime);
        BOOST_TEST_REQUIRE(rent->getRentDays() == 0);        
        BOOST_TEST(rent->getRentCost() == 0);
    }
    BOOST_AUTO_TEST_CASE(RentCostTestRentDaysIsPositive) {
        RentPtr rent = std::make_shared<Rent>(testId,testClient, testVehicle, testStartTime);
        rent->endRent(testStartTime + pt::hours(24));
        BOOST_TEST(rent->getVehicle()->getBasePrice() * rent->getRentDays() == rent->getRentCost()) ;
    }

    BOOST_AUTO_TEST_CASE(RentCostTestRentCostIsPermanentWhenVehiclePriceChanged) {
        RentPtr rent = std::make_shared<Rent>(testId,testClient, testVehicle, testStartTime);
        rent->endRent(testStartTime + pt::hours(24));
        unsigned int newPrice = rent->getVehicle()->getBasePrice() + 900;
        unsigned int oldPrice = rent->getVehicle()->getBasePrice();
        rent->getVehicle()->setBasePrice(newPrice); 
        
        BOOST_TEST(oldPrice * rent->getRentDays() == rent->getRentCost()) ;
    }


BOOST_AUTO_TEST_SUITE_END()