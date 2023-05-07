#include "model/ClientTypes/Silver.h"

Silver::Silver()
{
}
Silver::~Silver()
{
}
double Silver::applyDiscount(double price)
{
    return price - 6.0;
}

std::string Silver::getTypeInfo()
{
    return "Silver";
}
