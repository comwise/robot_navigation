#ifndef __COMWISE__ROBOT_NAV__COSTMAP__H__
#define __COMWISE__ROBOT_NAV__COSTMAP__H__

#include <cstdint>
#include <memory>
#include <vector>

class Costmap {
public:
    Costmap(size_t width, size_t height, double resolution)
        : width_(width), height_(height), resolution_(resolution) { }
    virtual ~Costmap() = default;
    
    // set/get cost
    virtual void setCost(size_t x, size_t y, uint8_t cost) = 0;
    virtual uint8_t getCost(size_t x, size_t y) const = 0;
    
    // world <-> map 
    virtual bool worldToMap(double wx, double wy, size_t& mx, size_t& my) const = 0;
    virtual void mapToWorld(size_t mx, size_t my, double& wx, double& wy) const = 0;
    
    // inflate 
    virtual void inflate(double inflation_radius) = 0;
    
    virtual size_t getWidth() const { return width_; }
    virtual size_t getHeight() const { return height_; }
    virtual double getResolution() const { return resolution_; }
    
protected:
    size_t width_{0};
    size_t height_{0};
    double resolution_{0};
};

#endif // __COMWISE__ROBOT_NAV__COSTMAP__H__