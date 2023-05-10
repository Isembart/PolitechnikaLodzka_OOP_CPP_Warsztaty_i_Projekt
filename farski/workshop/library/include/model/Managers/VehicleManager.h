#ifndef VehicleManagerHeader 
#define VehicleManagerHeader

#include "repositories/VehicleRepository.h"
#include "typyedefs.h"
#include "model/Vehicles/Car.h" //Segment enum

class VehicleManager
{
private:
    VehicleRepository repo;    
public:
    VehicleManager();
    ~VehicleManager();

    VehiclePtr registerBicycle(const std::string &plateNumber, const int &basePrice);
    VehiclePtr registerMoped(const std::string &plateNumber, const int &basePrice, const int &engineDisplacement);
    VehiclePtr registerCar(const std::string &_plateNumber,const int &_basePrice, const int &_engineDisplacement, const Segment &_segment);
    void unregisterVehicle(VehiclePtr vehicle);
    void unregisterVehicle(std::string plateNumber);
    VehiclePtr getVehicle(std::string plateNumber);
    std::vector<VehiclePtr> findVehicles(VehiclePredicate predicate);
    std::vector<VehiclePtr> findAllVehicles();
};

#endif