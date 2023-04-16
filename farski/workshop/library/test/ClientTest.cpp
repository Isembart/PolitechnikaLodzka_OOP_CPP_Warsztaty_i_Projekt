#include <boost/test/unit_test.hpp>
#include "model/Client.h"

BOOST_AUTO_TEST_SUITE(TestSuiteClient)

    BOOST_AUTO_TEST_CASE(AssertionsTests) {
        BOOST_TEST(1.0/3.0==0.333,boost::test_tools::tolerance(0.002));
        BOOST_TEST(true);
    }

    BOOST_AUTO_TEST_CASE(ConstructorTest) {
        Client* client1 = new Client("Mariusz","Pudzianowski",151413);
        BOOST_TEST(client1->getFirstName() == "Mariusz");
        BOOST_TEST(client1->getLastName() == "Pudzianowski");
        BOOST_TEST(client1->getPersonalID() == 151413);
    }

BOOST_AUTO_TEST_SUITE_END()