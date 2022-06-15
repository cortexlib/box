#include <catch2/catch.hpp>
#include <box.hpp>

TEST_CASE("Direct Comparisons")
{
    SECTION("Equality")
    {
        SECTION("Equal")
        {
            cortex::box<int> bx(4, 5, 1);
            cortex::box<int> nbx(4, 5, 1);

            REQUIRE(bx == bx);
            REQUIRE(bx == nbx);
        }

        SECTION("Different size")
        {
            cortex::box<int> bx(5, 8, 1);
            cortex::box<int> nbx(4, 13, 1);

            REQUIRE(bx != nbx);
            REQUIRE(nbx != bx);
        }
    }

    SECTION("Inequality")
    {
        SECTION("Not Equal")
        {
            cortex::box<int> bx(4, 5, 1);
            cortex::box<int> nbx(4, 5, 2);

            REQUIRE(bx != nbx);
            REQUIRE(nbx != bx);
        }

        SECTION("Different size")
        {
            cortex::box<int> bx(13, 6, 1);
            cortex::box<int> nbx(17, 11, 1);

            REQUIRE(bx != nbx);
            REQUIRE(nbx != bx);
        }

        SECTION("Different data")
        {
            cortex::box<int> bx(4, 5, 1);
            cortex::box<int> nbx(4, 5, 2);

            REQUIRE(bx != nbx);
            REQUIRE(nbx != bx);
        }

        SECTION("Different data and size")
        {
            cortex::box<int> bx(13, 6, 1);
            cortex::box<int> nbx(17, 11, 2);

            REQUIRE(bx != nbx);
            REQUIRE(nbx != bx);
        }
    }

    SECTION("Less Than")
    {
        SECTION("Different data")
        {
            cortex::box<int> bx(4, 5, 1);
            cortex::box<int> nbx(4, 5, 2);

            REQUIRE(bx < nbx);
            REQUIRE(!(nbx < bx));
        }

        SECTION("Different size")
        {
            cortex::box<int> bx(13, 6, 1);
            cortex::box<int> nbx(17, 11, 1);

            REQUIRE(bx < nbx);
            REQUIRE(!(nbx < bx));
        }

        SECTION("Different data and size")
        {
            cortex::box<int> bx(13, 6, 2);
            cortex::box<int> nbx(17, 11, 1);

            REQUIRE(!(bx < nbx));
            REQUIRE(nbx < bx);
        }

        SECTION("Same data")
        {
            cortex::box<int> bx(4, 5, 1);
            cortex::box<int> nbx(4, 5, 1);

            REQUIRE(!(bx < nbx));
            REQUIRE(!(nbx < bx));
        }
    }

    SECTION("Greater Than")
    {
        SECTION("Different data")
        {
            cortex::box<int> bx(4, 5, 1);
            cortex::box<int> nbx(4, 5, 2);

            REQUIRE(nbx > bx);
            REQUIRE(!(bx > nbx));
        }

        SECTION("Different size")
        {
            cortex::box<int> bx(13, 6, 1);
            cortex::box<int> nbx(17, 11, 1);

            REQUIRE(nbx > bx);
            REQUIRE(!(bx > nbx));
        }

        SECTION("Different data and size")
        {
            cortex::box<int> bx(13, 6, 2);
            cortex::box<int> nbx(17, 11, 1);

            REQUIRE(bx > nbx);
            REQUIRE(!(nbx > bx));
        }

        SECTION("Same data")
        {
            cortex::box<int> bx(4, 5, 1);
            cortex::box<int> nbx(4, 5, 1);

            REQUIRE(!(nbx > bx));
            REQUIRE(!(bx > nbx));
        }
    }

    SECTION("Less Than or Equal")
    {
        SECTION("Different data")
        {
            cortex::box<int> bx(4, 5, 1);
            cortex::box<int> nbx(4, 5, 2);

            REQUIRE(bx <= nbx);
            REQUIRE(!(nbx <= bx));
        }

        SECTION("Different size")
        {
            cortex::box<int> bx(13, 6, 1);
            cortex::box<int> nbx(17, 11, 1);

            REQUIRE(bx <= nbx);
            REQUIRE(!(nbx <= bx));
        }

        SECTION("Different data and size")
        {
            cortex::box<int> bx(13, 6, 2);
            cortex::box<int> nbx(17, 11, 1);

            REQUIRE(bx > nbx);
            REQUIRE(nbx <= bx);
        }

        SECTION("Same data")
        {
            cortex::box<int> bx(4, 5, 1);
            cortex::box<int> nbx(4, 5, 1);

            REQUIRE(bx <= nbx);
            REQUIRE(nbx <= bx);
        }
    }

    SECTION("Greater Than or Equal")
    {
        SECTION("Different data")
        {
            cortex::box<int> bx(4, 5, 1);
            cortex::box<int> nbx(4, 5, 2);

            REQUIRE(nbx >= bx);
            REQUIRE(!(bx >= nbx));
        }

        SECTION("Different size")
        {
            cortex::box<int> bx(13, 6, 1);
            cortex::box<int> nbx(17, 11, 1);

            REQUIRE(nbx >= bx);
            REQUIRE(!(bx >= nbx));
        }

        SECTION("Different data and size")
        {
            cortex::box<int> bx(13, 6, 2);
            cortex::box<int> nbx(17, 11, 1);

            REQUIRE(bx >= nbx);
            REQUIRE(!(nbx >= bx));
        }

        SECTION("Same data")
        {
            cortex::box<int> bx(4, 5, 1);
            cortex::box<int> nbx(4, 5, 1);

            REQUIRE(bx >= nbx);
            REQUIRE(nbx >= bx);
        }
    }
}