cmake_minimum_required(VERSION 3.26)
project(TreeDataStructure C)

set(CMAKE_C_STANDARD 11)

add_executable(JuniorTreeDataStructure CountBinaryTrees.c
        preOrderTraversal.c
        InOrderTraversal.c
        postOrderTraversal.c
        levelOrderTraversal.c
)
file(GLOB files "*.c")
foreach(file ${files})
    get_filename_component(exe_name ${file} NAME_WE) # 提取文件名（不含扩展名）
    add_executable(${exe_name} ${file})
endforeach()
