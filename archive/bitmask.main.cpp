#include <vector>
#include <iostream>
#include <matrix.hpp>

auto main() -> int
{
    std::vector<int> v { 1, 2, 1, 1, 1, 5, 2, 5, 2, 2 };
    cortex::matrix<int> bx(, 2);
    cortex::matrix<bool> mcheck(5, 2);

    std::cout << "v: ";
    for (auto i : v)
        std::cout << i << " ";
    std::cout << std::endl << "----------------------" << std::endl;

    for (size_t i = 0; i < v.size(); ++i)
    {
        bx[i] = v[i];
        mcheck[i] = v[i] == 2;
    }

    auto rbx { bx == 2 };

    std::cout << std::boolalpha << "Passed: " << (r == mcheck) << std::noboolalpha << std::endl;
    std::cout << "----------------------" << std::endl;

    for (auto& elem : rbx)
        std::cout << elem << " ";

    std::cout << std::endl;
    
    return 0;
}