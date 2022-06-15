#include <catch2/catch.hpp>
#include <concepts.hpp>

TEST_CASE("DivisibleWith : Signed Integers")
{
    SECTION("Int with _")
    {
        // Int with Signed Integers
        REQUIRE(cortex::DivisibleWith<int, int>);
        REQUIRE(cortex::DivisibleWith<int, short>);
        REQUIRE(cortex::DivisibleWith<int, long>);
        REQUIRE(cortex::DivisibleWith<int, long long>);

        // Int with Unsigned Integers
        REQUIRE(cortex::DivisibleWith<int, unsigned>);
        REQUIRE(cortex::DivisibleWith<int, unsigned short>);
        REQUIRE(cortex::DivisibleWith<int, u_short>);
        REQUIRE(cortex::DivisibleWith<int, unsigned long>);
        REQUIRE(cortex::DivisibleWith<int, unsigned long long>);
        
        // Integers with Floating Point and Doubles
        REQUIRE(cortex::DivisibleWith<int, float>);
        REQUIRE(cortex::DivisibleWith<int, double>);
        REQUIRE(cortex::DivisibleWith<int, long double>);

        // Integers with std::strings and std::string_view
        REQUIRE(!cortex::DivisibleWith<int, std::string>);
        REQUIRE(!cortex::DivisibleWith<int, std::string_view>);
        REQUIRE(!cortex::DivisibleWith<int, std::u8string>);
        REQUIRE(!cortex::DivisibleWith<int, std::u16string>);
        REQUIRE(!cortex::DivisibleWith<int, std::u32string>);

        // Integers with std::wstrings and std::wstring_view
        REQUIRE(!cortex::DivisibleWith<int, std::wstring>);
        REQUIRE(!cortex::DivisibleWith<int, std::wstring_view>);

        // Integers with Charaters
        REQUIRE(cortex::DivisibleWith<int, char>);
        REQUIRE(cortex::DivisibleWith<int, u_char>);
        REQUIRE(cortex::DivisibleWith<int, wchar_t>);

        // Integers with Bit Specific Characters
        REQUIRE(cortex::DivisibleWith<int, char8_t>);
        REQUIRE(cortex::DivisibleWith<int, char16_t>);
        REQUIRE(cortex::DivisibleWith<int, char32_t>);

        // Integers with Bit Specific Integers
        REQUIRE(cortex::DivisibleWith<int, int8_t>);
        REQUIRE(cortex::DivisibleWith<int, int16_t>);
        REQUIRE(cortex::DivisibleWith<int, int32_t>);
        REQUIRE(cortex::DivisibleWith<int, int64_t>);

        // Integers with Bit Specific Unsigned Integers
        REQUIRE(cortex::DivisibleWith<int, uint8_t>);
        REQUIRE(cortex::DivisibleWith<int, uint16_t>);
        REQUIRE(cortex::DivisibleWith<int, uint32_t>);
        REQUIRE(cortex::DivisibleWith<int, uint64_t>);

        // Integers with Bit Specific Least Integers
        REQUIRE(cortex::DivisibleWith<int, int_least8_t>);
        REQUIRE(cortex::DivisibleWith<int, int_least16_t>);
        REQUIRE(cortex::DivisibleWith<int, int_least32_t>);
        REQUIRE(cortex::DivisibleWith<int, int_least64_t>);
    }

    SECTION("Short with _")
    {
        // Short with Signed Integers
        REQUIRE(cortex::DivisibleWith<short, int>);
        REQUIRE(cortex::DivisibleWith<short, short>);
        REQUIRE(cortex::DivisibleWith<short, long>);
        REQUIRE(cortex::DivisibleWith<short, long long>);

        // Short with Unsigned Integers
        REQUIRE(cortex::DivisibleWith<short, unsigned>);
        REQUIRE(cortex::DivisibleWith<short, unsigned short>);
        REQUIRE(cortex::DivisibleWith<short, u_short>);
        REQUIRE(cortex::DivisibleWith<short, unsigned long>);
        REQUIRE(cortex::DivisibleWith<short, unsigned long long>);
        
        // Short with Floating Point and Doubles
        REQUIRE(cortex::DivisibleWith<short, float>);
        REQUIRE(cortex::DivisibleWith<short, double>);
        REQUIRE(cortex::DivisibleWith<short, long double>);

        // Short with std::strings and std::string_view
        REQUIRE(!cortex::DivisibleWith<short, std::string>);
        REQUIRE(!cortex::DivisibleWith<short, std::string_view>);
        REQUIRE(!cortex::DivisibleWith<short, std::u8string>);
        REQUIRE(!cortex::DivisibleWith<short, std::u16string>);
        REQUIRE(!cortex::DivisibleWith<short, std::u32string>);

        // Short with std::wstrings and std::wstring_view
        REQUIRE(!cortex::DivisibleWith<short, std::wstring>);
        REQUIRE(!cortex::DivisibleWith<short, std::wstring_view>);

        // Short with Charaters
        REQUIRE(cortex::DivisibleWith<short, char>);
        REQUIRE(cortex::DivisibleWith<short, u_char>);
        REQUIRE(cortex::DivisibleWith<short, wchar_t>);

        // Short with Bit Specific Characters
        REQUIRE(cortex::DivisibleWith<short, char8_t>);
        REQUIRE(cortex::DivisibleWith<short, char16_t>);
        REQUIRE(cortex::DivisibleWith<short, char32_t>);

        // Short with Bit Specific Short
        REQUIRE(cortex::DivisibleWith<short, int8_t>);
        REQUIRE(cortex::DivisibleWith<short, int16_t>);
        REQUIRE(cortex::DivisibleWith<short, int32_t>);
        REQUIRE(cortex::DivisibleWith<short, int64_t>);

        // Short with Bit Specific Unsigned Short
        REQUIRE(cortex::DivisibleWith<short, uint8_t>);
        REQUIRE(cortex::DivisibleWith<short, uint16_t>);
        REQUIRE(cortex::DivisibleWith<short, uint32_t>);
        REQUIRE(cortex::DivisibleWith<short, uint64_t>);

        // Short with Bit Specific Least Integers
        REQUIRE(cortex::DivisibleWith<short, int_least8_t>);
        REQUIRE(cortex::DivisibleWith<short, int_least16_t>);
        REQUIRE(cortex::DivisibleWith<short, int_least32_t>);
        REQUIRE(cortex::DivisibleWith<short, int_least64_t>);
    }

    SECTION("Long with _")
    {
        // Long with Signed Integers
        REQUIRE(cortex::DivisibleWith<long, int>);
        REQUIRE(cortex::DivisibleWith<long, short>);
        REQUIRE(cortex::DivisibleWith<long, long>);
        REQUIRE(cortex::DivisibleWith<long, long long>);

        // Long with Unsigned Integers
        REQUIRE(cortex::DivisibleWith<long, unsigned>);
        REQUIRE(cortex::DivisibleWith<long, unsigned short>);
        REQUIRE(cortex::DivisibleWith<long, u_short>);
        REQUIRE(cortex::DivisibleWith<long, unsigned long>);
        REQUIRE(cortex::DivisibleWith<long, unsigned long long>);
        
        // Long with Floating Point and Doubles
        REQUIRE(cortex::DivisibleWith<long, float>);
        REQUIRE(cortex::DivisibleWith<long, double>);
        REQUIRE(cortex::DivisibleWith<long, long double>);

        // Long with std::strings and std::string_view
        REQUIRE(!cortex::DivisibleWith<long, std::string>);
        REQUIRE(!cortex::DivisibleWith<long, std::string_view>);
        REQUIRE(!cortex::DivisibleWith<long, std::u8string>);
        REQUIRE(!cortex::DivisibleWith<long, std::u16string>);
        REQUIRE(!cortex::DivisibleWith<long, std::u32string>);

        // Long with std::wstrings and std::wstring_view
        REQUIRE(!cortex::DivisibleWith<long, std::wstring>);
        REQUIRE(!cortex::DivisibleWith<long, std::wstring_view>);

        // Long with Charaters
        REQUIRE(cortex::DivisibleWith<long, char>);
        REQUIRE(cortex::DivisibleWith<long, u_char>);
        REQUIRE(cortex::DivisibleWith<long, wchar_t>);

        // Long with Bit Specific Characters
        REQUIRE(cortex::DivisibleWith<long, char8_t>);
        REQUIRE(cortex::DivisibleWith<long, char16_t>);
        REQUIRE(cortex::DivisibleWith<long, char32_t>);

        // Long with Bit Specific Long
        REQUIRE(cortex::DivisibleWith<long, int8_t>);
        REQUIRE(cortex::DivisibleWith<long, int16_t>);
        REQUIRE(cortex::DivisibleWith<long, int32_t>);
        REQUIRE(cortex::DivisibleWith<long, int64_t>);

        // Long with Bit Specific Unsigned Long
        REQUIRE(cortex::DivisibleWith<long, uint8_t>);
        REQUIRE(cortex::DivisibleWith<long, uint16_t>);
        REQUIRE(cortex::DivisibleWith<long, uint32_t>);
        REQUIRE(cortex::DivisibleWith<long, uint64_t>);

        // Long with Bit Specific Least Integers
        REQUIRE(cortex::DivisibleWith<long, int_least8_t>);
        REQUIRE(cortex::DivisibleWith<long, int_least16_t>);
        REQUIRE(cortex::DivisibleWith<long, int_least32_t>);
        REQUIRE(cortex::DivisibleWith<long, int_least64_t>);
    }

    SECTION("Long Long with _")
    {
        // Signed Integers
        REQUIRE(cortex::DivisibleWith<long long, int>);
        REQUIRE(cortex::DivisibleWith<long long, short>);
        REQUIRE(cortex::DivisibleWith<long long, long>);
        REQUIRE(cortex::DivisibleWith<long long, long long>);

        // Unsigned Integers
        REQUIRE(cortex::DivisibleWith<long long, unsigned>);
        REQUIRE(cortex::DivisibleWith<long long, unsigned short>);
        REQUIRE(cortex::DivisibleWith<long long, u_short>);
        REQUIRE(cortex::DivisibleWith<long long, unsigned long>);
        REQUIRE(cortex::DivisibleWith<long long, unsigned long long>);
        
        // Integers with Floating Point and Doubles
        REQUIRE(cortex::DivisibleWith<long long, float>);
        REQUIRE(cortex::DivisibleWith<long long, double>);
        REQUIRE(cortex::DivisibleWith<long long, long double>);

        // Integers with std::strings and std::string_view
        REQUIRE(!cortex::DivisibleWith<long long, std::string>);
        REQUIRE(!cortex::DivisibleWith<long long, std::string_view>);
        REQUIRE(!cortex::DivisibleWith<long long, std::u8string>);
        REQUIRE(!cortex::DivisibleWith<long long, std::u16string>);
        REQUIRE(!cortex::DivisibleWith<long long, std::u32string>);

        // Integers with std::wstrings and std::wstring_view
        REQUIRE(!cortex::DivisibleWith<long long, std::wstring>);
        REQUIRE(!cortex::DivisibleWith<long long, std::wstring_view>);

        // Integers with Charaters
        REQUIRE(cortex::DivisibleWith<long long, char>);
        REQUIRE(cortex::DivisibleWith<long long, u_char>);
        REQUIRE(cortex::DivisibleWith<long long, wchar_t>);

        // Integers with Bit Specific Characters
        REQUIRE(cortex::DivisibleWith<long long, char8_t>);
        REQUIRE(cortex::DivisibleWith<long long, char16_t>);
        REQUIRE(cortex::DivisibleWith<long long, char32_t>);

        // Integers with Bit Specific Integers
        REQUIRE(cortex::DivisibleWith<long long, int8_t>);
        REQUIRE(cortex::DivisibleWith<long long, int16_t>);
        REQUIRE(cortex::DivisibleWith<long long, int32_t>);
        REQUIRE(cortex::DivisibleWith<long long, int64_t>);

        // Integers with Bit Specific Unsigned Integers
        REQUIRE(cortex::DivisibleWith<long long, uint8_t>);
        REQUIRE(cortex::DivisibleWith<long long, uint16_t>);
        REQUIRE(cortex::DivisibleWith<long long, uint32_t>);
        REQUIRE(cortex::DivisibleWith<long long, uint64_t>);

        // Long Long with Bit Specific Least Integers
        REQUIRE(cortex::DivisibleWith<long long, int_least8_t>);
        REQUIRE(cortex::DivisibleWith<long long, int_least16_t>);
        REQUIRE(cortex::DivisibleWith<long long, int_least32_t>);
        REQUIRE(cortex::DivisibleWith<long long, int_least64_t>);
    }
}

