#include "model/ClientTypes/Pro.hpp"

Pro::Pro()
{
    //-1 jest interpretowane jako nielimitwana ilość maszyn i GIB
    ClientType::maxComputers = -1;
    ClientType::maxRAM = -1;

}
Pro::~Pro()
{
}

std::string Pro::getClientTypeInfo()
{
    return "Pro";
}
