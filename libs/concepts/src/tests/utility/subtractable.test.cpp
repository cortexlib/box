#include <catch2/catch.hpp>
#include <concepts.hpp>

TEST_CASE("Integer types")
{
    SECTION("Signed Integers")
    {
        REQUIRE(cortex::Subtractable<int>);
        REQUIRE(cortex::Subtractable<short>);
        REQUIRE(cortex::Subtractable<long>);
        REQUIRE(cortex::Subtractable<long long>);
    }

    SECTION("Unsigned Integers")
    {
        REQUIRE(cortex::Subtractable<unsigned>);
        REQUIRE(cortex::Subtractable<unsigned short>);
        REQUIRE(cortex::Subtractable<u_short>);
        REQUIRE(cortex::Subtractable<unsigned long>);
        REQUIRE(cortex::Subtractable<unsigned long long>);
    }

    SECTION("Bit Specific Integers")
    {
        REQUIRE(cortex::Subtractable<int8_t>);
        REQUIRE(cortex::Subtractable<int16_t>);
        REQUIRE(cortex::Subtractable<int32_t>);
        REQUIRE(cortex::Subtractable<int64_t>);
        REQUIRE(cortex::Subtractable<uint8_t>);
        REQUIRE(cortex::Subtractable<uint16_t>);
        REQUIRE(cortex::Subtractable<uint32_t>);
        REQUIRE(cortex::Subtractable<uint64_t>);
    }

    SECTION("Fast & Least Integers")
    {
        REQUIRE(cortex::Subtractable<int_fast8_t>);
        REQUIRE(cortex::Subtractable<int_fast16_t>);
        REQUIRE(cortex::Subtractable<int_fast32_t>);
        REQUIRE(cortex::Subtractable<int_fast64_t>);
        REQUIRE(cortex::Subtractable<uint_fast8_t>);
        REQUIRE(cortex::Subtractable<uint_fast16_t>);
        REQUIRE(cortex::Subtractable<uint_fast32_t>);
        REQUIRE(cortex::Subtractable<uint_fast64_t>);
    }
}

TEST_CASE("Floating Points")
{
    SECTION("Floats & Doubles")
    {
        REQUIRE(cortex::Subtractable<float>);
        REQUIRE(cortex::Subtractable<double>);
        REQUIRE(cortex::Subtractable<long double>);
    }
}