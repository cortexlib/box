#include <catch2/catch.hpp>
#include <concepts.hpp>
#include <string>
#include <string_view>

TEST_CASE("AddableWith : Signed Integers")
{
    SECTION("Int with _")
    {
        // Int with Signed Integers
        REQUIRE(cortex::AddableWith<int, int>);
        REQUIRE(cortex::AddableWith<int, short>);
        REQUIRE(cortex::AddableWith<int, long>);
        REQUIRE(cortex::AddableWith<int, long long>);

        // Int with Unsigned Integers
        REQUIRE(cortex::AddableWith<int, unsigned>);
        REQUIRE(cortex::AddableWith<int, unsigned short>);
        REQUIRE(cortex::AddableWith<int, u_short>);
        REQUIRE(cortex::AddableWith<int, unsigned long>);
        REQUIRE(cortex::AddableWith<int, unsigned long long>);
        
        // Integers with Floating Point and Doubles
        REQUIRE(cortex::AddableWith<int, float>);
        REQUIRE(cortex::AddableWith<int, double>);
        REQUIRE(cortex::AddableWith<int, long double>);

        // Integers with std::strings and std::string_view
        REQUIRE(!cortex::AddableWith<int, std::string>);
        REQUIRE(!cortex::AddableWith<int, std::string_view>);
        REQUIRE(!cortex::AddableWith<int, std::u8string>);
        REQUIRE(!cortex::AddableWith<int, std::u16string>);
        REQUIRE(!cortex::AddableWith<int, std::u32string>);

        // Integers with std::wstrings and std::wstring_view
        REQUIRE(!cortex::AddableWith<int, std::wstring>);
        REQUIRE(!cortex::AddableWith<int, std::wstring_view>);

        // Integers with Charaters
        REQUIRE(cortex::AddableWith<int, char>);
        REQUIRE(cortex::AddableWith<int, u_char>);
        REQUIRE(cortex::AddableWith<int, wchar_t>);

        // Integers with Bit Specific Characters
        REQUIRE(cortex::AddableWith<int, char8_t>);
        REQUIRE(cortex::AddableWith<int, char16_t>);
        REQUIRE(cortex::AddableWith<int, char32_t>);

        // Integers with Bit Specific Integers
        REQUIRE(cortex::AddableWith<int, int8_t>);
        REQUIRE(cortex::AddableWith<int, int16_t>);
        REQUIRE(cortex::AddableWith<int, int32_t>);
        REQUIRE(cortex::AddableWith<int, int64_t>);

        // Integers with Bit Specific Unsigned Integers
        REQUIRE(cortex::AddableWith<int, uint8_t>);
        REQUIRE(cortex::AddableWith<int, uint16_t>);
        REQUIRE(cortex::AddableWith<int, uint32_t>);
        REQUIRE(cortex::AddableWith<int, uint64_t>);

        // Integers with Bit Specific Least Integers
        REQUIRE(cortex::AddableWith<int, int_least8_t>);
        REQUIRE(cortex::AddableWith<int, int_least16_t>);
        REQUIRE(cortex::AddableWith<int, int_least32_t>);
        REQUIRE(cortex::AddableWith<int, int_least64_t>);
    }

    SECTION("Short with _")
    {
        // Short with Signed Integers
        REQUIRE(cortex::AddableWith<short, int>);
        REQUIRE(cortex::AddableWith<short, short>);
        REQUIRE(cortex::AddableWith<short, long>);
        REQUIRE(cortex::AddableWith<short, long long>);

        // Short with Unsigned Integers
        REQUIRE(cortex::AddableWith<short, unsigned>);
        REQUIRE(cortex::AddableWith<short, unsigned short>);
        REQUIRE(cortex::AddableWith<short, u_short>);
        REQUIRE(cortex::AddableWith<short, unsigned long>);
        REQUIRE(cortex::AddableWith<short, unsigned long long>);
        
        // Short with Floating Point and Doubles
        REQUIRE(cortex::AddableWith<short, float>);
        REQUIRE(cortex::AddableWith<short, double>);
        REQUIRE(cortex::AddableWith<short, long double>);

        // Short with std::strings and std::string_view
        REQUIRE(!cortex::AddableWith<short, std::string>);
        REQUIRE(!cortex::AddableWith<short, std::string_view>);
        REQUIRE(!cortex::AddableWith<short, std::u8string>);
        REQUIRE(!cortex::AddableWith<short, std::u16string>);
        REQUIRE(!cortex::AddableWith<short, std::u32string>);

        // Short with std::wstrings and std::wstring_view
        REQUIRE(!cortex::AddableWith<short, std::wstring>);
        REQUIRE(!cortex::AddableWith<short, std::wstring_view>);

        // Short with Charaters
        REQUIRE(cortex::AddableWith<short, char>);
        REQUIRE(cortex::AddableWith<short, u_char>);
        REQUIRE(cortex::AddableWith<short, wchar_t>);

        // Short with Bit Specific Characters
        REQUIRE(cortex::AddableWith<short, char8_t>);
        REQUIRE(cortex::AddableWith<short, char16_t>);
        REQUIRE(cortex::AddableWith<short, char32_t>);

        // Short with Bit Specific Short
        REQUIRE(cortex::AddableWith<short, int8_t>);
        REQUIRE(cortex::AddableWith<short, int16_t>);
        REQUIRE(cortex::AddableWith<short, int32_t>);
        REQUIRE(cortex::AddableWith<short, int64_t>);

        // Short with Bit Specific Unsigned Short
        REQUIRE(cortex::AddableWith<short, uint8_t>);
        REQUIRE(cortex::AddableWith<short, uint16_t>);
        REQUIRE(cortex::AddableWith<short, uint32_t>);
        REQUIRE(cortex::AddableWith<short, uint64_t>);

        // Short with Bit Specific Least Integers
        REQUIRE(cortex::AddableWith<short, int_least8_t>);
        REQUIRE(cortex::AddableWith<short, int_least16_t>);
        REQUIRE(cortex::AddableWith<short, int_least32_t>);
        REQUIRE(cortex::AddableWith<short, int_least64_t>);
    }

    SECTION("Long with _")
    {
        // Long with Signed Integers
        REQUIRE(cortex::AddableWith<long, int>);
        REQUIRE(cortex::AddableWith<long, short>);
        REQUIRE(cortex::AddableWith<long, long>);
        REQUIRE(cortex::AddableWith<long, long long>);

        // Long with Unsigned Integers
        REQUIRE(cortex::AddableWith<long, unsigned>);
        REQUIRE(cortex::AddableWith<long, unsigned short>);
        REQUIRE(cortex::AddableWith<long, u_short>);
        REQUIRE(cortex::AddableWith<long, unsigned long>);
        REQUIRE(cortex::AddableWith<long, unsigned long long>);
        
        // Long with Floating Point and Doubles
        REQUIRE(cortex::AddableWith<long, float>);
        REQUIRE(cortex::AddableWith<long, double>);
        REQUIRE(cortex::AddableWith<long, long double>);

        // Long with std::strings and std::string_view
        REQUIRE(!cortex::AddableWith<long, std::string>);
        REQUIRE(!cortex::AddableWith<long, std::string_view>);
        REQUIRE(!cortex::AddableWith<long, std::u8string>);
        REQUIRE(!cortex::AddableWith<long, std::u16string>);
        REQUIRE(!cortex::AddableWith<long, std::u32string>);

        // Long with std::wstrings and std::wstring_view
        REQUIRE(!cortex::AddableWith<long, std::wstring>);
        REQUIRE(!cortex::AddableWith<long, std::wstring_view>);

        // Long with Charaters
        REQUIRE(cortex::AddableWith<long, char>);
        REQUIRE(cortex::AddableWith<long, u_char>);
        REQUIRE(cortex::AddableWith<long, wchar_t>);

        // Long with Bit Specific Characters
        REQUIRE(cortex::AddableWith<long, char8_t>);
        REQUIRE(cortex::AddableWith<long, char16_t>);
        REQUIRE(cortex::AddableWith<long, char32_t>);

        // Long with Bit Specific Long
        REQUIRE(cortex::AddableWith<long, int8_t>);
        REQUIRE(cortex::AddableWith<long, int16_t>);
        REQUIRE(cortex::AddableWith<long, int32_t>);
        REQUIRE(cortex::AddableWith<long, int64_t>);

        // Long with Bit Specific Unsigned Long
        REQUIRE(cortex::AddableWith<long, uint8_t>);
        REQUIRE(cortex::AddableWith<long, uint16_t>);
        REQUIRE(cortex::AddableWith<long, uint32_t>);
        REQUIRE(cortex::AddableWith<long, uint64_t>);

        // Long with Bit Specific Least Integers
        REQUIRE(cortex::AddableWith<long, int_least8_t>);
        REQUIRE(cortex::AddableWith<long, int_least16_t>);
        REQUIRE(cortex::AddableWith<long, int_least32_t>);
        REQUIRE(cortex::AddableWith<long, int_least64_t>);
    }

    SECTION("Long Long with _")
    {
        // Signed Integers
        REQUIRE(cortex::AddableWith<long long, int>);
        REQUIRE(cortex::AddableWith<long long, short>);
        REQUIRE(cortex::AddableWith<long long, long>);
        REQUIRE(cortex::AddableWith<long long, long long>);

        // Unsigned Integers
        REQUIRE(cortex::AddableWith<long long, unsigned>);
        REQUIRE(cortex::AddableWith<long long, unsigned short>);
        REQUIRE(cortex::AddableWith<long long, u_short>);
        REQUIRE(cortex::AddableWith<long long, unsigned long>);
        REQUIRE(cortex::AddableWith<long long, unsigned long long>);
        
        // Integers with Floating Point and Doubles
        REQUIRE(cortex::AddableWith<long long, float>);
        REQUIRE(cortex::AddableWith<long long, double>);
        REQUIRE(cortex::AddableWith<long long, long double>);

        // Integers with std::strings and std::string_view
        REQUIRE(!cortex::AddableWith<long long, std::string>);
        REQUIRE(!cortex::AddableWith<long long, std::string_view>);
        REQUIRE(!cortex::AddableWith<long long, std::u8string>);
        REQUIRE(!cortex::AddableWith<long long, std::u16string>);
        REQUIRE(!cortex::AddableWith<long long, std::u32string>);

        // Integers with std::wstrings and std::wstring_view
        REQUIRE(!cortex::AddableWith<long long, std::wstring>);
        REQUIRE(!cortex::AddableWith<long long, std::wstring_view>);

        // Integers with Charaters
        REQUIRE(cortex::AddableWith<long long, char>);
        REQUIRE(cortex::AddableWith<long long, u_char>);
        REQUIRE(cortex::AddableWith<long long, wchar_t>);

        // Integers with Bit Specific Characters
        REQUIRE(cortex::AddableWith<long long, char8_t>);
        REQUIRE(cortex::AddableWith<long long, char16_t>);
        REQUIRE(cortex::AddableWith<long long, char32_t>);

        // Integers with Bit Specific Integers
        REQUIRE(cortex::AddableWith<long long, int8_t>);
        REQUIRE(cortex::AddableWith<long long, int16_t>);
        REQUIRE(cortex::AddableWith<long long, int32_t>);
        REQUIRE(cortex::AddableWith<long long, int64_t>);

        // Integers with Bit Specific Unsigned Integers
        REQUIRE(cortex::AddableWith<long long, uint8_t>);
        REQUIRE(cortex::AddableWith<long long, uint16_t>);
        REQUIRE(cortex::AddableWith<long long, uint32_t>);
        REQUIRE(cortex::AddableWith<long long, uint64_t>);

        // Long Long with Bit Specific Least Integers
        REQUIRE(cortex::AddableWith<long long, int_least8_t>);
        REQUIRE(cortex::AddableWith<long long, int_least16_t>);
        REQUIRE(cortex::AddableWith<long long, int_least32_t>);
        REQUIRE(cortex::AddableWith<long long, int_least64_t>);
    }
}

