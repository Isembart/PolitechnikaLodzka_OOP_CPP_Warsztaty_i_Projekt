#ifndef VehicleRepoHeader
#define VehicleRepoHeader

#include <vector>

#include "model/VirtualMachine.hpp"
#include "typedefs.hpp"

class Mainframe
{
private:
    std::vector<VirtualMachinePtr> repo;
public:
    Mainframe(/* args */);
    ~Mainframe();
    VirtualMachinePtr get(int index)const;
    void add(VirtualMachinePtr client);
    void remove(VirtualMachinePtr client);
    std::string report();
    int size();

    std::vector<VirtualMachinePtr> findBy(VirtualMachinePredicate predicate) const;
    std::vector<VirtualMachinePtr> findAll() const;
    // VirtualMachinePtr findByPlateNumber(std::string plateNumber);
};
 

#endif