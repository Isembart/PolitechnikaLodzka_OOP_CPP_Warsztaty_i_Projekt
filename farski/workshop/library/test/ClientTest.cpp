#include <boost/test/unit_test.hpp>
#include "model/Client.h"
#include "model/Address.h"

BOOST_AUTO_TEST_SUITE(TestSuiteClient)

    // BOOST_AUTO_TEST_CASE(AssertionsTests) {
    //     BOOST_TEST(1.0/3.0==0.333,boost::test_tools::tolerance(0.002));
    //     BOOST_TEST(true);
    // }

    Address* address1 = new Address("Warszwa","Smolna","22");
    Client* client1 = new Client((std::string)"Mariusz",(std::string)"Pudzianowski",151413, address1);
    BOOST_AUTO_TEST_CASE(GettersTests) {
        //Testy getterów | _REQUIRE daltego że jeśli gettery nie działają to testy setterów korzystające z nich i tak nie będą wiarygodne
        BOOST_TEST_REQUIRE(client1->getFirstName() == "Mariusz");
        BOOST_TEST_REQUIRE(client1->getLastName() == "Pudzianowski");
        BOOST_TEST_REQUIRE(client1->getPersonalID() == 151413);
        BOOST_TEST_REQUIRE(client1->getAddress() == address1);
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

        client1->setAddress(nullptr);
        BOOST_TEST_REQUIRE(client1->getAddress() == address1);
        Address* address2 = new Address("Kłodawa","test","50");
        client1->setAddress(address2);
        BOOST_TEST_REQUIRE(client1->getAddress() == address2);
    }


BOOST_AUTO_TEST_SUITE_END()