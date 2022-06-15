#include <catch2/catch.hpp>
#include <concepts.hpp>

TEST_CASE("BitOrWith : Signed Integers")
{
    SECTION("Int with _")
    {
        // Int with Signed Integers
        REQUIRE(cortex::BitOrWith<int, int>);
        REQUIRE(cortex::BitOrWith<int, short>);
        REQUIRE(cortex::BitOrWith<int, long>);
        REQUIRE(cortex::BitOrWith<int, long long>);

        // Int with Unsigned Integers
        REQUIRE(cortex::BitOrWith<int, unsigned>);
        REQUIRE(cortex::BitOrWith<int, unsigned short>);
        REQUIRE(cortex::BitOrWith<int, u_short>);
        REQUIRE(cortex::BitOrWith<int, unsigned long>);
        REQUIRE(cortex::BitOrWith<int, unsigned long long>);
        
        // Integers with Floating Point and Doubles
        REQUIRE(!cortex::BitOrWith<int, float>);
        REQUIRE(!cortex::BitOrWith<int, double>);
        REQUIRE(!cortex::BitOrWith<int, long double>);

        // Integers with std::strings and std::string_view
        REQUIRE(!cortex::BitOrWith<int, std::string>);
        REQUIRE(!cortex::BitOrWith<int, std::string_view>);
        REQUIRE(!cortex::BitOrWith<int, std::u8string>);
        REQUIRE(!cortex::BitOrWith<int, std::u16string>);
        REQUIRE(!cortex::BitOrWith<int, std::u32string>);

        // Integers with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitOrWith<int, std::wstring>);
        REQUIRE(!cortex::BitOrWith<int, std::wstring_view>);

        // Integers with Charaters
        REQUIRE(cortex::BitOrWith<int, char>);
        REQUIRE(cortex::BitOrWith<int, u_char>);
        REQUIRE(cortex::BitOrWith<int, wchar_t>);

        // Integers with Bit Specific Characters
        REQUIRE(cortex::BitOrWith<int, char8_t>);
        REQUIRE(cortex::BitOrWith<int, char16_t>);
        REQUIRE(cortex::BitOrWith<int, char32_t>);

        // Integers with Bit Specific Integers
        REQUIRE(cortex::BitOrWith<int, int8_t>);
        REQUIRE(cortex::BitOrWith<int, int16_t>);
        REQUIRE(cortex::BitOrWith<int, int32_t>);
        REQUIRE(cortex::BitOrWith<int, int64_t>);

        // Integers with Bit Specific Unsigned Integers
        REQUIRE(cortex::BitOrWith<int, uint8_t>);
        REQUIRE(cortex::BitOrWith<int, uint16_t>);
        REQUIRE(cortex::BitOrWith<int, uint32_t>);
        REQUIRE(cortex::BitOrWith<int, uint64_t>);

        // Integers with Bit Specific Least Integers
        REQUIRE(cortex::BitOrWith<int, int_least8_t>);
        REQUIRE(cortex::BitOrWith<int, int_least16_t>);
        REQUIRE(cortex::BitOrWith<int, int_least32_t>);
        REQUIRE(cortex::BitOrWith<int, int_least64_t>);
    }

    SECTION("Short with _")
    {
        // Short with Signed Integers
        REQUIRE(cortex::BitOrWith<short, int>);
        REQUIRE(cortex::BitOrWith<short, short>);
        REQUIRE(cortex::BitOrWith<short, long>);
        REQUIRE(cortex::BitOrWith<short, long long>);

        // Short with Unsigned Integers
        REQUIRE(cortex::BitOrWith<short, unsigned>);
        REQUIRE(cortex::BitOrWith<short, unsigned short>);
        REQUIRE(cortex::BitOrWith<short, u_short>);
        REQUIRE(cortex::BitOrWith<short, unsigned long>);
        REQUIRE(cortex::BitOrWith<short, unsigned long long>);
        
        // Short with Floating Point and Doubles
        REQUIRE(!cortex::BitOrWith<short, float>);
        REQUIRE(!cortex::BitOrWith<short, double>);
        REQUIRE(!cortex::BitOrWith<short, long double>);

        // Short with std::strings and std::string_view
        REQUIRE(!cortex::BitOrWith<short, std::string>);
        REQUIRE(!cortex::BitOrWith<short, std::string_view>);
        REQUIRE(!cortex::BitOrWith<short, std::u8string>);
        REQUIRE(!cortex::BitOrWith<short, std::u16string>);
        REQUIRE(!cortex::BitOrWith<short, std::u32string>);

        // Short with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitOrWith<short, std::wstring>);
        REQUIRE(!cortex::BitOrWith<short, std::wstring_view>);

        // Short with Charaters
        REQUIRE(cortex::BitOrWith<short, char>);
        REQUIRE(cortex::BitOrWith<short, u_char>);
        REQUIRE(cortex::BitOrWith<short, wchar_t>);

        // Short with Bit Specific Characters
        REQUIRE(cortex::BitOrWith<short, char8_t>);
        REQUIRE(cortex::BitOrWith<short, char16_t>);
        REQUIRE(cortex::BitOrWith<short, char32_t>);

        // Short with Bit Specific Short
        REQUIRE(cortex::BitOrWith<short, int8_t>);
        REQUIRE(cortex::BitOrWith<short, int16_t>);
        REQUIRE(cortex::BitOrWith<short, int32_t>);
        REQUIRE(cortex::BitOrWith<short, int64_t>);

        // Short with Bit Specific Unsigned Short
        REQUIRE(cortex::BitOrWith<short, uint8_t>);
        REQUIRE(cortex::BitOrWith<short, uint16_t>);
        REQUIRE(cortex::BitOrWith<short, uint32_t>);
        REQUIRE(cortex::BitOrWith<short, uint64_t>);

        // Short with Bit Specific Least Integers
        REQUIRE(cortex::BitOrWith<short, int_least8_t>);
        REQUIRE(cortex::BitOrWith<short, int_least16_t>);
        REQUIRE(cortex::BitOrWith<short, int_least32_t>);
        REQUIRE(cortex::BitOrWith<short, int_least64_t>);
    }

    SECTION("Long with _")
    {
        // Long with Signed Integers
        REQUIRE(cortex::BitOrWith<long, int>);
        REQUIRE(cortex::BitOrWith<long, short>);
        REQUIRE(cortex::BitOrWith<long, long>);
        REQUIRE(cortex::BitOrWith<long, long long>);

        // Long with Unsigned Integers
        REQUIRE(cortex::BitOrWith<long, unsigned>);
        REQUIRE(cortex::BitOrWith<long, unsigned short>);
        REQUIRE(cortex::BitOrWith<long, u_short>);
        REQUIRE(cortex::BitOrWith<long, unsigned long>);
        REQUIRE(cortex::BitOrWith<long, unsigned long long>);
        
        // Long with Floating Point and Doubles
        REQUIRE(!cortex::BitOrWith<long, float>);
        REQUIRE(!cortex::BitOrWith<long, double>);
        REQUIRE(!cortex::BitOrWith<long, long double>);

        // Long with std::strings and std::string_view
        REQUIRE(!cortex::BitOrWith<long, std::string>);
        REQUIRE(!cortex::BitOrWith<long, std::string_view>);
        REQUIRE(!cortex::BitOrWith<long, std::u8string>);
        REQUIRE(!cortex::BitOrWith<long, std::u16string>);
        REQUIRE(!cortex::BitOrWith<long, std::u32string>);

        // Long with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitOrWith<long, std::wstring>);
        REQUIRE(!cortex::BitOrWith<long, std::wstring_view>);

        // Long with Charaters
        REQUIRE(cortex::BitOrWith<long, char>);
        REQUIRE(cortex::BitOrWith<long, u_char>);
        REQUIRE(cortex::BitOrWith<long, wchar_t>);

        // Long with Bit Specific Characters
        REQUIRE(cortex::BitOrWith<long, char8_t>);
        REQUIRE(cortex::BitOrWith<long, char16_t>);
        REQUIRE(cortex::BitOrWith<long, char32_t>);

        // Long with Bit Specific Long
        REQUIRE(cortex::BitOrWith<long, int8_t>);
        REQUIRE(cortex::BitOrWith<long, int16_t>);
        REQUIRE(cortex::BitOrWith<long, int32_t>);
        REQUIRE(cortex::BitOrWith<long, int64_t>);

        // Long with Bit Specific Unsigned Long
        REQUIRE(cortex::BitOrWith<long, uint8_t>);
        REQUIRE(cortex::BitOrWith<long, uint16_t>);
        REQUIRE(cortex::BitOrWith<long, uint32_t>);
        REQUIRE(cortex::BitOrWith<long, uint64_t>);

        // Long with Bit Specific Least Integers
        REQUIRE(cortex::BitOrWith<long, int_least8_t>);
        REQUIRE(cortex::BitOrWith<long, int_least16_t>);
        REQUIRE(cortex::BitOrWith<long, int_least32_t>);
        REQUIRE(cortex::BitOrWith<long, int_least64_t>);
    }

    SECTION("Long Long with _")
    {
        // Signed Integers
        REQUIRE(cortex::BitOrWith<long long, int>);
        REQUIRE(cortex::BitOrWith<long long, short>);
        REQUIRE(cortex::BitOrWith<long long, long>);
        REQUIRE(cortex::BitOrWith<long long, long long>);

        // Unsigned Integers
        REQUIRE(cortex::BitOrWith<long long, unsigned>);
        REQUIRE(cortex::BitOrWith<long long, unsigned short>);
        REQUIRE(cortex::BitOrWith<long long, u_short>);
        REQUIRE(cortex::BitOrWith<long long, unsigned long>);
        REQUIRE(cortex::BitOrWith<long long, unsigned long long>);
        
        // Integers with Floating Point and Doubles
        REQUIRE(!cortex::BitOrWith<long long, float>);
        REQUIRE(!cortex::BitOrWith<long long, double>);
        REQUIRE(!cortex::BitOrWith<long long, long double>);

        // Integers with std::strings and std::string_view
        REQUIRE(!cortex::BitOrWith<long long, std::string>);
        REQUIRE(!cortex::BitOrWith<long long, std::string_view>);
        REQUIRE(!cortex::BitOrWith<long long, std::u8string>);
        REQUIRE(!cortex::BitOrWith<long long, std::u16string>);
        REQUIRE(!cortex::BitOrWith<long long, std::u32string>);

        // Integers with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitOrWith<long long, std::wstring>);
        REQUIRE(!cortex::BitOrWith<long long, std::wstring_view>);

        // Integers with Charaters
        REQUIRE(cortex::BitOrWith<long long, char>);
        REQUIRE(cortex::BitOrWith<long long, u_char>);
        REQUIRE(cortex::BitOrWith<long long, wchar_t>);

        // Integers with Bit Specific Characters
        REQUIRE(cortex::BitOrWith<long long, char8_t>);
        REQUIRE(cortex::BitOrWith<long long, char16_t>);
        REQUIRE(cortex::BitOrWith<long long, char32_t>);

        // Integers with Bit Specific Integers
        REQUIRE(cortex::BitOrWith<long long, int8_t>);
        REQUIRE(cortex::BitOrWith<long long, int16_t>);
        REQUIRE(cortex::BitOrWith<long long, int32_t>);
        REQUIRE(cortex::BitOrWith<long long, int64_t>);

        // Integers with Bit Specific Unsigned Integers
        REQUIRE(cortex::BitOrWith<long long, uint8_t>);
        REQUIRE(cortex::BitOrWith<long long, uint16_t>);
        REQUIRE(cortex::BitOrWith<long long, uint32_t>);
        REQUIRE(cortex::BitOrWith<long long, uint64_t>);

        // Long Long with Bit Specific Least Integers
        REQUIRE(cortex::BitOrWith<long long, int_least8_t>);
        REQUIRE(cortex::BitOrWith<long long, int_least16_t>);
        REQUIRE(cortex::BitOrWith<long long, int_least32_t>);
        REQUIRE(cortex::BitOrWith<long long, int_least64_t>);
    }
}

