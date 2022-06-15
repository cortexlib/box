#include <catch2/catch.hpp>
#include <concepts.hpp>

TEST_CASE("MultiplicableWith : Signed Integers")
{
    SECTION("Int with _")
    {
        // Int with Signed Integers
        REQUIRE(cortex::MultiplicableWith<int, int>);
        REQUIRE(cortex::MultiplicableWith<int, short>);
        REQUIRE(cortex::MultiplicableWith<int, long>);
        REQUIRE(cortex::MultiplicableWith<int, long long>);

        // Int with Unsigned Integers
        REQUIRE(cortex::MultiplicableWith<int, unsigned>);
        REQUIRE(cortex::MultiplicableWith<int, unsigned short>);
        REQUIRE(cortex::MultiplicableWith<int, u_short>);
        REQUIRE(cortex::MultiplicableWith<int, unsigned long>);
        REQUIRE(cortex::MultiplicableWith<int, unsigned long long>);
        
        // Integers with Floating Point and Doubles
        REQUIRE(cortex::MultiplicableWith<int, float>);
        REQUIRE(cortex::MultiplicableWith<int, double>);
        REQUIRE(cortex::MultiplicableWith<int, long double>);

        // Integers with std::strings and std::string_view
        REQUIRE(!cortex::MultiplicableWith<int, std::string>);
        REQUIRE(!cortex::MultiplicableWith<int, std::string_view>);
        REQUIRE(!cortex::MultiplicableWith<int, std::u8string>);
        REQUIRE(!cortex::MultiplicableWith<int, std::u16string>);
        REQUIRE(!cortex::MultiplicableWith<int, std::u32string>);

        // Integers with std::wstrings and std::wstring_view
        REQUIRE(!cortex::MultiplicableWith<int, std::wstring>);
        REQUIRE(!cortex::MultiplicableWith<int, std::wstring_view>);

        // Integers with Charaters
        REQUIRE(cortex::MultiplicableWith<int, char>);
        REQUIRE(cortex::MultiplicableWith<int, u_char>);
        REQUIRE(cortex::MultiplicableWith<int, wchar_t>);

        // Integers with Bit Specific Characters
        REQUIRE(cortex::MultiplicableWith<int, char8_t>);
        REQUIRE(cortex::MultiplicableWith<int, char16_t>);
        REQUIRE(cortex::MultiplicableWith<int, char32_t>);

        // Integers with Bit Specific Integers
        REQUIRE(cortex::MultiplicableWith<int, int8_t>);
        REQUIRE(cortex::MultiplicableWith<int, int16_t>);
        REQUIRE(cortex::MultiplicableWith<int, int32_t>);
        REQUIRE(cortex::MultiplicableWith<int, int64_t>);

        // Integers with Bit Specific Unsigned Integers
        REQUIRE(cortex::MultiplicableWith<int, uint8_t>);
        REQUIRE(cortex::MultiplicableWith<int, uint16_t>);
        REQUIRE(cortex::MultiplicableWith<int, uint32_t>);
        REQUIRE(cortex::MultiplicableWith<int, uint64_t>);

        // Integers with Bit Specific Least Integers
        REQUIRE(cortex::MultiplicableWith<int, int_least8_t>);
        REQUIRE(cortex::MultiplicableWith<int, int_least16_t>);
        REQUIRE(cortex::MultiplicableWith<int, int_least32_t>);
        REQUIRE(cortex::MultiplicableWith<int, int_least64_t>);
    }

    SECTION("Short with _")
    {
        // Short with Signed Integers
        REQUIRE(cortex::MultiplicableWith<short, int>);
        REQUIRE(cortex::MultiplicableWith<short, short>);
        REQUIRE(cortex::MultiplicableWith<short, long>);
        REQUIRE(cortex::MultiplicableWith<short, long long>);

        // Short with Unsigned Integers
        REQUIRE(cortex::MultiplicableWith<short, unsigned>);
        REQUIRE(cortex::MultiplicableWith<short, unsigned short>);
        REQUIRE(cortex::MultiplicableWith<short, u_short>);
        REQUIRE(cortex::MultiplicableWith<short, unsigned long>);
        REQUIRE(cortex::MultiplicableWith<short, unsigned long long>);
        
        // Short with Floating Point and Doubles
        REQUIRE(cortex::MultiplicableWith<short, float>);
        REQUIRE(cortex::MultiplicableWith<short, double>);
        REQUIRE(cortex::MultiplicableWith<short, long double>);

        // Short with std::strings and std::string_view
        REQUIRE(!cortex::MultiplicableWith<short, std::string>);
        REQUIRE(!cortex::MultiplicableWith<short, std::string_view>);
        REQUIRE(!cortex::MultiplicableWith<short, std::u8string>);
        REQUIRE(!cortex::MultiplicableWith<short, std::u16string>);
        REQUIRE(!cortex::MultiplicableWith<short, std::u32string>);

        // Short with std::wstrings and std::wstring_view
        REQUIRE(!cortex::MultiplicableWith<short, std::wstring>);
        REQUIRE(!cortex::MultiplicableWith<short, std::wstring_view>);

        // Short with Charaters
        REQUIRE(cortex::MultiplicableWith<short, char>);
        REQUIRE(cortex::MultiplicableWith<short, u_char>);
        REQUIRE(cortex::MultiplicableWith<short, wchar_t>);

        // Short with Bit Specific Characters
        REQUIRE(cortex::MultiplicableWith<short, char8_t>);
        REQUIRE(cortex::MultiplicableWith<short, char16_t>);
        REQUIRE(cortex::MultiplicableWith<short, char32_t>);

        // Short with Bit Specific Short
        REQUIRE(cortex::MultiplicableWith<short, int8_t>);
        REQUIRE(cortex::MultiplicableWith<short, int16_t>);
        REQUIRE(cortex::MultiplicableWith<short, int32_t>);
        REQUIRE(cortex::MultiplicableWith<short, int64_t>);

        // Short with Bit Specific Unsigned Short
        REQUIRE(cortex::MultiplicableWith<short, uint8_t>);
        REQUIRE(cortex::MultiplicableWith<short, uint16_t>);
        REQUIRE(cortex::MultiplicableWith<short, uint32_t>);
        REQUIRE(cortex::MultiplicableWith<short, uint64_t>);

        // Short with Bit Specific Least Integers
        REQUIRE(cortex::MultiplicableWith<short, int_least8_t>);
        REQUIRE(cortex::MultiplicableWith<short, int_least16_t>);
        REQUIRE(cortex::MultiplicableWith<short, int_least32_t>);
        REQUIRE(cortex::MultiplicableWith<short, int_least64_t>);
    }

    SECTION("Long with _")
    {
        // Long with Signed Integers
        REQUIRE(cortex::MultiplicableWith<long, int>);
        REQUIRE(cortex::MultiplicableWith<long, short>);
        REQUIRE(cortex::MultiplicableWith<long, long>);
        REQUIRE(cortex::MultiplicableWith<long, long long>);

        // Long with Unsigned Integers
        REQUIRE(cortex::MultiplicableWith<long, unsigned>);
        REQUIRE(cortex::MultiplicableWith<long, unsigned short>);
        REQUIRE(cortex::MultiplicableWith<long, u_short>);
        REQUIRE(cortex::MultiplicableWith<long, unsigned long>);
        REQUIRE(cortex::MultiplicableWith<long, unsigned long long>);
        
        // Long with Floating Point and Doubles
        REQUIRE(cortex::MultiplicableWith<long, float>);
        REQUIRE(cortex::MultiplicableWith<long, double>);
        REQUIRE(cortex::MultiplicableWith<long, long double>);

        // Long with std::strings and std::string_view
        REQUIRE(!cortex::MultiplicableWith<long, std::string>);
        REQUIRE(!cortex::MultiplicableWith<long, std::string_view>);
        REQUIRE(!cortex::MultiplicableWith<long, std::u8string>);
        REQUIRE(!cortex::MultiplicableWith<long, std::u16string>);
        REQUIRE(!cortex::MultiplicableWith<long, std::u32string>);

        // Long with std::wstrings and std::wstring_view
        REQUIRE(!cortex::MultiplicableWith<long, std::wstring>);
        REQUIRE(!cortex::MultiplicableWith<long, std::wstring_view>);

        // Long with Charaters
        REQUIRE(cortex::MultiplicableWith<long, char>);
        REQUIRE(cortex::MultiplicableWith<long, u_char>);
        REQUIRE(cortex::MultiplicableWith<long, wchar_t>);

        // Long with Bit Specific Characters
        REQUIRE(cortex::MultiplicableWith<long, char8_t>);
        REQUIRE(cortex::MultiplicableWith<long, char16_t>);
        REQUIRE(cortex::MultiplicableWith<long, char32_t>);

        // Long with Bit Specific Long
        REQUIRE(cortex::MultiplicableWith<long, int8_t>);
        REQUIRE(cortex::MultiplicableWith<long, int16_t>);
        REQUIRE(cortex::MultiplicableWith<long, int32_t>);
        REQUIRE(cortex::MultiplicableWith<long, int64_t>);

        // Long with Bit Specific Unsigned Long
        REQUIRE(cortex::MultiplicableWith<long, uint8_t>);
        REQUIRE(cortex::MultiplicableWith<long, uint16_t>);
        REQUIRE(cortex::MultiplicableWith<long, uint32_t>);
        REQUIRE(cortex::MultiplicableWith<long, uint64_t>);

        // Long with Bit Specific Least Integers
        REQUIRE(cortex::MultiplicableWith<long, int_least8_t>);
        REQUIRE(cortex::MultiplicableWith<long, int_least16_t>);
        REQUIRE(cortex::MultiplicableWith<long, int_least32_t>);
        REQUIRE(cortex::MultiplicableWith<long, int_least64_t>);
    }

    SECTION("Long Long with _")
    {
        // Signed Integers
        REQUIRE(cortex::MultiplicableWith<long long, int>);
        REQUIRE(cortex::MultiplicableWith<long long, short>);
        REQUIRE(cortex::MultiplicableWith<long long, long>);
        REQUIRE(cortex::MultiplicableWith<long long, long long>);

        // Unsigned Integers
        REQUIRE(cortex::MultiplicableWith<long long, unsigned>);
        REQUIRE(cortex::MultiplicableWith<long long, unsigned short>);
        REQUIRE(cortex::MultiplicableWith<long long, u_short>);
        REQUIRE(cortex::MultiplicableWith<long long, unsigned long>);
        REQUIRE(cortex::MultiplicableWith<long long, unsigned long long>);
        
        // Integers with Floating Point and Doubles
        REQUIRE(cortex::MultiplicableWith<long long, float>);
        REQUIRE(cortex::MultiplicableWith<long long, double>);
        REQUIRE(cortex::MultiplicableWith<long long, long double>);

        // Integers with std::strings and std::string_view
        REQUIRE(!cortex::MultiplicableWith<long long, std::string>);
        REQUIRE(!cortex::MultiplicableWith<long long, std::string_view>);
        REQUIRE(!cortex::MultiplicableWith<long long, std::u8string>);
        REQUIRE(!cortex::MultiplicableWith<long long, std::u16string>);
        REQUIRE(!cortex::MultiplicableWith<long long, std::u32string>);

        // Integers with std::wstrings and std::wstring_view
        REQUIRE(!cortex::MultiplicableWith<long long, std::wstring>);
        REQUIRE(!cortex::MultiplicableWith<long long, std::wstring_view>);

        // Integers with Charaters
        REQUIRE(cortex::MultiplicableWith<long long, char>);
        REQUIRE(cortex::MultiplicableWith<long long, u_char>);
        REQUIRE(cortex::MultiplicableWith<long long, wchar_t>);

        // Integers with Bit Specific Characters
        REQUIRE(cortex::MultiplicableWith<long long, char8_t>);
        REQUIRE(cortex::MultiplicableWith<long long, char16_t>);
        REQUIRE(cortex::MultiplicableWith<long long, char32_t>);

        // Integers with Bit Specific Integers
        REQUIRE(cortex::MultiplicableWith<long long, int8_t>);
        REQUIRE(cortex::MultiplicableWith<long long, int16_t>);
        REQUIRE(cortex::MultiplicableWith<long long, int32_t>);
        REQUIRE(cortex::MultiplicableWith<long long, int64_t>);

        // Integers with Bit Specific Unsigned Integers
        REQUIRE(cortex::MultiplicableWith<long long, uint8_t>);
        REQUIRE(cortex::MultiplicableWith<long long, uint16_t>);
        REQUIRE(cortex::MultiplicableWith<long long, uint32_t>);
        REQUIRE(cortex::MultiplicableWith<long long, uint64_t>);

        // Long Long with Bit Specific Least Integers
        REQUIRE(cortex::MultiplicableWith<long long, int_least8_t>);
        REQUIRE(cortex::MultiplicableWith<long long, int_least16_t>);
        REQUIRE(cortex::MultiplicableWith<long long, int_least32_t>);
        REQUIRE(cortex::MultiplicableWith<long long, int_least64_t>);
    }
}

