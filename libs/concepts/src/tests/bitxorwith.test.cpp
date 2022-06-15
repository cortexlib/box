#include <catch2/catch.hpp>
#include <concepts.hpp>

TEST_CASE("BitXorWith : Signed Integers")
{
    SECTION("Int with _")
    {
        // Int with Signed Integers
        REQUIRE(cortex::BitXorWith<int, int>);
        REQUIRE(cortex::BitXorWith<int, short>);
        REQUIRE(cortex::BitXorWith<int, long>);
        REQUIRE(cortex::BitXorWith<int, long long>);

        // Int with Unsigned Integers
        REQUIRE(cortex::BitXorWith<int, unsigned>);
        REQUIRE(cortex::BitXorWith<int, unsigned short>);
        REQUIRE(cortex::BitXorWith<int, u_short>);
        REQUIRE(cortex::BitXorWith<int, unsigned long>);
        REQUIRE(cortex::BitXorWith<int, unsigned long long>);
        
        // Integers with Floating Point and Doubles
        REQUIRE(!cortex::BitXorWith<int, float>);
        REQUIRE(!cortex::BitXorWith<int, double>);
        REQUIRE(!cortex::BitXorWith<int, long double>);

        // Integers with std::strings and std::string_view
        REQUIRE(!cortex::BitXorWith<int, std::string>);
        REQUIRE(!cortex::BitXorWith<int, std::string_view>);
        REQUIRE(!cortex::BitXorWith<int, std::u8string>);
        REQUIRE(!cortex::BitXorWith<int, std::u16string>);
        REQUIRE(!cortex::BitXorWith<int, std::u32string>);

        // Integers with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitXorWith<int, std::wstring>);
        REQUIRE(!cortex::BitXorWith<int, std::wstring_view>);

        // Integers with Charaters
        REQUIRE(cortex::BitXorWith<int, char>);
        REQUIRE(cortex::BitXorWith<int, u_char>);
        REQUIRE(cortex::BitXorWith<int, wchar_t>);

        // Integers with Bit Specific Characters
        REQUIRE(cortex::BitXorWith<int, char8_t>);
        REQUIRE(cortex::BitXorWith<int, char16_t>);
        REQUIRE(cortex::BitXorWith<int, char32_t>);

        // Integers with Bit Specific Integers
        REQUIRE(cortex::BitXorWith<int, int8_t>);
        REQUIRE(cortex::BitXorWith<int, int16_t>);
        REQUIRE(cortex::BitXorWith<int, int32_t>);
        REQUIRE(cortex::BitXorWith<int, int64_t>);

        // Integers with Bit Specific Unsigned Integers
        REQUIRE(cortex::BitXorWith<int, uint8_t>);
        REQUIRE(cortex::BitXorWith<int, uint16_t>);
        REQUIRE(cortex::BitXorWith<int, uint32_t>);
        REQUIRE(cortex::BitXorWith<int, uint64_t>);

        // Integers with Bit Specific Least Integers
        REQUIRE(cortex::BitXorWith<int, int_least8_t>);
        REQUIRE(cortex::BitXorWith<int, int_least16_t>);
        REQUIRE(cortex::BitXorWith<int, int_least32_t>);
        REQUIRE(cortex::BitXorWith<int, int_least64_t>);
    }

    SECTION("Short with _")
    {
        // Short with Signed Integers
        REQUIRE(cortex::BitXorWith<short, int>);
        REQUIRE(cortex::BitXorWith<short, short>);
        REQUIRE(cortex::BitXorWith<short, long>);
        REQUIRE(cortex::BitXorWith<short, long long>);

        // Short with Unsigned Integers
        REQUIRE(cortex::BitXorWith<short, unsigned>);
        REQUIRE(cortex::BitXorWith<short, unsigned short>);
        REQUIRE(cortex::BitXorWith<short, u_short>);
        REQUIRE(cortex::BitXorWith<short, unsigned long>);
        REQUIRE(cortex::BitXorWith<short, unsigned long long>);
        
        // Short with Floating Point and Doubles
        REQUIRE(!cortex::BitXorWith<short, float>);
        REQUIRE(!cortex::BitXorWith<short, double>);
        REQUIRE(!cortex::BitXorWith<short, long double>);

        // Short with std::strings and std::string_view
        REQUIRE(!cortex::BitXorWith<short, std::string>);
        REQUIRE(!cortex::BitXorWith<short, std::string_view>);
        REQUIRE(!cortex::BitXorWith<short, std::u8string>);
        REQUIRE(!cortex::BitXorWith<short, std::u16string>);
        REQUIRE(!cortex::BitXorWith<short, std::u32string>);

        // Short with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitXorWith<short, std::wstring>);
        REQUIRE(!cortex::BitXorWith<short, std::wstring_view>);

        // Short with Charaters
        REQUIRE(cortex::BitXorWith<short, char>);
        REQUIRE(cortex::BitXorWith<short, u_char>);
        REQUIRE(cortex::BitXorWith<short, wchar_t>);

        // Short with Bit Specific Characters
        REQUIRE(cortex::BitXorWith<short, char8_t>);
        REQUIRE(cortex::BitXorWith<short, char16_t>);
        REQUIRE(cortex::BitXorWith<short, char32_t>);

        // Short with Bit Specific Short
        REQUIRE(cortex::BitXorWith<short, int8_t>);
        REQUIRE(cortex::BitXorWith<short, int16_t>);
        REQUIRE(cortex::BitXorWith<short, int32_t>);
        REQUIRE(cortex::BitXorWith<short, int64_t>);

        // Short with Bit Specific Unsigned Short
        REQUIRE(cortex::BitXorWith<short, uint8_t>);
        REQUIRE(cortex::BitXorWith<short, uint16_t>);
        REQUIRE(cortex::BitXorWith<short, uint32_t>);
        REQUIRE(cortex::BitXorWith<short, uint64_t>);

        // Short with Bit Specific Least Integers
        REQUIRE(cortex::BitXorWith<short, int_least8_t>);
        REQUIRE(cortex::BitXorWith<short, int_least16_t>);
        REQUIRE(cortex::BitXorWith<short, int_least32_t>);
        REQUIRE(cortex::BitXorWith<short, int_least64_t>);
    }

    SECTION("Long with _")
    {
        // Long with Signed Integers
        REQUIRE(cortex::BitXorWith<long, int>);
        REQUIRE(cortex::BitXorWith<long, short>);
        REQUIRE(cortex::BitXorWith<long, long>);
        REQUIRE(cortex::BitXorWith<long, long long>);

        // Long with Unsigned Integers
        REQUIRE(cortex::BitXorWith<long, unsigned>);
        REQUIRE(cortex::BitXorWith<long, unsigned short>);
        REQUIRE(cortex::BitXorWith<long, u_short>);
        REQUIRE(cortex::BitXorWith<long, unsigned long>);
        REQUIRE(cortex::BitXorWith<long, unsigned long long>);
        
        // Long with Floating Point and Doubles
        REQUIRE(!cortex::BitXorWith<long, float>);
        REQUIRE(!cortex::BitXorWith<long, double>);
        REQUIRE(!cortex::BitXorWith<long, long double>);

        // Long with std::strings and std::string_view
        REQUIRE(!cortex::BitXorWith<long, std::string>);
        REQUIRE(!cortex::BitXorWith<long, std::string_view>);
        REQUIRE(!cortex::BitXorWith<long, std::u8string>);
        REQUIRE(!cortex::BitXorWith<long, std::u16string>);
        REQUIRE(!cortex::BitXorWith<long, std::u32string>);

        // Long with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitXorWith<long, std::wstring>);
        REQUIRE(!cortex::BitXorWith<long, std::wstring_view>);

        // Long with Charaters
        REQUIRE(cortex::BitXorWith<long, char>);
        REQUIRE(cortex::BitXorWith<long, u_char>);
        REQUIRE(cortex::BitXorWith<long, wchar_t>);

        // Long with Bit Specific Characters
        REQUIRE(cortex::BitXorWith<long, char8_t>);
        REQUIRE(cortex::BitXorWith<long, char16_t>);
        REQUIRE(cortex::BitXorWith<long, char32_t>);

        // Long with Bit Specific Long
        REQUIRE(cortex::BitXorWith<long, int8_t>);
        REQUIRE(cortex::BitXorWith<long, int16_t>);
        REQUIRE(cortex::BitXorWith<long, int32_t>);
        REQUIRE(cortex::BitXorWith<long, int64_t>);

        // Long with Bit Specific Unsigned Long
        REQUIRE(cortex::BitXorWith<long, uint8_t>);
        REQUIRE(cortex::BitXorWith<long, uint16_t>);
        REQUIRE(cortex::BitXorWith<long, uint32_t>);
        REQUIRE(cortex::BitXorWith<long, uint64_t>);

        // Long with Bit Specific Least Integers
        REQUIRE(cortex::BitXorWith<long, int_least8_t>);
        REQUIRE(cortex::BitXorWith<long, int_least16_t>);
        REQUIRE(cortex::BitXorWith<long, int_least32_t>);
        REQUIRE(cortex::BitXorWith<long, int_least64_t>);
    }

    SECTION("Long Long with _")
    {
        // Signed Integers
        REQUIRE(cortex::BitXorWith<long long, int>);
        REQUIRE(cortex::BitXorWith<long long, short>);
        REQUIRE(cortex::BitXorWith<long long, long>);
        REQUIRE(cortex::BitXorWith<long long, long long>);

        // Unsigned Integers
        REQUIRE(cortex::BitXorWith<long long, unsigned>);
        REQUIRE(cortex::BitXorWith<long long, unsigned short>);
        REQUIRE(cortex::BitXorWith<long long, u_short>);
        REQUIRE(cortex::BitXorWith<long long, unsigned long>);
        REQUIRE(cortex::BitXorWith<long long, unsigned long long>);
        
        // Integers with Floating Point and Doubles
        REQUIRE(!cortex::BitXorWith<long long, float>);
        REQUIRE(!cortex::BitXorWith<long long, double>);
        REQUIRE(!cortex::BitXorWith<long long, long double>);

        // Integers with std::strings and std::string_view
        REQUIRE(!cortex::BitXorWith<long long, std::string>);
        REQUIRE(!cortex::BitXorWith<long long, std::string_view>);
        REQUIRE(!cortex::BitXorWith<long long, std::u8string>);
        REQUIRE(!cortex::BitXorWith<long long, std::u16string>);
        REQUIRE(!cortex::BitXorWith<long long, std::u32string>);

        // Integers with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitXorWith<long long, std::wstring>);
        REQUIRE(!cortex::BitXorWith<long long, std::wstring_view>);

        // Integers with Charaters
        REQUIRE(cortex::BitXorWith<long long, char>);
        REQUIRE(cortex::BitXorWith<long long, u_char>);
        REQUIRE(cortex::BitXorWith<long long, wchar_t>);

        // Integers with Bit Specific Characters
        REQUIRE(cortex::BitXorWith<long long, char8_t>);
        REQUIRE(cortex::BitXorWith<long long, char16_t>);
        REQUIRE(cortex::BitXorWith<long long, char32_t>);

        // Integers with Bit Specific Integers
        REQUIRE(cortex::BitXorWith<long long, int8_t>);
        REQUIRE(cortex::BitXorWith<long long, int16_t>);
        REQUIRE(cortex::BitXorWith<long long, int32_t>);
        REQUIRE(cortex::BitXorWith<long long, int64_t>);

        // Integers with Bit Specific Unsigned Integers
        REQUIRE(cortex::BitXorWith<long long, uint8_t>);
        REQUIRE(cortex::BitXorWith<long long, uint16_t>);
        REQUIRE(cortex::BitXorWith<long long, uint32_t>);
        REQUIRE(cortex::BitXorWith<long long, uint64_t>);

        // Long Long with Bit Specific Least Integers
        REQUIRE(cortex::BitXorWith<long long, int_least8_t>);
        REQUIRE(cortex::BitXorWith<long long, int_least16_t>);
        REQUIRE(cortex::BitXorWith<long long, int_least32_t>);
        REQUIRE(cortex::BitXorWith<long long, int_least64_t>);
    }
}

