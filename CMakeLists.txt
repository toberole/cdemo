cmake_minimum_required(VERSION 3.8)

add_definitions(-std=c++11)

aux_source_directory(${CMAKE_CURRENT_LIST_DIR}/src SRC_DIR)

include_directories(${CMAKE_CURRENT_LIST_DIR}/include)

add_executable(main ${SRC_DIR})

# Linux 需要添加thread库
if(${CMAKE_SYSTEM_NAME} STREQUAL "Linux")
	set(THREADS_PREFER_PTHREAD_FLAG ON)
	find_package(Threads REQUIRED)
	target_link_libraries(main Threads::Threads)
endif()