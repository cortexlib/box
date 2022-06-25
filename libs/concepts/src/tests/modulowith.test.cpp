#include <catch2/catch.hpp>
#include <concepts.hpp>

TEST_CASE("ModuloWith : Signed Integers")
{
    SECTION("Int with _")
    {
        // Int with Signed Integers
        REQUIRE(cortex::ModuloWith<int, int>);
        REQUIRE(cortex::ModuloWith<int, short>);
        REQUIRE(cortex::ModuloWith<int, long>);
        REQUIRE(cortex::ModuloWith<int, long long>);

        // Int with Unsigned Integers
        REQUIRE(cortex::ModuloWith<int, unsigned>);
        REQUIRE(cortex::ModuloWith<int, unsigned short>);
        REQUIRE(cortex::ModuloWith<int, u_short>);
        REQUIRE(cortex::ModuloWith<int, unsigned long>);
        REQUIRE(cortex::ModuloWith<int, unsigned long long>);

        // Integers with Bit Specific Integers
        REQUIRE(cortex::ModuloWith<int, int8_t>);
        REQUIRE(cortex::ModuloWith<int, int16_t>);
        REQUIRE(cortex::ModuloWith<int, int32_t>);
        REQUIRE(cortex::ModuloWith<int, int64_t>);

        // Integers with Bit Specific Unsigned Integers
        REQUIRE(cortex::ModuloWith<int, uint8_t>);
        REQUIRE(cortex::ModuloWith<int, uint16_t>);
        REQUIRE(cortex::ModuloWith<int, uint32_t>);
        REQUIRE(cortex::ModuloWith<int, uint64_t>);

        // Integers with Bit Specific Least Integers
        REQUIRE(cortex::ModuloWith<int, int_least8_t>);
        REQUIRE(cortex::ModuloWith<int, int_least16_t>);
        REQUIRE(cortex::ModuloWith<int, int_least32_t>);
        REQUIRE(cortex::ModuloWith<int, int_least64_t>);
    }

    SECTION("Short with _")
    {
        // Short with Signed Integers
        REQUIRE(cortex::ModuloWith<short, int>);
        REQUIRE(cortex::ModuloWith<short, short>);
        REQUIRE(cortex::ModuloWith<short, long>);
        REQUIRE(cortex::ModuloWith<short, long long>);

        // Short with Unsigned Integers
        REQUIRE(cortex::ModuloWith<short, unsigned>);
        REQUIRE(cortex::ModuloWith<short, unsigned short>);
        REQUIRE(cortex::ModuloWith<short, u_short>);
        REQUIRE(cortex::ModuloWith<short, unsigned long>);
        REQUIRE(cortex::ModuloWith<short, unsigned long long>);
        
        // Short with Bit Specific Short
        REQUIRE(cortex::ModuloWith<short, int8_t>);
        REQUIRE(cortex::ModuloWith<short, int16_t>);
        REQUIRE(cortex::ModuloWith<short, int32_t>);
        REQUIRE(cortex::ModuloWith<short, int64_t>);

        // Short with Bit Specific Unsigned Short
        REQUIRE(cortex::ModuloWith<short, uint8_t>);
        REQUIRE(cortex::ModuloWith<short, uint16_t>);
        REQUIRE(cortex::ModuloWith<short, uint32_t>);
        REQUIRE(cortex::ModuloWith<short, uint64_t>);

        // Short with Bit Specific Least Integers
        REQUIRE(cortex::ModuloWith<short, int_least8_t>);
        REQUIRE(cortex::ModuloWith<short, int_least16_t>);
        REQUIRE(cortex::ModuloWith<short, int_least32_t>);
        REQUIRE(cortex::ModuloWith<short, int_least64_t>);
    }

    SECTION("Long with _")
    {
        // Long with Signed Integers
        REQUIRE(cortex::ModuloWith<long, int>);
        REQUIRE(cortex::ModuloWith<long, short>);
        REQUIRE(cortex::ModuloWith<long, long>);
        REQUIRE(cortex::ModuloWith<long, long long>);

        // Long with Unsigned Integers
        REQUIRE(cortex::ModuloWith<long, unsigned>);
        REQUIRE(cortex::ModuloWith<long, unsigned short>);
        REQUIRE(cortex::ModuloWith<long, u_short>);
        REQUIRE(cortex::ModuloWith<long, unsigned long>);
        REQUIRE(cortex::ModuloWith<long, unsigned long long>);
        
        // Long with Bit Specific Long
        REQUIRE(cortex::ModuloWith<long, int8_t>);
        REQUIRE(cortex::ModuloWith<long, int16_t>);
        REQUIRE(cortex::ModuloWith<long, int32_t>);
        REQUIRE(cortex::ModuloWith<long, int64_t>);

        // Long with Bit Specific Unsigned Long
        REQUIRE(cortex::ModuloWith<long, uint8_t>);
        REQUIRE(cortex::ModuloWith<long, uint16_t>);
        REQUIRE(cortex::ModuloWith<long, uint32_t>);
        REQUIRE(cortex::ModuloWith<long, uint64_t>);

        // Long with Bit Specific Least Integers
        REQUIRE(cortex::ModuloWith<long, int_least8_t>);
        REQUIRE(cortex::ModuloWith<long, int_least16_t>);
        REQUIRE(cortex::ModuloWith<long, int_least32_t>);
        REQUIRE(cortex::ModuloWith<long, int_least64_t>);
    }

    SECTION("Long Long with _")
    {
        // Signed Integers
        REQUIRE(cortex::ModuloWith<long long, int>);
        REQUIRE(cortex::ModuloWith<long long, short>);
        REQUIRE(cortex::ModuloWith<long long, long>);
        REQUIRE(cortex::ModuloWith<long long, long long>);

        // Unsigned Integers
        REQUIRE(cortex::ModuloWith<long long, unsigned>);
        REQUIRE(cortex::ModuloWith<long long, unsigned short>);
        REQUIRE(cortex::ModuloWith<long long, u_short>);
        REQUIRE(cortex::ModuloWith<long long, unsigned long>);
        REQUIRE(cortex::ModuloWith<long long, unsigned long long>);
        
        // Integers with Bit Specific Integers
        REQUIRE(cortex::ModuloWith<long long, int8_t>);
        REQUIRE(cortex::ModuloWith<long long, int16_t>);
        REQUIRE(cortex::ModuloWith<long long, int32_t>);
        REQUIRE(cortex::ModuloWith<long long, int64_t>);

        // Integers with Bit Specific Unsigned Integers
        REQUIRE(cortex::ModuloWith<long long, uint8_t>);
        REQUIRE(cortex::ModuloWith<long long, uint16_t>);
        REQUIRE(cortex::ModuloWith<long long, uint32_t>);
        REQUIRE(cortex::ModuloWith<long long, uint64_t>);

        // Long Long with Bit Specific Least Integers
        REQUIRE(cortex::ModuloWith<long long, int_least8_t>);
        REQUIRE(cortex::ModuloWith<long long, int_least16_t>);
        REQUIRE(cortex::ModuloWith<long long, int_least32_t>);
        REQUIRE(cortex::ModuloWith<long long, int_least64_t>);
    }
}

