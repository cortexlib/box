#include <catch2/catch.hpp>
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

        SECTION("Non `muliplicible` or `muliplicibleWith` type")
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

        SECTION("Non `diviplicible` or `diviplicibleWith` type")
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