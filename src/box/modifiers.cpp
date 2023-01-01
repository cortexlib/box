// #include <catch2/catch.hpp>
// #include <box.hpp>
// #include <functional>

// TEST_CASE("Modifications")
// {
//     SECTION("box::transpose")
//     {
//         SECTION("box::transpose - Normal")
//         {
//             cxl::box<int> bx = { { 0, 1 }
//                                     , { 2, 3 }
//                                     , { 4, 5 }
//                                     , { 7, 6 }
//                                     , { 8, 9 } };

//             cxl::box<int> bxcheck = { { 0, 2, 4, 7, 8 }
//                                         , { 1, 3, 5, 6, 9 } };

//             REQUIRE(bx.size() == 10);
//             REQUIRE(bx.rows() == 5);
//             REQUIRE(bx.columns() == 2);

//             auto rbx { bx.transpose() };

//             REQUIRE(bx.size() == 10);
//             REQUIRE(bx.rows() == 5);
//             REQUIRE(bx.columns() == 2);

//             REQUIRE(rbx.size() == 10);
//             REQUIRE(rbx.rows() == 2);
//             REQUIRE(rbx.columns() == 5);

//             REQUIRE(rbx == bxcheck);
//         }

//         SECTION("box::transpose - Double transpose")
//         {
//             cxl::box<int> bx = { { 0, 1 }
//                                     , { 2, 3 }
//                                     , { 4, 5 }
//                                     , { 7, 6 }
//                                     , { 8, 9 } };

//             cxl::box<int> bxcheck = { { 0, 2, 4, 7, 8 }
//                                         , { 1, 3, 5, 6, 9 } };

//             REQUIRE(bx.size() == 10);
//             REQUIRE(bx.rows() == 5);
//             REQUIRE(bx.columns() == 2);

//             auto rbx { bx.transpose() };

//             REQUIRE(bx.size() == 10);
//             REQUIRE(bx.rows() == 5);
//             REQUIRE(bx.columns() == 2);

//             REQUIRE(rbx.size() == 10);
//             REQUIRE(rbx.rows() == 2);
//             REQUIRE(rbx.columns() == 5);

//             REQUIRE(rbx == bxcheck);

//             auto rrbx { rbx.transpose() };

//             REQUIRE(rbx.size() == 10);
//             REQUIRE(rbx.rows() == 2);
//             REQUIRE(rbx.columns() == 5);

//             REQUIRE(rrbx == bx);
//         }

//         SECTION("box::transpose - Double transpose in-place")
//         {
//             cxl::box<int> bx = { { 0, 1 }
//                                   , { 2, 3 }
//                                   , { 4, 5 }
//                                   , { 7, 6 }
//                                   , { 8, 9 } };

//             cxl::box<int> bxcheck = { { 0, 2, 4, 7, 8 }
//                                        , { 1, 3, 5, 6, 9 } };

//             REQUIRE(bx.size() == 10);
//             REQUIRE(bx.rows() == 5);
//             REQUIRE(bx.columns() == 2);

//             auto rbx { bx.transpose().transpose() };

//             REQUIRE(rbx.size() == 10);
//             REQUIRE(rbx.rows() == 5);
//             REQUIRE(rbx.columns() == 2);

//             REQUIRE(rbx == bx);
//         }

//         SECTION("box::transpose - Empty")
//         {
//             cxl::box<int> bx;

//             REQUIRE(bx.empty());
//             REQUIRE(bx.size() == 0);
//             REQUIRE(bx.rows() == 0);
//             REQUIRE(bx.columns() == 0);

//             auto rbx { bx.transpose() };

//             REQUIRE(rbx.size() == 0);
//             REQUIRE(rbx.rows() == 0);
//             REQUIRE(rbx.columns() == 0);

//             REQUIRE(rbx == bx);
//         }

//         SECTION("box::transpose - Column to Row")
//         {
//             cxl::box<int> bx = { { 5, 1 } };

//             cxl::box<int> bxcheck = { { 5 }
//                                        , { 1 } };

//             REQUIRE(bx.size() == 2);
//             REQUIRE(bx.rows() == 1);
//             REQUIRE(bx.columns() == 2);

//             auto rbx { bx.transpose() };

