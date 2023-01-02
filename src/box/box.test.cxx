#include <catch2/catch.hpp>
#include <fmt/core.h>

#include <box/box.hxx>

#include <iostream>
#include <tuple>
#include <utility>


TEST_CASE("Constructors and Assignments")
{
    SECTION("Default Allocated")
    {
        SECTION("Default constructor")
        {
            cxl::Box<int> bx;
            REQUIRE(bx.size() == 0);
            REQUIRE(bx.num_rows() == 0);
            REQUIRE(bx.num_columns() == 0);
        }

        SECTION("Size Constructor")
        {
            cxl::Box<int> bx(4, 5);
            REQUIRE(bx.size() == 20);
            REQUIRE(bx.num_rows() == 4);
            REQUIRE(bx.num_columns() == 5);
        }

        SECTION("Size and Value Constructor")
        {
            cxl::Box<int> bx(4, 5, 1);
            REQUIRE(bx.size() == 20);
            REQUIRE(bx.num_rows() == 4);
            REQUIRE(bx.num_columns() == 5);
        }

        SECTION("Copy constructor")
        {
            cxl::Box<int> bx(4, 5, 1);
            cxl::Box<int> nbx(bx);

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
            cxl::Box<int> bx(4, 5, 1);

            for (auto& v : bx)
                REQUIRE(v == 1);

            cxl::Box<int> nbx(std::move(bx));

            REQUIRE(nbx.size() == 20);
            REQUIRE(nbx.num_rows() == 4);
            REQUIRE(nbx.num_columns() == 5);

            for (auto& v : bx)
                REQUIRE(v == 1);
        }

        SECTION("Initializer List Constructor")
        {
            cxl::Box<int> bx { { 1, 2 }
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
            cxl::Box<int> bx(2, 5);
            bx = { { 1, 2, 3, 4, 5 }
                , { 6, 7, 8, 9, 10 } };
            
            REQUIRE(bx.num_rows() == 2);
            REQUIRE(bx.num_columns() == 5);
            REQUIRE(bx.size() == 10);
            REQUIRE(bx.shape() == std::tuple{ 2, 5 });
            
            REQUIRE(bx == cxl::Box<int> { { 1, 2, 3, 4, 5 }
                                        , { 6, 7, 8, 9, 10 } });

            cxl::Box<std::string> nbx(bx.shape());

            REQUIRE(nbx.num_rows() == 2);
            REQUIRE(nbx.num_columns() == 5);
            REQUIRE(nbx.size() == 10);
            REQUIRE(nbx.shape() == std::tuple{ 2, 5 });

            REQUIRE(nbx == cxl::Box<std::string> { { "", "", "", "", "" }
                                                    , { "", "", "", "", "" } });
        }
    }

    SECTION("Custom Allocated")
    {
        SECTION("Allocator Constructor")
        {
            std::allocator<int> alloc;
            cxl::Box<int> bx(alloc);
            REQUIRE(bx.size() == 0);
            REQUIRE(bx.num_rows() == 0);
            REQUIRE(bx.num_columns() == 0);
            REQUIRE(bx.get_allocator() == alloc);
        }

        SECTION("Size Constructor")
        {
            std::allocator<int> alloc;
            cxl::Box<int> bx(4, 5, alloc);
            REQUIRE(bx.size() == 20);
            REQUIRE(bx.num_rows() == 4);
            REQUIRE(bx.num_columns() == 5);
            REQUIRE(bx.get_allocator() == alloc);
        }

        SECTION("Size and Value Constructor")
        {
            std::allocator<int> alloc;
            cxl::Box<int> bx(4, 5, 1, alloc);
            REQUIRE(bx.size() == 20);
            REQUIRE(bx.num_rows() == 4);
            REQUIRE(bx.num_columns() == 5);
            REQUIRE(bx.get_allocator() == alloc);
        }

        SECTION("Copy constructor")
        {
            std::allocator<int> alloc;
            cxl::Box<int> bx(4, 5, 1, alloc);
            cxl::Box<int> nbx(bx);

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
            cxl::Box<int> bx(4, 5, 1, alloc);

            for (auto& v : bx)
                REQUIRE(v == 1);

            cxl::Box<int> nbx(std::move(bx));

            REQUIRE(nbx.size() == 20);
            REQUIRE(nbx.num_rows() == 4);
            REQUIRE(nbx.num_columns() == 5);
            REQUIRE(nbx.get_allocator() == alloc);

            for (auto& v : nbx)
                REQUIRE(v == 1);
        }

        SECTION("Dimension Constructor") 
        {
            cxl::Box<int> bx(2, 5);
            bx = { { 1, 2, 3, 4, 5 }
                , { 6, 7, 8, 9, 10 } };
            
            REQUIRE(bx.num_rows() == 2);
            REQUIRE(bx.num_columns() == 5);
            REQUIRE(bx.size() == 10);
            REQUIRE(bx.shape() == std::tuple{ 2, 5 });
            
            REQUIRE(bx == cxl::Box<int> { { 1, 2, 3, 4, 5 }
                                        , { 6, 7, 8, 9, 10 } });

            std::allocator<std::string> alloc;
            cxl::Box<std::string> nbx(bx.shape(), alloc);

            REQUIRE(nbx.num_rows() == 2);
            REQUIRE(nbx.num_columns() == 5);
            REQUIRE(nbx.size() == 10);
            REQUIRE(nbx.shape() == std::tuple{ 2, 5 });

            REQUIRE(nbx == cxl::Box<std::string> { { "", "", "", "", "" }
                                                    , { "", "", "", "", "" } });
        }
    }

    SECTION("Assignment Operators")
    {
        SECTION("Copy assignment")
        {
            cxl::Box<int> bx(4, 5, 1);
            cxl::Box<int> nbx;

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
            cxl::Box<int> bx(4, 5, 1);
            cxl::Box<int> nbx;

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
            cxl::Box<int> bx = { { 1, 2, 3 }
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
        SECTION("Box::size")
        {
            cxl::Box<int> bx(4, 5);
            REQUIRE(bx.size() == 20);
        }

        SECTION("Box::max_size")
        {
            std::allocator<int> alloc;
            cxl::Box<int> bx(4, 5, 1);
            REQUIRE(bx.max_size() == std::allocator_traits<decltype(alloc)>::max_size(alloc));
        }

        SECTION("Box::num_rows")
        {
            cxl::Box<int> bx(4, 5);
            REQUIRE(bx.num_rows() == 4);
        }

        SECTION("Box::num_columns")
        {
            cxl::Box<int> bx(4, 5);
            REQUIRE(bx.num_columns() == 5);
        }

        SECTION("Box::shape - Tuple")
        {
            cxl::Box<int> bx(4, 5, 1);
            auto dim = bx.shape();

            REQUIRE(std::get<0>(dim) == 4);
            REQUIRE(std::get<1>(dim) == 5);
        }

        SECTION("Box::shape - Structured Binding")
        {
            cxl::Box<int> bx(4, 5, 1);
            auto [c, r] = bx.shape();

            REQUIRE(c == 4);
            REQUIRE(r == 5);
        }
    }

    SECTION("Resources")
    {
        SECTION("Box::empty")
        {
            cxl::Box<int> bx;
            REQUIRE(bx.empty());
        }

        SECTION("Box::empty")
        {
            cxl::Box<int> bx(4, 5, 1);
            REQUIRE(!bx.empty());
        }

        SECTION("Box::get_allocator")
        {
            cxl::Box<int> bx(4, 5, 1);
            REQUIRE(bx.get_allocator() == std::allocator<int>());
        }
    }
}

TEST_CASE("Modifiers")
{
    SECTION("Assignment - Box::assign")
    {
        SECTION("Same Size")
        {
            cxl::Box<int> bx(3, 3, 1);

            auto ptr { bx.data() };

            REQUIRE(bx.size() == 9);
            REQUIRE(bx.shape() == std::tuple{3, 3});
            REQUIRE(bx.data() == ptr);
            REQUIRE(bx == cxl::Box<int> { { 1, 1, 1 }
                                        , { 1, 1, 1 }
                                        , { 1, 1, 1 } });

            bx.assign({ { 1, 2, 3 }
                    , { 4, 5, 6 }
                    , { 7, 8, 9 } });
            
            REQUIRE(bx.size() == 9);
            REQUIRE(bx.shape() == std::tuple{3, 3});
            REQUIRE(bx.data() == ptr);
            REQUIRE(bx == cxl::Box<int> { { 1, 2, 3 }
                                        , { 4, 5, 6 }
                                        , { 7, 8, 9 } });
        }

        SECTION("Larger Size")
        {
            cxl::Box<int> bx(3, 3, 1);

            auto ptr { bx.data() };

            REQUIRE(bx.size() == 9);
            REQUIRE(bx.shape() == std::tuple{3, 3});
            REQUIRE(ptr == bx.data());
            REQUIRE(bx == cxl::Box<int> { { 1, 1, 1 }
                                        , { 1, 1, 1 }
                                        , { 1, 1, 1 } });


            bx.assign({ { 1, 2, 3 }
                    , { 4, 5, 6 }
                    , { 7, 8, 9 }
                    , { 10, 11, 12 } });
            
            REQUIRE(bx.size() == 12);
            REQUIRE(bx.shape() == std::tuple{4, 3});
            REQUIRE(bx.data() != ptr);
            REQUIRE(bx == cxl::Box<int> { { 1, 2, 3 }
                                        , { 4, 5, 6 }
                                        , { 7, 8, 9 }
                                        , { 10, 11, 12 } });
        }

        SECTION("Smaller Box")
        {
            cxl::Box<int> bx(3, 3, 1);

            auto ptr { bx.data() };

            REQUIRE(bx.size() == 9);
            REQUIRE(bx.shape() == std::tuple{3, 3});
            REQUIRE(bx.data() == ptr);
            REQUIRE(bx == cxl::Box<int> { { 1, 1, 1 }
                                        , { 1, 1, 1 }
                                        , { 1, 1, 1 } });

            bx.assign({ { 1, 2, 3, 4 } });

            REQUIRE(bx.size() == 4);
            REQUIRE(bx.shape() == std::tuple{1, 4});
            REQUIRE(bx.data() != ptr);
            REQUIRE(bx == cxl::Box<int> { { 1, 2, 3, 4 } });
        }

        SECTION("Empty Box")
        {
            cxl::Box<int> bx;

            auto ptr { bx.data() };

            REQUIRE(bx.size() == 0);
            REQUIRE(bx.shape() == std::tuple{0, 0});
            REQUIRE(ptr == bx.data());
            REQUIRE(bx == cxl::Box<int> { });

            bx.assign({ { 1, 2, 3 }
                    , { 4, 5, 6 }
                    , { 7, 8, 9 } });
            
            REQUIRE(bx.size() == 9);
            REQUIRE(bx.shape() == std::tuple{3, 3});
            REQUIRE(bx.data() != ptr);
            REQUIRE(bx == cxl::Box<int> { { 1, 2, 3 }
                                        , { 4, 5, 6 }
                                        , { 7, 8, 9 } });
        }
    }
    
    SECTION("Swap")
    {
        SECTION("Box::swap")
        {
            cxl::Box<int> bx(2, 3, 1);
            cxl::Box<int> nbx(7, 4, 2);

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

        SECTION("Box - std::swap")
        {
            cxl::Box<int> bx(2, 3, 1);
            cxl::Box<int> nbx(7, 4, 2);

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
        SECTION("Box::clear")
        {
            cxl::Box<int> bx(4, 5, 1);

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

        SECTION("Box::clear - No allocated resources")
        {
            cxl::Box<int> bx;

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

        SECTION("Box::clear - Uninitialized Resources")
        {
            cxl::Box<int> bx(4, 5);

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
            SECTION("Box::resize - Larger Resize")
            {
                using namespace std::literals;

                /// std::string was used as it is not trivially constructable 
                /// and thus Box<std::string>::resize will actually initialise 
                /// the variable to an empty string (unlike ints)
                cxl::Box<std::string> bx(2, 5, "h");

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

                    fmt::print("i: {} | elem: {}\n", i, elem);

                    i += 1;
                }
            }

            SECTION("Box::resize - Smaller Resize")
            {
                using namespace std::literals;

                /// std::string was used as it is not trivially constructable 
                /// and thus Box<std::string>::resize will actually initialise 
                /// the variable to an empty string (unlike ints)
                cxl::Box<std::string> bx(2, 5, "h");

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

            SECTION("Box::resize - After clear")
            {
                using namespace std::literals;

                /// std::string was used as it is not trivially constructable 
                /// and thus Box<std::string>::resize will actually initialise 
                /// the variable to an empty string (unlike ints)
                cxl::Box<std::string> bx(2, 5, "h");

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
            SECTION("Box::reshape - correct reshape")
            {
                cxl::Box<int> bx(4, 6, 1);

                REQUIRE(bx.size() == 24);
                REQUIRE(bx.num_rows() == 4);
                REQUIRE(bx.num_columns() == 6);

                bx.reshape(3, 8);

                REQUIRE(bx.size() == 24);
                REQUIRE(bx.num_rows() == 3);
                REQUIRE(bx.num_columns() == 8);
            }

            SECTION("Box::reshape - larger reshape")
            {
                cxl::Box<int> bx(4, 6, 1);

                REQUIRE(bx.size() == 24);
                REQUIRE(bx.num_rows() == 4);
                REQUIRE(bx.num_columns() == 6);

                REQUIRE_THROWS_AS(bx.reshape(4, 8), std::length_error);

                REQUIRE(bx.size() == 24);
                REQUIRE(bx.num_rows() == 4);
                REQUIRE(bx.num_columns() == 6);
            }

            SECTION("Box::reshape - smaller reshape")
            {
                cxl::Box<int> bx(4, 6, 1);

                REQUIRE(bx.size() == 24);
                REQUIRE(bx.num_rows() == 4);
                REQUIRE(bx.num_columns() == 6);

                REQUIRE_THROWS_AS(bx.reshape(3, 5), std::length_error);

                REQUIRE(bx.size() == 24);
                REQUIRE(bx.num_rows() == 4);
                REQUIRE(bx.num_columns() == 6);
            }

            SECTION("Box::reshape - reshape column vector")
            {
                cxl::Box<int> bx(4, 6, 1);

                REQUIRE(bx.size() == 24);
                REQUIRE(bx.num_rows() == 4);
                REQUIRE(bx.num_columns() == 6);

                bx.reshape(24, 0);

                REQUIRE(bx.size() == 24);
                REQUIRE(bx.num_rows() == 24);
                REQUIRE(bx.num_columns() == 0);
            }

            SECTION("Box::reshape - reshape column vector")
            {
                cxl::Box<int> bx(4, 6, 1);

                REQUIRE(bx.size() == 24);
                REQUIRE(bx.num_rows() == 4);
                REQUIRE(bx.num_columns() == 6);

                bx.reshape(0, 24);

                REQUIRE(bx.size() == 24);
                REQUIRE(bx.num_rows() == 0);
                REQUIRE(bx.num_columns() == 24);
            }
        }
    }

    SECTION("box::map")
    {
        SECTION("Box only Mapping")
        {
            SECTION("Lambda")
            {
                cxl::Box<int> bx = { { 0, 1 }
                                    , { 2, 3 }
                                    , { 4, 5 }
                                    , { 7, 6 }
                                    , { 8, 9 } };

                cxl::Box<int> bxcheck = { { 0, 2 }
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
                cxl::Box<int> bx;

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
                cxl::Box<int> bx = { { 0, 1 }
                                    , { 2, 3 }
                                    , { 4, 5 }
                                    , { 6, 7 }
                                    , { 8, 9 } };

                cxl::Box<int> bxcheck = { { 0, 1 }
                                        , { 2, 3 }
                                        , { 4, 5 }
                                        , { 6, 7 }
                                        , { 8, 9 } };

                cxl::Box<int> ibxcheck = { { 0, 2 }
                                            , { 4, 6 }
                                            , { 8, 10 }
                                            , { 12, 14 }
                                            , { 16, 18 } };

                cxl::Box<int> rbxcheck = { { -3, -1 }
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
                cxl::Box<int> bx = { { 0, 1 }
                                    , { 2, 3 }
                                    , { 4, 5 }
                                    , { 6, 7 }
                                    , { 8, 9 } };

                cxl::Box<int> bxcheck = { { 0, 1 }
                                        , { 2, 3 }
                                        , { 4, 5 }
                                        , { 6, 7 }
                                        , { 8, 9 } };

                cxl::Box<int> rbxcheck = { { -3, -1 }
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
                cxl::Box<int> bx = { { 0, 1 }
                                    , { 2, 3 }
                                    , { 4, 5 }
                                    , { 6, 7 }
                                    , { 8, 9 } };

                auto square = [](const auto& i) { return i * i; };

                cxl::Box<int> bxcheck = { { 0, 1 }
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

        SECTION("Box and Range")
        {
            SECTION("Lambda - With Box")  
            {
                cxl::Box<int> bx = { { 0, 1 }
                                    , { 2, 3 }
                                    , { 4, 5 }
                                    , { 6, 7 }
                                    , { 8, 9 } };

                cxl::Box<int> bxcheck = { { 0, 1 }
                                        , { 2, 3 }
                                        , { 4, 5 }
                                        , { 6, 7 }
                                        , { 8, 9 } };

                cxl::Box<int> rbxcheck = { { 0, 2 }
                                            , { 48, -3 }
                                            , { -12, 280 }
                                            , { -24, 14 }
                                            , { -40, 36 } };

                REQUIRE(bx.size() == 10);
                REQUIRE(bx.shape() == std::tuple{ 5, 2 });
                REQUIRE(bx == bxcheck);

                cxl::Box<int> x = { { 5, 2 }
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
                cxl::Box<int> bx = { { 0, 1 }
                                    , { 2, 3 }
                                    , { 4, 5 }
                                    , { 6, 7 }
                                    , { 8, 9 } };

                cxl::Box<int> bxcheck = { { 0, 1 }
                                        , { 2, 3 }
                                        , { 4, 5 }
                                        , { 6, 7 }
                                        , { 8, 9 } };

                cxl::Box<int> rbxcheck = { { 0, 2 }
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
                cxl::Box<int> bx = { { 0, 1 }
                                    , { 2, 3 }
                                    , { 4, 5 }
                                    , { 6, 7 }
                                    , { 8, 9 } };

                auto add = [](const auto& x, const auto& y) { return x + y; };

                cxl::Box<int> bxcheck = { { 0, 1 }
                                        , { 2, 3 }
                                        , { 4, 5 }
                                        , { 6, 7 }
                                        , { 8, 9 } };

                cxl::Box<int> rbxcheck = { { 5, 3 }
                                            , { 26, 2 }
                                            , { 1, 61 }
                                            , { 2, 9 }
                                            , { 3, 13 } };

                REQUIRE(bx.size() == 10);
                REQUIRE(bx.shape() == std::tuple{ 5, 2 });
                REQUIRE(bx == bxcheck);

                cxl::Box<int> x = { { 5, 2 }
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

        SECTION("Box and Iterators")
        {
            SECTION("Lambda - With Box")  
            {
                cxl::Box<int> bx = { { 0, 1 }
                                    , { 2, 3 }
                                    , { 4, 5 }
                                    , { 6, 7 }
                                    , { 8, 9 } };

                cxl::Box<int> bxcheck = { { 0, 1 }
                                        , { 2, 3 }
                                        , { 4, 5 }
                                        , { 6, 7 }
                                        , { 8, 9 } };

                cxl::Box<int> rbxcheck = { { 0, 2 }
                                            , { 48, -3 }
                                            , { -12, 280 }
                                            , { -24, 14 }
                                            , { -40, 36 } };

                REQUIRE(bx.size() == 10);
                REQUIRE(bx.shape() == std::tuple{ 5, 2 });
                REQUIRE(bx == bxcheck);

                cxl::Box<int> x = { { 5, 2 }
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
                cxl::Box<int> bx = { { 0, 1 }
                                    , { 2, 3 }
                                    , { 4, 5 }
                                    , { 6, 7 }
                                    , { 8, 9 } };

                cxl::Box<int> bxcheck = { { 0, 1 }
                                        , { 2, 3 }
                                        , { 4, 5 }
                                        , { 6, 7 }
                                        , { 8, 9 } };

                cxl::Box<int> rbxcheck = { { 0, 2 }
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
                cxl::Box<int> bx = { { 0, 1 }
                                    , { 2, 3 }
                                    , { 4, 5 }
                                    , { 6, 7 }
                                    , { 8, 9 } };

                auto add = [](const auto& x, const auto& y) { return x + y; };

                cxl::Box<int> bxcheck = { { 0, 1 }
                                        , { 2, 3 }
                                        , { 4, 5 }
                                        , { 6, 7 }
                                        , { 8, 9 } };

                cxl::Box<int> rbxcheck = { { 5, 3 }
                                            , { 26, 2 }
                                            , { 1, 61 }
                                            , { 2, 9 }
                                            , { 3, 13 } };

                REQUIRE(bx.size() == 10);
                REQUIRE(bx.shape() == std::tuple{ 5, 2 });
                REQUIRE(bx == bxcheck);

                cxl::Box<int> x = { { 5, 2 }
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
}

TEST_CASE("Iterators")
{
    SECTION("Normal Iterators")
    {

        SECTION("Range for-loop")
        {
            cxl::Box<int> bx(4, 5, 1);

            for (auto& elem : bx)
            {
                REQUIRE(elem == 1);
                elem = 2;
            }

            for (auto& elem : bx)
                REQUIRE(elem == 2);
        }

        SECTION("Box::begin and Box::end")
        {
            cxl::Box<int> bx(4, 5);

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
            cxl::Box<int> bx = { { 1, 2 }
                                , { 3, 4 } };

            std::reverse(bx.begin(), bx.end());

            for (auto v { 4 }; auto& elem : bx)
            
                REQUIRE(elem == v--);
        }

        SECTION("Box::rbegin and Box::rend")
        {
            cxl::Box<int> bx(4, 5);

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
        SECTION("Box::data")
        {
            cxl::Box<int> bx(4, 5, 1);
            REQUIRE(bx.data() != nullptr);
        }

        SECTION("Box::front")
        {
            cxl::Box<int> bx(4, 5, 1);
            REQUIRE(bx.front() == 1);

            bx.front() = 2;
            REQUIRE(bx.front() == 2);
        }

        SECTION("Box::back")
        {
            cxl::Box<int> bx(4, 5, 1);
            REQUIRE(bx.back() == 1);

            bx.back() = 2;
            REQUIRE(bx.back() == 2);
        }
    }

    SECTION("Accessors")
    {
        SECTION("Box::at")
        {
            cxl::Box<int> bx(4, 5, 1);
            REQUIRE(bx.at(0, 1) == 1);

            bx.at(0, 1) = 2;
            REQUIRE(bx.at(0, 1) == 2);

            REQUIRE_THROWS_AS(bx.at(10, 1), std::out_of_range);
        }

        SECTION("Box::operator()")
        {
            cxl::Box<int> bx(4, 5, 1);
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
                cxl::Box<int> bx(4, 5, 1);
                cxl::Box<int> nbx(4, 5, 1);

                REQUIRE(bx == bx);
                REQUIRE(bx == nbx);
            }

            SECTION("Different size")
            {
                cxl::Box<int> bx(5, 8, 1);
                cxl::Box<int> nbx(4, 13, 1);

                REQUIRE(bx != nbx);
                REQUIRE(nbx != bx);
            }
        }

        SECTION("Inequality")
        {
            SECTION("Not Equal")
            {
                cxl::Box<int> bx(4, 5, 1);
                cxl::Box<int> nbx(4, 5, 2);

                REQUIRE(bx != nbx);
                REQUIRE(nbx != bx);
            }

            SECTION("Different size")
            {
                cxl::Box<int> bx(13, 6, 1);
                cxl::Box<int> nbx(17, 11, 1);

                REQUIRE(bx != nbx);
                REQUIRE(nbx != bx);
            }

            SECTION("Different data")
            {
                cxl::Box<int> bx(4, 5, 1);
                cxl::Box<int> nbx(4, 5, 2);

                REQUIRE(bx != nbx);
                REQUIRE(nbx != bx);
            }

            SECTION("Different data and size")
            {
                cxl::Box<int> bx(13, 6, 1);
                cxl::Box<int> nbx(17, 11, 2);

                REQUIRE(bx != nbx);
                REQUIRE(nbx != bx);
            }
        }

        SECTION("Less Than")
        {
            SECTION("Different data")
            {
                cxl::Box<int> bx(4, 5, 1);
                cxl::Box<int> nbx(4, 5, 2);

                REQUIRE(bx < nbx);
                REQUIRE(!(nbx < bx));
            }

            SECTION("Different size")
            {
                cxl::Box<int> bx(13, 6, 1);
                cxl::Box<int> nbx(17, 11, 1);

                REQUIRE(bx < nbx);
                REQUIRE(!(nbx < bx));
            }

            SECTION("Different data and size")
            {
                cxl::Box<int> bx(13, 6, 2);
                cxl::Box<int> nbx(17, 11, 1);

                REQUIRE(!(bx < nbx));
                REQUIRE(nbx < bx);
            }

            SECTION("Same data")
            {
                cxl::Box<int> bx(4, 5, 1);
                cxl::Box<int> nbx(4, 5, 1);

                REQUIRE(!(bx < nbx));
                REQUIRE(!(nbx < bx));
            }
        }

        SECTION("Greater Than")
        {
            SECTION("Different data")
            {
                cxl::Box<int> bx(4, 5, 1);
                cxl::Box<int> nbx(4, 5, 2);

                REQUIRE(nbx > bx);
                REQUIRE(!(bx > nbx));
            }

            SECTION("Different size")
            {
                cxl::Box<int> bx(13, 6, 1);
                cxl::Box<int> nbx(17, 11, 1);

                REQUIRE(nbx > bx);
                REQUIRE(!(bx > nbx));
            }

            SECTION("Different data and size")
            {
                cxl::Box<int> bx(13, 6, 2);
                cxl::Box<int> nbx(17, 11, 1);

                REQUIRE(bx > nbx);
                REQUIRE(!(nbx > bx));
            }

            SECTION("Same data")
            {
                cxl::Box<int> bx(4, 5, 1);
                cxl::Box<int> nbx(4, 5, 1);

                REQUIRE(!(nbx > bx));
                REQUIRE(!(bx > nbx));
            }
        }

        SECTION("Less Than or Equal")
        {
            SECTION("Different data")
            {
                cxl::Box<int> bx(4, 5, 1);
                cxl::Box<int> nbx(4, 5, 2);

                REQUIRE(bx <= nbx);
                REQUIRE(!(nbx <= bx));
            }

            SECTION("Different size")
            {
                cxl::Box<int> bx(13, 6, 1);
                cxl::Box<int> nbx(17, 11, 1);

                REQUIRE(bx <= nbx);
                REQUIRE(!(nbx <= bx));
            }

            SECTION("Different data and size")
            {
                cxl::Box<int> bx(13, 6, 2);
                cxl::Box<int> nbx(17, 11, 1);

                REQUIRE(bx > nbx);
                REQUIRE(nbx <= bx);
            }

            SECTION("Same data")
            {
                cxl::Box<int> bx(4, 5, 1);
                cxl::Box<int> nbx(4, 5, 1);

                REQUIRE(bx <= nbx);
                REQUIRE(nbx <= bx);
            }
        }

        SECTION("Greater Than or Equal")
        {
            SECTION("Different data")
            {
                cxl::Box<int> bx(4, 5, 1);
                cxl::Box<int> nbx(4, 5, 2);

                REQUIRE(nbx >= bx);
                REQUIRE(!(bx >= nbx));
            }

            SECTION("Different size")
            {
                cxl::Box<int> bx(13, 6, 1);
                cxl::Box<int> nbx(17, 11, 1);

                REQUIRE(nbx >= bx);
                REQUIRE(!(bx >= nbx));
            }

            SECTION("Different data and size")
            {
                cxl::Box<int> bx(13, 6, 2);
                cxl::Box<int> nbx(17, 11, 1);

                REQUIRE(bx >= nbx);
                REQUIRE(!(nbx >= bx));
            }

            SECTION("Same data")
            {
                cxl::Box<int> bx(4, 5, 1);
                cxl::Box<int> nbx(4, 5, 1);

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
                cxl::Box<int> a = { { 1, 2 }
                                    , { 3, 4 }
                                    , { 5, 6 }
                                    , { 7, 8 } };

                REQUIRE(a.size() == 8);
                REQUIRE(a.shape() == std::tuple{4, 2});

                auto b { a || [](const auto& i) { return i * 2; } };

                REQUIRE(b.size() == 8);
                REQUIRE(b.shape() == std::tuple{4, 2});
                REQUIRE(b == cxl::Box<int> { { 2, 4 }
                                            , { 6, 8 }
                                            , { 10, 12 }
                                            , { 14, 16 } });
            }

            SECTION("Map - Named Lambda")
            {
                cxl::Box<int> a = { { 1, 2 }
                                    , { 3, 4 }
                                    , { 5, 6 }
                                    , { 7, 8 } };

                auto xor_3 = [](const auto& i) { return i ^ 3; };

                REQUIRE(a.size() == 8);
                REQUIRE(a.shape() == std::tuple{4, 2});

                auto b { a || xor_3 };

                REQUIRE(b.size() == 8);
                REQUIRE(b.shape() == std::tuple{4, 2});
                REQUIRE(b == cxl::Box<int> { { 2, 1 }
                                            , { 0, 7 }
                                            , { 6, 5 }
                                            , { 4, 11 } });
            }

            SECTION("Map - Chained Lambdas")
            {
                cxl::Box<int> a = { { 1, 2 }
                                    , { 3, 4 }
                                    , { 5, 6 }
                                    , { 7, 8 } };

                REQUIRE(a.size() == 8);
                REQUIRE(a.shape() == std::tuple{4, 2});

                auto b { a || [](const auto& i) { return i * 2; } 
                            || [](const auto& i) { return i ^ 3; } };

                REQUIRE(b.size() == 8);
                REQUIRE(b.shape() == std::tuple{4, 2});
                REQUIRE(b == cxl::Box<int> { { 1, 7 }
                                            , { 5, 11 }
                                            , { 9, 15 }
                                            , { 13, 19 } });
            }

            SECTION("Map - Chained Named Lambdas")
            {
                cxl::Box<int> a = { { 1, 2 }
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
                REQUIRE(b == cxl::Box<int> { { 1, 7 }
                                            , { 5, 11 }
                                            , { 9, 15 }
                                            , { 13, 19 } });
            }
        }
    }
}
