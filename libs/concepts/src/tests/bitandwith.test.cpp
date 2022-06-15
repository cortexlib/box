#include <catch2/catch.hpp>
#include <concepts.hpp>

TEST_CASE("BitAndWith : Signed Integers")
{
    SECTION("Int with _")
    {
        // Int with Signed Integers
        REQUIRE(cortex::BitAndWith<int, int>);
        REQUIRE(cortex::BitAndWith<int, short>);
        REQUIRE(cortex::BitAndWith<int, long>);
        REQUIRE(cortex::BitAndWith<int, long long>);

        // Int with Unsigned Integers
        REQUIRE(cortex::BitAndWith<int, unsigned>);
        REQUIRE(cortex::BitAndWith<int, unsigned short>);
        REQUIRE(cortex::BitAndWith<int, u_short>);
        REQUIRE(cortex::BitAndWith<int, unsigned long>);
        REQUIRE(cortex::BitAndWith<int, unsigned long long>);
        
        // Integers with Floating Point and Doubles
        REQUIRE(!cortex::BitAndWith<int, float>);
        REQUIRE(!cortex::BitAndWith<int, double>);
        REQUIRE(!cortex::BitAndWith<int, long double>);

        // Integers with std::strings and std::string_view
        REQUIRE(!cortex::BitAndWith<int, std::string>);
        REQUIRE(!cortex::BitAndWith<int, std::string_view>);
        REQUIRE(!cortex::BitAndWith<int, std::u8string>);
        REQUIRE(!cortex::BitAndWith<int, std::u16string>);
        REQUIRE(!cortex::BitAndWith<int, std::u32string>);

        // Integers with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitAndWith<int, std::wstring>);
        REQUIRE(!cortex::BitAndWith<int, std::wstring_view>);

        // Integers with Charaters
        REQUIRE(cortex::BitAndWith<int, char>);
        REQUIRE(cortex::BitAndWith<int, u_char>);
        REQUIRE(cortex::BitAndWith<int, wchar_t>);

        // Integers with Bit Specific Characters
        REQUIRE(cortex::BitAndWith<int, char8_t>);
        REQUIRE(cortex::BitAndWith<int, char16_t>);
        REQUIRE(cortex::BitAndWith<int, char32_t>);

        // Integers with Bit Specific Integers
        REQUIRE(cortex::BitAndWith<int, int8_t>);
        REQUIRE(cortex::BitAndWith<int, int16_t>);
        REQUIRE(cortex::BitAndWith<int, int32_t>);
        REQUIRE(cortex::BitAndWith<int, int64_t>);

        // Integers with Bit Specific Unsigned Integers
        REQUIRE(cortex::BitAndWith<int, uint8_t>);
        REQUIRE(cortex::BitAndWith<int, uint16_t>);
        REQUIRE(cortex::BitAndWith<int, uint32_t>);
        REQUIRE(cortex::BitAndWith<int, uint64_t>);

        // Integers with Bit Specific Least Integers
        REQUIRE(cortex::BitAndWith<int, int_least8_t>);
        REQUIRE(cortex::BitAndWith<int, int_least16_t>);
        REQUIRE(cortex::BitAndWith<int, int_least32_t>);
        REQUIRE(cortex::BitAndWith<int, int_least64_t>);
    }

    SECTION("Short with _")
    {
        // Short with Signed Integers
        REQUIRE(cortex::BitAndWith<short, int>);
        REQUIRE(cortex::BitAndWith<short, short>);
        REQUIRE(cortex::BitAndWith<short, long>);
        REQUIRE(cortex::BitAndWith<short, long long>);

        // Short with Unsigned Integers
        REQUIRE(cortex::BitAndWith<short, unsigned>);
        REQUIRE(cortex::BitAndWith<short, unsigned short>);
        REQUIRE(cortex::BitAndWith<short, u_short>);
        REQUIRE(cortex::BitAndWith<short, unsigned long>);
        REQUIRE(cortex::BitAndWith<short, unsigned long long>);
        
        // Short with Floating Point and Doubles
        REQUIRE(!cortex::BitAndWith<short, float>);
        REQUIRE(!cortex::BitAndWith<short, double>);
        REQUIRE(!cortex::BitAndWith<short, long double>);

        // Short with std::strings and std::string_view
        REQUIRE(!cortex::BitAndWith<short, std::string>);
        REQUIRE(!cortex::BitAndWith<short, std::string_view>);
        REQUIRE(!cortex::BitAndWith<short, std::u8string>);
        REQUIRE(!cortex::BitAndWith<short, std::u16string>);
        REQUIRE(!cortex::BitAndWith<short, std::u32string>);

        // Short with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitAndWith<short, std::wstring>);
        REQUIRE(!cortex::BitAndWith<short, std::wstring_view>);

        // Short with Charaters
        REQUIRE(cortex::BitAndWith<short, char>);
        REQUIRE(cortex::BitAndWith<short, u_char>);
        REQUIRE(cortex::BitAndWith<short, wchar_t>);

        // Short with Bit Specific Characters
        REQUIRE(cortex::BitAndWith<short, char8_t>);
        REQUIRE(cortex::BitAndWith<short, char16_t>);
        REQUIRE(cortex::BitAndWith<short, char32_t>);

        // Short with Bit Specific Short
        REQUIRE(cortex::BitAndWith<short, int8_t>);
        REQUIRE(cortex::BitAndWith<short, int16_t>);
        REQUIRE(cortex::BitAndWith<short, int32_t>);
        REQUIRE(cortex::BitAndWith<short, int64_t>);

        // Short with Bit Specific Unsigned Short
        REQUIRE(cortex::BitAndWith<short, uint8_t>);
        REQUIRE(cortex::BitAndWith<short, uint16_t>);
        REQUIRE(cortex::BitAndWith<short, uint32_t>);
        REQUIRE(cortex::BitAndWith<short, uint64_t>);

        // Short with Bit Specific Least Integers
        REQUIRE(cortex::BitAndWith<short, int_least8_t>);
        REQUIRE(cortex::BitAndWith<short, int_least16_t>);
        REQUIRE(cortex::BitAndWith<short, int_least32_t>);
        REQUIRE(cortex::BitAndWith<short, int_least64_t>);
    }

    SECTION("Long with _")
    {
        // Long with Signed Integers
        REQUIRE(cortex::BitAndWith<long, int>);
        REQUIRE(cortex::BitAndWith<long, short>);
        REQUIRE(cortex::BitAndWith<long, long>);
        REQUIRE(cortex::BitAndWith<long, long long>);

        // Long with Unsigned Integers
        REQUIRE(cortex::BitAndWith<long, unsigned>);
        REQUIRE(cortex::BitAndWith<long, unsigned short>);
        REQUIRE(cortex::BitAndWith<long, u_short>);
        REQUIRE(cortex::BitAndWith<long, unsigned long>);
        REQUIRE(cortex::BitAndWith<long, unsigned long long>);
        
        // Long with Floating Point and Doubles
        REQUIRE(!cortex::BitAndWith<long, float>);
        REQUIRE(!cortex::BitAndWith<long, double>);
        REQUIRE(!cortex::BitAndWith<long, long double>);

        // Long with std::strings and std::string_view
        REQUIRE(!cortex::BitAndWith<long, std::string>);
        REQUIRE(!cortex::BitAndWith<long, std::string_view>);
        REQUIRE(!cortex::BitAndWith<long, std::u8string>);
        REQUIRE(!cortex::BitAndWith<long, std::u16string>);
        REQUIRE(!cortex::BitAndWith<long, std::u32string>);

        // Long with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitAndWith<long, std::wstring>);
        REQUIRE(!cortex::BitAndWith<long, std::wstring_view>);

        // Long with Charaters
        REQUIRE(cortex::BitAndWith<long, char>);
        REQUIRE(cortex::BitAndWith<long, u_char>);
        REQUIRE(cortex::BitAndWith<long, wchar_t>);

        // Long with Bit Specific Characters
        REQUIRE(cortex::BitAndWith<long, char8_t>);
        REQUIRE(cortex::BitAndWith<long, char16_t>);
        REQUIRE(cortex::BitAndWith<long, char32_t>);

        // Long with Bit Specific Long
        REQUIRE(cortex::BitAndWith<long, int8_t>);
        REQUIRE(cortex::BitAndWith<long, int16_t>);
        REQUIRE(cortex::BitAndWith<long, int32_t>);
        REQUIRE(cortex::BitAndWith<long, int64_t>);

        // Long with Bit Specific Unsigned Long
        REQUIRE(cortex::BitAndWith<long, uint8_t>);
        REQUIRE(cortex::BitAndWith<long, uint16_t>);
        REQUIRE(cortex::BitAndWith<long, uint32_t>);
        REQUIRE(cortex::BitAndWith<long, uint64_t>);

        // Long with Bit Specific Least Integers
        REQUIRE(cortex::BitAndWith<long, int_least8_t>);
        REQUIRE(cortex::BitAndWith<long, int_least16_t>);
        REQUIRE(cortex::BitAndWith<long, int_least32_t>);
        REQUIRE(cortex::BitAndWith<long, int_least64_t>);
    }

    SECTION("Long Long with _")
    {
        // Signed Integers
        REQUIRE(cortex::BitAndWith<long long, int>);
        REQUIRE(cortex::BitAndWith<long long, short>);
        REQUIRE(cortex::BitAndWith<long long, long>);
        REQUIRE(cortex::BitAndWith<long long, long long>);

        // Unsigned Integers
        REQUIRE(cortex::BitAndWith<long long, unsigned>);
        REQUIRE(cortex::BitAndWith<long long, unsigned short>);
        REQUIRE(cortex::BitAndWith<long long, u_short>);
        REQUIRE(cortex::BitAndWith<long long, unsigned long>);
        REQUIRE(cortex::BitAndWith<long long, unsigned long long>);
        
        // Integers with Floating Point and Doubles
        REQUIRE(!cortex::BitAndWith<long long, float>);
        REQUIRE(!cortex::BitAndWith<long long, double>);
        REQUIRE(!cortex::BitAndWith<long long, long double>);

        // Integers with std::strings and std::string_view
        REQUIRE(!cortex::BitAndWith<long long, std::string>);
        REQUIRE(!cortex::BitAndWith<long long, std::string_view>);
        REQUIRE(!cortex::BitAndWith<long long, std::u8string>);
        REQUIRE(!cortex::BitAndWith<long long, std::u16string>);
        REQUIRE(!cortex::BitAndWith<long long, std::u32string>);

        // Integers with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitAndWith<long long, std::wstring>);
        REQUIRE(!cortex::BitAndWith<long long, std::wstring_view>);

        // Integers with Charaters
        REQUIRE(cortex::BitAndWith<long long, char>);
        REQUIRE(cortex::BitAndWith<long long, u_char>);
        REQUIRE(cortex::BitAndWith<long long, wchar_t>);

        // Integers with Bit Specific Characters
        REQUIRE(cortex::BitAndWith<long long, char8_t>);
        REQUIRE(cortex::BitAndWith<long long, char16_t>);
        REQUIRE(cortex::BitAndWith<long long, char32_t>);

        // Integers with Bit Specific Integers
        REQUIRE(cortex::BitAndWith<long long, int8_t>);
        REQUIRE(cortex::BitAndWith<long long, int16_t>);
        REQUIRE(cortex::BitAndWith<long long, int32_t>);
        REQUIRE(cortex::BitAndWith<long long, int64_t>);

        // Integers with Bit Specific Unsigned Integers
        REQUIRE(cortex::BitAndWith<long long, uint8_t>);
        REQUIRE(cortex::BitAndWith<long long, uint16_t>);
        REQUIRE(cortex::BitAndWith<long long, uint32_t>);
        REQUIRE(cortex::BitAndWith<long long, uint64_t>);

        // Long Long with Bit Specific Least Integers
        REQUIRE(cortex::BitAndWith<long long, int_least8_t>);
        REQUIRE(cortex::BitAndWith<long long, int_least16_t>);
        REQUIRE(cortex::BitAndWith<long long, int_least32_t>);
        REQUIRE(cortex::BitAndWith<long long, int_least64_t>);
    }
}

