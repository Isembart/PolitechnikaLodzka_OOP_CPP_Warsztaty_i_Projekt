#ifndef ClientType1
#define ClientType1

#include <string>
#include "model/ClientType.hpp"


class Pro : public ClientType
{
 
public:
    Pro();
    virtual ~Pro();
    std::string getClientTypeInfo()final;
};

#endif