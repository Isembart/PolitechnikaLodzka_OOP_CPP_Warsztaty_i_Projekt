#ifndef ctH
#define ctH

#include <string>
// #include "model/ClientType.hpp"
#include "model/ClientType.hpp"

class Default : public ClientType
{
public:
    Default();
    virtual ~Default();
    std::string getClientTypeInfo()final;
};
#endif
