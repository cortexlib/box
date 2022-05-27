#include <catch2/catch.hpp>
#include <box.hpp>
#include <iostream>

TEST_CASE("Iterators")
{
    SECTION("Normal Iterators")
    {

        SECTION("Range for-loop")
        {
            cortex::box<int> bx(4, 5, 1);

            for (auto& elem : bx)
            {
                REQUIRE(elem == 1);
                elem = 2;
            }

            for (auto& elem : bx)
                REQUIRE(elem == 2);
        }

        SECTION("box::begin and box::end")
        {
            cortex::box<int> bx(4, 5);

            std::iota(bx.begin(), bx.end(), 1);

            auto idx { 1 };
            for (auto& elem : bx)
            {
                REQUIRE(elem == idx++);
                elem = 2 * elem;
            }

            idx = 1;
            for (auto& elem : bx)
            {
                REQUIRE(elem == idx * 2);
                ++idx;
            }
        }
    }

    SECTION("Reverse Iterators")
    {
        SECTION("range-for reversed")
        {
            cortex::box<int> bx = { { 1, 2 }
                                  , { 3, 4 } };

            for (auto v { 4 }; auto& elem : bx | std::views::reverse)
            
                REQUIRE(elem == v--);
        }

        SECTION("box::rbegin and box::rend")
        {
            cortex::box<int> bx(4, 5);

            std::iota(bx.begin(), bx.end(), 1);

            auto idx { 20 };
            for (auto& elem : bx | std::views::reverse)
            {
                REQUIRE(elem == idx--);
                elem *= 2;
            }

            idx = 20;
            for (auto& elem : bx | std::views::reverse)
                REQUIRE(elem == 2 * idx--);
        }
    }

    SECTION("Row Iterator")
    {
        SECTION("box::row_begin and box::row_end")
        {
            cortex::box<int> bx(4, 5);

            std::iota(bx.begin(), bx.end(), 1);

            auto idx { 1 };
            for ( auto elem { bx.row_begin() }; elem != bx.row_end(); ++elem)
            {    
                REQUIRE(*elem == idx++);
                *elem *= 5;
            }
            
            REQUIRE(bx == cortex::box<int>{ { 5, 10, 15, 20, 25 }
                                          , { 6, 7, 8, 9, 10 }
                                          , { 11, 12, 13, 14, 15 }
                                          , { 16, 17, 18, 19, 20 } });

            std::transform(bx.row_begin(2), bx.row_end(2), bx.row_begin(2), [](auto& elem) { return elem / 3; });

            REQUIRE(bx == cortex::box<int>{ { 5, 10, 15, 20, 25 }
                                          , { 6, 7, 8, 9, 10 }
                                          , { 3, 4, 4, 4, 5 }
                                          , { 16, 17, 18, 19, 20 } });
        }
    }
}