cmake_minimum_required(VERSION 2.6)

if ( "${CMAKE_UNITTEST}" STREQUAL "UTEST" )
message("Perform Unit test")
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})
add_executable(PerformTest main_test.cpp)
target_link_libraries(executeTest ${GTEST_LIBRARIES} pthread)

else() 

set(CMAKE_BUILD_TYPE debug)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11")
project(IntentReccognizer)

file(GLOB_RECURSE SOURCE_FILES src/*.cpp)
add_executable(IntentReccognizer main.cpp ${SOURCE_FILES})

target_include_directories(IntentReccognizer PRIVATE ${CMAKE_CURRENT_DOURCE_DIR}/include)

endif()