TEST_CASE("DivisibleWith: Unsigned Integers")
{
    SECTION("Unsigned Int with _")
    {
        // Unsigned Integers with Signed Integers
        REQUIRE(cortex::DivisibleWith<unsigned int, int>);
        REQUIRE(cortex::DivisibleWith<unsigned int, short>);
        REQUIRE(cortex::DivisibleWith<unsigned int, long>);
        REQUIRE(cortex::DivisibleWith<unsigned int, long long>);

        // Unsigned Integers with Unsigned Integers
        REQUIRE(cortex::DivisibleWith<unsigned int, unsigned>);
        REQUIRE(cortex::DivisibleWith<unsigned int, unsigned short>);
        REQUIRE(cortex::DivisibleWith<unsigned int, u_short>);
        REQUIRE(cortex::DivisibleWith<unsigned int, unsigned long>);
        REQUIRE(cortex::DivisibleWith<unsigned int, unsigned long long>);
        
        // Unsigned Integers with Floating Point and Doubles
        REQUIRE(cortex::DivisibleWith<unsigned int, float>);
        REQUIRE(cortex::DivisibleWith<unsigned int, double>);
        REQUIRE(cortex::DivisibleWith<unsigned int, long double>);

        // Unsigned Integers with std::strings and std::string_view
        REQUIRE(!cortex::DivisibleWith<unsigned int, std::string>);
        REQUIRE(!cortex::DivisibleWith<unsigned int, std::string_view>);
        REQUIRE(!cortex::DivisibleWith<unsigned int, std::u8string>);
        REQUIRE(!cortex::DivisibleWith<unsigned int, std::u16string>);
        REQUIRE(!cortex::DivisibleWith<unsigned int, std::u32string>);

        // Unsigned Integers with std::wstrings and std::wstring_view
        REQUIRE(!cortex::DivisibleWith<unsigned long long, std::wstring>);
        REQUIRE(!cortex::DivisibleWith<unsigned long long, std::wstring_view>);

        // Unsigned Integers with Charaters
        REQUIRE(cortex::DivisibleWith<unsigned int, char>);
        REQUIRE(cortex::DivisibleWith<unsigned int, u_char>);
        REQUIRE(cortex::DivisibleWith<unsigned int, wchar_t>);

        // Unsigned Integers with Bit Specific Characters
        REQUIRE(cortex::DivisibleWith<unsigned int, char8_t>);
        REQUIRE(cortex::DivisibleWith<unsigned int, char16_t>);
        REQUIRE(cortex::DivisibleWith<unsigned int, char32_t>);

        // Unsigned Integers with Bit Specific Integers
        REQUIRE(cortex::DivisibleWith<unsigned int, int8_t>);
        REQUIRE(cortex::DivisibleWith<unsigned int, int16_t>);
        REQUIRE(cortex::DivisibleWith<unsigned int, int32_t>);
        REQUIRE(cortex::DivisibleWith<unsigned int, int64_t>);

        // Unsigned Integers with Bit Specific Unsigned Integers
        REQUIRE(cortex::DivisibleWith<unsigned int, uint8_t>);
        REQUIRE(cortex::DivisibleWith<unsigned int, uint16_t>);
        REQUIRE(cortex::DivisibleWith<unsigned int, uint32_t>);
        REQUIRE(cortex::DivisibleWith<unsigned int, uint64_t>);

        // Unsigned Integers with Bit Specific Least Integers
        REQUIRE(cortex::DivisibleWith<unsigned int, int_least8_t>);
        REQUIRE(cortex::DivisibleWith<unsigned int, int_least16_t>);
        REQUIRE(cortex::DivisibleWith<unsigned int, int_least32_t>);
        REQUIRE(cortex::DivisibleWith<unsigned int, int_least64_t>);
    }

    SECTION("Unsigned Short with _")
    {
        // Unsigned Short with Signed Integers
        REQUIRE(cortex::DivisibleWith<unsigned short, int>);
        REQUIRE(cortex::DivisibleWith<unsigned short, short>);
        REQUIRE(cortex::DivisibleWith<unsigned short, long>);
        REQUIRE(cortex::DivisibleWith<unsigned short, long long>);

        // Unsigned Short with Unsigned Integers
        REQUIRE(cortex::DivisibleWith<unsigned short, unsigned>);
        REQUIRE(cortex::DivisibleWith<unsigned short, unsigned short>);
        REQUIRE(cortex::DivisibleWith<unsigned short, u_short>);
        REQUIRE(cortex::DivisibleWith<unsigned short, unsigned long>);
        REQUIRE(cortex::DivisibleWith<unsigned short, unsigned long long>);
        
        // Unsigned Short with Floating Point and Doubles
        REQUIRE(cortex::DivisibleWith<unsigned short, float>);
        REQUIRE(cortex::DivisibleWith<unsigned short, double>);
        REQUIRE(cortex::DivisibleWith<unsigned short, long double>);

        // Unsigned Short with std::strings and std::string_view
        REQUIRE(!cortex::DivisibleWith<unsigned short, std::string>);
        REQUIRE(!cortex::DivisibleWith<unsigned short, std::string_view>);
        REQUIRE(!cortex::DivisibleWith<unsigned short, std::u8string>);
        REQUIRE(!cortex::DivisibleWith<unsigned short, std::u16string>);
        REQUIRE(!cortex::DivisibleWith<unsigned short, std::u32string>);

        // Unsigned Short with std::wstrings and std::wstring_view
        REQUIRE(!cortex::DivisibleWith<unsigned short, std::wstring>);
        REQUIRE(!cortex::DivisibleWith<unsigned short, std::wstring_view>);

        // Unsigned Short with Charaters
        REQUIRE(cortex::DivisibleWith<unsigned short, char>);
        REQUIRE(cortex::DivisibleWith<unsigned short, u_char>);
        REQUIRE(cortex::DivisibleWith<unsigned short, wchar_t>);

        // Unsigned Short with Bit Specific Characters
        REQUIRE(cortex::DivisibleWith<unsigned short, char8_t>);
        REQUIRE(cortex::DivisibleWith<unsigned short, char16_t>);
        REQUIRE(cortex::DivisibleWith<unsigned short, char32_t>);

        // Unsigned Short with Bit Specific Short
        REQUIRE(cortex::DivisibleWith<unsigned short, int8_t>);
        REQUIRE(cortex::DivisibleWith<unsigned short, int16_t>);
        REQUIRE(cortex::DivisibleWith<unsigned short, int32_t>);
        REQUIRE(cortex::DivisibleWith<unsigned short, int64_t>);

        // Unsigned Short with Bit Specific Unsigned Short
        REQUIRE(cortex::DivisibleWith<unsigned short, uint8_t>);
        REQUIRE(cortex::DivisibleWith<unsigned short, uint16_t>);
        REQUIRE(cortex::DivisibleWith<unsigned short, uint32_t>);
        REQUIRE(cortex::DivisibleWith<unsigned short, uint64_t>);

        // Unsigned Short with Bit Specific Least Integers
        REQUIRE(cortex::DivisibleWith<unsigned short, int_least8_t>);
        REQUIRE(cortex::DivisibleWith<unsigned short, int_least16_t>);
        REQUIRE(cortex::DivisibleWith<unsigned short, int_least32_t>);
        REQUIRE(cortex::DivisibleWith<unsigned short, int_least64_t>);
    }

    SECTION("u_short with _")
    {
        // u_short with Signed Integers
        REQUIRE(cortex::DivisibleWith<u_short, int>);
        REQUIRE(cortex::DivisibleWith<u_short, short>);
        REQUIRE(cortex::DivisibleWith<u_short, long>);
        REQUIRE(cortex::DivisibleWith<u_short, long long>);

        // u_short with Unsigned Integers
        REQUIRE(cortex::DivisibleWith<u_short, unsigned>);
        REQUIRE(cortex::DivisibleWith<u_short, unsigned short>);
        REQUIRE(cortex::DivisibleWith<u_short, u_short>);
        REQUIRE(cortex::DivisibleWith<u_short, unsigned long>);
        REQUIRE(cortex::DivisibleWith<u_short, unsigned long long>);
        
        // u_short with Floating Point and Doubles
        REQUIRE(cortex::DivisibleWith<u_short, float>);
        REQUIRE(cortex::DivisibleWith<u_short, double>);
        REQUIRE(cortex::DivisibleWith<u_short, long double>);

        // u_short with std::strings and std::string_view
        REQUIRE(!cortex::DivisibleWith<u_short, std::string>);
        REQUIRE(!cortex::DivisibleWith<u_short, std::string_view>);
        REQUIRE(!cortex::DivisibleWith<u_short, std::u8string>);
        REQUIRE(!cortex::DivisibleWith<u_short, std::u16string>);
        REQUIRE(!cortex::DivisibleWith<u_short, std::u32string>);

        // u_short with std::wstrings and std::wstring_view
        REQUIRE(!cortex::DivisibleWith<u_short, std::wstring>);
        REQUIRE(!cortex::DivisibleWith<u_short, std::wstring_view>);

        // u_short with Charaters
        REQUIRE(cortex::DivisibleWith<u_short, char>);
        REQUIRE(cortex::DivisibleWith<u_short, u_char>);
        REQUIRE(cortex::DivisibleWith<u_short, wchar_t>);

        // u_short with Bit Specific Characters
        REQUIRE(cortex::DivisibleWith<u_short, char8_t>);
        REQUIRE(cortex::DivisibleWith<u_short, char16_t>);
        REQUIRE(cortex::DivisibleWith<u_short, char32_t>);

        // u_short with Bit Specific Short
        REQUIRE(cortex::DivisibleWith<u_short, int8_t>);
        REQUIRE(cortex::DivisibleWith<u_short, int16_t>);
        REQUIRE(cortex::DivisibleWith<u_short, int32_t>);
        REQUIRE(cortex::DivisibleWith<u_short, int64_t>);

        // u_short with Bit Specific Unsigned Short
        REQUIRE(cortex::DivisibleWith<u_short, uint8_t>);
        REQUIRE(cortex::DivisibleWith<u_short, uint16_t>);
        REQUIRE(cortex::DivisibleWith<u_short, uint32_t>);
        REQUIRE(cortex::DivisibleWith<u_short, uint64_t>);

        // u_short with Bit Specific Least Integers
        REQUIRE(cortex::DivisibleWith<u_short, int_least8_t>);
        REQUIRE(cortex::DivisibleWith<u_short, int_least16_t>);
        REQUIRE(cortex::DivisibleWith<u_short, int_least32_t>);
        REQUIRE(cortex::DivisibleWith<u_short, int_least64_t>);
    }

    SECTION("Unsigned Long with _")
    {
        // Unsigned Long with Signed Integers
        REQUIRE(cortex::DivisibleWith<unsigned long, int>);
        REQUIRE(cortex::DivisibleWith<unsigned long, short>);
        REQUIRE(cortex::DivisibleWith<unsigned long, long>);
        REQUIRE(cortex::DivisibleWith<unsigned long, long long>);

        // Unsigned Long with Unsigned Integers
        REQUIRE(cortex::DivisibleWith<unsigned long, unsigned>);
        REQUIRE(cortex::DivisibleWith<unsigned long, unsigned short>);
        REQUIRE(cortex::DivisibleWith<unsigned long, u_short>);
        REQUIRE(cortex::DivisibleWith<unsigned long, unsigned long>);
        REQUIRE(cortex::DivisibleWith<unsigned long, unsigned long long>);
        
        // Unsigned Long with Floating Point and Doubles
        REQUIRE(cortex::DivisibleWith<unsigned long, float>);
        REQUIRE(cortex::DivisibleWith<unsigned long, double>);
        REQUIRE(cortex::DivisibleWith<unsigned long, long double>);

        // Unsigned Long with std::strings and std::string_view
        REQUIRE(!cortex::DivisibleWith<unsigned long, std::string>);
        REQUIRE(!cortex::DivisibleWith<unsigned long, std::string_view>);
        REQUIRE(!cortex::DivisibleWith<unsigned long, std::u8string>);
        REQUIRE(!cortex::DivisibleWith<unsigned long, std::u16string>);
        REQUIRE(!cortex::DivisibleWith<unsigned long, std::u32string>);

        // Unsigned Long with std::wstrings and std::wstring_view
        REQUIRE(!cortex::DivisibleWith<unsigned long, std::wstring>);
        REQUIRE(!cortex::DivisibleWith<unsigned long, std::wstring_view>);

        // Unsigned Long with Charaters
        REQUIRE(cortex::DivisibleWith<unsigned long, char>);
        REQUIRE(cortex::DivisibleWith<unsigned long, u_char>);
        REQUIRE(cortex::DivisibleWith<unsigned long, wchar_t>);

        // Unsigned Long with Bit Specific Characters
        REQUIRE(cortex::DivisibleWith<unsigned long, char8_t>);
        REQUIRE(cortex::DivisibleWith<unsigned long, char16_t>);
        REQUIRE(cortex::DivisibleWith<unsigned long, char32_t>);

        // Unsigned Long with Bit Specific Long
        REQUIRE(cortex::DivisibleWith<unsigned long, int8_t>);
        REQUIRE(cortex::DivisibleWith<unsigned long, int16_t>);
        REQUIRE(cortex::DivisibleWith<unsigned long, int32_t>);
        REQUIRE(cortex::DivisibleWith<unsigned long, int64_t>);

        // Unsigned Long with Bit Specific Unsigned Long
        REQUIRE(cortex::DivisibleWith<unsigned long, uint8_t>);
        REQUIRE(cortex::DivisibleWith<unsigned long, uint16_t>);
        REQUIRE(cortex::DivisibleWith<unsigned long, uint32_t>);
        REQUIRE(cortex::DivisibleWith<unsigned long, uint64_t>);

        // Unsigned Long with Bit Specific Least Integers
        REQUIRE(cortex::DivisibleWith<unsigned long, int_least8_t>);
        REQUIRE(cortex::DivisibleWith<unsigned long, int_least16_t>);
        REQUIRE(cortex::DivisibleWith<unsigned long, int_least32_t>);
        REQUIRE(cortex::DivisibleWith<unsigned long, int_least64_t>);
    }

    SECTION("Unsigned Long Long with _")
    {
        // Unsigned Long Long with Signed Integers
        REQUIRE(cortex::DivisibleWith<unsigned long long, int>);
        REQUIRE(cortex::DivisibleWith<unsigned long long, short>);
        REQUIRE(cortex::DivisibleWith<unsigned long long, long>);
        REQUIRE(cortex::DivisibleWith<unsigned long long, long long>);

        // Unsigned Long Long with Unsigned Integers
        REQUIRE(cortex::DivisibleWith<unsigned long long, unsigned>);
        REQUIRE(cortex::DivisibleWith<unsigned long long, unsigned short>);
        REQUIRE(cortex::DivisibleWith<unsigned long long, u_short>);
        REQUIRE(cortex::DivisibleWith<unsigned long long, unsigned long>);
        REQUIRE(cortex::DivisibleWith<unsigned long long, unsigned long long>);
        
        // Unsigned Long Long with Floating Point and Doubles
        REQUIRE(cortex::DivisibleWith<unsigned long long, float>);
        REQUIRE(cortex::DivisibleWith<unsigned long long, double>);
        REQUIRE(cortex::DivisibleWith<unsigned long long, long double>);

        // Unsigned Long Long with std::strings and std::string_view
        REQUIRE(!cortex::DivisibleWith<unsigned long long, std::string>);
        REQUIRE(!cortex::DivisibleWith<unsigned long long, std::string_view>);
        REQUIRE(!cortex::DivisibleWith<unsigned long long, std::u8string>);
        REQUIRE(!cortex::DivisibleWith<unsigned long long, std::u16string>);
        REQUIRE(!cortex::DivisibleWith<unsigned long long, std::u32string>);

        // Unsigned Long Long with std::wstrings and std::wstring_view
        REQUIRE(!cortex::DivisibleWith<unsigned long long, std::wstring>);
        REQUIRE(!cortex::DivisibleWith<unsigned long long, std::wstring_view>);

        // Unsigned Long Long with Charaters
        REQUIRE(cortex::DivisibleWith<unsigned long long, char>);
        REQUIRE(cortex::DivisibleWith<unsigned long long, u_char>);
        REQUIRE(cortex::DivisibleWith<unsigned long long, wchar_t>);

        // Unsigned Long Long with Bit Specific Characters
        REQUIRE(cortex::DivisibleWith<unsigned long long, char8_t>);
        REQUIRE(cortex::DivisibleWith<unsigned long long, char16_t>);
        REQUIRE(cortex::DivisibleWith<unsigned long long, char32_t>);

        // Unsigned Long Long with Bit Specific Long Long
        REQUIRE(cortex::DivisibleWith<unsigned long long, int8_t>);
        REQUIRE(cortex::DivisibleWith<unsigned long long, int16_t>);
        REQUIRE(cortex::DivisibleWith<unsigned long long, int32_t>);
        REQUIRE(cortex::DivisibleWith<unsigned long long, int64_t>);

        // Unsigned Long Long with Bit Specific Unsigned Long Long
        REQUIRE(cortex::DivisibleWith<unsigned long long, uint8_t>);
        REQUIRE(cortex::DivisibleWith<unsigned long long, uint16_t>);
        REQUIRE(cortex::DivisibleWith<unsigned long long, uint32_t>);
        REQUIRE(cortex::DivisibleWith<unsigned long long, uint64_t>);

        // Long Long with Bit Specific Least Long Long
        REQUIRE(cortex::DivisibleWith<unsigned long long, int_least8_t>);
        REQUIRE(cortex::DivisibleWith<unsigned long long, int_least16_t>);
        REQUIRE(cortex::DivisibleWith<unsigned long long, int_least32_t>);
        REQUIRE(cortex::DivisibleWith<unsigned long long, int_least64_t>);
    }
}

