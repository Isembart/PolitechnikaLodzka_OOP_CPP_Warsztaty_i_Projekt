#include "model/ClientTypes/Gold.h"

Gold::Gold()
{
}
Gold::~Gold()
{
}
double Gold::applyDiscount(double price)
{
    return price - price*0.05;
}

std::string Gold::getTypeInfo()
{
    return "Gold";
}
