#include "repositories/StorageContainer.h"
#include "model/Vehicles/Car.h"
#include "typyedefs.h"

StorageContainer::StorageContainer()
{
    clientRepo = new ClientRepository;
    vehicleRepo = new VehicleRepository;
    rentRepo = new RentRepository;
    ClientPtr mariuszPudzianowski = new Client("Mariusz","Pudzianowski",0,new Address("Warszawa","Smolna","22"));
    ClientPtr Roman = new Client("Roman","Kostrzewski",123,new Address("grudziądz","armi krajowej","5A")); 
    clientRepo->add(mariuszPudzianowski);
    clientRepo->add(Roman);

    VehiclePtr toyotaCorolla = new Car("WZY000",10,1600,Segment(D));
    vehicleRepo->add(toyotaCorolla);

    // RentPtr rent1 = new Rent(1,mariuszPudzianowski,toyotaCorolla, boost::posix_time::ptime(boost::gregorian::date(2023,4,9)));

    // rentRepo->add(rent1);
    //Nigdy nie usuwamy tych danych, wyciek :P. ale w zadaniu jest i tak żeby tak nie robić 
}


StorageContainer::~StorageContainer()
{

}

ClientRepositoryPtr StorageContainer::getClientRepo() 
{
    return clientRepo;
}

VehicleRepositoryPtr StorageContainer::getVehicleRepo()
{
    return vehicleRepo;
}

RentRepositoryPtr StorageContainer::getRentRepo()
{
    return rentRepo;
}