TEST_CASE("BitAndWith: Unsigned Integers")
{
    SECTION("Unsigned Int with _")
    {
        // Unsigned Integers with Signed Integers
        REQUIRE(cortex::BitAndWith<unsigned int, int>);
        REQUIRE(cortex::BitAndWith<unsigned int, short>);
        REQUIRE(cortex::BitAndWith<unsigned int, long>);
        REQUIRE(cortex::BitAndWith<unsigned int, long long>);

        // Unsigned Integers with Unsigned Integers
        REQUIRE(cortex::BitAndWith<unsigned int, unsigned>);
        REQUIRE(cortex::BitAndWith<unsigned int, unsigned short>);
        REQUIRE(cortex::BitAndWith<unsigned int, u_short>);
        REQUIRE(cortex::BitAndWith<unsigned int, unsigned long>);
        REQUIRE(cortex::BitAndWith<unsigned int, unsigned long long>);
        
        // Unsigned Integers with Floating Point and Doubles
        REQUIRE(!cortex::BitAndWith<unsigned int, float>);
        REQUIRE(!cortex::BitAndWith<unsigned int, double>);
        REQUIRE(!cortex::BitAndWith<unsigned int, long double>);

        // Unsigned Integers with std::strings and std::string_view
        REQUIRE(!cortex::BitAndWith<unsigned int, std::string>);
        REQUIRE(!cortex::BitAndWith<unsigned int, std::string_view>);
        REQUIRE(!cortex::BitAndWith<unsigned int, std::u8string>);
        REQUIRE(!cortex::BitAndWith<unsigned int, std::u16string>);
        REQUIRE(!cortex::BitAndWith<unsigned int, std::u32string>);

        // Unsigned Integers with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitAndWith<unsigned long long, std::wstring>);
        REQUIRE(!cortex::BitAndWith<unsigned long long, std::wstring_view>);

        // Unsigned Integers with Charaters
        REQUIRE(cortex::BitAndWith<unsigned int, char>);
        REQUIRE(cortex::BitAndWith<unsigned int, u_char>);
        REQUIRE(cortex::BitAndWith<unsigned int, wchar_t>);

        // Unsigned Integers with Bit Specific Characters
        REQUIRE(cortex::BitAndWith<unsigned int, char8_t>);
        REQUIRE(cortex::BitAndWith<unsigned int, char16_t>);
        REQUIRE(cortex::BitAndWith<unsigned int, char32_t>);

        // Unsigned Integers with Bit Specific Integers
        REQUIRE(cortex::BitAndWith<unsigned int, int8_t>);
        REQUIRE(cortex::BitAndWith<unsigned int, int16_t>);
        REQUIRE(cortex::BitAndWith<unsigned int, int32_t>);
        REQUIRE(cortex::BitAndWith<unsigned int, int64_t>);

        // Unsigned Integers with Bit Specific Unsigned Integers
        REQUIRE(cortex::BitAndWith<unsigned int, uint8_t>);
        REQUIRE(cortex::BitAndWith<unsigned int, uint16_t>);
        REQUIRE(cortex::BitAndWith<unsigned int, uint32_t>);
        REQUIRE(cortex::BitAndWith<unsigned int, uint64_t>);

        // Unsigned Integers with Bit Specific Least Integers
        REQUIRE(cortex::BitAndWith<unsigned int, int_least8_t>);
        REQUIRE(cortex::BitAndWith<unsigned int, int_least16_t>);
        REQUIRE(cortex::BitAndWith<unsigned int, int_least32_t>);
        REQUIRE(cortex::BitAndWith<unsigned int, int_least64_t>);
    }

    SECTION("Unsigned Short with _")
    {
        // Unsigned Short with Signed Integers
        REQUIRE(cortex::BitAndWith<unsigned short, int>);
        REQUIRE(cortex::BitAndWith<unsigned short, short>);
        REQUIRE(cortex::BitAndWith<unsigned short, long>);
        REQUIRE(cortex::BitAndWith<unsigned short, long long>);

        // Unsigned Short with Unsigned Integers
        REQUIRE(cortex::BitAndWith<unsigned short, unsigned>);
        REQUIRE(cortex::BitAndWith<unsigned short, unsigned short>);
        REQUIRE(cortex::BitAndWith<unsigned short, u_short>);
        REQUIRE(cortex::BitAndWith<unsigned short, unsigned long>);
        REQUIRE(cortex::BitAndWith<unsigned short, unsigned long long>);
        
        // Unsigned Short with Floating Point and Doubles
        REQUIRE(!cortex::BitAndWith<unsigned short, float>);
        REQUIRE(!cortex::BitAndWith<unsigned short, double>);
        REQUIRE(!cortex::BitAndWith<unsigned short, long double>);

        // Unsigned Short with std::strings and std::string_view
        REQUIRE(!cortex::BitAndWith<unsigned short, std::string>);
        REQUIRE(!cortex::BitAndWith<unsigned short, std::string_view>);
        REQUIRE(!cortex::BitAndWith<unsigned short, std::u8string>);
        REQUIRE(!cortex::BitAndWith<unsigned short, std::u16string>);
        REQUIRE(!cortex::BitAndWith<unsigned short, std::u32string>);

        // Unsigned Short with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitAndWith<unsigned short, std::wstring>);
        REQUIRE(!cortex::BitAndWith<unsigned short, std::wstring_view>);

        // Unsigned Short with Charaters
        REQUIRE(cortex::BitAndWith<unsigned short, char>);
        REQUIRE(cortex::BitAndWith<unsigned short, u_char>);
        REQUIRE(cortex::BitAndWith<unsigned short, wchar_t>);

        // Unsigned Short with Bit Specific Characters
        REQUIRE(cortex::BitAndWith<unsigned short, char8_t>);
        REQUIRE(cortex::BitAndWith<unsigned short, char16_t>);
        REQUIRE(cortex::BitAndWith<unsigned short, char32_t>);

        // Unsigned Short with Bit Specific Short
        REQUIRE(cortex::BitAndWith<unsigned short, int8_t>);
        REQUIRE(cortex::BitAndWith<unsigned short, int16_t>);
        REQUIRE(cortex::BitAndWith<unsigned short, int32_t>);
        REQUIRE(cortex::BitAndWith<unsigned short, int64_t>);

        // Unsigned Short with Bit Specific Unsigned Short
        REQUIRE(cortex::BitAndWith<unsigned short, uint8_t>);
        REQUIRE(cortex::BitAndWith<unsigned short, uint16_t>);
        REQUIRE(cortex::BitAndWith<unsigned short, uint32_t>);
        REQUIRE(cortex::BitAndWith<unsigned short, uint64_t>);

        // Unsigned Short with Bit Specific Least Integers
        REQUIRE(cortex::BitAndWith<unsigned short, int_least8_t>);
        REQUIRE(cortex::BitAndWith<unsigned short, int_least16_t>);
        REQUIRE(cortex::BitAndWith<unsigned short, int_least32_t>);
        REQUIRE(cortex::BitAndWith<unsigned short, int_least64_t>);
    }

    SECTION("u_short with _")
    {
        // u_short with Signed Integers
        REQUIRE(cortex::BitAndWith<u_short, int>);
        REQUIRE(cortex::BitAndWith<u_short, short>);
        REQUIRE(cortex::BitAndWith<u_short, long>);
        REQUIRE(cortex::BitAndWith<u_short, long long>);

        // u_short with Unsigned Integers
        REQUIRE(cortex::BitAndWith<u_short, unsigned>);
        REQUIRE(cortex::BitAndWith<u_short, unsigned short>);
        REQUIRE(cortex::BitAndWith<u_short, u_short>);
        REQUIRE(cortex::BitAndWith<u_short, unsigned long>);
        REQUIRE(cortex::BitAndWith<u_short, unsigned long long>);
        
        // u_short with Floating Point and Doubles
        REQUIRE(!cortex::BitAndWith<u_short, float>);
        REQUIRE(!cortex::BitAndWith<u_short, double>);
        REQUIRE(!cortex::BitAndWith<u_short, long double>);

        // u_short with std::strings and std::string_view
        REQUIRE(!cortex::BitAndWith<u_short, std::string>);
        REQUIRE(!cortex::BitAndWith<u_short, std::string_view>);
        REQUIRE(!cortex::BitAndWith<u_short, std::u8string>);
        REQUIRE(!cortex::BitAndWith<u_short, std::u16string>);
        REQUIRE(!cortex::BitAndWith<u_short, std::u32string>);

        // u_short with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitAndWith<u_short, std::wstring>);
        REQUIRE(!cortex::BitAndWith<u_short, std::wstring_view>);

        // u_short with Charaters
        REQUIRE(cortex::BitAndWith<u_short, char>);
        REQUIRE(cortex::BitAndWith<u_short, u_char>);
        REQUIRE(cortex::BitAndWith<u_short, wchar_t>);

        // u_short with Bit Specific Characters
        REQUIRE(cortex::BitAndWith<u_short, char8_t>);
        REQUIRE(cortex::BitAndWith<u_short, char16_t>);
        REQUIRE(cortex::BitAndWith<u_short, char32_t>);

        // u_short with Bit Specific Short
        REQUIRE(cortex::BitAndWith<u_short, int8_t>);
        REQUIRE(cortex::BitAndWith<u_short, int16_t>);
        REQUIRE(cortex::BitAndWith<u_short, int32_t>);
        REQUIRE(cortex::BitAndWith<u_short, int64_t>);

        // u_short with Bit Specific Unsigned Short
        REQUIRE(cortex::BitAndWith<u_short, uint8_t>);
        REQUIRE(cortex::BitAndWith<u_short, uint16_t>);
        REQUIRE(cortex::BitAndWith<u_short, uint32_t>);
        REQUIRE(cortex::BitAndWith<u_short, uint64_t>);

        // u_short with Bit Specific Least Integers
        REQUIRE(cortex::BitAndWith<u_short, int_least8_t>);
        REQUIRE(cortex::BitAndWith<u_short, int_least16_t>);
        REQUIRE(cortex::BitAndWith<u_short, int_least32_t>);
        REQUIRE(cortex::BitAndWith<u_short, int_least64_t>);
    }

    SECTION("Unsigned Long with _")
    {
        // Unsigned Long with Signed Integers
        REQUIRE(cortex::BitAndWith<unsigned long, int>);
        REQUIRE(cortex::BitAndWith<unsigned long, short>);
        REQUIRE(cortex::BitAndWith<unsigned long, long>);
        REQUIRE(cortex::BitAndWith<unsigned long, long long>);

        // Unsigned Long with Unsigned Integers
        REQUIRE(cortex::BitAndWith<unsigned long, unsigned>);
        REQUIRE(cortex::BitAndWith<unsigned long, unsigned short>);
        REQUIRE(cortex::BitAndWith<unsigned long, u_short>);
        REQUIRE(cortex::BitAndWith<unsigned long, unsigned long>);
        REQUIRE(cortex::BitAndWith<unsigned long, unsigned long long>);
        
        // Unsigned Long with Floating Point and Doubles
        REQUIRE(!cortex::BitAndWith<unsigned long, float>);
        REQUIRE(!cortex::BitAndWith<unsigned long, double>);
        REQUIRE(!cortex::BitAndWith<unsigned long, long double>);

        // Unsigned Long with std::strings and std::string_view
        REQUIRE(!cortex::BitAndWith<unsigned long, std::string>);
        REQUIRE(!cortex::BitAndWith<unsigned long, std::string_view>);
        REQUIRE(!cortex::BitAndWith<unsigned long, std::u8string>);
        REQUIRE(!cortex::BitAndWith<unsigned long, std::u16string>);
        REQUIRE(!cortex::BitAndWith<unsigned long, std::u32string>);

        // Unsigned Long with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitAndWith<unsigned long, std::wstring>);
        REQUIRE(!cortex::BitAndWith<unsigned long, std::wstring_view>);

        // Unsigned Long with Charaters
        REQUIRE(cortex::BitAndWith<unsigned long, char>);
        REQUIRE(cortex::BitAndWith<unsigned long, u_char>);
        REQUIRE(cortex::BitAndWith<unsigned long, wchar_t>);

        // Unsigned Long with Bit Specific Characters
        REQUIRE(cortex::BitAndWith<unsigned long, char8_t>);
        REQUIRE(cortex::BitAndWith<unsigned long, char16_t>);
        REQUIRE(cortex::BitAndWith<unsigned long, char32_t>);

        // Unsigned Long with Bit Specific Long
        REQUIRE(cortex::BitAndWith<unsigned long, int8_t>);
        REQUIRE(cortex::BitAndWith<unsigned long, int16_t>);
        REQUIRE(cortex::BitAndWith<unsigned long, int32_t>);
        REQUIRE(cortex::BitAndWith<unsigned long, int64_t>);

        // Unsigned Long with Bit Specific Unsigned Long
        REQUIRE(cortex::BitAndWith<unsigned long, uint8_t>);
        REQUIRE(cortex::BitAndWith<unsigned long, uint16_t>);
        REQUIRE(cortex::BitAndWith<unsigned long, uint32_t>);
        REQUIRE(cortex::BitAndWith<unsigned long, uint64_t>);

        // Unsigned Long with Bit Specific Least Integers
        REQUIRE(cortex::BitAndWith<unsigned long, int_least8_t>);
        REQUIRE(cortex::BitAndWith<unsigned long, int_least16_t>);
        REQUIRE(cortex::BitAndWith<unsigned long, int_least32_t>);
        REQUIRE(cortex::BitAndWith<unsigned long, int_least64_t>);
    }

    SECTION("Unsigned Long Long with _")
    {
        // Unsigned Long Long with Signed Integers
        REQUIRE(cortex::BitAndWith<unsigned long long, int>);
        REQUIRE(cortex::BitAndWith<unsigned long long, short>);
        REQUIRE(cortex::BitAndWith<unsigned long long, long>);
        REQUIRE(cortex::BitAndWith<unsigned long long, long long>);

        // Unsigned Long Long with Unsigned Integers
        REQUIRE(cortex::BitAndWith<unsigned long long, unsigned>);
        REQUIRE(cortex::BitAndWith<unsigned long long, unsigned short>);
        REQUIRE(cortex::BitAndWith<unsigned long long, u_short>);
        REQUIRE(cortex::BitAndWith<unsigned long long, unsigned long>);
        REQUIRE(cortex::BitAndWith<unsigned long long, unsigned long long>);
        
        // Unsigned Long Long with Floating Point and Doubles
        REQUIRE(!cortex::BitAndWith<unsigned long long, float>);
        REQUIRE(!cortex::BitAndWith<unsigned long long, double>);
        REQUIRE(!cortex::BitAndWith<unsigned long long, long double>);

        // Unsigned Long Long with std::strings and std::string_view
        REQUIRE(!cortex::BitAndWith<unsigned long long, std::string>);
        REQUIRE(!cortex::BitAndWith<unsigned long long, std::string_view>);
        REQUIRE(!cortex::BitAndWith<unsigned long long, std::u8string>);
        REQUIRE(!cortex::BitAndWith<unsigned long long, std::u16string>);
        REQUIRE(!cortex::BitAndWith<unsigned long long, std::u32string>);

        // Unsigned Long Long with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitAndWith<unsigned long long, std::wstring>);
        REQUIRE(!cortex::BitAndWith<unsigned long long, std::wstring_view>);

        // Unsigned Long Long with Charaters
        REQUIRE(cortex::BitAndWith<unsigned long long, char>);
        REQUIRE(cortex::BitAndWith<unsigned long long, u_char>);
        REQUIRE(cortex::BitAndWith<unsigned long long, wchar_t>);

        // Unsigned Long Long with Bit Specific Characters
        REQUIRE(cortex::BitAndWith<unsigned long long, char8_t>);
        REQUIRE(cortex::BitAndWith<unsigned long long, char16_t>);
        REQUIRE(cortex::BitAndWith<unsigned long long, char32_t>);

        // Unsigned Long Long with Bit Specific Long Long
        REQUIRE(cortex::BitAndWith<unsigned long long, int8_t>);
        REQUIRE(cortex::BitAndWith<unsigned long long, int16_t>);
        REQUIRE(cortex::BitAndWith<unsigned long long, int32_t>);
        REQUIRE(cortex::BitAndWith<unsigned long long, int64_t>);

        // Unsigned Long Long with Bit Specific Unsigned Long Long
        REQUIRE(cortex::BitAndWith<unsigned long long, uint8_t>);
        REQUIRE(cortex::BitAndWith<unsigned long long, uint16_t>);
        REQUIRE(cortex::BitAndWith<unsigned long long, uint32_t>);
        REQUIRE(cortex::BitAndWith<unsigned long long, uint64_t>);

        // Long Long with Bit Specific Least Long Long
        REQUIRE(cortex::BitAndWith<unsigned long long, int_least8_t>);
        REQUIRE(cortex::BitAndWith<unsigned long long, int_least16_t>);
        REQUIRE(cortex::BitAndWith<unsigned long long, int_least32_t>);
        REQUIRE(cortex::BitAndWith<unsigned long long, int_least64_t>);
    }
}

