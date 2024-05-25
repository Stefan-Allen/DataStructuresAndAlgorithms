cmake_minimum_required(VERSION 3.28)

project(DataStructuresAndAlgorithms)

set(CMAKE_CXX_STANDARD 17)

add_executable(DataStructuresAndAlgorithms
        main.cpp
        Car.h
        Car.cpp
        ParkingSpace.h
        ParkingSpace.cpp
        ParkingLot.h
        ParkingLot.cpp
)
