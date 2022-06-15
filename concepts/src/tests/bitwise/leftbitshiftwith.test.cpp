#include <catch2/catch.hpp>
#include <concepts.hpp>

TEST_CASE("LeftBitShiftWith : Signed Integers")
{
    SECTION("Int with _")
    {
        // Int with Signed Integers
        REQUIRE(cortex::LeftBitShiftWith<int, int>);
        REQUIRE(cortex::LeftBitShiftWith<int, short>);
        REQUIRE(cortex::LeftBitShiftWith<int, long>);
        REQUIRE(cortex::LeftBitShiftWith<int, long long>);

        // Int with Unsigned Integers
        REQUIRE(cortex::LeftBitShiftWith<int, unsigned>);
        REQUIRE(cortex::LeftBitShiftWith<int, unsigned short>);
        REQUIRE(cortex::LeftBitShiftWith<int, u_short>);
        REQUIRE(cortex::LeftBitShiftWith<int, unsigned long>);
        REQUIRE(cortex::LeftBitShiftWith<int, unsigned long long>);
        
        // Integers with Floating Point and Doubles
        REQUIRE(!cortex::LeftBitShiftWith<int, float>);
        REQUIRE(!cortex::LeftBitShiftWith<int, double>);
        REQUIRE(!cortex::LeftBitShiftWith<int, long double>);

        // Integers with std::strings and std::string_view
        REQUIRE(!cortex::LeftBitShiftWith<int, std::string>);
        REQUIRE(!cortex::LeftBitShiftWith<int, std::string_view>);
        REQUIRE(!cortex::LeftBitShiftWith<int, std::u8string>);
        REQUIRE(!cortex::LeftBitShiftWith<int, std::u16string>);
        REQUIRE(!cortex::LeftBitShiftWith<int, std::u32string>);

        // Integers with std::wstrings and std::wstring_view
        REQUIRE(!cortex::LeftBitShiftWith<int, std::wstring>);
        REQUIRE(!cortex::LeftBitShiftWith<int, std::wstring_view>);

        // Integers with Charaters
        REQUIRE(cortex::LeftBitShiftWith<int, char>);
        REQUIRE(cortex::LeftBitShiftWith<int, u_char>);
        REQUIRE(cortex::LeftBitShiftWith<int, wchar_t>);

        // Integers with Bit Specific Characters
        REQUIRE(cortex::LeftBitShiftWith<int, char8_t>);
        REQUIRE(cortex::LeftBitShiftWith<int, char16_t>);
        REQUIRE(cortex::LeftBitShiftWith<int, char32_t>);

        // Integers with Bit Specific Integers
        REQUIRE(cortex::LeftBitShiftWith<int, int8_t>);
        REQUIRE(cortex::LeftBitShiftWith<int, int16_t>);
        REQUIRE(cortex::LeftBitShiftWith<int, int32_t>);
        REQUIRE(cortex::LeftBitShiftWith<int, int64_t>);

        // Integers with Bit Specific Unsigned Integers
        REQUIRE(cortex::LeftBitShiftWith<int, uint8_t>);
        REQUIRE(cortex::LeftBitShiftWith<int, uint16_t>);
        REQUIRE(cortex::LeftBitShiftWith<int, uint32_t>);
        REQUIRE(cortex::LeftBitShiftWith<int, uint64_t>);

        // Integers with Bit Specific Least Integers
        REQUIRE(cortex::LeftBitShiftWith<int, int_least8_t>);
        REQUIRE(cortex::LeftBitShiftWith<int, int_least16_t>);
        REQUIRE(cortex::LeftBitShiftWith<int, int_least32_t>);
        REQUIRE(cortex::LeftBitShiftWith<int, int_least64_t>);
    }

    SECTION("Short with _")
    {
        // Short with Signed Integers
        REQUIRE(cortex::LeftBitShiftWith<short, int>);
        REQUIRE(cortex::LeftBitShiftWith<short, short>);
        REQUIRE(cortex::LeftBitShiftWith<short, long>);
        REQUIRE(cortex::LeftBitShiftWith<short, long long>);

        // Short with Unsigned Integers
        REQUIRE(cortex::LeftBitShiftWith<short, unsigned>);
        REQUIRE(cortex::LeftBitShiftWith<short, unsigned short>);
        REQUIRE(cortex::LeftBitShiftWith<short, u_short>);
        REQUIRE(cortex::LeftBitShiftWith<short, unsigned long>);
        REQUIRE(cortex::LeftBitShiftWith<short, unsigned long long>);
        
        // Short with Floating Point and Doubles
        REQUIRE(!cortex::LeftBitShiftWith<short, float>);
        REQUIRE(!cortex::LeftBitShiftWith<short, double>);
        REQUIRE(!cortex::LeftBitShiftWith<short, long double>);

        // Short with std::strings and std::string_view
        REQUIRE(!cortex::LeftBitShiftWith<short, std::string>);
        REQUIRE(!cortex::LeftBitShiftWith<short, std::string_view>);
        REQUIRE(!cortex::LeftBitShiftWith<short, std::u8string>);
        REQUIRE(!cortex::LeftBitShiftWith<short, std::u16string>);
        REQUIRE(!cortex::LeftBitShiftWith<short, std::u32string>);

        // Short with std::wstrings and std::wstring_view
        REQUIRE(!cortex::LeftBitShiftWith<short, std::wstring>);
        REQUIRE(!cortex::LeftBitShiftWith<short, std::wstring_view>);

        // Short with Charaters
        REQUIRE(cortex::LeftBitShiftWith<short, char>);
        REQUIRE(cortex::LeftBitShiftWith<short, u_char>);
        REQUIRE(cortex::LeftBitShiftWith<short, wchar_t>);

        // Short with Bit Specific Characters
        REQUIRE(cortex::LeftBitShiftWith<short, char8_t>);
        REQUIRE(cortex::LeftBitShiftWith<short, char16_t>);
        REQUIRE(cortex::LeftBitShiftWith<short, char32_t>);

        // Short with Bit Specific Short
        REQUIRE(cortex::LeftBitShiftWith<short, int8_t>);
        REQUIRE(cortex::LeftBitShiftWith<short, int16_t>);
        REQUIRE(cortex::LeftBitShiftWith<short, int32_t>);
        REQUIRE(cortex::LeftBitShiftWith<short, int64_t>);

        // Short with Bit Specific Unsigned Short
        REQUIRE(cortex::LeftBitShiftWith<short, uint8_t>);
        REQUIRE(cortex::LeftBitShiftWith<short, uint16_t>);
        REQUIRE(cortex::LeftBitShiftWith<short, uint32_t>);
        REQUIRE(cortex::LeftBitShiftWith<short, uint64_t>);

        // Short with Bit Specific Least Integers
        REQUIRE(cortex::LeftBitShiftWith<short, int_least8_t>);
        REQUIRE(cortex::LeftBitShiftWith<short, int_least16_t>);
        REQUIRE(cortex::LeftBitShiftWith<short, int_least32_t>);
        REQUIRE(cortex::LeftBitShiftWith<short, int_least64_t>);
    }

    SECTION("Long with _")
    {
        // Long with Signed Integers
        REQUIRE(cortex::LeftBitShiftWith<long, int>);
        REQUIRE(cortex::LeftBitShiftWith<long, short>);
        REQUIRE(cortex::LeftBitShiftWith<long, long>);
        REQUIRE(cortex::LeftBitShiftWith<long, long long>);

        // Long with Unsigned Integers
        REQUIRE(cortex::LeftBitShiftWith<long, unsigned>);
        REQUIRE(cortex::LeftBitShiftWith<long, unsigned short>);
        REQUIRE(cortex::LeftBitShiftWith<long, u_short>);
        REQUIRE(cortex::LeftBitShiftWith<long, unsigned long>);
        REQUIRE(cortex::LeftBitShiftWith<long, unsigned long long>);
        
        // Long with Floating Point and Doubles
        REQUIRE(!cortex::LeftBitShiftWith<long, float>);
        REQUIRE(!cortex::LeftBitShiftWith<long, double>);
        REQUIRE(!cortex::LeftBitShiftWith<long, long double>);

        // Long with std::strings and std::string_view
        REQUIRE(!cortex::LeftBitShiftWith<long, std::string>);
        REQUIRE(!cortex::LeftBitShiftWith<long, std::string_view>);
        REQUIRE(!cortex::LeftBitShiftWith<long, std::u8string>);
        REQUIRE(!cortex::LeftBitShiftWith<long, std::u16string>);
        REQUIRE(!cortex::LeftBitShiftWith<long, std::u32string>);

        // Long with std::wstrings and std::wstring_view
        REQUIRE(!cortex::LeftBitShiftWith<long, std::wstring>);
        REQUIRE(!cortex::LeftBitShiftWith<long, std::wstring_view>);

        // Long with Charaters
        REQUIRE(cortex::LeftBitShiftWith<long, char>);
        REQUIRE(cortex::LeftBitShiftWith<long, u_char>);
        REQUIRE(cortex::LeftBitShiftWith<long, wchar_t>);

        // Long with Bit Specific Characters
        REQUIRE(cortex::LeftBitShiftWith<long, char8_t>);
        REQUIRE(cortex::LeftBitShiftWith<long, char16_t>);
        REQUIRE(cortex::LeftBitShiftWith<long, char32_t>);

        // Long with Bit Specific Long
        REQUIRE(cortex::LeftBitShiftWith<long, int8_t>);
        REQUIRE(cortex::LeftBitShiftWith<long, int16_t>);
        REQUIRE(cortex::LeftBitShiftWith<long, int32_t>);
        REQUIRE(cortex::LeftBitShiftWith<long, int64_t>);

        // Long with Bit Specific Unsigned Long
        REQUIRE(cortex::LeftBitShiftWith<long, uint8_t>);
        REQUIRE(cortex::LeftBitShiftWith<long, uint16_t>);
        REQUIRE(cortex::LeftBitShiftWith<long, uint32_t>);
        REQUIRE(cortex::LeftBitShiftWith<long, uint64_t>);

        // Long with Bit Specific Least Integers
        REQUIRE(cortex::LeftBitShiftWith<long, int_least8_t>);
        REQUIRE(cortex::LeftBitShiftWith<long, int_least16_t>);
        REQUIRE(cortex::LeftBitShiftWith<long, int_least32_t>);
        REQUIRE(cortex::LeftBitShiftWith<long, int_least64_t>);
    }

    SECTION("Long Long with _")
    {
        // Signed Integers
        REQUIRE(cortex::LeftBitShiftWith<long long, int>);
        REQUIRE(cortex::LeftBitShiftWith<long long, short>);
        REQUIRE(cortex::LeftBitShiftWith<long long, long>);
        REQUIRE(cortex::LeftBitShiftWith<long long, long long>);

        // Unsigned Integers
        REQUIRE(cortex::LeftBitShiftWith<long long, unsigned>);
        REQUIRE(cortex::LeftBitShiftWith<long long, unsigned short>);
        REQUIRE(cortex::LeftBitShiftWith<long long, u_short>);
        REQUIRE(cortex::LeftBitShiftWith<long long, unsigned long>);
        REQUIRE(cortex::LeftBitShiftWith<long long, unsigned long long>);
        
        // Integers with Floating Point and Doubles
        REQUIRE(!cortex::LeftBitShiftWith<long long, float>);
        REQUIRE(!cortex::LeftBitShiftWith<long long, double>);
        REQUIRE(!cortex::LeftBitShiftWith<long long, long double>);

        // Integers with std::strings and std::string_view
        REQUIRE(!cortex::LeftBitShiftWith<long long, std::string>);
        REQUIRE(!cortex::LeftBitShiftWith<long long, std::string_view>);
        REQUIRE(!cortex::LeftBitShiftWith<long long, std::u8string>);
        REQUIRE(!cortex::LeftBitShiftWith<long long, std::u16string>);
        REQUIRE(!cortex::LeftBitShiftWith<long long, std::u32string>);

        // Integers with std::wstrings and std::wstring_view
        REQUIRE(!cortex::LeftBitShiftWith<long long, std::wstring>);
        REQUIRE(!cortex::LeftBitShiftWith<long long, std::wstring_view>);

        // Integers with Charaters
        REQUIRE(cortex::LeftBitShiftWith<long long, char>);
        REQUIRE(cortex::LeftBitShiftWith<long long, u_char>);
        REQUIRE(cortex::LeftBitShiftWith<long long, wchar_t>);

        // Integers with Bit Specific Characters
        REQUIRE(cortex::LeftBitShiftWith<long long, char8_t>);
        REQUIRE(cortex::LeftBitShiftWith<long long, char16_t>);
        REQUIRE(cortex::LeftBitShiftWith<long long, char32_t>);

        // Integers with Bit Specific Integers
        REQUIRE(cortex::LeftBitShiftWith<long long, int8_t>);
        REQUIRE(cortex::LeftBitShiftWith<long long, int16_t>);
        REQUIRE(cortex::LeftBitShiftWith<long long, int32_t>);
        REQUIRE(cortex::LeftBitShiftWith<long long, int64_t>);

        // Integers with Bit Specific Unsigned Integers
        REQUIRE(cortex::LeftBitShiftWith<long long, uint8_t>);
        REQUIRE(cortex::LeftBitShiftWith<long long, uint16_t>);
        REQUIRE(cortex::LeftBitShiftWith<long long, uint32_t>);
        REQUIRE(cortex::LeftBitShiftWith<long long, uint64_t>);

        // Long Long with Bit Specific Least Integers
        REQUIRE(cortex::LeftBitShiftWith<long long, int_least8_t>);
        REQUIRE(cortex::LeftBitShiftWith<long long, int_least16_t>);
        REQUIRE(cortex::LeftBitShiftWith<long long, int_least32_t>);
        REQUIRE(cortex::LeftBitShiftWith<long long, int_least64_t>);
    }
}

