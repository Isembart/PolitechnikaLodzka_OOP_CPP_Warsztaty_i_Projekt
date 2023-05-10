#include <boost/test/unit_test.hpp>
#include "model/Managers/RentManager.h"
#include "model/Vehicles/Car.h"
#include "model/Vehicles/Bicycle.h"
#include "typyedefs.h"
#include "model/ClientTypes/Gold.h"
#include <memory>

BOOST_AUTO_TEST_SUITE()

BOOST_AUTO_TEST_CASE(RentVehicle_Test)
{

    //Ten sam kod w mainie działa bez zarzutów...
    RentManager rentManager;
    ClientTypePtr goldType = std::make_shared<Gold>();
    AddressPtr testAddress = std::make_shared<Address>("warszawa","smolna","22a");
    ClientPtr client = std::make_shared<Client>("Mariusz","pudzian",12,testAddress,goldType);
    VehiclePtr vehicle1 = std::make_shared<Car>("WZY01",100,2000,Segment(D));
    VehiclePtr vehicle2 = std::make_shared<Bicycle>("WO15",50);
    boost::posix_time::ptime startTime = boost::posix_time::second_clock::local_time();

    RentPtr rent = rentManager.rentVehicle(client, vehicle1, startTime);

    BOOST_TEST(rent != nullptr);
    BOOST_CHECK(rent->getClient() == client);
    BOOST_CHECK(rent->getVehicle() == vehicle1);
    BOOST_CHECK(rent->getBeginTime() == startTime);
}

BOOST_AUTO_TEST_SUITE_END()
