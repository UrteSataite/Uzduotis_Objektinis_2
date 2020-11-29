cmake_minimum_required(VERSION 3.17)

project(Uzduotis)

set(CMAKE_CXX_STANDARD 17)

add_executable(Uzduotis Uzduotis.cpp strukturos_v.h 
strukturos.h outputai_v.h outputai.h funkcijos_v.h funkcijos.h failu_generavimas.h
failu_generavimas.cpp funkcijos.cpp funkcijos_v.cpp outputai.cpp outputai_v.cpp)