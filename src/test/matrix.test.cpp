#include <catch2/catch.hpp>
#include <matrix.hpp>
#include <utility>
#include <string>


TEST_CASE("Constructors of Matrix")
{
    SECTION("Default constructor")
    {
        cortex::matrix<int> m;
        REQUIRE(m.size() == 0);
        REQUIRE(m.row_size() == 0);
        REQUIRE(m.column_size() == 0);
    }

    SECTION("Constructor with size")
    {
        cortex::matrix<int> m(10, 10);
        REQUIRE(m.size() == 100);
        REQUIRE(m.row_size() == 10);
        REQUIRE(m.column_size() == 10);
    }

    SECTION("Constructor with size and value")
    {
        cortex::matrix<int> m(10, 10, 1);
        REQUIRE(m.size() == 100);
        REQUIRE(m.row_size() == 10);
        REQUIRE(m.column_size() == 10);
    }

    SECTION("Copy constructor")
    {
        cortex::matrix<int> m(10, 10, 1);
        cortex::matrix<int> n(m);

        REQUIRE(n.size() == 100);
        REQUIRE(n.row_size() == 10);
        REQUIRE(n.column_size() == 10);

        for (auto i { 0UL }; i < m.size(); ++i)
        {
            REQUIRE(n[i] == 1);
            REQUIRE(m[i] == 1);
        }
    }

    SECTION("Move constructor")
    {
        cortex::matrix<int> m(10, 10, 1);

        for (int i = 0; i < 100; ++i)
            REQUIRE(m[i] == 1);

        cortex::matrix<int> n(std::move(m));

        REQUIRE(n.size() == 100);
        REQUIRE(n.row_size() == 10);
        REQUIRE(n.column_size() == 10);

        for (auto i { 0UL }; i < m.size(); ++i)
            REQUIRE(n[i] == 1);
    }

    SECTION("Copy assignment")
    {
        cortex::matrix<int> m(10, 10, 1);
        cortex::matrix<int> n;

        REQUIRE(n.size() == 0);
        REQUIRE(n.row_size() == 0);
        REQUIRE(n.column_size() == 0);

        n = m;
        REQUIRE(n.size() == 100);
        REQUIRE(n.row_size() == 10);
        REQUIRE(n.column_size() == 10);

        for (auto i { 0UL }; i < m.size(); ++i)
        {
            REQUIRE(n[i] == 1);
            REQUIRE(m[i] == 1);
        }
    }

    SECTION("Move assignment")
    {
        cortex::matrix<int> m(10, 10, 1);
        cortex::matrix<int> n;

        REQUIRE(n.size() == 0);
        REQUIRE(n.row_size() == 0);
        REQUIRE(n.column_size() == 0);

        n = std::move(m);
        REQUIRE(n.size() == 100);
        REQUIRE(n.row_size() == 10);
        REQUIRE(n.column_size() == 10);

        for (auto i { 0UL }; i < m.size(); ++i)
            REQUIRE(n[i] == 1);
    }
}

TEST_CASE("Matrix Meta-Data Access")
{
    SECTION("matrix::size")
    {
        cortex::matrix<int> m(10, 10);
        REQUIRE(m.size() == 100);
    }

    SECTION("matrix::max_size")
    {
        cortex::matrix<int> m(10, 10);
        REQUIRE(m.row_size() == 10);
    }

    SECTION("matrix::row_size")
    {
        cortex::matrix<int> m(10, 10);
        REQUIRE(m.row_size() == 10);
    }

    SECTION("matrix::column_size")
    {
        cortex::matrix<int> m(10, 10);
        REQUIRE(m.column_size() == 10);
    }

    SECTION("matrix::dimensions")
    {
        cortex::matrix<int> m(10, 10, 1);
        auto [c, r] = m.dimensions();

        REQUIRE(c == 10);
        REQUIRE(r == 10);
    }

    SECTION("matrix::empty")
    {
        cortex::matrix<int> m;
        REQUIRE(m.empty());
    }

    SECTION("matrix::empty")
    {
        cortex::matrix<int> m(10, 10, 1);
        REQUIRE(!m.empty());
    }
}

