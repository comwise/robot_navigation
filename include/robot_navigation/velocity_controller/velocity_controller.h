// velocity_controller.h
#ifndef __COMWISE__ROBOT_NAV__VELOCITY_CONTROLLER__H__
#define __COMWISE__ROBOT_NAV__VELOCITY_CONTROLLER__H__

class VelocityController {
public:
    virtual ~VelocityController() = default;
    
    virtual void set_velocity(float linear, float angular) = 0;
    virtual void apply_velocity() = 0;
};

#endif // __COMWISE__ROBOT_NAV__VELOCITY_CONTROLLER__H__