TEST_CASE("LeftBitShiftWith: Unsigned Integers")
{
    SECTION("Unsigned Int with _")
    {
        // Unsigned Integers with Signed Integers
        REQUIRE(cortex::LeftBitShiftWith<unsigned int, int>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned int, short>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned int, long>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned int, long long>);

        // Unsigned Integers with Unsigned Integers
        REQUIRE(cortex::LeftBitShiftWith<unsigned int, unsigned>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned int, unsigned short>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned int, u_short>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned int, unsigned long>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned int, unsigned long long>);
        
        // Unsigned Integers with Floating Point and Doubles
        REQUIRE(!cortex::LeftBitShiftWith<unsigned int, float>);
        REQUIRE(!cortex::LeftBitShiftWith<unsigned int, double>);
        REQUIRE(!cortex::LeftBitShiftWith<unsigned int, long double>);

        // Unsigned Integers with std::strings and std::string_view
        REQUIRE(!cortex::LeftBitShiftWith<unsigned int, std::string>);
        REQUIRE(!cortex::LeftBitShiftWith<unsigned int, std::string_view>);
        REQUIRE(!cortex::LeftBitShiftWith<unsigned int, std::u8string>);
        REQUIRE(!cortex::LeftBitShiftWith<unsigned int, std::u16string>);
        REQUIRE(!cortex::LeftBitShiftWith<unsigned int, std::u32string>);

        // Unsigned Integers with std::wstrings and std::wstring_view
        REQUIRE(!cortex::LeftBitShiftWith<unsigned long long, std::wstring>);
        REQUIRE(!cortex::LeftBitShiftWith<unsigned long long, std::wstring_view>);

        // Unsigned Integers with Charaters
        REQUIRE(cortex::LeftBitShiftWith<unsigned int, char>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned int, u_char>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned int, wchar_t>);

        // Unsigned Integers with Bit Specific Characters
        REQUIRE(cortex::LeftBitShiftWith<unsigned int, char8_t>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned int, char16_t>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned int, char32_t>);

        // Unsigned Integers with Bit Specific Integers
        REQUIRE(cortex::LeftBitShiftWith<unsigned int, int8_t>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned int, int16_t>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned int, int32_t>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned int, int64_t>);

        // Unsigned Integers with Bit Specific Unsigned Integers
        REQUIRE(cortex::LeftBitShiftWith<unsigned int, uint8_t>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned int, uint16_t>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned int, uint32_t>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned int, uint64_t>);

        // Unsigned Integers with Bit Specific Least Integers
        REQUIRE(cortex::LeftBitShiftWith<unsigned int, int_least8_t>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned int, int_least16_t>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned int, int_least32_t>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned int, int_least64_t>);
    }

    SECTION("Unsigned Short with _")
    {
        // Unsigned Short with Signed Integers
        REQUIRE(cortex::LeftBitShiftWith<unsigned short, int>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned short, short>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned short, long>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned short, long long>);

        // Unsigned Short with Unsigned Integers
        REQUIRE(cortex::LeftBitShiftWith<unsigned short, unsigned>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned short, unsigned short>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned short, u_short>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned short, unsigned long>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned short, unsigned long long>);
        
        // Unsigned Short with Floating Point and Doubles
        REQUIRE(!cortex::LeftBitShiftWith<unsigned short, float>);
        REQUIRE(!cortex::LeftBitShiftWith<unsigned short, double>);
        REQUIRE(!cortex::LeftBitShiftWith<unsigned short, long double>);

        // Unsigned Short with std::strings and std::string_view
        REQUIRE(!cortex::LeftBitShiftWith<unsigned short, std::string>);
        REQUIRE(!cortex::LeftBitShiftWith<unsigned short, std::string_view>);
        REQUIRE(!cortex::LeftBitShiftWith<unsigned short, std::u8string>);
        REQUIRE(!cortex::LeftBitShiftWith<unsigned short, std::u16string>);
        REQUIRE(!cortex::LeftBitShiftWith<unsigned short, std::u32string>);

        // Unsigned Short with std::wstrings and std::wstring_view
        REQUIRE(!cortex::LeftBitShiftWith<unsigned short, std::wstring>);
        REQUIRE(!cortex::LeftBitShiftWith<unsigned short, std::wstring_view>);

        // Unsigned Short with Charaters
        REQUIRE(cortex::LeftBitShiftWith<unsigned short, char>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned short, u_char>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned short, wchar_t>);

        // Unsigned Short with Bit Specific Characters
        REQUIRE(cortex::LeftBitShiftWith<unsigned short, char8_t>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned short, char16_t>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned short, char32_t>);

        // Unsigned Short with Bit Specific Short
        REQUIRE(cortex::LeftBitShiftWith<unsigned short, int8_t>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned short, int16_t>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned short, int32_t>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned short, int64_t>);

        // Unsigned Short with Bit Specific Unsigned Short
        REQUIRE(cortex::LeftBitShiftWith<unsigned short, uint8_t>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned short, uint16_t>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned short, uint32_t>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned short, uint64_t>);

        // Unsigned Short with Bit Specific Least Integers
        REQUIRE(cortex::LeftBitShiftWith<unsigned short, int_least8_t>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned short, int_least16_t>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned short, int_least32_t>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned short, int_least64_t>);
    }

    SECTION("u_short with _")
    {
        // u_short with Signed Integers
        REQUIRE(cortex::LeftBitShiftWith<u_short, int>);
        REQUIRE(cortex::LeftBitShiftWith<u_short, short>);
        REQUIRE(cortex::LeftBitShiftWith<u_short, long>);
        REQUIRE(cortex::LeftBitShiftWith<u_short, long long>);

        // u_short with Unsigned Integers
        REQUIRE(cortex::LeftBitShiftWith<u_short, unsigned>);
        REQUIRE(cortex::LeftBitShiftWith<u_short, unsigned short>);
        REQUIRE(cortex::LeftBitShiftWith<u_short, u_short>);
        REQUIRE(cortex::LeftBitShiftWith<u_short, unsigned long>);
        REQUIRE(cortex::LeftBitShiftWith<u_short, unsigned long long>);
        
        // u_short with Floating Point and Doubles
        REQUIRE(!cortex::LeftBitShiftWith<u_short, float>);
        REQUIRE(!cortex::LeftBitShiftWith<u_short, double>);
        REQUIRE(!cortex::LeftBitShiftWith<u_short, long double>);

        // u_short with std::strings and std::string_view
        REQUIRE(!cortex::LeftBitShiftWith<u_short, std::string>);
        REQUIRE(!cortex::LeftBitShiftWith<u_short, std::string_view>);
        REQUIRE(!cortex::LeftBitShiftWith<u_short, std::u8string>);
        REQUIRE(!cortex::LeftBitShiftWith<u_short, std::u16string>);
        REQUIRE(!cortex::LeftBitShiftWith<u_short, std::u32string>);

        // u_short with std::wstrings and std::wstring_view
        REQUIRE(!cortex::LeftBitShiftWith<u_short, std::wstring>);
        REQUIRE(!cortex::LeftBitShiftWith<u_short, std::wstring_view>);

        // u_short with Charaters
        REQUIRE(cortex::LeftBitShiftWith<u_short, char>);
        REQUIRE(cortex::LeftBitShiftWith<u_short, u_char>);
        REQUIRE(cortex::LeftBitShiftWith<u_short, wchar_t>);

        // u_short with Bit Specific Characters
        REQUIRE(cortex::LeftBitShiftWith<u_short, char8_t>);
        REQUIRE(cortex::LeftBitShiftWith<u_short, char16_t>);
        REQUIRE(cortex::LeftBitShiftWith<u_short, char32_t>);

        // u_short with Bit Specific Short
        REQUIRE(cortex::LeftBitShiftWith<u_short, int8_t>);
        REQUIRE(cortex::LeftBitShiftWith<u_short, int16_t>);
        REQUIRE(cortex::LeftBitShiftWith<u_short, int32_t>);
        REQUIRE(cortex::LeftBitShiftWith<u_short, int64_t>);

        // u_short with Bit Specific Unsigned Short
        REQUIRE(cortex::LeftBitShiftWith<u_short, uint8_t>);
        REQUIRE(cortex::LeftBitShiftWith<u_short, uint16_t>);
        REQUIRE(cortex::LeftBitShiftWith<u_short, uint32_t>);
        REQUIRE(cortex::LeftBitShiftWith<u_short, uint64_t>);

        // u_short with Bit Specific Least Integers
        REQUIRE(cortex::LeftBitShiftWith<u_short, int_least8_t>);
        REQUIRE(cortex::LeftBitShiftWith<u_short, int_least16_t>);
        REQUIRE(cortex::LeftBitShiftWith<u_short, int_least32_t>);
        REQUIRE(cortex::LeftBitShiftWith<u_short, int_least64_t>);
    }

    SECTION("Unsigned Long with _")
    {
        // Unsigned Long with Signed Integers
        REQUIRE(cortex::LeftBitShiftWith<unsigned long, int>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned long, short>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned long, long>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned long, long long>);

        // Unsigned Long with Unsigned Integers
        REQUIRE(cortex::LeftBitShiftWith<unsigned long, unsigned>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned long, unsigned short>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned long, u_short>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned long, unsigned long>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned long, unsigned long long>);
        
        // Unsigned Long with Floating Point and Doubles
        REQUIRE(!cortex::LeftBitShiftWith<unsigned long, float>);
        REQUIRE(!cortex::LeftBitShiftWith<unsigned long, double>);
        REQUIRE(!cortex::LeftBitShiftWith<unsigned long, long double>);

        // Unsigned Long with std::strings and std::string_view
        REQUIRE(!cortex::LeftBitShiftWith<unsigned long, std::string>);
        REQUIRE(!cortex::LeftBitShiftWith<unsigned long, std::string_view>);
        REQUIRE(!cortex::LeftBitShiftWith<unsigned long, std::u8string>);
        REQUIRE(!cortex::LeftBitShiftWith<unsigned long, std::u16string>);
        REQUIRE(!cortex::LeftBitShiftWith<unsigned long, std::u32string>);

        // Unsigned Long with std::wstrings and std::wstring_view
        REQUIRE(!cortex::LeftBitShiftWith<unsigned long, std::wstring>);
        REQUIRE(!cortex::LeftBitShiftWith<unsigned long, std::wstring_view>);

        // Unsigned Long with Charaters
        REQUIRE(cortex::LeftBitShiftWith<unsigned long, char>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned long, u_char>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned long, wchar_t>);

        // Unsigned Long with Bit Specific Characters
        REQUIRE(cortex::LeftBitShiftWith<unsigned long, char8_t>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned long, char16_t>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned long, char32_t>);

        // Unsigned Long with Bit Specific Long
        REQUIRE(cortex::LeftBitShiftWith<unsigned long, int8_t>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned long, int16_t>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned long, int32_t>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned long, int64_t>);

        // Unsigned Long with Bit Specific Unsigned Long
        REQUIRE(cortex::LeftBitShiftWith<unsigned long, uint8_t>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned long, uint16_t>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned long, uint32_t>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned long, uint64_t>);

        // Unsigned Long with Bit Specific Least Integers
        REQUIRE(cortex::LeftBitShiftWith<unsigned long, int_least8_t>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned long, int_least16_t>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned long, int_least32_t>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned long, int_least64_t>);
    }

    SECTION("Unsigned Long Long with _")
    {
        // Unsigned Long Long with Signed Integers
        REQUIRE(cortex::LeftBitShiftWith<unsigned long long, int>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned long long, short>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned long long, long>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned long long, long long>);

        // Unsigned Long Long with Unsigned Integers
        REQUIRE(cortex::LeftBitShiftWith<unsigned long long, unsigned>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned long long, unsigned short>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned long long, u_short>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned long long, unsigned long>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned long long, unsigned long long>);
        
        // Unsigned Long Long with Floating Point and Doubles
        REQUIRE(!cortex::LeftBitShiftWith<unsigned long long, float>);
        REQUIRE(!cortex::LeftBitShiftWith<unsigned long long, double>);
        REQUIRE(!cortex::LeftBitShiftWith<unsigned long long, long double>);

        // Unsigned Long Long with std::strings and std::string_view
        REQUIRE(!cortex::LeftBitShiftWith<unsigned long long, std::string>);
        REQUIRE(!cortex::LeftBitShiftWith<unsigned long long, std::string_view>);
        REQUIRE(!cortex::LeftBitShiftWith<unsigned long long, std::u8string>);
        REQUIRE(!cortex::LeftBitShiftWith<unsigned long long, std::u16string>);
        REQUIRE(!cortex::LeftBitShiftWith<unsigned long long, std::u32string>);

        // Unsigned Long Long with std::wstrings and std::wstring_view
        REQUIRE(!cortex::LeftBitShiftWith<unsigned long long, std::wstring>);
        REQUIRE(!cortex::LeftBitShiftWith<unsigned long long, std::wstring_view>);

        // Unsigned Long Long with Charaters
        REQUIRE(cortex::LeftBitShiftWith<unsigned long long, char>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned long long, u_char>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned long long, wchar_t>);

        // Unsigned Long Long with Bit Specific Characters
        REQUIRE(cortex::LeftBitShiftWith<unsigned long long, char8_t>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned long long, char16_t>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned long long, char32_t>);

        // Unsigned Long Long with Bit Specific Long Long
        REQUIRE(cortex::LeftBitShiftWith<unsigned long long, int8_t>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned long long, int16_t>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned long long, int32_t>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned long long, int64_t>);

        // Unsigned Long Long with Bit Specific Unsigned Long Long
        REQUIRE(cortex::LeftBitShiftWith<unsigned long long, uint8_t>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned long long, uint16_t>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned long long, uint32_t>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned long long, uint64_t>);

        // Long Long with Bit Specific Least Long Long
        REQUIRE(cortex::LeftBitShiftWith<unsigned long long, int_least8_t>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned long long, int_least16_t>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned long long, int_least32_t>);
        REQUIRE(cortex::LeftBitShiftWith<unsigned long long, int_least64_t>);
    }
}

