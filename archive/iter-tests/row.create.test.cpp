#include <catch2/catch.hpp>
#include <iterators/row.hpp>
#include <vector>

TEST_CASE("Creating row_iterators") 
{
    SECTION("Default Constructor")
    {
        cxl::row_iterator<typename std::vector<int>::iterator> it;
        REQUIRE(it.base() == std::vector<int>::iterator());
        REQUIRE(it.rows() == 0uL);
        REQUIRE(it.columns() == 0uL);
        REQUIRE(it.row_index() == 0uL);
        REQUIRE(it.column_index() == 0uL);
    }

    SECTION("Value Constructor")
    {
        std::vector<int> v = { 0, 1
                             , 2, 3
                             , 4, 5
                             , 6, 7
                             , 8, 9 };

        auto it { cxl::row_iterator<typename std::vector<int>::iterator>(v.begin(), 0ul, 0ul, 5ul, 2ul) };
        
        REQUIRE(it.base() == v.begin());
        REQUIRE(it.rows() == 5ul);
        REQUIRE(it.columns() == 2ul);
        REQUIRE(it.row_index() == 0ul);
        REQUIRE(it.column_index() == 0ul);

        /// First Row --------------------------------

        REQUIRE(*it == 0);
        REQUIRE(it.base() == v.begin());

        REQUIRE(it.rows() == 5ul);
        REQUIRE(it.columns() == 2ul);
        
        REQUIRE(it.row_index() == 0ul);
        REQUIRE(it.column_index() == 0ul);

        ++it;
        REQUIRE(*it == 1);
        REQUIRE(it.base() == v.begin() + 1);

        REQUIRE(it.rows() == 5ul);
        REQUIRE(it.columns() == 2ul);

        REQUIRE(it.row_index() == 0ul);
        REQUIRE(it.column_index() == 1ul);

        /// Second Row --------------------------------

        ++it;
        REQUIRE(*it == 2);
        REQUIRE(it.base() == v.begin() + 2);

        REQUIRE(it.rows() == 5ul);
        REQUIRE(it.columns() == 2ul);

        REQUIRE(it.row_index() == 1ul);
        REQUIRE(it.column_index() == 0ul);
        
        ++it;
        REQUIRE(*it == 3);
        REQUIRE(it.base() == v.begin() + 3);

        REQUIRE(it.rows() == 5ul);
        REQUIRE(it.columns() == 2ul);

        REQUIRE(it.row_index() == 1ul);
        REQUIRE(it.column_index() == 1ul);

        /// Third Row --------------------------------

        ++it;
        REQUIRE(*it == 4);
        REQUIRE(it.base() == v.begin() + 4);

        REQUIRE(it.rows() == 5ul);
        REQUIRE(it.columns() == 2ul);

        REQUIRE(it.row_index() == 2ul);
        REQUIRE(it.column_index() == 0ul);

        ++it;
        REQUIRE(*it == 5);
        REQUIRE(it.base() == v.begin() + 5);

        REQUIRE(it.rows() == 5ul);
        REQUIRE(it.columns() == 2ul);

        REQUIRE(it.row_index() == 2ul);
        REQUIRE(it.column_index() == 1ul);

        /// Fourth Row --------------------------------

        ++it;
        REQUIRE(*it == 6);
        REQUIRE(it.base() == v.begin() + 6);

        REQUIRE(it.rows() == 5ul);
        REQUIRE(it.columns() == 2ul);

        REQUIRE(it.row_index() == 3ul);
        REQUIRE(it.column_index() == 0ul);

        ++it;
        REQUIRE(*it == 7);
        REQUIRE(it.base() == v.begin() + 7);

        REQUIRE(it.rows() == 5ul);
        REQUIRE(it.columns() == 2ul);

        REQUIRE(it.row_index() == 3ul);
        REQUIRE(it.column_index() == 1ul);

        /// Fifth Row --------------------------------

        ++it;
        REQUIRE(*it == 8);
        REQUIRE(it.base() == v.begin() + 8);

        REQUIRE(it.rows() == 5ul);
        REQUIRE(it.columns() == 2ul);

        REQUIRE(it.row_index() == 4ul);
        REQUIRE(it.column_index() == 0ul);

        ++it;
        REQUIRE(*it == 9);
        REQUIRE(it.base() == v.begin() + 9);

        REQUIRE(it.rows() == 5ul);
        REQUIRE(it.columns() == 2ul);

        REQUIRE(it.row_index() == 4ul);
        REQUIRE(it.column_index() == 1ul);
    }
}