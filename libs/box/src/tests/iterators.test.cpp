#include <catch2/catch.hpp>
#include <box.hpp>

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

            auto value { 1 };
            for (auto& elem : bx)
            {
                REQUIRE(elem == value++);
                elem = 2 * elem;
            }

            value = 1;
            for (auto& elem : bx)
            {
                REQUIRE(elem == value * 2);
                ++value;
            }
        }
    }

    SECTION("Reverse Iterators")
    {
        SECTION("range-for reversed")
        {
            cortex::box<int> bx = { { 1, 2 }
                                  , { 3, 4 } };

            std::reverse(bx.begin(), bx.end());

            for (auto v { 4 }; auto& elem : bx)
            
                REQUIRE(elem == v--);
        }

        SECTION("box::rbegin and box::rend")
        {
            cortex::box<int> bx(4, 5);

            std::iota(bx.begin(), bx.end(), 1);

            auto value { 20 };
            std::reverse(bx.begin(), bx.end());

            for (auto& elem : bx)
            {
                REQUIRE(elem == value--);
                elem *= 2;
            }

            value = 20;
            std::reverse(bx.begin(), bx.end());
            std::reverse(bx.begin(), bx.end());
            
            for (auto& elem : bx)
                REQUIRE(elem == 2 * value--);
        }
    }

    SECTION("Row Iterator")
    {
        SECTION("box::row_begin and box::row_end")
        {
            cortex::box<int> bx(4, 5);

            std::iota(bx.begin(), bx.end(), 1);

            auto value { 1 };
            for ( auto elem { bx.row_begin() }; elem != bx.row_end(); ++elem)
            {    
                REQUIRE(*elem == value++);
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

        SECTION("box::row_rbegin and box::row_rend")
        {
            cortex::box<int> bx(4, 5);

            std::iota(bx.begin(), bx.end(), 1);

            auto value { 20 };
            for ( auto elem { bx.row_rbegin(3) }; elem != bx.row_rend(3); ++elem)
            {    
                REQUIRE(*elem == value--);
                *elem *= 5;
            }
            
            REQUIRE(bx == cortex::box<int>{ { 1, 2, 3, 4, 5 }
                                          , { 6, 7, 8, 9, 10 }
                                          , { 11, 12, 13, 14, 15 }
                                          , { 80, 85, 90, 95, 100 } });

            std::transform(bx.row_rbegin(), bx.row_rend(), bx.row_rbegin(), [](auto& elem) { return elem % 4; });

            REQUIRE(bx == cortex::box<int>{ { 1, 2, 3, 0, 1 }
                                          , { 6, 7, 8, 9, 10 }
                                          , { 11, 12, 13, 14, 15 }
                                          , { 80, 85, 90, 95, 100 } });
        }

        SECTION("Cross Row Iteration")
        {
            cortex::box<int> bx(4, 5);

            std::iota(bx.begin(), bx.end(), 1);

            auto value { 1 };
            for ( auto elem { bx.row_begin() }; elem != bx.row_end(1); ++elem)
            {    
                REQUIRE(*elem == value++);
                *elem *= 5;
            }
            
            REQUIRE(bx == cortex::box<int>{ { 5, 10, 15, 20, 25 }
                                          , { 30, 35, 40, 45, 50 }
                                          , { 11, 12, 13, 14, 15 }
                                          , { 16, 17, 18, 19, 20 } });

            std::transform(bx.row_rbegin(3), bx.row_rend(2), bx.row_rbegin(3), [](auto& elem) { return elem << 4; });

            REQUIRE(bx == cortex::box<int>{ { 5, 10, 15, 20, 25 }
                                          , { 30, 35, 40, 45, 50 }
                                          , { 176, 192, 208, 224, 240 }
                                          , { 256, 272, 288, 304, 320 } });
        }
    }

    SECTION("Column Iterator")
    {
        SECTION("box::column_begin and box::column_end")
        {
            cortex::box<int> bx(3, 6);

            std::iota(bx.begin(), bx.end(), 1);

            
            auto value { 1 };
            for ( auto elem { bx.column_begin() }; elem != bx.column_end(); ++elem)
            { 
                REQUIRE(*elem == value);
                *elem /= 3;
                value += static_cast<int>(bx.columns());
            }
            
            REQUIRE(bx == cortex::box<int>{ { 0, 2, 3, 4, 5, 6 }
                                          , { 2, 8, 9, 10, 11, 12 }
                                          , { 4, 14, 15, 16, 17, 18 } });

            std::transform(bx.column_begin(4), bx.column_end(4), bx.column_begin(4), [](auto& elem) { return elem & 13; });

            REQUIRE(bx == cortex::box<int>{ { 0, 2, 3, 4, 5, 6 }
                                          , { 2, 8, 9, 10, 9, 12 }
                                          , { 4, 14, 15, 16, 1, 18 } });
        }

        SECTION("box::column_rbegin and box::column_rend")
        {
            cortex::box<int> bx(4, 5);

            std::iota(bx.begin(), bx.end(), 1);

            auto value { 19 };
            for ( auto elem { bx.column_rbegin(3) }; elem != bx.column_rend(3); ++elem)
            {    
                REQUIRE(*elem == value);
                *elem ^= 3;
                value -= static_cast<int>(bx.columns());
            }
            
            REQUIRE(bx == cortex::box<int>{ { 1, 2, 3, 7, 5 }
                                          , { 6, 7, 8, 10, 10 }
                                          , { 11, 12, 13, 13, 15 }
                                          , { 16, 17, 18, 16, 20 } });

            std::transform(bx.column_rbegin(), bx.column_rend(), bx.column_rbegin(), [](auto& elem) { return elem | 9; });

            REQUIRE(bx == cortex::box<int>{ { 9, 2, 3, 7, 5 }
                                          , { 15, 7, 8, 10, 10 }
                                          , { 11, 12, 13, 13, 15 }
                                          , { 25, 17, 18, 16, 20 } });
        }

        SECTION("Cross Column Iteration")
        {
            cortex::box<int> bx(4, 5);

            std::iota(bx.begin(), bx.end(), 1);

            auto value { 1 };
            auto ridx { 0 };
            auto cidx { 1 };
            for (auto elem { bx.column_begin() }; elem != bx.column_end(2); ++elem)
            {    
                REQUIRE(*elem == value);
                *elem &= 5;

                value += static_cast<int>(bx.columns());

                if (++ridx == static_cast<int>(bx.rows()))
                {
                    ridx = 0;
                    cidx++;
                    value = cidx;
                }
                    
            }
            
            REQUIRE(bx == cortex::box<int>{ { 1, 0, 1, 4, 5 }
                                          , { 4, 5, 0, 9, 10 }
                                          , { 1, 4, 5, 14, 15 }
                                          , { 0, 1, 0, 19, 20 } });

            std::transform(bx.column_rbegin(4), bx.column_rend(3), bx.column_rbegin(4), [](auto& elem) { return elem % 4; });

            REQUIRE(bx == cortex::box<int>{ { 1, 0, 1, 0, 1 }
                                          , { 4, 5, 0, 1, 2 }
                                          , { 1, 4, 5, 2, 3 }
                                          , { 0, 1, 0, 3, 0 } });
        }
    }
}