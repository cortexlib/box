#include <catch2/catch.hpp>
#include <iostream>
#include <box.hpp>

TEST_CASE("Arithmatic Methods")
{
    SECTION("box::add")
    {
        SECTION("Same type")
        {
            cortex::box<int> bx(4, 5, 1);
            cortex::box<int> nbx(4, 5, 2);
            cortex::box<int> rbxcheck(4, 5, 3);

            auto rbx { bx.add(nbx) };

            REQUIRE(rbx == rbxcheck);

            for (auto& elem : bx)
                REQUIRE(elem == 1);
            
            for (auto& elem : nbx)
                REQUIRE(elem == 2);
            
            for (auto& elem : rbx)
                REQUIRE(elem == 3);
        }

        SECTION("Different type")
        {
            cortex::box<int> bx(4, 5, 1);
            cortex::box<double> nbx(4, 5, 2.5);
            cortex::box<double> rbxcheck(4, 5, 3.5);

            auto rbx { bx.add(nbx) };

            REQUIRE(rbx == rbxcheck);

            for (auto& elem : bx)
                REQUIRE(elem == 1);
            
            for (auto& elem : nbx)
                REQUIRE(elem == 2.5);

            for (auto& elem : rbx)
                REQUIRE(elem == 3.5);
        }

        SECTION("Same Matrix")
        {
            cortex::box<int> bx(4, 5, 1);
            cortex::box<double> rbxcheck(4, 5, 2);

            auto rbx { bx.add(bx) };

            REQUIRE(rbx == rbxcheck);

            for (auto& elem : bx)
                REQUIRE(elem == 1);

            for (auto& elem : rbx)
                REQUIRE(elem == 2);
        }

        SECTION("Same Matrix + Assign")
        {
            cortex::box<int> bx(4, 5, 1);
            cortex::box<double> bxcheck(4, 5, 2);

            bx = bx.add(bx);

            REQUIRE(bx == bxcheck);

            for (auto& elem : bx)
                REQUIRE(elem == 2);
        }

        SECTION("Size Mismatch")
        {
            cortex::box<int> bx(4, 5, 1);
            cortex::box<double> nbx(0, 11, 2.5);

            REQUIRE_THROWS_AS(bx.add(nbx), std::invalid_argument);
        }

        SECTION("Non `Addable` or `AddableWith` type")
        {
            using namespace std::string_literals;

            cortex::box<std::string> bx(0, 10, "hello"s);
            cortex::box<std::wstring> nbx(4, 5, L"world"s);

            /// To test, uncomment and code should not compile
            // auto rbx { bx.add(nbx) };
        }
    }

    SECTION("box::sub")
    {
        SECTION("Same type")
        {
            cortex::box<int> bx(4, 5, 1);
            cortex::box<int> nbx(4, 5, 2);
            cortex::box<int> rbxcheck(4, 5, -1);

            auto rbx { bx.sub(nbx) };

            REQUIRE(rbx == rbxcheck);

            for (auto& elem : bx)
                REQUIRE(elem == 1);
            
            for (auto& elem : nbx)
                REQUIRE(elem == 2);
            
            for (auto& elem : rbx)
                REQUIRE(elem == -1);
        }

        SECTION("Different type")
        {
            cortex::box<int> bx(4, 5, 1);
            cortex::box<double> nbx(4, 5, 2.5);
            cortex::box<double> rbxcheck(4, 5, -1.5);

            auto rbx { bx.sub(nbx) };

            REQUIRE(rbx == rbxcheck);

            for (auto& elem : bx)
                REQUIRE(elem == 1);
            
            for (auto& elem : nbx)
                REQUIRE(elem == 2.5);

            for (auto& elem : rbx)
                REQUIRE(elem == -1.5);
        }

        SECTION("Same Matrix")
        {
            cortex::box<int> bx(4, 5, 1);
            cortex::box<double> rbxcheck(4, 5, 0);

            auto rbx { bx.sub(bx) };

            REQUIRE(rbx == rbxcheck);

            for (auto& elem : bx)
                REQUIRE(elem == 1);

            for (auto& elem : rbx)
                REQUIRE(elem == 0);
        }

        SECTION("Same Matrix + Assign")
        {
            cortex::box<int> bx(4, 5, 1);
            cortex::box<double> bxcheck(4, 5, 0);

            bx = bx.sub(bx);

            REQUIRE(bx == bxcheck);

            for (auto& elem : bx)
                REQUIRE(elem == 0);
        }

        SECTION("Non `Subtractable` or `SubtractableWith` type")
        {
            using namespace std::string_literals;

            cortex::box<std::string> bx(0, 10, "hello"s);
            cortex::box<std::wstring> nbx(4, 5, L"world"s);

            /// To test, uncomment and code should not compile
            // auto rbx { bx.sub(nbx) };
        }
    }

    SECTION("box::mul")
    {
        SECTION("Same type")
        {
            cortex::box<int> bx(4, 5, 2);
            cortex::box<int> nbx(4, 5, 5);
            cortex::box<int> rbxcheck(4, 5, 10);

            auto rbx { bx.mul(nbx) };

            REQUIRE(rbx == rbxcheck);

            for (auto& elem : bx)
                REQUIRE(elem == 2);
            
            for (auto& elem : nbx)
                REQUIRE(elem == 5);
            
            for (auto& elem : rbx)
                REQUIRE(elem == 10);
        }

        SECTION("Different type")
        {
            cortex::box<int> bx(4, 5, 7);
            cortex::box<double> nbx(4, 5, 2.5);
            cortex::box<double> rbxcheck(4, 5, 17.5);

            auto rbx { bx.mul(nbx) };

            REQUIRE(rbx == rbxcheck);

            for (auto& elem : bx)
                REQUIRE(elem == 7);
            
            for (auto& elem : nbx)
                REQUIRE(elem == 2.5);

            for (auto& elem : rbx)
                REQUIRE(elem == 17.5);
        }

        SECTION("Same Matrix")
        {
            cortex::box<int> bx(4, 5, 5);
            cortex::box<double> rbxcheck(4, 5, 25);

            auto rbx { bx.mul(bx) };

            REQUIRE(rbx == rbxcheck);

            for (auto& elem : bx)
                REQUIRE(elem == 5);

            for (auto& elem : rbx)
                REQUIRE(elem == 25);
        }

        SECTION("Same Matrix + Assign")
        {
            cortex::box<int> bx(4, 5, 5);
            cortex::box<int> bxcheck(4, 5, 25);

            bx = bx.mul(bx);

            REQUIRE(bx == bxcheck);

            for (auto& elem : bx)
                REQUIRE(elem == 25);
        }

        SECTION("Non `Multiplicible` or `MultiplicibleWith` type")
        {
            using namespace std::string_literals;

            cortex::box<std::string> bx(0, 10, "hello"s);
            cortex::box<std::wstring> nbx(4, 5, L"world"s);

            /// To test, uncomment and code should not compile
            // auto rbx { bx.mul(nbx) };
        }

        SECTION("Scalar Multiply")
        {
            cortex::box<int> bx(4, 5, 5);
            cortex::box<int> bxcheck(4, 5, 35);

            auto rbx { bx.mul(7) };

            REQUIRE(rbx == bxcheck);

            for (auto& elem : rbx)
                REQUIRE(elem == 35);
        }
    }

    SECTION("box::div")
    {
        SECTION("Same type")
        {
            cortex::box<int> bx(4, 5, 2);
            cortex::box<int> nbx(4, 5, 5);
            cortex::box<double> rbxcheck(4, 5, 2 / 5);

            auto rbx { bx.div(nbx) };

            REQUIRE(rbx == rbxcheck);

            for (auto& elem : bx)
                REQUIRE(elem == 2);
            
            for (auto& elem : nbx)
                REQUIRE(elem == 5);
            
            for (auto& elem : rbx)
                REQUIRE(elem == 2 / 5);
        }

        SECTION("Different type")
        {
            cortex::box<int> bx(4, 5, 7);
            cortex::box<double> nbx(4, 5, 2.5);
            cortex::box<double> rbxcheck(4, 5, 2.8);

            auto rbx { bx.div(nbx) };

            REQUIRE(rbx == rbxcheck);

            for (auto& elem : bx)
                REQUIRE(elem == 7);
            
            for (auto& elem : nbx)
                REQUIRE(elem == 2.5);

            for (auto& elem : rbx)
                REQUIRE(elem == 2.8);
        }

        SECTION("Different type - Integer division")
        {
            cortex::box<int> bx(4, 5, 5);
            cortex::box nbx(4, 5, 2.);
            cortex::box<double> rbxcheck(4, 5, 2.5);

            auto rbx { bx.div(nbx) };

            REQUIRE(rbx == rbxcheck);

            for (auto& elem : bx)
                REQUIRE(elem == 5);
            
            for (auto& elem : nbx)
                REQUIRE(elem == 2);

            for (auto& elem : rbx)
                REQUIRE(elem == 2.5);
        }

        SECTION("Same Matrix")
        {
            cortex::box<int> bx(4, 5, 5);
            cortex::box<double> rbxcheck(4, 5, 1);

            auto rbx { bx.div(bx) };

            REQUIRE(rbx == rbxcheck);

            for (auto& elem : bx)
                REQUIRE(elem == 5);

            for (auto& elem : rbx)
                REQUIRE(elem == 1);
        }

        SECTION("Same Matrix + Assign")
        {
            cortex::box<int> bx(4, 5, 5);
            cortex::box<int> bxcheck(4, 5, 1);

            bx = bx.div(bx);

            REQUIRE(bx == bxcheck);

            for (auto& elem : bx)
                REQUIRE(elem == 1);
        }

        SECTION("Non `Divisible` or `DivisibleWith` type")
        {
            using namespace std::string_literals;

            cortex::box<std::string> bx(0, 10, "hello"s);
            cortex::box<std::wstring> nbx(4, 5, L"world"s);

            /// To test, uncomment and code should not compile
            // auto rbx { bx.div(nbx) };
        }

        SECTION("Scalar Divide")
        {
            cortex::box<int> bx(4, 5, 5);
            cortex::box<double> bxcheck(4, 5, 2.5);

            auto rbx { bx.div(2.) };

            REQUIRE(rbx == bxcheck);

            for (auto& elem : rbx)
                REQUIRE(elem == 2.5);
        }
    }
}