TEST_CASE("AddableWith: Unsigned Integers")
{
    SECTION("Unsigned Int with _")
    {
        // Unsigned Integers with Signed Integers
        REQUIRE(cortex::AddableWith<unsigned int, int>);
        REQUIRE(cortex::AddableWith<unsigned int, short>);
        REQUIRE(cortex::AddableWith<unsigned int, long>);
        REQUIRE(cortex::AddableWith<unsigned int, long long>);

        // Unsigned Integers with Unsigned Integers
        REQUIRE(cortex::AddableWith<unsigned int, unsigned>);
        REQUIRE(cortex::AddableWith<unsigned int, unsigned short>);
        REQUIRE(cortex::AddableWith<unsigned int, u_short>);
        REQUIRE(cortex::AddableWith<unsigned int, unsigned long>);
        REQUIRE(cortex::AddableWith<unsigned int, unsigned long long>);
        
        // Unsigned Integers with Floating Point and Doubles
        REQUIRE(cortex::AddableWith<unsigned int, float>);
        REQUIRE(cortex::AddableWith<unsigned int, double>);
        REQUIRE(cortex::AddableWith<unsigned int, long double>);

        // Unsigned Integers with std::strings and std::string_view
        REQUIRE(!cortex::AddableWith<unsigned int, std::string>);
        REQUIRE(!cortex::AddableWith<unsigned int, std::string_view>);
        REQUIRE(!cortex::AddableWith<unsigned int, std::u8string>);
        REQUIRE(!cortex::AddableWith<unsigned int, std::u16string>);
        REQUIRE(!cortex::AddableWith<unsigned int, std::u32string>);

        // Unsigned Integers with std::wstrings and std::wstring_view
        REQUIRE(!cortex::AddableWith<unsigned long long, std::wstring>);
        REQUIRE(!cortex::AddableWith<unsigned long long, std::wstring_view>);

        // Unsigned Integers with Charaters
        REQUIRE(cortex::AddableWith<unsigned int, char>);
        REQUIRE(cortex::AddableWith<unsigned int, u_char>);
        REQUIRE(cortex::AddableWith<unsigned int, wchar_t>);

        // Unsigned Integers with Bit Specific Characters
        REQUIRE(cortex::AddableWith<unsigned int, char8_t>);
        REQUIRE(cortex::AddableWith<unsigned int, char16_t>);
        REQUIRE(cortex::AddableWith<unsigned int, char32_t>);

        // Unsigned Integers with Bit Specific Integers
        REQUIRE(cortex::AddableWith<unsigned int, int8_t>);
        REQUIRE(cortex::AddableWith<unsigned int, int16_t>);
        REQUIRE(cortex::AddableWith<unsigned int, int32_t>);
        REQUIRE(cortex::AddableWith<unsigned int, int64_t>);

        // Unsigned Integers with Bit Specific Unsigned Integers
        REQUIRE(cortex::AddableWith<unsigned int, uint8_t>);
        REQUIRE(cortex::AddableWith<unsigned int, uint16_t>);
        REQUIRE(cortex::AddableWith<unsigned int, uint32_t>);
        REQUIRE(cortex::AddableWith<unsigned int, uint64_t>);

        // Unsigned Integers with Bit Specific Least Integers
        REQUIRE(cortex::AddableWith<unsigned int, int_least8_t>);
        REQUIRE(cortex::AddableWith<unsigned int, int_least16_t>);
        REQUIRE(cortex::AddableWith<unsigned int, int_least32_t>);
        REQUIRE(cortex::AddableWith<unsigned int, int_least64_t>);
    }

    SECTION("Unsigned Short with _")
    {
        // Unsigned Short with Signed Integers
        REQUIRE(cortex::AddableWith<unsigned short, int>);
        REQUIRE(cortex::AddableWith<unsigned short, short>);
        REQUIRE(cortex::AddableWith<unsigned short, long>);
        REQUIRE(cortex::AddableWith<unsigned short, long long>);

        // Unsigned Short with Unsigned Integers
        REQUIRE(cortex::AddableWith<unsigned short, unsigned>);
        REQUIRE(cortex::AddableWith<unsigned short, unsigned short>);
        REQUIRE(cortex::AddableWith<unsigned short, u_short>);
        REQUIRE(cortex::AddableWith<unsigned short, unsigned long>);
        REQUIRE(cortex::AddableWith<unsigned short, unsigned long long>);
        
        // Unsigned Short with Floating Point and Doubles
        REQUIRE(cortex::AddableWith<unsigned short, float>);
        REQUIRE(cortex::AddableWith<unsigned short, double>);
        REQUIRE(cortex::AddableWith<unsigned short, long double>);

        // Unsigned Short with std::strings and std::string_view
        REQUIRE(!cortex::AddableWith<unsigned short, std::string>);
        REQUIRE(!cortex::AddableWith<unsigned short, std::string_view>);
        REQUIRE(!cortex::AddableWith<unsigned short, std::u8string>);
        REQUIRE(!cortex::AddableWith<unsigned short, std::u16string>);
        REQUIRE(!cortex::AddableWith<unsigned short, std::u32string>);

        // Unsigned Short with std::wstrings and std::wstring_view
        REQUIRE(!cortex::AddableWith<unsigned short, std::wstring>);
        REQUIRE(!cortex::AddableWith<unsigned short, std::wstring_view>);

        // Unsigned Short with Charaters
        REQUIRE(cortex::AddableWith<unsigned short, char>);
        REQUIRE(cortex::AddableWith<unsigned short, u_char>);
        REQUIRE(cortex::AddableWith<unsigned short, wchar_t>);

        // Unsigned Short with Bit Specific Characters
        REQUIRE(cortex::AddableWith<unsigned short, char8_t>);
        REQUIRE(cortex::AddableWith<unsigned short, char16_t>);
        REQUIRE(cortex::AddableWith<unsigned short, char32_t>);

        // Unsigned Short with Bit Specific Short
        REQUIRE(cortex::AddableWith<unsigned short, int8_t>);
        REQUIRE(cortex::AddableWith<unsigned short, int16_t>);
        REQUIRE(cortex::AddableWith<unsigned short, int32_t>);
        REQUIRE(cortex::AddableWith<unsigned short, int64_t>);

        // Unsigned Short with Bit Specific Unsigned Short
        REQUIRE(cortex::AddableWith<unsigned short, uint8_t>);
        REQUIRE(cortex::AddableWith<unsigned short, uint16_t>);
        REQUIRE(cortex::AddableWith<unsigned short, uint32_t>);
        REQUIRE(cortex::AddableWith<unsigned short, uint64_t>);

        // Unsigned Short with Bit Specific Least Integers
        REQUIRE(cortex::AddableWith<unsigned short, int_least8_t>);
        REQUIRE(cortex::AddableWith<unsigned short, int_least16_t>);
        REQUIRE(cortex::AddableWith<unsigned short, int_least32_t>);
        REQUIRE(cortex::AddableWith<unsigned short, int_least64_t>);
    }

    SECTION("u_short with _")
    {
        // u_short with Signed Integers
        REQUIRE(cortex::AddableWith<u_short, int>);
        REQUIRE(cortex::AddableWith<u_short, short>);
        REQUIRE(cortex::AddableWith<u_short, long>);
        REQUIRE(cortex::AddableWith<u_short, long long>);

        // u_short with Unsigned Integers
        REQUIRE(cortex::AddableWith<u_short, unsigned>);
        REQUIRE(cortex::AddableWith<u_short, unsigned short>);
        REQUIRE(cortex::AddableWith<u_short, u_short>);
        REQUIRE(cortex::AddableWith<u_short, unsigned long>);
        REQUIRE(cortex::AddableWith<u_short, unsigned long long>);
        
        // u_short with Floating Point and Doubles
        REQUIRE(cortex::AddableWith<u_short, float>);
        REQUIRE(cortex::AddableWith<u_short, double>);
        REQUIRE(cortex::AddableWith<u_short, long double>);

        // u_short with std::strings and std::string_view
        REQUIRE(!cortex::AddableWith<u_short, std::string>);
        REQUIRE(!cortex::AddableWith<u_short, std::string_view>);
        REQUIRE(!cortex::AddableWith<u_short, std::u8string>);
        REQUIRE(!cortex::AddableWith<u_short, std::u16string>);
        REQUIRE(!cortex::AddableWith<u_short, std::u32string>);

        // u_short with std::wstrings and std::wstring_view
        REQUIRE(!cortex::AddableWith<u_short, std::wstring>);
        REQUIRE(!cortex::AddableWith<u_short, std::wstring_view>);

        // u_short with Charaters
        REQUIRE(cortex::AddableWith<u_short, char>);
        REQUIRE(cortex::AddableWith<u_short, u_char>);
        REQUIRE(cortex::AddableWith<u_short, wchar_t>);

        // u_short with Bit Specific Characters
        REQUIRE(cortex::AddableWith<u_short, char8_t>);
        REQUIRE(cortex::AddableWith<u_short, char16_t>);
        REQUIRE(cortex::AddableWith<u_short, char32_t>);

        // u_short with Bit Specific Short
        REQUIRE(cortex::AddableWith<u_short, int8_t>);
        REQUIRE(cortex::AddableWith<u_short, int16_t>);
        REQUIRE(cortex::AddableWith<u_short, int32_t>);
        REQUIRE(cortex::AddableWith<u_short, int64_t>);

        // u_short with Bit Specific Unsigned Short
        REQUIRE(cortex::AddableWith<u_short, uint8_t>);
        REQUIRE(cortex::AddableWith<u_short, uint16_t>);
        REQUIRE(cortex::AddableWith<u_short, uint32_t>);
        REQUIRE(cortex::AddableWith<u_short, uint64_t>);

        // u_short with Bit Specific Least Integers
        REQUIRE(cortex::AddableWith<u_short, int_least8_t>);
        REQUIRE(cortex::AddableWith<u_short, int_least16_t>);
        REQUIRE(cortex::AddableWith<u_short, int_least32_t>);
        REQUIRE(cortex::AddableWith<u_short, int_least64_t>);
    }

    SECTION("Unsigned Long with _")
    {
        // Unsigned Long with Signed Integers
        REQUIRE(cortex::AddableWith<unsigned long, int>);
        REQUIRE(cortex::AddableWith<unsigned long, short>);
        REQUIRE(cortex::AddableWith<unsigned long, long>);
        REQUIRE(cortex::AddableWith<unsigned long, long long>);

        // Unsigned Long with Unsigned Integers
        REQUIRE(cortex::AddableWith<unsigned long, unsigned>);
        REQUIRE(cortex::AddableWith<unsigned long, unsigned short>);
        REQUIRE(cortex::AddableWith<unsigned long, u_short>);
        REQUIRE(cortex::AddableWith<unsigned long, unsigned long>);
        REQUIRE(cortex::AddableWith<unsigned long, unsigned long long>);
        
        // Unsigned Long with Floating Point and Doubles
        REQUIRE(cortex::AddableWith<unsigned long, float>);
        REQUIRE(cortex::AddableWith<unsigned long, double>);
        REQUIRE(cortex::AddableWith<unsigned long, long double>);

        // Unsigned Long with std::strings and std::string_view
        REQUIRE(!cortex::AddableWith<unsigned long, std::string>);
        REQUIRE(!cortex::AddableWith<unsigned long, std::string_view>);
        REQUIRE(!cortex::AddableWith<unsigned long, std::u8string>);
        REQUIRE(!cortex::AddableWith<unsigned long, std::u16string>);
        REQUIRE(!cortex::AddableWith<unsigned long, std::u32string>);

        // Unsigned Long with std::wstrings and std::wstring_view
        REQUIRE(!cortex::AddableWith<unsigned long, std::wstring>);
        REQUIRE(!cortex::AddableWith<unsigned long, std::wstring_view>);

        // Unsigned Long with Charaters
        REQUIRE(cortex::AddableWith<unsigned long, char>);
        REQUIRE(cortex::AddableWith<unsigned long, u_char>);
        REQUIRE(cortex::AddableWith<unsigned long, wchar_t>);

        // Unsigned Long with Bit Specific Characters
        REQUIRE(cortex::AddableWith<unsigned long, char8_t>);
        REQUIRE(cortex::AddableWith<unsigned long, char16_t>);
        REQUIRE(cortex::AddableWith<unsigned long, char32_t>);

        // Unsigned Long with Bit Specific Long
        REQUIRE(cortex::AddableWith<unsigned long, int8_t>);
        REQUIRE(cortex::AddableWith<unsigned long, int16_t>);
        REQUIRE(cortex::AddableWith<unsigned long, int32_t>);
        REQUIRE(cortex::AddableWith<unsigned long, int64_t>);

        // Unsigned Long with Bit Specific Unsigned Long
        REQUIRE(cortex::AddableWith<unsigned long, uint8_t>);
        REQUIRE(cortex::AddableWith<unsigned long, uint16_t>);
        REQUIRE(cortex::AddableWith<unsigned long, uint32_t>);
        REQUIRE(cortex::AddableWith<unsigned long, uint64_t>);

        // Unsigned Long with Bit Specific Least Integers
        REQUIRE(cortex::AddableWith<unsigned long, int_least8_t>);
        REQUIRE(cortex::AddableWith<unsigned long, int_least16_t>);
        REQUIRE(cortex::AddableWith<unsigned long, int_least32_t>);
        REQUIRE(cortex::AddableWith<unsigned long, int_least64_t>);
    }

    SECTION("Unsigned Long Long with _")
    {
        // Unsigned Long Long with Signed Integers
        REQUIRE(cortex::AddableWith<unsigned long long, int>);
        REQUIRE(cortex::AddableWith<unsigned long long, short>);
        REQUIRE(cortex::AddableWith<unsigned long long, long>);
        REQUIRE(cortex::AddableWith<unsigned long long, long long>);

        // Unsigned Long Long with Unsigned Integers
        REQUIRE(cortex::AddableWith<unsigned long long, unsigned>);
        REQUIRE(cortex::AddableWith<unsigned long long, unsigned short>);
        REQUIRE(cortex::AddableWith<unsigned long long, u_short>);
        REQUIRE(cortex::AddableWith<unsigned long long, unsigned long>);
        REQUIRE(cortex::AddableWith<unsigned long long, unsigned long long>);
        
        // Unsigned Long Long with Floating Point and Doubles
        REQUIRE(cortex::AddableWith<unsigned long long, float>);
        REQUIRE(cortex::AddableWith<unsigned long long, double>);
        REQUIRE(cortex::AddableWith<unsigned long long, long double>);

        // Unsigned Long Long with std::strings and std::string_view
        REQUIRE(!cortex::AddableWith<unsigned long long, std::string>);
        REQUIRE(!cortex::AddableWith<unsigned long long, std::string_view>);
        REQUIRE(!cortex::AddableWith<unsigned long long, std::u8string>);
        REQUIRE(!cortex::AddableWith<unsigned long long, std::u16string>);
        REQUIRE(!cortex::AddableWith<unsigned long long, std::u32string>);

        // Unsigned Long Long with std::wstrings and std::wstring_view
        REQUIRE(!cortex::AddableWith<unsigned long long, std::wstring>);
        REQUIRE(!cortex::AddableWith<unsigned long long, std::wstring_view>);

        // Unsigned Long Long with Charaters
        REQUIRE(cortex::AddableWith<unsigned long long, char>);
        REQUIRE(cortex::AddableWith<unsigned long long, u_char>);
        REQUIRE(cortex::AddableWith<unsigned long long, wchar_t>);

        // Unsigned Long Long with Bit Specific Characters
        REQUIRE(cortex::AddableWith<unsigned long long, char8_t>);
        REQUIRE(cortex::AddableWith<unsigned long long, char16_t>);
        REQUIRE(cortex::AddableWith<unsigned long long, char32_t>);

        // Unsigned Long Long with Bit Specific Long Long
        REQUIRE(cortex::AddableWith<unsigned long long, int8_t>);
        REQUIRE(cortex::AddableWith<unsigned long long, int16_t>);
        REQUIRE(cortex::AddableWith<unsigned long long, int32_t>);
        REQUIRE(cortex::AddableWith<unsigned long long, int64_t>);

        // Unsigned Long Long with Bit Specific Unsigned Long Long
        REQUIRE(cortex::AddableWith<unsigned long long, uint8_t>);
        REQUIRE(cortex::AddableWith<unsigned long long, uint16_t>);
        REQUIRE(cortex::AddableWith<unsigned long long, uint32_t>);
        REQUIRE(cortex::AddableWith<unsigned long long, uint64_t>);

        // Long Long with Bit Specific Least Long Long
        REQUIRE(cortex::AddableWith<unsigned long long, int_least8_t>);
        REQUIRE(cortex::AddableWith<unsigned long long, int_least16_t>);
        REQUIRE(cortex::AddableWith<unsigned long long, int_least32_t>);
        REQUIRE(cortex::AddableWith<unsigned long long, int_least64_t>);
    }
}

