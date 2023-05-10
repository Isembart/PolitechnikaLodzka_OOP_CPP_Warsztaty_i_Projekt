#ifndef ClientType5
#define ClientType5
#include "model/ClientType.h"

class Diamond : public ClientType
{
public:
    Diamond();
    virtual ~Diamond();
    double applyDiscount(double price)final;
    std::string getTypeInfo()final;
};

#endif