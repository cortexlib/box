# Header file `two_dim.hpp`

``` cpp
#define CORTEX_TWO_DIM_ITERATOR_HPP

namespace cortex
{
    template <typename _Iterator>
    class two_dim_iterator;

    template <typename _IteratorL, typename _IteratorR>
    constexpr bool operator==(two_dim_iterator<_IteratorL> const& __lhs, two_dim_iterator<_IteratorR> const& __rhs) noexcept(noexcept(__lhs.base() == __rhs.base()));

    template <typename _IteratorL, typename _IteratorR>
    constexpr auto operator<=>(two_dim_iterator<_IteratorL> const& __lhs, two_dim_iterator<_IteratorR> const& __rhs) noexcept(noexcept(__lhs.base()<=>__rhs.base()));
}
```

Two Dimensional Iterator Base Class

Author: Tyler Swann (oraqlle@github.com)

Header Version: v1.0.1

Date: 25-06-2022

License: MIT

Copyright: Copyright (c) 2022

two\_dim.hpp

### Class `cortex::two_dim_iterator`

``` cpp
template <typename _Iterator>
class two_dim_iterator
{
public:
    constexpr two_dim_iterator(two_dim_iterator<_Iterator>&&) = delete;

    constexpr two_dim_iterator() noexcept;

    constexpr two_dim_iterator(const two_dim_iterator<_Iterator>& __other) noexcept;

    constexpr two_dim_iterator('hidden' const& ptr, 'hidden' ridx, 'hidden' cidx, 'hidden' rows, 'hidden' columns) noexcept;

    constexpr two_dim_iterator<_Iterator>& operator=(const two_dim_iterator<_Iterator>& __other) noexcept;

    constexpr 'hidden' operator*() noexcept;

    constexpr 'hidden' operator*() const noexcept;

    constexpr 'hidden' operator->() noexcept;

    constexpr 'hidden' operator->() const noexcept;

    constexpr 'hidden'& base() const noexcept;

    constexpr 'hidden' rows() const noexcept;

    constexpr 'hidden' columns() const noexcept;

    constexpr 'hidden' row_index() const noexcept;

    constexpr 'hidden' column_index() const noexcept;
};
```

Two Dimensional Iterator

*Notes:* Potential problem incrementing or decrementing the default constructed object as it refers to the the default constructed iterator type and causes segmentation fault on dereference.

The base class for a two dimensional iterator. Constructs the underlying iterator and the given position of the iterator and dimensions of in which it occupies.

### Constructor `cortex::two_dim_iterator::two_dim_iterator`

``` cpp
constexpr two_dim_iterator(two_dim_iterator<_Iterator>&&) = delete;
```

Deleteted Constructors

The move, iterator\_type copy and iterator\_type move constructors and assignemnts are deleted as these constructors are illogical for iterator types and copying just the underlying iterator does not give sufficitent information to the iterator.

-----

### Constructor `cortex::two_dim_iterator::two_dim_iterator`

``` cpp
constexpr two_dim_iterator() noexcept;
```

Default Constructor

Default constructor used default definition.

-----

### Constructor `cortex::two_dim_iterator::two_dim_iterator`

``` cpp
constexpr two_dim_iterator(const two_dim_iterator<_Iterator>& __other) noexcept;
```

Copy Constructor

-----

### Constructor `cortex::two_dim_iterator::two_dim_iterator`

``` cpp
constexpr two_dim_iterator('hidden' const& ptr, 'hidden' ridx, 'hidden' cidx, 'hidden' rows, 'hidden' columns) noexcept;
```

Explicit Value Constructor

Constructs the iterator by copying and instance of the underlying iterator and the given position of the iterator and dimensions in which it occupies and can move.

#### Parameters

  - `ptr` - type: iterator\_type | qualifiers: \[const, ref\]
  - `ridx` - type: size\_type
  - `cidx` - type: size\_type
  - `rows` - type: size\_type
  - `columns` - type: size\_type

-----

### Function `cortex::two_dim_iterator::operator=`

``` cpp
constexpr two_dim_iterator<_Iterator>& operator=(const two_dim_iterator<_Iterator>& __other) noexcept;
```

Copy Assignment

*Return values:* constexpr two\_dim\_iterator&

