#include "exceptions/RentException.h"

RentException::RentException(const char *message) : std::logic_error(message)
{

}

RentException::~RentException()
{
}