TEST_CASE("AddableWith : Floats & Doubles") 
{
    SECTION("Float with _")
    {
        // Floats with Signed Integers
        REQUIRE(cortex::AddableWith<float, int>);
        REQUIRE(cortex::AddableWith<float, short>);
        REQUIRE(cortex::AddableWith<float, long>);
        REQUIRE(cortex::AddableWith<float, long long>);

        // Floats with Unsigned Integers
        REQUIRE(cortex::AddableWith<float, unsigned>);
        REQUIRE(cortex::AddableWith<float, unsigned short>);
        REQUIRE(cortex::AddableWith<float, u_short>);
        REQUIRE(cortex::AddableWith<float, unsigned long>);
        REQUIRE(cortex::AddableWith<float, unsigned long long>);
        
        // Float with Floating Point and Doubles
        REQUIRE(cortex::AddableWith<float, float>);
        REQUIRE(cortex::AddableWith<float, double>);
        REQUIRE(cortex::AddableWith<float, long double>);

        // Float with std::strings and std::string_view
        REQUIRE(!cortex::AddableWith<float, std::string>);
        REQUIRE(!cortex::AddableWith<float, std::string_view>);
        REQUIRE(!cortex::AddableWith<float, std::u8string>);
        REQUIRE(!cortex::AddableWith<float, std::u16string>);
        REQUIRE(!cortex::AddableWith<float, std::u32string>);

        // Float with std::wstrings and std::wstring_view
        REQUIRE(!cortex::AddableWith<long long, std::wstring>);
        REQUIRE(!cortex::AddableWith<long long, std::wstring_view>);

        // Float with Charaters
        REQUIRE(cortex::AddableWith<float, char>);
        REQUIRE(cortex::AddableWith<float, u_char>);
        REQUIRE(cortex::AddableWith<float, wchar_t>);

        // Float with Bit Specific Characters
        REQUIRE(cortex::AddableWith<float, char8_t>);
        REQUIRE(cortex::AddableWith<float, char16_t>);
        REQUIRE(cortex::AddableWith<float, char32_t>);

        // Float with Bit Specific Integers
        REQUIRE(cortex::AddableWith<float, int8_t>);
        REQUIRE(cortex::AddableWith<float, int16_t>);
        REQUIRE(cortex::AddableWith<float, int32_t>);
        REQUIRE(cortex::AddableWith<float, int64_t>);

        // Float with Bit Specific Unsigned Integers
        REQUIRE(cortex::AddableWith<float, uint8_t>);
        REQUIRE(cortex::AddableWith<float, uint16_t>);
        REQUIRE(cortex::AddableWith<float, uint32_t>);
        REQUIRE(cortex::AddableWith<float, uint64_t>);

        // Float with Bit Specific Least Integers
        REQUIRE(cortex::AddableWith<float, int_least8_t>);
        REQUIRE(cortex::AddableWith<float, int_least16_t>);
        REQUIRE(cortex::AddableWith<float, int_least32_t>);
        REQUIRE(cortex::AddableWith<float, int_least64_t>);
    }

    SECTION("Double with _")
    {
        // Double with Signed Integers
        REQUIRE(cortex::AddableWith<double, int>);
        REQUIRE(cortex::AddableWith<double, short>);
        REQUIRE(cortex::AddableWith<double, long>);
        REQUIRE(cortex::AddableWith<double, long long>);

        // Double with Unsigned Integers
        REQUIRE(cortex::AddableWith<double, unsigned>);
        REQUIRE(cortex::AddableWith<double, unsigned short>);
        REQUIRE(cortex::AddableWith<double, u_short>);
        REQUIRE(cortex::AddableWith<double, unsigned long>);
        REQUIRE(cortex::AddableWith<double, unsigned long long>);
        
        // Double with Floating Point and Doubles
        REQUIRE(cortex::AddableWith<double, float>);
        REQUIRE(cortex::AddableWith<double, double>);
        REQUIRE(cortex::AddableWith<double, long double>);

        // Double with std::strings and std::string_view
        REQUIRE(!cortex::AddableWith<double, std::string>);
        REQUIRE(!cortex::AddableWith<double, std::string_view>);
        REQUIRE(!cortex::AddableWith<double, std::u8string>);
        REQUIRE(!cortex::AddableWith<double, std::u16string>);
        REQUIRE(!cortex::AddableWith<double, std::u32string>);

        // Double with std::wstrings and std::wstring_view
        REQUIRE(!cortex::AddableWith<double, std::wstring>);
        REQUIRE(!cortex::AddableWith<double, std::wstring_view>);

        // Double with Charaters
        REQUIRE(cortex::AddableWith<double, char>);
        REQUIRE(cortex::AddableWith<double, u_char>);
        REQUIRE(cortex::AddableWith<double, wchar_t>);

        // Double with Bit Specific Characters
        REQUIRE(cortex::AddableWith<double, char8_t>);
        REQUIRE(cortex::AddableWith<double, char16_t>);
        REQUIRE(cortex::AddableWith<double, char32_t>);

        // Double with Bit Specific Short
        REQUIRE(cortex::AddableWith<double, int8_t>);
        REQUIRE(cortex::AddableWith<double, int16_t>);
        REQUIRE(cortex::AddableWith<double, int32_t>);
        REQUIRE(cortex::AddableWith<double, int64_t>);

        // Double with Bit Specific Unsigned Short
        REQUIRE(cortex::AddableWith<double, uint8_t>);
        REQUIRE(cortex::AddableWith<double, uint16_t>);
        REQUIRE(cortex::AddableWith<double, uint32_t>);
        REQUIRE(cortex::AddableWith<double, uint64_t>);

        // Double with Bit Specific Least Integers
        REQUIRE(cortex::AddableWith<double, int_least8_t>);
        REQUIRE(cortex::AddableWith<double, int_least16_t>);
        REQUIRE(cortex::AddableWith<double, int_least32_t>);
        REQUIRE(cortex::AddableWith<double, int_least64_t>);
    }

    SECTION("Long Double with _")
    {
        // Long Double with Signed Integers
        REQUIRE(cortex::AddableWith<long double, int>);
        REQUIRE(cortex::AddableWith<long double, short>);
        REQUIRE(cortex::AddableWith<long double, long>);
        REQUIRE(cortex::AddableWith<long double, long long>);

        // Long Double with Unsigned Integers
        REQUIRE(cortex::AddableWith<long double, unsigned>);
        REQUIRE(cortex::AddableWith<long double, unsigned short>);
        REQUIRE(cortex::AddableWith<long double, u_short>);
        REQUIRE(cortex::AddableWith<long double, unsigned long>);
        REQUIRE(cortex::AddableWith<long double, unsigned long long>);
        
        // Long Double with Floating Point and Doubles
        REQUIRE(cortex::AddableWith<long double, float>);
        REQUIRE(cortex::AddableWith<long double, double>);
        REQUIRE(cortex::AddableWith<long double, long double>);

        // Long Double with std::strings and std::string_view
        REQUIRE(!cortex::AddableWith<long double, std::string>);
        REQUIRE(!cortex::AddableWith<long double, std::string_view>);
        REQUIRE(!cortex::AddableWith<long double, std::u8string>);
        REQUIRE(!cortex::AddableWith<long double, std::u16string>);
        REQUIRE(!cortex::AddableWith<long double, std::u32string>);

        // Long Double with std::wstrings and std::wstring_view
        REQUIRE(!cortex::AddableWith<long double, std::wstring>);
        REQUIRE(!cortex::AddableWith<long double, std::wstring_view>);

        // Long Double with Charaters
        REQUIRE(cortex::AddableWith<long double, char>);
        REQUIRE(cortex::AddableWith<long double, u_char>);
        REQUIRE(cortex::AddableWith<long double, wchar_t>);

        // Long Double with Bit Specific Characters
        REQUIRE(cortex::AddableWith<long double, char8_t>);
        REQUIRE(cortex::AddableWith<long double, char16_t>);
        REQUIRE(cortex::AddableWith<long double, char32_t>);

        // Long Double with Bit Specific Long
        REQUIRE(cortex::AddableWith<long double, int8_t>);
        REQUIRE(cortex::AddableWith<long double, int16_t>);
        REQUIRE(cortex::AddableWith<long double, int32_t>);
        REQUIRE(cortex::AddableWith<long double, int64_t>);

        // Long Double with Bit Specific Unsigned Long
        REQUIRE(cortex::AddableWith<long double, uint8_t>);
        REQUIRE(cortex::AddableWith<long double, uint16_t>);
        REQUIRE(cortex::AddableWith<long double, uint32_t>);
        REQUIRE(cortex::AddableWith<long double, uint64_t>);

        // Long Double with Bit Specific Least Integers
        REQUIRE(cortex::AddableWith<long double, int_least8_t>);
        REQUIRE(cortex::AddableWith<long double, int_least16_t>);
        REQUIRE(cortex::AddableWith<long double, int_least32_t>);
        REQUIRE(cortex::AddableWith<long double, int_least64_t>);
    }

}

