#include <boost/test/unit_test.hpp>
#include "model/Vehicle.h"
#include "model/Vehicles/MotorVehicle.h"
#include "model/Vehicles/Bicycle.h"
#include "model/Vehicles/Moped.h"
#include "model/Vehicles/Car.h"
#include "typyedefs.h"

struct TestSuiteMotorVehicleFixture {
    std::string testPlateNumber = "WZY0102";
    int testBasePrice = 100;
    int testEngineDisplacementLow = 600;
    int testEngineDisplacementMid = 2000;
    int testEngineDisplacementHigh = 4000;
    int testSegment = Segment(B);
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteVehicle,TestSuiteMotorVehicleFixture)

BOOST_AUTO_TEST_CASE(getAcutalPriceBicycle) {
    VehiclePtr vehicleToTest;
    vehicleToTest = new Bicycle(testPlateNumber,testBasePrice);
    BOOST_TEST(vehicleToTest->getActualRentalPrice() == testBasePrice);
}

BOOST_AUTO_TEST_CASE(getAcutalPriceMotorVehicleLowTier) {
    VehiclePtr vehicleToTest;

    vehicleToTest = new Moped(testPlateNumber,testBasePrice,testEngineDisplacementLow);
    BOOST_TEST(vehicleToTest->getActualRentalPrice() == testBasePrice);
}

BOOST_AUTO_TEST_CASE(getAcutalPriceMotorVehicleMidTier) {
    VehiclePtr vehicleToTest;

    vehicleToTest = new Moped(testPlateNumber,testBasePrice,testEngineDisplacementMid);
    double lerpValue = 0.5 + 0.5 * (testEngineDisplacementMid/1000); 

    BOOST_TEST(vehicleToTest->getActualRentalPrice() == testBasePrice * lerpValue);
}

BOOST_AUTO_TEST_CASE(getAcutalPriceMotorVehicleHighTier) {
    VehiclePtr vehicleToTest;

    vehicleToTest = new Moped(testPlateNumber,testBasePrice,testEngineDisplacementHigh);
    BOOST_TEST(vehicleToTest->getActualRentalPrice() == (double)testBasePrice * 1.5);
}

BOOST_AUTO_TEST_CASE(getAcutalPriceCar) {
    VehiclePtr vehicleToTest;

    vehicleToTest = new Car(testPlateNumber,testBasePrice,testEngineDisplacementHigh,Segment(E));
    BOOST_TEST(vehicleToTest->getActualRentalPrice() == (double)testBasePrice * 1.5 * 1.5);
}
BOOST_AUTO_TEST_SUITE_END()