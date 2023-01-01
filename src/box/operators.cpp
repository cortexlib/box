// #include <catch2/catch.hpp>
// #include <box.hpp>

// TEST_CASE("Arithmatic Operators")
// {
//     SECTION("Add and Add Assign")
//     {
//         SECTION("Add")
//         {
//             SECTION("Same Type")
//             {
//                 cxl::box<int> a = { { 1, 2, 3 }
//                                      , { 4, 5, 6 } };

//                 REQUIRE(a.size() == 6);
//                 REQUIRE(a.dimensions() == std::tuple{2, 3});

//                 cxl::box<int> b = { { 7, 8, 9 }
//                                      , { 10, 11, 12 } };

//                 REQUIRE(b.size() == 6);
//                 REQUIRE(b.dimensions() == std::tuple{2, 3});

//                 auto c { a + b };

//                 REQUIRE(c.size() == 6);
//                 REQUIRE(c.dimensions() == std::tuple{2, 3});
//                 REQUIRE(c == cxl::box<int> { { 8, 10, 12 }
//                                               , { 14, 16, 18 } });
//             }
        

//             SECTION("Different Types")
//             {
//                     cxl::box<int> a = { { 1, 2 }
//                                          , { 3, 4 }
//                                          , { 5, 6 }
//                                          , { 7, 8 } };

//                     REQUIRE(a.size() == 8);
//                     REQUIRE(a.dimensions() == std::tuple{4, 2});

//                     cxl::box<double> b = { { 6, 23 }
//                                             , { 4.52, 8.75 }
//                                             , { 1.12, 435 }
//                                             , { 13.4221, 0.4234 } };

//                     REQUIRE(b.size() == 8);
//                     REQUIRE(b.dimensions() == std::tuple{4, 2});

//                     auto c { a + b };

//                     REQUIRE(c.size() == 8);
//                     REQUIRE(c.dimensions() == std::tuple{4, 2});
//                     REQUIRE(c == cxl::box<double> { { 7.0, 25.0 }
//                                                      , { 7.52, 12.75 }
//                                                      , { 6.12, 441.0 }
//                                                      , { 20.4221, 8.4234 } });
//             }

//             SECTION("Self Add")
//             {
//                     cxl::box<int> a = { { 1, 2 }
//                                          , { 3, 4 }
//                                          , { 5, 6 }
//                                          , { 7, 8 } };

//                     REQUIRE(a.size() == 8);
//                     REQUIRE(a.dimensions() == std::tuple{4, 2});

//                     auto c { a + a };

//                     REQUIRE(c.size() == 8);
//                     REQUIRE(c.dimensions() == std::tuple{4, 2});
//                     REQUIRE(c == cxl::box<int> { { 2, 4 }
//                                                   , { 6, 8 }
//                                                   , { 10, 12 }
//                                                   , { 14, 16 } });
//             }
//         }

//         SECTION("Add Assign")
//         {
//             SECTION("Same Type")
//             {
//                 cxl::box<int> a = { { 1, 2, 3 }
//                                      , { 4, 5, 6 } };

//                 REQUIRE(a.size() == 6);
//                 REQUIRE(a.dimensions() == std::tuple{2, 3});

//                 cxl::box<int> b = { { 7, 8, 9 }
//                                      , { 10, 11, 12 } };

//                 REQUIRE(b.size() == 6);
//                 REQUIRE(b.dimensions() == std::tuple{2, 3});

//                 a += b;

//                 REQUIRE(a.size() == 6);
//                 REQUIRE(a.dimensions() == std::tuple{2, 3});
//                 REQUIRE(a == cxl::box<int> { { 8, 10, 12 }
//                                               , { 14, 16, 18 } });
//             }
        

//             SECTION("Different Types")
//             {
//                     cxl::box<int> a = { { 1, 2 }
//                                          , { 3, 4 }
//                                          , { 5, 6 }
//                                          , { 7, 8 } };

//                     REQUIRE(a.size() == 8);
//                     REQUIRE(a.dimensions() == std::tuple{4, 2});

//                     cxl::box<double> b = { { 6, 23 }
//                                             , { 4.52, 8.75 }
//                                             , { 1.12, 435 }
//                                             , { 13.4221, 0.4234 } };

//                     REQUIRE(b.size() == 8);
//                     REQUIRE(b.dimensions() == std::tuple{4, 2});

//                     REQUIRE_THROWS_AS(a += b, std::invalid_argument);
//                     b += a;

//                     REQUIRE(b.size() == 8);
//                     REQUIRE(b.dimensions() == std::tuple{4, 2});
//                     REQUIRE(b == cxl::box<double> { { 7.0, 25.0 }
//                                                      , { 7.52, 12.75 }
//                                                      , { 6.12, 441.0 }
//                                                      , { 20.4221, 8.4234 } });
//             }

//             SECTION("Self Add")
//             {
//                     cxl::box<int> a = { { 1, 2 }
//                                          , { 3, 4 }
//                                          , { 5, 6 }
//                                          , { 7, 8 } };

//                     REQUIRE(a.size() == 8);
//                     REQUIRE(a.dimensions() == std::tuple{4, 2});

//                     a += a;

//                     REQUIRE(a.size() == 8);
//                     REQUIRE(a.dimensions() == std::tuple{4, 2});
//                     REQUIRE(a == cxl::box<int> { { 2, 4 }
//                                                   , { 6, 8 }
//                                                   , { 10, 12 }
//                                                   , { 14, 16 } });
//             }
//         }
//     }

//     SECTION("Minus and Minus Assign")
//     {
//         SECTION("Minus")
//         {
//             SECTION("Same Type")
//             {
//                 cxl::box<int> a = { { 1, 2, 3 }
//                                      , { 4, 5, 6 } };

//                 REQUIRE(a.size() == 6);
//                 REQUIRE(a.dimensions() == std::tuple{2, 3});

//                 cxl::box<int> b = { { 5, 113, 13 }
//                                      , { 243, -42, 114 } };

//                 REQUIRE(b.size() == 6);
//                 REQUIRE(b.dimensions() == std::tuple{2, 3});

//                 auto c { a - b };

//                 REQUIRE(c.size() == 6);
//                 REQUIRE(c.dimensions() == std::tuple{2, 3});
//                 REQUIRE(c == cxl::box<int> { { -4, -111, -10 }
//                                               , { -239, 47, -108 } });
//             }
        

//             SECTION("Different Types")
//             {
//                     cxl::box<int> a = { { 1, 2 }
//                                          , { 3, 4 }
//                                          , { 5, 6 }
//                                          , { 7, 8 } };

//                     REQUIRE(a.size() == 8);
//                     REQUIRE(a.dimensions() == std::tuple{4, 2});

//                     cxl::box<double> b = { { 6, 23 }
//                                             , { 4.5, 8.75 }
//                                             , { 1.15, 435 }
//                                             , { 13.4, 0.4 } };

//                     REQUIRE(b.size() == 8);
//                     REQUIRE(b.dimensions() == std::tuple{4, 2});

//                     auto c { a - b };

//                     REQUIRE(c.size() == 8);
//                     REQUIRE(c.dimensions() == std::tuple{4, 2});
//                     REQUIRE(c == cxl::box<double> { { -5.0, -21.0 }
//                                                      , { -1.5, -4.75 }
//                                                      , { 3.85, -429.0 }
//                                                      , { -6.4, 7.6 } });
//             }

//             SECTION("Self Minus")
//             {
//                     cxl::box<int> a = { { 1, 2 }
//                                          , { 3, 4 }
//                                          , { 5, 6 }
//                                          , { 7, 8 } };

//                     REQUIRE(a.size() == 8);
//                     REQUIRE(a.dimensions() == std::tuple{4, 2});

//                     auto c { a - a };

//                     REQUIRE(c.size() == 8);
//                     REQUIRE(c.dimensions() == std::tuple{4, 2});
//                     REQUIRE(c == cxl::box<int> { { 0, 0 }
//                                                   , { 0, 0 }
//                                                   , { 0, 0}
//                                                   , { 0, 0 } });
//             }
//         }

//         SECTION("Minus Assign")
//         {
//             SECTION("Same Type")
//             {
//                 cxl::box<int> a = { { 1, 2, 3 }
//                                      , { 4, 5, 6 } };

