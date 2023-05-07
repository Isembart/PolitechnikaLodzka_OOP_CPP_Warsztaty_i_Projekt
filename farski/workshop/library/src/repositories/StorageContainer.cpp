#include "repositories/StorageContainer.h"
#include "model/Vehicles/Car.h"
#include "typyedefs.h"

StorageContainer::StorageContainer()
{
    
    clientRepo = std::make_shared<ClientRepository>();
    vehicleRepo = std::make_shared<VehicleRepository>();
    rentRepo = std::make_shared<RentRepository>();
    ClientPtr mariuszPudzianowski = std::make_shared<Client>("Mariusz","Pudzianowski",0, std::make_shared<Address>("Warszawa","Smolna","22"));
    ClientPtr Roman = std::make_shared<Client>("Roman","Kostrzewski",123, std::make_shared<Address>("grudziądz","armi krajowej","5A")); 
    clientRepo->add(mariuszPudzianowski);
    clientRepo->add(Roman);

    VehiclePtr toyotaCorolla = std::make_shared<Car>("WZY000",10,1600,Segment(D));
    vehicleRepo->add(toyotaCorolla);


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
