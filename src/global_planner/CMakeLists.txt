cmake_minimum_required(VERSION 3.2)

file(GLOB_RECURSE SOURCE_FILES "*.c*")

add_library(global_planner ${SOURCE_FILES})
#target_link_libraries(global_planner pthread rt)

add_executable(test_global_planner test.cpp)
target_link_libraries(test_global_planner global_planner)