//                 REQUIRE(a.size() == 6);
//                 REQUIRE(a.dimensions() == std::tuple{2, 3});

//                 cxl::box<int> b = { { 25, 14, 2 }
//                                      , { -14, -2453, 12 } };

//                 REQUIRE(b.size() == 6);
//                 REQUIRE(b.dimensions() == std::tuple{2, 3});

//                 a -= b;

//                 REQUIRE(a.size() == 6);
//                 REQUIRE(a.dimensions() == std::tuple{2, 3});
//                 REQUIRE(a == cxl::box<int> { { -24, -12, 1 }
//                                               , { 18, 2458, -6 } });
//             }
        

//             SECTION("Different Types")
//             {
//                     cxl::box<int> a = { { 1, 2 }
//                                          , { 3, 4 }
//                                          , { 5, 6 }
//                                          , { 7, 8 } };

//                     REQUIRE(a.size() == 8);
//                     REQUIRE(a.dimensions() == std::tuple{4, 2});

//                     cxl::box<double> b = { { 6, 23 }
//                                             , { 4.5, 8.75 }
//                                             , { 1.15, 435 }
//                                             , { 13.5, 0.4 } };

//                     REQUIRE(b.size() == 8);
//                     REQUIRE(b.dimensions() == std::tuple{4, 2});

//                     REQUIRE_THROWS_AS(a -= b, std::invalid_argument);
//                     b -= a;

//                     REQUIRE(b.size() == 8);
//                     REQUIRE(b.dimensions() == std::tuple{4, 2});
//                     REQUIRE(b == cxl::box<double> { { 5.0, 21.0 }
//                                                      , { 1.5, 4.75 }
//                                                      , { -3.85, 429.0 }
//                                                      , { 6.5, -7.6 } });
//             }

//             SECTION("Self Minus")
//             {
//                     cxl::box<int> a = { { 1, 2 }
//                                          , { 3, 4 }
//                                          , { 5, 6 }
//                                          , { 7, 8 } };

//                     REQUIRE(a.size() == 8);
//                     REQUIRE(a.dimensions() == std::tuple{4, 2});

//                     a -= a;

//                     REQUIRE(a.size() == 8);
//                     REQUIRE(a.dimensions() == std::tuple{4, 2});
//                     REQUIRE(a == cxl::box<int> { { 0, 0 }
//                                                   , { 0, 0 }
//                                                   , { 0, 0 }
//                                                   , { 0, 0 } });
//             }
//         }
//     }

//     SECTION("Multiply and Multiply Assign")
//     {
//         SECTION("Box Multiply")
//         {
//             SECTION("Multiply")
//             {
//                 SECTION("Same Type")
//                 {
//                     cxl::box<int> a = { { 1, 2, 3 }
//                                          , { 4, 5, 6 } };

//                     REQUIRE(a.size() == 6);
//                     REQUIRE(a.dimensions() == std::tuple{2, 3});

//                     cxl::box<int> b = { { 5, 113, 13 }
//                                          , { 243, -42, 114 } };

//                     REQUIRE(b.size() == 6);
//                     REQUIRE(b.dimensions() == std::tuple{2, 3});

//                     auto c { a * b };

//                     REQUIRE(c.size() == 6);
//                     REQUIRE(c.dimensions() == std::tuple{2, 3});
//                     REQUIRE(c == cxl::box<int> { { 5, 226, 39 }
//                                                   , { 972, -210, 684 } });
//                 }

//                 SECTION("Different Type")
//                 {
//                     cxl::box<int> a = { { 1, 2 }
//                                          , { 3, 4 }
//                                          , { 5, 6 }
//                                          , { 7, 8 } };

//                     REQUIRE(a.size() == 8);
//                     REQUIRE(a.dimensions() == std::tuple{4, 2});

//                     cxl::box<double> b = { { 6, 23 }
//                                             , { 4.5, 8.75 }
//                                             , { 1.15, 435 }
//                                             , { 13.4, 0.4 } };

//                     REQUIRE(b.size() == 8);
//                     REQUIRE(b.dimensions() == std::tuple{4, 2});

//                     auto c { a * b };

//                     REQUIRE(c.size() == 8);
//                     REQUIRE(c.dimensions() == std::tuple{4, 2});
//                     REQUIRE(c == cxl::box<double> { { 6, 46 }
//                                                      , { 13.5, 35 }
//                                                      , { 5.75, 2610 }
//                                                      , { 93.8, 3.2 } });
//                 }

//                 SECTION("Self Multiply")
//                 {
//                     cxl::box<int> a = { { 1, 2 }
//                                          , { 3, 4 }
//                                          , { 5, 6 }
//                                          , { 7, 8 } };

//                     REQUIRE(a.size() == 8);
//                     REQUIRE(a.dimensions() == std::tuple{4, 2});

//                     auto c { a * a };

//                     REQUIRE(c.size() == 8);
//                     REQUIRE(c.dimensions() == std::tuple{4, 2});
//                     REQUIRE(c == cxl::box<int> { { 1, 4 }
//                                                   , { 9, 16 }
//                                                   , { 25, 36 }
//                                                   , { 49, 64 } });
//                 }
//             }

//             SECTION("Multiply Assign") 
//             {
//                 SECTION("Same Type")
//                 {
//                     cxl::box<int> a = { { 1, 2, 3 }
//                                          , { 4, 5, 6 } };

//                     REQUIRE(a.size() == 6);
//                     REQUIRE(a.dimensions() == std::tuple{2, 3});

//                     cxl::box<int> b = { { 5, 113, 13 }
//                                          , { 243, -42, 114 } };

//                     REQUIRE(b.size() == 6);
//                     REQUIRE(b.dimensions() == std::tuple{2, 3});

//                     a *= b;

//                     REQUIRE(a.size() == 6);
//                     REQUIRE(a.dimensions() == std::tuple{2, 3});
//                     REQUIRE(a == cxl::box<int> { { 5, 226, 39 }
//                                                   , { 972, -210, 684 } });
//                 }

//                 SECTION("Different Type")
//                 {
//                     cxl::box<int> a = { { 1, 2 }
//                                          , { 3, 4 }
//                                          , { 5, 6 }
//                                          , { 7, 8 } };

//                     REQUIRE(a.size() == 8);
//                     REQUIRE(a.dimensions() == std::tuple{4, 2});

//                     cxl::box<double> b = { { 6, 23 }
//                                             , { 4.5, 8.75 }
//                                             , { 1.15, 435 }
//                                             , { 13.4, 0.4 } };

//                     REQUIRE(b.size() == 8);
//                     REQUIRE(b.dimensions() == std::tuple{4, 2});

//                     REQUIRE_THROWS_AS(a *= b, std::invalid_argument);
//                     b *= a;

//                     REQUIRE(b.size() == 8);
//                     REQUIRE(b.dimensions() == std::tuple{4, 2});
//                     REQUIRE(b == cxl::box<double> { { 6, 46 }
//                                                      , { 13.5, 35 }
//                                                      , { 5.75, 2610 }
//                                                      , { 93.8, 3.2 } });
//                 }
//             }
//         }

//         SECTION("Scalar Multiply")
//         {
//             SECTION("Multiply")
//             {
//                 SECTION("Same Type")
//                 {
//                     cxl::box<int> a = { { 1, 2, 3 }
//                                          , { 4, 5, 6 } };

//                     REQUIRE(a.size() == 6);
//                     REQUIRE(a.dimensions() == std::tuple{2, 3});

//                     auto b { a * 5 };
//                     auto c { 4 * a };

//                     REQUIRE(b.size() == 6);
//                     REQUIRE(b.dimensions() == std::tuple{2, 3});
//                     REQUIRE(b == cxl::box<int> { { 5, 10, 15 }
//                                                   , { 20, 25, 30 } });

//                     REQUIRE(c.size() == 6);
//                     REQUIRE(c.dimensions() == std::tuple{2, 3});
//                     REQUIRE(c == cxl::box<int> { { 4, 8, 12 }
//                                                   , { 16, 20, 24 } });
//                 }
//             }

