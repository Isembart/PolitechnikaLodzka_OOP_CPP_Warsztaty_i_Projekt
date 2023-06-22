cmake_minimum_required(VERSION 3.4)
project(VmRentalLibrary)

set(SOURCE_FILES
        src/model/Client.cpp
        src/model/ClientType.cpp
        src/model/ClientTypes/Default.cpp
        src/model/ClientTypes/Pro.cpp
        src/model/VirtualMachine.cpp
        src/model/Rent.cpp
        src/model/Repositories/ClientRepo.cpp 
        src/model/Repositories/RentRepo.cpp 
        src/model/Repositories/StorageContainer.cpp
        src/model/Repositories/Mainframe.cpp
        src/model/Managers/RentManager.cpp 
        src/model/Managers/MainframeManager.cpp 
        src/model/Managers/ClientManager.cpp 
        )
#Utwórz bibliotekę typu STATIC, SHARED albo MODULE ze wskazanych źródeł
add_library(VmRentalLibrary ${SOURCE_FILES})

target_include_directories(VmRentalLibrary PUBLIC include)


enable_testing() # dodane wcześniej w punkcie 2
find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

set(modelTestFiles 
        test/master.cpp 
        test/ClientTest.cpp
        test/RentTest.cpp
        ) # tu w przyszłości będą dodawane pliki źródłowe testów


set(repoTestFiles
        test/master.cpp
        test/ClientRepositoryTest.cpp
        test/RentRepositoryTest.cpp 
        )

set(managerTestFiles
        test/master.cpp
        test/RentManagerTest.cpp
        test/ClientManagerTest.cpp
        test/MainFrameTest.cpp
        test/MainFrameMenagerTest.cpp)
        
add_executable (vmRentalModelTest ${modelTestFiles})
add_executable (repositoriesTest ${repoTestFiles})
add_executable (managerTest ${managerTestFiles})

#dołącz bibliotekę z testowanymi klasami oraz bibliotekę boost.test do programu testów
target_link_libraries (vmRentalModelTest PUBLIC
        VmRentalLibrary
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )

target_link_libraries (repositoriesTest PUBLIC
        VmRentalLibrary
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )

target_link_libraries (managerTest PUBLIC
        VmRentalLibrary
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )
#dodaj test TestBiblioteki1. Instrukcji cmake add_test może być wiele.
#Dodatkowe parametry wpływają na szczegółowość generowanego raportu. Standardowo znajduje się on w Testing/Temporary.
add_test(ModelTest vmRentalModelTest
        --report_level=detailed
        --log_level=all
        --color_output=yes
        )

        add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIGURATION> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})

add_test(RepoTest repositoriesTest
        --report_level=detailed
        --log_level=all
        --color_output=yes
        )

add_test(ManagersTest managerTest
        --report_level=detailed
        --log_level=all
        --color_output=yes
)