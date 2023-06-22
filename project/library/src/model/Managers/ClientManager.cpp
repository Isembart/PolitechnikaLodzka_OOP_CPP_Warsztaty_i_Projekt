#include "model/Managers/ClientManager.hpp"

ClientManager::ClientManager() {}

ClientManager::~ClientManager() {}



ClientPtr ClientManager::registerClient(const std::string &firstname, const std::string &lastName, const int &personalID, ClientTypePtr type)
{
    ClientPtr existingClient = getClient(personalID);
    if(existingClient == nullptr) {
        ClientPtr newClient = std::make_shared<Client>(firstname,lastName,personalID,type);
        repo.add(newClient);
        return newClient;
    }
    return existingClient;
}

void ClientManager::unregisterClient(ClientPtr _client)
{
    getClient(_client->getPersonalID())->setArchive(true);
}

void ClientManager::unregisterClient(int id)
{
    getClient(id)->setArchive(true);
}

ClientPtr ClientManager::getClient(int id)
{
    return repo.findByPersonalId(id);
}

std::vector<ClientPtr> ClientManager::findClients(ClientPredicate predicate)
{
    ClientPredicate match = [predicate](ClientPtr ptr)
    {
        return !ptr->isArchive() * predicate(ptr);
    };
    return repo.findBy(match);
}

std::vector<ClientPtr> ClientManager::findAllClients()
{
    ClientPredicate alwaysTrue = [](ClientPtr ptr){
        return true;
    };

  
    return findClients(alwaysTrue);
}

std::string ClientManager::info()
{
    return repo.report();
}