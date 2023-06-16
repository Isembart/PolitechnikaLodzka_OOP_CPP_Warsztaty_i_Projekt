cmake_minimum_required(VERSION 3.4)

project(CarRentalRun)

#Ustaw we własnej zmiennej SOURCE_FILES zbiór plików źródłowych projektu
set(SOURCE_FILES src/main.cpp)

#Włącz powyższy zbiór plików do zbudowania programu wykonywalnego CarRentalRun
add_executable(CarRentalRun ${SOURCE_FILES})

#dodanie bibliotek
# target_link_libraries(CarRentalRun CarRentalLibrary)

#Dołącz katalog include podprojektu CarRentalRun do globalnej listy. Dzięki temu każdy inny podprojekt będzie ten katalog "widział"
target_include_directories(CarRentalRun PUBLIC include)