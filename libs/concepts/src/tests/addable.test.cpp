#include <catch2/catch.hpp>
#include <concepts.hpp>
#include <string>

TEST_CASE("Integer types")
{
    SECTION("Signed Integers")
    {
        REQUIRE(cortex::Addable<int>);
        REQUIRE(cortex::Addable<short>);
        REQUIRE(cortex::Addable<long>);
        REQUIRE(cortex::Addable<long long>);
    }

    SECTION("Unsigned Integers")
    {
        REQUIRE(cortex::Addable<unsigned>);
        REQUIRE(cortex::Addable<unsigned short>);
        REQUIRE(cortex::Addable<u_short>);
        REQUIRE(cortex::Addable<unsigned long>);
        REQUIRE(cortex::Addable<unsigned long long>);
    }

    SECTION("Bit Specific Integers")
    {
        REQUIRE(cortex::Addable<int8_t>);
        REQUIRE(cortex::Addable<int16_t>);
        REQUIRE(cortex::Addable<int32_t>);
        REQUIRE(cortex::Addable<int64_t>);
        REQUIRE(cortex::Addable<uint8_t>);
        REQUIRE(cortex::Addable<uint16_t>);
        REQUIRE(cortex::Addable<uint32_t>);
        REQUIRE(cortex::Addable<uint64_t>);
    }

    SECTION("Fast & Least Integers")
    {
        REQUIRE(cortex::Addable<int_fast8_t>);
        REQUIRE(cortex::Addable<int_fast16_t>);
        REQUIRE(cortex::Addable<int_fast32_t>);
        REQUIRE(cortex::Addable<int_fast64_t>);
        REQUIRE(cortex::Addable<uint_fast8_t>);
        REQUIRE(cortex::Addable<uint_fast16_t>);
        REQUIRE(cortex::Addable<uint_fast32_t>);
        REQUIRE(cortex::Addable<uint_fast64_t>);
    }
}

TEST_CASE("Floating Points")
{
    SECTION("Floats & Doubles")
    {
        REQUIRE(cortex::Addable<float>);
        REQUIRE(cortex::Addable<double>);
        REQUIRE(cortex::Addable<long double>);
    }
}

TEST_CASE("std::string and variants")
{
    SECTION("std::string")
    {
        REQUIRE(cortex::Addable<std::string>);
    }

    SECTION("std::wstring")
    {
        REQUIRE(cortex::Addable<std::wstring>);
    }

    SECTION("std::u8string")
    {
        REQUIRE(cortex::Addable<std::u8string>);
    }

    SECTION("std::u16string")
    {
        REQUIRE(cortex::Addable<std::u16string>);
    }

    SECTION("std::u32string")
    {
        REQUIRE(cortex::Addable<std::u32string>);
    }
}