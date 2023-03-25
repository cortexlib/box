#include <catch2/catch.hpp>
#include <fmt/core.h>

#include <containers/matrix.hxx>

#include <iostream>
#include <numeric>
#include <tuple>
#include <utility>

TEST_CASE("Constructors and Assignments")
{
    SECTION("Default Allocated")
    {
        SECTION("Default constructor")
        {
            cxl::matrix<int> bx;
            REQUIRE(bx.size() == 0);
            REQUIRE(bx.num_rows() == 0);
            REQUIRE(bx.num_columns() == 0);
        }

        SECTION("Size Constructor")
        {
            cxl::matrix<int> bx(4, 5);
            REQUIRE(bx.size() == 20);
            REQUIRE(bx.num_rows() == 4);
            REQUIRE(bx.num_columns() == 5);
        }

        SECTION("Size and Value Constructor")
        {
            cxl::matrix<int> bx(4, 5, 1);
            REQUIRE(bx.size() == 20);
            REQUIRE(bx.num_rows() == 4);
            REQUIRE(bx.num_columns() == 5);
        }

        SECTION("Copy constructor")
        {
            cxl::matrix<int> bx(4, 5, 1);
            cxl::matrix<int> nbx(bx);

            REQUIRE(nbx.size() == 20);
            REQUIRE(nbx.num_rows() == 4);
            REQUIRE(nbx.num_columns() == 5);

            for (auto& v : bx)
                REQUIRE(v == 1);

            for (auto& v : nbx)
                REQUIRE(v == 1);
        }

        SECTION("Move constructor")
        {
            cxl::matrix<int> bx(4, 5, 1);

            for (auto& v : bx)
                REQUIRE(v == 1);

            cxl::matrix<int> nbx(std::move(bx));

            REQUIRE(nbx.size() == 20);
            REQUIRE(nbx.num_rows() == 4);
            REQUIRE(nbx.num_columns() == 5);

            for (auto& v : bx)
                REQUIRE(v == 1);
        }

        SECTION("Initializer List Constructor")
        {
            cxl::matrix<int> bx { { 1, 2 }
                                , { 3, 4 }
                                , { 5, 6 }
                                , { 7, 8 }
                                , { 9, 10 } };

            REQUIRE(bx.num_rows() == 5);
            REQUIRE(bx.num_columns() == 2);
            REQUIRE(bx.size() == 10);

            for (auto i { 1 }; auto& v : bx)
                REQUIRE(v == i++);
        }

        SECTION("Dimension Constructor") 
        {
            cxl::matrix<int> bx(2, 5);
            bx = { { 1, 2, 3, 4, 5 }
                , { 6, 7, 8, 9, 10 } };
            
            REQUIRE(bx.num_rows() == 2);
            REQUIRE(bx.num_columns() == 5);
            REQUIRE(bx.size() == 10);
            REQUIRE(bx.shape() == std::tuple{ 2, 5 });
            
            REQUIRE(bx == cxl::matrix<int> { { 1, 2, 3, 4, 5 }
                                        , { 6, 7, 8, 9, 10 } });

            cxl::matrix<std::string> nbx(bx.shape());

            REQUIRE(nbx.num_rows() == 2);
            REQUIRE(nbx.num_columns() == 5);
            REQUIRE(nbx.size() == 10);
            REQUIRE(nbx.shape() == std::tuple{ 2, 5 });

            REQUIRE(nbx == cxl::matrix<std::string> { { "", "", "", "", "" }
                                                    , { "", "", "", "", "" } });
        }
    }

    SECTION("Custom Allocated")
    {
        SECTION("Allocator Constructor")
        {
            std::allocator<int> alloc;
            cxl::matrix<int> bx(alloc);
            REQUIRE(bx.size() == 0);
            REQUIRE(bx.num_rows() == 0);
            REQUIRE(bx.num_columns() == 0);
            REQUIRE(bx.get_allocator() == alloc);
        }

        SECTION("Size Constructor")
        {
            std::allocator<int> alloc;
            cxl::matrix<int> bx(4, 5, alloc);
            REQUIRE(bx.size() == 20);
            REQUIRE(bx.num_rows() == 4);
            REQUIRE(bx.num_columns() == 5);
            REQUIRE(bx.get_allocator() == alloc);
        }

        SECTION("Size and Value Constructor")
        {
            std::allocator<int> alloc;
            cxl::matrix<int> bx(4, 5, 1, alloc);
            REQUIRE(bx.size() == 20);
            REQUIRE(bx.num_rows() == 4);
            REQUIRE(bx.num_columns() == 5);
            REQUIRE(bx.get_allocator() == alloc);
        }

        SECTION("Copy constructor")
        {
            std::allocator<int> alloc;
            cxl::matrix<int> bx(4, 5, 1, alloc);
            cxl::matrix<int> nbx(bx);

            REQUIRE(nbx.size() == 20);
            REQUIRE(nbx.num_rows() == 4);
            REQUIRE(nbx.num_columns() == 5);
            REQUIRE(bx.get_allocator() == alloc);

            for (auto& v : bx)
                REQUIRE(v == 1);

            for (auto& v : nbx)
                REQUIRE(v == 1);
        }

        SECTION("Move constructor")
        {
            std::allocator<int> alloc;
            cxl::matrix<int> bx(4, 5, 1, alloc);

            for (auto& v : bx)
                REQUIRE(v == 1);

            cxl::matrix<int> nbx(std::move(bx));

            REQUIRE(nbx.size() == 20);
            REQUIRE(nbx.num_rows() == 4);
            REQUIRE(nbx.num_columns() == 5);
            REQUIRE(nbx.get_allocator() == alloc);

            for (auto& v : nbx)
                REQUIRE(v == 1);
        }

        SECTION("Dimension Constructor") 
        {
            cxl::matrix<int> bx(2, 5);
            bx = { { 1, 2, 3, 4, 5 }
                , { 6, 7, 8, 9, 10 } };
            
            REQUIRE(bx.num_rows() == 2);
            REQUIRE(bx.num_columns() == 5);
            REQUIRE(bx.size() == 10);
            REQUIRE(bx.shape() == std::tuple{ 2, 5 });
            
            REQUIRE(bx == cxl::matrix<int> { { 1, 2, 3, 4, 5 }
                                        , { 6, 7, 8, 9, 10 } });

            std::allocator<std::string> alloc;
            cxl::matrix<std::string> nbx(bx.shape(), alloc);

            REQUIRE(nbx.num_rows() == 2);
            REQUIRE(nbx.num_columns() == 5);
            REQUIRE(nbx.size() == 10);
            REQUIRE(nbx.shape() == std::tuple{ 2, 5 });

            REQUIRE(nbx == cxl::matrix<std::string> { { "", "", "", "", "" }
                                                    , { "", "", "", "", "" } });
        }
    }

    SECTION("Assignment Operators")
    {
        SECTION("Copy assignment")
        {
            cxl::matrix<int> bx(4, 5, 1);
            cxl::matrix<int> nbx;

            REQUIRE(nbx.size() == 0);
            REQUIRE(nbx.num_rows() == 0);
            REQUIRE(nbx.num_columns() == 0);

            nbx = bx;
            REQUIRE(nbx.size() == 20);
            REQUIRE(nbx.num_rows() == 4);
            REQUIRE(nbx.num_columns() == 5);

            for (auto& v : bx)
                REQUIRE(v == 1);
            
            for (auto& v : nbx)
                REQUIRE(v == 1);
        }

        SECTION("Move assignment")
        {
            cxl::matrix<int> bx(4, 5, 1);
            cxl::matrix<int> nbx;

            REQUIRE(nbx.size() == 0);
            REQUIRE(nbx.num_rows() == 0);
            REQUIRE(nbx.num_columns() == 0);

            nbx = std::move(bx);
            REQUIRE(nbx.size() == 20);
            REQUIRE(nbx.num_rows() == 4);
            REQUIRE(nbx.num_columns() == 5);

            for (auto& v : nbx)
                REQUIRE(v == 1);
        }

        SECTION("Initializer List Assignment")
        {
            cxl::matrix<int> bx = { { 1, 2, 3 }
                                , { 4, 5, 6 }
                                , { 7, 8, 9 } };

            REQUIRE(bx.num_rows() == 3);
            REQUIRE(bx.num_columns() == 3);
            REQUIRE(bx.size() == 9);

            for (auto i { 1 }; auto& v : bx)
                REQUIRE(v == i++);
        }
    }
}