TEST_CASE("Addable With : Bit Specific Signed Integers")
{
    SECTION("int8_t with _")
    {
        // int8_t with Signed Integers
        REQUIRE(cortex::BitAndWith<int8_t, int>);
        REQUIRE(cortex::BitAndWith<int8_t, short>);
        REQUIRE(cortex::BitAndWith<int8_t, long>);
        REQUIRE(cortex::BitAndWith<int8_t, long long>);

        // int8_t with Unsigned Integers
        REQUIRE(cortex::BitAndWith<int8_t, unsigned>);
        REQUIRE(cortex::BitAndWith<int8_t, unsigned short>);
        REQUIRE(cortex::BitAndWith<int8_t, u_short>);
        REQUIRE(cortex::BitAndWith<int8_t, unsigned long>);
        REQUIRE(cortex::BitAndWith<int8_t, unsigned long long>);
        
        // int8_t with Floating Point and Doubles
        REQUIRE(!cortex::BitAndWith<int8_t, float>);
        REQUIRE(!cortex::BitAndWith<int8_t, double>);
        REQUIRE(!cortex::BitAndWith<int8_t, long double>);

        // int8_t with std::strings and std::string_view
        REQUIRE(!cortex::BitAndWith<int8_t, std::string>);
        REQUIRE(!cortex::BitAndWith<int8_t, std::string_view>);
        REQUIRE(!cortex::BitAndWith<int8_t, std::u8string>);
        REQUIRE(!cortex::BitAndWith<int8_t, std::u16string>);
        REQUIRE(!cortex::BitAndWith<int8_t, std::u32string>);

        // int8_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitAndWith<long long, std::wstring>);
        REQUIRE(!cortex::BitAndWith<long long, std::wstring_view>);

        // int8_t with Charaters
        REQUIRE(cortex::BitAndWith<int8_t, char>);
        REQUIRE(cortex::BitAndWith<int8_t, u_char>);
        REQUIRE(cortex::BitAndWith<int8_t, wchar_t>);

        // int8_t with Bit Specific Characters
        REQUIRE(cortex::BitAndWith<int8_t, char8_t>);
        REQUIRE(cortex::BitAndWith<int8_t, char16_t>);
        REQUIRE(cortex::BitAndWith<int8_t, char32_t>);

        // int8_t with Bit Specific Integers
        REQUIRE(cortex::BitAndWith<int8_t, int8_t>);
        REQUIRE(cortex::BitAndWith<int8_t, int16_t>);
        REQUIRE(cortex::BitAndWith<int8_t, int32_t>);
        REQUIRE(cortex::BitAndWith<int8_t, int64_t>);

        // int8_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::BitAndWith<int8_t, uint8_t>);
        REQUIRE(cortex::BitAndWith<int8_t, uint16_t>);
        REQUIRE(cortex::BitAndWith<int8_t, uint32_t>);
        REQUIRE(cortex::BitAndWith<int8_t, uint64_t>);

        // int8_t with Bit Specific Least Integers
        REQUIRE(cortex::BitAndWith<int8_t, int_least8_t>);
        REQUIRE(cortex::BitAndWith<int8_t, int_least16_t>);
        REQUIRE(cortex::BitAndWith<int8_t, int_least32_t>);
        REQUIRE(cortex::BitAndWith<int8_t, int_least64_t>);
    }

    SECTION("int16_t with _")
    {
        // int16_t with Signed Integers
        REQUIRE(cortex::BitAndWith<int16_t, int>);
        REQUIRE(cortex::BitAndWith<int16_t, short>);
        REQUIRE(cortex::BitAndWith<int16_t, long>);
        REQUIRE(cortex::BitAndWith<int16_t, long long>);

        // int16_t with Unsigned Integers
        REQUIRE(cortex::BitAndWith<int16_t, unsigned>);
        REQUIRE(cortex::BitAndWith<int16_t, unsigned short>);
        REQUIRE(cortex::BitAndWith<int16_t, u_short>);
        REQUIRE(cortex::BitAndWith<int16_t, unsigned long>);
        REQUIRE(cortex::BitAndWith<int16_t, unsigned long long>);
        
        // int16_t with Floating Point and Doubles
        REQUIRE(!cortex::BitAndWith<int16_t, float>);
        REQUIRE(!cortex::BitAndWith<int16_t, double>);
        REQUIRE(!cortex::BitAndWith<int16_t, long double>);

        // int16_t with std::strings and std::string_view
        REQUIRE(!cortex::BitAndWith<int16_t, std::string>);
        REQUIRE(!cortex::BitAndWith<int16_t, std::string_view>);
        REQUIRE(!cortex::BitAndWith<int16_t, std::u8string>);
        REQUIRE(!cortex::BitAndWith<int16_t, std::u16string>);
        REQUIRE(!cortex::BitAndWith<int16_t, std::u32string>);

        // int16_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitAndWith<int16_t, std::wstring>);
        REQUIRE(!cortex::BitAndWith<int16_t, std::wstring_view>);

        // int16_t with Charaters
        REQUIRE(cortex::BitAndWith<int16_t, char>);
        REQUIRE(cortex::BitAndWith<int16_t, u_char>);
        REQUIRE(cortex::BitAndWith<int16_t, wchar_t>);

        // int16_t with Bit Specific Characters
        REQUIRE(cortex::BitAndWith<int16_t, char8_t>);
        REQUIRE(cortex::BitAndWith<int16_t, char16_t>);
        REQUIRE(cortex::BitAndWith<int16_t, char32_t>);

        // int16_t with Bit Specific Integers
        REQUIRE(cortex::BitAndWith<int16_t, int8_t>);
        REQUIRE(cortex::BitAndWith<int16_t, int16_t>);
        REQUIRE(cortex::BitAndWith<int16_t, int32_t>);
        REQUIRE(cortex::BitAndWith<int16_t, int64_t>);

        // int16_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::BitAndWith<int16_t, uint8_t>);
        REQUIRE(cortex::BitAndWith<int16_t, uint16_t>);
        REQUIRE(cortex::BitAndWith<int16_t, uint32_t>);
        REQUIRE(cortex::BitAndWith<int16_t, uint64_t>);

        // int16_t with Bit Specific Least Integers
        REQUIRE(cortex::BitAndWith<int16_t, int_least8_t>);
        REQUIRE(cortex::BitAndWith<int16_t, int_least16_t>);
        REQUIRE(cortex::BitAndWith<int16_t, int_least32_t>);
        REQUIRE(cortex::BitAndWith<int16_t, int_least64_t>);
    }

    SECTION("int32 with _")
    {
        // int32 with Signed Integers
        REQUIRE(cortex::BitAndWith<int32_t, int>);
        REQUIRE(cortex::BitAndWith<int32_t, short>);
        REQUIRE(cortex::BitAndWith<int32_t, long>);
        REQUIRE(cortex::BitAndWith<int32_t, long long>);

        // int32 with Unsigned Integers
        REQUIRE(cortex::BitAndWith<int32_t, unsigned>);
        REQUIRE(cortex::BitAndWith<int32_t, unsigned short>);
        REQUIRE(cortex::BitAndWith<int32_t, u_short>);
        REQUIRE(cortex::BitAndWith<int32_t, unsigned long>);
        REQUIRE(cortex::BitAndWith<int32_t, unsigned long long>);
        
        // int32 with Floating Point and Doubles
        REQUIRE(!cortex::BitAndWith<int32_t, float>);
        REQUIRE(!cortex::BitAndWith<int32_t, double>);
        REQUIRE(!cortex::BitAndWith<int32_t, long double>);

        // int32 with std::strings and std::string_view
        REQUIRE(!cortex::BitAndWith<int32_t, std::string>);
        REQUIRE(!cortex::BitAndWith<int32_t, std::string_view>);
        REQUIRE(!cortex::BitAndWith<int32_t, std::u8string>);
        REQUIRE(!cortex::BitAndWith<int32_t, std::u16string>);
        REQUIRE(!cortex::BitAndWith<int32_t, std::u32string>);

        // int32 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitAndWith<int32_t, std::wstring>);
        REQUIRE(!cortex::BitAndWith<int32_t, std::wstring_view>);

        // int32_t with Charaters
        REQUIRE(cortex::BitAndWith<int32_t, char>);
        REQUIRE(cortex::BitAndWith<int32_t, u_char>);
        REQUIRE(cortex::BitAndWith<int32_t, wchar_t>);

        // int32_t with Bit Specific Characters
        REQUIRE(cortex::BitAndWith<int32_t, char8_t>);
        REQUIRE(cortex::BitAndWith<int32_t, char16_t>);
        REQUIRE(cortex::BitAndWith<int32_t, char32_t>);

        // int32_t with Bit Specific Integers
        REQUIRE(cortex::BitAndWith<int32_t, int8_t>);
        REQUIRE(cortex::BitAndWith<int32_t, int16_t>);
        REQUIRE(cortex::BitAndWith<int32_t, int32_t>);
        REQUIRE(cortex::BitAndWith<int32_t, int64_t>);

        // int32_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::BitAndWith<int32_t, uint8_t>);
        REQUIRE(cortex::BitAndWith<int32_t, uint16_t>);
        REQUIRE(cortex::BitAndWith<int32_t, uint32_t>);
        REQUIRE(cortex::BitAndWith<int32_t, uint64_t>);

        // int32_t with Bit Specific Least Integers
        REQUIRE(cortex::BitAndWith<int32_t, int_least8_t>);
        REQUIRE(cortex::BitAndWith<int32_t, int_least16_t>);
        REQUIRE(cortex::BitAndWith<int32_t, int_least32_t>);
        REQUIRE(cortex::BitAndWith<int32_t, int_least64_t>);
    }

    SECTION("int64 with _")
    {
        // int64 with Signed Integers
        REQUIRE(cortex::BitAndWith<int64_t, int>);
        REQUIRE(cortex::BitAndWith<int64_t, short>);
        REQUIRE(cortex::BitAndWith<int64_t, long>);
        REQUIRE(cortex::BitAndWith<int64_t, long long>);

        // int64 with Unsigned Integers
        REQUIRE(cortex::BitAndWith<int64_t, unsigned>);
        REQUIRE(cortex::BitAndWith<int64_t, unsigned short>);
        REQUIRE(cortex::BitAndWith<int64_t, u_short>);
        REQUIRE(cortex::BitAndWith<int64_t, unsigned long>);
        REQUIRE(cortex::BitAndWith<int64_t, unsigned long long>);
        
        // int64 with Floating Point and Doubles
        REQUIRE(!cortex::BitAndWith<int64_t, float>);
        REQUIRE(!cortex::BitAndWith<int64_t, double>);
        REQUIRE(!cortex::BitAndWith<int64_t, long double>);

        // int64 with std::strings and std::string_view
        REQUIRE(!cortex::BitAndWith<int64_t, std::string>);
        REQUIRE(!cortex::BitAndWith<int64_t, std::string_view>);
        REQUIRE(!cortex::BitAndWith<int64_t, std::u8string>);
        REQUIRE(!cortex::BitAndWith<int64_t, std::u16string>);
        REQUIRE(!cortex::BitAndWith<int64_t, std::u32string>);

        // int64 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitAndWith<int64_t, std::wstring>);
        REQUIRE(!cortex::BitAndWith<int64_t, std::wstring_view>);

        // int64_t with Charaters
        REQUIRE(cortex::BitAndWith<int64_t, char>);
        REQUIRE(cortex::BitAndWith<int64_t, u_char>);
        REQUIRE(cortex::BitAndWith<int64_t, wchar_t>);

        // int64_t with Bit Specific Characters
        REQUIRE(cortex::BitAndWith<int64_t, char8_t>);
        REQUIRE(cortex::BitAndWith<int64_t, char16_t>);
        REQUIRE(cortex::BitAndWith<int64_t, char32_t>);

        // int64_t with Bit Specific Integers
        REQUIRE(cortex::BitAndWith<int64_t, int8_t>);
        REQUIRE(cortex::BitAndWith<int64_t, int16_t>);
        REQUIRE(cortex::BitAndWith<int64_t, int32_t>);
        REQUIRE(cortex::BitAndWith<int64_t, int64_t>);

        // int64_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::BitAndWith<int64_t, uint8_t>);
        REQUIRE(cortex::BitAndWith<int64_t, uint16_t>);
        REQUIRE(cortex::BitAndWith<int64_t, uint32_t>);
        REQUIRE(cortex::BitAndWith<int64_t, uint64_t>);

        // int64_t with Bit Specific Least Integers
        REQUIRE(cortex::BitAndWith<int64_t, int_least8_t>);
        REQUIRE(cortex::BitAndWith<int64_t, int_least16_t>);
        REQUIRE(cortex::BitAndWith<int64_t, int_least32_t>);
        REQUIRE(cortex::BitAndWith<int64_t, int_least64_t>);
}
}