TEST_CASE("MultiplicableWith: Unsigned Integers")
{
    SECTION("Unsigned Int with _")
    {
        // Unsigned Integers with Signed Integers
        REQUIRE(cortex::MultiplicableWith<unsigned int, int>);
        REQUIRE(cortex::MultiplicableWith<unsigned int, short>);
        REQUIRE(cortex::MultiplicableWith<unsigned int, long>);
        REQUIRE(cortex::MultiplicableWith<unsigned int, long long>);

        // Unsigned Integers with Unsigned Integers
        REQUIRE(cortex::MultiplicableWith<unsigned int, unsigned>);
        REQUIRE(cortex::MultiplicableWith<unsigned int, unsigned short>);
        REQUIRE(cortex::MultiplicableWith<unsigned int, u_short>);
        REQUIRE(cortex::MultiplicableWith<unsigned int, unsigned long>);
        REQUIRE(cortex::MultiplicableWith<unsigned int, unsigned long long>);
        
        // Unsigned Integers with Floating Point and Doubles
        REQUIRE(cortex::MultiplicableWith<unsigned int, float>);
        REQUIRE(cortex::MultiplicableWith<unsigned int, double>);
        REQUIRE(cortex::MultiplicableWith<unsigned int, long double>);

        // Unsigned Integers with std::strings and std::string_view
        REQUIRE(!cortex::MultiplicableWith<unsigned int, std::string>);
        REQUIRE(!cortex::MultiplicableWith<unsigned int, std::string_view>);
        REQUIRE(!cortex::MultiplicableWith<unsigned int, std::u8string>);
        REQUIRE(!cortex::MultiplicableWith<unsigned int, std::u16string>);
        REQUIRE(!cortex::MultiplicableWith<unsigned int, std::u32string>);

        // Unsigned Integers with std::wstrings and std::wstring_view
        REQUIRE(!cortex::MultiplicableWith<unsigned long long, std::wstring>);
        REQUIRE(!cortex::MultiplicableWith<unsigned long long, std::wstring_view>);

        // Unsigned Integers with Charaters
        REQUIRE(cortex::MultiplicableWith<unsigned int, char>);
        REQUIRE(cortex::MultiplicableWith<unsigned int, u_char>);
        REQUIRE(cortex::MultiplicableWith<unsigned int, wchar_t>);

        // Unsigned Integers with Bit Specific Characters
        REQUIRE(cortex::MultiplicableWith<unsigned int, char8_t>);
        REQUIRE(cortex::MultiplicableWith<unsigned int, char16_t>);
        REQUIRE(cortex::MultiplicableWith<unsigned int, char32_t>);

        // Unsigned Integers with Bit Specific Integers
        REQUIRE(cortex::MultiplicableWith<unsigned int, int8_t>);
        REQUIRE(cortex::MultiplicableWith<unsigned int, int16_t>);
        REQUIRE(cortex::MultiplicableWith<unsigned int, int32_t>);
        REQUIRE(cortex::MultiplicableWith<unsigned int, int64_t>);

        // Unsigned Integers with Bit Specific Unsigned Integers
        REQUIRE(cortex::MultiplicableWith<unsigned int, uint8_t>);
        REQUIRE(cortex::MultiplicableWith<unsigned int, uint16_t>);
        REQUIRE(cortex::MultiplicableWith<unsigned int, uint32_t>);
        REQUIRE(cortex::MultiplicableWith<unsigned int, uint64_t>);

        // Unsigned Integers with Bit Specific Least Integers
        REQUIRE(cortex::MultiplicableWith<unsigned int, int_least8_t>);
        REQUIRE(cortex::MultiplicableWith<unsigned int, int_least16_t>);
        REQUIRE(cortex::MultiplicableWith<unsigned int, int_least32_t>);
        REQUIRE(cortex::MultiplicableWith<unsigned int, int_least64_t>);
    }

    SECTION("Unsigned Short with _")
    {
        // Unsigned Short with Signed Integers
        REQUIRE(cortex::MultiplicableWith<unsigned short, int>);
        REQUIRE(cortex::MultiplicableWith<unsigned short, short>);
        REQUIRE(cortex::MultiplicableWith<unsigned short, long>);
        REQUIRE(cortex::MultiplicableWith<unsigned short, long long>);

        // Unsigned Short with Unsigned Integers
        REQUIRE(cortex::MultiplicableWith<unsigned short, unsigned>);
        REQUIRE(cortex::MultiplicableWith<unsigned short, unsigned short>);
        REQUIRE(cortex::MultiplicableWith<unsigned short, u_short>);
        REQUIRE(cortex::MultiplicableWith<unsigned short, unsigned long>);
        REQUIRE(cortex::MultiplicableWith<unsigned short, unsigned long long>);
        
        // Unsigned Short with Floating Point and Doubles
        REQUIRE(cortex::MultiplicableWith<unsigned short, float>);
        REQUIRE(cortex::MultiplicableWith<unsigned short, double>);
        REQUIRE(cortex::MultiplicableWith<unsigned short, long double>);

        // Unsigned Short with std::strings and std::string_view
        REQUIRE(!cortex::MultiplicableWith<unsigned short, std::string>);
        REQUIRE(!cortex::MultiplicableWith<unsigned short, std::string_view>);
        REQUIRE(!cortex::MultiplicableWith<unsigned short, std::u8string>);
        REQUIRE(!cortex::MultiplicableWith<unsigned short, std::u16string>);
        REQUIRE(!cortex::MultiplicableWith<unsigned short, std::u32string>);

        // Unsigned Short with std::wstrings and std::wstring_view
        REQUIRE(!cortex::MultiplicableWith<unsigned short, std::wstring>);
        REQUIRE(!cortex::MultiplicableWith<unsigned short, std::wstring_view>);

        // Unsigned Short with Charaters
        REQUIRE(cortex::MultiplicableWith<unsigned short, char>);
        REQUIRE(cortex::MultiplicableWith<unsigned short, u_char>);
        REQUIRE(cortex::MultiplicableWith<unsigned short, wchar_t>);

        // Unsigned Short with Bit Specific Characters
        REQUIRE(cortex::MultiplicableWith<unsigned short, char8_t>);
        REQUIRE(cortex::MultiplicableWith<unsigned short, char16_t>);
        REQUIRE(cortex::MultiplicableWith<unsigned short, char32_t>);

        // Unsigned Short with Bit Specific Short
        REQUIRE(cortex::MultiplicableWith<unsigned short, int8_t>);
        REQUIRE(cortex::MultiplicableWith<unsigned short, int16_t>);
        REQUIRE(cortex::MultiplicableWith<unsigned short, int32_t>);
        REQUIRE(cortex::MultiplicableWith<unsigned short, int64_t>);

        // Unsigned Short with Bit Specific Unsigned Short
        REQUIRE(cortex::MultiplicableWith<unsigned short, uint8_t>);
        REQUIRE(cortex::MultiplicableWith<unsigned short, uint16_t>);
        REQUIRE(cortex::MultiplicableWith<unsigned short, uint32_t>);
        REQUIRE(cortex::MultiplicableWith<unsigned short, uint64_t>);

        // Unsigned Short with Bit Specific Least Integers
        REQUIRE(cortex::MultiplicableWith<unsigned short, int_least8_t>);
        REQUIRE(cortex::MultiplicableWith<unsigned short, int_least16_t>);
        REQUIRE(cortex::MultiplicableWith<unsigned short, int_least32_t>);
        REQUIRE(cortex::MultiplicableWith<unsigned short, int_least64_t>);
    }

    SECTION("u_short with _")
    {
        // u_short with Signed Integers
        REQUIRE(cortex::MultiplicableWith<u_short, int>);
        REQUIRE(cortex::MultiplicableWith<u_short, short>);
        REQUIRE(cortex::MultiplicableWith<u_short, long>);
        REQUIRE(cortex::MultiplicableWith<u_short, long long>);

        // u_short with Unsigned Integers
        REQUIRE(cortex::MultiplicableWith<u_short, unsigned>);
        REQUIRE(cortex::MultiplicableWith<u_short, unsigned short>);
        REQUIRE(cortex::MultiplicableWith<u_short, u_short>);
        REQUIRE(cortex::MultiplicableWith<u_short, unsigned long>);
        REQUIRE(cortex::MultiplicableWith<u_short, unsigned long long>);
        
        // u_short with Floating Point and Doubles
        REQUIRE(cortex::MultiplicableWith<u_short, float>);
        REQUIRE(cortex::MultiplicableWith<u_short, double>);
        REQUIRE(cortex::MultiplicableWith<u_short, long double>);

        // u_short with std::strings and std::string_view
        REQUIRE(!cortex::MultiplicableWith<u_short, std::string>);
        REQUIRE(!cortex::MultiplicableWith<u_short, std::string_view>);
        REQUIRE(!cortex::MultiplicableWith<u_short, std::u8string>);
        REQUIRE(!cortex::MultiplicableWith<u_short, std::u16string>);
        REQUIRE(!cortex::MultiplicableWith<u_short, std::u32string>);

        // u_short with std::wstrings and std::wstring_view
        REQUIRE(!cortex::MultiplicableWith<u_short, std::wstring>);
        REQUIRE(!cortex::MultiplicableWith<u_short, std::wstring_view>);

        // u_short with Charaters
        REQUIRE(cortex::MultiplicableWith<u_short, char>);
        REQUIRE(cortex::MultiplicableWith<u_short, u_char>);
        REQUIRE(cortex::MultiplicableWith<u_short, wchar_t>);

        // u_short with Bit Specific Characters
        REQUIRE(cortex::MultiplicableWith<u_short, char8_t>);
        REQUIRE(cortex::MultiplicableWith<u_short, char16_t>);
        REQUIRE(cortex::MultiplicableWith<u_short, char32_t>);

        // u_short with Bit Specific Short
        REQUIRE(cortex::MultiplicableWith<u_short, int8_t>);
        REQUIRE(cortex::MultiplicableWith<u_short, int16_t>);
        REQUIRE(cortex::MultiplicableWith<u_short, int32_t>);
        REQUIRE(cortex::MultiplicableWith<u_short, int64_t>);

        // u_short with Bit Specific Unsigned Short
        REQUIRE(cortex::MultiplicableWith<u_short, uint8_t>);
        REQUIRE(cortex::MultiplicableWith<u_short, uint16_t>);
        REQUIRE(cortex::MultiplicableWith<u_short, uint32_t>);
        REQUIRE(cortex::MultiplicableWith<u_short, uint64_t>);

        // u_short with Bit Specific Least Integers
        REQUIRE(cortex::MultiplicableWith<u_short, int_least8_t>);
        REQUIRE(cortex::MultiplicableWith<u_short, int_least16_t>);
        REQUIRE(cortex::MultiplicableWith<u_short, int_least32_t>);
        REQUIRE(cortex::MultiplicableWith<u_short, int_least64_t>);
    }

    SECTION("Unsigned Long with _")
    {
        // Unsigned Long with Signed Integers
        REQUIRE(cortex::MultiplicableWith<unsigned long, int>);
        REQUIRE(cortex::MultiplicableWith<unsigned long, short>);
        REQUIRE(cortex::MultiplicableWith<unsigned long, long>);
        REQUIRE(cortex::MultiplicableWith<unsigned long, long long>);

        // Unsigned Long with Unsigned Integers
        REQUIRE(cortex::MultiplicableWith<unsigned long, unsigned>);
        REQUIRE(cortex::MultiplicableWith<unsigned long, unsigned short>);
        REQUIRE(cortex::MultiplicableWith<unsigned long, u_short>);
        REQUIRE(cortex::MultiplicableWith<unsigned long, unsigned long>);
        REQUIRE(cortex::MultiplicableWith<unsigned long, unsigned long long>);
        
        // Unsigned Long with Floating Point and Doubles
        REQUIRE(cortex::MultiplicableWith<unsigned long, float>);
        REQUIRE(cortex::MultiplicableWith<unsigned long, double>);
        REQUIRE(cortex::MultiplicableWith<unsigned long, long double>);

        // Unsigned Long with std::strings and std::string_view
        REQUIRE(!cortex::MultiplicableWith<unsigned long, std::string>);
        REQUIRE(!cortex::MultiplicableWith<unsigned long, std::string_view>);
        REQUIRE(!cortex::MultiplicableWith<unsigned long, std::u8string>);
        REQUIRE(!cortex::MultiplicableWith<unsigned long, std::u16string>);
        REQUIRE(!cortex::MultiplicableWith<unsigned long, std::u32string>);

        // Unsigned Long with std::wstrings and std::wstring_view
        REQUIRE(!cortex::MultiplicableWith<unsigned long, std::wstring>);
        REQUIRE(!cortex::MultiplicableWith<unsigned long, std::wstring_view>);

        // Unsigned Long with Charaters
        REQUIRE(cortex::MultiplicableWith<unsigned long, char>);
        REQUIRE(cortex::MultiplicableWith<unsigned long, u_char>);
        REQUIRE(cortex::MultiplicableWith<unsigned long, wchar_t>);

        // Unsigned Long with Bit Specific Characters
        REQUIRE(cortex::MultiplicableWith<unsigned long, char8_t>);
        REQUIRE(cortex::MultiplicableWith<unsigned long, char16_t>);
        REQUIRE(cortex::MultiplicableWith<unsigned long, char32_t>);

        // Unsigned Long with Bit Specific Long
        REQUIRE(cortex::MultiplicableWith<unsigned long, int8_t>);
        REQUIRE(cortex::MultiplicableWith<unsigned long, int16_t>);
        REQUIRE(cortex::MultiplicableWith<unsigned long, int32_t>);
        REQUIRE(cortex::MultiplicableWith<unsigned long, int64_t>);

        // Unsigned Long with Bit Specific Unsigned Long
        REQUIRE(cortex::MultiplicableWith<unsigned long, uint8_t>);
        REQUIRE(cortex::MultiplicableWith<unsigned long, uint16_t>);
        REQUIRE(cortex::MultiplicableWith<unsigned long, uint32_t>);
        REQUIRE(cortex::MultiplicableWith<unsigned long, uint64_t>);

        // Unsigned Long with Bit Specific Least Integers
        REQUIRE(cortex::MultiplicableWith<unsigned long, int_least8_t>);
        REQUIRE(cortex::MultiplicableWith<unsigned long, int_least16_t>);
        REQUIRE(cortex::MultiplicableWith<unsigned long, int_least32_t>);
        REQUIRE(cortex::MultiplicableWith<unsigned long, int_least64_t>);
    }

    SECTION("Unsigned Long Long with _")
    {
        // Unsigned Long Long with Signed Integers
        REQUIRE(cortex::MultiplicableWith<unsigned long long, int>);
        REQUIRE(cortex::MultiplicableWith<unsigned long long, short>);
        REQUIRE(cortex::MultiplicableWith<unsigned long long, long>);
        REQUIRE(cortex::MultiplicableWith<unsigned long long, long long>);

        // Unsigned Long Long with Unsigned Integers
        REQUIRE(cortex::MultiplicableWith<unsigned long long, unsigned>);
        REQUIRE(cortex::MultiplicableWith<unsigned long long, unsigned short>);
        REQUIRE(cortex::MultiplicableWith<unsigned long long, u_short>);
        REQUIRE(cortex::MultiplicableWith<unsigned long long, unsigned long>);
        REQUIRE(cortex::MultiplicableWith<unsigned long long, unsigned long long>);
        
        // Unsigned Long Long with Floating Point and Doubles
        REQUIRE(cortex::MultiplicableWith<unsigned long long, float>);
        REQUIRE(cortex::MultiplicableWith<unsigned long long, double>);
        REQUIRE(cortex::MultiplicableWith<unsigned long long, long double>);

        // Unsigned Long Long with std::strings and std::string_view
        REQUIRE(!cortex::MultiplicableWith<unsigned long long, std::string>);
        REQUIRE(!cortex::MultiplicableWith<unsigned long long, std::string_view>);
        REQUIRE(!cortex::MultiplicableWith<unsigned long long, std::u8string>);
        REQUIRE(!cortex::MultiplicableWith<unsigned long long, std::u16string>);
        REQUIRE(!cortex::MultiplicableWith<unsigned long long, std::u32string>);

        // Unsigned Long Long with std::wstrings and std::wstring_view
        REQUIRE(!cortex::MultiplicableWith<unsigned long long, std::wstring>);
        REQUIRE(!cortex::MultiplicableWith<unsigned long long, std::wstring_view>);

        // Unsigned Long Long with Charaters
        REQUIRE(cortex::MultiplicableWith<unsigned long long, char>);
        REQUIRE(cortex::MultiplicableWith<unsigned long long, u_char>);
        REQUIRE(cortex::MultiplicableWith<unsigned long long, wchar_t>);

        // Unsigned Long Long with Bit Specific Characters
        REQUIRE(cortex::MultiplicableWith<unsigned long long, char8_t>);
        REQUIRE(cortex::MultiplicableWith<unsigned long long, char16_t>);
        REQUIRE(cortex::MultiplicableWith<unsigned long long, char32_t>);

        // Unsigned Long Long with Bit Specific Long Long
        REQUIRE(cortex::MultiplicableWith<unsigned long long, int8_t>);
        REQUIRE(cortex::MultiplicableWith<unsigned long long, int16_t>);
        REQUIRE(cortex::MultiplicableWith<unsigned long long, int32_t>);
        REQUIRE(cortex::MultiplicableWith<unsigned long long, int64_t>);

        // Unsigned Long Long with Bit Specific Unsigned Long Long
        REQUIRE(cortex::MultiplicableWith<unsigned long long, uint8_t>);
        REQUIRE(cortex::MultiplicableWith<unsigned long long, uint16_t>);
        REQUIRE(cortex::MultiplicableWith<unsigned long long, uint32_t>);
        REQUIRE(cortex::MultiplicableWith<unsigned long long, uint64_t>);

        // Long Long with Bit Specific Least Long Long
        REQUIRE(cortex::MultiplicableWith<unsigned long long, int_least8_t>);
        REQUIRE(cortex::MultiplicableWith<unsigned long long, int_least16_t>);
        REQUIRE(cortex::MultiplicableWith<unsigned long long, int_least32_t>);
        REQUIRE(cortex::MultiplicableWith<unsigned long long, int_least64_t>);
    }
}

