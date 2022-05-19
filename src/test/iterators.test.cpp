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
}