//             SECTION("Multiply Assign")
//             {
//                 SECTION("Same Type")
//                 {
//                     cxl::box<int> a = { { 1, 2, 3 }
//                                          , { 4, 5, 6 } };

//                     REQUIRE(a.size() == 6);
//                     REQUIRE(a.dimensions() == std::tuple{2, 3});

//                     a *= 5;
                    
//                     REQUIRE(a.size() == 6);
//                     REQUIRE(a.dimensions() == std::tuple{2, 3});
//                     REQUIRE(a == cxl::box<int> { { 5, 10, 15 }
//                                                   , { 20, 25, 30 } });
//                 }
//             }
//         }
//     }

//     SECTION("Divide and Divide Assign")
//     {
//         SECTION("Box Divide")
//         {
//             SECTION("Divide")
//             {
//                 SECTION("Same Type")
//                 {
//                     cxl::box<int> a = { { 1, 2, 3 }
//                                          , { 4, 5, 6 } };

//                     REQUIRE(a.size() == 6);
//                     REQUIRE(a.dimensions() == std::tuple{2, 3});

//                     cxl::box<int> b = { { 5, 113, 13 }
//                                          , { 243, -42, 114 } };

//                     REQUIRE(b.size() == 6);
//                     REQUIRE(b.dimensions() == std::tuple{2, 3});

//                     auto c { a / b };

//                     REQUIRE(c.size() == 6);
//                     REQUIRE(c.dimensions() == std::tuple{2, 3});
//                     REQUIRE(c == cxl::box<int> { { 0, 0, 0 }
//                                                   , { 0, 0, 0 } });
//                 }

//                 SECTION("Different Type")
//                 {
//                     cxl::box<int> a = { { 1, 2 }
//                                          , { 3, 4 }
//                                          , { 5, 6 }
//                                          , { 7, 8 } };

//                     REQUIRE(a.size() == 8);
//                     REQUIRE(a.dimensions() == std::tuple{4, 2});

//                     cxl::box<short> b = { { 6, 2 }
//                                            , { 1, 8 }
//                                            , { 1, 5 }
//                                            , { 2, 4 } };

//                     REQUIRE(b.size() == 8);
//                     REQUIRE(b.dimensions() == std::tuple{4, 2});

//                     auto c { a / b };

//                     REQUIRE(c.size() == 8);
//                     REQUIRE(c.dimensions() == std::tuple{4, 2});
//                     REQUIRE(c == cxl::box<short> { { 0, 1 }
//                                                     , { 3, 0 }
//                                                     , { 5, 1 }
//                                                     , { 3, 2 } });
//                 }

//                 SECTION("Self Divide")
//                 {
//                     cxl::box<int> a = { { 1, 2 }
//                                          , { 3, 4 }
//                                          , { 5, 6 }
//                                          , { 7, 8 } };

//                     REQUIRE(a.size() == 8);
//                     REQUIRE(a.dimensions() == std::tuple{4, 2});

//                     auto c { a / a };

//                     REQUIRE(c.size() == 8);
//                     REQUIRE(c.dimensions() == std::tuple{4, 2});
//                     REQUIRE(c == cxl::box<int> { { 1, 1 }
//                                                   , { 1, 1 }
//                                                   , { 1, 1 }
//                                                   , { 1, 1 } });
//                 }
//             }

//             SECTION("Divide Assign") 
//             {
//                 SECTION("Same Type")
//                 {
//                     cxl::box<int> a = { { 1, 2, 3 }
//                                          , { 4, 5, 6 } };

//                     REQUIRE(a.size() == 6);
//                     REQUIRE(a.dimensions() == std::tuple{2, 3});

//                     cxl::box<int> b = { { 5, 113, 13 }
//                                          , { 243, -42, 114 } };

//                     REQUIRE(b.size() == 6);
//                     REQUIRE(b.dimensions() == std::tuple{2, 3});

//                     a /= b;

//                     REQUIRE(a.size() == 6);
//                     REQUIRE(a.dimensions() == std::tuple{2, 3});
//                     REQUIRE(a == cxl::box<int> { { 0, 0, 0 }
//                                                   , { 0, 0, 0 } });
//                 }

//                 SECTION("Different Type")
//                 {
//                     cxl::box<short> a = { { 1, 2 }
//                                            , { 3, 4 }
//                                            , { 5, 6 }
//                                            , { 7, 8 } };

//                     REQUIRE(a.size() == 8);
//                     REQUIRE(a.dimensions() == std::tuple{4, 2});

//                     cxl::box<int> b = { { 6, 23 }
//                                          , { 45, 8 }
//                                          , { 115, 255 }
//                                          , { 13, 4 } };

//                     REQUIRE(b.size() == 8);
//                     REQUIRE(b.dimensions() == std::tuple{4, 2});

//                     REQUIRE_THROWS_AS(a /= b, std::invalid_argument);
//                     b /= a;

//                     REQUIRE(b.size() == 8);
//                     REQUIRE(b.dimensions() == std::tuple{4, 2});
//                     REQUIRE(b == cxl::box<int> { { 6, 11 }
//                                                   , { 15, 2 }
//                                                   , { 23, 42 }
//                                                   , { 1, 0 } });
//                 }
//             }
//         }

//         SECTION("Scalar Divide")
//         {
//             SECTION("Divide")
//             {
//                 SECTION("Same Type")
//                 {
//                     cxl::box<int> a = { { 1, 2, 3 }
//                                          , { 4, 5, 6 } };

//                     REQUIRE(a.size() == 6);
//                     REQUIRE(a.dimensions() == std::tuple{2, 3});

//                     auto b { a / 5 };

//                     REQUIRE(b.size() == 6);
//                     REQUIRE(b.dimensions() == std::tuple{2, 3});
//                     REQUIRE(b == cxl::box<int> { { 0, 0, 0 }
//                                                   , { 0, 1, 1 } });
//                 }
//             }

//             SECTION("Divide Assign")
//             {
//                 SECTION("Same Type")
//                 {
//                     cxl::box<int> a = { { 1, 2, 3 }
//                                          , { 4, 5, 6 } };

//                     REQUIRE(a.size() == 6);
//                     REQUIRE(a.dimensions() == std::tuple{2, 3});

//                     a /= 5;
                    
//                     REQUIRE(a.size() == 6);
//                     REQUIRE(a.dimensions() == std::tuple{2, 3});
//                     REQUIRE(a == cxl::box<int> { { 0, 0, 0 }
//                                                   , { 0, 1, 1 } });
//                 }
//             }
//         }
//     }

//     SECTION("Modulo and Modulo Assign")
//     {
//         SECTION("Box Modulo")
//         {
//             SECTION("Modulo")
//             {
//                 SECTION("Same Type")
//                 {
//                     cxl::box<int> a = { { 1, 2, 3 }
//                                          , { 4, 5, 6 } };

//                     REQUIRE(a.size() == 6);
//                     REQUIRE(a.dimensions() == std::tuple{2, 3});

//                     cxl::box<int> b = { { 5, 113, 13 }
//                                          , { 243, -42, 114 } };

//                     REQUIRE(b.size() == 6);
//                     REQUIRE(b.dimensions() == std::tuple{2, 3});

//                     auto c { a % b };

//                     REQUIRE(c.size() == 6);
//                     REQUIRE(c.dimensions() == std::tuple{2, 3});
//                     REQUIRE(c == cxl::box<int> { { 1, 2, 3 }
//                                                   , { 4, 5, 6 } });
//                 }

//                 SECTION("Different Type")
//                 {
//                     cxl::box<int> a = { { 1, 2 }
//                                          , { 3, 4 }
//                                          , { 5, 6 }
//                                          , { 7, 8 } };

//                     REQUIRE(a.size() == 8);
//                     REQUIRE(a.dimensions() == std::tuple{4, 2});

//                     cxl::box<short> b = { { 6, 23 }
//                                            , { 45, 8 }
//                                            , { 115, 255 }
//                                            , { 13, 4 } };

//                     REQUIRE(b.size() == 8);
//                     REQUIRE(b.dimensions() == std::tuple{4, 2});

//                     auto c { a % b };

