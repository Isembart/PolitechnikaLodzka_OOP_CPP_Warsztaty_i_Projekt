#ifndef VehicleRepoHeader
#define VehicleRepoHeader

#include <vector>

#include "model/VirtualMachine.hpp"
#include "typedefs.hpp"

class Mainframe
{
private:
    std::vector<VirtualMachinePtr> repo;
    int physicalMemory;
    int remainingMemory;
public:
    Mainframe(int ram);
    ~Mainframe();
    VirtualMachinePtr get(int index)const;
    void add(VirtualMachinePtr client);
    void remove(VirtualMachinePtr client);
    std::string report();
    // int size();
    const int getPhysicalMemory() const;
    const int getFreePhysicalMemory() const;

    std::vector<VirtualMachinePtr> findBy(VirtualMachinePredicate predicate) const;
    std::vector<VirtualMachinePtr> findAll() const;
    VirtualMachinePtr findByID(int plateNumber);
};
 

#endif