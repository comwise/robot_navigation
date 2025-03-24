// data.h
#ifndef __COMWISE__ROBOT_NAV__NODE__H__
#define __COMWISE__ROBOT_NAV__NODE__H__

#include <vector>
#include <memory>

// 定义节点结构
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
