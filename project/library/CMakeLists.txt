cmake_minimum_required(VERSION 3.4)
project(CarRentalLibrary)

set(SOURCE_FILES
        src/model/Client.cpp
)
#Utwórz bibliotekę typu STATIC, SHARED albo MODULE ze wskazanych źródeł
add_library(CarRentalLibrary ${SOURCE_FILES})


target_include_directories(CarRentalLibrary PUBLIC PIERDOLONEGOWNO)

enable_testing() # dodane wcześniej w punkcie 2
find_package (Boost 1.60.0 COMPONENTS "unit_test_framework" REQUIRED)

include_directories(
        ${CMAKE_CURRENT_SOURCE_DIR}/include
        ${Boost_INCLUDE_DIRS}
)

set(SOURCE_TEST_FILES test/master.cpp 
        ) # tu w przyszłości będą dodawane pliki źródłowe testów

add_executable (CarRentalLibraryTest ${SOURCE_TEST_FILES})

#dołącz bibliotekę z testowanymi klasami oraz bibliotekę boost.test do programu testów
target_link_libraries (CarRentalLibraryTest PUBLIC
        CarRentalLibrary
        ${Boost_UNIT_TEST_FRAMEWORK_LIBRARY}
        )

#dodaj test TestBiblioteki1. Instrukcji cmake add_test może być wiele.
#Dodatkowe parametry wpływają na szczegółowość generowanego raportu. Standardowo znajduje się on w Testing/Temporary.
add_test(CarRentalLibraryTest1 LibraryTest
        --report_level=detailed
        --log_level=all
        --color_output=yes
        )

        add_custom_target(check ${CMAKE_COMMAND} -E env CTEST_OUTPUT_ON_FAILURE=1 BOOST_TEST_LOG_LEVEL=all
        ${CMAKE_CTEST_COMMAND} -C $<CONFIGURATION> --verbose
        WORKING_DIRECTORY ${CMAKE_BINARY_DIR})