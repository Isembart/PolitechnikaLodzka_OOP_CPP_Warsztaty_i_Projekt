#include "model/ClientType.hpp"

ClientType::ClientType()
{
}

ClientType::~ClientType()
{
}

const int ClientType::getMaxComputers() const
{
    return maxComputers;
}

std::string ClientType::getClientTypeInfo()
{
    return "Virtual type";
}
