#include <catch2/catch.hpp>
#include <box.hpp>

// Transpose, Flip, Rotate etc

TEST_CASE("Modifications")
{
    SECTION("box::transpose")
    {
        SECTION("box::transpose - Normal")
        {
            cortex::box<int> bx = { { 0, 1 }
                                    , { 2, 3 }
                                    , { 4, 5 }
                                    , { 7, 6 }
                                    , { 8, 9 } };

            cortex::box<int> bxcheck = { { 0, 2, 4, 7, 8 }
                                        , { 1, 3, 5, 6, 9 } };

            REQUIRE(bx.size() == 10);
            REQUIRE(bx.rows() == 5);
            REQUIRE(bx.columns() == 2);

            auto rbx { bx.transpose() };

            REQUIRE(bx.size() == 10);
            REQUIRE(bx.rows() == 5);
            REQUIRE(bx.columns() == 2);

            REQUIRE(rbx.size() == 10);
            REQUIRE(rbx.rows() == 2);
            REQUIRE(rbx.columns() == 5);

            REQUIRE(rbx == bxcheck);
        }

        SECTION("box::transpose - Double transpose")
        {
            cortex::box<int> bx = { { 0, 1 }
                                    , { 2, 3 }
                                    , { 4, 5 }
                                    , { 7, 6 }
                                    , { 8, 9 } };

            cortex::box<int> bxcheck = { { 0, 2, 4, 7, 8 }
                                        , { 1, 3, 5, 6, 9 } };

            REQUIRE(bx.size() == 10);
            REQUIRE(bx.rows() == 5);
            REQUIRE(bx.columns() == 2);

            auto rbx { bx.transpose() };

            REQUIRE(bx.size() == 10);
            REQUIRE(bx.rows() == 5);
            REQUIRE(bx.columns() == 2);

            REQUIRE(rbx.size() == 10);
            REQUIRE(rbx.rows() == 2);
            REQUIRE(rbx.columns() == 5);

            REQUIRE(rbx == bxcheck);

            auto rrbx { rbx.transpose() };

            REQUIRE(rbx.size() == 10);
            REQUIRE(rbx.rows() == 2);
            REQUIRE(rbx.columns() == 5);

            REQUIRE(rrbx == bx);
        }

        SECTION("box::transpose - Double transpose in-place")
        {
            cortex::box<int> bx = { { 0, 1 }
                                  , { 2, 3 }
                                  , { 4, 5 }
                                  , { 7, 6 }
                                  , { 8, 9 } };

            cortex::box<int> bxcheck = { { 0, 2, 4, 7, 8 }
                                       , { 1, 3, 5, 6, 9 } };

            REQUIRE(bx.size() == 10);
            REQUIRE(bx.rows() == 5);
            REQUIRE(bx.columns() == 2);

            auto rbx { bx.transpose().transpose() };

            REQUIRE(rbx.size() == 10);
            REQUIRE(rbx.rows() == 5);
            REQUIRE(rbx.columns() == 2);

            REQUIRE(rbx == bx);
        }

        SECTION("box::transpose - Empty")
        {
            cortex::box<int> bx;

            REQUIRE(bx.empty());
            REQUIRE(bx.size() == 0);
            REQUIRE(bx.rows() == 0);
            REQUIRE(bx.columns() == 0);

            auto rbx { bx.transpose() };

            REQUIRE(rbx.size() == 0);
            REQUIRE(rbx.rows() == 0);
            REQUIRE(rbx.columns() == 0);

            REQUIRE(rbx == bx);
        }

        SECTION("box::transpose - Column to Row")
        {
            cortex::box<int> bx = { { 5, 1 } };

            cortex::box<int> bxcheck = { { 5 }
                                       , { 1 } };

            REQUIRE(bx.size() == 2);
            REQUIRE(bx.rows() == 1);
            REQUIRE(bx.columns() == 2);

            auto rbx { bx.transpose() };

            REQUIRE(rbx.size() == 2);
            REQUIRE(rbx.rows() == 2);
            REQUIRE(rbx.columns() == 1);

            REQUIRE(rbx == bxcheck);
        }

        SECTION("box::transpose - Row to Column")
        {
            cortex::box<int> bx = { { 54 }
                                    , { 73 } 
                                    , { 12 } };

            cortex::box<int> bxcheck = { { 54, 73, 12} };

            REQUIRE(bx.size() == 3);
            REQUIRE(bx.rows() == 3);
            REQUIRE(bx.columns() == 1);

            auto rbx { bx.transpose() };

            REQUIRE(rbx.size() == 3);
            REQUIRE(rbx.rows() == 1);
            REQUIRE(rbx.columns() == 3);

            REQUIRE(rbx == bxcheck);
        }

        SECTION("box::transpose - Single Element")
        {
            cortex::box<int> bx = { { 5 } };

            REQUIRE(bx.size() == 1);
            REQUIRE(bx.rows() == 1);
            REQUIRE(bx.columns() == 1);

            auto rbx { bx.transpose() };

            REQUIRE(rbx.size() == 1);
            REQUIRE(rbx.rows() == 1);
            REQUIRE(rbx.columns() == 1);

            REQUIRE(rbx == bx);
        }
    }
}