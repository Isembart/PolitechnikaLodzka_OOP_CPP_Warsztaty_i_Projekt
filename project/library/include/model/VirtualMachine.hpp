#ifndef vmH
#define vmH

#include <string>
using std::string;

class VirtualMachine
{
private:
    const string operatingSystem;
    const int ram;
    const int id;
    bool archive;

public:
    VirtualMachine(int ID, string OS, int RAM);
    const string getOperatingSystem()const;
    const int getRam() const;
    const int getId() const;
    const bool isArchive() const;
    
    string getVirtualMachineInfo();
    virtual ~VirtualMachine();
};


#endif