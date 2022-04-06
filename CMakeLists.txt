cmake_minimum_required(VERSION 3.21)
project(ToDoList)

set(CMAKE_CXX_STANDARD 20)

add_subdirectory(test)

set(SOURCE_FILES Header/Date.h Header/Task.h Header/ToDoList.h Header/ToDoInterf.h Source/Date.cpp Source/Task.cpp Source/ToDoList.cpp Source/ToDoInterf.cpp)
add_executable(ToDoList main.cpp)

add_library(core ${SOURCE_FILES})
target_link_libraries(ToDoList core)
