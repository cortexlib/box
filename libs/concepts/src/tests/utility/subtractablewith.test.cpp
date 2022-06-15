#include <catch2/catch.hpp>
#include <concepts.hpp>

TEST_CASE("SubtractableWith : Signed Integers")
{
    SECTION("Int with _")
    {
        // Int with Signed Integers
        REQUIRE(cortex::SubtractableWith<int, int>);
        REQUIRE(cortex::SubtractableWith<int, short>);
        REQUIRE(cortex::SubtractableWith<int, long>);
        REQUIRE(cortex::SubtractableWith<int, long long>);

        // Int with Unsigned Integers
        REQUIRE(cortex::SubtractableWith<int, unsigned>);
        REQUIRE(cortex::SubtractableWith<int, unsigned short>);
        REQUIRE(cortex::SubtractableWith<int, u_short>);
        REQUIRE(cortex::SubtractableWith<int, unsigned long>);
        REQUIRE(cortex::SubtractableWith<int, unsigned long long>);
        
        // Integers with Floating Point and Doubles
        REQUIRE(cortex::SubtractableWith<int, float>);
        REQUIRE(cortex::SubtractableWith<int, double>);
        REQUIRE(cortex::SubtractableWith<int, long double>);

        // Integers with std::strings and std::string_view
        REQUIRE(!cortex::SubtractableWith<int, std::string>);
        REQUIRE(!cortex::SubtractableWith<int, std::string_view>);
        REQUIRE(!cortex::SubtractableWith<int, std::u8string>);
        REQUIRE(!cortex::SubtractableWith<int, std::u16string>);
        REQUIRE(!cortex::SubtractableWith<int, std::u32string>);

        // Integers with std::wstrings and std::wstring_view
        REQUIRE(!cortex::SubtractableWith<int, std::wstring>);
        REQUIRE(!cortex::SubtractableWith<int, std::wstring_view>);

        // Integers with Charaters
        REQUIRE(cortex::SubtractableWith<int, char>);
        REQUIRE(cortex::SubtractableWith<int, u_char>);
        REQUIRE(cortex::SubtractableWith<int, wchar_t>);

        // Integers with Bit Specific Characters
        REQUIRE(cortex::SubtractableWith<int, char8_t>);
        REQUIRE(cortex::SubtractableWith<int, char16_t>);
        REQUIRE(cortex::SubtractableWith<int, char32_t>);

        // Integers with Bit Specific Integers
        REQUIRE(cortex::SubtractableWith<int, int8_t>);
        REQUIRE(cortex::SubtractableWith<int, int16_t>);
        REQUIRE(cortex::SubtractableWith<int, int32_t>);
        REQUIRE(cortex::SubtractableWith<int, int64_t>);

        // Integers with Bit Specific Unsigned Integers
        REQUIRE(cortex::SubtractableWith<int, uint8_t>);
        REQUIRE(cortex::SubtractableWith<int, uint16_t>);
        REQUIRE(cortex::SubtractableWith<int, uint32_t>);
        REQUIRE(cortex::SubtractableWith<int, uint64_t>);

        // Integers with Bit Specific Least Integers
        REQUIRE(cortex::SubtractableWith<int, int_least8_t>);
        REQUIRE(cortex::SubtractableWith<int, int_least16_t>);
        REQUIRE(cortex::SubtractableWith<int, int_least32_t>);
        REQUIRE(cortex::SubtractableWith<int, int_least64_t>);
    }

    SECTION("Short with _")
    {
        // Short with Signed Integers
        REQUIRE(cortex::SubtractableWith<short, int>);
        REQUIRE(cortex::SubtractableWith<short, short>);
        REQUIRE(cortex::SubtractableWith<short, long>);
        REQUIRE(cortex::SubtractableWith<short, long long>);

        // Short with Unsigned Integers
        REQUIRE(cortex::SubtractableWith<short, unsigned>);
        REQUIRE(cortex::SubtractableWith<short, unsigned short>);
        REQUIRE(cortex::SubtractableWith<short, u_short>);
        REQUIRE(cortex::SubtractableWith<short, unsigned long>);
        REQUIRE(cortex::SubtractableWith<short, unsigned long long>);
        
        // Short with Floating Point and Doubles
        REQUIRE(cortex::SubtractableWith<short, float>);
        REQUIRE(cortex::SubtractableWith<short, double>);
        REQUIRE(cortex::SubtractableWith<short, long double>);

        // Short with std::strings and std::string_view
        REQUIRE(!cortex::SubtractableWith<short, std::string>);
        REQUIRE(!cortex::SubtractableWith<short, std::string_view>);
        REQUIRE(!cortex::SubtractableWith<short, std::u8string>);
        REQUIRE(!cortex::SubtractableWith<short, std::u16string>);
        REQUIRE(!cortex::SubtractableWith<short, std::u32string>);

        // Short with std::wstrings and std::wstring_view
        REQUIRE(!cortex::SubtractableWith<short, std::wstring>);
        REQUIRE(!cortex::SubtractableWith<short, std::wstring_view>);

        // Short with Charaters
        REQUIRE(cortex::SubtractableWith<short, char>);
        REQUIRE(cortex::SubtractableWith<short, u_char>);
        REQUIRE(cortex::SubtractableWith<short, wchar_t>);

        // Short with Bit Specific Characters
        REQUIRE(cortex::SubtractableWith<short, char8_t>);
        REQUIRE(cortex::SubtractableWith<short, char16_t>);
        REQUIRE(cortex::SubtractableWith<short, char32_t>);

        // Short with Bit Specific Short
        REQUIRE(cortex::SubtractableWith<short, int8_t>);
        REQUIRE(cortex::SubtractableWith<short, int16_t>);
        REQUIRE(cortex::SubtractableWith<short, int32_t>);
        REQUIRE(cortex::SubtractableWith<short, int64_t>);

        // Short with Bit Specific Unsigned Short
        REQUIRE(cortex::SubtractableWith<short, uint8_t>);
        REQUIRE(cortex::SubtractableWith<short, uint16_t>);
        REQUIRE(cortex::SubtractableWith<short, uint32_t>);
        REQUIRE(cortex::SubtractableWith<short, uint64_t>);

        // Short with Bit Specific Least Integers
        REQUIRE(cortex::SubtractableWith<short, int_least8_t>);
        REQUIRE(cortex::SubtractableWith<short, int_least16_t>);
        REQUIRE(cortex::SubtractableWith<short, int_least32_t>);
        REQUIRE(cortex::SubtractableWith<short, int_least64_t>);
    }

    SECTION("Long with _")
    {
        // Long with Signed Integers
        REQUIRE(cortex::SubtractableWith<long, int>);
        REQUIRE(cortex::SubtractableWith<long, short>);
        REQUIRE(cortex::SubtractableWith<long, long>);
        REQUIRE(cortex::SubtractableWith<long, long long>);

        // Long with Unsigned Integers
        REQUIRE(cortex::SubtractableWith<long, unsigned>);
        REQUIRE(cortex::SubtractableWith<long, unsigned short>);
        REQUIRE(cortex::SubtractableWith<long, u_short>);
        REQUIRE(cortex::SubtractableWith<long, unsigned long>);
        REQUIRE(cortex::SubtractableWith<long, unsigned long long>);
        
        // Long with Floating Point and Doubles
        REQUIRE(cortex::SubtractableWith<long, float>);
        REQUIRE(cortex::SubtractableWith<long, double>);
        REQUIRE(cortex::SubtractableWith<long, long double>);

        // Long with std::strings and std::string_view
        REQUIRE(!cortex::SubtractableWith<long, std::string>);
        REQUIRE(!cortex::SubtractableWith<long, std::string_view>);
        REQUIRE(!cortex::SubtractableWith<long, std::u8string>);
        REQUIRE(!cortex::SubtractableWith<long, std::u16string>);
        REQUIRE(!cortex::SubtractableWith<long, std::u32string>);

        // Long with std::wstrings and std::wstring_view
        REQUIRE(!cortex::SubtractableWith<long, std::wstring>);
        REQUIRE(!cortex::SubtractableWith<long, std::wstring_view>);

        // Long with Charaters
        REQUIRE(cortex::SubtractableWith<long, char>);
        REQUIRE(cortex::SubtractableWith<long, u_char>);
        REQUIRE(cortex::SubtractableWith<long, wchar_t>);

        // Long with Bit Specific Characters
        REQUIRE(cortex::SubtractableWith<long, char8_t>);
        REQUIRE(cortex::SubtractableWith<long, char16_t>);
        REQUIRE(cortex::SubtractableWith<long, char32_t>);

        // Long with Bit Specific Long
        REQUIRE(cortex::SubtractableWith<long, int8_t>);
        REQUIRE(cortex::SubtractableWith<long, int16_t>);
        REQUIRE(cortex::SubtractableWith<long, int32_t>);
        REQUIRE(cortex::SubtractableWith<long, int64_t>);

        // Long with Bit Specific Unsigned Long
        REQUIRE(cortex::SubtractableWith<long, uint8_t>);
        REQUIRE(cortex::SubtractableWith<long, uint16_t>);
        REQUIRE(cortex::SubtractableWith<long, uint32_t>);
        REQUIRE(cortex::SubtractableWith<long, uint64_t>);

        // Long with Bit Specific Least Integers
        REQUIRE(cortex::SubtractableWith<long, int_least8_t>);
        REQUIRE(cortex::SubtractableWith<long, int_least16_t>);
        REQUIRE(cortex::SubtractableWith<long, int_least32_t>);
        REQUIRE(cortex::SubtractableWith<long, int_least64_t>);
    }

    SECTION("Long Long with _")
    {
        // Signed Integers
        REQUIRE(cortex::SubtractableWith<long long, int>);
        REQUIRE(cortex::SubtractableWith<long long, short>);
        REQUIRE(cortex::SubtractableWith<long long, long>);
        REQUIRE(cortex::SubtractableWith<long long, long long>);

        // Unsigned Integers
        REQUIRE(cortex::SubtractableWith<long long, unsigned>);
        REQUIRE(cortex::SubtractableWith<long long, unsigned short>);
        REQUIRE(cortex::SubtractableWith<long long, u_short>);
        REQUIRE(cortex::SubtractableWith<long long, unsigned long>);
        REQUIRE(cortex::SubtractableWith<long long, unsigned long long>);
        
        // Integers with Floating Point and Doubles
        REQUIRE(cortex::SubtractableWith<long long, float>);
        REQUIRE(cortex::SubtractableWith<long long, double>);
        REQUIRE(cortex::SubtractableWith<long long, long double>);

        // Integers with std::strings and std::string_view
        REQUIRE(!cortex::SubtractableWith<long long, std::string>);
        REQUIRE(!cortex::SubtractableWith<long long, std::string_view>);
        REQUIRE(!cortex::SubtractableWith<long long, std::u8string>);
        REQUIRE(!cortex::SubtractableWith<long long, std::u16string>);
        REQUIRE(!cortex::SubtractableWith<long long, std::u32string>);

        // Integers with std::wstrings and std::wstring_view
        REQUIRE(!cortex::SubtractableWith<long long, std::wstring>);
        REQUIRE(!cortex::SubtractableWith<long long, std::wstring_view>);

        // Integers with Charaters
        REQUIRE(cortex::SubtractableWith<long long, char>);
        REQUIRE(cortex::SubtractableWith<long long, u_char>);
        REQUIRE(cortex::SubtractableWith<long long, wchar_t>);

        // Integers with Bit Specific Characters
        REQUIRE(cortex::SubtractableWith<long long, char8_t>);
        REQUIRE(cortex::SubtractableWith<long long, char16_t>);
        REQUIRE(cortex::SubtractableWith<long long, char32_t>);

        // Integers with Bit Specific Integers
        REQUIRE(cortex::SubtractableWith<long long, int8_t>);
        REQUIRE(cortex::SubtractableWith<long long, int16_t>);
        REQUIRE(cortex::SubtractableWith<long long, int32_t>);
        REQUIRE(cortex::SubtractableWith<long long, int64_t>);

        // Integers with Bit Specific Unsigned Integers
        REQUIRE(cortex::SubtractableWith<long long, uint8_t>);
        REQUIRE(cortex::SubtractableWith<long long, uint16_t>);
        REQUIRE(cortex::SubtractableWith<long long, uint32_t>);
        REQUIRE(cortex::SubtractableWith<long long, uint64_t>);

        // Long Long with Bit Specific Least Integers
        REQUIRE(cortex::SubtractableWith<long long, int_least8_t>);
        REQUIRE(cortex::SubtractableWith<long long, int_least16_t>);
        REQUIRE(cortex::SubtractableWith<long long, int_least32_t>);
        REQUIRE(cortex::SubtractableWith<long long, int_least64_t>);
    }
}

