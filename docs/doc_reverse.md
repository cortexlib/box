# Header file `reverse.hpp`

``` cpp
#define CORTEX_REVERSE_ITERATOR_HPP

namespace cortex
{
    template <typename _Iterator>
    class reverse_iterator;
}
```

An iterator for iterating through a container in reverse order.

Author: Tyler Swann (oraqlle@github.com)

Header Version: v1.0.0

Date: 25-06-2022

License: MIT

Copyright: Copyright (c) 2022

reverse.hpp

### Class `cortex::reverse_iterator`

``` cpp
template <typename _Iterator>
class reverse_iterator
{
public:
    constexpr reverse_iterator() noexcept;

    constexpr reverse_iterator(const reverse_iterator<_Iterator>& __other) noexcept;

    constexpr reverse_iterator<_Iterator>& operator++() noexcept;

    constexpr reverse_iterator<_Iterator>& operator--() noexcept;

    constexpr reverse_iterator<_Iterator>& operator+=('hidden' __step) noexcept;

    constexpr reverse_iterator<_Iterator>& operator-=('hidden' __step) noexcept;

    constexpr reverse_iterator<_Iterator> operator+('hidden' __step) const noexcept;

    constexpr reverse_iterator<_Iterator> operator-('hidden' __step) const noexcept;
};
```

Reverse Iterator

This iterator applies the inverse operation to an underlying iterator of type \_Iterator, thus allowing for reversed traversel through a container.

### Constructor `cortex::reverse_iterator::reverse_iterator`

``` cpp
constexpr reverse_iterator() noexcept;
```

Default Constructor

Initialises m\_current to the default value of the type \_Iterator.

\[constexpr\] \[noexcept\]

-----

### Constructor `cortex::reverse_iterator::reverse_iterator`

``` cpp
constexpr reverse_iterator(const reverse_iterator<_Iterator>& __other) noexcept;
```

Copy Constructor.

Uses copy semantics to initialise m\_current from another %reverse\_iterator object. Uses the \\code {.cpp} %reverse\_iterator::base() \\endcode method to access \_\_other’s underlying iterator.

\[constexpr\] \[noexcept\]

#### Parameters

  - `__other` - const reference to a %reverse\_iterator object.

-----

### Function `cortex::reverse_iterator::operator++`

``` cpp
constexpr reverse_iterator<_Iterator>& operator++() noexcept;
```

Prefix Increment Operator Overload.

*Return values:* constexpr reverse\_iterator&

Applies the prefix decrement operator to m\_current and returns a reference to this.

\[constexpr\] \[noexcept\]

-----

### Function `cortex::reverse_iterator::operator--`

``` cpp
constexpr reverse_iterator<_Iterator>& operator--() noexcept;
```

Prefix Decrement Operator Overload.

*Return values:* constexpr reverse\_iterator&

Applies the prefix increment operator to m\_current and returns a reference to this.

\[constexpr\] \[noexcept\]

-----

### Function `cortex::reverse_iterator::operator+=`

``` cpp
constexpr reverse_iterator<_Iterator>& operator+=('hidden' __step) noexcept;
```

Additive Assignment Operator Overload.

*Return values:* constexpr reverse\_iterator&

Decreases the m\_current’s pointer value by \_\_step and assigns m\_current the new pointer value and returns a reference to this.

\[constexpr\] \[noexcept\]

-----

### Function `cortex::reverse_iterator::operator-=`

``` cpp
constexpr reverse_iterator<_Iterator>& operator-=('hidden' __step) noexcept;
```

Subtraction Assignment Operator Overload.

*Return values:* constexpr reverse\_iterator&

Increases the m\_current’s pointer value by \_\_step and assigns m\_current the new pointer value and returns a reference to this.

\[constexpr\] \[noexcept\]

-----

### Function `cortex::reverse_iterator::operator+`

``` cpp
constexpr reverse_iterator<_Iterator> operator+('hidden' __step) const noexcept;
```

Addition Operator Overload.

*Return values:* constexpr reverse\_iterator

Constructs a new iterator from the substitution of m\_current and \_\_step.

\[constexpr\] \[noexcept\]

-----

### Function `cortex::reverse_iterator::operator-`

``` cpp
constexpr reverse_iterator<_Iterator> operator-('hidden' __step) const noexcept;
```

Subtraction Operator Overload.

*Return values:* constexpr reverse\_iterator

Constructs a new iterator from the addition of m\_current and \_\_step.

\[constexpr\] \[noexcept\]

-----

-----
