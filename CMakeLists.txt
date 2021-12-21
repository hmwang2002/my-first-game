cmake_minimum_required(VERSION 3.20)
project(gameswhm C)

set(CMAKE_C_STANDARD 11)

add_executable(gameswhm main.c)
add_executable(drawmap drawmap.c)
add_executable(copy copy.c)
add_executable(computer_choice computer_choice.c)
add_executable(quiz quiz.c)
add_executable(trial trial.c)