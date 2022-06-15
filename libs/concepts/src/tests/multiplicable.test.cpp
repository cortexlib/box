#include <catch2/catch.hpp>
#include <concepts.hpp>

TEST_CASE("Integer types")
{
    SECTION("Signed Integers")
    {
        REQUIRE(cortex::Multiplicable<int>);
        REQUIRE(cortex::Multiplicable<short>);
        REQUIRE(cortex::Multiplicable<long>);
        REQUIRE(cortex::Multiplicable<long long>);
    }

    SECTION("Unsigned Integers")
    {
        REQUIRE(cortex::Multiplicable<unsigned>);
        REQUIRE(cortex::Multiplicable<unsigned short>);
        REQUIRE(cortex::Multiplicable<u_short>);
        REQUIRE(cortex::Multiplicable<unsigned long>);
        REQUIRE(cortex::Multiplicable<unsigned long long>);
    }

    SECTION("Bit Specific Integers")
    {
        REQUIRE(cortex::Multiplicable<int8_t>);
        REQUIRE(cortex::Multiplicable<int16_t>);
        REQUIRE(cortex::Multiplicable<int32_t>);
        REQUIRE(cortex::Multiplicable<int64_t>);
        REQUIRE(cortex::Multiplicable<uint8_t>);
        REQUIRE(cortex::Multiplicable<uint16_t>);
        REQUIRE(cortex::Multiplicable<uint32_t>);
        REQUIRE(cortex::Multiplicable<uint64_t>);
    }

    SECTION("Fast & Least Integers")
    {
        REQUIRE(cortex::Multiplicable<int_fast8_t>);
        REQUIRE(cortex::Multiplicable<int_fast16_t>);
        REQUIRE(cortex::Multiplicable<int_fast32_t>);
        REQUIRE(cortex::Multiplicable<int_fast64_t>);
        REQUIRE(cortex::Multiplicable<uint_fast8_t>);
        REQUIRE(cortex::Multiplicable<uint_fast16_t>);
        REQUIRE(cortex::Multiplicable<uint_fast32_t>);
        REQUIRE(cortex::Multiplicable<uint_fast64_t>);
    }
}

TEST_CASE("Floating Points")
{
    SECTION("Floats & Doubles")
    {
        REQUIRE(cortex::Multiplicable<float>);
        REQUIRE(cortex::Multiplicable<double>);
        REQUIRE(cortex::Multiplicable<long double>);
    }
}