#include <iostream>
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
    
    print(bx);

    /// Output:
    /// { 1 2 3 }
    /// { 4 5 6 }
    /// { 7 8 9 }    

    print(bx.rrotate());

    /// Output:
    /// { 7 4 1 }
    /// { 8 5 2 }
    /// { 9 6 3 }

    print(bx.lrotate());

    /// Output:
    /// { 3 6 9 }
    /// { 2 5 8 }
    /// { 1 4 7 }

    return 0;
}