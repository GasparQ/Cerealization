cmake_minimum_required(VERSION 3.8)
project(Cerealizable)

set(CMAKE_CXX_STANDARD 14)

FILE(GLOB CEREAL_INCLUDES Cerealizable/*.hpp Cerealizer/*/*.hpp)

FILE(GLOB CEREAL_SOURCES main.cpp src/*.cpp Cerealizer/*/*.cpp)

include_directories(${CMAKE_SOURCE_DIR})

add_executable(Cerealizable ${CEREAL_SOURCES} ${CEREAL_INCLUDES})