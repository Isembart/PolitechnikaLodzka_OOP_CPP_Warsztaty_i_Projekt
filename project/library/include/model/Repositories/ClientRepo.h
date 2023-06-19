#ifndef ClientRepoHeader
#define ClientRepoHeader

#include <vector>

#include "model/Client.hpp"
#include "typedefs.hpp"

class ClientRepo
{
private:
    std::vector<ClientPtr> repo;
public:
    ClientRepo(/* args */);
    ~ClientRepo();
    ClientPtr get(int index) const;
    void add(ClientPtr client);
    void remove(ClientPtr client);
    std::string report();
    int size();

    std::vector<ClientPtr> findBy(ClientPtr) const;
    std::vector<ClientPtr> findAll() const;
    ClientPtr findByPersonalId(int personalID);
};


#endif