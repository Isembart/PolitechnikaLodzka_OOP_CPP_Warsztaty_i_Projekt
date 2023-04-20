#include <boost/test/unit_test.hpp>
#include "repositories/RentRepository.h"
#include "repositories/StorageContainer.h"

struct TestSuiteRentRepoFixture {
    StorageContainer container;
    TestSuiteRentRepoFixture() {

    }
    ~TestSuiteRentRepoFixture() {

    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRentRepo,TestSuiteRentRepoFixture)


BOOST_AUTO_TEST_SUITE_END()