// #include "model/Client.h" cannot import Client.h <- Dependency of Rent.h ~Compiler :D

//model
class Client;
class Address;
class Vehicle;
    class Bicycle;
    class MotorVehicle;
        class Moped;
        class Car;
class Rent;

//Repos
class ClientRepository;
class RentRepository;
class VehicleRepository;

class StorageContainer;

typedef Client* ClientPtr;
typedef Address* AddressPtr;
typedef Vehicle* VehiclePtr;
    typedef Bicycle* BicyclePtr;
    typedef MotorVehicle* MotorVehiclePtr;
    typedef Car* CarPtr;
    typedef Moped* MopedPtr;
typedef Rent* RentPtr;

typedef ClientRepository* ClientRepositoryPtr;
typedef RentRepository* RentRepositoryPtr;
typedef VehicleRepository* VehicleRepositoryPtr;

typedef StorageContainer* StorageContainerPtr;

//predicates
typedef bool(*ClientPredicate)(ClientPtr);
typedef bool(*VehiclePredicate)(VehiclePtr);
typedef bool(*RentPredicate)(RentPtr);
