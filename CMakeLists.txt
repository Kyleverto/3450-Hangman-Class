cmake_minimum_required(VERSION 3.10.0)
project(Hangman VERSION 0.1.0 LANGUAGES C CXX)

add_executable(Hangman main.cpp game.cpp console.cpp state.cpp)

include(CTest)
enable_testing()
