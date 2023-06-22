#include "model/ClientTypes/Default.hpp"

Default::Default()
{
    ClientType::maxComputers = 1;
    ClientType::maxRAM = 4096; //ram jest w megabajtach

}
Default::~Default()
{
}

std::string Default::getClientTypeInfo()
{
    return "Default";
}