TEST_CASE("Modulo Operator")
{
    SECTION("box::mod")
    {
        SECTION("Same type")
        {
            cortex::box<int> bx(4, 5, 2);
            cortex::box<int> nbx(4, 5, 5);
            cortex::box<int> rbxcheck(4, 5, 2 % 5);

            auto rbx { bx.mod(nbx) };

            REQUIRE(rbx == rbxcheck);

            for (auto& elem : bx)
                REQUIRE(elem == 2);
            
            for (auto& elem : nbx)
                REQUIRE(elem == 5);
            
            for (auto& elem : rbx)
                REQUIRE(elem == 2 % 5);
        }

        SECTION("Different type")
        {
            cortex::box<int> bx(4, 5, 7);
            cortex::box<std::size_t> nbx(4, 5, 4uL);
            cortex::box<double> rbxcheck(4, 5, 3);

            auto rbx { bx.mod(nbx) };

            REQUIRE(rbx == rbxcheck);

            for (auto& elem : bx)
                REQUIRE(elem == 7);
            
            for (auto& elem : nbx)
                REQUIRE(elem == 4uL);

            for (auto& elem : rbx)
                REQUIRE(elem == 3);
        }

        SECTION("Same Matrix")
        {
            cortex::box<int> bx(4, 5, 10);
            cortex::box<int> rbxcheck(4, 5, 0);

            auto rbx { bx.mod(bx) };

            REQUIRE(rbx == rbxcheck);

            for (auto& elem : bx)
                REQUIRE(elem == 10);

            for (auto& elem : rbx)
                REQUIRE(elem == 0);
        }

        SECTION("Same Matrix + Assign")
        {
            cortex::box<int> bx(4, 5, 5);
            cortex::box<int> bxcheck(4, 5, 0);

            bx = bx.mod(bx);

            REQUIRE(bx == bxcheck);

            for (auto& elem : bx)
                REQUIRE(elem == 0);
        }

        SECTION("Non `Modulo` or `ModuloWith` type")
        {
            using namespace std::string_literals;

            cortex::box<std::string> bx(0, 10, "hello"s);
            cortex::box<std::wstring> nbx(4, 5, L"world"s);

            /// To test, uncomment and code should not compile
            // auto rbx { bx.mod(nbx) };
        }

        SECTION("Scalar Modulo")
        {
            cortex::box<int> bx(4, 5, 15);
            cortex::box<int> bxcheck(4, 5, 3);

            auto rbx { bx.mod(6) };

            REQUIRE(rbx == bxcheck);

            for (auto& elem : rbx)
                REQUIRE(elem == 3);
        }
    }
}

