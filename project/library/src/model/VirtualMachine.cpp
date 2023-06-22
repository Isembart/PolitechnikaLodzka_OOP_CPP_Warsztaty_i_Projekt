#include "model/VirtualMachine.hpp"

VirtualMachine::VirtualMachine(int ID, string OS, int RAM) : id(ID),operatingSystem(OS),ram(RAM)
{
}

const string VirtualMachine::getOperatingSystem() const
{
    return operatingSystem;
}

const int VirtualMachine::getRAM() const
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

void VirtualMachine::setArchive(bool newArchive)
{
    archive = newArchive;
}
string VirtualMachine::getVirtualMachineInfo()
{
    return "ID: "+std::to_string(id) + " RAM: "+std::to_string(ram)+" OS: "+operatingSystem;
}
VirtualMachine::~VirtualMachine()
{
}
