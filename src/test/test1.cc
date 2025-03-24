#include <vector>
#include <iostream>
#include "global_planner/a_star_planner.h"
#include "local_planner/dwa_planner.h"
#include "velocity_controller/simple_velocity_controller.h"

int main() {
    // 初始化一个简单的地图
    std::vector<std::vector<int>> map(10, std::vector<int>(10, 0));
    AStarPlanner global_planner(10, 10, map);

    Node start(0, 0), goal(9, 9);
    std::vector<Node> path = global_planner.plan_path(start, goal);
    std::cout << "Global path found:" << std::endl;
    for (const auto& node : path) {
        std::cout << "(" << node.x << ", " << node.y << ")" << std::endl;
    }

    // 局部路径规划
    DWAPlanner local_planner;
    local_planner.plan_path();

    // 速度控制
    SimpleVelocityController velocity_controller;
    velocity_controller.set_velocity(0.5, 0.1);
    velocity_controller.apply_velocity();

    return 0;
}
