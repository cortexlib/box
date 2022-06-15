#include <catch2/catch.hpp>
#include <concepts.hpp>

TEST_CASE("RightBitShiftWith : Signed Integers")
{
    SECTION("Int with _")
    {
        // Int with Signed Integers
        REQUIRE(cortex::RightBitShiftWith<int, int>);
        REQUIRE(cortex::RightBitShiftWith<int, short>);
        REQUIRE(cortex::RightBitShiftWith<int, long>);
        REQUIRE(cortex::RightBitShiftWith<int, long long>);

        // Int with Unsigned Integers
        REQUIRE(cortex::RightBitShiftWith<int, unsigned>);
        REQUIRE(cortex::RightBitShiftWith<int, unsigned short>);
        REQUIRE(cortex::RightBitShiftWith<int, u_short>);
        REQUIRE(cortex::RightBitShiftWith<int, unsigned long>);
        REQUIRE(cortex::RightBitShiftWith<int, unsigned long long>);
        
        // Integers with Floating Point and Doubles
        REQUIRE(!cortex::RightBitShiftWith<int, float>);
        REQUIRE(!cortex::RightBitShiftWith<int, double>);
        REQUIRE(!cortex::RightBitShiftWith<int, long double>);

        // Integers with std::strings and std::string_view
        REQUIRE(!cortex::RightBitShiftWith<int, std::string>);
        REQUIRE(!cortex::RightBitShiftWith<int, std::string_view>);
        REQUIRE(!cortex::RightBitShiftWith<int, std::u8string>);
        REQUIRE(!cortex::RightBitShiftWith<int, std::u16string>);
        REQUIRE(!cortex::RightBitShiftWith<int, std::u32string>);

        // Integers with std::wstrings and std::wstring_view
        REQUIRE(!cortex::RightBitShiftWith<int, std::wstring>);
        REQUIRE(!cortex::RightBitShiftWith<int, std::wstring_view>);

        // Integers with Charaters
        REQUIRE(cortex::RightBitShiftWith<int, char>);
        REQUIRE(cortex::RightBitShiftWith<int, u_char>);
        REQUIRE(cortex::RightBitShiftWith<int, wchar_t>);

        // Integers with Bit Specific Characters
        REQUIRE(cortex::RightBitShiftWith<int, char8_t>);
        REQUIRE(cortex::RightBitShiftWith<int, char16_t>);
        REQUIRE(cortex::RightBitShiftWith<int, char32_t>);

        // Integers with Bit Specific Integers
        REQUIRE(cortex::RightBitShiftWith<int, int8_t>);
        REQUIRE(cortex::RightBitShiftWith<int, int16_t>);
        REQUIRE(cortex::RightBitShiftWith<int, int32_t>);
        REQUIRE(cortex::RightBitShiftWith<int, int64_t>);

        // Integers with Bit Specific Unsigned Integers
        REQUIRE(cortex::RightBitShiftWith<int, uint8_t>);
        REQUIRE(cortex::RightBitShiftWith<int, uint16_t>);
        REQUIRE(cortex::RightBitShiftWith<int, uint32_t>);
        REQUIRE(cortex::RightBitShiftWith<int, uint64_t>);

        // Integers with Bit Specific Least Integers
        REQUIRE(cortex::RightBitShiftWith<int, int_least8_t>);
        REQUIRE(cortex::RightBitShiftWith<int, int_least16_t>);
        REQUIRE(cortex::RightBitShiftWith<int, int_least32_t>);
        REQUIRE(cortex::RightBitShiftWith<int, int_least64_t>);
    }

    SECTION("Short with _")
    {
        // Short with Signed Integers
        REQUIRE(cortex::RightBitShiftWith<short, int>);
        REQUIRE(cortex::RightBitShiftWith<short, short>);
        REQUIRE(cortex::RightBitShiftWith<short, long>);
        REQUIRE(cortex::RightBitShiftWith<short, long long>);

        // Short with Unsigned Integers
        REQUIRE(cortex::RightBitShiftWith<short, unsigned>);
        REQUIRE(cortex::RightBitShiftWith<short, unsigned short>);
        REQUIRE(cortex::RightBitShiftWith<short, u_short>);
        REQUIRE(cortex::RightBitShiftWith<short, unsigned long>);
        REQUIRE(cortex::RightBitShiftWith<short, unsigned long long>);
        
        // Short with Floating Point and Doubles
        REQUIRE(!cortex::RightBitShiftWith<short, float>);
        REQUIRE(!cortex::RightBitShiftWith<short, double>);
        REQUIRE(!cortex::RightBitShiftWith<short, long double>);

        // Short with std::strings and std::string_view
        REQUIRE(!cortex::RightBitShiftWith<short, std::string>);
        REQUIRE(!cortex::RightBitShiftWith<short, std::string_view>);
        REQUIRE(!cortex::RightBitShiftWith<short, std::u8string>);
        REQUIRE(!cortex::RightBitShiftWith<short, std::u16string>);
        REQUIRE(!cortex::RightBitShiftWith<short, std::u32string>);

        // Short with std::wstrings and std::wstring_view
        REQUIRE(!cortex::RightBitShiftWith<short, std::wstring>);
        REQUIRE(!cortex::RightBitShiftWith<short, std::wstring_view>);

        // Short with Charaters
        REQUIRE(cortex::RightBitShiftWith<short, char>);
        REQUIRE(cortex::RightBitShiftWith<short, u_char>);
        REQUIRE(cortex::RightBitShiftWith<short, wchar_t>);

        // Short with Bit Specific Characters
        REQUIRE(cortex::RightBitShiftWith<short, char8_t>);
        REQUIRE(cortex::RightBitShiftWith<short, char16_t>);
        REQUIRE(cortex::RightBitShiftWith<short, char32_t>);

        // Short with Bit Specific Short
        REQUIRE(cortex::RightBitShiftWith<short, int8_t>);
        REQUIRE(cortex::RightBitShiftWith<short, int16_t>);
        REQUIRE(cortex::RightBitShiftWith<short, int32_t>);
        REQUIRE(cortex::RightBitShiftWith<short, int64_t>);

        // Short with Bit Specific Unsigned Short
        REQUIRE(cortex::RightBitShiftWith<short, uint8_t>);
        REQUIRE(cortex::RightBitShiftWith<short, uint16_t>);
        REQUIRE(cortex::RightBitShiftWith<short, uint32_t>);
        REQUIRE(cortex::RightBitShiftWith<short, uint64_t>);

        // Short with Bit Specific Least Integers
        REQUIRE(cortex::RightBitShiftWith<short, int_least8_t>);
        REQUIRE(cortex::RightBitShiftWith<short, int_least16_t>);
        REQUIRE(cortex::RightBitShiftWith<short, int_least32_t>);
        REQUIRE(cortex::RightBitShiftWith<short, int_least64_t>);
    }

    SECTION("Long with _")
    {
        // Long with Signed Integers
        REQUIRE(cortex::RightBitShiftWith<long, int>);
        REQUIRE(cortex::RightBitShiftWith<long, short>);
        REQUIRE(cortex::RightBitShiftWith<long, long>);
        REQUIRE(cortex::RightBitShiftWith<long, long long>);

        // Long with Unsigned Integers
        REQUIRE(cortex::RightBitShiftWith<long, unsigned>);
        REQUIRE(cortex::RightBitShiftWith<long, unsigned short>);
        REQUIRE(cortex::RightBitShiftWith<long, u_short>);
        REQUIRE(cortex::RightBitShiftWith<long, unsigned long>);
        REQUIRE(cortex::RightBitShiftWith<long, unsigned long long>);
        
        // Long with Floating Point and Doubles
        REQUIRE(!cortex::RightBitShiftWith<long, float>);
        REQUIRE(!cortex::RightBitShiftWith<long, double>);
        REQUIRE(!cortex::RightBitShiftWith<long, long double>);

        // Long with std::strings and std::string_view
        REQUIRE(!cortex::RightBitShiftWith<long, std::string>);
        REQUIRE(!cortex::RightBitShiftWith<long, std::string_view>);
        REQUIRE(!cortex::RightBitShiftWith<long, std::u8string>);
        REQUIRE(!cortex::RightBitShiftWith<long, std::u16string>);
        REQUIRE(!cortex::RightBitShiftWith<long, std::u32string>);

        // Long with std::wstrings and std::wstring_view
        REQUIRE(!cortex::RightBitShiftWith<long, std::wstring>);
        REQUIRE(!cortex::RightBitShiftWith<long, std::wstring_view>);

        // Long with Charaters
        REQUIRE(cortex::RightBitShiftWith<long, char>);
        REQUIRE(cortex::RightBitShiftWith<long, u_char>);
        REQUIRE(cortex::RightBitShiftWith<long, wchar_t>);

        // Long with Bit Specific Characters
        REQUIRE(cortex::RightBitShiftWith<long, char8_t>);
        REQUIRE(cortex::RightBitShiftWith<long, char16_t>);
        REQUIRE(cortex::RightBitShiftWith<long, char32_t>);

        // Long with Bit Specific Long
        REQUIRE(cortex::RightBitShiftWith<long, int8_t>);
        REQUIRE(cortex::RightBitShiftWith<long, int16_t>);
        REQUIRE(cortex::RightBitShiftWith<long, int32_t>);
        REQUIRE(cortex::RightBitShiftWith<long, int64_t>);

        // Long with Bit Specific Unsigned Long
        REQUIRE(cortex::RightBitShiftWith<long, uint8_t>);
        REQUIRE(cortex::RightBitShiftWith<long, uint16_t>);
        REQUIRE(cortex::RightBitShiftWith<long, uint32_t>);
        REQUIRE(cortex::RightBitShiftWith<long, uint64_t>);

        // Long with Bit Specific Least Integers
        REQUIRE(cortex::RightBitShiftWith<long, int_least8_t>);
        REQUIRE(cortex::RightBitShiftWith<long, int_least16_t>);
        REQUIRE(cortex::RightBitShiftWith<long, int_least32_t>);
        REQUIRE(cortex::RightBitShiftWith<long, int_least64_t>);
    }

    SECTION("Long Long with _")
    {
        // Signed Integers
        REQUIRE(cortex::RightBitShiftWith<long long, int>);
        REQUIRE(cortex::RightBitShiftWith<long long, short>);
        REQUIRE(cortex::RightBitShiftWith<long long, long>);
        REQUIRE(cortex::RightBitShiftWith<long long, long long>);

        // Unsigned Integers
        REQUIRE(cortex::RightBitShiftWith<long long, unsigned>);
        REQUIRE(cortex::RightBitShiftWith<long long, unsigned short>);
        REQUIRE(cortex::RightBitShiftWith<long long, u_short>);
        REQUIRE(cortex::RightBitShiftWith<long long, unsigned long>);
        REQUIRE(cortex::RightBitShiftWith<long long, unsigned long long>);
        
        // Integers with Floating Point and Doubles
        REQUIRE(!cortex::RightBitShiftWith<long long, float>);
        REQUIRE(!cortex::RightBitShiftWith<long long, double>);
        REQUIRE(!cortex::RightBitShiftWith<long long, long double>);

        // Integers with std::strings and std::string_view
        REQUIRE(!cortex::RightBitShiftWith<long long, std::string>);
        REQUIRE(!cortex::RightBitShiftWith<long long, std::string_view>);
        REQUIRE(!cortex::RightBitShiftWith<long long, std::u8string>);
        REQUIRE(!cortex::RightBitShiftWith<long long, std::u16string>);
        REQUIRE(!cortex::RightBitShiftWith<long long, std::u32string>);

        // Integers with std::wstrings and std::wstring_view
        REQUIRE(!cortex::RightBitShiftWith<long long, std::wstring>);
        REQUIRE(!cortex::RightBitShiftWith<long long, std::wstring_view>);

        // Integers with Charaters
        REQUIRE(cortex::RightBitShiftWith<long long, char>);
        REQUIRE(cortex::RightBitShiftWith<long long, u_char>);
        REQUIRE(cortex::RightBitShiftWith<long long, wchar_t>);

        // Integers with Bit Specific Characters
        REQUIRE(cortex::RightBitShiftWith<long long, char8_t>);
        REQUIRE(cortex::RightBitShiftWith<long long, char16_t>);
        REQUIRE(cortex::RightBitShiftWith<long long, char32_t>);

        // Integers with Bit Specific Integers
        REQUIRE(cortex::RightBitShiftWith<long long, int8_t>);
        REQUIRE(cortex::RightBitShiftWith<long long, int16_t>);
        REQUIRE(cortex::RightBitShiftWith<long long, int32_t>);
        REQUIRE(cortex::RightBitShiftWith<long long, int64_t>);

        // Integers with Bit Specific Unsigned Integers
        REQUIRE(cortex::RightBitShiftWith<long long, uint8_t>);
        REQUIRE(cortex::RightBitShiftWith<long long, uint16_t>);
        REQUIRE(cortex::RightBitShiftWith<long long, uint32_t>);
        REQUIRE(cortex::RightBitShiftWith<long long, uint64_t>);

        // Long Long with Bit Specific Least Integers
        REQUIRE(cortex::RightBitShiftWith<long long, int_least8_t>);
        REQUIRE(cortex::RightBitShiftWith<long long, int_least16_t>);
        REQUIRE(cortex::RightBitShiftWith<long long, int_least32_t>);
        REQUIRE(cortex::RightBitShiftWith<long long, int_least64_t>);
    }
}