TEST_CASE("SubtractableWith: Unsigned Integers")
{
    SECTION("Unsigned Int with _")
    {
        // Unsigned Integers with Signed Integers
        REQUIRE(cortex::SubtractableWith<unsigned int, int>);
        REQUIRE(cortex::SubtractableWith<unsigned int, short>);
        REQUIRE(cortex::SubtractableWith<unsigned int, long>);
        REQUIRE(cortex::SubtractableWith<unsigned int, long long>);

        // Unsigned Integers with Unsigned Integers
        REQUIRE(cortex::SubtractableWith<unsigned int, unsigned>);
        REQUIRE(cortex::SubtractableWith<unsigned int, unsigned short>);
        REQUIRE(cortex::SubtractableWith<unsigned int, u_short>);
        REQUIRE(cortex::SubtractableWith<unsigned int, unsigned long>);
        REQUIRE(cortex::SubtractableWith<unsigned int, unsigned long long>);
        
        // Unsigned Integers with Floating Point and Doubles
        REQUIRE(cortex::SubtractableWith<unsigned int, float>);
        REQUIRE(cortex::SubtractableWith<unsigned int, double>);
        REQUIRE(cortex::SubtractableWith<unsigned int, long double>);

        // Unsigned Integers with std::strings and std::string_view
        REQUIRE(!cortex::SubtractableWith<unsigned int, std::string>);
        REQUIRE(!cortex::SubtractableWith<unsigned int, std::string_view>);
        REQUIRE(!cortex::SubtractableWith<unsigned int, std::u8string>);
        REQUIRE(!cortex::SubtractableWith<unsigned int, std::u16string>);
        REQUIRE(!cortex::SubtractableWith<unsigned int, std::u32string>);

        // Unsigned Integers with std::wstrings and std::wstring_view
        REQUIRE(!cortex::SubtractableWith<unsigned long long, std::wstring>);
        REQUIRE(!cortex::SubtractableWith<unsigned long long, std::wstring_view>);

        // Unsigned Integers with Charaters
        REQUIRE(cortex::SubtractableWith<unsigned int, char>);
        REQUIRE(cortex::SubtractableWith<unsigned int, u_char>);
        REQUIRE(cortex::SubtractableWith<unsigned int, wchar_t>);

        // Unsigned Integers with Bit Specific Characters
        REQUIRE(cortex::SubtractableWith<unsigned int, char8_t>);
        REQUIRE(cortex::SubtractableWith<unsigned int, char16_t>);
        REQUIRE(cortex::SubtractableWith<unsigned int, char32_t>);

        // Unsigned Integers with Bit Specific Integers
        REQUIRE(cortex::SubtractableWith<unsigned int, int8_t>);
        REQUIRE(cortex::SubtractableWith<unsigned int, int16_t>);
        REQUIRE(cortex::SubtractableWith<unsigned int, int32_t>);
        REQUIRE(cortex::SubtractableWith<unsigned int, int64_t>);

        // Unsigned Integers with Bit Specific Unsigned Integers
        REQUIRE(cortex::SubtractableWith<unsigned int, uint8_t>);
        REQUIRE(cortex::SubtractableWith<unsigned int, uint16_t>);
        REQUIRE(cortex::SubtractableWith<unsigned int, uint32_t>);
        REQUIRE(cortex::SubtractableWith<unsigned int, uint64_t>);

        // Unsigned Integers with Bit Specific Least Integers
        REQUIRE(cortex::SubtractableWith<unsigned int, int_least8_t>);
        REQUIRE(cortex::SubtractableWith<unsigned int, int_least16_t>);
        REQUIRE(cortex::SubtractableWith<unsigned int, int_least32_t>);
        REQUIRE(cortex::SubtractableWith<unsigned int, int_least64_t>);
    }

    SECTION("Unsigned Short with _")
    {
        // Unsigned Short with Signed Integers
        REQUIRE(cortex::SubtractableWith<unsigned short, int>);
        REQUIRE(cortex::SubtractableWith<unsigned short, short>);
        REQUIRE(cortex::SubtractableWith<unsigned short, long>);
        REQUIRE(cortex::SubtractableWith<unsigned short, long long>);

        // Unsigned Short with Unsigned Integers
        REQUIRE(cortex::SubtractableWith<unsigned short, unsigned>);
        REQUIRE(cortex::SubtractableWith<unsigned short, unsigned short>);
        REQUIRE(cortex::SubtractableWith<unsigned short, u_short>);
        REQUIRE(cortex::SubtractableWith<unsigned short, unsigned long>);
        REQUIRE(cortex::SubtractableWith<unsigned short, unsigned long long>);
        
        // Unsigned Short with Floating Point and Doubles
        REQUIRE(cortex::SubtractableWith<unsigned short, float>);
        REQUIRE(cortex::SubtractableWith<unsigned short, double>);
        REQUIRE(cortex::SubtractableWith<unsigned short, long double>);

        // Unsigned Short with std::strings and std::string_view
        REQUIRE(!cortex::SubtractableWith<unsigned short, std::string>);
        REQUIRE(!cortex::SubtractableWith<unsigned short, std::string_view>);
        REQUIRE(!cortex::SubtractableWith<unsigned short, std::u8string>);
        REQUIRE(!cortex::SubtractableWith<unsigned short, std::u16string>);
        REQUIRE(!cortex::SubtractableWith<unsigned short, std::u32string>);

        // Unsigned Short with std::wstrings and std::wstring_view
        REQUIRE(!cortex::SubtractableWith<unsigned short, std::wstring>);
        REQUIRE(!cortex::SubtractableWith<unsigned short, std::wstring_view>);

        // Unsigned Short with Charaters
        REQUIRE(cortex::SubtractableWith<unsigned short, char>);
        REQUIRE(cortex::SubtractableWith<unsigned short, u_char>);
        REQUIRE(cortex::SubtractableWith<unsigned short, wchar_t>);

        // Unsigned Short with Bit Specific Characters
        REQUIRE(cortex::SubtractableWith<unsigned short, char8_t>);
        REQUIRE(cortex::SubtractableWith<unsigned short, char16_t>);
        REQUIRE(cortex::SubtractableWith<unsigned short, char32_t>);

        // Unsigned Short with Bit Specific Short
        REQUIRE(cortex::SubtractableWith<unsigned short, int8_t>);
        REQUIRE(cortex::SubtractableWith<unsigned short, int16_t>);
        REQUIRE(cortex::SubtractableWith<unsigned short, int32_t>);
        REQUIRE(cortex::SubtractableWith<unsigned short, int64_t>);

        // Unsigned Short with Bit Specific Unsigned Short
        REQUIRE(cortex::SubtractableWith<unsigned short, uint8_t>);
        REQUIRE(cortex::SubtractableWith<unsigned short, uint16_t>);
        REQUIRE(cortex::SubtractableWith<unsigned short, uint32_t>);
        REQUIRE(cortex::SubtractableWith<unsigned short, uint64_t>);

        // Unsigned Short with Bit Specific Least Integers
        REQUIRE(cortex::SubtractableWith<unsigned short, int_least8_t>);
        REQUIRE(cortex::SubtractableWith<unsigned short, int_least16_t>);
        REQUIRE(cortex::SubtractableWith<unsigned short, int_least32_t>);
        REQUIRE(cortex::SubtractableWith<unsigned short, int_least64_t>);
    }

    SECTION("u_short with _")
    {
        // u_short with Signed Integers
        REQUIRE(cortex::SubtractableWith<u_short, int>);
        REQUIRE(cortex::SubtractableWith<u_short, short>);
        REQUIRE(cortex::SubtractableWith<u_short, long>);
        REQUIRE(cortex::SubtractableWith<u_short, long long>);

        // u_short with Unsigned Integers
        REQUIRE(cortex::SubtractableWith<u_short, unsigned>);
        REQUIRE(cortex::SubtractableWith<u_short, unsigned short>);
        REQUIRE(cortex::SubtractableWith<u_short, u_short>);
        REQUIRE(cortex::SubtractableWith<u_short, unsigned long>);
        REQUIRE(cortex::SubtractableWith<u_short, unsigned long long>);
        
        // u_short with Floating Point and Doubles
        REQUIRE(cortex::SubtractableWith<u_short, float>);
        REQUIRE(cortex::SubtractableWith<u_short, double>);
        REQUIRE(cortex::SubtractableWith<u_short, long double>);

        // u_short with std::strings and std::string_view
        REQUIRE(!cortex::SubtractableWith<u_short, std::string>);
        REQUIRE(!cortex::SubtractableWith<u_short, std::string_view>);
        REQUIRE(!cortex::SubtractableWith<u_short, std::u8string>);
        REQUIRE(!cortex::SubtractableWith<u_short, std::u16string>);
        REQUIRE(!cortex::SubtractableWith<u_short, std::u32string>);

        // u_short with std::wstrings and std::wstring_view
        REQUIRE(!cortex::SubtractableWith<u_short, std::wstring>);
        REQUIRE(!cortex::SubtractableWith<u_short, std::wstring_view>);

        // u_short with Charaters
        REQUIRE(cortex::SubtractableWith<u_short, char>);
        REQUIRE(cortex::SubtractableWith<u_short, u_char>);
        REQUIRE(cortex::SubtractableWith<u_short, wchar_t>);

        // u_short with Bit Specific Characters
        REQUIRE(cortex::SubtractableWith<u_short, char8_t>);
        REQUIRE(cortex::SubtractableWith<u_short, char16_t>);
        REQUIRE(cortex::SubtractableWith<u_short, char32_t>);

        // u_short with Bit Specific Short
        REQUIRE(cortex::SubtractableWith<u_short, int8_t>);
        REQUIRE(cortex::SubtractableWith<u_short, int16_t>);
        REQUIRE(cortex::SubtractableWith<u_short, int32_t>);
        REQUIRE(cortex::SubtractableWith<u_short, int64_t>);

        // u_short with Bit Specific Unsigned Short
        REQUIRE(cortex::SubtractableWith<u_short, uint8_t>);
        REQUIRE(cortex::SubtractableWith<u_short, uint16_t>);
        REQUIRE(cortex::SubtractableWith<u_short, uint32_t>);
        REQUIRE(cortex::SubtractableWith<u_short, uint64_t>);

        // u_short with Bit Specific Least Integers
        REQUIRE(cortex::SubtractableWith<u_short, int_least8_t>);
        REQUIRE(cortex::SubtractableWith<u_short, int_least16_t>);
        REQUIRE(cortex::SubtractableWith<u_short, int_least32_t>);
        REQUIRE(cortex::SubtractableWith<u_short, int_least64_t>);
    }

    SECTION("Unsigned Long with _")
    {
        // Unsigned Long with Signed Integers
        REQUIRE(cortex::SubtractableWith<unsigned long, int>);
        REQUIRE(cortex::SubtractableWith<unsigned long, short>);
        REQUIRE(cortex::SubtractableWith<unsigned long, long>);
        REQUIRE(cortex::SubtractableWith<unsigned long, long long>);

        // Unsigned Long with Unsigned Integers
        REQUIRE(cortex::SubtractableWith<unsigned long, unsigned>);
        REQUIRE(cortex::SubtractableWith<unsigned long, unsigned short>);
        REQUIRE(cortex::SubtractableWith<unsigned long, u_short>);
        REQUIRE(cortex::SubtractableWith<unsigned long, unsigned long>);
        REQUIRE(cortex::SubtractableWith<unsigned long, unsigned long long>);
        
        // Unsigned Long with Floating Point and Doubles
        REQUIRE(cortex::SubtractableWith<unsigned long, float>);
        REQUIRE(cortex::SubtractableWith<unsigned long, double>);
        REQUIRE(cortex::SubtractableWith<unsigned long, long double>);

        // Unsigned Long with std::strings and std::string_view
        REQUIRE(!cortex::SubtractableWith<unsigned long, std::string>);
        REQUIRE(!cortex::SubtractableWith<unsigned long, std::string_view>);
        REQUIRE(!cortex::SubtractableWith<unsigned long, std::u8string>);
        REQUIRE(!cortex::SubtractableWith<unsigned long, std::u16string>);
        REQUIRE(!cortex::SubtractableWith<unsigned long, std::u32string>);

        // Unsigned Long with std::wstrings and std::wstring_view
        REQUIRE(!cortex::SubtractableWith<unsigned long, std::wstring>);
        REQUIRE(!cortex::SubtractableWith<unsigned long, std::wstring_view>);

        // Unsigned Long with Charaters
        REQUIRE(cortex::SubtractableWith<unsigned long, char>);
        REQUIRE(cortex::SubtractableWith<unsigned long, u_char>);
        REQUIRE(cortex::SubtractableWith<unsigned long, wchar_t>);

        // Unsigned Long with Bit Specific Characters
        REQUIRE(cortex::SubtractableWith<unsigned long, char8_t>);
        REQUIRE(cortex::SubtractableWith<unsigned long, char16_t>);
        REQUIRE(cortex::SubtractableWith<unsigned long, char32_t>);

        // Unsigned Long with Bit Specific Long
        REQUIRE(cortex::SubtractableWith<unsigned long, int8_t>);
        REQUIRE(cortex::SubtractableWith<unsigned long, int16_t>);
        REQUIRE(cortex::SubtractableWith<unsigned long, int32_t>);
        REQUIRE(cortex::SubtractableWith<unsigned long, int64_t>);

        // Unsigned Long with Bit Specific Unsigned Long
        REQUIRE(cortex::SubtractableWith<unsigned long, uint8_t>);
        REQUIRE(cortex::SubtractableWith<unsigned long, uint16_t>);
        REQUIRE(cortex::SubtractableWith<unsigned long, uint32_t>);
        REQUIRE(cortex::SubtractableWith<unsigned long, uint64_t>);

        // Unsigned Long with Bit Specific Least Integers
        REQUIRE(cortex::SubtractableWith<unsigned long, int_least8_t>);
        REQUIRE(cortex::SubtractableWith<unsigned long, int_least16_t>);
        REQUIRE(cortex::SubtractableWith<unsigned long, int_least32_t>);
        REQUIRE(cortex::SubtractableWith<unsigned long, int_least64_t>);
    }

    SECTION("Unsigned Long Long with _")
    {
        // Unsigned Long Long with Signed Integers
        REQUIRE(cortex::SubtractableWith<unsigned long long, int>);
        REQUIRE(cortex::SubtractableWith<unsigned long long, short>);
        REQUIRE(cortex::SubtractableWith<unsigned long long, long>);
        REQUIRE(cortex::SubtractableWith<unsigned long long, long long>);

        // Unsigned Long Long with Unsigned Integers
        REQUIRE(cortex::SubtractableWith<unsigned long long, unsigned>);
        REQUIRE(cortex::SubtractableWith<unsigned long long, unsigned short>);
        REQUIRE(cortex::SubtractableWith<unsigned long long, u_short>);
        REQUIRE(cortex::SubtractableWith<unsigned long long, unsigned long>);
        REQUIRE(cortex::SubtractableWith<unsigned long long, unsigned long long>);
        
        // Unsigned Long Long with Floating Point and Doubles
        REQUIRE(cortex::SubtractableWith<unsigned long long, float>);
        REQUIRE(cortex::SubtractableWith<unsigned long long, double>);
        REQUIRE(cortex::SubtractableWith<unsigned long long, long double>);

        // Unsigned Long Long with std::strings and std::string_view
        REQUIRE(!cortex::SubtractableWith<unsigned long long, std::string>);
        REQUIRE(!cortex::SubtractableWith<unsigned long long, std::string_view>);
        REQUIRE(!cortex::SubtractableWith<unsigned long long, std::u8string>);
        REQUIRE(!cortex::SubtractableWith<unsigned long long, std::u16string>);
        REQUIRE(!cortex::SubtractableWith<unsigned long long, std::u32string>);

        // Unsigned Long Long with std::wstrings and std::wstring_view
        REQUIRE(!cortex::SubtractableWith<unsigned long long, std::wstring>);
        REQUIRE(!cortex::SubtractableWith<unsigned long long, std::wstring_view>);

        // Unsigned Long Long with Charaters
        REQUIRE(cortex::SubtractableWith<unsigned long long, char>);
        REQUIRE(cortex::SubtractableWith<unsigned long long, u_char>);
        REQUIRE(cortex::SubtractableWith<unsigned long long, wchar_t>);

        // Unsigned Long Long with Bit Specific Characters
        REQUIRE(cortex::SubtractableWith<unsigned long long, char8_t>);
        REQUIRE(cortex::SubtractableWith<unsigned long long, char16_t>);
        REQUIRE(cortex::SubtractableWith<unsigned long long, char32_t>);

        // Unsigned Long Long with Bit Specific Long Long
        REQUIRE(cortex::SubtractableWith<unsigned long long, int8_t>);
        REQUIRE(cortex::SubtractableWith<unsigned long long, int16_t>);
        REQUIRE(cortex::SubtractableWith<unsigned long long, int32_t>);
        REQUIRE(cortex::SubtractableWith<unsigned long long, int64_t>);

        // Unsigned Long Long with Bit Specific Unsigned Long Long
        REQUIRE(cortex::SubtractableWith<unsigned long long, uint8_t>);
        REQUIRE(cortex::SubtractableWith<unsigned long long, uint16_t>);
        REQUIRE(cortex::SubtractableWith<unsigned long long, uint32_t>);
        REQUIRE(cortex::SubtractableWith<unsigned long long, uint64_t>);

        // Long Long with Bit Specific Least Long Long
        REQUIRE(cortex::SubtractableWith<unsigned long long, int_least8_t>);
        REQUIRE(cortex::SubtractableWith<unsigned long long, int_least16_t>);
        REQUIRE(cortex::SubtractableWith<unsigned long long, int_least32_t>);
        REQUIRE(cortex::SubtractableWith<unsigned long long, int_least64_t>);
    }
}

