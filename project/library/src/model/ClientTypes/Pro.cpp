#include "model/ClientTypes/Pro.hpp"

Pro::Pro()
{
    //-1 jest interpretowane jako nielimitwana ilość maszyn
    ClientType::maxComputers = -1;
}
Pro::~Pro()
{
}

std::string Pro::getClientTypeInfo()
{
    return "Pro";
}