TEST_CASE("RightBitShiftWith: Unsigned Integers")
{
    SECTION("Unsigned Int with _")
    {
        // Unsigned Integers with Signed Integers
        REQUIRE(cortex::RightBitShiftWith<unsigned int, int>);
        REQUIRE(cortex::RightBitShiftWith<unsigned int, short>);
        REQUIRE(cortex::RightBitShiftWith<unsigned int, long>);
        REQUIRE(cortex::RightBitShiftWith<unsigned int, long long>);

        // Unsigned Integers with Unsigned Integers
        REQUIRE(cortex::RightBitShiftWith<unsigned int, unsigned>);
        REQUIRE(cortex::RightBitShiftWith<unsigned int, unsigned short>);
        REQUIRE(cortex::RightBitShiftWith<unsigned int, u_short>);
        REQUIRE(cortex::RightBitShiftWith<unsigned int, unsigned long>);
        REQUIRE(cortex::RightBitShiftWith<unsigned int, unsigned long long>);
        
        // Unsigned Integers with Floating Point and Doubles
        REQUIRE(!cortex::RightBitShiftWith<unsigned int, float>);
        REQUIRE(!cortex::RightBitShiftWith<unsigned int, double>);
        REQUIRE(!cortex::RightBitShiftWith<unsigned int, long double>);

        // Unsigned Integers with std::strings and std::string_view
        REQUIRE(!cortex::RightBitShiftWith<unsigned int, std::string>);
        REQUIRE(!cortex::RightBitShiftWith<unsigned int, std::string_view>);
        REQUIRE(!cortex::RightBitShiftWith<unsigned int, std::u8string>);
        REQUIRE(!cortex::RightBitShiftWith<unsigned int, std::u16string>);
        REQUIRE(!cortex::RightBitShiftWith<unsigned int, std::u32string>);

        // Unsigned Integers with std::wstrings and std::wstring_view
        REQUIRE(!cortex::RightBitShiftWith<unsigned long long, std::wstring>);
        REQUIRE(!cortex::RightBitShiftWith<unsigned long long, std::wstring_view>);

        // Unsigned Integers with Charaters
        REQUIRE(cortex::RightBitShiftWith<unsigned int, char>);
        REQUIRE(cortex::RightBitShiftWith<unsigned int, u_char>);
        REQUIRE(cortex::RightBitShiftWith<unsigned int, wchar_t>);

        // Unsigned Integers with Bit Specific Characters
        REQUIRE(cortex::RightBitShiftWith<unsigned int, char8_t>);
        REQUIRE(cortex::RightBitShiftWith<unsigned int, char16_t>);
        REQUIRE(cortex::RightBitShiftWith<unsigned int, char32_t>);

        // Unsigned Integers with Bit Specific Integers
        REQUIRE(cortex::RightBitShiftWith<unsigned int, int8_t>);
        REQUIRE(cortex::RightBitShiftWith<unsigned int, int16_t>);
        REQUIRE(cortex::RightBitShiftWith<unsigned int, int32_t>);
        REQUIRE(cortex::RightBitShiftWith<unsigned int, int64_t>);

        // Unsigned Integers with Bit Specific Unsigned Integers
        REQUIRE(cortex::RightBitShiftWith<unsigned int, uint8_t>);
        REQUIRE(cortex::RightBitShiftWith<unsigned int, uint16_t>);
        REQUIRE(cortex::RightBitShiftWith<unsigned int, uint32_t>);
        REQUIRE(cortex::RightBitShiftWith<unsigned int, uint64_t>);

        // Unsigned Integers with Bit Specific Least Integers
        REQUIRE(cortex::RightBitShiftWith<unsigned int, int_least8_t>);
        REQUIRE(cortex::RightBitShiftWith<unsigned int, int_least16_t>);
        REQUIRE(cortex::RightBitShiftWith<unsigned int, int_least32_t>);
        REQUIRE(cortex::RightBitShiftWith<unsigned int, int_least64_t>);
    }

    SECTION("Unsigned Short with _")
    {
        // Unsigned Short with Signed Integers
        REQUIRE(cortex::RightBitShiftWith<unsigned short, int>);
        REQUIRE(cortex::RightBitShiftWith<unsigned short, short>);
        REQUIRE(cortex::RightBitShiftWith<unsigned short, long>);
        REQUIRE(cortex::RightBitShiftWith<unsigned short, long long>);

        // Unsigned Short with Unsigned Integers
        REQUIRE(cortex::RightBitShiftWith<unsigned short, unsigned>);
        REQUIRE(cortex::RightBitShiftWith<unsigned short, unsigned short>);
        REQUIRE(cortex::RightBitShiftWith<unsigned short, u_short>);
        REQUIRE(cortex::RightBitShiftWith<unsigned short, unsigned long>);
        REQUIRE(cortex::RightBitShiftWith<unsigned short, unsigned long long>);
        
        // Unsigned Short with Floating Point and Doubles
        REQUIRE(!cortex::RightBitShiftWith<unsigned short, float>);
        REQUIRE(!cortex::RightBitShiftWith<unsigned short, double>);
        REQUIRE(!cortex::RightBitShiftWith<unsigned short, long double>);

        // Unsigned Short with std::strings and std::string_view
        REQUIRE(!cortex::RightBitShiftWith<unsigned short, std::string>);
        REQUIRE(!cortex::RightBitShiftWith<unsigned short, std::string_view>);
        REQUIRE(!cortex::RightBitShiftWith<unsigned short, std::u8string>);
        REQUIRE(!cortex::RightBitShiftWith<unsigned short, std::u16string>);
        REQUIRE(!cortex::RightBitShiftWith<unsigned short, std::u32string>);

        // Unsigned Short with std::wstrings and std::wstring_view
        REQUIRE(!cortex::RightBitShiftWith<unsigned short, std::wstring>);
        REQUIRE(!cortex::RightBitShiftWith<unsigned short, std::wstring_view>);

        // Unsigned Short with Charaters
        REQUIRE(cortex::RightBitShiftWith<unsigned short, char>);
        REQUIRE(cortex::RightBitShiftWith<unsigned short, u_char>);
        REQUIRE(cortex::RightBitShiftWith<unsigned short, wchar_t>);

        // Unsigned Short with Bit Specific Characters
        REQUIRE(cortex::RightBitShiftWith<unsigned short, char8_t>);
        REQUIRE(cortex::RightBitShiftWith<unsigned short, char16_t>);
        REQUIRE(cortex::RightBitShiftWith<unsigned short, char32_t>);

        // Unsigned Short with Bit Specific Short
        REQUIRE(cortex::RightBitShiftWith<unsigned short, int8_t>);
        REQUIRE(cortex::RightBitShiftWith<unsigned short, int16_t>);
        REQUIRE(cortex::RightBitShiftWith<unsigned short, int32_t>);
        REQUIRE(cortex::RightBitShiftWith<unsigned short, int64_t>);

        // Unsigned Short with Bit Specific Unsigned Short
        REQUIRE(cortex::RightBitShiftWith<unsigned short, uint8_t>);
        REQUIRE(cortex::RightBitShiftWith<unsigned short, uint16_t>);
        REQUIRE(cortex::RightBitShiftWith<unsigned short, uint32_t>);
        REQUIRE(cortex::RightBitShiftWith<unsigned short, uint64_t>);

        // Unsigned Short with Bit Specific Least Integers
        REQUIRE(cortex::RightBitShiftWith<unsigned short, int_least8_t>);
        REQUIRE(cortex::RightBitShiftWith<unsigned short, int_least16_t>);
        REQUIRE(cortex::RightBitShiftWith<unsigned short, int_least32_t>);
        REQUIRE(cortex::RightBitShiftWith<unsigned short, int_least64_t>);
    }

    SECTION("u_short with _")
    {
        // u_short with Signed Integers
        REQUIRE(cortex::RightBitShiftWith<u_short, int>);
        REQUIRE(cortex::RightBitShiftWith<u_short, short>);
        REQUIRE(cortex::RightBitShiftWith<u_short, long>);
        REQUIRE(cortex::RightBitShiftWith<u_short, long long>);

        // u_short with Unsigned Integers
        REQUIRE(cortex::RightBitShiftWith<u_short, unsigned>);
        REQUIRE(cortex::RightBitShiftWith<u_short, unsigned short>);
        REQUIRE(cortex::RightBitShiftWith<u_short, u_short>);
        REQUIRE(cortex::RightBitShiftWith<u_short, unsigned long>);
        REQUIRE(cortex::RightBitShiftWith<u_short, unsigned long long>);
        
        // u_short with Floating Point and Doubles
        REQUIRE(!cortex::RightBitShiftWith<u_short, float>);
        REQUIRE(!cortex::RightBitShiftWith<u_short, double>);
        REQUIRE(!cortex::RightBitShiftWith<u_short, long double>);

        // u_short with std::strings and std::string_view
        REQUIRE(!cortex::RightBitShiftWith<u_short, std::string>);
        REQUIRE(!cortex::RightBitShiftWith<u_short, std::string_view>);
        REQUIRE(!cortex::RightBitShiftWith<u_short, std::u8string>);
        REQUIRE(!cortex::RightBitShiftWith<u_short, std::u16string>);
        REQUIRE(!cortex::RightBitShiftWith<u_short, std::u32string>);

        // u_short with std::wstrings and std::wstring_view
        REQUIRE(!cortex::RightBitShiftWith<u_short, std::wstring>);
        REQUIRE(!cortex::RightBitShiftWith<u_short, std::wstring_view>);

        // u_short with Charaters
        REQUIRE(cortex::RightBitShiftWith<u_short, char>);
        REQUIRE(cortex::RightBitShiftWith<u_short, u_char>);
        REQUIRE(cortex::RightBitShiftWith<u_short, wchar_t>);

        // u_short with Bit Specific Characters
        REQUIRE(cortex::RightBitShiftWith<u_short, char8_t>);
        REQUIRE(cortex::RightBitShiftWith<u_short, char16_t>);
        REQUIRE(cortex::RightBitShiftWith<u_short, char32_t>);

        // u_short with Bit Specific Short
        REQUIRE(cortex::RightBitShiftWith<u_short, int8_t>);
        REQUIRE(cortex::RightBitShiftWith<u_short, int16_t>);
        REQUIRE(cortex::RightBitShiftWith<u_short, int32_t>);
        REQUIRE(cortex::RightBitShiftWith<u_short, int64_t>);

        // u_short with Bit Specific Unsigned Short
        REQUIRE(cortex::RightBitShiftWith<u_short, uint8_t>);
        REQUIRE(cortex::RightBitShiftWith<u_short, uint16_t>);
        REQUIRE(cortex::RightBitShiftWith<u_short, uint32_t>);
        REQUIRE(cortex::RightBitShiftWith<u_short, uint64_t>);

        // u_short with Bit Specific Least Integers
        REQUIRE(cortex::RightBitShiftWith<u_short, int_least8_t>);
        REQUIRE(cortex::RightBitShiftWith<u_short, int_least16_t>);
        REQUIRE(cortex::RightBitShiftWith<u_short, int_least32_t>);
        REQUIRE(cortex::RightBitShiftWith<u_short, int_least64_t>);
    }

    SECTION("Unsigned Long with _")
    {
        // Unsigned Long with Signed Integers
        REQUIRE(cortex::RightBitShiftWith<unsigned long, int>);
        REQUIRE(cortex::RightBitShiftWith<unsigned long, short>);
        REQUIRE(cortex::RightBitShiftWith<unsigned long, long>);
        REQUIRE(cortex::RightBitShiftWith<unsigned long, long long>);

        // Unsigned Long with Unsigned Integers
        REQUIRE(cortex::RightBitShiftWith<unsigned long, unsigned>);
        REQUIRE(cortex::RightBitShiftWith<unsigned long, unsigned short>);
        REQUIRE(cortex::RightBitShiftWith<unsigned long, u_short>);
        REQUIRE(cortex::RightBitShiftWith<unsigned long, unsigned long>);
        REQUIRE(cortex::RightBitShiftWith<unsigned long, unsigned long long>);
        
        // Unsigned Long with Floating Point and Doubles
        REQUIRE(!cortex::RightBitShiftWith<unsigned long, float>);
        REQUIRE(!cortex::RightBitShiftWith<unsigned long, double>);
        REQUIRE(!cortex::RightBitShiftWith<unsigned long, long double>);

        // Unsigned Long with std::strings and std::string_view
        REQUIRE(!cortex::RightBitShiftWith<unsigned long, std::string>);
        REQUIRE(!cortex::RightBitShiftWith<unsigned long, std::string_view>);
        REQUIRE(!cortex::RightBitShiftWith<unsigned long, std::u8string>);
        REQUIRE(!cortex::RightBitShiftWith<unsigned long, std::u16string>);
        REQUIRE(!cortex::RightBitShiftWith<unsigned long, std::u32string>);

        // Unsigned Long with std::wstrings and std::wstring_view
        REQUIRE(!cortex::RightBitShiftWith<unsigned long, std::wstring>);
        REQUIRE(!cortex::RightBitShiftWith<unsigned long, std::wstring_view>);

        // Unsigned Long with Charaters
        REQUIRE(cortex::RightBitShiftWith<unsigned long, char>);
        REQUIRE(cortex::RightBitShiftWith<unsigned long, u_char>);
        REQUIRE(cortex::RightBitShiftWith<unsigned long, wchar_t>);

        // Unsigned Long with Bit Specific Characters
        REQUIRE(cortex::RightBitShiftWith<unsigned long, char8_t>);
        REQUIRE(cortex::RightBitShiftWith<unsigned long, char16_t>);
        REQUIRE(cortex::RightBitShiftWith<unsigned long, char32_t>);

        // Unsigned Long with Bit Specific Long
        REQUIRE(cortex::RightBitShiftWith<unsigned long, int8_t>);
        REQUIRE(cortex::RightBitShiftWith<unsigned long, int16_t>);
        REQUIRE(cortex::RightBitShiftWith<unsigned long, int32_t>);
        REQUIRE(cortex::RightBitShiftWith<unsigned long, int64_t>);

        // Unsigned Long with Bit Specific Unsigned Long
        REQUIRE(cortex::RightBitShiftWith<unsigned long, uint8_t>);
        REQUIRE(cortex::RightBitShiftWith<unsigned long, uint16_t>);
        REQUIRE(cortex::RightBitShiftWith<unsigned long, uint32_t>);
        REQUIRE(cortex::RightBitShiftWith<unsigned long, uint64_t>);

        // Unsigned Long with Bit Specific Least Integers
        REQUIRE(cortex::RightBitShiftWith<unsigned long, int_least8_t>);
        REQUIRE(cortex::RightBitShiftWith<unsigned long, int_least16_t>);
        REQUIRE(cortex::RightBitShiftWith<unsigned long, int_least32_t>);
        REQUIRE(cortex::RightBitShiftWith<unsigned long, int_least64_t>);
    }

    SECTION("Unsigned Long Long with _")
    {
        // Unsigned Long Long with Signed Integers
        REQUIRE(cortex::RightBitShiftWith<unsigned long long, int>);
        REQUIRE(cortex::RightBitShiftWith<unsigned long long, short>);
        REQUIRE(cortex::RightBitShiftWith<unsigned long long, long>);
        REQUIRE(cortex::RightBitShiftWith<unsigned long long, long long>);

        // Unsigned Long Long with Unsigned Integers
        REQUIRE(cortex::RightBitShiftWith<unsigned long long, unsigned>);
        REQUIRE(cortex::RightBitShiftWith<unsigned long long, unsigned short>);
        REQUIRE(cortex::RightBitShiftWith<unsigned long long, u_short>);
        REQUIRE(cortex::RightBitShiftWith<unsigned long long, unsigned long>);
        REQUIRE(cortex::RightBitShiftWith<unsigned long long, unsigned long long>);
        
        // Unsigned Long Long with Floating Point and Doubles
        REQUIRE(!cortex::RightBitShiftWith<unsigned long long, float>);
        REQUIRE(!cortex::RightBitShiftWith<unsigned long long, double>);
        REQUIRE(!cortex::RightBitShiftWith<unsigned long long, long double>);

        // Unsigned Long Long with std::strings and std::string_view
        REQUIRE(!cortex::RightBitShiftWith<unsigned long long, std::string>);
        REQUIRE(!cortex::RightBitShiftWith<unsigned long long, std::string_view>);
        REQUIRE(!cortex::RightBitShiftWith<unsigned long long, std::u8string>);
        REQUIRE(!cortex::RightBitShiftWith<unsigned long long, std::u16string>);
        REQUIRE(!cortex::RightBitShiftWith<unsigned long long, std::u32string>);

        // Unsigned Long Long with std::wstrings and std::wstring_view
        REQUIRE(!cortex::RightBitShiftWith<unsigned long long, std::wstring>);
        REQUIRE(!cortex::RightBitShiftWith<unsigned long long, std::wstring_view>);

        // Unsigned Long Long with Charaters
        REQUIRE(cortex::RightBitShiftWith<unsigned long long, char>);
        REQUIRE(cortex::RightBitShiftWith<unsigned long long, u_char>);
        REQUIRE(cortex::RightBitShiftWith<unsigned long long, wchar_t>);

        // Unsigned Long Long with Bit Specific Characters
        REQUIRE(cortex::RightBitShiftWith<unsigned long long, char8_t>);
        REQUIRE(cortex::RightBitShiftWith<unsigned long long, char16_t>);
        REQUIRE(cortex::RightBitShiftWith<unsigned long long, char32_t>);

        // Unsigned Long Long with Bit Specific Long Long
        REQUIRE(cortex::RightBitShiftWith<unsigned long long, int8_t>);
        REQUIRE(cortex::RightBitShiftWith<unsigned long long, int16_t>);
        REQUIRE(cortex::RightBitShiftWith<unsigned long long, int32_t>);
        REQUIRE(cortex::RightBitShiftWith<unsigned long long, int64_t>);

        // Unsigned Long Long with Bit Specific Unsigned Long Long
        REQUIRE(cortex::RightBitShiftWith<unsigned long long, uint8_t>);
        REQUIRE(cortex::RightBitShiftWith<unsigned long long, uint16_t>);
        REQUIRE(cortex::RightBitShiftWith<unsigned long long, uint32_t>);
        REQUIRE(cortex::RightBitShiftWith<unsigned long long, uint64_t>);

        // Long Long with Bit Specific Least Long Long
        REQUIRE(cortex::RightBitShiftWith<unsigned long long, int_least8_t>);
        REQUIRE(cortex::RightBitShiftWith<unsigned long long, int_least16_t>);
        REQUIRE(cortex::RightBitShiftWith<unsigned long long, int_least32_t>);
        REQUIRE(cortex::RightBitShiftWith<unsigned long long, int_least64_t>);
    }
}