TEST_CASE("AddableWith : Strings")
{
    SECTION("std::string with _")
    {
        REQUIRE(cortex::AddableWith<std::string, std::string>);
        REQUIRE(!cortex::AddableWith<std::string, std::string_view>);

        REQUIRE(cortex::AddableWith<std::string, const char*>);
        REQUIRE(cortex::AddableWith<std::string, char*>);

        REQUIRE(!cortex::AddableWith<std::string, std::u8string>);
        REQUIRE(!cortex::AddableWith<std::string, std::u16string>);
        REQUIRE(!cortex::AddableWith<std::string, std::u32string>);

        REQUIRE(!cortex::AddableWith<std::wstring, std::u8string_view>);
        REQUIRE(!cortex::AddableWith<std::wstring, std::u16string_view>);
        REQUIRE(!cortex::AddableWith<std::wstring, std::u32string_view>);

        REQUIRE(!cortex::AddableWith<std::string, std::wstring>);
        REQUIRE(!cortex::AddableWith<std::string, std::wstring_view>);

        REQUIRE(cortex::AddableWith<std::string, char>);
        REQUIRE(!cortex::AddableWith<std::string, u_char>);
        REQUIRE(!cortex::AddableWith<std::string, wchar_t>);

        REQUIRE(!cortex::AddableWith<std::string, char8_t>);
        REQUIRE(!cortex::AddableWith<std::string, char16_t>);
        REQUIRE(!cortex::AddableWith<std::string, char32_t>);
    }

    SECTION("std::wstring with _")
    {
        REQUIRE(!cortex::AddableWith<std::wstring, std::string>);
        REQUIRE(!cortex::AddableWith<std::wstring, std::string_view>);

        REQUIRE(!cortex::AddableWith<std::wstring, const char*>);
        REQUIRE(!cortex::AddableWith<std::wstring, char*>);

        REQUIRE(!cortex::AddableWith<std::wstring, std::u8string>);
        REQUIRE(!cortex::AddableWith<std::wstring, std::u16string>);
        REQUIRE(!cortex::AddableWith<std::wstring, std::u32string>);

        REQUIRE(!cortex::AddableWith<std::wstring, std::u8string_view>);
        REQUIRE(!cortex::AddableWith<std::wstring, std::u16string_view>);
        REQUIRE(!cortex::AddableWith<std::wstring, std::u32string_view>);

        REQUIRE(cortex::AddableWith<std::wstring, std::wstring>);
        REQUIRE(!cortex::AddableWith<std::wstring, std::wstring_view>);

        REQUIRE(!cortex::AddableWith<std::wstring, char>);
        REQUIRE(!cortex::AddableWith<std::wstring, u_char>);
        REQUIRE(cortex::AddableWith<std::wstring, wchar_t>);

        REQUIRE(!cortex::AddableWith<std::wstring, char8_t>);
        REQUIRE(!cortex::AddableWith<std::wstring, char16_t>);
        REQUIRE(!cortex::AddableWith<std::wstring, char32_t>);
    }

    SECTION("std::u8string with _")
    {
        REQUIRE(!cortex::AddableWith<std::u8string, std::string>);
        REQUIRE(!cortex::AddableWith<std::u8string, std::string_view>);

        REQUIRE(!cortex::AddableWith<std::u8string, const char*>);
        REQUIRE(!cortex::AddableWith<std::u8string, char*>);

        REQUIRE(cortex::AddableWith<std::u8string, std::u8string>);
        REQUIRE(!cortex::AddableWith<std::u8string, std::u16string>);
        REQUIRE(!cortex::AddableWith<std::u8string, std::u32string>);

        REQUIRE(!cortex::AddableWith<std::u8string, std::u8string_view>);
        REQUIRE(!cortex::AddableWith<std::u8string, std::u16string_view>);
        REQUIRE(!cortex::AddableWith<std::u8string, std::u32string_view>);

        REQUIRE(!cortex::AddableWith<std::u8string, std::wstring>);
        REQUIRE(!cortex::AddableWith<std::u8string, std::wstring_view>);

        REQUIRE(!cortex::AddableWith<std::u8string, char>);
        REQUIRE(!cortex::AddableWith<std::u8string, u_char>);
        REQUIRE(!cortex::AddableWith<std::u8string, wchar_t>);

        REQUIRE(cortex::AddableWith<std::u8string, char8_t>);
        REQUIRE(!cortex::AddableWith<std::u8string, char16_t>);
        REQUIRE(!cortex::AddableWith<std::u8string, char32_t>);
    }

    SECTION("std::u16string with _")
    {
        REQUIRE(!cortex::AddableWith<std::u16string, std::string>);
        REQUIRE(!cortex::AddableWith<std::u16string, std::string_view>);

        REQUIRE(!cortex::AddableWith<std::u16string, const char*>);
        REQUIRE(!cortex::AddableWith<std::u16string, char*>);

        REQUIRE(!cortex::AddableWith<std::u16string, std::u8string>);
        REQUIRE(cortex::AddableWith<std::u16string, std::u16string>);
        REQUIRE(!cortex::AddableWith<std::u16string, std::u32string>);

        REQUIRE(!cortex::AddableWith<std::u16string, std::u8string_view>);
        REQUIRE(!cortex::AddableWith<std::u16string, std::u16string_view>);
        REQUIRE(!cortex::AddableWith<std::u16string, std::u32string_view>);

        REQUIRE(!cortex::AddableWith<std::u16string, std::wstring>);
        REQUIRE(!cortex::AddableWith<std::u16string, std::wstring_view>);

        REQUIRE(!cortex::AddableWith<std::u16string, char>);
        REQUIRE(!cortex::AddableWith<std::u16string, u_char>);
        REQUIRE(!cortex::AddableWith<std::u16string, wchar_t>);

        REQUIRE(!cortex::AddableWith<std::u16string, char8_t>);
        REQUIRE(cortex::AddableWith<std::u16string, char16_t>);
        REQUIRE(!cortex::AddableWith<std::u16string, char32_t>);
    }

    SECTION("std::u32string with _")
    {
        REQUIRE(!cortex::AddableWith<std::u32string, std::string>);
        REQUIRE(!cortex::AddableWith<std::u32string, std::string_view>);

        REQUIRE(!cortex::AddableWith<std::u32string, const char*>);
        REQUIRE(!cortex::AddableWith<std::u32string, char*>);

        REQUIRE(!cortex::AddableWith<std::u32string, std::u8string>);
        REQUIRE(!cortex::AddableWith<std::u32string, std::u16string>);
        REQUIRE(cortex::AddableWith<std::u32string, std::u32string>);

        REQUIRE(!cortex::AddableWith<std::u32string, std::u8string_view>);
        REQUIRE(!cortex::AddableWith<std::u32string, std::u16string_view>);
        REQUIRE(!cortex::AddableWith<std::u32string, std::u32string_view>);

        REQUIRE(!cortex::AddableWith<std::u32string, std::wstring>);
        REQUIRE(!cortex::AddableWith<std::u32string, std::wstring_view>);

        REQUIRE(!cortex::AddableWith<std::u32string, char>);
        REQUIRE(!cortex::AddableWith<std::u32string, u_char>);
        REQUIRE(!cortex::AddableWith<std::u32string, wchar_t>);

        REQUIRE(!cortex::AddableWith<std::u32string, char8_t>);
        REQUIRE(!cortex::AddableWith<std::u32string, char16_t>);
        REQUIRE(cortex::AddableWith<std::u32string, char32_t>);
    }
}

TEST_CASE("AddableWith :  Pointers") {}