TEST_CASE("MetaData Access")
{
    SECTION("Shape and Size")
    {
        SECTION("matrix::size")
        {
            cxl::matrix<int> bx(4, 5);
            REQUIRE(bx.size() == 20);
        }

        SECTION("matrix::max_size")
        {
            std::allocator<int> alloc;
            cxl::matrix<int> bx(4, 5, 1);
            REQUIRE(bx.max_size() == std::allocator_traits<decltype(alloc)>::max_size(alloc));
        }

        SECTION("matrix::num_rows")
        {
            cxl::matrix<int> bx(4, 5);
            REQUIRE(bx.num_rows() == 4);
        }

        SECTION("matrix::num_columns")
        {
            cxl::matrix<int> bx(4, 5);
            REQUIRE(bx.num_columns() == 5);
        }

        SECTION("matrix::shape - Tuple")
        {
            cxl::matrix<int> bx(4, 5, 1);
            auto dim = bx.shape();

            REQUIRE(std::get<0>(dim) == 4);
            REQUIRE(std::get<1>(dim) == 5);
        }

        SECTION("matrix::shape - Structured Binding")
        {
            cxl::matrix<int> bx(4, 5, 1);
            auto [c, r] = bx.shape();

            REQUIRE(c == 4);
            REQUIRE(r == 5);
        }
    }

    SECTION("Resources")
    {
        SECTION("matrix::empty")
        {
            cxl::matrix<int> bx;
            REQUIRE(bx.empty());
        }

        SECTION("matrix::empty")
        {
            cxl::matrix<int> bx(4, 5, 1);
            REQUIRE(!bx.empty());
        }

        SECTION("matrix::get_allocator")
        {
            cxl::matrix<int> bx(4, 5, 1);
            REQUIRE(bx.get_allocator() == std::allocator<int>());
        }
    }
}