TEST_CASE("BitXorWith: Unsigned Integers")
{
    SECTION("Unsigned Int with _")
    {
        // Unsigned Integers with Signed Integers
        REQUIRE(cortex::BitXorWith<unsigned int, int>);
        REQUIRE(cortex::BitXorWith<unsigned int, short>);
        REQUIRE(cortex::BitXorWith<unsigned int, long>);
        REQUIRE(cortex::BitXorWith<unsigned int, long long>);

        // Unsigned Integers with Unsigned Integers
        REQUIRE(cortex::BitXorWith<unsigned int, unsigned>);
        REQUIRE(cortex::BitXorWith<unsigned int, unsigned short>);
        REQUIRE(cortex::BitXorWith<unsigned int, u_short>);
        REQUIRE(cortex::BitXorWith<unsigned int, unsigned long>);
        REQUIRE(cortex::BitXorWith<unsigned int, unsigned long long>);
        
        // Unsigned Integers with Floating Point and Doubles
        REQUIRE(!cortex::BitXorWith<unsigned int, float>);
        REQUIRE(!cortex::BitXorWith<unsigned int, double>);
        REQUIRE(!cortex::BitXorWith<unsigned int, long double>);

        // Unsigned Integers with std::strings and std::string_view
        REQUIRE(!cortex::BitXorWith<unsigned int, std::string>);
        REQUIRE(!cortex::BitXorWith<unsigned int, std::string_view>);
        REQUIRE(!cortex::BitXorWith<unsigned int, std::u8string>);
        REQUIRE(!cortex::BitXorWith<unsigned int, std::u16string>);
        REQUIRE(!cortex::BitXorWith<unsigned int, std::u32string>);

        // Unsigned Integers with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitXorWith<unsigned long long, std::wstring>);
        REQUIRE(!cortex::BitXorWith<unsigned long long, std::wstring_view>);

        // Unsigned Integers with Charaters
        REQUIRE(cortex::BitXorWith<unsigned int, char>);
        REQUIRE(cortex::BitXorWith<unsigned int, u_char>);
        REQUIRE(cortex::BitXorWith<unsigned int, wchar_t>);

        // Unsigned Integers with Bit Specific Characters
        REQUIRE(cortex::BitXorWith<unsigned int, char8_t>);
        REQUIRE(cortex::BitXorWith<unsigned int, char16_t>);
        REQUIRE(cortex::BitXorWith<unsigned int, char32_t>);

        // Unsigned Integers with Bit Specific Integers
        REQUIRE(cortex::BitXorWith<unsigned int, int8_t>);
        REQUIRE(cortex::BitXorWith<unsigned int, int16_t>);
        REQUIRE(cortex::BitXorWith<unsigned int, int32_t>);
        REQUIRE(cortex::BitXorWith<unsigned int, int64_t>);

        // Unsigned Integers with Bit Specific Unsigned Integers
        REQUIRE(cortex::BitXorWith<unsigned int, uint8_t>);
        REQUIRE(cortex::BitXorWith<unsigned int, uint16_t>);
        REQUIRE(cortex::BitXorWith<unsigned int, uint32_t>);
        REQUIRE(cortex::BitXorWith<unsigned int, uint64_t>);

        // Unsigned Integers with Bit Specific Least Integers
        REQUIRE(cortex::BitXorWith<unsigned int, int_least8_t>);
        REQUIRE(cortex::BitXorWith<unsigned int, int_least16_t>);
        REQUIRE(cortex::BitXorWith<unsigned int, int_least32_t>);
        REQUIRE(cortex::BitXorWith<unsigned int, int_least64_t>);
    }

    SECTION("Unsigned Short with _")
    {
        // Unsigned Short with Signed Integers
        REQUIRE(cortex::BitXorWith<unsigned short, int>);
        REQUIRE(cortex::BitXorWith<unsigned short, short>);
        REQUIRE(cortex::BitXorWith<unsigned short, long>);
        REQUIRE(cortex::BitXorWith<unsigned short, long long>);

        // Unsigned Short with Unsigned Integers
        REQUIRE(cortex::BitXorWith<unsigned short, unsigned>);
        REQUIRE(cortex::BitXorWith<unsigned short, unsigned short>);
        REQUIRE(cortex::BitXorWith<unsigned short, u_short>);
        REQUIRE(cortex::BitXorWith<unsigned short, unsigned long>);
        REQUIRE(cortex::BitXorWith<unsigned short, unsigned long long>);
        
        // Unsigned Short with Floating Point and Doubles
        REQUIRE(!cortex::BitXorWith<unsigned short, float>);
        REQUIRE(!cortex::BitXorWith<unsigned short, double>);
        REQUIRE(!cortex::BitXorWith<unsigned short, long double>);

        // Unsigned Short with std::strings and std::string_view
        REQUIRE(!cortex::BitXorWith<unsigned short, std::string>);
        REQUIRE(!cortex::BitXorWith<unsigned short, std::string_view>);
        REQUIRE(!cortex::BitXorWith<unsigned short, std::u8string>);
        REQUIRE(!cortex::BitXorWith<unsigned short, std::u16string>);
        REQUIRE(!cortex::BitXorWith<unsigned short, std::u32string>);

        // Unsigned Short with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitXorWith<unsigned short, std::wstring>);
        REQUIRE(!cortex::BitXorWith<unsigned short, std::wstring_view>);

        // Unsigned Short with Charaters
        REQUIRE(cortex::BitXorWith<unsigned short, char>);
        REQUIRE(cortex::BitXorWith<unsigned short, u_char>);
        REQUIRE(cortex::BitXorWith<unsigned short, wchar_t>);

        // Unsigned Short with Bit Specific Characters
        REQUIRE(cortex::BitXorWith<unsigned short, char8_t>);
        REQUIRE(cortex::BitXorWith<unsigned short, char16_t>);
        REQUIRE(cortex::BitXorWith<unsigned short, char32_t>);

        // Unsigned Short with Bit Specific Short
        REQUIRE(cortex::BitXorWith<unsigned short, int8_t>);
        REQUIRE(cortex::BitXorWith<unsigned short, int16_t>);
        REQUIRE(cortex::BitXorWith<unsigned short, int32_t>);
        REQUIRE(cortex::BitXorWith<unsigned short, int64_t>);

        // Unsigned Short with Bit Specific Unsigned Short
        REQUIRE(cortex::BitXorWith<unsigned short, uint8_t>);
        REQUIRE(cortex::BitXorWith<unsigned short, uint16_t>);
        REQUIRE(cortex::BitXorWith<unsigned short, uint32_t>);
        REQUIRE(cortex::BitXorWith<unsigned short, uint64_t>);

        // Unsigned Short with Bit Specific Least Integers
        REQUIRE(cortex::BitXorWith<unsigned short, int_least8_t>);
        REQUIRE(cortex::BitXorWith<unsigned short, int_least16_t>);
        REQUIRE(cortex::BitXorWith<unsigned short, int_least32_t>);
        REQUIRE(cortex::BitXorWith<unsigned short, int_least64_t>);
    }

    SECTION("u_short with _")
    {
        // u_short with Signed Integers
        REQUIRE(cortex::BitXorWith<u_short, int>);
        REQUIRE(cortex::BitXorWith<u_short, short>);
        REQUIRE(cortex::BitXorWith<u_short, long>);
        REQUIRE(cortex::BitXorWith<u_short, long long>);

        // u_short with Unsigned Integers
        REQUIRE(cortex::BitXorWith<u_short, unsigned>);
        REQUIRE(cortex::BitXorWith<u_short, unsigned short>);
        REQUIRE(cortex::BitXorWith<u_short, u_short>);
        REQUIRE(cortex::BitXorWith<u_short, unsigned long>);
        REQUIRE(cortex::BitXorWith<u_short, unsigned long long>);
        
        // u_short with Floating Point and Doubles
        REQUIRE(!cortex::BitXorWith<u_short, float>);
        REQUIRE(!cortex::BitXorWith<u_short, double>);
        REQUIRE(!cortex::BitXorWith<u_short, long double>);

        // u_short with std::strings and std::string_view
        REQUIRE(!cortex::BitXorWith<u_short, std::string>);
        REQUIRE(!cortex::BitXorWith<u_short, std::string_view>);
        REQUIRE(!cortex::BitXorWith<u_short, std::u8string>);
        REQUIRE(!cortex::BitXorWith<u_short, std::u16string>);
        REQUIRE(!cortex::BitXorWith<u_short, std::u32string>);

        // u_short with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitXorWith<u_short, std::wstring>);
        REQUIRE(!cortex::BitXorWith<u_short, std::wstring_view>);

        // u_short with Charaters
        REQUIRE(cortex::BitXorWith<u_short, char>);
        REQUIRE(cortex::BitXorWith<u_short, u_char>);
        REQUIRE(cortex::BitXorWith<u_short, wchar_t>);

        // u_short with Bit Specific Characters
        REQUIRE(cortex::BitXorWith<u_short, char8_t>);
        REQUIRE(cortex::BitXorWith<u_short, char16_t>);
        REQUIRE(cortex::BitXorWith<u_short, char32_t>);

        // u_short with Bit Specific Short
        REQUIRE(cortex::BitXorWith<u_short, int8_t>);
        REQUIRE(cortex::BitXorWith<u_short, int16_t>);
        REQUIRE(cortex::BitXorWith<u_short, int32_t>);
        REQUIRE(cortex::BitXorWith<u_short, int64_t>);

        // u_short with Bit Specific Unsigned Short
        REQUIRE(cortex::BitXorWith<u_short, uint8_t>);
        REQUIRE(cortex::BitXorWith<u_short, uint16_t>);
        REQUIRE(cortex::BitXorWith<u_short, uint32_t>);
        REQUIRE(cortex::BitXorWith<u_short, uint64_t>);

        // u_short with Bit Specific Least Integers
        REQUIRE(cortex::BitXorWith<u_short, int_least8_t>);
        REQUIRE(cortex::BitXorWith<u_short, int_least16_t>);
        REQUIRE(cortex::BitXorWith<u_short, int_least32_t>);
        REQUIRE(cortex::BitXorWith<u_short, int_least64_t>);
    }

    SECTION("Unsigned Long with _")
    {
        // Unsigned Long with Signed Integers
        REQUIRE(cortex::BitXorWith<unsigned long, int>);
        REQUIRE(cortex::BitXorWith<unsigned long, short>);
        REQUIRE(cortex::BitXorWith<unsigned long, long>);
        REQUIRE(cortex::BitXorWith<unsigned long, long long>);

        // Unsigned Long with Unsigned Integers
        REQUIRE(cortex::BitXorWith<unsigned long, unsigned>);
        REQUIRE(cortex::BitXorWith<unsigned long, unsigned short>);
        REQUIRE(cortex::BitXorWith<unsigned long, u_short>);
        REQUIRE(cortex::BitXorWith<unsigned long, unsigned long>);
        REQUIRE(cortex::BitXorWith<unsigned long, unsigned long long>);
        
        // Unsigned Long with Floating Point and Doubles
        REQUIRE(!cortex::BitXorWith<unsigned long, float>);
        REQUIRE(!cortex::BitXorWith<unsigned long, double>);
        REQUIRE(!cortex::BitXorWith<unsigned long, long double>);

        // Unsigned Long with std::strings and std::string_view
        REQUIRE(!cortex::BitXorWith<unsigned long, std::string>);
        REQUIRE(!cortex::BitXorWith<unsigned long, std::string_view>);
        REQUIRE(!cortex::BitXorWith<unsigned long, std::u8string>);
        REQUIRE(!cortex::BitXorWith<unsigned long, std::u16string>);
        REQUIRE(!cortex::BitXorWith<unsigned long, std::u32string>);

        // Unsigned Long with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitXorWith<unsigned long, std::wstring>);
        REQUIRE(!cortex::BitXorWith<unsigned long, std::wstring_view>);

        // Unsigned Long with Charaters
        REQUIRE(cortex::BitXorWith<unsigned long, char>);
        REQUIRE(cortex::BitXorWith<unsigned long, u_char>);
        REQUIRE(cortex::BitXorWith<unsigned long, wchar_t>);

        // Unsigned Long with Bit Specific Characters
        REQUIRE(cortex::BitXorWith<unsigned long, char8_t>);
        REQUIRE(cortex::BitXorWith<unsigned long, char16_t>);
        REQUIRE(cortex::BitXorWith<unsigned long, char32_t>);

        // Unsigned Long with Bit Specific Long
        REQUIRE(cortex::BitXorWith<unsigned long, int8_t>);
        REQUIRE(cortex::BitXorWith<unsigned long, int16_t>);
        REQUIRE(cortex::BitXorWith<unsigned long, int32_t>);
        REQUIRE(cortex::BitXorWith<unsigned long, int64_t>);

        // Unsigned Long with Bit Specific Unsigned Long
        REQUIRE(cortex::BitXorWith<unsigned long, uint8_t>);
        REQUIRE(cortex::BitXorWith<unsigned long, uint16_t>);
        REQUIRE(cortex::BitXorWith<unsigned long, uint32_t>);
        REQUIRE(cortex::BitXorWith<unsigned long, uint64_t>);

        // Unsigned Long with Bit Specific Least Integers
        REQUIRE(cortex::BitXorWith<unsigned long, int_least8_t>);
        REQUIRE(cortex::BitXorWith<unsigned long, int_least16_t>);
        REQUIRE(cortex::BitXorWith<unsigned long, int_least32_t>);
        REQUIRE(cortex::BitXorWith<unsigned long, int_least64_t>);
    }

    SECTION("Unsigned Long Long with _")
    {
        // Unsigned Long Long with Signed Integers
        REQUIRE(cortex::BitXorWith<unsigned long long, int>);
        REQUIRE(cortex::BitXorWith<unsigned long long, short>);
        REQUIRE(cortex::BitXorWith<unsigned long long, long>);
        REQUIRE(cortex::BitXorWith<unsigned long long, long long>);

        // Unsigned Long Long with Unsigned Integers
        REQUIRE(cortex::BitXorWith<unsigned long long, unsigned>);
        REQUIRE(cortex::BitXorWith<unsigned long long, unsigned short>);
        REQUIRE(cortex::BitXorWith<unsigned long long, u_short>);
        REQUIRE(cortex::BitXorWith<unsigned long long, unsigned long>);
        REQUIRE(cortex::BitXorWith<unsigned long long, unsigned long long>);
        
        // Unsigned Long Long with Floating Point and Doubles
        REQUIRE(!cortex::BitXorWith<unsigned long long, float>);
        REQUIRE(!cortex::BitXorWith<unsigned long long, double>);
        REQUIRE(!cortex::BitXorWith<unsigned long long, long double>);

        // Unsigned Long Long with std::strings and std::string_view
        REQUIRE(!cortex::BitXorWith<unsigned long long, std::string>);
        REQUIRE(!cortex::BitXorWith<unsigned long long, std::string_view>);
        REQUIRE(!cortex::BitXorWith<unsigned long long, std::u8string>);
        REQUIRE(!cortex::BitXorWith<unsigned long long, std::u16string>);
        REQUIRE(!cortex::BitXorWith<unsigned long long, std::u32string>);

        // Unsigned Long Long with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitXorWith<unsigned long long, std::wstring>);
        REQUIRE(!cortex::BitXorWith<unsigned long long, std::wstring_view>);

        // Unsigned Long Long with Charaters
        REQUIRE(cortex::BitXorWith<unsigned long long, char>);
        REQUIRE(cortex::BitXorWith<unsigned long long, u_char>);
        REQUIRE(cortex::BitXorWith<unsigned long long, wchar_t>);

        // Unsigned Long Long with Bit Specific Characters
        REQUIRE(cortex::BitXorWith<unsigned long long, char8_t>);
        REQUIRE(cortex::BitXorWith<unsigned long long, char16_t>);
        REQUIRE(cortex::BitXorWith<unsigned long long, char32_t>);

        // Unsigned Long Long with Bit Specific Long Long
        REQUIRE(cortex::BitXorWith<unsigned long long, int8_t>);
        REQUIRE(cortex::BitXorWith<unsigned long long, int16_t>);
        REQUIRE(cortex::BitXorWith<unsigned long long, int32_t>);
        REQUIRE(cortex::BitXorWith<unsigned long long, int64_t>);

        // Unsigned Long Long with Bit Specific Unsigned Long Long
        REQUIRE(cortex::BitXorWith<unsigned long long, uint8_t>);
        REQUIRE(cortex::BitXorWith<unsigned long long, uint16_t>);
        REQUIRE(cortex::BitXorWith<unsigned long long, uint32_t>);
        REQUIRE(cortex::BitXorWith<unsigned long long, uint64_t>);

        // Long Long with Bit Specific Least Long Long
        REQUIRE(cortex::BitXorWith<unsigned long long, int_least8_t>);
        REQUIRE(cortex::BitXorWith<unsigned long long, int_least16_t>);
        REQUIRE(cortex::BitXorWith<unsigned long long, int_least32_t>);
        REQUIRE(cortex::BitXorWith<unsigned long long, int_least64_t>);
    }
}

