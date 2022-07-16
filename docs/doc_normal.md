# Header file `normal.hpp`

``` cpp
#define CORTEX_NORMAL_ITERATOR_HPP

namespace cortex
{
    template <typename _Iterator, typename _Container>
    class normal_iterator;
}
```

Adapts a non-object iterator to an object iterator without changing its semantics.

Author: Tyler Swann (oraqlle@github.com)

Header Version: v1.1.0

Date: 25-06-2022

License: MIT

Copyright: Copyright (c) 2022

normal.hpp

### Class `cortex::normal_iterator`

``` cpp
template <typename _Iterator, typename _Container>
class normal_iterator
{
public:
    constexpr normal_iterator() noexcept;

    constexpr normal_iterator(const normal_iterator<_Iterator, _Container>& __other) noexcept;

    constexpr normal_iterator('hidden' const& __other) noexcept;

    constexpr normal_iterator<_Iterator, _Container>& operator=(const normal_iterator<_Iterator, _Container>& __other) noexcept;

    constexpr normal_iterator<_Iterator, _Container>& operator=('hidden' const& __other) noexcept;

    constexpr 'hidden' operator*() noexcept;

    constexpr 'hidden' operator*() const noexcept;

    constexpr 'hidden' operator->() noexcept;

    constexpr 'hidden' operator->() const noexcept;

    constexpr normal_iterator<_Iterator, _Container>& operator++() noexcept;

    constexpr normal_iterator<_Iterator, _Container> operator++(int) noexcept;

    constexpr normal_iterator<_Iterator, _Container>& operator--() noexcept;

    constexpr normal_iterator<_Iterator, _Container> operator--(int) noexcept;

    constexpr 'hidden' operator[]('hidden' __n) noexcept;

    constexpr normal_iterator<_Iterator, _Container>& operator+=('hidden' __step) noexcept;

    constexpr normal_iterator<_Iterator, _Container>& operator-=('hidden' __step) noexcept;

    constexpr normal_iterator<_Iterator, _Container> operator+('hidden' __step) const noexcept;

    constexpr normal_iterator<_Iterator, _Container> operator-('hidden' __step) const noexcept;
};
```

Normal Iterator

This iterator is used to adapt non-iterator objects into objects (ie. pointers). %normal\_iterator does not change the semantics of the operators of the underlying iterator of type \_Iterator.

#### Template parameters

  - `_Iterator` - The underlying type of the iterator.
  - `_Container` - Allows classes to create different types of iterators even if the \_Iterator type is the same.

### Constructor `cortex::normal_iterator::normal_iterator`

``` cpp
constexpr normal_iterator() noexcept;
```

Default Constructor

Initialises m\_current to the default value of the type \_Iterator.

\[constexpr\] \[noexcept\]

-----

### Constructor `cortex::normal_iterator::normal_iterator`

``` cpp
constexpr normal_iterator(const normal_iterator<_Iterator, _Container>& __other) noexcept;
```

Copy Constructor.

Uses copy semantics to initialise m\_current from another %normal\_iterator object. Uses the \\code {.cpp} %normal\_iterator::base() \\endcode method to access \_\_other’s underlying iterator.

\[constexpr\] \[noexcept\]

#### Parameters

  - `__other` - const reference to a %normal\_iterator object.

-----

### Constructor `cortex::normal_iterator::normal_iterator`

``` cpp
constexpr normal_iterator('hidden' const& __other) noexcept;
```

Copy Constructor.

Uses copy semantics to initialise m\_current from an object as the same type as iterator\_type. Because the the underlying types must be the same, m\_current can be directly initialised from \_\_other.

\[constexpr\] \[noexcept\]

#### Parameters

  - `__other` - const reference to an object of type iterator\_type.

-----

### Function `cortex::normal_iterator::operator=`

``` cpp
constexpr normal_iterator<_Iterator, _Container>& operator=(const normal_iterator<_Iterator, _Container>& __other) noexcept;
```

Copy Assignment.

*Return values:* constexpr normal\_iterator&

Uses copy semantics to assign m\_current to the underlying iterator of \_\_other. Uses the \\code {.cpp} %normal\_iterator::base() \\endcode method to access \_\_other’s underlying iterator. Returns a reference to this.

\[constexpr\] \[noexcept\] \[operator.assigment\]

-----

### Function `cortex::normal_iterator::operator=`

``` cpp
constexpr normal_iterator<_Iterator, _Container>& operator=('hidden' const& __other) noexcept;
```

Copy Assignment.

*Return values:* constexpr normal\_iterator&

Uses copy semantics to assign m\_current to \_\_other. \_\_other must be of type iterator\_type. Returns a reference to this.

\[constexpr\] \[noexcept\] \[operator.assigment\]

-----

### Function `cortex::normal_iterator::operator*`

``` cpp
constexpr 'hidden' operator*() noexcept;
```

