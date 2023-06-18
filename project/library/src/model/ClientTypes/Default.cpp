#include "model/ClientTypes/Default.hpp"

Default::Default()
{
    ClientType::maxComputers = 1;
}
Default::~Default()
{
}

std::string Default::getClientTypeInfo()
{
    return "Default";
}
