#include <catch2/catch.hpp>
#include <concepts.hpp>

TEST_CASE("Integer types")
{
    SECTION("Signed Integers")
    {
        REQUIRE(cortex::BitXor<int>);
        REQUIRE(cortex::BitXor<short>);
        REQUIRE(cortex::BitXor<long>);
        REQUIRE(cortex::BitXor<long long>);
    }

    SECTION("Unsigned Integers")
    {
        REQUIRE(cortex::BitXor<unsigned>);
        REQUIRE(cortex::BitXor<unsigned short>);
        REQUIRE(cortex::BitXor<u_short>);
        REQUIRE(cortex::BitXor<unsigned long>);
        REQUIRE(cortex::BitXor<unsigned long long>);
    }

    SECTION("Bit Specific Integers")
    {
        REQUIRE(cortex::BitXor<int8_t>);
        REQUIRE(cortex::BitXor<int16_t>);
        REQUIRE(cortex::BitXor<int32_t>);
        REQUIRE(cortex::BitXor<int64_t>);
        REQUIRE(cortex::BitXor<uint8_t>);
        REQUIRE(cortex::BitXor<uint16_t>);
        REQUIRE(cortex::BitXor<uint32_t>);
        REQUIRE(cortex::BitXor<uint64_t>);
    }

    SECTION("Fast & Least Integers")
    {
        REQUIRE(cortex::BitXor<int_fast8_t>);
        REQUIRE(cortex::BitXor<int_fast16_t>);
        REQUIRE(cortex::BitXor<int_fast32_t>);
        REQUIRE(cortex::BitXor<int_fast64_t>);
        REQUIRE(cortex::BitXor<uint_fast8_t>);
        REQUIRE(cortex::BitXor<uint_fast16_t>);
        REQUIRE(cortex::BitXor<uint_fast32_t>);
        REQUIRE(cortex::BitXor<uint_fast64_t>);
    }

    SECTION("Character Types")
    {
        REQUIRE(cortex::BitXor<char>);
        REQUIRE(cortex::BitXor<u_char>);
        REQUIRE(cortex::BitXor<wchar_t>);
        REQUIRE(cortex::BitXor<char8_t>);
        REQUIRE(cortex::BitXor<char16_t>);
        REQUIRE(cortex::BitXor<char32_t>);
    }
}