// costmap2d.h 代价地图模块
#ifndef __COMWISE__ROBOT_NAV__COSTMAP2D__H__
#define __COMWISE__ROBOT_NAV__COSTMAP2D__H__

#include <cmath>
#include "costmap.h"

class Costmap2D : public Costmap {
public:
    Costmap2D(size_t width, size_t height, double resolution);
    virtual ~Costmap2D();
    
    // 设置/获取代价值
    virtual void setCost(size_t x, size_t y, uint8_t cost) override;
    virtual uint8_t getCost(size_t x, size_t y) const override;
    
    // 世界坐标<->地图坐标转换
    virtual bool worldToMap(double wx, double wy, size_t& mx, size_t& my) const override;
    virtual void mapToWorld(size_t mx, size_t my, double& wx, double& wy) const override;
    
    // 膨胀障碍物
    virtual void inflate(double inflation_radius) override;
    
    std::vector<uint8_t> visualize() const;
    
private:
    double origin_x_{0};
    double origin_y_{0};
    std::vector<uint8_t> data_;
};

#endif // __COMWISE__ROBOT_NAV__COSTMAP2D__H__