TEST_CASE("DivisibleWith : Floats & Doubles") 
{
    SECTION("Float with _")
    {
        // Floats with Signed Integers
        REQUIRE(cortex::DivisibleWith<float, int>);
        REQUIRE(cortex::DivisibleWith<float, short>);
        REQUIRE(cortex::DivisibleWith<float, long>);
        REQUIRE(cortex::DivisibleWith<float, long long>);

        // Floats with Unsigned Integers
        REQUIRE(cortex::DivisibleWith<float, unsigned>);
        REQUIRE(cortex::DivisibleWith<float, unsigned short>);
        REQUIRE(cortex::DivisibleWith<float, u_short>);
        REQUIRE(cortex::DivisibleWith<float, unsigned long>);
        REQUIRE(cortex::DivisibleWith<float, unsigned long long>);
        
        // Float with Floating Point and Doubles
        REQUIRE(cortex::DivisibleWith<float, float>);
        REQUIRE(cortex::DivisibleWith<float, double>);
        REQUIRE(cortex::DivisibleWith<float, long double>);

        // Float with std::strings and std::string_view
        REQUIRE(!cortex::DivisibleWith<float, std::string>);
        REQUIRE(!cortex::DivisibleWith<float, std::string_view>);
        REQUIRE(!cortex::DivisibleWith<float, std::u8string>);
        REQUIRE(!cortex::DivisibleWith<float, std::u16string>);
        REQUIRE(!cortex::DivisibleWith<float, std::u32string>);

        // Float with std::wstrings and std::wstring_view
        REQUIRE(!cortex::DivisibleWith<long long, std::wstring>);
        REQUIRE(!cortex::DivisibleWith<long long, std::wstring_view>);

        // Float with Charaters
        REQUIRE(cortex::DivisibleWith<float, char>);
        REQUIRE(cortex::DivisibleWith<float, u_char>);
        REQUIRE(cortex::DivisibleWith<float, wchar_t>);

        // Float with Bit Specific Characters
        REQUIRE(cortex::DivisibleWith<float, char8_t>);
        REQUIRE(cortex::DivisibleWith<float, char16_t>);
        REQUIRE(cortex::DivisibleWith<float, char32_t>);

        // Float with Bit Specific Integers
        REQUIRE(cortex::DivisibleWith<float, int8_t>);
        REQUIRE(cortex::DivisibleWith<float, int16_t>);
        REQUIRE(cortex::DivisibleWith<float, int32_t>);
        REQUIRE(cortex::DivisibleWith<float, int64_t>);

        // Float with Bit Specific Unsigned Integers
        REQUIRE(cortex::DivisibleWith<float, uint8_t>);
        REQUIRE(cortex::DivisibleWith<float, uint16_t>);
        REQUIRE(cortex::DivisibleWith<float, uint32_t>);
        REQUIRE(cortex::DivisibleWith<float, uint64_t>);

        // Float with Bit Specific Least Integers
        REQUIRE(cortex::DivisibleWith<float, int_least8_t>);
        REQUIRE(cortex::DivisibleWith<float, int_least16_t>);
        REQUIRE(cortex::DivisibleWith<float, int_least32_t>);
        REQUIRE(cortex::DivisibleWith<float, int_least64_t>);
    }

    SECTION("Double with _")
    {
        // Double with Signed Integers
        REQUIRE(cortex::DivisibleWith<double, int>);
        REQUIRE(cortex::DivisibleWith<double, short>);
        REQUIRE(cortex::DivisibleWith<double, long>);
        REQUIRE(cortex::DivisibleWith<double, long long>);

        // Double with Unsigned Integers
        REQUIRE(cortex::DivisibleWith<double, unsigned>);
        REQUIRE(cortex::DivisibleWith<double, unsigned short>);
        REQUIRE(cortex::DivisibleWith<double, u_short>);
        REQUIRE(cortex::DivisibleWith<double, unsigned long>);
        REQUIRE(cortex::DivisibleWith<double, unsigned long long>);
        
        // Double with Floating Point and Doubles
        REQUIRE(cortex::DivisibleWith<double, float>);
        REQUIRE(cortex::DivisibleWith<double, double>);
        REQUIRE(cortex::DivisibleWith<double, long double>);

        // Double with std::strings and std::string_view
        REQUIRE(!cortex::DivisibleWith<double, std::string>);
        REQUIRE(!cortex::DivisibleWith<double, std::string_view>);
        REQUIRE(!cortex::DivisibleWith<double, std::u8string>);
        REQUIRE(!cortex::DivisibleWith<double, std::u16string>);
        REQUIRE(!cortex::DivisibleWith<double, std::u32string>);

        // Double with std::wstrings and std::wstring_view
        REQUIRE(!cortex::DivisibleWith<double, std::wstring>);
        REQUIRE(!cortex::DivisibleWith<double, std::wstring_view>);

        // Double with Charaters
        REQUIRE(cortex::DivisibleWith<double, char>);
        REQUIRE(cortex::DivisibleWith<double, u_char>);
        REQUIRE(cortex::DivisibleWith<double, wchar_t>);

        // Double with Bit Specific Characters
        REQUIRE(cortex::DivisibleWith<double, char8_t>);
        REQUIRE(cortex::DivisibleWith<double, char16_t>);
        REQUIRE(cortex::DivisibleWith<double, char32_t>);

        // Double with Bit Specific Short
        REQUIRE(cortex::DivisibleWith<double, int8_t>);
        REQUIRE(cortex::DivisibleWith<double, int16_t>);
        REQUIRE(cortex::DivisibleWith<double, int32_t>);
        REQUIRE(cortex::DivisibleWith<double, int64_t>);

        // Double with Bit Specific Unsigned Short
        REQUIRE(cortex::DivisibleWith<double, uint8_t>);
        REQUIRE(cortex::DivisibleWith<double, uint16_t>);
        REQUIRE(cortex::DivisibleWith<double, uint32_t>);
        REQUIRE(cortex::DivisibleWith<double, uint64_t>);

        // Double with Bit Specific Least Integers
        REQUIRE(cortex::DivisibleWith<double, int_least8_t>);
        REQUIRE(cortex::DivisibleWith<double, int_least16_t>);
        REQUIRE(cortex::DivisibleWith<double, int_least32_t>);
        REQUIRE(cortex::DivisibleWith<double, int_least64_t>);
    }

    SECTION("Long Double with _")
    {
        // Long Double with Signed Integers
        REQUIRE(cortex::DivisibleWith<long double, int>);
        REQUIRE(cortex::DivisibleWith<long double, short>);
        REQUIRE(cortex::DivisibleWith<long double, long>);
        REQUIRE(cortex::DivisibleWith<long double, long long>);

        // Long Double with Unsigned Integers
        REQUIRE(cortex::DivisibleWith<long double, unsigned>);
        REQUIRE(cortex::DivisibleWith<long double, unsigned short>);
        REQUIRE(cortex::DivisibleWith<long double, u_short>);
        REQUIRE(cortex::DivisibleWith<long double, unsigned long>);
        REQUIRE(cortex::DivisibleWith<long double, unsigned long long>);
        
        // Long Double with Floating Point and Doubles
        REQUIRE(cortex::DivisibleWith<long double, float>);
        REQUIRE(cortex::DivisibleWith<long double, double>);
        REQUIRE(cortex::DivisibleWith<long double, long double>);

        // Long Double with std::strings and std::string_view
        REQUIRE(!cortex::DivisibleWith<long double, std::string>);
        REQUIRE(!cortex::DivisibleWith<long double, std::string_view>);
        REQUIRE(!cortex::DivisibleWith<long double, std::u8string>);
        REQUIRE(!cortex::DivisibleWith<long double, std::u16string>);
        REQUIRE(!cortex::DivisibleWith<long double, std::u32string>);

        // Long Double with std::wstrings and std::wstring_view
        REQUIRE(!cortex::DivisibleWith<long double, std::wstring>);
        REQUIRE(!cortex::DivisibleWith<long double, std::wstring_view>);

        // Long Double with Charaters
        REQUIRE(cortex::DivisibleWith<long double, char>);
        REQUIRE(cortex::DivisibleWith<long double, u_char>);
        REQUIRE(cortex::DivisibleWith<long double, wchar_t>);

        // Long Double with Bit Specific Characters
        REQUIRE(cortex::DivisibleWith<long double, char8_t>);
        REQUIRE(cortex::DivisibleWith<long double, char16_t>);
        REQUIRE(cortex::DivisibleWith<long double, char32_t>);

        // Long Double with Bit Specific Long
        REQUIRE(cortex::DivisibleWith<long double, int8_t>);
        REQUIRE(cortex::DivisibleWith<long double, int16_t>);
        REQUIRE(cortex::DivisibleWith<long double, int32_t>);
        REQUIRE(cortex::DivisibleWith<long double, int64_t>);

        // Long Double with Bit Specific Unsigned Long
        REQUIRE(cortex::DivisibleWith<long double, uint8_t>);
        REQUIRE(cortex::DivisibleWith<long double, uint16_t>);
        REQUIRE(cortex::DivisibleWith<long double, uint32_t>);
        REQUIRE(cortex::DivisibleWith<long double, uint64_t>);

        // Long Double with Bit Specific Least Integers
        REQUIRE(cortex::DivisibleWith<long double, int_least8_t>);
        REQUIRE(cortex::DivisibleWith<long double, int_least16_t>);
        REQUIRE(cortex::DivisibleWith<long double, int_least32_t>);
        REQUIRE(cortex::DivisibleWith<long double, int_least64_t>);
    }

}

