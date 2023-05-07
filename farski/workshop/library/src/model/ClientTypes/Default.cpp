#include "model/ClientTypes/Default.h" 

Default::Default()
{
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
