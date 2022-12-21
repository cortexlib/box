#include <catch2/catch.hpp>
#include <box.hpp>

TEST_CASE("Element Access")
{
    SECTION("Raw Data")
    {
        SECTION("box::data")
        {
            cxl::box<int> bx(4, 5, 1);
            REQUIRE(bx.data() != nullptr);
        }

        SECTION("box::front")
        {
            cxl::box<int> bx(4, 5, 1);
            REQUIRE(bx.front() == 1);

            bx.front() = 2;
            REQUIRE(bx.front() == 2);
        }

        SECTION("box::back")
        {
            cxl::box<int> bx(4, 5, 1);
            REQUIRE(bx.back() == 1);

            bx.back() = 2;
            REQUIRE(bx.back() == 2);
        }
    }

    SECTION("Accessors")
    {
        SECTION("box::at")
        {
            cxl::box<int> bx(4, 5, 1);
            REQUIRE(bx.at(0, 1) == 1);

            bx.at(0, 1) = 2;
            REQUIRE(bx.at(0, 1) == 2);

            REQUIRE_THROWS_AS(bx.at(10, 1), std::out_of_range);
        }

        SECTION("box::slice")
        {
            cxl::box<int> bx { { 1, 2, 3 }
                                , { 4, 5, 6 }
                                , { 7, 8, 9 } };

            auto slc { bx.slice(2) };
            REQUIRE(slc.size() == 3);
            REQUIRE(slc[0] == 7);
            REQUIRE(slc[1] == 8);
            REQUIRE(slc[2] == 9);
            REQUIRE(slc.data() == bx.data() + 2 * bx.columns());

            REQUIRE_THROWS_AS(bx.slice(10), std::out_of_range);
        }

        SECTION("box::operator[]")
        {
            cxl::box<int> bx { { 1, 2, 3 }
                                , { 4, 5, 6 }
                                , { 7, 8, 9 } };

            auto slc { bx[2] };
            REQUIRE(slc.size() == 3);
            REQUIRE(slc[0] == 7);
            REQUIRE(slc[1] == 8);
            REQUIRE(slc[2] == 9);
            REQUIRE(slc.data() == bx.data() + 2 * bx.columns());

            REQUIRE(bx[1][1] == 5);

            REQUIRE_THROWS_AS(bx[10], std::out_of_range);
        }

        SECTION("box::operator()")
        {
            cxl::box<int> bx(4, 5, 1);
            REQUIRE(bx(0, 1) == 1);

            bx(1, 1) = 2;
            REQUIRE(bx(1, 1) == 2);

            REQUIRE_THROWS_AS(bx(4, 1), std::out_of_range);
        }
    }
}