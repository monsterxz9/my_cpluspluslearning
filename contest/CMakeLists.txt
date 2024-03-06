cmake_minimum_required(VERSION 3.27)
project(contestCPP)  # Removed space in project name

set(CMAKE_CXX_STANDARD 23)  # Corrected variable name

add_executable(contest WalletChange.c
        Plus-MinusSplit.cpp
        addTwoNumbers.cpp
        test.cpp)

file(GLOB files "*.c")

foreach(file ${files})
    get_filename_component(exe_name ${file} NAME_WE) # Extract file name (without extension)
    add_executable(${exe_name} ${file})
endforeach()
