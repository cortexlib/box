#include <catch2/catch.hpp>
#include <concepts.hpp>

TEST_CASE("Integer types")
{
    SECTION("Signed Integers")
    {
        REQUIRE(cortex::BitAnd<int>);
        REQUIRE(cortex::BitAnd<short>);
        REQUIRE(cortex::BitAnd<long>);
        REQUIRE(cortex::BitAnd<long long>);
    }

    SECTION("Unsigned Integers")
    {
        REQUIRE(cortex::BitAnd<unsigned>);
        REQUIRE(cortex::BitAnd<unsigned short>);
        REQUIRE(cortex::BitAnd<u_short>);
        REQUIRE(cortex::BitAnd<unsigned long>);
        REQUIRE(cortex::BitAnd<unsigned long long>);
    }

    SECTION("Bit Specific Integers")
    {
        REQUIRE(cortex::BitAnd<int8_t>);
        REQUIRE(cortex::BitAnd<int16_t>);
        REQUIRE(cortex::BitAnd<int32_t>);
        REQUIRE(cortex::BitAnd<int64_t>);
        REQUIRE(cortex::BitAnd<uint8_t>);
        REQUIRE(cortex::BitAnd<uint16_t>);
        REQUIRE(cortex::BitAnd<uint32_t>);
        REQUIRE(cortex::BitAnd<uint64_t>);
    }

    SECTION("Fast & Least Integers")
    {
        REQUIRE(cortex::BitAnd<int_fast8_t>);
        REQUIRE(cortex::BitAnd<int_fast16_t>);
        REQUIRE(cortex::BitAnd<int_fast32_t>);
        REQUIRE(cortex::BitAnd<int_fast64_t>);
        REQUIRE(cortex::BitAnd<uint_fast8_t>);
        REQUIRE(cortex::BitAnd<uint_fast16_t>);
        REQUIRE(cortex::BitAnd<uint_fast32_t>);
        REQUIRE(cortex::BitAnd<uint_fast64_t>);
    }

    SECTION("Character Types")
    {
        REQUIRE(cortex::BitAnd<char>);
        REQUIRE(cortex::BitAnd<u_char>);
        REQUIRE(cortex::BitAnd<wchar_t>);
        REQUIRE(cortex::BitAnd<char8_t>);
        REQUIRE(cortex::BitAnd<char16_t>);
        REQUIRE(cortex::BitAnd<char32_t>);
    }
}