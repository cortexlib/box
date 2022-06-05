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

    SECTION("Minus and Minus Assign")
    {
        SECTION("Minus")
        {
            SECTION("Same Type")
            {
                cortex::box<int> a = { { 1, 2, 3 }
                                     , { 4, 5, 6 } };

                REQUIRE(a.size() == 6);
                REQUIRE(a.dimensions() == std::tuple{2, 3});

                cortex::box<int> b = { { 5, 113, 13 }
                                     , { 243, -42, 114 } };

                REQUIRE(b.size() == 6);
                REQUIRE(b.dimensions() == std::tuple{2, 3});

                auto c { a - b };

                REQUIRE(c.size() == 6);
                REQUIRE(c.dimensions() == std::tuple{2, 3});
                REQUIRE(c == cortex::box<int> { { -4, -111, -10 }
                                              , { -239, 47, -108 } });
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
                                            , { 4.5, 8.75 }
                                            , { 1.15, 435 }
                                            , { 13.4, 0.4 } };

                    REQUIRE(b.size() == 8);
                    REQUIRE(b.dimensions() == std::tuple{4, 2});

                    auto c { a - b };

                    REQUIRE(c.size() == 8);
                    REQUIRE(c.dimensions() == std::tuple{4, 2});
                    REQUIRE(c == cortex::box<double> { { -5.0, -21.0 }
                                                     , { -1.5, -4.75 }
                                                     , { 3.85, -429.0 }
                                                     , { -6.4, 7.6 } });
            }

            SECTION("Self Minus")
            {
                    cortex::box<int> a = { { 1, 2 }
                                         , { 3, 4 }
                                         , { 5, 6 }
                                         , { 7, 8 } };

                    REQUIRE(a.size() == 8);
                    REQUIRE(a.dimensions() == std::tuple{4, 2});

                    auto c { a - a };

                    REQUIRE(c.size() == 8);
                    REQUIRE(c.dimensions() == std::tuple{4, 2});
                    REQUIRE(c == cortex::box<int> { { 0, 0 }
                                                  , { 0, 0 }
                                                  , { 0, 0}
                                                  , { 0, 0 } });
            }
        }

        SECTION("Minus Assign")
        {
            SECTION("Same Type")
            {
                cortex::box<int> a = { { 1, 2, 3 }
                                     , { 4, 5, 6 } };

                REQUIRE(a.size() == 6);
                REQUIRE(a.dimensions() == std::tuple{2, 3});

                cortex::box<int> b = { { 25, 14, 2 }
                                     , { -14, -2453, 12 } };

                REQUIRE(b.size() == 6);
                REQUIRE(b.dimensions() == std::tuple{2, 3});

                a -= b;

                REQUIRE(a.size() == 6);
                REQUIRE(a.dimensions() == std::tuple{2, 3});
                REQUIRE(a == cortex::box<int> { { -24, -12, 1 }
                                              , { 18, 2458, -6 } });
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
                                            , { 4.5, 8.75 }
                                            , { 1.15, 435 }
                                            , { 13.5, 0.4 } };

                    REQUIRE(b.size() == 8);
                    REQUIRE(b.dimensions() == std::tuple{4, 2});

                    REQUIRE_THROWS_AS(a -= b, std::invalid_argument);
                    b -= a;

                    REQUIRE(b.size() == 8);
                    REQUIRE(b.dimensions() == std::tuple{4, 2});
                    REQUIRE(b == cortex::box<double> { { 5.0, 21.0 }
                                                     , { 1.5, 4.75 }
                                                     , { -3.85, 429.0 }
                                                     , { 6.5, -7.6 } });
            }

            SECTION("Self Minus")
            {
                    cortex::box<int> a = { { 1, 2 }
                                         , { 3, 4 }
                                         , { 5, 6 }
                                         , { 7, 8 } };

                    REQUIRE(a.size() == 8);
                    REQUIRE(a.dimensions() == std::tuple{4, 2});

                    a -= a;

                    REQUIRE(a.size() == 8);
                    REQUIRE(a.dimensions() == std::tuple{4, 2});
                    REQUIRE(a == cortex::box<int> { { 0, 0 }
                                                  , { 0, 0 }
                                                  , { 0, 0 }
                                                  , { 0, 0 } });
            }
        }
    }

    SECTION("Multiply and Multiply Assign")
    {
        SECTION("Box Multiply")
        {
            SECTION("Multiply")
            {
                SECTION("Same Type")
                {
                    cortex::box<int> a = { { 1, 2, 3 }
                                         , { 4, 5, 6 } };

                    REQUIRE(a.size() == 6);
                    REQUIRE(a.dimensions() == std::tuple{2, 3});

                    cortex::box<int> b = { { 5, 113, 13 }
                                         , { 243, -42, 114 } };

                    REQUIRE(b.size() == 6);
                    REQUIRE(b.dimensions() == std::tuple{2, 3});

                    auto c { a * b };

                    REQUIRE(c.size() == 6);
                    REQUIRE(c.dimensions() == std::tuple{2, 3});
                    REQUIRE(c == cortex::box<int> { { 5, 226, 39 }
                                                  , { 972, -210, 684 } });
                }

                SECTION("Different Type")
                {
                    cortex::box<int> a = { { 1, 2 }
                                         , { 3, 4 }
                                         , { 5, 6 }
                                         , { 7, 8 } };

                    REQUIRE(a.size() == 8);
                    REQUIRE(a.dimensions() == std::tuple{4, 2});

                    cortex::box<double> b = { { 6, 23 }
                                            , { 4.5, 8.75 }
                                            , { 1.15, 435 }
                                            , { 13.4, 0.4 } };

                    REQUIRE(b.size() == 8);
                    REQUIRE(b.dimensions() == std::tuple{4, 2});

                    auto c { a * b };

                    REQUIRE(c.size() == 8);
                    REQUIRE(c.dimensions() == std::tuple{4, 2});
                    REQUIRE(c == cortex::box<double> { { 6, 46 }
                                                     , { 13.5, 35 }
                                                     , { 5.75, 2610 }
                                                     , { 93.8, 3.2 } });
                }

                SECTION("Self Multiply")
                {
                    cortex::box<int> a = { { 1, 2 }
                                         , { 3, 4 }
                                         , { 5, 6 }
                                         , { 7, 8 } };

                    REQUIRE(a.size() == 8);
                    REQUIRE(a.dimensions() == std::tuple{4, 2});

                    auto c { a * a };

                    REQUIRE(c.size() == 8);
                    REQUIRE(c.dimensions() == std::tuple{4, 2});
                    REQUIRE(c == cortex::box<int> { { 1, 4 }
                                                  , { 9, 16 }
                                                  , { 25, 36 }
                                                  , { 49, 64 } });
                }
            }

            SECTION("Multiply Assign") 
            {
                SECTION("Same Type")
                {
                    cortex::box<int> a = { { 1, 2, 3 }
                                         , { 4, 5, 6 } };

                    REQUIRE(a.size() == 6);
                    REQUIRE(a.dimensions() == std::tuple{2, 3});

                    cortex::box<int> b = { { 5, 113, 13 }
                                         , { 243, -42, 114 } };

                    REQUIRE(b.size() == 6);
                    REQUIRE(b.dimensions() == std::tuple{2, 3});

                    a *= b;

                    REQUIRE(a.size() == 6);
                    REQUIRE(a.dimensions() == std::tuple{2, 3});
                    REQUIRE(a == cortex::box<int> { { 5, 226, 39 }
                                                  , { 972, -210, 684 } });
                }

                SECTION("Different Type")
                {
                    cortex::box<int> a = { { 1, 2 }
                                         , { 3, 4 }
                                         , { 5, 6 }
                                         , { 7, 8 } };

                    REQUIRE(a.size() == 8);
                    REQUIRE(a.dimensions() == std::tuple{4, 2});

                    cortex::box<double> b = { { 6, 23 }
                                            , { 4.5, 8.75 }
                                            , { 1.15, 435 }
                                            , { 13.4, 0.4 } };

                    REQUIRE(b.size() == 8);
                    REQUIRE(b.dimensions() == std::tuple{4, 2});

                    REQUIRE_THROWS_AS(a *= b, std::invalid_argument);
                    b *= a;

                    REQUIRE(b.size() == 8);
                    REQUIRE(b.dimensions() == std::tuple{4, 2});
                    REQUIRE(b == cortex::box<double> { { 6, 46 }
                                                     , { 13.5, 35 }
                                                     , { 5.75, 2610 }
                                                     , { 93.8, 3.2 } });
                }
            }
        }

        SECTION("Scalar Multiply")
        {
            SECTION("Multiply")
            {
                SECTION("Same Type")
                {
                    cortex::box<int> a = { { 1, 2, 3 }
                                         , { 4, 5, 6 } };

                    REQUIRE(a.size() == 6);
                    REQUIRE(a.dimensions() == std::tuple{2, 3});

                    auto b { a * 5 };
                    auto c { 4 * a };

                    REQUIRE(b.size() == 6);
                    REQUIRE(b.dimensions() == std::tuple{2, 3});
                    REQUIRE(b == cortex::box<int> { { 5, 10, 15 }
                                                  , { 20, 25, 30 } });

                    REQUIRE(c.size() == 6);
                    REQUIRE(c.dimensions() == std::tuple{2, 3});
                    REQUIRE(c == cortex::box<int> { { 4, 8, 12 }
                                                  , { 16, 20, 24 } });
                }
            }

            SECTION("Multiply Assign")
            {
                SECTION("Same Type")
                {
                    cortex::box<int> a = { { 1, 2, 3 }
                                         , { 4, 5, 6 } };

                    REQUIRE(a.size() == 6);
                    REQUIRE(a.dimensions() == std::tuple{2, 3});

                    a *= 5;
                    
                    REQUIRE(a.size() == 6);
                    REQUIRE(a.dimensions() == std::tuple{2, 3});
                    REQUIRE(a == cortex::box<int> { { 5, 10, 15 }
                                                  , { 20, 25, 30 } });
                }
            }
        }
    }
}