TEST_CASE("BitOrWith: Unsigned Integers")
{
    SECTION("Unsigned Int with _")
    {
        // Unsigned Integers with Signed Integers
        REQUIRE(cortex::BitOrWith<unsigned int, int>);
        REQUIRE(cortex::BitOrWith<unsigned int, short>);
        REQUIRE(cortex::BitOrWith<unsigned int, long>);
        REQUIRE(cortex::BitOrWith<unsigned int, long long>);

        // Unsigned Integers with Unsigned Integers
        REQUIRE(cortex::BitOrWith<unsigned int, unsigned>);
        REQUIRE(cortex::BitOrWith<unsigned int, unsigned short>);
        REQUIRE(cortex::BitOrWith<unsigned int, u_short>);
        REQUIRE(cortex::BitOrWith<unsigned int, unsigned long>);
        REQUIRE(cortex::BitOrWith<unsigned int, unsigned long long>);
        
        // Unsigned Integers with Floating Point and Doubles
        REQUIRE(!cortex::BitOrWith<unsigned int, float>);
        REQUIRE(!cortex::BitOrWith<unsigned int, double>);
        REQUIRE(!cortex::BitOrWith<unsigned int, long double>);

        // Unsigned Integers with std::strings and std::string_view
        REQUIRE(!cortex::BitOrWith<unsigned int, std::string>);
        REQUIRE(!cortex::BitOrWith<unsigned int, std::string_view>);
        REQUIRE(!cortex::BitOrWith<unsigned int, std::u8string>);
        REQUIRE(!cortex::BitOrWith<unsigned int, std::u16string>);
        REQUIRE(!cortex::BitOrWith<unsigned int, std::u32string>);

        // Unsigned Integers with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitOrWith<unsigned long long, std::wstring>);
        REQUIRE(!cortex::BitOrWith<unsigned long long, std::wstring_view>);

        // Unsigned Integers with Charaters
        REQUIRE(cortex::BitOrWith<unsigned int, char>);
        REQUIRE(cortex::BitOrWith<unsigned int, u_char>);
        REQUIRE(cortex::BitOrWith<unsigned int, wchar_t>);

        // Unsigned Integers with Bit Specific Characters
        REQUIRE(cortex::BitOrWith<unsigned int, char8_t>);
        REQUIRE(cortex::BitOrWith<unsigned int, char16_t>);
        REQUIRE(cortex::BitOrWith<unsigned int, char32_t>);

        // Unsigned Integers with Bit Specific Integers
        REQUIRE(cortex::BitOrWith<unsigned int, int8_t>);
        REQUIRE(cortex::BitOrWith<unsigned int, int16_t>);
        REQUIRE(cortex::BitOrWith<unsigned int, int32_t>);
        REQUIRE(cortex::BitOrWith<unsigned int, int64_t>);

        // Unsigned Integers with Bit Specific Unsigned Integers
        REQUIRE(cortex::BitOrWith<unsigned int, uint8_t>);
        REQUIRE(cortex::BitOrWith<unsigned int, uint16_t>);
        REQUIRE(cortex::BitOrWith<unsigned int, uint32_t>);
        REQUIRE(cortex::BitOrWith<unsigned int, uint64_t>);

        // Unsigned Integers with Bit Specific Least Integers
        REQUIRE(cortex::BitOrWith<unsigned int, int_least8_t>);
        REQUIRE(cortex::BitOrWith<unsigned int, int_least16_t>);
        REQUIRE(cortex::BitOrWith<unsigned int, int_least32_t>);
        REQUIRE(cortex::BitOrWith<unsigned int, int_least64_t>);
    }

    SECTION("Unsigned Short with _")
    {
        // Unsigned Short with Signed Integers
        REQUIRE(cortex::BitOrWith<unsigned short, int>);
        REQUIRE(cortex::BitOrWith<unsigned short, short>);
        REQUIRE(cortex::BitOrWith<unsigned short, long>);
        REQUIRE(cortex::BitOrWith<unsigned short, long long>);

        // Unsigned Short with Unsigned Integers
        REQUIRE(cortex::BitOrWith<unsigned short, unsigned>);
        REQUIRE(cortex::BitOrWith<unsigned short, unsigned short>);
        REQUIRE(cortex::BitOrWith<unsigned short, u_short>);
        REQUIRE(cortex::BitOrWith<unsigned short, unsigned long>);
        REQUIRE(cortex::BitOrWith<unsigned short, unsigned long long>);
        
        // Unsigned Short with Floating Point and Doubles
        REQUIRE(!cortex::BitOrWith<unsigned short, float>);
        REQUIRE(!cortex::BitOrWith<unsigned short, double>);
        REQUIRE(!cortex::BitOrWith<unsigned short, long double>);

        // Unsigned Short with std::strings and std::string_view
        REQUIRE(!cortex::BitOrWith<unsigned short, std::string>);
        REQUIRE(!cortex::BitOrWith<unsigned short, std::string_view>);
        REQUIRE(!cortex::BitOrWith<unsigned short, std::u8string>);
        REQUIRE(!cortex::BitOrWith<unsigned short, std::u16string>);
        REQUIRE(!cortex::BitOrWith<unsigned short, std::u32string>);

        // Unsigned Short with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitOrWith<unsigned short, std::wstring>);
        REQUIRE(!cortex::BitOrWith<unsigned short, std::wstring_view>);

        // Unsigned Short with Charaters
        REQUIRE(cortex::BitOrWith<unsigned short, char>);
        REQUIRE(cortex::BitOrWith<unsigned short, u_char>);
        REQUIRE(cortex::BitOrWith<unsigned short, wchar_t>);

        // Unsigned Short with Bit Specific Characters
        REQUIRE(cortex::BitOrWith<unsigned short, char8_t>);
        REQUIRE(cortex::BitOrWith<unsigned short, char16_t>);
        REQUIRE(cortex::BitOrWith<unsigned short, char32_t>);

        // Unsigned Short with Bit Specific Short
        REQUIRE(cortex::BitOrWith<unsigned short, int8_t>);
        REQUIRE(cortex::BitOrWith<unsigned short, int16_t>);
        REQUIRE(cortex::BitOrWith<unsigned short, int32_t>);
        REQUIRE(cortex::BitOrWith<unsigned short, int64_t>);

        // Unsigned Short with Bit Specific Unsigned Short
        REQUIRE(cortex::BitOrWith<unsigned short, uint8_t>);
        REQUIRE(cortex::BitOrWith<unsigned short, uint16_t>);
        REQUIRE(cortex::BitOrWith<unsigned short, uint32_t>);
        REQUIRE(cortex::BitOrWith<unsigned short, uint64_t>);

        // Unsigned Short with Bit Specific Least Integers
        REQUIRE(cortex::BitOrWith<unsigned short, int_least8_t>);
        REQUIRE(cortex::BitOrWith<unsigned short, int_least16_t>);
        REQUIRE(cortex::BitOrWith<unsigned short, int_least32_t>);
        REQUIRE(cortex::BitOrWith<unsigned short, int_least64_t>);
    }

    SECTION("u_short with _")
    {
        // u_short with Signed Integers
        REQUIRE(cortex::BitOrWith<u_short, int>);
        REQUIRE(cortex::BitOrWith<u_short, short>);
        REQUIRE(cortex::BitOrWith<u_short, long>);
        REQUIRE(cortex::BitOrWith<u_short, long long>);

        // u_short with Unsigned Integers
        REQUIRE(cortex::BitOrWith<u_short, unsigned>);
        REQUIRE(cortex::BitOrWith<u_short, unsigned short>);
        REQUIRE(cortex::BitOrWith<u_short, u_short>);
        REQUIRE(cortex::BitOrWith<u_short, unsigned long>);
        REQUIRE(cortex::BitOrWith<u_short, unsigned long long>);
        
        // u_short with Floating Point and Doubles
        REQUIRE(!cortex::BitOrWith<u_short, float>);
        REQUIRE(!cortex::BitOrWith<u_short, double>);
        REQUIRE(!cortex::BitOrWith<u_short, long double>);

        // u_short with std::strings and std::string_view
        REQUIRE(!cortex::BitOrWith<u_short, std::string>);
        REQUIRE(!cortex::BitOrWith<u_short, std::string_view>);
        REQUIRE(!cortex::BitOrWith<u_short, std::u8string>);
        REQUIRE(!cortex::BitOrWith<u_short, std::u16string>);
        REQUIRE(!cortex::BitOrWith<u_short, std::u32string>);

        // u_short with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitOrWith<u_short, std::wstring>);
        REQUIRE(!cortex::BitOrWith<u_short, std::wstring_view>);

        // u_short with Charaters
        REQUIRE(cortex::BitOrWith<u_short, char>);
        REQUIRE(cortex::BitOrWith<u_short, u_char>);
        REQUIRE(cortex::BitOrWith<u_short, wchar_t>);

        // u_short with Bit Specific Characters
        REQUIRE(cortex::BitOrWith<u_short, char8_t>);
        REQUIRE(cortex::BitOrWith<u_short, char16_t>);
        REQUIRE(cortex::BitOrWith<u_short, char32_t>);

        // u_short with Bit Specific Short
        REQUIRE(cortex::BitOrWith<u_short, int8_t>);
        REQUIRE(cortex::BitOrWith<u_short, int16_t>);
        REQUIRE(cortex::BitOrWith<u_short, int32_t>);
        REQUIRE(cortex::BitOrWith<u_short, int64_t>);

        // u_short with Bit Specific Unsigned Short
        REQUIRE(cortex::BitOrWith<u_short, uint8_t>);
        REQUIRE(cortex::BitOrWith<u_short, uint16_t>);
        REQUIRE(cortex::BitOrWith<u_short, uint32_t>);
        REQUIRE(cortex::BitOrWith<u_short, uint64_t>);

        // u_short with Bit Specific Least Integers
        REQUIRE(cortex::BitOrWith<u_short, int_least8_t>);
        REQUIRE(cortex::BitOrWith<u_short, int_least16_t>);
        REQUIRE(cortex::BitOrWith<u_short, int_least32_t>);
        REQUIRE(cortex::BitOrWith<u_short, int_least64_t>);
    }

    SECTION("Unsigned Long with _")
    {
        // Unsigned Long with Signed Integers
        REQUIRE(cortex::BitOrWith<unsigned long, int>);
        REQUIRE(cortex::BitOrWith<unsigned long, short>);
        REQUIRE(cortex::BitOrWith<unsigned long, long>);
        REQUIRE(cortex::BitOrWith<unsigned long, long long>);

        // Unsigned Long with Unsigned Integers
        REQUIRE(cortex::BitOrWith<unsigned long, unsigned>);
        REQUIRE(cortex::BitOrWith<unsigned long, unsigned short>);
        REQUIRE(cortex::BitOrWith<unsigned long, u_short>);
        REQUIRE(cortex::BitOrWith<unsigned long, unsigned long>);
        REQUIRE(cortex::BitOrWith<unsigned long, unsigned long long>);
        
        // Unsigned Long with Floating Point and Doubles
        REQUIRE(!cortex::BitOrWith<unsigned long, float>);
        REQUIRE(!cortex::BitOrWith<unsigned long, double>);
        REQUIRE(!cortex::BitOrWith<unsigned long, long double>);

        // Unsigned Long with std::strings and std::string_view
        REQUIRE(!cortex::BitOrWith<unsigned long, std::string>);
        REQUIRE(!cortex::BitOrWith<unsigned long, std::string_view>);
        REQUIRE(!cortex::BitOrWith<unsigned long, std::u8string>);
        REQUIRE(!cortex::BitOrWith<unsigned long, std::u16string>);
        REQUIRE(!cortex::BitOrWith<unsigned long, std::u32string>);

        // Unsigned Long with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitOrWith<unsigned long, std::wstring>);
        REQUIRE(!cortex::BitOrWith<unsigned long, std::wstring_view>);

        // Unsigned Long with Charaters
        REQUIRE(cortex::BitOrWith<unsigned long, char>);
        REQUIRE(cortex::BitOrWith<unsigned long, u_char>);
        REQUIRE(cortex::BitOrWith<unsigned long, wchar_t>);

        // Unsigned Long with Bit Specific Characters
        REQUIRE(cortex::BitOrWith<unsigned long, char8_t>);
        REQUIRE(cortex::BitOrWith<unsigned long, char16_t>);
        REQUIRE(cortex::BitOrWith<unsigned long, char32_t>);

        // Unsigned Long with Bit Specific Long
        REQUIRE(cortex::BitOrWith<unsigned long, int8_t>);
        REQUIRE(cortex::BitOrWith<unsigned long, int16_t>);
        REQUIRE(cortex::BitOrWith<unsigned long, int32_t>);
        REQUIRE(cortex::BitOrWith<unsigned long, int64_t>);

        // Unsigned Long with Bit Specific Unsigned Long
        REQUIRE(cortex::BitOrWith<unsigned long, uint8_t>);
        REQUIRE(cortex::BitOrWith<unsigned long, uint16_t>);
        REQUIRE(cortex::BitOrWith<unsigned long, uint32_t>);
        REQUIRE(cortex::BitOrWith<unsigned long, uint64_t>);

        // Unsigned Long with Bit Specific Least Integers
        REQUIRE(cortex::BitOrWith<unsigned long, int_least8_t>);
        REQUIRE(cortex::BitOrWith<unsigned long, int_least16_t>);
        REQUIRE(cortex::BitOrWith<unsigned long, int_least32_t>);
        REQUIRE(cortex::BitOrWith<unsigned long, int_least64_t>);
    }

    SECTION("Unsigned Long Long with _")
    {
        // Unsigned Long Long with Signed Integers
        REQUIRE(cortex::BitOrWith<unsigned long long, int>);
        REQUIRE(cortex::BitOrWith<unsigned long long, short>);
        REQUIRE(cortex::BitOrWith<unsigned long long, long>);
        REQUIRE(cortex::BitOrWith<unsigned long long, long long>);

        // Unsigned Long Long with Unsigned Integers
        REQUIRE(cortex::BitOrWith<unsigned long long, unsigned>);
        REQUIRE(cortex::BitOrWith<unsigned long long, unsigned short>);
        REQUIRE(cortex::BitOrWith<unsigned long long, u_short>);
        REQUIRE(cortex::BitOrWith<unsigned long long, unsigned long>);
        REQUIRE(cortex::BitOrWith<unsigned long long, unsigned long long>);
        
        // Unsigned Long Long with Floating Point and Doubles
        REQUIRE(!cortex::BitOrWith<unsigned long long, float>);
        REQUIRE(!cortex::BitOrWith<unsigned long long, double>);
        REQUIRE(!cortex::BitOrWith<unsigned long long, long double>);

        // Unsigned Long Long with std::strings and std::string_view
        REQUIRE(!cortex::BitOrWith<unsigned long long, std::string>);
        REQUIRE(!cortex::BitOrWith<unsigned long long, std::string_view>);
        REQUIRE(!cortex::BitOrWith<unsigned long long, std::u8string>);
        REQUIRE(!cortex::BitOrWith<unsigned long long, std::u16string>);
        REQUIRE(!cortex::BitOrWith<unsigned long long, std::u32string>);

        // Unsigned Long Long with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitOrWith<unsigned long long, std::wstring>);
        REQUIRE(!cortex::BitOrWith<unsigned long long, std::wstring_view>);

        // Unsigned Long Long with Charaters
        REQUIRE(cortex::BitOrWith<unsigned long long, char>);
        REQUIRE(cortex::BitOrWith<unsigned long long, u_char>);
        REQUIRE(cortex::BitOrWith<unsigned long long, wchar_t>);

        // Unsigned Long Long with Bit Specific Characters
        REQUIRE(cortex::BitOrWith<unsigned long long, char8_t>);
        REQUIRE(cortex::BitOrWith<unsigned long long, char16_t>);
        REQUIRE(cortex::BitOrWith<unsigned long long, char32_t>);

        // Unsigned Long Long with Bit Specific Long Long
        REQUIRE(cortex::BitOrWith<unsigned long long, int8_t>);
        REQUIRE(cortex::BitOrWith<unsigned long long, int16_t>);
        REQUIRE(cortex::BitOrWith<unsigned long long, int32_t>);
        REQUIRE(cortex::BitOrWith<unsigned long long, int64_t>);

        // Unsigned Long Long with Bit Specific Unsigned Long Long
        REQUIRE(cortex::BitOrWith<unsigned long long, uint8_t>);
        REQUIRE(cortex::BitOrWith<unsigned long long, uint16_t>);
        REQUIRE(cortex::BitOrWith<unsigned long long, uint32_t>);
        REQUIRE(cortex::BitOrWith<unsigned long long, uint64_t>);

        // Long Long with Bit Specific Least Long Long
        REQUIRE(cortex::BitOrWith<unsigned long long, int_least8_t>);
        REQUIRE(cortex::BitOrWith<unsigned long long, int_least16_t>);
        REQUIRE(cortex::BitOrWith<unsigned long long, int_least32_t>);
        REQUIRE(cortex::BitOrWith<unsigned long long, int_least64_t>);
    }
}

