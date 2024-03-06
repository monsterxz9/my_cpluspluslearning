cmake_minimum_required(VERSION 3.26)
project(LinearDataStructure C)
set(CMAKE_C_STANDARD 11)

add_executable(untitled main.c
        stack.c
        list.c
        queue.c
        LinkedQueue.c
        RemoveDuplicatesFromList.c
        reverseList.c
        rotateRight.c
        isValid.c
        findKthPositive.c
)

file(GLOB files "*.c")
foreach(file ${files})
    get_filename_component(exe_name ${file} NAME_WE) # 提取文件名（不含扩展名）
    add_executable(${exe_name} ${file})
endforeach()

