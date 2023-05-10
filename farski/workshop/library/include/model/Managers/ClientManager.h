#ifndef ClientManagerHeader 
#define ClientManagerHeader

#include "repositories/ClientRepository.h"
#include "typyedefs.h"

class ClientManager
{
private:
    ClientRepository repo;    
public:
    ClientManager();
    ~ClientManager();

    ClientPtr registerClient(const std::string &firstname, const std::string &lastName, const int &personalID, AddressPtr adr, ClientTypePtr type);
    void unregisterClient(ClientPtr client);
    void unregisterClient(int id);
    ClientPtr getClient(int id);
    std::vector<ClientPtr> findClients(ClientPredicate predicate);
    std::vector<ClientPtr> findAllClients();
};

#endif