TEST_CASE("Addable With : Bit Specific Signed Integers")
{
    SECTION("int8_t with _")
    {
        // int8_t with Signed Integers
        REQUIRE(cortex::BitOrWith<int8_t, int>);
        REQUIRE(cortex::BitOrWith<int8_t, short>);
        REQUIRE(cortex::BitOrWith<int8_t, long>);
        REQUIRE(cortex::BitOrWith<int8_t, long long>);

        // int8_t with Unsigned Integers
        REQUIRE(cortex::BitOrWith<int8_t, unsigned>);
        REQUIRE(cortex::BitOrWith<int8_t, unsigned short>);
        REQUIRE(cortex::BitOrWith<int8_t, u_short>);
        REQUIRE(cortex::BitOrWith<int8_t, unsigned long>);
        REQUIRE(cortex::BitOrWith<int8_t, unsigned long long>);
        
        // int8_t with Floating Point and Doubles
        REQUIRE(!cortex::BitOrWith<int8_t, float>);
        REQUIRE(!cortex::BitOrWith<int8_t, double>);
        REQUIRE(!cortex::BitOrWith<int8_t, long double>);

        // int8_t with std::strings and std::string_view
        REQUIRE(!cortex::BitOrWith<int8_t, std::string>);
        REQUIRE(!cortex::BitOrWith<int8_t, std::string_view>);
        REQUIRE(!cortex::BitOrWith<int8_t, std::u8string>);
        REQUIRE(!cortex::BitOrWith<int8_t, std::u16string>);
        REQUIRE(!cortex::BitOrWith<int8_t, std::u32string>);

        // int8_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitOrWith<long long, std::wstring>);
        REQUIRE(!cortex::BitOrWith<long long, std::wstring_view>);

        // int8_t with Charaters
        REQUIRE(cortex::BitOrWith<int8_t, char>);
        REQUIRE(cortex::BitOrWith<int8_t, u_char>);
        REQUIRE(cortex::BitOrWith<int8_t, wchar_t>);

        // int8_t with Bit Specific Characters
        REQUIRE(cortex::BitOrWith<int8_t, char8_t>);
        REQUIRE(cortex::BitOrWith<int8_t, char16_t>);
        REQUIRE(cortex::BitOrWith<int8_t, char32_t>);

        // int8_t with Bit Specific Integers
        REQUIRE(cortex::BitOrWith<int8_t, int8_t>);
        REQUIRE(cortex::BitOrWith<int8_t, int16_t>);
        REQUIRE(cortex::BitOrWith<int8_t, int32_t>);
        REQUIRE(cortex::BitOrWith<int8_t, int64_t>);

        // int8_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::BitOrWith<int8_t, uint8_t>);
        REQUIRE(cortex::BitOrWith<int8_t, uint16_t>);
        REQUIRE(cortex::BitOrWith<int8_t, uint32_t>);
        REQUIRE(cortex::BitOrWith<int8_t, uint64_t>);

        // int8_t with Bit Specific Least Integers
        REQUIRE(cortex::BitOrWith<int8_t, int_least8_t>);
        REQUIRE(cortex::BitOrWith<int8_t, int_least16_t>);
        REQUIRE(cortex::BitOrWith<int8_t, int_least32_t>);
        REQUIRE(cortex::BitOrWith<int8_t, int_least64_t>);
    }

    SECTION("int16_t with _")
    {
        // int16_t with Signed Integers
        REQUIRE(cortex::BitOrWith<int16_t, int>);
        REQUIRE(cortex::BitOrWith<int16_t, short>);
        REQUIRE(cortex::BitOrWith<int16_t, long>);
        REQUIRE(cortex::BitOrWith<int16_t, long long>);

        // int16_t with Unsigned Integers
        REQUIRE(cortex::BitOrWith<int16_t, unsigned>);
        REQUIRE(cortex::BitOrWith<int16_t, unsigned short>);
        REQUIRE(cortex::BitOrWith<int16_t, u_short>);
        REQUIRE(cortex::BitOrWith<int16_t, unsigned long>);
        REQUIRE(cortex::BitOrWith<int16_t, unsigned long long>);
        
        // int16_t with Floating Point and Doubles
        REQUIRE(!cortex::BitOrWith<int16_t, float>);
        REQUIRE(!cortex::BitOrWith<int16_t, double>);
        REQUIRE(!cortex::BitOrWith<int16_t, long double>);

        // int16_t with std::strings and std::string_view
        REQUIRE(!cortex::BitOrWith<int16_t, std::string>);
        REQUIRE(!cortex::BitOrWith<int16_t, std::string_view>);
        REQUIRE(!cortex::BitOrWith<int16_t, std::u8string>);
        REQUIRE(!cortex::BitOrWith<int16_t, std::u16string>);
        REQUIRE(!cortex::BitOrWith<int16_t, std::u32string>);

        // int16_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitOrWith<int16_t, std::wstring>);
        REQUIRE(!cortex::BitOrWith<int16_t, std::wstring_view>);

        // int16_t with Charaters
        REQUIRE(cortex::BitOrWith<int16_t, char>);
        REQUIRE(cortex::BitOrWith<int16_t, u_char>);
        REQUIRE(cortex::BitOrWith<int16_t, wchar_t>);

        // int16_t with Bit Specific Characters
        REQUIRE(cortex::BitOrWith<int16_t, char8_t>);
        REQUIRE(cortex::BitOrWith<int16_t, char16_t>);
        REQUIRE(cortex::BitOrWith<int16_t, char32_t>);

        // int16_t with Bit Specific Integers
        REQUIRE(cortex::BitOrWith<int16_t, int8_t>);
        REQUIRE(cortex::BitOrWith<int16_t, int16_t>);
        REQUIRE(cortex::BitOrWith<int16_t, int32_t>);
        REQUIRE(cortex::BitOrWith<int16_t, int64_t>);

        // int16_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::BitOrWith<int16_t, uint8_t>);
        REQUIRE(cortex::BitOrWith<int16_t, uint16_t>);
        REQUIRE(cortex::BitOrWith<int16_t, uint32_t>);
        REQUIRE(cortex::BitOrWith<int16_t, uint64_t>);

        // int16_t with Bit Specific Least Integers
        REQUIRE(cortex::BitOrWith<int16_t, int_least8_t>);
        REQUIRE(cortex::BitOrWith<int16_t, int_least16_t>);
        REQUIRE(cortex::BitOrWith<int16_t, int_least32_t>);
        REQUIRE(cortex::BitOrWith<int16_t, int_least64_t>);
    }

    SECTION("int32 with _")
    {
        // int32 with Signed Integers
        REQUIRE(cortex::BitOrWith<int32_t, int>);
        REQUIRE(cortex::BitOrWith<int32_t, short>);
        REQUIRE(cortex::BitOrWith<int32_t, long>);
        REQUIRE(cortex::BitOrWith<int32_t, long long>);

        // int32 with Unsigned Integers
        REQUIRE(cortex::BitOrWith<int32_t, unsigned>);
        REQUIRE(cortex::BitOrWith<int32_t, unsigned short>);
        REQUIRE(cortex::BitOrWith<int32_t, u_short>);
        REQUIRE(cortex::BitOrWith<int32_t, unsigned long>);
        REQUIRE(cortex::BitOrWith<int32_t, unsigned long long>);
        
        // int32 with Floating Point and Doubles
        REQUIRE(!cortex::BitOrWith<int32_t, float>);
        REQUIRE(!cortex::BitOrWith<int32_t, double>);
        REQUIRE(!cortex::BitOrWith<int32_t, long double>);

        // int32 with std::strings and std::string_view
        REQUIRE(!cortex::BitOrWith<int32_t, std::string>);
        REQUIRE(!cortex::BitOrWith<int32_t, std::string_view>);
        REQUIRE(!cortex::BitOrWith<int32_t, std::u8string>);
        REQUIRE(!cortex::BitOrWith<int32_t, std::u16string>);
        REQUIRE(!cortex::BitOrWith<int32_t, std::u32string>);

        // int32 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitOrWith<int32_t, std::wstring>);
        REQUIRE(!cortex::BitOrWith<int32_t, std::wstring_view>);

        // int32_t with Charaters
        REQUIRE(cortex::BitOrWith<int32_t, char>);
        REQUIRE(cortex::BitOrWith<int32_t, u_char>);
        REQUIRE(cortex::BitOrWith<int32_t, wchar_t>);

        // int32_t with Bit Specific Characters
        REQUIRE(cortex::BitOrWith<int32_t, char8_t>);
        REQUIRE(cortex::BitOrWith<int32_t, char16_t>);
        REQUIRE(cortex::BitOrWith<int32_t, char32_t>);

        // int32_t with Bit Specific Integers
        REQUIRE(cortex::BitOrWith<int32_t, int8_t>);
        REQUIRE(cortex::BitOrWith<int32_t, int16_t>);
        REQUIRE(cortex::BitOrWith<int32_t, int32_t>);
        REQUIRE(cortex::BitOrWith<int32_t, int64_t>);

        // int32_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::BitOrWith<int32_t, uint8_t>);
        REQUIRE(cortex::BitOrWith<int32_t, uint16_t>);
        REQUIRE(cortex::BitOrWith<int32_t, uint32_t>);
        REQUIRE(cortex::BitOrWith<int32_t, uint64_t>);

        // int32_t with Bit Specific Least Integers
        REQUIRE(cortex::BitOrWith<int32_t, int_least8_t>);
        REQUIRE(cortex::BitOrWith<int32_t, int_least16_t>);
        REQUIRE(cortex::BitOrWith<int32_t, int_least32_t>);
        REQUIRE(cortex::BitOrWith<int32_t, int_least64_t>);
    }

    SECTION("int64 with _")
    {
        // int64 with Signed Integers
        REQUIRE(cortex::BitOrWith<int64_t, int>);
        REQUIRE(cortex::BitOrWith<int64_t, short>);
        REQUIRE(cortex::BitOrWith<int64_t, long>);
        REQUIRE(cortex::BitOrWith<int64_t, long long>);

        // int64 with Unsigned Integers
        REQUIRE(cortex::BitOrWith<int64_t, unsigned>);
        REQUIRE(cortex::BitOrWith<int64_t, unsigned short>);
        REQUIRE(cortex::BitOrWith<int64_t, u_short>);
        REQUIRE(cortex::BitOrWith<int64_t, unsigned long>);
        REQUIRE(cortex::BitOrWith<int64_t, unsigned long long>);
        
        // int64 with Floating Point and Doubles
        REQUIRE(!cortex::BitOrWith<int64_t, float>);
        REQUIRE(!cortex::BitOrWith<int64_t, double>);
        REQUIRE(!cortex::BitOrWith<int64_t, long double>);

        // int64 with std::strings and std::string_view
        REQUIRE(!cortex::BitOrWith<int64_t, std::string>);
        REQUIRE(!cortex::BitOrWith<int64_t, std::string_view>);
        REQUIRE(!cortex::BitOrWith<int64_t, std::u8string>);
        REQUIRE(!cortex::BitOrWith<int64_t, std::u16string>);
        REQUIRE(!cortex::BitOrWith<int64_t, std::u32string>);

        // int64 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitOrWith<int64_t, std::wstring>);
        REQUIRE(!cortex::BitOrWith<int64_t, std::wstring_view>);

        // int64_t with Charaters
        REQUIRE(cortex::BitOrWith<int64_t, char>);
        REQUIRE(cortex::BitOrWith<int64_t, u_char>);
        REQUIRE(cortex::BitOrWith<int64_t, wchar_t>);

        // int64_t with Bit Specific Characters
        REQUIRE(cortex::BitOrWith<int64_t, char8_t>);
        REQUIRE(cortex::BitOrWith<int64_t, char16_t>);
        REQUIRE(cortex::BitOrWith<int64_t, char32_t>);

        // int64_t with Bit Specific Integers
        REQUIRE(cortex::BitOrWith<int64_t, int8_t>);
        REQUIRE(cortex::BitOrWith<int64_t, int16_t>);
        REQUIRE(cortex::BitOrWith<int64_t, int32_t>);
        REQUIRE(cortex::BitOrWith<int64_t, int64_t>);

        // int64_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::BitOrWith<int64_t, uint8_t>);
        REQUIRE(cortex::BitOrWith<int64_t, uint16_t>);
        REQUIRE(cortex::BitOrWith<int64_t, uint32_t>);
        REQUIRE(cortex::BitOrWith<int64_t, uint64_t>);

        // int64_t with Bit Specific Least Integers
        REQUIRE(cortex::BitOrWith<int64_t, int_least8_t>);
        REQUIRE(cortex::BitOrWith<int64_t, int_least16_t>);
        REQUIRE(cortex::BitOrWith<int64_t, int_least32_t>);
        REQUIRE(cortex::BitOrWith<int64_t, int_least64_t>);
}
}

