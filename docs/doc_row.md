# Header file `row.hpp`

``` cpp
#include "two_dim.hpp"

#define CORTEX_ROW_ITERATOR_HPP

namespace cortex
{
    template <typename _Iterator>
    class row_iterator;

    template <typename _Iterator>
    constexpr bool operator<(row_iterator<_Iterator> const& __lhs, row_iterator<_Iterator> const& __rhs) noexcept;

    template <typename _Iterator>
    constexpr bool operator>(row_iterator<_Iterator> const& __lhs, row_iterator<_Iterator> const& __rhs) noexcept;

    template <typename _Iterator>
    constexpr bool operator<=(row_iterator<_Iterator> const& __lhs, row_iterator<_Iterator> const& __rhs) noexcept;

    template <typename _Iterator>
    constexpr bool operator>=(row_iterator<_Iterator> const& __lhs, row_iterator<_Iterator> const& __rhs) noexcept;
}
```

Row Iterator

row.hpp \\author Tyler Swann (oraqlle@github.com) \\version 1.0.1 \\date 2022-05-20

\\ingroup %iterators

\\copyright Copyright (c) 2022

### Class `cortex::row_iterator`

``` cpp
template <typename _Iterator>
class row_iterator
: public two_dim_iterator<_Iterator>
{
public:
    constexpr row_iterator() noexcept;

    constexpr row_iterator('hidden' const& ptr, 'hidden' ridx, 'hidden' cidx, 'hidden' row, 'hidden' col) noexcept;

    constexpr row_iterator<_Iterator>& operator++() noexcept;

    constexpr row_iterator<_Iterator> operator++(int) noexcept;

    constexpr row_iterator<_Iterator>& operator--() noexcept;

    constexpr row_iterator<_Iterator> operator--(int) noexcept;
};
```

Row Iterator

A row iterator is a iterator that iterates a given two dimensional space in row order. Incrementing moves the iterator to the next item in that row and vice versa for decrementing. Incrementing from the last item in a row causes the iterator to jump to the first item in the next row. Like wise, decrementing from the first item in a row causes the iterator to jump to the last item in the previous row. A column iterator is derived from the base %cortex::two\_dim\_iterator.

### Constructor `cortex::row_iterator::row_iterator`

``` cpp
constexpr row_iterator() noexcept;
```

Default Constructor

Constructs a row iterator with the two\_dim\_iterators default constrcutor.

-----

### Constructor `cortex::row_iterator::row_iterator`

``` cpp
constexpr row_iterator('hidden' const& ptr, 'hidden' ridx, 'hidden' cidx, 'hidden' row, 'hidden' col) noexcept;
```

Explicit Value Constrcutor

Constructs a column iterator from a reference to an iterator of the underlying iterator type, the dimensions the column iterator can move through and the current point index the iterator points to. Calls the base class constructor.

#### Parameters

  - `ptr` - type: iterator\_type | qualifier: \[const, ref\]

-----

### Function `cortex::row_iterator::operator++`

``` cpp
constexpr row_iterator<_Iterator>& operator++() noexcept;
```

Pre Increment Operator

Increments the iterator to the next item in the row. If the iterator is at the end of the row, the iterator jumps to the first item in the next row.

\\return constexpr row\_iterator&

-----

### Function `cortex::row_iterator::operator++`

``` cpp
constexpr row_iterator<_Iterator> operator++(int) noexcept;
```

Post Increment Operator

Increments the iterator to the next item in the row. If the iterator is at the end of the row, the iterator jumps to the first item in the next row. Returns the iterator before the increment.

\\return constexpr row\_iterator

-----

### Function `cortex::row_iterator::operator--`

``` cpp
constexpr row_iterator<_Iterator>& operator--() noexcept;
```

Pre Decrement Operator

Decrements the iterator to the previous item in the row. If the iterator is at the first item in the row, the iterator jumps to the last item in the previous row.

\\return constexpr row\_iterator&

-----

### Function `cortex::row_iterator::operator--`

``` cpp
constexpr row_iterator<_Iterator> operator--(int) noexcept;
```

Post Decrement Operator

Decrements the iterator to the previous item in the row. If the iterator is at the first item in the row, the iterator jumps to the last item in the previous row. Returns the iterator before the decrement.

\\return constexpr row\_iterator

-----

-----

### Function `cortex::operator<`

``` cpp
template <typename _Iterator>
constexpr bool operator<(row_iterator<_Iterator> const& __lhs, row_iterator<_Iterator> const& __rhs) noexcept;
```

Less Than Operator

Performs less-than comparison of two row iterators. A row iterator is considered less than  another firstly, if it is at a lower row index. If the row indices are equal, the row iterator is considered less than another if it is at a lower column index.

#### Parameters

  - `__lhs` - type: row\_iterator\<\_Iterator\> | qualifier: \[const, ref\]
  - `__rhs` - type: row\_iterator\<\_Iterator\> | qualifier: \[const, ref\] \\return true \\return false

-----

### Function `cortex::operator>`

``` cpp
template <typename _Iterator>
constexpr bool operator>(row_iterator<_Iterator> const& __lhs, row_iterator<_Iterator> const& __rhs) noexcept;
```

Greater Than Operator

Performs greater-than comparison of two row iterators. A row iterator is considered greater than another firstly, if it is at a higher row index. If the row indices are equal, the row iterator is considered greater than another if it is at a higher column index.

#### Parameters

  - `__lhs` - type: row\_iterator\<\_Iterator\> | qualifier: \[const, ref\]
  - `__rhs` - type: row\_iterator\<\_Iterator\> | qualifier: \[const, ref\] \\return true \\return false

-----

### Function `cortex::operator<=`

``` cpp
template <typename _Iterator>
constexpr bool operator<=(row_iterator<_Iterator> const& __lhs, row_iterator<_Iterator> const& __rhs) noexcept;
```

Less Than or Equal Operator

Performs less-than-or-equal comparison of two row iterators. A row iterator is considered less than or equal to another firstly, if they compare equal, secondly if they compare less than.

#### Parameters

  - `__lhs` - type: row\_iterator\<\_Iterator\> | qualifier: \[const, ref\]
  - `__rhs` - type: row\_iterator\<\_Iterator\> | qualifier: \[const, ref\] \\return true \\return false

-----

### Function `cortex::operator>=`

``` cpp
template <typename _Iterator>
constexpr bool operator>=(row_iterator<_Iterator> const& __lhs, row_iterator<_Iterator> const& __rhs) noexcept;
```

Greater Than or Equal Operator

Performs greater-than-or-equal comparison of two row iterators. A row iterator is considered greater than or equal to another firstly, if they compare equal, secondly if they compare greater than.

#### Parameters

  - `__rhs` - \\return true \\return false

-----
