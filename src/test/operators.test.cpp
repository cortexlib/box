#include <catch2/catch.hpp>
#include <box.hpp>

TEST_CASE("Arithmatic Operators")
{
    SECTION("Add and Add Assign")
    {
        SECTION("Add")
        {
            SECTION("Same Type")
            {
                cortex::box<int> a = { { 1, 2, 3 }
                                     , { 4, 5, 6 } };

                REQUIRE(a.size() == 6);
                REQUIRE(a.dimensions() == std::tuple{2, 3});

                cortex::box<int> b = { { 7, 8, 9 }
                                     , { 10, 11, 12 } };

                REQUIRE(b.size() == 6);
                REQUIRE(b.dimensions() == std::tuple{2, 3});

                auto c { a + b };

                REQUIRE(c.size() == 6);
                REQUIRE(c.dimensions() == std::tuple{2, 3});
                REQUIRE(c == cortex::box<int> { { 8, 10, 12 }
                                              , { 14, 16, 18 } });
            }
        

            SECTION("Different Types")
            {
                    cortex::box<int> a = { { 1, 2 }
                                         , { 3, 4 }
                                         , { 5, 6 }
                                         , { 7, 8 } };

                    REQUIRE(a.size() == 8);
                    REQUIRE(a.dimensions() == std::tuple{4, 2});

                    cortex::box<double> b = { { 6, 23 }
                                            , { 4.52, 8.75 }
                                            , { 1.12, 435 }
                                            , { 13.4221, 0.4234 } };

                    REQUIRE(b.size() == 8);
                    REQUIRE(b.dimensions() == std::tuple{4, 2});

                    auto c { a + b };

                    REQUIRE(c.size() == 8);
                    REQUIRE(c.dimensions() == std::tuple{4, 2});
                    REQUIRE(c == cortex::box<double> { { 7.0, 25.0 }
                                                     , { 7.52, 12.75 }
                                                     , { 6.12, 441.0 }
                                                     , { 20.4221, 8.4234 } });
            }

            SECTION("Self Add")
            {
                    cortex::box<int> a = { { 1, 2 }
                                         , { 3, 4 }
                                         , { 5, 6 }
                                         , { 7, 8 } };

                    REQUIRE(a.size() == 8);
                    REQUIRE(a.dimensions() == std::tuple{4, 2});

                    auto c { a + a };

                    REQUIRE(c.size() == 8);
                    REQUIRE(c.dimensions() == std::tuple{4, 2});
                    REQUIRE(c == cortex::box<int> { { 2, 4 }
                                                  , { 6, 8 }
                                                  , { 10, 12 }
                                                  , { 14, 16 } });
            }
        }

        SECTION("Add Assign")
        {
            SECTION("Same Type")
            {
                cortex::box<int> a = { { 1, 2, 3 }
                                     , { 4, 5, 6 } };

                REQUIRE(a.size() == 6);
                REQUIRE(a.dimensions() == std::tuple{2, 3});

                cortex::box<int> b = { { 7, 8, 9 }
                                     , { 10, 11, 12 } };

                REQUIRE(b.size() == 6);
                REQUIRE(b.dimensions() == std::tuple{2, 3});

                a += b;

                REQUIRE(a.size() == 6);
                REQUIRE(a.dimensions() == std::tuple{2, 3});
                REQUIRE(a == cortex::box<int> { { 8, 10, 12 }
                                              , { 14, 16, 18 } });
            }
        

            SECTION("Different Types")
            {
                    cortex::box<int> a = { { 1, 2 }
                                         , { 3, 4 }
                                         , { 5, 6 }
                                         , { 7, 8 } };

                    REQUIRE(a.size() == 8);
                    REQUIRE(a.dimensions() == std::tuple{4, 2});

                    cortex::box<double> b = { { 6, 23 }
                                            , { 4.52, 8.75 }
                                            , { 1.12, 435 }
                                            , { 13.4221, 0.4234 } };

                    REQUIRE(b.size() == 8);
                    REQUIRE(b.dimensions() == std::tuple{4, 2});

                    REQUIRE_THROWS_AS(a += b, std::invalid_argument);
                    b += a;

                    REQUIRE(b.size() == 8);
                    REQUIRE(b.dimensions() == std::tuple{4, 2});
                    REQUIRE(b == cortex::box<double> { { 7.0, 25.0 }
                                                     , { 7.52, 12.75 }
                                                     , { 6.12, 441.0 }
                                                     , { 20.4221, 8.4234 } });
            }

            SECTION("Self Add")
            {
                    cortex::box<int> a = { { 1, 2 }
                                         , { 3, 4 }
                                         , { 5, 6 }
                                         , { 7, 8 } };

                    REQUIRE(a.size() == 8);
                    REQUIRE(a.dimensions() == std::tuple{4, 2});

                    a += a;

                    REQUIRE(a.size() == 8);
                    REQUIRE(a.dimensions() == std::tuple{4, 2});
                    REQUIRE(a == cortex::box<int> { { 2, 4 }
                                                  , { 6, 8 }
                                                  , { 10, 12 }
                                                  , { 14, 16 } });
            }
        }
    }
}