TEST_CASE("Addable With : Bit Specific Signed Integers")
{
    SECTION("int8_t with _")
    {
        // int8_t with Signed Integers
        REQUIRE(cortex::BitXorWith<int8_t, int>);
        REQUIRE(cortex::BitXorWith<int8_t, short>);
        REQUIRE(cortex::BitXorWith<int8_t, long>);
        REQUIRE(cortex::BitXorWith<int8_t, long long>);

        // int8_t with Unsigned Integers
        REQUIRE(cortex::BitXorWith<int8_t, unsigned>);
        REQUIRE(cortex::BitXorWith<int8_t, unsigned short>);
        REQUIRE(cortex::BitXorWith<int8_t, u_short>);
        REQUIRE(cortex::BitXorWith<int8_t, unsigned long>);
        REQUIRE(cortex::BitXorWith<int8_t, unsigned long long>);
        
        // int8_t with Floating Point and Doubles
        REQUIRE(!cortex::BitXorWith<int8_t, float>);
        REQUIRE(!cortex::BitXorWith<int8_t, double>);
        REQUIRE(!cortex::BitXorWith<int8_t, long double>);

        // int8_t with std::strings and std::string_view
        REQUIRE(!cortex::BitXorWith<int8_t, std::string>);
        REQUIRE(!cortex::BitXorWith<int8_t, std::string_view>);
        REQUIRE(!cortex::BitXorWith<int8_t, std::u8string>);
        REQUIRE(!cortex::BitXorWith<int8_t, std::u16string>);
        REQUIRE(!cortex::BitXorWith<int8_t, std::u32string>);

        // int8_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitXorWith<long long, std::wstring>);
        REQUIRE(!cortex::BitXorWith<long long, std::wstring_view>);

        // int8_t with Charaters
        REQUIRE(cortex::BitXorWith<int8_t, char>);
        REQUIRE(cortex::BitXorWith<int8_t, u_char>);
        REQUIRE(cortex::BitXorWith<int8_t, wchar_t>);

        // int8_t with Bit Specific Characters
        REQUIRE(cortex::BitXorWith<int8_t, char8_t>);
        REQUIRE(cortex::BitXorWith<int8_t, char16_t>);
        REQUIRE(cortex::BitXorWith<int8_t, char32_t>);

        // int8_t with Bit Specific Integers
        REQUIRE(cortex::BitXorWith<int8_t, int8_t>);
        REQUIRE(cortex::BitXorWith<int8_t, int16_t>);
        REQUIRE(cortex::BitXorWith<int8_t, int32_t>);
        REQUIRE(cortex::BitXorWith<int8_t, int64_t>);

        // int8_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::BitXorWith<int8_t, uint8_t>);
        REQUIRE(cortex::BitXorWith<int8_t, uint16_t>);
        REQUIRE(cortex::BitXorWith<int8_t, uint32_t>);
        REQUIRE(cortex::BitXorWith<int8_t, uint64_t>);

        // int8_t with Bit Specific Least Integers
        REQUIRE(cortex::BitXorWith<int8_t, int_least8_t>);
        REQUIRE(cortex::BitXorWith<int8_t, int_least16_t>);
        REQUIRE(cortex::BitXorWith<int8_t, int_least32_t>);
        REQUIRE(cortex::BitXorWith<int8_t, int_least64_t>);
    }

    SECTION("int16_t with _")
    {
        // int16_t with Signed Integers
        REQUIRE(cortex::BitXorWith<int16_t, int>);
        REQUIRE(cortex::BitXorWith<int16_t, short>);
        REQUIRE(cortex::BitXorWith<int16_t, long>);
        REQUIRE(cortex::BitXorWith<int16_t, long long>);

        // int16_t with Unsigned Integers
        REQUIRE(cortex::BitXorWith<int16_t, unsigned>);
        REQUIRE(cortex::BitXorWith<int16_t, unsigned short>);
        REQUIRE(cortex::BitXorWith<int16_t, u_short>);
        REQUIRE(cortex::BitXorWith<int16_t, unsigned long>);
        REQUIRE(cortex::BitXorWith<int16_t, unsigned long long>);
        
        // int16_t with Floating Point and Doubles
        REQUIRE(!cortex::BitXorWith<int16_t, float>);
        REQUIRE(!cortex::BitXorWith<int16_t, double>);
        REQUIRE(!cortex::BitXorWith<int16_t, long double>);

        // int16_t with std::strings and std::string_view
        REQUIRE(!cortex::BitXorWith<int16_t, std::string>);
        REQUIRE(!cortex::BitXorWith<int16_t, std::string_view>);
        REQUIRE(!cortex::BitXorWith<int16_t, std::u8string>);
        REQUIRE(!cortex::BitXorWith<int16_t, std::u16string>);
        REQUIRE(!cortex::BitXorWith<int16_t, std::u32string>);

        // int16_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitXorWith<int16_t, std::wstring>);
        REQUIRE(!cortex::BitXorWith<int16_t, std::wstring_view>);

        // int16_t with Charaters
        REQUIRE(cortex::BitXorWith<int16_t, char>);
        REQUIRE(cortex::BitXorWith<int16_t, u_char>);
        REQUIRE(cortex::BitXorWith<int16_t, wchar_t>);

        // int16_t with Bit Specific Characters
        REQUIRE(cortex::BitXorWith<int16_t, char8_t>);
        REQUIRE(cortex::BitXorWith<int16_t, char16_t>);
        REQUIRE(cortex::BitXorWith<int16_t, char32_t>);

        // int16_t with Bit Specific Integers
        REQUIRE(cortex::BitXorWith<int16_t, int8_t>);
        REQUIRE(cortex::BitXorWith<int16_t, int16_t>);
        REQUIRE(cortex::BitXorWith<int16_t, int32_t>);
        REQUIRE(cortex::BitXorWith<int16_t, int64_t>);

        // int16_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::BitXorWith<int16_t, uint8_t>);
        REQUIRE(cortex::BitXorWith<int16_t, uint16_t>);
        REQUIRE(cortex::BitXorWith<int16_t, uint32_t>);
        REQUIRE(cortex::BitXorWith<int16_t, uint64_t>);

        // int16_t with Bit Specific Least Integers
        REQUIRE(cortex::BitXorWith<int16_t, int_least8_t>);
        REQUIRE(cortex::BitXorWith<int16_t, int_least16_t>);
        REQUIRE(cortex::BitXorWith<int16_t, int_least32_t>);
        REQUIRE(cortex::BitXorWith<int16_t, int_least64_t>);
    }

    SECTION("int32 with _")
    {
        // int32 with Signed Integers
        REQUIRE(cortex::BitXorWith<int32_t, int>);
        REQUIRE(cortex::BitXorWith<int32_t, short>);
        REQUIRE(cortex::BitXorWith<int32_t, long>);
        REQUIRE(cortex::BitXorWith<int32_t, long long>);

        // int32 with Unsigned Integers
        REQUIRE(cortex::BitXorWith<int32_t, unsigned>);
        REQUIRE(cortex::BitXorWith<int32_t, unsigned short>);
        REQUIRE(cortex::BitXorWith<int32_t, u_short>);
        REQUIRE(cortex::BitXorWith<int32_t, unsigned long>);
        REQUIRE(cortex::BitXorWith<int32_t, unsigned long long>);
        
        // int32 with Floating Point and Doubles
        REQUIRE(!cortex::BitXorWith<int32_t, float>);
        REQUIRE(!cortex::BitXorWith<int32_t, double>);
        REQUIRE(!cortex::BitXorWith<int32_t, long double>);

        // int32 with std::strings and std::string_view
        REQUIRE(!cortex::BitXorWith<int32_t, std::string>);
        REQUIRE(!cortex::BitXorWith<int32_t, std::string_view>);
        REQUIRE(!cortex::BitXorWith<int32_t, std::u8string>);
        REQUIRE(!cortex::BitXorWith<int32_t, std::u16string>);
        REQUIRE(!cortex::BitXorWith<int32_t, std::u32string>);

        // int32 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitXorWith<int32_t, std::wstring>);
        REQUIRE(!cortex::BitXorWith<int32_t, std::wstring_view>);

        // int32_t with Charaters
        REQUIRE(cortex::BitXorWith<int32_t, char>);
        REQUIRE(cortex::BitXorWith<int32_t, u_char>);
        REQUIRE(cortex::BitXorWith<int32_t, wchar_t>);

        // int32_t with Bit Specific Characters
        REQUIRE(cortex::BitXorWith<int32_t, char8_t>);
        REQUIRE(cortex::BitXorWith<int32_t, char16_t>);
        REQUIRE(cortex::BitXorWith<int32_t, char32_t>);

        // int32_t with Bit Specific Integers
        REQUIRE(cortex::BitXorWith<int32_t, int8_t>);
        REQUIRE(cortex::BitXorWith<int32_t, int16_t>);
        REQUIRE(cortex::BitXorWith<int32_t, int32_t>);
        REQUIRE(cortex::BitXorWith<int32_t, int64_t>);

        // int32_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::BitXorWith<int32_t, uint8_t>);
        REQUIRE(cortex::BitXorWith<int32_t, uint16_t>);
        REQUIRE(cortex::BitXorWith<int32_t, uint32_t>);
        REQUIRE(cortex::BitXorWith<int32_t, uint64_t>);

        // int32_t with Bit Specific Least Integers
        REQUIRE(cortex::BitXorWith<int32_t, int_least8_t>);
        REQUIRE(cortex::BitXorWith<int32_t, int_least16_t>);
        REQUIRE(cortex::BitXorWith<int32_t, int_least32_t>);
        REQUIRE(cortex::BitXorWith<int32_t, int_least64_t>);
    }

    SECTION("int64 with _")
    {
        // int64 with Signed Integers
        REQUIRE(cortex::BitXorWith<int64_t, int>);
        REQUIRE(cortex::BitXorWith<int64_t, short>);
        REQUIRE(cortex::BitXorWith<int64_t, long>);
        REQUIRE(cortex::BitXorWith<int64_t, long long>);

        // int64 with Unsigned Integers
        REQUIRE(cortex::BitXorWith<int64_t, unsigned>);
        REQUIRE(cortex::BitXorWith<int64_t, unsigned short>);
        REQUIRE(cortex::BitXorWith<int64_t, u_short>);
        REQUIRE(cortex::BitXorWith<int64_t, unsigned long>);
        REQUIRE(cortex::BitXorWith<int64_t, unsigned long long>);
        
        // int64 with Floating Point and Doubles
        REQUIRE(!cortex::BitXorWith<int64_t, float>);
        REQUIRE(!cortex::BitXorWith<int64_t, double>);
        REQUIRE(!cortex::BitXorWith<int64_t, long double>);

        // int64 with std::strings and std::string_view
        REQUIRE(!cortex::BitXorWith<int64_t, std::string>);
        REQUIRE(!cortex::BitXorWith<int64_t, std::string_view>);
        REQUIRE(!cortex::BitXorWith<int64_t, std::u8string>);
        REQUIRE(!cortex::BitXorWith<int64_t, std::u16string>);
        REQUIRE(!cortex::BitXorWith<int64_t, std::u32string>);

        // int64 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitXorWith<int64_t, std::wstring>);
        REQUIRE(!cortex::BitXorWith<int64_t, std::wstring_view>);

        // int64_t with Charaters
        REQUIRE(cortex::BitXorWith<int64_t, char>);
        REQUIRE(cortex::BitXorWith<int64_t, u_char>);
        REQUIRE(cortex::BitXorWith<int64_t, wchar_t>);

        // int64_t with Bit Specific Characters
        REQUIRE(cortex::BitXorWith<int64_t, char8_t>);
        REQUIRE(cortex::BitXorWith<int64_t, char16_t>);
        REQUIRE(cortex::BitXorWith<int64_t, char32_t>);

        // int64_t with Bit Specific Integers
        REQUIRE(cortex::BitXorWith<int64_t, int8_t>);
        REQUIRE(cortex::BitXorWith<int64_t, int16_t>);
        REQUIRE(cortex::BitXorWith<int64_t, int32_t>);
        REQUIRE(cortex::BitXorWith<int64_t, int64_t>);

        // int64_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::BitXorWith<int64_t, uint8_t>);
        REQUIRE(cortex::BitXorWith<int64_t, uint16_t>);
        REQUIRE(cortex::BitXorWith<int64_t, uint32_t>);
        REQUIRE(cortex::BitXorWith<int64_t, uint64_t>);

        // int64_t with Bit Specific Least Integers
        REQUIRE(cortex::BitXorWith<int64_t, int_least8_t>);
        REQUIRE(cortex::BitXorWith<int64_t, int_least16_t>);
        REQUIRE(cortex::BitXorWith<int64_t, int_least32_t>);
        REQUIRE(cortex::BitXorWith<int64_t, int_least64_t>);
}
}