TEST_CASE("Bit Operators")
{
    SECTION("Bit And and Bit And Assign")
    {
        SECTION("Box Bit And")
        {
            SECTION("Bit And")
            {
                SECTION("Same Type")
                {
                    cortex::box<int> a = { { 1, 2, 3 }
                                         , { 4, 5, 6 } };

                    REQUIRE(a.size() == 6);
                    REQUIRE(a.dimensions() == std::tuple{2, 3});

                    cortex::box<int> b = { { 5, 113, 13 }
                                         , { 243, -42, 114 } };

                    REQUIRE(b.size() == 6);
                    REQUIRE(b.dimensions() == std::tuple{2, 3});

                    auto c { a & b };

                    REQUIRE(c.size() == 6);
                    REQUIRE(c.dimensions() == std::tuple{2, 3});
                    REQUIRE(c == cortex::box<int> { { 1, 0, 1 }
                                                  , { 0, 4, 2 } });
                }

                SECTION("Different Type")
                {
                    cortex::box<int> a = { { 1, 2 }
                                         , { 3, 4 }
                                         , { 5, 6 }
                                         , { 7, 8 } };

                    REQUIRE(a.size() == 8);
                    REQUIRE(a.dimensions() == std::tuple{4, 2});

                    cortex::box<short> b = { { 6, 23 }
                                           , { 45, 8 }
                                           , { 115, 255 }
                                           , { 13, 4 } };

                    REQUIRE(b.size() == 8);
                    REQUIRE(b.dimensions() == std::tuple{4, 2});

                    auto c { a & b };

                    REQUIRE(c.size() == 8);
                    REQUIRE(c.dimensions() == std::tuple{4, 2});
                    REQUIRE(c == cortex::box<short> { { 0, 2 }
                                                    , { 1, 0 }
                                                    , { 1, 6 }
                                                    , { 5, 0 } });
                }

                SECTION("Self Bit And")
                {
                    cortex::box<int> a = { { 1, 2 }
                                         , { 3, 4 }
                                         , { 5, 6 }
                                         , { 7, 8 } };

                    REQUIRE(a.size() == 8);
                    REQUIRE(a.dimensions() == std::tuple{4, 2});

                    auto c { a & a };

                    REQUIRE(c.size() == 8);
                    REQUIRE(c.dimensions() == std::tuple{4, 2});
                    REQUIRE(c == cortex::box<int> { { 1, 2 }
                                                  , { 3, 4 }
                                                  , { 5, 6 }
                                                  , { 7, 8 } });
                }
            }

            SECTION("Bit And Assign") 
            {
                SECTION("Same Type")
                {
                    cortex::box<int> a = { { 1, 2, 3 }
                                         , { 4, 5, 6 } };

                    REQUIRE(a.size() == 6);
                    REQUIRE(a.dimensions() == std::tuple{2, 3});

                    cortex::box<int> b = { { 5, 113, 13 }
                                         , { 243, -42, 114 } };

                    REQUIRE(b.size() == 6);
                    REQUIRE(b.dimensions() == std::tuple{2, 3});

                    a &= b;

                    REQUIRE(a.size() == 6);
                    REQUIRE(a.dimensions() == std::tuple{2, 3});
                    REQUIRE(a == cortex::box<int> { { 1, 0, 1 }
                                                  , { 0, 4, 2 } });
                }

                SECTION("Different Type")
                {
                    cortex::box<short> a = { { 1, 2 }
                                           , { 3, 4 }
                                           , { 5, 6 }
                                           , { 7, 8 } };

                    REQUIRE(a.size() == 8);
                    REQUIRE(a.dimensions() == std::tuple{4, 2});

                    cortex::box<int> b = { { 6, 23 }
                                         , { 45, 8 }
                                         , { 115, 255 }
                                         , { 13, 4 } };

                    REQUIRE(b.size() == 8);
                    REQUIRE(b.dimensions() == std::tuple{4, 2});

                    REQUIRE_THROWS_AS(a &= b, std::invalid_argument);
                    b &= a;

                    REQUIRE(b.size() == 8);
                    REQUIRE(b.dimensions() == std::tuple{4, 2});
                    REQUIRE(b == cortex::box<int> { { 0, 2 }
                                                  , { 1, 0 }
                                                  , { 1, 6 }
                                                  , { 5, 0 } });
                }
            }
        }

        SECTION("Scalar Bit And")
        {
            SECTION("Bit And")
            {
                SECTION("Same Type")
                {
                    cortex::box<int> a = { { 1, 2, 3 }
                                         , { 4, 5, 6 } };

                    REQUIRE(a.size() == 6);
                    REQUIRE(a.dimensions() == std::tuple{2, 3});

                    auto b { a & 5 };
                    auto c { 4 & a };

                    REQUIRE(b.size() == 6);
                    REQUIRE(b.dimensions() == std::tuple{2, 3});
                    REQUIRE(b == cortex::box<int> { { 1, 0, 1 }
                                                  , { 4, 5, 4 } });

                    REQUIRE(c.size() == 6);
                    REQUIRE(c.dimensions() == std::tuple{2, 3});
                    REQUIRE(c == cortex::box<int> { { 0, 0, 0 }
                                                  , { 4, 4, 4 } });
                }
            }

            SECTION("Bit And Assign")
            {
                SECTION("Same Type")
                {
                    cortex::box<int> a = { { 1, 2, 3 }
                                         , { 4, 5, 6 } };

                    REQUIRE(a.size() == 6);
                    REQUIRE(a.dimensions() == std::tuple{2, 3});

                    a &= 5;
                    
                    REQUIRE(a.size() == 6);
                    REQUIRE(a.dimensions() == std::tuple{2, 3});
                    REQUIRE(a == cortex::box<int> { { 1, 0, 1 }
                                                  , { 4, 5, 4 } });
                }
            }
        }
    }

    SECTION("Bit Or and Bit Or Assign")
    {
        SECTION("Box Bit Or")
        {
            SECTION("Bit Or")
            {
                SECTION("Same Type")
                {
                    cortex::box<int> a = { { 1, 2, 3 }
                                         , { 4, 5, 6 } };

                    REQUIRE(a.size() == 6);
                    REQUIRE(a.dimensions() == std::tuple{2, 3});

                    cortex::box<int> b = { { 5, 113, 13 }
                                         , { 243, -42, 114 } };

                    REQUIRE(b.size() == 6);
                    REQUIRE(b.dimensions() == std::tuple{2, 3});

                    auto c { a | b };

                    REQUIRE(c.size() == 6);
                    REQUIRE(c.dimensions() == std::tuple{2, 3});
                    REQUIRE(c == cortex::box<int> { { 5, 115, 15 }
                                                  , { 247, -41, 118 } });
                }

                SECTION("Different Type")
                {
                    cortex::box<int> a = { { 1, 2 }
                                         , { 3, 4 }
                                         , { 5, 6 }
                                         , { 7, 8 } };

                    REQUIRE(a.size() == 8);
                    REQUIRE(a.dimensions() == std::tuple{4, 2});

                    cortex::box<short> b = { { 6, 23 }
                                           , { 45, 8 }
                                           , { 115, 255 }
                                           , { 13, 4 } };

                    REQUIRE(b.size() == 8);
                    REQUIRE(b.dimensions() == std::tuple{4, 2});

                    auto c { a | b };

                    REQUIRE(c.size() == 8);
                    REQUIRE(c.dimensions() == std::tuple{4, 2});
                    REQUIRE(c == cortex::box<short> { { 7, 23 }
                                                    , { 47, 12 }
                                                    , { 119, 255 }
                                                    , { 15, 12 } });
                }

                SECTION("Self Bit Or")
                {
                    cortex::box<int> a = { { 1, 2 }
                                         , { 3, 4 }
                                         , { 5, 6 }
                                         , { 7, 8 } };

                    REQUIRE(a.size() == 8);
                    REQUIRE(a.dimensions() == std::tuple{4, 2});

                    auto c { a | a };

                    REQUIRE(c.size() == 8);
                    REQUIRE(c.dimensions() == std::tuple{4, 2});
                    REQUIRE(c == cortex::box<int> { { 1, 2 }
                                                  , { 3, 4 }
                                                  , { 5, 6 }
                                                  , { 7, 8 } });
                }
            }

            SECTION("Bit Or Assign") 
            {
                SECTION("Same Type")
                {
                    cortex::box<int> a = { { 1, 2, 3 }
                                         , { 4, 5, 6 } };

                    REQUIRE(a.size() == 6);
                    REQUIRE(a.dimensions() == std::tuple{2, 3});

                    cortex::box<int> b = { { 5, 113, 13 }
                                         , { 243, -42, 114 } };

                    REQUIRE(b.size() == 6);
                    REQUIRE(b.dimensions() == std::tuple{2, 3});

                    a |= b;

                    REQUIRE(a.size() == 6);
                    REQUIRE(a.dimensions() == std::tuple{2, 3});
                    REQUIRE(a == cortex::box<int> { { 5, 115, 15 }
                                                  , { 247, -41, 118 } });
                }

                SECTION("Different Type")
                {
                    cortex::box<short> a = { { 1, 2 }
                                           , { 3, 4 }
                                           , { 5, 6 }
                                           , { 7, 8 } };

                    REQUIRE(a.size() == 8);
                    REQUIRE(a.dimensions() == std::tuple{4, 2});

                    cortex::box<int> b = { { 6, 23 }
                                         , { 45, 8 }
                                         , { 115, 255 }
                                         , { 13, 4 } };

                    REQUIRE(b.size() == 8);
                    REQUIRE(b.dimensions() == std::tuple{4, 2});

                    REQUIRE_THROWS_AS(a |= b, std::invalid_argument);
                    b |= a;

                    REQUIRE(b.size() == 8);
                    REQUIRE(b.dimensions() == std::tuple{4, 2});
                    REQUIRE(b == cortex::box<int> { { 7, 23 }
                                                  , { 47, 12 }
                                                  , { 119, 255 }
                                                  , { 15, 12 } });
                }
            }
        }

        SECTION("Scalar Bit Or")
        {
            SECTION("Bit Or")
            {
                SECTION("Same Type")
                {
                    cortex::box<int> a = { { 1, 2, 3 }
                                         , { 4, 5, 6 } };

                    REQUIRE(a.size() == 6);
                    REQUIRE(a.dimensions() == std::tuple{2, 3});

                    auto b { a | 5 };
                    auto c { 4 | a };

                    REQUIRE(b.size() == 6);
                    REQUIRE(b.dimensions() == std::tuple{2, 3});
                    REQUIRE(b == cortex::box<int> { { 5, 7, 7 }
                                                  , { 5, 5, 7 } });

                    REQUIRE(c.size() == 6);
                    REQUIRE(c.dimensions() == std::tuple{2, 3});
                    REQUIRE(c == cortex::box<int> { { 5, 6, 7 }
                                                  , { 4, 5, 6 } });
                }
            }

            SECTION("Bit Or Assign")
            {
                SECTION("Same Type")
                {
                    cortex::box<int> a = { { 1, 2, 3 }
                                         , { 4, 5, 6 } };

                    REQUIRE(a.size() == 6);
                    REQUIRE(a.dimensions() == std::tuple{2, 3});

                    a |= 5;
                    
                    REQUIRE(a.size() == 6);
                    REQUIRE(a.dimensions() == std::tuple{2, 3});
                    REQUIRE(a == cortex::box<int> { { 5, 7, 7 }
                                                  , { 5, 5, 7 } });
                }
            }
        }
    }

    SECTION("Bit Xor and Bit Xor Assign")
    {
        SECTION("Box Bit Xor")
        {
            SECTION("Bit Xor")
            {
                SECTION("Same Type")
                {
                    cortex::box<int> a = { { 1, 2, 3 }
                                         , { 4, 5, 6 } };

                    REQUIRE(a.size() == 6);
                    REQUIRE(a.dimensions() == std::tuple{2, 3});

                    cortex::box<int> b = { { 5, 113, 13 }
                                         , { 243, -42, 114 } };

                    REQUIRE(b.size() == 6);
                    REQUIRE(b.dimensions() == std::tuple{2, 3});

                    auto c { a ^ b };

                    REQUIRE(c.size() == 6);
                    REQUIRE(c.dimensions() == std::tuple{2, 3});
                    REQUIRE(c == cortex::box<int> { { 4, 115, 14 }
                                                  , { 247, -45, 116 } });
                }

                SECTION("Different Type")
                {
                    cortex::box<int> a = { { 1, 2 }
                                         , { 3, 4 }
                                         , { 5, 6 }
                                         , { 7, 8 } };

                    REQUIRE(a.size() == 8);
                    REQUIRE(a.dimensions() == std::tuple{4, 2});

                    cortex::box<short> b = { { 6, 23 }
                                           , { 45, 8 }
                                           , { 115, 255 }
                                           , { 13, 4 } };

                    REQUIRE(b.size() == 8);
                    REQUIRE(b.dimensions() == std::tuple{4, 2});

                    auto c { a ^ b };

                    REQUIRE(c.size() == 8);
                    REQUIRE(c.dimensions() == std::tuple{4, 2});
                    REQUIRE(c == cortex::box<short> { { 7, 21 }
                                                    , { 46, 12 }
                                                    , { 118, 249 }
                                                    , { 10, 12 } });
                }

                SECTION("Self Bit Xor")
                {
                    cortex::box<int> a = { { 1, 2 }
                                         , { 3, 4 }
                                         , { 5, 6 }
                                         , { 7, 8 } };

                    REQUIRE(a.size() == 8);
                    REQUIRE(a.dimensions() == std::tuple{4, 2});

                    auto c { a ^ a };

                    REQUIRE(c.size() == 8);
                    REQUIRE(c.dimensions() == std::tuple{4, 2});
                    REQUIRE(c == cortex::box<int> { { 0, 0 }
                                                  , { 0, 0 }
                                                  , { 0, 0 }
                                                  , { 0, 0 } });
                }
            }

            SECTION("Bit Xor Assign") 
            {
                SECTION("Same Type")
                {
                    cortex::box<int> a = { { 1, 2, 3 }
                                         , { 4, 5, 6 } };

                    REQUIRE(a.size() == 6);
                    REQUIRE(a.dimensions() == std::tuple{2, 3});

                    cortex::box<int> b = { { 5, 113, 13 }
                                         , { 243, -42, 114 } };

                    REQUIRE(b.size() == 6);
                    REQUIRE(b.dimensions() == std::tuple{2, 3});

                    a ^= b;

                    REQUIRE(a.size() == 6);
                    REQUIRE(a.dimensions() == std::tuple{2, 3});
                    REQUIRE(a == cortex::box<int> { { 4, 115, 14 }
                                                  , { 247, -45, 116 } });
                }

                SECTION("Different Type")
                {
                    cortex::box<short> a = { { 1, 2 }
                                           , { 3, 4 }
                                           , { 5, 6 }
                                           , { 7, 8 } };

                    REQUIRE(a.size() == 8);
                    REQUIRE(a.dimensions() == std::tuple{4, 2});

                    cortex::box<int> b = { { 6, 23 }
                                         , { 45, 8 }
                                         , { 115, 255 }
                                         , { 13, 4 } };

                    REQUIRE(b.size() == 8);
                    REQUIRE(b.dimensions() == std::tuple{4, 2});

                    REQUIRE_THROWS_AS(a ^= b, std::invalid_argument);
                    b ^= a;

                    REQUIRE(b.size() == 8);
                    REQUIRE(b.dimensions() == std::tuple{4, 2});
                    REQUIRE(b == cortex::box<int> { { 7, 21 }
                                                  , { 46, 12 }
                                                  , { 118, 249 }
                                                  , { 10, 12 } });
                }
            }
        }

        SECTION("Scalar Bit Xor")
        {
            SECTION("Bit Xor")
            {
                SECTION("Same Type")
                {
                    cortex::box<int> a = { { 1, 2, 3 }
                                         , { 4, 5, 6 } };

                    REQUIRE(a.size() == 6);
                    REQUIRE(a.dimensions() == std::tuple{2, 3});

                    auto b { a ^ 5 };
                    auto c { 4 ^ a };

                    REQUIRE(b.size() == 6);
                    REQUIRE(b.dimensions() == std::tuple{2, 3});
                    REQUIRE(b == cortex::box<int> { { 4, 7, 6 }
                                                  , { 1, 0, 3 } });

                    REQUIRE(c.size() == 6);
                    REQUIRE(c.dimensions() == std::tuple{2, 3});
                    REQUIRE(c == cortex::box<int> { { 5, 6, 7 }
                                                  , { 0, 1, 2 } });
                }
            }

            SECTION("Bit Xor Assign")
            {
                SECTION("Same Type")
                {
                    cortex::box<int> a = { { 1, 2, 3 }
                                         , { 4, 5, 6 } };

                    REQUIRE(a.size() == 6);
                    REQUIRE(a.dimensions() == std::tuple{2, 3});

                    a ^= 5;
                    
                    REQUIRE(a.size() == 6);
                    REQUIRE(a.dimensions() == std::tuple{2, 3});
                    REQUIRE(a == cortex::box<int> { { 4, 7, 6 }
                                                  , { 1, 0, 3 } });
                }
            }
        }
    }

    SECTION("Left Bit Shift and Left Bit Shift Assign")
    {
        SECTION("Box Left Bit Shift")
        {
            SECTION("Left Bit Shift")
            {
                SECTION("Same Type")
                {
                    cortex::box<int> a = { { 1, 2, 3 }
                                         , { 4, 5, 6 } };

                    REQUIRE(a.size() == 6);
                    REQUIRE(a.dimensions() == std::tuple{2, 3});

                    cortex::box<int> b = { { 5, 113, 13 }
                                         , { 243, -42, 114 } };

                    REQUIRE(b.size() == 6);
                    REQUIRE(b.dimensions() == std::tuple{2, 3});

                    auto c { a << b };

                    REQUIRE(c.size() == 6);
                    REQUIRE(c.dimensions() == std::tuple{2, 3});
                    REQUIRE(c == cortex::box<int> { { 32, 262144, 24576 }
                                                  , { 2097152, 20971520, 1572864 } });
                }

                SECTION("Different Type")
                {
                    cortex::box<int> a = { { 1, 2 }
                                         , { 3, 4 }
                                         , { 5, 6 }
                                         , { 7, 8 } };

                    REQUIRE(a.size() == 8);
                    REQUIRE(a.dimensions() == std::tuple{4, 2});

                    cortex::box<short> b = { { 6, 2 }
                                           , { 1, 8 }
                                           , { 1, 5 }
                                           , { 2, 4 } };

                    REQUIRE(b.size() == 8);
                    REQUIRE(b.dimensions() == std::tuple{4, 2});

                    auto c { a << b };

                    REQUIRE(c.size() == 8);
                    REQUIRE(c.dimensions() == std::tuple{4, 2});
                    REQUIRE(c == cortex::box<short> { { 64, 8 }
                                                    , { 6, 1024 }
                                                    , { 10, 192 }
                                                    , { 28, 128 } });
                }

                SECTION("Self Left Bit Shift")
                {
                    cortex::box<int> a = { { 1, 2 }
                                         , { 3, 4 }
                                         , { 5, 6 }
                                         , { 7, 8 } };

                    REQUIRE(a.size() == 8);
                    REQUIRE(a.dimensions() == std::tuple{4, 2});

                    auto c { a << a };

                    REQUIRE(c.size() == 8);
                    REQUIRE(c.dimensions() == std::tuple{4, 2});
                    REQUIRE(c == cortex::box<int> { { 2, 8 }
                                                  , { 24, 64 }
                                                  , { 160, 384 }
                                                  , { 896, 2048 } });
                }
            }

            SECTION("Left Bit Shift Assign") 
            {
                SECTION("Same Type")
                {
                    cortex::box<int> a = { { 1, 2, 3 }
                                         , { 4, 5, 6 } };

                    REQUIRE(a.size() == 6);
                    REQUIRE(a.dimensions() == std::tuple{2, 3});

                    cortex::box<int> b = { { 5, 113, 13 }
                                         , { 243, -42, 114 } };

                    REQUIRE(b.size() == 6);
                    REQUIRE(b.dimensions() == std::tuple{2, 3});

                    a <<= b;

                    REQUIRE(a.size() == 6);
                    REQUIRE(a.dimensions() == std::tuple{2, 3});
                    REQUIRE(a == cortex::box<int> { { 32, 262144, 24576 }
                                                  , { 2097152, 20971520, 1572864 } });
                }

                SECTION("Different Type")
                {
                    cortex::box<short> a = { { 1, 2 }
                                           , { 3, 4 }
                                           , { 5, 6 }
                                           , { 7, 8 } };

                    REQUIRE(a.size() == 8);
                    REQUIRE(a.dimensions() == std::tuple{4, 2});

                    cortex::box<int> b = { { 6, 23 }
                                         , { 45, 8 }
                                         , { 115, 255 }
                                         , { 13, 4 } };

                    REQUIRE(b.size() == 8);
                    REQUIRE(b.dimensions() == std::tuple{4, 2});

                    REQUIRE_THROWS_AS(a <<= b, std::invalid_argument);
                    b <<= a;

                    REQUIRE(b.size() == 8);
                    REQUIRE(b.dimensions() == std::tuple{4, 2});
                    REQUIRE(b == cortex::box<int> { { 12, 92 }
                                                  , { 360, 128 }
                                                  , { 3680, 16320 }
                                                  , { 1664, 1024 } });
                }
            }
        }

        SECTION("Scalar Left Bit Shift")
        {
            SECTION("Left Bit Shift")
            {
                SECTION("Same Type")
                {
                    cortex::box<int> a = { { 1, 2, 3 }
                                         , { 4, 5, 6 } };

                    REQUIRE(a.size() == 6);
                    REQUIRE(a.dimensions() == std::tuple{2, 3});

                    auto b { a << 5 };

                    REQUIRE(b.size() == 6);
                    REQUIRE(b.dimensions() == std::tuple{2, 3});
                    REQUIRE(b == cortex::box<int> { { 32, 64, 96 }
                                                  , { 128, 160, 192 } });
                }
            }

            SECTION("Left Bit Shift Assign")
            {
                SECTION("Same Type")
                {
                    cortex::box<int> a = { { 1, 2, 3 }
                                         , { 4, 5, 6 } };

                    REQUIRE(a.size() == 6);
                    REQUIRE(a.dimensions() == std::tuple{2, 3});

                    a <<= 5;
                    
                    REQUIRE(a.size() == 6);
                    REQUIRE(a.dimensions() == std::tuple{2, 3});
                    REQUIRE(a == cortex::box<int> { { 32, 64, 96 }
                                                  , { 128, 160, 192 } });
                }
            }
        }
    }

    SECTION("Right Bit Shift and Right Bit Shift Assign")
    {
        SECTION("Box Right Bit Shift")
        {
            SECTION("Right Bit Shift")
            {
                SECTION("Same Type")
                {
                    cortex::box<int> a = { { 1, 2, 3 }
                                         , { 4, 5, 6 } };

                    REQUIRE(a.size() == 6);
                    REQUIRE(a.dimensions() == std::tuple{2, 3});

                    cortex::box<int> b = { { 5, 113, 13 }
                                         , { 243, -42, 114 } };

                    REQUIRE(b.size() == 6);
                    REQUIRE(b.dimensions() == std::tuple{2, 3});

                    auto c { a >> b };

                    REQUIRE(c.size() == 6);
                    REQUIRE(c.dimensions() == std::tuple{2, 3});
                    REQUIRE(c == cortex::box<int> { { 0, 0, 0 }
                                                  , { 0, 0, 0 } });
                }

                SECTION("Different Type")
                {
                    cortex::box<int> a = { { 1, 2 }
                                         , { 3, 4 }
                                         , { 5, 6 }
                                         , { 7, 8 } };

                    REQUIRE(a.size() == 8);
                    REQUIRE(a.dimensions() == std::tuple{4, 2});

                    cortex::box<short> b = { { 6, 23 }
                                           , { 45, 8 }
                                           , { 115, 255 }
                                           , { 13, 4 } };

                    REQUIRE(b.size() == 8);
                    REQUIRE(b.dimensions() == std::tuple{4, 2});

                    auto c { a >> b };

                    REQUIRE(c.size() == 8);
                    REQUIRE(c.dimensions() == std::tuple{4, 2});
                    REQUIRE(c == cortex::box<short> { { 0, 0 }
                                                    , { 0, 0 }
                                                    , { 0, 0 }
                                                    , { 0, 0 } });
                }

                SECTION("Self Right Bit Shift")
                {
                    cortex::box<int> a = { { 1, 2 }
                                         , { 3, 4 }
                                         , { 5, 6 }
                                         , { 7, 8 } };

                    REQUIRE(a.size() == 8);
                    REQUIRE(a.dimensions() == std::tuple{4, 2});

                    auto c { a >> a };

                    REQUIRE(c.size() == 8);
                    REQUIRE(c.dimensions() == std::tuple{4, 2});
                    REQUIRE(c == cortex::box<int> { { 0, 0 }
                                                  , { 0, 0 }
                                                  , { 0, 0 }
                                                  , { 0, 0 } });
                }
            }

            SECTION("Right Bit Shift Assign") 
            {
                SECTION("Same Type")
                {
                    cortex::box<int> a = { { 1, 2, 3 }
                                         , { 4, 5, 6 } };

                    REQUIRE(a.size() == 6);
                    REQUIRE(a.dimensions() == std::tuple{2, 3});

                    cortex::box<int> b = { { 5, 113, 13 }
                                         , { 243, -42, 114 } };

                    REQUIRE(b.size() == 6);
                    REQUIRE(b.dimensions() == std::tuple{2, 3});

                    a >>= b;

                    REQUIRE(a.size() == 6);
                    REQUIRE(a.dimensions() == std::tuple{2, 3});
                    REQUIRE(a == cortex::box<int> { { 0, 0, 0 }
                                                  , { 0, 0, 0 } });
                }

                SECTION("Different Type")
                {
                    cortex::box<short> a = { { 1, 2 }
                                           , { 3, 4 }
                                           , { 5, 6 }
                                           , { 7, 8 } };

                    REQUIRE(a.size() == 8);
                    REQUIRE(a.dimensions() == std::tuple{4, 2});

                    cortex::box<int> b = { { 6, 23 }
                                         , { 45, 8 }
                                         , { 115, 255 }
                                         , { 13, 4 } };

                    REQUIRE(b.size() == 8);
                    REQUIRE(b.dimensions() == std::tuple{4, 2});

                    REQUIRE_THROWS_AS(a >>= b, std::invalid_argument);
                    b >>= a;

                    REQUIRE(b.size() == 8);
                    REQUIRE(b.dimensions() == std::tuple{4, 2});
                    REQUIRE(b == cortex::box<int> { { 3, 5 }
                                                  , { 5, 0 }
                                                  , { 3, 3 }
                                                  , { 0, 0 } });
                }
            }
        }

        SECTION("Scalar Right Bit Shift")
        {
            SECTION("Right Bit Shift")
            {
                SECTION("Same Type")
                {
                    cortex::box<int> a = { { 1, 2, 3 }
                                         , { 4, 5, 6 } };

                    REQUIRE(a.size() == 6);
                    REQUIRE(a.dimensions() == std::tuple{2, 3});

                    auto b { a >> 5 };

                    REQUIRE(b.size() == 6);
                    REQUIRE(b.dimensions() == std::tuple{2, 3});
                    REQUIRE(b == cortex::box<int> { { 0, 0, 0 }
                                                  , { 0, 0, 0 } });
                }
            }

            SECTION("Right Bit Shift Assign")
            {
                SECTION("Same Type")
                {
                    cortex::box<int> a = { { 1, 2, 3 }
                                         , { 4, 5, 6 } };

                    REQUIRE(a.size() == 6);
                    REQUIRE(a.dimensions() == std::tuple{2, 3});

                    a >>= 5;
                    
                    REQUIRE(a.size() == 6);
                    REQUIRE(a.dimensions() == std::tuple{2, 3});
                    REQUIRE(a == cortex::box<int> { { 0, 0, 0 }
                                                  , { 0, 0, 0 } });
                }
            }
        }
    }

    SECTION("Bit Not")
    {
        cortex::box<int> a = { { 1, 2 }
                             , { 3, 4 }
                             , { 5, 6 }
                             , { 7, 8 } };

        REQUIRE(a.size() == 8);
        REQUIRE(a.dimensions() == std::tuple{4, 2});

        auto b { ~a };

        REQUIRE(b.size() == 8);
        REQUIRE(b.dimensions() == std::tuple{4, 2});
        REQUIRE(b == cortex::box<int> { { -2, -3 }
                                      , { -4, -5 }
                                      , { -6, -7 }
                                      , { -8, -9 } });
    }
}

TEST_CASE("Utility Operators")
{
    SECTION("Transpose")
    {
        cortex::box<int> a = { { 1, 2 }
                             , { 3, 4 }
                             , { 5, 6 }
                             , { 7, 8 } };

        REQUIRE(a.size() == 8);
        REQUIRE(a.dimensions() == std::tuple{4, 2});

        auto b { !a };

        REQUIRE(b.size() == 8);
        REQUIRE(b.dimensions() == std::tuple{2, 4});
        REQUIRE(b == cortex::box<int> { { 1, 3, 5, 7 }
                                      , { 2, 4, 6, 8 } });
    }
}