//             REQUIRE(rbx.size() == 2);
//             REQUIRE(rbx.rows() == 2);
//             REQUIRE(rbx.columns() == 1);

//             REQUIRE(rbx == bxcheck);
//         }

//         SECTION("box::transpose - Row to Column")
//         {
//             cxl::box<int> bx = { { 54 }
//                                     , { 73 } 
//                                     , { 12 } };

//             cxl::box<int> bxcheck = { { 54, 73, 12} };

//             REQUIRE(bx.size() == 3);
//             REQUIRE(bx.rows() == 3);
//             REQUIRE(bx.columns() == 1);

//             auto rbx { bx.transpose() };

//             REQUIRE(rbx.size() == 3);
//             REQUIRE(rbx.rows() == 1);
//             REQUIRE(rbx.columns() == 3);

//             REQUIRE(rbx == bxcheck);
//         }

//         SECTION("box::transpose - Single Element")
//         {
//             cxl::box<int> bx = { { 5 } };

//             REQUIRE(bx.size() == 1);
//             REQUIRE(bx.rows() == 1);
//             REQUIRE(bx.columns() == 1);

//             auto rbx { bx.transpose() };

//             REQUIRE(rbx.size() == 1);
//             REQUIRE(rbx.rows() == 1);
//             REQUIRE(rbx.columns() == 1);

//             REQUIRE(rbx == bx);
//         }
//     }

//     SECTION("box::map")
//     {
//         SECTION("Box only Mapping")
//         {
//             SECTION("Lambda")
//             {
//                 cxl::box<int> bx = { { 0, 1 }
//                                     , { 2, 3 }
//                                     , { 4, 5 }
//                                     , { 7, 6 }
//                                     , { 8, 9 } };

//                 cxl::box<int> bxcheck = { { 0, 2 }
//                                         , { 4, 6 }
//                                         , { 8, 10 }
//                                         , { 12, 14 }
//                                         , { 16, 18 } };

//                 REQUIRE(bx.size() == 10);
//                 REQUIRE(bx.rows() == 5);
//                 REQUIRE(bx.columns() == 2);

//                 auto rbx { bx.map([](int i) { return i * 2; }) };

//                 REQUIRE(bx.size() == 10);
//                 REQUIRE(bx.rows() == 5);
//                 REQUIRE(bx.columns() == 2);

//                 REQUIRE(rbx.size() == 10);
//                 REQUIRE(rbx.rows() == 5);
//             }

//             SECTION("Lambda - Empty")
//             {
//                 cxl::box<int> bx;

//                 REQUIRE(bx.empty());
//                 REQUIRE(bx.size() == 0);
//                 REQUIRE(bx.rows() == 0);
//                 REQUIRE(bx.columns() == 0);

//                 auto rbx { bx.map([](int i) { return i * 2; }) };

//                 REQUIRE(rbx.empty());
//                 REQUIRE(rbx.size() == 0);
//                 REQUIRE(rbx.rows() == 0);
//                 REQUIRE(rbx.columns() == 0);

//                 REQUIRE(rbx == bx);
//             }

//             SECTION("Double Call - Intermidiate")
//             {
//                 cxl::box<int> bx = { { 0, 1 }
//                                     , { 2, 3 }
//                                     , { 4, 5 }
//                                     , { 6, 7 }
//                                     , { 8, 9 } };

//                 cxl::box<int> bxcheck = { { 0, 1 }
//                                         , { 2, 3 }
//                                         , { 4, 5 }
//                                         , { 6, 7 }
//                                         , { 8, 9 } };

//                 cxl::box<int> ibxcheck = { { 0, 2 }
//                                             , { 4, 6 }
//                                             , { 8, 10 }
//                                             , { 12, 14 }
//                                             , { 16, 18 } };

//                 cxl::box<int> rbxcheck = { { -3, -1 }
//                                             , { -7, -5 }
//                                             , { -11, -9 }
//                                             , { -15, -13 }
//                                             , { -19, -17 } };

//                 REQUIRE(bx.size() == 10);
//                 REQUIRE(bx.rows() == 5);
//                 REQUIRE(bx.columns() == 2);

//                 auto ibx { bx.map([](int i) { return i * 2; }) };

//                 REQUIRE(bx == bxcheck);

