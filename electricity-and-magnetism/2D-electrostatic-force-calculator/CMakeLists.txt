cmake_minimum_required(VERSION 3.15)
project(electrostatic_force_calculator)

set(CMAKE_CXX_STANDARD 17)

add_executable(electrostatic_force_calculator main.cpp Charge.cpp Charge.h constants.h)