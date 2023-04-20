#ifndef ClientRepoHeader
#define ClientRepoHeader

#include <vector>

#include "model/Client.h"
#include "typyedefs.h"

class ClientRepository
{
private:
    std::vector<ClientPtr> repo;
public:
    ClientRepository(/* args */);
    ~ClientRepository();
    ClientPtr get(int index);
    void add(ClientPtr client);
    void remove(ClientPtr client);
    std::string report();
    int size();
};
 

#endif