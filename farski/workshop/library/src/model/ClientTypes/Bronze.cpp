#include "model/ClientTypes/Bronze.h"

Bronze::Bronze()
{
}
Bronze::~Bronze()
{
}
double Bronze::applyDiscount(double price)
{
    return price - 3.0;
}

std::string Bronze::getTypeInfo()
{
    return "Bronze";
}
