#include <catch2/catch.hpp>
#include <concepts.hpp>

TEST_CASE("Integer types")
{
    SECTION("Signed Integers")
    {
        REQUIRE(cortex::RightBitShift<int>);
        REQUIRE(cortex::RightBitShift<short>);
        REQUIRE(cortex::RightBitShift<long>);
        REQUIRE(cortex::RightBitShift<long long>);
    }

    SECTION("Unsigned Integers")
    {
        REQUIRE(cortex::RightBitShift<unsigned>);
        REQUIRE(cortex::RightBitShift<unsigned short>);
        REQUIRE(cortex::RightBitShift<u_short>);
        REQUIRE(cortex::RightBitShift<unsigned long>);
        REQUIRE(cortex::RightBitShift<unsigned long long>);
    }

    SECTION("Bit Specific Integers")
    {
        REQUIRE(cortex::RightBitShift<int8_t>);
        REQUIRE(cortex::RightBitShift<int16_t>);
        REQUIRE(cortex::RightBitShift<int32_t>);
        REQUIRE(cortex::RightBitShift<int64_t>);
        REQUIRE(cortex::RightBitShift<uint8_t>);
        REQUIRE(cortex::RightBitShift<uint16_t>);
        REQUIRE(cortex::RightBitShift<uint32_t>);
        REQUIRE(cortex::RightBitShift<uint64_t>);
    }

    SECTION("Fast & Least Integers")
    {
        REQUIRE(cortex::RightBitShift<int_fast8_t>);
        REQUIRE(cortex::RightBitShift<int_fast16_t>);
        REQUIRE(cortex::RightBitShift<int_fast32_t>);
        REQUIRE(cortex::RightBitShift<int_fast64_t>);
        REQUIRE(cortex::RightBitShift<uint_fast8_t>);
        REQUIRE(cortex::RightBitShift<uint_fast16_t>);
        REQUIRE(cortex::RightBitShift<uint_fast32_t>);
        REQUIRE(cortex::RightBitShift<uint_fast64_t>);
    }

    SECTION("Character Types")
    {
        REQUIRE(cortex::RightBitShift<char>);
        REQUIRE(cortex::RightBitShift<u_char>);
        REQUIRE(cortex::RightBitShift<wchar_t>);
        REQUIRE(cortex::RightBitShift<char8_t>);
        REQUIRE(cortex::RightBitShift<char16_t>);
        REQUIRE(cortex::RightBitShift<char32_t>);
    }
}