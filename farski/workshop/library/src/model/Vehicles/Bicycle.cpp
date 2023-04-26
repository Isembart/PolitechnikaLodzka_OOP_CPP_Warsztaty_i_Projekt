#include <string>
#include "model/Vehicle.h"
#include "model/Vehicles/Bicycle.h"

Bicycle::Bicycle(const std::string &_plateNumber, const int &_basePrice) : Vehicle(_plateNumber,_basePrice) {}
Bicycle::~Bicycle()
{
}
