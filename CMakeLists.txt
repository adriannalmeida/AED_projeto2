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

find_package(Doxygen)
if(DOXYGEN_FOUND)
    set(BUILD_DOC_DIR "${CMAKE_SOURCE_DIR}/documentation")
    if(NOT EXISTS "${BUILD_DOC_DIR}")
        file(MAKE_DIRECTORY "${BUILD_DOC_DIR}")
    endif()

    set(DOXYGEN_IN "../Project_AED_pt2/documentation/Doxyfile")
    set(DOXYGEN_OUT "${CMAKE_CURRENT_BINARY_DIR}/Doxyfile")
    configure_file("${DOXYGEN_IN}" "${DOXYGEN_OUT}" @ONLY)

    message("Doxygen build started")
    add_custom_target(Doxygen ALL
            COMMAND "${DOXYGEN_EXECUTABLE}" "${DOXYGEN_OUT}"
            WORKING_DIRECTORY "${CMAKE_CURRENT_BINARY_DIR}"
            COMMENT "Generating API documentation with Doxygen"
            VERBATIM)
else(DOXYGEN_FOUND)
    message("Doxygen needs to be installed to generate the documentation.")
endif(DOXYGEN_FOUND)