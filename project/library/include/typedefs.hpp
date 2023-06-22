#ifndef typedefsH
#define typedefsH
#include <memory>
#include <functional>

class Client;
// class Address;

class ClientType;
    class Default;
    class Pro;

class VirtualMachine;
class ClientType;
class Rent;
class Mainframe;

typedef std::shared_ptr<Client> ClientPtr;
typedef std::shared_ptr<ClientType> ClientTypePtr;
typedef std::shared_ptr<VirtualMachine> VirtualMachinePtr;
typedef std::shared_ptr<Rent> RentPtr;
typedef std::shared_ptr<Mainframe> ManiframePtr;


//Repositories

class ClientRepo;
class RentRepo;
class Mainframe;

class StorageContainer;

typedef std::shared_ptr<ClientRepo> ClientRepositoryPtr;
typedef std::shared_ptr<RentRepo> RentRepositoryPtr;
typedef std::shared_ptr<Mainframe> MainframePtr;

//predicates
typedef std::function<bool(ClientPtr)> ClientPredicate;
typedef std::function<bool(VirtualMachinePtr)> VirtualMachinePredicate;
typedef std::function<bool(RentPtr)> RentPredicate;

#endif