TEST_CASE("SubtractableWith : Floats & Doubles") 
{
    SECTION("Float with _")
    {
        // Floats with Signed Integers
        REQUIRE(cortex::SubtractableWith<float, int>);
        REQUIRE(cortex::SubtractableWith<float, short>);
        REQUIRE(cortex::SubtractableWith<float, long>);
        REQUIRE(cortex::SubtractableWith<float, long long>);

        // Floats with Unsigned Integers
        REQUIRE(cortex::SubtractableWith<float, unsigned>);
        REQUIRE(cortex::SubtractableWith<float, unsigned short>);
        REQUIRE(cortex::SubtractableWith<float, u_short>);
        REQUIRE(cortex::SubtractableWith<float, unsigned long>);
        REQUIRE(cortex::SubtractableWith<float, unsigned long long>);
        
        // Float with Floating Point and Doubles
        REQUIRE(cortex::SubtractableWith<float, float>);
        REQUIRE(cortex::SubtractableWith<float, double>);
        REQUIRE(cortex::SubtractableWith<float, long double>);

        // Float with std::strings and std::string_view
        REQUIRE(!cortex::SubtractableWith<float, std::string>);
        REQUIRE(!cortex::SubtractableWith<float, std::string_view>);
        REQUIRE(!cortex::SubtractableWith<float, std::u8string>);
        REQUIRE(!cortex::SubtractableWith<float, std::u16string>);
        REQUIRE(!cortex::SubtractableWith<float, std::u32string>);

        // Float with std::wstrings and std::wstring_view
        REQUIRE(!cortex::SubtractableWith<long long, std::wstring>);
        REQUIRE(!cortex::SubtractableWith<long long, std::wstring_view>);

        // Float with Charaters
        REQUIRE(cortex::SubtractableWith<float, char>);
        REQUIRE(cortex::SubtractableWith<float, u_char>);
        REQUIRE(cortex::SubtractableWith<float, wchar_t>);

        // Float with Bit Specific Characters
        REQUIRE(cortex::SubtractableWith<float, char8_t>);
        REQUIRE(cortex::SubtractableWith<float, char16_t>);
        REQUIRE(cortex::SubtractableWith<float, char32_t>);

        // Float with Bit Specific Integers
        REQUIRE(cortex::SubtractableWith<float, int8_t>);
        REQUIRE(cortex::SubtractableWith<float, int16_t>);
        REQUIRE(cortex::SubtractableWith<float, int32_t>);
        REQUIRE(cortex::SubtractableWith<float, int64_t>);

        // Float with Bit Specific Unsigned Integers
        REQUIRE(cortex::SubtractableWith<float, uint8_t>);
        REQUIRE(cortex::SubtractableWith<float, uint16_t>);
        REQUIRE(cortex::SubtractableWith<float, uint32_t>);
        REQUIRE(cortex::SubtractableWith<float, uint64_t>);

        // Float with Bit Specific Least Integers
        REQUIRE(cortex::SubtractableWith<float, int_least8_t>);
        REQUIRE(cortex::SubtractableWith<float, int_least16_t>);
        REQUIRE(cortex::SubtractableWith<float, int_least32_t>);
        REQUIRE(cortex::SubtractableWith<float, int_least64_t>);
    }

    SECTION("Double with _")
    {
        // Double with Signed Integers
        REQUIRE(cortex::SubtractableWith<double, int>);
        REQUIRE(cortex::SubtractableWith<double, short>);
        REQUIRE(cortex::SubtractableWith<double, long>);
        REQUIRE(cortex::SubtractableWith<double, long long>);

        // Double with Unsigned Integers
        REQUIRE(cortex::SubtractableWith<double, unsigned>);
        REQUIRE(cortex::SubtractableWith<double, unsigned short>);
        REQUIRE(cortex::SubtractableWith<double, u_short>);
        REQUIRE(cortex::SubtractableWith<double, unsigned long>);
        REQUIRE(cortex::SubtractableWith<double, unsigned long long>);
        
        // Double with Floating Point and Doubles
        REQUIRE(cortex::SubtractableWith<double, float>);
        REQUIRE(cortex::SubtractableWith<double, double>);
        REQUIRE(cortex::SubtractableWith<double, long double>);

        // Double with std::strings and std::string_view
        REQUIRE(!cortex::SubtractableWith<double, std::string>);
        REQUIRE(!cortex::SubtractableWith<double, std::string_view>);
        REQUIRE(!cortex::SubtractableWith<double, std::u8string>);
        REQUIRE(!cortex::SubtractableWith<double, std::u16string>);
        REQUIRE(!cortex::SubtractableWith<double, std::u32string>);

        // Double with std::wstrings and std::wstring_view
        REQUIRE(!cortex::SubtractableWith<double, std::wstring>);
        REQUIRE(!cortex::SubtractableWith<double, std::wstring_view>);

        // Double with Charaters
        REQUIRE(cortex::SubtractableWith<double, char>);
        REQUIRE(cortex::SubtractableWith<double, u_char>);
        REQUIRE(cortex::SubtractableWith<double, wchar_t>);

        // Double with Bit Specific Characters
        REQUIRE(cortex::SubtractableWith<double, char8_t>);
        REQUIRE(cortex::SubtractableWith<double, char16_t>);
        REQUIRE(cortex::SubtractableWith<double, char32_t>);

        // Double with Bit Specific Short
        REQUIRE(cortex::SubtractableWith<double, int8_t>);
        REQUIRE(cortex::SubtractableWith<double, int16_t>);
        REQUIRE(cortex::SubtractableWith<double, int32_t>);
        REQUIRE(cortex::SubtractableWith<double, int64_t>);

        // Double with Bit Specific Unsigned Short
        REQUIRE(cortex::SubtractableWith<double, uint8_t>);
        REQUIRE(cortex::SubtractableWith<double, uint16_t>);
        REQUIRE(cortex::SubtractableWith<double, uint32_t>);
        REQUIRE(cortex::SubtractableWith<double, uint64_t>);

        // Double with Bit Specific Least Integers
        REQUIRE(cortex::SubtractableWith<double, int_least8_t>);
        REQUIRE(cortex::SubtractableWith<double, int_least16_t>);
        REQUIRE(cortex::SubtractableWith<double, int_least32_t>);
        REQUIRE(cortex::SubtractableWith<double, int_least64_t>);
    }

    SECTION("Long Double with _")
    {
        // Long Double with Signed Integers
        REQUIRE(cortex::SubtractableWith<long double, int>);
        REQUIRE(cortex::SubtractableWith<long double, short>);
        REQUIRE(cortex::SubtractableWith<long double, long>);
        REQUIRE(cortex::SubtractableWith<long double, long long>);

        // Long Double with Unsigned Integers
        REQUIRE(cortex::SubtractableWith<long double, unsigned>);
        REQUIRE(cortex::SubtractableWith<long double, unsigned short>);
        REQUIRE(cortex::SubtractableWith<long double, u_short>);
        REQUIRE(cortex::SubtractableWith<long double, unsigned long>);
        REQUIRE(cortex::SubtractableWith<long double, unsigned long long>);
        
        // Long Double with Floating Point and Doubles
        REQUIRE(cortex::SubtractableWith<long double, float>);
        REQUIRE(cortex::SubtractableWith<long double, double>);
        REQUIRE(cortex::SubtractableWith<long double, long double>);

        // Long Double with std::strings and std::string_view
        REQUIRE(!cortex::SubtractableWith<long double, std::string>);
        REQUIRE(!cortex::SubtractableWith<long double, std::string_view>);
        REQUIRE(!cortex::SubtractableWith<long double, std::u8string>);
        REQUIRE(!cortex::SubtractableWith<long double, std::u16string>);
        REQUIRE(!cortex::SubtractableWith<long double, std::u32string>);

        // Long Double with std::wstrings and std::wstring_view
        REQUIRE(!cortex::SubtractableWith<long double, std::wstring>);
        REQUIRE(!cortex::SubtractableWith<long double, std::wstring_view>);

        // Long Double with Charaters
        REQUIRE(cortex::SubtractableWith<long double, char>);
        REQUIRE(cortex::SubtractableWith<long double, u_char>);
        REQUIRE(cortex::SubtractableWith<long double, wchar_t>);

        // Long Double with Bit Specific Characters
        REQUIRE(cortex::SubtractableWith<long double, char8_t>);
        REQUIRE(cortex::SubtractableWith<long double, char16_t>);
        REQUIRE(cortex::SubtractableWith<long double, char32_t>);

        // Long Double with Bit Specific Long
        REQUIRE(cortex::SubtractableWith<long double, int8_t>);
        REQUIRE(cortex::SubtractableWith<long double, int16_t>);
        REQUIRE(cortex::SubtractableWith<long double, int32_t>);
        REQUIRE(cortex::SubtractableWith<long double, int64_t>);

        // Long Double with Bit Specific Unsigned Long
        REQUIRE(cortex::SubtractableWith<long double, uint8_t>);
        REQUIRE(cortex::SubtractableWith<long double, uint16_t>);
        REQUIRE(cortex::SubtractableWith<long double, uint32_t>);
        REQUIRE(cortex::SubtractableWith<long double, uint64_t>);

        // Long Double with Bit Specific Least Integers
        REQUIRE(cortex::SubtractableWith<long double, int_least8_t>);
        REQUIRE(cortex::SubtractableWith<long double, int_least16_t>);
        REQUIRE(cortex::SubtractableWith<long double, int_least32_t>);
        REQUIRE(cortex::SubtractableWith<long double, int_least64_t>);
    }

}