TEST_CASE("Addable With : Bit Specific Unsigned Integers")
{
    SECTION("uint8_t with _")
    {
        // uint8_t with Signed Integers
        REQUIRE(cortex::BitAndWith<uint8_t, int>);
        REQUIRE(cortex::BitAndWith<uint8_t, short>);
        REQUIRE(cortex::BitAndWith<uint8_t, long>);
        REQUIRE(cortex::BitAndWith<uint8_t, long long>);

        // uint8_t with Unsigned Integers
        REQUIRE(cortex::BitAndWith<uint8_t, unsigned>);
        REQUIRE(cortex::BitAndWith<uint8_t, unsigned short>);
        REQUIRE(cortex::BitAndWith<uint8_t, u_short>);
        REQUIRE(cortex::BitAndWith<uint8_t, unsigned long>);
        REQUIRE(cortex::BitAndWith<uint8_t, unsigned long long>);
        
        // uint8_t with Floating Point and Doubles
        REQUIRE(!cortex::BitAndWith<uint8_t, float>);
        REQUIRE(!cortex::BitAndWith<uint8_t, double>);
        REQUIRE(!cortex::BitAndWith<uint8_t, long double>);

        // uint8_t with std::strings and std::string_view
        REQUIRE(!cortex::BitAndWith<uint8_t, std::string>);
        REQUIRE(!cortex::BitAndWith<uint8_t, std::string_view>);
        REQUIRE(!cortex::BitAndWith<uint8_t, std::u8string>);
        REQUIRE(!cortex::BitAndWith<uint8_t, std::u16string>);
        REQUIRE(!cortex::BitAndWith<uint8_t, std::u32string>);

        // uint8_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitAndWith<long long, std::wstring>);
        REQUIRE(!cortex::BitAndWith<long long, std::wstring_view>);

        // uint8_t with Charaters
        REQUIRE(cortex::BitAndWith<uint8_t, char>);
        REQUIRE(cortex::BitAndWith<uint8_t, u_char>);
        REQUIRE(cortex::BitAndWith<uint8_t, wchar_t>);

        // uint8_t with Bit Specific Characters
        REQUIRE(cortex::BitAndWith<uint8_t, char8_t>);
        REQUIRE(cortex::BitAndWith<uint8_t, char16_t>);
        REQUIRE(cortex::BitAndWith<uint8_t, char32_t>);

        // uint8_t with Bit Specific Integers
        REQUIRE(cortex::BitAndWith<uint8_t, int8_t>);
        REQUIRE(cortex::BitAndWith<uint8_t, int16_t>);
        REQUIRE(cortex::BitAndWith<uint8_t, int32_t>);
        REQUIRE(cortex::BitAndWith<uint8_t, int64_t>);

        // uint8_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::BitAndWith<uint8_t, uint8_t>);
        REQUIRE(cortex::BitAndWith<uint8_t, uint16_t>);
        REQUIRE(cortex::BitAndWith<uint8_t, uint32_t>);
        REQUIRE(cortex::BitAndWith<uint8_t, uint64_t>);

        // uint8_t with Bit Specific Least Integers
        REQUIRE(cortex::BitAndWith<uint8_t, int_least8_t>);
        REQUIRE(cortex::BitAndWith<uint8_t, int_least16_t>);
        REQUIRE(cortex::BitAndWith<uint8_t, int_least32_t>);
        REQUIRE(cortex::BitAndWith<uint8_t, int_least64_t>);
    }

    SECTION("uint16_t with _")
    {
        // uint16_t with Signed Integers
        REQUIRE(cortex::BitAndWith<uint16_t, int>);
        REQUIRE(cortex::BitAndWith<uint16_t, short>);
        REQUIRE(cortex::BitAndWith<uint16_t, long>);
        REQUIRE(cortex::BitAndWith<uint16_t, long long>);

        // uint16_t with Unsigned Integers
        REQUIRE(cortex::BitAndWith<uint16_t, unsigned>);
        REQUIRE(cortex::BitAndWith<uint16_t, unsigned short>);
        REQUIRE(cortex::BitAndWith<uint16_t, u_short>);
        REQUIRE(cortex::BitAndWith<uint16_t, unsigned long>);
        REQUIRE(cortex::BitAndWith<uint16_t, unsigned long long>);
        
        // uint16_t with Floating Point and Doubles
        REQUIRE(!cortex::BitAndWith<uint16_t, float>);
        REQUIRE(!cortex::BitAndWith<uint16_t, double>);
        REQUIRE(!cortex::BitAndWith<uint16_t, long double>);

        // uint16_t with std::strings and std::string_view
        REQUIRE(!cortex::BitAndWith<uint16_t, std::string>);
        REQUIRE(!cortex::BitAndWith<uint16_t, std::string_view>);
        REQUIRE(!cortex::BitAndWith<uint16_t, std::u8string>);
        REQUIRE(!cortex::BitAndWith<uint16_t, std::u16string>);
        REQUIRE(!cortex::BitAndWith<uint16_t, std::u32string>);

        // uint16_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitAndWith<uint16_t, std::wstring>);
        REQUIRE(!cortex::BitAndWith<uint16_t, std::wstring_view>);

        // uint16_t with Charaters
        REQUIRE(cortex::BitAndWith<uint16_t, char>);
        REQUIRE(cortex::BitAndWith<uint16_t, u_char>);
        REQUIRE(cortex::BitAndWith<uint16_t, wchar_t>);

        // uint16_t with Bit Specific Characters
        REQUIRE(cortex::BitAndWith<uint16_t, char8_t>);
        REQUIRE(cortex::BitAndWith<uint16_t, char16_t>);
        REQUIRE(cortex::BitAndWith<uint16_t, char32_t>);

        // uint16_t with Bit Specific Integers
        REQUIRE(cortex::BitAndWith<uint16_t, int8_t>);
        REQUIRE(cortex::BitAndWith<uint16_t, int16_t>);
        REQUIRE(cortex::BitAndWith<uint16_t, int32_t>);
        REQUIRE(cortex::BitAndWith<uint16_t, int64_t>);

        // uint16_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::BitAndWith<uint16_t, uint8_t>);
        REQUIRE(cortex::BitAndWith<uint16_t, uint16_t>);
        REQUIRE(cortex::BitAndWith<uint16_t, uint32_t>);
        REQUIRE(cortex::BitAndWith<uint16_t, uint64_t>);

        // uint16_t with Bit Specific Least Integers
        REQUIRE(cortex::BitAndWith<uint16_t, int_least8_t>);
        REQUIRE(cortex::BitAndWith<uint16_t, int_least16_t>);
        REQUIRE(cortex::BitAndWith<uint16_t, int_least32_t>);
        REQUIRE(cortex::BitAndWith<uint16_t, int_least64_t>);
    }

    SECTION("uint32_t with _")
    {
        // int32 with Signed Integers
        REQUIRE(cortex::BitAndWith<uint32_t, int>);
        REQUIRE(cortex::BitAndWith<uint32_t, short>);
        REQUIRE(cortex::BitAndWith<uint32_t, long>);
        REQUIRE(cortex::BitAndWith<uint32_t, long long>);

        // int32 with Unsigned Integers
        REQUIRE(cortex::BitAndWith<uint32_t, unsigned>);
        REQUIRE(cortex::BitAndWith<uint32_t, unsigned short>);
        REQUIRE(cortex::BitAndWith<uint32_t, u_short>);
        REQUIRE(cortex::BitAndWith<uint32_t, unsigned long>);
        REQUIRE(cortex::BitAndWith<uint32_t, unsigned long long>);
        
        // int32 with Floating Point and Doubles
        REQUIRE(!cortex::BitAndWith<uint32_t, float>);
        REQUIRE(!cortex::BitAndWith<uint32_t, double>);
        REQUIRE(!cortex::BitAndWith<uint32_t, long double>);

        // int32 with std::strings and std::string_view
        REQUIRE(!cortex::BitAndWith<uint32_t, std::string>);
        REQUIRE(!cortex::BitAndWith<uint32_t, std::string_view>);
        REQUIRE(!cortex::BitAndWith<uint32_t, std::u8string>);
        REQUIRE(!cortex::BitAndWith<uint32_t, std::u16string>);
        REQUIRE(!cortex::BitAndWith<uint32_t, std::u32string>);

        // int32 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitAndWith<uint32_t, std::wstring>);
        REQUIRE(!cortex::BitAndWith<uint32_t, std::wstring_view>);

        // uint32_t with Charaters
        REQUIRE(cortex::BitAndWith<uint32_t, char>);
        REQUIRE(cortex::BitAndWith<uint32_t, u_char>);
        REQUIRE(cortex::BitAndWith<uint32_t, wchar_t>);

        // uint32_t with Bit Specific Characters
        REQUIRE(cortex::BitAndWith<uint32_t, char8_t>);
        REQUIRE(cortex::BitAndWith<uint32_t, char16_t>);
        REQUIRE(cortex::BitAndWith<uint32_t, char32_t>);

        // uint32_t with Bit Specific Integers
        REQUIRE(cortex::BitAndWith<uint32_t, int8_t>);
        REQUIRE(cortex::BitAndWith<uint32_t, int16_t>);
        REQUIRE(cortex::BitAndWith<uint32_t, int32_t>);
        REQUIRE(cortex::BitAndWith<uint32_t, int64_t>);

        // uint32_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::BitAndWith<uint32_t, uint8_t>);
        REQUIRE(cortex::BitAndWith<uint32_t, uint16_t>);
        REQUIRE(cortex::BitAndWith<uint32_t, uint32_t>);
        REQUIRE(cortex::BitAndWith<uint32_t, uint64_t>);

        // uint32_t with Bit Specific Least Integers
        REQUIRE(cortex::BitAndWith<uint32_t, int_least8_t>);
        REQUIRE(cortex::BitAndWith<uint32_t, int_least16_t>);
        REQUIRE(cortex::BitAndWith<uint32_t, int_least32_t>);
        REQUIRE(cortex::BitAndWith<uint32_t, int_least64_t>);
    }

    SECTION("uint64_t with _")
    {
        // int64 with Signed Integers
        REQUIRE(cortex::BitAndWith<uint64_t, int>);
        REQUIRE(cortex::BitAndWith<uint64_t, short>);
        REQUIRE(cortex::BitAndWith<uint64_t, long>);
        REQUIRE(cortex::BitAndWith<uint64_t, long long>);

        // int64 with Unsigned Integers
        REQUIRE(cortex::BitAndWith<uint64_t, unsigned>);
        REQUIRE(cortex::BitAndWith<uint64_t, unsigned short>);
        REQUIRE(cortex::BitAndWith<uint64_t, u_short>);
        REQUIRE(cortex::BitAndWith<uint64_t, unsigned long>);
        REQUIRE(cortex::BitAndWith<uint64_t, unsigned long long>);
        
        // int64 with Floating Point and Doubles
        REQUIRE(!cortex::BitAndWith<uint64_t, float>);
        REQUIRE(!cortex::BitAndWith<uint64_t, double>);
        REQUIRE(!cortex::BitAndWith<uint64_t, long double>);

        // int64 with std::strings and std::string_view
        REQUIRE(!cortex::BitAndWith<uint64_t, std::string>);
        REQUIRE(!cortex::BitAndWith<uint64_t, std::string_view>);
        REQUIRE(!cortex::BitAndWith<uint64_t, std::u8string>);
        REQUIRE(!cortex::BitAndWith<uint64_t, std::u16string>);
        REQUIRE(!cortex::BitAndWith<uint64_t, std::u32string>);

        // int64 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitAndWith<uint64_t, std::wstring>);
        REQUIRE(!cortex::BitAndWith<uint64_t, std::wstring_view>);

        // uint64_t with Charaters
        REQUIRE(cortex::BitAndWith<uint64_t, char>);
        REQUIRE(cortex::BitAndWith<uint64_t, u_char>);
        REQUIRE(cortex::BitAndWith<uint64_t, wchar_t>);

        // uint64_t with Bit Specific Characters
        REQUIRE(cortex::BitAndWith<uint64_t, char8_t>);
        REQUIRE(cortex::BitAndWith<uint64_t, char16_t>);
        REQUIRE(cortex::BitAndWith<uint64_t, char32_t>);

        // uint64_t with Bit Specific Integers
        REQUIRE(cortex::BitAndWith<uint64_t, int8_t>);
        REQUIRE(cortex::BitAndWith<uint64_t, int16_t>);
        REQUIRE(cortex::BitAndWith<uint64_t, int32_t>);
        REQUIRE(cortex::BitAndWith<uint64_t, int64_t>);

        // uint64_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::BitAndWith<uint64_t, uint8_t>);
        REQUIRE(cortex::BitAndWith<uint64_t, uint16_t>);
        REQUIRE(cortex::BitAndWith<uint64_t, uint32_t>);
        REQUIRE(cortex::BitAndWith<uint64_t, uint64_t>);

        // uint64_t with Bit Specific Least Integers
        REQUIRE(cortex::BitAndWith<uint64_t, int_least8_t>);
        REQUIRE(cortex::BitAndWith<uint64_t, int_least16_t>);
        REQUIRE(cortex::BitAndWith<uint64_t, int_least32_t>);
        REQUIRE(cortex::BitAndWith<uint64_t, int_least64_t>);
    }
}

