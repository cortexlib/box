#include <catch2/catch.hpp>
#include <box.hpp>


TEST_CASE("Constructors and Assignment")
{
    SECTION("Default Allocated")
    {
        SECTION("Default constructor")
        {
            cxl::box<int> bx;
            REQUIRE(bx.size() == 0);
            REQUIRE(bx.rows() == 0);
            REQUIRE(bx.columns() == 0);
        }

        SECTION("Size Constructor")
        {
            cxl::box<int> bx(4, 5);
            REQUIRE(bx.size() == 20);
            REQUIRE(bx.rows() == 4);
            REQUIRE(bx.columns() == 5);
        }

        SECTION("Size and Value Constructor")
        {
            cxl::box<int> bx(4, 5, 1);
            REQUIRE(bx.size() == 20);
            REQUIRE(bx.rows() == 4);
            REQUIRE(bx.columns() == 5);
        }

        SECTION("Copy constructor")
        {
            cxl::box<int> bx(4, 5, 1);
            cxl::box<int> nbx(bx);

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
            cxl::box<int> bx(4, 5, 1);

            for (auto& v : bx)
                REQUIRE(v == 1);

            cxl::box<int> nbx(std::move(bx));

            REQUIRE(nbx.size() == 20);
            REQUIRE(nbx.rows() == 4);
            REQUIRE(nbx.columns() == 5);

            for (auto& v : bx)
                REQUIRE(v == 1);
        }

        SECTION("Initializer List Constructor")
        {
            cxl::box<int> bx { { 1, 2 }
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
            cxl::box<int> bx(v.begin(), v.end(), 2, 5);
            
            REQUIRE(bx.rows() == 2);
            REQUIRE(bx.columns() == 5);
            REQUIRE(bx.size() == 10);

            REQUIRE(bx == cxl::box<int> { { 1, 2, 3, 4, 5 }
                                           , { 6, 7, 8, 9, 10 } });
        }

        SECTION("Dimension Constructor") 
        {
            cxl::box<int> bx(2, 5);
            bx = { { 1, 2, 3, 4, 5 }
                 , { 6, 7, 8, 9, 10 } };
            
            REQUIRE(bx.rows() == 2);
            REQUIRE(bx.columns() == 5);
            REQUIRE(bx.size() == 10);
            REQUIRE(bx.dimensions() == std::tuple{ 2, 5 });
            
            REQUIRE(bx == cxl::box<int> { { 1, 2, 3, 4, 5 }
                                           , { 6, 7, 8, 9, 10 } });

            cxl::box<std::string> nbx(bx.dimensions());

            REQUIRE(nbx.rows() == 2);
            REQUIRE(nbx.columns() == 5);
            REQUIRE(nbx.size() == 10);
            REQUIRE(nbx.dimensions() == std::tuple{ 2, 5 });

            REQUIRE(nbx == cxl::box<std::string> { { "", "", "", "", "" }
                                                    , { "", "", "", "", "" } });
        }
    }

    SECTION("Custom Allocted")
    {
        SECTION("Allocator Constructor")
        {
            std::allocator<int> alloc;
            cxl::box<int> bx(alloc);
            REQUIRE(bx.size() == 0);
            REQUIRE(bx.rows() == 0);
            REQUIRE(bx.columns() == 0);
            REQUIRE(bx.get_allocator() == alloc);
        }

        SECTION("Size Constructor")
        {
            std::allocator<int> alloc;
            cxl::box<int> bx(4, 5, alloc);
            REQUIRE(bx.size() == 20);
            REQUIRE(bx.rows() == 4);
            REQUIRE(bx.columns() == 5);
            REQUIRE(bx.get_allocator() == alloc);
        }

        SECTION("Size and Value Constructor")
        {
            std::allocator<int> alloc;
            cxl::box<int> bx(4, 5, 1, alloc);
            REQUIRE(bx.size() == 20);
            REQUIRE(bx.rows() == 4);
            REQUIRE(bx.columns() == 5);
            REQUIRE(bx.get_allocator() == alloc);
        }

        SECTION("Copy constructor")
        {
            std::allocator<int> alloc;
            cxl::box<int> bx(4, 5, 1, alloc);
            cxl::box<int> nbx(bx);

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
            cxl::box<int> bx(4, 5, 1, alloc);

            for (auto& v : bx)
                REQUIRE(v == 1);

            cxl::box<int> nbx(std::move(bx));

            REQUIRE(nbx.size() == 20);
            REQUIRE(nbx.rows() == 4);
            REQUIRE(nbx.columns() == 5);
            REQUIRE(nbx.get_allocator() == alloc);

            for (auto& v : nbx)
                REQUIRE(v == 1);
        }

        SECTION("Dimension Constructor") 
        {
            cxl::box<int> bx(2, 5);
            bx = { { 1, 2, 3, 4, 5 }
                 , { 6, 7, 8, 9, 10 } };
            
            REQUIRE(bx.rows() == 2);
            REQUIRE(bx.columns() == 5);
            REQUIRE(bx.size() == 10);
            REQUIRE(bx.dimensions() == std::tuple{ 2, 5 });
            
            REQUIRE(bx == cxl::box<int> { { 1, 2, 3, 4, 5 }
                                           , { 6, 7, 8, 9, 10 } });

            std::allocator<std::string> alloc;
            cxl::box<std::string> nbx(bx.dimensions(), alloc);

            REQUIRE(nbx.rows() == 2);
            REQUIRE(nbx.columns() == 5);
            REQUIRE(nbx.size() == 10);
            REQUIRE(nbx.dimensions() == std::tuple{ 2, 5 });

            REQUIRE(nbx == cxl::box<std::string> { { "", "", "", "", "" }
                                                    , { "", "", "", "", "" } });
        }
    }

    SECTION("Assignment Operators")
    {
        SECTION("Copy assignment")
        {
            cxl::box<int> bx(4, 5, 1);
            cxl::box<int> nbx;

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
            cxl::box<int> bx(4, 5, 1);
            cxl::box<int> nbx;

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
            cxl::box<int> bx = { { 1, 2, 3 }
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
            cxl::box<int> bx(3, 3, 1);

            auto ptr { bx.data() };

            REQUIRE(bx.size() == 9);
            REQUIRE(bx.dimensions() == std::tuple{3, 3});
            REQUIRE(bx.data() == ptr);
            REQUIRE(bx == cxl::box<int> { { 1, 1, 1 }
                                           , { 1, 1, 1 }
                                           , { 1, 1, 1 } });

            bx.assign({ { 1, 2, 3 }
                      , { 4, 5, 6 }
                      , { 7, 8, 9 } });
            
            REQUIRE(bx.size() == 9);
            REQUIRE(bx.dimensions() == std::tuple{3, 3});
            REQUIRE(bx.data() == ptr);
            REQUIRE(bx == cxl::box<int> { { 1, 2, 3 }
                                           , { 4, 5, 6 }
                                           , { 7, 8, 9 } });
        }

        SECTION("Larger Size")
        {
            cxl::box<int> bx(3, 3, 1);

            auto ptr { bx.data() };

            REQUIRE(bx.size() == 9);
            REQUIRE(bx.dimensions() == std::tuple{3, 3});
            REQUIRE(ptr == bx.data());
            REQUIRE(bx == cxl::box<int> { { 1, 1, 1 }
                                           , { 1, 1, 1 }
                                           , { 1, 1, 1 } });


            bx.assign({ { 1, 2, 3 }
                      , { 4, 5, 6 }
                      , { 7, 8, 9 }
                      , { 10, 11, 12 } });
            
            REQUIRE(bx.size() == 12);
            REQUIRE(bx.dimensions() == std::tuple{4, 3});
            REQUIRE(bx.data() != ptr);
            REQUIRE(bx == cxl::box<int> { { 1, 2, 3 }
                                           , { 4, 5, 6 }
                                           , { 7, 8, 9 }
                                           , { 10, 11, 12 } });
        }

        SECTION("Smaller Box")
        {
            cxl::box<int> bx(3, 3, 1);

            auto ptr { bx.data() };

            REQUIRE(bx.size() == 9);
            REQUIRE(bx.dimensions() == std::tuple{3, 3});
            REQUIRE(bx.data() == ptr);
            REQUIRE(bx == cxl::box<int> { { 1, 1, 1 }
                                           , { 1, 1, 1 }
                                           , { 1, 1, 1 } });

            bx.assign({ { 1, 2, 3, 4 } });

            REQUIRE(bx.size() == 4);
            REQUIRE(bx.dimensions() == std::tuple{1, 4});
            REQUIRE(bx.data() != ptr);
            REQUIRE(bx == cxl::box<int> { { 1, 2, 3, 4 } });
        }

        SECTION("Empty Box")
        {
            cxl::box<int> bx;

            auto ptr { bx.data() };

            REQUIRE(bx.size() == 0);
            REQUIRE(bx.dimensions() == std::tuple{0, 0});
            REQUIRE(ptr == bx.data());
            REQUIRE(bx == cxl::box<int> { });

            bx.assign({ { 1, 2, 3 }
                      , { 4, 5, 6 }
                      , { 7, 8, 9 } });
            
            REQUIRE(bx.size() == 9);
            REQUIRE(bx.dimensions() == std::tuple{3, 3});
            REQUIRE(bx.data() != ptr);
            REQUIRE(bx == cxl::box<int> { { 1, 2, 3 }
                                           , { 4, 5, 6 }
                                           , { 7, 8, 9 } });
        }
    }
}
