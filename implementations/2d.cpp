#include <cstddef>
#include <string>

#include "controller.hpp"

int main()
{
    const std::size_t nx = 50;
    const std::size_t ny = 50;
    const double size_x_ddm = 10;
    const double size_y_ddm = 10; 
    const double alpha = 5;
    const double m = 5.0/3.0;
    const double t0 = 0;
    const double time_step = 0.01;
    int draw_every_n_steps[] = {1, 100, 500, 1000, 2000, 3000, 4000, 5000, 6000, 
                                7000, 10000, 15000};

    auto init_h = [](double x, double y) 
                  {
                      if (x > 5 || y > 5) {
                          return 0.0; }
                      else {
                          return 0.0; }
                  };

    auto rainfall = [](double x, double y, double t) 
             {
                 if (t < 3) {
                     return 0.01; }
                 else {
                     return 0.0; }
                 return 0.00;
             };

    Controller controller{size_x_ddm, size_y_ddm, nx, ny, t0, alpha, m, 
                          init_h, rainfall, StepperType::UPWIND};

    //controller.run(time_step, 100);
    controller.create_figures(time_step, draw_every_n_steps, 12);
}
