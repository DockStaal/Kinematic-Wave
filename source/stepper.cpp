/*
#include "stepper.hpp"

Stepper::Stepper(std::function<double(Node*, int, int, double)> F)
    : F(F)
{
}

void Stepper::step(DrainDirectionMap& ddm, double dt) const
{
    for (int y = 0; y < ddm.ny; y++)
        for (int x = 0; x < ddm.nx; x++)
            ddm.grid->at(ddm.index(x, y)).h_next = F(&ddm.grid->at(ddm.index(x, y)), x, y, dt);

    for(int i = 0; i < ddm.nx * ddm.ny; i++)
        ddm.grid->at(i).h = ddm.grid->at(i).h_next;
}
*/
