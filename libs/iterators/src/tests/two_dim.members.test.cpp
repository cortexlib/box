#include <catch2/catch.hpp>
#include <iterators/two_dim.hpp>
#include <vector>

TEST_CASE("column_iterator member functions")
{
    std::vector<int> v { 0, 1, 2
                       , 3, 4, 5 };
    auto it { cortex::two_dim_iterator<typename std::vector<int>::iterator>(v.begin(), 0ul, 0ul, 2ul, 3ul) };

    SECTION("two_dim_iterator::base")
    { REQUIRE(it.base() == v.begin()); }

    SECTION("two_dim_iterator::rows")
    { REQUIRE(it.rows() == 2ul); }

    SECTION("two_dim_iterator::columns")
    { REQUIRE(it.columns() == 3ul); }

    SECTION("two_dim_iterator::row_index")
    { REQUIRE(it.row_index() == 0ul); }

    SECTION("two_dim_iterator::column_index")
    { REQUIRE(it.column_index() == 0ul); }
}