TEST_CASE("Element Access")
{
    SECTION("matrix::data")
    {
        cortex::matrix<int> m(10, 10, 1);
        REQUIRE(m.data() != nullptr);
    }

    SECTION("matrix::front")
    {
        cortex::matrix<int> m(10, 10, 1);
        REQUIRE(m.front() == 1);

        m.front() = 2;
        REQUIRE(m.front() == 2);
    }

    SECTION("matrix::back")
    {
        cortex::matrix<int> m(10, 10, 1);
        REQUIRE(m.back() == 1);

        m.back() = 2;
        REQUIRE(m.back() == 2);
    }

    SECTION("matrix::at")
    {
        cortex::matrix<int> m(10, 10, 1);
        REQUIRE(m.at(0, 1) == 1);

        m.at(0, 1) = 2;
        REQUIRE(m.at(0, 1) == 2);

        REQUIRE_THROWS_AS(m.at(10, 1), std::out_of_range);
    }

    SECTION("matrix::operator()")
    {
        cortex::matrix<int> m(10, 10, 1);
        REQUIRE(m(0, 1) == 1);

        m(0, 1) = 2;
        REQUIRE(m(0, 1) == 2);

        REQUIRE_THROWS_AS(m(10, 1), std::out_of_range);
    }
}

TEST_CASE("Element Modifiers")
{
    SECTION("matrix::swap")
    {
        cortex::matrix<int> m(2, 3, 1);
        cortex::matrix<int> n(7, 4, 2);

        for (auto i { 0UL }; i < m.size(); ++i)
            REQUIRE(m[i] == 1);

        for (auto i { 0UL }; i < n.size(); ++i)
            REQUIRE(n[i] == 2);

        m.swap(n);

        for (auto i { 0UL }; i < m.size(); ++i)
            REQUIRE(m[i] == 2);

        for (auto i { 0UL }; i < n.size(); ++i)
            REQUIRE(n[i] == 1);
    }

    SECTION("matrix - std::swap")
    {
        cortex::matrix<int> m(2, 3, 1);
        cortex::matrix<int> n(7, 4, 2);

        for (auto i { 0UL }; i < m.size(); ++i)
            REQUIRE(m[i] == 1);

        for (auto i { 0UL }; i < n.size(); ++i)
            REQUIRE(n[i] == 2);

        std::swap(m, n);

        for (auto i { 0UL }; i < m.size(); ++i)
            REQUIRE(m[i] == 2);

        for (auto i { 0UL }; i < n.size(); ++i)
            REQUIRE(n[i] == 1);
    }

    SECTION("matrix::flatten")
    {
        cortex::matrix<int> m(2, 3, 1);
        std::vector<int> v = m.flatten();

        for (auto i { 0UL }; i < v.size(); ++i)
            REQUIRE(v[i] == 1);
    }

    SECTION("matrix::clear")
    {
        cortex::matrix<int> m(10, 10, 1);

        auto ptr { m.begin().base() };
        REQUIRE(m.data() == std::to_address(ptr));

        m.clear();

        for (auto& elem : m)
            REQUIRE(elem == 0);

        REQUIRE(m.empty());
        REQUIRE(m.size() == 0);
        REQUIRE(m.capacity() == 100);

        REQUIRE_THROWS_AS(m.at(0, 0) = 1, std::out_of_range);

        REQUIRE(m.empty());
        REQUIRE(m.size() == 0);
        REQUIRE(m.capacity() == 100);
        REQUIRE(m.data() != nullptr);
        REQUIRE(m.data() != decltype(m)::pointer());
    }

    SECTION("matrix::clear - No allocated recources")
    {
        cortex::matrix<int> m;

        REQUIRE(m.empty());
        REQUIRE(m.size() == 0);
        REQUIRE(m.capacity() == 0);
        REQUIRE(m.data() == nullptr);
        REQUIRE(m.data() == decltype(m)::pointer());

        m.clear();

        REQUIRE(m.empty());
        REQUIRE(m.size() == 0);
        REQUIRE(m.capacity() == 0);
        REQUIRE(m.data() == nullptr);
        REQUIRE(m.data() == decltype(m)::pointer());
    }

    SECTION("matrix::clear - Uninitialized Resources")
    {
        cortex::matrix<int> m(10, 10);

        REQUIRE(!m.empty());
        REQUIRE(m.size() == 100);
        REQUIRE(m.capacity() == 100);
        REQUIRE(m.row_size() == 10);
        REQUIRE(m.column_size() == 10);
        REQUIRE(m.data() != nullptr);

        m.clear();

        REQUIRE(m.empty());
        REQUIRE(m.size() == 0);
        REQUIRE(m.capacity() == 100);
        REQUIRE(m.column_size() == 0);
        REQUIRE(m.row_size() == 0);
        REQUIRE(m.data() != nullptr);
    }

    SECTION("matrix::reserve")
    {
        cortex::matrix<int> m(7, 3, 1);

        REQUIRE(m.capacity() == 21);

        m.reserve(8, 4);

        REQUIRE(m.capacity() == 32);
    }

    SECTION("matrix::reserve - column and row order preservation")
    {
        cortex::matrix<int> m(7, 3, 1);

        REQUIRE(m.capacity() == 21);
        REQUIRE(m.row_size() == 7);
        REQUIRE(m.column_size() == 3);

        for (auto& elem : m)
            REQUIRE(elem == 1);

        m.reserve(8, 4);

        REQUIRE(m.capacity() == 32);
        REQUIRE(m.row_size() == 8);
        REQUIRE(m.column_size() == 4);

        for (auto elem { m.begin() }; elem != m.cend(); ++elem)
        {
            auto dist { static_cast<decltype(m)::size_type>(std::distance(m.begin(), elem)) };
            if (dist < m.size())
                REQUIRE(*elem == 1);
            else
                REQUIRE(*elem == 0);
        }
    }
}

