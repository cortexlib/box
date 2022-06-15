#include <catch2/catch.hpp>
#include <concepts.hpp>
#include <string>
#include <vector>

TEST_CASE("Subscripting Tests")
{
    SECTION("Pointers")
    {
        REQUIRE(cortex::Subscriptible<int*, int>);
        REQUIRE(cortex::Subscriptible<int**, int>);

    }

    SECTION("Arrays")
    {
        REQUIRE(cortex::Subscriptible<int[], int>);
    }

    SECTION("Vectors")
    {
        REQUIRE(cortex::Subscriptible<std::vector<int>, int>);
    }

    SECTION("Strings")
    {
        REQUIRE(cortex::Subscriptible<std::string, int>);
    }
}