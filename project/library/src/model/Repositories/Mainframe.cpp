#include <algorithm> //std::remove
#include "model/Repositories/Mainframe.hpp"
#include "model/VirtualMachine.hpp"

Mainframe::Mainframe(int ram) : physicalMemory(ram), remainingMemory(ram)
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
    if (client->getRam() > remainingMemory)
    {
        /* code */
        //EXCEPTION
        return;
    }
    remainingMemory-=client->getRam();
    
    repo.push_back(client);
}

void Mainframe::remove(VirtualMachinePtr client)
{
    if(client == nullptr) return;
    auto newEnd = std::remove(repo.begin(),repo.end(),client);
    repo.erase(newEnd,repo.end());
    remainingMemory+=client->getRam();
}

std::string Mainframe::report()
{
    std::string info = "";
    for(int i = 0; i < repo.size(); i++) {
        info += repo.at(i)->getVirtualMachineInfo() + "\n";
    } 

    return info;
}

const int Mainframe::getPhysicalMemory() const
{
    return physicalMemory;
}

const int Mainframe::getFreePhysicalMemory() const
{
    return remainingMemory;
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

VirtualMachinePtr Mainframe::findByID(int id) {
    VirtualMachinePredicate matchNumber = [id](VirtualMachinePtr ptr)
    {
        return ptr->getId() == id; 
    };

    std::vector<VirtualMachinePtr> found = findBy(matchNumber);
    if(found.size() == 0) {
        return nullptr;
    }

    return found.at(0);
}