TEST_CASE("Addable With : Bit Specific Signed Integers")
{
    SECTION("int8_t with _")
    {
        // int8_t with Signed Integers
        REQUIRE(cortex::AddableWith<int8_t, int>);
        REQUIRE(cortex::AddableWith<int8_t, short>);
        REQUIRE(cortex::AddableWith<int8_t, long>);
        REQUIRE(cortex::AddableWith<int8_t, long long>);

        // int8_t with Unsigned Integers
        REQUIRE(cortex::AddableWith<int8_t, unsigned>);
        REQUIRE(cortex::AddableWith<int8_t, unsigned short>);
        REQUIRE(cortex::AddableWith<int8_t, u_short>);
        REQUIRE(cortex::AddableWith<int8_t, unsigned long>);
        REQUIRE(cortex::AddableWith<int8_t, unsigned long long>);
        
        // int8_t with Floating Point and Doubles
        REQUIRE(cortex::AddableWith<int8_t, float>);
        REQUIRE(cortex::AddableWith<int8_t, double>);
        REQUIRE(cortex::AddableWith<int8_t, long double>);

        // int8_t with std::strings and std::string_view
        REQUIRE(!cortex::AddableWith<int8_t, std::string>);
        REQUIRE(!cortex::AddableWith<int8_t, std::string_view>);
        REQUIRE(!cortex::AddableWith<int8_t, std::u8string>);
        REQUIRE(!cortex::AddableWith<int8_t, std::u16string>);
        REQUIRE(!cortex::AddableWith<int8_t, std::u32string>);

        // int8_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::AddableWith<long long, std::wstring>);
        REQUIRE(!cortex::AddableWith<long long, std::wstring_view>);

        // int8_t with Charaters
        REQUIRE(cortex::AddableWith<int8_t, char>);
        REQUIRE(cortex::AddableWith<int8_t, u_char>);
        REQUIRE(cortex::AddableWith<int8_t, wchar_t>);

        // int8_t with Bit Specific Characters
        REQUIRE(cortex::AddableWith<int8_t, char8_t>);
        REQUIRE(cortex::AddableWith<int8_t, char16_t>);
        REQUIRE(cortex::AddableWith<int8_t, char32_t>);

        // int8_t with Bit Specific Integers
        REQUIRE(cortex::AddableWith<int8_t, int8_t>);
        REQUIRE(cortex::AddableWith<int8_t, int16_t>);
        REQUIRE(cortex::AddableWith<int8_t, int32_t>);
        REQUIRE(cortex::AddableWith<int8_t, int64_t>);

        // int8_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::AddableWith<int8_t, uint8_t>);
        REQUIRE(cortex::AddableWith<int8_t, uint16_t>);
        REQUIRE(cortex::AddableWith<int8_t, uint32_t>);
        REQUIRE(cortex::AddableWith<int8_t, uint64_t>);

        // int8_t with Bit Specific Least Integers
        REQUIRE(cortex::AddableWith<int8_t, int_least8_t>);
        REQUIRE(cortex::AddableWith<int8_t, int_least16_t>);
        REQUIRE(cortex::AddableWith<int8_t, int_least32_t>);
        REQUIRE(cortex::AddableWith<int8_t, int_least64_t>);
    }

    SECTION("int16_t with _")
    {
        // int16_t with Signed Integers
        REQUIRE(cortex::AddableWith<int16_t, int>);
        REQUIRE(cortex::AddableWith<int16_t, short>);
        REQUIRE(cortex::AddableWith<int16_t, long>);
        REQUIRE(cortex::AddableWith<int16_t, long long>);

        // int16_t with Unsigned Integers
        REQUIRE(cortex::AddableWith<int16_t, unsigned>);
        REQUIRE(cortex::AddableWith<int16_t, unsigned short>);
        REQUIRE(cortex::AddableWith<int16_t, u_short>);
        REQUIRE(cortex::AddableWith<int16_t, unsigned long>);
        REQUIRE(cortex::AddableWith<int16_t, unsigned long long>);
        
        // int16_t with Floating Point and Doubles
        REQUIRE(cortex::AddableWith<int16_t, float>);
        REQUIRE(cortex::AddableWith<int16_t, double>);
        REQUIRE(cortex::AddableWith<int16_t, long double>);

        // int16_t with std::strings and std::string_view
        REQUIRE(!cortex::AddableWith<int16_t, std::string>);
        REQUIRE(!cortex::AddableWith<int16_t, std::string_view>);
        REQUIRE(!cortex::AddableWith<int16_t, std::u8string>);
        REQUIRE(!cortex::AddableWith<int16_t, std::u16string>);
        REQUIRE(!cortex::AddableWith<int16_t, std::u32string>);

        // int16_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::AddableWith<int16_t, std::wstring>);
        REQUIRE(!cortex::AddableWith<int16_t, std::wstring_view>);

        // int16_t with Charaters
        REQUIRE(cortex::AddableWith<int16_t, char>);
        REQUIRE(cortex::AddableWith<int16_t, u_char>);
        REQUIRE(cortex::AddableWith<int16_t, wchar_t>);

        // int16_t with Bit Specific Characters
        REQUIRE(cortex::AddableWith<int16_t, char8_t>);
        REQUIRE(cortex::AddableWith<int16_t, char16_t>);
        REQUIRE(cortex::AddableWith<int16_t, char32_t>);

        // int16_t with Bit Specific Integers
        REQUIRE(cortex::AddableWith<int16_t, int8_t>);
        REQUIRE(cortex::AddableWith<int16_t, int16_t>);
        REQUIRE(cortex::AddableWith<int16_t, int32_t>);
        REQUIRE(cortex::AddableWith<int16_t, int64_t>);

        // int16_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::AddableWith<int16_t, uint8_t>);
        REQUIRE(cortex::AddableWith<int16_t, uint16_t>);
        REQUIRE(cortex::AddableWith<int16_t, uint32_t>);
        REQUIRE(cortex::AddableWith<int16_t, uint64_t>);

        // int16_t with Bit Specific Least Integers
        REQUIRE(cortex::AddableWith<int16_t, int_least8_t>);
        REQUIRE(cortex::AddableWith<int16_t, int_least16_t>);
        REQUIRE(cortex::AddableWith<int16_t, int_least32_t>);
        REQUIRE(cortex::AddableWith<int16_t, int_least64_t>);
    }

    SECTION("int32 with _")
    {
        // int32 with Signed Integers
        REQUIRE(cortex::AddableWith<int32_t, int>);
        REQUIRE(cortex::AddableWith<int32_t, short>);
        REQUIRE(cortex::AddableWith<int32_t, long>);
        REQUIRE(cortex::AddableWith<int32_t, long long>);

        // int32 with Unsigned Integers
        REQUIRE(cortex::AddableWith<int32_t, unsigned>);
        REQUIRE(cortex::AddableWith<int32_t, unsigned short>);
        REQUIRE(cortex::AddableWith<int32_t, u_short>);
        REQUIRE(cortex::AddableWith<int32_t, unsigned long>);
        REQUIRE(cortex::AddableWith<int32_t, unsigned long long>);
        
        // int32 with Floating Point and Doubles
        REQUIRE(cortex::AddableWith<int32_t, float>);
        REQUIRE(cortex::AddableWith<int32_t, double>);
        REQUIRE(cortex::AddableWith<int32_t, long double>);

        // int32 with std::strings and std::string_view
        REQUIRE(!cortex::AddableWith<int32_t, std::string>);
        REQUIRE(!cortex::AddableWith<int32_t, std::string_view>);
        REQUIRE(!cortex::AddableWith<int32_t, std::u8string>);
        REQUIRE(!cortex::AddableWith<int32_t, std::u16string>);
        REQUIRE(!cortex::AddableWith<int32_t, std::u32string>);

        // int32 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::AddableWith<int32_t, std::wstring>);
        REQUIRE(!cortex::AddableWith<int32_t, std::wstring_view>);

        // int32_t with Charaters
        REQUIRE(cortex::AddableWith<int32_t, char>);
        REQUIRE(cortex::AddableWith<int32_t, u_char>);
        REQUIRE(cortex::AddableWith<int32_t, wchar_t>);

        // int32_t with Bit Specific Characters
        REQUIRE(cortex::AddableWith<int32_t, char8_t>);
        REQUIRE(cortex::AddableWith<int32_t, char16_t>);
        REQUIRE(cortex::AddableWith<int32_t, char32_t>);

        // int32_t with Bit Specific Integers
        REQUIRE(cortex::AddableWith<int32_t, int8_t>);
        REQUIRE(cortex::AddableWith<int32_t, int16_t>);
        REQUIRE(cortex::AddableWith<int32_t, int32_t>);
        REQUIRE(cortex::AddableWith<int32_t, int64_t>);

        // int32_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::AddableWith<int32_t, uint8_t>);
        REQUIRE(cortex::AddableWith<int32_t, uint16_t>);
        REQUIRE(cortex::AddableWith<int32_t, uint32_t>);
        REQUIRE(cortex::AddableWith<int32_t, uint64_t>);

        // int32_t with Bit Specific Least Integers
        REQUIRE(cortex::AddableWith<int32_t, int_least8_t>);
        REQUIRE(cortex::AddableWith<int32_t, int_least16_t>);
        REQUIRE(cortex::AddableWith<int32_t, int_least32_t>);
        REQUIRE(cortex::AddableWith<int32_t, int_least64_t>);
    }

    SECTION("int64 with _")
    {
        // int64 with Signed Integers
        REQUIRE(cortex::AddableWith<int64_t, int>);
        REQUIRE(cortex::AddableWith<int64_t, short>);
        REQUIRE(cortex::AddableWith<int64_t, long>);
        REQUIRE(cortex::AddableWith<int64_t, long long>);

        // int64 with Unsigned Integers
        REQUIRE(cortex::AddableWith<int64_t, unsigned>);
        REQUIRE(cortex::AddableWith<int64_t, unsigned short>);
        REQUIRE(cortex::AddableWith<int64_t, u_short>);
        REQUIRE(cortex::AddableWith<int64_t, unsigned long>);
        REQUIRE(cortex::AddableWith<int64_t, unsigned long long>);
        
        // int64 with Floating Point and Doubles
        REQUIRE(cortex::AddableWith<int64_t, float>);
        REQUIRE(cortex::AddableWith<int64_t, double>);
        REQUIRE(cortex::AddableWith<int64_t, long double>);

        // int64 with std::strings and std::string_view
        REQUIRE(!cortex::AddableWith<int64_t, std::string>);
        REQUIRE(!cortex::AddableWith<int64_t, std::string_view>);
        REQUIRE(!cortex::AddableWith<int64_t, std::u8string>);
        REQUIRE(!cortex::AddableWith<int64_t, std::u16string>);
        REQUIRE(!cortex::AddableWith<int64_t, std::u32string>);

        // int64 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::AddableWith<int64_t, std::wstring>);
        REQUIRE(!cortex::AddableWith<int64_t, std::wstring_view>);

        // int64_t with Charaters
        REQUIRE(cortex::AddableWith<int64_t, char>);
        REQUIRE(cortex::AddableWith<int64_t, u_char>);
        REQUIRE(cortex::AddableWith<int64_t, wchar_t>);

        // int64_t with Bit Specific Characters
        REQUIRE(cortex::AddableWith<int64_t, char8_t>);
        REQUIRE(cortex::AddableWith<int64_t, char16_t>);
        REQUIRE(cortex::AddableWith<int64_t, char32_t>);

        // int64_t with Bit Specific Integers
        REQUIRE(cortex::AddableWith<int64_t, int8_t>);
        REQUIRE(cortex::AddableWith<int64_t, int16_t>);
        REQUIRE(cortex::AddableWith<int64_t, int32_t>);
        REQUIRE(cortex::AddableWith<int64_t, int64_t>);

        // int64_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::AddableWith<int64_t, uint8_t>);
        REQUIRE(cortex::AddableWith<int64_t, uint16_t>);
        REQUIRE(cortex::AddableWith<int64_t, uint32_t>);
        REQUIRE(cortex::AddableWith<int64_t, uint64_t>);

        // int64_t with Bit Specific Least Integers
        REQUIRE(cortex::AddableWith<int64_t, int_least8_t>);
        REQUIRE(cortex::AddableWith<int64_t, int_least16_t>);
        REQUIRE(cortex::AddableWith<int64_t, int_least32_t>);
        REQUIRE(cortex::AddableWith<int64_t, int_least64_t>);
}
}

