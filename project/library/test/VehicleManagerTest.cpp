#include <boost/test/unit_test.hpp>
#include "model/Managers/VehicleManager.h"
#include "repositories/VehicleRepository.h"
#include <memory>
#include "model/Vehicles/Bicycle.h"
#include "model/Vehicles/Moped.h"
#include "model/Vehicles/Car.h"
#include "typyedefs.h"

struct VehicleManagerFixture {

    VehicleManager manager;
    VehicleManagerFixture() {
        
    }
    ~VehicleManagerFixture() {

    }
};

BOOST_FIXTURE_TEST_SUITE(VehicleManagerTests,VehicleManagerFixture)

BOOST_AUTO_TEST_CASE(registerBicycle) {
    manager.registerBicycle("WZY01",100);

    VehiclePtr ptr = manager.registerBicycle("WZY02",100);
    BOOST_TEST(manager.registerBicycle("WZY02",99999)==ptr);
}

BOOST_AUTO_TEST_CASE(registerMoped) {
    VehiclePtr ptr = manager.registerMoped("WZY02",100,125);
    BOOST_TEST(manager.registerMoped("WZY02",99999,999999)==ptr);
}

BOOST_AUTO_TEST_CASE(registerCar) {
    VehiclePtr ptr = manager.registerCar("WZY02",100,2000,Segment(A));
    BOOST_TEST(manager.registerCar("WZY02",125124,9999,Segment(D)) == ptr);
}

BOOST_AUTO_TEST_CASE(getVehicle) {

    manager.registerCar("WZY01",100,2000,Segment(A)); 
    VehiclePtr ptr = manager.registerMoped("WZY02",100,125);
    manager.registerBicycle("WZY03",100);

    BOOST_TEST(ptr == manager.getVehicle("WZY02"));
}

BOOST_AUTO_TEST_CASE(findVehicles) {
    manager.registerCar("WZY01",999,2000,Segment(A)); 
    VehiclePtr ptr = manager.registerMoped("WZY02",100,125);
    manager.registerBicycle("WZY03",100);

    VehiclePredicate tanszeNiz100 = [](VehiclePtr ptr) {
        return ptr->getBasePrice() <= 100;
    }; 

    BOOST_REQUIRE(manager.findVehicles(tanszeNiz100).size() == 2);

    BOOST_TEST(manager.findAllVehicles().size() == 3);
    manager.unregisterVehicle("WZY02");
    BOOST_TEST(manager.findVehicles(tanszeNiz100).size() == 1);

    //FIND ALL
    BOOST_TEST(manager.findAllVehicles().size() == 2);
}



BOOST_AUTO_TEST_SUITE_END()