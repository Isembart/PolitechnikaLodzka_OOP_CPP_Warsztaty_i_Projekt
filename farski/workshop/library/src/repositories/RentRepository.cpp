#include <algorithm> //std::remove
#include "repositories/RentRepository.h"
#include "model/Rent.h"
RentRepository::RentRepository()
{
}

RentRepository::~RentRepository()
{
}

RentPtr RentRepository::get(int index) const
{
    if(index >= repo.size() || index < 0) {
        return nullptr;
    }

    return repo.at(index);
}

void RentRepository::add(RentPtr client)
{
    if(client == nullptr) return;
    repo.push_back(client);
}

void RentRepository::remove(RentPtr client)
{
    if(client == nullptr) return;
    auto newEnd = std::remove(repo.begin(),repo.end(),client);
    repo.erase(newEnd,repo.end());
}

std::string RentRepository::report()
{
    std::string info = "";
    for(int i = 0; i < repo.size(); i++) {
        info += repo.at(i)->getRentInfo() + "\n";
    } 

    return info;
}

int RentRepository::size()
{
    return repo.size();
}

std::vector<RentPtr> RentRepository::findBy(RentPredicate predicate) const
{
    std::vector<RentPtr> found;
    for (unsigned int i = 0; i < repo.size(); i++)
    {
        RentPtr client = get(i);
        if(client != nullptr && predicate(client)) {
            found.push_back(client);
        }
    } 
    return found;
}

bool alwaysTrue(RentPtr ptr) {
    return true;
}

std::vector<RentPtr> RentRepository::findAll() const
{
    return findBy(alwaysTrue);
}