TEST_CASE("Addable With : Bit Specific Unsigned Integers")
{
    SECTION("uint8_t with _")
    {
        // uint8_t with Signed Integers
        REQUIRE(cortex::BitOrWith<uint8_t, int>);
        REQUIRE(cortex::BitOrWith<uint8_t, short>);
        REQUIRE(cortex::BitOrWith<uint8_t, long>);
        REQUIRE(cortex::BitOrWith<uint8_t, long long>);

        // uint8_t with Unsigned Integers
        REQUIRE(cortex::BitOrWith<uint8_t, unsigned>);
        REQUIRE(cortex::BitOrWith<uint8_t, unsigned short>);
        REQUIRE(cortex::BitOrWith<uint8_t, u_short>);
        REQUIRE(cortex::BitOrWith<uint8_t, unsigned long>);
        REQUIRE(cortex::BitOrWith<uint8_t, unsigned long long>);
        
        // uint8_t with Floating Point and Doubles
        REQUIRE(!cortex::BitOrWith<uint8_t, float>);
        REQUIRE(!cortex::BitOrWith<uint8_t, double>);
        REQUIRE(!cortex::BitOrWith<uint8_t, long double>);

        // uint8_t with std::strings and std::string_view
        REQUIRE(!cortex::BitOrWith<uint8_t, std::string>);
        REQUIRE(!cortex::BitOrWith<uint8_t, std::string_view>);
        REQUIRE(!cortex::BitOrWith<uint8_t, std::u8string>);
        REQUIRE(!cortex::BitOrWith<uint8_t, std::u16string>);
        REQUIRE(!cortex::BitOrWith<uint8_t, std::u32string>);

        // uint8_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitOrWith<long long, std::wstring>);
        REQUIRE(!cortex::BitOrWith<long long, std::wstring_view>);

        // uint8_t with Charaters
        REQUIRE(cortex::BitOrWith<uint8_t, char>);
        REQUIRE(cortex::BitOrWith<uint8_t, u_char>);
        REQUIRE(cortex::BitOrWith<uint8_t, wchar_t>);

        // uint8_t with Bit Specific Characters
        REQUIRE(cortex::BitOrWith<uint8_t, char8_t>);
        REQUIRE(cortex::BitOrWith<uint8_t, char16_t>);
        REQUIRE(cortex::BitOrWith<uint8_t, char32_t>);

        // uint8_t with Bit Specific Integers
        REQUIRE(cortex::BitOrWith<uint8_t, int8_t>);
        REQUIRE(cortex::BitOrWith<uint8_t, int16_t>);
        REQUIRE(cortex::BitOrWith<uint8_t, int32_t>);
        REQUIRE(cortex::BitOrWith<uint8_t, int64_t>);

        // uint8_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::BitOrWith<uint8_t, uint8_t>);
        REQUIRE(cortex::BitOrWith<uint8_t, uint16_t>);
        REQUIRE(cortex::BitOrWith<uint8_t, uint32_t>);
        REQUIRE(cortex::BitOrWith<uint8_t, uint64_t>);

        // uint8_t with Bit Specific Least Integers
        REQUIRE(cortex::BitOrWith<uint8_t, int_least8_t>);
        REQUIRE(cortex::BitOrWith<uint8_t, int_least16_t>);
        REQUIRE(cortex::BitOrWith<uint8_t, int_least32_t>);
        REQUIRE(cortex::BitOrWith<uint8_t, int_least64_t>);
    }

    SECTION("uint16_t with _")
    {
        // uint16_t with Signed Integers
        REQUIRE(cortex::BitOrWith<uint16_t, int>);
        REQUIRE(cortex::BitOrWith<uint16_t, short>);
        REQUIRE(cortex::BitOrWith<uint16_t, long>);
        REQUIRE(cortex::BitOrWith<uint16_t, long long>);

        // uint16_t with Unsigned Integers
        REQUIRE(cortex::BitOrWith<uint16_t, unsigned>);
        REQUIRE(cortex::BitOrWith<uint16_t, unsigned short>);
        REQUIRE(cortex::BitOrWith<uint16_t, u_short>);
        REQUIRE(cortex::BitOrWith<uint16_t, unsigned long>);
        REQUIRE(cortex::BitOrWith<uint16_t, unsigned long long>);
        
        // uint16_t with Floating Point and Doubles
        REQUIRE(!cortex::BitOrWith<uint16_t, float>);
        REQUIRE(!cortex::BitOrWith<uint16_t, double>);
        REQUIRE(!cortex::BitOrWith<uint16_t, long double>);

        // uint16_t with std::strings and std::string_view
        REQUIRE(!cortex::BitOrWith<uint16_t, std::string>);
        REQUIRE(!cortex::BitOrWith<uint16_t, std::string_view>);
        REQUIRE(!cortex::BitOrWith<uint16_t, std::u8string>);
        REQUIRE(!cortex::BitOrWith<uint16_t, std::u16string>);
        REQUIRE(!cortex::BitOrWith<uint16_t, std::u32string>);

        // uint16_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitOrWith<uint16_t, std::wstring>);
        REQUIRE(!cortex::BitOrWith<uint16_t, std::wstring_view>);

        // uint16_t with Charaters
        REQUIRE(cortex::BitOrWith<uint16_t, char>);
        REQUIRE(cortex::BitOrWith<uint16_t, u_char>);
        REQUIRE(cortex::BitOrWith<uint16_t, wchar_t>);

        // uint16_t with Bit Specific Characters
        REQUIRE(cortex::BitOrWith<uint16_t, char8_t>);
        REQUIRE(cortex::BitOrWith<uint16_t, char16_t>);
        REQUIRE(cortex::BitOrWith<uint16_t, char32_t>);

        // uint16_t with Bit Specific Integers
        REQUIRE(cortex::BitOrWith<uint16_t, int8_t>);
        REQUIRE(cortex::BitOrWith<uint16_t, int16_t>);
        REQUIRE(cortex::BitOrWith<uint16_t, int32_t>);
        REQUIRE(cortex::BitOrWith<uint16_t, int64_t>);

        // uint16_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::BitOrWith<uint16_t, uint8_t>);
        REQUIRE(cortex::BitOrWith<uint16_t, uint16_t>);
        REQUIRE(cortex::BitOrWith<uint16_t, uint32_t>);
        REQUIRE(cortex::BitOrWith<uint16_t, uint64_t>);

        // uint16_t with Bit Specific Least Integers
        REQUIRE(cortex::BitOrWith<uint16_t, int_least8_t>);
        REQUIRE(cortex::BitOrWith<uint16_t, int_least16_t>);
        REQUIRE(cortex::BitOrWith<uint16_t, int_least32_t>);
        REQUIRE(cortex::BitOrWith<uint16_t, int_least64_t>);
    }

    SECTION("uint32_t with _")
    {
        // int32 with Signed Integers
        REQUIRE(cortex::BitOrWith<uint32_t, int>);
        REQUIRE(cortex::BitOrWith<uint32_t, short>);
        REQUIRE(cortex::BitOrWith<uint32_t, long>);
        REQUIRE(cortex::BitOrWith<uint32_t, long long>);

        // int32 with Unsigned Integers
        REQUIRE(cortex::BitOrWith<uint32_t, unsigned>);
        REQUIRE(cortex::BitOrWith<uint32_t, unsigned short>);
        REQUIRE(cortex::BitOrWith<uint32_t, u_short>);
        REQUIRE(cortex::BitOrWith<uint32_t, unsigned long>);
        REQUIRE(cortex::BitOrWith<uint32_t, unsigned long long>);
        
        // int32 with Floating Point and Doubles
        REQUIRE(!cortex::BitOrWith<uint32_t, float>);
        REQUIRE(!cortex::BitOrWith<uint32_t, double>);
        REQUIRE(!cortex::BitOrWith<uint32_t, long double>);

        // int32 with std::strings and std::string_view
        REQUIRE(!cortex::BitOrWith<uint32_t, std::string>);
        REQUIRE(!cortex::BitOrWith<uint32_t, std::string_view>);
        REQUIRE(!cortex::BitOrWith<uint32_t, std::u8string>);
        REQUIRE(!cortex::BitOrWith<uint32_t, std::u16string>);
        REQUIRE(!cortex::BitOrWith<uint32_t, std::u32string>);

        // int32 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitOrWith<uint32_t, std::wstring>);
        REQUIRE(!cortex::BitOrWith<uint32_t, std::wstring_view>);

        // uint32_t with Charaters
        REQUIRE(cortex::BitOrWith<uint32_t, char>);
        REQUIRE(cortex::BitOrWith<uint32_t, u_char>);
        REQUIRE(cortex::BitOrWith<uint32_t, wchar_t>);

        // uint32_t with Bit Specific Characters
        REQUIRE(cortex::BitOrWith<uint32_t, char8_t>);
        REQUIRE(cortex::BitOrWith<uint32_t, char16_t>);
        REQUIRE(cortex::BitOrWith<uint32_t, char32_t>);

        // uint32_t with Bit Specific Integers
        REQUIRE(cortex::BitOrWith<uint32_t, int8_t>);
        REQUIRE(cortex::BitOrWith<uint32_t, int16_t>);
        REQUIRE(cortex::BitOrWith<uint32_t, int32_t>);
        REQUIRE(cortex::BitOrWith<uint32_t, int64_t>);

        // uint32_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::BitOrWith<uint32_t, uint8_t>);
        REQUIRE(cortex::BitOrWith<uint32_t, uint16_t>);
        REQUIRE(cortex::BitOrWith<uint32_t, uint32_t>);
        REQUIRE(cortex::BitOrWith<uint32_t, uint64_t>);

        // uint32_t with Bit Specific Least Integers
        REQUIRE(cortex::BitOrWith<uint32_t, int_least8_t>);
        REQUIRE(cortex::BitOrWith<uint32_t, int_least16_t>);
        REQUIRE(cortex::BitOrWith<uint32_t, int_least32_t>);
        REQUIRE(cortex::BitOrWith<uint32_t, int_least64_t>);
    }

    SECTION("uint64_t with _")
    {
        // int64 with Signed Integers
        REQUIRE(cortex::BitOrWith<uint64_t, int>);
        REQUIRE(cortex::BitOrWith<uint64_t, short>);
        REQUIRE(cortex::BitOrWith<uint64_t, long>);
        REQUIRE(cortex::BitOrWith<uint64_t, long long>);

        // int64 with Unsigned Integers
        REQUIRE(cortex::BitOrWith<uint64_t, unsigned>);
        REQUIRE(cortex::BitOrWith<uint64_t, unsigned short>);
        REQUIRE(cortex::BitOrWith<uint64_t, u_short>);
        REQUIRE(cortex::BitOrWith<uint64_t, unsigned long>);
        REQUIRE(cortex::BitOrWith<uint64_t, unsigned long long>);
        
        // int64 with Floating Point and Doubles
        REQUIRE(!cortex::BitOrWith<uint64_t, float>);
        REQUIRE(!cortex::BitOrWith<uint64_t, double>);
        REQUIRE(!cortex::BitOrWith<uint64_t, long double>);

        // int64 with std::strings and std::string_view
        REQUIRE(!cortex::BitOrWith<uint64_t, std::string>);
        REQUIRE(!cortex::BitOrWith<uint64_t, std::string_view>);
        REQUIRE(!cortex::BitOrWith<uint64_t, std::u8string>);
        REQUIRE(!cortex::BitOrWith<uint64_t, std::u16string>);
        REQUIRE(!cortex::BitOrWith<uint64_t, std::u32string>);

        // int64 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitOrWith<uint64_t, std::wstring>);
        REQUIRE(!cortex::BitOrWith<uint64_t, std::wstring_view>);

        // uint64_t with Charaters
        REQUIRE(cortex::BitOrWith<uint64_t, char>);
        REQUIRE(cortex::BitOrWith<uint64_t, u_char>);
        REQUIRE(cortex::BitOrWith<uint64_t, wchar_t>);

        // uint64_t with Bit Specific Characters
        REQUIRE(cortex::BitOrWith<uint64_t, char8_t>);
        REQUIRE(cortex::BitOrWith<uint64_t, char16_t>);
        REQUIRE(cortex::BitOrWith<uint64_t, char32_t>);

        // uint64_t with Bit Specific Integers
        REQUIRE(cortex::BitOrWith<uint64_t, int8_t>);
        REQUIRE(cortex::BitOrWith<uint64_t, int16_t>);
        REQUIRE(cortex::BitOrWith<uint64_t, int32_t>);
        REQUIRE(cortex::BitOrWith<uint64_t, int64_t>);

        // uint64_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::BitOrWith<uint64_t, uint8_t>);
        REQUIRE(cortex::BitOrWith<uint64_t, uint16_t>);
        REQUIRE(cortex::BitOrWith<uint64_t, uint32_t>);
        REQUIRE(cortex::BitOrWith<uint64_t, uint64_t>);

        // uint64_t with Bit Specific Least Integers
        REQUIRE(cortex::BitOrWith<uint64_t, int_least8_t>);
        REQUIRE(cortex::BitOrWith<uint64_t, int_least16_t>);
        REQUIRE(cortex::BitOrWith<uint64_t, int_least32_t>);
        REQUIRE(cortex::BitOrWith<uint64_t, int_least64_t>);
    }
}