TEST_CASE("Addable With : Bit Specific Signed Integers")
{
    SECTION("int8_t with _")
    {
        // int8_t with Signed Integers
        REQUIRE(cortex::DivisibleWith<int8_t, int>);
        REQUIRE(cortex::DivisibleWith<int8_t, short>);
        REQUIRE(cortex::DivisibleWith<int8_t, long>);
        REQUIRE(cortex::DivisibleWith<int8_t, long long>);

        // int8_t with Unsigned Integers
        REQUIRE(cortex::DivisibleWith<int8_t, unsigned>);
        REQUIRE(cortex::DivisibleWith<int8_t, unsigned short>);
        REQUIRE(cortex::DivisibleWith<int8_t, u_short>);
        REQUIRE(cortex::DivisibleWith<int8_t, unsigned long>);
        REQUIRE(cortex::DivisibleWith<int8_t, unsigned long long>);
        
        // int8_t with Floating Point and Doubles
        REQUIRE(cortex::DivisibleWith<int8_t, float>);
        REQUIRE(cortex::DivisibleWith<int8_t, double>);
        REQUIRE(cortex::DivisibleWith<int8_t, long double>);

        // int8_t with std::strings and std::string_view
        REQUIRE(!cortex::DivisibleWith<int8_t, std::string>);
        REQUIRE(!cortex::DivisibleWith<int8_t, std::string_view>);
        REQUIRE(!cortex::DivisibleWith<int8_t, std::u8string>);
        REQUIRE(!cortex::DivisibleWith<int8_t, std::u16string>);
        REQUIRE(!cortex::DivisibleWith<int8_t, std::u32string>);

        // int8_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::DivisibleWith<long long, std::wstring>);
        REQUIRE(!cortex::DivisibleWith<long long, std::wstring_view>);

        // int8_t with Charaters
        REQUIRE(cortex::DivisibleWith<int8_t, char>);
        REQUIRE(cortex::DivisibleWith<int8_t, u_char>);
        REQUIRE(cortex::DivisibleWith<int8_t, wchar_t>);

        // int8_t with Bit Specific Characters
        REQUIRE(cortex::DivisibleWith<int8_t, char8_t>);
        REQUIRE(cortex::DivisibleWith<int8_t, char16_t>);
        REQUIRE(cortex::DivisibleWith<int8_t, char32_t>);

        // int8_t with Bit Specific Integers
        REQUIRE(cortex::DivisibleWith<int8_t, int8_t>);
        REQUIRE(cortex::DivisibleWith<int8_t, int16_t>);
        REQUIRE(cortex::DivisibleWith<int8_t, int32_t>);
        REQUIRE(cortex::DivisibleWith<int8_t, int64_t>);

        // int8_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::DivisibleWith<int8_t, uint8_t>);
        REQUIRE(cortex::DivisibleWith<int8_t, uint16_t>);
        REQUIRE(cortex::DivisibleWith<int8_t, uint32_t>);
        REQUIRE(cortex::DivisibleWith<int8_t, uint64_t>);

        // int8_t with Bit Specific Least Integers
        REQUIRE(cortex::DivisibleWith<int8_t, int_least8_t>);
        REQUIRE(cortex::DivisibleWith<int8_t, int_least16_t>);
        REQUIRE(cortex::DivisibleWith<int8_t, int_least32_t>);
        REQUIRE(cortex::DivisibleWith<int8_t, int_least64_t>);
    }

    SECTION("int16_t with _")
    {
        // int16_t with Signed Integers
        REQUIRE(cortex::DivisibleWith<int16_t, int>);
        REQUIRE(cortex::DivisibleWith<int16_t, short>);
        REQUIRE(cortex::DivisibleWith<int16_t, long>);
        REQUIRE(cortex::DivisibleWith<int16_t, long long>);

        // int16_t with Unsigned Integers
        REQUIRE(cortex::DivisibleWith<int16_t, unsigned>);
        REQUIRE(cortex::DivisibleWith<int16_t, unsigned short>);
        REQUIRE(cortex::DivisibleWith<int16_t, u_short>);
        REQUIRE(cortex::DivisibleWith<int16_t, unsigned long>);
        REQUIRE(cortex::DivisibleWith<int16_t, unsigned long long>);
        
        // int16_t with Floating Point and Doubles
        REQUIRE(cortex::DivisibleWith<int16_t, float>);
        REQUIRE(cortex::DivisibleWith<int16_t, double>);
        REQUIRE(cortex::DivisibleWith<int16_t, long double>);

        // int16_t with std::strings and std::string_view
        REQUIRE(!cortex::DivisibleWith<int16_t, std::string>);
        REQUIRE(!cortex::DivisibleWith<int16_t, std::string_view>);
        REQUIRE(!cortex::DivisibleWith<int16_t, std::u8string>);
        REQUIRE(!cortex::DivisibleWith<int16_t, std::u16string>);
        REQUIRE(!cortex::DivisibleWith<int16_t, std::u32string>);

        // int16_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::DivisibleWith<int16_t, std::wstring>);
        REQUIRE(!cortex::DivisibleWith<int16_t, std::wstring_view>);

        // int16_t with Charaters
        REQUIRE(cortex::DivisibleWith<int16_t, char>);
        REQUIRE(cortex::DivisibleWith<int16_t, u_char>);
        REQUIRE(cortex::DivisibleWith<int16_t, wchar_t>);

        // int16_t with Bit Specific Characters
        REQUIRE(cortex::DivisibleWith<int16_t, char8_t>);
        REQUIRE(cortex::DivisibleWith<int16_t, char16_t>);
        REQUIRE(cortex::DivisibleWith<int16_t, char32_t>);

        // int16_t with Bit Specific Integers
        REQUIRE(cortex::DivisibleWith<int16_t, int8_t>);
        REQUIRE(cortex::DivisibleWith<int16_t, int16_t>);
        REQUIRE(cortex::DivisibleWith<int16_t, int32_t>);
        REQUIRE(cortex::DivisibleWith<int16_t, int64_t>);

        // int16_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::DivisibleWith<int16_t, uint8_t>);
        REQUIRE(cortex::DivisibleWith<int16_t, uint16_t>);
        REQUIRE(cortex::DivisibleWith<int16_t, uint32_t>);
        REQUIRE(cortex::DivisibleWith<int16_t, uint64_t>);

        // int16_t with Bit Specific Least Integers
        REQUIRE(cortex::DivisibleWith<int16_t, int_least8_t>);
        REQUIRE(cortex::DivisibleWith<int16_t, int_least16_t>);
        REQUIRE(cortex::DivisibleWith<int16_t, int_least32_t>);
        REQUIRE(cortex::DivisibleWith<int16_t, int_least64_t>);
    }

    SECTION("int32 with _")
    {
        // int32 with Signed Integers
        REQUIRE(cortex::DivisibleWith<int32_t, int>);
        REQUIRE(cortex::DivisibleWith<int32_t, short>);
        REQUIRE(cortex::DivisibleWith<int32_t, long>);
        REQUIRE(cortex::DivisibleWith<int32_t, long long>);

        // int32 with Unsigned Integers
        REQUIRE(cortex::DivisibleWith<int32_t, unsigned>);
        REQUIRE(cortex::DivisibleWith<int32_t, unsigned short>);
        REQUIRE(cortex::DivisibleWith<int32_t, u_short>);
        REQUIRE(cortex::DivisibleWith<int32_t, unsigned long>);
        REQUIRE(cortex::DivisibleWith<int32_t, unsigned long long>);
        
        // int32 with Floating Point and Doubles
        REQUIRE(cortex::DivisibleWith<int32_t, float>);
        REQUIRE(cortex::DivisibleWith<int32_t, double>);
        REQUIRE(cortex::DivisibleWith<int32_t, long double>);

        // int32 with std::strings and std::string_view
        REQUIRE(!cortex::DivisibleWith<int32_t, std::string>);
        REQUIRE(!cortex::DivisibleWith<int32_t, std::string_view>);
        REQUIRE(!cortex::DivisibleWith<int32_t, std::u8string>);
        REQUIRE(!cortex::DivisibleWith<int32_t, std::u16string>);
        REQUIRE(!cortex::DivisibleWith<int32_t, std::u32string>);

        // int32 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::DivisibleWith<int32_t, std::wstring>);
        REQUIRE(!cortex::DivisibleWith<int32_t, std::wstring_view>);

        // int32_t with Charaters
        REQUIRE(cortex::DivisibleWith<int32_t, char>);
        REQUIRE(cortex::DivisibleWith<int32_t, u_char>);
        REQUIRE(cortex::DivisibleWith<int32_t, wchar_t>);

        // int32_t with Bit Specific Characters
        REQUIRE(cortex::DivisibleWith<int32_t, char8_t>);
        REQUIRE(cortex::DivisibleWith<int32_t, char16_t>);
        REQUIRE(cortex::DivisibleWith<int32_t, char32_t>);

        // int32_t with Bit Specific Integers
        REQUIRE(cortex::DivisibleWith<int32_t, int8_t>);
        REQUIRE(cortex::DivisibleWith<int32_t, int16_t>);
        REQUIRE(cortex::DivisibleWith<int32_t, int32_t>);
        REQUIRE(cortex::DivisibleWith<int32_t, int64_t>);

        // int32_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::DivisibleWith<int32_t, uint8_t>);
        REQUIRE(cortex::DivisibleWith<int32_t, uint16_t>);
        REQUIRE(cortex::DivisibleWith<int32_t, uint32_t>);
        REQUIRE(cortex::DivisibleWith<int32_t, uint64_t>);

        // int32_t with Bit Specific Least Integers
        REQUIRE(cortex::DivisibleWith<int32_t, int_least8_t>);
        REQUIRE(cortex::DivisibleWith<int32_t, int_least16_t>);
        REQUIRE(cortex::DivisibleWith<int32_t, int_least32_t>);
        REQUIRE(cortex::DivisibleWith<int32_t, int_least64_t>);
    }

    SECTION("int64 with _")
    {
        // int64 with Signed Integers
        REQUIRE(cortex::DivisibleWith<int64_t, int>);
        REQUIRE(cortex::DivisibleWith<int64_t, short>);
        REQUIRE(cortex::DivisibleWith<int64_t, long>);
        REQUIRE(cortex::DivisibleWith<int64_t, long long>);

        // int64 with Unsigned Integers
        REQUIRE(cortex::DivisibleWith<int64_t, unsigned>);
        REQUIRE(cortex::DivisibleWith<int64_t, unsigned short>);
        REQUIRE(cortex::DivisibleWith<int64_t, u_short>);
        REQUIRE(cortex::DivisibleWith<int64_t, unsigned long>);
        REQUIRE(cortex::DivisibleWith<int64_t, unsigned long long>);
        
        // int64 with Floating Point and Doubles
        REQUIRE(cortex::DivisibleWith<int64_t, float>);
        REQUIRE(cortex::DivisibleWith<int64_t, double>);
        REQUIRE(cortex::DivisibleWith<int64_t, long double>);

        // int64 with std::strings and std::string_view
        REQUIRE(!cortex::DivisibleWith<int64_t, std::string>);
        REQUIRE(!cortex::DivisibleWith<int64_t, std::string_view>);
        REQUIRE(!cortex::DivisibleWith<int64_t, std::u8string>);
        REQUIRE(!cortex::DivisibleWith<int64_t, std::u16string>);
        REQUIRE(!cortex::DivisibleWith<int64_t, std::u32string>);

        // int64 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::DivisibleWith<int64_t, std::wstring>);
        REQUIRE(!cortex::DivisibleWith<int64_t, std::wstring_view>);

        // int64_t with Charaters
        REQUIRE(cortex::DivisibleWith<int64_t, char>);
        REQUIRE(cortex::DivisibleWith<int64_t, u_char>);
        REQUIRE(cortex::DivisibleWith<int64_t, wchar_t>);

        // int64_t with Bit Specific Characters
        REQUIRE(cortex::DivisibleWith<int64_t, char8_t>);
        REQUIRE(cortex::DivisibleWith<int64_t, char16_t>);
        REQUIRE(cortex::DivisibleWith<int64_t, char32_t>);

        // int64_t with Bit Specific Integers
        REQUIRE(cortex::DivisibleWith<int64_t, int8_t>);
        REQUIRE(cortex::DivisibleWith<int64_t, int16_t>);
        REQUIRE(cortex::DivisibleWith<int64_t, int32_t>);
        REQUIRE(cortex::DivisibleWith<int64_t, int64_t>);

        // int64_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::DivisibleWith<int64_t, uint8_t>);
        REQUIRE(cortex::DivisibleWith<int64_t, uint16_t>);
        REQUIRE(cortex::DivisibleWith<int64_t, uint32_t>);
        REQUIRE(cortex::DivisibleWith<int64_t, uint64_t>);

        // int64_t with Bit Specific Least Integers
        REQUIRE(cortex::DivisibleWith<int64_t, int_least8_t>);
        REQUIRE(cortex::DivisibleWith<int64_t, int_least16_t>);
        REQUIRE(cortex::DivisibleWith<int64_t, int_least32_t>);
        REQUIRE(cortex::DivisibleWith<int64_t, int_least64_t>);
}
}

