#include "repositories/RentRepository.h"
#include "model/Rent.h"
RentRepository::RentRepository()
{
}

RentRepository::~RentRepository()
{
}

RentPtr RentRepository::get(int index)
{
    if(index >= repo.size() || index < 0) {
        return nullptr;
    }

    return repo.at(index);
}

void RentRepository::add(RentPtr client)
{
    repo.push_back(client);
}

void RentRepository::remove(RentPtr client)
{
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
