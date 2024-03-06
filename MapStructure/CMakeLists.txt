cmake_minimum_required(VERSION 3.27)
project(MapStructure C)

set(CMAKE_C_STANDARD 11)

add_executable(MapStructure adjacencyMatrix.c
        adjacencyList.c
        DepthFirstSearch.c
        BreadthFirstSearch.c
        Floyd.c)

file(GLOB files "*.c")

foreach(file ${files})
    get_filename_component(exe_name ${file} NAME_WE) # 提取文件名（不含扩展名）
    add_executable(${exe_name} ${file})
endforeach()
