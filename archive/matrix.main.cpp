#include <iostream>
#include <matrix.hpp>
#include <utility>
#include <vector>

template<typename T>
void printArray(cortex::matrix<T> mat)
{
    for (auto elem { mat.begin() }; elem != mat.cend(); ++elem)
    {
        if ((std::distance(mat.begin(), elem) + 1) % mat.column_size() == 0)
            std::cout << *elem << "\n";
        else
            std::cout << *elem << ", ";
    }
    std::cout << "\n---------------------------------\n" << std::flush;
}

template<typename T>
void printArray(std::vector<T> vec)
{
    std::cout << "[ ";

    for (auto elem { vec.begin() }; elem != vec.cend(); ++elem)
    {
        if ((std::distance(vec.begin(), elem) + 1) % vec.size() == 0)
            std::cout << *elem << " ]";
        else
            std::cout << *elem << ", ";
    }

    std::cout << "\n---------------------------------\n" << std::flush;
}

auto main() -> int
{
    cortex::matrix<int> m(7, 3, 1);

    printArray(m);
    auto ptr { m.data() };
    std::cout << "Capacity: " 
              << m.capacity() 
              << " | Size: " 
              << m.size() 
              << " | Data: " 
              << m.data()
              << " | ptr: "
              << ptr
              << " | Value at ptr: "
              << *ptr  
              << "\n";

    m.reserve(8, 4);

    printArray(m);
    std::cout << "Capacity: " 
              << m.capacity() 
              << " | Size: " 
              << m.size() 
              << " | Data: " 
              << m.data()
              << " | ptr: "
              << ptr
              << " | Value at ptr: "
              << *ptr  
              << "\n";
    
    *(ptr + 1) = 2;
    std::cout << "ptr: "
              << ptr + 1
              << " | Value at ptr: "
              << *(ptr + 1)  
              << "\n";

    std::vector<int> v(7, 1);

    printArray(v);
    auto ptr2 { v.data() };
    std::cout << "Capacity: " 
              << v.capacity() 
              << " | Size: " 
              << v.size() 
              << " | Data: " 
              << v.data()
              << " | ptr2: "
              << ptr2 + 1
              << " | Value at ptr2: "
              << *(ptr2 + 1) 
              << "\n";

    v.reserve(9);

    printArray(v);
    std::cout << "Capacity: " 
              << v.capacity() 
              << " | Size: " 
              << v.size() 
              << " | Data: " 
              << v.data()
              << " | ptr2: "
              << ptr2
              << " | Value at ptr2: "
              << *ptr2  
              << "\n";
    
    *(ptr2 + 1) = 2;
    std::cout << "ptr2: "
              << ptr2 + 1
              << " | Value at ptr2: "
              << *(ptr2 + 1)  
              << "\n";
}