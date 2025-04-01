// obstacle_controller.h 避障策略控制器
#ifndef __COMWISE__ROBOT_NAV__AVOID_CONTROLLER__H__
#define __COMWISE__ROBOT_NAV__AVOID_CONTROLLER__H__

#include <cstdint>
#include <vector>
#include <mutex>
#include "navigation_data/data.h"

class ObstacleController {
public:
    void updateObstacles(const std::vector<Point>& obstacles) {
        std::lock_guard<std::mutex> lock(mutex_);
        obstacles_ = obstacles;
    }
    
    bool isObstacleNearby(const Pose& pose, double threshold) {
        std::lock_guard<std::mutex> lock(mutex_);
        for (const auto& obs : obstacles_) {
            if (pose.distanceTo(obs) < threshold) {
                return true;
            }
        }
        return false;
    }
    
private:
    std::vector<Point> obstacles_;
    std::mutex mutex_;
};

#endif // __COMWISE__ROBOT_NAV__AVOID_CONTROLLER__H__