TEST_CASE("Addable With : Bit Specific Unsigned Integers")
{
    SECTION("uint8_t with _")
    {
        // uint8_t with Signed Integers
        REQUIRE(cortex::AddableWith<uint8_t, int>);
        REQUIRE(cortex::AddableWith<uint8_t, short>);
        REQUIRE(cortex::AddableWith<uint8_t, long>);
        REQUIRE(cortex::AddableWith<uint8_t, long long>);

        // uint8_t with Unsigned Integers
        REQUIRE(cortex::AddableWith<uint8_t, unsigned>);
        REQUIRE(cortex::AddableWith<uint8_t, unsigned short>);
        REQUIRE(cortex::AddableWith<uint8_t, u_short>);
        REQUIRE(cortex::AddableWith<uint8_t, unsigned long>);
        REQUIRE(cortex::AddableWith<uint8_t, unsigned long long>);
        
        // uint8_t with Floating Point and Doubles
        REQUIRE(cortex::AddableWith<uint8_t, float>);
        REQUIRE(cortex::AddableWith<uint8_t, double>);
        REQUIRE(cortex::AddableWith<uint8_t, long double>);

        // uint8_t with std::strings and std::string_view
        REQUIRE(!cortex::AddableWith<uint8_t, std::string>);
        REQUIRE(!cortex::AddableWith<uint8_t, std::string_view>);
        REQUIRE(!cortex::AddableWith<uint8_t, std::u8string>);
        REQUIRE(!cortex::AddableWith<uint8_t, std::u16string>);
        REQUIRE(!cortex::AddableWith<uint8_t, std::u32string>);

        // uint8_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::AddableWith<long long, std::wstring>);
        REQUIRE(!cortex::AddableWith<long long, std::wstring_view>);

        // uint8_t with Charaters
        REQUIRE(cortex::AddableWith<uint8_t, char>);
        REQUIRE(cortex::AddableWith<uint8_t, u_char>);
        REQUIRE(cortex::AddableWith<uint8_t, wchar_t>);

        // uint8_t with Bit Specific Characters
        REQUIRE(cortex::AddableWith<uint8_t, char8_t>);
        REQUIRE(cortex::AddableWith<uint8_t, char16_t>);
        REQUIRE(cortex::AddableWith<uint8_t, char32_t>);

        // uint8_t with Bit Specific Integers
        REQUIRE(cortex::AddableWith<uint8_t, int8_t>);
        REQUIRE(cortex::AddableWith<uint8_t, int16_t>);
        REQUIRE(cortex::AddableWith<uint8_t, int32_t>);
        REQUIRE(cortex::AddableWith<uint8_t, int64_t>);

        // uint8_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::AddableWith<uint8_t, uint8_t>);
        REQUIRE(cortex::AddableWith<uint8_t, uint16_t>);
        REQUIRE(cortex::AddableWith<uint8_t, uint32_t>);
        REQUIRE(cortex::AddableWith<uint8_t, uint64_t>);

        // uint8_t with Bit Specific Least Integers
        REQUIRE(cortex::AddableWith<uint8_t, int_least8_t>);
        REQUIRE(cortex::AddableWith<uint8_t, int_least16_t>);
        REQUIRE(cortex::AddableWith<uint8_t, int_least32_t>);
        REQUIRE(cortex::AddableWith<uint8_t, int_least64_t>);
    }

    SECTION("uint16_t with _")
    {
        // uint16_t with Signed Integers
        REQUIRE(cortex::AddableWith<uint16_t, int>);
        REQUIRE(cortex::AddableWith<uint16_t, short>);
        REQUIRE(cortex::AddableWith<uint16_t, long>);
        REQUIRE(cortex::AddableWith<uint16_t, long long>);

        // uint16_t with Unsigned Integers
        REQUIRE(cortex::AddableWith<uint16_t, unsigned>);
        REQUIRE(cortex::AddableWith<uint16_t, unsigned short>);
        REQUIRE(cortex::AddableWith<uint16_t, u_short>);
        REQUIRE(cortex::AddableWith<uint16_t, unsigned long>);
        REQUIRE(cortex::AddableWith<uint16_t, unsigned long long>);
        
        // uint16_t with Floating Point and Doubles
        REQUIRE(cortex::AddableWith<uint16_t, float>);
        REQUIRE(cortex::AddableWith<uint16_t, double>);
        REQUIRE(cortex::AddableWith<uint16_t, long double>);

        // uint16_t with std::strings and std::string_view
        REQUIRE(!cortex::AddableWith<uint16_t, std::string>);
        REQUIRE(!cortex::AddableWith<uint16_t, std::string_view>);
        REQUIRE(!cortex::AddableWith<uint16_t, std::u8string>);
        REQUIRE(!cortex::AddableWith<uint16_t, std::u16string>);
        REQUIRE(!cortex::AddableWith<uint16_t, std::u32string>);

        // uint16_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::AddableWith<uint16_t, std::wstring>);
        REQUIRE(!cortex::AddableWith<uint16_t, std::wstring_view>);

        // uint16_t with Charaters
        REQUIRE(cortex::AddableWith<uint16_t, char>);
        REQUIRE(cortex::AddableWith<uint16_t, u_char>);
        REQUIRE(cortex::AddableWith<uint16_t, wchar_t>);

        // uint16_t with Bit Specific Characters
        REQUIRE(cortex::AddableWith<uint16_t, char8_t>);
        REQUIRE(cortex::AddableWith<uint16_t, char16_t>);
        REQUIRE(cortex::AddableWith<uint16_t, char32_t>);

        // uint16_t with Bit Specific Integers
        REQUIRE(cortex::AddableWith<uint16_t, int8_t>);
        REQUIRE(cortex::AddableWith<uint16_t, int16_t>);
        REQUIRE(cortex::AddableWith<uint16_t, int32_t>);
        REQUIRE(cortex::AddableWith<uint16_t, int64_t>);

        // uint16_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::AddableWith<uint16_t, uint8_t>);
        REQUIRE(cortex::AddableWith<uint16_t, uint16_t>);
        REQUIRE(cortex::AddableWith<uint16_t, uint32_t>);
        REQUIRE(cortex::AddableWith<uint16_t, uint64_t>);

        // uint16_t with Bit Specific Least Integers
        REQUIRE(cortex::AddableWith<uint16_t, int_least8_t>);
        REQUIRE(cortex::AddableWith<uint16_t, int_least16_t>);
        REQUIRE(cortex::AddableWith<uint16_t, int_least32_t>);
        REQUIRE(cortex::AddableWith<uint16_t, int_least64_t>);
    }

    SECTION("uint32_t with _")
    {
        // int32 with Signed Integers
        REQUIRE(cortex::AddableWith<uint32_t, int>);
        REQUIRE(cortex::AddableWith<uint32_t, short>);
        REQUIRE(cortex::AddableWith<uint32_t, long>);
        REQUIRE(cortex::AddableWith<uint32_t, long long>);

        // int32 with Unsigned Integers
        REQUIRE(cortex::AddableWith<uint32_t, unsigned>);
        REQUIRE(cortex::AddableWith<uint32_t, unsigned short>);
        REQUIRE(cortex::AddableWith<uint32_t, u_short>);
        REQUIRE(cortex::AddableWith<uint32_t, unsigned long>);
        REQUIRE(cortex::AddableWith<uint32_t, unsigned long long>);
        
        // int32 with Floating Point and Doubles
        REQUIRE(cortex::AddableWith<uint32_t, float>);
        REQUIRE(cortex::AddableWith<uint32_t, double>);
        REQUIRE(cortex::AddableWith<uint32_t, long double>);

        // int32 with std::strings and std::string_view
        REQUIRE(!cortex::AddableWith<uint32_t, std::string>);
        REQUIRE(!cortex::AddableWith<uint32_t, std::string_view>);
        REQUIRE(!cortex::AddableWith<uint32_t, std::u8string>);
        REQUIRE(!cortex::AddableWith<uint32_t, std::u16string>);
        REQUIRE(!cortex::AddableWith<uint32_t, std::u32string>);

        // int32 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::AddableWith<uint32_t, std::wstring>);
        REQUIRE(!cortex::AddableWith<uint32_t, std::wstring_view>);

        // uint32_t with Charaters
        REQUIRE(cortex::AddableWith<uint32_t, char>);
        REQUIRE(cortex::AddableWith<uint32_t, u_char>);
        REQUIRE(cortex::AddableWith<uint32_t, wchar_t>);

        // uint32_t with Bit Specific Characters
        REQUIRE(cortex::AddableWith<uint32_t, char8_t>);
        REQUIRE(cortex::AddableWith<uint32_t, char16_t>);
        REQUIRE(cortex::AddableWith<uint32_t, char32_t>);

        // uint32_t with Bit Specific Integers
        REQUIRE(cortex::AddableWith<uint32_t, int8_t>);
        REQUIRE(cortex::AddableWith<uint32_t, int16_t>);
        REQUIRE(cortex::AddableWith<uint32_t, int32_t>);
        REQUIRE(cortex::AddableWith<uint32_t, int64_t>);

        // uint32_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::AddableWith<uint32_t, uint8_t>);
        REQUIRE(cortex::AddableWith<uint32_t, uint16_t>);
        REQUIRE(cortex::AddableWith<uint32_t, uint32_t>);
        REQUIRE(cortex::AddableWith<uint32_t, uint64_t>);

        // uint32_t with Bit Specific Least Integers
        REQUIRE(cortex::AddableWith<uint32_t, int_least8_t>);
        REQUIRE(cortex::AddableWith<uint32_t, int_least16_t>);
        REQUIRE(cortex::AddableWith<uint32_t, int_least32_t>);
        REQUIRE(cortex::AddableWith<uint32_t, int_least64_t>);
    }

    SECTION("uint64_t with _")
    {
        // int64 with Signed Integers
        REQUIRE(cortex::AddableWith<uint64_t, int>);
        REQUIRE(cortex::AddableWith<uint64_t, short>);
        REQUIRE(cortex::AddableWith<uint64_t, long>);
        REQUIRE(cortex::AddableWith<uint64_t, long long>);

        // int64 with Unsigned Integers
        REQUIRE(cortex::AddableWith<uint64_t, unsigned>);
        REQUIRE(cortex::AddableWith<uint64_t, unsigned short>);
        REQUIRE(cortex::AddableWith<uint64_t, u_short>);
        REQUIRE(cortex::AddableWith<uint64_t, unsigned long>);
        REQUIRE(cortex::AddableWith<uint64_t, unsigned long long>);
        
        // int64 with Floating Point and Doubles
        REQUIRE(cortex::AddableWith<uint64_t, float>);
        REQUIRE(cortex::AddableWith<uint64_t, double>);
        REQUIRE(cortex::AddableWith<uint64_t, long double>);

        // int64 with std::strings and std::string_view
        REQUIRE(!cortex::AddableWith<uint64_t, std::string>);
        REQUIRE(!cortex::AddableWith<uint64_t, std::string_view>);
        REQUIRE(!cortex::AddableWith<uint64_t, std::u8string>);
        REQUIRE(!cortex::AddableWith<uint64_t, std::u16string>);
        REQUIRE(!cortex::AddableWith<uint64_t, std::u32string>);

        // int64 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::AddableWith<uint64_t, std::wstring>);
        REQUIRE(!cortex::AddableWith<uint64_t, std::wstring_view>);

        // uint64_t with Charaters
        REQUIRE(cortex::AddableWith<uint64_t, char>);
        REQUIRE(cortex::AddableWith<uint64_t, u_char>);
        REQUIRE(cortex::AddableWith<uint64_t, wchar_t>);

        // uint64_t with Bit Specific Characters
        REQUIRE(cortex::AddableWith<uint64_t, char8_t>);
        REQUIRE(cortex::AddableWith<uint64_t, char16_t>);
        REQUIRE(cortex::AddableWith<uint64_t, char32_t>);

        // uint64_t with Bit Specific Integers
        REQUIRE(cortex::AddableWith<uint64_t, int8_t>);
        REQUIRE(cortex::AddableWith<uint64_t, int16_t>);
        REQUIRE(cortex::AddableWith<uint64_t, int32_t>);
        REQUIRE(cortex::AddableWith<uint64_t, int64_t>);

        // uint64_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::AddableWith<uint64_t, uint8_t>);
        REQUIRE(cortex::AddableWith<uint64_t, uint16_t>);
        REQUIRE(cortex::AddableWith<uint64_t, uint32_t>);
        REQUIRE(cortex::AddableWith<uint64_t, uint64_t>);

        // uint64_t with Bit Specific Least Integers
        REQUIRE(cortex::AddableWith<uint64_t, int_least8_t>);
        REQUIRE(cortex::AddableWith<uint64_t, int_least16_t>);
        REQUIRE(cortex::AddableWith<uint64_t, int_least32_t>);
        REQUIRE(cortex::AddableWith<uint64_t, int_least64_t>);
    }
}

TEST_CASE("Addable With : std::size_t")
{
    SECTION("std::size_t with _")
    {
        // std::size_t with Signed Integers
        REQUIRE(cortex::AddableWith<std::size_t, int>);
        REQUIRE(cortex::AddableWith<std::size_t, short>);
        REQUIRE(cortex::AddableWith<std::size_t, long>);
        REQUIRE(cortex::AddableWith<std::size_t, long long>);

        // std::size_t with Unsigned Integers
        REQUIRE(cortex::AddableWith<std::size_t, unsigned>);
        REQUIRE(cortex::AddableWith<std::size_t, unsigned short>);
        REQUIRE(cortex::AddableWith<std::size_t, u_short>);
        REQUIRE(cortex::AddableWith<std::size_t, unsigned long>);
        REQUIRE(cortex::AddableWith<std::size_t, unsigned long long>);
        
        // std::size_t with Floating Point and Doubles
        REQUIRE(cortex::AddableWith<std::size_t, float>);
        REQUIRE(cortex::AddableWith<std::size_t, double>);
        REQUIRE(cortex::AddableWith<std::size_t, long double>);

        // std::size_t with std::strings and std::string_view
        REQUIRE(!cortex::AddableWith<std::size_t, std::string>);
        REQUIRE(!cortex::AddableWith<std::size_t, std::string_view>);
        REQUIRE(!cortex::AddableWith<std::size_t, std::u8string>);
        REQUIRE(!cortex::AddableWith<std::size_t, std::u16string>);
        REQUIRE(!cortex::AddableWith<std::size_t, std::u32string>);

        // std::size_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::AddableWith<long long, std::wstring>);
        REQUIRE(!cortex::AddableWith<long long, std::wstring_view>);

        // std::size_t with Charaters
        REQUIRE(cortex::AddableWith<std::size_t, char>);
        REQUIRE(cortex::AddableWith<std::size_t, u_char>);
        REQUIRE(cortex::AddableWith<std::size_t, wchar_t>);

        // std::size_t with Bit Specific Characters
        REQUIRE(cortex::AddableWith<std::size_t, char8_t>);
        REQUIRE(cortex::AddableWith<std::size_t, char16_t>);
        REQUIRE(cortex::AddableWith<std::size_t, char32_t>);

        // std::size_t with Bit Specific Integers
        REQUIRE(cortex::AddableWith<std::size_t, int8_t>);
        REQUIRE(cortex::AddableWith<std::size_t, int16_t>);
        REQUIRE(cortex::AddableWith<std::size_t, int32_t>);
        REQUIRE(cortex::AddableWith<std::size_t, int64_t>);

        // std::size_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::AddableWith<std::size_t, uint8_t>);
        REQUIRE(cortex::AddableWith<std::size_t, uint16_t>);
        REQUIRE(cortex::AddableWith<std::size_t, uint32_t>);
        REQUIRE(cortex::AddableWith<std::size_t, uint64_t>);

        // std::size_t with Bit Specific Least Integers
        REQUIRE(cortex::AddableWith<std::size_t, int_least8_t>);
        REQUIRE(cortex::AddableWith<std::size_t, int_least16_t>);
        REQUIRE(cortex::AddableWith<std::size_t, int_least32_t>);
        REQUIRE(cortex::AddableWith<std::size_t, int_least64_t>);
    }
}

