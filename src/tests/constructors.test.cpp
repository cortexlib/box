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

            for (auto& v : bx)
                REQUIRE(v == 1);

            for (auto& v : nbx)
                REQUIRE(v == 1);
        }

        SECTION("Move constructor")
        {
            cortex::box<int> bx(4, 5, 1);

            for (auto& v : bx)
                REQUIRE(v == 1);

            cortex::box<int> nbx(std::move(bx));

            REQUIRE(nbx.size() == 20);
            REQUIRE(nbx.rows() == 4);
            REQUIRE(nbx.columns() == 5);

            for (auto& v : bx)
                REQUIRE(v == 1);
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

            for (auto i { 1 }; auto& v : bx)
                REQUIRE(v == i++);
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

            for (auto& v : bx)
                REQUIRE(v == 1);

            for (auto& v : nbx)
                REQUIRE(v == 1);
        }

        SECTION("Move constructor")
        {
            std::allocator<int> alloc;
            cortex::box<int> bx(4, 5, 1, alloc);

            for (auto& v : bx)
                REQUIRE(v == 1);

            cortex::box<int> nbx(std::move(bx));

            REQUIRE(nbx.size() == 20);
            REQUIRE(nbx.rows() == 4);
            REQUIRE(nbx.columns() == 5);
            REQUIRE(nbx.get_allocator() == alloc);

            for (auto& v : nbx)
                REQUIRE(v == 1);
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

            for (auto& v : bx)
                REQUIRE(v == 1);
            
            for (auto& v : nbx)
                REQUIRE(v == 1);
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

            for (auto& v : nbx)
                REQUIRE(v == 1);
        }

        SECTION("Initializer List Assignment")
        {
            cortex::box<int> bx = { { 1, 2, 3 }
                                  , { 4, 5, 6 }
                                  , { 7, 8, 9 }};

            REQUIRE(bx.rows() == 3);
            REQUIRE(bx.columns() == 3);
            REQUIRE(bx.size() == 9);

            for (auto i { 1 }; auto& v : bx)
                REQUIRE(v == i++);
        }
    }
}

TEST_CASE("Assignment")
{
    SECTION("box::assign - initialiser list")
    {
        SECTION("Same Size")
        {
            cortex::box<int> bx(3, 3, 1);

            auto ptr { bx.data() };

            REQUIRE(bx.size() == 9);
            REQUIRE(bx.dimensions() == std::tuple{3, 3});
            REQUIRE(bx.data() == ptr);
            REQUIRE(bx == cortex::box<int> { { 1, 1, 1 }
                                           , { 1, 1, 1 }
                                           , { 1, 1, 1 } });

            bx.assign({ { 1, 2, 3 }
                      , { 4, 5, 6 }
                      , { 7, 8, 9 } });
            
            REQUIRE(bx.size() == 9);
            REQUIRE(bx.dimensions() == std::tuple{3, 3});
            REQUIRE(bx.data() == ptr);
            REQUIRE(bx == cortex::box<int> { { 1, 2, 3 }
                                           , { 4, 5, 6 }
                                           , { 7, 8, 9 } });
        }

        SECTION("Larger Size")
        {
            cortex::box<int> bx(3, 3, 1);

            auto ptr { bx.data() };

            REQUIRE(bx.size() == 9);
            REQUIRE(bx.dimensions() == std::tuple{3, 3});
            REQUIRE(ptr == bx.data());
            REQUIRE(bx == cortex::box<int> { { 1, 1, 1 }
                                           , { 1, 1, 1 }
                                           , { 1, 1, 1 } });


            bx.assign({ { 1, 2, 3 }
                      , { 4, 5, 6 }
                      , { 7, 8, 9 }
                      , { 10, 11, 12 } });
            
            REQUIRE(bx.size() == 12);
            REQUIRE(bx.dimensions() == std::tuple{4, 3});
            REQUIRE(bx.data() != ptr);
            REQUIRE(bx == cortex::box<int> { { 1, 2, 3 }
                                           , { 4, 5, 6 }
                                           , { 7, 8, 9 }
                                           , { 10, 11, 12 } });
        }

        SECTION("Smaller Box")
        {
            cortex::box<int> bx(3, 3, 1);

            auto ptr { bx.data() };

            REQUIRE(bx.size() == 9);
            REQUIRE(bx.dimensions() == std::tuple{3, 3});
            REQUIRE(bx.data() == ptr);
            REQUIRE(bx == cortex::box<int> { { 1, 1, 1 }
                                           , { 1, 1, 1 }
                                           , { 1, 1, 1 } });

            bx.assign({ { 1, 2, 3, 4 } });

            REQUIRE(bx.size() == 4);
            REQUIRE(bx.dimensions() == std::tuple{1, 4});
            REQUIRE(bx.data() != ptr);
            REQUIRE(bx == cortex::box<int> { { 1, 2, 3, 4 } });
        }

        SECTION("Empty Box")
        {
            cortex::box<int> bx;

            auto ptr { bx.data() };

            REQUIRE(bx.size() == 0);
            REQUIRE(bx.dimensions() == std::tuple{0, 0});
            REQUIRE(ptr == bx.data());
            REQUIRE(bx == cortex::box<int> { });

            bx.assign({ { 1, 2, 3 }
                      , { 4, 5, 6 }
                      , { 7, 8, 9 } });
            
            REQUIRE(bx.size() == 9);
            REQUIRE(bx.dimensions() == std::tuple{3, 3});
            REQUIRE(bx.data() != ptr);
            REQUIRE(bx == cortex::box<int> { { 1, 2, 3 }
                                           , { 4, 5, 6 }
                                           , { 7, 8, 9 } });
        }
    }
}
