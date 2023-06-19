#include "model/ClientTypes/Pro.hpp"
#include "model/ClientTypes/Default.hpp"
#include "model/Managers/RentManager.hpp"

RentManager::RentManager()
{
    currentRents = RentRepo();
    archiveRents = RentRepo();
}

RentManager::~RentManager()
{
}

std::vector<RentPtr> RentManager::getAllClientRents(ClientPtr client)
{
    RentPredicate matchClient = [client](RentPtr ptr) {
        return ptr->getClient() == client;
    };
    return currentRents.findBy(matchClient);
}

RentPtr RentManager::getVirtualMachineRent(VirtualMachinePtr VirtualMachine)
{
    RentPredicate matchVirtualMachine = [VirtualMachine](RentPtr ptr) {
        return ptr->getVirtualMachine() == VirtualMachine;
    };
    auto found =  currentRents.findBy(matchVirtualMachine);
    if(found.size() > 0) {
        return found.at(0);
    }
    return nullptr;
}

std::vector<RentPtr> RentManager::findRents(RentPredicate predicate)
{
    return currentRents.findBy(predicate);
}

std::vector<RentPtr> RentManager::findAllRents()
{
    return currentRents.findAll();
}

double RentManager::checkClientRentBalance(ClientPtr client)
{
    RentPredicate matchClient = [client](RentPtr ptr) {
        return ptr->getClient() == client;
    };
    std::vector<RentPtr> rents = archiveRents.findBy(matchClient);
    double sum = 0;
    for (int i = 0; i < rents.size(); i++)
    {
        sum += rents.at(i)->getRentHours();
    }

    return sum;
}

RentPtr RentManager::rentVirtualMachine(ClientPtr client, VirtualMachinePtr VirtualMachine, boost::posix_time::ptime startTime=boost::posix_time::not_a_date_time)
{
    //klient i maszyna nie są archiwalne -> Client i VirtualMachine Manager nie zwrócą archiwalnej maszyny i klienta
    if(getAllClientRents(client).size() >= client->getMaxComputers()) {
        //Limit maszyn wykorzystany
        return nullptr;
    }

    if(getVirtualMachineRent(VirtualMachine) != nullptr) {
        //maszyna jest wypozyczony
        return nullptr;
    }

    RentPtr result = std::make_shared<Rent>(id,client,VirtualMachine,startTime);
    currentRents.add(result);
    id++;

    return result;
}

void RentManager::returnVirtualMachine(VirtualMachinePtr VirtualMachine) {
    RentPtr found = getVirtualMachineRent(VirtualMachine);
    if(found != nullptr) {
        found->endRent(boost::posix_time::not_a_date_time);
        currentRents.remove(found);
        archiveRents.add(found);
        changeClientType(found->getClient());
    }
}

//Balans jest roboczo ustawiony na  4 ze względu na ograniczenie gib jeśli chhodzi o maszynę, trzeba jeszcze dodać ograniczenie na ilość maszyn
void RentManager::changeClientType(ClientPtr client)
{
    double sum = checkClientRentBalance(client);
    if(sum <4) {
        client->setClientType(std::make_shared<Default>());
    }
    else {
        client->setClientType(std::make_shared<Pro>());
    }
}