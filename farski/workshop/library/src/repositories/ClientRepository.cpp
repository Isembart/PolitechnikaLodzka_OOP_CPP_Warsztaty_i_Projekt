#include <algorithm> //std::remove
#include "repositories/ClientRepository.h"
#include "model/Client.h"

ClientRepository::ClientRepository()
{
}

ClientRepository::~ClientRepository()
{
}

ClientPtr ClientRepository::get(int index) const
{
    if(index >= repo.size() || index < 0) {
        return nullptr;
    }

    return repo.at(index);
}

void ClientRepository::add(ClientPtr client)
{
    if(client == nullptr) return;
    repo.push_back(client);
}

void ClientRepository::remove(ClientPtr client)

{
    if(client == nullptr) return;
    auto newEnd = std::remove(repo.begin(),repo.end(),client);
    repo.erase(newEnd,repo.end());
}

std::string ClientRepository::report()
{
    std::string info = "";
    for(int i = 0; i < repo.size(); i++) {
        info += repo.at(i)->getClientInfo() + "\n";
    } 

    return info;
}

int ClientRepository::size()
{
    return repo.size();
}

std::vector<ClientPtr> ClientRepository::findBy(ClientPredicate predicate) const
{
    std::vector<ClientPtr> found;
    for (unsigned int i = 0; i < repo.size(); i++)
    {
        ClientPtr client = get(i);
        if(client != nullptr && predicate(client)) {
            found.push_back(client);
        }
    } 
    return found;
}

bool alwaysTrue(ClientPtr ptr) {
    return true;
}

std::vector<ClientPtr> ClientRepository::findAll() const
{
    return findBy(alwaysTrue);
}