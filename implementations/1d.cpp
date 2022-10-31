#include <cstddef>
#include <cmath>
#include <string>

#include "controller.hpp"
#include "upwind.hpp"

int main()
{
    double size_x_ddm = 10.0;
    double size_y_ddm = 1.0;
    std::size_t nx = 100;
    std::size_t ny = 1;

    auto init_h = [](double x, double y) 
                  {
                      return std::exp(-(x-5)*(x-5));
                  };

    auto i = [](double x, double y, double t) 
             {
                 return 0.0;
             };

    Controller controller{size_x_ddm, size_y_ddm, nx, ny, 0.0, 40.0 * 0.04, 5.0/3.0, 
                          init_h, i, StepperType::UPWIND};

    controller.draw_initial_state();

    controller.run(0.01, 12);
}
