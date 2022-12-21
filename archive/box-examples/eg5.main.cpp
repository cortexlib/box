#include <iostream>
#include <algorithm>
#include <box/box.hxx>

template<typename T>
void print(const cxl::box<T>& bx)
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
                        , { 7, 8, 9 } };
    
    std::transform(bx.column_begin(1), bx.column_end(1), bx.column_begin(1), std::negate{});

    print(bx);

    /// Output:
    /// { 4 7 16 }
    /// { 5 17 74 }
    /// { 41 12 85 }

    return 0;
}