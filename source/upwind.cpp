#include <cmath>
#include <functional>
#include <iostream>
#include <vector>

#include "upwind.hpp"

Upwind::Upwind(std::function<double(double, double, double)> i)
    : i(i)
{
    q = [](double h, double a, double m) {
        return (h > 0)? a * std::pow(h, m) : 0; //TODO 
    };

    d = [](double x1, double y1, double x2, double y2)
    {
        return std::sqrt(std::pow(x1 - x2, 2) + std::pow(y1 - y2, 2));
    };
}


void Upwind::step(
        DrainDirectionMap& ddm, 
        double a,
        double m,
        double t,
        double dt) const
{
    for (auto &node: *ddm.grid)
    {
        const double h_current = node.h;
        const double flux_out = q(h_current, a, m);
        
        double flux_in = 0;
        for (auto prev_node : node.prev)
        {
            const double h_previous = prev_node->h;
            flux_in += q(h_previous, a, m);
        } // for (auto prev_node : node.prev)

        node.h_next = h_current 
                    - dt/node.cell_size * (flux_out - flux_in) 
                    + dt * i(node.x, node.y, t);
    }
    
    double max = 0;
    for (auto &node : *ddm.grid)
    {
        node.h = (node.h_next > 0)? node.h_next : 0;
        if (node.h > max)
            max = node.h;
    }
}
