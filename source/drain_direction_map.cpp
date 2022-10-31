#include <algorithm>
#include <cstddef>
#include <iostream>
#include <random>
#include <vector>

#include "drain_direction_map.hpp"
#include "node.hpp"

DrainDirectionMap::DrainDirectionMap(
        double size_x, 
        double size_y, 
        std::size_t nx, 
        std::size_t ny)
    : size_x(size_x)
    , size_y(size_y)
    , nx(nx)
    , ny(ny)
    , grid(std::make_unique<std::vector<Node>>(nx * ny))
{
    double x_step = size_x / (nx - 1);
    double y_step = (ny > 1)? size_y / (ny - 1) : 0;
    for (std::size_t i = 0; i < nx; ++i) 
    {
        for (std::size_t j = 0; j < ny; ++j) 
        {
            double x = i * x_step;
            double y = j * y_step;
            grid->at(index(i, j)).x = x;
            grid->at(index(i, j)).y = y;
            grid->at(index(i, j)).cell_size = std::max(x_step, y_step);
        }
    }

    std::vector<std::size_t> stack{0}; 
    unsigned int seed = std::random_device()();
    std::default_random_engine generator(seed);

    while(stack.size() > 0)
    {
        std::size_t current = stack.back();
        std::vector<Direction> possible_directions = check_available_directions(current);
        if(possible_directions.size() == 0)
        {
            stack.pop_back();
        }
        else
        {
            int next;
            std::shuffle(possible_directions.begin(), possible_directions.end(), generator);
            switch(possible_directions.back())
            {
                case Direction::UP:
                    next = current - nx;
                    break;
                case Direction::DOWN:
                    next = current + nx;
                    break;
                case Direction::LEFT:
                    next = current - 1;
                    break;
                case Direction::RIGHT:
                    next = current + 1;
                    break;
            }
            stack.push_back(next);
            grid->at(current).add_prev(&grid->at(next));
            grid->at(next).add_next(&grid->at(current));
        }
    }
}

int DrainDirectionMap::index(std::size_t x, std::size_t y) const
{
    return x + y * nx;
}

std::vector<DrainDirectionMap::Direction> DrainDirectionMap::check_available_directions(std::size_t i) const
{
    std::vector<Direction> directions{};
    // This is to avoid problems with unsigned and singed :)
    int I = (int)i; 
    int NX = (int)nx;
    int NY = (int)ny;
    if(I - NX >= 0 && grid->at(I - NX).next == nullptr && grid->at(I - NX).prev.size() == 0)
    {
        directions.push_back(Direction::UP);
    }
    if(I + NX < NX * NY && grid->at(I + NX).next == nullptr && grid->at(I + NX).prev.size() == 0)
    {
        directions.push_back(Direction::DOWN);
    }
    if(I % NX != 0 && grid->at(I - 1).next == nullptr && grid->at(I - 1).prev.size() == 0)
    {
        directions.push_back(Direction::LEFT);
    }
    if(I % NX != NX - 1 && grid->at(I + 1).next == nullptr && grid->at(I + 1).prev.size() == 0)
    {
        directions.push_back(Direction::RIGHT);
    }
    return directions;
}