//                 REQUIRE(ibx.size() == 10);
//                 REQUIRE(ibx.rows() == 5);
//                 REQUIRE(ibx.columns() == 2);
//                 REQUIRE(ibx == ibxcheck);

//                 auto rbx { ibx.map([](int i) { return i ^ -3; }) };

//                 REQUIRE(ibx == ibxcheck);

//                 REQUIRE(rbx.size() == 10);
//                 REQUIRE(rbx.rows() == 5);
//                 REQUIRE(rbx.columns() == 2);
//                 REQUIRE(rbx == rbxcheck);
//             }

//             SECTION("Double Call - Chained")
//             {
//                 cxl::box<int> bx = { { 0, 1 }
//                                     , { 2, 3 }
//                                     , { 4, 5 }
//                                     , { 6, 7 }
//                                     , { 8, 9 } };

//                 cxl::box<int> bxcheck = { { 0, 1 }
//                                         , { 2, 3 }
//                                         , { 4, 5 }
//                                         , { 6, 7 }
//                                         , { 8, 9 } };

//                 cxl::box<int> rbxcheck = { { -3, -1 }
//                                             , { -7, -5 }
//                                             , { -11, -9 }
//                                             , { -15, -13 }
//                                             , { -19, -17 } };

//                 REQUIRE(bx.size() == 10);
//                 REQUIRE(bx.rows() == 5);
//                 REQUIRE(bx.columns() == 2);

//                 auto rbx { bx.map([](int i) { return i * 2; }).map([](int i) { return i ^ -3; }) };

//                 REQUIRE(bx == bxcheck);

//                 REQUIRE(rbx.size() == 10);
//                 REQUIRE(rbx.rows() == 5);
//                 REQUIRE(rbx.columns() == 2);
//                 REQUIRE(rbx == rbxcheck);
//             }

//             SECTION("Named Lambda")
//             {
//                 cxl::box<int> bx = { { 0, 1 }
//                                     , { 2, 3 }
//                                     , { 4, 5 }
//                                     , { 6, 7 }
//                                     , { 8, 9 } };

//                 auto square = [](const auto& i) { return i * i; };

//                 cxl::box<int> bxcheck = { { 0, 1 }
//                                         , { 4, 9 }
//                                         , { 16, 25 }
//                                         , { 36, 49 }
//                                         , { 64, 81 } };

//                 REQUIRE(bx.size() == 10);
//                 REQUIRE(bx.rows() == 5);
//                 REQUIRE(bx.columns() == 2);

//                 auto rbx { bx.map(square) };

//                 REQUIRE(bx.size() == 10);
//                 REQUIRE(bx.rows() == 5);
//                 REQUIRE(bx.columns() == 2);

//                 REQUIRE(rbx.size() == 10);
//                 REQUIRE(rbx.rows() == 5);
//             }
//         }

//         SECTION("Box and Range")
//         {
//             SECTION("Lambda - With Box")  
//             {
//                 cxl::box<int> bx = { { 0, 1 }
//                                       , { 2, 3 }
//                                       , { 4, 5 }
//                                       , { 6, 7 }
//                                       , { 8, 9 } };

//                 cxl::box<int> bxcheck = { { 0, 1 }
//                                            , { 2, 3 }
//                                            , { 4, 5 }
//                                            , { 6, 7 }
//                                            , { 8, 9 } };

//                 cxl::box<int> rbxcheck = { { 0, 2 }
//                                             , { 48, -3 }
//                                             , { -12, 280 }
//                                             , { -24, 14 }
//                                             , { -40, 36 } };

//                 REQUIRE(bx.size() == 10);
//                 REQUIRE(bx.dimensions() == std::tuple{ 5, 2 });
//                 REQUIRE(bx == bxcheck);

//                 cxl::box<int> x = { { 5, 2 }
//                                      , { 24, -1 }
//                                      , { -3, 56 }
//                                      , { -4, 2 }
//                                      , { -5, 4 } };

//                 auto rbx { bx.map(x, [](auto e, auto x) { return e * x; }) };

//                 REQUIRE(rbx.size() == 10);
//                 REQUIRE(rbx.dimensions() == std::tuple{ 5, 2 });
//                 REQUIRE(rbx == rbxcheck);
//             }