TEST_CASE("Addable With : Bit Specific Signed Integers")
{
    SECTION("int8_t with _")
    {
        // int8_t with Signed Integers
        REQUIRE(cortex::SubtractableWith<int8_t, int>);
        REQUIRE(cortex::SubtractableWith<int8_t, short>);
        REQUIRE(cortex::SubtractableWith<int8_t, long>);
        REQUIRE(cortex::SubtractableWith<int8_t, long long>);

        // int8_t with Unsigned Integers
        REQUIRE(cortex::SubtractableWith<int8_t, unsigned>);
        REQUIRE(cortex::SubtractableWith<int8_t, unsigned short>);
        REQUIRE(cortex::SubtractableWith<int8_t, u_short>);
        REQUIRE(cortex::SubtractableWith<int8_t, unsigned long>);
        REQUIRE(cortex::SubtractableWith<int8_t, unsigned long long>);
        
        // int8_t with Floating Point and Doubles
        REQUIRE(cortex::SubtractableWith<int8_t, float>);
        REQUIRE(cortex::SubtractableWith<int8_t, double>);
        REQUIRE(cortex::SubtractableWith<int8_t, long double>);

        // int8_t with std::strings and std::string_view
        REQUIRE(!cortex::SubtractableWith<int8_t, std::string>);
        REQUIRE(!cortex::SubtractableWith<int8_t, std::string_view>);
        REQUIRE(!cortex::SubtractableWith<int8_t, std::u8string>);
        REQUIRE(!cortex::SubtractableWith<int8_t, std::u16string>);
        REQUIRE(!cortex::SubtractableWith<int8_t, std::u32string>);

        // int8_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::SubtractableWith<long long, std::wstring>);
        REQUIRE(!cortex::SubtractableWith<long long, std::wstring_view>);

        // int8_t with Charaters
        REQUIRE(cortex::SubtractableWith<int8_t, char>);
        REQUIRE(cortex::SubtractableWith<int8_t, u_char>);
        REQUIRE(cortex::SubtractableWith<int8_t, wchar_t>);

        // int8_t with Bit Specific Characters
        REQUIRE(cortex::SubtractableWith<int8_t, char8_t>);
        REQUIRE(cortex::SubtractableWith<int8_t, char16_t>);
        REQUIRE(cortex::SubtractableWith<int8_t, char32_t>);

        // int8_t with Bit Specific Integers
        REQUIRE(cortex::SubtractableWith<int8_t, int8_t>);
        REQUIRE(cortex::SubtractableWith<int8_t, int16_t>);
        REQUIRE(cortex::SubtractableWith<int8_t, int32_t>);
        REQUIRE(cortex::SubtractableWith<int8_t, int64_t>);

        // int8_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::SubtractableWith<int8_t, uint8_t>);
        REQUIRE(cortex::SubtractableWith<int8_t, uint16_t>);
        REQUIRE(cortex::SubtractableWith<int8_t, uint32_t>);
        REQUIRE(cortex::SubtractableWith<int8_t, uint64_t>);

        // int8_t with Bit Specific Least Integers
        REQUIRE(cortex::SubtractableWith<int8_t, int_least8_t>);
        REQUIRE(cortex::SubtractableWith<int8_t, int_least16_t>);
        REQUIRE(cortex::SubtractableWith<int8_t, int_least32_t>);
        REQUIRE(cortex::SubtractableWith<int8_t, int_least64_t>);
    }

    SECTION("int16_t with _")
    {
        // int16_t with Signed Integers
        REQUIRE(cortex::SubtractableWith<int16_t, int>);
        REQUIRE(cortex::SubtractableWith<int16_t, short>);
        REQUIRE(cortex::SubtractableWith<int16_t, long>);
        REQUIRE(cortex::SubtractableWith<int16_t, long long>);

        // int16_t with Unsigned Integers
        REQUIRE(cortex::SubtractableWith<int16_t, unsigned>);
        REQUIRE(cortex::SubtractableWith<int16_t, unsigned short>);
        REQUIRE(cortex::SubtractableWith<int16_t, u_short>);
        REQUIRE(cortex::SubtractableWith<int16_t, unsigned long>);
        REQUIRE(cortex::SubtractableWith<int16_t, unsigned long long>);
        
        // int16_t with Floating Point and Doubles
        REQUIRE(cortex::SubtractableWith<int16_t, float>);
        REQUIRE(cortex::SubtractableWith<int16_t, double>);
        REQUIRE(cortex::SubtractableWith<int16_t, long double>);

        // int16_t with std::strings and std::string_view
        REQUIRE(!cortex::SubtractableWith<int16_t, std::string>);
        REQUIRE(!cortex::SubtractableWith<int16_t, std::string_view>);
        REQUIRE(!cortex::SubtractableWith<int16_t, std::u8string>);
        REQUIRE(!cortex::SubtractableWith<int16_t, std::u16string>);
        REQUIRE(!cortex::SubtractableWith<int16_t, std::u32string>);

        // int16_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::SubtractableWith<int16_t, std::wstring>);
        REQUIRE(!cortex::SubtractableWith<int16_t, std::wstring_view>);

        // int16_t with Charaters
        REQUIRE(cortex::SubtractableWith<int16_t, char>);
        REQUIRE(cortex::SubtractableWith<int16_t, u_char>);
        REQUIRE(cortex::SubtractableWith<int16_t, wchar_t>);

        // int16_t with Bit Specific Characters
        REQUIRE(cortex::SubtractableWith<int16_t, char8_t>);
        REQUIRE(cortex::SubtractableWith<int16_t, char16_t>);
        REQUIRE(cortex::SubtractableWith<int16_t, char32_t>);

        // int16_t with Bit Specific Integers
        REQUIRE(cortex::SubtractableWith<int16_t, int8_t>);
        REQUIRE(cortex::SubtractableWith<int16_t, int16_t>);
        REQUIRE(cortex::SubtractableWith<int16_t, int32_t>);
        REQUIRE(cortex::SubtractableWith<int16_t, int64_t>);

        // int16_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::SubtractableWith<int16_t, uint8_t>);
        REQUIRE(cortex::SubtractableWith<int16_t, uint16_t>);
        REQUIRE(cortex::SubtractableWith<int16_t, uint32_t>);
        REQUIRE(cortex::SubtractableWith<int16_t, uint64_t>);

        // int16_t with Bit Specific Least Integers
        REQUIRE(cortex::SubtractableWith<int16_t, int_least8_t>);
        REQUIRE(cortex::SubtractableWith<int16_t, int_least16_t>);
        REQUIRE(cortex::SubtractableWith<int16_t, int_least32_t>);
        REQUIRE(cortex::SubtractableWith<int16_t, int_least64_t>);
    }

    SECTION("int32 with _")
    {
        // int32 with Signed Integers
        REQUIRE(cortex::SubtractableWith<int32_t, int>);
        REQUIRE(cortex::SubtractableWith<int32_t, short>);
        REQUIRE(cortex::SubtractableWith<int32_t, long>);
        REQUIRE(cortex::SubtractableWith<int32_t, long long>);

        // int32 with Unsigned Integers
        REQUIRE(cortex::SubtractableWith<int32_t, unsigned>);
        REQUIRE(cortex::SubtractableWith<int32_t, unsigned short>);
        REQUIRE(cortex::SubtractableWith<int32_t, u_short>);
        REQUIRE(cortex::SubtractableWith<int32_t, unsigned long>);
        REQUIRE(cortex::SubtractableWith<int32_t, unsigned long long>);
        
        // int32 with Floating Point and Doubles
        REQUIRE(cortex::SubtractableWith<int32_t, float>);
        REQUIRE(cortex::SubtractableWith<int32_t, double>);
        REQUIRE(cortex::SubtractableWith<int32_t, long double>);

        // int32 with std::strings and std::string_view
        REQUIRE(!cortex::SubtractableWith<int32_t, std::string>);
        REQUIRE(!cortex::SubtractableWith<int32_t, std::string_view>);
        REQUIRE(!cortex::SubtractableWith<int32_t, std::u8string>);
        REQUIRE(!cortex::SubtractableWith<int32_t, std::u16string>);
        REQUIRE(!cortex::SubtractableWith<int32_t, std::u32string>);

        // int32 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::SubtractableWith<int32_t, std::wstring>);
        REQUIRE(!cortex::SubtractableWith<int32_t, std::wstring_view>);

        // int32_t with Charaters
        REQUIRE(cortex::SubtractableWith<int32_t, char>);
        REQUIRE(cortex::SubtractableWith<int32_t, u_char>);
        REQUIRE(cortex::SubtractableWith<int32_t, wchar_t>);

        // int32_t with Bit Specific Characters
        REQUIRE(cortex::SubtractableWith<int32_t, char8_t>);
        REQUIRE(cortex::SubtractableWith<int32_t, char16_t>);
        REQUIRE(cortex::SubtractableWith<int32_t, char32_t>);

        // int32_t with Bit Specific Integers
        REQUIRE(cortex::SubtractableWith<int32_t, int8_t>);
        REQUIRE(cortex::SubtractableWith<int32_t, int16_t>);
        REQUIRE(cortex::SubtractableWith<int32_t, int32_t>);
        REQUIRE(cortex::SubtractableWith<int32_t, int64_t>);

        // int32_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::SubtractableWith<int32_t, uint8_t>);
        REQUIRE(cortex::SubtractableWith<int32_t, uint16_t>);
        REQUIRE(cortex::SubtractableWith<int32_t, uint32_t>);
        REQUIRE(cortex::SubtractableWith<int32_t, uint64_t>);

        // int32_t with Bit Specific Least Integers
        REQUIRE(cortex::SubtractableWith<int32_t, int_least8_t>);
        REQUIRE(cortex::SubtractableWith<int32_t, int_least16_t>);
        REQUIRE(cortex::SubtractableWith<int32_t, int_least32_t>);
        REQUIRE(cortex::SubtractableWith<int32_t, int_least64_t>);
    }

    SECTION("int64 with _")
    {
        // int64 with Signed Integers
        REQUIRE(cortex::SubtractableWith<int64_t, int>);
        REQUIRE(cortex::SubtractableWith<int64_t, short>);
        REQUIRE(cortex::SubtractableWith<int64_t, long>);
        REQUIRE(cortex::SubtractableWith<int64_t, long long>);

        // int64 with Unsigned Integers
        REQUIRE(cortex::SubtractableWith<int64_t, unsigned>);
        REQUIRE(cortex::SubtractableWith<int64_t, unsigned short>);
        REQUIRE(cortex::SubtractableWith<int64_t, u_short>);
        REQUIRE(cortex::SubtractableWith<int64_t, unsigned long>);
        REQUIRE(cortex::SubtractableWith<int64_t, unsigned long long>);
        
        // int64 with Floating Point and Doubles
        REQUIRE(cortex::SubtractableWith<int64_t, float>);
        REQUIRE(cortex::SubtractableWith<int64_t, double>);
        REQUIRE(cortex::SubtractableWith<int64_t, long double>);

        // int64 with std::strings and std::string_view
        REQUIRE(!cortex::SubtractableWith<int64_t, std::string>);
        REQUIRE(!cortex::SubtractableWith<int64_t, std::string_view>);
        REQUIRE(!cortex::SubtractableWith<int64_t, std::u8string>);
        REQUIRE(!cortex::SubtractableWith<int64_t, std::u16string>);
        REQUIRE(!cortex::SubtractableWith<int64_t, std::u32string>);

        // int64 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::SubtractableWith<int64_t, std::wstring>);
        REQUIRE(!cortex::SubtractableWith<int64_t, std::wstring_view>);

        // int64_t with Charaters
        REQUIRE(cortex::SubtractableWith<int64_t, char>);
        REQUIRE(cortex::SubtractableWith<int64_t, u_char>);
        REQUIRE(cortex::SubtractableWith<int64_t, wchar_t>);

        // int64_t with Bit Specific Characters
        REQUIRE(cortex::SubtractableWith<int64_t, char8_t>);
        REQUIRE(cortex::SubtractableWith<int64_t, char16_t>);
        REQUIRE(cortex::SubtractableWith<int64_t, char32_t>);

        // int64_t with Bit Specific Integers
        REQUIRE(cortex::SubtractableWith<int64_t, int8_t>);
        REQUIRE(cortex::SubtractableWith<int64_t, int16_t>);
        REQUIRE(cortex::SubtractableWith<int64_t, int32_t>);
        REQUIRE(cortex::SubtractableWith<int64_t, int64_t>);

        // int64_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::SubtractableWith<int64_t, uint8_t>);
        REQUIRE(cortex::SubtractableWith<int64_t, uint16_t>);
        REQUIRE(cortex::SubtractableWith<int64_t, uint32_t>);
        REQUIRE(cortex::SubtractableWith<int64_t, uint64_t>);

        // int64_t with Bit Specific Least Integers
        REQUIRE(cortex::SubtractableWith<int64_t, int_least8_t>);
        REQUIRE(cortex::SubtractableWith<int64_t, int_least16_t>);
        REQUIRE(cortex::SubtractableWith<int64_t, int_least32_t>);
        REQUIRE(cortex::SubtractableWith<int64_t, int_least64_t>);
}
}

