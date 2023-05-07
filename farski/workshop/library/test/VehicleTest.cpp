#include <boost/test/unit_test.hpp>
#include "model/Vehicles/Car.h"


struct TestSuiteVehicleFixture {
    std::string testPlateNumber = "WZY0102";
    int testBasePrice = 200;
 TestSuiteVehicleFixture() {
 }

 ~TestSuiteVehicleFixture() {
 }

};

BOOST_FIXTURE_TEST_SUITE(TestSuiteVehicle,TestSuiteVehicleFixture)


BOOST_AUTO_TEST_CASE(ConstructorTest) {
    Car vehicle1(testPlateNumber,testBasePrice,1600,Segment(D));
    BOOST_TEST(testPlateNumber == vehicle1.getPlateNumber());
    BOOST_TEST(testBasePrice == vehicle1.getBasePrice());
    //BOOST_TEST(false == vehicle1.isRented());
}

BOOST_AUTO_TEST_CASE(SetPlateNumberPositiveTest) {
    Car vehicle1(testPlateNumber,testBasePrice,1600,Segment(D));
    vehicle1.setPlateNumber("test123");
    BOOST_TEST("test123" == vehicle1.getPlateNumber());
}

BOOST_AUTO_TEST_CASE(SetPlateNumberNegativeTest) {
    Car vehicle1(testPlateNumber,testBasePrice,1600,Segment(D));
    vehicle1.setPlateNumber("");
    BOOST_TEST(testPlateNumber == vehicle1.getPlateNumber());
}

BOOST_AUTO_TEST_CASE(SetBasePricePositiveTest) {
    Car vehicle1(testPlateNumber,testBasePrice,1600,Segment(D));
    vehicle1.setBasePrice(300);
    BOOST_TEST(300 == vehicle1.getBasePrice());
}

BOOST_AUTO_TEST_CASE(SetBasePriceNegativeTest) {
    Car vehicle1(testPlateNumber,testBasePrice,1600,Segment(D));
    vehicle1.setBasePrice(-123);
    BOOST_TEST(testBasePrice == vehicle1.getBasePrice());
}
BOOST_AUTO_TEST_SUITE_END()