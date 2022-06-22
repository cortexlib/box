# Header file `column.hpp`

``` cpp
#include "two_dim.hpp"

#define CORTEX_COLUMN_ITERATOR_HPP

namespace cortex
{
    template <typename _Iterator>
    class column_iterator;

    template <typename _Iterator>
    constexpr bool operator<(column_iterator<_Iterator> const& __lhs, column_iterator<_Iterator> const& __rhs) noexcept;

    template <typename _Iterator>
    constexpr bool operator>(column_iterator<_Iterator> const& __lhs, column_iterator<_Iterator> const& __rhs) noexcept;

    template <typename _Iterator>
    constexpr bool operator<=(column_iterator<_Iterator> const& __lhs, column_iterator<_Iterator> const& __rhs) noexcept;

    template <typename _Iterator>
    constexpr bool operator>=(column_iterator<_Iterator> const& __lhs, column_iterator<_Iterator> const& __rhs) noexcept;
}
```

column.hpp \\author Tyler Swann (oraqlle@github.com)

### Class `cortex::column_iterator`

``` cpp
template <typename _Iterator>
class column_iterator
: public two_dim_iterator<_Iterator>
{
public:
    constexpr column_iterator() noexcept;

    constexpr column_iterator('hidden' const& ptr, 'hidden' ridx, 'hidden' cidx, 'hidden' rows, 'hidden' columns) noexcept;

    constexpr column_iterator<_Iterator>& operator++() noexcept;

    constexpr column_iterator<_Iterator> operator++(int) noexcept;

    constexpr column_iterator<_Iterator>& operator--() noexcept;

    constexpr column_iterator<_Iterator> operator--(int) noexcept;
};
```

Column Iterator

A column iterator is an iterator that iterates a given two dimensional space in column order. Incrementing moves the iterator to the next item in that column and vice versa for decrementing. Incrementing from the last item in a column causes the iterator to jump to the first item in the next column. Like wise, decrementing from the first item in a column causes the iterator to jump to the last item in the previous column. A column iterator is derived from the base %cortex::two\_dim\_iterator.

### Constructor `cortex::column_iterator::column_iterator`

``` cpp
constexpr column_iterator() noexcept;
```

Default Constructor

Constructs a column iterator with the two\_dim\_iterators default constrcutor.

-----

### Constructor `cortex::column_iterator::column_iterator`

``` cpp
constexpr column_iterator('hidden' const& ptr, 'hidden' ridx, 'hidden' cidx, 'hidden' rows, 'hidden' columns) noexcept;
```

Explicit Value Constructor

Constructs a column iterator from a reference to an iterator of the underlying iterator type, the dimensions the column iterator can move through and the current point index the iterator points to. Calls the base class constructor.

#### Parameters

  - `ptr` - type: iterator\_type | qualifiers: \[const, ref\]
  - `ridx` - type: size\_type
  - `cidx` - type: size\_type
  - `rows` - type: size\_type
  - `columns` - type: size\_type

-----

### Function `cortex::column_iterator::operator++`

``` cpp
constexpr column_iterator<_Iterator>& operator++() noexcept;
```

Pre Increment Operator

Increments the iterator to the next item in the column. If the iterator is at the last item in the column, the iterator is set to the first item in the next column.

\\return constexpr column\_iterator&

-----

### Function `cortex::column_iterator::operator++`

``` cpp
constexpr column_iterator<_Iterator> operator++(int) noexcept;
```

Post Increment Operator

Increments the iterator to the next item in the column. If the iterator is at the last item in the column, the iterator is set to the first item in the next column. Returns the column iterator before the increment.

\\return constexpr column\_iterator

-----

### Function `cortex::column_iterator::operator--`

``` cpp
constexpr column_iterator<_Iterator>& operator--() noexcept;
```

Pre Decrement Operator

Decrements the iterator to the previous item in the column. If the iterator is at the first item in the column, the iterator is set to the last item in the previous column.

\\return constexpr column\_iterator&

-----

### Function `cortex::column_iterator::operator--`

``` cpp
constexpr column_iterator<_Iterator> operator--(int) noexcept;
```

Post Decrement Operator

Decrements the iterator to the previous item in the column. If the iterator is at the first item in the column, the iterator is set to the last item in the previous column. Returns the column iterator before the decrement.

\\return constexpr column\_iterator

-----

-----

### Function `cortex::operator<`

``` cpp
template <typename _Iterator>
constexpr bool operator<(column_iterator<_Iterator> const& __lhs, column_iterator<_Iterator> const& __rhs) noexcept;
```

Less Than Operator

Performs less-than comparison of two column iterators. A column iterator is considered less than another firstly, if it is at a lower column index. If the column indices are equal, the column iterator is considered less than another if it is at a lower row index.

#### Parameters

  - `__lhs` - type: column\_iterator\<\_Iterator\> | qualifiers: \[const, ref\]
  - `__rhs` - type: column\_iterator\<\_Iterator\> | qualifiers: \[const, ref\] \\return true \\return false

-----

### Function `cortex::operator>`

``` cpp
template <typename _Iterator>
constexpr bool operator>(column_iterator<_Iterator> const& __lhs, column_iterator<_Iterator> const& __rhs) noexcept;
```

Greater Than Operator Overload

Performs greater-than comparison of two column iterators. A column iterator is considered greater than another firstly, if it is at a higher column index. If the column indices are equal, the column iterator is considered greater than another if it is at a higher row index.

#### Parameters

  - `__lhs` - type: column\_iterator\<\_Iterator\> | qualifiers: \[const, ref\]
  - `__rhs` - type: column\_iterator\<\_Iterator\> | qualifiers: \[const, ref\] \\return true \\return false

-----

### Function `cortex::operator<=`

``` cpp
template <typename _Iterator>
constexpr bool operator<=(column_iterator<_Iterator> const& __lhs, column_iterator<_Iterator> const& __rhs) noexcept;
```

Less Than or Equal Operator

Performs less-than-or-equal comparison of two column iterators. A column iterator is considered less than or equal to another firstly, if they compare equal, secondly if they compare less than.

#### Parameters

  - `__lhs` - type: column\_iterator\<\_Iterator\> | qualifiers: \[const, ref\]
  - `__rhs` - type: column\_iterator\<\_Iterator\> | qualifiers: \[const, ref\] \\return true \\return false

-----

### Function `cortex::operator>=`

``` cpp
template <typename _Iterator>
constexpr bool operator>=(column_iterator<_Iterator> const& __lhs, column_iterator<_Iterator> const& __rhs) noexcept;
```

Greater Than or Equal Operator

Performs greater-than-or-equal comparison of two column iterators. A column iterator is considered greater than or equal to another firstly, if they compare equal, secondly if they compare greater than.

#### Parameters

  - `__lhs` - type: column\_iterator\<\_Iterator\> | qualifiers: \[const, ref\]
  - `__rhs` - type: column\_iterator\<\_Iterator\> | qualifiers: \[const, ref\] \\return true \\return false

-----