TEST_CASE("Addable With : Bit Specific Signed Integers")
{
    SECTION("int8_t with _")
    {
        // int8_t with Signed Integers
        REQUIRE(cortex::LeftBitShiftWith<int8_t, int>);
        REQUIRE(cortex::LeftBitShiftWith<int8_t, short>);
        REQUIRE(cortex::LeftBitShiftWith<int8_t, long>);
        REQUIRE(cortex::LeftBitShiftWith<int8_t, long long>);

        // int8_t with Unsigned Integers
        REQUIRE(cortex::LeftBitShiftWith<int8_t, unsigned>);
        REQUIRE(cortex::LeftBitShiftWith<int8_t, unsigned short>);
        REQUIRE(cortex::LeftBitShiftWith<int8_t, u_short>);
        REQUIRE(cortex::LeftBitShiftWith<int8_t, unsigned long>);
        REQUIRE(cortex::LeftBitShiftWith<int8_t, unsigned long long>);
        
        // int8_t with Floating Point and Doubles
        REQUIRE(!cortex::LeftBitShiftWith<int8_t, float>);
        REQUIRE(!cortex::LeftBitShiftWith<int8_t, double>);
        REQUIRE(!cortex::LeftBitShiftWith<int8_t, long double>);

        // int8_t with std::strings and std::string_view
        REQUIRE(!cortex::LeftBitShiftWith<int8_t, std::string>);
        REQUIRE(!cortex::LeftBitShiftWith<int8_t, std::string_view>);
        REQUIRE(!cortex::LeftBitShiftWith<int8_t, std::u8string>);
        REQUIRE(!cortex::LeftBitShiftWith<int8_t, std::u16string>);
        REQUIRE(!cortex::LeftBitShiftWith<int8_t, std::u32string>);

        // int8_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::LeftBitShiftWith<long long, std::wstring>);
        REQUIRE(!cortex::LeftBitShiftWith<long long, std::wstring_view>);

        // int8_t with Charaters
        REQUIRE(cortex::LeftBitShiftWith<int8_t, char>);
        REQUIRE(cortex::LeftBitShiftWith<int8_t, u_char>);
        REQUIRE(cortex::LeftBitShiftWith<int8_t, wchar_t>);

        // int8_t with Bit Specific Characters
        REQUIRE(cortex::LeftBitShiftWith<int8_t, char8_t>);
        REQUIRE(cortex::LeftBitShiftWith<int8_t, char16_t>);
        REQUIRE(cortex::LeftBitShiftWith<int8_t, char32_t>);

        // int8_t with Bit Specific Integers
        REQUIRE(cortex::LeftBitShiftWith<int8_t, int8_t>);
        REQUIRE(cortex::LeftBitShiftWith<int8_t, int16_t>);
        REQUIRE(cortex::LeftBitShiftWith<int8_t, int32_t>);
        REQUIRE(cortex::LeftBitShiftWith<int8_t, int64_t>);

        // int8_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::LeftBitShiftWith<int8_t, uint8_t>);
        REQUIRE(cortex::LeftBitShiftWith<int8_t, uint16_t>);
        REQUIRE(cortex::LeftBitShiftWith<int8_t, uint32_t>);
        REQUIRE(cortex::LeftBitShiftWith<int8_t, uint64_t>);

        // int8_t with Bit Specific Least Integers
        REQUIRE(cortex::LeftBitShiftWith<int8_t, int_least8_t>);
        REQUIRE(cortex::LeftBitShiftWith<int8_t, int_least16_t>);
        REQUIRE(cortex::LeftBitShiftWith<int8_t, int_least32_t>);
        REQUIRE(cortex::LeftBitShiftWith<int8_t, int_least64_t>);
    }

    SECTION("int16_t with _")
    {
        // int16_t with Signed Integers
        REQUIRE(cortex::LeftBitShiftWith<int16_t, int>);
        REQUIRE(cortex::LeftBitShiftWith<int16_t, short>);
        REQUIRE(cortex::LeftBitShiftWith<int16_t, long>);
        REQUIRE(cortex::LeftBitShiftWith<int16_t, long long>);

        // int16_t with Unsigned Integers
        REQUIRE(cortex::LeftBitShiftWith<int16_t, unsigned>);
        REQUIRE(cortex::LeftBitShiftWith<int16_t, unsigned short>);
        REQUIRE(cortex::LeftBitShiftWith<int16_t, u_short>);
        REQUIRE(cortex::LeftBitShiftWith<int16_t, unsigned long>);
        REQUIRE(cortex::LeftBitShiftWith<int16_t, unsigned long long>);
        
        // int16_t with Floating Point and Doubles
        REQUIRE(!cortex::LeftBitShiftWith<int16_t, float>);
        REQUIRE(!cortex::LeftBitShiftWith<int16_t, double>);
        REQUIRE(!cortex::LeftBitShiftWith<int16_t, long double>);

        // int16_t with std::strings and std::string_view
        REQUIRE(!cortex::LeftBitShiftWith<int16_t, std::string>);
        REQUIRE(!cortex::LeftBitShiftWith<int16_t, std::string_view>);
        REQUIRE(!cortex::LeftBitShiftWith<int16_t, std::u8string>);
        REQUIRE(!cortex::LeftBitShiftWith<int16_t, std::u16string>);
        REQUIRE(!cortex::LeftBitShiftWith<int16_t, std::u32string>);

        // int16_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::LeftBitShiftWith<int16_t, std::wstring>);
        REQUIRE(!cortex::LeftBitShiftWith<int16_t, std::wstring_view>);

        // int16_t with Charaters
        REQUIRE(cortex::LeftBitShiftWith<int16_t, char>);
        REQUIRE(cortex::LeftBitShiftWith<int16_t, u_char>);
        REQUIRE(cortex::LeftBitShiftWith<int16_t, wchar_t>);

        // int16_t with Bit Specific Characters
        REQUIRE(cortex::LeftBitShiftWith<int16_t, char8_t>);
        REQUIRE(cortex::LeftBitShiftWith<int16_t, char16_t>);
        REQUIRE(cortex::LeftBitShiftWith<int16_t, char32_t>);

        // int16_t with Bit Specific Integers
        REQUIRE(cortex::LeftBitShiftWith<int16_t, int8_t>);
        REQUIRE(cortex::LeftBitShiftWith<int16_t, int16_t>);
        REQUIRE(cortex::LeftBitShiftWith<int16_t, int32_t>);
        REQUIRE(cortex::LeftBitShiftWith<int16_t, int64_t>);

        // int16_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::LeftBitShiftWith<int16_t, uint8_t>);
        REQUIRE(cortex::LeftBitShiftWith<int16_t, uint16_t>);
        REQUIRE(cortex::LeftBitShiftWith<int16_t, uint32_t>);
        REQUIRE(cortex::LeftBitShiftWith<int16_t, uint64_t>);

        // int16_t with Bit Specific Least Integers
        REQUIRE(cortex::LeftBitShiftWith<int16_t, int_least8_t>);
        REQUIRE(cortex::LeftBitShiftWith<int16_t, int_least16_t>);
        REQUIRE(cortex::LeftBitShiftWith<int16_t, int_least32_t>);
        REQUIRE(cortex::LeftBitShiftWith<int16_t, int_least64_t>);
    }

    SECTION("int32 with _")
    {
        // int32 with Signed Integers
        REQUIRE(cortex::LeftBitShiftWith<int32_t, int>);
        REQUIRE(cortex::LeftBitShiftWith<int32_t, short>);
        REQUIRE(cortex::LeftBitShiftWith<int32_t, long>);
        REQUIRE(cortex::LeftBitShiftWith<int32_t, long long>);

        // int32 with Unsigned Integers
        REQUIRE(cortex::LeftBitShiftWith<int32_t, unsigned>);
        REQUIRE(cortex::LeftBitShiftWith<int32_t, unsigned short>);
        REQUIRE(cortex::LeftBitShiftWith<int32_t, u_short>);
        REQUIRE(cortex::LeftBitShiftWith<int32_t, unsigned long>);
        REQUIRE(cortex::LeftBitShiftWith<int32_t, unsigned long long>);
        
        // int32 with Floating Point and Doubles
        REQUIRE(!cortex::LeftBitShiftWith<int32_t, float>);
        REQUIRE(!cortex::LeftBitShiftWith<int32_t, double>);
        REQUIRE(!cortex::LeftBitShiftWith<int32_t, long double>);

        // int32 with std::strings and std::string_view
        REQUIRE(!cortex::LeftBitShiftWith<int32_t, std::string>);
        REQUIRE(!cortex::LeftBitShiftWith<int32_t, std::string_view>);
        REQUIRE(!cortex::LeftBitShiftWith<int32_t, std::u8string>);
        REQUIRE(!cortex::LeftBitShiftWith<int32_t, std::u16string>);
        REQUIRE(!cortex::LeftBitShiftWith<int32_t, std::u32string>);

        // int32 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::LeftBitShiftWith<int32_t, std::wstring>);
        REQUIRE(!cortex::LeftBitShiftWith<int32_t, std::wstring_view>);

        // int32_t with Charaters
        REQUIRE(cortex::LeftBitShiftWith<int32_t, char>);
        REQUIRE(cortex::LeftBitShiftWith<int32_t, u_char>);
        REQUIRE(cortex::LeftBitShiftWith<int32_t, wchar_t>);

        // int32_t with Bit Specific Characters
        REQUIRE(cortex::LeftBitShiftWith<int32_t, char8_t>);
        REQUIRE(cortex::LeftBitShiftWith<int32_t, char16_t>);
        REQUIRE(cortex::LeftBitShiftWith<int32_t, char32_t>);

        // int32_t with Bit Specific Integers
        REQUIRE(cortex::LeftBitShiftWith<int32_t, int8_t>);
        REQUIRE(cortex::LeftBitShiftWith<int32_t, int16_t>);
        REQUIRE(cortex::LeftBitShiftWith<int32_t, int32_t>);
        REQUIRE(cortex::LeftBitShiftWith<int32_t, int64_t>);

        // int32_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::LeftBitShiftWith<int32_t, uint8_t>);
        REQUIRE(cortex::LeftBitShiftWith<int32_t, uint16_t>);
        REQUIRE(cortex::LeftBitShiftWith<int32_t, uint32_t>);
        REQUIRE(cortex::LeftBitShiftWith<int32_t, uint64_t>);

        // int32_t with Bit Specific Least Integers
        REQUIRE(cortex::LeftBitShiftWith<int32_t, int_least8_t>);
        REQUIRE(cortex::LeftBitShiftWith<int32_t, int_least16_t>);
        REQUIRE(cortex::LeftBitShiftWith<int32_t, int_least32_t>);
        REQUIRE(cortex::LeftBitShiftWith<int32_t, int_least64_t>);
    }

    SECTION("int64 with _")
    {
        // int64 with Signed Integers
        REQUIRE(cortex::LeftBitShiftWith<int64_t, int>);
        REQUIRE(cortex::LeftBitShiftWith<int64_t, short>);
        REQUIRE(cortex::LeftBitShiftWith<int64_t, long>);
        REQUIRE(cortex::LeftBitShiftWith<int64_t, long long>);

        // int64 with Unsigned Integers
        REQUIRE(cortex::LeftBitShiftWith<int64_t, unsigned>);
        REQUIRE(cortex::LeftBitShiftWith<int64_t, unsigned short>);
        REQUIRE(cortex::LeftBitShiftWith<int64_t, u_short>);
        REQUIRE(cortex::LeftBitShiftWith<int64_t, unsigned long>);
        REQUIRE(cortex::LeftBitShiftWith<int64_t, unsigned long long>);
        
        // int64 with Floating Point and Doubles
        REQUIRE(!cortex::LeftBitShiftWith<int64_t, float>);
        REQUIRE(!cortex::LeftBitShiftWith<int64_t, double>);
        REQUIRE(!cortex::LeftBitShiftWith<int64_t, long double>);

        // int64 with std::strings and std::string_view
        REQUIRE(!cortex::LeftBitShiftWith<int64_t, std::string>);
        REQUIRE(!cortex::LeftBitShiftWith<int64_t, std::string_view>);
        REQUIRE(!cortex::LeftBitShiftWith<int64_t, std::u8string>);
        REQUIRE(!cortex::LeftBitShiftWith<int64_t, std::u16string>);
        REQUIRE(!cortex::LeftBitShiftWith<int64_t, std::u32string>);

        // int64 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::LeftBitShiftWith<int64_t, std::wstring>);
        REQUIRE(!cortex::LeftBitShiftWith<int64_t, std::wstring_view>);

        // int64_t with Charaters
        REQUIRE(cortex::LeftBitShiftWith<int64_t, char>);
        REQUIRE(cortex::LeftBitShiftWith<int64_t, u_char>);
        REQUIRE(cortex::LeftBitShiftWith<int64_t, wchar_t>);

        // int64_t with Bit Specific Characters
        REQUIRE(cortex::LeftBitShiftWith<int64_t, char8_t>);
        REQUIRE(cortex::LeftBitShiftWith<int64_t, char16_t>);
        REQUIRE(cortex::LeftBitShiftWith<int64_t, char32_t>);

        // int64_t with Bit Specific Integers
        REQUIRE(cortex::LeftBitShiftWith<int64_t, int8_t>);
        REQUIRE(cortex::LeftBitShiftWith<int64_t, int16_t>);
        REQUIRE(cortex::LeftBitShiftWith<int64_t, int32_t>);
        REQUIRE(cortex::LeftBitShiftWith<int64_t, int64_t>);

        // int64_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::LeftBitShiftWith<int64_t, uint8_t>);
        REQUIRE(cortex::LeftBitShiftWith<int64_t, uint16_t>);
        REQUIRE(cortex::LeftBitShiftWith<int64_t, uint32_t>);
        REQUIRE(cortex::LeftBitShiftWith<int64_t, uint64_t>);

        // int64_t with Bit Specific Least Integers
        REQUIRE(cortex::LeftBitShiftWith<int64_t, int_least8_t>);
        REQUIRE(cortex::LeftBitShiftWith<int64_t, int_least16_t>);
        REQUIRE(cortex::LeftBitShiftWith<int64_t, int_least32_t>);
        REQUIRE(cortex::LeftBitShiftWith<int64_t, int_least64_t>);
}
}