TEST_CASE("Addable With : std::size_t")
{
    SECTION("std::size_t with _")
    {
        // std::size_t with Signed Integers
        REQUIRE(cortex::BitAndWith<std::size_t, int>);
        REQUIRE(cortex::BitAndWith<std::size_t, short>);
        REQUIRE(cortex::BitAndWith<std::size_t, long>);
        REQUIRE(cortex::BitAndWith<std::size_t, long long>);

        // std::size_t with Unsigned Integers
        REQUIRE(cortex::BitAndWith<std::size_t, unsigned>);
        REQUIRE(cortex::BitAndWith<std::size_t, unsigned short>);
        REQUIRE(cortex::BitAndWith<std::size_t, u_short>);
        REQUIRE(cortex::BitAndWith<std::size_t, unsigned long>);
        REQUIRE(cortex::BitAndWith<std::size_t, unsigned long long>);
        
        // std::size_t with Floating Point and Doubles
        REQUIRE(!cortex::BitAndWith<std::size_t, float>);
        REQUIRE(!cortex::BitAndWith<std::size_t, double>);
        REQUIRE(!cortex::BitAndWith<std::size_t, long double>);

        // std::size_t with std::strings and std::string_view
        REQUIRE(!cortex::BitAndWith<std::size_t, std::string>);
        REQUIRE(!cortex::BitAndWith<std::size_t, std::string_view>);
        REQUIRE(!cortex::BitAndWith<std::size_t, std::u8string>);
        REQUIRE(!cortex::BitAndWith<std::size_t, std::u16string>);
        REQUIRE(!cortex::BitAndWith<std::size_t, std::u32string>);

        // std::size_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitAndWith<long long, std::wstring>);
        REQUIRE(!cortex::BitAndWith<long long, std::wstring_view>);

        // std::size_t with Charaters
        REQUIRE(cortex::BitAndWith<std::size_t, char>);
        REQUIRE(cortex::BitAndWith<std::size_t, u_char>);
        REQUIRE(cortex::BitAndWith<std::size_t, wchar_t>);

        // std::size_t with Bit Specific Characters
        REQUIRE(cortex::BitAndWith<std::size_t, char8_t>);
        REQUIRE(cortex::BitAndWith<std::size_t, char16_t>);
        REQUIRE(cortex::BitAndWith<std::size_t, char32_t>);

        // std::size_t with Bit Specific Integers
        REQUIRE(cortex::BitAndWith<std::size_t, int8_t>);
        REQUIRE(cortex::BitAndWith<std::size_t, int16_t>);
        REQUIRE(cortex::BitAndWith<std::size_t, int32_t>);
        REQUIRE(cortex::BitAndWith<std::size_t, int64_t>);

        // std::size_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::BitAndWith<std::size_t, uint8_t>);
        REQUIRE(cortex::BitAndWith<std::size_t, uint16_t>);
        REQUIRE(cortex::BitAndWith<std::size_t, uint32_t>);
        REQUIRE(cortex::BitAndWith<std::size_t, uint64_t>);

        // std::size_t with Bit Specific Least Integers
        REQUIRE(cortex::BitAndWith<std::size_t, int_least8_t>);
        REQUIRE(cortex::BitAndWith<std::size_t, int_least16_t>);
        REQUIRE(cortex::BitAndWith<std::size_t, int_least32_t>);
        REQUIRE(cortex::BitAndWith<std::size_t, int_least64_t>);
    }
}

