#include <catch2/catch.hpp>
#include <concepts.hpp>

TEST_CASE("Integer types")
{
    SECTION("Signed Integers")
    {
        REQUIRE(cortex::BitOr<int>);
        REQUIRE(cortex::BitOr<short>);
        REQUIRE(cortex::BitOr<long>);
        REQUIRE(cortex::BitOr<long long>);
    }

    SECTION("Unsigned Integers")
    {
        REQUIRE(cortex::BitOr<unsigned>);
        REQUIRE(cortex::BitOr<unsigned short>);
        REQUIRE(cortex::BitOr<u_short>);
        REQUIRE(cortex::BitOr<unsigned long>);
        REQUIRE(cortex::BitOr<unsigned long long>);
    }

    SECTION("Bit Specific Integers")
    {
        REQUIRE(cortex::BitOr<int8_t>);
        REQUIRE(cortex::BitOr<int16_t>);
        REQUIRE(cortex::BitOr<int32_t>);
        REQUIRE(cortex::BitOr<int64_t>);
        REQUIRE(cortex::BitOr<uint8_t>);
        REQUIRE(cortex::BitOr<uint16_t>);
        REQUIRE(cortex::BitOr<uint32_t>);
        REQUIRE(cortex::BitOr<uint64_t>);
    }

    SECTION("Fast & Least Integers")
    {
        REQUIRE(cortex::BitOr<int_fast8_t>);
        REQUIRE(cortex::BitOr<int_fast16_t>);
        REQUIRE(cortex::BitOr<int_fast32_t>);
        REQUIRE(cortex::BitOr<int_fast64_t>);
        REQUIRE(cortex::BitOr<uint_fast8_t>);
        REQUIRE(cortex::BitOr<uint_fast16_t>);
        REQUIRE(cortex::BitOr<uint_fast32_t>);
        REQUIRE(cortex::BitOr<uint_fast64_t>);
    }

    SECTION("Character Types")
    {
        REQUIRE(cortex::BitOr<char>);
        REQUIRE(cortex::BitOr<u_char>);
        REQUIRE(cortex::BitOr<wchar_t>);
        REQUIRE(cortex::BitOr<char8_t>);
        REQUIRE(cortex::BitOr<char16_t>);
        REQUIRE(cortex::BitOr<char32_t>);
    }
}