TEST_CASE("Addable With : Bit Specific Unsigned Integers")
{
    SECTION("uint8_t with _")
    {
        // uint8_t with Signed Integers
        REQUIRE(cortex::LeftBitShiftWith<uint8_t, int>);
        REQUIRE(cortex::LeftBitShiftWith<uint8_t, short>);
        REQUIRE(cortex::LeftBitShiftWith<uint8_t, long>);
        REQUIRE(cortex::LeftBitShiftWith<uint8_t, long long>);

        // uint8_t with Unsigned Integers
        REQUIRE(cortex::LeftBitShiftWith<uint8_t, unsigned>);
        REQUIRE(cortex::LeftBitShiftWith<uint8_t, unsigned short>);
        REQUIRE(cortex::LeftBitShiftWith<uint8_t, u_short>);
        REQUIRE(cortex::LeftBitShiftWith<uint8_t, unsigned long>);
        REQUIRE(cortex::LeftBitShiftWith<uint8_t, unsigned long long>);
        
        // uint8_t with Floating Point and Doubles
        REQUIRE(!cortex::LeftBitShiftWith<uint8_t, float>);
        REQUIRE(!cortex::LeftBitShiftWith<uint8_t, double>);
        REQUIRE(!cortex::LeftBitShiftWith<uint8_t, long double>);

        // uint8_t with std::strings and std::string_view
        REQUIRE(!cortex::LeftBitShiftWith<uint8_t, std::string>);
        REQUIRE(!cortex::LeftBitShiftWith<uint8_t, std::string_view>);
        REQUIRE(!cortex::LeftBitShiftWith<uint8_t, std::u8string>);
        REQUIRE(!cortex::LeftBitShiftWith<uint8_t, std::u16string>);
        REQUIRE(!cortex::LeftBitShiftWith<uint8_t, std::u32string>);

        // uint8_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::LeftBitShiftWith<long long, std::wstring>);
        REQUIRE(!cortex::LeftBitShiftWith<long long, std::wstring_view>);

        // uint8_t with Charaters
        REQUIRE(cortex::LeftBitShiftWith<uint8_t, char>);
        REQUIRE(cortex::LeftBitShiftWith<uint8_t, u_char>);
        REQUIRE(cortex::LeftBitShiftWith<uint8_t, wchar_t>);

        // uint8_t with Bit Specific Characters
        REQUIRE(cortex::LeftBitShiftWith<uint8_t, char8_t>);
        REQUIRE(cortex::LeftBitShiftWith<uint8_t, char16_t>);
        REQUIRE(cortex::LeftBitShiftWith<uint8_t, char32_t>);

        // uint8_t with Bit Specific Integers
        REQUIRE(cortex::LeftBitShiftWith<uint8_t, int8_t>);
        REQUIRE(cortex::LeftBitShiftWith<uint8_t, int16_t>);
        REQUIRE(cortex::LeftBitShiftWith<uint8_t, int32_t>);
        REQUIRE(cortex::LeftBitShiftWith<uint8_t, int64_t>);

        // uint8_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::LeftBitShiftWith<uint8_t, uint8_t>);
        REQUIRE(cortex::LeftBitShiftWith<uint8_t, uint16_t>);
        REQUIRE(cortex::LeftBitShiftWith<uint8_t, uint32_t>);
        REQUIRE(cortex::LeftBitShiftWith<uint8_t, uint64_t>);

        // uint8_t with Bit Specific Least Integers
        REQUIRE(cortex::LeftBitShiftWith<uint8_t, int_least8_t>);
        REQUIRE(cortex::LeftBitShiftWith<uint8_t, int_least16_t>);
        REQUIRE(cortex::LeftBitShiftWith<uint8_t, int_least32_t>);
        REQUIRE(cortex::LeftBitShiftWith<uint8_t, int_least64_t>);
    }

    SECTION("uint16_t with _")
    {
        // uint16_t with Signed Integers
        REQUIRE(cortex::LeftBitShiftWith<uint16_t, int>);
        REQUIRE(cortex::LeftBitShiftWith<uint16_t, short>);
        REQUIRE(cortex::LeftBitShiftWith<uint16_t, long>);
        REQUIRE(cortex::LeftBitShiftWith<uint16_t, long long>);

        // uint16_t with Unsigned Integers
        REQUIRE(cortex::LeftBitShiftWith<uint16_t, unsigned>);
        REQUIRE(cortex::LeftBitShiftWith<uint16_t, unsigned short>);
        REQUIRE(cortex::LeftBitShiftWith<uint16_t, u_short>);
        REQUIRE(cortex::LeftBitShiftWith<uint16_t, unsigned long>);
        REQUIRE(cortex::LeftBitShiftWith<uint16_t, unsigned long long>);
        
        // uint16_t with Floating Point and Doubles
        REQUIRE(!cortex::LeftBitShiftWith<uint16_t, float>);
        REQUIRE(!cortex::LeftBitShiftWith<uint16_t, double>);
        REQUIRE(!cortex::LeftBitShiftWith<uint16_t, long double>);

        // uint16_t with std::strings and std::string_view
        REQUIRE(!cortex::LeftBitShiftWith<uint16_t, std::string>);
        REQUIRE(!cortex::LeftBitShiftWith<uint16_t, std::string_view>);
        REQUIRE(!cortex::LeftBitShiftWith<uint16_t, std::u8string>);
        REQUIRE(!cortex::LeftBitShiftWith<uint16_t, std::u16string>);
        REQUIRE(!cortex::LeftBitShiftWith<uint16_t, std::u32string>);

        // uint16_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::LeftBitShiftWith<uint16_t, std::wstring>);
        REQUIRE(!cortex::LeftBitShiftWith<uint16_t, std::wstring_view>);

        // uint16_t with Charaters
        REQUIRE(cortex::LeftBitShiftWith<uint16_t, char>);
        REQUIRE(cortex::LeftBitShiftWith<uint16_t, u_char>);
        REQUIRE(cortex::LeftBitShiftWith<uint16_t, wchar_t>);

        // uint16_t with Bit Specific Characters
        REQUIRE(cortex::LeftBitShiftWith<uint16_t, char8_t>);
        REQUIRE(cortex::LeftBitShiftWith<uint16_t, char16_t>);
        REQUIRE(cortex::LeftBitShiftWith<uint16_t, char32_t>);

        // uint16_t with Bit Specific Integers
        REQUIRE(cortex::LeftBitShiftWith<uint16_t, int8_t>);
        REQUIRE(cortex::LeftBitShiftWith<uint16_t, int16_t>);
        REQUIRE(cortex::LeftBitShiftWith<uint16_t, int32_t>);
        REQUIRE(cortex::LeftBitShiftWith<uint16_t, int64_t>);

        // uint16_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::LeftBitShiftWith<uint16_t, uint8_t>);
        REQUIRE(cortex::LeftBitShiftWith<uint16_t, uint16_t>);
        REQUIRE(cortex::LeftBitShiftWith<uint16_t, uint32_t>);
        REQUIRE(cortex::LeftBitShiftWith<uint16_t, uint64_t>);

        // uint16_t with Bit Specific Least Integers
        REQUIRE(cortex::LeftBitShiftWith<uint16_t, int_least8_t>);
        REQUIRE(cortex::LeftBitShiftWith<uint16_t, int_least16_t>);
        REQUIRE(cortex::LeftBitShiftWith<uint16_t, int_least32_t>);
        REQUIRE(cortex::LeftBitShiftWith<uint16_t, int_least64_t>);
    }

    SECTION("uint32_t with _")
    {
        // int32 with Signed Integers
        REQUIRE(cortex::LeftBitShiftWith<uint32_t, int>);
        REQUIRE(cortex::LeftBitShiftWith<uint32_t, short>);
        REQUIRE(cortex::LeftBitShiftWith<uint32_t, long>);
        REQUIRE(cortex::LeftBitShiftWith<uint32_t, long long>);

        // int32 with Unsigned Integers
        REQUIRE(cortex::LeftBitShiftWith<uint32_t, unsigned>);
        REQUIRE(cortex::LeftBitShiftWith<uint32_t, unsigned short>);
        REQUIRE(cortex::LeftBitShiftWith<uint32_t, u_short>);
        REQUIRE(cortex::LeftBitShiftWith<uint32_t, unsigned long>);
        REQUIRE(cortex::LeftBitShiftWith<uint32_t, unsigned long long>);
        
        // int32 with Floating Point and Doubles
        REQUIRE(!cortex::LeftBitShiftWith<uint32_t, float>);
        REQUIRE(!cortex::LeftBitShiftWith<uint32_t, double>);
        REQUIRE(!cortex::LeftBitShiftWith<uint32_t, long double>);

        // int32 with std::strings and std::string_view
        REQUIRE(!cortex::LeftBitShiftWith<uint32_t, std::string>);
        REQUIRE(!cortex::LeftBitShiftWith<uint32_t, std::string_view>);
        REQUIRE(!cortex::LeftBitShiftWith<uint32_t, std::u8string>);
        REQUIRE(!cortex::LeftBitShiftWith<uint32_t, std::u16string>);
        REQUIRE(!cortex::LeftBitShiftWith<uint32_t, std::u32string>);

        // int32 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::LeftBitShiftWith<uint32_t, std::wstring>);
        REQUIRE(!cortex::LeftBitShiftWith<uint32_t, std::wstring_view>);

        // uint32_t with Charaters
        REQUIRE(cortex::LeftBitShiftWith<uint32_t, char>);
        REQUIRE(cortex::LeftBitShiftWith<uint32_t, u_char>);
        REQUIRE(cortex::LeftBitShiftWith<uint32_t, wchar_t>);

        // uint32_t with Bit Specific Characters
        REQUIRE(cortex::LeftBitShiftWith<uint32_t, char8_t>);
        REQUIRE(cortex::LeftBitShiftWith<uint32_t, char16_t>);
        REQUIRE(cortex::LeftBitShiftWith<uint32_t, char32_t>);

        // uint32_t with Bit Specific Integers
        REQUIRE(cortex::LeftBitShiftWith<uint32_t, int8_t>);
        REQUIRE(cortex::LeftBitShiftWith<uint32_t, int16_t>);
        REQUIRE(cortex::LeftBitShiftWith<uint32_t, int32_t>);
        REQUIRE(cortex::LeftBitShiftWith<uint32_t, int64_t>);

        // uint32_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::LeftBitShiftWith<uint32_t, uint8_t>);
        REQUIRE(cortex::LeftBitShiftWith<uint32_t, uint16_t>);
        REQUIRE(cortex::LeftBitShiftWith<uint32_t, uint32_t>);
        REQUIRE(cortex::LeftBitShiftWith<uint32_t, uint64_t>);

        // uint32_t with Bit Specific Least Integers
        REQUIRE(cortex::LeftBitShiftWith<uint32_t, int_least8_t>);
        REQUIRE(cortex::LeftBitShiftWith<uint32_t, int_least16_t>);
        REQUIRE(cortex::LeftBitShiftWith<uint32_t, int_least32_t>);
        REQUIRE(cortex::LeftBitShiftWith<uint32_t, int_least64_t>);
    }

    SECTION("uint64_t with _")
    {
        // int64 with Signed Integers
        REQUIRE(cortex::LeftBitShiftWith<uint64_t, int>);
        REQUIRE(cortex::LeftBitShiftWith<uint64_t, short>);
        REQUIRE(cortex::LeftBitShiftWith<uint64_t, long>);
        REQUIRE(cortex::LeftBitShiftWith<uint64_t, long long>);

        // int64 with Unsigned Integers
        REQUIRE(cortex::LeftBitShiftWith<uint64_t, unsigned>);
        REQUIRE(cortex::LeftBitShiftWith<uint64_t, unsigned short>);
        REQUIRE(cortex::LeftBitShiftWith<uint64_t, u_short>);
        REQUIRE(cortex::LeftBitShiftWith<uint64_t, unsigned long>);
        REQUIRE(cortex::LeftBitShiftWith<uint64_t, unsigned long long>);
        
        // int64 with Floating Point and Doubles
        REQUIRE(!cortex::LeftBitShiftWith<uint64_t, float>);
        REQUIRE(!cortex::LeftBitShiftWith<uint64_t, double>);
        REQUIRE(!cortex::LeftBitShiftWith<uint64_t, long double>);

        // int64 with std::strings and std::string_view
        REQUIRE(!cortex::LeftBitShiftWith<uint64_t, std::string>);
        REQUIRE(!cortex::LeftBitShiftWith<uint64_t, std::string_view>);
        REQUIRE(!cortex::LeftBitShiftWith<uint64_t, std::u8string>);
        REQUIRE(!cortex::LeftBitShiftWith<uint64_t, std::u16string>);
        REQUIRE(!cortex::LeftBitShiftWith<uint64_t, std::u32string>);

        // int64 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::LeftBitShiftWith<uint64_t, std::wstring>);
        REQUIRE(!cortex::LeftBitShiftWith<uint64_t, std::wstring_view>);

        // uint64_t with Charaters
        REQUIRE(cortex::LeftBitShiftWith<uint64_t, char>);
        REQUIRE(cortex::LeftBitShiftWith<uint64_t, u_char>);
        REQUIRE(cortex::LeftBitShiftWith<uint64_t, wchar_t>);

        // uint64_t with Bit Specific Characters
        REQUIRE(cortex::LeftBitShiftWith<uint64_t, char8_t>);
        REQUIRE(cortex::LeftBitShiftWith<uint64_t, char16_t>);
        REQUIRE(cortex::LeftBitShiftWith<uint64_t, char32_t>);

        // uint64_t with Bit Specific Integers
        REQUIRE(cortex::LeftBitShiftWith<uint64_t, int8_t>);
        REQUIRE(cortex::LeftBitShiftWith<uint64_t, int16_t>);
        REQUIRE(cortex::LeftBitShiftWith<uint64_t, int32_t>);
        REQUIRE(cortex::LeftBitShiftWith<uint64_t, int64_t>);

        // uint64_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::LeftBitShiftWith<uint64_t, uint8_t>);
        REQUIRE(cortex::LeftBitShiftWith<uint64_t, uint16_t>);
        REQUIRE(cortex::LeftBitShiftWith<uint64_t, uint32_t>);
        REQUIRE(cortex::LeftBitShiftWith<uint64_t, uint64_t>);

        // uint64_t with Bit Specific Least Integers
        REQUIRE(cortex::LeftBitShiftWith<uint64_t, int_least8_t>);
        REQUIRE(cortex::LeftBitShiftWith<uint64_t, int_least16_t>);
        REQUIRE(cortex::LeftBitShiftWith<uint64_t, int_least32_t>);
        REQUIRE(cortex::LeftBitShiftWith<uint64_t, int_least64_t>);
    }
}