//             SECTION("Lambda - With Other Range")
//             {
//                 cxl::box<int> bx = { { 0, 1 }
//                                       , { 2, 3 }
//                                       , { 4, 5 }
//                                       , { 6, 7 }
//                                       , { 8, 9 } };

//                 cxl::box<int> bxcheck = { { 0, 1 }
//                                            , { 2, 3 }
//                                            , { 4, 5 }
//                                            , { 6, 7 }
//                                            , { 8, 9 } };

//                 cxl::box<int> rbxcheck = { { 0, 2 }
//                                             , { 48, -3 }
//                                             , { -12, 280 }
//                                             , { -24, 14 }
//                                             , { -40, 36 } };

//                 REQUIRE(bx.size() == 10);
//                 REQUIRE(bx.dimensions() == std::tuple{ 5, 2 });
//                 REQUIRE(bx == bxcheck);

//                 std::vector<int> v = { 5, 2, 24, -1, -3, 56,-4, 2, -5, 4 };

//                 auto rbx { bx.map(v, [](auto x, auto v) { return x * v; }) };

//                 REQUIRE(rbx.size() == 10);
//                 REQUIRE(rbx.dimensions() == std::tuple{ 5, 2 });
//                 REQUIRE(rbx == rbxcheck);
//             }

//             SECTION("Named Lambda")
//             {
//                 cxl::box<int> bx = { { 0, 1 }
//                                       , { 2, 3 }
//                                       , { 4, 5 }
//                                       , { 6, 7 }
//                                       , { 8, 9 } };

//                 auto add = [](const auto& x, const auto& y) { return x + y; };

//                 cxl::box<int> bxcheck = { { 0, 1 }
//                                            , { 2, 3 }
//                                            , { 4, 5 }
//                                            , { 6, 7 }
//                                            , { 8, 9 } };

//                 cxl::box<int> rbxcheck = { { 5, 3 }
//                                             , { 26, 2 }
//                                             , { 1, 61 }
//                                             , { 2, 9 }
//                                             , { 3, 13 } };

//                 REQUIRE(bx.size() == 10);
//                 REQUIRE(bx.dimensions() == std::tuple{ 5, 2 });
//                 REQUIRE(bx == bxcheck);

//                 cxl::box<int> x = { { 5, 2 }
//                                      , { 24, -1 }
//                                      , { -3, 56 }
//                                      , { -4, 2 }
//                                      , { -5, 4 } };

//                 auto rbx { bx.map(x, add) };

//                 REQUIRE(rbx.size() == 10);
//                 REQUIRE(rbx.dimensions() == std::tuple{ 5, 2 });
//                 REQUIRE(rbx == rbxcheck);
//             }
//         }

//         SECTION("Box and Iterators")
//         {
//             SECTION("Lambda - With Box")  
//             {
//                 cxl::box<int> bx = { { 0, 1 }
//                                       , { 2, 3 }
//                                       , { 4, 5 }
//                                       , { 6, 7 }
//                                       , { 8, 9 } };

//                 cxl::box<int> bxcheck = { { 0, 1 }
//                                            , { 2, 3 }
//                                            , { 4, 5 }
//                                            , { 6, 7 }
//                                            , { 8, 9 } };

//                 cxl::box<int> rbxcheck = { { 0, 2 }
//                                             , { 48, -3 }
//                                             , { -12, 280 }
//                                             , { -24, 14 }
//                                             , { -40, 36 } };

//                 REQUIRE(bx.size() == 10);
//                 REQUIRE(bx.dimensions() == std::tuple{ 5, 2 });
//                 REQUIRE(bx == bxcheck);

//                 cxl::box<int> x = { { 5, 2 }
//                                      , { 24, -1 }
//                                      , { -3, 56 }
//                                      , { -4, 2 }
//                                      , { -5, 4 } };

//                 auto rbx { bx.map(x.begin(), x.end(), [](auto e, auto x) { return e * x; }) };

//                 REQUIRE(rbx.size() == 10);
//                 REQUIRE(rbx.dimensions() == std::tuple{ 5, 2 });
//                 REQUIRE(rbx == rbxcheck);
//             }

//             SECTION("Lambda - With Other Container")
//             {
//                 cxl::box<int> bx = { { 0, 1 }
//                                       , { 2, 3 }
//                                       , { 4, 5 }
//                                       , { 6, 7 }
//                                       , { 8, 9 } };

