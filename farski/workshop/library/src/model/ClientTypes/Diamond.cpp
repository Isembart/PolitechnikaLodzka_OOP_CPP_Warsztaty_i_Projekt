#include "model/ClientTypes/Diamond.h"

Diamond::Diamond()
{
    Vehicle:maxVehicles = 10;
}
Diamond::~Diamond()
{
}
double Diamond::applyDiscount(double price)
{
    double discount;
    if(price <=125) discount = 0.1;
    else if(price <=250) discount = 0.2;
    else if(price <=500) discount = 0.3;
    else if(price > 500) discount = 0.4;

    return price - price * discount;
}

std::string Diamond::getTypeInfo()
{
    return "Diamond";
}
