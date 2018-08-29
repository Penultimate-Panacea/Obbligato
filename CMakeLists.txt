cmake_minimum_required(VERSION 3.9)
project(Obbligato)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(CMAKE_CXX_STANDARD 11)

add_executable(Obbligato main.cpp BaseEightyNine.cpp BaseEightyNine.h rlcg.hpp Seeder.cpp Seeder.h)
#
# FIXME Including the above two files leads to the following error on build:
# CMakeFiles/Obbligato.dir/BaseEightyNine.cpp.o:BaseEightyNine.cpp:(.rdata$.refptr._ZN14BaseEightyNine11equivalenceE[.refptr._ZN14BaseEightyNine11equivalenceE]+0x0): undefined reference to `BaseEightyNine::equivalence'
