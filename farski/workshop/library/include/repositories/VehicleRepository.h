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
    VehiclePtr get(int index);
    void add(VehiclePtr client);
    void remove(VehiclePtr client);
    std::string report();
    int size();
};
 

#endif