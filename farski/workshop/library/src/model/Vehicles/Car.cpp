#include <string>
// #include "model/Vehicle.h"
#include "model/Vehicles/MotorVehicle.h"
#include "model/Vehicles/Car.h"

Car::Car(const std::string &_plateNumber, const int &_basePrice,const int &_engineDisplacement, const Segment &_segment) : MotorVehicle(_plateNumber,_basePrice,_engineDisplacement) , segment(_segment){}

const double Car::getActualRentalPrice() const
{
    return MotorVehicle::getActualRentalPrice() * (1+segment*0.1);
}

Car::~Car() {}


std::string Car::getVehicleInfo() {
    
    std::string returnString = MotorVehicle::getVehicleInfo() + " Segment: " + std::to_string(segment);
    return returnString;
}