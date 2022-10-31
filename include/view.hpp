#ifndef VIEW_HPP_
#define VIEW_HPP_

#include "drain_direction_map.hpp"

class View 
{
public:
    View(DrainDirectionMap &ddm);

    void draw(double t) const;
    void show() const;

private:
    DrainDirectionMap& ddm_;
};

#endif // VIEW_HPP_


