cmake_minimum_required(VERSION 3.29)
project(data_structure_and_algorithms C)

set(CMAKE_C_STANDARD 11)

add_executable(data_structure_and_algorithms main.c
        线性表/sequential_list.c
        线性表/singly_linked_list.c
        线性表/double_linked_lists.c
        线性表/stack.c
        线性表/queue.c
)
