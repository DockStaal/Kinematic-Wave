#ifndef UWPIND_HPP_
#define UWPIND_HPP_

#include <functional>

#include "stepper.hpp"
#include "drain_direction_map.hpp"

class Upwind : public Stepper
{
public:
    Upwind(std::function<double(double, double, double)> i);

    void step(
            DrainDirectionMap& ddm, 
            double a,
            double m,
            double t,
            double dt) const override;

private:
    std::function<double(double, double, double)> i;
    std::function<double(double, double, double)> q;
    std::function<double(double, double, double, double)> d;
};

#endif // UWPIND_HPP_