TEST_CASE("MultiplicableWith : Floats & Doubles") 
{
    SECTION("Float with _")
    {
        // Floats with Signed Integers
        REQUIRE(cortex::MultiplicableWith<float, int>);
        REQUIRE(cortex::MultiplicableWith<float, short>);
        REQUIRE(cortex::MultiplicableWith<float, long>);
        REQUIRE(cortex::MultiplicableWith<float, long long>);

        // Floats with Unsigned Integers
        REQUIRE(cortex::MultiplicableWith<float, unsigned>);
        REQUIRE(cortex::MultiplicableWith<float, unsigned short>);
        REQUIRE(cortex::MultiplicableWith<float, u_short>);
        REQUIRE(cortex::MultiplicableWith<float, unsigned long>);
        REQUIRE(cortex::MultiplicableWith<float, unsigned long long>);
        
        // Float with Floating Point and Doubles
        REQUIRE(cortex::MultiplicableWith<float, float>);
        REQUIRE(cortex::MultiplicableWith<float, double>);
        REQUIRE(cortex::MultiplicableWith<float, long double>);

        // Float with std::strings and std::string_view
        REQUIRE(!cortex::MultiplicableWith<float, std::string>);
        REQUIRE(!cortex::MultiplicableWith<float, std::string_view>);
        REQUIRE(!cortex::MultiplicableWith<float, std::u8string>);
        REQUIRE(!cortex::MultiplicableWith<float, std::u16string>);
        REQUIRE(!cortex::MultiplicableWith<float, std::u32string>);

        // Float with std::wstrings and std::wstring_view
        REQUIRE(!cortex::MultiplicableWith<long long, std::wstring>);
        REQUIRE(!cortex::MultiplicableWith<long long, std::wstring_view>);

        // Float with Charaters
        REQUIRE(cortex::MultiplicableWith<float, char>);
        REQUIRE(cortex::MultiplicableWith<float, u_char>);
        REQUIRE(cortex::MultiplicableWith<float, wchar_t>);

        // Float with Bit Specific Characters
        REQUIRE(cortex::MultiplicableWith<float, char8_t>);
        REQUIRE(cortex::MultiplicableWith<float, char16_t>);
        REQUIRE(cortex::MultiplicableWith<float, char32_t>);

        // Float with Bit Specific Integers
        REQUIRE(cortex::MultiplicableWith<float, int8_t>);
        REQUIRE(cortex::MultiplicableWith<float, int16_t>);
        REQUIRE(cortex::MultiplicableWith<float, int32_t>);
        REQUIRE(cortex::MultiplicableWith<float, int64_t>);

        // Float with Bit Specific Unsigned Integers
        REQUIRE(cortex::MultiplicableWith<float, uint8_t>);
        REQUIRE(cortex::MultiplicableWith<float, uint16_t>);
        REQUIRE(cortex::MultiplicableWith<float, uint32_t>);
        REQUIRE(cortex::MultiplicableWith<float, uint64_t>);

        // Float with Bit Specific Least Integers
        REQUIRE(cortex::MultiplicableWith<float, int_least8_t>);
        REQUIRE(cortex::MultiplicableWith<float, int_least16_t>);
        REQUIRE(cortex::MultiplicableWith<float, int_least32_t>);
        REQUIRE(cortex::MultiplicableWith<float, int_least64_t>);
    }

    SECTION("Double with _")
    {
        // Double with Signed Integers
        REQUIRE(cortex::MultiplicableWith<double, int>);
        REQUIRE(cortex::MultiplicableWith<double, short>);
        REQUIRE(cortex::MultiplicableWith<double, long>);
        REQUIRE(cortex::MultiplicableWith<double, long long>);

        // Double with Unsigned Integers
        REQUIRE(cortex::MultiplicableWith<double, unsigned>);
        REQUIRE(cortex::MultiplicableWith<double, unsigned short>);
        REQUIRE(cortex::MultiplicableWith<double, u_short>);
        REQUIRE(cortex::MultiplicableWith<double, unsigned long>);
        REQUIRE(cortex::MultiplicableWith<double, unsigned long long>);
        
        // Double with Floating Point and Doubles
        REQUIRE(cortex::MultiplicableWith<double, float>);
        REQUIRE(cortex::MultiplicableWith<double, double>);
        REQUIRE(cortex::MultiplicableWith<double, long double>);

        // Double with std::strings and std::string_view
        REQUIRE(!cortex::MultiplicableWith<double, std::string>);
        REQUIRE(!cortex::MultiplicableWith<double, std::string_view>);
        REQUIRE(!cortex::MultiplicableWith<double, std::u8string>);
        REQUIRE(!cortex::MultiplicableWith<double, std::u16string>);
        REQUIRE(!cortex::MultiplicableWith<double, std::u32string>);

        // Double with std::wstrings and std::wstring_view
        REQUIRE(!cortex::MultiplicableWith<double, std::wstring>);
        REQUIRE(!cortex::MultiplicableWith<double, std::wstring_view>);

        // Double with Charaters
        REQUIRE(cortex::MultiplicableWith<double, char>);
        REQUIRE(cortex::MultiplicableWith<double, u_char>);
        REQUIRE(cortex::MultiplicableWith<double, wchar_t>);

        // Double with Bit Specific Characters
        REQUIRE(cortex::MultiplicableWith<double, char8_t>);
        REQUIRE(cortex::MultiplicableWith<double, char16_t>);
        REQUIRE(cortex::MultiplicableWith<double, char32_t>);

        // Double with Bit Specific Short
        REQUIRE(cortex::MultiplicableWith<double, int8_t>);
        REQUIRE(cortex::MultiplicableWith<double, int16_t>);
        REQUIRE(cortex::MultiplicableWith<double, int32_t>);
        REQUIRE(cortex::MultiplicableWith<double, int64_t>);

        // Double with Bit Specific Unsigned Short
        REQUIRE(cortex::MultiplicableWith<double, uint8_t>);
        REQUIRE(cortex::MultiplicableWith<double, uint16_t>);
        REQUIRE(cortex::MultiplicableWith<double, uint32_t>);
        REQUIRE(cortex::MultiplicableWith<double, uint64_t>);

        // Double with Bit Specific Least Integers
        REQUIRE(cortex::MultiplicableWith<double, int_least8_t>);
        REQUIRE(cortex::MultiplicableWith<double, int_least16_t>);
        REQUIRE(cortex::MultiplicableWith<double, int_least32_t>);
        REQUIRE(cortex::MultiplicableWith<double, int_least64_t>);
    }

    SECTION("Long Double with _")
    {
        // Long Double with Signed Integers
        REQUIRE(cortex::MultiplicableWith<long double, int>);
        REQUIRE(cortex::MultiplicableWith<long double, short>);
        REQUIRE(cortex::MultiplicableWith<long double, long>);
        REQUIRE(cortex::MultiplicableWith<long double, long long>);

        // Long Double with Unsigned Integers
        REQUIRE(cortex::MultiplicableWith<long double, unsigned>);
        REQUIRE(cortex::MultiplicableWith<long double, unsigned short>);
        REQUIRE(cortex::MultiplicableWith<long double, u_short>);
        REQUIRE(cortex::MultiplicableWith<long double, unsigned long>);
        REQUIRE(cortex::MultiplicableWith<long double, unsigned long long>);
        
        // Long Double with Floating Point and Doubles
        REQUIRE(cortex::MultiplicableWith<long double, float>);
        REQUIRE(cortex::MultiplicableWith<long double, double>);
        REQUIRE(cortex::MultiplicableWith<long double, long double>);

        // Long Double with std::strings and std::string_view
        REQUIRE(!cortex::MultiplicableWith<long double, std::string>);
        REQUIRE(!cortex::MultiplicableWith<long double, std::string_view>);
        REQUIRE(!cortex::MultiplicableWith<long double, std::u8string>);
        REQUIRE(!cortex::MultiplicableWith<long double, std::u16string>);
        REQUIRE(!cortex::MultiplicableWith<long double, std::u32string>);

        // Long Double with std::wstrings and std::wstring_view
        REQUIRE(!cortex::MultiplicableWith<long double, std::wstring>);
        REQUIRE(!cortex::MultiplicableWith<long double, std::wstring_view>);

        // Long Double with Charaters
        REQUIRE(cortex::MultiplicableWith<long double, char>);
        REQUIRE(cortex::MultiplicableWith<long double, u_char>);
        REQUIRE(cortex::MultiplicableWith<long double, wchar_t>);

        // Long Double with Bit Specific Characters
        REQUIRE(cortex::MultiplicableWith<long double, char8_t>);
        REQUIRE(cortex::MultiplicableWith<long double, char16_t>);
        REQUIRE(cortex::MultiplicableWith<long double, char32_t>);

        // Long Double with Bit Specific Long
        REQUIRE(cortex::MultiplicableWith<long double, int8_t>);
        REQUIRE(cortex::MultiplicableWith<long double, int16_t>);
        REQUIRE(cortex::MultiplicableWith<long double, int32_t>);
        REQUIRE(cortex::MultiplicableWith<long double, int64_t>);

        // Long Double with Bit Specific Unsigned Long
        REQUIRE(cortex::MultiplicableWith<long double, uint8_t>);
        REQUIRE(cortex::MultiplicableWith<long double, uint16_t>);
        REQUIRE(cortex::MultiplicableWith<long double, uint32_t>);
        REQUIRE(cortex::MultiplicableWith<long double, uint64_t>);

        // Long Double with Bit Specific Least Integers
        REQUIRE(cortex::MultiplicableWith<long double, int_least8_t>);
        REQUIRE(cortex::MultiplicableWith<long double, int_least16_t>);
        REQUIRE(cortex::MultiplicableWith<long double, int_least32_t>);
        REQUIRE(cortex::MultiplicableWith<long double, int_least64_t>);
    }

}

