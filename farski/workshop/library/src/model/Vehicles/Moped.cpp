#include <string>
// #include "model/Vehicle.h"
#include "model/Vehicles/MotorVehicle.h"
#include "model/Vehicles/Moped.h"

Moped::Moped(const std::string &_plateNumber, const int &_basePrice,const int &_engineDisplacement) : 
MotorVehicle(_plateNumber,_basePrice,_engineDisplacement) {}


Moped::~Moped()
{
}