TEST_CASE("ModuloWith: Unsigned Integers")
{
    SECTION("Unsigned Int with _")
    {
        // Unsigned Integers with Signed Integers
        REQUIRE(cortex::ModuloWith<unsigned int, int>);
        REQUIRE(cortex::ModuloWith<unsigned int, short>);
        REQUIRE(cortex::ModuloWith<unsigned int, long>);
        REQUIRE(cortex::ModuloWith<unsigned int, long long>);

        // Unsigned Integers with Unsigned Integers
        REQUIRE(cortex::ModuloWith<unsigned int, unsigned>);
        REQUIRE(cortex::ModuloWith<unsigned int, unsigned short>);
        REQUIRE(cortex::ModuloWith<unsigned int, u_short>);
        REQUIRE(cortex::ModuloWith<unsigned int, unsigned long>);
        REQUIRE(cortex::ModuloWith<unsigned int, unsigned long long>);
        
        // Unsigned Integers with Bit Specific Integers
        REQUIRE(cortex::ModuloWith<unsigned int, int8_t>);
        REQUIRE(cortex::ModuloWith<unsigned int, int16_t>);
        REQUIRE(cortex::ModuloWith<unsigned int, int32_t>);
        REQUIRE(cortex::ModuloWith<unsigned int, int64_t>);

        // Unsigned Integers with Bit Specific Unsigned Integers
        REQUIRE(cortex::ModuloWith<unsigned int, uint8_t>);
        REQUIRE(cortex::ModuloWith<unsigned int, uint16_t>);
        REQUIRE(cortex::ModuloWith<unsigned int, uint32_t>);
        REQUIRE(cortex::ModuloWith<unsigned int, uint64_t>);

        // Unsigned Integers with Bit Specific Least Integers
        REQUIRE(cortex::ModuloWith<unsigned int, int_least8_t>);
        REQUIRE(cortex::ModuloWith<unsigned int, int_least16_t>);
        REQUIRE(cortex::ModuloWith<unsigned int, int_least32_t>);
        REQUIRE(cortex::ModuloWith<unsigned int, int_least64_t>);
    }

    SECTION("Unsigned Short with _")
    {
        // Unsigned Short with Signed Integers
        REQUIRE(cortex::ModuloWith<unsigned short, int>);
        REQUIRE(cortex::ModuloWith<unsigned short, short>);
        REQUIRE(cortex::ModuloWith<unsigned short, long>);
        REQUIRE(cortex::ModuloWith<unsigned short, long long>);

        // Unsigned Short with Unsigned Integers
        REQUIRE(cortex::ModuloWith<unsigned short, unsigned>);
        REQUIRE(cortex::ModuloWith<unsigned short, unsigned short>);
        REQUIRE(cortex::ModuloWith<unsigned short, u_short>);
        REQUIRE(cortex::ModuloWith<unsigned short, unsigned long>);
        REQUIRE(cortex::ModuloWith<unsigned short, unsigned long long>);
        
        // Unsigned Short with Bit Specific Short
        REQUIRE(cortex::ModuloWith<unsigned short, int8_t>);
        REQUIRE(cortex::ModuloWith<unsigned short, int16_t>);
        REQUIRE(cortex::ModuloWith<unsigned short, int32_t>);
        REQUIRE(cortex::ModuloWith<unsigned short, int64_t>);

        // Unsigned Short with Bit Specific Unsigned Short
        REQUIRE(cortex::ModuloWith<unsigned short, uint8_t>);
        REQUIRE(cortex::ModuloWith<unsigned short, uint16_t>);
        REQUIRE(cortex::ModuloWith<unsigned short, uint32_t>);
        REQUIRE(cortex::ModuloWith<unsigned short, uint64_t>);

        // Unsigned Short with Bit Specific Least Integers
        REQUIRE(cortex::ModuloWith<unsigned short, int_least8_t>);
        REQUIRE(cortex::ModuloWith<unsigned short, int_least16_t>);
        REQUIRE(cortex::ModuloWith<unsigned short, int_least32_t>);
        REQUIRE(cortex::ModuloWith<unsigned short, int_least64_t>);
    }

    SECTION("u_short with _")
    {
        // u_short with Signed Integers
        REQUIRE(cortex::ModuloWith<u_short, int>);
        REQUIRE(cortex::ModuloWith<u_short, short>);
        REQUIRE(cortex::ModuloWith<u_short, long>);
        REQUIRE(cortex::ModuloWith<u_short, long long>);

        // u_short with Unsigned Integers
        REQUIRE(cortex::ModuloWith<u_short, unsigned>);
        REQUIRE(cortex::ModuloWith<u_short, unsigned short>);
        REQUIRE(cortex::ModuloWith<u_short, u_short>);
        REQUIRE(cortex::ModuloWith<u_short, unsigned long>);
        REQUIRE(cortex::ModuloWith<u_short, unsigned long long>);
        
        // u_short with Bit Specific Short
        REQUIRE(cortex::ModuloWith<u_short, int8_t>);
        REQUIRE(cortex::ModuloWith<u_short, int16_t>);
        REQUIRE(cortex::ModuloWith<u_short, int32_t>);
        REQUIRE(cortex::ModuloWith<u_short, int64_t>);

        // u_short with Bit Specific Unsigned Short
        REQUIRE(cortex::ModuloWith<u_short, uint8_t>);
        REQUIRE(cortex::ModuloWith<u_short, uint16_t>);
        REQUIRE(cortex::ModuloWith<u_short, uint32_t>);
        REQUIRE(cortex::ModuloWith<u_short, uint64_t>);

        // u_short with Bit Specific Least Integers
        REQUIRE(cortex::ModuloWith<u_short, int_least8_t>);
        REQUIRE(cortex::ModuloWith<u_short, int_least16_t>);
        REQUIRE(cortex::ModuloWith<u_short, int_least32_t>);
        REQUIRE(cortex::ModuloWith<u_short, int_least64_t>);
    }

    SECTION("Unsigned Long with _")
    {
        // Unsigned Long with Signed Integers
        REQUIRE(cortex::ModuloWith<unsigned long, int>);
        REQUIRE(cortex::ModuloWith<unsigned long, short>);
        REQUIRE(cortex::ModuloWith<unsigned long, long>);
        REQUIRE(cortex::ModuloWith<unsigned long, long long>);

        // Unsigned Long with Unsigned Integers
        REQUIRE(cortex::ModuloWith<unsigned long, unsigned>);
        REQUIRE(cortex::ModuloWith<unsigned long, unsigned short>);
        REQUIRE(cortex::ModuloWith<unsigned long, u_short>);
        REQUIRE(cortex::ModuloWith<unsigned long, unsigned long>);
        REQUIRE(cortex::ModuloWith<unsigned long, unsigned long long>);
        
        // Unsigned Long with Bit Specific Long
        REQUIRE(cortex::ModuloWith<unsigned long, int8_t>);
        REQUIRE(cortex::ModuloWith<unsigned long, int16_t>);
        REQUIRE(cortex::ModuloWith<unsigned long, int32_t>);
        REQUIRE(cortex::ModuloWith<unsigned long, int64_t>);

        // Unsigned Long with Bit Specific Unsigned Long
        REQUIRE(cortex::ModuloWith<unsigned long, uint8_t>);
        REQUIRE(cortex::ModuloWith<unsigned long, uint16_t>);
        REQUIRE(cortex::ModuloWith<unsigned long, uint32_t>);
        REQUIRE(cortex::ModuloWith<unsigned long, uint64_t>);

        // Unsigned Long with Bit Specific Least Integers
        REQUIRE(cortex::ModuloWith<unsigned long, int_least8_t>);
        REQUIRE(cortex::ModuloWith<unsigned long, int_least16_t>);
        REQUIRE(cortex::ModuloWith<unsigned long, int_least32_t>);
        REQUIRE(cortex::ModuloWith<unsigned long, int_least64_t>);
    }

    SECTION("Unsigned Long Long with _")
    {
        // Unsigned Long Long with Signed Integers
        REQUIRE(cortex::ModuloWith<unsigned long long, int>);
        REQUIRE(cortex::ModuloWith<unsigned long long, short>);
        REQUIRE(cortex::ModuloWith<unsigned long long, long>);
        REQUIRE(cortex::ModuloWith<unsigned long long, long long>);

        // Unsigned Long Long with Unsigned Integers
        REQUIRE(cortex::ModuloWith<unsigned long long, unsigned>);
        REQUIRE(cortex::ModuloWith<unsigned long long, unsigned short>);
        REQUIRE(cortex::ModuloWith<unsigned long long, u_short>);
        REQUIRE(cortex::ModuloWith<unsigned long long, unsigned long>);
        REQUIRE(cortex::ModuloWith<unsigned long long, unsigned long long>);
        
        // Unsigned Long Long with Bit Specific Long Long
        REQUIRE(cortex::ModuloWith<unsigned long long, int8_t>);
        REQUIRE(cortex::ModuloWith<unsigned long long, int16_t>);
        REQUIRE(cortex::ModuloWith<unsigned long long, int32_t>);
        REQUIRE(cortex::ModuloWith<unsigned long long, int64_t>);

        // Unsigned Long Long with Bit Specific Unsigned Long Long
        REQUIRE(cortex::ModuloWith<unsigned long long, uint8_t>);
        REQUIRE(cortex::ModuloWith<unsigned long long, uint16_t>);
        REQUIRE(cortex::ModuloWith<unsigned long long, uint32_t>);
        REQUIRE(cortex::ModuloWith<unsigned long long, uint64_t>);

        // Long Long with Bit Specific Least Long Long
        REQUIRE(cortex::ModuloWith<unsigned long long, int_least8_t>);
        REQUIRE(cortex::ModuloWith<unsigned long long, int_least16_t>);
        REQUIRE(cortex::ModuloWith<unsigned long long, int_least32_t>);
        REQUIRE(cortex::ModuloWith<unsigned long long, int_least64_t>);
    }
}

