cmake_minimum_required(VERSION 3.8)

project("lib1")

set(CMAKE_CXX_VISIBILITY_PRESET hidden)
set(CMAKE_C_VISIBILITY_PRESET hidden)

SET(CMAKE_CXX_FLAGS "-std=c++17")

include_directories(${CMAKE_CURRENT_LIST_DIR})

aux_source_directory(${CMAKE_CURRENT_LIST_DIR} SRC_DIR)
aux_source_directory(${CMAKE_CURRENT_LIST_DIR} SRC_DIR)

link_directories(${CMAKE_CURRENT_LIST_DIR})

add_library(lib1 STATIC ${SRC_DIR})
add_executable(lib1_exe ${SRC_DIR})

target_link_libraries(
    lib1

    demo6
)

target_link_libraries(
    lib1_exe

    demo6
)