Dereference Operator Overload.

*Return values:* constexpr reference (T&)

Dereferences m\_current and returns a reference of the value to the caller.

\[constexpr\] \[noexcept\]

-----

### Function `cortex::normal_iterator::operator*`

``` cpp
constexpr 'hidden' operator*() const noexcept;
```

Dereference Operator Overload.

*Return values:* constexpr reference (T&)

Dereferences m\_current and returns a reference of the value to the caller.

\[constexpr\] \[noexcept\] \[trailing.const\]

-----

### Function `cortex::normal_iterator::operator->`

``` cpp
constexpr 'hidden' operator->() noexcept;
```

Arrow Deference Operator Overload.

*Return values:* constexpr pointer (T\*)

Returns a pointer of m\_current, this allows for access to the internal members if m\_current is a class or object type throught “indirection chaining”.

\[constexpr\] \[noexcept\]

-----

### Function `cortex::normal_iterator::operator->`

``` cpp
constexpr 'hidden' operator->() const noexcept;
```

Arrow Deference Operator Overload.

*Return values:* constexpr pointer (T\*)

Returns a pointer of m\_current, this allows for access to the internal members if m\_current is a class or object type throught “indirection chaining”.

\[constexpr\] \[noexcept\] \[trailing.const\]

-----

### Function `cortex::normal_iterator::operator++`

``` cpp
constexpr normal_iterator<_Iterator, _Container>& operator++() noexcept;
```

Prefix Increment Operator Overload.

*Return values:* constexpr normal\_iterator&

Applies the prefix increment operator to m\_current and returns a reference to this.

\[constexpr\] \[noexcept\]

-----

### Function `cortex::normal_iterator::operator++`

``` cpp
constexpr normal_iterator<_Iterator, _Container> operator++(int) noexcept;
```

Postfix Increment Operator Overload.

*Return values:* constexpr normal\_iterator

Constructs a new iterator from m\_current while applying the postifix increment operator on Construction. This effectively increments m\_current for this while creating a new iterator with its m\_current equal to the last value of this m\_current.

\[constexpr\] \[noexcept\]

-----

### Function `cortex::normal_iterator::operator--`

``` cpp
constexpr normal_iterator<_Iterator, _Container>& operator--() noexcept;
```

Prefix Decrement Operator Overload.

*Return values:* constexpr normal\_iterator&

Applies the prefix decrement operator to m\_current and returns a reference to this.

\[constexpr\] \[noexcept\]

-----

### Function `cortex::normal_iterator::operator--`

``` cpp
constexpr normal_iterator<_Iterator, _Container> operator--(int) noexcept;
```

Postfix Decrement Operator Overload.

*Return values:* constexpr normal\_iterator

Constructs a new iterator from m\_current while applying the postifix decrement operator on construction. This effectively decrements m\_current for this while creating a new iterator with its m\_current equal to the last value of this m\_current.

\[constexpr\] \[noexcept\]

-----

### Function `cortex::normal_iterator::operator[]`

``` cpp
constexpr 'hidden' operator[]('hidden' __n) noexcept;
```

Subscript Operator Overload.

*Return values:* constexpr reference (T&)

Accesses the element at an offset to m\_current’s location in memory and returns a reference to the value stored at that location.

\[constexpr\] \[noexcept\] \!\[range.validation\]

-----

### Function `cortex::normal_iterator::operator+=`

``` cpp
constexpr normal_iterator<_Iterator, _Container>& operator+=('hidden' __step) noexcept;
```

Additive Assignment Operator Overload.

*Return values:* constexpr normal\_iterator&

Increases the m\_current’s pointer value by \_\_step and assigns m\_current the new pointer value and returns a reference to this.

\[constexpr\] \[noexcept\]

-----

### Function `cortex::normal_iterator::operator-=`

``` cpp
constexpr normal_iterator<_Iterator, _Container>& operator-=('hidden' __step) noexcept;
```

Subtraction Assignment Operator Overload.

*Return values:* constexpr normal\_iterator&

Decreases the m\_current’s pointer value by \_\_step and assigns m\_current the new pointer value and returns a reference to this.

\[constexpr\] \[noexcept\]

-----

### Function `cortex::normal_iterator::operator+`

``` cpp
constexpr normal_iterator<_Iterator, _Container> operator+('hidden' __step) const noexcept;
```

Addition Operator Overload.

*Return values:* constexpr normal\_iterator

Constructs a new iterator from the addition of m\_current and \_\_step.

\[constexpr\] \[noexcept\]

-----

### Function `cortex::normal_iterator::operator-`

``` cpp
constexpr normal_iterator<_Iterator, _Container> operator-('hidden' __step) const noexcept;
```

Subtraction Operator Overload.

*Return values:* constexpr normal\_iterator

Constructs a new iterator from the subtraction of m\_current and \_\_step.

\[constexpr\] \[noexcept\]

-----

-----
