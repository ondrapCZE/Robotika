cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME motor_driver_md22)
project(${PROJECT_NAME})

ADD_DEFINITIONS(
    -std=c++11 # Or -std=c++0x
    # Other flags
)

file(GLOB SOURCES *.cpp)
file(GLOB HEADERS *.hpp)

add_library(${PROJECT_NAME} SHARED ${SOURCES} ${HEADERS})
