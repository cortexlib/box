#include <catch2/catch.hpp>
#include <iterators/reverse.hpp>
#include <vector>

struct Point
{
    int x;
    int y;
};

TEST_CASE("reverse_iterator operators")
{
    std::vector<int> v{1, 2, 3, 4, 5};
    auto it { cxl::make_reverse(v, v.end()) };

    SECTION("operator*(dereference)")
    { REQUIRE(*it == 5); }

    std::vector<Point> points { { 1, 5 } };

    auto indirect_it { cxl::make_reverse(points, points.end()) };

    SECTION("operator-> [indirection]")
    { REQUIRE(indirect_it->x == 1); }

    SECTION("operator-> [indirection]")
    { REQUIRE(indirect_it->y == 5); }

    SECTION("operator[]")
    { REQUIRE(it[2] == 3); }

    SECTION("operator++")
    { REQUIRE(*++it == 4);}

    SECTION("operator++(int)")
    { 
        REQUIRE(*it++ == 5); 
        REQUIRE(*it == 4);
    }

    SECTION("operator--")
    { 
        it += 1;
        REQUIRE(*--it == 5); 
    }

    SECTION("operator--(int)")
    { 
        it += 4;
        REQUIRE(*it-- == 1);
        REQUIRE(*it == 2);
    }

    SECTION("operator+")
    { REQUIRE(*(it + 2) == 3); }

    SECTION("operator+=")
    { 
        it += 4;
        REQUIRE(*it == 1); 
    }

    SECTION("operator-")
    { 
        it += 4;
        REQUIRE(*(it - 1) == 2); 
    }

    SECTION("operator-=")
    { 
        it += 4;
        it -= 3;
        REQUIRE(*it == 4);
    }

    std::vector<std::vector<int>> vv{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    std::vector<std::vector<int>> vvcheck{
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9, 10}
    };

    auto itc = cxl::make_reverse(vv, vv.end());

    SECTION("operator->")
    {
        itc->push_back(10);
        REQUIRE(vv == vvcheck);
    }

    it = cxl::make_reverse(v, v.end());
    SECTION("operator==")
    { REQUIRE(it == cxl::make_reverse(v, v.end())); }

    SECTION("operator!=")
    { REQUIRE(it != cxl::make_reverse(v, v.end()) + 1); }

    SECTION("operator>")
    { REQUIRE(it > cxl::make_reverse(v, v.end()) + 3); }

    SECTION("operator>=")
    { REQUIRE(it >= cxl::make_reverse(v, v.end())); }

    SECTION("operator<")
    { REQUIRE(it + 4 < cxl::make_reverse(v, v.end())); }

    SECTION("operator<=")
    { REQUIRE(it + 4 <= cxl::make_reverse(v, v.end())); }
}