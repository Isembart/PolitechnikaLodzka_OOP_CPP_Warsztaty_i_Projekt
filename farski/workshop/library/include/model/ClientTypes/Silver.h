#ifndef ClientType2
#define ClientType2
#include "model/ClientType.h"


class Silver : public ClientType
{
public:
    Silver();
    ~Silver();
    double applyDiscount(double price)final;
    std::string getTypeInfo()final;
};

#endif