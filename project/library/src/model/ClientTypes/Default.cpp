#include "model/ClientTypes/Default.hpp"

Default::Default()
{
    Vehicle:maxVehicles = 1;
}
Default::~Default()
{
}
double Default::applyDiscount(double price)
{
    return price;
}

std::string Default::getTypeInfo()
{
    return "Default";
}