//                 cxl::box<int> bxcheck = { { 0, 1 }
//                                            , { 2, 3 }
//                                            , { 4, 5 }
//                                            , { 6, 7 }
//                                            , { 8, 9 } };

//                 cxl::box<int> rbxcheck = { { 0, 2 }
//                                             , { 48, -3 }
//                                             , { -12, 280 }
//                                             , { -24, 14 }
//                                             , { -40, 36 } };

//                 REQUIRE(bx.size() == 10);
//                 REQUIRE(bx.dimensions() == std::tuple{ 5, 2 });
//                 REQUIRE(bx == bxcheck);

//                 std::vector<int> v = { 5, 2, 24, -1, -3, 56,-4, 2, -5, 4 };

//                 auto rbx { bx.map(v.begin(), v.end(), [](auto x, auto v) { return x * v; }) };

//                 REQUIRE(rbx.size() == 10);
//                 REQUIRE(rbx.dimensions() == std::tuple{ 5, 2 });
//                 REQUIRE(rbx == rbxcheck);
//             }

//             SECTION("Named Lambda")
//             {
//                 cxl::box<int> bx = { { 0, 1 }
//                                       , { 2, 3 }
//                                       , { 4, 5 }
//                                       , { 6, 7 }
//                                       , { 8, 9 } };

//                 auto add = [](const auto& x, const auto& y) { return x + y; };

//                 cxl::box<int> bxcheck = { { 0, 1 }
//                                            , { 2, 3 }
//                                            , { 4, 5 }
//                                            , { 6, 7 }
//                                            , { 8, 9 } };

//                 cxl::box<int> rbxcheck = { { 5, 3 }
//                                             , { 26, 2 }
//                                             , { 1, 61 }
//                                             , { 2, 9 }
//                                             , { 3, 13 } };

//                 REQUIRE(bx.size() == 10);
//                 REQUIRE(bx.dimensions() == std::tuple{ 5, 2 });
//                 REQUIRE(bx == bxcheck);

//                 cxl::box<int> x = { { 5, 2 }
//                                      , { 24, -1 }
//                                      , { -3, 56 }
//                                      , { -4, 2 }
//                                      , { -5, 4 } };

//                 auto rbx { bx.map(x.begin(), x.end(), add) };

//                 REQUIRE(rbx.size() == 10);
//                 REQUIRE(rbx.dimensions() == std::tuple{ 5, 2 });
//                 REQUIRE(rbx == rbxcheck);
//             }
//         }
//     }

//     SECTION("box::vflip")
//     {
//         SECTION("box::vflip - Empty")
//         {
//             cxl::box<int> bx;

//             REQUIRE(bx.empty());
//             REQUIRE(bx.size() == 0);
//             REQUIRE(bx.rows() == 0);
//             REQUIRE(bx.columns() == 0);

//             auto rbx { bx.vflip() };

//             REQUIRE(rbx.empty());
//             REQUIRE(rbx.size() == 0);
//             REQUIRE(rbx.rows() == 0);
//             REQUIRE(rbx.columns() == 0);

//             REQUIRE(rbx == bx);
//         }

//         SECTION("box::vflip - Single")
//         {
//             cxl::box<int> bx = { { 0 } };

//             cxl::box<int> bxcheck = { { 0 } };

//             cxl::box<int> rbxcheck = { { 0 } };

//             REQUIRE(bx.size() == 1);
//             REQUIRE(bx.rows() == 1);
//             REQUIRE(bx.columns() == 1);

//             auto rbx { bx.vflip() };

//             REQUIRE(bx == bxcheck);

//             REQUIRE(rbx.size() == 1);
//             REQUIRE(rbx.rows() == 1);
//             REQUIRE(rbx.columns() == 1);
//             REQUIRE(rbx == rbxcheck);

//             REQUIRE(rbx == bx);

//             REQUIRE(rbx.vflip() == bx);
//         }

//         SECTION("box::vflip - Shaped")
//         {
//             cxl::box<int> bx = { { 0, 1 }
//                                   , { 2, 3 }
//                                   , { 4, 5 }
//                                   , { 6, 7 }
//                                   , { 8, 9 } };

