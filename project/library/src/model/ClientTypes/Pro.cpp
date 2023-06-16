#include "model/ClientTypes/Pro.hpp"

Pro::Pro()
{
    Vehicle:maxVehicles = 2;
}
Pro::~Pro()
{
}
double Pro::applyDiscount(double price)
{
    return price - 3.0;
}

std::string Pro::getTypeInfo()
{
    return "Pro";
}
