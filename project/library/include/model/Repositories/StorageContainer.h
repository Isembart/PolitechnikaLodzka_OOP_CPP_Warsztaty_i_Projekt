#ifndef StorageContainerHeader
#define StorageContainerHeader

#include <vector>

#include "model/Repositories/ClientRepo.hpp"
#include "model/Repositories/RentRepo.hpp"
// #include "repositories/VehicleRepository.h"

#include "typedefs.hpp"

class StorageContainer
{
private:
    ClientRepositoryPtr clientRepo;
    ManiframePtr vmRepo;
    RentRepositoryPtr rentRepo;
public:
    StorageContainer(/* args */);
    ~StorageContainer();

    ClientRepositoryPtr getClientRepo() ;
    ManiframePtr getVehicleRepo() ;
    RentRepositoryPtr getRentRepo() ;
};

#endif