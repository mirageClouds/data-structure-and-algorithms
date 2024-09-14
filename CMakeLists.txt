cmake_minimum_required(VERSION 3.29)
project(data_structure_and_algorithms C)

set(CMAKE_C_STANDARD 11)

add_executable(data_structure_and_algorithms main.c
        sequential_list.c
        singly_linked_list.c
        double_linked_lists.c
        stack.c
        queue.c
)
