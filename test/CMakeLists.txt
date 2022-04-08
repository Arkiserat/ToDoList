cmake_minimum_required(VERSION 3.21)
project(ToDoList)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(./lib/googletest-main/)
set(gtest_SOURCE_DIR, ./lib/googletest-main/googletest/)
include_directories(${gtest_SOURCE_DIR}/include ${gtest_SOURCE_DIR})

set(TEST_SOURCE_FILES DateTest.cpp TaskTest.cpp ToDoListTest.cpp ToDoInterfTest.cpp mainTest.cpp)
add_executable(RunToDoListTests ${TEST_SOURCE_FILES})
target_link_libraries(RunToDoListTests PUBLIC gtest gtest_main core)