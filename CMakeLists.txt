cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

project(ParticleSim)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_definitions("-Wall" "-g")


find_package(fmt CONFIG REQUIRED)
find_package(glfw3)
find_package(Eigen3 3.4 REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/include)
set(GLAD_SRC ${CMAKE_SOURCE_DIR}/src/glad/glad.c)
file(GLOB SRC_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)
file(GLOB HEADER_FILES ${CMAKE_SOURCE_DIR}/include/ParticleSim/*.h)

add_executable(${PROJECT_NAME} ${SRC_FILES} ${GLAD_SRC} ${HEADER_FILES})
target_link_libraries(${PROJECT_NAME} fmt::fmt glfw Eigen3::Eigen)
