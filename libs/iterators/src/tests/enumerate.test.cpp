#include <catch2/catch.hpp>
#include <adaptors/enumerate.hpp>
#include <vector>

TEST_CASE("Basic Enumeration")
{
    std::vector<int> v = {1, 2, 3, 4, 5};
    
    for (auto [i, e] : v | cortex::adaptors::enumerate(0))
    {
        REQUIRE(e == v[std::size_t(i)]);
    }
}

TEST_CASE("Enumeration from negative index")
{
    std::vector<int> v = {1, 2, 3, 4, 5};
    
    auto check {-2};

    for (auto [i, e] : v | cortex::adaptors::enumerate(-1))
    {
        REQUIRE(i == ++check);
    }
}


TEST_CASE("Enumeration upwards with non-one step")
{
    std::vector<int> v = {1, 2, 3, 4, 5};
    
    auto check {0};

    for (auto [i, e] : v | cortex::adaptors::enumerate(0, 2))
    {
        REQUIRE(i == check);
        check += 2;
    }
}


TEST_CASE("Enumeration downwards with non-one step")
{
    std::vector<int> v = {1, 2, 3, 4, 5};
    
    auto check {static_cast<int>(v.size())};

    for (auto [i, e] : v | cortex::adaptors::enumerate(static_cast<int>(v.size() - 1), -1))
        REQUIRE(i == --check);
}

using namespace cortex::adaptors;

TEST_CASE("Eliding the Adaptor Namespace")
{
    std::vector<int> v = {1, 2, 3, 4, 5};
    
    for (auto [i, e] : v | enumerate(0))
    {
        REQUIRE(e == v[std::size_t(i)]);
    }
}