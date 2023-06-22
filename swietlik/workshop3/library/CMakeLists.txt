cmake_minimum_required(VERSION 3.4)
project(MathLibrary)

set(SOURCE_FILES
        src/math_helpers.cpp
        src/model/client.cpp include/model/client.h src/model/adress.cpp include/model/adress.h src/model/rent.cpp include/model/rent.h src/model/vehicle.cpp include/model/vehicle.h)
#Utwórz bibliotekę typu STATIC, SHARED albo MODULE ze wskazanych źródeł
add_library(MathLibrary ${SOURCE_FILES})

target_include_directories(MathLibrary PUBLIC include)