TEST_CASE("Addable With : Bit Specific Signed Integers")
{
    SECTION("int8_t with _")
    {
        // int8_t with Signed Integers
        REQUIRE(cortex::RightBitShiftWith<int8_t, int>);
        REQUIRE(cortex::RightBitShiftWith<int8_t, short>);
        REQUIRE(cortex::RightBitShiftWith<int8_t, long>);
        REQUIRE(cortex::RightBitShiftWith<int8_t, long long>);

        // int8_t with Unsigned Integers
        REQUIRE(cortex::RightBitShiftWith<int8_t, unsigned>);
        REQUIRE(cortex::RightBitShiftWith<int8_t, unsigned short>);
        REQUIRE(cortex::RightBitShiftWith<int8_t, u_short>);
        REQUIRE(cortex::RightBitShiftWith<int8_t, unsigned long>);
        REQUIRE(cortex::RightBitShiftWith<int8_t, unsigned long long>);
        
        // int8_t with Floating Point and Doubles
        REQUIRE(!cortex::RightBitShiftWith<int8_t, float>);
        REQUIRE(!cortex::RightBitShiftWith<int8_t, double>);
        REQUIRE(!cortex::RightBitShiftWith<int8_t, long double>);

        // int8_t with std::strings and std::string_view
        REQUIRE(!cortex::RightBitShiftWith<int8_t, std::string>);
        REQUIRE(!cortex::RightBitShiftWith<int8_t, std::string_view>);
        REQUIRE(!cortex::RightBitShiftWith<int8_t, std::u8string>);
        REQUIRE(!cortex::RightBitShiftWith<int8_t, std::u16string>);
        REQUIRE(!cortex::RightBitShiftWith<int8_t, std::u32string>);

        // int8_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::RightBitShiftWith<long long, std::wstring>);
        REQUIRE(!cortex::RightBitShiftWith<long long, std::wstring_view>);

        // int8_t with Charaters
        REQUIRE(cortex::RightBitShiftWith<int8_t, char>);
        REQUIRE(cortex::RightBitShiftWith<int8_t, u_char>);
        REQUIRE(cortex::RightBitShiftWith<int8_t, wchar_t>);

        // int8_t with Bit Specific Characters
        REQUIRE(cortex::RightBitShiftWith<int8_t, char8_t>);
        REQUIRE(cortex::RightBitShiftWith<int8_t, char16_t>);
        REQUIRE(cortex::RightBitShiftWith<int8_t, char32_t>);

        // int8_t with Bit Specific Integers
        REQUIRE(cortex::RightBitShiftWith<int8_t, int8_t>);
        REQUIRE(cortex::RightBitShiftWith<int8_t, int16_t>);
        REQUIRE(cortex::RightBitShiftWith<int8_t, int32_t>);
        REQUIRE(cortex::RightBitShiftWith<int8_t, int64_t>);

        // int8_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::RightBitShiftWith<int8_t, uint8_t>);
        REQUIRE(cortex::RightBitShiftWith<int8_t, uint16_t>);
        REQUIRE(cortex::RightBitShiftWith<int8_t, uint32_t>);
        REQUIRE(cortex::RightBitShiftWith<int8_t, uint64_t>);

        // int8_t with Bit Specific Least Integers
        REQUIRE(cortex::RightBitShiftWith<int8_t, int_least8_t>);
        REQUIRE(cortex::RightBitShiftWith<int8_t, int_least16_t>);
        REQUIRE(cortex::RightBitShiftWith<int8_t, int_least32_t>);
        REQUIRE(cortex::RightBitShiftWith<int8_t, int_least64_t>);
    }

    SECTION("int16_t with _")
    {
        // int16_t with Signed Integers
        REQUIRE(cortex::RightBitShiftWith<int16_t, int>);
        REQUIRE(cortex::RightBitShiftWith<int16_t, short>);
        REQUIRE(cortex::RightBitShiftWith<int16_t, long>);
        REQUIRE(cortex::RightBitShiftWith<int16_t, long long>);

        // int16_t with Unsigned Integers
        REQUIRE(cortex::RightBitShiftWith<int16_t, unsigned>);
        REQUIRE(cortex::RightBitShiftWith<int16_t, unsigned short>);
        REQUIRE(cortex::RightBitShiftWith<int16_t, u_short>);
        REQUIRE(cortex::RightBitShiftWith<int16_t, unsigned long>);
        REQUIRE(cortex::RightBitShiftWith<int16_t, unsigned long long>);
        
        // int16_t with Floating Point and Doubles
        REQUIRE(!cortex::RightBitShiftWith<int16_t, float>);
        REQUIRE(!cortex::RightBitShiftWith<int16_t, double>);
        REQUIRE(!cortex::RightBitShiftWith<int16_t, long double>);

        // int16_t with std::strings and std::string_view
        REQUIRE(!cortex::RightBitShiftWith<int16_t, std::string>);
        REQUIRE(!cortex::RightBitShiftWith<int16_t, std::string_view>);
        REQUIRE(!cortex::RightBitShiftWith<int16_t, std::u8string>);
        REQUIRE(!cortex::RightBitShiftWith<int16_t, std::u16string>);
        REQUIRE(!cortex::RightBitShiftWith<int16_t, std::u32string>);

        // int16_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::RightBitShiftWith<int16_t, std::wstring>);
        REQUIRE(!cortex::RightBitShiftWith<int16_t, std::wstring_view>);

        // int16_t with Charaters
        REQUIRE(cortex::RightBitShiftWith<int16_t, char>);
        REQUIRE(cortex::RightBitShiftWith<int16_t, u_char>);
        REQUIRE(cortex::RightBitShiftWith<int16_t, wchar_t>);

        // int16_t with Bit Specific Characters
        REQUIRE(cortex::RightBitShiftWith<int16_t, char8_t>);
        REQUIRE(cortex::RightBitShiftWith<int16_t, char16_t>);
        REQUIRE(cortex::RightBitShiftWith<int16_t, char32_t>);

        // int16_t with Bit Specific Integers
        REQUIRE(cortex::RightBitShiftWith<int16_t, int8_t>);
        REQUIRE(cortex::RightBitShiftWith<int16_t, int16_t>);
        REQUIRE(cortex::RightBitShiftWith<int16_t, int32_t>);
        REQUIRE(cortex::RightBitShiftWith<int16_t, int64_t>);

        // int16_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::RightBitShiftWith<int16_t, uint8_t>);
        REQUIRE(cortex::RightBitShiftWith<int16_t, uint16_t>);
        REQUIRE(cortex::RightBitShiftWith<int16_t, uint32_t>);
        REQUIRE(cortex::RightBitShiftWith<int16_t, uint64_t>);

        // int16_t with Bit Specific Least Integers
        REQUIRE(cortex::RightBitShiftWith<int16_t, int_least8_t>);
        REQUIRE(cortex::RightBitShiftWith<int16_t, int_least16_t>);
        REQUIRE(cortex::RightBitShiftWith<int16_t, int_least32_t>);
        REQUIRE(cortex::RightBitShiftWith<int16_t, int_least64_t>);
    }

    SECTION("int32 with _")
    {
        // int32 with Signed Integers
        REQUIRE(cortex::RightBitShiftWith<int32_t, int>);
        REQUIRE(cortex::RightBitShiftWith<int32_t, short>);
        REQUIRE(cortex::RightBitShiftWith<int32_t, long>);
        REQUIRE(cortex::RightBitShiftWith<int32_t, long long>);

        // int32 with Unsigned Integers
        REQUIRE(cortex::RightBitShiftWith<int32_t, unsigned>);
        REQUIRE(cortex::RightBitShiftWith<int32_t, unsigned short>);
        REQUIRE(cortex::RightBitShiftWith<int32_t, u_short>);
        REQUIRE(cortex::RightBitShiftWith<int32_t, unsigned long>);
        REQUIRE(cortex::RightBitShiftWith<int32_t, unsigned long long>);
        
        // int32 with Floating Point and Doubles
        REQUIRE(!cortex::RightBitShiftWith<int32_t, float>);
        REQUIRE(!cortex::RightBitShiftWith<int32_t, double>);
        REQUIRE(!cortex::RightBitShiftWith<int32_t, long double>);

        // int32 with std::strings and std::string_view
        REQUIRE(!cortex::RightBitShiftWith<int32_t, std::string>);
        REQUIRE(!cortex::RightBitShiftWith<int32_t, std::string_view>);
        REQUIRE(!cortex::RightBitShiftWith<int32_t, std::u8string>);
        REQUIRE(!cortex::RightBitShiftWith<int32_t, std::u16string>);
        REQUIRE(!cortex::RightBitShiftWith<int32_t, std::u32string>);

        // int32 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::RightBitShiftWith<int32_t, std::wstring>);
        REQUIRE(!cortex::RightBitShiftWith<int32_t, std::wstring_view>);

        // int32_t with Charaters
        REQUIRE(cortex::RightBitShiftWith<int32_t, char>);
        REQUIRE(cortex::RightBitShiftWith<int32_t, u_char>);
        REQUIRE(cortex::RightBitShiftWith<int32_t, wchar_t>);

        // int32_t with Bit Specific Characters
        REQUIRE(cortex::RightBitShiftWith<int32_t, char8_t>);
        REQUIRE(cortex::RightBitShiftWith<int32_t, char16_t>);
        REQUIRE(cortex::RightBitShiftWith<int32_t, char32_t>);

        // int32_t with Bit Specific Integers
        REQUIRE(cortex::RightBitShiftWith<int32_t, int8_t>);
        REQUIRE(cortex::RightBitShiftWith<int32_t, int16_t>);
        REQUIRE(cortex::RightBitShiftWith<int32_t, int32_t>);
        REQUIRE(cortex::RightBitShiftWith<int32_t, int64_t>);

        // int32_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::RightBitShiftWith<int32_t, uint8_t>);
        REQUIRE(cortex::RightBitShiftWith<int32_t, uint16_t>);
        REQUIRE(cortex::RightBitShiftWith<int32_t, uint32_t>);
        REQUIRE(cortex::RightBitShiftWith<int32_t, uint64_t>);

        // int32_t with Bit Specific Least Integers
        REQUIRE(cortex::RightBitShiftWith<int32_t, int_least8_t>);
        REQUIRE(cortex::RightBitShiftWith<int32_t, int_least16_t>);
        REQUIRE(cortex::RightBitShiftWith<int32_t, int_least32_t>);
        REQUIRE(cortex::RightBitShiftWith<int32_t, int_least64_t>);
    }

    SECTION("int64 with _")
    {
        // int64 with Signed Integers
        REQUIRE(cortex::RightBitShiftWith<int64_t, int>);
        REQUIRE(cortex::RightBitShiftWith<int64_t, short>);
        REQUIRE(cortex::RightBitShiftWith<int64_t, long>);
        REQUIRE(cortex::RightBitShiftWith<int64_t, long long>);

        // int64 with Unsigned Integers
        REQUIRE(cortex::RightBitShiftWith<int64_t, unsigned>);
        REQUIRE(cortex::RightBitShiftWith<int64_t, unsigned short>);
        REQUIRE(cortex::RightBitShiftWith<int64_t, u_short>);
        REQUIRE(cortex::RightBitShiftWith<int64_t, unsigned long>);
        REQUIRE(cortex::RightBitShiftWith<int64_t, unsigned long long>);
        
        // int64 with Floating Point and Doubles
        REQUIRE(!cortex::RightBitShiftWith<int64_t, float>);
        REQUIRE(!cortex::RightBitShiftWith<int64_t, double>);
        REQUIRE(!cortex::RightBitShiftWith<int64_t, long double>);

        // int64 with std::strings and std::string_view
        REQUIRE(!cortex::RightBitShiftWith<int64_t, std::string>);
        REQUIRE(!cortex::RightBitShiftWith<int64_t, std::string_view>);
        REQUIRE(!cortex::RightBitShiftWith<int64_t, std::u8string>);
        REQUIRE(!cortex::RightBitShiftWith<int64_t, std::u16string>);
        REQUIRE(!cortex::RightBitShiftWith<int64_t, std::u32string>);

        // int64 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::RightBitShiftWith<int64_t, std::wstring>);
        REQUIRE(!cortex::RightBitShiftWith<int64_t, std::wstring_view>);

        // int64_t with Charaters
        REQUIRE(cortex::RightBitShiftWith<int64_t, char>);
        REQUIRE(cortex::RightBitShiftWith<int64_t, u_char>);
        REQUIRE(cortex::RightBitShiftWith<int64_t, wchar_t>);

        // int64_t with Bit Specific Characters
        REQUIRE(cortex::RightBitShiftWith<int64_t, char8_t>);
        REQUIRE(cortex::RightBitShiftWith<int64_t, char16_t>);
        REQUIRE(cortex::RightBitShiftWith<int64_t, char32_t>);

        // int64_t with Bit Specific Integers
        REQUIRE(cortex::RightBitShiftWith<int64_t, int8_t>);
        REQUIRE(cortex::RightBitShiftWith<int64_t, int16_t>);
        REQUIRE(cortex::RightBitShiftWith<int64_t, int32_t>);
        REQUIRE(cortex::RightBitShiftWith<int64_t, int64_t>);

        // int64_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::RightBitShiftWith<int64_t, uint8_t>);
        REQUIRE(cortex::RightBitShiftWith<int64_t, uint16_t>);
        REQUIRE(cortex::RightBitShiftWith<int64_t, uint32_t>);
        REQUIRE(cortex::RightBitShiftWith<int64_t, uint64_t>);

        // int64_t with Bit Specific Least Integers
        REQUIRE(cortex::RightBitShiftWith<int64_t, int_least8_t>);
        REQUIRE(cortex::RightBitShiftWith<int64_t, int_least16_t>);
        REQUIRE(cortex::RightBitShiftWith<int64_t, int_least32_t>);
        REQUIRE(cortex::RightBitShiftWith<int64_t, int_least64_t>);
}
}

