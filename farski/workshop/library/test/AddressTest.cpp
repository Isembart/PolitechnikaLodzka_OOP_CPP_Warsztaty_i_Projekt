#include <boost/test/unit_test.hpp>
#include "model/Address.h"

struct TestSuiteAddressFixture {
    const std::string city = "warszawa";
    const std::string street = "smolna";
    const std::string number = "22";

 TestSuiteAddressFixture() {
 }

 ~TestSuiteAddressFixture() {
 }

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteAddress,TestSuiteAddressFixture)

BOOST_AUTO_TEST_CASE(ConstructorTest) {
    Address address1(city,street,number);
    BOOST_TEST(address1.getCity() == city); 
    BOOST_TEST(address1.getStreet() == street);
    BOOST_TEST(address1.getNumber() ==  number);
     
}

BOOST_AUTO_TEST_SUITE_END()