TEST_CASE("Addable With : Bit Specific Signed Integers")
{
    SECTION("int8_t with _")
    {
        // int8_t with Signed Integers
        REQUIRE(cortex::ModuloWith<int8_t, int>);
        REQUIRE(cortex::ModuloWith<int8_t, short>);
        REQUIRE(cortex::ModuloWith<int8_t, long>);
        REQUIRE(cortex::ModuloWith<int8_t, long long>);

        // int8_t with Unsigned Integers
        REQUIRE(cortex::ModuloWith<int8_t, unsigned>);
        REQUIRE(cortex::ModuloWith<int8_t, unsigned short>);
        REQUIRE(cortex::ModuloWith<int8_t, u_short>);
        REQUIRE(cortex::ModuloWith<int8_t, unsigned long>);
        REQUIRE(cortex::ModuloWith<int8_t, unsigned long long>);

        // int8_t with Bit Specific Integers
        REQUIRE(cortex::ModuloWith<int8_t, int8_t>);
        REQUIRE(cortex::ModuloWith<int8_t, int16_t>);
        REQUIRE(cortex::ModuloWith<int8_t, int32_t>);
        REQUIRE(cortex::ModuloWith<int8_t, int64_t>);

        // int8_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::ModuloWith<int8_t, uint8_t>);
        REQUIRE(cortex::ModuloWith<int8_t, uint16_t>);
        REQUIRE(cortex::ModuloWith<int8_t, uint32_t>);
        REQUIRE(cortex::ModuloWith<int8_t, uint64_t>);

        // int8_t with Bit Specific Least Integers
        REQUIRE(cortex::ModuloWith<int8_t, int_least8_t>);
        REQUIRE(cortex::ModuloWith<int8_t, int_least16_t>);
        REQUIRE(cortex::ModuloWith<int8_t, int_least32_t>);
        REQUIRE(cortex::ModuloWith<int8_t, int_least64_t>);
    }

    SECTION("int16_t with _")
    {
        // int16_t with Signed Integers
        REQUIRE(cortex::ModuloWith<int16_t, int>);
        REQUIRE(cortex::ModuloWith<int16_t, short>);
        REQUIRE(cortex::ModuloWith<int16_t, long>);
        REQUIRE(cortex::ModuloWith<int16_t, long long>);

        // int16_t with Unsigned Integers
        REQUIRE(cortex::ModuloWith<int16_t, unsigned>);
        REQUIRE(cortex::ModuloWith<int16_t, unsigned short>);
        REQUIRE(cortex::ModuloWith<int16_t, u_short>);
        REQUIRE(cortex::ModuloWith<int16_t, unsigned long>);
        REQUIRE(cortex::ModuloWith<int16_t, unsigned long long>);
        
        // int16_t with Bit Specific Characters
        REQUIRE(cortex::ModuloWith<int16_t, char8_t>);
        REQUIRE(cortex::ModuloWith<int16_t, char16_t>);
        REQUIRE(cortex::ModuloWith<int16_t, char32_t>);

        // int16_t with Bit Specific Integers
        REQUIRE(cortex::ModuloWith<int16_t, int8_t>);
        REQUIRE(cortex::ModuloWith<int16_t, int16_t>);
        REQUIRE(cortex::ModuloWith<int16_t, int32_t>);
        REQUIRE(cortex::ModuloWith<int16_t, int64_t>);

        // int16_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::ModuloWith<int16_t, uint8_t>);
        REQUIRE(cortex::ModuloWith<int16_t, uint16_t>);
        REQUIRE(cortex::ModuloWith<int16_t, uint32_t>);
        REQUIRE(cortex::ModuloWith<int16_t, uint64_t>);

        // int16_t with Bit Specific Least Integers
        REQUIRE(cortex::ModuloWith<int16_t, int_least8_t>);
        REQUIRE(cortex::ModuloWith<int16_t, int_least16_t>);
        REQUIRE(cortex::ModuloWith<int16_t, int_least32_t>);
        REQUIRE(cortex::ModuloWith<int16_t, int_least64_t>);
    }

    SECTION("int32 with _")
    {
        // int32 with Signed Integers
        REQUIRE(cortex::ModuloWith<int32_t, int>);
        REQUIRE(cortex::ModuloWith<int32_t, short>);
        REQUIRE(cortex::ModuloWith<int32_t, long>);
        REQUIRE(cortex::ModuloWith<int32_t, long long>);

        // int32 with Unsigned Integers
        REQUIRE(cortex::ModuloWith<int32_t, unsigned>);
        REQUIRE(cortex::ModuloWith<int32_t, unsigned short>);
        REQUIRE(cortex::ModuloWith<int32_t, u_short>);
        REQUIRE(cortex::ModuloWith<int32_t, unsigned long>);
        REQUIRE(cortex::ModuloWith<int32_t, unsigned long long>);
        
        // int32_t with Bit Specific Integers
        REQUIRE(cortex::ModuloWith<int32_t, int8_t>);
        REQUIRE(cortex::ModuloWith<int32_t, int16_t>);
        REQUIRE(cortex::ModuloWith<int32_t, int32_t>);
        REQUIRE(cortex::ModuloWith<int32_t, int64_t>);

        // int32_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::ModuloWith<int32_t, uint8_t>);
        REQUIRE(cortex::ModuloWith<int32_t, uint16_t>);
        REQUIRE(cortex::ModuloWith<int32_t, uint32_t>);
        REQUIRE(cortex::ModuloWith<int32_t, uint64_t>);

        // int32_t with Bit Specific Least Integers
        REQUIRE(cortex::ModuloWith<int32_t, int_least8_t>);
        REQUIRE(cortex::ModuloWith<int32_t, int_least16_t>);
        REQUIRE(cortex::ModuloWith<int32_t, int_least32_t>);
        REQUIRE(cortex::ModuloWith<int32_t, int_least64_t>);
    }

    SECTION("int64 with _")
    {
        // int64 with Signed Integers
        REQUIRE(cortex::ModuloWith<int64_t, int>);
        REQUIRE(cortex::ModuloWith<int64_t, short>);
        REQUIRE(cortex::ModuloWith<int64_t, long>);
        REQUIRE(cortex::ModuloWith<int64_t, long long>);

        // int64 with Unsigned Integers
        REQUIRE(cortex::ModuloWith<int64_t, unsigned>);
        REQUIRE(cortex::ModuloWith<int64_t, unsigned short>);
        REQUIRE(cortex::ModuloWith<int64_t, u_short>);
        REQUIRE(cortex::ModuloWith<int64_t, unsigned long>);
        REQUIRE(cortex::ModuloWith<int64_t, unsigned long long>);
        
        // int64_t with Bit Specific Integers
        REQUIRE(cortex::ModuloWith<int64_t, int8_t>);
        REQUIRE(cortex::ModuloWith<int64_t, int16_t>);
        REQUIRE(cortex::ModuloWith<int64_t, int32_t>);
        REQUIRE(cortex::ModuloWith<int64_t, int64_t>);

        // int64_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::ModuloWith<int64_t, uint8_t>);
        REQUIRE(cortex::ModuloWith<int64_t, uint16_t>);
        REQUIRE(cortex::ModuloWith<int64_t, uint32_t>);
        REQUIRE(cortex::ModuloWith<int64_t, uint64_t>);

        // int64_t with Bit Specific Least Integers
        REQUIRE(cortex::ModuloWith<int64_t, int_least8_t>);
        REQUIRE(cortex::ModuloWith<int64_t, int_least16_t>);
        REQUIRE(cortex::ModuloWith<int64_t, int_least32_t>);
        REQUIRE(cortex::ModuloWith<int64_t, int_least64_t>);
}
}

