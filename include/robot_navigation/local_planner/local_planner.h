
#ifndef __COMWISE__ROBOT_NAV__LOCAL_PLANNER__H__
#define __COMWISE__ROBOT_NAV__LOCAL_PLANNER__H__

class LocalPlanner {
public:
    virtual ~LocalPlanner() = default;
    
    virtual void plan_path() = 0;
};

#endif // __COMWISE__ROBOT_NAV__LOCAL_PLANNER__H__