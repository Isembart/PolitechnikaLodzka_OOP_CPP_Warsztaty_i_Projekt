#include <boost/test/unit_test.hpp>
#include "model/Client.h"

BOOST_AUTO_TEST_SUITE(TestSuiteClient)

    BOOST_AUTO_TEST_CASE(AssertionsTests) {
        BOOST_TEST(1.0/3.0==0.333,boost::test_tools::tolerance(0.002));
        BOOST_TEST(true);
    }

    Client* client1 = new Client("Mariusz","Pudzianowski",151413);
    BOOST_AUTO_TEST_CASE(GettersTests) {
        //Testy getterów | _REQUIRE daltego że jeśli gettery nie działają to testy setterów korzystające z nich i tak nie będą wiarygodne
        BOOST_TEST_REQUIRE(client1->getFirstName() == "Mariusz");
        BOOST_TEST_REQUIRE(client1->getLastName() == "Pudzianowski");
        BOOST_TEST_REQUIRE(client1->getPersonalID() == 151413);
    }

    BOOST_AUTO_TEST_CASE(SettersTests) {
        //Testy setFirstName
        client1->setFirstName("Jonasz");
        BOOST_TEST(client1->getFirstName()=="Jonasz");
        client1->setFirstName("");
        BOOST_TEST(client1->getFirstName()=="Jonasz");

        //Testy setLastName
        client1->setLastName("josephson");
        BOOST_TEST(client1->getLastName()=="josephson");
        client1->setLastName("");
        BOOST_TEST(client1->getLastName()=="josephson");
    }


BOOST_AUTO_TEST_SUITE_END()