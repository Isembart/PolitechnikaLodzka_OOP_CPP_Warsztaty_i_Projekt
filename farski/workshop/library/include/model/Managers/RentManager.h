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
    int id = 0;
public:
    RentManager();
    ~RentManager();

    std::vector<RentPtr> getAllClientRents(ClientPtr client);
    RentPtr getVehicleRent(VehiclePtr vehicle);
    std::vector<RentPtr> findRents(RentPredicate predicate);
    std::vector<RentPtr> findAllRents();
    double checkClientRentBalance(ClientPtr client);

    RentPtr rentVehicle(ClientPtr client, VehiclePtr vehicle, boost::posix_time::ptime startTime);
    void returnVehicle(VehiclePtr vehicle);

    void changeClientType(ClientPtr client);

};

#endif