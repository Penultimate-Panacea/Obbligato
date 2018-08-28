cmake_minimum_required(VERSION 3.9)
project(Obbligato)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(CMAKE_CXX_STANDARD 11)

add_executable(Obbligato main.cpp ObbligatoExeceptions.h rlcg.hpp Seeder.cpp Seeder.h)
# BaseEightyNine.cpp BaseEightyNine.h
# FIXME CMakeFiles/Obbligato.dir/BaseEightyNine.cpp.o:BaseEightyNine.cpp:(.rdata$.refptr._ZN14BaseEightyNine11equivalenceE[.refptr._ZN14BaseEightyNine11equivalenceE]+0x0): undefined reference to `BaseEightyNine::equivalence'
