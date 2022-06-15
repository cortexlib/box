#include <catch2/catch.hpp>
#include <box.hpp>

TEST_CASE("Element Access")
{
    SECTION("Raw Data")
    {
        SECTION("box::data")
        {
            cortex::box<int> bx(4, 5, 1);
            REQUIRE(bx.data() != nullptr);
        }

        SECTION("box::front")
        {
            cortex::box<int> bx(4, 5, 1);
            REQUIRE(bx.front() == 1);

            bx.front() = 2;
            REQUIRE(bx.front() == 2);
        }

        SECTION("box::back")
        {
            cortex::box<int> bx(4, 5, 1);
            REQUIRE(bx.back() == 1);

            bx.back() = 2;
            REQUIRE(bx.back() == 2);
        }
    }

    SECTION("Accessors")
    {
        SECTION("box::at")
        {
            cortex::box<int> bx(4, 5, 1);
            REQUIRE(bx.at(0, 1) == 1);

            bx.at(0, 1) = 2;
            REQUIRE(bx.at(0, 1) == 2);

            REQUIRE_THROWS_AS(bx.at(10, 1), std::out_of_range);
        }

        SECTION("box::operator[]")
        {
            cortex::box<int> bx(4, 5, 1);
            REQUIRE(bx[0] == 1);

            bx[0] = 2;
            REQUIRE(bx[0] == 2);
        }

        SECTION("box::operator()")
        {
            cortex::box<int> bx(4, 5, 1);
            REQUIRE(bx(0, 1) == 1);

            bx(1, 1) = 2;
            REQUIRE(bx(1, 1) == 2);

            REQUIRE_THROWS_AS(bx(4, 1), std::out_of_range);
        }
    }
}