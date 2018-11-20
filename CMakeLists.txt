cmake_minimum_required(VERSION 3.9)
project(Obbligato)

include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(CMAKE_CXX_STANDARD 11)

add_executable(Obbligato main.cpp BaseEightyNine.cpp BaseEightyNine.h rlcg.hpp Seeder.cpp Seeder.h ABCFilemaker.cpp ABCFilemaker.hpp CustomExceptions.hpp)