TEST_CASE("Addable With : Bit Specific Unsigned Integers")
{
    SECTION("uint8_t with _")
    {
        // uint8_t with Signed Integers
        REQUIRE(cortex::RightBitShiftWith<uint8_t, int>);
        REQUIRE(cortex::RightBitShiftWith<uint8_t, short>);
        REQUIRE(cortex::RightBitShiftWith<uint8_t, long>);
        REQUIRE(cortex::RightBitShiftWith<uint8_t, long long>);

        // uint8_t with Unsigned Integers
        REQUIRE(cortex::RightBitShiftWith<uint8_t, unsigned>);
        REQUIRE(cortex::RightBitShiftWith<uint8_t, unsigned short>);
        REQUIRE(cortex::RightBitShiftWith<uint8_t, u_short>);
        REQUIRE(cortex::RightBitShiftWith<uint8_t, unsigned long>);
        REQUIRE(cortex::RightBitShiftWith<uint8_t, unsigned long long>);
        
        // uint8_t with Floating Point and Doubles
        REQUIRE(!cortex::RightBitShiftWith<uint8_t, float>);
        REQUIRE(!cortex::RightBitShiftWith<uint8_t, double>);
        REQUIRE(!cortex::RightBitShiftWith<uint8_t, long double>);

        // uint8_t with std::strings and std::string_view
        REQUIRE(!cortex::RightBitShiftWith<uint8_t, std::string>);
        REQUIRE(!cortex::RightBitShiftWith<uint8_t, std::string_view>);
        REQUIRE(!cortex::RightBitShiftWith<uint8_t, std::u8string>);
        REQUIRE(!cortex::RightBitShiftWith<uint8_t, std::u16string>);
        REQUIRE(!cortex::RightBitShiftWith<uint8_t, std::u32string>);

        // uint8_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::RightBitShiftWith<long long, std::wstring>);
        REQUIRE(!cortex::RightBitShiftWith<long long, std::wstring_view>);

        // uint8_t with Charaters
        REQUIRE(cortex::RightBitShiftWith<uint8_t, char>);
        REQUIRE(cortex::RightBitShiftWith<uint8_t, u_char>);
        REQUIRE(cortex::RightBitShiftWith<uint8_t, wchar_t>);

        // uint8_t with Bit Specific Characters
        REQUIRE(cortex::RightBitShiftWith<uint8_t, char8_t>);
        REQUIRE(cortex::RightBitShiftWith<uint8_t, char16_t>);
        REQUIRE(cortex::RightBitShiftWith<uint8_t, char32_t>);

        // uint8_t with Bit Specific Integers
        REQUIRE(cortex::RightBitShiftWith<uint8_t, int8_t>);
        REQUIRE(cortex::RightBitShiftWith<uint8_t, int16_t>);
        REQUIRE(cortex::RightBitShiftWith<uint8_t, int32_t>);
        REQUIRE(cortex::RightBitShiftWith<uint8_t, int64_t>);

        // uint8_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::RightBitShiftWith<uint8_t, uint8_t>);
        REQUIRE(cortex::RightBitShiftWith<uint8_t, uint16_t>);
        REQUIRE(cortex::RightBitShiftWith<uint8_t, uint32_t>);
        REQUIRE(cortex::RightBitShiftWith<uint8_t, uint64_t>);

        // uint8_t with Bit Specific Least Integers
        REQUIRE(cortex::RightBitShiftWith<uint8_t, int_least8_t>);
        REQUIRE(cortex::RightBitShiftWith<uint8_t, int_least16_t>);
        REQUIRE(cortex::RightBitShiftWith<uint8_t, int_least32_t>);
        REQUIRE(cortex::RightBitShiftWith<uint8_t, int_least64_t>);
    }

    SECTION("uint16_t with _")
    {
        // uint16_t with Signed Integers
        REQUIRE(cortex::RightBitShiftWith<uint16_t, int>);
        REQUIRE(cortex::RightBitShiftWith<uint16_t, short>);
        REQUIRE(cortex::RightBitShiftWith<uint16_t, long>);
        REQUIRE(cortex::RightBitShiftWith<uint16_t, long long>);

        // uint16_t with Unsigned Integers
        REQUIRE(cortex::RightBitShiftWith<uint16_t, unsigned>);
        REQUIRE(cortex::RightBitShiftWith<uint16_t, unsigned short>);
        REQUIRE(cortex::RightBitShiftWith<uint16_t, u_short>);
        REQUIRE(cortex::RightBitShiftWith<uint16_t, unsigned long>);
        REQUIRE(cortex::RightBitShiftWith<uint16_t, unsigned long long>);
        
        // uint16_t with Floating Point and Doubles
        REQUIRE(!cortex::RightBitShiftWith<uint16_t, float>);
        REQUIRE(!cortex::RightBitShiftWith<uint16_t, double>);
        REQUIRE(!cortex::RightBitShiftWith<uint16_t, long double>);

        // uint16_t with std::strings and std::string_view
        REQUIRE(!cortex::RightBitShiftWith<uint16_t, std::string>);
        REQUIRE(!cortex::RightBitShiftWith<uint16_t, std::string_view>);
        REQUIRE(!cortex::RightBitShiftWith<uint16_t, std::u8string>);
        REQUIRE(!cortex::RightBitShiftWith<uint16_t, std::u16string>);
        REQUIRE(!cortex::RightBitShiftWith<uint16_t, std::u32string>);

        // uint16_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::RightBitShiftWith<uint16_t, std::wstring>);
        REQUIRE(!cortex::RightBitShiftWith<uint16_t, std::wstring_view>);

        // uint16_t with Charaters
        REQUIRE(cortex::RightBitShiftWith<uint16_t, char>);
        REQUIRE(cortex::RightBitShiftWith<uint16_t, u_char>);
        REQUIRE(cortex::RightBitShiftWith<uint16_t, wchar_t>);

        // uint16_t with Bit Specific Characters
        REQUIRE(cortex::RightBitShiftWith<uint16_t, char8_t>);
        REQUIRE(cortex::RightBitShiftWith<uint16_t, char16_t>);
        REQUIRE(cortex::RightBitShiftWith<uint16_t, char32_t>);

        // uint16_t with Bit Specific Integers
        REQUIRE(cortex::RightBitShiftWith<uint16_t, int8_t>);
        REQUIRE(cortex::RightBitShiftWith<uint16_t, int16_t>);
        REQUIRE(cortex::RightBitShiftWith<uint16_t, int32_t>);
        REQUIRE(cortex::RightBitShiftWith<uint16_t, int64_t>);

        // uint16_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::RightBitShiftWith<uint16_t, uint8_t>);
        REQUIRE(cortex::RightBitShiftWith<uint16_t, uint16_t>);
        REQUIRE(cortex::RightBitShiftWith<uint16_t, uint32_t>);
        REQUIRE(cortex::RightBitShiftWith<uint16_t, uint64_t>);

        // uint16_t with Bit Specific Least Integers
        REQUIRE(cortex::RightBitShiftWith<uint16_t, int_least8_t>);
        REQUIRE(cortex::RightBitShiftWith<uint16_t, int_least16_t>);
        REQUIRE(cortex::RightBitShiftWith<uint16_t, int_least32_t>);
        REQUIRE(cortex::RightBitShiftWith<uint16_t, int_least64_t>);
    }

    SECTION("uint32_t with _")
    {
        // int32 with Signed Integers
        REQUIRE(cortex::RightBitShiftWith<uint32_t, int>);
        REQUIRE(cortex::RightBitShiftWith<uint32_t, short>);
        REQUIRE(cortex::RightBitShiftWith<uint32_t, long>);
        REQUIRE(cortex::RightBitShiftWith<uint32_t, long long>);

        // int32 with Unsigned Integers
        REQUIRE(cortex::RightBitShiftWith<uint32_t, unsigned>);
        REQUIRE(cortex::RightBitShiftWith<uint32_t, unsigned short>);
        REQUIRE(cortex::RightBitShiftWith<uint32_t, u_short>);
        REQUIRE(cortex::RightBitShiftWith<uint32_t, unsigned long>);
        REQUIRE(cortex::RightBitShiftWith<uint32_t, unsigned long long>);
        
        // int32 with Floating Point and Doubles
        REQUIRE(!cortex::RightBitShiftWith<uint32_t, float>);
        REQUIRE(!cortex::RightBitShiftWith<uint32_t, double>);
        REQUIRE(!cortex::RightBitShiftWith<uint32_t, long double>);

        // int32 with std::strings and std::string_view
        REQUIRE(!cortex::RightBitShiftWith<uint32_t, std::string>);
        REQUIRE(!cortex::RightBitShiftWith<uint32_t, std::string_view>);
        REQUIRE(!cortex::RightBitShiftWith<uint32_t, std::u8string>);
        REQUIRE(!cortex::RightBitShiftWith<uint32_t, std::u16string>);
        REQUIRE(!cortex::RightBitShiftWith<uint32_t, std::u32string>);

        // int32 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::RightBitShiftWith<uint32_t, std::wstring>);
        REQUIRE(!cortex::RightBitShiftWith<uint32_t, std::wstring_view>);

        // uint32_t with Charaters
        REQUIRE(cortex::RightBitShiftWith<uint32_t, char>);
        REQUIRE(cortex::RightBitShiftWith<uint32_t, u_char>);
        REQUIRE(cortex::RightBitShiftWith<uint32_t, wchar_t>);

        // uint32_t with Bit Specific Characters
        REQUIRE(cortex::RightBitShiftWith<uint32_t, char8_t>);
        REQUIRE(cortex::RightBitShiftWith<uint32_t, char16_t>);
        REQUIRE(cortex::RightBitShiftWith<uint32_t, char32_t>);

        // uint32_t with Bit Specific Integers
        REQUIRE(cortex::RightBitShiftWith<uint32_t, int8_t>);
        REQUIRE(cortex::RightBitShiftWith<uint32_t, int16_t>);
        REQUIRE(cortex::RightBitShiftWith<uint32_t, int32_t>);
        REQUIRE(cortex::RightBitShiftWith<uint32_t, int64_t>);

        // uint32_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::RightBitShiftWith<uint32_t, uint8_t>);
        REQUIRE(cortex::RightBitShiftWith<uint32_t, uint16_t>);
        REQUIRE(cortex::RightBitShiftWith<uint32_t, uint32_t>);
        REQUIRE(cortex::RightBitShiftWith<uint32_t, uint64_t>);

        // uint32_t with Bit Specific Least Integers
        REQUIRE(cortex::RightBitShiftWith<uint32_t, int_least8_t>);
        REQUIRE(cortex::RightBitShiftWith<uint32_t, int_least16_t>);
        REQUIRE(cortex::RightBitShiftWith<uint32_t, int_least32_t>);
        REQUIRE(cortex::RightBitShiftWith<uint32_t, int_least64_t>);
    }

    SECTION("uint64_t with _")
    {
        // int64 with Signed Integers
        REQUIRE(cortex::RightBitShiftWith<uint64_t, int>);
        REQUIRE(cortex::RightBitShiftWith<uint64_t, short>);
        REQUIRE(cortex::RightBitShiftWith<uint64_t, long>);
        REQUIRE(cortex::RightBitShiftWith<uint64_t, long long>);

        // int64 with Unsigned Integers
        REQUIRE(cortex::RightBitShiftWith<uint64_t, unsigned>);
        REQUIRE(cortex::RightBitShiftWith<uint64_t, unsigned short>);
        REQUIRE(cortex::RightBitShiftWith<uint64_t, u_short>);
        REQUIRE(cortex::RightBitShiftWith<uint64_t, unsigned long>);
        REQUIRE(cortex::RightBitShiftWith<uint64_t, unsigned long long>);
        
        // int64 with Floating Point and Doubles
        REQUIRE(!cortex::RightBitShiftWith<uint64_t, float>);
        REQUIRE(!cortex::RightBitShiftWith<uint64_t, double>);
        REQUIRE(!cortex::RightBitShiftWith<uint64_t, long double>);

        // int64 with std::strings and std::string_view
        REQUIRE(!cortex::RightBitShiftWith<uint64_t, std::string>);
        REQUIRE(!cortex::RightBitShiftWith<uint64_t, std::string_view>);
        REQUIRE(!cortex::RightBitShiftWith<uint64_t, std::u8string>);
        REQUIRE(!cortex::RightBitShiftWith<uint64_t, std::u16string>);
        REQUIRE(!cortex::RightBitShiftWith<uint64_t, std::u32string>);

        // int64 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::RightBitShiftWith<uint64_t, std::wstring>);
        REQUIRE(!cortex::RightBitShiftWith<uint64_t, std::wstring_view>);

        // uint64_t with Charaters
        REQUIRE(cortex::RightBitShiftWith<uint64_t, char>);
        REQUIRE(cortex::RightBitShiftWith<uint64_t, u_char>);
        REQUIRE(cortex::RightBitShiftWith<uint64_t, wchar_t>);

        // uint64_t with Bit Specific Characters
        REQUIRE(cortex::RightBitShiftWith<uint64_t, char8_t>);
        REQUIRE(cortex::RightBitShiftWith<uint64_t, char16_t>);
        REQUIRE(cortex::RightBitShiftWith<uint64_t, char32_t>);

        // uint64_t with Bit Specific Integers
        REQUIRE(cortex::RightBitShiftWith<uint64_t, int8_t>);
        REQUIRE(cortex::RightBitShiftWith<uint64_t, int16_t>);
        REQUIRE(cortex::RightBitShiftWith<uint64_t, int32_t>);
        REQUIRE(cortex::RightBitShiftWith<uint64_t, int64_t>);

        // uint64_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::RightBitShiftWith<uint64_t, uint8_t>);
        REQUIRE(cortex::RightBitShiftWith<uint64_t, uint16_t>);
        REQUIRE(cortex::RightBitShiftWith<uint64_t, uint32_t>);
        REQUIRE(cortex::RightBitShiftWith<uint64_t, uint64_t>);

        // uint64_t with Bit Specific Least Integers
        REQUIRE(cortex::RightBitShiftWith<uint64_t, int_least8_t>);
        REQUIRE(cortex::RightBitShiftWith<uint64_t, int_least16_t>);
        REQUIRE(cortex::RightBitShiftWith<uint64_t, int_least32_t>);
        REQUIRE(cortex::RightBitShiftWith<uint64_t, int_least64_t>);
    }
}