TEST_CASE("Addable With : std::size_t")
{
    SECTION("std::size_t with _")
    {
        // std::size_t with Signed Integers
        REQUIRE(cortex::LeftBitShiftWith<std::size_t, int>);
        REQUIRE(cortex::LeftBitShiftWith<std::size_t, short>);
        REQUIRE(cortex::LeftBitShiftWith<std::size_t, long>);
        REQUIRE(cortex::LeftBitShiftWith<std::size_t, long long>);

        // std::size_t with Unsigned Integers
        REQUIRE(cortex::LeftBitShiftWith<std::size_t, unsigned>);
        REQUIRE(cortex::LeftBitShiftWith<std::size_t, unsigned short>);
        REQUIRE(cortex::LeftBitShiftWith<std::size_t, u_short>);
        REQUIRE(cortex::LeftBitShiftWith<std::size_t, unsigned long>);
        REQUIRE(cortex::LeftBitShiftWith<std::size_t, unsigned long long>);
        
        // std::size_t with Floating Point and Doubles
        REQUIRE(!cortex::LeftBitShiftWith<std::size_t, float>);
        REQUIRE(!cortex::LeftBitShiftWith<std::size_t, double>);
        REQUIRE(!cortex::LeftBitShiftWith<std::size_t, long double>);

        // std::size_t with std::strings and std::string_view
        REQUIRE(!cortex::LeftBitShiftWith<std::size_t, std::string>);
        REQUIRE(!cortex::LeftBitShiftWith<std::size_t, std::string_view>);
        REQUIRE(!cortex::LeftBitShiftWith<std::size_t, std::u8string>);
        REQUIRE(!cortex::LeftBitShiftWith<std::size_t, std::u16string>);
        REQUIRE(!cortex::LeftBitShiftWith<std::size_t, std::u32string>);

        // std::size_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::LeftBitShiftWith<long long, std::wstring>);
        REQUIRE(!cortex::LeftBitShiftWith<long long, std::wstring_view>);

        // std::size_t with Charaters
        REQUIRE(cortex::LeftBitShiftWith<std::size_t, char>);
        REQUIRE(cortex::LeftBitShiftWith<std::size_t, u_char>);
        REQUIRE(cortex::LeftBitShiftWith<std::size_t, wchar_t>);

        // std::size_t with Bit Specific Characters
        REQUIRE(cortex::LeftBitShiftWith<std::size_t, char8_t>);
        REQUIRE(cortex::LeftBitShiftWith<std::size_t, char16_t>);
        REQUIRE(cortex::LeftBitShiftWith<std::size_t, char32_t>);

        // std::size_t with Bit Specific Integers
        REQUIRE(cortex::LeftBitShiftWith<std::size_t, int8_t>);
        REQUIRE(cortex::LeftBitShiftWith<std::size_t, int16_t>);
        REQUIRE(cortex::LeftBitShiftWith<std::size_t, int32_t>);
        REQUIRE(cortex::LeftBitShiftWith<std::size_t, int64_t>);

        // std::size_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::LeftBitShiftWith<std::size_t, uint8_t>);
        REQUIRE(cortex::LeftBitShiftWith<std::size_t, uint16_t>);
        REQUIRE(cortex::LeftBitShiftWith<std::size_t, uint32_t>);
        REQUIRE(cortex::LeftBitShiftWith<std::size_t, uint64_t>);

        // std::size_t with Bit Specific Least Integers
        REQUIRE(cortex::LeftBitShiftWith<std::size_t, int_least8_t>);
        REQUIRE(cortex::LeftBitShiftWith<std::size_t, int_least16_t>);
        REQUIRE(cortex::LeftBitShiftWith<std::size_t, int_least32_t>);
        REQUIRE(cortex::LeftBitShiftWith<std::size_t, int_least64_t>);
    }
}