TEST_CASE("Addable With : Bit Specific Signed Integers")
{
    SECTION("int8_t with _")
    {
        // int8_t with Signed Integers
        REQUIRE(cortex::MultiplicableWith<int8_t, int>);
        REQUIRE(cortex::MultiplicableWith<int8_t, short>);
        REQUIRE(cortex::MultiplicableWith<int8_t, long>);
        REQUIRE(cortex::MultiplicableWith<int8_t, long long>);

        // int8_t with Unsigned Integers
        REQUIRE(cortex::MultiplicableWith<int8_t, unsigned>);
        REQUIRE(cortex::MultiplicableWith<int8_t, unsigned short>);
        REQUIRE(cortex::MultiplicableWith<int8_t, u_short>);
        REQUIRE(cortex::MultiplicableWith<int8_t, unsigned long>);
        REQUIRE(cortex::MultiplicableWith<int8_t, unsigned long long>);
        
        // int8_t with Floating Point and Doubles
        REQUIRE(cortex::MultiplicableWith<int8_t, float>);
        REQUIRE(cortex::MultiplicableWith<int8_t, double>);
        REQUIRE(cortex::MultiplicableWith<int8_t, long double>);

        // int8_t with std::strings and std::string_view
        REQUIRE(!cortex::MultiplicableWith<int8_t, std::string>);
        REQUIRE(!cortex::MultiplicableWith<int8_t, std::string_view>);
        REQUIRE(!cortex::MultiplicableWith<int8_t, std::u8string>);
        REQUIRE(!cortex::MultiplicableWith<int8_t, std::u16string>);
        REQUIRE(!cortex::MultiplicableWith<int8_t, std::u32string>);

        // int8_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::MultiplicableWith<long long, std::wstring>);
        REQUIRE(!cortex::MultiplicableWith<long long, std::wstring_view>);

        // int8_t with Charaters
        REQUIRE(cortex::MultiplicableWith<int8_t, char>);
        REQUIRE(cortex::MultiplicableWith<int8_t, u_char>);
        REQUIRE(cortex::MultiplicableWith<int8_t, wchar_t>);

        // int8_t with Bit Specific Characters
        REQUIRE(cortex::MultiplicableWith<int8_t, char8_t>);
        REQUIRE(cortex::MultiplicableWith<int8_t, char16_t>);
        REQUIRE(cortex::MultiplicableWith<int8_t, char32_t>);

        // int8_t with Bit Specific Integers
        REQUIRE(cortex::MultiplicableWith<int8_t, int8_t>);
        REQUIRE(cortex::MultiplicableWith<int8_t, int16_t>);
        REQUIRE(cortex::MultiplicableWith<int8_t, int32_t>);
        REQUIRE(cortex::MultiplicableWith<int8_t, int64_t>);

        // int8_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::MultiplicableWith<int8_t, uint8_t>);
        REQUIRE(cortex::MultiplicableWith<int8_t, uint16_t>);
        REQUIRE(cortex::MultiplicableWith<int8_t, uint32_t>);
        REQUIRE(cortex::MultiplicableWith<int8_t, uint64_t>);

        // int8_t with Bit Specific Least Integers
        REQUIRE(cortex::MultiplicableWith<int8_t, int_least8_t>);
        REQUIRE(cortex::MultiplicableWith<int8_t, int_least16_t>);
        REQUIRE(cortex::MultiplicableWith<int8_t, int_least32_t>);
        REQUIRE(cortex::MultiplicableWith<int8_t, int_least64_t>);
    }

    SECTION("int16_t with _")
    {
        // int16_t with Signed Integers
        REQUIRE(cortex::MultiplicableWith<int16_t, int>);
        REQUIRE(cortex::MultiplicableWith<int16_t, short>);
        REQUIRE(cortex::MultiplicableWith<int16_t, long>);
        REQUIRE(cortex::MultiplicableWith<int16_t, long long>);

        // int16_t with Unsigned Integers
        REQUIRE(cortex::MultiplicableWith<int16_t, unsigned>);
        REQUIRE(cortex::MultiplicableWith<int16_t, unsigned short>);
        REQUIRE(cortex::MultiplicableWith<int16_t, u_short>);
        REQUIRE(cortex::MultiplicableWith<int16_t, unsigned long>);
        REQUIRE(cortex::MultiplicableWith<int16_t, unsigned long long>);
        
        // int16_t with Floating Point and Doubles
        REQUIRE(cortex::MultiplicableWith<int16_t, float>);
        REQUIRE(cortex::MultiplicableWith<int16_t, double>);
        REQUIRE(cortex::MultiplicableWith<int16_t, long double>);

        // int16_t with std::strings and std::string_view
        REQUIRE(!cortex::MultiplicableWith<int16_t, std::string>);
        REQUIRE(!cortex::MultiplicableWith<int16_t, std::string_view>);
        REQUIRE(!cortex::MultiplicableWith<int16_t, std::u8string>);
        REQUIRE(!cortex::MultiplicableWith<int16_t, std::u16string>);
        REQUIRE(!cortex::MultiplicableWith<int16_t, std::u32string>);

        // int16_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::MultiplicableWith<int16_t, std::wstring>);
        REQUIRE(!cortex::MultiplicableWith<int16_t, std::wstring_view>);

        // int16_t with Charaters
        REQUIRE(cortex::MultiplicableWith<int16_t, char>);
        REQUIRE(cortex::MultiplicableWith<int16_t, u_char>);
        REQUIRE(cortex::MultiplicableWith<int16_t, wchar_t>);

        // int16_t with Bit Specific Characters
        REQUIRE(cortex::MultiplicableWith<int16_t, char8_t>);
        REQUIRE(cortex::MultiplicableWith<int16_t, char16_t>);
        REQUIRE(cortex::MultiplicableWith<int16_t, char32_t>);

        // int16_t with Bit Specific Integers
        REQUIRE(cortex::MultiplicableWith<int16_t, int8_t>);
        REQUIRE(cortex::MultiplicableWith<int16_t, int16_t>);
        REQUIRE(cortex::MultiplicableWith<int16_t, int32_t>);
        REQUIRE(cortex::MultiplicableWith<int16_t, int64_t>);

        // int16_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::MultiplicableWith<int16_t, uint8_t>);
        REQUIRE(cortex::MultiplicableWith<int16_t, uint16_t>);
        REQUIRE(cortex::MultiplicableWith<int16_t, uint32_t>);
        REQUIRE(cortex::MultiplicableWith<int16_t, uint64_t>);

        // int16_t with Bit Specific Least Integers
        REQUIRE(cortex::MultiplicableWith<int16_t, int_least8_t>);
        REQUIRE(cortex::MultiplicableWith<int16_t, int_least16_t>);
        REQUIRE(cortex::MultiplicableWith<int16_t, int_least32_t>);
        REQUIRE(cortex::MultiplicableWith<int16_t, int_least64_t>);
    }

    SECTION("int32 with _")
    {
        // int32 with Signed Integers
        REQUIRE(cortex::MultiplicableWith<int32_t, int>);
        REQUIRE(cortex::MultiplicableWith<int32_t, short>);
        REQUIRE(cortex::MultiplicableWith<int32_t, long>);
        REQUIRE(cortex::MultiplicableWith<int32_t, long long>);

        // int32 with Unsigned Integers
        REQUIRE(cortex::MultiplicableWith<int32_t, unsigned>);
        REQUIRE(cortex::MultiplicableWith<int32_t, unsigned short>);
        REQUIRE(cortex::MultiplicableWith<int32_t, u_short>);
        REQUIRE(cortex::MultiplicableWith<int32_t, unsigned long>);
        REQUIRE(cortex::MultiplicableWith<int32_t, unsigned long long>);
        
        // int32 with Floating Point and Doubles
        REQUIRE(cortex::MultiplicableWith<int32_t, float>);
        REQUIRE(cortex::MultiplicableWith<int32_t, double>);
        REQUIRE(cortex::MultiplicableWith<int32_t, long double>);

        // int32 with std::strings and std::string_view
        REQUIRE(!cortex::MultiplicableWith<int32_t, std::string>);
        REQUIRE(!cortex::MultiplicableWith<int32_t, std::string_view>);
        REQUIRE(!cortex::MultiplicableWith<int32_t, std::u8string>);
        REQUIRE(!cortex::MultiplicableWith<int32_t, std::u16string>);
        REQUIRE(!cortex::MultiplicableWith<int32_t, std::u32string>);

        // int32 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::MultiplicableWith<int32_t, std::wstring>);
        REQUIRE(!cortex::MultiplicableWith<int32_t, std::wstring_view>);

        // int32_t with Charaters
        REQUIRE(cortex::MultiplicableWith<int32_t, char>);
        REQUIRE(cortex::MultiplicableWith<int32_t, u_char>);
        REQUIRE(cortex::MultiplicableWith<int32_t, wchar_t>);

        // int32_t with Bit Specific Characters
        REQUIRE(cortex::MultiplicableWith<int32_t, char8_t>);
        REQUIRE(cortex::MultiplicableWith<int32_t, char16_t>);
        REQUIRE(cortex::MultiplicableWith<int32_t, char32_t>);

        // int32_t with Bit Specific Integers
        REQUIRE(cortex::MultiplicableWith<int32_t, int8_t>);
        REQUIRE(cortex::MultiplicableWith<int32_t, int16_t>);
        REQUIRE(cortex::MultiplicableWith<int32_t, int32_t>);
        REQUIRE(cortex::MultiplicableWith<int32_t, int64_t>);

        // int32_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::MultiplicableWith<int32_t, uint8_t>);
        REQUIRE(cortex::MultiplicableWith<int32_t, uint16_t>);
        REQUIRE(cortex::MultiplicableWith<int32_t, uint32_t>);
        REQUIRE(cortex::MultiplicableWith<int32_t, uint64_t>);

        // int32_t with Bit Specific Least Integers
        REQUIRE(cortex::MultiplicableWith<int32_t, int_least8_t>);
        REQUIRE(cortex::MultiplicableWith<int32_t, int_least16_t>);
        REQUIRE(cortex::MultiplicableWith<int32_t, int_least32_t>);
        REQUIRE(cortex::MultiplicableWith<int32_t, int_least64_t>);
    }

    SECTION("int64 with _")
    {
        // int64 with Signed Integers
        REQUIRE(cortex::MultiplicableWith<int64_t, int>);
        REQUIRE(cortex::MultiplicableWith<int64_t, short>);
        REQUIRE(cortex::MultiplicableWith<int64_t, long>);
        REQUIRE(cortex::MultiplicableWith<int64_t, long long>);

        // int64 with Unsigned Integers
        REQUIRE(cortex::MultiplicableWith<int64_t, unsigned>);
        REQUIRE(cortex::MultiplicableWith<int64_t, unsigned short>);
        REQUIRE(cortex::MultiplicableWith<int64_t, u_short>);
        REQUIRE(cortex::MultiplicableWith<int64_t, unsigned long>);
        REQUIRE(cortex::MultiplicableWith<int64_t, unsigned long long>);
        
        // int64 with Floating Point and Doubles
        REQUIRE(cortex::MultiplicableWith<int64_t, float>);
        REQUIRE(cortex::MultiplicableWith<int64_t, double>);
        REQUIRE(cortex::MultiplicableWith<int64_t, long double>);

        // int64 with std::strings and std::string_view
        REQUIRE(!cortex::MultiplicableWith<int64_t, std::string>);
        REQUIRE(!cortex::MultiplicableWith<int64_t, std::string_view>);
        REQUIRE(!cortex::MultiplicableWith<int64_t, std::u8string>);
        REQUIRE(!cortex::MultiplicableWith<int64_t, std::u16string>);
        REQUIRE(!cortex::MultiplicableWith<int64_t, std::u32string>);

        // int64 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::MultiplicableWith<int64_t, std::wstring>);
        REQUIRE(!cortex::MultiplicableWith<int64_t, std::wstring_view>);

        // int64_t with Charaters
        REQUIRE(cortex::MultiplicableWith<int64_t, char>);
        REQUIRE(cortex::MultiplicableWith<int64_t, u_char>);
        REQUIRE(cortex::MultiplicableWith<int64_t, wchar_t>);

        // int64_t with Bit Specific Characters
        REQUIRE(cortex::MultiplicableWith<int64_t, char8_t>);
        REQUIRE(cortex::MultiplicableWith<int64_t, char16_t>);
        REQUIRE(cortex::MultiplicableWith<int64_t, char32_t>);

        // int64_t with Bit Specific Integers
        REQUIRE(cortex::MultiplicableWith<int64_t, int8_t>);
        REQUIRE(cortex::MultiplicableWith<int64_t, int16_t>);
        REQUIRE(cortex::MultiplicableWith<int64_t, int32_t>);
        REQUIRE(cortex::MultiplicableWith<int64_t, int64_t>);

        // int64_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::MultiplicableWith<int64_t, uint8_t>);
        REQUIRE(cortex::MultiplicableWith<int64_t, uint16_t>);
        REQUIRE(cortex::MultiplicableWith<int64_t, uint32_t>);
        REQUIRE(cortex::MultiplicableWith<int64_t, uint64_t>);

        // int64_t with Bit Specific Least Integers
        REQUIRE(cortex::MultiplicableWith<int64_t, int_least8_t>);
        REQUIRE(cortex::MultiplicableWith<int64_t, int_least16_t>);
        REQUIRE(cortex::MultiplicableWith<int64_t, int_least32_t>);
        REQUIRE(cortex::MultiplicableWith<int64_t, int_least64_t>);
}
}