//                     REQUIRE(c.size() == 8);
//                     REQUIRE(c.dimensions() == std::tuple{4, 2});
//                     REQUIRE(c == cxl::box<short> { { 1, 2 }
//                                                     , { 3, 4 }
//                                                     , { 5, 6 }
//                                                     , { 7, 0 } });
//                 }

//                 SECTION("Self Modulo")
//                 {
//                     cxl::box<int> a = { { 1, 2 }
//                                          , { 3, 4 }
//                                          , { 5, 6 }
//                                          , { 7, 8 } };

//                     REQUIRE(a.size() == 8);
//                     REQUIRE(a.dimensions() == std::tuple{4, 2});

//                     auto c { a % a };

//                     REQUIRE(c.size() == 8);
//                     REQUIRE(c.dimensions() == std::tuple{4, 2});
//                     REQUIRE(c == cxl::box<int> { { 0, 0 }
//                                                   , { 0, 0 }
//                                                   , { 0, 0 }
//                                                   , { 0, 0 } });
//                 }
//             }

//             SECTION("Modulo Assign") 
//             {
//                 SECTION("Same Type")
//                 {
//                     cxl::box<int> a = { { 1, 2, 3 }
//                                          , { 4, 5, 6 } };

//                     REQUIRE(a.size() == 6);
//                     REQUIRE(a.dimensions() == std::tuple{2, 3});

//                     cxl::box<int> b = { { 5, 113, 13 }
//                                          , { 243, -42, 114 } };

//                     REQUIRE(b.size() == 6);
//                     REQUIRE(b.dimensions() == std::tuple{2, 3});

//                     a %= b;

//                     REQUIRE(a.size() == 6);
//                     REQUIRE(a.dimensions() == std::tuple{2, 3});
//                     REQUIRE(a == cxl::box<int> { { 1, 2, 3 }
//                                                   , { 4, 5, 6 } });
//                 }

//                 SECTION("Different Type")
//                 {
//                     cxl::box<short> a = { { 1, 2 }
//                                            , { 3, 4 }
//                                            , { 5, 6 }
//                                            , { 7, 8 } };

//                     REQUIRE(a.size() == 8);
//                     REQUIRE(a.dimensions() == std::tuple{4, 2});

//                     cxl::box<int> b = { { 6, 23 }
//                                          , { 45, 8 }
//                                          , { 115, 255 }
//                                          , { 13, 4 } };

//                     REQUIRE(b.size() == 8);
//                     REQUIRE(b.dimensions() == std::tuple{4, 2});

//                     REQUIRE_THROWS_AS(a %= b, std::invalid_argument);
//                     b %= a;

//                     REQUIRE(b.size() == 8);
//                     REQUIRE(b.dimensions() == std::tuple{4, 2});
//                     REQUIRE(b == cxl::box<int> { { 0, 1 }
//                                                   , { 0, 0 }
//                                                   , { 0, 3 }
//                                                   , { 6, 4 } });
//                 }
//             }
//         }

//         SECTION("Scalar Modulo")
//         {
//             SECTION("Modulo")
//             {
//                 SECTION("Same Type")
//                 {
//                     cxl::box<int> a = { { 1, 2, 3 }
//                                          , { 4, 5, 6 } };

//                     REQUIRE(a.size() == 6);
//                     REQUIRE(a.dimensions() == std::tuple{2, 3});

//                     auto b { a % 5 };

//                     REQUIRE(b.size() == 6);
//                     REQUIRE(b.dimensions() == std::tuple{2, 3});
//                     REQUIRE(b == cxl::box<int> { { 1, 2, 3 }
//                                                   , { 4, 0, 1 } });
//                 }
//             }

//             SECTION("Modulo Assign")
//             {
//                 SECTION("Same Type")
//                 {
//                     cxl::box<int> a = { { 1, 2, 3 }
//                                          , { 4, 5, 6 } };

//                     REQUIRE(a.size() == 6);
//                     REQUIRE(a.dimensions() == std::tuple{2, 3});

//                     a %= 5;
                    
//                     REQUIRE(a.size() == 6);
//                     REQUIRE(a.dimensions() == std::tuple{2, 3});
//                     REQUIRE(a == cxl::box<int> { { 1, 2, 3 }
//                                                   , { 4, 0, 1 } });
//                 }
//             }
//         }
//     }
// }

// TEST_CASE("Bit Operators")
// {
//     SECTION("Bit And and Bit And Assign")
//     {
//         SECTION("Box Bit And")
//         {
//             SECTION("Bit And")
//             {
//                 SECTION("Same Type")
//                 {
//                     cxl::box<int> a = { { 1, 2, 3 }
//                                          , { 4, 5, 6 } };

//                     REQUIRE(a.size() == 6);
//                     REQUIRE(a.dimensions() == std::tuple{2, 3});

//                     cxl::box<int> b = { { 5, 113, 13 }
//                                          , { 243, -42, 114 } };

//                     REQUIRE(b.size() == 6);
//                     REQUIRE(b.dimensions() == std::tuple{2, 3});

//                     auto c { a & b };

//                     REQUIRE(c.size() == 6);
//                     REQUIRE(c.dimensions() == std::tuple{2, 3});
//                     REQUIRE(c == cxl::box<int> { { 1, 0, 1 }
//                                                   , { 0, 4, 2 } });
//                 }

//                 SECTION("Different Type")
//                 {
//                     cxl::box<int> a = { { 1, 2 }
//                                          , { 3, 4 }
//                                          , { 5, 6 }
//                                          , { 7, 8 } };

//                     REQUIRE(a.size() == 8);
//                     REQUIRE(a.dimensions() == std::tuple{4, 2});

//                     cxl::box<short> b = { { 6, 23 }
//                                            , { 45, 8 }
//                                            , { 115, 255 }
//                                            , { 13, 4 } };

//                     REQUIRE(b.size() == 8);
//                     REQUIRE(b.dimensions() == std::tuple{4, 2});

//                     auto c { a & b };

//                     REQUIRE(c.size() == 8);
//                     REQUIRE(c.dimensions() == std::tuple{4, 2});
//                     REQUIRE(c == cxl::box<short> { { 0, 2 }
//                                                     , { 1, 0 }
//                                                     , { 1, 6 }
//                                                     , { 5, 0 } });
//                 }

//                 SECTION("Self Bit And")
//                 {
//                     cxl::box<int> a = { { 1, 2 }
//                                          , { 3, 4 }
//                                          , { 5, 6 }
//                                          , { 7, 8 } };

//                     REQUIRE(a.size() == 8);
//                     REQUIRE(a.dimensions() == std::tuple{4, 2});

//                     auto c { a & a };

//                     REQUIRE(c.size() == 8);
//                     REQUIRE(c.dimensions() == std::tuple{4, 2});
//                     REQUIRE(c == cxl::box<int> { { 1, 2 }
//                                                   , { 3, 4 }
//                                                   , { 5, 6 }
//                                                   , { 7, 8 } });
//                 }
//             }

//             SECTION("Bit And Assign") 
//             {
//                 SECTION("Same Type")
//                 {
//                     cxl::box<int> a = { { 1, 2, 3 }
//                                          , { 4, 5, 6 } };

//                     REQUIRE(a.size() == 6);
//                     REQUIRE(a.dimensions() == std::tuple{2, 3});

//                     cxl::box<int> b = { { 5, 113, 13 }
//                                          , { 243, -42, 114 } };

//                     REQUIRE(b.size() == 6);
//                     REQUIRE(b.dimensions() == std::tuple{2, 3});

//                     a &= b;

//                     REQUIRE(a.size() == 6);
//                     REQUIRE(a.dimensions() == std::tuple{2, 3});
//                     REQUIRE(a == cxl::box<int> { { 1, 0, 1 }
//                                                   , { 0, 4, 2 } });
//                 }

//                 SECTION("Different Type")
//                 {
//                     cxl::box<short> a = { { 1, 2 }
//                                            , { 3, 4 }
//                                            , { 5, 6 }
//                                            , { 7, 8 } };

//                     REQUIRE(a.size() == 8);
//                     REQUIRE(a.dimensions() == std::tuple{4, 2});

//                     cxl::box<int> b = { { 6, 23 }
//                                          , { 45, 8 }
//                                          , { 115, 255 }
//                                          , { 13, 4 } };

