#include <catch2/catch.hpp>
#include <concepts.hpp>
#include <string>
#include <vector>
#include <list>
#include <optional>

TEST_CASE("Testing Any against builtin types")
{
    SECTION("Int, chars, floats etc.")
    {
        REQUIRE(cortex::Any<int>);
        REQUIRE(cortex::Any<unsigned>);
        REQUIRE(cortex::Any<short>);
        REQUIRE(cortex::Any<char>);
        REQUIRE(cortex::Any<long>);
        REQUIRE(cortex::Any<long long>);
        REQUIRE(cortex::Any<float>);
        REQUIRE(cortex::Any<double>);
    }

    SECTION("Pointers and Arrays")
    {
        REQUIRE(cortex::Any<int*>);
        REQUIRE(cortex::Any<int**>);
        REQUIRE(cortex::Any<int[]>);
        REQUIRE(cortex::Any<int[2]>);
    }

    SECTION("STL Containers")
    {
        REQUIRE(cortex::Any<std::vector<int>>);
        REQUIRE(cortex::Any<std::list<int>>);
        REQUIRE(cortex::Any<std::string>);
        REQUIRE(cortex::Any<std::optional<int>>);
        REQUIRE(cortex::Any<std::wstring>);
    }
}