#ifndef ClientManagerHeader
#define ClientManagerHeader

#include "typedefs.hpp"
#include "model/Repositories/ClientRepo.h"

class ClientManager
{
private:
    ClientRepo repo;
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