TEST_CASE("Addable With : Bit Specific Unsigned Integers")
{
    SECTION("uint8_t with _")
    {
        // uint8_t with Signed Integers
        REQUIRE(cortex::MultiplicableWith<uint8_t, int>);
        REQUIRE(cortex::MultiplicableWith<uint8_t, short>);
        REQUIRE(cortex::MultiplicableWith<uint8_t, long>);
        REQUIRE(cortex::MultiplicableWith<uint8_t, long long>);

        // uint8_t with Unsigned Integers
        REQUIRE(cortex::MultiplicableWith<uint8_t, unsigned>);
        REQUIRE(cortex::MultiplicableWith<uint8_t, unsigned short>);
        REQUIRE(cortex::MultiplicableWith<uint8_t, u_short>);
        REQUIRE(cortex::MultiplicableWith<uint8_t, unsigned long>);
        REQUIRE(cortex::MultiplicableWith<uint8_t, unsigned long long>);
        
        // uint8_t with Floating Point and Doubles
        REQUIRE(cortex::MultiplicableWith<uint8_t, float>);
        REQUIRE(cortex::MultiplicableWith<uint8_t, double>);
        REQUIRE(cortex::MultiplicableWith<uint8_t, long double>);

        // uint8_t with std::strings and std::string_view
        REQUIRE(!cortex::MultiplicableWith<uint8_t, std::string>);
        REQUIRE(!cortex::MultiplicableWith<uint8_t, std::string_view>);
        REQUIRE(!cortex::MultiplicableWith<uint8_t, std::u8string>);
        REQUIRE(!cortex::MultiplicableWith<uint8_t, std::u16string>);
        REQUIRE(!cortex::MultiplicableWith<uint8_t, std::u32string>);

        // uint8_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::MultiplicableWith<long long, std::wstring>);
        REQUIRE(!cortex::MultiplicableWith<long long, std::wstring_view>);

        // uint8_t with Charaters
        REQUIRE(cortex::MultiplicableWith<uint8_t, char>);
        REQUIRE(cortex::MultiplicableWith<uint8_t, u_char>);
        REQUIRE(cortex::MultiplicableWith<uint8_t, wchar_t>);

        // uint8_t with Bit Specific Characters
        REQUIRE(cortex::MultiplicableWith<uint8_t, char8_t>);
        REQUIRE(cortex::MultiplicableWith<uint8_t, char16_t>);
        REQUIRE(cortex::MultiplicableWith<uint8_t, char32_t>);

        // uint8_t with Bit Specific Integers
        REQUIRE(cortex::MultiplicableWith<uint8_t, int8_t>);
        REQUIRE(cortex::MultiplicableWith<uint8_t, int16_t>);
        REQUIRE(cortex::MultiplicableWith<uint8_t, int32_t>);
        REQUIRE(cortex::MultiplicableWith<uint8_t, int64_t>);

        // uint8_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::MultiplicableWith<uint8_t, uint8_t>);
        REQUIRE(cortex::MultiplicableWith<uint8_t, uint16_t>);
        REQUIRE(cortex::MultiplicableWith<uint8_t, uint32_t>);
        REQUIRE(cortex::MultiplicableWith<uint8_t, uint64_t>);

        // uint8_t with Bit Specific Least Integers
        REQUIRE(cortex::MultiplicableWith<uint8_t, int_least8_t>);
        REQUIRE(cortex::MultiplicableWith<uint8_t, int_least16_t>);
        REQUIRE(cortex::MultiplicableWith<uint8_t, int_least32_t>);
        REQUIRE(cortex::MultiplicableWith<uint8_t, int_least64_t>);
    }

    SECTION("uint16_t with _")
    {
        // uint16_t with Signed Integers
        REQUIRE(cortex::MultiplicableWith<uint16_t, int>);
        REQUIRE(cortex::MultiplicableWith<uint16_t, short>);
        REQUIRE(cortex::MultiplicableWith<uint16_t, long>);
        REQUIRE(cortex::MultiplicableWith<uint16_t, long long>);

        // uint16_t with Unsigned Integers
        REQUIRE(cortex::MultiplicableWith<uint16_t, unsigned>);
        REQUIRE(cortex::MultiplicableWith<uint16_t, unsigned short>);
        REQUIRE(cortex::MultiplicableWith<uint16_t, u_short>);
        REQUIRE(cortex::MultiplicableWith<uint16_t, unsigned long>);
        REQUIRE(cortex::MultiplicableWith<uint16_t, unsigned long long>);
        
        // uint16_t with Floating Point and Doubles
        REQUIRE(cortex::MultiplicableWith<uint16_t, float>);
        REQUIRE(cortex::MultiplicableWith<uint16_t, double>);
        REQUIRE(cortex::MultiplicableWith<uint16_t, long double>);

        // uint16_t with std::strings and std::string_view
        REQUIRE(!cortex::MultiplicableWith<uint16_t, std::string>);
        REQUIRE(!cortex::MultiplicableWith<uint16_t, std::string_view>);
        REQUIRE(!cortex::MultiplicableWith<uint16_t, std::u8string>);
        REQUIRE(!cortex::MultiplicableWith<uint16_t, std::u16string>);
        REQUIRE(!cortex::MultiplicableWith<uint16_t, std::u32string>);

        // uint16_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::MultiplicableWith<uint16_t, std::wstring>);
        REQUIRE(!cortex::MultiplicableWith<uint16_t, std::wstring_view>);

        // uint16_t with Charaters
        REQUIRE(cortex::MultiplicableWith<uint16_t, char>);
        REQUIRE(cortex::MultiplicableWith<uint16_t, u_char>);
        REQUIRE(cortex::MultiplicableWith<uint16_t, wchar_t>);

        // uint16_t with Bit Specific Characters
        REQUIRE(cortex::MultiplicableWith<uint16_t, char8_t>);
        REQUIRE(cortex::MultiplicableWith<uint16_t, char16_t>);
        REQUIRE(cortex::MultiplicableWith<uint16_t, char32_t>);

        // uint16_t with Bit Specific Integers
        REQUIRE(cortex::MultiplicableWith<uint16_t, int8_t>);
        REQUIRE(cortex::MultiplicableWith<uint16_t, int16_t>);
        REQUIRE(cortex::MultiplicableWith<uint16_t, int32_t>);
        REQUIRE(cortex::MultiplicableWith<uint16_t, int64_t>);

        // uint16_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::MultiplicableWith<uint16_t, uint8_t>);
        REQUIRE(cortex::MultiplicableWith<uint16_t, uint16_t>);
        REQUIRE(cortex::MultiplicableWith<uint16_t, uint32_t>);
        REQUIRE(cortex::MultiplicableWith<uint16_t, uint64_t>);

        // uint16_t with Bit Specific Least Integers
        REQUIRE(cortex::MultiplicableWith<uint16_t, int_least8_t>);
        REQUIRE(cortex::MultiplicableWith<uint16_t, int_least16_t>);
        REQUIRE(cortex::MultiplicableWith<uint16_t, int_least32_t>);
        REQUIRE(cortex::MultiplicableWith<uint16_t, int_least64_t>);
    }

    SECTION("uint32_t with _")
    {
        // int32 with Signed Integers
        REQUIRE(cortex::MultiplicableWith<uint32_t, int>);
        REQUIRE(cortex::MultiplicableWith<uint32_t, short>);
        REQUIRE(cortex::MultiplicableWith<uint32_t, long>);
        REQUIRE(cortex::MultiplicableWith<uint32_t, long long>);

        // int32 with Unsigned Integers
        REQUIRE(cortex::MultiplicableWith<uint32_t, unsigned>);
        REQUIRE(cortex::MultiplicableWith<uint32_t, unsigned short>);
        REQUIRE(cortex::MultiplicableWith<uint32_t, u_short>);
        REQUIRE(cortex::MultiplicableWith<uint32_t, unsigned long>);
        REQUIRE(cortex::MultiplicableWith<uint32_t, unsigned long long>);
        
        // int32 with Floating Point and Doubles
        REQUIRE(cortex::MultiplicableWith<uint32_t, float>);
        REQUIRE(cortex::MultiplicableWith<uint32_t, double>);
        REQUIRE(cortex::MultiplicableWith<uint32_t, long double>);

        // int32 with std::strings and std::string_view
        REQUIRE(!cortex::MultiplicableWith<uint32_t, std::string>);
        REQUIRE(!cortex::MultiplicableWith<uint32_t, std::string_view>);
        REQUIRE(!cortex::MultiplicableWith<uint32_t, std::u8string>);
        REQUIRE(!cortex::MultiplicableWith<uint32_t, std::u16string>);
        REQUIRE(!cortex::MultiplicableWith<uint32_t, std::u32string>);

        // int32 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::MultiplicableWith<uint32_t, std::wstring>);
        REQUIRE(!cortex::MultiplicableWith<uint32_t, std::wstring_view>);

        // uint32_t with Charaters
        REQUIRE(cortex::MultiplicableWith<uint32_t, char>);
        REQUIRE(cortex::MultiplicableWith<uint32_t, u_char>);
        REQUIRE(cortex::MultiplicableWith<uint32_t, wchar_t>);

        // uint32_t with Bit Specific Characters
        REQUIRE(cortex::MultiplicableWith<uint32_t, char8_t>);
        REQUIRE(cortex::MultiplicableWith<uint32_t, char16_t>);
        REQUIRE(cortex::MultiplicableWith<uint32_t, char32_t>);

        // uint32_t with Bit Specific Integers
        REQUIRE(cortex::MultiplicableWith<uint32_t, int8_t>);
        REQUIRE(cortex::MultiplicableWith<uint32_t, int16_t>);
        REQUIRE(cortex::MultiplicableWith<uint32_t, int32_t>);
        REQUIRE(cortex::MultiplicableWith<uint32_t, int64_t>);

        // uint32_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::MultiplicableWith<uint32_t, uint8_t>);
        REQUIRE(cortex::MultiplicableWith<uint32_t, uint16_t>);
        REQUIRE(cortex::MultiplicableWith<uint32_t, uint32_t>);
        REQUIRE(cortex::MultiplicableWith<uint32_t, uint64_t>);

        // uint32_t with Bit Specific Least Integers
        REQUIRE(cortex::MultiplicableWith<uint32_t, int_least8_t>);
        REQUIRE(cortex::MultiplicableWith<uint32_t, int_least16_t>);
        REQUIRE(cortex::MultiplicableWith<uint32_t, int_least32_t>);
        REQUIRE(cortex::MultiplicableWith<uint32_t, int_least64_t>);
    }

    SECTION("uint64_t with _")
    {
        // int64 with Signed Integers
        REQUIRE(cortex::MultiplicableWith<uint64_t, int>);
        REQUIRE(cortex::MultiplicableWith<uint64_t, short>);
        REQUIRE(cortex::MultiplicableWith<uint64_t, long>);
        REQUIRE(cortex::MultiplicableWith<uint64_t, long long>);

        // int64 with Unsigned Integers
        REQUIRE(cortex::MultiplicableWith<uint64_t, unsigned>);
        REQUIRE(cortex::MultiplicableWith<uint64_t, unsigned short>);
        REQUIRE(cortex::MultiplicableWith<uint64_t, u_short>);
        REQUIRE(cortex::MultiplicableWith<uint64_t, unsigned long>);
        REQUIRE(cortex::MultiplicableWith<uint64_t, unsigned long long>);
        
        // int64 with Floating Point and Doubles
        REQUIRE(cortex::MultiplicableWith<uint64_t, float>);
        REQUIRE(cortex::MultiplicableWith<uint64_t, double>);
        REQUIRE(cortex::MultiplicableWith<uint64_t, long double>);

        // int64 with std::strings and std::string_view
        REQUIRE(!cortex::MultiplicableWith<uint64_t, std::string>);
        REQUIRE(!cortex::MultiplicableWith<uint64_t, std::string_view>);
        REQUIRE(!cortex::MultiplicableWith<uint64_t, std::u8string>);
        REQUIRE(!cortex::MultiplicableWith<uint64_t, std::u16string>);
        REQUIRE(!cortex::MultiplicableWith<uint64_t, std::u32string>);

        // int64 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::MultiplicableWith<uint64_t, std::wstring>);
        REQUIRE(!cortex::MultiplicableWith<uint64_t, std::wstring_view>);

        // uint64_t with Charaters
        REQUIRE(cortex::MultiplicableWith<uint64_t, char>);
        REQUIRE(cortex::MultiplicableWith<uint64_t, u_char>);
        REQUIRE(cortex::MultiplicableWith<uint64_t, wchar_t>);

        // uint64_t with Bit Specific Characters
        REQUIRE(cortex::MultiplicableWith<uint64_t, char8_t>);
        REQUIRE(cortex::MultiplicableWith<uint64_t, char16_t>);
        REQUIRE(cortex::MultiplicableWith<uint64_t, char32_t>);

        // uint64_t with Bit Specific Integers
        REQUIRE(cortex::MultiplicableWith<uint64_t, int8_t>);
        REQUIRE(cortex::MultiplicableWith<uint64_t, int16_t>);
        REQUIRE(cortex::MultiplicableWith<uint64_t, int32_t>);
        REQUIRE(cortex::MultiplicableWith<uint64_t, int64_t>);

        // uint64_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::MultiplicableWith<uint64_t, uint8_t>);
        REQUIRE(cortex::MultiplicableWith<uint64_t, uint16_t>);
        REQUIRE(cortex::MultiplicableWith<uint64_t, uint32_t>);
        REQUIRE(cortex::MultiplicableWith<uint64_t, uint64_t>);

        // uint64_t with Bit Specific Least Integers
        REQUIRE(cortex::MultiplicableWith<uint64_t, int_least8_t>);
        REQUIRE(cortex::MultiplicableWith<uint64_t, int_least16_t>);
        REQUIRE(cortex::MultiplicableWith<uint64_t, int_least32_t>);
        REQUIRE(cortex::MultiplicableWith<uint64_t, int_least64_t>);
    }
}

