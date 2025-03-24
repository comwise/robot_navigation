#ifndef __COMWISE__ROBOT_NAV__SIMPLE_VELOCITY_CONTROLLER__H__
#define __COMWISE__ROBOT_NAV__SIMPLE_VELOCITY_CONTROLLER__H__

#include "velocity_controller.h"

class SimpleVelocityController : public VelocityController {
public:
    SimpleVelocityController();
    
    void set_velocity(float linear, float angular) override;
    void apply_velocity() override;

private:
    float linear_velocity_, angular_velocity_;
};

#endif // __COMWISE__ROBOT_NAV__SIMPLE_VELOCITY_CONTROLLER__H__