TEST_CASE("Addable With : Bit Specific Unsigned Integers")
{
    SECTION("uint8_t with _")
    {
        // uint8_t with Signed Integers
        REQUIRE(cortex::ModuloWith<uint8_t, int>);
        REQUIRE(cortex::ModuloWith<uint8_t, short>);
        REQUIRE(cortex::ModuloWith<uint8_t, long>);
        REQUIRE(cortex::ModuloWith<uint8_t, long long>);

        // uint8_t with Unsigned Integers
        REQUIRE(cortex::ModuloWith<uint8_t, unsigned>);
        REQUIRE(cortex::ModuloWith<uint8_t, unsigned short>);
        REQUIRE(cortex::ModuloWith<uint8_t, u_short>);
        REQUIRE(cortex::ModuloWith<uint8_t, unsigned long>);
        REQUIRE(cortex::ModuloWith<uint8_t, unsigned long long>);
        
        // uint8_t with Bit Specific Integers
        REQUIRE(cortex::ModuloWith<uint8_t, int8_t>);
        REQUIRE(cortex::ModuloWith<uint8_t, int16_t>);
        REQUIRE(cortex::ModuloWith<uint8_t, int32_t>);
        REQUIRE(cortex::ModuloWith<uint8_t, int64_t>);

        // uint8_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::ModuloWith<uint8_t, uint8_t>);
        REQUIRE(cortex::ModuloWith<uint8_t, uint16_t>);
        REQUIRE(cortex::ModuloWith<uint8_t, uint32_t>);
        REQUIRE(cortex::ModuloWith<uint8_t, uint64_t>);

        // uint8_t with Bit Specific Least Integers
        REQUIRE(cortex::ModuloWith<uint8_t, int_least8_t>);
        REQUIRE(cortex::ModuloWith<uint8_t, int_least16_t>);
        REQUIRE(cortex::ModuloWith<uint8_t, int_least32_t>);
        REQUIRE(cortex::ModuloWith<uint8_t, int_least64_t>);
    }

    SECTION("uint16_t with _")
    {
        // uint16_t with Signed Integers
        REQUIRE(cortex::ModuloWith<uint16_t, int>);
        REQUIRE(cortex::ModuloWith<uint16_t, short>);
        REQUIRE(cortex::ModuloWith<uint16_t, long>);
        REQUIRE(cortex::ModuloWith<uint16_t, long long>);

        // uint16_t with Unsigned Integers
        REQUIRE(cortex::ModuloWith<uint16_t, unsigned>);
        REQUIRE(cortex::ModuloWith<uint16_t, unsigned short>);
        REQUIRE(cortex::ModuloWith<uint16_t, u_short>);
        REQUIRE(cortex::ModuloWith<uint16_t, unsigned long>);
        REQUIRE(cortex::ModuloWith<uint16_t, unsigned long long>);
        
        // uint16_t with Bit Specific Integers
        REQUIRE(cortex::ModuloWith<uint16_t, int8_t>);
        REQUIRE(cortex::ModuloWith<uint16_t, int16_t>);
        REQUIRE(cortex::ModuloWith<uint16_t, int32_t>);
        REQUIRE(cortex::ModuloWith<uint16_t, int64_t>);

        // uint16_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::ModuloWith<uint16_t, uint8_t>);
        REQUIRE(cortex::ModuloWith<uint16_t, uint16_t>);
        REQUIRE(cortex::ModuloWith<uint16_t, uint32_t>);
        REQUIRE(cortex::ModuloWith<uint16_t, uint64_t>);

        // uint16_t with Bit Specific Least Integers
        REQUIRE(cortex::ModuloWith<uint16_t, int_least8_t>);
        REQUIRE(cortex::ModuloWith<uint16_t, int_least16_t>);
        REQUIRE(cortex::ModuloWith<uint16_t, int_least32_t>);
        REQUIRE(cortex::ModuloWith<uint16_t, int_least64_t>);
    }

    SECTION("uint32_t with _")
    {
        // int32 with Signed Integers
        REQUIRE(cortex::ModuloWith<uint32_t, int>);
        REQUIRE(cortex::ModuloWith<uint32_t, short>);
        REQUIRE(cortex::ModuloWith<uint32_t, long>);
        REQUIRE(cortex::ModuloWith<uint32_t, long long>);

        // int32 with Unsigned Integers
        REQUIRE(cortex::ModuloWith<uint32_t, unsigned>);
        REQUIRE(cortex::ModuloWith<uint32_t, unsigned short>);
        REQUIRE(cortex::ModuloWith<uint32_t, u_short>);
        REQUIRE(cortex::ModuloWith<uint32_t, unsigned long>);
        REQUIRE(cortex::ModuloWith<uint32_t, unsigned long long>);
        
        // uint32_t with Bit Specific Integers
        REQUIRE(cortex::ModuloWith<uint32_t, int8_t>);
        REQUIRE(cortex::ModuloWith<uint32_t, int16_t>);
        REQUIRE(cortex::ModuloWith<uint32_t, int32_t>);
        REQUIRE(cortex::ModuloWith<uint32_t, int64_t>);

        // uint32_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::ModuloWith<uint32_t, uint8_t>);
        REQUIRE(cortex::ModuloWith<uint32_t, uint16_t>);
        REQUIRE(cortex::ModuloWith<uint32_t, uint32_t>);
        REQUIRE(cortex::ModuloWith<uint32_t, uint64_t>);

        // uint32_t with Bit Specific Least Integers
        REQUIRE(cortex::ModuloWith<uint32_t, int_least8_t>);
        REQUIRE(cortex::ModuloWith<uint32_t, int_least16_t>);
        REQUIRE(cortex::ModuloWith<uint32_t, int_least32_t>);
        REQUIRE(cortex::ModuloWith<uint32_t, int_least64_t>);
    }

    SECTION("uint64_t with _")
    {
        // int64 with Signed Integers
        REQUIRE(cortex::ModuloWith<uint64_t, int>);
        REQUIRE(cortex::ModuloWith<uint64_t, short>);
        REQUIRE(cortex::ModuloWith<uint64_t, long>);
        REQUIRE(cortex::ModuloWith<uint64_t, long long>);

        // int64 with Unsigned Integers
        REQUIRE(cortex::ModuloWith<uint64_t, unsigned>);
        REQUIRE(cortex::ModuloWith<uint64_t, unsigned short>);
        REQUIRE(cortex::ModuloWith<uint64_t, u_short>);
        REQUIRE(cortex::ModuloWith<uint64_t, unsigned long>);
        REQUIRE(cortex::ModuloWith<uint64_t, unsigned long long>);
        
        // uint64_t with Bit Specific Integers
        REQUIRE(cortex::ModuloWith<uint64_t, int8_t>);
        REQUIRE(cortex::ModuloWith<uint64_t, int16_t>);
        REQUIRE(cortex::ModuloWith<uint64_t, int32_t>);
        REQUIRE(cortex::ModuloWith<uint64_t, int64_t>);

        // uint64_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::ModuloWith<uint64_t, uint8_t>);
        REQUIRE(cortex::ModuloWith<uint64_t, uint16_t>);
        REQUIRE(cortex::ModuloWith<uint64_t, uint32_t>);
        REQUIRE(cortex::ModuloWith<uint64_t, uint64_t>);

        // uint64_t with Bit Specific Least Integers
        REQUIRE(cortex::ModuloWith<uint64_t, int_least8_t>);
        REQUIRE(cortex::ModuloWith<uint64_t, int_least16_t>);
        REQUIRE(cortex::ModuloWith<uint64_t, int_least32_t>);
        REQUIRE(cortex::ModuloWith<uint64_t, int_least64_t>);
    }
}

