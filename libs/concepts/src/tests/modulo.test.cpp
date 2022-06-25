#include <catch2/catch.hpp>
#include <concepts.hpp>

TEST_CASE("Integer types")
{
    SECTION("Signed Integers")
    {
        REQUIRE(cortex::Modulo<int>);
        REQUIRE(cortex::Modulo<short>);
        REQUIRE(cortex::Modulo<long>);
        REQUIRE(cortex::Modulo<long long>);
    }

    SECTION("Unsigned Integers")
    {
        REQUIRE(cortex::Modulo<unsigned>);
        REQUIRE(cortex::Modulo<unsigned short>);
        REQUIRE(cortex::Modulo<u_short>);
        REQUIRE(cortex::Modulo<unsigned long>);
        REQUIRE(cortex::Modulo<unsigned long long>);
    }

    SECTION("Bit Specific Integers")
    {
        REQUIRE(cortex::Modulo<int8_t>);
        REQUIRE(cortex::Modulo<int16_t>);
        REQUIRE(cortex::Modulo<int32_t>);
        REQUIRE(cortex::Modulo<int64_t>);
        REQUIRE(cortex::Modulo<uint8_t>);
        REQUIRE(cortex::Modulo<uint16_t>);
        REQUIRE(cortex::Modulo<uint32_t>);
        REQUIRE(cortex::Modulo<uint64_t>);
    }

    SECTION("Fast & Least Integers")
    {
        REQUIRE(cortex::Modulo<int_fast8_t>);
        REQUIRE(cortex::Modulo<int_fast16_t>);
        REQUIRE(cortex::Modulo<int_fast32_t>);
        REQUIRE(cortex::Modulo<int_fast64_t>);
        REQUIRE(cortex::Modulo<uint_fast8_t>);
        REQUIRE(cortex::Modulo<uint_fast16_t>);
        REQUIRE(cortex::Modulo<uint_fast32_t>);
        REQUIRE(cortex::Modulo<uint_fast64_t>);
    }
}