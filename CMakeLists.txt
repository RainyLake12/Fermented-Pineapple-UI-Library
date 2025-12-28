cmake_minimum_required(VERSION 3.10)
project(FPUL)

set(PROJECT_DIR "${CMAKE_CURRENT_SOURCE_DIR}/")
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY "${PROJECT_DIR}/bin")

file(GLOB_RECURSE SRC "${PROJECT_DIR}/src/*.cpp")

add_library(FPUL STATIC ${SRC})

target_include_directories(FPUL PUBLIC "${PROJECT_DIR}/include")