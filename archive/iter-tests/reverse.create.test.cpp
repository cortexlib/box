#include <catch2/catch.hpp>
#include <iterators/reverse.hpp>
#include <vector>

TEST_CASE("Creating reverse_iterators") 
{
    SECTION("Test 1 : std::vector::iterator -> reverse_iterator")
    {
        std::vector<int> v = {1, 2, 3, 4, 5};
        auto it = cxl::reverse_iterator<std::vector<int>::iterator>(v.end());
        REQUIRE(*it == 5);
        ++it;
        REQUIRE(*it == 4);
        ++it;
        REQUIRE(*it == 3);
        ++it;
        REQUIRE(*it == 2);
        ++it;
        REQUIRE(*it == 1);
    }
    
    SECTION("Test 2 : make_reverse : std::vector::begin() -> reverse_iterator")
    {
        std::vector<int> v = {1, 2, 3, 4, 5};
        auto it = cxl::make_reverse<std::vector<int>>(v.end());
        REQUIRE(*it == 5);
        ++it;
        REQUIRE(*it == 4);
        ++it;
        REQUIRE(*it == 3);
        ++it;
        REQUIRE(*it == 2);
        ++it;
        REQUIRE(*it == 1);
    }

    SECTION("Test 3 : make_reverse w/ decltype : std::vector::begin() -> reverse_iterator")
    {
        std::vector<int> v = {1, 2, 3, 4, 5};
        auto it = cxl::make_reverse<decltype(v)>(v.end());
        REQUIRE(*it == 5);
        ++it;
        REQUIRE(*it == 4);
        ++it;
        REQUIRE(*it == 3);
        ++it;
        REQUIRE(*it == 2);
        ++it;
        REQUIRE(*it == 1);
    }

    SECTION("Test 4 : make_reverse C-style array : int* -> reverse_iterator")
    {
        int arr[] = {1, 2, 3, 4, 5};
        auto it = cxl::make_reverse<int*>(arr + 5);
        REQUIRE(*it == 5);
        ++it;
        REQUIRE(*it == 4);
        ++it;
        REQUIRE(*it == 3);
        ++it;
        REQUIRE(*it == 2);
        ++it;
        REQUIRE(*it == 1);
    }

    SECTION("Test 5 : make_reverse w/ template type deduction : std::vector::begin() -> reverse_iterator")
    {
        std::vector<int> v = {1, 2, 3, 4, 5};
        auto it = cxl::make_reverse(v, v.end());
        REQUIRE(*it == 5);
        ++it;
        REQUIRE(*it == 4);
        ++it;
        REQUIRE(*it == 3);
        ++it;
        REQUIRE(*it == 2);
        ++it;
        REQUIRE(*it == 1);
    }
}