TEST_CASE("Bit Arithmatic Methods")
{
    SECTION("box::bit_xor")
    {
        SECTION("Same type")
        {
            cortex::box<int> bx(4, 5, 2);
            cortex::box<int> nbx(4, 5, 5);
            cortex::box<int> rbxcheck(4, 5, 7);

            auto rbx { bx.bit_xor(nbx) };

            REQUIRE(rbx == rbxcheck);

            for (auto& elem : bx)
                REQUIRE(elem == 2);
            
            for (auto& elem : nbx)
                REQUIRE(elem == 5);
            
            for (auto& elem : rbx)
                REQUIRE(elem == 7);
        }

        SECTION("Different type")
        {
            cortex::box<int> bx(4, 5, 7);
            cortex::box<std::size_t> nbx(4, 5, 4uL);
            cortex::box<decltype(int() ^ std::size_t())> rbxcheck(4, 5, 3);

            auto rbx { bx.bit_xor(nbx) };

            REQUIRE(rbx == rbxcheck);

            for (auto& elem : bx)
                REQUIRE(elem == 7);
            
            for (auto& elem : nbx)
                REQUIRE(elem == 4uL);

            for (auto& elem : rbx)
                REQUIRE(elem == 3uL);
        }

        SECTION("Same Matrix")
        {
            cortex::box<int> bx(4, 5, 10);
            cortex::box<int> rbxcheck(4, 5, 0);

            auto rbx { bx.bit_xor(bx) };

            REQUIRE(rbx == rbxcheck);

            for (auto& elem : bx)
                REQUIRE(elem == 10);

            for (auto& elem : rbx)
                REQUIRE(elem == 0);
        }

        SECTION("Same Matrix + Assign")
        {
            cortex::box<int> bx(4, 5, 5);
            cortex::box<int> bxcheck(4, 5, 0);

            bx = bx.bit_xor(bx);

            REQUIRE(bx == bxcheck);

            for (auto& elem : bx)
                REQUIRE(elem == 0);
        }

        SECTION("Non `BitXor` or `BitXorWith` type")
        {
            using namespace std::string_literals;

            cortex::box<std::string> bx(0, 10, "hello"s);
            cortex::box<std::wstring> nbx(4, 5, L"world"s);

            /// To test, uncomment and code should not compile
            // auto rbx { bx.bit_xor(nbx) };
        }

        SECTION("Scalar Xor")
        {
            cortex::box<int> bx(4, 5, 15);
            cortex::box<int> bxcheck(4, 5, 9);

            auto rbx { bx.bit_xor(6) };

            REQUIRE(rbx == bxcheck);

            for (auto& elem : rbx)
                REQUIRE(elem == 9);
        }
    }

    SECTION("box::bit_and")
    {
        SECTION("Same type")
        {
            cortex::box<int> bx(4, 5, 2);
            cortex::box<int> nbx(4, 5, 5);
            cortex::box<int> rbxcheck(4, 5, 0);

            auto rbx { bx.bit_and(nbx) };

            REQUIRE(rbx == rbxcheck);

            for (auto& elem : bx)
                REQUIRE(elem == 2);
            
            for (auto& elem : nbx)
                REQUIRE(elem == 5);
            
            for (auto& elem : rbx)
                REQUIRE(elem == 0);
        }

        SECTION("Different type")
        {
            cortex::box<int> bx(4, 5, 7);
            cortex::box<std::size_t> nbx(4, 5, 4uL);
            cortex::box<decltype(int() & std::size_t())> rbxcheck(4, 5, 4);

            auto rbx { bx.bit_and(nbx) };

            REQUIRE(rbx == rbxcheck);

            for (auto& elem : bx)
                REQUIRE(elem == 7);
            
            for (auto& elem : nbx)
                REQUIRE(elem == 4uL);

            for (auto& elem : rbx)
                REQUIRE(elem == 4uL);
        }

        SECTION("Same Matrix")
        {
            cortex::box<int> bx(4, 5, 10);
            cortex::box<int> rbxcheck(4, 5, 10);

            auto rbx { bx.bit_and(bx) };

            REQUIRE(rbx == rbxcheck);

            for (auto& elem : bx)
                REQUIRE(elem == 10);

            for (auto& elem : rbx)
                REQUIRE(elem == 10);
        }

        SECTION("Same Matrix + Assign")
        {
            cortex::box<int> bx(4, 5, 5);
            cortex::box<int> bxcheck(4, 5, 5);

            bx = bx.bit_and(bx);

            REQUIRE(bx == bxcheck);

            for (auto& elem : bx)
                REQUIRE(elem == 5);
        }

        SECTION("Non `BitAnd` or `BitAndWith` type")
        {
            using namespace std::string_literals;

            cortex::box<std::string> bx(0, 10, "hello"s);
            cortex::box<std::wstring> nbx(4, 5, L"world"s);

            /// To test, uncomment and code should not compile
            // auto rbx { bx.bit_and(nbx) };
        }

        SECTION("Scalar And")
        {
            cortex::box<int> bx(4, 5, 15);
            cortex::box<int> bxcheck(4, 5, 6);

            auto rbx { bx.bit_and(6) };

            REQUIRE(rbx == bxcheck);

            for (auto& elem : rbx)
                REQUIRE(elem == 6);
        }
    }

    SECTION("box::bit_or")
    {
        SECTION("Same type")
        {
            cortex::box<int> bx(4, 5, 2);
            cortex::box<int> nbx(4, 5, 5);
            cortex::box<int> rbxcheck(4, 5, 7);

            auto rbx { bx.bit_or(nbx) };

            REQUIRE(rbx == rbxcheck);

            for (auto& elem : bx)
                REQUIRE(elem == 2);
            
            for (auto& elem : nbx)
                REQUIRE(elem == 5);
            
            for (auto& elem : rbx)
                REQUIRE(elem == 7);
        }

        SECTION("Different type")
        {
            cortex::box<int> bx(4, 5, 7);
            cortex::box<std::size_t> nbx(4, 5, 4uL);
            cortex::box<decltype(int() | std::size_t())> rbxcheck(4, 5, 7);

            auto rbx { bx.bit_or(nbx) };

            REQUIRE(rbx == rbxcheck);

            for (auto& elem : bx)
                REQUIRE(elem == 7);
            
            for (auto& elem : nbx)
                REQUIRE(elem == 4uL);

            for (auto& elem : rbx)
                REQUIRE(elem == 7uL);
        }

        SECTION("Same Matrix")
        {
            cortex::box<int> bx(4, 5, 10);
            cortex::box<int> rbxcheck(4, 5, 10);

            auto rbx { bx.bit_or(bx) };

            REQUIRE(rbx == rbxcheck);

            for (auto& elem : bx)
                REQUIRE(elem == 10);

            for (auto& elem : rbx)
                REQUIRE(elem == 10);
        }

        SECTION("Same Matrix + Assign")
        {
            cortex::box<int> bx(4, 5, 5);
            cortex::box<int> bxcheck(4, 5, 5);

            bx = bx.bit_or(bx);

            REQUIRE(bx == bxcheck);

            for (auto& elem : bx)
                REQUIRE(elem == 5);
        }

        SECTION("Non `BitOr` or `BitOrWith` type")
        {
            using namespace std::string_literals;

            cortex::box<std::string> bx(0, 10, "hello"s);
            cortex::box<std::wstring> nbx(4, 5, L"world"s);

            /// To test, uncomment and code should not compile
            // auto rbx { bx.bit_or(nbx) };
        }

        SECTION("Scalar Or")
        {
            cortex::box<int> bx(4, 5, 15);
            cortex::box<int> bxcheck(4, 5, 15);

            auto rbx { bx.bit_or(6) };

            REQUIRE(rbx == bxcheck);

            for (auto& elem : rbx)
                REQUIRE(elem == 15);
        }
    }

    SECTION("box::shift_left")
    {
        SECTION("Same type")
        {
            cortex::box<int> bx(4, 5, 2);
            cortex::box<int> nbx(4, 5, 5);
            cortex::box<int> rbxcheck(4, 5, 64);

            auto rbx { bx.shift_left(nbx) };

            REQUIRE(rbx == rbxcheck);

            for (auto& elem : bx)
                REQUIRE(elem == 2);
            
            for (auto& elem : nbx)
                REQUIRE(elem == 5);
            
            for (auto& elem : rbx)
                REQUIRE(elem == 64);
        }

        SECTION("Different type")
        {
            cortex::box<int> bx(4, 5, 7);
            cortex::box<std::size_t> nbx(4, 5, 4uL);
            cortex::box<decltype(int() << std::size_t())> rbxcheck(4, 5, 112);

            auto rbx { bx.shift_left(nbx) };

            REQUIRE(rbx == rbxcheck);

            for (auto& elem : bx)
                REQUIRE(elem == 7);
            
            for (auto& elem : nbx)
                REQUIRE(elem == 4uL);

            for (auto& elem : rbx)
                REQUIRE(elem == 112uL);
        }

        SECTION("Same Matrix")
        {
            cortex::box<int> bx(4, 5, 10);
            cortex::box<int> rbxcheck(4, 5, 10240);

            auto rbx { bx.shift_left(bx) };

            REQUIRE(rbx == rbxcheck);

            for (auto& elem : bx)
                REQUIRE(elem == 10);

            for (auto& elem : rbx)
                REQUIRE(elem == 10240);
        }

        SECTION("Same Matrix + Assign")
        {
            cortex::box<int> bx(4, 5, 5);
            cortex::box<int> bxcheck(4, 5, 160);

            bx = bx.shift_left(bx);

            REQUIRE(bx == bxcheck);

            for (auto& elem : bx)
                REQUIRE(elem == 160);
        }

        SECTION("Non `RightBitShift` or `RightBitShiftWith` type")
        {
            using namespace std::string_literals;

            cortex::box<std::string> bx(0, 10, "hello"s);
            cortex::box<std::wstring> nbx(4, 5, L"world"s);

            /// To test, uncomment and code should not compile
            // auto rbx { bx.left_bitshift(nbx) };
        }

        SECTION("Scalar Right Bit Shift")
        {
            cortex::box<int> bx(4, 5, 15);
            cortex::box<int> bxcheck(4, 5, 960);

            auto rbx { bx.shift_left(6) };

            REQUIRE(rbx == bxcheck);

            for (auto& elem : rbx)
                REQUIRE(elem == 960);
        }
    }

    SECTION("box::shift_right")
    {
        SECTION("Same type")
        {
            cortex::box<int> bx(4, 5, 2);
            cortex::box<int> nbx(4, 5, 5);
            cortex::box<int> rbxcheck(4, 5, 0);

            auto rbx { bx.shift_right(nbx) };

            REQUIRE(rbx == rbxcheck);

            for (auto& elem : bx)
                REQUIRE(elem == 2);
            
            for (auto& elem : nbx)
                REQUIRE(elem == 5);
            
            for (auto& elem : rbx)
                REQUIRE(elem == 0);
        }

        SECTION("Different type")
        {
            cortex::box<int> bx(4, 5, 7);
            cortex::box<std::size_t> nbx(4, 5, 4uL);
            cortex::box<decltype(int() >> std::size_t())> rbxcheck(4, 5, 0);

            auto rbx { bx.shift_right(nbx) };

            REQUIRE(rbx == rbxcheck);

            for (auto& elem : bx)
                REQUIRE(elem == 7);
            
            for (auto& elem : nbx)
                REQUIRE(elem == 4uL);

            for (auto& elem : rbx)
                REQUIRE(elem == 0uL);
        }

        SECTION("Same Matrix")
        {
            cortex::box<int> bx(4, 5, 10);
            cortex::box<int> rbxcheck(4, 5, 0);

            auto rbx { bx.shift_right(bx) };

            REQUIRE(rbx == rbxcheck);

            for (auto& elem : bx)
                REQUIRE(elem == 10);

            for (auto& elem : rbx)
                REQUIRE(elem == 0);
        }

        SECTION("Same Matrix + Assign")
        {
            cortex::box<int> bx(4, 5, 5);
            cortex::box<int> bxcheck(4, 5, 0);

            bx = bx.shift_right(bx);

            REQUIRE(bx == bxcheck);

            for (auto& elem : bx)
                REQUIRE(elem == 0);
        }

        SECTION("Non `LeftBitShift` or `LeftBitShiftWith` type")
        {
            using namespace std::string_literals;

            cortex::box<std::string> bx(0, 10, "hello"s);
            cortex::box<std::wstring> nbx(4, 5, L"world"s);

            /// To test, uncomment and code should not compile
            // auto rbx { bx.right_bitshift(nbx) };
        }

        SECTION("Scalar Left Bit Shift")
        {
            cortex::box<int> bx(4, 5, 15);
            cortex::box<int> bxcheck(4, 5, 0);

            auto rbx { bx.shift_right(6) };

            REQUIRE(rbx == bxcheck);

            for (auto& elem : rbx)
                REQUIRE(elem == 0);
        }
    }

    SECTION("box::bit_not")
    {
        SECTION("Bit Not")
        {
            cortex::box<int> bx(4, 5, 15);
            cortex::box<int> bxcheck(4, 5, -16);

            auto rbx { bx.bit_not() };

            REQUIRE(rbx == bxcheck);

            for (auto& elem : bx)
                REQUIRE(elem == 15);

            for (auto& elem : rbx)
                REQUIRE(elem == -16);
        }
    }
}