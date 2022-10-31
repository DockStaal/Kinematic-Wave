#ifndef STEPPER_HPP_
#define STEPPER_HPP_

#include <cstddef>
#include <functional>
#include <vector>

#include "drain_direction_map.hpp"
#include "utils.hpp"

class Stepper 
{
public: 
    // Evolves the grid by one time step of size dt and thus 
    // changes the state of the DrainDirectionMap.
    // 
    // i.e. it changes the state h of the water level
    // at time t to h(t + dt) using the numerical scheme F.
    virtual void step(
            DrainDirectionMap& ddm, 
            double a,
            double m,
            double t,
            double dt) const = 0;

    virtual ~Stepper() = default;
};

#endif // STEPPER_HPP_
