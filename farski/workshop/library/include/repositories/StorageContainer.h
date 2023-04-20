#ifndef StorageContainerHeader
#define StorageContainerHeader

#include <vector>

#include "repositories/StorageContainer.h"
#include "repositories/ClientRepository.h"
#include "repositories/RentRepository.h"
#include "repositories/VehicleRepository.h"

#include "typyedefs.h"

class StorageContainer
{
private:
    ClientRepositoryPtr clientRepo;
    VehicleRepositoryPtr vehicleRepo;
    RentRepositoryPtr rentRepo;
public:
    StorageContainer(/* args */);
    ~StorageContainer();

    ClientRepositoryPtr getClientRepo() ;
    VehicleRepositoryPtr getVehicleRepo() ;
    RentRepositoryPtr getRentRepo() ;
};

#endif