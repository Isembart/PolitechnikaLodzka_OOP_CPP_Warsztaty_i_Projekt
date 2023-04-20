#include "repositories/ClientRepository.h"
#include "model/Client.h"
ClientRepository::ClientRepository()
{
}

ClientRepository::~ClientRepository()
{
}

ClientPtr ClientRepository::get(int index)
{
    if(index >= repo.size() || index < 0) {
        return nullptr;
    }

    return repo.at(index);
}

void ClientRepository::add(ClientPtr client)
{
    repo.push_back(client);
}

void ClientRepository::remove(ClientPtr client)
{
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
