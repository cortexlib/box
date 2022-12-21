#include <iostream>
#include <vector>
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

auto add = [](auto x, auto v){ return x + v; };

auto main() -> int
{
    cxl::box<int> bx { { 1, 2, 3 } 
                        , { 4, 5, 6 }
                        , { 7, 8, 9 } };

    std::vector<int> v { 3, 5, 13, 1, 12, 68, 34, 4, 76 };

    
    auto new_box = bx.map(v, add);

    print(new_box);

    return 0;
}