#include "costmap2d.h"

Costmap2D::Costmap2D(size_t width, size_t height, double resolution)
        : Costmap(width, height, resolution) {
        data_.resize(width * height, 0);
}

Costmap2D::~Costmap2D() {

}

// 设置/获取代价值
void Costmap2D::setCost(size_t x, size_t y, unsigned char cost) {
    if (x < width_ && y < height_) {
        data_[y * width_ + x] = cost;
    }
}

unsigned char Costmap2D::getCost(size_t x, size_t y) const {
    if (x < width_ && y < height_) {
        return data_[y * width_ + x];
    }
    return 0;
}

// 世界坐标到地图坐标转换
bool Costmap2D::worldToMap(double wx, double wy, size_t& mx, size_t& my) const {
    mx = static_cast<size_t>((wx - origin_x_) / resolution_);
    my = static_cast<size_t>((wy - origin_y_) / resolution_);
    return mx < width_ && my < height_;
}

// 地图坐标到世界坐标转换
void Costmap2D::mapToWorld(size_t mx, size_t my, double& wx, double& wy) const {
    wx = origin_x_ + (mx + 0.5) * resolution_;
    wy = origin_y_ + (my + 0.5) * resolution_;
}

// 膨胀障碍物
void Costmap2D::inflate(double inflation_radius) {
    // 实现障碍物膨胀算法
    // ...
}

 std::vector<uint8_t> Costmap2D::visualize() const {
    
 }