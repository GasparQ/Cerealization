cmake_minimum_required(VERSION 2.8)
project(Cerealization)

set(CMAKE_CXX_STANDARD 14)

FILE(GLOB CEREAL_INCLUDES Cerealizable/*.hpp Cerealizer/*/*.hpp)

FILE(GLOB CEREAL_SOURCES src/*/*.cpp)

include_directories(${CMAKE_SOURCE_DIR})

add_library(Cerealization ${CEREAL_SOURCES} ${CEREAL_INCLUDES})

add_executable(CerealTest main.cpp)

target_link_libraries(CerealTest Cerealization)

set(CMAKE_VS_INCLUDE_INSTALL_TO_DEFAULT_BUILD 1)
install(TARGETS Cerealization DESTINATION ${PROJECT_BINARY_DIR}/lib/bin)
install(DIRECTORY Cerealizable DESTINATION ${PROJECT_BINARY_DIR}/lib/include)
install(DIRECTORY Cerealizer DESTINATION ${PROJECT_BINARY_DIR}/lib/include)
