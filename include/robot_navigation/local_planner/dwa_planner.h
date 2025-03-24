
#ifndef __COMWISE__ROBOT_NAV__DWA_PLANNER__H__
#define __COMWISE__ROBOT_NAV__DWA_PLANNER__H__

#include "local_planner.h"

class DWAPlanner : public LocalPlanner {
public:
    DWAPlanner();
    
    void plan_path() override;
};

#endif // __COMWISE__ROBOT_NAV__DWA_PLANNER__H__