//             cxl::box<int> bxcheck = { { 0, 1 }
//                                        , { 2, 3 }
//                                        , { 4, 5 }
//                                        , { 6, 7 }
//                                        , { 8, 9 } };

//             cxl::box<int> rbxcheck = { { 8, 9 }
//                                         , { 6, 7 }
//                                         , { 4, 5 }
//                                         , { 2, 3 }
//                                         , { 0, 1 } };

//             REQUIRE(bx.size() == 10);
//             REQUIRE(bx.dimensions() == std::tuple{5, 2});

//             auto rbx { bx.vflip() };

//             REQUIRE(bx == bxcheck);

//             REQUIRE(rbx.size() == 10);
//             REQUIRE(rbx.dimensions() == std::tuple{5, 2});
//             REQUIRE(rbx == rbxcheck);

//             REQUIRE(rbx.vflip() == bx);
//         }
//     }

//     SECTION("box::hflip")
//     {
//         SECTION("box::hflip - Empty")
//         {
//             cxl::box<int> bx;

//             REQUIRE(bx.empty());
//             REQUIRE(bx.size() == 0);
//             REQUIRE(bx.rows() == 0);
//             REQUIRE(bx.columns() == 0);

//             auto rbx { bx.hflip() };

//             REQUIRE(rbx.empty());
//             REQUIRE(rbx.size() == 0);
//             REQUIRE(rbx.rows() == 0);
//             REQUIRE(rbx.columns() == 0);

//             REQUIRE(rbx == bx);
//         }

//         SECTION("box::hflip - Single")
//         {
//             cxl::box<int> bx = { { 0 } };

//             cxl::box<int> bxcheck = { { 0 } };

//             cxl::box<int> rbxcheck = { { 0 } };

//             REQUIRE(bx.size() == 1);
//             REQUIRE(bx.rows() == 1);
//             REQUIRE(bx.columns() == 1);

//             auto rbx { bx.hflip() };

//             REQUIRE(bx == bxcheck);

//             REQUIRE(rbx.size() == 1);
//             REQUIRE(rbx.rows() == 1);
//             REQUIRE(rbx.columns() == 1);
//             REQUIRE(rbx == rbxcheck);

//             REQUIRE(rbx == bx);

//             REQUIRE(rbx.hflip() == bx);
//         }

//         SECTION("box::hflip - Shaped")
//         {
//             cxl::box<int> bx = { { 0, 1 }
//                                   , { 2, 3 }
//                                   , { 4, 5 }
//                                   , { 6, 7 }
//                                   , { 8, 9 } };

//             cxl::box<int> bxcheck = { { 0, 1 }
//                                        , { 2, 3 }
//                                        , { 4, 5 }
//                                        , { 6, 7 }
//                                        , { 8, 9 } };

//             cxl::box<int> rbxcheck = { { 1, 0 }
//                                         , { 3, 2 }
//                                         , { 5, 4 }
//                                         , { 7, 6 }
//                                         , { 9, 8 } };

//             REQUIRE(bx.size() == 10);
//             REQUIRE(bx.dimensions() == std::tuple{5, 2});

//             REQUIRE(bx == bxcheck);

//             auto rbx { bx.hflip() };

//             REQUIRE(rbx.size() == 10);
//             REQUIRE(rbx.dimensions() == std::tuple{5, 2});
//             REQUIRE(rbx == rbxcheck);

//             REQUIRE(rbx.hflip() == bx);
//         }
//     }

//     SECTION("box::rrotate")
//     {
//         SECTION("box::rrotate - Empty")
//         {
//             cxl::box<int> bx;

//             REQUIRE(bx.empty());
//             REQUIRE(bx.size() == 0);
//             REQUIRE(bx.rows() == 0);
//             REQUIRE(bx.columns() == 0);

//             auto rbx { bx.rrotate() };

//             REQUIRE(rbx.empty());
//             REQUIRE(rbx.size() == 0);
//             REQUIRE(rbx.rows() == 0);
//             REQUIRE(rbx.columns() == 0);

//             REQUIRE(rbx == bx);
//         }

//         SECTION("box::rrotate - Single")
//         {
//             cxl::box<int> bx = { { 0 } };

//             cxl::box<int> bxcheck = { { 0 } };