TEST_CASE("AddableWith : Fast Integers")
{
    SECTION("int_fast8_t with _")
    {
        // int_fast8_t with Signed Integers
        REQUIRE(cortex::AddableWith<int_fast8_t, int>);
        REQUIRE(cortex::AddableWith<int_fast8_t, short>);
        REQUIRE(cortex::AddableWith<int_fast8_t, long>);
        REQUIRE(cortex::AddableWith<int_fast8_t, long long>);

        // int_fast8_t with Unsigned Integers
        REQUIRE(cortex::AddableWith<int_fast8_t, unsigned>);
        REQUIRE(cortex::AddableWith<int_fast8_t, unsigned short>);
        REQUIRE(cortex::AddableWith<int_fast8_t, u_short>);
        REQUIRE(cortex::AddableWith<int_fast8_t, unsigned long>);
        REQUIRE(cortex::AddableWith<int_fast8_t, unsigned long long>);
        
        // int_fast8_t with Floating Point and Doubles
        REQUIRE(cortex::AddableWith<int_fast8_t, float>);
        REQUIRE(cortex::AddableWith<int_fast8_t, double>);
        REQUIRE(cortex::AddableWith<int_fast8_t, long double>);

        // int_fast8_t with std::strings and std::string_view
        REQUIRE(!cortex::AddableWith<int_fast8_t, std::string>);
        REQUIRE(!cortex::AddableWith<int_fast8_t, std::string_view>);
        REQUIRE(!cortex::AddableWith<int_fast8_t, std::u8string>);
        REQUIRE(!cortex::AddableWith<int_fast8_t, std::u16string>);
        REQUIRE(!cortex::AddableWith<int_fast8_t, std::u32string>);

        // int_fast8_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::AddableWith<long long, std::wstring>);
        REQUIRE(!cortex::AddableWith<long long, std::wstring_view>);

        // int_fast8_t with Charaters
        REQUIRE(cortex::AddableWith<int_fast8_t, char>);
        REQUIRE(cortex::AddableWith<int_fast8_t, u_char>);
        REQUIRE(cortex::AddableWith<int_fast8_t, wchar_t>);

        // int_fast8_t with Bit Specific Characters
        REQUIRE(cortex::AddableWith<int_fast8_t, char8_t>);
        REQUIRE(cortex::AddableWith<int_fast8_t, char16_t>);
        REQUIRE(cortex::AddableWith<int_fast8_t, char32_t>);

        // int_fast8_t with Bit Specific Integers
        REQUIRE(cortex::AddableWith<int_fast8_t, int8_t>);
        REQUIRE(cortex::AddableWith<int_fast8_t, int16_t>);
        REQUIRE(cortex::AddableWith<int_fast8_t, int32_t>);
        REQUIRE(cortex::AddableWith<int_fast8_t, int64_t>);

        // int_fast8_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::AddableWith<int_fast8_t, uint8_t>);
        REQUIRE(cortex::AddableWith<int_fast8_t, uint16_t>);
        REQUIRE(cortex::AddableWith<int_fast8_t, uint32_t>);
        REQUIRE(cortex::AddableWith<int_fast8_t, uint64_t>);

        // int_fast8_t with Bit Specific Least Integers
        REQUIRE(cortex::AddableWith<int_fast8_t, int_least8_t>);
        REQUIRE(cortex::AddableWith<int_fast8_t, int_least16_t>);
        REQUIRE(cortex::AddableWith<int_fast8_t, int_least32_t>);
        REQUIRE(cortex::AddableWith<int_fast8_t, int_least64_t>);
    }

    SECTION("int_fast16_t with _")
    {
        // int_fast16_t with Signed Integers
        REQUIRE(cortex::AddableWith<int_fast16_t, int>);
        REQUIRE(cortex::AddableWith<int_fast16_t, short>);
        REQUIRE(cortex::AddableWith<int_fast16_t, long>);
        REQUIRE(cortex::AddableWith<int_fast16_t, long long>);

        // int_fast16_t with Unsigned Integers
        REQUIRE(cortex::AddableWith<int_fast16_t, unsigned>);
        REQUIRE(cortex::AddableWith<int_fast16_t, unsigned short>);
        REQUIRE(cortex::AddableWith<int_fast16_t, u_short>);
        REQUIRE(cortex::AddableWith<int_fast16_t, unsigned long>);
        REQUIRE(cortex::AddableWith<int_fast16_t, unsigned long long>);
        
        // int_fast16_t with Floating Point and Doubles
        REQUIRE(cortex::AddableWith<int_fast16_t, float>);
        REQUIRE(cortex::AddableWith<int_fast16_t, double>);
        REQUIRE(cortex::AddableWith<int_fast16_t, long double>);

        // int_fast16_t with std::strings and std::string_view
        REQUIRE(!cortex::AddableWith<int_fast16_t, std::string>);
        REQUIRE(!cortex::AddableWith<int_fast16_t, std::string_view>);
        REQUIRE(!cortex::AddableWith<int_fast16_t, std::u8string>);
        REQUIRE(!cortex::AddableWith<int_fast16_t, std::u16string>);
        REQUIRE(!cortex::AddableWith<int_fast16_t, std::u32string>);

        // int_fast16_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::AddableWith<int_fast16_t, std::wstring>);
        REQUIRE(!cortex::AddableWith<int_fast16_t, std::wstring_view>);

        // int_fast16_t with Charaters
        REQUIRE(cortex::AddableWith<int_fast16_t, char>);
        REQUIRE(cortex::AddableWith<int_fast16_t, u_char>);
        REQUIRE(cortex::AddableWith<int_fast16_t, wchar_t>);

        // int_fast16_t with Bit Specific Characters
        REQUIRE(cortex::AddableWith<int_fast16_t, char8_t>);
        REQUIRE(cortex::AddableWith<int_fast16_t, char16_t>);
        REQUIRE(cortex::AddableWith<int_fast16_t, char32_t>);

        // int_fast16_t with Bit Specific Integers
        REQUIRE(cortex::AddableWith<int_fast16_t, int8_t>);
        REQUIRE(cortex::AddableWith<int_fast16_t, int16_t>);
        REQUIRE(cortex::AddableWith<int_fast16_t, int32_t>);
        REQUIRE(cortex::AddableWith<int_fast16_t, int64_t>);

        // int_fast16_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::AddableWith<int_fast16_t, uint8_t>);
        REQUIRE(cortex::AddableWith<int_fast16_t, uint16_t>);
        REQUIRE(cortex::AddableWith<int_fast16_t, uint32_t>);
        REQUIRE(cortex::AddableWith<int_fast16_t, uint64_t>);

        // int_fast16_t with Bit Specific Least Integers
        REQUIRE(cortex::AddableWith<int_fast16_t, int_least8_t>);
        REQUIRE(cortex::AddableWith<int_fast16_t, int_least16_t>);
        REQUIRE(cortex::AddableWith<int_fast16_t, int_least32_t>);
        REQUIRE(cortex::AddableWith<int_fast16_t, int_least64_t>);
    }

    SECTION("int_fast32_t with _")
    {
        // int32 with Signed Integers
        REQUIRE(cortex::AddableWith<int_fast32_t, int>);
        REQUIRE(cortex::AddableWith<int_fast32_t, short>);
        REQUIRE(cortex::AddableWith<int_fast32_t, long>);
        REQUIRE(cortex::AddableWith<int_fast32_t, long long>);

        // int32 with Unsigned Integers
        REQUIRE(cortex::AddableWith<int_fast32_t, unsigned>);
        REQUIRE(cortex::AddableWith<int_fast32_t, unsigned short>);
        REQUIRE(cortex::AddableWith<int_fast32_t, u_short>);
        REQUIRE(cortex::AddableWith<int_fast32_t, unsigned long>);
        REQUIRE(cortex::AddableWith<int_fast32_t, unsigned long long>);
        
        // int32 with Floating Point and Doubles
        REQUIRE(cortex::AddableWith<int_fast32_t, float>);
        REQUIRE(cortex::AddableWith<int_fast32_t, double>);
        REQUIRE(cortex::AddableWith<int_fast32_t, long double>);

        // int32 with std::strings and std::string_view
        REQUIRE(!cortex::AddableWith<int_fast32_t, std::string>);
        REQUIRE(!cortex::AddableWith<int_fast32_t, std::string_view>);
        REQUIRE(!cortex::AddableWith<int_fast32_t, std::u8string>);
        REQUIRE(!cortex::AddableWith<int_fast32_t, std::u16string>);
        REQUIRE(!cortex::AddableWith<int_fast32_t, std::u32string>);

        // int32 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::AddableWith<int_fast32_t, std::wstring>);
        REQUIRE(!cortex::AddableWith<int_fast32_t, std::wstring_view>);

        // int_fast32_t with Charaters
        REQUIRE(cortex::AddableWith<int_fast32_t, char>);
        REQUIRE(cortex::AddableWith<int_fast32_t, u_char>);
        REQUIRE(cortex::AddableWith<int_fast32_t, wchar_t>);

        // int_fast32_t with Bit Specific Characters
        REQUIRE(cortex::AddableWith<int_fast32_t, char8_t>);
        REQUIRE(cortex::AddableWith<int_fast32_t, char16_t>);
        REQUIRE(cortex::AddableWith<int_fast32_t, char32_t>);

        // int_fast32_t with Bit Specific Integers
        REQUIRE(cortex::AddableWith<int_fast32_t, int8_t>);
        REQUIRE(cortex::AddableWith<int_fast32_t, int16_t>);
        REQUIRE(cortex::AddableWith<int_fast32_t, int32_t>);
        REQUIRE(cortex::AddableWith<int_fast32_t, int64_t>);

        // int_fast32_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::AddableWith<int_fast32_t, uint8_t>);
        REQUIRE(cortex::AddableWith<int_fast32_t, uint16_t>);
        REQUIRE(cortex::AddableWith<int_fast32_t, uint32_t>);
        REQUIRE(cortex::AddableWith<int_fast32_t, uint64_t>);

        // int_fast32_t with Bit Specific Least Integers
        REQUIRE(cortex::AddableWith<int_fast32_t, int_least8_t>);
        REQUIRE(cortex::AddableWith<int_fast32_t, int_least16_t>);
        REQUIRE(cortex::AddableWith<int_fast32_t, int_least32_t>);
        REQUIRE(cortex::AddableWith<int_fast32_t, int_least64_t>);
    }

    SECTION("int_fast64_t with _")
    {
        // int64 with Signed Integers
        REQUIRE(cortex::AddableWith<int_fast64_t, int>);
        REQUIRE(cortex::AddableWith<int_fast64_t, short>);
        REQUIRE(cortex::AddableWith<int_fast64_t, long>);
        REQUIRE(cortex::AddableWith<int_fast64_t, long long>);

        // int64 with Unsigned Integers
        REQUIRE(cortex::AddableWith<int_fast64_t, unsigned>);
        REQUIRE(cortex::AddableWith<int_fast64_t, unsigned short>);
        REQUIRE(cortex::AddableWith<int_fast64_t, u_short>);
        REQUIRE(cortex::AddableWith<int_fast64_t, unsigned long>);
        REQUIRE(cortex::AddableWith<int_fast64_t, unsigned long long>);
        
        // int64 with Floating Point and Doubles
        REQUIRE(cortex::AddableWith<int_fast64_t, float>);
        REQUIRE(cortex::AddableWith<int_fast64_t, double>);
        REQUIRE(cortex::AddableWith<int_fast64_t, long double>);

        // int64 with std::strings and std::string_view
        REQUIRE(!cortex::AddableWith<int_fast64_t, std::string>);
        REQUIRE(!cortex::AddableWith<int_fast64_t, std::string_view>);
        REQUIRE(!cortex::AddableWith<int_fast64_t, std::u8string>);
        REQUIRE(!cortex::AddableWith<int_fast64_t, std::u16string>);
        REQUIRE(!cortex::AddableWith<int_fast64_t, std::u32string>);

        // int64 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::AddableWith<int_fast64_t, std::wstring>);
        REQUIRE(!cortex::AddableWith<int_fast64_t, std::wstring_view>);

        // int_fast64_t with Charaters
        REQUIRE(cortex::AddableWith<int_fast64_t, char>);
        REQUIRE(cortex::AddableWith<int_fast64_t, u_char>);
        REQUIRE(cortex::AddableWith<int_fast64_t, wchar_t>);

        // int_fast64_t with Bit Specific Characters
        REQUIRE(cortex::AddableWith<int_fast64_t, char8_t>);
        REQUIRE(cortex::AddableWith<int_fast64_t, char16_t>);
        REQUIRE(cortex::AddableWith<int_fast64_t, char32_t>);

        // int_fast64_t with Bit Specific Integers
        REQUIRE(cortex::AddableWith<int_fast64_t, int8_t>);
        REQUIRE(cortex::AddableWith<int_fast64_t, int16_t>);
        REQUIRE(cortex::AddableWith<int_fast64_t, int32_t>);
        REQUIRE(cortex::AddableWith<int_fast64_t, int64_t>);

        // int_fast64_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::AddableWith<int_fast64_t, uint8_t>);
        REQUIRE(cortex::AddableWith<int_fast64_t, uint16_t>);
        REQUIRE(cortex::AddableWith<int_fast64_t, uint32_t>);
        REQUIRE(cortex::AddableWith<int_fast64_t, uint64_t>);

        // int_fast64_t with Bit Specific Least Integers
        REQUIRE(cortex::AddableWith<int_fast64_t, int_least8_t>);
        REQUIRE(cortex::AddableWith<int_fast64_t, int_least16_t>);
        REQUIRE(cortex::AddableWith<int_fast64_t, int_least32_t>);
        REQUIRE(cortex::AddableWith<int_fast64_t, int_least64_t>);
    }
}

