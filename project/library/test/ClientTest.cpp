#include <boost/test/unit_test.hpp>
#include "model/Client.hpp"
#include "model/ClientTypes/Default.hpp"
#include <memory>
struct TestSuiteClientFixture {
 const std::string testFirstName = "Mariusz";
 const std::string testLastName = "Pudzianowski";
 const int testPersonalID = 151413;

 TestSuiteClientFixture() {
 }

 ~TestSuiteClientFixture() {
 }

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteClient, TestSuiteClientFixture)
//BOOST_AUTO_TEST_SUITE(TestSuiteClient)

    // BOOST_AUTO_TEST_CASE(AssertionsTests) {
    //     BOOST_TEST(1.0/3.0==0.333,boost::test_tools::tolerance(0.002));
    //     BOOST_TEST(true);
    // }

    BOOST_AUTO_TEST_CASE(GettersTests) {
        Client client1(testFirstName,testLastName,testPersonalID,std::make_shared<Default>());
        //Testy getterów | _REQUIRE daltego że jeśli gettery nie działają to testy setterów korzystające z nich i tak nie będą wiarygodne
        BOOST_TEST_REQUIRE(client1.getFirstName() == testFirstName);
        BOOST_TEST_REQUIRE(client1.getLastName() == testLastName);
        BOOST_TEST_REQUIRE(client1.getPersonalID() == testPersonalID);
    }

    BOOST_AUTO_TEST_CASE(SettersTests) {
        Client client1(testFirstName,testLastName,testPersonalID,std::make_shared<Default>());
        //Testy setFirstName
        client1.setFirstName("Jonasz");
        BOOST_TEST(client1.getFirstName()=="Jonasz");
        client1.setFirstName("");
        BOOST_TEST(client1.getFirstName()=="Jonasz");

        //Testy setLastName
        client1.setLastName("josephson");
        BOOST_TEST(client1.getLastName()=="josephson");
        client1.setLastName("");
        BOOST_TEST(client1.getLastName()=="josephson");
    }


BOOST_AUTO_TEST_SUITE_END()