//             cxl::box<int> rbxcheck = { { 0 } };

//             REQUIRE(bx.size() == 1);
//             REQUIRE(bx.rows() == 1);
//             REQUIRE(bx.columns() == 1);

//             auto rbx { bx.rrotate() };

//             REQUIRE(bx == bxcheck);

//             REQUIRE(rbx.size() == 1);
//             REQUIRE(rbx.rows() == 1);
//             REQUIRE(rbx.columns() == 1);
//             REQUIRE(rbx == rbxcheck);

//             REQUIRE(rbx == bx);

//             REQUIRE(rbx.rrotate() == bx);
//         }

//         SECTION("box::rrotate - Shaped")
//         {
//             cxl::box<int> bx = { { 0, 1 }
//                                   , { 2, 3 }
//                                   , { 4, 5 }
//                                   , { 6, 7 }
//                                   , { 8, 9 } };

//             cxl::box<int> bxcheck = { { 0, 1 }
//                                        , { 2, 3 }
//                                        , { 4, 5 }
//                                        , { 6, 7 }
//                                        , { 8, 9 } };

//             cxl::box <int> rbxcheck = { { 8, 6, 4, 2, 0 }
//                                          , { 9, 7, 5, 3, 1 } };

//             REQUIRE(bx.size() == 10);
//             REQUIRE(bx.dimensions() == std::tuple{5, 2});

//             REQUIRE(bx == bxcheck);

//             auto rbx { bx.rrotate() };

//             REQUIRE(rbx.size() == 10);
//             REQUIRE(rbx.dimensions() == std::tuple{2, 5});

//             REQUIRE(rbx == rbxcheck);

//             REQUIRE(rbx.lrotate() == bx);
//         }
//     }

//     SECTION("box::lrotate")
//     {
//         SECTION("box::lrotate - Empty")
//         {
//             cxl::box<int> bx;

//             REQUIRE(bx.empty());
//             REQUIRE(bx.size() == 0);
//             REQUIRE(bx.rows() == 0);
//             REQUIRE(bx.columns() == 0);

//             auto rbx { bx.lrotate() };

//             REQUIRE(rbx.empty());
//             REQUIRE(rbx.size() == 0);
//             REQUIRE(rbx.rows() == 0);
//             REQUIRE(rbx.columns() == 0);

//             REQUIRE(rbx == bx);
//         }

//         SECTION("box::lrotate - Single")
//         {
//             cxl::box<int> bx = { { 0 } };

//             cxl::box<int> bxcheck = { { 0 } };

//             cxl::box<int> rbxcheck = { { 0 } };

//             REQUIRE(bx.size() == 1);
//             REQUIRE(bx.rows() == 1);
//             REQUIRE(bx.columns() == 1);

//             auto rbx { bx.lrotate() };

//             REQUIRE(bx == bxcheck);

//             REQUIRE(rbx.size() == 1);
//             REQUIRE(rbx.rows() == 1);
//             REQUIRE(rbx.columns() == 1);
//             REQUIRE(rbx == rbxcheck);

//             REQUIRE(rbx == bx);

//             REQUIRE(rbx.lrotate() == bx);
//         }

//         SECTION("box::lrotate - Shaped")
//         {
//             cxl::box<int> bx = { { 0, 1 }
//                                   , { 2, 3 }
//                                   , { 4, 5 }
//                                   , { 6, 7 }
//                                   , { 8, 9 } };

//             cxl::box<int> bxcheck = { { 0, 1 }
//                                        , { 2, 3 }
//                                        , { 4, 5 }
//                                        , { 6, 7 }
//                                        , { 8, 9 } };

//             cxl::box <int> rbxcheck = { { 1, 3, 5, 7, 9 }
//                                          , { 0, 2, 4, 6, 8 } };
            
//             REQUIRE(bx.size() == 10);
//             REQUIRE(bx.dimensions() == std::tuple{5, 2});

//             REQUIRE(bx == bxcheck);

//             auto rbx { bx.lrotate() };

//             REQUIRE(rbx.size() == 10);
//             REQUIRE(rbx.dimensions() == std::tuple{2, 5});

//             REQUIRE(rbx == rbxcheck);

//             REQUIRE(rbx.rrotate() == bx);
//         }
//     }
// }