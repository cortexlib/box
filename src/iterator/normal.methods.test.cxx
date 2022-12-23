#include <catch2/catch.hpp>
#include <fmt/core.h>
#include <fmt/ranges.h>
#include <fmt/std.h>

#include <iterator/normal.hxx>

#include <string>
#include <vector>

TEST_CASE("normal_iterator functions")
{
    SECTION("normal_iterator::base()")
    {
        std::vector<int> v{1, 2, 3, 4, 5};
        auto it { cxl::make_normal_iterator<std::vector<int>>(v.begin()) };
    
    
        REQUIRE(it.base() == v.begin());
    }

    SECTION("std::iter_move()")
    {
        std::vector<std::string> v { "Alpha", "Bravo", "Charlie" };
        std::vector<std::string> u {};
        
        fmt::print("v: {}\n", v);
        fmt::print("u: {}\n", u);

        REQUIRE(v == std::vector<std::string>{ "Alpha", "Bravo", "Charlie" });
        REQUIRE(u == std::vector<std::string>{});

        auto it = cxl::make_normal_iterator<std::vector<std::string>>(v.begin());
        auto eit = cxl::make_normal_iterator<std::vector<std::string>>(v.end());

        for (;it != eit; ++it)
            u.emplace_back(std::iter_move(it));

        fmt::print("v: {}\n", v);
        fmt::print("u: {}\n", u);

        REQUIRE(v == std::vector<std::string>{ "", "", "" });
        REQUIRE(u == std::vector<std::string>{ "Alpha", "Bravo", "Charlie" });
    }

    SECTION("std::iter_swap()")
    {
        std::vector<std::string> v { "Alpha", "Bravo", "Charlie" };
        std::vector<std::string> u { "Delta", "Omega", "Sigma" };
        
        fmt::print("v: {}\n", v);
        fmt::print("u: {}\n", u);

        REQUIRE(v == std::vector<std::string>{ "Alpha", "Bravo", "Charlie" });
        REQUIRE(u == std::vector<std::string>{ "Delta", "Omega", "Sigma" });

        auto vit = cxl::make_normal_iterator<std::vector<std::string>>(v.begin());
        auto eit = cxl::make_normal_iterator<std::vector<std::string>>(v.end());
        auto uit = cxl::make_normal_iterator<std::vector<std::string>>(u.begin());

        for (;vit != eit; ++vit, ++uit)
            std::iter_swap(vit, uit);

        fmt::print("v: {}\n", v);
        fmt::print("u: {}\n", u);

        REQUIRE(v == std::vector<std::string>{ "Delta", "Omega", "Sigma" });
        REQUIRE(u == std::vector<std::string>{ "Alpha", "Bravo", "Charlie" });
    }
}