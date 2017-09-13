cmake_minimum_required(VERSION 3.8)
project(tictactoe_cpp)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        src/board.cpp
        src/board.hpp
        src/main.cpp
        src/rules.cpp
        src/rules.hpp
        test/board_test.cpp
        test/catch.hpp
        test/rules_test.cpp
        test/test.cpp)

add_executable(tictactoe_cpp ${SOURCE_FILES})