TEST_CASE("Addable With : std::size_t")
{
    SECTION("std::size_t with _")
    {
        // std::size_t with Signed Integers
        REQUIRE(cortex::ModuloWith<std::size_t, int>);
        REQUIRE(cortex::ModuloWith<std::size_t, short>);
        REQUIRE(cortex::ModuloWith<std::size_t, long>);
        REQUIRE(cortex::ModuloWith<std::size_t, long long>);

        // std::size_t with Unsigned Integers
        REQUIRE(cortex::ModuloWith<std::size_t, unsigned>);
        REQUIRE(cortex::ModuloWith<std::size_t, unsigned short>);
        REQUIRE(cortex::ModuloWith<std::size_t, u_short>);
        REQUIRE(cortex::ModuloWith<std::size_t, unsigned long>);
        REQUIRE(cortex::ModuloWith<std::size_t, unsigned long long>);
        
        // std::size_t with Bit Specific Integers
        REQUIRE(cortex::ModuloWith<std::size_t, int8_t>);
        REQUIRE(cortex::ModuloWith<std::size_t, int16_t>);
        REQUIRE(cortex::ModuloWith<std::size_t, int32_t>);
        REQUIRE(cortex::ModuloWith<std::size_t, int64_t>);

        // std::size_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::ModuloWith<std::size_t, uint8_t>);
        REQUIRE(cortex::ModuloWith<std::size_t, uint16_t>);
        REQUIRE(cortex::ModuloWith<std::size_t, uint32_t>);
        REQUIRE(cortex::ModuloWith<std::size_t, uint64_t>);

        // std::size_t with Bit Specific Least Integers
        REQUIRE(cortex::ModuloWith<std::size_t, int_least8_t>);
        REQUIRE(cortex::ModuloWith<std::size_t, int_least16_t>);
        REQUIRE(cortex::ModuloWith<std::size_t, int_least32_t>);
        REQUIRE(cortex::ModuloWith<std::size_t, int_least64_t>);
    }
}

