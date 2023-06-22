#include <algorithm> //std::remove
#include "model/Client.hpp"
#include "model/Repositories/ClientRepo.hpp"

ClientRepo::ClientRepo()
{
}

ClientRepo::~ClientRepo()
{
}

ClientPtr ClientRepo::get(int index) const
{
    if(index >= repo.size() || index < 0) {
        return nullptr;
    }

    return repo.at(index);
}

void ClientRepo::add(ClientPtr client)
{
    if(client == nullptr) return;
    repo.push_back(client);
}

void ClientRepo::remove(ClientPtr client)

{
    if(client == nullptr) return;
    auto newEnd = std::remove(repo.begin(),repo.end(),client);
    repo.erase(newEnd,repo.end());
}

std::string ClientRepo::report()
{
    std::string info = "";
    for(int i = 0; i < repo.size(); i++) {
        info += repo.at(i)->getClientInfo() + "\n";
    }

    return info;
}

int ClientRepo::size()
{
    return repo.size();
}

std::vector<ClientPtr> ClientRepo::findBy(ClientPredicate predicate) const
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

std::vector<ClientPtr> ClientRepo::findAll() const
{
    return findBy(alwaysTrue);
}

// bool matchID(ClientPtr ptr, int id)
// {
//     return ptr->getPersonalID() == id;
// }

ClientPtr ClientRepo::findByPersonalId(int personalID) {
    //Predykat z parametrem to inny typ więc nie jestem w stanie stworzyc predykatu porownujacego id.
    // for (unsigned int i = 0; i < repo.size(); i++)
    // {
    //     ClientPtr client = get(i);
    //     if(client != nullptr && client->getPersonalID() == personalID) {
    //         return client;
    //     }
    // }
    // return nullptr;
    //Naprawiłem
    ClientPredicate matchID = [personalID](ClientPtr ptr)
    {
        return ptr->getPersonalID()==personalID;
    };

    std::vector<ClientPtr> found = findBy(matchID);
    if(found.size() == 0) {
        return nullptr;
    }

    return found.at(0);

}

