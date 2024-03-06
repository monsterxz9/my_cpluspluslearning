cmake_minimum_required(VERSION 3.27)
project(string C)

set(CMAKE_C_STANDARD 11)

add_executable(string countWords.c
        CaesarCipher.c
        MentalArithmeticExercise.c
        wordProcess.c
        countTitle.c
        stupidMonkey.c
        autoCorrect.c)

file(GLOB files "*.c")

foreach(file ${files})
    get_filename_component(exe_name ${file} NAME_WE) # 提取文件名（不含扩展名）
    add_executable(${exe_name} ${file})
endforeach()
