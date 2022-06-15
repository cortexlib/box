#include <catch2/catch.hpp>
#include <iterators/normal.hpp>
#include <vector>

TEST_CASE("Creating normal_iterators") 
{
    SECTION("Test 1 : std::vector::iterator -> normal_iterator")
    {
        std::vector<int> v = {1, 2, 3, 4, 5};
        auto it = cortex::normal_iterator<typename std::vector<int>::iterator, std::vector<int>>(v.begin());
        REQUIRE(*it == 1);
        ++it;
        REQUIRE(*it == 2);
        ++it;
        REQUIRE(*it == 3);
        ++it;
        REQUIRE(*it == 4);
        ++it;
        REQUIRE(*it == 5);
    }
    
    SECTION("Test 2 : make_normal : std::vector::begin() -> normal_iterator")
    {
        std::vector<int> v = {1, 2, 3, 4, 5};
        auto it = cortex::make_normal<std::vector<int>>(v.begin());
        REQUIRE(*it == 1);
        ++it;
        REQUIRE(*it == 2);
        ++it;
        REQUIRE(*it == 3);
        ++it;
        REQUIRE(*it == 4);
        ++it;
        REQUIRE(*it == 5);
    }

    SECTION("Test 3 : make_normal w/ decltype : std::vector::begin() -> normal_iterator")
    {
        std::vector<int> v = {1, 2, 3, 4, 5};
        auto it = cortex::make_normal<decltype(v)>(v.begin());
        REQUIRE(*it == 1);
        ++it;
        REQUIRE(*it == 2);
        ++it;
        REQUIRE(*it == 3);
        ++it;
        REQUIRE(*it == 4);
        ++it;
        REQUIRE(*it == 5);
    }

    SECTION("Test 4 : make_normal C-style array : int[] -> normal_iterator")
    {
        int arr[] = {1, 2, 3, 4, 5};
        auto it = cortex::make_normal<int*, int[]>(arr);
        REQUIRE(*it == 1);
        ++it;
        REQUIRE(*it == 2);
        ++it;
        REQUIRE(*it == 3);
        ++it;
        REQUIRE(*it == 4);
        ++it;
        REQUIRE(*it == 5);
    }

    SECTION("Test 5 : make_normal w/ template type deduction : std::vector::begin() -> normal_iterator")
    {
        std::vector<int> v = {1, 2, 3, 4, 5};
        auto it = cortex::make_normal(v, v.begin());
        REQUIRE(*it == 1);
        ++it;
        REQUIRE(*it == 2);
        ++it;
        REQUIRE(*it == 3);
        ++it;
        REQUIRE(*it == 4);
        ++it;
        REQUIRE(*it == 5);
    }
}