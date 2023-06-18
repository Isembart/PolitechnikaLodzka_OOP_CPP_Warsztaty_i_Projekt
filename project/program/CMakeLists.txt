cmake_minimum_required(VERSION 3.4)

project(VmRentalRun)

#Ustaw we własnej zmiennej SOURCE_FILES zbiór plików źródłowych projektu
set(SOURCE_FILES src/main.cpp)

#Włącz powyższy zbiór plików do zbudowania programu wykonywalnego VmRentalRun
add_executable(VmRentalRun ${SOURCE_FILES})

#dodanie bibliotek
target_link_libraries(VmRentalRun VmRentalLibrary)

#Dołącz katalog include podprojektu VmRentalRun do globalnej listy. Dzięki temu każdy inny podprojekt będzie ten katalog "widział"
target_include_directories(VmRentalRun PUBLIC include)