TEST_CASE("BitAndWith : Fast Integers")
{
    SECTION("int_fast8_t with _")
    {
        // int_fast8_t with Signed Integers
        REQUIRE(cortex::BitAndWith<int_fast8_t, int>);
        REQUIRE(cortex::BitAndWith<int_fast8_t, short>);
        REQUIRE(cortex::BitAndWith<int_fast8_t, long>);
        REQUIRE(cortex::BitAndWith<int_fast8_t, long long>);

        // int_fast8_t with Unsigned Integers
        REQUIRE(cortex::BitAndWith<int_fast8_t, unsigned>);
        REQUIRE(cortex::BitAndWith<int_fast8_t, unsigned short>);
        REQUIRE(cortex::BitAndWith<int_fast8_t, u_short>);
        REQUIRE(cortex::BitAndWith<int_fast8_t, unsigned long>);
        REQUIRE(cortex::BitAndWith<int_fast8_t, unsigned long long>);
        
        // int_fast8_t with Floating Point and Doubles
        REQUIRE(!cortex::BitAndWith<int_fast8_t, float>);
        REQUIRE(!cortex::BitAndWith<int_fast8_t, double>);
        REQUIRE(!cortex::BitAndWith<int_fast8_t, long double>);

        // int_fast8_t with std::strings and std::string_view
        REQUIRE(!cortex::BitAndWith<int_fast8_t, std::string>);
        REQUIRE(!cortex::BitAndWith<int_fast8_t, std::string_view>);
        REQUIRE(!cortex::BitAndWith<int_fast8_t, std::u8string>);
        REQUIRE(!cortex::BitAndWith<int_fast8_t, std::u16string>);
        REQUIRE(!cortex::BitAndWith<int_fast8_t, std::u32string>);

        // int_fast8_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitAndWith<long long, std::wstring>);
        REQUIRE(!cortex::BitAndWith<long long, std::wstring_view>);

        // int_fast8_t with Charaters
        REQUIRE(cortex::BitAndWith<int_fast8_t, char>);
        REQUIRE(cortex::BitAndWith<int_fast8_t, u_char>);
        REQUIRE(cortex::BitAndWith<int_fast8_t, wchar_t>);

        // int_fast8_t with Bit Specific Characters
        REQUIRE(cortex::BitAndWith<int_fast8_t, char8_t>);
        REQUIRE(cortex::BitAndWith<int_fast8_t, char16_t>);
        REQUIRE(cortex::BitAndWith<int_fast8_t, char32_t>);

        // int_fast8_t with Bit Specific Integers
        REQUIRE(cortex::BitAndWith<int_fast8_t, int8_t>);
        REQUIRE(cortex::BitAndWith<int_fast8_t, int16_t>);
        REQUIRE(cortex::BitAndWith<int_fast8_t, int32_t>);
        REQUIRE(cortex::BitAndWith<int_fast8_t, int64_t>);

        // int_fast8_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::BitAndWith<int_fast8_t, uint8_t>);
        REQUIRE(cortex::BitAndWith<int_fast8_t, uint16_t>);
        REQUIRE(cortex::BitAndWith<int_fast8_t, uint32_t>);
        REQUIRE(cortex::BitAndWith<int_fast8_t, uint64_t>);

        // int_fast8_t with Bit Specific Least Integers
        REQUIRE(cortex::BitAndWith<int_fast8_t, int_least8_t>);
        REQUIRE(cortex::BitAndWith<int_fast8_t, int_least16_t>);
        REQUIRE(cortex::BitAndWith<int_fast8_t, int_least32_t>);
        REQUIRE(cortex::BitAndWith<int_fast8_t, int_least64_t>);
    }

    SECTION("int_fast16_t with _")
    {
        // int_fast16_t with Signed Integers
        REQUIRE(cortex::BitAndWith<int_fast16_t, int>);
        REQUIRE(cortex::BitAndWith<int_fast16_t, short>);
        REQUIRE(cortex::BitAndWith<int_fast16_t, long>);
        REQUIRE(cortex::BitAndWith<int_fast16_t, long long>);

        // int_fast16_t with Unsigned Integers
        REQUIRE(cortex::BitAndWith<int_fast16_t, unsigned>);
        REQUIRE(cortex::BitAndWith<int_fast16_t, unsigned short>);
        REQUIRE(cortex::BitAndWith<int_fast16_t, u_short>);
        REQUIRE(cortex::BitAndWith<int_fast16_t, unsigned long>);
        REQUIRE(cortex::BitAndWith<int_fast16_t, unsigned long long>);
        
        // int_fast16_t with Floating Point and Doubles
        REQUIRE(!cortex::BitAndWith<int_fast16_t, float>);
        REQUIRE(!cortex::BitAndWith<int_fast16_t, double>);
        REQUIRE(!cortex::BitAndWith<int_fast16_t, long double>);

        // int_fast16_t with std::strings and std::string_view
        REQUIRE(!cortex::BitAndWith<int_fast16_t, std::string>);
        REQUIRE(!cortex::BitAndWith<int_fast16_t, std::string_view>);
        REQUIRE(!cortex::BitAndWith<int_fast16_t, std::u8string>);
        REQUIRE(!cortex::BitAndWith<int_fast16_t, std::u16string>);
        REQUIRE(!cortex::BitAndWith<int_fast16_t, std::u32string>);

        // int_fast16_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitAndWith<int_fast16_t, std::wstring>);
        REQUIRE(!cortex::BitAndWith<int_fast16_t, std::wstring_view>);

        // int_fast16_t with Charaters
        REQUIRE(cortex::BitAndWith<int_fast16_t, char>);
        REQUIRE(cortex::BitAndWith<int_fast16_t, u_char>);
        REQUIRE(cortex::BitAndWith<int_fast16_t, wchar_t>);

        // int_fast16_t with Bit Specific Characters
        REQUIRE(cortex::BitAndWith<int_fast16_t, char8_t>);
        REQUIRE(cortex::BitAndWith<int_fast16_t, char16_t>);
        REQUIRE(cortex::BitAndWith<int_fast16_t, char32_t>);

        // int_fast16_t with Bit Specific Integers
        REQUIRE(cortex::BitAndWith<int_fast16_t, int8_t>);
        REQUIRE(cortex::BitAndWith<int_fast16_t, int16_t>);
        REQUIRE(cortex::BitAndWith<int_fast16_t, int32_t>);
        REQUIRE(cortex::BitAndWith<int_fast16_t, int64_t>);

        // int_fast16_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::BitAndWith<int_fast16_t, uint8_t>);
        REQUIRE(cortex::BitAndWith<int_fast16_t, uint16_t>);
        REQUIRE(cortex::BitAndWith<int_fast16_t, uint32_t>);
        REQUIRE(cortex::BitAndWith<int_fast16_t, uint64_t>);

        // int_fast16_t with Bit Specific Least Integers
        REQUIRE(cortex::BitAndWith<int_fast16_t, int_least8_t>);
        REQUIRE(cortex::BitAndWith<int_fast16_t, int_least16_t>);
        REQUIRE(cortex::BitAndWith<int_fast16_t, int_least32_t>);
        REQUIRE(cortex::BitAndWith<int_fast16_t, int_least64_t>);
    }

    SECTION("int_fast32_t with _")
    {
        // int32 with Signed Integers
        REQUIRE(cortex::BitAndWith<int_fast32_t, int>);
        REQUIRE(cortex::BitAndWith<int_fast32_t, short>);
        REQUIRE(cortex::BitAndWith<int_fast32_t, long>);
        REQUIRE(cortex::BitAndWith<int_fast32_t, long long>);

        // int32 with Unsigned Integers
        REQUIRE(cortex::BitAndWith<int_fast32_t, unsigned>);
        REQUIRE(cortex::BitAndWith<int_fast32_t, unsigned short>);
        REQUIRE(cortex::BitAndWith<int_fast32_t, u_short>);
        REQUIRE(cortex::BitAndWith<int_fast32_t, unsigned long>);
        REQUIRE(cortex::BitAndWith<int_fast32_t, unsigned long long>);
        
        // int32 with Floating Point and Doubles
        REQUIRE(!cortex::BitAndWith<int_fast32_t, float>);
        REQUIRE(!cortex::BitAndWith<int_fast32_t, double>);
        REQUIRE(!cortex::BitAndWith<int_fast32_t, long double>);

        // int32 with std::strings and std::string_view
        REQUIRE(!cortex::BitAndWith<int_fast32_t, std::string>);
        REQUIRE(!cortex::BitAndWith<int_fast32_t, std::string_view>);
        REQUIRE(!cortex::BitAndWith<int_fast32_t, std::u8string>);
        REQUIRE(!cortex::BitAndWith<int_fast32_t, std::u16string>);
        REQUIRE(!cortex::BitAndWith<int_fast32_t, std::u32string>);

        // int32 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitAndWith<int_fast32_t, std::wstring>);
        REQUIRE(!cortex::BitAndWith<int_fast32_t, std::wstring_view>);

        // int_fast32_t with Charaters
        REQUIRE(cortex::BitAndWith<int_fast32_t, char>);
        REQUIRE(cortex::BitAndWith<int_fast32_t, u_char>);
        REQUIRE(cortex::BitAndWith<int_fast32_t, wchar_t>);

        // int_fast32_t with Bit Specific Characters
        REQUIRE(cortex::BitAndWith<int_fast32_t, char8_t>);
        REQUIRE(cortex::BitAndWith<int_fast32_t, char16_t>);
        REQUIRE(cortex::BitAndWith<int_fast32_t, char32_t>);

        // int_fast32_t with Bit Specific Integers
        REQUIRE(cortex::BitAndWith<int_fast32_t, int8_t>);
        REQUIRE(cortex::BitAndWith<int_fast32_t, int16_t>);
        REQUIRE(cortex::BitAndWith<int_fast32_t, int32_t>);
        REQUIRE(cortex::BitAndWith<int_fast32_t, int64_t>);

        // int_fast32_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::BitAndWith<int_fast32_t, uint8_t>);
        REQUIRE(cortex::BitAndWith<int_fast32_t, uint16_t>);
        REQUIRE(cortex::BitAndWith<int_fast32_t, uint32_t>);
        REQUIRE(cortex::BitAndWith<int_fast32_t, uint64_t>);

        // int_fast32_t with Bit Specific Least Integers
        REQUIRE(cortex::BitAndWith<int_fast32_t, int_least8_t>);
        REQUIRE(cortex::BitAndWith<int_fast32_t, int_least16_t>);
        REQUIRE(cortex::BitAndWith<int_fast32_t, int_least32_t>);
        REQUIRE(cortex::BitAndWith<int_fast32_t, int_least64_t>);
    }

    SECTION("int_fast64_t with _")
    {
        // int64 with Signed Integers
        REQUIRE(cortex::BitAndWith<int_fast64_t, int>);
        REQUIRE(cortex::BitAndWith<int_fast64_t, short>);
        REQUIRE(cortex::BitAndWith<int_fast64_t, long>);
        REQUIRE(cortex::BitAndWith<int_fast64_t, long long>);

        // int64 with Unsigned Integers
        REQUIRE(cortex::BitAndWith<int_fast64_t, unsigned>);
        REQUIRE(cortex::BitAndWith<int_fast64_t, unsigned short>);
        REQUIRE(cortex::BitAndWith<int_fast64_t, u_short>);
        REQUIRE(cortex::BitAndWith<int_fast64_t, unsigned long>);
        REQUIRE(cortex::BitAndWith<int_fast64_t, unsigned long long>);
        
        // int64 with Floating Point and Doubles
        REQUIRE(!cortex::BitAndWith<int_fast64_t, float>);
        REQUIRE(!cortex::BitAndWith<int_fast64_t, double>);
        REQUIRE(!cortex::BitAndWith<int_fast64_t, long double>);

        // int64 with std::strings and std::string_view
        REQUIRE(!cortex::BitAndWith<int_fast64_t, std::string>);
        REQUIRE(!cortex::BitAndWith<int_fast64_t, std::string_view>);
        REQUIRE(!cortex::BitAndWith<int_fast64_t, std::u8string>);
        REQUIRE(!cortex::BitAndWith<int_fast64_t, std::u16string>);
        REQUIRE(!cortex::BitAndWith<int_fast64_t, std::u32string>);

        // int64 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitAndWith<int_fast64_t, std::wstring>);
        REQUIRE(!cortex::BitAndWith<int_fast64_t, std::wstring_view>);

        // int_fast64_t with Charaters
        REQUIRE(cortex::BitAndWith<int_fast64_t, char>);
        REQUIRE(cortex::BitAndWith<int_fast64_t, u_char>);
        REQUIRE(cortex::BitAndWith<int_fast64_t, wchar_t>);

        // int_fast64_t with Bit Specific Characters
        REQUIRE(cortex::BitAndWith<int_fast64_t, char8_t>);
        REQUIRE(cortex::BitAndWith<int_fast64_t, char16_t>);
        REQUIRE(cortex::BitAndWith<int_fast64_t, char32_t>);

        // int_fast64_t with Bit Specific Integers
        REQUIRE(cortex::BitAndWith<int_fast64_t, int8_t>);
        REQUIRE(cortex::BitAndWith<int_fast64_t, int16_t>);
        REQUIRE(cortex::BitAndWith<int_fast64_t, int32_t>);
        REQUIRE(cortex::BitAndWith<int_fast64_t, int64_t>);

        // int_fast64_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::BitAndWith<int_fast64_t, uint8_t>);
        REQUIRE(cortex::BitAndWith<int_fast64_t, uint16_t>);
        REQUIRE(cortex::BitAndWith<int_fast64_t, uint32_t>);
        REQUIRE(cortex::BitAndWith<int_fast64_t, uint64_t>);

        // int_fast64_t with Bit Specific Least Integers
        REQUIRE(cortex::BitAndWith<int_fast64_t, int_least8_t>);
        REQUIRE(cortex::BitAndWith<int_fast64_t, int_least16_t>);
        REQUIRE(cortex::BitAndWith<int_fast64_t, int_least32_t>);
        REQUIRE(cortex::BitAndWith<int_fast64_t, int_least64_t>);
    }
}

