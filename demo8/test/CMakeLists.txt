cmake_minimum_required(VERSION 3.8)

project("test_lib1_lib2")

SET(CMAKE_CXX_FLAGS "-std=c++17")

include_directories(${CMAKE_CURRENT_LIST_DIR})

aux_source_directory(${CMAKE_CURRENT_LIST_DIR} SRC_DIR)
aux_source_directory(${CMAKE_CURRENT_LIST_DIR} SRC_DIR)

link_directories(${CMAKE_CURRENT_LIST_DIR})

add_executable(test_lib1_lib2 ${SRC_DIR})

target_link_libraries(
    test_lib1_lib2

    demo6
    lib1
    lib2
)

