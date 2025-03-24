// a_star_planner.h
#ifndef __COMWISE__ROBOT_NAV__A_STAR_PLANNER__H__
#define __COMWISE__ROBOT_NAV__A_STAR_PLANNER__H__

#include "global_planner.h"

class AStarPlanner : public GlobalPlanner {
public:
    AStarPlanner(int width, int height, const std::vector<std::vector<int>>& map);
    
    std::vector<Node> plan_path(const Node& start, const Node& goal) override;

private:
    int width_, height_;
    std::vector<std::vector<int>> map_;
    std::vector<Node> get_neighbors(Node node);
    bool is_valid(Node node);
};

#endif // __COMWISE__ROBOT_NAV__A_STAR_PLANNER__H__
