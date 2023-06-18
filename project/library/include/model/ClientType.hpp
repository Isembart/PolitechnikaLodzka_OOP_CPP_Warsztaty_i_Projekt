#ifndef ClientTypeClass
#define ClientTypeClass
#include "model/Client.hpp"


class ClientType
{
protected:
    int maxComputers;
    
public:
    ClientType();
    virtual ~ClientType()=0;

    const int getMaxComputers() const;
    virtual std::string getClientTypeInfo();
};

#endif