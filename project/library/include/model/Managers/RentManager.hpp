#ifndef RentManagerHeader
#define RentManagerHeader

#include "model/Rent.hpp"
#include "model/Repositories/RentRepo.hpp"
#include "typedefs.hpp"


class RentManager
{
private:
    RentRepo currentRents;
    RentRepo archiveRents;
    int id = 0;
public:
    RentManager();
    ~RentManager();

    std::vector<RentPtr> getAllClientRents(ClientPtr client);
    RentPtr getVirtualMachineRent(VirtualMachinePtr VirtualMachine);
    std::vector<RentPtr> findRents(RentPredicate predicate);
    std::vector<RentPtr> findAllRents();
    double checkClientRentBalance(ClientPtr client);

    RentPtr rentVirtualMachine(ClientPtr client, VirtualMachinePtr VirtualMachine, boost::posix_time::ptime startTime);
    void returnVirtualMachine(VirtualMachinePtr VirtualMachine);

    void changeClientType(ClientPtr client);

    std::string info();
};

#endif