TEST_CASE("Addable With : std::size_t")
{
    SECTION("std::size_t with _")
    {
        // std::size_t with Signed Integers
        REQUIRE(cortex::RightBitShiftWith<std::size_t, int>);
        REQUIRE(cortex::RightBitShiftWith<std::size_t, short>);
        REQUIRE(cortex::RightBitShiftWith<std::size_t, long>);
        REQUIRE(cortex::RightBitShiftWith<std::size_t, long long>);

        // std::size_t with Unsigned Integers
        REQUIRE(cortex::RightBitShiftWith<std::size_t, unsigned>);
        REQUIRE(cortex::RightBitShiftWith<std::size_t, unsigned short>);
        REQUIRE(cortex::RightBitShiftWith<std::size_t, u_short>);
        REQUIRE(cortex::RightBitShiftWith<std::size_t, unsigned long>);
        REQUIRE(cortex::RightBitShiftWith<std::size_t, unsigned long long>);
        
        // std::size_t with Floating Point and Doubles
        REQUIRE(!cortex::RightBitShiftWith<std::size_t, float>);
        REQUIRE(!cortex::RightBitShiftWith<std::size_t, double>);
        REQUIRE(!cortex::RightBitShiftWith<std::size_t, long double>);

        // std::size_t with std::strings and std::string_view
        REQUIRE(!cortex::RightBitShiftWith<std::size_t, std::string>);
        REQUIRE(!cortex::RightBitShiftWith<std::size_t, std::string_view>);
        REQUIRE(!cortex::RightBitShiftWith<std::size_t, std::u8string>);
        REQUIRE(!cortex::RightBitShiftWith<std::size_t, std::u16string>);
        REQUIRE(!cortex::RightBitShiftWith<std::size_t, std::u32string>);

        // std::size_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::RightBitShiftWith<long long, std::wstring>);
        REQUIRE(!cortex::RightBitShiftWith<long long, std::wstring_view>);

        // std::size_t with Charaters
        REQUIRE(cortex::RightBitShiftWith<std::size_t, char>);
        REQUIRE(cortex::RightBitShiftWith<std::size_t, u_char>);
        REQUIRE(cortex::RightBitShiftWith<std::size_t, wchar_t>);

        // std::size_t with Bit Specific Characters
        REQUIRE(cortex::RightBitShiftWith<std::size_t, char8_t>);
        REQUIRE(cortex::RightBitShiftWith<std::size_t, char16_t>);
        REQUIRE(cortex::RightBitShiftWith<std::size_t, char32_t>);

        // std::size_t with Bit Specific Integers
        REQUIRE(cortex::RightBitShiftWith<std::size_t, int8_t>);
        REQUIRE(cortex::RightBitShiftWith<std::size_t, int16_t>);
        REQUIRE(cortex::RightBitShiftWith<std::size_t, int32_t>);
        REQUIRE(cortex::RightBitShiftWith<std::size_t, int64_t>);

        // std::size_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::RightBitShiftWith<std::size_t, uint8_t>);
        REQUIRE(cortex::RightBitShiftWith<std::size_t, uint16_t>);
        REQUIRE(cortex::RightBitShiftWith<std::size_t, uint32_t>);
        REQUIRE(cortex::RightBitShiftWith<std::size_t, uint64_t>);

        // std::size_t with Bit Specific Least Integers
        REQUIRE(cortex::RightBitShiftWith<std::size_t, int_least8_t>);
        REQUIRE(cortex::RightBitShiftWith<std::size_t, int_least16_t>);
        REQUIRE(cortex::RightBitShiftWith<std::size_t, int_least32_t>);
        REQUIRE(cortex::RightBitShiftWith<std::size_t, int_least64_t>);
    }
}