TEST_CASE("Addable With : std::size_t")
{
    SECTION("std::size_t with _")
    {
        // std::size_t with Signed Integers
        REQUIRE(cortex::MultiplicableWith<std::size_t, int>);
        REQUIRE(cortex::MultiplicableWith<std::size_t, short>);
        REQUIRE(cortex::MultiplicableWith<std::size_t, long>);
        REQUIRE(cortex::MultiplicableWith<std::size_t, long long>);

        // std::size_t with Unsigned Integers
        REQUIRE(cortex::MultiplicableWith<std::size_t, unsigned>);
        REQUIRE(cortex::MultiplicableWith<std::size_t, unsigned short>);
        REQUIRE(cortex::MultiplicableWith<std::size_t, u_short>);
        REQUIRE(cortex::MultiplicableWith<std::size_t, unsigned long>);
        REQUIRE(cortex::MultiplicableWith<std::size_t, unsigned long long>);
        
        // std::size_t with Floating Point and Doubles
        REQUIRE(cortex::MultiplicableWith<std::size_t, float>);
        REQUIRE(cortex::MultiplicableWith<std::size_t, double>);
        REQUIRE(cortex::MultiplicableWith<std::size_t, long double>);

        // std::size_t with std::strings and std::string_view
        REQUIRE(!cortex::MultiplicableWith<std::size_t, std::string>);
        REQUIRE(!cortex::MultiplicableWith<std::size_t, std::string_view>);
        REQUIRE(!cortex::MultiplicableWith<std::size_t, std::u8string>);
        REQUIRE(!cortex::MultiplicableWith<std::size_t, std::u16string>);
        REQUIRE(!cortex::MultiplicableWith<std::size_t, std::u32string>);

        // std::size_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::MultiplicableWith<long long, std::wstring>);
        REQUIRE(!cortex::MultiplicableWith<long long, std::wstring_view>);

        // std::size_t with Charaters
        REQUIRE(cortex::MultiplicableWith<std::size_t, char>);
        REQUIRE(cortex::MultiplicableWith<std::size_t, u_char>);
        REQUIRE(cortex::MultiplicableWith<std::size_t, wchar_t>);

        // std::size_t with Bit Specific Characters
        REQUIRE(cortex::MultiplicableWith<std::size_t, char8_t>);
        REQUIRE(cortex::MultiplicableWith<std::size_t, char16_t>);
        REQUIRE(cortex::MultiplicableWith<std::size_t, char32_t>);

        // std::size_t with Bit Specific Integers
        REQUIRE(cortex::MultiplicableWith<std::size_t, int8_t>);
        REQUIRE(cortex::MultiplicableWith<std::size_t, int16_t>);
        REQUIRE(cortex::MultiplicableWith<std::size_t, int32_t>);
        REQUIRE(cortex::MultiplicableWith<std::size_t, int64_t>);

        // std::size_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::MultiplicableWith<std::size_t, uint8_t>);
        REQUIRE(cortex::MultiplicableWith<std::size_t, uint16_t>);
        REQUIRE(cortex::MultiplicableWith<std::size_t, uint32_t>);
        REQUIRE(cortex::MultiplicableWith<std::size_t, uint64_t>);

        // std::size_t with Bit Specific Least Integers
        REQUIRE(cortex::MultiplicableWith<std::size_t, int_least8_t>);
        REQUIRE(cortex::MultiplicableWith<std::size_t, int_least16_t>);
        REQUIRE(cortex::MultiplicableWith<std::size_t, int_least32_t>);
        REQUIRE(cortex::MultiplicableWith<std::size_t, int_least64_t>);
    }
}