TEST_CASE("Addable With : Bit Specific Unsigned Integers")
{
    SECTION("uint8_t with _")
    {
        // uint8_t with Signed Integers
        REQUIRE(cortex::DivisibleWith<uint8_t, int>);
        REQUIRE(cortex::DivisibleWith<uint8_t, short>);
        REQUIRE(cortex::DivisibleWith<uint8_t, long>);
        REQUIRE(cortex::DivisibleWith<uint8_t, long long>);

        // uint8_t with Unsigned Integers
        REQUIRE(cortex::DivisibleWith<uint8_t, unsigned>);
        REQUIRE(cortex::DivisibleWith<uint8_t, unsigned short>);
        REQUIRE(cortex::DivisibleWith<uint8_t, u_short>);
        REQUIRE(cortex::DivisibleWith<uint8_t, unsigned long>);
        REQUIRE(cortex::DivisibleWith<uint8_t, unsigned long long>);
        
        // uint8_t with Floating Point and Doubles
        REQUIRE(cortex::DivisibleWith<uint8_t, float>);
        REQUIRE(cortex::DivisibleWith<uint8_t, double>);
        REQUIRE(cortex::DivisibleWith<uint8_t, long double>);

        // uint8_t with std::strings and std::string_view
        REQUIRE(!cortex::DivisibleWith<uint8_t, std::string>);
        REQUIRE(!cortex::DivisibleWith<uint8_t, std::string_view>);
        REQUIRE(!cortex::DivisibleWith<uint8_t, std::u8string>);
        REQUIRE(!cortex::DivisibleWith<uint8_t, std::u16string>);
        REQUIRE(!cortex::DivisibleWith<uint8_t, std::u32string>);

        // uint8_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::DivisibleWith<long long, std::wstring>);
        REQUIRE(!cortex::DivisibleWith<long long, std::wstring_view>);

        // uint8_t with Charaters
        REQUIRE(cortex::DivisibleWith<uint8_t, char>);
        REQUIRE(cortex::DivisibleWith<uint8_t, u_char>);
        REQUIRE(cortex::DivisibleWith<uint8_t, wchar_t>);

        // uint8_t with Bit Specific Characters
        REQUIRE(cortex::DivisibleWith<uint8_t, char8_t>);
        REQUIRE(cortex::DivisibleWith<uint8_t, char16_t>);
        REQUIRE(cortex::DivisibleWith<uint8_t, char32_t>);

        // uint8_t with Bit Specific Integers
        REQUIRE(cortex::DivisibleWith<uint8_t, int8_t>);
        REQUIRE(cortex::DivisibleWith<uint8_t, int16_t>);
        REQUIRE(cortex::DivisibleWith<uint8_t, int32_t>);
        REQUIRE(cortex::DivisibleWith<uint8_t, int64_t>);

        // uint8_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::DivisibleWith<uint8_t, uint8_t>);
        REQUIRE(cortex::DivisibleWith<uint8_t, uint16_t>);
        REQUIRE(cortex::DivisibleWith<uint8_t, uint32_t>);
        REQUIRE(cortex::DivisibleWith<uint8_t, uint64_t>);

        // uint8_t with Bit Specific Least Integers
        REQUIRE(cortex::DivisibleWith<uint8_t, int_least8_t>);
        REQUIRE(cortex::DivisibleWith<uint8_t, int_least16_t>);
        REQUIRE(cortex::DivisibleWith<uint8_t, int_least32_t>);
        REQUIRE(cortex::DivisibleWith<uint8_t, int_least64_t>);
    }

    SECTION("uint16_t with _")
    {
        // uint16_t with Signed Integers
        REQUIRE(cortex::DivisibleWith<uint16_t, int>);
        REQUIRE(cortex::DivisibleWith<uint16_t, short>);
        REQUIRE(cortex::DivisibleWith<uint16_t, long>);
        REQUIRE(cortex::DivisibleWith<uint16_t, long long>);

        // uint16_t with Unsigned Integers
        REQUIRE(cortex::DivisibleWith<uint16_t, unsigned>);
        REQUIRE(cortex::DivisibleWith<uint16_t, unsigned short>);
        REQUIRE(cortex::DivisibleWith<uint16_t, u_short>);
        REQUIRE(cortex::DivisibleWith<uint16_t, unsigned long>);
        REQUIRE(cortex::DivisibleWith<uint16_t, unsigned long long>);
        
        // uint16_t with Floating Point and Doubles
        REQUIRE(cortex::DivisibleWith<uint16_t, float>);
        REQUIRE(cortex::DivisibleWith<uint16_t, double>);
        REQUIRE(cortex::DivisibleWith<uint16_t, long double>);

        // uint16_t with std::strings and std::string_view
        REQUIRE(!cortex::DivisibleWith<uint16_t, std::string>);
        REQUIRE(!cortex::DivisibleWith<uint16_t, std::string_view>);
        REQUIRE(!cortex::DivisibleWith<uint16_t, std::u8string>);
        REQUIRE(!cortex::DivisibleWith<uint16_t, std::u16string>);
        REQUIRE(!cortex::DivisibleWith<uint16_t, std::u32string>);

        // uint16_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::DivisibleWith<uint16_t, std::wstring>);
        REQUIRE(!cortex::DivisibleWith<uint16_t, std::wstring_view>);

        // uint16_t with Charaters
        REQUIRE(cortex::DivisibleWith<uint16_t, char>);
        REQUIRE(cortex::DivisibleWith<uint16_t, u_char>);
        REQUIRE(cortex::DivisibleWith<uint16_t, wchar_t>);

        // uint16_t with Bit Specific Characters
        REQUIRE(cortex::DivisibleWith<uint16_t, char8_t>);
        REQUIRE(cortex::DivisibleWith<uint16_t, char16_t>);
        REQUIRE(cortex::DivisibleWith<uint16_t, char32_t>);

        // uint16_t with Bit Specific Integers
        REQUIRE(cortex::DivisibleWith<uint16_t, int8_t>);
        REQUIRE(cortex::DivisibleWith<uint16_t, int16_t>);
        REQUIRE(cortex::DivisibleWith<uint16_t, int32_t>);
        REQUIRE(cortex::DivisibleWith<uint16_t, int64_t>);

        // uint16_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::DivisibleWith<uint16_t, uint8_t>);
        REQUIRE(cortex::DivisibleWith<uint16_t, uint16_t>);
        REQUIRE(cortex::DivisibleWith<uint16_t, uint32_t>);
        REQUIRE(cortex::DivisibleWith<uint16_t, uint64_t>);

        // uint16_t with Bit Specific Least Integers
        REQUIRE(cortex::DivisibleWith<uint16_t, int_least8_t>);
        REQUIRE(cortex::DivisibleWith<uint16_t, int_least16_t>);
        REQUIRE(cortex::DivisibleWith<uint16_t, int_least32_t>);
        REQUIRE(cortex::DivisibleWith<uint16_t, int_least64_t>);
    }

    SECTION("uint32_t with _")
    {
        // int32 with Signed Integers
        REQUIRE(cortex::DivisibleWith<uint32_t, int>);
        REQUIRE(cortex::DivisibleWith<uint32_t, short>);
        REQUIRE(cortex::DivisibleWith<uint32_t, long>);
        REQUIRE(cortex::DivisibleWith<uint32_t, long long>);

        // int32 with Unsigned Integers
        REQUIRE(cortex::DivisibleWith<uint32_t, unsigned>);
        REQUIRE(cortex::DivisibleWith<uint32_t, unsigned short>);
        REQUIRE(cortex::DivisibleWith<uint32_t, u_short>);
        REQUIRE(cortex::DivisibleWith<uint32_t, unsigned long>);
        REQUIRE(cortex::DivisibleWith<uint32_t, unsigned long long>);
        
        // int32 with Floating Point and Doubles
        REQUIRE(cortex::DivisibleWith<uint32_t, float>);
        REQUIRE(cortex::DivisibleWith<uint32_t, double>);
        REQUIRE(cortex::DivisibleWith<uint32_t, long double>);

        // int32 with std::strings and std::string_view
        REQUIRE(!cortex::DivisibleWith<uint32_t, std::string>);
        REQUIRE(!cortex::DivisibleWith<uint32_t, std::string_view>);
        REQUIRE(!cortex::DivisibleWith<uint32_t, std::u8string>);
        REQUIRE(!cortex::DivisibleWith<uint32_t, std::u16string>);
        REQUIRE(!cortex::DivisibleWith<uint32_t, std::u32string>);

        // int32 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::DivisibleWith<uint32_t, std::wstring>);
        REQUIRE(!cortex::DivisibleWith<uint32_t, std::wstring_view>);

        // uint32_t with Charaters
        REQUIRE(cortex::DivisibleWith<uint32_t, char>);
        REQUIRE(cortex::DivisibleWith<uint32_t, u_char>);
        REQUIRE(cortex::DivisibleWith<uint32_t, wchar_t>);

        // uint32_t with Bit Specific Characters
        REQUIRE(cortex::DivisibleWith<uint32_t, char8_t>);
        REQUIRE(cortex::DivisibleWith<uint32_t, char16_t>);
        REQUIRE(cortex::DivisibleWith<uint32_t, char32_t>);

        // uint32_t with Bit Specific Integers
        REQUIRE(cortex::DivisibleWith<uint32_t, int8_t>);
        REQUIRE(cortex::DivisibleWith<uint32_t, int16_t>);
        REQUIRE(cortex::DivisibleWith<uint32_t, int32_t>);
        REQUIRE(cortex::DivisibleWith<uint32_t, int64_t>);

        // uint32_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::DivisibleWith<uint32_t, uint8_t>);
        REQUIRE(cortex::DivisibleWith<uint32_t, uint16_t>);
        REQUIRE(cortex::DivisibleWith<uint32_t, uint32_t>);
        REQUIRE(cortex::DivisibleWith<uint32_t, uint64_t>);

        // uint32_t with Bit Specific Least Integers
        REQUIRE(cortex::DivisibleWith<uint32_t, int_least8_t>);
        REQUIRE(cortex::DivisibleWith<uint32_t, int_least16_t>);
        REQUIRE(cortex::DivisibleWith<uint32_t, int_least32_t>);
        REQUIRE(cortex::DivisibleWith<uint32_t, int_least64_t>);
    }

    SECTION("uint64_t with _")
    {
        // int64 with Signed Integers
        REQUIRE(cortex::DivisibleWith<uint64_t, int>);
        REQUIRE(cortex::DivisibleWith<uint64_t, short>);
        REQUIRE(cortex::DivisibleWith<uint64_t, long>);
        REQUIRE(cortex::DivisibleWith<uint64_t, long long>);

        // int64 with Unsigned Integers
        REQUIRE(cortex::DivisibleWith<uint64_t, unsigned>);
        REQUIRE(cortex::DivisibleWith<uint64_t, unsigned short>);
        REQUIRE(cortex::DivisibleWith<uint64_t, u_short>);
        REQUIRE(cortex::DivisibleWith<uint64_t, unsigned long>);
        REQUIRE(cortex::DivisibleWith<uint64_t, unsigned long long>);
        
        // int64 with Floating Point and Doubles
        REQUIRE(cortex::DivisibleWith<uint64_t, float>);
        REQUIRE(cortex::DivisibleWith<uint64_t, double>);
        REQUIRE(cortex::DivisibleWith<uint64_t, long double>);

        // int64 with std::strings and std::string_view
        REQUIRE(!cortex::DivisibleWith<uint64_t, std::string>);
        REQUIRE(!cortex::DivisibleWith<uint64_t, std::string_view>);
        REQUIRE(!cortex::DivisibleWith<uint64_t, std::u8string>);
        REQUIRE(!cortex::DivisibleWith<uint64_t, std::u16string>);
        REQUIRE(!cortex::DivisibleWith<uint64_t, std::u32string>);

        // int64 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::DivisibleWith<uint64_t, std::wstring>);
        REQUIRE(!cortex::DivisibleWith<uint64_t, std::wstring_view>);

        // uint64_t with Charaters
        REQUIRE(cortex::DivisibleWith<uint64_t, char>);
        REQUIRE(cortex::DivisibleWith<uint64_t, u_char>);
        REQUIRE(cortex::DivisibleWith<uint64_t, wchar_t>);

        // uint64_t with Bit Specific Characters
        REQUIRE(cortex::DivisibleWith<uint64_t, char8_t>);
        REQUIRE(cortex::DivisibleWith<uint64_t, char16_t>);
        REQUIRE(cortex::DivisibleWith<uint64_t, char32_t>);

        // uint64_t with Bit Specific Integers
        REQUIRE(cortex::DivisibleWith<uint64_t, int8_t>);
        REQUIRE(cortex::DivisibleWith<uint64_t, int16_t>);
        REQUIRE(cortex::DivisibleWith<uint64_t, int32_t>);
        REQUIRE(cortex::DivisibleWith<uint64_t, int64_t>);

        // uint64_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::DivisibleWith<uint64_t, uint8_t>);
        REQUIRE(cortex::DivisibleWith<uint64_t, uint16_t>);
        REQUIRE(cortex::DivisibleWith<uint64_t, uint32_t>);
        REQUIRE(cortex::DivisibleWith<uint64_t, uint64_t>);

        // uint64_t with Bit Specific Least Integers
        REQUIRE(cortex::DivisibleWith<uint64_t, int_least8_t>);
        REQUIRE(cortex::DivisibleWith<uint64_t, int_least16_t>);
        REQUIRE(cortex::DivisibleWith<uint64_t, int_least32_t>);
        REQUIRE(cortex::DivisibleWith<uint64_t, int_least64_t>);
    }
}