TEST_CASE("RightBitShiftWith : Fast Integers")
{
    SECTION("int_fast8_t with _")
    {
        // int_fast8_t with Signed Integers
        REQUIRE(cortex::RightBitShiftWith<int_fast8_t, int>);
        REQUIRE(cortex::RightBitShiftWith<int_fast8_t, short>);
        REQUIRE(cortex::RightBitShiftWith<int_fast8_t, long>);
        REQUIRE(cortex::RightBitShiftWith<int_fast8_t, long long>);

        // int_fast8_t with Unsigned Integers
        REQUIRE(cortex::RightBitShiftWith<int_fast8_t, unsigned>);
        REQUIRE(cortex::RightBitShiftWith<int_fast8_t, unsigned short>);
        REQUIRE(cortex::RightBitShiftWith<int_fast8_t, u_short>);
        REQUIRE(cortex::RightBitShiftWith<int_fast8_t, unsigned long>);
        REQUIRE(cortex::RightBitShiftWith<int_fast8_t, unsigned long long>);
        
        // int_fast8_t with Floating Point and Doubles
        REQUIRE(!cortex::RightBitShiftWith<int_fast8_t, float>);
        REQUIRE(!cortex::RightBitShiftWith<int_fast8_t, double>);
        REQUIRE(!cortex::RightBitShiftWith<int_fast8_t, long double>);

        // int_fast8_t with std::strings and std::string_view
        REQUIRE(!cortex::RightBitShiftWith<int_fast8_t, std::string>);
        REQUIRE(!cortex::RightBitShiftWith<int_fast8_t, std::string_view>);
        REQUIRE(!cortex::RightBitShiftWith<int_fast8_t, std::u8string>);
        REQUIRE(!cortex::RightBitShiftWith<int_fast8_t, std::u16string>);
        REQUIRE(!cortex::RightBitShiftWith<int_fast8_t, std::u32string>);

        // int_fast8_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::RightBitShiftWith<long long, std::wstring>);
        REQUIRE(!cortex::RightBitShiftWith<long long, std::wstring_view>);

        // int_fast8_t with Charaters
        REQUIRE(cortex::RightBitShiftWith<int_fast8_t, char>);
        REQUIRE(cortex::RightBitShiftWith<int_fast8_t, u_char>);
        REQUIRE(cortex::RightBitShiftWith<int_fast8_t, wchar_t>);

        // int_fast8_t with Bit Specific Characters
        REQUIRE(cortex::RightBitShiftWith<int_fast8_t, char8_t>);
        REQUIRE(cortex::RightBitShiftWith<int_fast8_t, char16_t>);
        REQUIRE(cortex::RightBitShiftWith<int_fast8_t, char32_t>);

        // int_fast8_t with Bit Specific Integers
        REQUIRE(cortex::RightBitShiftWith<int_fast8_t, int8_t>);
        REQUIRE(cortex::RightBitShiftWith<int_fast8_t, int16_t>);
        REQUIRE(cortex::RightBitShiftWith<int_fast8_t, int32_t>);
        REQUIRE(cortex::RightBitShiftWith<int_fast8_t, int64_t>);

        // int_fast8_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::RightBitShiftWith<int_fast8_t, uint8_t>);
        REQUIRE(cortex::RightBitShiftWith<int_fast8_t, uint16_t>);
        REQUIRE(cortex::RightBitShiftWith<int_fast8_t, uint32_t>);
        REQUIRE(cortex::RightBitShiftWith<int_fast8_t, uint64_t>);

        // int_fast8_t with Bit Specific Least Integers
        REQUIRE(cortex::RightBitShiftWith<int_fast8_t, int_least8_t>);
        REQUIRE(cortex::RightBitShiftWith<int_fast8_t, int_least16_t>);
        REQUIRE(cortex::RightBitShiftWith<int_fast8_t, int_least32_t>);
        REQUIRE(cortex::RightBitShiftWith<int_fast8_t, int_least64_t>);
    }

    SECTION("int_fast16_t with _")
    {
        // int_fast16_t with Signed Integers
        REQUIRE(cortex::RightBitShiftWith<int_fast16_t, int>);
        REQUIRE(cortex::RightBitShiftWith<int_fast16_t, short>);
        REQUIRE(cortex::RightBitShiftWith<int_fast16_t, long>);
        REQUIRE(cortex::RightBitShiftWith<int_fast16_t, long long>);

        // int_fast16_t with Unsigned Integers
        REQUIRE(cortex::RightBitShiftWith<int_fast16_t, unsigned>);
        REQUIRE(cortex::RightBitShiftWith<int_fast16_t, unsigned short>);
        REQUIRE(cortex::RightBitShiftWith<int_fast16_t, u_short>);
        REQUIRE(cortex::RightBitShiftWith<int_fast16_t, unsigned long>);
        REQUIRE(cortex::RightBitShiftWith<int_fast16_t, unsigned long long>);
        
        // int_fast16_t with Floating Point and Doubles
        REQUIRE(!cortex::RightBitShiftWith<int_fast16_t, float>);
        REQUIRE(!cortex::RightBitShiftWith<int_fast16_t, double>);
        REQUIRE(!cortex::RightBitShiftWith<int_fast16_t, long double>);

        // int_fast16_t with std::strings and std::string_view
        REQUIRE(!cortex::RightBitShiftWith<int_fast16_t, std::string>);
        REQUIRE(!cortex::RightBitShiftWith<int_fast16_t, std::string_view>);
        REQUIRE(!cortex::RightBitShiftWith<int_fast16_t, std::u8string>);
        REQUIRE(!cortex::RightBitShiftWith<int_fast16_t, std::u16string>);
        REQUIRE(!cortex::RightBitShiftWith<int_fast16_t, std::u32string>);

        // int_fast16_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::RightBitShiftWith<int_fast16_t, std::wstring>);
        REQUIRE(!cortex::RightBitShiftWith<int_fast16_t, std::wstring_view>);

        // int_fast16_t with Charaters
        REQUIRE(cortex::RightBitShiftWith<int_fast16_t, char>);
        REQUIRE(cortex::RightBitShiftWith<int_fast16_t, u_char>);
        REQUIRE(cortex::RightBitShiftWith<int_fast16_t, wchar_t>);

        // int_fast16_t with Bit Specific Characters
        REQUIRE(cortex::RightBitShiftWith<int_fast16_t, char8_t>);
        REQUIRE(cortex::RightBitShiftWith<int_fast16_t, char16_t>);
        REQUIRE(cortex::RightBitShiftWith<int_fast16_t, char32_t>);

        // int_fast16_t with Bit Specific Integers
        REQUIRE(cortex::RightBitShiftWith<int_fast16_t, int8_t>);
        REQUIRE(cortex::RightBitShiftWith<int_fast16_t, int16_t>);
        REQUIRE(cortex::RightBitShiftWith<int_fast16_t, int32_t>);
        REQUIRE(cortex::RightBitShiftWith<int_fast16_t, int64_t>);

        // int_fast16_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::RightBitShiftWith<int_fast16_t, uint8_t>);
        REQUIRE(cortex::RightBitShiftWith<int_fast16_t, uint16_t>);
        REQUIRE(cortex::RightBitShiftWith<int_fast16_t, uint32_t>);
        REQUIRE(cortex::RightBitShiftWith<int_fast16_t, uint64_t>);

        // int_fast16_t with Bit Specific Least Integers
        REQUIRE(cortex::RightBitShiftWith<int_fast16_t, int_least8_t>);
        REQUIRE(cortex::RightBitShiftWith<int_fast16_t, int_least16_t>);
        REQUIRE(cortex::RightBitShiftWith<int_fast16_t, int_least32_t>);
        REQUIRE(cortex::RightBitShiftWith<int_fast16_t, int_least64_t>);
    }

    SECTION("int_fast32_t with _")
    {
        // int32 with Signed Integers
        REQUIRE(cortex::RightBitShiftWith<int_fast32_t, int>);
        REQUIRE(cortex::RightBitShiftWith<int_fast32_t, short>);
        REQUIRE(cortex::RightBitShiftWith<int_fast32_t, long>);
        REQUIRE(cortex::RightBitShiftWith<int_fast32_t, long long>);

        // int32 with Unsigned Integers
        REQUIRE(cortex::RightBitShiftWith<int_fast32_t, unsigned>);
        REQUIRE(cortex::RightBitShiftWith<int_fast32_t, unsigned short>);
        REQUIRE(cortex::RightBitShiftWith<int_fast32_t, u_short>);
        REQUIRE(cortex::RightBitShiftWith<int_fast32_t, unsigned long>);
        REQUIRE(cortex::RightBitShiftWith<int_fast32_t, unsigned long long>);
        
        // int32 with Floating Point and Doubles
        REQUIRE(!cortex::RightBitShiftWith<int_fast32_t, float>);
        REQUIRE(!cortex::RightBitShiftWith<int_fast32_t, double>);
        REQUIRE(!cortex::RightBitShiftWith<int_fast32_t, long double>);

        // int32 with std::strings and std::string_view
        REQUIRE(!cortex::RightBitShiftWith<int_fast32_t, std::string>);
        REQUIRE(!cortex::RightBitShiftWith<int_fast32_t, std::string_view>);
        REQUIRE(!cortex::RightBitShiftWith<int_fast32_t, std::u8string>);
        REQUIRE(!cortex::RightBitShiftWith<int_fast32_t, std::u16string>);
        REQUIRE(!cortex::RightBitShiftWith<int_fast32_t, std::u32string>);

        // int32 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::RightBitShiftWith<int_fast32_t, std::wstring>);
        REQUIRE(!cortex::RightBitShiftWith<int_fast32_t, std::wstring_view>);

        // int_fast32_t with Charaters
        REQUIRE(cortex::RightBitShiftWith<int_fast32_t, char>);
        REQUIRE(cortex::RightBitShiftWith<int_fast32_t, u_char>);
        REQUIRE(cortex::RightBitShiftWith<int_fast32_t, wchar_t>);

        // int_fast32_t with Bit Specific Characters
        REQUIRE(cortex::RightBitShiftWith<int_fast32_t, char8_t>);
        REQUIRE(cortex::RightBitShiftWith<int_fast32_t, char16_t>);
        REQUIRE(cortex::RightBitShiftWith<int_fast32_t, char32_t>);

        // int_fast32_t with Bit Specific Integers
        REQUIRE(cortex::RightBitShiftWith<int_fast32_t, int8_t>);
        REQUIRE(cortex::RightBitShiftWith<int_fast32_t, int16_t>);
        REQUIRE(cortex::RightBitShiftWith<int_fast32_t, int32_t>);
        REQUIRE(cortex::RightBitShiftWith<int_fast32_t, int64_t>);

        // int_fast32_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::RightBitShiftWith<int_fast32_t, uint8_t>);
        REQUIRE(cortex::RightBitShiftWith<int_fast32_t, uint16_t>);
        REQUIRE(cortex::RightBitShiftWith<int_fast32_t, uint32_t>);
        REQUIRE(cortex::RightBitShiftWith<int_fast32_t, uint64_t>);

        // int_fast32_t with Bit Specific Least Integers
        REQUIRE(cortex::RightBitShiftWith<int_fast32_t, int_least8_t>);
        REQUIRE(cortex::RightBitShiftWith<int_fast32_t, int_least16_t>);
        REQUIRE(cortex::RightBitShiftWith<int_fast32_t, int_least32_t>);
        REQUIRE(cortex::RightBitShiftWith<int_fast32_t, int_least64_t>);
    }

    SECTION("int_fast64_t with _")
    {
        // int64 with Signed Integers
        REQUIRE(cortex::RightBitShiftWith<int_fast64_t, int>);
        REQUIRE(cortex::RightBitShiftWith<int_fast64_t, short>);
        REQUIRE(cortex::RightBitShiftWith<int_fast64_t, long>);
        REQUIRE(cortex::RightBitShiftWith<int_fast64_t, long long>);

        // int64 with Unsigned Integers
        REQUIRE(cortex::RightBitShiftWith<int_fast64_t, unsigned>);
        REQUIRE(cortex::RightBitShiftWith<int_fast64_t, unsigned short>);
        REQUIRE(cortex::RightBitShiftWith<int_fast64_t, u_short>);
        REQUIRE(cortex::RightBitShiftWith<int_fast64_t, unsigned long>);
        REQUIRE(cortex::RightBitShiftWith<int_fast64_t, unsigned long long>);
        
        // int64 with Floating Point and Doubles
        REQUIRE(!cortex::RightBitShiftWith<int_fast64_t, float>);
        REQUIRE(!cortex::RightBitShiftWith<int_fast64_t, double>);
        REQUIRE(!cortex::RightBitShiftWith<int_fast64_t, long double>);

        // int64 with std::strings and std::string_view
        REQUIRE(!cortex::RightBitShiftWith<int_fast64_t, std::string>);
        REQUIRE(!cortex::RightBitShiftWith<int_fast64_t, std::string_view>);
        REQUIRE(!cortex::RightBitShiftWith<int_fast64_t, std::u8string>);
        REQUIRE(!cortex::RightBitShiftWith<int_fast64_t, std::u16string>);
        REQUIRE(!cortex::RightBitShiftWith<int_fast64_t, std::u32string>);

        // int64 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::RightBitShiftWith<int_fast64_t, std::wstring>);
        REQUIRE(!cortex::RightBitShiftWith<int_fast64_t, std::wstring_view>);

        // int_fast64_t with Charaters
        REQUIRE(cortex::RightBitShiftWith<int_fast64_t, char>);
        REQUIRE(cortex::RightBitShiftWith<int_fast64_t, u_char>);
        REQUIRE(cortex::RightBitShiftWith<int_fast64_t, wchar_t>);

        // int_fast64_t with Bit Specific Characters
        REQUIRE(cortex::RightBitShiftWith<int_fast64_t, char8_t>);
        REQUIRE(cortex::RightBitShiftWith<int_fast64_t, char16_t>);
        REQUIRE(cortex::RightBitShiftWith<int_fast64_t, char32_t>);

        // int_fast64_t with Bit Specific Integers
        REQUIRE(cortex::RightBitShiftWith<int_fast64_t, int8_t>);
        REQUIRE(cortex::RightBitShiftWith<int_fast64_t, int16_t>);
        REQUIRE(cortex::RightBitShiftWith<int_fast64_t, int32_t>);
        REQUIRE(cortex::RightBitShiftWith<int_fast64_t, int64_t>);

        // int_fast64_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::RightBitShiftWith<int_fast64_t, uint8_t>);
        REQUIRE(cortex::RightBitShiftWith<int_fast64_t, uint16_t>);
        REQUIRE(cortex::RightBitShiftWith<int_fast64_t, uint32_t>);
        REQUIRE(cortex::RightBitShiftWith<int_fast64_t, uint64_t>);

        // int_fast64_t with Bit Specific Least Integers
        REQUIRE(cortex::RightBitShiftWith<int_fast64_t, int_least8_t>);
        REQUIRE(cortex::RightBitShiftWith<int_fast64_t, int_least16_t>);
        REQUIRE(cortex::RightBitShiftWith<int_fast64_t, int_least32_t>);
        REQUIRE(cortex::RightBitShiftWith<int_fast64_t, int_least64_t>);
    }
}