TEST_CASE("MultiplicableWith : Fast Integers")
{
    SECTION("int_fast8_t with _")
    {
        // int_fast8_t with Signed Integers
        REQUIRE(cortex::MultiplicableWith<int_fast8_t, int>);
        REQUIRE(cortex::MultiplicableWith<int_fast8_t, short>);
        REQUIRE(cortex::MultiplicableWith<int_fast8_t, long>);
        REQUIRE(cortex::MultiplicableWith<int_fast8_t, long long>);

        // int_fast8_t with Unsigned Integers
        REQUIRE(cortex::MultiplicableWith<int_fast8_t, unsigned>);
        REQUIRE(cortex::MultiplicableWith<int_fast8_t, unsigned short>);
        REQUIRE(cortex::MultiplicableWith<int_fast8_t, u_short>);
        REQUIRE(cortex::MultiplicableWith<int_fast8_t, unsigned long>);
        REQUIRE(cortex::MultiplicableWith<int_fast8_t, unsigned long long>);
        
        // int_fast8_t with Floating Point and Doubles
        REQUIRE(cortex::MultiplicableWith<int_fast8_t, float>);
        REQUIRE(cortex::MultiplicableWith<int_fast8_t, double>);
        REQUIRE(cortex::MultiplicableWith<int_fast8_t, long double>);

        // int_fast8_t with std::strings and std::string_view
        REQUIRE(!cortex::MultiplicableWith<int_fast8_t, std::string>);
        REQUIRE(!cortex::MultiplicableWith<int_fast8_t, std::string_view>);
        REQUIRE(!cortex::MultiplicableWith<int_fast8_t, std::u8string>);
        REQUIRE(!cortex::MultiplicableWith<int_fast8_t, std::u16string>);
        REQUIRE(!cortex::MultiplicableWith<int_fast8_t, std::u32string>);

        // int_fast8_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::MultiplicableWith<long long, std::wstring>);
        REQUIRE(!cortex::MultiplicableWith<long long, std::wstring_view>);

        // int_fast8_t with Charaters
        REQUIRE(cortex::MultiplicableWith<int_fast8_t, char>);
        REQUIRE(cortex::MultiplicableWith<int_fast8_t, u_char>);
        REQUIRE(cortex::MultiplicableWith<int_fast8_t, wchar_t>);

        // int_fast8_t with Bit Specific Characters
        REQUIRE(cortex::MultiplicableWith<int_fast8_t, char8_t>);
        REQUIRE(cortex::MultiplicableWith<int_fast8_t, char16_t>);
        REQUIRE(cortex::MultiplicableWith<int_fast8_t, char32_t>);

        // int_fast8_t with Bit Specific Integers
        REQUIRE(cortex::MultiplicableWith<int_fast8_t, int8_t>);
        REQUIRE(cortex::MultiplicableWith<int_fast8_t, int16_t>);
        REQUIRE(cortex::MultiplicableWith<int_fast8_t, int32_t>);
        REQUIRE(cortex::MultiplicableWith<int_fast8_t, int64_t>);

        // int_fast8_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::MultiplicableWith<int_fast8_t, uint8_t>);
        REQUIRE(cortex::MultiplicableWith<int_fast8_t, uint16_t>);
        REQUIRE(cortex::MultiplicableWith<int_fast8_t, uint32_t>);
        REQUIRE(cortex::MultiplicableWith<int_fast8_t, uint64_t>);

        // int_fast8_t with Bit Specific Least Integers
        REQUIRE(cortex::MultiplicableWith<int_fast8_t, int_least8_t>);
        REQUIRE(cortex::MultiplicableWith<int_fast8_t, int_least16_t>);
        REQUIRE(cortex::MultiplicableWith<int_fast8_t, int_least32_t>);
        REQUIRE(cortex::MultiplicableWith<int_fast8_t, int_least64_t>);
    }

    SECTION("int_fast16_t with _")
    {
        // int_fast16_t with Signed Integers
        REQUIRE(cortex::MultiplicableWith<int_fast16_t, int>);
        REQUIRE(cortex::MultiplicableWith<int_fast16_t, short>);
        REQUIRE(cortex::MultiplicableWith<int_fast16_t, long>);
        REQUIRE(cortex::MultiplicableWith<int_fast16_t, long long>);

        // int_fast16_t with Unsigned Integers
        REQUIRE(cortex::MultiplicableWith<int_fast16_t, unsigned>);
        REQUIRE(cortex::MultiplicableWith<int_fast16_t, unsigned short>);
        REQUIRE(cortex::MultiplicableWith<int_fast16_t, u_short>);
        REQUIRE(cortex::MultiplicableWith<int_fast16_t, unsigned long>);
        REQUIRE(cortex::MultiplicableWith<int_fast16_t, unsigned long long>);
        
        // int_fast16_t with Floating Point and Doubles
        REQUIRE(cortex::MultiplicableWith<int_fast16_t, float>);
        REQUIRE(cortex::MultiplicableWith<int_fast16_t, double>);
        REQUIRE(cortex::MultiplicableWith<int_fast16_t, long double>);

        // int_fast16_t with std::strings and std::string_view
        REQUIRE(!cortex::MultiplicableWith<int_fast16_t, std::string>);
        REQUIRE(!cortex::MultiplicableWith<int_fast16_t, std::string_view>);
        REQUIRE(!cortex::MultiplicableWith<int_fast16_t, std::u8string>);
        REQUIRE(!cortex::MultiplicableWith<int_fast16_t, std::u16string>);
        REQUIRE(!cortex::MultiplicableWith<int_fast16_t, std::u32string>);

        // int_fast16_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::MultiplicableWith<int_fast16_t, std::wstring>);
        REQUIRE(!cortex::MultiplicableWith<int_fast16_t, std::wstring_view>);

        // int_fast16_t with Charaters
        REQUIRE(cortex::MultiplicableWith<int_fast16_t, char>);
        REQUIRE(cortex::MultiplicableWith<int_fast16_t, u_char>);
        REQUIRE(cortex::MultiplicableWith<int_fast16_t, wchar_t>);

        // int_fast16_t with Bit Specific Characters
        REQUIRE(cortex::MultiplicableWith<int_fast16_t, char8_t>);
        REQUIRE(cortex::MultiplicableWith<int_fast16_t, char16_t>);
        REQUIRE(cortex::MultiplicableWith<int_fast16_t, char32_t>);

        // int_fast16_t with Bit Specific Integers
        REQUIRE(cortex::MultiplicableWith<int_fast16_t, int8_t>);
        REQUIRE(cortex::MultiplicableWith<int_fast16_t, int16_t>);
        REQUIRE(cortex::MultiplicableWith<int_fast16_t, int32_t>);
        REQUIRE(cortex::MultiplicableWith<int_fast16_t, int64_t>);

        // int_fast16_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::MultiplicableWith<int_fast16_t, uint8_t>);
        REQUIRE(cortex::MultiplicableWith<int_fast16_t, uint16_t>);
        REQUIRE(cortex::MultiplicableWith<int_fast16_t, uint32_t>);
        REQUIRE(cortex::MultiplicableWith<int_fast16_t, uint64_t>);

        // int_fast16_t with Bit Specific Least Integers
        REQUIRE(cortex::MultiplicableWith<int_fast16_t, int_least8_t>);
        REQUIRE(cortex::MultiplicableWith<int_fast16_t, int_least16_t>);
        REQUIRE(cortex::MultiplicableWith<int_fast16_t, int_least32_t>);
        REQUIRE(cortex::MultiplicableWith<int_fast16_t, int_least64_t>);
    }

    SECTION("int_fast32_t with _")
    {
        // int32 with Signed Integers
        REQUIRE(cortex::MultiplicableWith<int_fast32_t, int>);
        REQUIRE(cortex::MultiplicableWith<int_fast32_t, short>);
        REQUIRE(cortex::MultiplicableWith<int_fast32_t, long>);
        REQUIRE(cortex::MultiplicableWith<int_fast32_t, long long>);

        // int32 with Unsigned Integers
        REQUIRE(cortex::MultiplicableWith<int_fast32_t, unsigned>);
        REQUIRE(cortex::MultiplicableWith<int_fast32_t, unsigned short>);
        REQUIRE(cortex::MultiplicableWith<int_fast32_t, u_short>);
        REQUIRE(cortex::MultiplicableWith<int_fast32_t, unsigned long>);
        REQUIRE(cortex::MultiplicableWith<int_fast32_t, unsigned long long>);
        
        // int32 with Floating Point and Doubles
        REQUIRE(cortex::MultiplicableWith<int_fast32_t, float>);
        REQUIRE(cortex::MultiplicableWith<int_fast32_t, double>);
        REQUIRE(cortex::MultiplicableWith<int_fast32_t, long double>);

        // int32 with std::strings and std::string_view
        REQUIRE(!cortex::MultiplicableWith<int_fast32_t, std::string>);
        REQUIRE(!cortex::MultiplicableWith<int_fast32_t, std::string_view>);
        REQUIRE(!cortex::MultiplicableWith<int_fast32_t, std::u8string>);
        REQUIRE(!cortex::MultiplicableWith<int_fast32_t, std::u16string>);
        REQUIRE(!cortex::MultiplicableWith<int_fast32_t, std::u32string>);

        // int32 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::MultiplicableWith<int_fast32_t, std::wstring>);
        REQUIRE(!cortex::MultiplicableWith<int_fast32_t, std::wstring_view>);

        // int_fast32_t with Charaters
        REQUIRE(cortex::MultiplicableWith<int_fast32_t, char>);
        REQUIRE(cortex::MultiplicableWith<int_fast32_t, u_char>);
        REQUIRE(cortex::MultiplicableWith<int_fast32_t, wchar_t>);

        // int_fast32_t with Bit Specific Characters
        REQUIRE(cortex::MultiplicableWith<int_fast32_t, char8_t>);
        REQUIRE(cortex::MultiplicableWith<int_fast32_t, char16_t>);
        REQUIRE(cortex::MultiplicableWith<int_fast32_t, char32_t>);

        // int_fast32_t with Bit Specific Integers
        REQUIRE(cortex::MultiplicableWith<int_fast32_t, int8_t>);
        REQUIRE(cortex::MultiplicableWith<int_fast32_t, int16_t>);
        REQUIRE(cortex::MultiplicableWith<int_fast32_t, int32_t>);
        REQUIRE(cortex::MultiplicableWith<int_fast32_t, int64_t>);

        // int_fast32_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::MultiplicableWith<int_fast32_t, uint8_t>);
        REQUIRE(cortex::MultiplicableWith<int_fast32_t, uint16_t>);
        REQUIRE(cortex::MultiplicableWith<int_fast32_t, uint32_t>);
        REQUIRE(cortex::MultiplicableWith<int_fast32_t, uint64_t>);

        // int_fast32_t with Bit Specific Least Integers
        REQUIRE(cortex::MultiplicableWith<int_fast32_t, int_least8_t>);
        REQUIRE(cortex::MultiplicableWith<int_fast32_t, int_least16_t>);
        REQUIRE(cortex::MultiplicableWith<int_fast32_t, int_least32_t>);
        REQUIRE(cortex::MultiplicableWith<int_fast32_t, int_least64_t>);
    }

    SECTION("int_fast64_t with _")
    {
        // int64 with Signed Integers
        REQUIRE(cortex::MultiplicableWith<int_fast64_t, int>);
        REQUIRE(cortex::MultiplicableWith<int_fast64_t, short>);
        REQUIRE(cortex::MultiplicableWith<int_fast64_t, long>);
        REQUIRE(cortex::MultiplicableWith<int_fast64_t, long long>);

        // int64 with Unsigned Integers
        REQUIRE(cortex::MultiplicableWith<int_fast64_t, unsigned>);
        REQUIRE(cortex::MultiplicableWith<int_fast64_t, unsigned short>);
        REQUIRE(cortex::MultiplicableWith<int_fast64_t, u_short>);
        REQUIRE(cortex::MultiplicableWith<int_fast64_t, unsigned long>);
        REQUIRE(cortex::MultiplicableWith<int_fast64_t, unsigned long long>);
        
        // int64 with Floating Point and Doubles
        REQUIRE(cortex::MultiplicableWith<int_fast64_t, float>);
        REQUIRE(cortex::MultiplicableWith<int_fast64_t, double>);
        REQUIRE(cortex::MultiplicableWith<int_fast64_t, long double>);

        // int64 with std::strings and std::string_view
        REQUIRE(!cortex::MultiplicableWith<int_fast64_t, std::string>);
        REQUIRE(!cortex::MultiplicableWith<int_fast64_t, std::string_view>);
        REQUIRE(!cortex::MultiplicableWith<int_fast64_t, std::u8string>);
        REQUIRE(!cortex::MultiplicableWith<int_fast64_t, std::u16string>);
        REQUIRE(!cortex::MultiplicableWith<int_fast64_t, std::u32string>);

        // int64 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::MultiplicableWith<int_fast64_t, std::wstring>);
        REQUIRE(!cortex::MultiplicableWith<int_fast64_t, std::wstring_view>);

        // int_fast64_t with Charaters
        REQUIRE(cortex::MultiplicableWith<int_fast64_t, char>);
        REQUIRE(cortex::MultiplicableWith<int_fast64_t, u_char>);
        REQUIRE(cortex::MultiplicableWith<int_fast64_t, wchar_t>);

        // int_fast64_t with Bit Specific Characters
        REQUIRE(cortex::MultiplicableWith<int_fast64_t, char8_t>);
        REQUIRE(cortex::MultiplicableWith<int_fast64_t, char16_t>);
        REQUIRE(cortex::MultiplicableWith<int_fast64_t, char32_t>);

        // int_fast64_t with Bit Specific Integers
        REQUIRE(cortex::MultiplicableWith<int_fast64_t, int8_t>);
        REQUIRE(cortex::MultiplicableWith<int_fast64_t, int16_t>);
        REQUIRE(cortex::MultiplicableWith<int_fast64_t, int32_t>);
        REQUIRE(cortex::MultiplicableWith<int_fast64_t, int64_t>);

        // int_fast64_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::MultiplicableWith<int_fast64_t, uint8_t>);
        REQUIRE(cortex::MultiplicableWith<int_fast64_t, uint16_t>);
        REQUIRE(cortex::MultiplicableWith<int_fast64_t, uint32_t>);
        REQUIRE(cortex::MultiplicableWith<int_fast64_t, uint64_t>);

        // int_fast64_t with Bit Specific Least Integers
        REQUIRE(cortex::MultiplicableWith<int_fast64_t, int_least8_t>);
        REQUIRE(cortex::MultiplicableWith<int_fast64_t, int_least16_t>);
        REQUIRE(cortex::MultiplicableWith<int_fast64_t, int_least32_t>);
        REQUIRE(cortex::MultiplicableWith<int_fast64_t, int_least64_t>);
    }
}