TEST_CASE("AddableWith : Least Integers")
{
    SECTION("int_least8_t with _")
    {
        // int_fast8_t with Signed Integers
        REQUIRE(cortex::AddableWith<int_least8_t, int>);
        REQUIRE(cortex::AddableWith<int_least8_t, short>);
        REQUIRE(cortex::AddableWith<int_least8_t, long>);
        REQUIRE(cortex::AddableWith<int_least8_t, long long>);

        // int_fast8_t with Unsigned Integers
        REQUIRE(cortex::AddableWith<int_least8_t, unsigned>);
        REQUIRE(cortex::AddableWith<int_least8_t, unsigned short>);
        REQUIRE(cortex::AddableWith<int_least8_t, u_short>);
        REQUIRE(cortex::AddableWith<int_least8_t, unsigned long>);
        REQUIRE(cortex::AddableWith<int_least8_t, unsigned long long>);
        
        // int_fast8_t with Floating Point and Doubles
        REQUIRE(cortex::AddableWith<int_least8_t, float>);
        REQUIRE(cortex::AddableWith<int_least8_t, double>);
        REQUIRE(cortex::AddableWith<int_least8_t, long double>);

        // int_fast8_t with std::strings and std::string_view
        REQUIRE(!cortex::AddableWith<int_least8_t, std::string>);
        REQUIRE(!cortex::AddableWith<int_least8_t, std::string_view>);
        REQUIRE(!cortex::AddableWith<int_least8_t, std::u8string>);
        REQUIRE(!cortex::AddableWith<int_least8_t, std::u16string>);
        REQUIRE(!cortex::AddableWith<int_least8_t, std::u32string>);

        // int_fast8_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::AddableWith<long long, std::wstring>);
        REQUIRE(!cortex::AddableWith<long long, std::wstring_view>);

        // int_fast8_t with Charaters
        REQUIRE(cortex::AddableWith<int_least8_t, char>);
        REQUIRE(cortex::AddableWith<int_least8_t, u_char>);
        REQUIRE(cortex::AddableWith<int_least8_t, wchar_t>);

        // int_fast8_t with Bit Specific Characters
        REQUIRE(cortex::AddableWith<int_least8_t, char8_t>);
        REQUIRE(cortex::AddableWith<int_least8_t, char16_t>);
        REQUIRE(cortex::AddableWith<int_least8_t, char32_t>);

        // int_fast8_t with Bit Specific Integers
        REQUIRE(cortex::AddableWith<int_least8_t, int8_t>);
        REQUIRE(cortex::AddableWith<int_least8_t, int16_t>);
        REQUIRE(cortex::AddableWith<int_least8_t, int32_t>);
        REQUIRE(cortex::AddableWith<int_least8_t, int64_t>);

        // int_fast8_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::AddableWith<int_least8_t, uint8_t>);
        REQUIRE(cortex::AddableWith<int_least8_t, uint16_t>);
        REQUIRE(cortex::AddableWith<int_least8_t, uint32_t>);
        REQUIRE(cortex::AddableWith<int_least8_t, uint64_t>);

        // int_fast8_t with Bit Specific Least Integers
        REQUIRE(cortex::AddableWith<int_least8_t, int_least8_t>);
        REQUIRE(cortex::AddableWith<int_least8_t, int_least16_t>);
        REQUIRE(cortex::AddableWith<int_least8_t, int_least32_t>);
        REQUIRE(cortex::AddableWith<int_least8_t, int_least64_t>);
    }

    SECTION("int_least16_t with _")
    {
        // int_fast16_t with Signed Integers
        REQUIRE(cortex::AddableWith<int_least16_t, int>);
        REQUIRE(cortex::AddableWith<int_least16_t, short>);
        REQUIRE(cortex::AddableWith<int_least16_t, long>);
        REQUIRE(cortex::AddableWith<int_least16_t, long long>);

        // int_fast16_t with Unsigned Integers
        REQUIRE(cortex::AddableWith<int_least16_t, unsigned>);
        REQUIRE(cortex::AddableWith<int_least16_t, unsigned short>);
        REQUIRE(cortex::AddableWith<int_least16_t, u_short>);
        REQUIRE(cortex::AddableWith<int_least16_t, unsigned long>);
        REQUIRE(cortex::AddableWith<int_least16_t, unsigned long long>);
        
        // int_fast16_t with Floating Point and Doubles
        REQUIRE(cortex::AddableWith<int_least16_t, float>);
        REQUIRE(cortex::AddableWith<int_least16_t, double>);
        REQUIRE(cortex::AddableWith<int_least16_t, long double>);

        // int_fast16_t with std::strings and std::string_view
        REQUIRE(!cortex::AddableWith<int_least16_t, std::string>);
        REQUIRE(!cortex::AddableWith<int_least16_t, std::string_view>);
        REQUIRE(!cortex::AddableWith<int_least16_t, std::u8string>);
        REQUIRE(!cortex::AddableWith<int_least16_t, std::u16string>);
        REQUIRE(!cortex::AddableWith<int_least16_t, std::u32string>);

        // int_fast16_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::AddableWith<int_least16_t, std::wstring>);
        REQUIRE(!cortex::AddableWith<int_least16_t, std::wstring_view>);

        // int_fast16_t with Charaters
        REQUIRE(cortex::AddableWith<int_least16_t, char>);
        REQUIRE(cortex::AddableWith<int_least16_t, u_char>);
        REQUIRE(cortex::AddableWith<int_least16_t, wchar_t>);

        // int_fast16_t with Bit Specific Characters
        REQUIRE(cortex::AddableWith<int_least16_t, char8_t>);
        REQUIRE(cortex::AddableWith<int_least16_t, char16_t>);
        REQUIRE(cortex::AddableWith<int_least16_t, char32_t>);

        // int_fast16_t with Bit Specific Integers
        REQUIRE(cortex::AddableWith<int_least16_t, int8_t>);
        REQUIRE(cortex::AddableWith<int_least16_t, int16_t>);
        REQUIRE(cortex::AddableWith<int_least16_t, int32_t>);
        REQUIRE(cortex::AddableWith<int_least16_t, int64_t>);

        // int_fast16_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::AddableWith<int_least16_t, uint8_t>);
        REQUIRE(cortex::AddableWith<int_least16_t, uint16_t>);
        REQUIRE(cortex::AddableWith<int_least16_t, uint32_t>);
        REQUIRE(cortex::AddableWith<int_least16_t, uint64_t>);

        // int_fast16_t with Bit Specific Least Integers
        REQUIRE(cortex::AddableWith<int_least16_t, int_least8_t>);
        REQUIRE(cortex::AddableWith<int_least16_t, int_least16_t>);
        REQUIRE(cortex::AddableWith<int_least16_t, int_least32_t>);
        REQUIRE(cortex::AddableWith<int_least16_t, int_least64_t>);
    }

    SECTION("int_least32_t with _")
    {
        // int32 with Signed Integers
        REQUIRE(cortex::AddableWith<int_least32_t, int>);
        REQUIRE(cortex::AddableWith<int_least32_t, short>);
        REQUIRE(cortex::AddableWith<int_least32_t, long>);
        REQUIRE(cortex::AddableWith<int_least32_t, long long>);

        // int32 with Unsigned Integers
        REQUIRE(cortex::AddableWith<int_least32_t, unsigned>);
        REQUIRE(cortex::AddableWith<int_least32_t, unsigned short>);
        REQUIRE(cortex::AddableWith<int_least32_t, u_short>);
        REQUIRE(cortex::AddableWith<int_least32_t, unsigned long>);
        REQUIRE(cortex::AddableWith<int_least32_t, unsigned long long>);
        
        // int32 with Floating Point and Doubles
        REQUIRE(cortex::AddableWith<int_least32_t, float>);
        REQUIRE(cortex::AddableWith<int_least32_t, double>);
        REQUIRE(cortex::AddableWith<int_least32_t, long double>);

        // int32 with std::strings and std::string_view
        REQUIRE(!cortex::AddableWith<int_least32_t, std::string>);
        REQUIRE(!cortex::AddableWith<int_least32_t, std::string_view>);
        REQUIRE(!cortex::AddableWith<int_least32_t, std::u8string>);
        REQUIRE(!cortex::AddableWith<int_least32_t, std::u16string>);
        REQUIRE(!cortex::AddableWith<int_least32_t, std::u32string>);

        // int32 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::AddableWith<int_least32_t, std::wstring>);
        REQUIRE(!cortex::AddableWith<int_least32_t, std::wstring_view>);

        // int_fast32_t with Charaters
        REQUIRE(cortex::AddableWith<int_least32_t, char>);
        REQUIRE(cortex::AddableWith<int_least32_t, u_char>);
        REQUIRE(cortex::AddableWith<int_least32_t, wchar_t>);

        // int_fast32_t with Bit Specific Characters
        REQUIRE(cortex::AddableWith<int_least32_t, char8_t>);
        REQUIRE(cortex::AddableWith<int_least32_t, char16_t>);
        REQUIRE(cortex::AddableWith<int_least32_t, char32_t>);

        // int_fast32_t with Bit Specific Integers
        REQUIRE(cortex::AddableWith<int_least32_t, int8_t>);
        REQUIRE(cortex::AddableWith<int_least32_t, int16_t>);
        REQUIRE(cortex::AddableWith<int_least32_t, int32_t>);
        REQUIRE(cortex::AddableWith<int_least32_t, int64_t>);

        // int_fast32_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::AddableWith<int_least32_t, uint8_t>);
        REQUIRE(cortex::AddableWith<int_least32_t, uint16_t>);
        REQUIRE(cortex::AddableWith<int_least32_t, uint32_t>);
        REQUIRE(cortex::AddableWith<int_least32_t, uint64_t>);

        // int_fast32_t with Bit Specific Least Integers
        REQUIRE(cortex::AddableWith<int_least32_t, int_least8_t>);
        REQUIRE(cortex::AddableWith<int_least32_t, int_least16_t>);
        REQUIRE(cortex::AddableWith<int_least32_t, int_least32_t>);
        REQUIRE(cortex::AddableWith<int_least32_t, int_least64_t>);
    }

    SECTION("int_least64_t with _")
    {
        // int64 with Signed Integers
        REQUIRE(cortex::AddableWith<int_least64_t, int>);
        REQUIRE(cortex::AddableWith<int_least64_t, short>);
        REQUIRE(cortex::AddableWith<int_least64_t, long>);
        REQUIRE(cortex::AddableWith<int_least64_t, long long>);

        // int64 with Unsigned Integers
        REQUIRE(cortex::AddableWith<int_least64_t, unsigned>);
        REQUIRE(cortex::AddableWith<int_least64_t, unsigned short>);
        REQUIRE(cortex::AddableWith<int_least64_t, u_short>);
        REQUIRE(cortex::AddableWith<int_least64_t, unsigned long>);
        REQUIRE(cortex::AddableWith<int_least64_t, unsigned long long>);
        
        // int64 with Floating Point and Doubles
        REQUIRE(cortex::AddableWith<int_least64_t, float>);
        REQUIRE(cortex::AddableWith<int_least64_t, double>);
        REQUIRE(cortex::AddableWith<int_least64_t, long double>);

        // int64 with std::strings and std::string_view
        REQUIRE(!cortex::AddableWith<int_least64_t, std::string>);
        REQUIRE(!cortex::AddableWith<int_least64_t, std::string_view>);
        REQUIRE(!cortex::AddableWith<int_least64_t, std::u8string>);
        REQUIRE(!cortex::AddableWith<int_least64_t, std::u16string>);
        REQUIRE(!cortex::AddableWith<int_least64_t, std::u32string>);

        // int64 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::AddableWith<int_least64_t, std::wstring>);
        REQUIRE(!cortex::AddableWith<int_least64_t, std::wstring_view>);

        // int_fast64_t with Charaters
        REQUIRE(cortex::AddableWith<int_least64_t, char>);
        REQUIRE(cortex::AddableWith<int_least64_t, u_char>);
        REQUIRE(cortex::AddableWith<int_least64_t, wchar_t>);

        // int_fast64_t with Bit Specific Characters
        REQUIRE(cortex::AddableWith<int_least64_t, char8_t>);
        REQUIRE(cortex::AddableWith<int_least64_t, char16_t>);
        REQUIRE(cortex::AddableWith<int_least64_t, char32_t>);

        // int_fast64_t with Bit Specific Integers
        REQUIRE(cortex::AddableWith<int_least64_t, int8_t>);
        REQUIRE(cortex::AddableWith<int_least64_t, int16_t>);
        REQUIRE(cortex::AddableWith<int_least64_t, int32_t>);
        REQUIRE(cortex::AddableWith<int_least64_t, int64_t>);

        // int_fast64_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::AddableWith<int_least64_t, uint8_t>);
        REQUIRE(cortex::AddableWith<int_least64_t, uint16_t>);
        REQUIRE(cortex::AddableWith<int_least64_t, uint32_t>);
        REQUIRE(cortex::AddableWith<int_least64_t, uint64_t>);

        // int_fast64_t with Bit Specific Least Integers
        REQUIRE(cortex::AddableWith<int_least64_t, int_least8_t>);
        REQUIRE(cortex::AddableWith<int_least64_t, int_least16_t>);
        REQUIRE(cortex::AddableWith<int_least64_t, int_least32_t>);
        REQUIRE(cortex::AddableWith<int_least64_t, int_least64_t>);
    }
}