TEST_CASE("Addable With : Bit Specific Unsigned Integers")
{
    SECTION("uint8_t with _")
    {
        // uint8_t with Signed Integers
        REQUIRE(cortex::BitXorWith<uint8_t, int>);
        REQUIRE(cortex::BitXorWith<uint8_t, short>);
        REQUIRE(cortex::BitXorWith<uint8_t, long>);
        REQUIRE(cortex::BitXorWith<uint8_t, long long>);

        // uint8_t with Unsigned Integers
        REQUIRE(cortex::BitXorWith<uint8_t, unsigned>);
        REQUIRE(cortex::BitXorWith<uint8_t, unsigned short>);
        REQUIRE(cortex::BitXorWith<uint8_t, u_short>);
        REQUIRE(cortex::BitXorWith<uint8_t, unsigned long>);
        REQUIRE(cortex::BitXorWith<uint8_t, unsigned long long>);
        
        // uint8_t with Floating Point and Doubles
        REQUIRE(!cortex::BitXorWith<uint8_t, float>);
        REQUIRE(!cortex::BitXorWith<uint8_t, double>);
        REQUIRE(!cortex::BitXorWith<uint8_t, long double>);

        // uint8_t with std::strings and std::string_view
        REQUIRE(!cortex::BitXorWith<uint8_t, std::string>);
        REQUIRE(!cortex::BitXorWith<uint8_t, std::string_view>);
        REQUIRE(!cortex::BitXorWith<uint8_t, std::u8string>);
        REQUIRE(!cortex::BitXorWith<uint8_t, std::u16string>);
        REQUIRE(!cortex::BitXorWith<uint8_t, std::u32string>);

        // uint8_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitXorWith<long long, std::wstring>);
        REQUIRE(!cortex::BitXorWith<long long, std::wstring_view>);

        // uint8_t with Charaters
        REQUIRE(cortex::BitXorWith<uint8_t, char>);
        REQUIRE(cortex::BitXorWith<uint8_t, u_char>);
        REQUIRE(cortex::BitXorWith<uint8_t, wchar_t>);

        // uint8_t with Bit Specific Characters
        REQUIRE(cortex::BitXorWith<uint8_t, char8_t>);
        REQUIRE(cortex::BitXorWith<uint8_t, char16_t>);
        REQUIRE(cortex::BitXorWith<uint8_t, char32_t>);

        // uint8_t with Bit Specific Integers
        REQUIRE(cortex::BitXorWith<uint8_t, int8_t>);
        REQUIRE(cortex::BitXorWith<uint8_t, int16_t>);
        REQUIRE(cortex::BitXorWith<uint8_t, int32_t>);
        REQUIRE(cortex::BitXorWith<uint8_t, int64_t>);

        // uint8_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::BitXorWith<uint8_t, uint8_t>);
        REQUIRE(cortex::BitXorWith<uint8_t, uint16_t>);
        REQUIRE(cortex::BitXorWith<uint8_t, uint32_t>);
        REQUIRE(cortex::BitXorWith<uint8_t, uint64_t>);

        // uint8_t with Bit Specific Least Integers
        REQUIRE(cortex::BitXorWith<uint8_t, int_least8_t>);
        REQUIRE(cortex::BitXorWith<uint8_t, int_least16_t>);
        REQUIRE(cortex::BitXorWith<uint8_t, int_least32_t>);
        REQUIRE(cortex::BitXorWith<uint8_t, int_least64_t>);
    }

    SECTION("uint16_t with _")
    {
        // uint16_t with Signed Integers
        REQUIRE(cortex::BitXorWith<uint16_t, int>);
        REQUIRE(cortex::BitXorWith<uint16_t, short>);
        REQUIRE(cortex::BitXorWith<uint16_t, long>);
        REQUIRE(cortex::BitXorWith<uint16_t, long long>);

        // uint16_t with Unsigned Integers
        REQUIRE(cortex::BitXorWith<uint16_t, unsigned>);
        REQUIRE(cortex::BitXorWith<uint16_t, unsigned short>);
        REQUIRE(cortex::BitXorWith<uint16_t, u_short>);
        REQUIRE(cortex::BitXorWith<uint16_t, unsigned long>);
        REQUIRE(cortex::BitXorWith<uint16_t, unsigned long long>);
        
        // uint16_t with Floating Point and Doubles
        REQUIRE(!cortex::BitXorWith<uint16_t, float>);
        REQUIRE(!cortex::BitXorWith<uint16_t, double>);
        REQUIRE(!cortex::BitXorWith<uint16_t, long double>);

        // uint16_t with std::strings and std::string_view
        REQUIRE(!cortex::BitXorWith<uint16_t, std::string>);
        REQUIRE(!cortex::BitXorWith<uint16_t, std::string_view>);
        REQUIRE(!cortex::BitXorWith<uint16_t, std::u8string>);
        REQUIRE(!cortex::BitXorWith<uint16_t, std::u16string>);
        REQUIRE(!cortex::BitXorWith<uint16_t, std::u32string>);

        // uint16_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitXorWith<uint16_t, std::wstring>);
        REQUIRE(!cortex::BitXorWith<uint16_t, std::wstring_view>);

        // uint16_t with Charaters
        REQUIRE(cortex::BitXorWith<uint16_t, char>);
        REQUIRE(cortex::BitXorWith<uint16_t, u_char>);
        REQUIRE(cortex::BitXorWith<uint16_t, wchar_t>);

        // uint16_t with Bit Specific Characters
        REQUIRE(cortex::BitXorWith<uint16_t, char8_t>);
        REQUIRE(cortex::BitXorWith<uint16_t, char16_t>);
        REQUIRE(cortex::BitXorWith<uint16_t, char32_t>);

        // uint16_t with Bit Specific Integers
        REQUIRE(cortex::BitXorWith<uint16_t, int8_t>);
        REQUIRE(cortex::BitXorWith<uint16_t, int16_t>);
        REQUIRE(cortex::BitXorWith<uint16_t, int32_t>);
        REQUIRE(cortex::BitXorWith<uint16_t, int64_t>);

        // uint16_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::BitXorWith<uint16_t, uint8_t>);
        REQUIRE(cortex::BitXorWith<uint16_t, uint16_t>);
        REQUIRE(cortex::BitXorWith<uint16_t, uint32_t>);
        REQUIRE(cortex::BitXorWith<uint16_t, uint64_t>);

        // uint16_t with Bit Specific Least Integers
        REQUIRE(cortex::BitXorWith<uint16_t, int_least8_t>);
        REQUIRE(cortex::BitXorWith<uint16_t, int_least16_t>);
        REQUIRE(cortex::BitXorWith<uint16_t, int_least32_t>);
        REQUIRE(cortex::BitXorWith<uint16_t, int_least64_t>);
    }

    SECTION("uint32_t with _")
    {
        // int32 with Signed Integers
        REQUIRE(cortex::BitXorWith<uint32_t, int>);
        REQUIRE(cortex::BitXorWith<uint32_t, short>);
        REQUIRE(cortex::BitXorWith<uint32_t, long>);
        REQUIRE(cortex::BitXorWith<uint32_t, long long>);

        // int32 with Unsigned Integers
        REQUIRE(cortex::BitXorWith<uint32_t, unsigned>);
        REQUIRE(cortex::BitXorWith<uint32_t, unsigned short>);
        REQUIRE(cortex::BitXorWith<uint32_t, u_short>);
        REQUIRE(cortex::BitXorWith<uint32_t, unsigned long>);
        REQUIRE(cortex::BitXorWith<uint32_t, unsigned long long>);
        
        // int32 with Floating Point and Doubles
        REQUIRE(!cortex::BitXorWith<uint32_t, float>);
        REQUIRE(!cortex::BitXorWith<uint32_t, double>);
        REQUIRE(!cortex::BitXorWith<uint32_t, long double>);

        // int32 with std::strings and std::string_view
        REQUIRE(!cortex::BitXorWith<uint32_t, std::string>);
        REQUIRE(!cortex::BitXorWith<uint32_t, std::string_view>);
        REQUIRE(!cortex::BitXorWith<uint32_t, std::u8string>);
        REQUIRE(!cortex::BitXorWith<uint32_t, std::u16string>);
        REQUIRE(!cortex::BitXorWith<uint32_t, std::u32string>);

        // int32 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitXorWith<uint32_t, std::wstring>);
        REQUIRE(!cortex::BitXorWith<uint32_t, std::wstring_view>);

        // uint32_t with Charaters
        REQUIRE(cortex::BitXorWith<uint32_t, char>);
        REQUIRE(cortex::BitXorWith<uint32_t, u_char>);
        REQUIRE(cortex::BitXorWith<uint32_t, wchar_t>);

        // uint32_t with Bit Specific Characters
        REQUIRE(cortex::BitXorWith<uint32_t, char8_t>);
        REQUIRE(cortex::BitXorWith<uint32_t, char16_t>);
        REQUIRE(cortex::BitXorWith<uint32_t, char32_t>);

        // uint32_t with Bit Specific Integers
        REQUIRE(cortex::BitXorWith<uint32_t, int8_t>);
        REQUIRE(cortex::BitXorWith<uint32_t, int16_t>);
        REQUIRE(cortex::BitXorWith<uint32_t, int32_t>);
        REQUIRE(cortex::BitXorWith<uint32_t, int64_t>);

        // uint32_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::BitXorWith<uint32_t, uint8_t>);
        REQUIRE(cortex::BitXorWith<uint32_t, uint16_t>);
        REQUIRE(cortex::BitXorWith<uint32_t, uint32_t>);
        REQUIRE(cortex::BitXorWith<uint32_t, uint64_t>);

        // uint32_t with Bit Specific Least Integers
        REQUIRE(cortex::BitXorWith<uint32_t, int_least8_t>);
        REQUIRE(cortex::BitXorWith<uint32_t, int_least16_t>);
        REQUIRE(cortex::BitXorWith<uint32_t, int_least32_t>);
        REQUIRE(cortex::BitXorWith<uint32_t, int_least64_t>);
    }

    SECTION("uint64_t with _")
    {
        // int64 with Signed Integers
        REQUIRE(cortex::BitXorWith<uint64_t, int>);
        REQUIRE(cortex::BitXorWith<uint64_t, short>);
        REQUIRE(cortex::BitXorWith<uint64_t, long>);
        REQUIRE(cortex::BitXorWith<uint64_t, long long>);

        // int64 with Unsigned Integers
        REQUIRE(cortex::BitXorWith<uint64_t, unsigned>);
        REQUIRE(cortex::BitXorWith<uint64_t, unsigned short>);
        REQUIRE(cortex::BitXorWith<uint64_t, u_short>);
        REQUIRE(cortex::BitXorWith<uint64_t, unsigned long>);
        REQUIRE(cortex::BitXorWith<uint64_t, unsigned long long>);
        
        // int64 with Floating Point and Doubles
        REQUIRE(!cortex::BitXorWith<uint64_t, float>);
        REQUIRE(!cortex::BitXorWith<uint64_t, double>);
        REQUIRE(!cortex::BitXorWith<uint64_t, long double>);

        // int64 with std::strings and std::string_view
        REQUIRE(!cortex::BitXorWith<uint64_t, std::string>);
        REQUIRE(!cortex::BitXorWith<uint64_t, std::string_view>);
        REQUIRE(!cortex::BitXorWith<uint64_t, std::u8string>);
        REQUIRE(!cortex::BitXorWith<uint64_t, std::u16string>);
        REQUIRE(!cortex::BitXorWith<uint64_t, std::u32string>);

        // int64 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitXorWith<uint64_t, std::wstring>);
        REQUIRE(!cortex::BitXorWith<uint64_t, std::wstring_view>);

        // uint64_t with Charaters
        REQUIRE(cortex::BitXorWith<uint64_t, char>);
        REQUIRE(cortex::BitXorWith<uint64_t, u_char>);
        REQUIRE(cortex::BitXorWith<uint64_t, wchar_t>);

        // uint64_t with Bit Specific Characters
        REQUIRE(cortex::BitXorWith<uint64_t, char8_t>);
        REQUIRE(cortex::BitXorWith<uint64_t, char16_t>);
        REQUIRE(cortex::BitXorWith<uint64_t, char32_t>);

        // uint64_t with Bit Specific Integers
        REQUIRE(cortex::BitXorWith<uint64_t, int8_t>);
        REQUIRE(cortex::BitXorWith<uint64_t, int16_t>);
        REQUIRE(cortex::BitXorWith<uint64_t, int32_t>);
        REQUIRE(cortex::BitXorWith<uint64_t, int64_t>);

        // uint64_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::BitXorWith<uint64_t, uint8_t>);
        REQUIRE(cortex::BitXorWith<uint64_t, uint16_t>);
        REQUIRE(cortex::BitXorWith<uint64_t, uint32_t>);
        REQUIRE(cortex::BitXorWith<uint64_t, uint64_t>);

        // uint64_t with Bit Specific Least Integers
        REQUIRE(cortex::BitXorWith<uint64_t, int_least8_t>);
        REQUIRE(cortex::BitXorWith<uint64_t, int_least16_t>);
        REQUIRE(cortex::BitXorWith<uint64_t, int_least32_t>);
        REQUIRE(cortex::BitXorWith<uint64_t, int_least64_t>);
    }
}

