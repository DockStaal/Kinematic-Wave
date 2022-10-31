#include <catch2/catch.hpp>

#include <iostream>
#include <vector>

#include "drain_direction_map.hpp"
#include "node.hpp"

TEST_CASE("Test drain direction map")
{
    SECTION("Basic constructor test 1d system")
    {
        std::size_t nx = 10000;
        std::size_t ny = 1;

        double size_x_ddm = 12.3;
        double size_y_ddm = 1.0;

        DrainDirectionMap ddm{size_x_ddm, size_y_ddm, nx, ny};
        REQUIRE(ddm.nx == nx);
        REQUIRE(ddm.ny == ny);
        REQUIRE(ddm.grid->size() == nx);

        REQUIRE(ddm.grid->at(0).next == nullptr);
        REQUIRE(ddm.grid->at(0).prev.back() == &ddm.grid->at(1));

        for (std::size_t i = 1; i < nx - 1; i++)
        {
            REQUIRE(ddm.grid->at(i).next == &ddm.grid->at(i - 1));
            REQUIRE(ddm.grid->at(i).prev.back() == &ddm.grid->at(i + 1));
            REQUIRE(ddm.grid->at(i).x == Approx(i * size_x_ddm / (nx - 1)));
            REQUIRE(ddm.grid->at(i).y == Approx(0.0));
        }
        REQUIRE(ddm.grid->at(nx - 1).next == &ddm.grid->at(nx - 2));
        REQUIRE(ddm.grid->at(nx - 1).prev.size() == 0);

    }
    SECTION("Basic constructor test 2d system")
    {
        std::size_t nx = 1000;
        std::size_t ny = 1000;

        double size_x_ddm = 12.3;
        double size_y_ddm = 1.0;

        DrainDirectionMap ddm{size_x_ddm, size_y_ddm, nx, ny};
        REQUIRE(ddm.nx == nx);
        REQUIRE(ddm.ny == ny);
        REQUIRE(ddm.grid->size() == nx * ny);
        
        int count_no_next = 0;
        int count_empty_prev = 0;
        int count_one_prev = 0;
        
        for (int i = 0; i < nx * ny; i++)
        {
            if (ddm.grid->at(i).next == nullptr)
                count_no_next++;

            if (ddm.grid->at(i).prev.size() == 0)
                count_empty_prev++;

            if (ddm.grid->at(i).prev.size() == 1)
                count_one_prev++;

            REQUIRE(ddm.grid->at(i).prev.size() < 4);
        }
        REQUIRE(count_no_next == 1);
        
        std::cout << "sources: " << count_empty_prev << std::endl;
        std::cout << "chanels: " << count_one_prev << std::endl;
        std::cout << "splittings:" << (nx * ny - count_empty_prev - count_one_prev) << std::endl;
        std::cout << "total: " << (nx * ny) << std::endl;
    } 

}