#### Parameters

  - `__other` - type: two\_dim\_iterator | qualifiers: \[const, ref\]

-----

### Function `cortex::two_dim_iterator::operator*`

``` cpp
constexpr 'hidden' operator*() noexcept;
```

Deference Operator

*Return values:* reference

Dereferences the underlying iterator.

-----

### Function `cortex::two_dim_iterator::operator*`

``` cpp
constexpr 'hidden' operator*() const noexcept;
```

Deference Operator

*Return values:* constexpr reference

Dereferences the underlying iterator and returns a constant value.

-----

### Function `cortex::two_dim_iterator::operator->`

``` cpp
constexpr 'hidden' operator->() noexcept;
```

Indirection Operator

*Requires:* The underlying iterator must be a pointer type or support the indirectin operator itself.

*Return values:* constexpr pointer

Returns a pointer to the underlying iterator.

-----

### Function `cortex::two_dim_iterator::operator->`

``` cpp
constexpr 'hidden' operator->() const noexcept;
```

Indirection Operator

*Requires:* The underlying iterator must be a pointer type or support the indirectin operator itself.

*Return values:* constexpr pointer

Returns a pointer to the underlying iterator and returns a constant value.

-----

### Function `cortex::two_dim_iterator::base`

``` cpp
constexpr 'hidden'& base() const noexcept;
```

Base Iterator

*Return values:* constexpr const iterator\_type&

Returns the underlying iterator.

-----

### Function `cortex::two_dim_iterator::rows`

``` cpp
constexpr 'hidden' rows() const noexcept;
```

Occupied Rows

*Return values:* constexpr size\_type

Returns the number of rows the iterator moves through.

-----

### Function `cortex::two_dim_iterator::columns`

``` cpp
constexpr 'hidden' columns() const noexcept;
```

Occupied Columns

*Return values:* constexpr size\_type

Returns the number of columns the iterator moves through.

-----

### Function `cortex::two_dim_iterator::row_index`

``` cpp
constexpr 'hidden' row_index() const noexcept;
```

Row Index

*Return values:* constexpr size\_type

Returns the current row index of the iterator.

-----

### Function `cortex::two_dim_iterator::column_index`

``` cpp
constexpr 'hidden' column_index() const noexcept;
```

Column Index

*Return values:* constexpr size\_type

Returns the current column index of the iterator.

-----

-----

### Function `cortex::operator==`

``` cpp
template <typename _IteratorL, typename _IteratorR>
constexpr bool operator==(two_dim_iterator<_IteratorL> const& __lhs, two_dim_iterator<_IteratorR> const& __rhs) noexcept(noexcept(__lhs.base() == __rhs.base()));
```

Equality Operator Overload.

*Requires:* That the underlying \_Iterator types are equality comparable. \\code {.cpp} { \_\_lhsI == \_\_rhsI } -\> bool \\endcode

*Notes:* \_IteratorL can equal \_IteratorR.

*Return values:* constexpr true

*Return values:* constexpr false

Performs an equality comparison of two %two\_dim\_iterator’s whose \_Iterator types can be different but of they share the same \_Container type.

\\exception Ensures that \_\_lhs.base() == \_\_rhs.base() is noexcept.

\[constexpr\] \[noexcept.noexcept-clause\]

-----

### Function `cortex::operator<=>`

``` cpp
template <typename _IteratorL, typename _IteratorR>
constexpr auto operator<=>(two_dim_iterator<_IteratorL> const& __lhs, two_dim_iterator<_IteratorR> const& __rhs) noexcept(noexcept(__lhs.base()<=>__rhs.base()));
```

Spaceship Operator Overload.

*Notes:* \_IteratorL can equal \_IteratorR.

*Return values:* constexpr auto of \[std::strong\_ordering\] : \[std::weak\_ordering\] : \[std::partial\_ordering\]

Performs a 3-way comparison of two %two\_dim\_iterator’s whose \_Iterator types can be different but of they share the same \_Container type.

\\exception \\code {.cpp} code noexcept (noexcept(\_\_lhs.base() \<=\> \_\_rhs.base())) \\endcode Ensures that the 3-way comparison of \_\_lhs.base() and \_\_rhs.base() is noexcept.

\[constexpr\] \[noexcept.noexcept-clause\]

-----
