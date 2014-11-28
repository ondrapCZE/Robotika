cmake_minimum_required(VERSION 2.8)

set(PROJECT_NAME Settings)
project(${PROJECT_NAME})

ADD_DEFINITIONS(
    -std=c++11 # Or -std=c++0x
    # Other flags
)

file(GLOB SOURCES *.cpp)
file(GLOB HEADERS *.hpp)

find_package( Boost REQUIRED COMPONENTS program_options )
include_directories( ${Boost_INCLUDE_DIRS} )

add_library(${PROJECT_NAME} SHARED ${SOURCES} ${HEADERS})
target_link_libraries( ${PROJECT_NAME} ${Boost_LIBRARIES})