TEST_CASE("Addable With : std::size_t")
{
    SECTION("std::size_t with _")
    {
        // std::size_t with Signed Integers
        REQUIRE(cortex::DivisibleWith<std::size_t, int>);
        REQUIRE(cortex::DivisibleWith<std::size_t, short>);
        REQUIRE(cortex::DivisibleWith<std::size_t, long>);
        REQUIRE(cortex::DivisibleWith<std::size_t, long long>);

        // std::size_t with Unsigned Integers
        REQUIRE(cortex::DivisibleWith<std::size_t, unsigned>);
        REQUIRE(cortex::DivisibleWith<std::size_t, unsigned short>);
        REQUIRE(cortex::DivisibleWith<std::size_t, u_short>);
        REQUIRE(cortex::DivisibleWith<std::size_t, unsigned long>);
        REQUIRE(cortex::DivisibleWith<std::size_t, unsigned long long>);
        
        // std::size_t with Floating Point and Doubles
        REQUIRE(cortex::DivisibleWith<std::size_t, float>);
        REQUIRE(cortex::DivisibleWith<std::size_t, double>);
        REQUIRE(cortex::DivisibleWith<std::size_t, long double>);

        // std::size_t with std::strings and std::string_view
        REQUIRE(!cortex::DivisibleWith<std::size_t, std::string>);
        REQUIRE(!cortex::DivisibleWith<std::size_t, std::string_view>);
        REQUIRE(!cortex::DivisibleWith<std::size_t, std::u8string>);
        REQUIRE(!cortex::DivisibleWith<std::size_t, std::u16string>);
        REQUIRE(!cortex::DivisibleWith<std::size_t, std::u32string>);

        // std::size_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::DivisibleWith<long long, std::wstring>);
        REQUIRE(!cortex::DivisibleWith<long long, std::wstring_view>);

        // std::size_t with Charaters
        REQUIRE(cortex::DivisibleWith<std::size_t, char>);
        REQUIRE(cortex::DivisibleWith<std::size_t, u_char>);
        REQUIRE(cortex::DivisibleWith<std::size_t, wchar_t>);

        // std::size_t with Bit Specific Characters
        REQUIRE(cortex::DivisibleWith<std::size_t, char8_t>);
        REQUIRE(cortex::DivisibleWith<std::size_t, char16_t>);
        REQUIRE(cortex::DivisibleWith<std::size_t, char32_t>);

        // std::size_t with Bit Specific Integers
        REQUIRE(cortex::DivisibleWith<std::size_t, int8_t>);
        REQUIRE(cortex::DivisibleWith<std::size_t, int16_t>);
        REQUIRE(cortex::DivisibleWith<std::size_t, int32_t>);
        REQUIRE(cortex::DivisibleWith<std::size_t, int64_t>);

        // std::size_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::DivisibleWith<std::size_t, uint8_t>);
        REQUIRE(cortex::DivisibleWith<std::size_t, uint16_t>);
        REQUIRE(cortex::DivisibleWith<std::size_t, uint32_t>);
        REQUIRE(cortex::DivisibleWith<std::size_t, uint64_t>);

        // std::size_t with Bit Specific Least Integers
        REQUIRE(cortex::DivisibleWith<std::size_t, int_least8_t>);
        REQUIRE(cortex::DivisibleWith<std::size_t, int_least16_t>);
        REQUIRE(cortex::DivisibleWith<std::size_t, int_least32_t>);
        REQUIRE(cortex::DivisibleWith<std::size_t, int_least64_t>);
    }
}

