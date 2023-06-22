#ifndef MainframeManagerHeader 
#define MainframeManagerHeader

#include "model/Repositories/Mainframe.hpp"
#include "typedefs.hpp"
#include "model/VirtualMachine.hpp" 

class MainframeManager
{
private:
    Mainframe repo;    
public:
    MainframeManager(int RamMegabytes);
    ~MainframeManager();

    // VirtualMachinePtr registerBicycle(const std::string &plateNumber, const int &basePrice);
    // VirtualMachinePtr registerMoped(const std::string &plateNumber, const int &basePrice, const int &engineDisplacement);
    // VirtualMachinePtr registerCar(const std::string &_plateNumber,const int &_basePrice, const int &_engineDisplacement, const Segment &_segment);

    VirtualMachinePtr registerVirtualmachine(int id,std::string OS, int RAM);

    void unregisterVirtualMachine(VirtualMachinePtr vm);
    void unregisterVirtualMachine(int Id);
    VirtualMachinePtr getVirtualMachine(int id);
    std::vector<VirtualMachinePtr> findVirtualMachines(VirtualMachinePredicate predicate);
    std::vector<VirtualMachinePtr> findAllVirtualMachines();
    std::string info();
};

#endif