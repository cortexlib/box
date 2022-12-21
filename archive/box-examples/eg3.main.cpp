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

auto square = [](auto x){ return x * x; };
auto xor_3 = [](auto x){ return x ^ 3; };

auto main() -> int
{
    cxl::box<int> bx { { 1, 2, 3 } 
                        , { 4, 5, 6 }
                        , { 7, 8, 9 } };

    /// box.map(square) could also be used.
    auto new_box = bx || square;

    print(new_box);

    auto other_box = new_box || square
                             || xor_3;

    print(other_box);

    return 0;
}