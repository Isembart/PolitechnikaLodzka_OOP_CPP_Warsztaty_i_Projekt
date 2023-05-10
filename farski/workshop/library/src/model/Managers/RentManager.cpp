#include "model/Managers/RentManager.h"
#include "model/ClientTypes/Default.h"
#include "model/ClientTypes/Bronze.h"
#include "model/ClientTypes/Silver.h"
#include "model/ClientTypes/Gold.h"
#include "model/ClientTypes/Platinum.h"
#include "model/ClientTypes/Diamond.h"
RentManager::RentManager()
{
    currentRents = RentRepository();
    archiveRents = RentRepository();
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

RentPtr RentManager::getVehicleRent(VehiclePtr vehicle)
{
    RentPredicate matchVehicle = [vehicle](RentPtr ptr) {
        return ptr->getVehicle() == vehicle;
    };
    auto found =  currentRents.findBy(matchVehicle);
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
        sum += rents.at(i)->getRentCost();
    }

    return sum;
}

    RentPtr RentManager::rentVehicle(ClientPtr client, VehiclePtr vehicle, boost::posix_time::ptime startTime=boost::posix_time::not_a_date_time)
    {
        //klient i pojazd nie są archiwalne -> Client i Vehicle Manager nie zwrócą archiwalnego pojazdu i klienta
        if(getAllClientRents(client).size() >= client->getMaxVehicles()) {
            //Limit pojazdów wykorzystany
            return nullptr;
        }

        if(getVehicleRent(vehicle) != nullptr) {
            //Pojazd jest wypozyczony
            return nullptr;
        }

        currentRents.add(std::make_shared<Rent>(id,client,vehicle,startTime));
        id++;

        return nullptr;
    }

    void RentManager::returnVehicle(VehiclePtr vehicle) {
        RentPtr found = getVehicleRent(vehicle);
        if(found != nullptr) {
            found->endRent(boost::posix_time::not_a_date_time);
            currentRents.remove(found);
            archiveRents.add(found);
            changeClientType(found->getClient());
        }
    }

    void RentManager::changeClientType(ClientPtr client)
    {
        double sum = checkClientRentBalance(client);
        if(sum <100) {
            client->setClientType(std::make_shared<Default>());
        }
        else if( sum < 200) { 
            client->setClientType(std::make_shared<Bronze>());
        }
        else if( sum < 400) { 
            client->setClientType(std::make_shared<Silver>());
        }
        else if( sum < 800) { 
            client->setClientType(std::make_shared<Gold>());
        }
        else if( sum < 1600) { 
            client->setClientType(std::make_shared<Platinum>());
        }
        else if( sum >=1600) { 
            client->setClientType(std::make_shared<Diamond>());
        }
    }