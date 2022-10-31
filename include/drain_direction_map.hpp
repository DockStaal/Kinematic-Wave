#ifndef DRAIN_DIRECTION_MAP_HPP_
#define DRAIN_DIRECTION_MAP_HPP_

#include <cstddef>
#include <memory>
#include <vector>

#include "node.hpp"

struct DrainDirectionMap 
{
public:
    // Initialize the drain direction map using depth-first search.
    //
    // @param size_x The size of the map in the x direction.
    // @param size_y The size of the map in the y direction.
    // @param nx The number of nodes in the x direction.
    // @param ny The number of nodes in the y direction.
    DrainDirectionMap(
            double size_x,  
            double size_y, 
            std::size_t nx, 
            std::size_t ny);

    // Returns the index in the grid vector of the node at 
    // position int x, int y in the 2d interpertation of the grid
    // vector.
    int index(std::size_t x, std::size_t y) const;

public:
    std::size_t size_x; // Size of the map in the x direction.
    std::size_t size_y; // Size of the map in the y direction.
    std::size_t nx; // Number of nodes in the x direction.
    std::size_t ny; // Number of nodes in the y direction.
    std::unique_ptr<std::vector<Node>> grid;

private:
    enum class Direction {
        UP,
        DOWN,
        LEFT,
        RIGHT
    };
    // Functions needed for depth-first search.
    std::vector<Direction> check_available_directions(std::size_t i) const;
};

#endif // DRAIN_DIRECTION_MAP_HPP_
