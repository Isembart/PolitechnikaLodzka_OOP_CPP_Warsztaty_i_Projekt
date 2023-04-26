#include <boost/test/unit_test.hpp>
#include "repositories/VehicleRepository.h"
#include "repositories/StorageContainer.h"

struct TestSuiteVehicleRepoFixture {
    StorageContainer container;
    TestSuiteVehicleRepoFixture() {

    }
    ~TestSuiteVehicleRepoFixture() {

    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteVehicleRepo,TestSuiteVehicleRepoFixture)


BOOST_AUTO_TEST_SUITE_END()