TEST_CASE("Addable With : std::size_t")
{
    SECTION("std::size_t with _")
    {
        // std::size_t with Signed Integers
        REQUIRE(cortex::BitXorWith<std::size_t, int>);
        REQUIRE(cortex::BitXorWith<std::size_t, short>);
        REQUIRE(cortex::BitXorWith<std::size_t, long>);
        REQUIRE(cortex::BitXorWith<std::size_t, long long>);

        // std::size_t with Unsigned Integers
        REQUIRE(cortex::BitXorWith<std::size_t, unsigned>);
        REQUIRE(cortex::BitXorWith<std::size_t, unsigned short>);
        REQUIRE(cortex::BitXorWith<std::size_t, u_short>);
        REQUIRE(cortex::BitXorWith<std::size_t, unsigned long>);
        REQUIRE(cortex::BitXorWith<std::size_t, unsigned long long>);
        
        // std::size_t with Floating Point and Doubles
        REQUIRE(!cortex::BitXorWith<std::size_t, float>);
        REQUIRE(!cortex::BitXorWith<std::size_t, double>);
        REQUIRE(!cortex::BitXorWith<std::size_t, long double>);

        // std::size_t with std::strings and std::string_view
        REQUIRE(!cortex::BitXorWith<std::size_t, std::string>);
        REQUIRE(!cortex::BitXorWith<std::size_t, std::string_view>);
        REQUIRE(!cortex::BitXorWith<std::size_t, std::u8string>);
        REQUIRE(!cortex::BitXorWith<std::size_t, std::u16string>);
        REQUIRE(!cortex::BitXorWith<std::size_t, std::u32string>);

        // std::size_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitXorWith<long long, std::wstring>);
        REQUIRE(!cortex::BitXorWith<long long, std::wstring_view>);

        // std::size_t with Charaters
        REQUIRE(cortex::BitXorWith<std::size_t, char>);
        REQUIRE(cortex::BitXorWith<std::size_t, u_char>);
        REQUIRE(cortex::BitXorWith<std::size_t, wchar_t>);

        // std::size_t with Bit Specific Characters
        REQUIRE(cortex::BitXorWith<std::size_t, char8_t>);
        REQUIRE(cortex::BitXorWith<std::size_t, char16_t>);
        REQUIRE(cortex::BitXorWith<std::size_t, char32_t>);

        // std::size_t with Bit Specific Integers
        REQUIRE(cortex::BitXorWith<std::size_t, int8_t>);
        REQUIRE(cortex::BitXorWith<std::size_t, int16_t>);
        REQUIRE(cortex::BitXorWith<std::size_t, int32_t>);
        REQUIRE(cortex::BitXorWith<std::size_t, int64_t>);

        // std::size_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::BitXorWith<std::size_t, uint8_t>);
        REQUIRE(cortex::BitXorWith<std::size_t, uint16_t>);
        REQUIRE(cortex::BitXorWith<std::size_t, uint32_t>);
        REQUIRE(cortex::BitXorWith<std::size_t, uint64_t>);

        // std::size_t with Bit Specific Least Integers
        REQUIRE(cortex::BitXorWith<std::size_t, int_least8_t>);
        REQUIRE(cortex::BitXorWith<std::size_t, int_least16_t>);
        REQUIRE(cortex::BitXorWith<std::size_t, int_least32_t>);
        REQUIRE(cortex::BitXorWith<std::size_t, int_least64_t>);
    }
}

