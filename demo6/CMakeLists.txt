cmake_minimum_required(VERSION 3.8)

project("demo6")

SET(CMAKE_CXX_FLAGS "-std=c++17")

set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_C_VISIBILITY_PRESET hidden)

include_directories(${CMAKE_CURRENT_LIST_DIR})

aux_source_directory(${CMAKE_CURRENT_LIST_DIR} SRC_DIR)
aux_source_directory(${CMAKE_CURRENT_LIST_DIR} SRC_DIR)

add_library(demo6 SHARED ${SRC_DIR})

