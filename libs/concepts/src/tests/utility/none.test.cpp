#include <catch2/catch.hpp>
#include <concepts.hpp>
#include <string>
#include <vector>
#include <list>
#include <optional>

TEST_CASE("Testing None against builtin types")
{
    SECTION("Int, chars, floats etc.")
    {
        REQUIRE(!cortex::None<int>);
        REQUIRE(!cortex::None<unsigned>);
        REQUIRE(!cortex::None<short>);
        REQUIRE(!cortex::None<char>);
        REQUIRE(!cortex::None<long>);
        REQUIRE(!cortex::None<long long>);
        REQUIRE(!cortex::None<float>);
        REQUIRE(!cortex::None<double>);
    }

    SECTION("Pointers and Arrays")
    {
        REQUIRE(!cortex::None<int*>);
        REQUIRE(!cortex::None<int**>);
        REQUIRE(!cortex::None<int[]>);
        REQUIRE(!cortex::None<int[2]>);
    }

    SECTION("STL Containers")
    {
        REQUIRE(!cortex::None<std::vector<int>>);
        REQUIRE(!cortex::None<std::list<int>>);
        REQUIRE(!cortex::None<std::string>);
        REQUIRE(!cortex::None<std::optional<int>>);
        REQUIRE(!cortex::None<std::wstring>);
    }
}