TEST_CASE("Iterators")
{
    SECTION("Range for-loop")
    {
        cortex::matrix<int> m(10, 10, 1);

        for (auto& elem : m)
        {
            REQUIRE(elem == 1);
            elem = 2;
        }

        for (auto& elem : m)
            REQUIRE(elem == 2);
    }

    SECTION("matrix::begin and matrix::end")
    {
        cortex::matrix<int> m(10, 10);

        std::iota(m.begin(), m.end(), 1);

        auto idx { 1 };
        for (auto& elem : m)
        {
            REQUIRE(elem == idx++);
            elem = 2 * elem;
        }

        idx = 1;
        for (auto& elem : m)
        {
            REQUIRE(elem == idx * 2);
            ++idx;
        }
    }
}

TEST_CASE("Comparison")
{
    SECTION("Equality")
    {
        cortex::matrix<int> m(10, 10, 1);
        cortex::matrix<int> n(10, 10, 1);

        REQUIRE(m == m);
        REQUIRE(m == n);
    }

    // SECTION("")
    // {
    //     std::vector<int> v(10, 1);
    //     std::vector<int> w(10, 2);

    //     REQUIRE((v <=> w) == std::strong_ordering::less);
    //     REQUIRE((w <=> v) == std::strong_ordering::greater);
    // }

    SECTION("Equality - Different size")
    {
        cortex::matrix<int> m(5, 8, 1);
        cortex::matrix<int> n(4, 13, 1);

        REQUIRE(m != n);
        REQUIRE(n != m);
    }

    SECTION("Inequality")
    {
        cortex::matrix<int> m(10, 10, 1);
        cortex::matrix<int> n(10, 10, 2);

        REQUIRE(m != n);
        REQUIRE(n != m);
    }

    SECTION("Inequality - different size")
    {
        cortex::matrix<int> m(13, 6, 1);
        cortex::matrix<int> n(17, 11, 1);

        REQUIRE(m != n);
        REQUIRE(n != m);
    }

    SECTION("Inequality - different data")
    {
        cortex::matrix<int> m(10, 10, 1);
        cortex::matrix<int> n(10, 10, 2);

        REQUIRE(m != n);
        REQUIRE(n != m);
    }

    SECTION("Inequality - different data - different size")
    {
        cortex::matrix<int> m(13, 6, 1);
        cortex::matrix<int> n(17, 11, 2);

        REQUIRE(m != n);
        REQUIRE(n != m);
    }
    
    // Lexigraphical Compare Doesn't Like My Normal Iterator
    // SECTION("Spaceship - different data")
    // {
    //     cortex::matrix<int> m(10, 10, 1);
    //     cortex::matrix<int> n(10, 10, 2);

    //     REQUIRE((m <=> n) == std::strong_ordering::less);
    //     REQUIRE((n <=> m) == std::strong_ordering::greater);
    // }

    // SECTION("Spaceship - different size")
    // {
    //     cortex::matrix<int> m(13, 6, 1);
    //     cortex::matrix<int> n(17, 11, 1);

    //     REQUIRE((m <=> n) == std::strong_ordering::less);
    //     REQUIRE((n <=> m) == std::strong_ordering::greater);
    // }

    // SECTION("Spaceship - different data - different size")
    // {
    //     cortex::matrix<int> m(13, 6, 1);
    //     cortex::matrix<int> n(17, 11, 2);

    //     REQUIRE((m <=> n) == std::strong_ordering::less);
    //     REQUIRE((n <=> m) == std::strong_ordering::greater);
    // }

    // SECTION("Spaceship - same data")
    // {
    //     cortex::matrix<int> m(10, 10, 1);
    //     cortex::matrix<int> n(10, 10, 1);

    //     REQUIRE((m <=> n) == std::strong_ordering::equal);
    //     REQUIRE((n <=> m) == std::strong_ordering::equal);
    // }

    SECTION("Less Than - different data")
    {
        cortex::matrix<int> m(10, 10, 1);
        cortex::matrix<int> n(10, 10, 2);

        REQUIRE(m < n);
        REQUIRE(!(n < m));
    }

    SECTION("Less Than - different size")
    {
        cortex::matrix<int> m(13, 6, 1);
        cortex::matrix<int> n(17, 11, 1);

        REQUIRE(m < n);
        REQUIRE(!(n < m));
    }

    SECTION("Less Than - different data - different size")
    {
        cortex::matrix<int> m(13, 6, 2);
        cortex::matrix<int> n(17, 11, 1);

        REQUIRE(!(m < n));
        REQUIRE(n < m);
    }

    SECTION("Less Than - same data")
    {
        cortex::matrix<int> m(10, 10, 1);
        cortex::matrix<int> n(10, 10, 1);

        REQUIRE(!(m < n));
        REQUIRE(!(n < m));
    }

    SECTION("Greater Than - different data")
    {
        cortex::matrix<int> m(10, 10, 1);
        cortex::matrix<int> n(10, 10, 2);

        REQUIRE(n > m);
        REQUIRE(!(m > n));
    }

    SECTION("Greater Than - different size")
    {
        cortex::matrix<int> m(13, 6, 1);
        cortex::matrix<int> n(17, 11, 1);

        REQUIRE(n > m);
        REQUIRE(!(m > n));
    }

    SECTION("Greater Than - different data - different size")
    {
        cortex::matrix<int> m(13, 6, 2);
        cortex::matrix<int> n(17, 11, 1);

        REQUIRE(m > n);
        REQUIRE(!(n > m));
    }

    SECTION("Greater Than - same data")
    {
        cortex::matrix<int> m(10, 10, 1);
        cortex::matrix<int> n(10, 10, 1);

        REQUIRE(!(n > m));
        REQUIRE(!(m > n));
    }

    SECTION("Less Than or Equal - different data")
    {
        cortex::matrix<int> m(10, 10, 1);
        cortex::matrix<int> n(10, 10, 2);

        REQUIRE(m <= n);
        REQUIRE(!(n <= m));
    }

    SECTION("Less Than or Equal - different size")
    {
        cortex::matrix<int> m(13, 6, 1);
        cortex::matrix<int> n(17, 11, 1);

        REQUIRE(m <= n);
        REQUIRE(!(n <= m));
    }

    SECTION("Less Than or Equal - different data - different size")
    {
        cortex::matrix<int> m(13, 6, 2);
        cortex::matrix<int> n(17, 11, 1);

        REQUIRE(m > n);
        REQUIRE(n <= m);
    }

    SECTION("Less Than or Equal - same data")
    {
        cortex::matrix<int> m(10, 10, 1);
        cortex::matrix<int> n(10, 10, 1);

        REQUIRE(m <= n);
        REQUIRE(n <= m);
    }

    SECTION("Greater Than or Equal - different data")
    {
        cortex::matrix<int> m(10, 10, 1);
        cortex::matrix<int> n(10, 10, 2);

        REQUIRE(n >= m);
        REQUIRE(!(m >= n));
    }

    SECTION("Greater Than or Equal - different size")
    {
        cortex::matrix<int> m(13, 6, 1);
        cortex::matrix<int> n(17, 11, 1);

        REQUIRE(n >= m);
        REQUIRE(!(m >= n));
    }

    SECTION("Greater Than or Equal - different data - different size")
    {
        cortex::matrix<int> m(13, 6, 2);
        cortex::matrix<int> n(17, 11, 1);

        REQUIRE(m >= n);
        REQUIRE(!(n >= m));
    }

    SECTION("Greater Than or Equal - same data")
    {
        cortex::matrix<int> m(10, 10, 1);
        cortex::matrix<int> n(10, 10, 1);

        REQUIRE(m >= n);
        REQUIRE(n >= m);
    }
}

