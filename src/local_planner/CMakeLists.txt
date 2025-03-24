cmake_minimum_required(VERSION 3.2)

file(GLOB_RECURSE SOURCE_FILES "*.c*")

add_library(local_planner ${SOURCE_FILES})
#target_link_libraries(local_planner pthread rt)

#add_executable(test_local_planner main.cpp)
#target_link_libraries(test_local_planner local_planner)