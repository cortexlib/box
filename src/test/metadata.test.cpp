#include <catch2/catch.hpp>
#include <box.hpp>

TEST_CASE("MetaData Access")
{
    SECTION("Dimensions")
    {
        SECTION("box::size")
        {
            cortex::box<int> bx(4, 5);
            REQUIRE(bx.size() == 20);
        }

        SECTION("box::max_size")
        {
            std::allocator<int> alloc;
            cortex::box<int> bx(4, 5, 1);
            REQUIRE(bx.max_size() == std::allocator_traits<decltype(alloc)>::max_size(alloc));
        }

        SECTION("box::rows")
        {
            cortex::box<int> bx(4, 5);
            REQUIRE(bx.rows() == 4);
        }

        SECTION("box::columns")
        {
            cortex::box<int> bx(4, 5);
            REQUIRE(bx.columns() == 5);
        }

        SECTION("box::dimensions - Tuple")
        {
            cortex::box<int> bx(4, 5, 1);
            auto dim = bx.dimensions();

            REQUIRE(std::get<0>(dim) == 4);
            REQUIRE(std::get<1>(dim) == 5);
        }

        SECTION("box::dimensions - Structured Binding")
        {
            cortex::box<int> bx(4, 5, 1);
            auto [c, r] = bx.dimensions();

            REQUIRE(c == 4);
            REQUIRE(r == 5);
        }
    }

    SECTION("Recources")
    {
        SECTION("box::empty")
        {
            cortex::box<int> bx;
            REQUIRE(bx.empty());
        }

        SECTION("box::empty")
        {
            cortex::box<int> bx(4, 5, 1);
            REQUIRE(!bx.empty());
        }

        SECTION("box::get_allocator")
        {
            cortex::box<int> bx(4, 5, 1);
            REQUIRE(bx.get_allocator() == std::allocator<int>());
        }
    }
}