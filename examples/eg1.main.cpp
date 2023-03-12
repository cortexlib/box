#include <iostream>
#include <data_structures/matrix.hxx>

template<typename T>
void print(const cxl::box<T>& bx)
{
    for (auto ridx { 0uL }; ridx < bx.num_rows(); ++ridx)
    {
        std::cout << "| ";
        for (auto cidx { 0uL }; cidx < bx.num_columns(); ++cidx)
            std::cout << bx(ridx, cidx) << ' ';
        std::cout << "|\n";
    }
}

auto main() -> int
{
    cxl::box<int> bx { { 1, 2, 3 } 
                     , { 4, 5, 6 }
                     , { 7, 8, 9 } };

    print(bx);

    return 0;
}