#include "model/ClientTypes/Pro.hpp"
#include "model/ClientTypes/Default.hpp"
#include "model/Managers/RentManager.hpp"


class ClientRentException : public std::exception {
    private:
    std::string message;

    public:
    ClientRentException(std::string msg) : message(msg) {}
    std::string errorMessage () {
        return message;
    }
};


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

// double RentManager::checkClientRentBalance(ClientPtr client)
// {
//     RentPredicate matchClient = [client](RentPtr ptr) {
//         return ptr->getClient() == client;
//     };
//     std::vector<RentPtr> rents = archiveRents.findBy(matchClient);
//     double sum = 0;
//     for (int i = 0; i < rents.size(); i++)
//     {
//         sum += rents.at(i)->getRentHours();
//     }

//     return sum;
// }

RentPtr RentManager::rentVirtualMachine(ClientPtr client, VirtualMachinePtr VirtualMachine, boost::posix_time::ptime startTime=boost::posix_time::not_a_date_time)
{
    //EXCEPTION 
    try{
        //klient i maszyna nie są archiwalne -> Client i VirtualMachine Manager nie zwrócą archiwalnej maszyny i klienta
        if(getAllClientRents(client).size() >= client->getMaxComputers()) {
            //Limit maszyn wykorzystany
            throw ClientRentException(std::string("Limit maszyn wykorzystany"));
        }

        if(VirtualMachine->getRAM()>client->getMaxRAM() && client->getMaxRAM() != -1){
            //wartosc Ramu jest za duza niz pozwala na to typ klienta
            throw ClientRentException(std::string("Limit Ramu wykorzystany"));
            
        }

        if(getVirtualMachineRent(VirtualMachine) != nullptr) {
            //maszyna jest wypozyczony
            throw ClientRentException(std::string("Maszyna jest juz wypozyczona"));
        }

        RentPtr result = std::make_shared<Rent>(id,client,VirtualMachine,startTime);
        currentRents.add(result);
        id++;

        return result;
    }
    catch(ClientRentException exc) {
        std::cout << "██████████████ Error ocurred: " << client->getClientInfo() << ": "<< exc.errorMessage()<<"████████████████████"<<std::endl ;
        return nullptr;
    }
}


void RentManager::returnVirtualMachine(VirtualMachinePtr VirtualMachine) {
    RentPtr found = getVirtualMachineRent(VirtualMachine);
    if(found != nullptr) {
        found->endRent(boost::posix_time::not_a_date_time);
        currentRents.remove(found);
        archiveRents.add(found);
        // changeClientType(found->getClient());
    }
}

//Trzeba ustalić balans od którego jest wersja pro??
// void RentManager::changeClientType(ClientPtr client)
// {
//     double sum = checkClientRentBalance(client);
//     if(sum <500) {
//         client->setClientType(std::make_shared<Default>());
//     }
//     else {
//         client->setClientType(std::make_shared<Pro>());

       
//     }
// }

 std::string RentManager::info()
        {
            return currentRents.report();
        }