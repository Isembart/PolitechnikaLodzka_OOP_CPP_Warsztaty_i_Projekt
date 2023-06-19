#include <algorithm> //std::remove
#include "model/Rent.hpp"
#include "typedefs.hpp"
#include "model/Repositories/RentRepo.h"

RentRepo::RentRepo()
{
}

RentRepo::~RentRepo()
{
}

RentPtr RentRepo::get(int index) const
{
    if(index >= repo.size() || index < 0) {
        return nullptr;
    }

    return repo.at(index);
}

void RentRepo::add(RentPtr client)
{
    if(client == nullptr) return;
    repo.push_back(client);
}

void RentRepo::remove(RentPtr client)
{
    if(client == nullptr) return;
    auto newEnd = std::remove(repo.begin(),repo.end(),client);
    repo.erase(newEnd,repo.end());
}

std::string RentRepo::report()
{
    std::string info = "";
    for(int i = 0; i < repo.size(); i++) {
        info += repo.at(i)->getRentInfo() + "\n";
    }

    return info;
}

int RentRepo::size()
{
    return repo.size();
}

std::vector<RentPtr> RentRepo::findBy(RentPredicate predicate) const
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

// bool alwaysTrue(RentPtr ptr) {
//     return true;
// }

std::vector<RentPtr> RentRepo::findAll() const
{
    RentPredicate all = [](RentPtr ptr) {
        return true;
    };
    return findBy(all);
}