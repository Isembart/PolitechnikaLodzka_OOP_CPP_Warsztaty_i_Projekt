#ifndef VehicleRepoHeader
#define VehicleRepoHeader

#include <vector>

#include "model/Vehicle.h"
#include "typyedefs.h"

class VehicleRepository
{
private:
    std::vector<VehiclePtr> repo;
public:
    VehicleRepository(/* args */);
    ~VehicleRepository();
    VehiclePtr get(int index)const;
    void add(VehiclePtr client);
    void remove(VehiclePtr client);
    std::string report();
    int size();

    std::vector<VehiclePtr> findBy(VehiclePredicate) const;
    std::vector<VehiclePtr> findAll() const;
    VehiclePtr findByPlateNumber(std::string plateNumber);
};
 

#endif