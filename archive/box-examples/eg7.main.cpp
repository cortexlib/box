#include <iostream>
#include <box/box.hxx>

template<typename T>
void print(const c::box<T>& bx)
{
    for (auto ridx { 0uL }; ridx < bx.rows(); ++ridx)
    {
        std::cout << "{ ";
        for (auto elem { bx.row_begin(ridx) }; elem != bx.row_end(ridx); ++elem)
            std::cout << *elem << ' ';
        std::cout << "}\n";
    }
}

auto main() -> int
{
    cxl::box<int> bx { { 1, 2, 3 } 
                        , { 4, 5, 6 }
                        , { 7, 8, 9 }
                        , { 10, 11, 12 } };
    
    print(bx);

    /// Output:
    /// { 1 2 3 }
    /// { 4 5 6 }
    /// { 7 8 9 }
    /// { 10, 11, 12 }

    bx.reshape(6, 2);

    print(bx);

    /// Output:
    /// { 0 0 }
    /// { 0 0 }
    /// { 0 0 }
    /// { 0 0 }
    /// { 0 0 }
    /// { 0 0 }

    return 0;
}