TEST_CASE("DivisibleWith : Fast Integers")
{
    SECTION("int_fast8_t with _")
    {
        // int_fast8_t with Signed Integers
        REQUIRE(cortex::DivisibleWith<int_fast8_t, int>);
        REQUIRE(cortex::DivisibleWith<int_fast8_t, short>);
        REQUIRE(cortex::DivisibleWith<int_fast8_t, long>);
        REQUIRE(cortex::DivisibleWith<int_fast8_t, long long>);

        // int_fast8_t with Unsigned Integers
        REQUIRE(cortex::DivisibleWith<int_fast8_t, unsigned>);
        REQUIRE(cortex::DivisibleWith<int_fast8_t, unsigned short>);
        REQUIRE(cortex::DivisibleWith<int_fast8_t, u_short>);
        REQUIRE(cortex::DivisibleWith<int_fast8_t, unsigned long>);
        REQUIRE(cortex::DivisibleWith<int_fast8_t, unsigned long long>);
        
        // int_fast8_t with Floating Point and Doubles
        REQUIRE(cortex::DivisibleWith<int_fast8_t, float>);
        REQUIRE(cortex::DivisibleWith<int_fast8_t, double>);
        REQUIRE(cortex::DivisibleWith<int_fast8_t, long double>);

        // int_fast8_t with std::strings and std::string_view
        REQUIRE(!cortex::DivisibleWith<int_fast8_t, std::string>);
        REQUIRE(!cortex::DivisibleWith<int_fast8_t, std::string_view>);
        REQUIRE(!cortex::DivisibleWith<int_fast8_t, std::u8string>);
        REQUIRE(!cortex::DivisibleWith<int_fast8_t, std::u16string>);
        REQUIRE(!cortex::DivisibleWith<int_fast8_t, std::u32string>);

        // int_fast8_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::DivisibleWith<long long, std::wstring>);
        REQUIRE(!cortex::DivisibleWith<long long, std::wstring_view>);

        // int_fast8_t with Charaters
        REQUIRE(cortex::DivisibleWith<int_fast8_t, char>);
        REQUIRE(cortex::DivisibleWith<int_fast8_t, u_char>);
        REQUIRE(cortex::DivisibleWith<int_fast8_t, wchar_t>);

        // int_fast8_t with Bit Specific Characters
        REQUIRE(cortex::DivisibleWith<int_fast8_t, char8_t>);
        REQUIRE(cortex::DivisibleWith<int_fast8_t, char16_t>);
        REQUIRE(cortex::DivisibleWith<int_fast8_t, char32_t>);

        // int_fast8_t with Bit Specific Integers
        REQUIRE(cortex::DivisibleWith<int_fast8_t, int8_t>);
        REQUIRE(cortex::DivisibleWith<int_fast8_t, int16_t>);
        REQUIRE(cortex::DivisibleWith<int_fast8_t, int32_t>);
        REQUIRE(cortex::DivisibleWith<int_fast8_t, int64_t>);

        // int_fast8_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::DivisibleWith<int_fast8_t, uint8_t>);
        REQUIRE(cortex::DivisibleWith<int_fast8_t, uint16_t>);
        REQUIRE(cortex::DivisibleWith<int_fast8_t, uint32_t>);
        REQUIRE(cortex::DivisibleWith<int_fast8_t, uint64_t>);

        // int_fast8_t with Bit Specific Least Integers
        REQUIRE(cortex::DivisibleWith<int_fast8_t, int_least8_t>);
        REQUIRE(cortex::DivisibleWith<int_fast8_t, int_least16_t>);
        REQUIRE(cortex::DivisibleWith<int_fast8_t, int_least32_t>);
        REQUIRE(cortex::DivisibleWith<int_fast8_t, int_least64_t>);
    }

    SECTION("int_fast16_t with _")
    {
        // int_fast16_t with Signed Integers
        REQUIRE(cortex::DivisibleWith<int_fast16_t, int>);
        REQUIRE(cortex::DivisibleWith<int_fast16_t, short>);
        REQUIRE(cortex::DivisibleWith<int_fast16_t, long>);
        REQUIRE(cortex::DivisibleWith<int_fast16_t, long long>);

        // int_fast16_t with Unsigned Integers
        REQUIRE(cortex::DivisibleWith<int_fast16_t, unsigned>);
        REQUIRE(cortex::DivisibleWith<int_fast16_t, unsigned short>);
        REQUIRE(cortex::DivisibleWith<int_fast16_t, u_short>);
        REQUIRE(cortex::DivisibleWith<int_fast16_t, unsigned long>);
        REQUIRE(cortex::DivisibleWith<int_fast16_t, unsigned long long>);
        
        // int_fast16_t with Floating Point and Doubles
        REQUIRE(cortex::DivisibleWith<int_fast16_t, float>);
        REQUIRE(cortex::DivisibleWith<int_fast16_t, double>);
        REQUIRE(cortex::DivisibleWith<int_fast16_t, long double>);

        // int_fast16_t with std::strings and std::string_view
        REQUIRE(!cortex::DivisibleWith<int_fast16_t, std::string>);
        REQUIRE(!cortex::DivisibleWith<int_fast16_t, std::string_view>);
        REQUIRE(!cortex::DivisibleWith<int_fast16_t, std::u8string>);
        REQUIRE(!cortex::DivisibleWith<int_fast16_t, std::u16string>);
        REQUIRE(!cortex::DivisibleWith<int_fast16_t, std::u32string>);

        // int_fast16_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::DivisibleWith<int_fast16_t, std::wstring>);
        REQUIRE(!cortex::DivisibleWith<int_fast16_t, std::wstring_view>);

        // int_fast16_t with Charaters
        REQUIRE(cortex::DivisibleWith<int_fast16_t, char>);
        REQUIRE(cortex::DivisibleWith<int_fast16_t, u_char>);
        REQUIRE(cortex::DivisibleWith<int_fast16_t, wchar_t>);

        // int_fast16_t with Bit Specific Characters
        REQUIRE(cortex::DivisibleWith<int_fast16_t, char8_t>);
        REQUIRE(cortex::DivisibleWith<int_fast16_t, char16_t>);
        REQUIRE(cortex::DivisibleWith<int_fast16_t, char32_t>);

        // int_fast16_t with Bit Specific Integers
        REQUIRE(cortex::DivisibleWith<int_fast16_t, int8_t>);
        REQUIRE(cortex::DivisibleWith<int_fast16_t, int16_t>);
        REQUIRE(cortex::DivisibleWith<int_fast16_t, int32_t>);
        REQUIRE(cortex::DivisibleWith<int_fast16_t, int64_t>);

        // int_fast16_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::DivisibleWith<int_fast16_t, uint8_t>);
        REQUIRE(cortex::DivisibleWith<int_fast16_t, uint16_t>);
        REQUIRE(cortex::DivisibleWith<int_fast16_t, uint32_t>);
        REQUIRE(cortex::DivisibleWith<int_fast16_t, uint64_t>);

        // int_fast16_t with Bit Specific Least Integers
        REQUIRE(cortex::DivisibleWith<int_fast16_t, int_least8_t>);
        REQUIRE(cortex::DivisibleWith<int_fast16_t, int_least16_t>);
        REQUIRE(cortex::DivisibleWith<int_fast16_t, int_least32_t>);
        REQUIRE(cortex::DivisibleWith<int_fast16_t, int_least64_t>);
    }

    SECTION("int_fast32_t with _")
    {
        // int32 with Signed Integers
        REQUIRE(cortex::DivisibleWith<int_fast32_t, int>);
        REQUIRE(cortex::DivisibleWith<int_fast32_t, short>);
        REQUIRE(cortex::DivisibleWith<int_fast32_t, long>);
        REQUIRE(cortex::DivisibleWith<int_fast32_t, long long>);

        // int32 with Unsigned Integers
        REQUIRE(cortex::DivisibleWith<int_fast32_t, unsigned>);
        REQUIRE(cortex::DivisibleWith<int_fast32_t, unsigned short>);
        REQUIRE(cortex::DivisibleWith<int_fast32_t, u_short>);
        REQUIRE(cortex::DivisibleWith<int_fast32_t, unsigned long>);
        REQUIRE(cortex::DivisibleWith<int_fast32_t, unsigned long long>);
        
        // int32 with Floating Point and Doubles
        REQUIRE(cortex::DivisibleWith<int_fast32_t, float>);
        REQUIRE(cortex::DivisibleWith<int_fast32_t, double>);
        REQUIRE(cortex::DivisibleWith<int_fast32_t, long double>);

        // int32 with std::strings and std::string_view
        REQUIRE(!cortex::DivisibleWith<int_fast32_t, std::string>);
        REQUIRE(!cortex::DivisibleWith<int_fast32_t, std::string_view>);
        REQUIRE(!cortex::DivisibleWith<int_fast32_t, std::u8string>);
        REQUIRE(!cortex::DivisibleWith<int_fast32_t, std::u16string>);
        REQUIRE(!cortex::DivisibleWith<int_fast32_t, std::u32string>);

        // int32 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::DivisibleWith<int_fast32_t, std::wstring>);
        REQUIRE(!cortex::DivisibleWith<int_fast32_t, std::wstring_view>);

        // int_fast32_t with Charaters
        REQUIRE(cortex::DivisibleWith<int_fast32_t, char>);
        REQUIRE(cortex::DivisibleWith<int_fast32_t, u_char>);
        REQUIRE(cortex::DivisibleWith<int_fast32_t, wchar_t>);

        // int_fast32_t with Bit Specific Characters
        REQUIRE(cortex::DivisibleWith<int_fast32_t, char8_t>);
        REQUIRE(cortex::DivisibleWith<int_fast32_t, char16_t>);
        REQUIRE(cortex::DivisibleWith<int_fast32_t, char32_t>);

        // int_fast32_t with Bit Specific Integers
        REQUIRE(cortex::DivisibleWith<int_fast32_t, int8_t>);
        REQUIRE(cortex::DivisibleWith<int_fast32_t, int16_t>);
        REQUIRE(cortex::DivisibleWith<int_fast32_t, int32_t>);
        REQUIRE(cortex::DivisibleWith<int_fast32_t, int64_t>);

        // int_fast32_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::DivisibleWith<int_fast32_t, uint8_t>);
        REQUIRE(cortex::DivisibleWith<int_fast32_t, uint16_t>);
        REQUIRE(cortex::DivisibleWith<int_fast32_t, uint32_t>);
        REQUIRE(cortex::DivisibleWith<int_fast32_t, uint64_t>);

        // int_fast32_t with Bit Specific Least Integers
        REQUIRE(cortex::DivisibleWith<int_fast32_t, int_least8_t>);
        REQUIRE(cortex::DivisibleWith<int_fast32_t, int_least16_t>);
        REQUIRE(cortex::DivisibleWith<int_fast32_t, int_least32_t>);
        REQUIRE(cortex::DivisibleWith<int_fast32_t, int_least64_t>);
    }

    SECTION("int_fast64_t with _")
    {
        // int64 with Signed Integers
        REQUIRE(cortex::DivisibleWith<int_fast64_t, int>);
        REQUIRE(cortex::DivisibleWith<int_fast64_t, short>);
        REQUIRE(cortex::DivisibleWith<int_fast64_t, long>);
        REQUIRE(cortex::DivisibleWith<int_fast64_t, long long>);

        // int64 with Unsigned Integers
        REQUIRE(cortex::DivisibleWith<int_fast64_t, unsigned>);
        REQUIRE(cortex::DivisibleWith<int_fast64_t, unsigned short>);
        REQUIRE(cortex::DivisibleWith<int_fast64_t, u_short>);
        REQUIRE(cortex::DivisibleWith<int_fast64_t, unsigned long>);
        REQUIRE(cortex::DivisibleWith<int_fast64_t, unsigned long long>);
        
        // int64 with Floating Point and Doubles
        REQUIRE(cortex::DivisibleWith<int_fast64_t, float>);
        REQUIRE(cortex::DivisibleWith<int_fast64_t, double>);
        REQUIRE(cortex::DivisibleWith<int_fast64_t, long double>);

        // int64 with std::strings and std::string_view
        REQUIRE(!cortex::DivisibleWith<int_fast64_t, std::string>);
        REQUIRE(!cortex::DivisibleWith<int_fast64_t, std::string_view>);
        REQUIRE(!cortex::DivisibleWith<int_fast64_t, std::u8string>);
        REQUIRE(!cortex::DivisibleWith<int_fast64_t, std::u16string>);
        REQUIRE(!cortex::DivisibleWith<int_fast64_t, std::u32string>);

        // int64 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::DivisibleWith<int_fast64_t, std::wstring>);
        REQUIRE(!cortex::DivisibleWith<int_fast64_t, std::wstring_view>);

        // int_fast64_t with Charaters
        REQUIRE(cortex::DivisibleWith<int_fast64_t, char>);
        REQUIRE(cortex::DivisibleWith<int_fast64_t, u_char>);
        REQUIRE(cortex::DivisibleWith<int_fast64_t, wchar_t>);

        // int_fast64_t with Bit Specific Characters
        REQUIRE(cortex::DivisibleWith<int_fast64_t, char8_t>);
        REQUIRE(cortex::DivisibleWith<int_fast64_t, char16_t>);
        REQUIRE(cortex::DivisibleWith<int_fast64_t, char32_t>);

        // int_fast64_t with Bit Specific Integers
        REQUIRE(cortex::DivisibleWith<int_fast64_t, int8_t>);
        REQUIRE(cortex::DivisibleWith<int_fast64_t, int16_t>);
        REQUIRE(cortex::DivisibleWith<int_fast64_t, int32_t>);
        REQUIRE(cortex::DivisibleWith<int_fast64_t, int64_t>);

        // int_fast64_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::DivisibleWith<int_fast64_t, uint8_t>);
        REQUIRE(cortex::DivisibleWith<int_fast64_t, uint16_t>);
        REQUIRE(cortex::DivisibleWith<int_fast64_t, uint32_t>);
        REQUIRE(cortex::DivisibleWith<int_fast64_t, uint64_t>);

        // int_fast64_t with Bit Specific Least Integers
        REQUIRE(cortex::DivisibleWith<int_fast64_t, int_least8_t>);
        REQUIRE(cortex::DivisibleWith<int_fast64_t, int_least16_t>);
        REQUIRE(cortex::DivisibleWith<int_fast64_t, int_least32_t>);
        REQUIRE(cortex::DivisibleWith<int_fast64_t, int_least64_t>);
    }
}

