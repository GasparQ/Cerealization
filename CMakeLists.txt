cmake_minimum_required(VERSION 3.8)
project(Cerealization)

set(CMAKE_CXX_STANDARD 14)

FILE(GLOB INCLUDE_FILES includes/*.hpp)

FILE(GLOB SOURCE_FILES main.cpp src/*.cpp)

include_directories(includes)

add_executable(Cerealization ${SOURCE_FILES} ${INCLUDE_FILES})