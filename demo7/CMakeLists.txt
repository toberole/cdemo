cmake_minimum_required(VERSION 3.8)

project("ios_lib_demo7")

# add_definitions(-std=c++17)

include_directories(${CMAKE_CURRENT_LIST_DIR})

aux_source_directory(${CMAKE_CURRENT_LIST_DIR} SRC_DIR)
aux_source_directory(${CMAKE_CURRENT_LIST_DIR} SRC_DIR)

# SHARED STATIC
add_library(ios_lib STATIC ${SRC_DIR})

# set_target_properties(ios_lib PROPERTIES
# FRAMEWORK TRUE
# FRAMEWORK_VERSION A
# VERSION 1.0.0
# SOVERSION 1.0.0
# MACOSX_FRAMEWORK_IDENTIFIER org.cmake.MyFramework
# )

install(TARGETS ios_lib DESTINATION lib)


