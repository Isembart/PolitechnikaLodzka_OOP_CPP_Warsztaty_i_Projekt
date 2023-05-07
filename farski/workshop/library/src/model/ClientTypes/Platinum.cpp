#include "model/ClientTypes/Platinum.h"

Platinum::Platinum()
{
}
Platinum::~Platinum()
{
}
double Platinum::applyDiscount(double price)
{
    return price - price * 0.1;
}

std::string Platinum::getTypeInfo()
{
    return "Platinum";
}
