cmake_minimum_required(VERSION 3.21)
project(ToDoList)

set(CMAKE_CXX_STANDARD 20)

add_executable(ToDoList main.cpp Header/ToDoList.h Header/Date.h Source/Task.cpp Header/Task.h Source/Date.cpp Source/ToDoList.cpp Source/Observer.cpp Header/Observer.h)
