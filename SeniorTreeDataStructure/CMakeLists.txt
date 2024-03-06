cmake_minimum_required(VERSION 3.27)
project(SeniorTreeDataStructure C)

set(CMAKE_C_STANDARD 11)

add_executable(SeniorTreeDataStructure preOrderThreaded.c
        inOrderThreaded.c
        postOrderThreaded.c
        BinarySearchTree.c
        AVLTree.c
        RedBlackTree.c
        BTreeAndB+Tree.c
        Heap.c
        rangeSumBST.c
        buildTree.c
        isValidBST.c
        sumNumbers.c
        maxPathSum.c
)
file(GLOB files "*.c")
foreach(file ${files})
    get_filename_component(exe_name ${file} NAME_WE) # 提取文件名（不含扩展名）
    add_executable(${exe_name} ${file})
endforeach()