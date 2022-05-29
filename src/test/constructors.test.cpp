#include <catch2/catch.hpp>
#include <box.hpp>


TEST_CASE("Constructors and Assignment")
{
    SECTION("Default Allocated")
    {
        SECTION("Default constructor")
        {
            cortex::box<int> bx;
            REQUIRE(bx.size() == 0);
            REQUIRE(bx.rows() == 0);
            REQUIRE(bx.columns() == 0);
        }

        SECTION("Size Constructor")
        {
            cortex::box<int> bx(4, 5);
            REQUIRE(bx.size() == 20);
            REQUIRE(bx.rows() == 4);
            REQUIRE(bx.columns() == 5);
        }

        SECTION("Size and Value Constructor")
        {
            cortex::box<int> bx(4, 5, 1);
            REQUIRE(bx.size() == 20);
            REQUIRE(bx.rows() == 4);
            REQUIRE(bx.columns() == 5);
        }

        SECTION("Copy constructor")
        {
            cortex::box<int> bx(4, 5, 1);
            cortex::box<int> nbx(bx);

            REQUIRE(nbx.size() == 20);
            REQUIRE(nbx.rows() == 4);
            REQUIRE(nbx.columns() == 5);

            for (auto i { 0ul }; i < bx.size(); ++i)
            {
                REQUIRE(nbx[i] == 1);
                REQUIRE(bx[i] == 1);
            }
        }

        SECTION("Move constructor")
        {
            cortex::box<int> bx(4, 5, 1);

            for (auto i { 0ul }; i < bx.size(); ++i)
                REQUIRE(bx[i] == 1);

            cortex::box<int> nbx(std::move(bx));

            REQUIRE(nbx.size() == 20);
            REQUIRE(nbx.rows() == 4);
            REQUIRE(nbx.columns() == 5);

            for (auto i { 0ul }; i < bx.size(); ++i)
                REQUIRE(nbx[i] == 1);
        }

        SECTION("Initializer List Constructor")
        {
            cortex::box<int> bx { { 1, 2 }
                                , { 3, 4 }
                                , { 5, 6 }
                                , { 7, 8 }
                                , { 9, 10 } };

            REQUIRE(bx.rows() == 5);
            REQUIRE(bx.columns() == 2);
            REQUIRE(bx.size() == 10);

            for (auto i { 0ul }; i < bx.size(); ++i)
                REQUIRE(bx[i] == static_cast<int>(i + 1));
        }

        SECTION("Assign Constructor")
        {
            std::vector<int> v { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
            cortex::box<int> bx(v.begin(), v.end(), 2, 5);
            
            REQUIRE(bx.rows() == 2);
            REQUIRE(bx.columns() == 5);
            REQUIRE(bx.size() == 10);

            REQUIRE(bx == cortex::box<int> { { 1, 2, 3, 4, 5 }
                                           , { 6, 7, 8, 9, 10 } });
        }
    }

    SECTION("Custom Allocted")
    {
        SECTION("Allocator Constructor")
        {
            std::allocator<int> alloc;
            cortex::box<int> bx(alloc);
            REQUIRE(bx.size() == 0);
            REQUIRE(bx.rows() == 0);
            REQUIRE(bx.columns() == 0);
            REQUIRE(bx.get_allocator() == alloc);
        }

        SECTION("Size Constructor")
        {
            std::allocator<int> alloc;
            cortex::box<int> bx(4, 5, alloc);
            REQUIRE(bx.size() == 20);
            REQUIRE(bx.rows() == 4);
            REQUIRE(bx.columns() == 5);
            REQUIRE(bx.get_allocator() == alloc);
        }

        SECTION("Size and Value Constructor")
        {
            std::allocator<int> alloc;
            cortex::box<int> bx(4, 5, 1, alloc);
            REQUIRE(bx.size() == 20);
            REQUIRE(bx.rows() == 4);
            REQUIRE(bx.columns() == 5);
            REQUIRE(bx.get_allocator() == alloc);
        }

        SECTION("Copy constructor")
        {
            std::allocator<int> alloc;
            cortex::box<int> bx(4, 5, 1, alloc);
            cortex::box<int> nbx(bx);

            REQUIRE(nbx.size() == 20);
            REQUIRE(nbx.rows() == 4);
            REQUIRE(nbx.columns() == 5);
            REQUIRE(bx.get_allocator() == alloc);

            for (auto i { 0ul }; i < bx.size(); ++i)
            {
                REQUIRE(nbx[i] == 1);
                REQUIRE(bx[i] == 1);
            }
        }

        SECTION("Move constructor")
        {
            std::allocator<int> alloc;
            cortex::box<int> bx(4, 5, 1, alloc);

            for (auto i { 0ul }; i < bx.size(); ++i)
                REQUIRE(bx[i] == 1);

            cortex::box<int> nbx(std::move(bx));

            REQUIRE(nbx.size() == 20);
            REQUIRE(nbx.rows() == 4);
            REQUIRE(nbx.columns() == 5);
            REQUIRE(nbx.get_allocator() == alloc);

            for (auto i { 0ul }; i < bx.size(); ++i)
                REQUIRE(nbx[i] == 1);
        }
    }

    SECTION("Assignment Operators")
    {
        SECTION("Copy assignment")
        {
            cortex::box<int> bx(4, 5, 1);
            cortex::box<int> nbx;

            REQUIRE(nbx.size() == 0);
            REQUIRE(nbx.rows() == 0);
            REQUIRE(nbx.columns() == 0);

            nbx = bx;
            REQUIRE(nbx.size() == 20);
            REQUIRE(nbx.rows() == 4);
            REQUIRE(nbx.columns() == 5);

            for (auto i { 0ul }; i < bx.size(); ++i)
            {
                REQUIRE(nbx[i] == 1);
                REQUIRE(bx[i] == 1);
            }
        }

        SECTION("Move assignment")
        {
            cortex::box<int> bx(4, 5, 1);
            cortex::box<int> nbx;

            REQUIRE(nbx.size() == 0);
            REQUIRE(nbx.rows() == 0);
            REQUIRE(nbx.columns() == 0);

            nbx = std::move(bx);
            REQUIRE(nbx.size() == 20);
            REQUIRE(nbx.rows() == 4);
            REQUIRE(nbx.columns() == 5);

            for (auto i { 0ul }; i < bx.size(); ++i)
                REQUIRE(nbx[i] == 1);
        }

        SECTION("Initializer List Assignment")
        {
            cortex::box<int> bx = { { 1, 2, 3 }
                                  , { 4, 5, 6 }
                                  , { 7, 8, 9 }};

            REQUIRE(bx.rows() == 3);
            REQUIRE(bx.columns() == 3);
            REQUIRE(bx.size() == 9);

            for (auto i { 0ul }; i < bx.size(); ++i)
                REQUIRE(bx[i] == static_cast<int>(i + 1));
        }
    }
}
