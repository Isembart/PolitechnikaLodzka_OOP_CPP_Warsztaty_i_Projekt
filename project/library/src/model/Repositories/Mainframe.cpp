#include <algorithm> //std::remove
#include "model/Repositories/Mainframe.hpp"
#include "model/VirtualMachine.hpp"

Mainframe::Mainframe()
{
}

Mainframe::~Mainframe()
{
}

VirtualMachinePtr Mainframe::get(int index) const
{
    if(index >= repo.size() || index < 0) {
        return nullptr;
    }

    return repo.at(index);
}

void Mainframe::add(VirtualMachinePtr client)
{
    if(client == nullptr) return;
    repo.push_back(client);
}

void Mainframe::remove(VirtualMachinePtr client)
{
    if(client == nullptr) return;
    auto newEnd = std::remove(repo.begin(),repo.end(),client);
    repo.erase(newEnd,repo.end());
}

std::string Mainframe::report()
{
    std::string info = "";
    for(int i = 0; i < repo.size(); i++) {
        info += repo.at(i)->getVirtualMachineInfo() + "\n";
    } 

    return info;
}

int Mainframe::size()
{
    return repo.size();
}

std::vector<VirtualMachinePtr> Mainframe::findBy(VirtualMachinePredicate predicate) const
{
    std::vector<VirtualMachinePtr> found;
    for (unsigned int i = 0; i < repo.size(); i++)
    {
        VirtualMachinePtr client = get(i);
        if(client != nullptr && predicate(client)) {
            found.push_back(client);
        }
    } 
    return found;
}

bool alwaysTrue(VirtualMachinePtr ptr) {
    return true;
}

std::vector<VirtualMachinePtr> Mainframe::findAll() const
{
    return findBy(alwaysTrue);
}

// VirtualMachinePtr Mainframe::findByPlateNumber(std::string plateNumber) {
//     VirtualMachinePredicate matchNumber = [plateNumber](VirtualMachinePtr ptr)
//     {
//         return ptr->getPlateNumber() == plateNumber; 
//     };

//     std::vector<VirtualMachinePtr> found = findBy(matchNumber);
//     if(found.size() == 0) {
//         return nullptr;
//     }

//     return found.at(0);
// }