#include <cstddef>
#include <functional>
#include <memory>
#include <string>
#include <vector>
#include <iostream>

#include "controller.hpp"
#include "drain_direction_map.hpp"
#include "stepper.hpp"
#include "upwind.hpp"
#include "view.hpp"

Controller::Controller(
        double size_x_ddm,
        double size_y_ddm,
        std::size_t nx, 
        std::size_t ny, 
        double starting_time,
        double a,
        double m, 
        std::function<double(double, double)> init_h,
        std::function<double(double, double, double)> i,
        StepperType stepper_type)
    : t(starting_time)
    , a(a)
    , m(m)
    , ddm(size_x_ddm, size_y_ddm, nx, ny)
    , view(ddm)
{
    for (std::size_t i = 0; i < nx * ny; ++i)
        ddm.grid->at(i).h = init_h(ddm.grid->at(i).x, ddm.grid->at(i).y);

    switch(stepper_type)
    {
        case StepperType::UPWIND: {
            stepper = std::make_unique<Upwind>(i);
            break;
        }
    }
}

void Controller::draw_initial_state() const 
{
    view.draw(0);
    view.show();
}

void Controller::run(double step_size, int draw_every_n_steps)
{
    for (int i = 0; i < 100000; ++i)
    {   
        stepper->step(ddm, a, m, t, step_size);
        t += step_size;
        if (i % draw_every_n_steps == 0)
            view.draw(t);
    }
    view.show();
}

void Controller::create_figures(
        double step_size,
        int draw_every_n_steps[],
        int number_of_draws) 
{
    int j = 0;
    int count = 1;
    while (j < number_of_draws)
    {
        stepper->step(ddm, a, m, t, step_size);
        t += step_size;
        if (count % draw_every_n_steps[j] == 0)
        {
            view.draw(t);
            view.show();
            j += 1;
        }
        count += 1;
    }
}
