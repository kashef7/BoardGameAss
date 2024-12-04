cmake_minimum_required(VERSION 3.27)
project(BoardGameAss C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

add_executable(BoardGameAss
        BoardGame_Classes.h
        Four_in_a_Row.h
        main.cpp
        PyramidXO.h
        WordXO.h
        Numerical_TicTacToe.h
        Numerical_TicTacToe.h
)