TEST_CASE("Modifiers")
{
    SECTION("Assignment - matrix::assign")
    {
        SECTION("Same Size")
        {
            cxl::matrix<int> bx(3, 3, 1);

            auto ptr { bx.data() };

            REQUIRE(bx.size() == 9);
            REQUIRE(bx.shape() == std::tuple{3, 3});
            REQUIRE(bx.data() == ptr);
            REQUIRE(bx == cxl::matrix<int> { { 1, 1, 1 }
                                        , { 1, 1, 1 }
                                        , { 1, 1, 1 } });

            bx.assign({ { 1, 2, 3 }
                    , { 4, 5, 6 }
                    , { 7, 8, 9 } });
            
            REQUIRE(bx.size() == 9);
            REQUIRE(bx.shape() == std::tuple{3, 3});
            REQUIRE(bx.data() == ptr);
            REQUIRE(bx == cxl::matrix<int> { { 1, 2, 3 }
                                        , { 4, 5, 6 }
                                        , { 7, 8, 9 } });
        }

        SECTION("Larger Size")
        {
            cxl::matrix<int> bx(3, 3, 1);

            auto ptr { bx.data() };

            REQUIRE(bx.size() == 9);
            REQUIRE(bx.shape() == std::tuple{3, 3});
            REQUIRE(ptr == bx.data());
            REQUIRE(bx == cxl::matrix<int> { { 1, 1, 1 }
                                        , { 1, 1, 1 }
                                        , { 1, 1, 1 } });


            bx.assign({ { 1, 2, 3 }
                    , { 4, 5, 6 }
                    , { 7, 8, 9 }
                    , { 10, 11, 12 } });
            
            REQUIRE(bx.size() == 12);
            REQUIRE(bx.shape() == std::tuple{4, 3});
            REQUIRE(bx.data() != ptr);
            REQUIRE(bx == cxl::matrix<int> { { 1, 2, 3 }
                                        , { 4, 5, 6 }
                                        , { 7, 8, 9 }
                                        , { 10, 11, 12 } });
        }

        SECTION("Smaller matrix")
        {
            cxl::matrix<int> bx(3, 3, 1);

            auto ptr { bx.data() };

            REQUIRE(bx.size() == 9);
            REQUIRE(bx.shape() == std::tuple{3, 3});
            REQUIRE(bx.data() == ptr);
            REQUIRE(bx == cxl::matrix<int> { { 1, 1, 1 }
                                        , { 1, 1, 1 }
                                        , { 1, 1, 1 } });

            bx.assign({ { 1, 2, 3, 4 } });

            REQUIRE(bx.size() == 4);
            REQUIRE(bx.shape() == std::tuple{1, 4});
            REQUIRE(bx.data() != ptr);
            REQUIRE(bx == cxl::matrix<int> { { 1, 2, 3, 4 } });
        }

        SECTION("Empty matrix")
        {
            cxl::matrix<int> bx;

            auto ptr { bx.data() };

            REQUIRE(bx.size() == 0);
            REQUIRE(bx.shape() == std::tuple{0, 0});
            REQUIRE(ptr == bx.data());
            REQUIRE(bx == cxl::matrix<int> { });

            bx.assign({ { 1, 2, 3 }
                    , { 4, 5, 6 }
                    , { 7, 8, 9 } });
            
            REQUIRE(bx.size() == 9);
            REQUIRE(bx.shape() == std::tuple{3, 3});
            REQUIRE(bx.data() != ptr);
            REQUIRE(bx == cxl::matrix<int> { { 1, 2, 3 }
                                        , { 4, 5, 6 }
                                        , { 7, 8, 9 } });
        }
    }
    
    SECTION("Swap")
    {
        SECTION("matrix::swap")
        {
            cxl::matrix<int> bx(2, 3, 1);
            cxl::matrix<int> nbx(7, 4, 2);

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

        SECTION("matrix - std::swap")
        {
            cxl::matrix<int> bx(2, 3, 1);
            cxl::matrix<int> nbx(7, 4, 2);

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

    SECTION("Removal")
    {
        SECTION("matrix::clear")
        {
            cxl::matrix<int> bx(4, 5, 1);

            auto ptr { bx.begin().base() };
            REQUIRE(bx.data() == std::to_address(ptr));

            bx.clear();

            REQUIRE(bx.empty());
            REQUIRE(bx.size() == 0);

            REQUIRE_THROWS_AS(bx.at(0, 0) = 1, std::out_of_range);

            REQUIRE(bx.empty());
            REQUIRE(bx.size() == 0);
            REQUIRE(bx.data() == nullptr);
            REQUIRE(bx.data() == decltype(bx)::pointer{});
        }

        SECTION("matrix::clear - No allocated resources")
        {
            cxl::matrix<int> bx;

            REQUIRE(bx.empty());
            REQUIRE(bx.size() == 0);
            REQUIRE(bx.data() == nullptr);
            REQUIRE(bx.data() == decltype(bx)::pointer{});

            bx.clear();

            REQUIRE(bx.empty());
            REQUIRE(bx.size() == 0);
            REQUIRE(bx.data() == nullptr);
            REQUIRE(bx.data() == decltype(bx)::pointer{});
        }

        SECTION("matrix::clear - Uninitialized Resources")
        {
            cxl::matrix<int> bx(4, 5);

            REQUIRE(!bx.empty());
            REQUIRE(bx.size() == 20);
            REQUIRE(bx.num_rows() == 4);
            REQUIRE(bx.num_columns() == 5);
            REQUIRE(bx.data() != nullptr);

            bx.clear();

            REQUIRE(bx.empty());
            REQUIRE(bx.size() == 0);
            REQUIRE(bx.num_columns() == 0);
            REQUIRE(bx.num_rows() == 0);
            REQUIRE(bx.data() == nullptr);
        }
    }

    SECTION("Restructuring")
    {
        SECTION("Resize")
        {
            SECTION("matrix::resize - Larger Resize")
            {
                using namespace std::literals;

                /// std::string was used as it is not trivially constructable 
                /// and thus matrix<std::string>::resize will actually initialise 
                /// the variable to an empty string (unlike ints)
                cxl::matrix<std::string> bx(2, 5, "h");

                REQUIRE(!bx.empty());
                REQUIRE(bx.size() == 10);
                REQUIRE(bx.num_rows() == 2);
                REQUIRE(bx.num_columns() == 5);
                REQUIRE(bx.data() != nullptr);

                for (auto& elem : bx)
                    REQUIRE(elem == "h"s);

                bx.resize(2, 8);

                REQUIRE(!bx.empty());
                REQUIRE(bx.size() == 16);
                REQUIRE(bx.num_rows() == 2);
                REQUIRE(bx.num_columns() == 8);
                REQUIRE(bx.data() != nullptr);

                for (auto i { 0 }; auto& elem : bx)
                {
                    if (i < 10)
                        REQUIRE(elem == "h"s);
                    else
                        REQUIRE(elem == ""s);

                    // fmt::print("i: {} | elem: {}\n", i, elem);

                    i += 1;
                }
            }

            SECTION("matrix::resize - Smaller Resize")
            {
                using namespace std::literals;

                /// std::string was used as it is not trivially constructable 
                /// and thus matrix<std::string>::resize will actually initialise 
                /// the variable to an empty string (unlike ints)
                cxl::matrix<std::string> bx(2, 5, "h");

                REQUIRE(!bx.empty());
                REQUIRE(bx.size() == 10);
                REQUIRE(bx.num_rows() == 2);
                REQUIRE(bx.num_columns() == 5);
                REQUIRE(bx.data() != nullptr);

                for (auto& elem : bx)
                    REQUIRE(elem == "h"s);

                bx.resize(2, 3);

                REQUIRE(!bx.empty());
                REQUIRE(bx.size() == 6);
                REQUIRE(bx.num_rows() == 2);
                REQUIRE(bx.num_columns() == 3);
                REQUIRE(bx.data() != nullptr);

                for (auto& elem : bx)
                    REQUIRE(elem == "h"s);
            }

            SECTION("matrix::resize - After clear")
            {
                using namespace std::literals;

                /// std::string was used as it is not trivially constructable 
                /// and thus matrix<std::string>::resize will actually initialise 
                /// the variable to an empty string (unlike ints)
                cxl::matrix<std::string> bx(2, 5, "h");

                REQUIRE(!bx.empty());
                REQUIRE(bx.size() == 10);
                REQUIRE(bx.num_rows() == 2);
                REQUIRE(bx.num_columns() == 5);
                REQUIRE(bx.data() != nullptr);

                for (auto& elem : bx)
                    REQUIRE(elem == "h"s);

                bx.clear();

                REQUIRE(bx.empty());
                REQUIRE(bx.size() == 0);
                REQUIRE(bx.num_rows() == 0);
                REQUIRE(bx.num_columns() == 0);
                REQUIRE(bx.data() == nullptr);

                bx.resize(6, 4);

                REQUIRE(!bx.empty());
                REQUIRE(bx.size() == 24);
                REQUIRE(bx.num_rows() == 6);
                REQUIRE(bx.num_columns() == 4);
                REQUIRE(bx.data() != nullptr);

                for (auto& elem : bx)
                    REQUIRE(elem == ""s);
            }
        }

        SECTION("Reshape")
        {
            SECTION("matrix::reshape - correct reshape")
            {
                cxl::matrix<int> bx(4, 6, 1);

                REQUIRE(bx.size() == 24);
                REQUIRE(bx.num_rows() == 4);
                REQUIRE(bx.num_columns() == 6);

                bx.reshape(3, 8);

                REQUIRE(bx.size() == 24);
                REQUIRE(bx.num_rows() == 3);
                REQUIRE(bx.num_columns() == 8);
            }

            SECTION("matrix::reshape - larger reshape")
            {
                cxl::matrix<int> bx(4, 6, 1);

                REQUIRE(bx.size() == 24);
                REQUIRE(bx.num_rows() == 4);
                REQUIRE(bx.num_columns() == 6);

                REQUIRE_THROWS_AS(bx.reshape(4, 8), std::length_error);

                REQUIRE(bx.size() == 24);
                REQUIRE(bx.num_rows() == 4);
                REQUIRE(bx.num_columns() == 6);
            }

            SECTION("matrix::reshape - smaller reshape")
            {
                cxl::matrix<int> bx(4, 6, 1);

                REQUIRE(bx.size() == 24);
                REQUIRE(bx.num_rows() == 4);
                REQUIRE(bx.num_columns() == 6);

                REQUIRE_THROWS_AS(bx.reshape(3, 5), std::length_error);

                REQUIRE(bx.size() == 24);
                REQUIRE(bx.num_rows() == 4);
                REQUIRE(bx.num_columns() == 6);
            }

            SECTION("matrix::reshape - reshape column vector")
            {
                cxl::matrix<int> bx(4, 6, 1);

                REQUIRE(bx.size() == 24);
                REQUIRE(bx.num_rows() == 4);
                REQUIRE(bx.num_columns() == 6);

                bx.reshape(24, 1);

                REQUIRE(bx.size() == 24);
                REQUIRE(bx.num_rows() == 24);
                REQUIRE(bx.num_columns() == 1);
            }

            SECTION("matrix::reshape - reshape column vector")
            {
                cxl::matrix<int> bx(4, 6, 1);

                REQUIRE(bx.size() == 24);
                REQUIRE(bx.num_rows() == 4);
                REQUIRE(bx.num_columns() == 6);

                bx.reshape(1, 24);

                REQUIRE(bx.size() == 24);
                REQUIRE(bx.num_rows() == 1);
                REQUIRE(bx.num_columns() == 24);
            }
        }
    }

    SECTION("box::map")
    {
        SECTION("matrix only Mapping")
        {
            SECTION("Lambda")
            {
                cxl::matrix<int> bx = { { 0, 1 }
                                    , { 2, 3 }
                                    , { 4, 5 }
                                    , { 7, 6 }
                                    , { 8, 9 } };

                cxl::matrix<int> bxcheck = { { 0, 2 }
                                        , { 4, 6 }
                                        , { 8, 10 }
                                        , { 12, 14 }
                                        , { 16, 18 } };

                REQUIRE(bx.size() == 10);
                REQUIRE(bx.num_rows() == 5);
                REQUIRE(bx.num_columns() == 2);

                auto rbx { bx.map([](int i) { return i * 2; }) };

                REQUIRE(bx.size() == 10);
                REQUIRE(bx.num_rows() == 5);
                REQUIRE(bx.num_columns() == 2);

                REQUIRE(rbx.size() == 10);
                REQUIRE(rbx.num_rows() == 5);
            }

            SECTION("Lambda - Empty")
            {
                cxl::matrix<int> bx;

                REQUIRE(bx.empty());
                REQUIRE(bx.size() == 0);
                REQUIRE(bx.num_rows() == 0);
                REQUIRE(bx.num_columns() == 0);

                auto rbx { bx.map([](int i) { return i * 2; }) };

                REQUIRE(rbx.empty());
                REQUIRE(rbx.size() == 0);
                REQUIRE(rbx.num_rows() == 0);
                REQUIRE(rbx.num_columns() == 0);

                REQUIRE(rbx == bx);
            }

            SECTION("Double Call - Intermidiate")
            {
                cxl::matrix<int> bx = { { 0, 1 }
                                    , { 2, 3 }
                                    , { 4, 5 }
                                    , { 6, 7 }
                                    , { 8, 9 } };

                cxl::matrix<int> bxcheck = { { 0, 1 }
                                        , { 2, 3 }
                                        , { 4, 5 }
                                        , { 6, 7 }
                                        , { 8, 9 } };

                cxl::matrix<int> ibxcheck = { { 0, 2 }
                                            , { 4, 6 }
                                            , { 8, 10 }
                                            , { 12, 14 }
                                            , { 16, 18 } };

                cxl::matrix<int> rbxcheck = { { -3, -1 }
                                            , { -7, -5 }
                                            , { -11, -9 }
                                            , { -15, -13 }
                                            , { -19, -17 } };

                REQUIRE(bx.size() == 10);
                REQUIRE(bx.num_rows() == 5);
                REQUIRE(bx.num_columns() == 2);

                auto ibx { bx.map([](int i) { return i * 2; }) };

                REQUIRE(bx == bxcheck);

                REQUIRE(ibx.size() == 10);
                REQUIRE(ibx.num_rows() == 5);
                REQUIRE(ibx.num_columns() == 2);
                REQUIRE(ibx == ibxcheck);

                auto rbx { ibx.map([](int i) { return i ^ -3; }) };

                REQUIRE(ibx == ibxcheck);

                REQUIRE(rbx.size() == 10);
                REQUIRE(rbx.num_rows() == 5);
                REQUIRE(rbx.num_columns() == 2);
                REQUIRE(rbx == rbxcheck);
            }

            SECTION("Double Call - Chained")
            {
                cxl::matrix<int> bx = { { 0, 1 }
                                    , { 2, 3 }
                                    , { 4, 5 }
                                    , { 6, 7 }
                                    , { 8, 9 } };

                cxl::matrix<int> bxcheck = { { 0, 1 }
                                        , { 2, 3 }
                                        , { 4, 5 }
                                        , { 6, 7 }
                                        , { 8, 9 } };

                cxl::matrix<int> rbxcheck = { { -3, -1 }
                                            , { -7, -5 }
                                            , { -11, -9 }
                                            , { -15, -13 }
                                            , { -19, -17 } };

                REQUIRE(bx.size() == 10);
                REQUIRE(bx.num_rows() == 5);
                REQUIRE(bx.num_columns() == 2);

                auto rbx { bx.map([](int i) { return i * 2; }).map([](int i) { return i ^ -3; }) };

                REQUIRE(bx == bxcheck);

                REQUIRE(rbx.size() == 10);
                REQUIRE(rbx.num_rows() == 5);
                REQUIRE(rbx.num_columns() == 2);
                REQUIRE(rbx == rbxcheck);
            }

            SECTION("Named Lambda")
            {
                cxl::matrix<int> bx = { { 0, 1 }
                                    , { 2, 3 }
                                    , { 4, 5 }
                                    , { 6, 7 }
                                    , { 8, 9 } };

                auto square = [](const auto& i) { return i * i; };

                cxl::matrix<int> bxcheck = { { 0, 1 }
                                        , { 4, 9 }
                                        , { 16, 25 }
                                        , { 36, 49 }
                                        , { 64, 81 } };

                REQUIRE(bx.size() == 10);
                REQUIRE(bx.num_rows() == 5);
                REQUIRE(bx.num_columns() == 2);

                auto rbx { bx.map(square) };

                REQUIRE(bx.size() == 10);
                REQUIRE(bx.num_rows() == 5);
                REQUIRE(bx.num_columns() == 2);

                REQUIRE(rbx.size() == 10);
                REQUIRE(rbx.num_rows() == 5);
            }
        }

        SECTION("matrix and Range")
        {
            SECTION("Lambda - With matrix")  
            {
                cxl::matrix<int> bx = { { 0, 1 }
                                    , { 2, 3 }
                                    , { 4, 5 }
                                    , { 6, 7 }
                                    , { 8, 9 } };

                cxl::matrix<int> bxcheck = { { 0, 1 }
                                        , { 2, 3 }
                                        , { 4, 5 }
                                        , { 6, 7 }
                                        , { 8, 9 } };

                cxl::matrix<int> rbxcheck = { { 0, 2 }
                                            , { 48, -3 }
                                            , { -12, 280 }
                                            , { -24, 14 }
                                            , { -40, 36 } };

                REQUIRE(bx.size() == 10);
                REQUIRE(bx.shape() == std::tuple{ 5, 2 });
                REQUIRE(bx == bxcheck);

                cxl::matrix<int> x = { { 5, 2 }
                                    , { 24, -1 }
                                    , { -3, 56 }
                                    , { -4, 2 }
                                    , { -5, 4 } };

                auto rbx { bx.map(x, [](auto e, auto x) { return e * x; }) };

                REQUIRE(rbx.size() == 10);
                REQUIRE(rbx.shape() == std::tuple{ 5, 2 });
                REQUIRE(rbx == rbxcheck);
            }

            SECTION("Lambda - With Other Range")
            {
                cxl::matrix<int> bx = { { 0, 1 }
                                    , { 2, 3 }
                                    , { 4, 5 }
                                    , { 6, 7 }
                                    , { 8, 9 } };

                cxl::matrix<int> bxcheck = { { 0, 1 }
                                        , { 2, 3 }
                                        , { 4, 5 }
                                        , { 6, 7 }
                                        , { 8, 9 } };

                cxl::matrix<int> rbxcheck = { { 0, 2 }
                                            , { 48, -3 }
                                            , { -12, 280 }
                                            , { -24, 14 }
                                            , { -40, 36 } };

                REQUIRE(bx.size() == 10);
                REQUIRE(bx.shape() == std::tuple{ 5, 2 });
                REQUIRE(bx == bxcheck);

                std::vector<int> v = { 5, 2, 24, -1, -3, 56,-4, 2, -5, 4 };

                auto rbx { bx.map(v, [](auto x, auto v) { return x * v; }) };

                REQUIRE(rbx.size() == 10);
                REQUIRE(rbx.shape() == std::tuple{ 5, 2 });
                REQUIRE(rbx == rbxcheck);
            }

            SECTION("Named Lambda")
            {
                cxl::matrix<int> bx = { { 0, 1 }
                                    , { 2, 3 }
                                    , { 4, 5 }
                                    , { 6, 7 }
                                    , { 8, 9 } };

                auto add = [](const auto& x, const auto& y) { return x + y; };

                cxl::matrix<int> bxcheck = { { 0, 1 }
                                        , { 2, 3 }
                                        , { 4, 5 }
                                        , { 6, 7 }
                                        , { 8, 9 } };

                cxl::matrix<int> rbxcheck = { { 5, 3 }
                                            , { 26, 2 }
                                            , { 1, 61 }
                                            , { 2, 9 }
                                            , { 3, 13 } };

                REQUIRE(bx.size() == 10);
                REQUIRE(bx.shape() == std::tuple{ 5, 2 });
                REQUIRE(bx == bxcheck);

                cxl::matrix<int> x = { { 5, 2 }
                                    , { 24, -1 }
                                    , { -3, 56 }
                                    , { -4, 2 }
                                    , { -5, 4 } };

                auto rbx { bx.map(x, add) };

                REQUIRE(rbx.size() == 10);
                REQUIRE(rbx.shape() == std::tuple{ 5, 2 });
                REQUIRE(rbx == rbxcheck);
            }
        }

        SECTION("matrix and Iterators")
        {
            SECTION("Lambda - With matrix")  
            {
                cxl::matrix<int> bx = { { 0, 1 }
                                    , { 2, 3 }
                                    , { 4, 5 }
                                    , { 6, 7 }
                                    , { 8, 9 } };

                cxl::matrix<int> bxcheck = { { 0, 1 }
                                        , { 2, 3 }
                                        , { 4, 5 }
                                        , { 6, 7 }
                                        , { 8, 9 } };

                cxl::matrix<int> rbxcheck = { { 0, 2 }
                                            , { 48, -3 }
                                            , { -12, 280 }
                                            , { -24, 14 }
                                            , { -40, 36 } };

                REQUIRE(bx.size() == 10);
                REQUIRE(bx.shape() == std::tuple{ 5, 2 });
                REQUIRE(bx == bxcheck);

                cxl::matrix<int> x = { { 5, 2 }
                                    , { 24, -1 }
                                    , { -3, 56 }
                                    , { -4, 2 }
                                    , { -5, 4 } };

                auto rbx { bx.map(x.begin(), x.end(), [](auto e, auto x) { return e * x; }) };

                REQUIRE(rbx.size() == 10);
                REQUIRE(rbx.shape() == std::tuple{ 5, 2 });
                REQUIRE(rbx == rbxcheck);
            }

            SECTION("Lambda - With Other Container")
            {
                cxl::matrix<int> bx = { { 0, 1 }
                                    , { 2, 3 }
                                    , { 4, 5 }
                                    , { 6, 7 }
                                    , { 8, 9 } };

                cxl::matrix<int> bxcheck = { { 0, 1 }
                                        , { 2, 3 }
                                        , { 4, 5 }
                                        , { 6, 7 }
                                        , { 8, 9 } };

                cxl::matrix<int> rbxcheck = { { 0, 2 }
                                            , { 48, -3 }
                                            , { -12, 280 }
                                            , { -24, 14 }
                                            , { -40, 36 } };

                REQUIRE(bx.size() == 10);
                REQUIRE(bx.shape() == std::tuple{ 5, 2 });
                REQUIRE(bx == bxcheck);

                std::vector<int> v = { 5, 2, 24, -1, -3, 56,-4, 2, -5, 4 };

                auto rbx { bx.map(v.begin(), v.end(), [](auto x, auto v) { return x * v; }) };

                REQUIRE(rbx.size() == 10);
                REQUIRE(rbx.shape() == std::tuple{ 5, 2 });
                REQUIRE(rbx == rbxcheck);
            }

            SECTION("Named Lambda")
            {
                cxl::matrix<int> bx = { { 0, 1 }
                                    , { 2, 3 }
                                    , { 4, 5 }
                                    , { 6, 7 }
                                    , { 8, 9 } };

                auto add = [](const auto& x, const auto& y) { return x + y; };

                cxl::matrix<int> bxcheck = { { 0, 1 }
                                        , { 2, 3 }
                                        , { 4, 5 }
                                        , { 6, 7 }
                                        , { 8, 9 } };

                cxl::matrix<int> rbxcheck = { { 5, 3 }
                                            , { 26, 2 }
                                            , { 1, 61 }
                                            , { 2, 9 }
                                            , { 3, 13 } };

                REQUIRE(bx.size() == 10);
                REQUIRE(bx.shape() == std::tuple{ 5, 2 });
                REQUIRE(bx == bxcheck);

                cxl::matrix<int> x = { { 5, 2 }
                                    , { 24, -1 }
                                    , { -3, 56 }
                                    , { -4, 2 }
                                    , { -5, 4 } };

                auto rbx { bx.map(x.begin(), x.end(), add) };

                REQUIRE(rbx.size() == 10);
                REQUIRE(rbx.shape() == std::tuple{ 5, 2 });
                REQUIRE(rbx == rbxcheck);
            }
        }
    }

    SECTION("box::transpose")
    {
        // SECTION("box::transpose - Normal")
        // {
        //     cxl::box<int> bx = { { 0, 1 }
        //                             , { 2, 3 }
        //                             , { 4, 5 }
        //                             , { 7, 6 }
        //                             , { 8, 9 } };

        //     cxl::box<int> bxcheck = { { 0, 2, 4, 7, 8 }
        //                                 , { 1, 3, 5, 6, 9 } };

        //     REQUIRE(bx.size() == 10);
        //     REQUIRE(bx.rows() == 5);
        //     REQUIRE(bx.columns() == 2);

        //     auto rbx { bx.transpose() };

        //     REQUIRE(bx.size() == 10);
        //     REQUIRE(bx.rows() == 5);
        //     REQUIRE(bx.columns() == 2);

        //     REQUIRE(rbx.size() == 10);
        //     REQUIRE(rbx.rows() == 2);
        //     REQUIRE(rbx.columns() == 5);

        //     REQUIRE(rbx == bxcheck);
        // }

        // SECTION("box::transpose - Double transpose")
        // {
        //     cxl::box<int> bx = { { 0, 1 }
        //                             , { 2, 3 }
        //                             , { 4, 5 }
        //                             , { 7, 6 }
        //                             , { 8, 9 } };

        //     cxl::box<int> bxcheck = { { 0, 2, 4, 7, 8 }
        //                                 , { 1, 3, 5, 6, 9 } };

        //     REQUIRE(bx.size() == 10);
        //     REQUIRE(bx.rows() == 5);
        //     REQUIRE(bx.columns() == 2);

        //     auto rbx { bx.transpose() };

        //     REQUIRE(bx.size() == 10);
        //     REQUIRE(bx.rows() == 5);
        //     REQUIRE(bx.columns() == 2);

        //     REQUIRE(rbx.size() == 10);
        //     REQUIRE(rbx.rows() == 2);
        //     REQUIRE(rbx.columns() == 5);

        //     REQUIRE(rbx == bxcheck);

        //     auto rrbx { rbx.transpose() };

        //     REQUIRE(rbx.size() == 10);
        //     REQUIRE(rbx.rows() == 2);
        //     REQUIRE(rbx.columns() == 5);

        //     REQUIRE(rrbx == bx);
        // }

        // SECTION("box::transpose - Double transpose in-place")
        // {
        //     cxl::box<int> bx = { { 0, 1 }
        //                           , { 2, 3 }
        //                           , { 4, 5 }
        //                           , { 7, 6 }
        //                           , { 8, 9 } };

        //     cxl::box<int> bxcheck = { { 0, 2, 4, 7, 8 }
        //                                , { 1, 3, 5, 6, 9 } };

        //     REQUIRE(bx.size() == 10);
        //     REQUIRE(bx.rows() == 5);
        //     REQUIRE(bx.columns() == 2);

        //     auto rbx { bx.transpose().transpose() };

        //     REQUIRE(rbx.size() == 10);
        //     REQUIRE(rbx.rows() == 5);
        //     REQUIRE(rbx.columns() == 2);

        //     REQUIRE(rbx == bx);
        // }

        // SECTION("box::transpose - Empty")
        // {
        //     cxl::box<int> bx;

        //     REQUIRE(bx.empty());
        //     REQUIRE(bx.size() == 0);
        //     REQUIRE(bx.rows() == 0);
        //     REQUIRE(bx.columns() == 0);

        //     auto rbx { bx.transpose() };

        //     REQUIRE(rbx.size() == 0);
        //     REQUIRE(rbx.rows() == 0);
        //     REQUIRE(rbx.columns() == 0);

        //     REQUIRE(rbx == bx);
        // }

        // SECTION("box::transpose - Column to Row")
        // {
        //     cxl::box<int> bx = { { 5, 1 } };

        //     cxl::box<int> bxcheck = { { 5 }
        //                                , { 1 } };

        //     REQUIRE(bx.size() == 2);
        //     REQUIRE(bx.rows() == 1);
        //     REQUIRE(bx.columns() == 2);

        //     auto rbx { bx.transpose() };

        //     REQUIRE(rbx.size() == 2);
        //     REQUIRE(rbx.rows() == 2);
        //     REQUIRE(rbx.columns() == 1);

        //     REQUIRE(rbx == bxcheck);
        // }

        // SECTION("box::transpose - Row to Column")
        // {
        //     cxl::box<int> bx = { { 54 }
        //                             , { 73 } 
        //                             , { 12 } };

        //     cxl::box<int> bxcheck = { { 54, 73, 12} };

        //     REQUIRE(bx.size() == 3);
        //     REQUIRE(bx.rows() == 3);
        //     REQUIRE(bx.columns() == 1);

        //     auto rbx { bx.transpose() };

        //     REQUIRE(rbx.size() == 3);
        //     REQUIRE(rbx.rows() == 1);
        //     REQUIRE(rbx.columns() == 3);

        //     REQUIRE(rbx == bxcheck);
        // }

        // SECTION("box::transpose - Single Element")
        // {
        //     cxl::box<int> bx = { { 5 } };

        //     REQUIRE(bx.size() == 1);
        //     REQUIRE(bx.rows() == 1);
        //     REQUIRE(bx.columns() == 1);

        //     auto rbx { bx.transpose() };

        //     REQUIRE(rbx.size() == 1);
        //     REQUIRE(rbx.rows() == 1);
        //     REQUIRE(rbx.columns() == 1);

        //     REQUIRE(rbx == bx);
        // }
    }

    SECTION("box::vflip")
    {
    //     SECTION("box::vflip - Empty")
    //     {
    //         cxl::box<int> bx;

    //         REQUIRE(bx.empty());
    //         REQUIRE(bx.size() == 0);
    //         REQUIRE(bx.rows() == 0);
    //         REQUIRE(bx.columns() == 0);

    //         auto rbx { bx.vflip() };

    //         REQUIRE(rbx.empty());
    //         REQUIRE(rbx.size() == 0);
    //         REQUIRE(rbx.rows() == 0);
    //         REQUIRE(rbx.columns() == 0);

    //         REQUIRE(rbx == bx);
    //     }

    //     SECTION("box::vflip - Single")
    //     {
    //         cxl::box<int> bx = { { 0 } };

    //         cxl::box<int> bxcheck = { { 0 } };

    //         cxl::box<int> rbxcheck = { { 0 } };

    //         REQUIRE(bx.size() == 1);
    //         REQUIRE(bx.rows() == 1);
    //         REQUIRE(bx.columns() == 1);

    //         auto rbx { bx.vflip() };

    //         REQUIRE(bx == bxcheck);

    //         REQUIRE(rbx.size() == 1);
    //         REQUIRE(rbx.rows() == 1);
    //         REQUIRE(rbx.columns() == 1);
    //         REQUIRE(rbx == rbxcheck);

    //         REQUIRE(rbx == bx);

    //         REQUIRE(rbx.vflip() == bx);
    //     }

    //     SECTION("box::vflip - Shaped")
    //     {
    //         cxl::box<int> bx = { { 0, 1 }
    //                               , { 2, 3 }
    //                               , { 4, 5 }
    //                               , { 6, 7 }
    //                               , { 8, 9 } };

    //         cxl::box<int> bxcheck = { { 0, 1 }
    //                                    , { 2, 3 }
    //                                    , { 4, 5 }
    //                                    , { 6, 7 }
    //                                    , { 8, 9 } };

    //         cxl::box<int> rbxcheck = { { 8, 9 }
    //                                     , { 6, 7 }
    //                                     , { 4, 5 }
    //                                     , { 2, 3 }
    //                                     , { 0, 1 } };

    //         REQUIRE(bx.size() == 10);
    //         REQUIRE(bx.dimensions() == std::tuple{5, 2});

    //         auto rbx { bx.vflip() };

    //         REQUIRE(bx == bxcheck);

    //         REQUIRE(rbx.size() == 10);
    //         REQUIRE(rbx.dimensions() == std::tuple{5, 2});
    //         REQUIRE(rbx == rbxcheck);

    //         REQUIRE(rbx.vflip() == bx);
    //     }
    }

    SECTION("box::hflip")
    {
    //     SECTION("box::hflip - Empty")
    //     {
    //         cxl::box<int> bx;

    //         REQUIRE(bx.empty());
    //         REQUIRE(bx.size() == 0);
    //         REQUIRE(bx.rows() == 0);
    //         REQUIRE(bx.columns() == 0);

    //         auto rbx { bx.hflip() };

    //         REQUIRE(rbx.empty());
    //         REQUIRE(rbx.size() == 0);
    //         REQUIRE(rbx.rows() == 0);
    //         REQUIRE(rbx.columns() == 0);

    //         REQUIRE(rbx == bx);
    //     }

    //     SECTION("box::hflip - Single")
    //     {
    //         cxl::box<int> bx = { { 0 } };

    //         cxl::box<int> bxcheck = { { 0 } };

    //         cxl::box<int> rbxcheck = { { 0 } };

    //         REQUIRE(bx.size() == 1);
    //         REQUIRE(bx.rows() == 1);
    //         REQUIRE(bx.columns() == 1);

    //         auto rbx { bx.hflip() };

    //         REQUIRE(bx == bxcheck);

    //         REQUIRE(rbx.size() == 1);
    //         REQUIRE(rbx.rows() == 1);
    //         REQUIRE(rbx.columns() == 1);
    //         REQUIRE(rbx == rbxcheck);

    //         REQUIRE(rbx == bx);

    //         REQUIRE(rbx.hflip() == bx);
    //     }

    //     SECTION("box::hflip - Shaped")
    //     {
    //         cxl::box<int> bx = { { 0, 1 }
    //                               , { 2, 3 }
    //                               , { 4, 5 }
    //                               , { 6, 7 }
    //                               , { 8, 9 } };

    //         cxl::box<int> bxcheck = { { 0, 1 }
    //                                    , { 2, 3 }
    //                                    , { 4, 5 }
    //                                    , { 6, 7 }
    //                                    , { 8, 9 } };

    //         cxl::box<int> rbxcheck = { { 1, 0 }
    //                                     , { 3, 2 }
    //                                     , { 5, 4 }
    //                                     , { 7, 6 }
    //                                     , { 9, 8 } };

    //         REQUIRE(bx.size() == 10);
    //         REQUIRE(bx.dimensions() == std::tuple{5, 2});

    //         REQUIRE(bx == bxcheck);

    //         auto rbx { bx.hflip() };

    //         REQUIRE(rbx.size() == 10);
    //         REQUIRE(rbx.dimensions() == std::tuple{5, 2});
    //         REQUIRE(rbx == rbxcheck);

    //         REQUIRE(rbx.hflip() == bx);
    //     }
    }

    SECTION("box::rrotate")
    {
    //     SECTION("box::rrotate - Empty")
    //     {
    //         cxl::box<int> bx;

    //         REQUIRE(bx.empty());
    //         REQUIRE(bx.size() == 0);
    //         REQUIRE(bx.rows() == 0);
    //         REQUIRE(bx.columns() == 0);

    //         auto rbx { bx.rrotate() };

    //         REQUIRE(rbx.empty());
    //         REQUIRE(rbx.size() == 0);
    //         REQUIRE(rbx.rows() == 0);
    //         REQUIRE(rbx.columns() == 0);

    //         REQUIRE(rbx == bx);
    //     }

    //     SECTION("box::rrotate - Single")
    //     {
    //         cxl::box<int> bx = { { 0 } };

    //         cxl::box<int> bxcheck = { { 0 } };

    //         cxl::box<int> rbxcheck = { { 0 } };

    //         REQUIRE(bx.size() == 1);
    //         REQUIRE(bx.rows() == 1);
    //         REQUIRE(bx.columns() == 1);

    //         auto rbx { bx.rrotate() };

    //         REQUIRE(bx == bxcheck);

    //         REQUIRE(rbx.size() == 1);
    //         REQUIRE(rbx.rows() == 1);
    //         REQUIRE(rbx.columns() == 1);
    //         REQUIRE(rbx == rbxcheck);

    //         REQUIRE(rbx == bx);

    //         REQUIRE(rbx.rrotate() == bx);
    //     }

    //     SECTION("box::rrotate - Shaped")
    //     {
    //         cxl::box<int> bx = { { 0, 1 }
    //                               , { 2, 3 }
    //                               , { 4, 5 }
    //                               , { 6, 7 }
    //                               , { 8, 9 } };

    //         cxl::box<int> bxcheck = { { 0, 1 }
    //                                    , { 2, 3 }
    //                                    , { 4, 5 }
    //                                    , { 6, 7 }
    //                                    , { 8, 9 } };

    //         cxl::box <int> rbxcheck = { { 8, 6, 4, 2, 0 }
    //                                      , { 9, 7, 5, 3, 1 } };

    //         REQUIRE(bx.size() == 10);
    //         REQUIRE(bx.dimensions() == std::tuple{5, 2});

    //         REQUIRE(bx == bxcheck);

    //         auto rbx { bx.rrotate() };

    //         REQUIRE(rbx.size() == 10);
    //         REQUIRE(rbx.dimensions() == std::tuple{2, 5});

    //         REQUIRE(rbx == rbxcheck);

    //         REQUIRE(rbx.lrotate() == bx);
    //     }
    }

    SECTION("box::lrotate")
    {
    //     SECTION("box::lrotate - Empty")
    //     {
    //         cxl::box<int> bx;

    //         REQUIRE(bx.empty());
    //         REQUIRE(bx.size() == 0);
    //         REQUIRE(bx.rows() == 0);
    //         REQUIRE(bx.columns() == 0);

    //         auto rbx { bx.lrotate() };

    //         REQUIRE(rbx.empty());
    //         REQUIRE(rbx.size() == 0);
    //         REQUIRE(rbx.rows() == 0);
    //         REQUIRE(rbx.columns() == 0);

    //         REQUIRE(rbx == bx);
    //     }

    //     SECTION("box::lrotate - Single")
    //     {
    //         cxl::box<int> bx = { { 0 } };

    //         cxl::box<int> bxcheck = { { 0 } };

    //         cxl::box<int> rbxcheck = { { 0 } };

    //         REQUIRE(bx.size() == 1);
    //         REQUIRE(bx.rows() == 1);
    //         REQUIRE(bx.columns() == 1);

    //         auto rbx { bx.lrotate() };

    //         REQUIRE(bx == bxcheck);

    //         REQUIRE(rbx.size() == 1);
    //         REQUIRE(rbx.rows() == 1);
    //         REQUIRE(rbx.columns() == 1);
    //         REQUIRE(rbx == rbxcheck);

    //         REQUIRE(rbx == bx);

    //         REQUIRE(rbx.lrotate() == bx);
    //     }

    //     SECTION("box::lrotate - Shaped")
    //     {
    //         cxl::box<int> bx = { { 0, 1 }
    //                               , { 2, 3 }
    //                               , { 4, 5 }
    //                               , { 6, 7 }
    //                               , { 8, 9 } };

    //         cxl::box<int> bxcheck = { { 0, 1 }
    //                                    , { 2, 3 }
    //                                    , { 4, 5 }
    //                                    , { 6, 7 }
    //                                    , { 8, 9 } };

    //         cxl::box <int> rbxcheck = { { 1, 3, 5, 7, 9 }
    //                                      , { 0, 2, 4, 6, 8 } };
            
    //         REQUIRE(bx.size() == 10);
    //         REQUIRE(bx.dimensions() == std::tuple{5, 2});

    //         REQUIRE(bx == bxcheck);

    //         auto rbx { bx.lrotate() };

    //         REQUIRE(rbx.size() == 10);
    //         REQUIRE(rbx.dimensions() == std::tuple{2, 5});

    //         REQUIRE(rbx == rbxcheck);

    //         REQUIRE(rbx.rrotate() == bx);
    //     }
    }
}

TEST_CASE("Iterators")
{
    SECTION("Normal Iterators")
    {

        SECTION("Range for-loop")
        {
            cxl::matrix<int> bx(4, 5, 1);

            for (auto& elem : bx)
            {
                REQUIRE(elem == 1);
                elem = 2;
            }

            for (auto& elem : bx)
                REQUIRE(elem == 2);
        }

        SECTION("matrix::begin and matrix::end")
        {
            cxl::matrix<int> bx(4, 5);

            std::iota(bx.begin(), bx.end(), 1);

            auto value { 1 };
            for (auto& elem : bx)
            {
                REQUIRE(elem == value++);
                elem = 2 * elem;
            }

            value = 1;
            for (auto& elem : bx)
            {
                REQUIRE(elem == value * 2);
                ++value;
            }
        }
    }

    SECTION("Reverse Iterators")
    {
        SECTION("range-for reversed")
        {
            cxl::matrix<int> bx = { { 1, 2 }
                                , { 3, 4 } };

            std::reverse(bx.begin(), bx.end());

            for (auto v { 4 }; auto& elem : bx)
            
                REQUIRE(elem == v--);
        }

        SECTION("matrix::rbegin and matrix::rend")
        {
            cxl::matrix<int> bx(4, 5);

            std::iota(bx.begin(), bx.end(), 1);

            auto value { 20 };
            std::reverse(bx.begin(), bx.end());

            for (auto& elem : bx)
            {
                REQUIRE(elem == value--);
                elem *= 2;
            }

            value = 20;
            std::reverse(bx.begin(), bx.end());
            std::reverse(bx.begin(), bx.end());
            
            for (auto& elem : bx)
                REQUIRE(elem == 2 * value--);
        }
    }
}

TEST_CASE("Element Access")
{
    SECTION("Raw Data")
    {
        SECTION("matrix::data")
        {
            cxl::matrix<int> bx(4, 5, 1);
            REQUIRE(bx.data() != nullptr);
        }

        SECTION("matrix::front")
        {
            cxl::matrix<int> bx(4, 5, 1);
            REQUIRE(bx.front() == 1);

            bx.front() = 2;
            REQUIRE(bx.front() == 2);
        }

        SECTION("matrix::back")
        {
            cxl::matrix<int> bx(4, 5, 1);
            REQUIRE(bx.back() == 1);

            bx.back() = 2;
            REQUIRE(bx.back() == 2);
        }
    }

    SECTION("Accessors")
    {
        SECTION("matrix::at")
        {
            cxl::matrix<int> bx(4, 5, 1);
            REQUIRE(bx.at(0, 1) == 1);

            bx.at(0, 1) = 2;
            REQUIRE(bx.at(0, 1) == 2);

            REQUIRE_THROWS_AS(bx.at(10, 1), std::out_of_range);
        }

        SECTION("matrix::operator()")
        {
            cxl::matrix<int> bx(4, 5, 1);
            REQUIRE(bx(0, 1) == 1);

            bx(1, 1) = 2;
            REQUIRE(bx(1, 1) == 2);

            REQUIRE_THROWS_AS(bx(4, 1), std::out_of_range);
        }
    }
}

TEST_CASE("Operators")
{
    SECTION("Comparisons")
    {
        SECTION("Equality")
        {
            SECTION("Equal")
            {
                cxl::matrix<int> bx(4, 5, 1);
                cxl::matrix<int> nbx(4, 5, 1);

                REQUIRE(bx == bx);
                REQUIRE(bx == nbx);
            }

            SECTION("Different size")
            {
                cxl::matrix<int> bx(5, 8, 1);
                cxl::matrix<int> nbx(4, 13, 1);

                REQUIRE(bx != nbx);
                REQUIRE(nbx != bx);
            }
        }

        SECTION("Inequality")
        {
            SECTION("Not Equal")
            {
                cxl::matrix<int> bx(4, 5, 1);
                cxl::matrix<int> nbx(4, 5, 2);

                REQUIRE(bx != nbx);
                REQUIRE(nbx != bx);
            }

            SECTION("Different size")
            {
                cxl::matrix<int> bx(13, 6, 1);
                cxl::matrix<int> nbx(17, 11, 1);

                REQUIRE(bx != nbx);
                REQUIRE(nbx != bx);
            }

            SECTION("Different data")
            {
                cxl::matrix<int> bx(4, 5, 1);
                cxl::matrix<int> nbx(4, 5, 2);

                REQUIRE(bx != nbx);
                REQUIRE(nbx != bx);
            }

            SECTION("Different data and size")
            {
                cxl::matrix<int> bx(13, 6, 1);
                cxl::matrix<int> nbx(17, 11, 2);

                REQUIRE(bx != nbx);
                REQUIRE(nbx != bx);
            }
        }

        SECTION("Less Than")
        {
            SECTION("Different data")
            {
                cxl::matrix<int> bx(4, 5, 1);
                cxl::matrix<int> nbx(4, 5, 2);

                REQUIRE(bx < nbx);
                REQUIRE(!(nbx < bx));
            }

            SECTION("Different size")
            {
                cxl::matrix<int> bx(13, 6, 1);
                cxl::matrix<int> nbx(17, 11, 1);

                REQUIRE(bx < nbx);
                REQUIRE(!(nbx < bx));
            }

            SECTION("Different data and size")
            {
                cxl::matrix<int> bx(13, 6, 2);
                cxl::matrix<int> nbx(17, 11, 1);

                REQUIRE(!(bx < nbx));
                REQUIRE(nbx < bx);
            }

            SECTION("Same data")
            {
                cxl::matrix<int> bx(4, 5, 1);
                cxl::matrix<int> nbx(4, 5, 1);

                REQUIRE(!(bx < nbx));
                REQUIRE(!(nbx < bx));
            }
        }

        SECTION("Greater Than")
        {
            SECTION("Different data")
            {
                cxl::matrix<int> bx(4, 5, 1);
                cxl::matrix<int> nbx(4, 5, 2);

                REQUIRE(nbx > bx);
                REQUIRE(!(bx > nbx));
            }

            SECTION("Different size")
            {
                cxl::matrix<int> bx(13, 6, 1);
                cxl::matrix<int> nbx(17, 11, 1);

                REQUIRE(nbx > bx);
                REQUIRE(!(bx > nbx));
            }

            SECTION("Different data and size")
            {
                cxl::matrix<int> bx(13, 6, 2);
                cxl::matrix<int> nbx(17, 11, 1);

                REQUIRE(bx > nbx);
                REQUIRE(!(nbx > bx));
            }

            SECTION("Same data")
            {
                cxl::matrix<int> bx(4, 5, 1);
                cxl::matrix<int> nbx(4, 5, 1);

                REQUIRE(!(nbx > bx));
                REQUIRE(!(bx > nbx));
            }
        }

        SECTION("Less Than or Equal")
        {
            SECTION("Different data")
            {
                cxl::matrix<int> bx(4, 5, 1);
                cxl::matrix<int> nbx(4, 5, 2);

                REQUIRE(bx <= nbx);
                REQUIRE(!(nbx <= bx));
            }

            SECTION("Different size")
            {
                cxl::matrix<int> bx(13, 6, 1);
                cxl::matrix<int> nbx(17, 11, 1);

                REQUIRE(bx <= nbx);
                REQUIRE(!(nbx <= bx));
            }

            SECTION("Different data and size")
            {
                cxl::matrix<int> bx(13, 6, 2);
                cxl::matrix<int> nbx(17, 11, 1);

                REQUIRE(bx > nbx);
                REQUIRE(nbx <= bx);
            }

            SECTION("Same data")
            {
                cxl::matrix<int> bx(4, 5, 1);
                cxl::matrix<int> nbx(4, 5, 1);

                REQUIRE(bx <= nbx);
                REQUIRE(nbx <= bx);
            }
        }

        SECTION("Greater Than or Equal")
        {
            SECTION("Different data")
            {
                cxl::matrix<int> bx(4, 5, 1);
                cxl::matrix<int> nbx(4, 5, 2);

                REQUIRE(nbx >= bx);
                REQUIRE(!(bx >= nbx));
            }

            SECTION("Different size")
            {
                cxl::matrix<int> bx(13, 6, 1);
                cxl::matrix<int> nbx(17, 11, 1);

                REQUIRE(nbx >= bx);
                REQUIRE(!(bx >= nbx));
            }

            SECTION("Different data and size")
            {
                cxl::matrix<int> bx(13, 6, 2);
                cxl::matrix<int> nbx(17, 11, 1);

                REQUIRE(bx >= nbx);
                REQUIRE(!(nbx >= bx));
            }

            SECTION("Same data")
            {
                cxl::matrix<int> bx(4, 5, 1);
                cxl::matrix<int> nbx(4, 5, 1);

                REQUIRE(bx >= nbx);
                REQUIRE(nbx >= bx);
            }
        }
    }

    SECTION("Functional")
    {
        SECTION("Map")
        {
            SECTION("Map - Lambda")
            {
                cxl::matrix<int> a = { { 1, 2 }
                                    , { 3, 4 }
                                    , { 5, 6 }
                                    , { 7, 8 } };

                REQUIRE(a.size() == 8);
                REQUIRE(a.shape() == std::tuple{4, 2});

                auto b { a || [](const auto& i) { return i * 2; } };

                REQUIRE(b.size() == 8);
                REQUIRE(b.shape() == std::tuple{4, 2});
                REQUIRE(b == cxl::matrix<int> { { 2, 4 }
                                            , { 6, 8 }
                                            , { 10, 12 }
                                            , { 14, 16 } });
            }

            SECTION("Map - Named Lambda")
            {
                cxl::matrix<int> a = { { 1, 2 }
                                    , { 3, 4 }
                                    , { 5, 6 }
                                    , { 7, 8 } };

                auto xor_3 = [](const auto& i) { return i ^ 3; };

                REQUIRE(a.size() == 8);
                REQUIRE(a.shape() == std::tuple{4, 2});

                auto b { a || xor_3 };

                REQUIRE(b.size() == 8);
                REQUIRE(b.shape() == std::tuple{4, 2});
                REQUIRE(b == cxl::matrix<int> { { 2, 1 }
                                            , { 0, 7 }
                                            , { 6, 5 }
                                            , { 4, 11 } });
            }

            SECTION("Map - Chained Lambdas")
            {
                cxl::matrix<int> a = { { 1, 2 }
                                    , { 3, 4 }
                                    , { 5, 6 }
                                    , { 7, 8 } };

                REQUIRE(a.size() == 8);
                REQUIRE(a.shape() == std::tuple{4, 2});

                auto b { a || [](const auto& i) { return i * 2; } 
                            || [](const auto& i) { return i ^ 3; } };

                REQUIRE(b.size() == 8);
                REQUIRE(b.shape() == std::tuple{4, 2});
                REQUIRE(b == cxl::matrix<int> { { 1, 7 }
                                            , { 5, 11 }
                                            , { 9, 15 }
                                            , { 13, 19 } });
            }

            SECTION("Map - Chained Named Lambdas")
            {
                cxl::matrix<int> a = { { 1, 2 }
                                    , { 3, 4 }
                                    , { 5, 6 }
                                    , { 7, 8 } };

                auto square = [](const auto& i) { return i * 2; };
                auto xor_3 = [](const auto& i) { return i ^ 3; };

                REQUIRE(a.size() == 8);
                REQUIRE(a.shape() == std::tuple{4, 2});

                auto b { a || square 
                            || xor_3 };

                REQUIRE(b.size() == 8);
                REQUIRE(b.shape() == std::tuple{4, 2});
                REQUIRE(b == cxl::matrix<int> { { 1, 7 }
                                            , { 5, 11 }
                                            , { 9, 15 }
                                            , { 13, 19 } });
            }
        }
    
        SECTION("Transpose")
        {
        //     SECTION("Simple Transpose")
        //     {
        //         cxl::box<int> a = { { 1, 2 }
        //                             , { 3, 4 }
        //                             , { 5, 6 }
        //                             , { 7, 8 } };

        //         REQUIRE(a.size() == 8);
        //         REQUIRE(a.dimensions() == std::tuple{4, 2});

        //         auto b { !a };

        //         REQUIRE(b.size() == 8);
        //         REQUIRE(b.dimensions() == std::tuple{2, 4});
        //         REQUIRE(b == cxl::box<int> { { 1, 3, 5, 7 }
        //                                     , { 2, 4, 6, 8 } });
        //     }

        //     SECTION("Transpose Empty")
        //     {
        //         cxl::box<int> a;

        //         REQUIRE(a.size() == 0);
        //         REQUIRE(a.dimensions() == std::tuple{0, 0});

        //         auto b { !a };

        //         REQUIRE(b.size() == 0);
        //         REQUIRE(b.dimensions() == std::tuple{0, 0});
        //     }

        //     SECTION("Transpose Single Element")
        //     {
        //         cxl::box<int> a = { { 1 } };

        //         REQUIRE(a.size() == 1);
        //         REQUIRE(a.dimensions() == std::tuple{1, 1});

        //         auto b { !a };

        //         REQUIRE(b.size() == 1);
        //         REQUIRE(b.dimensions() == std::tuple{1, 1});
        //         REQUIRE(b == cxl::box<int> { { 1 } });
        //     }

        //     SECTION("Transpose Assign")
        //     {
        //         cxl::box<int> a = { { 1, 2 }
        //                             , { 3, 4 }
        //                             , { 5, 6 }
        //                             , { 7, 8 } };

        //         REQUIRE(a.size() == 8);
        //         REQUIRE(a.dimensions() == std::tuple{4, 2});

        //         a = !a;

        //         REQUIRE(a.size() == 8);
        //         REQUIRE(a.dimensions() == std::tuple{2, 4});
        //         REQUIRE(a == cxl::box<int> { { 1, 3, 5, 7 }
        //                                     , { 2, 4, 6, 8 } });
        //     }
        }
    }
}
