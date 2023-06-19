#ifndef RentRepoHeader
#define RentRepoHeader

#include <vector>

#include "model/Repositories/RentRepo.h"
#include "typedefs.hpp"

class RentRepo
{
private:
    std::vector<RentPtr> repo;
public:
    RentRepo(/* args */);
    ~RentRepo();
    RentPtr get(int index) const;
    void add(RentPtr client);
    void remove(RentPtr client);
    std::string report();
    int size();

    std::vector<RentPtr> findBy(RentPredicate) const;
    std::vector<RentPtr> findAll() const;
};


#endif