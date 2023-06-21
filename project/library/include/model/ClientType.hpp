#ifndef ClientTypeClass
#define ClientTypeClass
#include "model/Client.hpp"


class ClientType
{
protected:
    int maxComputers;
    int maxRAM;
    
public:
    ClientType();
    virtual ~ClientType()=0;

    const int getMaxComputers() const;
    virtual std::string getClientTypeInfo();
};

#endif