#include <catch2/catch.hpp>
#include <iterators/reverse.hpp>
#include <vector>

TEST_CASE("reverse_iterator member functions")
{
    std::vector<int> v{1, 2, 3, 4, 5};
    auto it { cxl::make_reverse<std::vector<int>>(v.end()) };

    SECTION("as bool")
    { REQUIRE(it); }

    SECTION("if-clause")
    {
        if (it)
            REQUIRE(*it == 5);
        else
            REQUIRE(false);
    }

    SECTION("base")
    { REQUIRE(it.base() == v.end()); }
}