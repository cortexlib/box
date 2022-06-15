#include <catch2/catch.hpp>
#include <iterators/two_dim.hpp>
#include <vector>
#include <iostream>

TEST_CASE("Creating two_dim_iterators") 
{
    SECTION("Default Constructor")
    {
        cortex::two_dim_iterator<typename std::vector<int>::iterator> it;
        REQUIRE(it.base() == std::vector<int>::iterator());
        REQUIRE(it.rows() == 0uL);
        REQUIRE(it.columns() == 0uL);
        REQUIRE(it.row_index() == 0uL);
        REQUIRE(it.column_index() == 0uL);
    }

    std::vector<int> v = { 0, 1
                         , 2, 3
                         , 4, 5
                         , 6, 7
                         , 8, 9 };

    auto it { cortex::two_dim_iterator<typename std::vector<int>::iterator>(v.begin(), 0ul, 0ul, 5ul, 2ul) };


    SECTION("Value Constructor")
    {
        REQUIRE(it.base() == v.begin());
        REQUIRE(it.rows() == 5ul);
        REQUIRE(it.columns() == 2ul);
        REQUIRE(it.row_index() == 0ul);
        REQUIRE(it.column_index() == 0ul);
    }

    SECTION("Copy Constructor")
    {
        auto copy { it };

        REQUIRE(copy.base() == v.begin());
        REQUIRE(copy.rows() == 5ul);
        REQUIRE(copy.columns() == 2ul);
        REQUIRE(copy.row_index() == 0ul);
        REQUIRE(copy.column_index() == 0ul);
    }

    SECTION("Copy Assignment")
    {
        auto copy = it;

        REQUIRE(copy.base() == v.begin());
        REQUIRE(copy.rows() == 5ul);
        REQUIRE(copy.columns() == 2ul);
        REQUIRE(copy.row_index() == 0ul);
        REQUIRE(copy.column_index() == 0ul);
    }
}