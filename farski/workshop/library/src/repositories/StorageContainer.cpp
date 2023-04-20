#include "repositories/StorageContainer.h"

StorageContainer::StorageContainer()
{
    Client mariuszPudzianowski("Mariusz","Pudzianowski",0,new Address("Warszawa","Smolna","22"));
    Client Roman("roman","kostrzewski",123,new Address("grudziądz","armi krajowej","5A")); 
    clientRepo.add(&mariuszPudzianowski);
    clientRepo.add(&Roman);

    Vehicle toyotaCorolla("WZY000",10);
    vehicleRepo.add(&toyotaCorolla);

    Rent rent1(1,&mariuszPudzianowski,&toyotaCorolla, boost::posix_time::ptime(boost::gregorian::date(2023,4,9)));

    rentRepo.add(&rent1);
}


StorageContainer::~StorageContainer()
{
}

ClientRepository StorageContainer::getClientRepo() const
{
    return clientRepo;
}

VehicleRepository StorageContainer::getVehicleRepo() const
{
    return vehicleRepo;
}

RentRepository StorageContainer::getRentRepo() const
{
    return rentRepo;
}