TEST_CASE("Addable With : Bit Specific Unsigned Integers")
{
    SECTION("uint8_t with _")
    {
        // uint8_t with Signed Integers
        REQUIRE(cortex::SubtractableWith<uint8_t, int>);
        REQUIRE(cortex::SubtractableWith<uint8_t, short>);
        REQUIRE(cortex::SubtractableWith<uint8_t, long>);
        REQUIRE(cortex::SubtractableWith<uint8_t, long long>);

        // uint8_t with Unsigned Integers
        REQUIRE(cortex::SubtractableWith<uint8_t, unsigned>);
        REQUIRE(cortex::SubtractableWith<uint8_t, unsigned short>);
        REQUIRE(cortex::SubtractableWith<uint8_t, u_short>);
        REQUIRE(cortex::SubtractableWith<uint8_t, unsigned long>);
        REQUIRE(cortex::SubtractableWith<uint8_t, unsigned long long>);
        
        // uint8_t with Floating Point and Doubles
        REQUIRE(cortex::SubtractableWith<uint8_t, float>);
        REQUIRE(cortex::SubtractableWith<uint8_t, double>);
        REQUIRE(cortex::SubtractableWith<uint8_t, long double>);

        // uint8_t with std::strings and std::string_view
        REQUIRE(!cortex::SubtractableWith<uint8_t, std::string>);
        REQUIRE(!cortex::SubtractableWith<uint8_t, std::string_view>);
        REQUIRE(!cortex::SubtractableWith<uint8_t, std::u8string>);
        REQUIRE(!cortex::SubtractableWith<uint8_t, std::u16string>);
        REQUIRE(!cortex::SubtractableWith<uint8_t, std::u32string>);

        // uint8_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::SubtractableWith<long long, std::wstring>);
        REQUIRE(!cortex::SubtractableWith<long long, std::wstring_view>);

        // uint8_t with Charaters
        REQUIRE(cortex::SubtractableWith<uint8_t, char>);
        REQUIRE(cortex::SubtractableWith<uint8_t, u_char>);
        REQUIRE(cortex::SubtractableWith<uint8_t, wchar_t>);

        // uint8_t with Bit Specific Characters
        REQUIRE(cortex::SubtractableWith<uint8_t, char8_t>);
        REQUIRE(cortex::SubtractableWith<uint8_t, char16_t>);
        REQUIRE(cortex::SubtractableWith<uint8_t, char32_t>);

        // uint8_t with Bit Specific Integers
        REQUIRE(cortex::SubtractableWith<uint8_t, int8_t>);
        REQUIRE(cortex::SubtractableWith<uint8_t, int16_t>);
        REQUIRE(cortex::SubtractableWith<uint8_t, int32_t>);
        REQUIRE(cortex::SubtractableWith<uint8_t, int64_t>);

        // uint8_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::SubtractableWith<uint8_t, uint8_t>);
        REQUIRE(cortex::SubtractableWith<uint8_t, uint16_t>);
        REQUIRE(cortex::SubtractableWith<uint8_t, uint32_t>);
        REQUIRE(cortex::SubtractableWith<uint8_t, uint64_t>);

        // uint8_t with Bit Specific Least Integers
        REQUIRE(cortex::SubtractableWith<uint8_t, int_least8_t>);
        REQUIRE(cortex::SubtractableWith<uint8_t, int_least16_t>);
        REQUIRE(cortex::SubtractableWith<uint8_t, int_least32_t>);
        REQUIRE(cortex::SubtractableWith<uint8_t, int_least64_t>);
    }

    SECTION("uint16_t with _")
    {
        // uint16_t with Signed Integers
        REQUIRE(cortex::SubtractableWith<uint16_t, int>);
        REQUIRE(cortex::SubtractableWith<uint16_t, short>);
        REQUIRE(cortex::SubtractableWith<uint16_t, long>);
        REQUIRE(cortex::SubtractableWith<uint16_t, long long>);

        // uint16_t with Unsigned Integers
        REQUIRE(cortex::SubtractableWith<uint16_t, unsigned>);
        REQUIRE(cortex::SubtractableWith<uint16_t, unsigned short>);
        REQUIRE(cortex::SubtractableWith<uint16_t, u_short>);
        REQUIRE(cortex::SubtractableWith<uint16_t, unsigned long>);
        REQUIRE(cortex::SubtractableWith<uint16_t, unsigned long long>);
        
        // uint16_t with Floating Point and Doubles
        REQUIRE(cortex::SubtractableWith<uint16_t, float>);
        REQUIRE(cortex::SubtractableWith<uint16_t, double>);
        REQUIRE(cortex::SubtractableWith<uint16_t, long double>);

        // uint16_t with std::strings and std::string_view
        REQUIRE(!cortex::SubtractableWith<uint16_t, std::string>);
        REQUIRE(!cortex::SubtractableWith<uint16_t, std::string_view>);
        REQUIRE(!cortex::SubtractableWith<uint16_t, std::u8string>);
        REQUIRE(!cortex::SubtractableWith<uint16_t, std::u16string>);
        REQUIRE(!cortex::SubtractableWith<uint16_t, std::u32string>);

        // uint16_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::SubtractableWith<uint16_t, std::wstring>);
        REQUIRE(!cortex::SubtractableWith<uint16_t, std::wstring_view>);

        // uint16_t with Charaters
        REQUIRE(cortex::SubtractableWith<uint16_t, char>);
        REQUIRE(cortex::SubtractableWith<uint16_t, u_char>);
        REQUIRE(cortex::SubtractableWith<uint16_t, wchar_t>);

        // uint16_t with Bit Specific Characters
        REQUIRE(cortex::SubtractableWith<uint16_t, char8_t>);
        REQUIRE(cortex::SubtractableWith<uint16_t, char16_t>);
        REQUIRE(cortex::SubtractableWith<uint16_t, char32_t>);

        // uint16_t with Bit Specific Integers
        REQUIRE(cortex::SubtractableWith<uint16_t, int8_t>);
        REQUIRE(cortex::SubtractableWith<uint16_t, int16_t>);
        REQUIRE(cortex::SubtractableWith<uint16_t, int32_t>);
        REQUIRE(cortex::SubtractableWith<uint16_t, int64_t>);

        // uint16_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::SubtractableWith<uint16_t, uint8_t>);
        REQUIRE(cortex::SubtractableWith<uint16_t, uint16_t>);
        REQUIRE(cortex::SubtractableWith<uint16_t, uint32_t>);
        REQUIRE(cortex::SubtractableWith<uint16_t, uint64_t>);

        // uint16_t with Bit Specific Least Integers
        REQUIRE(cortex::SubtractableWith<uint16_t, int_least8_t>);
        REQUIRE(cortex::SubtractableWith<uint16_t, int_least16_t>);
        REQUIRE(cortex::SubtractableWith<uint16_t, int_least32_t>);
        REQUIRE(cortex::SubtractableWith<uint16_t, int_least64_t>);
    }

    SECTION("uint32_t with _")
    {
        // int32 with Signed Integers
        REQUIRE(cortex::SubtractableWith<uint32_t, int>);
        REQUIRE(cortex::SubtractableWith<uint32_t, short>);
        REQUIRE(cortex::SubtractableWith<uint32_t, long>);
        REQUIRE(cortex::SubtractableWith<uint32_t, long long>);

        // int32 with Unsigned Integers
        REQUIRE(cortex::SubtractableWith<uint32_t, unsigned>);
        REQUIRE(cortex::SubtractableWith<uint32_t, unsigned short>);
        REQUIRE(cortex::SubtractableWith<uint32_t, u_short>);
        REQUIRE(cortex::SubtractableWith<uint32_t, unsigned long>);
        REQUIRE(cortex::SubtractableWith<uint32_t, unsigned long long>);
        
        // int32 with Floating Point and Doubles
        REQUIRE(cortex::SubtractableWith<uint32_t, float>);
        REQUIRE(cortex::SubtractableWith<uint32_t, double>);
        REQUIRE(cortex::SubtractableWith<uint32_t, long double>);

        // int32 with std::strings and std::string_view
        REQUIRE(!cortex::SubtractableWith<uint32_t, std::string>);
        REQUIRE(!cortex::SubtractableWith<uint32_t, std::string_view>);
        REQUIRE(!cortex::SubtractableWith<uint32_t, std::u8string>);
        REQUIRE(!cortex::SubtractableWith<uint32_t, std::u16string>);
        REQUIRE(!cortex::SubtractableWith<uint32_t, std::u32string>);

        // int32 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::SubtractableWith<uint32_t, std::wstring>);
        REQUIRE(!cortex::SubtractableWith<uint32_t, std::wstring_view>);

        // uint32_t with Charaters
        REQUIRE(cortex::SubtractableWith<uint32_t, char>);
        REQUIRE(cortex::SubtractableWith<uint32_t, u_char>);
        REQUIRE(cortex::SubtractableWith<uint32_t, wchar_t>);

        // uint32_t with Bit Specific Characters
        REQUIRE(cortex::SubtractableWith<uint32_t, char8_t>);
        REQUIRE(cortex::SubtractableWith<uint32_t, char16_t>);
        REQUIRE(cortex::SubtractableWith<uint32_t, char32_t>);

        // uint32_t with Bit Specific Integers
        REQUIRE(cortex::SubtractableWith<uint32_t, int8_t>);
        REQUIRE(cortex::SubtractableWith<uint32_t, int16_t>);
        REQUIRE(cortex::SubtractableWith<uint32_t, int32_t>);
        REQUIRE(cortex::SubtractableWith<uint32_t, int64_t>);

        // uint32_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::SubtractableWith<uint32_t, uint8_t>);
        REQUIRE(cortex::SubtractableWith<uint32_t, uint16_t>);
        REQUIRE(cortex::SubtractableWith<uint32_t, uint32_t>);
        REQUIRE(cortex::SubtractableWith<uint32_t, uint64_t>);

        // uint32_t with Bit Specific Least Integers
        REQUIRE(cortex::SubtractableWith<uint32_t, int_least8_t>);
        REQUIRE(cortex::SubtractableWith<uint32_t, int_least16_t>);
        REQUIRE(cortex::SubtractableWith<uint32_t, int_least32_t>);
        REQUIRE(cortex::SubtractableWith<uint32_t, int_least64_t>);
    }

    SECTION("uint64_t with _")
    {
        // int64 with Signed Integers
        REQUIRE(cortex::SubtractableWith<uint64_t, int>);
        REQUIRE(cortex::SubtractableWith<uint64_t, short>);
        REQUIRE(cortex::SubtractableWith<uint64_t, long>);
        REQUIRE(cortex::SubtractableWith<uint64_t, long long>);

        // int64 with Unsigned Integers
        REQUIRE(cortex::SubtractableWith<uint64_t, unsigned>);
        REQUIRE(cortex::SubtractableWith<uint64_t, unsigned short>);
        REQUIRE(cortex::SubtractableWith<uint64_t, u_short>);
        REQUIRE(cortex::SubtractableWith<uint64_t, unsigned long>);
        REQUIRE(cortex::SubtractableWith<uint64_t, unsigned long long>);
        
        // int64 with Floating Point and Doubles
        REQUIRE(cortex::SubtractableWith<uint64_t, float>);
        REQUIRE(cortex::SubtractableWith<uint64_t, double>);
        REQUIRE(cortex::SubtractableWith<uint64_t, long double>);

        // int64 with std::strings and std::string_view
        REQUIRE(!cortex::SubtractableWith<uint64_t, std::string>);
        REQUIRE(!cortex::SubtractableWith<uint64_t, std::string_view>);
        REQUIRE(!cortex::SubtractableWith<uint64_t, std::u8string>);
        REQUIRE(!cortex::SubtractableWith<uint64_t, std::u16string>);
        REQUIRE(!cortex::SubtractableWith<uint64_t, std::u32string>);

        // int64 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::SubtractableWith<uint64_t, std::wstring>);
        REQUIRE(!cortex::SubtractableWith<uint64_t, std::wstring_view>);

        // uint64_t with Charaters
        REQUIRE(cortex::SubtractableWith<uint64_t, char>);
        REQUIRE(cortex::SubtractableWith<uint64_t, u_char>);
        REQUIRE(cortex::SubtractableWith<uint64_t, wchar_t>);

        // uint64_t with Bit Specific Characters
        REQUIRE(cortex::SubtractableWith<uint64_t, char8_t>);
        REQUIRE(cortex::SubtractableWith<uint64_t, char16_t>);
        REQUIRE(cortex::SubtractableWith<uint64_t, char32_t>);

        // uint64_t with Bit Specific Integers
        REQUIRE(cortex::SubtractableWith<uint64_t, int8_t>);
        REQUIRE(cortex::SubtractableWith<uint64_t, int16_t>);
        REQUIRE(cortex::SubtractableWith<uint64_t, int32_t>);
        REQUIRE(cortex::SubtractableWith<uint64_t, int64_t>);

        // uint64_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::SubtractableWith<uint64_t, uint8_t>);
        REQUIRE(cortex::SubtractableWith<uint64_t, uint16_t>);
        REQUIRE(cortex::SubtractableWith<uint64_t, uint32_t>);
        REQUIRE(cortex::SubtractableWith<uint64_t, uint64_t>);

        // uint64_t with Bit Specific Least Integers
        REQUIRE(cortex::SubtractableWith<uint64_t, int_least8_t>);
        REQUIRE(cortex::SubtractableWith<uint64_t, int_least16_t>);
        REQUIRE(cortex::SubtractableWith<uint64_t, int_least32_t>);
        REQUIRE(cortex::SubtractableWith<uint64_t, int_least64_t>);
    }
}

