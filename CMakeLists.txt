cmake_minimum_required(VERSION 3.26)
project(2Projeto)

set(CMAKE_CXX_STANDARD 17)

add_executable(2Projeto main.cpp
        src/menu.cpp
        src/menu.h
        src/Airport.cpp
        src/Airport.h
        src/Coordinates.cpp
        src/Coordinates.h
        src/Country.cpp
        src/Country.h
        src/Graph.h
        src/Flights.cpp
        src/Flights.h
        src/Airline.cpp
        src/Airline.h
        src/DataParser.cpp
        src/DataParser.h)
