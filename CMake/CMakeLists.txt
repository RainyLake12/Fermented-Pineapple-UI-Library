cmake_minimum_required(VERSION 3.5)
project(FPUL)

set(PROJECT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/..")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${PROJECT_DIR}/bin")

file(GLOB_RECURSE SRC "${PROJECT_DIR}/src/*.cpp")

add_executable(FPUL ${SRC})

target_include_directories(FPUL PUBLIC "${PROJECT_DIR}/include")