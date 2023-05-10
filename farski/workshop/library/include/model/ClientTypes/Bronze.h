#ifndef ClientType1
#define ClientType1

#include "model/ClientType.h"

class Bronze : public ClientType
{
 
public:
    Bronze();
    virtual ~Bronze();
    double applyDiscount(double price)final;
    std::string getTypeInfo()final;
};

#endif