TEST_CASE("BitAndWith : Least Integers")
{
    SECTION("int_least8_t with _")
    {
        // int_fast8_t with Signed Integers
        REQUIRE(cortex::BitAndWith<int_least8_t, int>);
        REQUIRE(cortex::BitAndWith<int_least8_t, short>);
        REQUIRE(cortex::BitAndWith<int_least8_t, long>);
        REQUIRE(cortex::BitAndWith<int_least8_t, long long>);

        // int_fast8_t with Unsigned Integers
        REQUIRE(cortex::BitAndWith<int_least8_t, unsigned>);
        REQUIRE(cortex::BitAndWith<int_least8_t, unsigned short>);
        REQUIRE(cortex::BitAndWith<int_least8_t, u_short>);
        REQUIRE(cortex::BitAndWith<int_least8_t, unsigned long>);
        REQUIRE(cortex::BitAndWith<int_least8_t, unsigned long long>);
        
        // int_fast8_t with Floating Point and Doubles
        REQUIRE(!cortex::BitAndWith<int_least8_t, float>);
        REQUIRE(!cortex::BitAndWith<int_least8_t, double>);
        REQUIRE(!cortex::BitAndWith<int_least8_t, long double>);

        // int_fast8_t with std::strings and std::string_view
        REQUIRE(!cortex::BitAndWith<int_least8_t, std::string>);
        REQUIRE(!cortex::BitAndWith<int_least8_t, std::string_view>);
        REQUIRE(!cortex::BitAndWith<int_least8_t, std::u8string>);
        REQUIRE(!cortex::BitAndWith<int_least8_t, std::u16string>);
        REQUIRE(!cortex::BitAndWith<int_least8_t, std::u32string>);

        // int_fast8_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitAndWith<long long, std::wstring>);
        REQUIRE(!cortex::BitAndWith<long long, std::wstring_view>);

        // int_fast8_t with Charaters
        REQUIRE(cortex::BitAndWith<int_least8_t, char>);
        REQUIRE(cortex::BitAndWith<int_least8_t, u_char>);
        REQUIRE(cortex::BitAndWith<int_least8_t, wchar_t>);

        // int_fast8_t with Bit Specific Characters
        REQUIRE(cortex::BitAndWith<int_least8_t, char8_t>);
        REQUIRE(cortex::BitAndWith<int_least8_t, char16_t>);
        REQUIRE(cortex::BitAndWith<int_least8_t, char32_t>);

        // int_fast8_t with Bit Specific Integers
        REQUIRE(cortex::BitAndWith<int_least8_t, int8_t>);
        REQUIRE(cortex::BitAndWith<int_least8_t, int16_t>);
        REQUIRE(cortex::BitAndWith<int_least8_t, int32_t>);
        REQUIRE(cortex::BitAndWith<int_least8_t, int64_t>);

        // int_fast8_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::BitAndWith<int_least8_t, uint8_t>);
        REQUIRE(cortex::BitAndWith<int_least8_t, uint16_t>);
        REQUIRE(cortex::BitAndWith<int_least8_t, uint32_t>);
        REQUIRE(cortex::BitAndWith<int_least8_t, uint64_t>);

        // int_fast8_t with Bit Specific Least Integers
        REQUIRE(cortex::BitAndWith<int_least8_t, int_least8_t>);
        REQUIRE(cortex::BitAndWith<int_least8_t, int_least16_t>);
        REQUIRE(cortex::BitAndWith<int_least8_t, int_least32_t>);
        REQUIRE(cortex::BitAndWith<int_least8_t, int_least64_t>);
    }

    SECTION("int_least16_t with _")
    {
        // int_fast16_t with Signed Integers
        REQUIRE(cortex::BitAndWith<int_least16_t, int>);
        REQUIRE(cortex::BitAndWith<int_least16_t, short>);
        REQUIRE(cortex::BitAndWith<int_least16_t, long>);
        REQUIRE(cortex::BitAndWith<int_least16_t, long long>);

        // int_fast16_t with Unsigned Integers
        REQUIRE(cortex::BitAndWith<int_least16_t, unsigned>);
        REQUIRE(cortex::BitAndWith<int_least16_t, unsigned short>);
        REQUIRE(cortex::BitAndWith<int_least16_t, u_short>);
        REQUIRE(cortex::BitAndWith<int_least16_t, unsigned long>);
        REQUIRE(cortex::BitAndWith<int_least16_t, unsigned long long>);
        
        // int_fast16_t with Floating Point and Doubles
        REQUIRE(!cortex::BitAndWith<int_least16_t, float>);
        REQUIRE(!cortex::BitAndWith<int_least16_t, double>);
        REQUIRE(!cortex::BitAndWith<int_least16_t, long double>);

        // int_fast16_t with std::strings and std::string_view
        REQUIRE(!cortex::BitAndWith<int_least16_t, std::string>);
        REQUIRE(!cortex::BitAndWith<int_least16_t, std::string_view>);
        REQUIRE(!cortex::BitAndWith<int_least16_t, std::u8string>);
        REQUIRE(!cortex::BitAndWith<int_least16_t, std::u16string>);
        REQUIRE(!cortex::BitAndWith<int_least16_t, std::u32string>);

        // int_fast16_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitAndWith<int_least16_t, std::wstring>);
        REQUIRE(!cortex::BitAndWith<int_least16_t, std::wstring_view>);

        // int_fast16_t with Charaters
        REQUIRE(cortex::BitAndWith<int_least16_t, char>);
        REQUIRE(cortex::BitAndWith<int_least16_t, u_char>);
        REQUIRE(cortex::BitAndWith<int_least16_t, wchar_t>);

        // int_fast16_t with Bit Specific Characters
        REQUIRE(cortex::BitAndWith<int_least16_t, char8_t>);
        REQUIRE(cortex::BitAndWith<int_least16_t, char16_t>);
        REQUIRE(cortex::BitAndWith<int_least16_t, char32_t>);

        // int_fast16_t with Bit Specific Integers
        REQUIRE(cortex::BitAndWith<int_least16_t, int8_t>);
        REQUIRE(cortex::BitAndWith<int_least16_t, int16_t>);
        REQUIRE(cortex::BitAndWith<int_least16_t, int32_t>);
        REQUIRE(cortex::BitAndWith<int_least16_t, int64_t>);

        // int_fast16_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::BitAndWith<int_least16_t, uint8_t>);
        REQUIRE(cortex::BitAndWith<int_least16_t, uint16_t>);
        REQUIRE(cortex::BitAndWith<int_least16_t, uint32_t>);
        REQUIRE(cortex::BitAndWith<int_least16_t, uint64_t>);

        // int_fast16_t with Bit Specific Least Integers
        REQUIRE(cortex::BitAndWith<int_least16_t, int_least8_t>);
        REQUIRE(cortex::BitAndWith<int_least16_t, int_least16_t>);
        REQUIRE(cortex::BitAndWith<int_least16_t, int_least32_t>);
        REQUIRE(cortex::BitAndWith<int_least16_t, int_least64_t>);
    }

    SECTION("int_least32_t with _")
    {
        // int32 with Signed Integers
        REQUIRE(cortex::BitAndWith<int_least32_t, int>);
        REQUIRE(cortex::BitAndWith<int_least32_t, short>);
        REQUIRE(cortex::BitAndWith<int_least32_t, long>);
        REQUIRE(cortex::BitAndWith<int_least32_t, long long>);

        // int32 with Unsigned Integers
        REQUIRE(cortex::BitAndWith<int_least32_t, unsigned>);
        REQUIRE(cortex::BitAndWith<int_least32_t, unsigned short>);
        REQUIRE(cortex::BitAndWith<int_least32_t, u_short>);
        REQUIRE(cortex::BitAndWith<int_least32_t, unsigned long>);
        REQUIRE(cortex::BitAndWith<int_least32_t, unsigned long long>);
        
        // int32 with Floating Point and Doubles
        REQUIRE(!cortex::BitAndWith<int_least32_t, float>);
        REQUIRE(!cortex::BitAndWith<int_least32_t, double>);
        REQUIRE(!cortex::BitAndWith<int_least32_t, long double>);

        // int32 with std::strings and std::string_view
        REQUIRE(!cortex::BitAndWith<int_least32_t, std::string>);
        REQUIRE(!cortex::BitAndWith<int_least32_t, std::string_view>);
        REQUIRE(!cortex::BitAndWith<int_least32_t, std::u8string>);
        REQUIRE(!cortex::BitAndWith<int_least32_t, std::u16string>);
        REQUIRE(!cortex::BitAndWith<int_least32_t, std::u32string>);

        // int32 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitAndWith<int_least32_t, std::wstring>);
        REQUIRE(!cortex::BitAndWith<int_least32_t, std::wstring_view>);

        // int_fast32_t with Charaters
        REQUIRE(cortex::BitAndWith<int_least32_t, char>);
        REQUIRE(cortex::BitAndWith<int_least32_t, u_char>);
        REQUIRE(cortex::BitAndWith<int_least32_t, wchar_t>);

        // int_fast32_t with Bit Specific Characters
        REQUIRE(cortex::BitAndWith<int_least32_t, char8_t>);
        REQUIRE(cortex::BitAndWith<int_least32_t, char16_t>);
        REQUIRE(cortex::BitAndWith<int_least32_t, char32_t>);

        // int_fast32_t with Bit Specific Integers
        REQUIRE(cortex::BitAndWith<int_least32_t, int8_t>);
        REQUIRE(cortex::BitAndWith<int_least32_t, int16_t>);
        REQUIRE(cortex::BitAndWith<int_least32_t, int32_t>);
        REQUIRE(cortex::BitAndWith<int_least32_t, int64_t>);

        // int_fast32_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::BitAndWith<int_least32_t, uint8_t>);
        REQUIRE(cortex::BitAndWith<int_least32_t, uint16_t>);
        REQUIRE(cortex::BitAndWith<int_least32_t, uint32_t>);
        REQUIRE(cortex::BitAndWith<int_least32_t, uint64_t>);

        // int_fast32_t with Bit Specific Least Integers
        REQUIRE(cortex::BitAndWith<int_least32_t, int_least8_t>);
        REQUIRE(cortex::BitAndWith<int_least32_t, int_least16_t>);
        REQUIRE(cortex::BitAndWith<int_least32_t, int_least32_t>);
        REQUIRE(cortex::BitAndWith<int_least32_t, int_least64_t>);
    }

    SECTION("int_least64_t with _")
    {
        // int64 with Signed Integers
        REQUIRE(cortex::BitAndWith<int_least64_t, int>);
        REQUIRE(cortex::BitAndWith<int_least64_t, short>);
        REQUIRE(cortex::BitAndWith<int_least64_t, long>);
        REQUIRE(cortex::BitAndWith<int_least64_t, long long>);

        // int64 with Unsigned Integers
        REQUIRE(cortex::BitAndWith<int_least64_t, unsigned>);
        REQUIRE(cortex::BitAndWith<int_least64_t, unsigned short>);
        REQUIRE(cortex::BitAndWith<int_least64_t, u_short>);
        REQUIRE(cortex::BitAndWith<int_least64_t, unsigned long>);
        REQUIRE(cortex::BitAndWith<int_least64_t, unsigned long long>);
        
        // int64 with Floating Point and Doubles
        REQUIRE(!cortex::BitAndWith<int_least64_t, float>);
        REQUIRE(!cortex::BitAndWith<int_least64_t, double>);
        REQUIRE(!cortex::BitAndWith<int_least64_t, long double>);

        // int64 with std::strings and std::string_view
        REQUIRE(!cortex::BitAndWith<int_least64_t, std::string>);
        REQUIRE(!cortex::BitAndWith<int_least64_t, std::string_view>);
        REQUIRE(!cortex::BitAndWith<int_least64_t, std::u8string>);
        REQUIRE(!cortex::BitAndWith<int_least64_t, std::u16string>);
        REQUIRE(!cortex::BitAndWith<int_least64_t, std::u32string>);

        // int64 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitAndWith<int_least64_t, std::wstring>);
        REQUIRE(!cortex::BitAndWith<int_least64_t, std::wstring_view>);

        // int_fast64_t with Charaters
        REQUIRE(cortex::BitAndWith<int_least64_t, char>);
        REQUIRE(cortex::BitAndWith<int_least64_t, u_char>);
        REQUIRE(cortex::BitAndWith<int_least64_t, wchar_t>);

        // int_fast64_t with Bit Specific Characters
        REQUIRE(cortex::BitAndWith<int_least64_t, char8_t>);
        REQUIRE(cortex::BitAndWith<int_least64_t, char16_t>);
        REQUIRE(cortex::BitAndWith<int_least64_t, char32_t>);

        // int_fast64_t with Bit Specific Integers
        REQUIRE(cortex::BitAndWith<int_least64_t, int8_t>);
        REQUIRE(cortex::BitAndWith<int_least64_t, int16_t>);
        REQUIRE(cortex::BitAndWith<int_least64_t, int32_t>);
        REQUIRE(cortex::BitAndWith<int_least64_t, int64_t>);

        // int_fast64_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::BitAndWith<int_least64_t, uint8_t>);
        REQUIRE(cortex::BitAndWith<int_least64_t, uint16_t>);
        REQUIRE(cortex::BitAndWith<int_least64_t, uint32_t>);
        REQUIRE(cortex::BitAndWith<int_least64_t, uint64_t>);

        // int_fast64_t with Bit Specific Least Integers
        REQUIRE(cortex::BitAndWith<int_least64_t, int_least8_t>);
        REQUIRE(cortex::BitAndWith<int_least64_t, int_least16_t>);
        REQUIRE(cortex::BitAndWith<int_least64_t, int_least32_t>);
        REQUIRE(cortex::BitAndWith<int_least64_t, int_least64_t>);
    }
}