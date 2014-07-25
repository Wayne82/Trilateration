cmake_minimum_required(VERSION 2.6)

project(Trilateration)

message(STATUS "CMake version is ${CMAKE_VERSION}")

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${T_OUTPUT_DIR})
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${T_OUTPUT_DIR})
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${T_OUTPUT_DIR})

if(${T_BUILD_LIBTYPE} STREQUAL static)
  set(T_LIB_TYPE STATIC)
else()
  set(T_LIB_TYPE SHARED)
endif()

# Include the correct platform-specific CMake files.
if(APPLE)
  include(scripts/cmake/Mac.cmake)
elseif(WIN32)
  include(scripts/cmake/Win.cmake)
endif()

include_directories(external/eigen)

# Add cppunit to project.
add_subdirectory(external)

# Add source
add_subdirectory(source)