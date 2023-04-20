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
    ClientRepository clientRepo;
    VehicleRepository vehicleRepo;
    RentRepository rentRepo;
public:
    StorageContainer(/* args */);
    ~StorageContainer();

    ClientRepository getClientRepo() const;
    VehicleRepository getVehicleRepo() const;
    RentRepository getRentRepo() const;
};

#endif