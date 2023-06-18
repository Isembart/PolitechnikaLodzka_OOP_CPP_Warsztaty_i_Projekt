#include "model/VirtualMachine.hpp"

VirtualMachine::VirtualMachine(int ID, string OS, int RAM) : id(ID),operatingSystem(OS),ram(RAM)
{
}

const string VirtualMachine::getOperatingSystem() const
{
    return operatingSystem;
}

const int VirtualMachine::getRam() const
{
    return ram;
}

const int VirtualMachine::getId() const
{
    return id;
}

const bool VirtualMachine::isArchive() const
{
    return archive;
}

VirtualMachine::~VirtualMachine()
{
}
