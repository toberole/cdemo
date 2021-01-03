cmake_minimum_required(VERSION 3.8)

project (example-ios C CXX)

MESSAGE( STATUS "CMAKE_CXX_FLAGS: " ${CMAKE_CXX_FLAGS} )

# Source files
set(SOURCES
  test.c
)

# Headers
set(HEADERS
  test.h
)

set(BU)

# Library
# if(BUILD_SHARED)
#   add_library (example SHARED ${SOURCES} ${HEADERS})
#   message(STATUS "Building shared version...")
# else()
#   add_library (example STATIC ${SOURCES} ${HEADERS})
#   message(STATUS "Building static version...")
# endif()

add_library (example SHARED ${SOURCES} ${HEADERS})
  

if(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)
  set(CMAKE_INSTALL_PREFIX ${example-ios_SOURCE_DIR}/../example-app/example-lib CACHE PATH "Install path" FORCE)
endif(CMAKE_INSTALL_PREFIX_INITIALIZED_TO_DEFAULT)

set_xcode_property(example GCC_GENERATE_DEBUGGING_SYMBOLS YES "All")

# Installation
install (TARGETS example DESTINATION lib)
install (FILES ${HEADERS} DESTINATION include)
