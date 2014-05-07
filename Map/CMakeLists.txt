cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME map)
project(${PROJECT_NAME})

ADD_DEFINITIONS(
    -std=c++11 # Or -std=c++0x
    # Other flags
)

file(GLOB SOURCES *.cpp ./OccupancyMap/*.cpp)
file(GLOB HEADERS *.hpp ./OccupancyMap/*.hpp)

add_library(${PROJECT_NAME} SHARED ${SOURCES} ${HEADERS})
