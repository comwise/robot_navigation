cmake_minimum_required(VERSION 3.2)

file(GLOB_RECURSE SOURCE_FILES "*.c*")

add_library(velocity_controller ${SOURCE_FILES})
#target_link_libraries(velocity_controller pthread rt)

#add_executable(test_local_planner main.cpp)
#target_link_libraries(test_local_planner local_planner)