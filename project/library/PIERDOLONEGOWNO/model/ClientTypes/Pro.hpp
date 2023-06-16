#ifndef ClientType1
#define ClientType1

#include "model/ClientType.hpp"

class Pro : public ClientType
{
 
public:
    Pro();
    virtual ~Pro();
    double applyDiscount(double price)final;
    std::string getTypeInfo()final;
};

#endif