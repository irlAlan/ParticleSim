cmake_minimum_required(VERSION 3.12 FATAL_ERROR)

# set(CMAKE_TOOLCHAIN_FILE "~/Downloads/vcpkg/scripts/buildsystems/vcpkg.cmake")

# set(CMAKE_TOOLCHAIN_FILE ON)

project(ParticleSim)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

add_definitions("-Wall" "-g")

include_directories(${CMAKE_SOURCE_DIR}/include)
file(GLOB SRC_FILES ${CMAKE_SOURCE_DIR}/src/*.cpp)
set(GLAD_SRC ${CMAKE_SOURCE_DIR}/src/glad/glad.c)
file(GLOB HEADER_FILES ${CMAKE_SOURCE_DIR}/include/*.h)

find_package(fmt CONFIG REQUIRED)
find_package(glfw3)
#find_package(glad)
find_package(Eigen3 3.4 REQUIRED)


add_executable(${PROJECT_NAME} ${SRC_FILES} ${GLAD_SRC} ${HEADER_FILES})
target_link_libraries(${PROJECT_NAME} PRIVATE fmt::fmt glfw Eigen3::Eigen)
