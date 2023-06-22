#include <boost/test/unit_test.hpp>
#include "model/Repositories/RentRepo.hpp"
#include "model/Repositories/StorageContainer.h"
#include "model/Rent.hpp"
#include <boost/test/unit_test.hpp>
#include <memory>

struct TestSuiteRentRepoFixture {
    StorageContainer container;
    TestSuiteRentRepoFixture() {

    }
    ~TestSuiteRentRepoFixture() {

    }
};

BOOST_FIXTURE_TEST_SUITE(TestSuiteRentRepo,TestSuiteRentRepoFixture)


    BOOST_FIXTURE_TEST_SUITE(TestSuiteRenttRepo,TestSuiteRentRepoFixture)


        BOOST_AUTO_TEST_CASE(getValidIndexTest) {
            BOOST_TEST(container.getRentRepo()->get(0)->getId() == 666);
            BOOST_TEST(container.getRentRepo()->get(1)->getId() == 333);
        }

        BOOST_AUTO_TEST_CASE(getInvalidIndextText) {
            BOOST_TEST(container.getRentRepo()->get(-40) == nullptr);
            BOOST_TEST(container.getRentRepo()->get(-52) == nullptr);
        }


        BOOST_AUTO_TEST_CASE(sizeTest) {
            BOOST_TEST_REQUIRE(container.getRentRepo()->size() == 2);
        }


        BOOST_AUTO_TEST_CASE(reportTest) {
            std::string info = container.getRentRepo() ->get(0)->getRentInfo() + "\n" + container.getRentRepo()->get(1)->getRentInfo() + "\n";
            BOOST_TEST(container.getRentRepo()->report() == info);
        }


    BOOST_AUTO_TEST_SUITE_END()
}

