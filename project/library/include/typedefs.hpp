#ifndef typedefsH
#define typedefsH
#include <memory>
class Client;
class VirtualMachine;
class ClientType;
class Rent;
class Mainframe;

typedef std::shared_ptr<Client> ClientPtr;
typedef std::shared_ptr<ClientType> ClientTypePtr;
typedef std::shared_ptr<VirtualMachine> VirtualMachinePtr;
typedef std::shared_ptr<Rent> RentPtr;
typedef std::shared_ptr<Mainframe> ManiframePtr;

#endif