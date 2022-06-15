#include <catch2/catch.hpp>
#include <concepts.hpp>

TEST_CASE("Integer types")
{
    SECTION("Signed Integers")
    {
        REQUIRE(cortex::BitNot<int>);
        REQUIRE(cortex::BitNot<short>);
        REQUIRE(cortex::BitNot<long>);
        REQUIRE(cortex::BitNot<long long>);
    }

    SECTION("Unsigned Integers")
    {
        REQUIRE(cortex::BitNot<unsigned>);
        REQUIRE(cortex::BitNot<unsigned short>);
        REQUIRE(cortex::BitNot<u_short>);
        REQUIRE(cortex::BitNot<unsigned long>);
        REQUIRE(cortex::BitNot<unsigned long long>);
    }

    SECTION("Bit Specific Integers")
    {
        REQUIRE(cortex::BitNot<int8_t>);
        REQUIRE(cortex::BitNot<int16_t>);
        REQUIRE(cortex::BitNot<int32_t>);
        REQUIRE(cortex::BitNot<int64_t>);
        REQUIRE(cortex::BitNot<uint8_t>);
        REQUIRE(cortex::BitNot<uint16_t>);
        REQUIRE(cortex::BitNot<uint32_t>);
        REQUIRE(cortex::BitNot<uint64_t>);
    }

    SECTION("Fast & Least Integers")
    {
        REQUIRE(cortex::BitNot<int_fast8_t>);
        REQUIRE(cortex::BitNot<int_fast16_t>);
        REQUIRE(cortex::BitNot<int_fast32_t>);
        REQUIRE(cortex::BitNot<int_fast64_t>);
        REQUIRE(cortex::BitNot<uint_fast8_t>);
        REQUIRE(cortex::BitNot<uint_fast16_t>);
        REQUIRE(cortex::BitNot<uint_fast32_t>);
        REQUIRE(cortex::BitNot<uint_fast64_t>);
    }

    SECTION("Character Types")
    {
        REQUIRE(cortex::BitNot<char>);
        REQUIRE(cortex::BitNot<u_char>);
        REQUIRE(cortex::BitNot<wchar_t>);
        REQUIRE(cortex::BitNot<char8_t>);
        REQUIRE(cortex::BitNot<char16_t>);
        REQUIRE(cortex::BitNot<char32_t>);
    }
}