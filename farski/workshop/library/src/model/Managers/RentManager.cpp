#include "model/Managers/RentManager.h"

RentManager::RentManager()
{
}

RentManager::~RentManager()
{
}

std::vector<RentPtr> RentManager::getAllClientRents(ClientPtr client)
{
    RentPredicate matchClient = [client](RentPtr ptr) {
        return ptr->getClient() == client;
    };
    currentRents.findBy(matchClient);
}

RentPtr RentManager::getVehicleRent(VehiclePtr vehicle)
{
    RentPredicate matchVehicle = [vehicle](RentPtr ptr) {
        return ptr->getVehicle() == vehicle;
    };
    currentRents.findBy(matchVehicle);
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
