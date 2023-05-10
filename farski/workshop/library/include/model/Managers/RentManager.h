#ifndef RentManagerHeader
#define RentManagerHeader

#include "model/Rent.h"
#include "repositories/RentRepository.h"
#include "typyedefs.h"


class RentManager
{
private:
    RentRepository currentRents;
    RentRepository archiveRents; 
public:
    RentManager();
    ~RentManager();

    std::vector<RentPtr> getAllClientRents(ClientPtr client);
    RentPtr getVehicleRent(VehiclePtr vehicle);
    std::vector<RentPtr> findRents(RentPredicate predicate);
    std::vector<RentPtr> findAllRents();
    double checkClientRentBalance(ClientPtr client);
};

#endif