TEST_CASE("RightBitShiftWith : Least Integers")
{
    SECTION("int_least8_t with _")
    {
        // int_fast8_t with Signed Integers
        REQUIRE(cortex::RightBitShiftWith<int_least8_t, int>);
        REQUIRE(cortex::RightBitShiftWith<int_least8_t, short>);
        REQUIRE(cortex::RightBitShiftWith<int_least8_t, long>);
        REQUIRE(cortex::RightBitShiftWith<int_least8_t, long long>);

        // int_fast8_t with Unsigned Integers
        REQUIRE(cortex::RightBitShiftWith<int_least8_t, unsigned>);
        REQUIRE(cortex::RightBitShiftWith<int_least8_t, unsigned short>);
        REQUIRE(cortex::RightBitShiftWith<int_least8_t, u_short>);
        REQUIRE(cortex::RightBitShiftWith<int_least8_t, unsigned long>);
        REQUIRE(cortex::RightBitShiftWith<int_least8_t, unsigned long long>);
        
        // int_fast8_t with Floating Point and Doubles
        REQUIRE(!cortex::RightBitShiftWith<int_least8_t, float>);
        REQUIRE(!cortex::RightBitShiftWith<int_least8_t, double>);
        REQUIRE(!cortex::RightBitShiftWith<int_least8_t, long double>);

        // int_fast8_t with std::strings and std::string_view
        REQUIRE(!cortex::RightBitShiftWith<int_least8_t, std::string>);
        REQUIRE(!cortex::RightBitShiftWith<int_least8_t, std::string_view>);
        REQUIRE(!cortex::RightBitShiftWith<int_least8_t, std::u8string>);
        REQUIRE(!cortex::RightBitShiftWith<int_least8_t, std::u16string>);
        REQUIRE(!cortex::RightBitShiftWith<int_least8_t, std::u32string>);

        // int_fast8_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::RightBitShiftWith<long long, std::wstring>);
        REQUIRE(!cortex::RightBitShiftWith<long long, std::wstring_view>);

        // int_fast8_t with Charaters
        REQUIRE(cortex::RightBitShiftWith<int_least8_t, char>);
        REQUIRE(cortex::RightBitShiftWith<int_least8_t, u_char>);
        REQUIRE(cortex::RightBitShiftWith<int_least8_t, wchar_t>);

        // int_fast8_t with Bit Specific Characters
        REQUIRE(cortex::RightBitShiftWith<int_least8_t, char8_t>);
        REQUIRE(cortex::RightBitShiftWith<int_least8_t, char16_t>);
        REQUIRE(cortex::RightBitShiftWith<int_least8_t, char32_t>);

        // int_fast8_t with Bit Specific Integers
        REQUIRE(cortex::RightBitShiftWith<int_least8_t, int8_t>);
        REQUIRE(cortex::RightBitShiftWith<int_least8_t, int16_t>);
        REQUIRE(cortex::RightBitShiftWith<int_least8_t, int32_t>);
        REQUIRE(cortex::RightBitShiftWith<int_least8_t, int64_t>);

        // int_fast8_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::RightBitShiftWith<int_least8_t, uint8_t>);
        REQUIRE(cortex::RightBitShiftWith<int_least8_t, uint16_t>);
        REQUIRE(cortex::RightBitShiftWith<int_least8_t, uint32_t>);
        REQUIRE(cortex::RightBitShiftWith<int_least8_t, uint64_t>);

        // int_fast8_t with Bit Specific Least Integers
        REQUIRE(cortex::RightBitShiftWith<int_least8_t, int_least8_t>);
        REQUIRE(cortex::RightBitShiftWith<int_least8_t, int_least16_t>);
        REQUIRE(cortex::RightBitShiftWith<int_least8_t, int_least32_t>);
        REQUIRE(cortex::RightBitShiftWith<int_least8_t, int_least64_t>);
    }

    SECTION("int_least16_t with _")
    {
        // int_fast16_t with Signed Integers
        REQUIRE(cortex::RightBitShiftWith<int_least16_t, int>);
        REQUIRE(cortex::RightBitShiftWith<int_least16_t, short>);
        REQUIRE(cortex::RightBitShiftWith<int_least16_t, long>);
        REQUIRE(cortex::RightBitShiftWith<int_least16_t, long long>);

        // int_fast16_t with Unsigned Integers
        REQUIRE(cortex::RightBitShiftWith<int_least16_t, unsigned>);
        REQUIRE(cortex::RightBitShiftWith<int_least16_t, unsigned short>);
        REQUIRE(cortex::RightBitShiftWith<int_least16_t, u_short>);
        REQUIRE(cortex::RightBitShiftWith<int_least16_t, unsigned long>);
        REQUIRE(cortex::RightBitShiftWith<int_least16_t, unsigned long long>);
        
        // int_fast16_t with Floating Point and Doubles
        REQUIRE(!cortex::RightBitShiftWith<int_least16_t, float>);
        REQUIRE(!cortex::RightBitShiftWith<int_least16_t, double>);
        REQUIRE(!cortex::RightBitShiftWith<int_least16_t, long double>);

        // int_fast16_t with std::strings and std::string_view
        REQUIRE(!cortex::RightBitShiftWith<int_least16_t, std::string>);
        REQUIRE(!cortex::RightBitShiftWith<int_least16_t, std::string_view>);
        REQUIRE(!cortex::RightBitShiftWith<int_least16_t, std::u8string>);
        REQUIRE(!cortex::RightBitShiftWith<int_least16_t, std::u16string>);
        REQUIRE(!cortex::RightBitShiftWith<int_least16_t, std::u32string>);

        // int_fast16_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::RightBitShiftWith<int_least16_t, std::wstring>);
        REQUIRE(!cortex::RightBitShiftWith<int_least16_t, std::wstring_view>);

        // int_fast16_t with Charaters
        REQUIRE(cortex::RightBitShiftWith<int_least16_t, char>);
        REQUIRE(cortex::RightBitShiftWith<int_least16_t, u_char>);
        REQUIRE(cortex::RightBitShiftWith<int_least16_t, wchar_t>);

        // int_fast16_t with Bit Specific Characters
        REQUIRE(cortex::RightBitShiftWith<int_least16_t, char8_t>);
        REQUIRE(cortex::RightBitShiftWith<int_least16_t, char16_t>);
        REQUIRE(cortex::RightBitShiftWith<int_least16_t, char32_t>);

        // int_fast16_t with Bit Specific Integers
        REQUIRE(cortex::RightBitShiftWith<int_least16_t, int8_t>);
        REQUIRE(cortex::RightBitShiftWith<int_least16_t, int16_t>);
        REQUIRE(cortex::RightBitShiftWith<int_least16_t, int32_t>);
        REQUIRE(cortex::RightBitShiftWith<int_least16_t, int64_t>);

        // int_fast16_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::RightBitShiftWith<int_least16_t, uint8_t>);
        REQUIRE(cortex::RightBitShiftWith<int_least16_t, uint16_t>);
        REQUIRE(cortex::RightBitShiftWith<int_least16_t, uint32_t>);
        REQUIRE(cortex::RightBitShiftWith<int_least16_t, uint64_t>);

        // int_fast16_t with Bit Specific Least Integers
        REQUIRE(cortex::RightBitShiftWith<int_least16_t, int_least8_t>);
        REQUIRE(cortex::RightBitShiftWith<int_least16_t, int_least16_t>);
        REQUIRE(cortex::RightBitShiftWith<int_least16_t, int_least32_t>);
        REQUIRE(cortex::RightBitShiftWith<int_least16_t, int_least64_t>);
    }

    SECTION("int_least32_t with _")
    {
        // int32 with Signed Integers
        REQUIRE(cortex::RightBitShiftWith<int_least32_t, int>);
        REQUIRE(cortex::RightBitShiftWith<int_least32_t, short>);
        REQUIRE(cortex::RightBitShiftWith<int_least32_t, long>);
        REQUIRE(cortex::RightBitShiftWith<int_least32_t, long long>);

        // int32 with Unsigned Integers
        REQUIRE(cortex::RightBitShiftWith<int_least32_t, unsigned>);
        REQUIRE(cortex::RightBitShiftWith<int_least32_t, unsigned short>);
        REQUIRE(cortex::RightBitShiftWith<int_least32_t, u_short>);
        REQUIRE(cortex::RightBitShiftWith<int_least32_t, unsigned long>);
        REQUIRE(cortex::RightBitShiftWith<int_least32_t, unsigned long long>);
        
        // int32 with Floating Point and Doubles
        REQUIRE(!cortex::RightBitShiftWith<int_least32_t, float>);
        REQUIRE(!cortex::RightBitShiftWith<int_least32_t, double>);
        REQUIRE(!cortex::RightBitShiftWith<int_least32_t, long double>);

        // int32 with std::strings and std::string_view
        REQUIRE(!cortex::RightBitShiftWith<int_least32_t, std::string>);
        REQUIRE(!cortex::RightBitShiftWith<int_least32_t, std::string_view>);
        REQUIRE(!cortex::RightBitShiftWith<int_least32_t, std::u8string>);
        REQUIRE(!cortex::RightBitShiftWith<int_least32_t, std::u16string>);
        REQUIRE(!cortex::RightBitShiftWith<int_least32_t, std::u32string>);

        // int32 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::RightBitShiftWith<int_least32_t, std::wstring>);
        REQUIRE(!cortex::RightBitShiftWith<int_least32_t, std::wstring_view>);

        // int_fast32_t with Charaters
        REQUIRE(cortex::RightBitShiftWith<int_least32_t, char>);
        REQUIRE(cortex::RightBitShiftWith<int_least32_t, u_char>);
        REQUIRE(cortex::RightBitShiftWith<int_least32_t, wchar_t>);

        // int_fast32_t with Bit Specific Characters
        REQUIRE(cortex::RightBitShiftWith<int_least32_t, char8_t>);
        REQUIRE(cortex::RightBitShiftWith<int_least32_t, char16_t>);
        REQUIRE(cortex::RightBitShiftWith<int_least32_t, char32_t>);

        // int_fast32_t with Bit Specific Integers
        REQUIRE(cortex::RightBitShiftWith<int_least32_t, int8_t>);
        REQUIRE(cortex::RightBitShiftWith<int_least32_t, int16_t>);
        REQUIRE(cortex::RightBitShiftWith<int_least32_t, int32_t>);
        REQUIRE(cortex::RightBitShiftWith<int_least32_t, int64_t>);

        // int_fast32_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::RightBitShiftWith<int_least32_t, uint8_t>);
        REQUIRE(cortex::RightBitShiftWith<int_least32_t, uint16_t>);
        REQUIRE(cortex::RightBitShiftWith<int_least32_t, uint32_t>);
        REQUIRE(cortex::RightBitShiftWith<int_least32_t, uint64_t>);

        // int_fast32_t with Bit Specific Least Integers
        REQUIRE(cortex::RightBitShiftWith<int_least32_t, int_least8_t>);
        REQUIRE(cortex::RightBitShiftWith<int_least32_t, int_least16_t>);
        REQUIRE(cortex::RightBitShiftWith<int_least32_t, int_least32_t>);
        REQUIRE(cortex::RightBitShiftWith<int_least32_t, int_least64_t>);
    }

    SECTION("int_least64_t with _")
    {
        // int64 with Signed Integers
        REQUIRE(cortex::RightBitShiftWith<int_least64_t, int>);
        REQUIRE(cortex::RightBitShiftWith<int_least64_t, short>);
        REQUIRE(cortex::RightBitShiftWith<int_least64_t, long>);
        REQUIRE(cortex::RightBitShiftWith<int_least64_t, long long>);

        // int64 with Unsigned Integers
        REQUIRE(cortex::RightBitShiftWith<int_least64_t, unsigned>);
        REQUIRE(cortex::RightBitShiftWith<int_least64_t, unsigned short>);
        REQUIRE(cortex::RightBitShiftWith<int_least64_t, u_short>);
        REQUIRE(cortex::RightBitShiftWith<int_least64_t, unsigned long>);
        REQUIRE(cortex::RightBitShiftWith<int_least64_t, unsigned long long>);
        
        // int64 with Floating Point and Doubles
        REQUIRE(!cortex::RightBitShiftWith<int_least64_t, float>);
        REQUIRE(!cortex::RightBitShiftWith<int_least64_t, double>);
        REQUIRE(!cortex::RightBitShiftWith<int_least64_t, long double>);

        // int64 with std::strings and std::string_view
        REQUIRE(!cortex::RightBitShiftWith<int_least64_t, std::string>);
        REQUIRE(!cortex::RightBitShiftWith<int_least64_t, std::string_view>);
        REQUIRE(!cortex::RightBitShiftWith<int_least64_t, std::u8string>);
        REQUIRE(!cortex::RightBitShiftWith<int_least64_t, std::u16string>);
        REQUIRE(!cortex::RightBitShiftWith<int_least64_t, std::u32string>);

        // int64 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::RightBitShiftWith<int_least64_t, std::wstring>);
        REQUIRE(!cortex::RightBitShiftWith<int_least64_t, std::wstring_view>);

        // int_fast64_t with Charaters
        REQUIRE(cortex::RightBitShiftWith<int_least64_t, char>);
        REQUIRE(cortex::RightBitShiftWith<int_least64_t, u_char>);
        REQUIRE(cortex::RightBitShiftWith<int_least64_t, wchar_t>);

        // int_fast64_t with Bit Specific Characters
        REQUIRE(cortex::RightBitShiftWith<int_least64_t, char8_t>);
        REQUIRE(cortex::RightBitShiftWith<int_least64_t, char16_t>);
        REQUIRE(cortex::RightBitShiftWith<int_least64_t, char32_t>);

        // int_fast64_t with Bit Specific Integers
        REQUIRE(cortex::RightBitShiftWith<int_least64_t, int8_t>);
        REQUIRE(cortex::RightBitShiftWith<int_least64_t, int16_t>);
        REQUIRE(cortex::RightBitShiftWith<int_least64_t, int32_t>);
        REQUIRE(cortex::RightBitShiftWith<int_least64_t, int64_t>);

        // int_fast64_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::RightBitShiftWith<int_least64_t, uint8_t>);
        REQUIRE(cortex::RightBitShiftWith<int_least64_t, uint16_t>);
        REQUIRE(cortex::RightBitShiftWith<int_least64_t, uint32_t>);
        REQUIRE(cortex::RightBitShiftWith<int_least64_t, uint64_t>);

        // int_fast64_t with Bit Specific Least Integers
        REQUIRE(cortex::RightBitShiftWith<int_least64_t, int_least8_t>);
        REQUIRE(cortex::RightBitShiftWith<int_least64_t, int_least16_t>);
        REQUIRE(cortex::RightBitShiftWith<int_least64_t, int_least32_t>);
        REQUIRE(cortex::RightBitShiftWith<int_least64_t, int_least64_t>);
    }
}