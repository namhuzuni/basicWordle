cmake_minimum_required(VERSION 3.21)
project(Wordle)

set(CMAKE_CXX_STANDARD 14)

add_executable(Wordle main.cpp WordBank.h  WordBank.cpp Board.cpp Player.cpp Game.cpp)
