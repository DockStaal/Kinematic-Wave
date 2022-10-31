#ifndef CONTROLLER_HPP_
#define CONTROLLER_HPP_

#include <cstddef>
#include <functional>
#include <memory>
#include <string>
#include <vector>

#include "drain_direction_map.hpp"
#include "node.hpp"
#include "stepper.hpp"
#include "stepper_type.hpp"
#include "view.hpp"

class Controller
{
public:
    Controller(
            double size_x_ddm,
            double size_y_ddm,
            std::size_t nx,
            std::size_t ny, 
            double starting_time,
            double a,
            double m,
            std::function<double(double, double)> init_h,
            std::function<double(double, double, double)> i,
            StepperType stepper_type);

    void draw_initial_state() const;

    void run(double step_size, int draw_every_n_steps);

    //A quick function just to genereate some figures for the report
    void create_figures(
            double step_size,
            int draw_every_n_steps[],
            int number_of_draws);

private:
    double t;
    double a;
    double m;
    std::unique_ptr<Stepper> stepper;
    DrainDirectionMap ddm;
    View view;
};


#endif // CONTROLLER_HPP_
