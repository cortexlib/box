#include <catch2/catch.hpp>
#include <box.hpp>
#include <functional>

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

    SECTION("box::map")
    {
        SECTION("box::map - Lambda")
        {
            cortex::box<int> bx = { { 0, 1 }
                                  , { 2, 3 }
                                  , { 4, 5 }
                                  , { 7, 6 }
                                  , { 8, 9 } };

            cortex::box<int> bxcheck = { { 0, 2 }
                                       , { 4, 6 }
                                       , { 8, 10 }
                                       , { 12, 14 }
                                       , { 16, 18 } };

            REQUIRE(bx.size() == 10);
            REQUIRE(bx.rows() == 5);
            REQUIRE(bx.columns() == 2);

            auto rbx { bx.map([](int i) { return i * 2; }) };

            REQUIRE(bx.size() == 10);
            REQUIRE(bx.rows() == 5);
            REQUIRE(bx.columns() == 2);

            REQUIRE(rbx.size() == 10);
            REQUIRE(rbx.rows() == 5);
        }

        SECTION("box::map - Lambda - Empty")
        {
            cortex::box<int> bx;

            REQUIRE(bx.empty());
            REQUIRE(bx.size() == 0);
            REQUIRE(bx.rows() == 0);
            REQUIRE(bx.columns() == 0);

            auto rbx { bx.map([](int i) { return i * 2; }) };

            REQUIRE(rbx.empty());
            REQUIRE(rbx.size() == 0);
            REQUIRE(rbx.rows() == 0);
            REQUIRE(rbx.columns() == 0);

            REQUIRE(rbx == bx);
        }

        SECTION("box::map - Double Call - Intermidiate")
        {
            cortex::box<int> bx = { { 0, 1 }
                                  , { 2, 3 }
                                  , { 4, 5 }
                                  , { 6, 7 }
                                  , { 8, 9 } };

            cortex::box<int> bxcheck = { { 0, 1 }
                                       , { 2, 3 }
                                       , { 4, 5 }
                                       , { 6, 7 }
                                       , { 8, 9 } };

            cortex::box<int> ibxcheck = { { 0, 2 }
                                        , { 4, 6 }
                                        , { 8, 10 }
                                        , { 12, 14 }
                                        , { 16, 18 } };

            cortex::box<int> rbxcheck = { { -3, -1 }
                                        , { -7, -5 }
                                        , { -11, -9 }
                                        , { -15, -13 }
                                        , { -19, -17 } };

            REQUIRE(bx.size() == 10);
            REQUIRE(bx.rows() == 5);
            REQUIRE(bx.columns() == 2);

            auto ibx { bx.map([](int i) { return i * 2; }) };

            REQUIRE(bx == bxcheck);

            REQUIRE(ibx.size() == 10);
            REQUIRE(ibx.rows() == 5);
            REQUIRE(ibx.columns() == 2);
            REQUIRE(ibx == ibxcheck);

            auto rbx { ibx.map([](int i) { return i ^ -3; }) };

            REQUIRE(ibx == ibxcheck);

            REQUIRE(rbx.size() == 10);
            REQUIRE(rbx.rows() == 5);
            REQUIRE(rbx.columns() == 2);
            REQUIRE(rbx == rbxcheck);
        }

        SECTION("box::map - Double Call - Chained")
        {
            cortex::box<int> bx = { { 0, 1 }
                                  , { 2, 3 }
                                  , { 4, 5 }
                                  , { 6, 7 }
                                  , { 8, 9 } };

            cortex::box<int> bxcheck = { { 0, 1 }
                                       , { 2, 3 }
                                       , { 4, 5 }
                                       , { 6, 7 }
                                       , { 8, 9 } };

            cortex::box<int> rbxcheck = { { -3, -1 }
                                        , { -7, -5 }
                                        , { -11, -9 }
                                        , { -15, -13 }
                                        , { -19, -17 } };

            REQUIRE(bx.size() == 10);
            REQUIRE(bx.rows() == 5);
            REQUIRE(bx.columns() == 2);

            auto rbx { bx.map([](int i) { return i * 2; }).map([](int i) { return i ^ -3; }) };

            REQUIRE(bx == bxcheck);

            REQUIRE(rbx.size() == 10);
            REQUIRE(rbx.rows() == 5);
            REQUIRE(rbx.columns() == 2);
            REQUIRE(rbx == rbxcheck);
        }

        /// note: Because the element type of the box
        /// has to be known, using a l-value reference 
        /// currently breaks the current type deduction 
        /// implentation of `box::map`. Thus lambdas must 
        /// have value semantics.
        SECTION("box::map - Named Lambda")
        {
            cortex::box<int> bx = { { 0, 1 }
                                  , { 2, 3 }
                                  , { 4, 5 }
                                  , { 6, 7 }
                                  , { 8, 9 } };

            auto square = [](const auto& i) { return i * i; };

            cortex::box<int> bxcheck = { { 0, 1 }
                                       , { 4, 9 }
                                       , { 16, 25 }
                                       , { 36, 49 }
                                       , { 64, 81 } };

            REQUIRE(bx.size() == 10);
            REQUIRE(bx.rows() == 5);
            REQUIRE(bx.columns() == 2);

            auto rbx { bx.map(square) };

            REQUIRE(bx.size() == 10);
            REQUIRE(bx.rows() == 5);
            REQUIRE(bx.columns() == 2);

            REQUIRE(rbx.size() == 10);
            REQUIRE(rbx.rows() == 5);
        }
    }

    SECTION("box::vflip")
    {
        SECTION("box::vflip - Empty")
        {
            cortex::box<int> bx;

            REQUIRE(bx.empty());
            REQUIRE(bx.size() == 0);
            REQUIRE(bx.rows() == 0);
            REQUIRE(bx.columns() == 0);

            auto rbx { bx.vflip() };

            REQUIRE(rbx.empty());
            REQUIRE(rbx.size() == 0);
            REQUIRE(rbx.rows() == 0);
            REQUIRE(rbx.columns() == 0);

            REQUIRE(rbx == bx);
        }

        SECTION("box::vflip - Single")
        {
            cortex::box<int> bx = { { 0 } };

            cortex::box<int> bxcheck = { { 0 } };

            cortex::box<int> rbxcheck = { { 0 } };

            REQUIRE(bx.size() == 1);
            REQUIRE(bx.rows() == 1);
            REQUIRE(bx.columns() == 1);

            auto rbx { bx.vflip() };

            REQUIRE(bx == bxcheck);

            REQUIRE(rbx.size() == 1);
            REQUIRE(rbx.rows() == 1);
            REQUIRE(rbx.columns() == 1);
            REQUIRE(rbx == rbxcheck);

            REQUIRE(rbx == bx);

            REQUIRE(rbx.vflip() == bx);
        }

        SECTION("box::vflip - Shaped")
        {
            cortex::box<int> bx = { { 0, 1 }
                                  , { 2, 3 }
                                  , { 4, 5 }
                                  , { 6, 7 }
                                  , { 8, 9 } };

            cortex::box<int> bxcheck = { { 0, 1 }
                                       , { 2, 3 }
                                       , { 4, 5 }
                                       , { 6, 7 }
                                       , { 8, 9 } };

            cortex::box<int> rbxcheck = { { 8, 9 }
                                        , { 6, 7 }
                                        , { 4, 5 }
                                        , { 2, 3 }
                                        , { 0, 1 } };

            REQUIRE(bx.size() == 10);
            REQUIRE(bx.dimensions() == std::tuple{5, 2});

            auto rbx { bx.vflip() };

            REQUIRE(bx == bxcheck);

            REQUIRE(rbx.size() == 10);
            REQUIRE(rbx.dimensions() == std::tuple{5, 2});
            REQUIRE(rbx == rbxcheck);

            REQUIRE(rbx.vflip() == bx);
        }
    }

    SECTION("box::hflip")
    {
        SECTION("box::hflip - Empty")
        {
            cortex::box<int> bx;

            REQUIRE(bx.empty());
            REQUIRE(bx.size() == 0);
            REQUIRE(bx.rows() == 0);
            REQUIRE(bx.columns() == 0);

            auto rbx { bx.hflip() };

            REQUIRE(rbx.empty());
            REQUIRE(rbx.size() == 0);
            REQUIRE(rbx.rows() == 0);
            REQUIRE(rbx.columns() == 0);

            REQUIRE(rbx == bx);
        }

        SECTION("box::hflip - Single")
        {
            cortex::box<int> bx = { { 0 } };

            cortex::box<int> bxcheck = { { 0 } };

            cortex::box<int> rbxcheck = { { 0 } };

            REQUIRE(bx.size() == 1);
            REQUIRE(bx.rows() == 1);
            REQUIRE(bx.columns() == 1);

            auto rbx { bx.hflip() };

            REQUIRE(bx == bxcheck);

            REQUIRE(rbx.size() == 1);
            REQUIRE(rbx.rows() == 1);
            REQUIRE(rbx.columns() == 1);
            REQUIRE(rbx == rbxcheck);

            REQUIRE(rbx == bx);

            REQUIRE(rbx.hflip() == bx);
        }

        SECTION("box::hflip - Shaped")
        {
            cortex::box<int> bx = { { 0, 1 }
                                  , { 2, 3 }
                                  , { 4, 5 }
                                  , { 6, 7 }
                                  , { 8, 9 } };

            cortex::box<int> bxcheck = { { 0, 1 }
                                       , { 2, 3 }
                                       , { 4, 5 }
                                       , { 6, 7 }
                                       , { 8, 9 } };

            cortex::box<int> rbxcheck = { { 1, 0 }
                                        , { 3, 2 }
                                        , { 5, 4 }
                                        , { 7, 6 }
                                        , { 9, 8 } };

            REQUIRE(bx.size() == 10);
            REQUIRE(bx.dimensions() == std::tuple{5, 2});

            REQUIRE(bx == bxcheck);

            auto rbx { bx.hflip() };

            REQUIRE(rbx.size() == 10);
            REQUIRE(rbx.dimensions() == std::tuple{5, 2});
            REQUIRE(rbx == rbxcheck);

            REQUIRE(rbx.hflip() == bx);
        }
    }
}