TEST_CASE("MultiplicableWith : Least Integers")
{
    SECTION("int_least8_t with _")
    {
        // int_fast8_t with Signed Integers
        REQUIRE(cortex::MultiplicableWith<int_least8_t, int>);
        REQUIRE(cortex::MultiplicableWith<int_least8_t, short>);
        REQUIRE(cortex::MultiplicableWith<int_least8_t, long>);
        REQUIRE(cortex::MultiplicableWith<int_least8_t, long long>);

        // int_fast8_t with Unsigned Integers
        REQUIRE(cortex::MultiplicableWith<int_least8_t, unsigned>);
        REQUIRE(cortex::MultiplicableWith<int_least8_t, unsigned short>);
        REQUIRE(cortex::MultiplicableWith<int_least8_t, u_short>);
        REQUIRE(cortex::MultiplicableWith<int_least8_t, unsigned long>);
        REQUIRE(cortex::MultiplicableWith<int_least8_t, unsigned long long>);
        
        // int_fast8_t with Floating Point and Doubles
        REQUIRE(cortex::MultiplicableWith<int_least8_t, float>);
        REQUIRE(cortex::MultiplicableWith<int_least8_t, double>);
        REQUIRE(cortex::MultiplicableWith<int_least8_t, long double>);

        // int_fast8_t with std::strings and std::string_view
        REQUIRE(!cortex::MultiplicableWith<int_least8_t, std::string>);
        REQUIRE(!cortex::MultiplicableWith<int_least8_t, std::string_view>);
        REQUIRE(!cortex::MultiplicableWith<int_least8_t, std::u8string>);
        REQUIRE(!cortex::MultiplicableWith<int_least8_t, std::u16string>);
        REQUIRE(!cortex::MultiplicableWith<int_least8_t, std::u32string>);

        // int_fast8_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::MultiplicableWith<long long, std::wstring>);
        REQUIRE(!cortex::MultiplicableWith<long long, std::wstring_view>);

        // int_fast8_t with Charaters
        REQUIRE(cortex::MultiplicableWith<int_least8_t, char>);
        REQUIRE(cortex::MultiplicableWith<int_least8_t, u_char>);
        REQUIRE(cortex::MultiplicableWith<int_least8_t, wchar_t>);

        // int_fast8_t with Bit Specific Characters
        REQUIRE(cortex::MultiplicableWith<int_least8_t, char8_t>);
        REQUIRE(cortex::MultiplicableWith<int_least8_t, char16_t>);
        REQUIRE(cortex::MultiplicableWith<int_least8_t, char32_t>);

        // int_fast8_t with Bit Specific Integers
        REQUIRE(cortex::MultiplicableWith<int_least8_t, int8_t>);
        REQUIRE(cortex::MultiplicableWith<int_least8_t, int16_t>);
        REQUIRE(cortex::MultiplicableWith<int_least8_t, int32_t>);
        REQUIRE(cortex::MultiplicableWith<int_least8_t, int64_t>);

        // int_fast8_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::MultiplicableWith<int_least8_t, uint8_t>);
        REQUIRE(cortex::MultiplicableWith<int_least8_t, uint16_t>);
        REQUIRE(cortex::MultiplicableWith<int_least8_t, uint32_t>);
        REQUIRE(cortex::MultiplicableWith<int_least8_t, uint64_t>);

        // int_fast8_t with Bit Specific Least Integers
        REQUIRE(cortex::MultiplicableWith<int_least8_t, int_least8_t>);
        REQUIRE(cortex::MultiplicableWith<int_least8_t, int_least16_t>);
        REQUIRE(cortex::MultiplicableWith<int_least8_t, int_least32_t>);
        REQUIRE(cortex::MultiplicableWith<int_least8_t, int_least64_t>);
    }

    SECTION("int_least16_t with _")
    {
        // int_fast16_t with Signed Integers
        REQUIRE(cortex::MultiplicableWith<int_least16_t, int>);
        REQUIRE(cortex::MultiplicableWith<int_least16_t, short>);
        REQUIRE(cortex::MultiplicableWith<int_least16_t, long>);
        REQUIRE(cortex::MultiplicableWith<int_least16_t, long long>);

        // int_fast16_t with Unsigned Integers
        REQUIRE(cortex::MultiplicableWith<int_least16_t, unsigned>);
        REQUIRE(cortex::MultiplicableWith<int_least16_t, unsigned short>);
        REQUIRE(cortex::MultiplicableWith<int_least16_t, u_short>);
        REQUIRE(cortex::MultiplicableWith<int_least16_t, unsigned long>);
        REQUIRE(cortex::MultiplicableWith<int_least16_t, unsigned long long>);
        
        // int_fast16_t with Floating Point and Doubles
        REQUIRE(cortex::MultiplicableWith<int_least16_t, float>);
        REQUIRE(cortex::MultiplicableWith<int_least16_t, double>);
        REQUIRE(cortex::MultiplicableWith<int_least16_t, long double>);

        // int_fast16_t with std::strings and std::string_view
        REQUIRE(!cortex::MultiplicableWith<int_least16_t, std::string>);
        REQUIRE(!cortex::MultiplicableWith<int_least16_t, std::string_view>);
        REQUIRE(!cortex::MultiplicableWith<int_least16_t, std::u8string>);
        REQUIRE(!cortex::MultiplicableWith<int_least16_t, std::u16string>);
        REQUIRE(!cortex::MultiplicableWith<int_least16_t, std::u32string>);

        // int_fast16_t with std::wstrings and std::wstring_view
        REQUIRE(!cortex::MultiplicableWith<int_least16_t, std::wstring>);
        REQUIRE(!cortex::MultiplicableWith<int_least16_t, std::wstring_view>);

        // int_fast16_t with Charaters
        REQUIRE(cortex::MultiplicableWith<int_least16_t, char>);
        REQUIRE(cortex::MultiplicableWith<int_least16_t, u_char>);
        REQUIRE(cortex::MultiplicableWith<int_least16_t, wchar_t>);

        // int_fast16_t with Bit Specific Characters
        REQUIRE(cortex::MultiplicableWith<int_least16_t, char8_t>);
        REQUIRE(cortex::MultiplicableWith<int_least16_t, char16_t>);
        REQUIRE(cortex::MultiplicableWith<int_least16_t, char32_t>);

        // int_fast16_t with Bit Specific Integers
        REQUIRE(cortex::MultiplicableWith<int_least16_t, int8_t>);
        REQUIRE(cortex::MultiplicableWith<int_least16_t, int16_t>);
        REQUIRE(cortex::MultiplicableWith<int_least16_t, int32_t>);
        REQUIRE(cortex::MultiplicableWith<int_least16_t, int64_t>);

        // int_fast16_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::MultiplicableWith<int_least16_t, uint8_t>);
        REQUIRE(cortex::MultiplicableWith<int_least16_t, uint16_t>);
        REQUIRE(cortex::MultiplicableWith<int_least16_t, uint32_t>);
        REQUIRE(cortex::MultiplicableWith<int_least16_t, uint64_t>);

        // int_fast16_t with Bit Specific Least Integers
        REQUIRE(cortex::MultiplicableWith<int_least16_t, int_least8_t>);
        REQUIRE(cortex::MultiplicableWith<int_least16_t, int_least16_t>);
        REQUIRE(cortex::MultiplicableWith<int_least16_t, int_least32_t>);
        REQUIRE(cortex::MultiplicableWith<int_least16_t, int_least64_t>);
    }

    SECTION("int_least32_t with _")
    {
        // int32 with Signed Integers
        REQUIRE(cortex::MultiplicableWith<int_least32_t, int>);
        REQUIRE(cortex::MultiplicableWith<int_least32_t, short>);
        REQUIRE(cortex::MultiplicableWith<int_least32_t, long>);
        REQUIRE(cortex::MultiplicableWith<int_least32_t, long long>);

        // int32 with Unsigned Integers
        REQUIRE(cortex::MultiplicableWith<int_least32_t, unsigned>);
        REQUIRE(cortex::MultiplicableWith<int_least32_t, unsigned short>);
        REQUIRE(cortex::MultiplicableWith<int_least32_t, u_short>);
        REQUIRE(cortex::MultiplicableWith<int_least32_t, unsigned long>);
        REQUIRE(cortex::MultiplicableWith<int_least32_t, unsigned long long>);
        
        // int32 with Floating Point and Doubles
        REQUIRE(cortex::MultiplicableWith<int_least32_t, float>);
        REQUIRE(cortex::MultiplicableWith<int_least32_t, double>);
        REQUIRE(cortex::MultiplicableWith<int_least32_t, long double>);

        // int32 with std::strings and std::string_view
        REQUIRE(!cortex::MultiplicableWith<int_least32_t, std::string>);
        REQUIRE(!cortex::MultiplicableWith<int_least32_t, std::string_view>);
        REQUIRE(!cortex::MultiplicableWith<int_least32_t, std::u8string>);
        REQUIRE(!cortex::MultiplicableWith<int_least32_t, std::u16string>);
        REQUIRE(!cortex::MultiplicableWith<int_least32_t, std::u32string>);

        // int32 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::MultiplicableWith<int_least32_t, std::wstring>);
        REQUIRE(!cortex::MultiplicableWith<int_least32_t, std::wstring_view>);

        // int_fast32_t with Charaters
        REQUIRE(cortex::MultiplicableWith<int_least32_t, char>);
        REQUIRE(cortex::MultiplicableWith<int_least32_t, u_char>);
        REQUIRE(cortex::MultiplicableWith<int_least32_t, wchar_t>);

        // int_fast32_t with Bit Specific Characters
        REQUIRE(cortex::MultiplicableWith<int_least32_t, char8_t>);
        REQUIRE(cortex::MultiplicableWith<int_least32_t, char16_t>);
        REQUIRE(cortex::MultiplicableWith<int_least32_t, char32_t>);

        // int_fast32_t with Bit Specific Integers
        REQUIRE(cortex::MultiplicableWith<int_least32_t, int8_t>);
        REQUIRE(cortex::MultiplicableWith<int_least32_t, int16_t>);
        REQUIRE(cortex::MultiplicableWith<int_least32_t, int32_t>);
        REQUIRE(cortex::MultiplicableWith<int_least32_t, int64_t>);

        // int_fast32_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::MultiplicableWith<int_least32_t, uint8_t>);
        REQUIRE(cortex::MultiplicableWith<int_least32_t, uint16_t>);
        REQUIRE(cortex::MultiplicableWith<int_least32_t, uint32_t>);
        REQUIRE(cortex::MultiplicableWith<int_least32_t, uint64_t>);

        // int_fast32_t with Bit Specific Least Integers
        REQUIRE(cortex::MultiplicableWith<int_least32_t, int_least8_t>);
        REQUIRE(cortex::MultiplicableWith<int_least32_t, int_least16_t>);
        REQUIRE(cortex::MultiplicableWith<int_least32_t, int_least32_t>);
        REQUIRE(cortex::MultiplicableWith<int_least32_t, int_least64_t>);
    }

    SECTION("int_least64_t with _")
    {
        // int64 with Signed Integers
        REQUIRE(cortex::MultiplicableWith<int_least64_t, int>);
        REQUIRE(cortex::MultiplicableWith<int_least64_t, short>);
        REQUIRE(cortex::MultiplicableWith<int_least64_t, long>);
        REQUIRE(cortex::MultiplicableWith<int_least64_t, long long>);

        // int64 with Unsigned Integers
        REQUIRE(cortex::MultiplicableWith<int_least64_t, unsigned>);
        REQUIRE(cortex::MultiplicableWith<int_least64_t, unsigned short>);
        REQUIRE(cortex::MultiplicableWith<int_least64_t, u_short>);
        REQUIRE(cortex::MultiplicableWith<int_least64_t, unsigned long>);
        REQUIRE(cortex::MultiplicableWith<int_least64_t, unsigned long long>);
        
        // int64 with Floating Point and Doubles
        REQUIRE(cortex::MultiplicableWith<int_least64_t, float>);
        REQUIRE(cortex::MultiplicableWith<int_least64_t, double>);
        REQUIRE(cortex::MultiplicableWith<int_least64_t, long double>);

        // int64 with std::strings and std::string_view
        REQUIRE(!cortex::MultiplicableWith<int_least64_t, std::string>);
        REQUIRE(!cortex::MultiplicableWith<int_least64_t, std::string_view>);
        REQUIRE(!cortex::MultiplicableWith<int_least64_t, std::u8string>);
        REQUIRE(!cortex::MultiplicableWith<int_least64_t, std::u16string>);
        REQUIRE(!cortex::MultiplicableWith<int_least64_t, std::u32string>);

        // int64 with std::wstrings and std::wstring_view
        REQUIRE(!cortex::MultiplicableWith<int_least64_t, std::wstring>);
        REQUIRE(!cortex::MultiplicableWith<int_least64_t, std::wstring_view>);

        // int_fast64_t with Charaters
        REQUIRE(cortex::MultiplicableWith<int_least64_t, char>);
        REQUIRE(cortex::MultiplicableWith<int_least64_t, u_char>);
        REQUIRE(cortex::MultiplicableWith<int_least64_t, wchar_t>);

        // int_fast64_t with Bit Specific Characters
        REQUIRE(cortex::MultiplicableWith<int_least64_t, char8_t>);
        REQUIRE(cortex::MultiplicableWith<int_least64_t, char16_t>);
        REQUIRE(cortex::MultiplicableWith<int_least64_t, char32_t>);

        // int_fast64_t with Bit Specific Integers
        REQUIRE(cortex::MultiplicableWith<int_least64_t, int8_t>);
        REQUIRE(cortex::MultiplicableWith<int_least64_t, int16_t>);
        REQUIRE(cortex::MultiplicableWith<int_least64_t, int32_t>);
        REQUIRE(cortex::MultiplicableWith<int_least64_t, int64_t>);

        // int_fast64_t with Bit Specific Unsigned Integers
        REQUIRE(cortex::MultiplicableWith<int_least64_t, uint8_t>);
        REQUIRE(cortex::MultiplicableWith<int_least64_t, uint16_t>);
        REQUIRE(cortex::MultiplicableWith<int_least64_t, uint32_t>);
        REQUIRE(cortex::MultiplicableWith<int_least64_t, uint64_t>);

        // int_fast64_t with Bit Specific Least Integers
        REQUIRE(cortex::MultiplicableWith<int_least64_t, int_least8_t>);
        REQUIRE(cortex::MultiplicableWith<int_least64_t, int_least16_t>);
        REQUIRE(cortex::MultiplicableWith<int_least64_t, int_least32_t>);
        REQUIRE(cortex::MultiplicableWith<int_least64_t, int_least64_t>);
    }
}