TEST_CASE("Addable With : std::size_t")
{
    SECTION("std::size_t with _")
    {
        // std::size_t with Signed Integers
        REQUIRE(cortex::SubtractableWith<std::size_t, int>);
        REQUIRE(cortex::SubtractableWith<std::size_t, short>);
        REQUIRE(cortex::SubtractableWith<std::size_t, long>);
        REQUIRE(cortex::SubtractableWith<std::size_t, long long>);

        // std::size_t with Unsigned Integers
        REQUIRE(cortex::SubtractableWith<std::size_t, unsigned>);
        REQUIRE(cortex::SubtractableWith<std::size_t, unsigned short>);
        REQUIRE(cortex::SubtractableWith<std::size_t, u_short>);
        REQUIRE(cortex::SubtractableWith<std::size_t, unsigned long>);
        REQUIRE(cortex::SubtractableWith<std::size_t, unsigned long long>);
        
        // std::size_t with Floating Point and Doubles
        REQUIRE(cortex::SubtractableWith<std::size_t, float>);
        REQUIRE(cortex::SubtractableWith<std::size_t, double>);
        REQUIRE(cortex::SubtractableWith<std::size_t, long double>);

        // std::size_t with std::strings and std::string_view
        REQUIRE(!cortex::SubtractableWith<std::size_t, std::string>);
        REQUIRE(!cortex::SubtractableWith<std::size_t, std::string_view>);
        REQUIRE(!cortex::SubtractableWith<std::size_t, std::u8string>);
        REQUIRE(!cortex::SubtractableWith<std::size_t, std::u16string>);
        REQUIRE(!cortex::SubtractableWith<std::size_t, std::u32string>);

        // std::size_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::SubtractableWith<long long, std::wstring>);
        REQUIRE(!cortex::SubtractableWith<long long, std::wstring_view>);

        // std::size_t with Charaters
        REQUIRE(cortex::SubtractableWith<std::size_t, char>);
        REQUIRE(cortex::SubtractableWith<std::size_t, u_char>);
        REQUIRE(cortex::SubtractableWith<std::size_t, wchar_t>);

        // std::size_t with Bit Specific Characters
        REQUIRE(cortex::SubtractableWith<std::size_t, char8_t>);
        REQUIRE(cortex::SubtractableWith<std::size_t, char16_t>);
        REQUIRE(cortex::SubtractableWith<std::size_t, char32_t>);

        // std::size_t with Bit Specific Integers
        REQUIRE(cortex::SubtractableWith<std::size_t, int8_t>);
        REQUIRE(cortex::SubtractableWith<std::size_t, int16_t>);
        REQUIRE(cortex::SubtractableWith<std::size_t, int32_t>);
        REQUIRE(cortex::SubtractableWith<std::size_t, int64_t>);

        // std::size_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::SubtractableWith<std::size_t, uint8_t>);
        REQUIRE(cortex::SubtractableWith<std::size_t, uint16_t>);
        REQUIRE(cortex::SubtractableWith<std::size_t, uint32_t>);
        REQUIRE(cortex::SubtractableWith<std::size_t, uint64_t>);

        // std::size_t with Bit Specific Least Integers
        REQUIRE(cortex::SubtractableWith<std::size_t, int_least8_t>);
        REQUIRE(cortex::SubtractableWith<std::size_t, int_least16_t>);
        REQUIRE(cortex::SubtractableWith<std::size_t, int_least32_t>);
        REQUIRE(cortex::SubtractableWith<std::size_t, int_least64_t>);
    }
}

