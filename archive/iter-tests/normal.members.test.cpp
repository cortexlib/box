#include <catch2/catch.hpp>
#include <iterators/normal.hpp>
#include <vector>

TEST_CASE("normal_iterator member functions")
{
    std::vector<int> v{1, 2, 3, 4, 5};
    auto it { cxl::make_normal<std::vector<int>>(v.begin()) };
    
    SECTION("base")
    { REQUIRE(it.base() == v.begin()); }
}