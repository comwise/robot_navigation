#include <iostream>
#include <vector>
#include <memory>
#include <cmath>
#include <queue>
#include <map>
#include <functional>
#include <mutex>
#include "costmap/costmap.h"
#include "global_planner/a_star_planner.h"
#include "local_planner/dwa_planner.h"
#include "trajectory_controller/obstacle_controller.h"


// 导航框架核心类
class NavigationStack {
public:
    NavigationStack() {
        // 初始化各模块
        costmap_ = std::make_shared<Costmap2D>(100, 100, 0.1);
        global_planner_ = std::make_unique<AStarPlanner>(costmap_);
        local_planner_ = std::make_unique<DWAPlanner>();
        
        // 初始化代价地图（示例障碍物）
        for (size_t x = 30; x < 70; ++x) {
            costmap_->setCost(x, 50, 100);
        }
    }
    
    void setGoal(const Pose& goal) {
        goal_ = goal;
        plan_.clear();
    }
    
    void updateRobotPose(const Pose& pose) {
        robot_pose_ = pose;
    }
    
    void updateObstacles(const std::vector<Point>& obstacles) {
        obstacle_controller_.updateObstacles(obstacles);
    }
    
    Velocity computeVelocityCommands() {
        // 检查是否需要重新规划全局路径
        if (plan_.empty() || needReplan()) {
            if (!global_planner_->makePlan(robot_pose_, goal_, plan_)) {
                return Velocity(0, 0);
            }
        }
        
        // 获取附近障碍物
        std::vector<Point> obstacles;
        {
            std::lock_guard<std::mutex> lock(obstacle_controller_.mutex_);
            obstacles = obstacle_controller_.obstacles_;
        }
        
        // 计算速度命令
        return local_planner_->computeVelocityCommands(robot_pose_, plan_, obstacles);
    }
    
private:
    bool needReplan() const {
        // 简单检查：如果机器人偏离路径太远，需要重新规划
        if (plan_.empty()) return true;
        
        double min_dist = std::numeric_limits<double>::max();
        for (const auto& pose : plan_) {
            double dist = robot_pose_.distanceTo(pose);
            if (dist < min_dist) {
                min_dist = dist;
            }
        }
        
        return min_dist > 0.5;
    }
    
    std::shared_ptr<Costmap2D> costmap_;
    std::unique_ptr<GlobalPlanner> global_planner_;
    std::unique_ptr<LocalPlanner> local_planner_;
    ObstacleController obstacle_controller_;
    
    Pose robot_pose_;
    Pose goal_;
    std::vector<Pose> plan_;
};

int main() {
    NavigationStack nav_stack;
    
    // 设置目标点
    nav_stack.setGoal(Pose(8.0, 8.0, 0));
    
    // 模拟机器人位置更新
    nav_stack.updateRobotPose(Pose(1.0, 1.0, 0));
    
    // 模拟障碍物检测
    std::vector<Point> obstacles = {Point(4.0, 4.0), Point(5.0, 5.0)};
    nav_stack.updateObstacles(obstacles);
    
    // 计算速度命令
    Velocity cmd = nav_stack.computeVelocityCommands();
    std::cout << "Velocity command: linear=" << cmd.linear 
              << ", angular=" << cmd.angular << std::endl;
    
    return 0;
}