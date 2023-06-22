#ifndef rentexcPH
#define rentexcPH

#include <stdexcept>

class RentException : public std::logic_error
{
private:
    /* data */
public:
    RentException(const char* message);
    ~RentException();
};


#endif