TEST_CASE("ModuloWith : Fast Integers")
{
    SECTION("int_fast8_t with _")
    {
        // int_fast8_t with Signed Integers
        REQUIRE(cortex::ModuloWith<int_fast8_t, int>);
        REQUIRE(cortex::ModuloWith<int_fast8_t, short>);
        REQUIRE(cortex::ModuloWith<int_fast8_t, long>);
        REQUIRE(cortex::ModuloWith<int_fast8_t, long long>);

        // int_fast8_t with Unsigned Integers
        REQUIRE(cortex::ModuloWith<int_fast8_t, unsigned>);
        REQUIRE(cortex::ModuloWith<int_fast8_t, unsigned short>);
        REQUIRE(cortex::ModuloWith<int_fast8_t, u_short>);
        REQUIRE(cortex::ModuloWith<int_fast8_t, unsigned long>);
        REQUIRE(cortex::ModuloWith<int_fast8_t, unsigned long long>);
        
        // int_fast8_t with Bit Specific Integers
        REQUIRE(cortex::ModuloWith<int_fast8_t, int8_t>);
        REQUIRE(cortex::ModuloWith<int_fast8_t, int16_t>);
        REQUIRE(cortex::ModuloWith<int_fast8_t, int32_t>);
        REQUIRE(cortex::ModuloWith<int_fast8_t, int64_t>);

        // int_fast8_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::ModuloWith<int_fast8_t, uint8_t>);
        REQUIRE(cortex::ModuloWith<int_fast8_t, uint16_t>);
        REQUIRE(cortex::ModuloWith<int_fast8_t, uint32_t>);
        REQUIRE(cortex::ModuloWith<int_fast8_t, uint64_t>);

        // int_fast8_t with Bit Specific Least Integers
        REQUIRE(cortex::ModuloWith<int_fast8_t, int_least8_t>);
        REQUIRE(cortex::ModuloWith<int_fast8_t, int_least16_t>);
        REQUIRE(cortex::ModuloWith<int_fast8_t, int_least32_t>);
        REQUIRE(cortex::ModuloWith<int_fast8_t, int_least64_t>);
    }

    SECTION("int_fast16_t with _")
    {
        // int_fast16_t with Signed Integers
        REQUIRE(cortex::ModuloWith<int_fast16_t, int>);
        REQUIRE(cortex::ModuloWith<int_fast16_t, short>);
        REQUIRE(cortex::ModuloWith<int_fast16_t, long>);
        REQUIRE(cortex::ModuloWith<int_fast16_t, long long>);

        // int_fast16_t with Unsigned Integers
        REQUIRE(cortex::ModuloWith<int_fast16_t, unsigned>);
        REQUIRE(cortex::ModuloWith<int_fast16_t, unsigned short>);
        REQUIRE(cortex::ModuloWith<int_fast16_t, u_short>);
        REQUIRE(cortex::ModuloWith<int_fast16_t, unsigned long>);
        REQUIRE(cortex::ModuloWith<int_fast16_t, unsigned long long>);
        
        // int_fast16_t with Bit Specific Integers
        REQUIRE(cortex::ModuloWith<int_fast16_t, int8_t>);
        REQUIRE(cortex::ModuloWith<int_fast16_t, int16_t>);
        REQUIRE(cortex::ModuloWith<int_fast16_t, int32_t>);
        REQUIRE(cortex::ModuloWith<int_fast16_t, int64_t>);

        // int_fast16_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::ModuloWith<int_fast16_t, uint8_t>);
        REQUIRE(cortex::ModuloWith<int_fast16_t, uint16_t>);
        REQUIRE(cortex::ModuloWith<int_fast16_t, uint32_t>);
        REQUIRE(cortex::ModuloWith<int_fast16_t, uint64_t>);

        // int_fast16_t with Bit Specific Least Integers
        REQUIRE(cortex::ModuloWith<int_fast16_t, int_least8_t>);
        REQUIRE(cortex::ModuloWith<int_fast16_t, int_least16_t>);
        REQUIRE(cortex::ModuloWith<int_fast16_t, int_least32_t>);
        REQUIRE(cortex::ModuloWith<int_fast16_t, int_least64_t>);
    }

    SECTION("int_fast32_t with _")
    {
        // int32 with Signed Integers
        REQUIRE(cortex::ModuloWith<int_fast32_t, int>);
        REQUIRE(cortex::ModuloWith<int_fast32_t, short>);
        REQUIRE(cortex::ModuloWith<int_fast32_t, long>);
        REQUIRE(cortex::ModuloWith<int_fast32_t, long long>);

        // int32 with Unsigned Integers
        REQUIRE(cortex::ModuloWith<int_fast32_t, unsigned>);
        REQUIRE(cortex::ModuloWith<int_fast32_t, unsigned short>);
        REQUIRE(cortex::ModuloWith<int_fast32_t, u_short>);
        REQUIRE(cortex::ModuloWith<int_fast32_t, unsigned long>);
        REQUIRE(cortex::ModuloWith<int_fast32_t, unsigned long long>);
        
        // int32 with Floating Point and Doubles
       // int_fast32_t with Bit Specific Integers
        REQUIRE(cortex::ModuloWith<int_fast32_t, int8_t>);
        REQUIRE(cortex::ModuloWith<int_fast32_t, int16_t>);
        REQUIRE(cortex::ModuloWith<int_fast32_t, int32_t>);
        REQUIRE(cortex::ModuloWith<int_fast32_t, int64_t>);

        // int_fast32_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::ModuloWith<int_fast32_t, uint8_t>);
        REQUIRE(cortex::ModuloWith<int_fast32_t, uint16_t>);
        REQUIRE(cortex::ModuloWith<int_fast32_t, uint32_t>);
        REQUIRE(cortex::ModuloWith<int_fast32_t, uint64_t>);

        // int_fast32_t with Bit Specific Least Integers
        REQUIRE(cortex::ModuloWith<int_fast32_t, int_least8_t>);
        REQUIRE(cortex::ModuloWith<int_fast32_t, int_least16_t>);
        REQUIRE(cortex::ModuloWith<int_fast32_t, int_least32_t>);
        REQUIRE(cortex::ModuloWith<int_fast32_t, int_least64_t>);
    }

    SECTION("int_fast64_t with _")
    {
        // int64 with Signed Integers
        REQUIRE(cortex::ModuloWith<int_fast64_t, int>);
        REQUIRE(cortex::ModuloWith<int_fast64_t, short>);
        REQUIRE(cortex::ModuloWith<int_fast64_t, long>);
        REQUIRE(cortex::ModuloWith<int_fast64_t, long long>);

        // int64 with Unsigned Integers
        REQUIRE(cortex::ModuloWith<int_fast64_t, unsigned>);
        REQUIRE(cortex::ModuloWith<int_fast64_t, unsigned short>);
        REQUIRE(cortex::ModuloWith<int_fast64_t, u_short>);
        REQUIRE(cortex::ModuloWith<int_fast64_t, unsigned long>);
        REQUIRE(cortex::ModuloWith<int_fast64_t, unsigned long long>);
        
        // int_fast64_t with Bit Specific Integers
        REQUIRE(cortex::ModuloWith<int_fast64_t, int8_t>);
        REQUIRE(cortex::ModuloWith<int_fast64_t, int16_t>);
        REQUIRE(cortex::ModuloWith<int_fast64_t, int32_t>);
        REQUIRE(cortex::ModuloWith<int_fast64_t, int64_t>);

        // int_fast64_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::ModuloWith<int_fast64_t, uint8_t>);
        REQUIRE(cortex::ModuloWith<int_fast64_t, uint16_t>);
        REQUIRE(cortex::ModuloWith<int_fast64_t, uint32_t>);
        REQUIRE(cortex::ModuloWith<int_fast64_t, uint64_t>);

        // int_fast64_t with Bit Specific Least Integers
        REQUIRE(cortex::ModuloWith<int_fast64_t, int_least8_t>);
        REQUIRE(cortex::ModuloWith<int_fast64_t, int_least16_t>);
        REQUIRE(cortex::ModuloWith<int_fast64_t, int_least32_t>);
        REQUIRE(cortex::ModuloWith<int_fast64_t, int_least64_t>);
    }
}

