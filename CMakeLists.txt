cmake_minimum_required(VERSION 3.27)
project(C++)

set(CMAKE_CXX_STANDARD 17)

add_executable(C++ main.cpp
        this.cpp
)

file(GLOB files "*.cpp")
foreach(file ${files})
    get_filename_component(exe_name ${file} NAME_WE) # 提取文件名（不含扩展名）
    add_executable(${exe_name} ${file})
endforeach()