TEST_CASE("LeftBitShiftWith : Fast Integers")
{
    SECTION("int_fast8_t with _")
    {
        // int_fast8_t with Signed Integers
        REQUIRE(cortex::LeftBitShiftWith<int_fast8_t, int>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast8_t, short>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast8_t, long>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast8_t, long long>);

        // int_fast8_t with Unsigned Integers
        REQUIRE(cortex::LeftBitShiftWith<int_fast8_t, unsigned>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast8_t, unsigned short>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast8_t, u_short>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast8_t, unsigned long>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast8_t, unsigned long long>);
        
        // int_fast8_t with Floating Point and Doubles
        REQUIRE(!cortex::LeftBitShiftWith<int_fast8_t, float>);
        REQUIRE(!cortex::LeftBitShiftWith<int_fast8_t, double>);
        REQUIRE(!cortex::LeftBitShiftWith<int_fast8_t, long double>);

        // int_fast8_t with std::strings and std::string_view
        REQUIRE(!cortex::LeftBitShiftWith<int_fast8_t, std::string>);
        REQUIRE(!cortex::LeftBitShiftWith<int_fast8_t, std::string_view>);
        REQUIRE(!cortex::LeftBitShiftWith<int_fast8_t, std::u8string>);
        REQUIRE(!cortex::LeftBitShiftWith<int_fast8_t, std::u16string>);
        REQUIRE(!cortex::LeftBitShiftWith<int_fast8_t, std::u32string>);

        // int_fast8_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::LeftBitShiftWith<long long, std::wstring>);
        REQUIRE(!cortex::LeftBitShiftWith<long long, std::wstring_view>);

        // int_fast8_t with Charaters
        REQUIRE(cortex::LeftBitShiftWith<int_fast8_t, char>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast8_t, u_char>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast8_t, wchar_t>);

        // int_fast8_t with Bit Specific Characters
        REQUIRE(cortex::LeftBitShiftWith<int_fast8_t, char8_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast8_t, char16_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast8_t, char32_t>);

        // int_fast8_t with Bit Specific Integers
        REQUIRE(cortex::LeftBitShiftWith<int_fast8_t, int8_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast8_t, int16_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast8_t, int32_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast8_t, int64_t>);

        // int_fast8_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::LeftBitShiftWith<int_fast8_t, uint8_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast8_t, uint16_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast8_t, uint32_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast8_t, uint64_t>);

        // int_fast8_t with Bit Specific Least Integers
        REQUIRE(cortex::LeftBitShiftWith<int_fast8_t, int_least8_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast8_t, int_least16_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast8_t, int_least32_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast8_t, int_least64_t>);
    }

    SECTION("int_fast16_t with _")
    {
        // int_fast16_t with Signed Integers
        REQUIRE(cortex::LeftBitShiftWith<int_fast16_t, int>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast16_t, short>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast16_t, long>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast16_t, long long>);

        // int_fast16_t with Unsigned Integers
        REQUIRE(cortex::LeftBitShiftWith<int_fast16_t, unsigned>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast16_t, unsigned short>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast16_t, u_short>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast16_t, unsigned long>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast16_t, unsigned long long>);
        
        // int_fast16_t with Floating Point and Doubles
        REQUIRE(!cortex::LeftBitShiftWith<int_fast16_t, float>);
        REQUIRE(!cortex::LeftBitShiftWith<int_fast16_t, double>);
        REQUIRE(!cortex::LeftBitShiftWith<int_fast16_t, long double>);

        // int_fast16_t with std::strings and std::string_view
        REQUIRE(!cortex::LeftBitShiftWith<int_fast16_t, std::string>);
        REQUIRE(!cortex::LeftBitShiftWith<int_fast16_t, std::string_view>);
        REQUIRE(!cortex::LeftBitShiftWith<int_fast16_t, std::u8string>);
        REQUIRE(!cortex::LeftBitShiftWith<int_fast16_t, std::u16string>);
        REQUIRE(!cortex::LeftBitShiftWith<int_fast16_t, std::u32string>);

        // int_fast16_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::LeftBitShiftWith<int_fast16_t, std::wstring>);
        REQUIRE(!cortex::LeftBitShiftWith<int_fast16_t, std::wstring_view>);

        // int_fast16_t with Charaters
        REQUIRE(cortex::LeftBitShiftWith<int_fast16_t, char>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast16_t, u_char>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast16_t, wchar_t>);

        // int_fast16_t with Bit Specific Characters
        REQUIRE(cortex::LeftBitShiftWith<int_fast16_t, char8_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast16_t, char16_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast16_t, char32_t>);

        // int_fast16_t with Bit Specific Integers
        REQUIRE(cortex::LeftBitShiftWith<int_fast16_t, int8_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast16_t, int16_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast16_t, int32_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast16_t, int64_t>);

        // int_fast16_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::LeftBitShiftWith<int_fast16_t, uint8_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast16_t, uint16_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast16_t, uint32_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast16_t, uint64_t>);

        // int_fast16_t with Bit Specific Least Integers
        REQUIRE(cortex::LeftBitShiftWith<int_fast16_t, int_least8_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast16_t, int_least16_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast16_t, int_least32_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast16_t, int_least64_t>);
    }

    SECTION("int_fast32_t with _")
    {
        // int32 with Signed Integers
        REQUIRE(cortex::LeftBitShiftWith<int_fast32_t, int>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast32_t, short>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast32_t, long>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast32_t, long long>);

        // int32 with Unsigned Integers
        REQUIRE(cortex::LeftBitShiftWith<int_fast32_t, unsigned>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast32_t, unsigned short>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast32_t, u_short>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast32_t, unsigned long>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast32_t, unsigned long long>);
        
        // int32 with Floating Point and Doubles
        REQUIRE(!cortex::LeftBitShiftWith<int_fast32_t, float>);
        REQUIRE(!cortex::LeftBitShiftWith<int_fast32_t, double>);
        REQUIRE(!cortex::LeftBitShiftWith<int_fast32_t, long double>);

        // int32 with std::strings and std::string_view
        REQUIRE(!cortex::LeftBitShiftWith<int_fast32_t, std::string>);
        REQUIRE(!cortex::LeftBitShiftWith<int_fast32_t, std::string_view>);
        REQUIRE(!cortex::LeftBitShiftWith<int_fast32_t, std::u8string>);
        REQUIRE(!cortex::LeftBitShiftWith<int_fast32_t, std::u16string>);
        REQUIRE(!cortex::LeftBitShiftWith<int_fast32_t, std::u32string>);

        // int32 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::LeftBitShiftWith<int_fast32_t, std::wstring>);
        REQUIRE(!cortex::LeftBitShiftWith<int_fast32_t, std::wstring_view>);

        // int_fast32_t with Charaters
        REQUIRE(cortex::LeftBitShiftWith<int_fast32_t, char>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast32_t, u_char>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast32_t, wchar_t>);

        // int_fast32_t with Bit Specific Characters
        REQUIRE(cortex::LeftBitShiftWith<int_fast32_t, char8_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast32_t, char16_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast32_t, char32_t>);

        // int_fast32_t with Bit Specific Integers
        REQUIRE(cortex::LeftBitShiftWith<int_fast32_t, int8_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast32_t, int16_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast32_t, int32_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast32_t, int64_t>);

        // int_fast32_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::LeftBitShiftWith<int_fast32_t, uint8_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast32_t, uint16_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast32_t, uint32_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast32_t, uint64_t>);

        // int_fast32_t with Bit Specific Least Integers
        REQUIRE(cortex::LeftBitShiftWith<int_fast32_t, int_least8_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast32_t, int_least16_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast32_t, int_least32_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast32_t, int_least64_t>);
    }

    SECTION("int_fast64_t with _")
    {
        // int64 with Signed Integers
        REQUIRE(cortex::LeftBitShiftWith<int_fast64_t, int>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast64_t, short>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast64_t, long>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast64_t, long long>);

        // int64 with Unsigned Integers
        REQUIRE(cortex::LeftBitShiftWith<int_fast64_t, unsigned>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast64_t, unsigned short>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast64_t, u_short>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast64_t, unsigned long>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast64_t, unsigned long long>);
        
        // int64 with Floating Point and Doubles
        REQUIRE(!cortex::LeftBitShiftWith<int_fast64_t, float>);
        REQUIRE(!cortex::LeftBitShiftWith<int_fast64_t, double>);
        REQUIRE(!cortex::LeftBitShiftWith<int_fast64_t, long double>);

        // int64 with std::strings and std::string_view
        REQUIRE(!cortex::LeftBitShiftWith<int_fast64_t, std::string>);
        REQUIRE(!cortex::LeftBitShiftWith<int_fast64_t, std::string_view>);
        REQUIRE(!cortex::LeftBitShiftWith<int_fast64_t, std::u8string>);
        REQUIRE(!cortex::LeftBitShiftWith<int_fast64_t, std::u16string>);
        REQUIRE(!cortex::LeftBitShiftWith<int_fast64_t, std::u32string>);

        // int64 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::LeftBitShiftWith<int_fast64_t, std::wstring>);
        REQUIRE(!cortex::LeftBitShiftWith<int_fast64_t, std::wstring_view>);

        // int_fast64_t with Charaters
        REQUIRE(cortex::LeftBitShiftWith<int_fast64_t, char>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast64_t, u_char>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast64_t, wchar_t>);

        // int_fast64_t with Bit Specific Characters
        REQUIRE(cortex::LeftBitShiftWith<int_fast64_t, char8_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast64_t, char16_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast64_t, char32_t>);

        // int_fast64_t with Bit Specific Integers
        REQUIRE(cortex::LeftBitShiftWith<int_fast64_t, int8_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast64_t, int16_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast64_t, int32_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast64_t, int64_t>);

        // int_fast64_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::LeftBitShiftWith<int_fast64_t, uint8_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast64_t, uint16_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast64_t, uint32_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast64_t, uint64_t>);

        // int_fast64_t with Bit Specific Least Integers
        REQUIRE(cortex::LeftBitShiftWith<int_fast64_t, int_least8_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast64_t, int_least16_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast64_t, int_least32_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_fast64_t, int_least64_t>);
    }
}

