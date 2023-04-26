#include <string>
#include "model/Vehicle.h"
#include "model/Vehicles/MotorVehicle.h"

//Konstruktor
MotorVehicle::MotorVehicle(const std::string &_plateNumber, const int &_basePrice,const int &_engineDisplacement) : Vehicle(_plateNumber,_basePrice) , engineDisplacement(_engineDisplacement) {}

MotorVehicle::~MotorVehicle() {}


const int MotorVehicle::getEngineDisplacement() const {

    return engineDisplacement;
}

std::string MotorVehicle::getVehicleInfo()
{
    std::string returnString = Vehicle::getVehicleInfo() + " rozmiar silnika: " + std::to_string(engineDisplacement) + "cm^3";
    return returnString;
}
const double MotorVehicle::getActualRentalPrice() const
{
    if(engineDisplacement < 1000) {
        return Vehicle::getActualRentalPrice();
    }
    if (engineDisplacement <= 2000)
    {
        double lerpValue = 0.5 + 0.5 * engineDisplacement/1000.0; //piękny lerp!, sprawdzałem w desmosie
        return lerpValue * Vehicle::getActualRentalPrice();
    }
    if(engineDisplacement > 2000) {
        return 1.5 * Vehicle::getActualRentalPrice(); 
    } 


    //Dotarł*ś do miejsca w który diabeł mówi "dobry wieczór"
    return -99999999;
}