TEST_CASE("SubtractableWith : Fast Integers")
{
    SECTION("int_fast8_t with _")
    {
        // int_fast8_t with Signed Integers
        REQUIRE(cortex::SubtractableWith<int_fast8_t, int>);
        REQUIRE(cortex::SubtractableWith<int_fast8_t, short>);
        REQUIRE(cortex::SubtractableWith<int_fast8_t, long>);
        REQUIRE(cortex::SubtractableWith<int_fast8_t, long long>);

        // int_fast8_t with Unsigned Integers
        REQUIRE(cortex::SubtractableWith<int_fast8_t, unsigned>);
        REQUIRE(cortex::SubtractableWith<int_fast8_t, unsigned short>);
        REQUIRE(cortex::SubtractableWith<int_fast8_t, u_short>);
        REQUIRE(cortex::SubtractableWith<int_fast8_t, unsigned long>);
        REQUIRE(cortex::SubtractableWith<int_fast8_t, unsigned long long>);
        
        // int_fast8_t with Floating Point and Doubles
        REQUIRE(cortex::SubtractableWith<int_fast8_t, float>);
        REQUIRE(cortex::SubtractableWith<int_fast8_t, double>);
        REQUIRE(cortex::SubtractableWith<int_fast8_t, long double>);

        // int_fast8_t with std::strings and std::string_view
        REQUIRE(!cortex::SubtractableWith<int_fast8_t, std::string>);
        REQUIRE(!cortex::SubtractableWith<int_fast8_t, std::string_view>);
        REQUIRE(!cortex::SubtractableWith<int_fast8_t, std::u8string>);
        REQUIRE(!cortex::SubtractableWith<int_fast8_t, std::u16string>);
        REQUIRE(!cortex::SubtractableWith<int_fast8_t, std::u32string>);

        // int_fast8_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::SubtractableWith<long long, std::wstring>);
        REQUIRE(!cortex::SubtractableWith<long long, std::wstring_view>);

        // int_fast8_t with Charaters
        REQUIRE(cortex::SubtractableWith<int_fast8_t, char>);
        REQUIRE(cortex::SubtractableWith<int_fast8_t, u_char>);
        REQUIRE(cortex::SubtractableWith<int_fast8_t, wchar_t>);

        // int_fast8_t with Bit Specific Characters
        REQUIRE(cortex::SubtractableWith<int_fast8_t, char8_t>);
        REQUIRE(cortex::SubtractableWith<int_fast8_t, char16_t>);
        REQUIRE(cortex::SubtractableWith<int_fast8_t, char32_t>);

        // int_fast8_t with Bit Specific Integers
        REQUIRE(cortex::SubtractableWith<int_fast8_t, int8_t>);
        REQUIRE(cortex::SubtractableWith<int_fast8_t, int16_t>);
        REQUIRE(cortex::SubtractableWith<int_fast8_t, int32_t>);
        REQUIRE(cortex::SubtractableWith<int_fast8_t, int64_t>);

        // int_fast8_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::SubtractableWith<int_fast8_t, uint8_t>);
        REQUIRE(cortex::SubtractableWith<int_fast8_t, uint16_t>);
        REQUIRE(cortex::SubtractableWith<int_fast8_t, uint32_t>);
        REQUIRE(cortex::SubtractableWith<int_fast8_t, uint64_t>);

        // int_fast8_t with Bit Specific Least Integers
        REQUIRE(cortex::SubtractableWith<int_fast8_t, int_least8_t>);
        REQUIRE(cortex::SubtractableWith<int_fast8_t, int_least16_t>);
        REQUIRE(cortex::SubtractableWith<int_fast8_t, int_least32_t>);
        REQUIRE(cortex::SubtractableWith<int_fast8_t, int_least64_t>);
    }

    SECTION("int_fast16_t with _")
    {
        // int_fast16_t with Signed Integers
        REQUIRE(cortex::SubtractableWith<int_fast16_t, int>);
        REQUIRE(cortex::SubtractableWith<int_fast16_t, short>);
        REQUIRE(cortex::SubtractableWith<int_fast16_t, long>);
        REQUIRE(cortex::SubtractableWith<int_fast16_t, long long>);

        // int_fast16_t with Unsigned Integers
        REQUIRE(cortex::SubtractableWith<int_fast16_t, unsigned>);
        REQUIRE(cortex::SubtractableWith<int_fast16_t, unsigned short>);
        REQUIRE(cortex::SubtractableWith<int_fast16_t, u_short>);
        REQUIRE(cortex::SubtractableWith<int_fast16_t, unsigned long>);
        REQUIRE(cortex::SubtractableWith<int_fast16_t, unsigned long long>);
        
        // int_fast16_t with Floating Point and Doubles
        REQUIRE(cortex::SubtractableWith<int_fast16_t, float>);
        REQUIRE(cortex::SubtractableWith<int_fast16_t, double>);
        REQUIRE(cortex::SubtractableWith<int_fast16_t, long double>);

        // int_fast16_t with std::strings and std::string_view
        REQUIRE(!cortex::SubtractableWith<int_fast16_t, std::string>);
        REQUIRE(!cortex::SubtractableWith<int_fast16_t, std::string_view>);
        REQUIRE(!cortex::SubtractableWith<int_fast16_t, std::u8string>);
        REQUIRE(!cortex::SubtractableWith<int_fast16_t, std::u16string>);
        REQUIRE(!cortex::SubtractableWith<int_fast16_t, std::u32string>);

        // int_fast16_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::SubtractableWith<int_fast16_t, std::wstring>);
        REQUIRE(!cortex::SubtractableWith<int_fast16_t, std::wstring_view>);

        // int_fast16_t with Charaters
        REQUIRE(cortex::SubtractableWith<int_fast16_t, char>);
        REQUIRE(cortex::SubtractableWith<int_fast16_t, u_char>);
        REQUIRE(cortex::SubtractableWith<int_fast16_t, wchar_t>);

        // int_fast16_t with Bit Specific Characters
        REQUIRE(cortex::SubtractableWith<int_fast16_t, char8_t>);
        REQUIRE(cortex::SubtractableWith<int_fast16_t, char16_t>);
        REQUIRE(cortex::SubtractableWith<int_fast16_t, char32_t>);

        // int_fast16_t with Bit Specific Integers
        REQUIRE(cortex::SubtractableWith<int_fast16_t, int8_t>);
        REQUIRE(cortex::SubtractableWith<int_fast16_t, int16_t>);
        REQUIRE(cortex::SubtractableWith<int_fast16_t, int32_t>);
        REQUIRE(cortex::SubtractableWith<int_fast16_t, int64_t>);

        // int_fast16_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::SubtractableWith<int_fast16_t, uint8_t>);
        REQUIRE(cortex::SubtractableWith<int_fast16_t, uint16_t>);
        REQUIRE(cortex::SubtractableWith<int_fast16_t, uint32_t>);
        REQUIRE(cortex::SubtractableWith<int_fast16_t, uint64_t>);

        // int_fast16_t with Bit Specific Least Integers
        REQUIRE(cortex::SubtractableWith<int_fast16_t, int_least8_t>);
        REQUIRE(cortex::SubtractableWith<int_fast16_t, int_least16_t>);
        REQUIRE(cortex::SubtractableWith<int_fast16_t, int_least32_t>);
        REQUIRE(cortex::SubtractableWith<int_fast16_t, int_least64_t>);
    }

    SECTION("int_fast32_t with _")
    {
        // int32 with Signed Integers
        REQUIRE(cortex::SubtractableWith<int_fast32_t, int>);
        REQUIRE(cortex::SubtractableWith<int_fast32_t, short>);
        REQUIRE(cortex::SubtractableWith<int_fast32_t, long>);
        REQUIRE(cortex::SubtractableWith<int_fast32_t, long long>);

        // int32 with Unsigned Integers
        REQUIRE(cortex::SubtractableWith<int_fast32_t, unsigned>);
        REQUIRE(cortex::SubtractableWith<int_fast32_t, unsigned short>);
        REQUIRE(cortex::SubtractableWith<int_fast32_t, u_short>);
        REQUIRE(cortex::SubtractableWith<int_fast32_t, unsigned long>);
        REQUIRE(cortex::SubtractableWith<int_fast32_t, unsigned long long>);
        
        // int32 with Floating Point and Doubles
        REQUIRE(cortex::SubtractableWith<int_fast32_t, float>);
        REQUIRE(cortex::SubtractableWith<int_fast32_t, double>);
        REQUIRE(cortex::SubtractableWith<int_fast32_t, long double>);

        // int32 with std::strings and std::string_view
        REQUIRE(!cortex::SubtractableWith<int_fast32_t, std::string>);
        REQUIRE(!cortex::SubtractableWith<int_fast32_t, std::string_view>);
        REQUIRE(!cortex::SubtractableWith<int_fast32_t, std::u8string>);
        REQUIRE(!cortex::SubtractableWith<int_fast32_t, std::u16string>);
        REQUIRE(!cortex::SubtractableWith<int_fast32_t, std::u32string>);

        // int32 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::SubtractableWith<int_fast32_t, std::wstring>);
        REQUIRE(!cortex::SubtractableWith<int_fast32_t, std::wstring_view>);

        // int_fast32_t with Charaters
        REQUIRE(cortex::SubtractableWith<int_fast32_t, char>);
        REQUIRE(cortex::SubtractableWith<int_fast32_t, u_char>);
        REQUIRE(cortex::SubtractableWith<int_fast32_t, wchar_t>);

        // int_fast32_t with Bit Specific Characters
        REQUIRE(cortex::SubtractableWith<int_fast32_t, char8_t>);
        REQUIRE(cortex::SubtractableWith<int_fast32_t, char16_t>);
        REQUIRE(cortex::SubtractableWith<int_fast32_t, char32_t>);

        // int_fast32_t with Bit Specific Integers
        REQUIRE(cortex::SubtractableWith<int_fast32_t, int8_t>);
        REQUIRE(cortex::SubtractableWith<int_fast32_t, int16_t>);
        REQUIRE(cortex::SubtractableWith<int_fast32_t, int32_t>);
        REQUIRE(cortex::SubtractableWith<int_fast32_t, int64_t>);

        // int_fast32_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::SubtractableWith<int_fast32_t, uint8_t>);
        REQUIRE(cortex::SubtractableWith<int_fast32_t, uint16_t>);
        REQUIRE(cortex::SubtractableWith<int_fast32_t, uint32_t>);
        REQUIRE(cortex::SubtractableWith<int_fast32_t, uint64_t>);

        // int_fast32_t with Bit Specific Least Integers
        REQUIRE(cortex::SubtractableWith<int_fast32_t, int_least8_t>);
        REQUIRE(cortex::SubtractableWith<int_fast32_t, int_least16_t>);
        REQUIRE(cortex::SubtractableWith<int_fast32_t, int_least32_t>);
        REQUIRE(cortex::SubtractableWith<int_fast32_t, int_least64_t>);
    }

    SECTION("int_fast64_t with _")
    {
        // int64 with Signed Integers
        REQUIRE(cortex::SubtractableWith<int_fast64_t, int>);
        REQUIRE(cortex::SubtractableWith<int_fast64_t, short>);
        REQUIRE(cortex::SubtractableWith<int_fast64_t, long>);
        REQUIRE(cortex::SubtractableWith<int_fast64_t, long long>);

        // int64 with Unsigned Integers
        REQUIRE(cortex::SubtractableWith<int_fast64_t, unsigned>);
        REQUIRE(cortex::SubtractableWith<int_fast64_t, unsigned short>);
        REQUIRE(cortex::SubtractableWith<int_fast64_t, u_short>);
        REQUIRE(cortex::SubtractableWith<int_fast64_t, unsigned long>);
        REQUIRE(cortex::SubtractableWith<int_fast64_t, unsigned long long>);
        
        // int64 with Floating Point and Doubles
        REQUIRE(cortex::SubtractableWith<int_fast64_t, float>);
        REQUIRE(cortex::SubtractableWith<int_fast64_t, double>);
        REQUIRE(cortex::SubtractableWith<int_fast64_t, long double>);

        // int64 with std::strings and std::string_view
        REQUIRE(!cortex::SubtractableWith<int_fast64_t, std::string>);
        REQUIRE(!cortex::SubtractableWith<int_fast64_t, std::string_view>);
        REQUIRE(!cortex::SubtractableWith<int_fast64_t, std::u8string>);
        REQUIRE(!cortex::SubtractableWith<int_fast64_t, std::u16string>);
        REQUIRE(!cortex::SubtractableWith<int_fast64_t, std::u32string>);

        // int64 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::SubtractableWith<int_fast64_t, std::wstring>);
        REQUIRE(!cortex::SubtractableWith<int_fast64_t, std::wstring_view>);

        // int_fast64_t with Charaters
        REQUIRE(cortex::SubtractableWith<int_fast64_t, char>);
        REQUIRE(cortex::SubtractableWith<int_fast64_t, u_char>);
        REQUIRE(cortex::SubtractableWith<int_fast64_t, wchar_t>);

        // int_fast64_t with Bit Specific Characters
        REQUIRE(cortex::SubtractableWith<int_fast64_t, char8_t>);
        REQUIRE(cortex::SubtractableWith<int_fast64_t, char16_t>);
        REQUIRE(cortex::SubtractableWith<int_fast64_t, char32_t>);

        // int_fast64_t with Bit Specific Integers
        REQUIRE(cortex::SubtractableWith<int_fast64_t, int8_t>);
        REQUIRE(cortex::SubtractableWith<int_fast64_t, int16_t>);
        REQUIRE(cortex::SubtractableWith<int_fast64_t, int32_t>);
        REQUIRE(cortex::SubtractableWith<int_fast64_t, int64_t>);

        // int_fast64_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::SubtractableWith<int_fast64_t, uint8_t>);
        REQUIRE(cortex::SubtractableWith<int_fast64_t, uint16_t>);
        REQUIRE(cortex::SubtractableWith<int_fast64_t, uint32_t>);
        REQUIRE(cortex::SubtractableWith<int_fast64_t, uint64_t>);

        // int_fast64_t with Bit Specific Least Integers
        REQUIRE(cortex::SubtractableWith<int_fast64_t, int_least8_t>);
        REQUIRE(cortex::SubtractableWith<int_fast64_t, int_least16_t>);
        REQUIRE(cortex::SubtractableWith<int_fast64_t, int_least32_t>);
        REQUIRE(cortex::SubtractableWith<int_fast64_t, int_least64_t>);
    }
}