TEST_CASE("Arithmatic Operators")
{
    SECTION("matrix::add")
    {
        SECTION("Same type")
        {
            cortex::matrix<int> m(10, 10, 1);
            cortex::matrix<int> n(10, 10, 2);
            cortex::matrix<int> rcheck(10, 10, 3);

            auto r { m.add(n) };

            REQUIRE(r == rcheck);

            for (auto& elem : m)
                REQUIRE(elem == 1);
            
            for (auto& elem : n)
                REQUIRE(elem == 2);
            
            for (auto& elem : r)
                REQUIRE(elem == 3);
        }

        SECTION("Different type")
        {
            cortex::matrix<int> m(10, 10, 1);
            cortex::matrix<double> n(10, 10, 2.5);
            cortex::matrix<double> rcheck(10, 10, 3.5);

            auto r { m.add(n) };

            REQUIRE(r == rcheck);

            for (auto& elem : m)
                REQUIRE(elem == 1);
            
            for (auto& elem : n)
                REQUIRE(elem == 2.5);

            for (auto& elem : r)
                REQUIRE(elem == 3.5);
        }

        SECTION("Same Matrix")
        {
            cortex::matrix<int> m(10, 10, 1);
            cortex::matrix<double> rcheck(10, 10, 2);

            auto r { m.add(m) };

            REQUIRE(r == rcheck);

            for (auto& elem : m)
                REQUIRE(elem == 1);

            for (auto& elem : r)
                REQUIRE(elem == 2);
        }

        SECTION("Same Matrix + Assign")
        {
            cortex::matrix<int> m(10, 10, 1);
            cortex::matrix<double> mcheck(10, 10, 2);

            m = m.add(m);

            REQUIRE(m == mcheck);

            for (auto& elem : m)
                REQUIRE(elem == 2);
        }

        SECTION("Size Mismatch")
        {
            cortex::matrix<int> m(10, 10, 1);
            cortex::matrix<double> n(10, 11, 2.5);

            REQUIRE_THROWS_AS(m.add(n), std::invalid_argument);
        }

        SECTION("Non `Addable` or `AddableWith` type")
        {
            using namespace std::string_literals;

            cortex::matrix<std::string> m(10, 10, "hello"s);
            cortex::matrix<std::wstring> n(10, 10, L"world"s);

            /// To test, uncomment and code should not compile
            // auto r { m.add(n) };
        }
    }

    SECTION("matrix::sub")
    {
        SECTION("Same type")
        {
            cortex::matrix<int> m(10, 10, 1);
            cortex::matrix<int> n(10, 10, 2);
            cortex::matrix<int> rcheck(10, 10, -1);

            auto r { m.sub(n) };

            REQUIRE(r == rcheck);

            for (auto& elem : m)
                REQUIRE(elem == 1);
            
            for (auto& elem : n)
                REQUIRE(elem == 2);
            
            for (auto& elem : r)
                REQUIRE(elem == -1);
        }

        SECTION("Different type")
        {
            cortex::matrix<int> m(10, 10, 1);
            cortex::matrix<double> n(10, 10, 2.5);
            cortex::matrix<double> rcheck(10, 10, -1.5);

            auto r { m.sub(n) };

            REQUIRE(r == rcheck);

            for (auto& elem : m)
                REQUIRE(elem == 1);
            
            for (auto& elem : n)
                REQUIRE(elem == 2.5);

            for (auto& elem : r)
                REQUIRE(elem == -1.5);
        }

        SECTION("Same Matrix")
        {
            cortex::matrix<int> m(10, 10, 1);
            cortex::matrix<double> rcheck(10, 10, 0);

            auto r { m.sub(m) };

            REQUIRE(r == rcheck);

            for (auto& elem : m)
                REQUIRE(elem == 1);

            for (auto& elem : r)
                REQUIRE(elem == 0);
        }

        SECTION("Same Matrix + Assign")
        {
            cortex::matrix<int> m(10, 10, 1);
            cortex::matrix<double> mcheck(10, 10, 0);

            m = m.sub(m);

            REQUIRE(m == mcheck);

            for (auto& elem : m)
                REQUIRE(elem == 0);
        }

        SECTION("Non `Subtractable` or `SubtractableWith` type")
        {
            using namespace std::string_literals;

            cortex::matrix<std::string> m(10, 10, "hello"s);
            cortex::matrix<std::wstring> n(10, 10, L"world"s);

            /// To test, uncomment and code should not compile
            // auto r { m.sub(n) };
        }
    }

    SECTION("matrix::mul")
    {
        SECTION("Same type")
        {
            cortex::matrix<int> m(10, 10, 2);
            cortex::matrix<int> n(10, 10, 5);
            cortex::matrix<int> rcheck(10, 10, 10);

            auto r { m.mul(n) };

            REQUIRE(r == rcheck);

            for (auto& elem : m)
                REQUIRE(elem == 2);
            
            for (auto& elem : n)
                REQUIRE(elem == 5);
            
            for (auto& elem : r)
                REQUIRE(elem == 10);
        }

        SECTION("Different type")
        {
            cortex::matrix<int> m(10, 10, 7);
            cortex::matrix<double> n(10, 10, 2.5);
            cortex::matrix<double> rcheck(10, 10, 17.5);

            auto r { m.mul(n) };

            REQUIRE(r == rcheck);

            for (auto& elem : m)
                REQUIRE(elem == 7);
            
            for (auto& elem : n)
                REQUIRE(elem == 2.5);

            for (auto& elem : r)
                REQUIRE(elem == 17.5);
        }

        SECTION("Same Matrix")
        {
            cortex::matrix<int> m(10, 10, 5);
            cortex::matrix<double> rcheck(10, 10, 25);

            auto r { m.mul(m) };

            REQUIRE(r == rcheck);

            for (auto& elem : m)
                REQUIRE(elem == 5);

            for (auto& elem : r)
                REQUIRE(elem == 25);
        }

        SECTION("Same Matrix + Assign")
        {
            cortex::matrix<int> m(10, 10, 5);
            cortex::matrix<int> mcheck(10, 10, 25);

            m = m.mul(m);

            REQUIRE(m == mcheck);

            for (auto& elem : m)
                REQUIRE(elem == 25);
        }

        SECTION("Non `muliplicible` or `muliplicibleWith` type")
        {
            using namespace std::string_literals;

            cortex::matrix<std::string> m(10, 10, "hello"s);
            cortex::matrix<std::wstring> n(10, 10, L"world"s);

            /// To test, uncomment and code should not compile
            // auto r { m.mul(n) };
        }

        SECTION("Scalar Multiply")
        {
            cortex::matrix<int> m(10, 10, 5);
            cortex::matrix<int> mcheck(10, 10, 35);

            auto r { m.mul(7) };

            REQUIRE(r == mcheck);

            for (auto& elem : r)
                REQUIRE(elem == 35);
        }
    }

     SECTION("matrix::div")
    {
        SECTION("Same type")
        {
            cortex::matrix<int> m(10, 10, 2);
            cortex::matrix<int> n(10, 10, 5);
            cortex::matrix<int> rcheck(10, 10, 2 / 5);

            auto r { m.div(n) };

            REQUIRE(r == rcheck);

            for (auto& elem : m)
                REQUIRE(elem == 2);
            
            for (auto& elem : n)
                REQUIRE(elem == 5);
            
            for (auto& elem : r)
                REQUIRE(elem == 2 / 5);
        }

        SECTION("Different type")
        {
            cortex::matrix<int> m(10, 10, 7);
            cortex::matrix<double> n(10, 10, 2.5);
            cortex::matrix<double> rcheck(10, 10, 2.8);

            auto r { m.div(n) };

            REQUIRE(r == rcheck);

            for (auto& elem : m)
                REQUIRE(elem == 7);
            
            for (auto& elem : n)
                REQUIRE(elem == 2.5);

            for (auto& elem : r)
                REQUIRE(elem == 2.8);
        }

        SECTION("Different type - Integer division")
        {
            cortex::matrix<int> m(10, 10, 5);
            cortex::matrix n(10, 10, 2.);
            cortex::matrix<double> rcheck(10, 10, 2.5);

            auto r { m.div(n) };

            REQUIRE(r == rcheck);

            for (auto& elem : m)
                REQUIRE(elem == 5);
            
            for (auto& elem : n)
                REQUIRE(elem == 2);

            for (auto& elem : r)
                REQUIRE(elem == 2.5);
        }

        SECTION("Same Matrix")
        {
            cortex::matrix<int> m(10, 10, 5);
            cortex::matrix<double> rcheck(10, 10, 1);

            auto r { m.div(m) };

            REQUIRE(r == rcheck);

            for (auto& elem : m)
                REQUIRE(elem == 5);

            for (auto& elem : r)
                REQUIRE(elem == 1);
        }

        SECTION("Same Matrix + Assign")
        {
            cortex::matrix<int> m(10, 10, 5);
            cortex::matrix<int> mcheck(10, 10, 1);

            m = m.div(m);

            REQUIRE(m == mcheck);

            for (auto& elem : m)
                REQUIRE(elem == 1);
        }

        SECTION("Non `diviplicible` or `diviplicibleWith` type")
        {
            using namespace std::string_literals;

            cortex::matrix<std::string> m(10, 10, "hello"s);
            cortex::matrix<std::wstring> n(10, 10, L"world"s);

            /// To test, uncomment and code should not compile
            // auto r { m.div(n) };
        }

        SECTION("Scalar Divide")
        {
            cortex::matrix<int> m(10, 10, 5);
            cortex::matrix<double> mcheck(10, 10, 2.5);

            auto r { m.div(2.) };

            REQUIRE(r == mcheck);

            for (auto& elem : r)
                REQUIRE(elem == 2.5);
        }
    }
}