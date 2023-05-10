#include "model/ClientTypes/Default.h" 

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
