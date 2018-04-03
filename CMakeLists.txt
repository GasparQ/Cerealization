cmake_minimum_required(VERSION 3.0.2)
project(Cerealization CXX)

set(CMAKE_CXX_STANDARD 14)

FILE(GLOB_RECURSE CEREAL_INCLUDES ${CMAKE_SOURCE_DIR}/include/*.hpp)

FILE(GLOB_RECURSE CEREAL_SOURCES ${CMAKE_SOURCE_DIR}/src/*.cpp)

include_directories(${CMAKE_SOURCE_DIR}/include)

add_library(Cerealib ${CEREAL_SOURCES} ${CEREAL_INCLUDES})

set_target_properties(Cerealib PROPERTIES LINKER_LANGUAGE CXX)

set(CMAKE_VS_INCLUDE_INSTALL_TO_DEFAULT_BUILD 1)
install(TARGETS Cerealib DESTINATION ${PROJECT_BINARY_DIR}/lib/bin)
install(DIRECTORY include DESTINATION ${PROJECT_BINARY_DIR}/lib/include)

add_executable(ModelCereal tests/simple/test_model_cereal.cpp)
target_link_libraries(ModelCereal Cerealib)

add_executable(AdvancedExemple1 tests/advanced/test_1.cpp)
target_link_libraries(AdvancedExemple1 Cerealib)

enable_testing()

if (WIN32)
    set(EXE_SUFFIX ".exe")
else()
    set(EXE_SUFFIX "")
endif()

add_test(cereal_test ${EXECUTABLE_OUTPUT_PATH}/ModelCereal${EXE_SUFFIX})
