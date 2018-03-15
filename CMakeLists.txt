cmake_minimum_required(VERSION 3.0.2)
project(Cerealization CXX)

set(CMAKE_CXX_STANDARD 14)

FILE(GLOB_RECURSE CEREAL_INCLUDES ${CMAKE_SOURCE_DIR}/include/*.hpp)

FILE(GLOB_RECURSE CEREAL_SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_library(Cerealization ${CEREAL_SOURCES} ${CEREAL_INCLUDES})

set_target_properties(Cerealization PROPERTIES LINKER_LANGUAGE CXX)

set(CMAKE_VS_INCLUDE_INSTALL_TO_DEFAULT_BUILD 1)
install(TARGETS Cerealization DESTINATION ${PROJECT_BINARY_DIR}/lib/bin)
install(DIRECTORY include DESTINATION ${PROJECT_BINARY_DIR}/lib/include)