TEST_CASE("ModuloWith : Least Integers")
{
    SECTION("int_least8_t with _")
    {
        // int_fast8_t with Signed Integers
        REQUIRE(cortex::ModuloWith<int_least8_t, int>);
        REQUIRE(cortex::ModuloWith<int_least8_t, short>);
        REQUIRE(cortex::ModuloWith<int_least8_t, long>);
        REQUIRE(cortex::ModuloWith<int_least8_t, long long>);

        // int_fast8_t with Unsigned Integers
        REQUIRE(cortex::ModuloWith<int_least8_t, unsigned>);
        REQUIRE(cortex::ModuloWith<int_least8_t, unsigned short>);
        REQUIRE(cortex::ModuloWith<int_least8_t, u_short>);
        REQUIRE(cortex::ModuloWith<int_least8_t, unsigned long>);
        REQUIRE(cortex::ModuloWith<int_least8_t, unsigned long long>);
        
        // int_fast8_t with Bit Specific Integers
        REQUIRE(cortex::ModuloWith<int_least8_t, int8_t>);
        REQUIRE(cortex::ModuloWith<int_least8_t, int16_t>);
        REQUIRE(cortex::ModuloWith<int_least8_t, int32_t>);
        REQUIRE(cortex::ModuloWith<int_least8_t, int64_t>);

        // int_fast8_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::ModuloWith<int_least8_t, uint8_t>);
        REQUIRE(cortex::ModuloWith<int_least8_t, uint16_t>);
        REQUIRE(cortex::ModuloWith<int_least8_t, uint32_t>);
        REQUIRE(cortex::ModuloWith<int_least8_t, uint64_t>);

        // int_fast8_t with Bit Specific Least Integers
        REQUIRE(cortex::ModuloWith<int_least8_t, int_least8_t>);
        REQUIRE(cortex::ModuloWith<int_least8_t, int_least16_t>);
        REQUIRE(cortex::ModuloWith<int_least8_t, int_least32_t>);
        REQUIRE(cortex::ModuloWith<int_least8_t, int_least64_t>);
    }

    SECTION("int_least16_t with _")
    {
        // int_fast16_t with Signed Integers
        REQUIRE(cortex::ModuloWith<int_least16_t, int>);
        REQUIRE(cortex::ModuloWith<int_least16_t, short>);
        REQUIRE(cortex::ModuloWith<int_least16_t, long>);
        REQUIRE(cortex::ModuloWith<int_least16_t, long long>);

        // int_fast16_t with Unsigned Integers
        REQUIRE(cortex::ModuloWith<int_least16_t, unsigned>);
        REQUIRE(cortex::ModuloWith<int_least16_t, unsigned short>);
        REQUIRE(cortex::ModuloWith<int_least16_t, u_short>);
        REQUIRE(cortex::ModuloWith<int_least16_t, unsigned long>);
        REQUIRE(cortex::ModuloWith<int_least16_t, unsigned long long>);
        
        // int_fast16_t with Bit Specific Integers
        REQUIRE(cortex::ModuloWith<int_least16_t, int8_t>);
        REQUIRE(cortex::ModuloWith<int_least16_t, int16_t>);
        REQUIRE(cortex::ModuloWith<int_least16_t, int32_t>);
        REQUIRE(cortex::ModuloWith<int_least16_t, int64_t>);

        // int_fast16_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::ModuloWith<int_least16_t, uint8_t>);
        REQUIRE(cortex::ModuloWith<int_least16_t, uint16_t>);
        REQUIRE(cortex::ModuloWith<int_least16_t, uint32_t>);
        REQUIRE(cortex::ModuloWith<int_least16_t, uint64_t>);

        // int_fast16_t with Bit Specific Least Integers
        REQUIRE(cortex::ModuloWith<int_least16_t, int_least8_t>);
        REQUIRE(cortex::ModuloWith<int_least16_t, int_least16_t>);
        REQUIRE(cortex::ModuloWith<int_least16_t, int_least32_t>);
        REQUIRE(cortex::ModuloWith<int_least16_t, int_least64_t>);
    }

    SECTION("int_least32_t with _")
    {
        // int32 with Signed Integers
        REQUIRE(cortex::ModuloWith<int_least32_t, int>);
        REQUIRE(cortex::ModuloWith<int_least32_t, short>);
        REQUIRE(cortex::ModuloWith<int_least32_t, long>);
        REQUIRE(cortex::ModuloWith<int_least32_t, long long>);

        // int32 with Unsigned Integers
        REQUIRE(cortex::ModuloWith<int_least32_t, unsigned>);
        REQUIRE(cortex::ModuloWith<int_least32_t, unsigned short>);
        REQUIRE(cortex::ModuloWith<int_least32_t, u_short>);
        REQUIRE(cortex::ModuloWith<int_least32_t, unsigned long>);
        REQUIRE(cortex::ModuloWith<int_least32_t, unsigned long long>);
        
        // int_fast32_t with Bit Specific Integers
        REQUIRE(cortex::ModuloWith<int_least32_t, int8_t>);
        REQUIRE(cortex::ModuloWith<int_least32_t, int16_t>);
        REQUIRE(cortex::ModuloWith<int_least32_t, int32_t>);
        REQUIRE(cortex::ModuloWith<int_least32_t, int64_t>);

        // int_fast32_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::ModuloWith<int_least32_t, uint8_t>);
        REQUIRE(cortex::ModuloWith<int_least32_t, uint16_t>);
        REQUIRE(cortex::ModuloWith<int_least32_t, uint32_t>);
        REQUIRE(cortex::ModuloWith<int_least32_t, uint64_t>);

        // int_fast32_t with Bit Specific Least Integers
        REQUIRE(cortex::ModuloWith<int_least32_t, int_least8_t>);
        REQUIRE(cortex::ModuloWith<int_least32_t, int_least16_t>);
        REQUIRE(cortex::ModuloWith<int_least32_t, int_least32_t>);
        REQUIRE(cortex::ModuloWith<int_least32_t, int_least64_t>);
    }

    SECTION("int_least64_t with _")
    {
        // int64 with Signed Integers
        REQUIRE(cortex::ModuloWith<int_least64_t, int>);
        REQUIRE(cortex::ModuloWith<int_least64_t, short>);
        REQUIRE(cortex::ModuloWith<int_least64_t, long>);
        REQUIRE(cortex::ModuloWith<int_least64_t, long long>);

        // int64 with Unsigned Integers
        REQUIRE(cortex::ModuloWith<int_least64_t, unsigned>);
        REQUIRE(cortex::ModuloWith<int_least64_t, unsigned short>);
        REQUIRE(cortex::ModuloWith<int_least64_t, u_short>);
        REQUIRE(cortex::ModuloWith<int_least64_t, unsigned long>);
        REQUIRE(cortex::ModuloWith<int_least64_t, unsigned long long>);
        
        // int_fast64_t with Bit Specific Integers
        REQUIRE(cortex::ModuloWith<int_least64_t, int8_t>);
        REQUIRE(cortex::ModuloWith<int_least64_t, int16_t>);
        REQUIRE(cortex::ModuloWith<int_least64_t, int32_t>);
        REQUIRE(cortex::ModuloWith<int_least64_t, int64_t>);

        // int_fast64_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::ModuloWith<int_least64_t, uint8_t>);
        REQUIRE(cortex::ModuloWith<int_least64_t, uint16_t>);
        REQUIRE(cortex::ModuloWith<int_least64_t, uint32_t>);
        REQUIRE(cortex::ModuloWith<int_least64_t, uint64_t>);

        // int_fast64_t with Bit Specific Least Integers
        REQUIRE(cortex::ModuloWith<int_least64_t, int_least8_t>);
        REQUIRE(cortex::ModuloWith<int_least64_t, int_least16_t>);
        REQUIRE(cortex::ModuloWith<int_least64_t, int_least32_t>);
        REQUIRE(cortex::ModuloWith<int_least64_t, int_least64_t>);
    }
}