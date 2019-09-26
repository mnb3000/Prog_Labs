cmake_minimum_required(VERSION 3.13)
project(Prog_Labs C)

set(CMAKE_C_STANDARD 99)

add_subdirectory(lab1)
add_subdirectory(lab2)
add_subdirectory(lab3)
add_subdirectory(lab4)
add_subdirectory(input_lib)
install(CODE "MESSAGE(\"Sample install message.\")")