//                     REQUIRE(b.size() == 8);
//                     REQUIRE(b.dimensions() == std::tuple{4, 2});

//                     REQUIRE_THROWS_AS(a &= b, std::invalid_argument);
//                     b &= a;

//                     REQUIRE(b.size() == 8);
//                     REQUIRE(b.dimensions() == std::tuple{4, 2});
//                     REQUIRE(b == cxl::box<int> { { 0, 2 }
//                                                   , { 1, 0 }
//                                                   , { 1, 6 }
//                                                   , { 5, 0 } });
//                 }
//             }
//         }

//         SECTION("Scalar Bit And")
//         {
//             SECTION("Bit And")
//             {
//                 SECTION("Same Type")
//                 {
//                     cxl::box<int> a = { { 1, 2, 3 }
//                                          , { 4, 5, 6 } };

//                     REQUIRE(a.size() == 6);
//                     REQUIRE(a.dimensions() == std::tuple{2, 3});

//                     auto b { a & 5 };
//                     auto c { 4 & a };

//                     REQUIRE(b.size() == 6);
//                     REQUIRE(b.dimensions() == std::tuple{2, 3});
//                     REQUIRE(b == cxl::box<int> { { 1, 0, 1 }
//                                                   , { 4, 5, 4 } });

//                     REQUIRE(c.size() == 6);
//                     REQUIRE(c.dimensions() == std::tuple{2, 3});
//                     REQUIRE(c == cxl::box<int> { { 0, 0, 0 }
//                                                   , { 4, 4, 4 } });
//                 }
//             }

//             SECTION("Bit And Assign")
//             {
//                 SECTION("Same Type")
//                 {
//                     cxl::box<int> a = { { 1, 2, 3 }
//                                          , { 4, 5, 6 } };

//                     REQUIRE(a.size() == 6);
//                     REQUIRE(a.dimensions() == std::tuple{2, 3});

//                     a &= 5;
                    
//                     REQUIRE(a.size() == 6);
//                     REQUIRE(a.dimensions() == std::tuple{2, 3});
//                     REQUIRE(a == cxl::box<int> { { 1, 0, 1 }
//                                                   , { 4, 5, 4 } });
//                 }
//             }
//         }
//     }

//     SECTION("Bit Or and Bit Or Assign")
//     {
//         SECTION("Box Bit Or")
//         {
//             SECTION("Bit Or")
//             {
//                 SECTION("Same Type")
//                 {
//                     cxl::box<int> a = { { 1, 2, 3 }
//                                          , { 4, 5, 6 } };

//                     REQUIRE(a.size() == 6);
//                     REQUIRE(a.dimensions() == std::tuple{2, 3});

//                     cxl::box<int> b = { { 5, 113, 13 }
//                                          , { 243, -42, 114 } };

//                     REQUIRE(b.size() == 6);
//                     REQUIRE(b.dimensions() == std::tuple{2, 3});

//                     auto c { a | b };

//                     REQUIRE(c.size() == 6);
//                     REQUIRE(c.dimensions() == std::tuple{2, 3});
//                     REQUIRE(c == cxl::box<int> { { 5, 115, 15 }
//                                                   , { 247, -41, 118 } });
//                 }

//                 SECTION("Different Type")
//                 {
//                     cxl::box<int> a = { { 1, 2 }
//                                          , { 3, 4 }
//                                          , { 5, 6 }
//                                          , { 7, 8 } };

//                     REQUIRE(a.size() == 8);
//                     REQUIRE(a.dimensions() == std::tuple{4, 2});

//                     cxl::box<short> b = { { 6, 23 }
//                                            , { 45, 8 }
//                                            , { 115, 255 }
//                                            , { 13, 4 } };

//                     REQUIRE(b.size() == 8);
//                     REQUIRE(b.dimensions() == std::tuple{4, 2});

//                     auto c { a | b };

//                     REQUIRE(c.size() == 8);
//                     REQUIRE(c.dimensions() == std::tuple{4, 2});
//                     REQUIRE(c == cxl::box<short> { { 7, 23 }
//                                                     , { 47, 12 }
//                                                     , { 119, 255 }
//                                                     , { 15, 12 } });
//                 }

//                 SECTION("Self Bit Or")
//                 {
//                     cxl::box<int> a = { { 1, 2 }
//                                          , { 3, 4 }
//                                          , { 5, 6 }
//                                          , { 7, 8 } };

//                     REQUIRE(a.size() == 8);
//                     REQUIRE(a.dimensions() == std::tuple{4, 2});

//                     auto c { a | a };

//                     REQUIRE(c.size() == 8);
//                     REQUIRE(c.dimensions() == std::tuple{4, 2});
//                     REQUIRE(c == cxl::box<int> { { 1, 2 }
//                                                   , { 3, 4 }
//                                                   , { 5, 6 }
//                                                   , { 7, 8 } });
//                 }
//             }

//             SECTION("Bit Or Assign") 
//             {
//                 SECTION("Same Type")
//                 {
//                     cxl::box<int> a = { { 1, 2, 3 }
//                                          , { 4, 5, 6 } };

//                     REQUIRE(a.size() == 6);
//                     REQUIRE(a.dimensions() == std::tuple{2, 3});

//                     cxl::box<int> b = { { 5, 113, 13 }
//                                          , { 243, -42, 114 } };

//                     REQUIRE(b.size() == 6);
//                     REQUIRE(b.dimensions() == std::tuple{2, 3});

//                     a |= b;

//                     REQUIRE(a.size() == 6);
//                     REQUIRE(a.dimensions() == std::tuple{2, 3});
//                     REQUIRE(a == cxl::box<int> { { 5, 115, 15 }
//                                                   , { 247, -41, 118 } });
//                 }

//                 SECTION("Different Type")
//                 {
//                     cxl::box<short> a = { { 1, 2 }
//                                            , { 3, 4 }
//                                            , { 5, 6 }
//                                            , { 7, 8 } };

//                     REQUIRE(a.size() == 8);
//                     REQUIRE(a.dimensions() == std::tuple{4, 2});

//                     cxl::box<int> b = { { 6, 23 }
//                                          , { 45, 8 }
//                                          , { 115, 255 }
//                                          , { 13, 4 } };

//                     REQUIRE(b.size() == 8);
//                     REQUIRE(b.dimensions() == std::tuple{4, 2});

//                     REQUIRE_THROWS_AS(a |= b, std::invalid_argument);
//                     b |= a;

//                     REQUIRE(b.size() == 8);
//                     REQUIRE(b.dimensions() == std::tuple{4, 2});
//                     REQUIRE(b == cxl::box<int> { { 7, 23 }
//                                                   , { 47, 12 }
//                                                   , { 119, 255 }
//                                                   , { 15, 12 } });
//                 }
//             }
//         }

//         SECTION("Scalar Bit Or")
//         {
//             SECTION("Bit Or")
//             {
//                 SECTION("Same Type")
//                 {
//                     cxl::box<int> a = { { 1, 2, 3 }
//                                          , { 4, 5, 6 } };

//                     REQUIRE(a.size() == 6);
//                     REQUIRE(a.dimensions() == std::tuple{2, 3});

//                     auto b { a | 5 };
//                     auto c { 4 | a };

//                     REQUIRE(b.size() == 6);
//                     REQUIRE(b.dimensions() == std::tuple{2, 3});
//                     REQUIRE(b == cxl::box<int> { { 5, 7, 7 }
//                                                   , { 5, 5, 7 } });

//                     REQUIRE(c.size() == 6);
//                     REQUIRE(c.dimensions() == std::tuple{2, 3});
//                     REQUIRE(c == cxl::box<int> { { 5, 6, 7 }
//                                                   , { 4, 5, 6 } });
//                 }
//             }

//             SECTION("Bit Or Assign")
//             {
//                 SECTION("Same Type")
//                 {
//                     cxl::box<int> a = { { 1, 2, 3 }
//                                          , { 4, 5, 6 } };

//                     REQUIRE(a.size() == 6);
//                     REQUIRE(a.dimensions() == std::tuple{2, 3});

//                     a |= 5;
                    