TEST_CASE("BitXorWith : Fast Integers")
{
    SECTION("int_fast8_t with _")
    {
        // int_fast8_t with Signed Integers
        REQUIRE(cortex::BitXorWith<int_fast8_t, int>);
        REQUIRE(cortex::BitXorWith<int_fast8_t, short>);
        REQUIRE(cortex::BitXorWith<int_fast8_t, long>);
        REQUIRE(cortex::BitXorWith<int_fast8_t, long long>);

        // int_fast8_t with Unsigned Integers
        REQUIRE(cortex::BitXorWith<int_fast8_t, unsigned>);
        REQUIRE(cortex::BitXorWith<int_fast8_t, unsigned short>);
        REQUIRE(cortex::BitXorWith<int_fast8_t, u_short>);
        REQUIRE(cortex::BitXorWith<int_fast8_t, unsigned long>);
        REQUIRE(cortex::BitXorWith<int_fast8_t, unsigned long long>);
        
        // int_fast8_t with Floating Point and Doubles
        REQUIRE(!cortex::BitXorWith<int_fast8_t, float>);
        REQUIRE(!cortex::BitXorWith<int_fast8_t, double>);
        REQUIRE(!cortex::BitXorWith<int_fast8_t, long double>);

        // int_fast8_t with std::strings and std::string_view
        REQUIRE(!cortex::BitXorWith<int_fast8_t, std::string>);
        REQUIRE(!cortex::BitXorWith<int_fast8_t, std::string_view>);
        REQUIRE(!cortex::BitXorWith<int_fast8_t, std::u8string>);
        REQUIRE(!cortex::BitXorWith<int_fast8_t, std::u16string>);
        REQUIRE(!cortex::BitXorWith<int_fast8_t, std::u32string>);

        // int_fast8_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitXorWith<long long, std::wstring>);
        REQUIRE(!cortex::BitXorWith<long long, std::wstring_view>);

        // int_fast8_t with Charaters
        REQUIRE(cortex::BitXorWith<int_fast8_t, char>);
        REQUIRE(cortex::BitXorWith<int_fast8_t, u_char>);
        REQUIRE(cortex::BitXorWith<int_fast8_t, wchar_t>);

        // int_fast8_t with Bit Specific Characters
        REQUIRE(cortex::BitXorWith<int_fast8_t, char8_t>);
        REQUIRE(cortex::BitXorWith<int_fast8_t, char16_t>);
        REQUIRE(cortex::BitXorWith<int_fast8_t, char32_t>);

        // int_fast8_t with Bit Specific Integers
        REQUIRE(cortex::BitXorWith<int_fast8_t, int8_t>);
        REQUIRE(cortex::BitXorWith<int_fast8_t, int16_t>);
        REQUIRE(cortex::BitXorWith<int_fast8_t, int32_t>);
        REQUIRE(cortex::BitXorWith<int_fast8_t, int64_t>);

        // int_fast8_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::BitXorWith<int_fast8_t, uint8_t>);
        REQUIRE(cortex::BitXorWith<int_fast8_t, uint16_t>);
        REQUIRE(cortex::BitXorWith<int_fast8_t, uint32_t>);
        REQUIRE(cortex::BitXorWith<int_fast8_t, uint64_t>);

        // int_fast8_t with Bit Specific Least Integers
        REQUIRE(cortex::BitXorWith<int_fast8_t, int_least8_t>);
        REQUIRE(cortex::BitXorWith<int_fast8_t, int_least16_t>);
        REQUIRE(cortex::BitXorWith<int_fast8_t, int_least32_t>);
        REQUIRE(cortex::BitXorWith<int_fast8_t, int_least64_t>);
    }

    SECTION("int_fast16_t with _")
    {
        // int_fast16_t with Signed Integers
        REQUIRE(cortex::BitXorWith<int_fast16_t, int>);
        REQUIRE(cortex::BitXorWith<int_fast16_t, short>);
        REQUIRE(cortex::BitXorWith<int_fast16_t, long>);
        REQUIRE(cortex::BitXorWith<int_fast16_t, long long>);

        // int_fast16_t with Unsigned Integers
        REQUIRE(cortex::BitXorWith<int_fast16_t, unsigned>);
        REQUIRE(cortex::BitXorWith<int_fast16_t, unsigned short>);
        REQUIRE(cortex::BitXorWith<int_fast16_t, u_short>);
        REQUIRE(cortex::BitXorWith<int_fast16_t, unsigned long>);
        REQUIRE(cortex::BitXorWith<int_fast16_t, unsigned long long>);
        
        // int_fast16_t with Floating Point and Doubles
        REQUIRE(!cortex::BitXorWith<int_fast16_t, float>);
        REQUIRE(!cortex::BitXorWith<int_fast16_t, double>);
        REQUIRE(!cortex::BitXorWith<int_fast16_t, long double>);

        // int_fast16_t with std::strings and std::string_view
        REQUIRE(!cortex::BitXorWith<int_fast16_t, std::string>);
        REQUIRE(!cortex::BitXorWith<int_fast16_t, std::string_view>);
        REQUIRE(!cortex::BitXorWith<int_fast16_t, std::u8string>);
        REQUIRE(!cortex::BitXorWith<int_fast16_t, std::u16string>);
        REQUIRE(!cortex::BitXorWith<int_fast16_t, std::u32string>);

        // int_fast16_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitXorWith<int_fast16_t, std::wstring>);
        REQUIRE(!cortex::BitXorWith<int_fast16_t, std::wstring_view>);

        // int_fast16_t with Charaters
        REQUIRE(cortex::BitXorWith<int_fast16_t, char>);
        REQUIRE(cortex::BitXorWith<int_fast16_t, u_char>);
        REQUIRE(cortex::BitXorWith<int_fast16_t, wchar_t>);

        // int_fast16_t with Bit Specific Characters
        REQUIRE(cortex::BitXorWith<int_fast16_t, char8_t>);
        REQUIRE(cortex::BitXorWith<int_fast16_t, char16_t>);
        REQUIRE(cortex::BitXorWith<int_fast16_t, char32_t>);

        // int_fast16_t with Bit Specific Integers
        REQUIRE(cortex::BitXorWith<int_fast16_t, int8_t>);
        REQUIRE(cortex::BitXorWith<int_fast16_t, int16_t>);
        REQUIRE(cortex::BitXorWith<int_fast16_t, int32_t>);
        REQUIRE(cortex::BitXorWith<int_fast16_t, int64_t>);

        // int_fast16_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::BitXorWith<int_fast16_t, uint8_t>);
        REQUIRE(cortex::BitXorWith<int_fast16_t, uint16_t>);
        REQUIRE(cortex::BitXorWith<int_fast16_t, uint32_t>);
        REQUIRE(cortex::BitXorWith<int_fast16_t, uint64_t>);

        // int_fast16_t with Bit Specific Least Integers
        REQUIRE(cortex::BitXorWith<int_fast16_t, int_least8_t>);
        REQUIRE(cortex::BitXorWith<int_fast16_t, int_least16_t>);
        REQUIRE(cortex::BitXorWith<int_fast16_t, int_least32_t>);
        REQUIRE(cortex::BitXorWith<int_fast16_t, int_least64_t>);
    }

    SECTION("int_fast32_t with _")
    {
        // int32 with Signed Integers
        REQUIRE(cortex::BitXorWith<int_fast32_t, int>);
        REQUIRE(cortex::BitXorWith<int_fast32_t, short>);
        REQUIRE(cortex::BitXorWith<int_fast32_t, long>);
        REQUIRE(cortex::BitXorWith<int_fast32_t, long long>);

        // int32 with Unsigned Integers
        REQUIRE(cortex::BitXorWith<int_fast32_t, unsigned>);
        REQUIRE(cortex::BitXorWith<int_fast32_t, unsigned short>);
        REQUIRE(cortex::BitXorWith<int_fast32_t, u_short>);
        REQUIRE(cortex::BitXorWith<int_fast32_t, unsigned long>);
        REQUIRE(cortex::BitXorWith<int_fast32_t, unsigned long long>);
        
        // int32 with Floating Point and Doubles
        REQUIRE(!cortex::BitXorWith<int_fast32_t, float>);
        REQUIRE(!cortex::BitXorWith<int_fast32_t, double>);
        REQUIRE(!cortex::BitXorWith<int_fast32_t, long double>);

        // int32 with std::strings and std::string_view
        REQUIRE(!cortex::BitXorWith<int_fast32_t, std::string>);
        REQUIRE(!cortex::BitXorWith<int_fast32_t, std::string_view>);
        REQUIRE(!cortex::BitXorWith<int_fast32_t, std::u8string>);
        REQUIRE(!cortex::BitXorWith<int_fast32_t, std::u16string>);
        REQUIRE(!cortex::BitXorWith<int_fast32_t, std::u32string>);

        // int32 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitXorWith<int_fast32_t, std::wstring>);
        REQUIRE(!cortex::BitXorWith<int_fast32_t, std::wstring_view>);

        // int_fast32_t with Charaters
        REQUIRE(cortex::BitXorWith<int_fast32_t, char>);
        REQUIRE(cortex::BitXorWith<int_fast32_t, u_char>);
        REQUIRE(cortex::BitXorWith<int_fast32_t, wchar_t>);

        // int_fast32_t with Bit Specific Characters
        REQUIRE(cortex::BitXorWith<int_fast32_t, char8_t>);
        REQUIRE(cortex::BitXorWith<int_fast32_t, char16_t>);
        REQUIRE(cortex::BitXorWith<int_fast32_t, char32_t>);

        // int_fast32_t with Bit Specific Integers
        REQUIRE(cortex::BitXorWith<int_fast32_t, int8_t>);
        REQUIRE(cortex::BitXorWith<int_fast32_t, int16_t>);
        REQUIRE(cortex::BitXorWith<int_fast32_t, int32_t>);
        REQUIRE(cortex::BitXorWith<int_fast32_t, int64_t>);

        // int_fast32_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::BitXorWith<int_fast32_t, uint8_t>);
        REQUIRE(cortex::BitXorWith<int_fast32_t, uint16_t>);
        REQUIRE(cortex::BitXorWith<int_fast32_t, uint32_t>);
        REQUIRE(cortex::BitXorWith<int_fast32_t, uint64_t>);

        // int_fast32_t with Bit Specific Least Integers
        REQUIRE(cortex::BitXorWith<int_fast32_t, int_least8_t>);
        REQUIRE(cortex::BitXorWith<int_fast32_t, int_least16_t>);
        REQUIRE(cortex::BitXorWith<int_fast32_t, int_least32_t>);
        REQUIRE(cortex::BitXorWith<int_fast32_t, int_least64_t>);
    }

    SECTION("int_fast64_t with _")
    {
        // int64 with Signed Integers
        REQUIRE(cortex::BitXorWith<int_fast64_t, int>);
        REQUIRE(cortex::BitXorWith<int_fast64_t, short>);
        REQUIRE(cortex::BitXorWith<int_fast64_t, long>);
        REQUIRE(cortex::BitXorWith<int_fast64_t, long long>);

        // int64 with Unsigned Integers
        REQUIRE(cortex::BitXorWith<int_fast64_t, unsigned>);
        REQUIRE(cortex::BitXorWith<int_fast64_t, unsigned short>);
        REQUIRE(cortex::BitXorWith<int_fast64_t, u_short>);
        REQUIRE(cortex::BitXorWith<int_fast64_t, unsigned long>);
        REQUIRE(cortex::BitXorWith<int_fast64_t, unsigned long long>);
        
        // int64 with Floating Point and Doubles
        REQUIRE(!cortex::BitXorWith<int_fast64_t, float>);
        REQUIRE(!cortex::BitXorWith<int_fast64_t, double>);
        REQUIRE(!cortex::BitXorWith<int_fast64_t, long double>);

        // int64 with std::strings and std::string_view
        REQUIRE(!cortex::BitXorWith<int_fast64_t, std::string>);
        REQUIRE(!cortex::BitXorWith<int_fast64_t, std::string_view>);
        REQUIRE(!cortex::BitXorWith<int_fast64_t, std::u8string>);
        REQUIRE(!cortex::BitXorWith<int_fast64_t, std::u16string>);
        REQUIRE(!cortex::BitXorWith<int_fast64_t, std::u32string>);

        // int64 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitXorWith<int_fast64_t, std::wstring>);
        REQUIRE(!cortex::BitXorWith<int_fast64_t, std::wstring_view>);

        // int_fast64_t with Charaters
        REQUIRE(cortex::BitXorWith<int_fast64_t, char>);
        REQUIRE(cortex::BitXorWith<int_fast64_t, u_char>);
        REQUIRE(cortex::BitXorWith<int_fast64_t, wchar_t>);

        // int_fast64_t with Bit Specific Characters
        REQUIRE(cortex::BitXorWith<int_fast64_t, char8_t>);
        REQUIRE(cortex::BitXorWith<int_fast64_t, char16_t>);
        REQUIRE(cortex::BitXorWith<int_fast64_t, char32_t>);

        // int_fast64_t with Bit Specific Integers
        REQUIRE(cortex::BitXorWith<int_fast64_t, int8_t>);
        REQUIRE(cortex::BitXorWith<int_fast64_t, int16_t>);
        REQUIRE(cortex::BitXorWith<int_fast64_t, int32_t>);
        REQUIRE(cortex::BitXorWith<int_fast64_t, int64_t>);

        // int_fast64_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::BitXorWith<int_fast64_t, uint8_t>);
        REQUIRE(cortex::BitXorWith<int_fast64_t, uint16_t>);
        REQUIRE(cortex::BitXorWith<int_fast64_t, uint32_t>);
        REQUIRE(cortex::BitXorWith<int_fast64_t, uint64_t>);

        // int_fast64_t with Bit Specific Least Integers
        REQUIRE(cortex::BitXorWith<int_fast64_t, int_least8_t>);
        REQUIRE(cortex::BitXorWith<int_fast64_t, int_least16_t>);
        REQUIRE(cortex::BitXorWith<int_fast64_t, int_least32_t>);
        REQUIRE(cortex::BitXorWith<int_fast64_t, int_least64_t>);
    }
}

