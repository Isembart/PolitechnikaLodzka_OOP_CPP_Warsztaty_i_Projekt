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
    RentPtr get(int index);
    void add(RentPtr client);
    void remove(RentPtr client);
    std::string report();
    int size();
};
 

#endif