#include <catch2/catch.hpp>
#include <iterator/normal.hxx>
#include <vector>

struct Point
{
    int x;
    int y;
};

TEST_CASE("normal_iterator operators")
{
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