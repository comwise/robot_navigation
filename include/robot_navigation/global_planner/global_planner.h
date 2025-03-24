// global_planner.h
#ifndef __COMWISE__ROBOT_NAV__GLOBAL_PLANNER__H__
#define __COMWISE__ROBOT_NAV__GLOBAL_PLANNER__H__

#include <memory>
#include <vector>
#include "navigation_data/data.h"

class GlobalPlanner {
public:
    virtual ~GlobalPlanner() = default;
    
    virtual std::vector<Node> plan_path(const Node& start, const Node& goal) = 0;
};

#endif // __COMWISE__ROBOT_NAV__GLOBAL_PLANNER__H__
