// #include "model/Client.h" cannot import Client.h <- Dependency of Rent.h ~Compiler :D
#include "model/Address.h"
#include "model/Vehicle.h"
#include "model/Rent.h"

class Client;
class Address;
class Vehicle;
class Rent;

typedef Client* ClientPtr;
typedef Address* AddressPtr;
typedef Vehicle* VehiclePtr;
typedef Rent* RentPtr;

typedef bool(*ClientPredicate)(ClientPtr);
typedef bool(*VehiclePredicate)(VehiclePtr);
typedef bool(*RentPredicate)(RentPtr);