#include <matrix.hpp>

auto main() -> int
{
    cortex::matrix<int> m(10, 10, 1);

    std::cout << m.size() << std::endl;

    for (auto& elem : m)
        std::cout << elem << ", ";
    std::cout << std::endl;
    std::cout << std::endl;

    m.resize(12, 10);

    std::cout << m.size() << std::endl;

    for (auto& elem : m)
        std::cout << elem << ", ";
    std::cout << std::endl;

    return 0;
}