TEST_CASE("SubtractableWith : Least Integers")
{
    SECTION("int_least8_t with _")
    {
        // int_fast8_t with Signed Integers
        REQUIRE(cortex::SubtractableWith<int_least8_t, int>);
        REQUIRE(cortex::SubtractableWith<int_least8_t, short>);
        REQUIRE(cortex::SubtractableWith<int_least8_t, long>);
        REQUIRE(cortex::SubtractableWith<int_least8_t, long long>);

        // int_fast8_t with Unsigned Integers
        REQUIRE(cortex::SubtractableWith<int_least8_t, unsigned>);
        REQUIRE(cortex::SubtractableWith<int_least8_t, unsigned short>);
        REQUIRE(cortex::SubtractableWith<int_least8_t, u_short>);
        REQUIRE(cortex::SubtractableWith<int_least8_t, unsigned long>);
        REQUIRE(cortex::SubtractableWith<int_least8_t, unsigned long long>);
        
        // int_fast8_t with Floating Point and Doubles
        REQUIRE(cortex::SubtractableWith<int_least8_t, float>);
        REQUIRE(cortex::SubtractableWith<int_least8_t, double>);
        REQUIRE(cortex::SubtractableWith<int_least8_t, long double>);

        // int_fast8_t with std::strings and std::string_view
        REQUIRE(!cortex::SubtractableWith<int_least8_t, std::string>);
        REQUIRE(!cortex::SubtractableWith<int_least8_t, std::string_view>);
        REQUIRE(!cortex::SubtractableWith<int_least8_t, std::u8string>);
        REQUIRE(!cortex::SubtractableWith<int_least8_t, std::u16string>);
        REQUIRE(!cortex::SubtractableWith<int_least8_t, std::u32string>);

        // int_fast8_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::SubtractableWith<long long, std::wstring>);
        REQUIRE(!cortex::SubtractableWith<long long, std::wstring_view>);

        // int_fast8_t with Charaters
        REQUIRE(cortex::SubtractableWith<int_least8_t, char>);
        REQUIRE(cortex::SubtractableWith<int_least8_t, u_char>);
        REQUIRE(cortex::SubtractableWith<int_least8_t, wchar_t>);

        // int_fast8_t with Bit Specific Characters
        REQUIRE(cortex::SubtractableWith<int_least8_t, char8_t>);
        REQUIRE(cortex::SubtractableWith<int_least8_t, char16_t>);
        REQUIRE(cortex::SubtractableWith<int_least8_t, char32_t>);

        // int_fast8_t with Bit Specific Integers
        REQUIRE(cortex::SubtractableWith<int_least8_t, int8_t>);
        REQUIRE(cortex::SubtractableWith<int_least8_t, int16_t>);
        REQUIRE(cortex::SubtractableWith<int_least8_t, int32_t>);
        REQUIRE(cortex::SubtractableWith<int_least8_t, int64_t>);

        // int_fast8_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::SubtractableWith<int_least8_t, uint8_t>);
        REQUIRE(cortex::SubtractableWith<int_least8_t, uint16_t>);
        REQUIRE(cortex::SubtractableWith<int_least8_t, uint32_t>);
        REQUIRE(cortex::SubtractableWith<int_least8_t, uint64_t>);

        // int_fast8_t with Bit Specific Least Integers
        REQUIRE(cortex::SubtractableWith<int_least8_t, int_least8_t>);
        REQUIRE(cortex::SubtractableWith<int_least8_t, int_least16_t>);
        REQUIRE(cortex::SubtractableWith<int_least8_t, int_least32_t>);
        REQUIRE(cortex::SubtractableWith<int_least8_t, int_least64_t>);
    }

    SECTION("int_least16_t with _")
    {
        // int_fast16_t with Signed Integers
        REQUIRE(cortex::SubtractableWith<int_least16_t, int>);
        REQUIRE(cortex::SubtractableWith<int_least16_t, short>);
        REQUIRE(cortex::SubtractableWith<int_least16_t, long>);
        REQUIRE(cortex::SubtractableWith<int_least16_t, long long>);

        // int_fast16_t with Unsigned Integers
        REQUIRE(cortex::SubtractableWith<int_least16_t, unsigned>);
        REQUIRE(cortex::SubtractableWith<int_least16_t, unsigned short>);
        REQUIRE(cortex::SubtractableWith<int_least16_t, u_short>);
        REQUIRE(cortex::SubtractableWith<int_least16_t, unsigned long>);
        REQUIRE(cortex::SubtractableWith<int_least16_t, unsigned long long>);
        
        // int_fast16_t with Floating Point and Doubles
        REQUIRE(cortex::SubtractableWith<int_least16_t, float>);
        REQUIRE(cortex::SubtractableWith<int_least16_t, double>);
        REQUIRE(cortex::SubtractableWith<int_least16_t, long double>);

        // int_fast16_t with std::strings and std::string_view
        REQUIRE(!cortex::SubtractableWith<int_least16_t, std::string>);
        REQUIRE(!cortex::SubtractableWith<int_least16_t, std::string_view>);
        REQUIRE(!cortex::SubtractableWith<int_least16_t, std::u8string>);
        REQUIRE(!cortex::SubtractableWith<int_least16_t, std::u16string>);
        REQUIRE(!cortex::SubtractableWith<int_least16_t, std::u32string>);

        // int_fast16_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::SubtractableWith<int_least16_t, std::wstring>);
        REQUIRE(!cortex::SubtractableWith<int_least16_t, std::wstring_view>);

        // int_fast16_t with Charaters
        REQUIRE(cortex::SubtractableWith<int_least16_t, char>);
        REQUIRE(cortex::SubtractableWith<int_least16_t, u_char>);
        REQUIRE(cortex::SubtractableWith<int_least16_t, wchar_t>);

        // int_fast16_t with Bit Specific Characters
        REQUIRE(cortex::SubtractableWith<int_least16_t, char8_t>);
        REQUIRE(cortex::SubtractableWith<int_least16_t, char16_t>);
        REQUIRE(cortex::SubtractableWith<int_least16_t, char32_t>);

        // int_fast16_t with Bit Specific Integers
        REQUIRE(cortex::SubtractableWith<int_least16_t, int8_t>);
        REQUIRE(cortex::SubtractableWith<int_least16_t, int16_t>);
        REQUIRE(cortex::SubtractableWith<int_least16_t, int32_t>);
        REQUIRE(cortex::SubtractableWith<int_least16_t, int64_t>);

        // int_fast16_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::SubtractableWith<int_least16_t, uint8_t>);
        REQUIRE(cortex::SubtractableWith<int_least16_t, uint16_t>);
        REQUIRE(cortex::SubtractableWith<int_least16_t, uint32_t>);
        REQUIRE(cortex::SubtractableWith<int_least16_t, uint64_t>);

        // int_fast16_t with Bit Specific Least Integers
        REQUIRE(cortex::SubtractableWith<int_least16_t, int_least8_t>);
        REQUIRE(cortex::SubtractableWith<int_least16_t, int_least16_t>);
        REQUIRE(cortex::SubtractableWith<int_least16_t, int_least32_t>);
        REQUIRE(cortex::SubtractableWith<int_least16_t, int_least64_t>);
    }

    SECTION("int_least32_t with _")
    {
        // int32 with Signed Integers
        REQUIRE(cortex::SubtractableWith<int_least32_t, int>);
        REQUIRE(cortex::SubtractableWith<int_least32_t, short>);
        REQUIRE(cortex::SubtractableWith<int_least32_t, long>);
        REQUIRE(cortex::SubtractableWith<int_least32_t, long long>);

        // int32 with Unsigned Integers
        REQUIRE(cortex::SubtractableWith<int_least32_t, unsigned>);
        REQUIRE(cortex::SubtractableWith<int_least32_t, unsigned short>);
        REQUIRE(cortex::SubtractableWith<int_least32_t, u_short>);
        REQUIRE(cortex::SubtractableWith<int_least32_t, unsigned long>);
        REQUIRE(cortex::SubtractableWith<int_least32_t, unsigned long long>);
        
        // int32 with Floating Point and Doubles
        REQUIRE(cortex::SubtractableWith<int_least32_t, float>);
        REQUIRE(cortex::SubtractableWith<int_least32_t, double>);
        REQUIRE(cortex::SubtractableWith<int_least32_t, long double>);

        // int32 with std::strings and std::string_view
        REQUIRE(!cortex::SubtractableWith<int_least32_t, std::string>);
        REQUIRE(!cortex::SubtractableWith<int_least32_t, std::string_view>);
        REQUIRE(!cortex::SubtractableWith<int_least32_t, std::u8string>);
        REQUIRE(!cortex::SubtractableWith<int_least32_t, std::u16string>);
        REQUIRE(!cortex::SubtractableWith<int_least32_t, std::u32string>);

        // int32 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::SubtractableWith<int_least32_t, std::wstring>);
        REQUIRE(!cortex::SubtractableWith<int_least32_t, std::wstring_view>);

        // int_fast32_t with Charaters
        REQUIRE(cortex::SubtractableWith<int_least32_t, char>);
        REQUIRE(cortex::SubtractableWith<int_least32_t, u_char>);
        REQUIRE(cortex::SubtractableWith<int_least32_t, wchar_t>);

        // int_fast32_t with Bit Specific Characters
        REQUIRE(cortex::SubtractableWith<int_least32_t, char8_t>);
        REQUIRE(cortex::SubtractableWith<int_least32_t, char16_t>);
        REQUIRE(cortex::SubtractableWith<int_least32_t, char32_t>);

        // int_fast32_t with Bit Specific Integers
        REQUIRE(cortex::SubtractableWith<int_least32_t, int8_t>);
        REQUIRE(cortex::SubtractableWith<int_least32_t, int16_t>);
        REQUIRE(cortex::SubtractableWith<int_least32_t, int32_t>);
        REQUIRE(cortex::SubtractableWith<int_least32_t, int64_t>);

        // int_fast32_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::SubtractableWith<int_least32_t, uint8_t>);
        REQUIRE(cortex::SubtractableWith<int_least32_t, uint16_t>);
        REQUIRE(cortex::SubtractableWith<int_least32_t, uint32_t>);
        REQUIRE(cortex::SubtractableWith<int_least32_t, uint64_t>);

        // int_fast32_t with Bit Specific Least Integers
        REQUIRE(cortex::SubtractableWith<int_least32_t, int_least8_t>);
        REQUIRE(cortex::SubtractableWith<int_least32_t, int_least16_t>);
        REQUIRE(cortex::SubtractableWith<int_least32_t, int_least32_t>);
        REQUIRE(cortex::SubtractableWith<int_least32_t, int_least64_t>);
    }

    SECTION("int_least64_t with _")
    {
        // int64 with Signed Integers
        REQUIRE(cortex::SubtractableWith<int_least64_t, int>);
        REQUIRE(cortex::SubtractableWith<int_least64_t, short>);
        REQUIRE(cortex::SubtractableWith<int_least64_t, long>);
        REQUIRE(cortex::SubtractableWith<int_least64_t, long long>);

        // int64 with Unsigned Integers
        REQUIRE(cortex::SubtractableWith<int_least64_t, unsigned>);
        REQUIRE(cortex::SubtractableWith<int_least64_t, unsigned short>);
        REQUIRE(cortex::SubtractableWith<int_least64_t, u_short>);
        REQUIRE(cortex::SubtractableWith<int_least64_t, unsigned long>);
        REQUIRE(cortex::SubtractableWith<int_least64_t, unsigned long long>);
        
        // int64 with Floating Point and Doubles
        REQUIRE(cortex::SubtractableWith<int_least64_t, float>);
        REQUIRE(cortex::SubtractableWith<int_least64_t, double>);
        REQUIRE(cortex::SubtractableWith<int_least64_t, long double>);

        // int64 with std::strings and std::string_view
        REQUIRE(!cortex::SubtractableWith<int_least64_t, std::string>);
        REQUIRE(!cortex::SubtractableWith<int_least64_t, std::string_view>);
        REQUIRE(!cortex::SubtractableWith<int_least64_t, std::u8string>);
        REQUIRE(!cortex::SubtractableWith<int_least64_t, std::u16string>);
        REQUIRE(!cortex::SubtractableWith<int_least64_t, std::u32string>);

        // int64 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::SubtractableWith<int_least64_t, std::wstring>);
        REQUIRE(!cortex::SubtractableWith<int_least64_t, std::wstring_view>);

        // int_fast64_t with Charaters
        REQUIRE(cortex::SubtractableWith<int_least64_t, char>);
        REQUIRE(cortex::SubtractableWith<int_least64_t, u_char>);
        REQUIRE(cortex::SubtractableWith<int_least64_t, wchar_t>);

        // int_fast64_t with Bit Specific Characters
        REQUIRE(cortex::SubtractableWith<int_least64_t, char8_t>);
        REQUIRE(cortex::SubtractableWith<int_least64_t, char16_t>);
        REQUIRE(cortex::SubtractableWith<int_least64_t, char32_t>);

        // int_fast64_t with Bit Specific Integers
        REQUIRE(cortex::SubtractableWith<int_least64_t, int8_t>);
        REQUIRE(cortex::SubtractableWith<int_least64_t, int16_t>);
        REQUIRE(cortex::SubtractableWith<int_least64_t, int32_t>);
        REQUIRE(cortex::SubtractableWith<int_least64_t, int64_t>);

        // int_fast64_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::SubtractableWith<int_least64_t, uint8_t>);
        REQUIRE(cortex::SubtractableWith<int_least64_t, uint16_t>);
        REQUIRE(cortex::SubtractableWith<int_least64_t, uint32_t>);
        REQUIRE(cortex::SubtractableWith<int_least64_t, uint64_t>);

        // int_fast64_t with Bit Specific Least Integers
        REQUIRE(cortex::SubtractableWith<int_least64_t, int_least8_t>);
        REQUIRE(cortex::SubtractableWith<int_least64_t, int_least16_t>);
        REQUIRE(cortex::SubtractableWith<int_least64_t, int_least32_t>);
        REQUIRE(cortex::SubtractableWith<int_least64_t, int_least64_t>);
    }
}