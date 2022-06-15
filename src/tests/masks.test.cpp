#include <catch2/catch.hpp>
#include <box.hpp>

TEST_CASE("Boolean Masks")
{
    SECTION("Equality")
    {
        SECTION("All Equal")
        {
            cortex::box<int> bx(4, 5, 5);
            cortex::box<bool> bxcheck(4, 5, true);

            auto rbx { bx == 5 };

            REQUIRE(rbx == bxcheck);

            for (auto& elem : bx)
                REQUIRE(elem == 5);

            for (auto& elem : rbx)
                REQUIRE(elem == true);
        }

        SECTION("All Not Equal")
        {
            cortex::box<int> bx(4, 5, 5);
            cortex::box<bool> bxcheck(4, 5, false);

            auto rbx { bx == 6 };

            REQUIRE(rbx == bxcheck);

            for (auto& elem : bx)
                REQUIRE(elem == 5);

            for (auto& elem : rbx)
                REQUIRE(elem == false);
        }

        SECTION("Mismatched")
        {
            std::vector<int> v { 1, 2, 1, 1, 1, 5, 2, 5, 2, 2 };
            cortex::box<int> bx(5, 2);
            cortex::box<bool> bxcheck(5, 2);

            for (auto i { 0ul }; i < v.size(); ++i)
            {
                bx[i] = v[i];
                bxcheck[i] = v[i] == 2;
            }

            auto rbx { bx == 2 };

            REQUIRE(rbx == bxcheck);
        }
    }

    SECTION("Inequality")
    {
        SECTION("All Not Equal")
        {
            cortex::box<int> bx(4, 5, 5);
            cortex::box<bool> bxcheck(4, 5, true);

            auto rbx { bx != 6 };

            REQUIRE(rbx == bxcheck);

            for (auto& elem : bx)
                REQUIRE(elem == 5);

            for (auto& elem : rbx)
                REQUIRE(elem == true);
        }

        SECTION("All Equal")
        {
            cortex::box<int> bx(4, 5, 5);
            cortex::box<bool> bxcheck(4, 5, false);

            auto rbx { bx != 5 };

            REQUIRE(rbx == bxcheck);

            for (auto& elem : bx)
                REQUIRE(elem == 5);

            for (auto& elem : rbx)
                REQUIRE(elem == false);
        }

        SECTION("Mismatched")
        {
            std::vector<int> v { 1, 2, 1, 1, 1, 5, 2, 5, 2, 2 };
            cortex::box<int> bx(5, 2);
            cortex::box<bool> bxcheck(5, 2);

            for (auto i { 0ul }; i < v.size(); ++i)
            {
                bx[i] = v[i];
                bxcheck[i] = v[i] != 2;
            }

            auto rbx { bx != 2 };

            REQUIRE(rbx == bxcheck);
        }
    }

    SECTION("Less Than")
    {
        SECTION("All Less Than")
        {
            cortex::box<int> bx(4, 5, 5);
            cortex::box<bool> bxcheck(4, 5, true);

            auto rbx { bx < 6 };

            REQUIRE(rbx == bxcheck);

            for (auto& elem : bx)
                REQUIRE(elem == 5);

            for (auto& elem : rbx)
                REQUIRE(elem == true);
        }

        SECTION("All Equal")
        {
            cortex::box<int> bx(4, 5, 5);
            cortex::box<bool> bxcheck(4, 5, false);

            auto rbx { bx < 5 };

            REQUIRE(rbx == bxcheck);

            for (auto& elem : bx)
                REQUIRE(elem == 5);

            for (auto& elem : rbx)
                REQUIRE(elem == false);
        }

        SECTION("Mismatched")
        {
            std::vector<int> v { 1, 2, 1, 1, 1, 5, 2, 5, 2, 2 };
            cortex::box<int> bx(5, 2);
            cortex::box<bool> bxcheck(5, 2);

            for (auto i { 0ul }; i < v.size(); ++i)
            {
                bx[i] = v[i];
                bxcheck[i] = v[i] < 2;
            }

            auto rbx { bx < 2 };

            REQUIRE(rbx == bxcheck);
        }
    }

    SECTION("Greater Than")
    {
        SECTION("All Greater Than")
        {
            cortex::box<int> bx(4, 5, 5);
            cortex::box<bool> bxcheck(4, 5, true);

            auto rbx { bx > 4 };

            REQUIRE(rbx == bxcheck);

            for (auto& elem : bx)
                REQUIRE(elem == 5);

            for (auto& elem : rbx)
                REQUIRE(elem == true);
        }

        SECTION("All Equal")
        {
            cortex::box<int> bx(4, 5, 5);
            cortex::box<bool> bxcheck(4, 5, false);

            auto rbx { bx > 5 };

            REQUIRE(rbx == bxcheck);

            for (auto& elem : bx)
                REQUIRE(elem == 5);

            for (auto& elem : rbx)
                REQUIRE(elem == false);
        }

        SECTION("Mismatched")
        {
            std::vector<int> v { 1, 2, 1, 1, 1, 5, 2, 5, 2, 2 };
            cortex::box<int> bx(5, 2);
            cortex::box<bool> bxcheck(5, 2);

            for (auto i { 0ul }; i < v.size(); ++i)
            {
                bx[i] = v[i];
                bxcheck[i] = v[i] > 2;
            }

            auto rbx { bx > 2 };

            REQUIRE(rbx == bxcheck);
        }
    }

    SECTION("Less Than Or Equal")
    {
        SECTION("All Less Than Or Equal")
        {
            cortex::box<int> bx(4, 5, 5);
            cortex::box<bool> bxcheck(4, 5, true);

            auto rbx1 { bx <= 5 };
            auto rbx2 { bx <= 6 };

            REQUIRE(rbx1 == bxcheck);
            REQUIRE(rbx2 == bxcheck);

            for (auto& elem : bx)
                REQUIRE(elem == 5);

            for (auto& elem : rbx1)
                REQUIRE(elem == true);
            
            for (auto& elem : rbx2)
                REQUIRE(elem == true);
        }

        SECTION("All Greater")
        {
            cortex::box<int> bx(4, 5, 5);
            cortex::box<bool> bxcheck(4, 5, false);

            auto rbx { bx <= 4 };

            REQUIRE(rbx == bxcheck);

            for (auto& elem : bx)
                REQUIRE(elem == 5);

            for (auto& elem : rbx)
                REQUIRE(elem == false);
        }

        SECTION("Mismatched")
        {
            std::vector<int> v { 1, 2, 1, 1, 1, 5, 2, 5, 2, 2 };
            cortex::box<int> bx(5, 2);
            cortex::box<bool> bxcheck(5, 2);

            for (auto i { 0ul }; i < v.size(); ++i)
            {
                bx[i] = v[i];
                bxcheck[i] = v[i] <= 2;
            }

            auto rbx { bx <= 2 };

            REQUIRE(rbx == bxcheck);
        }
    }

    SECTION("Greater Than Or Equal")
    {
        SECTION("All Greater Than Or Equal")
        {
            cortex::box<int> bx(4, 5, 5);
            cortex::box<bool> bxcheck(4, 5, true);

            auto rbx1 { bx >= 5 };
            auto rbx2 { bx >= 4 };

            REQUIRE(rbx1 == bxcheck);
            REQUIRE(rbx2 == bxcheck);

            for (auto& elem : bx)
                REQUIRE(elem == 5);

            for (auto& elem : rbx1)
                REQUIRE(elem == true);
            
            for (auto& elem : rbx2)
                REQUIRE(elem == true);
        }

        SECTION("All Less")
        {
            cortex::box<int> bx(4, 5, 5);
            cortex::box<bool> bxcheck(4, 5, false);

            auto rbx { bx >= 6 };

            REQUIRE(rbx == bxcheck);

            for (auto& elem : bx)
                REQUIRE(elem == 5);

            for (auto& elem : rbx)
                REQUIRE(elem == false);
        }

        SECTION("Mismatched")
        {
            std::vector<int> v { 1, 2, 1, 1, 1, 5, 2, 5, 2, 2 };
            cortex::box<int> bx(5, 2);
            cortex::box<bool> bxcheck(5, 2);

            for (auto i { 0ul }; i < v.size(); ++i)
            {
                bx[i] = v[i];
                bxcheck[i] = v[i] >= 2;
            }

            auto rbx { bx >= 2 };

            REQUIRE(rbx == bxcheck);
        }
    }
}