TEST_CASE("Addable With : std::size_t")
{
    SECTION("std::size_t with _")
    {
        // std::size_t with Signed Integers
        REQUIRE(cortex::BitOrWith<std::size_t, int>);
        REQUIRE(cortex::BitOrWith<std::size_t, short>);
        REQUIRE(cortex::BitOrWith<std::size_t, long>);
        REQUIRE(cortex::BitOrWith<std::size_t, long long>);

        // std::size_t with Unsigned Integers
        REQUIRE(cortex::BitOrWith<std::size_t, unsigned>);
        REQUIRE(cortex::BitOrWith<std::size_t, unsigned short>);
        REQUIRE(cortex::BitOrWith<std::size_t, u_short>);
        REQUIRE(cortex::BitOrWith<std::size_t, unsigned long>);
        REQUIRE(cortex::BitOrWith<std::size_t, unsigned long long>);
        
        // std::size_t with Floating Point and Doubles
        REQUIRE(!cortex::BitOrWith<std::size_t, float>);
        REQUIRE(!cortex::BitOrWith<std::size_t, double>);
        REQUIRE(!cortex::BitOrWith<std::size_t, long double>);

        // std::size_t with std::strings and std::string_view
        REQUIRE(!cortex::BitOrWith<std::size_t, std::string>);
        REQUIRE(!cortex::BitOrWith<std::size_t, std::string_view>);
        REQUIRE(!cortex::BitOrWith<std::size_t, std::u8string>);
        REQUIRE(!cortex::BitOrWith<std::size_t, std::u16string>);
        REQUIRE(!cortex::BitOrWith<std::size_t, std::u32string>);

        // std::size_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitOrWith<long long, std::wstring>);
        REQUIRE(!cortex::BitOrWith<long long, std::wstring_view>);

        // std::size_t with Charaters
        REQUIRE(cortex::BitOrWith<std::size_t, char>);
        REQUIRE(cortex::BitOrWith<std::size_t, u_char>);
        REQUIRE(cortex::BitOrWith<std::size_t, wchar_t>);

        // std::size_t with Bit Specific Characters
        REQUIRE(cortex::BitOrWith<std::size_t, char8_t>);
        REQUIRE(cortex::BitOrWith<std::size_t, char16_t>);
        REQUIRE(cortex::BitOrWith<std::size_t, char32_t>);

        // std::size_t with Bit Specific Integers
        REQUIRE(cortex::BitOrWith<std::size_t, int8_t>);
        REQUIRE(cortex::BitOrWith<std::size_t, int16_t>);
        REQUIRE(cortex::BitOrWith<std::size_t, int32_t>);
        REQUIRE(cortex::BitOrWith<std::size_t, int64_t>);

        // std::size_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::BitOrWith<std::size_t, uint8_t>);
        REQUIRE(cortex::BitOrWith<std::size_t, uint16_t>);
        REQUIRE(cortex::BitOrWith<std::size_t, uint32_t>);
        REQUIRE(cortex::BitOrWith<std::size_t, uint64_t>);

        // std::size_t with Bit Specific Least Integers
        REQUIRE(cortex::BitOrWith<std::size_t, int_least8_t>);
        REQUIRE(cortex::BitOrWith<std::size_t, int_least16_t>);
        REQUIRE(cortex::BitOrWith<std::size_t, int_least32_t>);
        REQUIRE(cortex::BitOrWith<std::size_t, int_least64_t>);
    }
}

