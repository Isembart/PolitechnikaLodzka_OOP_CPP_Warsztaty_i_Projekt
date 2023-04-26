#ifndef RentRepoHeader
#define RentRepoHeader

#include <vector>

#include "model/Rent.h"
#include "typyedefs.h"

class RentRepository
{
private:
    std::vector<RentPtr> repo;
public:
    RentRepository(/* args */);
    ~RentRepository();
    RentPtr get(int index) const;
    void add(RentPtr client);
    void remove(RentPtr client);
    std::string report();
    int size();

    std::vector<RentPtr> findBy(RentPredicate) const;
    std::vector<RentPtr> findAll() const;
};
 

#endif