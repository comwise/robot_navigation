// costmap.h 代价地图模块
#ifndef __COMWISE__ROBOT_NAV__COSTMAP__H__
#define __COMWISE__ROBOT_NAV__COSTMAP__H__

#include <cstdint>
#include <memory>
#include <vector>
#include <cmath>

class Costmap2D {
public:
    Costmap2D(size_t width, size_t height, double resolution);
    
    // 设置/获取代价值
    void setCost(size_t x, size_t y, uint8_t cost);
    uint8_t getCost(size_t x, size_t y) const;
    
    // 世界坐标到地图坐标转换
    bool worldToMap(double wx, double wy, size_t& mx, size_t& my) const;
    // 地图坐标到世界坐标转换
    void mapToWorld(size_t mx, size_t my, double& wx, double& wy) const;
    
    // 膨胀障碍物
    void inflate(double inflation_radius);
    
    std::vector<uint8_t> visualize() const;
    
    size_t getWidth() const { return width_; }
    size_t getHeight() const { return height_; }
    double getResolution() const { return resolution_; }
    
private:
    size_t width_{0};
    size_t height_{0};
    double resolution_{0};
    double origin_x_{0};
    double origin_y_{0};
    std::vector<uint8_t> data_;
};

#endif // __COMWISE__ROBOT_NAV__COSTMAP__H__