TEST_CASE("BitXorWith : Least Integers")
{
    SECTION("int_least8_t with _")
    {
        // int_fast8_t with Signed Integers
        REQUIRE(cortex::BitXorWith<int_least8_t, int>);
        REQUIRE(cortex::BitXorWith<int_least8_t, short>);
        REQUIRE(cortex::BitXorWith<int_least8_t, long>);
        REQUIRE(cortex::BitXorWith<int_least8_t, long long>);

        // int_fast8_t with Unsigned Integers
        REQUIRE(cortex::BitXorWith<int_least8_t, unsigned>);
        REQUIRE(cortex::BitXorWith<int_least8_t, unsigned short>);
        REQUIRE(cortex::BitXorWith<int_least8_t, u_short>);
        REQUIRE(cortex::BitXorWith<int_least8_t, unsigned long>);
        REQUIRE(cortex::BitXorWith<int_least8_t, unsigned long long>);
        
        // int_fast8_t with Floating Point and Doubles
        REQUIRE(!cortex::BitXorWith<int_least8_t, float>);
        REQUIRE(!cortex::BitXorWith<int_least8_t, double>);
        REQUIRE(!cortex::BitXorWith<int_least8_t, long double>);

        // int_fast8_t with std::strings and std::string_view
        REQUIRE(!cortex::BitXorWith<int_least8_t, std::string>);
        REQUIRE(!cortex::BitXorWith<int_least8_t, std::string_view>);
        REQUIRE(!cortex::BitXorWith<int_least8_t, std::u8string>);
        REQUIRE(!cortex::BitXorWith<int_least8_t, std::u16string>);
        REQUIRE(!cortex::BitXorWith<int_least8_t, std::u32string>);

        // int_fast8_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitXorWith<long long, std::wstring>);
        REQUIRE(!cortex::BitXorWith<long long, std::wstring_view>);

        // int_fast8_t with Charaters
        REQUIRE(cortex::BitXorWith<int_least8_t, char>);
        REQUIRE(cortex::BitXorWith<int_least8_t, u_char>);
        REQUIRE(cortex::BitXorWith<int_least8_t, wchar_t>);

        // int_fast8_t with Bit Specific Characters
        REQUIRE(cortex::BitXorWith<int_least8_t, char8_t>);
        REQUIRE(cortex::BitXorWith<int_least8_t, char16_t>);
        REQUIRE(cortex::BitXorWith<int_least8_t, char32_t>);

        // int_fast8_t with Bit Specific Integers
        REQUIRE(cortex::BitXorWith<int_least8_t, int8_t>);
        REQUIRE(cortex::BitXorWith<int_least8_t, int16_t>);
        REQUIRE(cortex::BitXorWith<int_least8_t, int32_t>);
        REQUIRE(cortex::BitXorWith<int_least8_t, int64_t>);

        // int_fast8_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::BitXorWith<int_least8_t, uint8_t>);
        REQUIRE(cortex::BitXorWith<int_least8_t, uint16_t>);
        REQUIRE(cortex::BitXorWith<int_least8_t, uint32_t>);
        REQUIRE(cortex::BitXorWith<int_least8_t, uint64_t>);

        // int_fast8_t with Bit Specific Least Integers
        REQUIRE(cortex::BitXorWith<int_least8_t, int_least8_t>);
        REQUIRE(cortex::BitXorWith<int_least8_t, int_least16_t>);
        REQUIRE(cortex::BitXorWith<int_least8_t, int_least32_t>);
        REQUIRE(cortex::BitXorWith<int_least8_t, int_least64_t>);
    }

    SECTION("int_least16_t with _")
    {
        // int_fast16_t with Signed Integers
        REQUIRE(cortex::BitXorWith<int_least16_t, int>);
        REQUIRE(cortex::BitXorWith<int_least16_t, short>);
        REQUIRE(cortex::BitXorWith<int_least16_t, long>);
        REQUIRE(cortex::BitXorWith<int_least16_t, long long>);

        // int_fast16_t with Unsigned Integers
        REQUIRE(cortex::BitXorWith<int_least16_t, unsigned>);
        REQUIRE(cortex::BitXorWith<int_least16_t, unsigned short>);
        REQUIRE(cortex::BitXorWith<int_least16_t, u_short>);
        REQUIRE(cortex::BitXorWith<int_least16_t, unsigned long>);
        REQUIRE(cortex::BitXorWith<int_least16_t, unsigned long long>);
        
        // int_fast16_t with Floating Point and Doubles
        REQUIRE(!cortex::BitXorWith<int_least16_t, float>);
        REQUIRE(!cortex::BitXorWith<int_least16_t, double>);
        REQUIRE(!cortex::BitXorWith<int_least16_t, long double>);

        // int_fast16_t with std::strings and std::string_view
        REQUIRE(!cortex::BitXorWith<int_least16_t, std::string>);
        REQUIRE(!cortex::BitXorWith<int_least16_t, std::string_view>);
        REQUIRE(!cortex::BitXorWith<int_least16_t, std::u8string>);
        REQUIRE(!cortex::BitXorWith<int_least16_t, std::u16string>);
        REQUIRE(!cortex::BitXorWith<int_least16_t, std::u32string>);

        // int_fast16_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitXorWith<int_least16_t, std::wstring>);
        REQUIRE(!cortex::BitXorWith<int_least16_t, std::wstring_view>);

        // int_fast16_t with Charaters
        REQUIRE(cortex::BitXorWith<int_least16_t, char>);
        REQUIRE(cortex::BitXorWith<int_least16_t, u_char>);
        REQUIRE(cortex::BitXorWith<int_least16_t, wchar_t>);

        // int_fast16_t with Bit Specific Characters
        REQUIRE(cortex::BitXorWith<int_least16_t, char8_t>);
        REQUIRE(cortex::BitXorWith<int_least16_t, char16_t>);
        REQUIRE(cortex::BitXorWith<int_least16_t, char32_t>);

        // int_fast16_t with Bit Specific Integers
        REQUIRE(cortex::BitXorWith<int_least16_t, int8_t>);
        REQUIRE(cortex::BitXorWith<int_least16_t, int16_t>);
        REQUIRE(cortex::BitXorWith<int_least16_t, int32_t>);
        REQUIRE(cortex::BitXorWith<int_least16_t, int64_t>);

        // int_fast16_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::BitXorWith<int_least16_t, uint8_t>);
        REQUIRE(cortex::BitXorWith<int_least16_t, uint16_t>);
        REQUIRE(cortex::BitXorWith<int_least16_t, uint32_t>);
        REQUIRE(cortex::BitXorWith<int_least16_t, uint64_t>);

        // int_fast16_t with Bit Specific Least Integers
        REQUIRE(cortex::BitXorWith<int_least16_t, int_least8_t>);
        REQUIRE(cortex::BitXorWith<int_least16_t, int_least16_t>);
        REQUIRE(cortex::BitXorWith<int_least16_t, int_least32_t>);
        REQUIRE(cortex::BitXorWith<int_least16_t, int_least64_t>);
    }

    SECTION("int_least32_t with _")
    {
        // int32 with Signed Integers
        REQUIRE(cortex::BitXorWith<int_least32_t, int>);
        REQUIRE(cortex::BitXorWith<int_least32_t, short>);
        REQUIRE(cortex::BitXorWith<int_least32_t, long>);
        REQUIRE(cortex::BitXorWith<int_least32_t, long long>);

        // int32 with Unsigned Integers
        REQUIRE(cortex::BitXorWith<int_least32_t, unsigned>);
        REQUIRE(cortex::BitXorWith<int_least32_t, unsigned short>);
        REQUIRE(cortex::BitXorWith<int_least32_t, u_short>);
        REQUIRE(cortex::BitXorWith<int_least32_t, unsigned long>);
        REQUIRE(cortex::BitXorWith<int_least32_t, unsigned long long>);
        
        // int32 with Floating Point and Doubles
        REQUIRE(!cortex::BitXorWith<int_least32_t, float>);
        REQUIRE(!cortex::BitXorWith<int_least32_t, double>);
        REQUIRE(!cortex::BitXorWith<int_least32_t, long double>);

        // int32 with std::strings and std::string_view
        REQUIRE(!cortex::BitXorWith<int_least32_t, std::string>);
        REQUIRE(!cortex::BitXorWith<int_least32_t, std::string_view>);
        REQUIRE(!cortex::BitXorWith<int_least32_t, std::u8string>);
        REQUIRE(!cortex::BitXorWith<int_least32_t, std::u16string>);
        REQUIRE(!cortex::BitXorWith<int_least32_t, std::u32string>);

        // int32 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitXorWith<int_least32_t, std::wstring>);
        REQUIRE(!cortex::BitXorWith<int_least32_t, std::wstring_view>);

        // int_fast32_t with Charaters
        REQUIRE(cortex::BitXorWith<int_least32_t, char>);
        REQUIRE(cortex::BitXorWith<int_least32_t, u_char>);
        REQUIRE(cortex::BitXorWith<int_least32_t, wchar_t>);

        // int_fast32_t with Bit Specific Characters
        REQUIRE(cortex::BitXorWith<int_least32_t, char8_t>);
        REQUIRE(cortex::BitXorWith<int_least32_t, char16_t>);
        REQUIRE(cortex::BitXorWith<int_least32_t, char32_t>);

        // int_fast32_t with Bit Specific Integers
        REQUIRE(cortex::BitXorWith<int_least32_t, int8_t>);
        REQUIRE(cortex::BitXorWith<int_least32_t, int16_t>);
        REQUIRE(cortex::BitXorWith<int_least32_t, int32_t>);
        REQUIRE(cortex::BitXorWith<int_least32_t, int64_t>);

        // int_fast32_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::BitXorWith<int_least32_t, uint8_t>);
        REQUIRE(cortex::BitXorWith<int_least32_t, uint16_t>);
        REQUIRE(cortex::BitXorWith<int_least32_t, uint32_t>);
        REQUIRE(cortex::BitXorWith<int_least32_t, uint64_t>);

        // int_fast32_t with Bit Specific Least Integers
        REQUIRE(cortex::BitXorWith<int_least32_t, int_least8_t>);
        REQUIRE(cortex::BitXorWith<int_least32_t, int_least16_t>);
        REQUIRE(cortex::BitXorWith<int_least32_t, int_least32_t>);
        REQUIRE(cortex::BitXorWith<int_least32_t, int_least64_t>);
    }

    SECTION("int_least64_t with _")
    {
        // int64 with Signed Integers
        REQUIRE(cortex::BitXorWith<int_least64_t, int>);
        REQUIRE(cortex::BitXorWith<int_least64_t, short>);
        REQUIRE(cortex::BitXorWith<int_least64_t, long>);
        REQUIRE(cortex::BitXorWith<int_least64_t, long long>);

        // int64 with Unsigned Integers
        REQUIRE(cortex::BitXorWith<int_least64_t, unsigned>);
        REQUIRE(cortex::BitXorWith<int_least64_t, unsigned short>);
        REQUIRE(cortex::BitXorWith<int_least64_t, u_short>);
        REQUIRE(cortex::BitXorWith<int_least64_t, unsigned long>);
        REQUIRE(cortex::BitXorWith<int_least64_t, unsigned long long>);
        
        // int64 with Floating Point and Doubles
        REQUIRE(!cortex::BitXorWith<int_least64_t, float>);
        REQUIRE(!cortex::BitXorWith<int_least64_t, double>);
        REQUIRE(!cortex::BitXorWith<int_least64_t, long double>);

        // int64 with std::strings and std::string_view
        REQUIRE(!cortex::BitXorWith<int_least64_t, std::string>);
        REQUIRE(!cortex::BitXorWith<int_least64_t, std::string_view>);
        REQUIRE(!cortex::BitXorWith<int_least64_t, std::u8string>);
        REQUIRE(!cortex::BitXorWith<int_least64_t, std::u16string>);
        REQUIRE(!cortex::BitXorWith<int_least64_t, std::u32string>);

        // int64 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::BitXorWith<int_least64_t, std::wstring>);
        REQUIRE(!cortex::BitXorWith<int_least64_t, std::wstring_view>);

        // int_fast64_t with Charaters
        REQUIRE(cortex::BitXorWith<int_least64_t, char>);
        REQUIRE(cortex::BitXorWith<int_least64_t, u_char>);
        REQUIRE(cortex::BitXorWith<int_least64_t, wchar_t>);

        // int_fast64_t with Bit Specific Characters
        REQUIRE(cortex::BitXorWith<int_least64_t, char8_t>);
        REQUIRE(cortex::BitXorWith<int_least64_t, char16_t>);
        REQUIRE(cortex::BitXorWith<int_least64_t, char32_t>);

        // int_fast64_t with Bit Specific Integers
        REQUIRE(cortex::BitXorWith<int_least64_t, int8_t>);
        REQUIRE(cortex::BitXorWith<int_least64_t, int16_t>);
        REQUIRE(cortex::BitXorWith<int_least64_t, int32_t>);
        REQUIRE(cortex::BitXorWith<int_least64_t, int64_t>);

        // int_fast64_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::BitXorWith<int_least64_t, uint8_t>);
        REQUIRE(cortex::BitXorWith<int_least64_t, uint16_t>);
        REQUIRE(cortex::BitXorWith<int_least64_t, uint32_t>);
        REQUIRE(cortex::BitXorWith<int_least64_t, uint64_t>);

        // int_fast64_t with Bit Specific Least Integers
        REQUIRE(cortex::BitXorWith<int_least64_t, int_least8_t>);
        REQUIRE(cortex::BitXorWith<int_least64_t, int_least16_t>);
        REQUIRE(cortex::BitXorWith<int_least64_t, int_least32_t>);
        REQUIRE(cortex::BitXorWith<int_least64_t, int_least64_t>);
    }
}