#include <string>
#include "model/Vehicle.h"

Vehicle::Vehicle(const std::string &_plateNumber, const int &_basePrice)
{
    plateNumber = _plateNumber;
    basePrice = _basePrice;
}

Vehicle::~Vehicle(){}


std::string Vehicle::getVehicleInfo()
{
    return plateNumber+ " " + std::to_string(basePrice);
}

const std::string Vehicle::getPlateNumber() const
{
    return plateNumber;
}

const int Vehicle::getBasePrice() const
{
    return basePrice;
}

const double Vehicle::getActualRentalPrice() const
{
    return basePrice;
}

void Vehicle::setPlateNumber(const std::string &_plateNumber)
{
    if(_plateNumber.length()>0) {
        plateNumber = _plateNumber;
    }
}

void Vehicle::setBasePrice(const int &_basePrice)
{
    if(_basePrice >= 0) {
        basePrice = _basePrice;

    }
}

void Vehicle::setArchive(const bool &_archive)
{
    archive = _archive;
}

const bool Vehicle::isArchive() const
{
    return archive;
}