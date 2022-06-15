# Cortex : { box }

[![Contributor Covenant](https://img.shields.io/badge/Contributor%20Covenant-2.1-4baaaa.svg)](CODE_OF_CONDUCT.md)
[![License](https://img.shields.io/github/license/cortexlib/box)](LICENSE.md)
![Current Release](https://img.shields.io/github/v/release/cortexlib/box)
![DDS Version](https://img.shields.io/badge/DDS%20Version-alpha--6-blue)
![C++ Standard](https://img.shields.io/badge/C%2B%2B%20Standard-C%2B%2B20-red)
![GCC](https://img.shields.io/badge/GCC-11.1.0-yellow)
![Clang](https://img.shields.io/badge/Clang-❌-yellow)

Box is a two dimensional generic container. It aims to provide expressive and dynamic operations that allow for easy fast mainpulation of the data's shape. Box is available under the `cortex::` namespace.

Box has been built and tested for C++20 only. This is because `box` relies on `std::ranges`.
Box also only works with GCC-11 currently due to Clang not having completed [PR0634R3](https://wg21.link/P0634R3) yet which invalidates part of the `std::ranges` library.

Box is built and packaged using the [BPT/DDS](https://github.com/vector-of-bool/dds) building tool. Click [here](https://dds.pizza) view the documentation and install instructions for BPT/DDS. BPT/DDS is a command line tool for managing dependencies and building applications in C++.

Box is part of a larger library called the [Cortex Library](https://github.com/cortexlib/cortexlib). You can include box independently in your project and only install box's dependencies or you can add the larger Cortex Library. Instructions are [here] (<- add link).

---

## Contents

- [Cortex : { box }](#cortex---box-)
  - [Contents](#contents)
  - [Features](#features)
  - [Adding Box to your BPT/DDS Project](#adding-box-to-your-bptdds-project)
  - [Examples](#examples)
    - [Operators](#operators)
    - [Mapping](#mapping)
    - [Row and Column Iterators](#row-and-column-iterators)
    - [Restructuring](#restructuring)
      - [Resize](#resize)
      - [Reshape](#reshape)
      - [Flips](#flips)
      - [Rotates](#rotates)
  - [Contributing and License](#contributing-and-license)
  - [Links and Resources](#links-and-resources)

---

## Features

- STL complient and valid begin and end iterators.
- Row and Column iterators allowing traversal and manipulation of discrete parts of the box.
- Works with range-for loops, STL algorithms and C++20's `std::ranges`.
- Scalar and Box comparison operators.
- Builtin function mapping and mapping operator overload.
- Common arithmatic and bitwise transformation methods.
- Operator overloads for arithmatic and bitwise transformations for expressive notation.
- Restructuring methods that can change the data's structure.
- Custom allocator support similar to the STL generic containers.

---

## Adding Box to your BPT/DDS Project

To add Box to your project is super simple. The first thing you need to do is add the repository that hosts the package. Box along with all of the cortexlib can be found on the [Trove Package Index](https://trovepi.dev). To add, simply run:

```sh
dds pkg repo add "https://trovepi.dev"
```

This will allow BPT/DDS to find the packages host by Trove. Once you've added the repo, go to your package.json5 file within your pojects directory and add box as a dependency.

```json5
{
    name: 'package',
    version: 'x.x.x',
    namespace: 'namespace',
    test_driver: 'Catch-Main',
    depends: [
        'cortex-box^1.0.0'
    ]
}
```

Finally, any library that uses Box needs to declare that it is in use. This is done in the library.json5 files corresponding to the indiviual libraries. More information on BPT/DDS package structures and libraries can be found [here](https://dds.pizza/docs/guide/packages.html).

```json5
{
    name: 'library',
    uses: [
        'cortex/box'
    ]
}
```

And you all set. On the next build run, BPT/DDS with install box and build against it.

---

## Examples

### Operators

Box has many operator overloads so that you can express common arithmatic, bitwise and restructuring operations with a simple notation. Check out the [docs](docs) for the full list.

```cpp
#include <iostream>
#include <box.hpp>

template<typename T>
void print(const cortex::box<T>& bx)
{
    for (auto ridx { 0uL }; ridx < bx.rows(); ++ridx)
    {
        std::cout << "{ ";
        /// Uses row iterators to traverse elements.
        for (auto elem { bx.row_begin(ridx) }; elem != bx.row_end(ridx); ++elem)
            std::cout << *elem << ' ';
        std::cout << "}\n";
    }
}

auto main() -> int
{
    cortex::box<int> bx { { 1, 2, 3 } 
                        , { 4, 5, 6 }
                        , { 7, 8, 9 } };

    /// Transposes box, multiplies by 3 and bit_or's every element against 4.
    auto new_box { !bx * 3 | 4 };

    print(new_box);

    /// Output:
    /// { 7 12 21 }
    /// { 6 15 28 }
    /// { 13 22 31 }

    return 0;
}
```

If you prefer, each operator has a corresponding method within the box, allowing for a method chaining notation instead.

```cpp
#include <iostream>
#include <box.hpp>

template<typename T>
void print(const cortex::box<T>& bx)
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
    cortex::box<int> bx { { 1, 2, 3 } 
                        , { 4, 5, 6 }
                        , { 7, 8, 9 } };

    auto new_box { bx.transpose().mul(3).bit_or(4) };

    print(new_box);

    /// Output:
    /// { 7 12 21 }
    /// { 6 15 28 }
    /// { 13 22 31 }

    return 0;
}
```

### Mapping

While box has iterators that are complient with the standard library's algorithms and the `std::ranges` library, box also has a convienent notation for mapping functions over a box. Mappings can be chained aswell.

```cpp
#include <iostream>
#include <box.hpp>

template<typename T>
void print(const cortex::box<T>& bx)
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
    cortex::box<int> bx { { 1, 2, 3 } 
                        , { 4, 5, 6 }
                        , { 7, 8, 9 } };

    /// box.map(square) could also be used.
    auto new_box = bx || square;

    print(new_box);

    /// Output:
    /// { 1 4 9 }
    /// { 16 25 36 }
    /// { 49 64 81 }

    auto other_box = new_box || square
                             || xor_3;

    print(other_box);

    /// Output:
    /// { 2 19 82 }
    /// { 259 626 1299 }
    /// { 2402 4099 6562 }

    return 0;
}
```

box::map is also overloaded to take other ranges or iterator pairs to map with the box.

```cpp
#include <iostream>
#include <vector>
#include <box.hpp>

template<typename T>
void print(const cortex::box<T>& bx)
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
    cortex::box<int> bx { { 1, 2, 3 } 
                        , { 4, 5, 6 }
                        , { 7, 8, 9 } };

    std::vector<int> v { 3, 5, 13, 1, 12, 68, 34, 4, 76 };

    
    auto new_box = bx.map(v, add);

    print(new_box);

    /// Output:
    /// { 4 7 16 }
    /// { 5 17 74 }
    /// { 41 12 85 }

    return 0;
}
```

### Row and Column Iterators

Box has to unique iterators, the row and column iterators. These iterators traverse a size field allowing them to jump discretely between rows or columns.

```cpp
#include <iostream>
#include <algorithm>
#include <box.hpp>

template<typename T>
void print(const cortex::box<T>& bx)
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
    cortex::box<int> bx { { 1, 2, 3 } 
                        , { 4, 5, 6 }
                        , { 7, 8, 9 } };
    
    /// Only negates elements in the middle (1st) column.
    std::transform(bx.column_begin(1), bx.column_end(1), bx.column_begin(1), std::negate{});

    print(bx);

    /// Output:
    /// { 1 -2 3 }
    /// { 4 -5 6 }
    /// { 7 -8 9 }

    return 0;
}
```

### Restructuring

Box sits between `std::vector` and `std::array` in terms of resource managment. The elements are stored dynamically but individual elements cannot be added to the box. However, a box is not fixed to its given size at construction. Box supportst two operations for changing the dimensions of the box.

Box also supports more literal transformations of the data it holds. You've already seen one, `box::transpose` (!) which performs the mathematical transpose. There are two other categories for transformations, flips and rotates.

#### Resize

Resizing allows the box's recources to potentially be reallocated if the new dimensions exceed the the old dimensions.

```cpp
#include <iostream>
#include <box.hpp>

template<typename T>
void print(const cortex::box<T>& bx)
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
    cortex::box<int> bx { { 1, 2, 3 } 
                        , { 4, 5, 6 }
                        , { 7, 8, 9 } };
    
    print(bx);

    /// Output:
    /// { 1 2 3 }
    /// { 4 5 6 }
    /// { 7 8 9 }

    bx.resize(4, 3);

    print(bx);

    /// Output:
    /// { 1 2 3 }
    /// { 4 5 6 }
    /// { 7 8 9 }
    /// { 0 0 0 }

    return 0;
}
```

#### Reshape

If you wish to change the dimensions of the box but its overall size remains the same, you can use the reshape method. This will alter the dimension of the box and how the data is viewed but but garuntees that resources wont be reallocated. Be warned that an exception will be thrown if the reshape fails.

```cpp
#include <iostream>
#include <box.hpp>

template<typename T>
void print(const cortex::box<T>& bx)
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
    cortex::box<int> bx { { 1, 2, 3 } 
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
```

#### Flips

Flips allow you to change the orientation of the data. Two flip methods exist as part of the box API; `box::vflip` which inverts the elements vertically and `box::hflip` which inverts the elements horizontlly.

```cpp
#include <iostream>
#include <box.hpp>

template<typename T>
void print(const cortex::box<T>& bx)
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
    cortex::box<int> bx { { 1, 2, 3 } 
                        , { 4, 5, 6 }
                        , { 7, 8, 9 } };
    
    print(bx);

    /// Output:
    /// { 1 2 3 }
    /// { 4 5 6 }
    /// { 7 8 9 }

    auto new_box { bx.vflip().hflip() };

    print(new_box);

    /// Output:
    /// { 9 8 7 }
    /// { 6 5 4 }
    /// { 3 2 1 }

    return 0;
}
```

#### Rotates

Rotates are the other form of data manipulation methods. Two rotates exist, `box::rrotate` which rotates the box 90 degrees to the left and `box::lrotate` which rotate the box 90 degrees to the right.

```cpp
#include <iostream>
#include <box.hpp>

template<typename T>
void print(const cortex::box<T>& bx)
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
    cortex::box<int> bx { { 1, 2, 3 } 
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
```

---

## Contributing and License

- Refer to [CONTRIBUTING.md](./CONTRIBUTING.md) for ways to contribute and support the development of `cortex::box`.

- Box is under the MIT License. Refer to [LICENSE](./LICENSE) for full details.

---

## Links and Resources

- [DDS](https://dds.pizza)
- [DDS Install Guide](https://dds.pizza/docs/tut/install.html)
- [Trove Package Index Homepage](https://trovepi.dev)
- [Cortex Library](https://github.com/cortexlib/cortexlib)
