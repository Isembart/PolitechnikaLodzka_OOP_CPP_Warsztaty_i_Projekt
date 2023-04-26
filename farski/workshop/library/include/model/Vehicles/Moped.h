#ifndef mopedHeader
#define mopedHeader

// #include "model/Vehicle.h"
#include "model/Vehicles/MotorVehicle.h"

class Moped : public MotorVehicle
{
private:
public:
    Moped(const std::string &_plateNumber,const int &_basePrice, const int &_engineDisplacement);
    ~Moped();
};

#endif