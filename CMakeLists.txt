cmake_minimum_required(VERSION 3.19)
project(LMS_PROJECT)

set(CMAKE_CXX_STANDARD 17)

add_executable(LMS_PROJECT main.cpp book.cpp book.h main.cpp record.cpp record.h borrow.cpp borrow.h)