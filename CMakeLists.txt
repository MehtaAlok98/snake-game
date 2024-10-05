cmake_minimum_required(VERSION 3.10)
project(snake VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

if(EXISTS "${CMAKE_BINARY_DIR}/generators/conan_toolchain.cmake")
    include(${CMAKE_BINARY_DIR}/generators/conan_toolchain.cmake)
endif()

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# set(SOURCES main.cpp)

set(SOURCES src/main.cpp src/apple.cpp src/grid.cpp src/snake.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})

find_package(SDL2)
target_link_libraries(${PROJECT_NAME} PRIVATE SDL2::SDL2main)

target_include_directories(${PROJECT_NAME} PRIVATE include/)

# file(COPY assets DESTINATION ${CMAKE_RUNTIME_OUTPUT_DIRECTORY})