TEST_CASE("LeftBitShiftWith : Least Integers")
{
    SECTION("int_least8_t with _")
    {
        // int_fast8_t with Signed Integers
        REQUIRE(cortex::LeftBitShiftWith<int_least8_t, int>);
        REQUIRE(cortex::LeftBitShiftWith<int_least8_t, short>);
        REQUIRE(cortex::LeftBitShiftWith<int_least8_t, long>);
        REQUIRE(cortex::LeftBitShiftWith<int_least8_t, long long>);

        // int_fast8_t with Unsigned Integers
        REQUIRE(cortex::LeftBitShiftWith<int_least8_t, unsigned>);
        REQUIRE(cortex::LeftBitShiftWith<int_least8_t, unsigned short>);
        REQUIRE(cortex::LeftBitShiftWith<int_least8_t, u_short>);
        REQUIRE(cortex::LeftBitShiftWith<int_least8_t, unsigned long>);
        REQUIRE(cortex::LeftBitShiftWith<int_least8_t, unsigned long long>);
        
        // int_fast8_t with Floating Point and Doubles
        REQUIRE(!cortex::LeftBitShiftWith<int_least8_t, float>);
        REQUIRE(!cortex::LeftBitShiftWith<int_least8_t, double>);
        REQUIRE(!cortex::LeftBitShiftWith<int_least8_t, long double>);

        // int_fast8_t with std::strings and std::string_view
        REQUIRE(!cortex::LeftBitShiftWith<int_least8_t, std::string>);
        REQUIRE(!cortex::LeftBitShiftWith<int_least8_t, std::string_view>);
        REQUIRE(!cortex::LeftBitShiftWith<int_least8_t, std::u8string>);
        REQUIRE(!cortex::LeftBitShiftWith<int_least8_t, std::u16string>);
        REQUIRE(!cortex::LeftBitShiftWith<int_least8_t, std::u32string>);

        // int_fast8_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::LeftBitShiftWith<long long, std::wstring>);
        REQUIRE(!cortex::LeftBitShiftWith<long long, std::wstring_view>);

        // int_fast8_t with Charaters
        REQUIRE(cortex::LeftBitShiftWith<int_least8_t, char>);
        REQUIRE(cortex::LeftBitShiftWith<int_least8_t, u_char>);
        REQUIRE(cortex::LeftBitShiftWith<int_least8_t, wchar_t>);

        // int_fast8_t with Bit Specific Characters
        REQUIRE(cortex::LeftBitShiftWith<int_least8_t, char8_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_least8_t, char16_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_least8_t, char32_t>);

        // int_fast8_t with Bit Specific Integers
        REQUIRE(cortex::LeftBitShiftWith<int_least8_t, int8_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_least8_t, int16_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_least8_t, int32_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_least8_t, int64_t>);

        // int_fast8_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::LeftBitShiftWith<int_least8_t, uint8_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_least8_t, uint16_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_least8_t, uint32_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_least8_t, uint64_t>);

        // int_fast8_t with Bit Specific Least Integers
        REQUIRE(cortex::LeftBitShiftWith<int_least8_t, int_least8_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_least8_t, int_least16_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_least8_t, int_least32_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_least8_t, int_least64_t>);
    }

    SECTION("int_least16_t with _")
    {
        // int_fast16_t with Signed Integers
        REQUIRE(cortex::LeftBitShiftWith<int_least16_t, int>);
        REQUIRE(cortex::LeftBitShiftWith<int_least16_t, short>);
        REQUIRE(cortex::LeftBitShiftWith<int_least16_t, long>);
        REQUIRE(cortex::LeftBitShiftWith<int_least16_t, long long>);

        // int_fast16_t with Unsigned Integers
        REQUIRE(cortex::LeftBitShiftWith<int_least16_t, unsigned>);
        REQUIRE(cortex::LeftBitShiftWith<int_least16_t, unsigned short>);
        REQUIRE(cortex::LeftBitShiftWith<int_least16_t, u_short>);
        REQUIRE(cortex::LeftBitShiftWith<int_least16_t, unsigned long>);
        REQUIRE(cortex::LeftBitShiftWith<int_least16_t, unsigned long long>);
        
        // int_fast16_t with Floating Point and Doubles
        REQUIRE(!cortex::LeftBitShiftWith<int_least16_t, float>);
        REQUIRE(!cortex::LeftBitShiftWith<int_least16_t, double>);
        REQUIRE(!cortex::LeftBitShiftWith<int_least16_t, long double>);

        // int_fast16_t with std::strings and std::string_view
        REQUIRE(!cortex::LeftBitShiftWith<int_least16_t, std::string>);
        REQUIRE(!cortex::LeftBitShiftWith<int_least16_t, std::string_view>);
        REQUIRE(!cortex::LeftBitShiftWith<int_least16_t, std::u8string>);
        REQUIRE(!cortex::LeftBitShiftWith<int_least16_t, std::u16string>);
        REQUIRE(!cortex::LeftBitShiftWith<int_least16_t, std::u32string>);

        // int_fast16_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::LeftBitShiftWith<int_least16_t, std::wstring>);
        REQUIRE(!cortex::LeftBitShiftWith<int_least16_t, std::wstring_view>);

        // int_fast16_t with Charaters
        REQUIRE(cortex::LeftBitShiftWith<int_least16_t, char>);
        REQUIRE(cortex::LeftBitShiftWith<int_least16_t, u_char>);
        REQUIRE(cortex::LeftBitShiftWith<int_least16_t, wchar_t>);

        // int_fast16_t with Bit Specific Characters
        REQUIRE(cortex::LeftBitShiftWith<int_least16_t, char8_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_least16_t, char16_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_least16_t, char32_t>);

        // int_fast16_t with Bit Specific Integers
        REQUIRE(cortex::LeftBitShiftWith<int_least16_t, int8_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_least16_t, int16_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_least16_t, int32_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_least16_t, int64_t>);

        // int_fast16_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::LeftBitShiftWith<int_least16_t, uint8_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_least16_t, uint16_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_least16_t, uint32_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_least16_t, uint64_t>);

        // int_fast16_t with Bit Specific Least Integers
        REQUIRE(cortex::LeftBitShiftWith<int_least16_t, int_least8_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_least16_t, int_least16_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_least16_t, int_least32_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_least16_t, int_least64_t>);
    }

    SECTION("int_least32_t with _")
    {
        // int32 with Signed Integers
        REQUIRE(cortex::LeftBitShiftWith<int_least32_t, int>);
        REQUIRE(cortex::LeftBitShiftWith<int_least32_t, short>);
        REQUIRE(cortex::LeftBitShiftWith<int_least32_t, long>);
        REQUIRE(cortex::LeftBitShiftWith<int_least32_t, long long>);

        // int32 with Unsigned Integers
        REQUIRE(cortex::LeftBitShiftWith<int_least32_t, unsigned>);
        REQUIRE(cortex::LeftBitShiftWith<int_least32_t, unsigned short>);
        REQUIRE(cortex::LeftBitShiftWith<int_least32_t, u_short>);
        REQUIRE(cortex::LeftBitShiftWith<int_least32_t, unsigned long>);
        REQUIRE(cortex::LeftBitShiftWith<int_least32_t, unsigned long long>);
        
        // int32 with Floating Point and Doubles
        REQUIRE(!cortex::LeftBitShiftWith<int_least32_t, float>);
        REQUIRE(!cortex::LeftBitShiftWith<int_least32_t, double>);
        REQUIRE(!cortex::LeftBitShiftWith<int_least32_t, long double>);

        // int32 with std::strings and std::string_view
        REQUIRE(!cortex::LeftBitShiftWith<int_least32_t, std::string>);
        REQUIRE(!cortex::LeftBitShiftWith<int_least32_t, std::string_view>);
        REQUIRE(!cortex::LeftBitShiftWith<int_least32_t, std::u8string>);
        REQUIRE(!cortex::LeftBitShiftWith<int_least32_t, std::u16string>);
        REQUIRE(!cortex::LeftBitShiftWith<int_least32_t, std::u32string>);

        // int32 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::LeftBitShiftWith<int_least32_t, std::wstring>);
        REQUIRE(!cortex::LeftBitShiftWith<int_least32_t, std::wstring_view>);

        // int_fast32_t with Charaters
        REQUIRE(cortex::LeftBitShiftWith<int_least32_t, char>);
        REQUIRE(cortex::LeftBitShiftWith<int_least32_t, u_char>);
        REQUIRE(cortex::LeftBitShiftWith<int_least32_t, wchar_t>);

        // int_fast32_t with Bit Specific Characters
        REQUIRE(cortex::LeftBitShiftWith<int_least32_t, char8_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_least32_t, char16_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_least32_t, char32_t>);

        // int_fast32_t with Bit Specific Integers
        REQUIRE(cortex::LeftBitShiftWith<int_least32_t, int8_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_least32_t, int16_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_least32_t, int32_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_least32_t, int64_t>);

        // int_fast32_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::LeftBitShiftWith<int_least32_t, uint8_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_least32_t, uint16_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_least32_t, uint32_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_least32_t, uint64_t>);

        // int_fast32_t with Bit Specific Least Integers
        REQUIRE(cortex::LeftBitShiftWith<int_least32_t, int_least8_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_least32_t, int_least16_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_least32_t, int_least32_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_least32_t, int_least64_t>);
    }

    SECTION("int_least64_t with _")
    {
        // int64 with Signed Integers
        REQUIRE(cortex::LeftBitShiftWith<int_least64_t, int>);
        REQUIRE(cortex::LeftBitShiftWith<int_least64_t, short>);
        REQUIRE(cortex::LeftBitShiftWith<int_least64_t, long>);
        REQUIRE(cortex::LeftBitShiftWith<int_least64_t, long long>);

        // int64 with Unsigned Integers
        REQUIRE(cortex::LeftBitShiftWith<int_least64_t, unsigned>);
        REQUIRE(cortex::LeftBitShiftWith<int_least64_t, unsigned short>);
        REQUIRE(cortex::LeftBitShiftWith<int_least64_t, u_short>);
        REQUIRE(cortex::LeftBitShiftWith<int_least64_t, unsigned long>);
        REQUIRE(cortex::LeftBitShiftWith<int_least64_t, unsigned long long>);
        
        // int64 with Floating Point and Doubles
        REQUIRE(!cortex::LeftBitShiftWith<int_least64_t, float>);
        REQUIRE(!cortex::LeftBitShiftWith<int_least64_t, double>);
        REQUIRE(!cortex::LeftBitShiftWith<int_least64_t, long double>);

        // int64 with std::strings and std::string_view
        REQUIRE(!cortex::LeftBitShiftWith<int_least64_t, std::string>);
        REQUIRE(!cortex::LeftBitShiftWith<int_least64_t, std::string_view>);
        REQUIRE(!cortex::LeftBitShiftWith<int_least64_t, std::u8string>);
        REQUIRE(!cortex::LeftBitShiftWith<int_least64_t, std::u16string>);
        REQUIRE(!cortex::LeftBitShiftWith<int_least64_t, std::u32string>);

        // int64 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::LeftBitShiftWith<int_least64_t, std::wstring>);
        REQUIRE(!cortex::LeftBitShiftWith<int_least64_t, std::wstring_view>);

        // int_fast64_t with Charaters
        REQUIRE(cortex::LeftBitShiftWith<int_least64_t, char>);
        REQUIRE(cortex::LeftBitShiftWith<int_least64_t, u_char>);
        REQUIRE(cortex::LeftBitShiftWith<int_least64_t, wchar_t>);

        // int_fast64_t with Bit Specific Characters
        REQUIRE(cortex::LeftBitShiftWith<int_least64_t, char8_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_least64_t, char16_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_least64_t, char32_t>);

        // int_fast64_t with Bit Specific Integers
        REQUIRE(cortex::LeftBitShiftWith<int_least64_t, int8_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_least64_t, int16_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_least64_t, int32_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_least64_t, int64_t>);

        // int_fast64_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::LeftBitShiftWith<int_least64_t, uint8_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_least64_t, uint16_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_least64_t, uint32_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_least64_t, uint64_t>);

        // int_fast64_t with Bit Specific Least Integers
        REQUIRE(cortex::LeftBitShiftWith<int_least64_t, int_least8_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_least64_t, int_least16_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_least64_t, int_least32_t>);
        REQUIRE(cortex::LeftBitShiftWith<int_least64_t, int_least64_t>);
    }
}