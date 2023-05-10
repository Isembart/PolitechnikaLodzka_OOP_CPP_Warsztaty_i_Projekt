#include <algorithm> //std::remove
#include "repositories/VehicleRepository.h"
#include "model/Vehicle.h"
VehicleRepository::VehicleRepository()
{
}

VehicleRepository::~VehicleRepository()
{
}

VehiclePtr VehicleRepository::get(int index) const
{
    if(index >= repo.size() || index < 0) {
        return nullptr;
    }

    return repo.at(index);
}

void VehicleRepository::add(VehiclePtr client)
{
    if(client == nullptr) return;
    repo.push_back(client);
}

void VehicleRepository::remove(VehiclePtr client)
{
    if(client == nullptr) return;
    auto newEnd = std::remove(repo.begin(),repo.end(),client);
    repo.erase(newEnd,repo.end());
}

std::string VehicleRepository::report()
{
    std::string info = "";
    for(int i = 0; i < repo.size(); i++) {
        info += repo.at(i)->getVehicleInfo() + "\n";
    } 

    return info;
}

int VehicleRepository::size()
{
    return repo.size();
}

std::vector<VehiclePtr> VehicleRepository::findBy(VehiclePredicate predicate) const
{
    std::vector<VehiclePtr> found;
    for (unsigned int i = 0; i < repo.size(); i++)
    {
        VehiclePtr client = get(i);
        if(client != nullptr && predicate(client)) {
            found.push_back(client);
        }
    } 
    return found;
}

bool alwaysTrue(VehiclePtr ptr) {
    return true;
}

std::vector<VehiclePtr> VehicleRepository::findAll() const
{
    return findBy(alwaysTrue);
}

VehiclePtr VehicleRepository::findByPlateNumber(std::string plateNumber) {
    VehiclePredicate matchNumber = [plateNumber](VehiclePtr ptr)
    {
        return ptr->getPlateNumber() == plateNumber; 
    };

    std::vector<VehiclePtr> found = findBy(matchNumber);
    if(found.size() == 0) {
        return nullptr;
    }

    return found.at(0);
    
}