#ifndef ClientRepoHeader
#define ClientRepoHeader

#include <vector>

#include "../model/Client.h"
#include "../typyedefs.h"

class ClientRepository
{
private:
    std::vector<ClientPtr> repo;
public:
    ClientRepository(/* args */);
    ~ClientRepository();
};

ClientRepository::ClientRepository(/* args */)
{
}

ClientRepository::~ClientRepository()
{
}
 

#endif