// data.h
#ifndef __COMWISE__ROBOT_NAV__DATA__H__
#define __COMWISE__ROBOT_NAV__DATA__H__

#include <memory>
#include <vector>
#include <cmath>

// 基础类型定义
struct Point {
    double x;
    double y;

    Point(double x = 0, double y = 0) : x(x), y(y) {}
    
    double distanceTo(const Point& other) const {
        return std::hypot(x - other.x, y - other.y);
    }
};

struct Pose : public Point {
    double theta; // 朝向角度
    
    Pose(double x = 0, double y = 0, double theta = 0) 
        : Point(x, y), theta(theta) {}
};

struct Velocity {
    double linear;
    double angular;
    
    Velocity(double linear = 0, double angular = 0) 
        : linear(linear), angular(angular) {}
};

// 传感器数据结构
struct LaserScan {
    float angle_min;
    float angle_max;
    float angle_increment;
    float time_increment;
    float scan_time;
    float range_min;
    float range_max;
    std::vector<float> ranges;
    std::vector<float> intensities;
    
    std::vector<Point> toCartesian(const Pose& sensor_pose) const {
        std::vector<Point> points;
        float angle = angle_min;
        for (float range : ranges) {
            if (range >= range_min && range <= range_max) {
                Point p;
                p.x = sensor_pose.x + range * std::cos(sensor_pose.theta + angle);
                p.y = sensor_pose.y + range * std::sin(sensor_pose.theta + angle);
                points.push_back(p);
            }
            angle += angle_increment;
        }
        return points;
    }
};

struct ImageData {
    std::vector<uint8_t> image;
    double timestamp;
};

// node data
struct Node {
    int x, y;
    float g_cost, h_cost, f_cost;
    Node *parent;

    Node(int x, int y) : x(x), y(y), g_cost(0), h_cost(0), f_cost(0), parent(nullptr) {}

    float get_f_cost() const {
        return g_cost + h_cost;
    }

    bool operator==(const Node& rh) {
        return rh.x == x && 
               rh.y == y &&
               rh.g_cost == g_cost &&
               rh.h_cost == h_cost &&
               rh.f_cost == f_cost &&
               rh.parent == parent;
    }
};

#endif // __COMWISE__ROBOT_NAV__NODE__H__
