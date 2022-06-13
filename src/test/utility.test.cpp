#include <catch2/catch.hpp>
#include <box.hpp>

TEST_CASE("Utility Functions")
{
    SECTION("Swap")
    {
        SECTION("box::swap")
        {
            cortex::box<int> bx(2, 3, 1);
            cortex::box<int> nbx(7, 4, 2);

            for (auto& v : bx)
                REQUIRE(v == 1);
            
            for (auto& v : nbx)
                REQUIRE(v == 2);

            bx.swap(nbx);

            for (auto& v : bx)
                REQUIRE(v == 2);
            
            for (auto& v : nbx)
                REQUIRE(v == 1);
        }

        SECTION("box - std::swap")
        {
            cortex::box<int> bx(2, 3, 1);
            cortex::box<int> nbx(7, 4, 2);

            for (auto& v : bx)
                REQUIRE(v == 1);
            
            for (auto& v : nbx)
                REQUIRE(v == 2);

            std::swap(bx, nbx);

            for (auto& v : bx)
                REQUIRE(v == 2);
            
            for (auto& v : nbx)
                REQUIRE(v == 1);
        }
    }

    SECTION("Flatten")
    {
        SECTION("box::flatten")
        {
            cortex::box<int> bx(2, 3, 1);
            std::vector<int> v = bx.flatten();

            for (auto& elem : v)
                REQUIRE(elem == 1);

            v.assign({ 0, 1, 2, 3, 4, 5 });

            for (auto i { 0 }; auto& elem : v)
                REQUIRE(elem == i++);
        }
    }

    SECTION("Removal")
    {
        SECTION("box::clear")
        {
            cortex::box<int> bx(4, 5, 1);

            auto ptr { bx.begin().base() };
            REQUIRE(bx.data() == std::to_address(ptr));

            bx.clear();

            for (auto& elem : bx)
                REQUIRE(elem == 0);

            REQUIRE(bx.empty());
            REQUIRE(bx.size() == 0);

            REQUIRE_THROWS_AS(bx.at(0, 0) = 1, std::out_of_range);

            REQUIRE(bx.empty());
            REQUIRE(bx.size() == 0);
            REQUIRE(bx.data() == nullptr);
            REQUIRE(bx.data() == decltype(bx)::pointer());
        }

        SECTION("box::clear - No allocated recources")
        {
            cortex::box<int> bx;

            REQUIRE(bx.empty());
            REQUIRE(bx.size() == 0);
            REQUIRE(bx.data() == nullptr);
            REQUIRE(bx.data() == decltype(bx)::pointer());

            bx.clear();

            REQUIRE(bx.empty());
            REQUIRE(bx.size() == 0);
            REQUIRE(bx.data() == nullptr);
            REQUIRE(bx.data() == decltype(bx)::pointer());
        }

        SECTION("box::clear - Uninitialized Resources")
        {
            cortex::box<int> bx(4, 5);

            REQUIRE(!bx.empty());
            REQUIRE(bx.size() == 20);
            REQUIRE(bx.rows() == 4);
            REQUIRE(bx.columns() == 5);
            REQUIRE(bx.data() != nullptr);

            bx.clear();

            REQUIRE(bx.empty());
            REQUIRE(bx.size() == 0);
            REQUIRE(bx.columns() == 0);
            REQUIRE(bx.rows() == 0);
            REQUIRE(bx.data() == nullptr);
        }
    }

    SECTION("Restructuring")
    {
        SECTION("Resize")
        {
            SECTION("box::resize - After clear")
            {
                using namespace std::literals;

                /// std::string was used as it is not trivially constructuble 
                /// and thus box<std::string>::resize will actually initialise 
                /// the variable to an empty string (unlike ints)
                cortex::box<std::string> bx(2, 5, "h");

                REQUIRE(!bx.empty());
                REQUIRE(bx.size() == 10);
                REQUIRE(bx.rows() == 2);
                REQUIRE(bx.columns() == 5);
                REQUIRE(bx.data() != nullptr);

                for (auto& elem : bx)
                    REQUIRE(elem == "h"s);

                bx.clear();

                REQUIRE(bx.empty());
                REQUIRE(bx.size() == 0);
                REQUIRE(bx.rows() == 0);
                REQUIRE(bx.columns() == 0);
                REQUIRE(bx.data() == nullptr);

                bx.resize(6, 4);

                REQUIRE(!bx.empty());
                REQUIRE(bx.size() == 24);
                REQUIRE(bx.rows() == 6);
                REQUIRE(bx.columns() == 4);
                REQUIRE(bx.data() != nullptr);

                for (auto& elem : bx)
                    REQUIRE(elem == ""s);
            }
        }

        SECTION("Reshape")
        {
            SECTION("box::reshape - correct reshape")
            {
                cortex::box<int> bx(4, 6, 1);

                REQUIRE(bx.size() == 24);
                REQUIRE(bx.rows() == 4);
                REQUIRE(bx.columns() == 6);

                bx.reshape(3, 8);

                REQUIRE(bx.size() == 24);
                REQUIRE(bx.rows() == 3);
                REQUIRE(bx.columns() == 8);
            }

            SECTION("box::reshape - larger reshape")
            {
                cortex::box<int> bx(4, 6, 1);

                REQUIRE(bx.size() == 24);
                REQUIRE(bx.rows() == 4);
                REQUIRE(bx.columns() == 6);

                REQUIRE_THROWS_AS(bx.reshape(4, 8), std::length_error);

                REQUIRE(bx.size() == 24);
                REQUIRE(bx.rows() == 4);
                REQUIRE(bx.columns() == 6);
            }

            SECTION("box::reshape - smaller reshape")
            {
                cortex::box<int> bx(4, 6, 1);

                REQUIRE(bx.size() == 24);
                REQUIRE(bx.rows() == 4);
                REQUIRE(bx.columns() == 6);

                REQUIRE_THROWS_AS(bx.reshape(3, 5), std::length_error);

                REQUIRE(bx.size() == 24);
                REQUIRE(bx.rows() == 4);
                REQUIRE(bx.columns() == 6);
            }

            SECTION("box::reshape - reshape column vector")
            {
                cortex::box<int> bx(4, 6, 1);

                REQUIRE(bx.size() == 24);
                REQUIRE(bx.rows() == 4);
                REQUIRE(bx.columns() == 6);

                bx.reshape(24, 0);

                REQUIRE(bx.size() == 24);
                REQUIRE(bx.rows() == 24);
                REQUIRE(bx.columns() == 0);
            }

            SECTION("box::reshape - reshape column vector")
            {
                cortex::box<int> bx(4, 6, 1);

                REQUIRE(bx.size() == 24);
                REQUIRE(bx.rows() == 4);
                REQUIRE(bx.columns() == 6);

                bx.reshape(0, 24);

                REQUIRE(bx.size() == 24);
                REQUIRE(bx.rows() == 0);
                REQUIRE(bx.columns() == 24);
            }
        }
    }
}