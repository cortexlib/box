#include <catch2/catch.hpp>
#include <concepts.hpp>

TEST_CASE("Integer types")
{
    SECTION("Signed Integers")
    {
        REQUIRE(cortex::LeftBitShift<int>);
        REQUIRE(cortex::LeftBitShift<short>);
        REQUIRE(cortex::LeftBitShift<long>);
        REQUIRE(cortex::LeftBitShift<long long>);
    }

    SECTION("Unsigned Integers")
    {
        REQUIRE(cortex::LeftBitShift<unsigned>);
        REQUIRE(cortex::LeftBitShift<unsigned short>);
        REQUIRE(cortex::LeftBitShift<u_short>);
        REQUIRE(cortex::LeftBitShift<unsigned long>);
        REQUIRE(cortex::LeftBitShift<unsigned long long>);
    }

    SECTION("Bit Specific Integers")
    {
        REQUIRE(cortex::LeftBitShift<int8_t>);
        REQUIRE(cortex::LeftBitShift<int16_t>);
        REQUIRE(cortex::LeftBitShift<int32_t>);
        REQUIRE(cortex::LeftBitShift<int64_t>);
        REQUIRE(cortex::LeftBitShift<uint8_t>);
        REQUIRE(cortex::LeftBitShift<uint16_t>);
        REQUIRE(cortex::LeftBitShift<uint32_t>);
        REQUIRE(cortex::LeftBitShift<uint64_t>);
    }

    SECTION("Fast & Least Integers")
    {
        REQUIRE(cortex::LeftBitShift<int_fast8_t>);
        REQUIRE(cortex::LeftBitShift<int_fast16_t>);
        REQUIRE(cortex::LeftBitShift<int_fast32_t>);
        REQUIRE(cortex::LeftBitShift<int_fast64_t>);
        REQUIRE(cortex::LeftBitShift<uint_fast8_t>);
        REQUIRE(cortex::LeftBitShift<uint_fast16_t>);
        REQUIRE(cortex::LeftBitShift<uint_fast32_t>);
        REQUIRE(cortex::LeftBitShift<uint_fast64_t>);
    }

    SECTION("Character Types")
    {
        REQUIRE(cortex::LeftBitShift<char>);
        REQUIRE(cortex::LeftBitShift<u_char>);
        REQUIRE(cortex::LeftBitShift<wchar_t>);
        REQUIRE(cortex::LeftBitShift<char8_t>);
        REQUIRE(cortex::LeftBitShift<char16_t>);
        REQUIRE(cortex::LeftBitShift<char32_t>);
    }
}