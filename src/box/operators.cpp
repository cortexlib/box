// #include <catch2/catch.hpp>
// #include <box.hpp>


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
// }