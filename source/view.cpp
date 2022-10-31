#include "matplotlibcpp/matplotlibcpp.h"

#include <stdexcept>
#include <iostream>

#include "drain_direction_map.hpp"
#include "view.hpp"

namespace plt = matplotlibcpp;

View::View(DrainDirectionMap &ddm) : ddm_(ddm)
{
}

void View::draw(double t) const
{
    if (ddm_.ny == 1)
    {
        std::vector<double> h(ddm_.nx);
        for (int i = 0; i < ddm_.nx; i++)
            h[i] = ddm_.grid->at(i).h;
        
        plt::clf();
        plt::plot(h);
        plt::title("t = " + std::to_string(t));
        plt::pause(0.001);
    } // !if ddm.ny == 1 
    else 
    {
        // Prepare data
        int nx = ddm_.nx; 
        int ny = ddm_.ny;
        std::vector<float> h(nx * ny);
        for (int i=0; i<nx; ++i) {
            for (int j=0; j<ny; ++j) {
                h.at(nx * j + i) = ddm_.grid->at(nx * j + i).h;
            }
        }

        const float* hptr = &(h[0]);
        const int colors = 1;

        PyObject* mat;

        plt::clf();
        plt::title("t = " + std::to_string(t));
        plt::imshow(hptr, ny, nx, colors, {}, &mat);
        plt::colorbar(mat);
        plt::pause(0.00001);
    }
}

void View::show() const
{
    plt::show();
}

