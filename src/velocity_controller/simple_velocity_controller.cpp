#include "velocity_controller/simple_velocity_controller.h"
#include <iostream>

SimpleVelocityController::SimpleVelocityController() 
    : linear_velocity_(0), angular_velocity_(0) {

}

void SimpleVelocityController::set_velocity(float linear, float angular) {
    linear_velocity_ = linear;
    angular_velocity_ = angular;
}

void SimpleVelocityController::apply_velocity() {
    std::cout << "Applying velocity: linear = " << linear_velocity_ << ", angular = " << angular_velocity_ << std::endl;
}
