cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(ParticleSim)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_definitions("-Wall" "-g")

include_directories(${CMAKE_SOURCE_DIR}/include)
file(GLOB SRC_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)

find_package(fmt CONFIG REQUIRED)


add_executable(${PROJECT_NAME} ${SRC_FILES} ${HEADER_FILES})
target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt)


### Testing code
set(PROJECT_TEST_SRC ParticleSimTests)


find_package(GTest CONFIG REQUIRED)
include(GoogleTest)
enable_testing()

add_executable(${PROJECT_TEST_SRC})

target_sources(${PROJECT_TEST_SRC} PRIVATE tests/ParticleSimTests.cpp)
target_link_libraries(${PROJECT_TEST_SRC} PRIVATE GTest::gtest GTest::gtest_main)
gtest_discover_tests(${PROJECT_TEST_SRC})