TEST_CASE("BitOrWith : Fast Integers")
{
    SECTION("int_fast8_t with _")
    {
        // int_fast8_t with Signed Integers
        REQUIRE(cortex::BitOrWith<int_fast8_t, int>);
        REQUIRE(cortex::BitOrWith<int_fast8_t, short>);
        REQUIRE(cortex::BitOrWith<int_fast8_t, long>);
        REQUIRE(cortex::BitOrWith<int_fast8_t, long long>);

        // int_fast8_t with Unsigned Integers
        REQUIRE(cortex::BitOrWith<int_fast8_t, unsigned>);
        REQUIRE(cortex::BitOrWith<int_fast8_t, unsigned short>);
        REQUIRE(cortex::BitOrWith<int_fast8_t, u_short>);
        REQUIRE(cortex::BitOrWith<int_fast8_t, unsigned long>);
        REQUIRE(cortex::BitOrWith<int_fast8_t, unsigned long long>);
        
        // int_fast8_t with Floating Point and Doubles
        REQUIRE(!cortex::BitOrWith<int_fast8_t, float>);
        REQUIRE(!cortex::BitOrWith<int_fast8_t, double>);
        REQUIRE(!cortex::BitOrWith<int_fast8_t, long double>);

        // int_fast8_t with std::strings and std::string_view
        REQUIRE(!cortex::BitOrWith<int_fast8_t, std::string>);
        REQUIRE(!cortex::BitOrWith<int_fast8_t, std::string_view>);
        REQUIRE(!cortex::BitOrWith<int_fast8_t, std::u8string>);
        REQUIRE(!cortex::BitOrWith<int_fast8_t, std::u16string>);
        REQUIRE(!cortex::BitOrWith<int_fast8_t, std::u32string>);

        // int_fast8_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitOrWith<long long, std::wstring>);
        REQUIRE(!cortex::BitOrWith<long long, std::wstring_view>);

        // int_fast8_t with Charaters
        REQUIRE(cortex::BitOrWith<int_fast8_t, char>);
        REQUIRE(cortex::BitOrWith<int_fast8_t, u_char>);
        REQUIRE(cortex::BitOrWith<int_fast8_t, wchar_t>);

        // int_fast8_t with Bit Specific Characters
        REQUIRE(cortex::BitOrWith<int_fast8_t, char8_t>);
        REQUIRE(cortex::BitOrWith<int_fast8_t, char16_t>);
        REQUIRE(cortex::BitOrWith<int_fast8_t, char32_t>);

        // int_fast8_t with Bit Specific Integers
        REQUIRE(cortex::BitOrWith<int_fast8_t, int8_t>);
        REQUIRE(cortex::BitOrWith<int_fast8_t, int16_t>);
        REQUIRE(cortex::BitOrWith<int_fast8_t, int32_t>);
        REQUIRE(cortex::BitOrWith<int_fast8_t, int64_t>);

        // int_fast8_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::BitOrWith<int_fast8_t, uint8_t>);
        REQUIRE(cortex::BitOrWith<int_fast8_t, uint16_t>);
        REQUIRE(cortex::BitOrWith<int_fast8_t, uint32_t>);
        REQUIRE(cortex::BitOrWith<int_fast8_t, uint64_t>);

        // int_fast8_t with Bit Specific Least Integers
        REQUIRE(cortex::BitOrWith<int_fast8_t, int_least8_t>);
        REQUIRE(cortex::BitOrWith<int_fast8_t, int_least16_t>);
        REQUIRE(cortex::BitOrWith<int_fast8_t, int_least32_t>);
        REQUIRE(cortex::BitOrWith<int_fast8_t, int_least64_t>);
    }

    SECTION("int_fast16_t with _")
    {
        // int_fast16_t with Signed Integers
        REQUIRE(cortex::BitOrWith<int_fast16_t, int>);
        REQUIRE(cortex::BitOrWith<int_fast16_t, short>);
        REQUIRE(cortex::BitOrWith<int_fast16_t, long>);
        REQUIRE(cortex::BitOrWith<int_fast16_t, long long>);

        // int_fast16_t with Unsigned Integers
        REQUIRE(cortex::BitOrWith<int_fast16_t, unsigned>);
        REQUIRE(cortex::BitOrWith<int_fast16_t, unsigned short>);
        REQUIRE(cortex::BitOrWith<int_fast16_t, u_short>);
        REQUIRE(cortex::BitOrWith<int_fast16_t, unsigned long>);
        REQUIRE(cortex::BitOrWith<int_fast16_t, unsigned long long>);
        
        // int_fast16_t with Floating Point and Doubles
        REQUIRE(!cortex::BitOrWith<int_fast16_t, float>);
        REQUIRE(!cortex::BitOrWith<int_fast16_t, double>);
        REQUIRE(!cortex::BitOrWith<int_fast16_t, long double>);

        // int_fast16_t with std::strings and std::string_view
        REQUIRE(!cortex::BitOrWith<int_fast16_t, std::string>);
        REQUIRE(!cortex::BitOrWith<int_fast16_t, std::string_view>);
        REQUIRE(!cortex::BitOrWith<int_fast16_t, std::u8string>);
        REQUIRE(!cortex::BitOrWith<int_fast16_t, std::u16string>);
        REQUIRE(!cortex::BitOrWith<int_fast16_t, std::u32string>);

        // int_fast16_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitOrWith<int_fast16_t, std::wstring>);
        REQUIRE(!cortex::BitOrWith<int_fast16_t, std::wstring_view>);

        // int_fast16_t with Charaters
        REQUIRE(cortex::BitOrWith<int_fast16_t, char>);
        REQUIRE(cortex::BitOrWith<int_fast16_t, u_char>);
        REQUIRE(cortex::BitOrWith<int_fast16_t, wchar_t>);

        // int_fast16_t with Bit Specific Characters
        REQUIRE(cortex::BitOrWith<int_fast16_t, char8_t>);
        REQUIRE(cortex::BitOrWith<int_fast16_t, char16_t>);
        REQUIRE(cortex::BitOrWith<int_fast16_t, char32_t>);

        // int_fast16_t with Bit Specific Integers
        REQUIRE(cortex::BitOrWith<int_fast16_t, int8_t>);
        REQUIRE(cortex::BitOrWith<int_fast16_t, int16_t>);
        REQUIRE(cortex::BitOrWith<int_fast16_t, int32_t>);
        REQUIRE(cortex::BitOrWith<int_fast16_t, int64_t>);

        // int_fast16_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::BitOrWith<int_fast16_t, uint8_t>);
        REQUIRE(cortex::BitOrWith<int_fast16_t, uint16_t>);
        REQUIRE(cortex::BitOrWith<int_fast16_t, uint32_t>);
        REQUIRE(cortex::BitOrWith<int_fast16_t, uint64_t>);

        // int_fast16_t with Bit Specific Least Integers
        REQUIRE(cortex::BitOrWith<int_fast16_t, int_least8_t>);
        REQUIRE(cortex::BitOrWith<int_fast16_t, int_least16_t>);
        REQUIRE(cortex::BitOrWith<int_fast16_t, int_least32_t>);
        REQUIRE(cortex::BitOrWith<int_fast16_t, int_least64_t>);
    }

    SECTION("int_fast32_t with _")
    {
        // int32 with Signed Integers
        REQUIRE(cortex::BitOrWith<int_fast32_t, int>);
        REQUIRE(cortex::BitOrWith<int_fast32_t, short>);
        REQUIRE(cortex::BitOrWith<int_fast32_t, long>);
        REQUIRE(cortex::BitOrWith<int_fast32_t, long long>);

        // int32 with Unsigned Integers
        REQUIRE(cortex::BitOrWith<int_fast32_t, unsigned>);
        REQUIRE(cortex::BitOrWith<int_fast32_t, unsigned short>);
        REQUIRE(cortex::BitOrWith<int_fast32_t, u_short>);
        REQUIRE(cortex::BitOrWith<int_fast32_t, unsigned long>);
        REQUIRE(cortex::BitOrWith<int_fast32_t, unsigned long long>);
        
        // int32 with Floating Point and Doubles
        REQUIRE(!cortex::BitOrWith<int_fast32_t, float>);
        REQUIRE(!cortex::BitOrWith<int_fast32_t, double>);
        REQUIRE(!cortex::BitOrWith<int_fast32_t, long double>);

        // int32 with std::strings and std::string_view
        REQUIRE(!cortex::BitOrWith<int_fast32_t, std::string>);
        REQUIRE(!cortex::BitOrWith<int_fast32_t, std::string_view>);
        REQUIRE(!cortex::BitOrWith<int_fast32_t, std::u8string>);
        REQUIRE(!cortex::BitOrWith<int_fast32_t, std::u16string>);
        REQUIRE(!cortex::BitOrWith<int_fast32_t, std::u32string>);

        // int32 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitOrWith<int_fast32_t, std::wstring>);
        REQUIRE(!cortex::BitOrWith<int_fast32_t, std::wstring_view>);

        // int_fast32_t with Charaters
        REQUIRE(cortex::BitOrWith<int_fast32_t, char>);
        REQUIRE(cortex::BitOrWith<int_fast32_t, u_char>);
        REQUIRE(cortex::BitOrWith<int_fast32_t, wchar_t>);

        // int_fast32_t with Bit Specific Characters
        REQUIRE(cortex::BitOrWith<int_fast32_t, char8_t>);
        REQUIRE(cortex::BitOrWith<int_fast32_t, char16_t>);
        REQUIRE(cortex::BitOrWith<int_fast32_t, char32_t>);

        // int_fast32_t with Bit Specific Integers
        REQUIRE(cortex::BitOrWith<int_fast32_t, int8_t>);
        REQUIRE(cortex::BitOrWith<int_fast32_t, int16_t>);
        REQUIRE(cortex::BitOrWith<int_fast32_t, int32_t>);
        REQUIRE(cortex::BitOrWith<int_fast32_t, int64_t>);

        // int_fast32_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::BitOrWith<int_fast32_t, uint8_t>);
        REQUIRE(cortex::BitOrWith<int_fast32_t, uint16_t>);
        REQUIRE(cortex::BitOrWith<int_fast32_t, uint32_t>);
        REQUIRE(cortex::BitOrWith<int_fast32_t, uint64_t>);

        // int_fast32_t with Bit Specific Least Integers
        REQUIRE(cortex::BitOrWith<int_fast32_t, int_least8_t>);
        REQUIRE(cortex::BitOrWith<int_fast32_t, int_least16_t>);
        REQUIRE(cortex::BitOrWith<int_fast32_t, int_least32_t>);
        REQUIRE(cortex::BitOrWith<int_fast32_t, int_least64_t>);
    }

    SECTION("int_fast64_t with _")
    {
        // int64 with Signed Integers
        REQUIRE(cortex::BitOrWith<int_fast64_t, int>);
        REQUIRE(cortex::BitOrWith<int_fast64_t, short>);
        REQUIRE(cortex::BitOrWith<int_fast64_t, long>);
        REQUIRE(cortex::BitOrWith<int_fast64_t, long long>);

        // int64 with Unsigned Integers
        REQUIRE(cortex::BitOrWith<int_fast64_t, unsigned>);
        REQUIRE(cortex::BitOrWith<int_fast64_t, unsigned short>);
        REQUIRE(cortex::BitOrWith<int_fast64_t, u_short>);
        REQUIRE(cortex::BitOrWith<int_fast64_t, unsigned long>);
        REQUIRE(cortex::BitOrWith<int_fast64_t, unsigned long long>);
        
        // int64 with Floating Point and Doubles
        REQUIRE(!cortex::BitOrWith<int_fast64_t, float>);
        REQUIRE(!cortex::BitOrWith<int_fast64_t, double>);
        REQUIRE(!cortex::BitOrWith<int_fast64_t, long double>);

        // int64 with std::strings and std::string_view
        REQUIRE(!cortex::BitOrWith<int_fast64_t, std::string>);
        REQUIRE(!cortex::BitOrWith<int_fast64_t, std::string_view>);
        REQUIRE(!cortex::BitOrWith<int_fast64_t, std::u8string>);
        REQUIRE(!cortex::BitOrWith<int_fast64_t, std::u16string>);
        REQUIRE(!cortex::BitOrWith<int_fast64_t, std::u32string>);

        // int64 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitOrWith<int_fast64_t, std::wstring>);
        REQUIRE(!cortex::BitOrWith<int_fast64_t, std::wstring_view>);

        // int_fast64_t with Charaters
        REQUIRE(cortex::BitOrWith<int_fast64_t, char>);
        REQUIRE(cortex::BitOrWith<int_fast64_t, u_char>);
        REQUIRE(cortex::BitOrWith<int_fast64_t, wchar_t>);

        // int_fast64_t with Bit Specific Characters
        REQUIRE(cortex::BitOrWith<int_fast64_t, char8_t>);
        REQUIRE(cortex::BitOrWith<int_fast64_t, char16_t>);
        REQUIRE(cortex::BitOrWith<int_fast64_t, char32_t>);

        // int_fast64_t with Bit Specific Integers
        REQUIRE(cortex::BitOrWith<int_fast64_t, int8_t>);
        REQUIRE(cortex::BitOrWith<int_fast64_t, int16_t>);
        REQUIRE(cortex::BitOrWith<int_fast64_t, int32_t>);
        REQUIRE(cortex::BitOrWith<int_fast64_t, int64_t>);

        // int_fast64_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::BitOrWith<int_fast64_t, uint8_t>);
        REQUIRE(cortex::BitOrWith<int_fast64_t, uint16_t>);
        REQUIRE(cortex::BitOrWith<int_fast64_t, uint32_t>);
        REQUIRE(cortex::BitOrWith<int_fast64_t, uint64_t>);

        // int_fast64_t with Bit Specific Least Integers
        REQUIRE(cortex::BitOrWith<int_fast64_t, int_least8_t>);
        REQUIRE(cortex::BitOrWith<int_fast64_t, int_least16_t>);
        REQUIRE(cortex::BitOrWith<int_fast64_t, int_least32_t>);
        REQUIRE(cortex::BitOrWith<int_fast64_t, int_least64_t>);
    }
}

