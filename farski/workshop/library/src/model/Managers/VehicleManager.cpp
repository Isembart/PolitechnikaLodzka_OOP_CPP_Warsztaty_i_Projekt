#include "model/Managers/VehicleManager.h"
#include "model/Vehicles/Bicycle.h"
#include "model/Vehicles/Moped.h"
#include "model/Vehicles/Car.h"

VehicleManager::VehicleManager() {}

VehicleManager::~VehicleManager() {}

VehiclePtr VehicleManager::registerBicycle(const std::string &plateNumber, const int &basePrice) {
    VehiclePtr existingVehicle = getVehicle(plateNumber);
    if(existingVehicle == nullptr) {
        // Bicycle newBicycle(plateNumber,basePrice);
        VehiclePtr newVehicle = std::make_shared<Bicycle>(plateNumber,basePrice);
        repo.add(newVehicle);
        return newVehicle;
    }
    return existingVehicle;
}

VehiclePtr VehicleManager::registerMoped(const std::string &plateNumber, const int &basePrice, const int &engineDisplacement)
{
    VehiclePtr existingVehicle = getVehicle(plateNumber);
    if(existingVehicle == nullptr) {

        // Moped newMoped(plateNumber,basePrice,engineDisplacement);
        VehiclePtr newVehicle = std::make_shared<Moped>(plateNumber,basePrice,engineDisplacement);
        repo.add(newVehicle);
        return newVehicle;
    }
    return existingVehicle;
}
VehiclePtr VehicleManager::registerCar(const std::string &_plateNumber, const int &_basePrice, const int &_engineDisplacement, const Segment &_segment)
{
    VehiclePtr existingVehicle = getVehicle(_plateNumber);
    if(existingVehicle == nullptr) {

        // Car newCar(_plateNumber,_basePrice,_engineDisplacement,_segment);
        VehiclePtr newVehicle = std::make_shared<Car>(_plateNumber,_basePrice,_engineDisplacement,_segment);
        repo.add(newVehicle);
        return newVehicle;
    }
    return existingVehicle;
}
void VehicleManager::unregisterVehicle(VehiclePtr _vehicle)
{
    getVehicle(_vehicle->getPlateNumber())->setArchive(true);
}

void VehicleManager::unregisterVehicle(std::string _plateNumber)
{
    getVehicle(_plateNumber)->setArchive(true);
}

VehiclePtr VehicleManager::getVehicle(std::string _plateNumber)
{
    return repo.findByPlateNumber(_plateNumber);
}

std::vector<VehiclePtr> VehicleManager::findVehicles(VehiclePredicate predicate)
{ 
    VehiclePredicate match = [predicate](VehiclePtr ptr)
    { 
        return !ptr->isArchive() * predicate(ptr);
    };
    return repo.findBy(match);
}

std::vector<VehiclePtr> VehicleManager::findAllVehicles()
{
    VehiclePredicate alwaysTrue = [](VehiclePtr ptr){
        return true;
    };
    return findVehicles(alwaysTrue);
}