//                     REQUIRE(a.size() == 6);
//                     REQUIRE(a.dimensions() == std::tuple{2, 3});
//                     REQUIRE(a == cxl::box<int> { { 5, 7, 7 }
//                                                   , { 5, 5, 7 } });
//                 }
//             }
//         }
//     }

//     SECTION("Bit Xor and Bit Xor Assign")
//     {
//         SECTION("Box Bit Xor")
//         {
//             SECTION("Bit Xor")
//             {
//                 SECTION("Same Type")
//                 {
//                     cxl::box<int> a = { { 1, 2, 3 }
//                                          , { 4, 5, 6 } };

//                     REQUIRE(a.size() == 6);
//                     REQUIRE(a.dimensions() == std::tuple{2, 3});

//                     cxl::box<int> b = { { 5, 113, 13 }
//                                          , { 243, -42, 114 } };

//                     REQUIRE(b.size() == 6);
//                     REQUIRE(b.dimensions() == std::tuple{2, 3});

//                     auto c { a ^ b };

//                     REQUIRE(c.size() == 6);
//                     REQUIRE(c.dimensions() == std::tuple{2, 3});
//                     REQUIRE(c == cxl::box<int> { { 4, 115, 14 }
//                                                   , { 247, -45, 116 } });
//                 }

//                 SECTION("Different Type")
//                 {
//                     cxl::box<int> a = { { 1, 2 }
//                                          , { 3, 4 }
//                                          , { 5, 6 }
//                                          , { 7, 8 } };

//                     REQUIRE(a.size() == 8);
//                     REQUIRE(a.dimensions() == std::tuple{4, 2});

//                     cxl::box<short> b = { { 6, 23 }
//                                            , { 45, 8 }
//                                            , { 115, 255 }
//                                            , { 13, 4 } };

//                     REQUIRE(b.size() == 8);
//                     REQUIRE(b.dimensions() == std::tuple{4, 2});

//                     auto c { a ^ b };

//                     REQUIRE(c.size() == 8);
//                     REQUIRE(c.dimensions() == std::tuple{4, 2});
//                     REQUIRE(c == cxl::box<short> { { 7, 21 }
//                                                     , { 46, 12 }
//                                                     , { 118, 249 }
//                                                     , { 10, 12 } });
//                 }

//                 SECTION("Self Bit Xor")
//                 {
//                     cxl::box<int> a = { { 1, 2 }
//                                          , { 3, 4 }
//                                          , { 5, 6 }
//                                          , { 7, 8 } };

//                     REQUIRE(a.size() == 8);
//                     REQUIRE(a.dimensions() == std::tuple{4, 2});

//                     auto c { a ^ a };

//                     REQUIRE(c.size() == 8);
//                     REQUIRE(c.dimensions() == std::tuple{4, 2});
//                     REQUIRE(c == cxl::box<int> { { 0, 0 }
//                                                   , { 0, 0 }
//                                                   , { 0, 0 }
//                                                   , { 0, 0 } });
//                 }
//             }

//             SECTION("Bit Xor Assign") 
//             {
//                 SECTION("Same Type")
//                 {
//                     cxl::box<int> a = { { 1, 2, 3 }
//                                          , { 4, 5, 6 } };

//                     REQUIRE(a.size() == 6);
//                     REQUIRE(a.dimensions() == std::tuple{2, 3});

//                     cxl::box<int> b = { { 5, 113, 13 }
//                                          , { 243, -42, 114 } };

//                     REQUIRE(b.size() == 6);
//                     REQUIRE(b.dimensions() == std::tuple{2, 3});

//                     a ^= b;

//                     REQUIRE(a.size() == 6);
//                     REQUIRE(a.dimensions() == std::tuple{2, 3});
//                     REQUIRE(a == cxl::box<int> { { 4, 115, 14 }
//                                                   , { 247, -45, 116 } });
//                 }

//                 SECTION("Different Type")
//                 {
//                     cxl::box<short> a = { { 1, 2 }
//                                            , { 3, 4 }
//                                            , { 5, 6 }
//                                            , { 7, 8 } };

//                     REQUIRE(a.size() == 8);
//                     REQUIRE(a.dimensions() == std::tuple{4, 2});

//                     cxl::box<int> b = { { 6, 23 }
//                                          , { 45, 8 }
//                                          , { 115, 255 }
//                                          , { 13, 4 } };

//                     REQUIRE(b.size() == 8);
//                     REQUIRE(b.dimensions() == std::tuple{4, 2});

//                     REQUIRE_THROWS_AS(a ^= b, std::invalid_argument);
//                     b ^= a;

//                     REQUIRE(b.size() == 8);
//                     REQUIRE(b.dimensions() == std::tuple{4, 2});
//                     REQUIRE(b == cxl::box<int> { { 7, 21 }
//                                                   , { 46, 12 }
//                                                   , { 118, 249 }
//                                                   , { 10, 12 } });
//                 }
//             }
//         }

//         SECTION("Scalar Bit Xor")
//         {
//             SECTION("Bit Xor")
//             {
//                 SECTION("Same Type")
//                 {
//                     cxl::box<int> a = { { 1, 2, 3 }
//                                          , { 4, 5, 6 } };

//                     REQUIRE(a.size() == 6);
//                     REQUIRE(a.dimensions() == std::tuple{2, 3});

//                     auto b { a ^ 5 };
//                     auto c { 4 ^ a };

//                     REQUIRE(b.size() == 6);
//                     REQUIRE(b.dimensions() == std::tuple{2, 3});
//                     REQUIRE(b == cxl::box<int> { { 4, 7, 6 }
//                                                   , { 1, 0, 3 } });

//                     REQUIRE(c.size() == 6);
//                     REQUIRE(c.dimensions() == std::tuple{2, 3});
//                     REQUIRE(c == cxl::box<int> { { 5, 6, 7 }
//                                                   , { 0, 1, 2 } });
//                 }
//             }

//             SECTION("Bit Xor Assign")
//             {
//                 SECTION("Same Type")
//                 {
//                     cxl::box<int> a = { { 1, 2, 3 }
//                                          , { 4, 5, 6 } };

//                     REQUIRE(a.size() == 6);
//                     REQUIRE(a.dimensions() == std::tuple{2, 3});

//                     a ^= 5;
                    
//                     REQUIRE(a.size() == 6);
//                     REQUIRE(a.dimensions() == std::tuple{2, 3});
//                     REQUIRE(a == cxl::box<int> { { 4, 7, 6 }
//                                                   , { 1, 0, 3 } });
//                 }
//             }
//         }
//     }

//     SECTION("Left Bit Shift and Left Bit Shift Assign")
//     {
//         SECTION("Box Left Bit Shift")
//         {
//             SECTION("Left Bit Shift")
//             {
//                 SECTION("Same Type")
//                 {
//                     cxl::box<int> a = { { 1, 2, 3 }
//                                          , { 4, 5, 6 } };

//                     REQUIRE(a.size() == 6);
//                     REQUIRE(a.dimensions() == std::tuple{2, 3});

//                     cxl::box<int> b = { { 5, 113, 13 }
//                                          , { 243, -42, 114 } };

//                     REQUIRE(b.size() == 6);
//                     REQUIRE(b.dimensions() == std::tuple{2, 3});

//                     auto c { a << b };

//                     REQUIRE(c.size() == 6);
//                     REQUIRE(c.dimensions() == std::tuple{2, 3});
//                     REQUIRE(c == cxl::box<int> { { 32, 262144, 24576 }
//                                                   , { 2097152, 20971520, 1572864 } });
//                 }

//                 SECTION("Different Type")
//                 {
//                     cxl::box<int> a = { { 1, 2 }
//                                          , { 3, 4 }
//                                          , { 5, 6 }
//                                          , { 7, 8 } };

//                     REQUIRE(a.size() == 8);
//                     REQUIRE(a.dimensions() == std::tuple{4, 2});

//                     cxl::box<short> b = { { 6, 2 }
//                                            , { 1, 8 }
//                                            , { 1, 5 }
//                                            , { 2, 4 } };

//                     REQUIRE(b.size() == 8);
//                     REQUIRE(b.dimensions() == std::tuple{4, 2});

//                     auto c { a << b };