TEST_CASE("DivisibleWith : Least Integers")
{
    SECTION("int_least8_t with _")
    {
        // int_fast8_t with Signed Integers
        REQUIRE(cortex::DivisibleWith<int_least8_t, int>);
        REQUIRE(cortex::DivisibleWith<int_least8_t, short>);
        REQUIRE(cortex::DivisibleWith<int_least8_t, long>);
        REQUIRE(cortex::DivisibleWith<int_least8_t, long long>);

        // int_fast8_t with Unsigned Integers
        REQUIRE(cortex::DivisibleWith<int_least8_t, unsigned>);
        REQUIRE(cortex::DivisibleWith<int_least8_t, unsigned short>);
        REQUIRE(cortex::DivisibleWith<int_least8_t, u_short>);
        REQUIRE(cortex::DivisibleWith<int_least8_t, unsigned long>);
        REQUIRE(cortex::DivisibleWith<int_least8_t, unsigned long long>);
        
        // int_fast8_t with Floating Point and Doubles
        REQUIRE(cortex::DivisibleWith<int_least8_t, float>);
        REQUIRE(cortex::DivisibleWith<int_least8_t, double>);
        REQUIRE(cortex::DivisibleWith<int_least8_t, long double>);

        // int_fast8_t with std::strings and std::string_view
        REQUIRE(!cortex::DivisibleWith<int_least8_t, std::string>);
        REQUIRE(!cortex::DivisibleWith<int_least8_t, std::string_view>);
        REQUIRE(!cortex::DivisibleWith<int_least8_t, std::u8string>);
        REQUIRE(!cortex::DivisibleWith<int_least8_t, std::u16string>);
        REQUIRE(!cortex::DivisibleWith<int_least8_t, std::u32string>);

        // int_fast8_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::DivisibleWith<long long, std::wstring>);
        REQUIRE(!cortex::DivisibleWith<long long, std::wstring_view>);

        // int_fast8_t with Charaters
        REQUIRE(cortex::DivisibleWith<int_least8_t, char>);
        REQUIRE(cortex::DivisibleWith<int_least8_t, u_char>);
        REQUIRE(cortex::DivisibleWith<int_least8_t, wchar_t>);

        // int_fast8_t with Bit Specific Characters
        REQUIRE(cortex::DivisibleWith<int_least8_t, char8_t>);
        REQUIRE(cortex::DivisibleWith<int_least8_t, char16_t>);
        REQUIRE(cortex::DivisibleWith<int_least8_t, char32_t>);

        // int_fast8_t with Bit Specific Integers
        REQUIRE(cortex::DivisibleWith<int_least8_t, int8_t>);
        REQUIRE(cortex::DivisibleWith<int_least8_t, int16_t>);
        REQUIRE(cortex::DivisibleWith<int_least8_t, int32_t>);
        REQUIRE(cortex::DivisibleWith<int_least8_t, int64_t>);

        // int_fast8_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::DivisibleWith<int_least8_t, uint8_t>);
        REQUIRE(cortex::DivisibleWith<int_least8_t, uint16_t>);
        REQUIRE(cortex::DivisibleWith<int_least8_t, uint32_t>);
        REQUIRE(cortex::DivisibleWith<int_least8_t, uint64_t>);

        // int_fast8_t with Bit Specific Least Integers
        REQUIRE(cortex::DivisibleWith<int_least8_t, int_least8_t>);
        REQUIRE(cortex::DivisibleWith<int_least8_t, int_least16_t>);
        REQUIRE(cortex::DivisibleWith<int_least8_t, int_least32_t>);
        REQUIRE(cortex::DivisibleWith<int_least8_t, int_least64_t>);
    }

    SECTION("int_least16_t with _")
    {
        // int_fast16_t with Signed Integers
        REQUIRE(cortex::DivisibleWith<int_least16_t, int>);
        REQUIRE(cortex::DivisibleWith<int_least16_t, short>);
        REQUIRE(cortex::DivisibleWith<int_least16_t, long>);
        REQUIRE(cortex::DivisibleWith<int_least16_t, long long>);

        // int_fast16_t with Unsigned Integers
        REQUIRE(cortex::DivisibleWith<int_least16_t, unsigned>);
        REQUIRE(cortex::DivisibleWith<int_least16_t, unsigned short>);
        REQUIRE(cortex::DivisibleWith<int_least16_t, u_short>);
        REQUIRE(cortex::DivisibleWith<int_least16_t, unsigned long>);
        REQUIRE(cortex::DivisibleWith<int_least16_t, unsigned long long>);
        
        // int_fast16_t with Floating Point and Doubles
        REQUIRE(cortex::DivisibleWith<int_least16_t, float>);
        REQUIRE(cortex::DivisibleWith<int_least16_t, double>);
        REQUIRE(cortex::DivisibleWith<int_least16_t, long double>);

        // int_fast16_t with std::strings and std::string_view
        REQUIRE(!cortex::DivisibleWith<int_least16_t, std::string>);
        REQUIRE(!cortex::DivisibleWith<int_least16_t, std::string_view>);
        REQUIRE(!cortex::DivisibleWith<int_least16_t, std::u8string>);
        REQUIRE(!cortex::DivisibleWith<int_least16_t, std::u16string>);
        REQUIRE(!cortex::DivisibleWith<int_least16_t, std::u32string>);

        // int_fast16_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::DivisibleWith<int_least16_t, std::wstring>);
        REQUIRE(!cortex::DivisibleWith<int_least16_t, std::wstring_view>);

        // int_fast16_t with Charaters
        REQUIRE(cortex::DivisibleWith<int_least16_t, char>);
        REQUIRE(cortex::DivisibleWith<int_least16_t, u_char>);
        REQUIRE(cortex::DivisibleWith<int_least16_t, wchar_t>);

        // int_fast16_t with Bit Specific Characters
        REQUIRE(cortex::DivisibleWith<int_least16_t, char8_t>);
        REQUIRE(cortex::DivisibleWith<int_least16_t, char16_t>);
        REQUIRE(cortex::DivisibleWith<int_least16_t, char32_t>);

        // int_fast16_t with Bit Specific Integers
        REQUIRE(cortex::DivisibleWith<int_least16_t, int8_t>);
        REQUIRE(cortex::DivisibleWith<int_least16_t, int16_t>);
        REQUIRE(cortex::DivisibleWith<int_least16_t, int32_t>);
        REQUIRE(cortex::DivisibleWith<int_least16_t, int64_t>);

        // int_fast16_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::DivisibleWith<int_least16_t, uint8_t>);
        REQUIRE(cortex::DivisibleWith<int_least16_t, uint16_t>);
        REQUIRE(cortex::DivisibleWith<int_least16_t, uint32_t>);
        REQUIRE(cortex::DivisibleWith<int_least16_t, uint64_t>);

        // int_fast16_t with Bit Specific Least Integers
        REQUIRE(cortex::DivisibleWith<int_least16_t, int_least8_t>);
        REQUIRE(cortex::DivisibleWith<int_least16_t, int_least16_t>);
        REQUIRE(cortex::DivisibleWith<int_least16_t, int_least32_t>);
        REQUIRE(cortex::DivisibleWith<int_least16_t, int_least64_t>);
    }

    SECTION("int_least32_t with _")
    {
        // int32 with Signed Integers
        REQUIRE(cortex::DivisibleWith<int_least32_t, int>);
        REQUIRE(cortex::DivisibleWith<int_least32_t, short>);
        REQUIRE(cortex::DivisibleWith<int_least32_t, long>);
        REQUIRE(cortex::DivisibleWith<int_least32_t, long long>);

        // int32 with Unsigned Integers
        REQUIRE(cortex::DivisibleWith<int_least32_t, unsigned>);
        REQUIRE(cortex::DivisibleWith<int_least32_t, unsigned short>);
        REQUIRE(cortex::DivisibleWith<int_least32_t, u_short>);
        REQUIRE(cortex::DivisibleWith<int_least32_t, unsigned long>);
        REQUIRE(cortex::DivisibleWith<int_least32_t, unsigned long long>);
        
        // int32 with Floating Point and Doubles
        REQUIRE(cortex::DivisibleWith<int_least32_t, float>);
        REQUIRE(cortex::DivisibleWith<int_least32_t, double>);
        REQUIRE(cortex::DivisibleWith<int_least32_t, long double>);

        // int32 with std::strings and std::string_view
        REQUIRE(!cortex::DivisibleWith<int_least32_t, std::string>);
        REQUIRE(!cortex::DivisibleWith<int_least32_t, std::string_view>);
        REQUIRE(!cortex::DivisibleWith<int_least32_t, std::u8string>);
        REQUIRE(!cortex::DivisibleWith<int_least32_t, std::u16string>);
        REQUIRE(!cortex::DivisibleWith<int_least32_t, std::u32string>);

        // int32 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::DivisibleWith<int_least32_t, std::wstring>);
        REQUIRE(!cortex::DivisibleWith<int_least32_t, std::wstring_view>);

        // int_fast32_t with Charaters
        REQUIRE(cortex::DivisibleWith<int_least32_t, char>);
        REQUIRE(cortex::DivisibleWith<int_least32_t, u_char>);
        REQUIRE(cortex::DivisibleWith<int_least32_t, wchar_t>);

        // int_fast32_t with Bit Specific Characters
        REQUIRE(cortex::DivisibleWith<int_least32_t, char8_t>);
        REQUIRE(cortex::DivisibleWith<int_least32_t, char16_t>);
        REQUIRE(cortex::DivisibleWith<int_least32_t, char32_t>);

        // int_fast32_t with Bit Specific Integers
        REQUIRE(cortex::DivisibleWith<int_least32_t, int8_t>);
        REQUIRE(cortex::DivisibleWith<int_least32_t, int16_t>);
        REQUIRE(cortex::DivisibleWith<int_least32_t, int32_t>);
        REQUIRE(cortex::DivisibleWith<int_least32_t, int64_t>);

        // int_fast32_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::DivisibleWith<int_least32_t, uint8_t>);
        REQUIRE(cortex::DivisibleWith<int_least32_t, uint16_t>);
        REQUIRE(cortex::DivisibleWith<int_least32_t, uint32_t>);
        REQUIRE(cortex::DivisibleWith<int_least32_t, uint64_t>);

        // int_fast32_t with Bit Specific Least Integers
        REQUIRE(cortex::DivisibleWith<int_least32_t, int_least8_t>);
        REQUIRE(cortex::DivisibleWith<int_least32_t, int_least16_t>);
        REQUIRE(cortex::DivisibleWith<int_least32_t, int_least32_t>);
        REQUIRE(cortex::DivisibleWith<int_least32_t, int_least64_t>);
    }

    SECTION("int_least64_t with _")
    {
        // int64 with Signed Integers
        REQUIRE(cortex::DivisibleWith<int_least64_t, int>);
        REQUIRE(cortex::DivisibleWith<int_least64_t, short>);
        REQUIRE(cortex::DivisibleWith<int_least64_t, long>);
        REQUIRE(cortex::DivisibleWith<int_least64_t, long long>);

        // int64 with Unsigned Integers
        REQUIRE(cortex::DivisibleWith<int_least64_t, unsigned>);
        REQUIRE(cortex::DivisibleWith<int_least64_t, unsigned short>);
        REQUIRE(cortex::DivisibleWith<int_least64_t, u_short>);
        REQUIRE(cortex::DivisibleWith<int_least64_t, unsigned long>);
        REQUIRE(cortex::DivisibleWith<int_least64_t, unsigned long long>);
        
        // int64 with Floating Point and Doubles
        REQUIRE(cortex::DivisibleWith<int_least64_t, float>);
        REQUIRE(cortex::DivisibleWith<int_least64_t, double>);
        REQUIRE(cortex::DivisibleWith<int_least64_t, long double>);

        // int64 with std::strings and std::string_view
        REQUIRE(!cortex::DivisibleWith<int_least64_t, std::string>);
        REQUIRE(!cortex::DivisibleWith<int_least64_t, std::string_view>);
        REQUIRE(!cortex::DivisibleWith<int_least64_t, std::u8string>);
        REQUIRE(!cortex::DivisibleWith<int_least64_t, std::u16string>);
        REQUIRE(!cortex::DivisibleWith<int_least64_t, std::u32string>);

        // int64 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::DivisibleWith<int_least64_t, std::wstring>);
        REQUIRE(!cortex::DivisibleWith<int_least64_t, std::wstring_view>);

        // int_fast64_t with Charaters
        REQUIRE(cortex::DivisibleWith<int_least64_t, char>);
        REQUIRE(cortex::DivisibleWith<int_least64_t, u_char>);
        REQUIRE(cortex::DivisibleWith<int_least64_t, wchar_t>);

        // int_fast64_t with Bit Specific Characters
        REQUIRE(cortex::DivisibleWith<int_least64_t, char8_t>);
        REQUIRE(cortex::DivisibleWith<int_least64_t, char16_t>);
        REQUIRE(cortex::DivisibleWith<int_least64_t, char32_t>);

        // int_fast64_t with Bit Specific Integers
        REQUIRE(cortex::DivisibleWith<int_least64_t, int8_t>);
        REQUIRE(cortex::DivisibleWith<int_least64_t, int16_t>);
        REQUIRE(cortex::DivisibleWith<int_least64_t, int32_t>);
        REQUIRE(cortex::DivisibleWith<int_least64_t, int64_t>);

        // int_fast64_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::DivisibleWith<int_least64_t, uint8_t>);
        REQUIRE(cortex::DivisibleWith<int_least64_t, uint16_t>);
        REQUIRE(cortex::DivisibleWith<int_least64_t, uint32_t>);
        REQUIRE(cortex::DivisibleWith<int_least64_t, uint64_t>);

        // int_fast64_t with Bit Specific Least Integers
        REQUIRE(cortex::DivisibleWith<int_least64_t, int_least8_t>);
        REQUIRE(cortex::DivisibleWith<int_least64_t, int_least16_t>);
        REQUIRE(cortex::DivisibleWith<int_least64_t, int_least32_t>);
        REQUIRE(cortex::DivisibleWith<int_least64_t, int_least64_t>);
    }
}