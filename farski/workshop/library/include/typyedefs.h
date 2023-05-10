// #include "model/Client.h" cannot import Client.h <- Dependency of Rent.h ~Compiler :D
#include <memory>
#include <functional>

//model
class Client;
class Address;
class Vehicle;
    class Bicycle;
    class MotorVehicle;
        class Moped;
        class Car;
class Rent;

class ClientType;
    class Default;
    class Bronze;
    class Silver;
    class Gold;
    class Platinum;
    class Diamond;


//Repos
class ClientRepository;
class RentRepository;
class VehicleRepository;

class StorageContainer;

using std::shared_ptr;
typedef shared_ptr<Client> ClientPtr;
typedef shared_ptr<Rent> RentPtr;
typedef shared_ptr<Address> AddressPtr;
typedef shared_ptr<Vehicle> VehiclePtr;
    typedef shared_ptr<Bicycle> BicyclePtr;
    typedef shared_ptr<MotorVehicle> MotorVehiclePtr;
    typedef shared_ptr<Car> CarPtr;
    typedef shared_ptr<Moped> MopedPtr;
typedef shared_ptr<Rent> RentPtr;

typedef shared_ptr<ClientRepository> ClientRepositoryPtr;
typedef shared_ptr<RentRepository> RentRepositoryPtr;
typedef shared_ptr<VehicleRepository> VehicleRepositoryPtr;

typedef shared_ptr<StorageContainer> StorageContainerPtr;

typedef shared_ptr<ClientType> ClientTypePtr;

//predicates
typedef std::function<bool(ClientPtr)> ClientPredicate;
typedef std::function<bool(VehiclePtr)> VehiclePredicate;
typedef std::function<bool(RentPtr)> RentPredicate;
// typedef bool(*ClientPredicate)(ClientPtr);
// typedef bool(*VehiclePredicate)(VehiclePtr);
// typedef bool(*RentPredicate)(RentPtr);
