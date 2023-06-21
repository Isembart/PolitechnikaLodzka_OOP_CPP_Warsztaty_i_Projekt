#include "model/Repositories/StorageContainer.h"
#include "model/VirtualMachine.hpp"
#include "model/Repositories/Mainframe.hpp"
#include "typedefs.hpp"
#include "model/ClientTypes/Default.hpp"
#include <memory>

StorageContainer::StorageContainer()
{
    
    clientRepo = std::make_shared<ClientRepo>();
    vmRepo = std::make_shared<Mainframe>();
    rentRepo = std::make_shared<RentRepo>();
    ClientPtr mariuszPudzianowski = std::make_shared<Client>("Mariusz","Pudzianowski",0,std::make_shared<Default>());
    ClientPtr Roman = std::make_shared<Client>("Roman","Kostrzewski",123,std::make_shared<Default>()); 
    clientRepo->add(mariuszPudzianowski);
    clientRepo->add(Roman);

    // VehiclePtr toyotaCorolla = std::make_shared<Car>("WZY000",10,1600,Segment(D));
    VirtualMachinePtr vm1 = std::make_shared<VirtualMachine>(1,"Ubuntu",16);
    vmRepo->add(vm1);


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

MainframePtr StorageContainer::getVehicleRepo()
{
    return vmRepo;
}

RentRepositoryPtr StorageContainer::getRentRepo()
{
    return rentRepo;
}
