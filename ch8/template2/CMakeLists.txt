#
CMAKE_MINIMUM_REQUIRED (VERSION 3.5.1)

#
PROJECT(adapter)

# Configuration
#

SET(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
SET(CMAKE_CXX_FLAGS "-std=c++11")

include_directories(
  src
)

add_executable(adapter
    src/main.cpp
)

TARGET_LINK_LIBRARIES(adapter
)
