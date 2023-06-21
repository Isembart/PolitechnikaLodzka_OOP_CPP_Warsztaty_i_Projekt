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


const int ClientType::getMaxRAM() const
{
    return maxRAM;
}


std::string ClientType::getClientTypeInfo()
{
    return "Virtual type";
}
