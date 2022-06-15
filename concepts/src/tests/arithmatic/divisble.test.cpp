#include <catch2/catch.hpp>
#include <concepts.hpp>

TEST_CASE("Integer types")
{
    SECTION("Signed Integers")
    {
        REQUIRE(cortex::Divisible<int>);
        REQUIRE(cortex::Divisible<short>);
        REQUIRE(cortex::Divisible<long>);
        REQUIRE(cortex::Divisible<long long>);
    }

    SECTION("Unsigned Integers")
    {
        REQUIRE(cortex::Divisible<unsigned>);
        REQUIRE(cortex::Divisible<unsigned short>);
        REQUIRE(cortex::Divisible<u_short>);
        REQUIRE(cortex::Divisible<unsigned long>);
        REQUIRE(cortex::Divisible<unsigned long long>);
    }

    SECTION("Bit Specific Integers")
    {
        REQUIRE(cortex::Divisible<int8_t>);
        REQUIRE(cortex::Divisible<int16_t>);
        REQUIRE(cortex::Divisible<int32_t>);
        REQUIRE(cortex::Divisible<int64_t>);
        REQUIRE(cortex::Divisible<uint8_t>);
        REQUIRE(cortex::Divisible<uint16_t>);
        REQUIRE(cortex::Divisible<uint32_t>);
        REQUIRE(cortex::Divisible<uint64_t>);
    }

    SECTION("Fast & Least Integers")
    {
        REQUIRE(cortex::Divisible<int_fast8_t>);
        REQUIRE(cortex::Divisible<int_fast16_t>);
        REQUIRE(cortex::Divisible<int_fast32_t>);
        REQUIRE(cortex::Divisible<int_fast64_t>);
        REQUIRE(cortex::Divisible<uint_fast8_t>);
        REQUIRE(cortex::Divisible<uint_fast16_t>);
        REQUIRE(cortex::Divisible<uint_fast32_t>);
        REQUIRE(cortex::Divisible<uint_fast64_t>);
    }
}

TEST_CASE("Floating Points")
{
    SECTION("Floats & Doubles")
    {
        REQUIRE(cortex::Divisible<float>);
        REQUIRE(cortex::Divisible<double>);
        REQUIRE(cortex::Divisible<long double>);
    }
}