//                     REQUIRE(c.size() == 8);
//                     REQUIRE(c.dimensions() == std::tuple{4, 2});
//                     REQUIRE(c == cxl::box<short> { { 64, 8 }
//                                                     , { 6, 1024 }
//                                                     , { 10, 192 }
//                                                     , { 28, 128 } });
//                 }

//                 SECTION("Self Left Bit Shift")
//                 {
//                     cxl::box<int> a = { { 1, 2 }
//                                          , { 3, 4 }
//                                          , { 5, 6 }
//                                          , { 7, 8 } };

//                     REQUIRE(a.size() == 8);
//                     REQUIRE(a.dimensions() == std::tuple{4, 2});

//                     auto c { a << a };

//                     REQUIRE(c.size() == 8);
//                     REQUIRE(c.dimensions() == std::tuple{4, 2});
//                     REQUIRE(c == cxl::box<int> { { 2, 8 }
//                                                   , { 24, 64 }
//                                                   , { 160, 384 }
//                                                   , { 896, 2048 } });
//                 }
//             }

//             SECTION("Left Bit Shift Assign") 
//             {
//                 SECTION("Same Type")
//                 {
//                     cxl::box<int> a = { { 1, 2, 3 }
//                                          , { 4, 5, 6 } };

//                     REQUIRE(a.size() == 6);
//                     REQUIRE(a.dimensions() == std::tuple{2, 3});

//                     cxl::box<int> b = { { 5, 113, 13 }
//                                          , { 243, -42, 114 } };

//                     REQUIRE(b.size() == 6);
//                     REQUIRE(b.dimensions() == std::tuple{2, 3});

//                     a <<= b;

//                     REQUIRE(a.size() == 6);
//                     REQUIRE(a.dimensions() == std::tuple{2, 3});
//                     REQUIRE(a == cxl::box<int> { { 32, 262144, 24576 }
//                                                   , { 2097152, 20971520, 1572864 } });
//                 }

//                 SECTION("Different Type")
//                 {
//                     cxl::box<short> a = { { 1, 2 }
//                                            , { 3, 4 }
//                                            , { 5, 6 }
//                                            , { 7, 8 } };

//                     REQUIRE(a.size() == 8);
//                     REQUIRE(a.dimensions() == std::tuple{4, 2});

//                     cxl::box<int> b = { { 6, 23 }
//                                          , { 45, 8 }
//                                          , { 115, 255 }
//                                          , { 13, 4 } };

//                     REQUIRE(b.size() == 8);
//                     REQUIRE(b.dimensions() == std::tuple{4, 2});

//                     REQUIRE_THROWS_AS(a <<= b, std::invalid_argument);
//                     b <<= a;

//                     REQUIRE(b.size() == 8);
//                     REQUIRE(b.dimensions() == std::tuple{4, 2});
//                     REQUIRE(b == cxl::box<int> { { 12, 92 }
//                                                   , { 360, 128 }
//                                                   , { 3680, 16320 }
//                                                   , { 1664, 1024 } });
//                 }
//             }
//         }

//         SECTION("Scalar Left Bit Shift")
//         {
//             SECTION("Left Bit Shift")
//             {
//                 SECTION("Same Type")
//                 {
//                     cxl::box<int> a = { { 1, 2, 3 }
//                                          , { 4, 5, 6 } };

//                     REQUIRE(a.size() == 6);
//                     REQUIRE(a.dimensions() == std::tuple{2, 3});

//                     auto b { a << 5 };

//                     REQUIRE(b.size() == 6);
//                     REQUIRE(b.dimensions() == std::tuple{2, 3});
//                     REQUIRE(b == cxl::box<int> { { 32, 64, 96 }
//                                                   , { 128, 160, 192 } });
//                 }
//             }

//             SECTION("Left Bit Shift Assign")
//             {
//                 SECTION("Same Type")
//                 {
//                     cxl::box<int> a = { { 1, 2, 3 }
//                                          , { 4, 5, 6 } };

//                     REQUIRE(a.size() == 6);
//                     REQUIRE(a.dimensions() == std::tuple{2, 3});

//                     a <<= 5;
                    
//                     REQUIRE(a.size() == 6);
//                     REQUIRE(a.dimensions() == std::tuple{2, 3});
//                     REQUIRE(a == cxl::box<int> { { 32, 64, 96 }
//                                                   , { 128, 160, 192 } });
//                 }
//             }
//         }
//     }

//     SECTION("Right Bit Shift and Right Bit Shift Assign")
//     {
//         SECTION("Box Right Bit Shift")
//         {
//             SECTION("Right Bit Shift")
//             {
//                 SECTION("Same Type")
//                 {
//                     cxl::box<int> a = { { 1, 2, 3 }
//                                          , { 4, 5, 6 } };

//                     REQUIRE(a.size() == 6);
//                     REQUIRE(a.dimensions() == std::tuple{2, 3});

//                     cxl::box<int> b = { { 5, 113, 13 }
//                                          , { 243, -42, 114 } };

//                     REQUIRE(b.size() == 6);
//                     REQUIRE(b.dimensions() == std::tuple{2, 3});

//                     auto c { a >> b };

//                     REQUIRE(c.size() == 6);
//                     REQUIRE(c.dimensions() == std::tuple{2, 3});
//                     REQUIRE(c == cxl::box<int> { { 0, 0, 0 }
//                                                   , { 0, 0, 0 } });
//                 }

//                 SECTION("Different Type")
//                 {
//                     cxl::box<int> a = { { 1, 2 }
//                                          , { 3, 4 }
//                                          , { 5, 6 }
//                                          , { 7, 8 } };

//                     REQUIRE(a.size() == 8);
//                     REQUIRE(a.dimensions() == std::tuple{4, 2});

//                     cxl::box<short> b = { { 6, 23 }
//                                            , { 45, 8 }
//                                            , { 115, 255 }
//                                            , { 13, 4 } };

//                     REQUIRE(b.size() == 8);
//                     REQUIRE(b.dimensions() == std::tuple{4, 2});

//                     auto c { a >> b };

//                     REQUIRE(c.size() == 8);
//                     REQUIRE(c.dimensions() == std::tuple{4, 2});
//                     REQUIRE(c == cxl::box<short> { { 0, 0 }
//                                                     , { 0, 0 }
//                                                     , { 0, 0 }
//                                                     , { 0, 0 } });
//                 }

//                 SECTION("Self Right Bit Shift")
//                 {
//                     cxl::box<int> a = { { 1, 2 }
//                                          , { 3, 4 }
//                                          , { 5, 6 }
//                                          , { 7, 8 } };

//                     REQUIRE(a.size() == 8);
//                     REQUIRE(a.dimensions() == std::tuple{4, 2});

//                     auto c { a >> a };

//                     REQUIRE(c.size() == 8);
//                     REQUIRE(c.dimensions() == std::tuple{4, 2});
//                     REQUIRE(c == cxl::box<int> { { 0, 0 }
//                                                   , { 0, 0 }
//                                                   , { 0, 0 }
//                                                   , { 0, 0 } });
//                 }
//             }

//             SECTION("Right Bit Shift Assign") 
//             {
//                 SECTION("Same Type")
//                 {
//                     cxl::box<int> a = { { 1, 2, 3 }
//                                          , { 4, 5, 6 } };

//                     REQUIRE(a.size() == 6);
//                     REQUIRE(a.dimensions() == std::tuple{2, 3});

//                     cxl::box<int> b = { { 5, 113, 13 }
//                                          , { 243, -42, 114 } };

//                     REQUIRE(b.size() == 6);
//                     REQUIRE(b.dimensions() == std::tuple{2, 3});

//                     a >>= b;

//                     REQUIRE(a.size() == 6);
//                     REQUIRE(a.dimensions() == std::tuple{2, 3});
//                     REQUIRE(a == cxl::box<int> { { 0, 0, 0 }
//                                                   , { 0, 0, 0 } });
//                 }

//                 SECTION("Different Type")
//                 {
//                     cxl::box<short> a = { { 1, 2 }
//                                            , { 3, 4 }
//                                            , { 5, 6 }
//                                            , { 7, 8 } };

