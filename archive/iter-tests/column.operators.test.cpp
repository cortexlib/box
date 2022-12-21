#include <catch2/catch.hpp>
#include <iterators/column.hpp>
#include <vector>
#include <iostream>

struct Point
{
    int x;
    int y;
};

TEST_CASE("column_iterator operators")
{
    std::vector<int> v { 0, 1, 2
                       , 3, 4, 5
                       , 6, 7, 8 };
    
    auto it { cxl::column_iterator<typename std::vector<int>::iterator>(v.begin(), 0ul, 0ul, 3ul, 3ul) };

    SECTION("operator* [dereference]")
    { REQUIRE(*it == 0); }

    std::vector<Point> points { { 1, 5 } };

    auto indirect_it { cxl::column_iterator<typename std::vector<Point>::iterator>(points.begin(), 0ul, 0ul, 1ul, 1ul) };

    SECTION("operator-> [indirection]")
    { REQUIRE(indirect_it->x == 1); }

    SECTION("operator-> [indirection]")
    { REQUIRE(indirect_it->y == 5); }

    SECTION("operator++")
    { REQUIRE(*++it == 3);}

    SECTION("operator++(int)")
    { 
        REQUIRE(*it++ == 0); 
        REQUIRE(*it == 3);
    }

    SECTION("operator--")
    { 
        it = cxl::column_iterator<typename std::vector<int>::iterator>(v.begin() + 8, 2ul, 2ul, 3ul, 3ul);
        REQUIRE(*it == 8);
        REQUIRE(*--it == 5); 
    }

    SECTION("operator--(int)")
    { 
        it = cxl::column_iterator<typename std::vector<int>::iterator>(v.begin() + 5, 1ul, 2ul, 3ul, 3ul);
        REQUIRE(*it-- == 5);
        REQUIRE(*it == 2);
    }

    // SECTION("operator[]")
    // {   
    //     REQUIRE(it[0] == 0);
    //     REQUIRE(it[1] == 3);
    //     REQUIRE(it[2] == 1);
    //     REQUIRE(it[3] == 4);
    //     REQUIRE(it[4] == 2);
    //     REQUIRE(it[5] == 5);
    // }

    // SECTION("operator+")
    // { REQUIRE(*(it + 2) == 1); }

    // SECTION("operator+=")
    // { 
    //     it += 5;
    //     REQUIRE(*it == 5); 
    // }

    // SECTION("operator-")
    // { 
    //     it += 4;
    //     REQUIRE(*(it - 3) == 3); 
    // }

    // SECTION("operator-=")
    // { 
    //     it += 4;
    //     it -= 2;
    //     REQUIRE(*it == 1);
    // }
}

TEST_CASE("Comparison")
{
    std::vector<int> v { 0, 1, 2
                       , 3, 4, 5
                       , 6, 7, 8 };
    
    auto it { cxl::column_iterator<typename std::vector<int>::iterator>(v.begin(), 0ul, 0ul, 3ul, 3ul) };
    auto it2 { cxl::column_iterator<typename std::vector<int>::iterator>(it) };
    auto it3 { cxl::column_iterator<typename std::vector<int>::iterator>(v.begin() + 7, 2ul, 1ul, 3ul, 3ul) };
    auto it4 { cxl::column_iterator<typename std::vector<int>::iterator>(v.begin() + 2, 0ul, 2ul, 3ul, 3ul) };

    SECTION("operator ==")
    { REQUIRE(it == it2); }

    SECTION("operator !=")
    { REQUIRE(it != it3); }

    SECTION("operator <")
    { REQUIRE(it < it4); }

    SECTION("operator <=")
    { 
        REQUIRE(it <= it2); 
        REQUIRE(it <= it4); 
    }

    SECTION("operator >")
    { REQUIRE(it4 > it3); }

    SECTION("operator >=")
    { 
        REQUIRE(it4 >= it3);
        REQUIRE(it4 >= ++it3);
    }
}