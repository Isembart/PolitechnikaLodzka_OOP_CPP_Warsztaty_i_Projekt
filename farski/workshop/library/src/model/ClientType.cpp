#include "model/ClientType.h"

ClientType::ClientType()
{
}

ClientType::~ClientType()
{
}

const int ClientType::getMaxVehicles() const
{
    return maxVehicles;
}

double ClientType::applyDiscount(double price)
{
    return 0.0;
}

std::string ClientType::getTypeInfo()
{
    return "Virtual type";
}
