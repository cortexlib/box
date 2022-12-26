#include <catch2/catch.hpp>
#include <fmt/core.h>
#include <fmt/ranges.h>
#include <fmt/std.h>

#include <iterator/normal.hxx>

#include <string>
#include <vector>

TEST_CASE("normal_iterators test") 
{
    SECTION("Creation")
    {
        SECTION("Test 1 : std::vector::iterator -> normal_iterator")
        {
            std::vector<int> v = {1, 2, 3, 4, 5};
            auto it = cxl::normal_iterator<typename std::vector<int>::iterator, std::vector<int>>(v.begin());
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
            auto it = cxl::make_normal_iterator<std::vector<int>>(v.begin());
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
            auto it = cxl::make_normal_iterator<decltype(v)>(v.begin());
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
            auto it = cxl::make_normal_iterator<int*, int[]>(arr);
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

    SECTION("Methods")
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

    SECTION("Operators")
    {
        struct Point
        {
            int x;
            int y;
        };

        std::vector<int> v{1, 2, 3, 4, 5};
        auto it { cxl::make_normal_iterator<std::vector<int>>(v.begin()) };

        SECTION("operator*(dereference)")
        { REQUIRE(*it == 1); }

        std::vector<Point> points { { 1, 5 } };

        auto indirect_it { cxl::make_normal_iterator<std::vector<Point>>(points.begin()) };

        SECTION("operator-> [indirection]")
        { REQUIRE(indirect_it->x == 1); }

        SECTION("operator-> [indirection]")
        { REQUIRE(indirect_it->y == 5); }

        SECTION("operator[]")
        { REQUIRE(it[2] == 3); }

        SECTION("operator++")
        { REQUIRE(*++it == 2);}

        SECTION("operator++(int)")
        { 
            REQUIRE(*it++ == 1); 
            REQUIRE(*it == 2);
        }

        SECTION("operator--")
        { 
            it += 4;
            REQUIRE(*--it == 4); 
        }

        SECTION("operator--(int)")
        { 
            it += 4;
            REQUIRE(*it-- == 5);
            REQUIRE(*it == 4);
        }

        SECTION("operator+")
        { REQUIRE(*(it + 2) == 3); }

        SECTION("operator+=")
        { 
            it += 4;
            REQUIRE(*it == 5); 
        }

        SECTION("operator-")
        { 
            it += 4;
            REQUIRE(*(it - 1) == 4); 
        }

        SECTION("operator-=")
        { 
            it += 4;
            it -= 3;
            REQUIRE(*it == 2);
        }


        it = cxl::make_normal_iterator<std::vector<int>>(v.begin());
        SECTION("operator==")
        { REQUIRE(it == cxl::make_normal_iterator<std::vector<int>>(v.begin())); }

        SECTION("operator<=>")
        { 
            REQUIRE((it <=> cxl::make_normal_iterator<std::vector<int>>(v.begin())) == std::strong_ordering::equal); 
            REQUIRE(((it + 1) <=> cxl::make_normal_iterator<std::vector<int>>(v.begin())) == std::strong_ordering::greater); 
            REQUIRE((it <=> cxl::make_normal_iterator<std::vector<int>>(v.begin()) + 1) == std::strong_ordering::less); 
        }

        SECTION("operator!=")
        { REQUIRE(it != cxl::make_normal_iterator<std::vector<int>>(v.begin()) + 1); }

        SECTION("operator<")
        { REQUIRE(it < cxl::make_normal_iterator<std::vector<int>>(v.begin()) + 3); }

        SECTION("operator<=")
        { REQUIRE(it <= cxl::make_normal_iterator<std::vector<int>>(v.begin())); }

        SECTION("operator>")
        { REQUIRE(it + 4 > cxl::make_normal_iterator<std::vector<int>>(v.begin())); }

        SECTION("operator>=")
        { REQUIRE(it + 4 >= cxl::make_normal_iterator<std::vector<int>>(v.begin())); }
    }
}