TEST_CASE("BitOrWith : Least Integers")
{
    SECTION("int_least8_t with _")
    {
        // int_fast8_t with Signed Integers
        REQUIRE(cortex::BitOrWith<int_least8_t, int>);
        REQUIRE(cortex::BitOrWith<int_least8_t, short>);
        REQUIRE(cortex::BitOrWith<int_least8_t, long>);
        REQUIRE(cortex::BitOrWith<int_least8_t, long long>);

        // int_fast8_t with Unsigned Integers
        REQUIRE(cortex::BitOrWith<int_least8_t, unsigned>);
        REQUIRE(cortex::BitOrWith<int_least8_t, unsigned short>);
        REQUIRE(cortex::BitOrWith<int_least8_t, u_short>);
        REQUIRE(cortex::BitOrWith<int_least8_t, unsigned long>);
        REQUIRE(cortex::BitOrWith<int_least8_t, unsigned long long>);
        
        // int_fast8_t with Floating Point and Doubles
        REQUIRE(!cortex::BitOrWith<int_least8_t, float>);
        REQUIRE(!cortex::BitOrWith<int_least8_t, double>);
        REQUIRE(!cortex::BitOrWith<int_least8_t, long double>);

        // int_fast8_t with std::strings and std::string_view
        REQUIRE(!cortex::BitOrWith<int_least8_t, std::string>);
        REQUIRE(!cortex::BitOrWith<int_least8_t, std::string_view>);
        REQUIRE(!cortex::BitOrWith<int_least8_t, std::u8string>);
        REQUIRE(!cortex::BitOrWith<int_least8_t, std::u16string>);
        REQUIRE(!cortex::BitOrWith<int_least8_t, std::u32string>);

        // int_fast8_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitOrWith<long long, std::wstring>);
        REQUIRE(!cortex::BitOrWith<long long, std::wstring_view>);

        // int_fast8_t with Charaters
        REQUIRE(cortex::BitOrWith<int_least8_t, char>);
        REQUIRE(cortex::BitOrWith<int_least8_t, u_char>);
        REQUIRE(cortex::BitOrWith<int_least8_t, wchar_t>);

        // int_fast8_t with Bit Specific Characters
        REQUIRE(cortex::BitOrWith<int_least8_t, char8_t>);
        REQUIRE(cortex::BitOrWith<int_least8_t, char16_t>);
        REQUIRE(cortex::BitOrWith<int_least8_t, char32_t>);

        // int_fast8_t with Bit Specific Integers
        REQUIRE(cortex::BitOrWith<int_least8_t, int8_t>);
        REQUIRE(cortex::BitOrWith<int_least8_t, int16_t>);
        REQUIRE(cortex::BitOrWith<int_least8_t, int32_t>);
        REQUIRE(cortex::BitOrWith<int_least8_t, int64_t>);

        // int_fast8_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::BitOrWith<int_least8_t, uint8_t>);
        REQUIRE(cortex::BitOrWith<int_least8_t, uint16_t>);
        REQUIRE(cortex::BitOrWith<int_least8_t, uint32_t>);
        REQUIRE(cortex::BitOrWith<int_least8_t, uint64_t>);

        // int_fast8_t with Bit Specific Least Integers
        REQUIRE(cortex::BitOrWith<int_least8_t, int_least8_t>);
        REQUIRE(cortex::BitOrWith<int_least8_t, int_least16_t>);
        REQUIRE(cortex::BitOrWith<int_least8_t, int_least32_t>);
        REQUIRE(cortex::BitOrWith<int_least8_t, int_least64_t>);
    }

    SECTION("int_least16_t with _")
    {
        // int_fast16_t with Signed Integers
        REQUIRE(cortex::BitOrWith<int_least16_t, int>);
        REQUIRE(cortex::BitOrWith<int_least16_t, short>);
        REQUIRE(cortex::BitOrWith<int_least16_t, long>);
        REQUIRE(cortex::BitOrWith<int_least16_t, long long>);

        // int_fast16_t with Unsigned Integers
        REQUIRE(cortex::BitOrWith<int_least16_t, unsigned>);
        REQUIRE(cortex::BitOrWith<int_least16_t, unsigned short>);
        REQUIRE(cortex::BitOrWith<int_least16_t, u_short>);
        REQUIRE(cortex::BitOrWith<int_least16_t, unsigned long>);
        REQUIRE(cortex::BitOrWith<int_least16_t, unsigned long long>);
        
        // int_fast16_t with Floating Point and Doubles
        REQUIRE(!cortex::BitOrWith<int_least16_t, float>);
        REQUIRE(!cortex::BitOrWith<int_least16_t, double>);
        REQUIRE(!cortex::BitOrWith<int_least16_t, long double>);

        // int_fast16_t with std::strings and std::string_view
        REQUIRE(!cortex::BitOrWith<int_least16_t, std::string>);
        REQUIRE(!cortex::BitOrWith<int_least16_t, std::string_view>);
        REQUIRE(!cortex::BitOrWith<int_least16_t, std::u8string>);
        REQUIRE(!cortex::BitOrWith<int_least16_t, std::u16string>);
        REQUIRE(!cortex::BitOrWith<int_least16_t, std::u32string>);

        // int_fast16_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitOrWith<int_least16_t, std::wstring>);
        REQUIRE(!cortex::BitOrWith<int_least16_t, std::wstring_view>);

        // int_fast16_t with Charaters
        REQUIRE(cortex::BitOrWith<int_least16_t, char>);
        REQUIRE(cortex::BitOrWith<int_least16_t, u_char>);
        REQUIRE(cortex::BitOrWith<int_least16_t, wchar_t>);

        // int_fast16_t with Bit Specific Characters
        REQUIRE(cortex::BitOrWith<int_least16_t, char8_t>);
        REQUIRE(cortex::BitOrWith<int_least16_t, char16_t>);
        REQUIRE(cortex::BitOrWith<int_least16_t, char32_t>);

        // int_fast16_t with Bit Specific Integers
        REQUIRE(cortex::BitOrWith<int_least16_t, int8_t>);
        REQUIRE(cortex::BitOrWith<int_least16_t, int16_t>);
        REQUIRE(cortex::BitOrWith<int_least16_t, int32_t>);
        REQUIRE(cortex::BitOrWith<int_least16_t, int64_t>);

        // int_fast16_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::BitOrWith<int_least16_t, uint8_t>);
        REQUIRE(cortex::BitOrWith<int_least16_t, uint16_t>);
        REQUIRE(cortex::BitOrWith<int_least16_t, uint32_t>);
        REQUIRE(cortex::BitOrWith<int_least16_t, uint64_t>);

        // int_fast16_t with Bit Specific Least Integers
        REQUIRE(cortex::BitOrWith<int_least16_t, int_least8_t>);
        REQUIRE(cortex::BitOrWith<int_least16_t, int_least16_t>);
        REQUIRE(cortex::BitOrWith<int_least16_t, int_least32_t>);
        REQUIRE(cortex::BitOrWith<int_least16_t, int_least64_t>);
    }

    SECTION("int_least32_t with _")
    {
        // int32 with Signed Integers
        REQUIRE(cortex::BitOrWith<int_least32_t, int>);
        REQUIRE(cortex::BitOrWith<int_least32_t, short>);
        REQUIRE(cortex::BitOrWith<int_least32_t, long>);
        REQUIRE(cortex::BitOrWith<int_least32_t, long long>);

        // int32 with Unsigned Integers
        REQUIRE(cortex::BitOrWith<int_least32_t, unsigned>);
        REQUIRE(cortex::BitOrWith<int_least32_t, unsigned short>);
        REQUIRE(cortex::BitOrWith<int_least32_t, u_short>);
        REQUIRE(cortex::BitOrWith<int_least32_t, unsigned long>);
        REQUIRE(cortex::BitOrWith<int_least32_t, unsigned long long>);
        
        // int32 with Floating Point and Doubles
        REQUIRE(!cortex::BitOrWith<int_least32_t, float>);
        REQUIRE(!cortex::BitOrWith<int_least32_t, double>);
        REQUIRE(!cortex::BitOrWith<int_least32_t, long double>);

        // int32 with std::strings and std::string_view
        REQUIRE(!cortex::BitOrWith<int_least32_t, std::string>);
        REQUIRE(!cortex::BitOrWith<int_least32_t, std::string_view>);
        REQUIRE(!cortex::BitOrWith<int_least32_t, std::u8string>);
        REQUIRE(!cortex::BitOrWith<int_least32_t, std::u16string>);
        REQUIRE(!cortex::BitOrWith<int_least32_t, std::u32string>);

        // int32 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitOrWith<int_least32_t, std::wstring>);
        REQUIRE(!cortex::BitOrWith<int_least32_t, std::wstring_view>);

        // int_fast32_t with Charaters
        REQUIRE(cortex::BitOrWith<int_least32_t, char>);
        REQUIRE(cortex::BitOrWith<int_least32_t, u_char>);
        REQUIRE(cortex::BitOrWith<int_least32_t, wchar_t>);

        // int_fast32_t with Bit Specific Characters
        REQUIRE(cortex::BitOrWith<int_least32_t, char8_t>);
        REQUIRE(cortex::BitOrWith<int_least32_t, char16_t>);
        REQUIRE(cortex::BitOrWith<int_least32_t, char32_t>);

        // int_fast32_t with Bit Specific Integers
        REQUIRE(cortex::BitOrWith<int_least32_t, int8_t>);
        REQUIRE(cortex::BitOrWith<int_least32_t, int16_t>);
        REQUIRE(cortex::BitOrWith<int_least32_t, int32_t>);
        REQUIRE(cortex::BitOrWith<int_least32_t, int64_t>);

        // int_fast32_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::BitOrWith<int_least32_t, uint8_t>);
        REQUIRE(cortex::BitOrWith<int_least32_t, uint16_t>);
        REQUIRE(cortex::BitOrWith<int_least32_t, uint32_t>);
        REQUIRE(cortex::BitOrWith<int_least32_t, uint64_t>);

        // int_fast32_t with Bit Specific Least Integers
        REQUIRE(cortex::BitOrWith<int_least32_t, int_least8_t>);
        REQUIRE(cortex::BitOrWith<int_least32_t, int_least16_t>);
        REQUIRE(cortex::BitOrWith<int_least32_t, int_least32_t>);
        REQUIRE(cortex::BitOrWith<int_least32_t, int_least64_t>);
    }

    SECTION("int_least64_t with _")
    {
        // int64 with Signed Integers
        REQUIRE(cortex::BitOrWith<int_least64_t, int>);
        REQUIRE(cortex::BitOrWith<int_least64_t, short>);
        REQUIRE(cortex::BitOrWith<int_least64_t, long>);
        REQUIRE(cortex::BitOrWith<int_least64_t, long long>);

        // int64 with Unsigned Integers
        REQUIRE(cortex::BitOrWith<int_least64_t, unsigned>);
        REQUIRE(cortex::BitOrWith<int_least64_t, unsigned short>);
        REQUIRE(cortex::BitOrWith<int_least64_t, u_short>);
        REQUIRE(cortex::BitOrWith<int_least64_t, unsigned long>);
        REQUIRE(cortex::BitOrWith<int_least64_t, unsigned long long>);
        
        // int64 with Floating Point and Doubles
        REQUIRE(!cortex::BitOrWith<int_least64_t, float>);
        REQUIRE(!cortex::BitOrWith<int_least64_t, double>);
        REQUIRE(!cortex::BitOrWith<int_least64_t, long double>);

        // int64 with std::strings and std::string_view
        REQUIRE(!cortex::BitOrWith<int_least64_t, std::string>);
        REQUIRE(!cortex::BitOrWith<int_least64_t, std::string_view>);
        REQUIRE(!cortex::BitOrWith<int_least64_t, std::u8string>);
        REQUIRE(!cortex::BitOrWith<int_least64_t, std::u16string>);
        REQUIRE(!cortex::BitOrWith<int_least64_t, std::u32string>);

        // int64 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitOrWith<int_least64_t, std::wstring>);
        REQUIRE(!cortex::BitOrWith<int_least64_t, std::wstring_view>);

        // int_fast64_t with Charaters
        REQUIRE(cortex::BitOrWith<int_least64_t, char>);
        REQUIRE(cortex::BitOrWith<int_least64_t, u_char>);
        REQUIRE(cortex::BitOrWith<int_least64_t, wchar_t>);

        // int_fast64_t with Bit Specific Characters
        REQUIRE(cortex::BitOrWith<int_least64_t, char8_t>);
        REQUIRE(cortex::BitOrWith<int_least64_t, char16_t>);
        REQUIRE(cortex::BitOrWith<int_least64_t, char32_t>);

        // int_fast64_t with Bit Specific Integers
        REQUIRE(cortex::BitOrWith<int_least64_t, int8_t>);
        REQUIRE(cortex::BitOrWith<int_least64_t, int16_t>);
        REQUIRE(cortex::BitOrWith<int_least64_t, int32_t>);
        REQUIRE(cortex::BitOrWith<int_least64_t, int64_t>);

        // int_fast64_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::BitOrWith<int_least64_t, uint8_t>);
        REQUIRE(cortex::BitOrWith<int_least64_t, uint16_t>);
        REQUIRE(cortex::BitOrWith<int_least64_t, uint32_t>);
        REQUIRE(cortex::BitOrWith<int_least64_t, uint64_t>);

        // int_fast64_t with Bit Specific Least Integers
        REQUIRE(cortex::BitOrWith<int_least64_t, int_least8_t>);
        REQUIRE(cortex::BitOrWith<int_least64_t, int_least16_t>);
        REQUIRE(cortex::BitOrWith<int_least64_t, int_least32_t>);
        REQUIRE(cortex::BitOrWith<int_least64_t, int_least64_t>);
    }
}