//                     REQUIRE(a.size() == 8);
//                     REQUIRE(a.dimensions() == std::tuple{4, 2});

//                     cxl::box<int> b = { { 6, 23 }
//                                          , { 45, 8 }
//                                          , { 115, 255 }
//                                          , { 13, 4 } };

//                     REQUIRE(b.size() == 8);
//                     REQUIRE(b.dimensions() == std::tuple{4, 2});

//                     REQUIRE_THROWS_AS(a >>= b, std::invalid_argument);
//                     b >>= a;

//                     REQUIRE(b.size() == 8);
//                     REQUIRE(b.dimensions() == std::tuple{4, 2});
//                     REQUIRE(b == cxl::box<int> { { 3, 5 }
//                                                   , { 5, 0 }
//                                                   , { 3, 3 }
//                                                   , { 0, 0 } });
//                 }
//             }
//         }

//         SECTION("Scalar Right Bit Shift")
//         {
//             SECTION("Right Bit Shift")
//             {
//                 SECTION("Same Type")
//                 {
//                     cxl::box<int> a = { { 1, 2, 3 }
//                                          , { 4, 5, 6 } };

//                     REQUIRE(a.size() == 6);
//                     REQUIRE(a.dimensions() == std::tuple{2, 3});

//                     auto b { a >> 5 };

//                     REQUIRE(b.size() == 6);
//                     REQUIRE(b.dimensions() == std::tuple{2, 3});
//                     REQUIRE(b == cxl::box<int> { { 0, 0, 0 }
//                                                   , { 0, 0, 0 } });
//                 }
//             }

//             SECTION("Right Bit Shift Assign")
//             {
//                 SECTION("Same Type")
//                 {
//                     cxl::box<int> a = { { 1, 2, 3 }
//                                          , { 4, 5, 6 } };

//                     REQUIRE(a.size() == 6);
//                     REQUIRE(a.dimensions() == std::tuple{2, 3});

//                     a >>= 5;
                    
//                     REQUIRE(a.size() == 6);
//                     REQUIRE(a.dimensions() == std::tuple{2, 3});
//                     REQUIRE(a == cxl::box<int> { { 0, 0, 0 }
//                                                   , { 0, 0, 0 } });
//                 }
//             }
//         }
//     }

//     SECTION("Bit Not")
//     {
//         cxl::box<int> a = { { 1, 2 }
//                              , { 3, 4 }
//                              , { 5, 6 }
//                              , { 7, 8 } };

//         REQUIRE(a.size() == 8);
//         REQUIRE(a.dimensions() == std::tuple{4, 2});

//         auto b { ~a };

//         REQUIRE(b.size() == 8);
//         REQUIRE(b.dimensions() == std::tuple{4, 2});
//         REQUIRE(b == cxl::box<int> { { -2, -3 }
//                                       , { -4, -5 }
//                                       , { -6, -7 }
//                                       , { -8, -9 } });
//     }
// }

// TEST_CASE("Utility Operators")
// {
//     SECTION("Transpose")
//     {
//         SECTION("Transpose")
//         {
//             cxl::box<int> a = { { 1, 2 }
//                                 , { 3, 4 }
//                                 , { 5, 6 }
//                                 , { 7, 8 } };

//             REQUIRE(a.size() == 8);
//             REQUIRE(a.dimensions() == std::tuple{4, 2});

//             auto b { !a };

//             REQUIRE(b.size() == 8);
//             REQUIRE(b.dimensions() == std::tuple{2, 4});
//             REQUIRE(b == cxl::box<int> { { 1, 3, 5, 7 }
//                                         , { 2, 4, 6, 8 } });
//         }

//         SECTION("Transpose Empty")
//         {
//             cxl::box<int> a;

//             REQUIRE(a.size() == 0);
//             REQUIRE(a.dimensions() == std::tuple{0, 0});

//             auto b { !a };

//             REQUIRE(b.size() == 0);
//             REQUIRE(b.dimensions() == std::tuple{0, 0});
//         }

//         SECTION("Transpose Single Element")
//         {
//             cxl::box<int> a = { { 1 } };

//             REQUIRE(a.size() == 1);
//             REQUIRE(a.dimensions() == std::tuple{1, 1});

//             auto b { !a };

//             REQUIRE(b.size() == 1);
//             REQUIRE(b.dimensions() == std::tuple{1, 1});
//             REQUIRE(b == cxl::box<int> { { 1 } });
//         }

//         SECTION("Transpose Assign")
//         {
//             cxl::box<int> a = { { 1, 2 }
//                                 , { 3, 4 }
//                                 , { 5, 6 }
//                                 , { 7, 8 } };

//             REQUIRE(a.size() == 8);
//             REQUIRE(a.dimensions() == std::tuple{4, 2});

//             a = !a;

//             REQUIRE(a.size() == 8);
//             REQUIRE(a.dimensions() == std::tuple{2, 4});
//             REQUIRE(a == cxl::box<int> { { 1, 3, 5, 7 }
//                                         , { 2, 4, 6, 8 } });
//         }
//     }

//     SECTION("Map")
//     {
//         SECTION("Map")
//         {
//             SECTION("Map - Lambda")
//             {
//                 cxl::box<int> a = { { 1, 2 }
//                                      , { 3, 4 }
//                                      , { 5, 6 }
//                                      , { 7, 8 } };

//                 REQUIRE(a.size() == 8);
//                 REQUIRE(a.dimensions() == std::tuple{4, 2});

//                 auto b { a || [](const auto& i) { return i * 2; } };

//                 REQUIRE(b.size() == 8);
//                 REQUIRE(b.dimensions() == std::tuple{4, 2});
//                 REQUIRE(b == cxl::box<int> { { 2, 4 }
//                                               , { 6, 8 }
//                                               , { 10, 12 }
//                                               , { 14, 16 } });
//             }

//             SECTION("Map - Named Lambda")
//             {
//                 cxl::box<int> a = { { 1, 2 }
//                                      , { 3, 4 }
//                                      , { 5, 6 }
//                                      , { 7, 8 } };

//                 auto xor_3 = [](const auto& i) { return i ^ 3; };

//                 REQUIRE(a.size() == 8);
//                 REQUIRE(a.dimensions() == std::tuple{4, 2});

//                 auto b { a || xor_3 };

//                 REQUIRE(b.size() == 8);
//                 REQUIRE(b.dimensions() == std::tuple{4, 2});
//                 REQUIRE(b == cxl::box<int> { { 2, 1 }
//                                               , { 0, 7 }
//                                               , { 6, 5 }
//                                               , { 4, 11 } });
//             }

//             SECTION("Map - Chained Lambdas")
//             {
//                 cxl::box<int> a = { { 1, 2 }
//                                      , { 3, 4 }
//                                      , { 5, 6 }
//                                      , { 7, 8 } };

//                 REQUIRE(a.size() == 8);
//                 REQUIRE(a.dimensions() == std::tuple{4, 2});

//                 auto b { a || [](const auto& i) { return i * 2; } 
//                            || [](const auto& i) { return i ^ 3; } };

//                 REQUIRE(b.size() == 8);
//                 REQUIRE(b.dimensions() == std::tuple{4, 2});
//                 REQUIRE(b == cxl::box<int> { { 1, 7 }
//                                               , { 5, 11 }
//                                               , { 9, 15 }
//                                               , { 13, 19 } });
//             }

//             SECTION("Map - Chained Named Lambdas")
//             {
//                 cxl::box<int> a = { { 1, 2 }
//                                      , { 3, 4 }
//                                      , { 5, 6 }
//                                      , { 7, 8 } };

//                 auto square = [](const auto& i) { return i * 2; };
//                 auto xor_3 = [](const auto& i) { return i ^ 3; };

//                 REQUIRE(a.size() == 8);
//                 REQUIRE(a.dimensions() == std::tuple{4, 2});

//                 auto b { a || square 
//                            || xor_3 };

//                 REQUIRE(b.size() == 8);
//                 REQUIRE(b.dimensions() == std::tuple{4, 2});
//                 REQUIRE(b == cxl::box<int> { { 1, 7 }
//                                               , { 5, 11 }
//                                               , { 9, 15 }
//                                               , { 13, 19 } });
//             }
//         }
//     }
// }