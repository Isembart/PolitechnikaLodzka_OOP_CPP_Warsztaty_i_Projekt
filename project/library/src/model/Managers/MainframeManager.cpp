#include "model/Managers/MainframeManager.hpp"
#include "model/VirtualMachine.hpp"
// #include "model/VirtualMachines/Bicycle.h"
// #include "model/VirtualMachines/Moped.h"
// #include "model/VirtualMachines/Car.h"

MainframeManager::MainframeManager(int RamMegabytes) : repo(RamMegabytes) {
}

MainframeManager::~MainframeManager() {}

VirtualMachinePtr MainframeManager::registerVirtualmachine(int id, std::string OS, int RAM)
{
    VirtualMachinePtr existingVM = getVirtualMachine(id);
    if(existingVM == nullptr) {
        VirtualMachinePtr newVm = std::make_shared<VirtualMachine>(id,OS,RAM);
        repo.add(newVm);
        return newVm;
    }
    return existingVM;
}
void MainframeManager::unregisterVirtualMachine(VirtualMachinePtr _vm)
{
    getVirtualMachine(_vm->getId())->setArchive(true);
}

void MainframeManager::unregisterVirtualMachine(int _id)
{
    getVirtualMachine(_id)->setArchive(true);
}

VirtualMachinePtr MainframeManager::getVirtualMachine(int _id)
{
    return repo.findByID(_id);
}

std::vector<VirtualMachinePtr> MainframeManager::findVirtualMachines(VirtualMachinePredicate predicate)
{ 
    VirtualMachinePredicate match = [predicate](VirtualMachinePtr ptr)
    { 
        return !ptr->isArchive() * predicate(ptr);
    };
    return repo.findBy(match);
}

std::vector<VirtualMachinePtr> MainframeManager::findAllVirtualMachines()
{
    VirtualMachinePredicate alwaysTrue = [](VirtualMachinePtr ptr){
        return true;
    };

    
    return findVirtualMachines(alwaysTrue);
}

    std::string MainframeManager::info()
    {
        return repo.report();
    }
