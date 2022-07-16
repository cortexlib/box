# Header file `box.hpp`

``` cpp
#include <concepts.hpp>

#include <iterators/column.hpp>

#include <iterators/normal.hpp>

#include <iterators/row.hpp>

#define CORTEX_BOX_H

#define lexicographical_compare_bug

namespace cortex
{
    //=== Box ===//
    template <typename T, typename Alloc = std::allocator<T>>>
    class box;
    template <typename _ElemL, typename _ElemR>
    bool operator==(box<_ElemL> const& lhs, box<_ElemR> const& rhs);
    template <typename _ElemL, typename _ElemR>
    bool operator!=(box<_ElemL> const& lhs, box<_ElemR> const& rhs);
    template <typename _ElemL, typename _ElemR>
    bool operator<(box<_ElemL> const& lhs, box<_ElemR> const& rhs);
    template <typename _ElemL, typename _ElemR>
    bool operator>(box<_ElemL> const& lhs, box<_ElemR> const& rhs);
    template <typename _ElemL, typename _ElemR>
    bool operator<=(box<_ElemL> const& lhs, box<_ElemR> const& rhs);
    template <typename _ElemL, typename _ElemR>
    bool operator>=(box<_ElemL> const& lhs, box<_ElemR> const& rhs);
    template <typename _ElemT>
    box<bool> operator==(box<_ElemT> const& bx, _ElemT const& scalar);
    template <typename _ElemT>
    box<bool> operator!=(box<_ElemT> const& bx, _ElemT const& scalar);
    template <typename _ElemT>
    box<bool> operator<(box<_ElemT> const& bx, _ElemT const& scalar);
    template <typename _ElemT>
    box<bool> operator>(box<_ElemT> const& bx, _ElemT const& scalar);
    template <typename _ElemT>
    box<bool> operator<=(box<_ElemT> const& bx, _ElemT const& scalar);
    template <typename _ElemT>
    box<bool> operator>=(box<_ElemT> const& bx, _ElemT const& scalar);
}

namespace std
{
    template <typename T>
    void swap(cortex::box<T>& x, cortex::box<T>& y) noexcept;
}
```

Two Dimensional Access To Contiguous Data.

Author: Tyler Swann (oraqlle@github.com)

Header Version: v2.3.3

Date: 25-06-2022

License: MIT

Copyright: Copyright (c) 2022

box.hpp

### Box

``` cpp
(1) template <typename T, typename Alloc = std::allocator<T>>>
class box
{
public:
    constexpr box() noexcept;

    constexpr box('hidden' const& alloc) noexcept;

    constexpr box('hidden' rows, 'hidden' cols, 'hidden' const& alloc = allocator_type());

    constexpr box('hidden' rows, 'hidden' cols, 'hidden' value, 'hidden' const& alloc = allocator_type());

    constexpr box(const box<T, Alloc>& other);

    constexpr box(const box<T, Alloc>& other, 'hidden' const& alloc);

    constexpr box(box<T, Alloc>&& other) noexcept;

    constexpr box(box<T, Alloc>&& other, 'hidden' const& alloc) noexcept;

    constexpr box(std::initializer_list<std::initializer_list<value_type>> list, 'hidden' const& alloc = allocator_type());

    constexpr box<T, Alloc>& operator=(const box<T, Alloc>& other);

    constexpr box<T, Alloc>& operator=(box<T, Alloc>&& other) noexcept;

    constexpr box<T, Alloc>& operator=(std::initializer_list<std::initializer_list<value_type>> list);

    constexpr void assign(std::initializer_list<std::initializer_list<value_type>> list);

    constexpr void resize('hidden' new_rows, 'hidden' new_columns);

    constexpr void resize('hidden' new_rows, 'hidden' new_columns, 'hidden' value);

    constexpr 'hidden' erase('hidden' position);

    constexpr 'hidden' erase('hidden' first, 'hidden' last);

    constexpr void clear();

    constexpr void reshape('hidden' new_rows, 'hidden' new_columns);

    void swap(box<T, Alloc>& other) noexcept;

    constexpr 'hidden' get_allocator() const noexcept;

    constexpr 'hidden' size() const noexcept;

    constexpr 'hidden' rows() const noexcept;

    constexpr 'hidden' columns() const noexcept;

    constexpr 'hidden' max_size() const noexcept;

    constexpr auto dimensions() const noexcept;

    constexpr bool is_square() const noexcept;

    constexpr bool empty() const noexcept;

    'hidden' data() noexcept;

    'hidden' data() const noexcept;

    constexpr std::span<value_type> slice('hidden' ridx) const;

    constexpr std::span<value_type> operator[]('hidden' ridx);

    constexpr 'hidden' at('hidden' row, 'hidden' column);

    constexpr 'hidden' at('hidden' row, 'hidden' column) const;

    constexpr 'hidden' operator()('hidden' row, 'hidden' column);

    constexpr 'hidden' operator()('hidden' row, 'hidden' column) const;

    constexpr 'hidden' front() noexcept;

    constexpr 'hidden' front() const noexcept;

    constexpr 'hidden' back() noexcept;

    constexpr 'hidden' back() const noexcept;

    constexpr std::vector<value_type> flatten() const noexcept;

    constexpr 'hidden' begin() noexcept;

    constexpr 'hidden' begin() const noexcept;

    constexpr 'hidden' cbegin() const noexcept;

    constexpr 'hidden' rbegin() noexcept;

    constexpr 'hidden' rbegin() const noexcept;

    constexpr 'hidden' crbegin() const noexcept;

    constexpr 'hidden' end() noexcept;

    constexpr 'hidden' end() const noexcept;

    constexpr 'hidden' cend() const noexcept;

    constexpr 'hidden' rend() noexcept;

    constexpr 'hidden' rend() const noexcept;

    constexpr 'hidden' crend() const noexcept;

    constexpr 'hidden' row_begin('hidden' row = 0uL);

    constexpr 'hidden' row_begin('hidden' row = 0uL) const;

    constexpr 'hidden' row_cbegin('hidden' row = 0uL) const;

    constexpr 'hidden' row_rbegin('hidden' row = 0uL);

    constexpr 'hidden' row_rbegin('hidden' row = 0uL) const;

    constexpr 'hidden' row_crbegin('hidden' row = 0uL) const;

    constexpr 'hidden' row_end('hidden' row = 0uL);

    constexpr 'hidden' row_end('hidden' row = 0uL) const;

    constexpr 'hidden' row_cend('hidden' row = 0uL) const;

    constexpr 'hidden' row_rend('hidden' row = 0uL);

    constexpr 'hidden' row_rend('hidden' row = 0uL) const;

    constexpr 'hidden' row_crend('hidden' row = 0uL) const;

    constexpr 'hidden' column_begin('hidden' column = 0uL);

    constexpr 'hidden' column_begin('hidden' column = 0uL) const;

    constexpr 'hidden' column_cbegin('hidden' column = 0uL) const;

    constexpr 'hidden' column_rbegin('hidden' column = 0uL);

    constexpr 'hidden' column_rbegin('hidden' column = 0uL) const;

    constexpr 'hidden' column_crbegin('hidden' column = 0uL) const;

    constexpr 'hidden' column_end('hidden' column = 0uL);

    constexpr 'hidden' column_end('hidden' column = 0uL) const;

    constexpr 'hidden' column_cend('hidden' column = 0uL) const;

    constexpr 'hidden' column_rend('hidden' column = 0uL);

    constexpr 'hidden' column_rend('hidden' column = 0uL) const;

    constexpr 'hidden' column_crend('hidden' column = 0uL) const;

    constexpr auto bit_not() const;

    constexpr auto transpose();

    constexpr auto vflip() const;

    constexpr auto hflip() const;

    constexpr auto rrotate() const;

    constexpr auto lrotate() const;
};

(2) template <typename _ElemL, typename _ElemR>
bool operator==(box<_ElemL> const& lhs, box<_ElemR> const& rhs);

(3) template <typename _ElemL, typename _ElemR>
bool operator!=(box<_ElemL> const& lhs, box<_ElemR> const& rhs);

(4) template <typename _ElemL, typename _ElemR>
bool operator<(box<_ElemL> const& lhs, box<_ElemR> const& rhs);

(5) template <typename _ElemL, typename _ElemR>
bool operator>(box<_ElemL> const& lhs, box<_ElemR> const& rhs);

(6) template <typename _ElemL, typename _ElemR>
bool operator<=(box<_ElemL> const& lhs, box<_ElemR> const& rhs);

(7) template <typename _ElemL, typename _ElemR>
bool operator>=(box<_ElemL> const& lhs, box<_ElemR> const& rhs);

(8) template <typename _ElemT>
box<bool> operator==(box<_ElemT> const& bx, _ElemT const& scalar);

(9) template <typename _ElemT>
box<bool> operator!=(box<_ElemT> const& bx, _ElemT const& scalar);

(10) template <typename _ElemT>
box<bool> operator<(box<_ElemT> const& bx, _ElemT const& scalar);

(11) template <typename _ElemT>
box<bool> operator>(box<_ElemT> const& bx, _ElemT const& scalar);

(12) template <typename _ElemT>
box<bool> operator<=(box<_ElemT> const& bx, _ElemT const& scalar);

(13) template <typename _ElemT>
box<bool> operator>=(box<_ElemT> const& bx, _ElemT const& scalar);
```

Box - Two Dimensional Array

Box is a two dimensional generic container. It aims to support expressive methods and operations that allow unique manipulation an structural access to data. Elements are stored continguously in memory and are layed out in a row-wise fashion.

#### Template parameters

  - `T` - concept: Any
  - `Alloc` - default: std::allocator\<T\>

### Constructor `cortex::box::box`

``` cpp
constexpr box() noexcept;
```

Default Constructor

Default constructor for box.

-----

### Constructor `cortex::box::box`

``` cpp
constexpr box('hidden' const& alloc) noexcept;
```

Allocator Constructor

Default Constructs a box with a given allocator.

#### Parameters

  - `alloc` - type: allocator\_type | qualifiers: \[const, ref\]

-----

### Constructor `cortex::box::box`

``` cpp
constexpr box('hidden' rows, 'hidden' cols, 'hidden' const& alloc = allocator_type());
```

Size Constructor

Constructs a box with dimensions of rows x columns. Values are default constructed or fill constructed depending on the default constructiblity qualification.

#### Parameters

  - `rows` - type: size\_type
  - `cols` - type: size\_type
  - `alloc` - type: allocator\_type | qualifiers: \[const, ref\]

-----

### Constructor `cortex::box::box`

``` cpp
constexpr box('hidden' rows, 'hidden' cols, 'hidden' value, 'hidden' const& alloc = allocator_type());
```

Size + Value Constructor

Constructs a box with dimensions of rows x columns. Values are constructed from the a constant reference to a provided value.

#### Parameters

  - `rows` - type: size\_type
  - `cols` - type: size\_type
  - `value` - type: value\_type | qualifiers: \[const, ref\]
  - `alloc` - type: allocator\_type | qualifiers: \[const, ref\]

-----

### Constructor `cortex::box::box`

``` cpp
constexpr box(const box<T, Alloc>& other);
```

Copy Constructor

Constructs a box that is a copy of another box of the same underlying type.

#### Parameters

  - `other` - type: \[box\] | qualifiers: \[const, ref\]

-----

### Constructor `cortex::box::box`

``` cpp
constexpr box(const box<T, Alloc>& other, 'hidden' const& alloc);
```

Copy Constructor with Alternative Allocator

Constructs a box that is a copy of another box of the same underlying type.

#### Parameters

  - `other` - type: \[box\] | qualifiers: \[const, ref\]
  - `alloc` - type: allocator\_type | qualifiers: \[const, ref\]

-----

### Constructor `cortex::box::box`

``` cpp
constexpr box(box<T, Alloc>&& other) noexcept;
```

Move Constructor

Moves ownership of an existing box’s resources to this box and leaves the other box in a default constructed state.

#### Parameters

  - `other` - type: \[box\] | qualifiers: \[move\]

-----

### Constructor `cortex::box::box`

``` cpp
constexpr box(box<T, Alloc>&& other, 'hidden' const& alloc) noexcept;
```

Move Constructor with Alternative Allocator

Moves ownership of an existing box’s resources to this box and leaves the other box in a default constructed state. Uses an alternative allocator for construction of `this` box.

#### Parameters

  - `other` - type: \[box\] | qualifiers: \[move\]
  - `alloc` - type: allocator\_type | qualifiers: \[const, ref\]

-----

### Constructor `cortex::box::box`

``` cpp
constexpr box(std::initializer_list<std::initializer_list<value_type>> list, 'hidden' const& alloc = allocator_type());
```

Initialiser List Constructor

Uses std::initializer\_list to create a box from an initializer list of initializer lists. Elements ownership is moved to the box’s memory.

#### Parameters

  - `list` - type: \[std::initializer\_list\<std::initializer\_list\<value\_type\>\>\] | qualifiers: \[const, ref\]
  - `alloc` - type: allocator\_type | qualifiers: \[const, ref\] | attribute: \[\[maybe\_unused\]\]

-----

### Function `cortex::box::operator=`

``` cpp
constexpr box<T, Alloc>& operator=(const box<T, Alloc>& other);
```

Copy Assignment

*Return values:* constexpr box&

Copies the contents of another box into this box and returns///this. If self assignment occurs then///this is returned immediately.

#### Parameters

  - `other` - type: \[box\] | qualifiers: \[const, ref\]

-----

### Function `cortex::box::operator=`

``` cpp
constexpr box<T, Alloc>& operator=(box<T, Alloc>&& other) noexcept;
```

Move Assignment

*Return values:* constexpr box&

Moves the ownership of other’s resources to this box and leaves the other box in a default constructed state. Returns///this. If self assignment occurs then///this is returned immediately.

#### Parameters

  - `other` - type: \[box\] | qualifiers: \[move\]

-----

### Function `cortex::box::operator=`

``` cpp
constexpr box<T, Alloc>& operator=(std::initializer_list<std::initializer_list<value_type>> list);
```

Initialiser List Assignment

*Return values:* constexpr box&

Uses std::initializer\_list to create a box from an initializer list of initializer lists. Elements ownership is moved to the box’s memory.

#### Parameters

  - `list` - type: \[std::initializer\_list\<std::initializer\_list\<value\_type\>\>\]

-----

### Function `cortex::box::assign`

``` cpp
constexpr void assign(std::initializer_list<std::initializer_list<value_type>> list);
```

Intialiser List Assign

Uses std::initializer\_list to reassign values to a box. If the lists dimensions are not the same as the box’s dimensions, then the box is resized to match the dimensions of the list.

#### Parameters

  - `list` - type: \[std::initializer\_list\<std::initializer\_list\<value\_type\>\>\]

-----

### Function `cortex::box::resize`

``` cpp
constexpr void resize('hidden' new_rows, 'hidden' new_columns);
```

Resizes the box to dimensions new\_rows x new\_columns.

Resizes the box to dimensions new\_rows x new\_columns, the resize will result in a new memory block being allocated if the new dimensions are larger or smaller than the current dimensions. Reallocation or destruction of elements causes iterators and references to be invalidated. If new dimensions don’t change the overall size, only the view over the data (ie. the dimension sizes) are changed, elements of the box remain unchanged, however, this is unchecked. For a checked change that can only changes the dimension sizes, use box::reshape.

#### Parameters

  - `new_rows` - type: size\_type
  - `new_columns` - type: size\_type

-----

### Function `cortex::box::resize`

``` cpp
constexpr void resize('hidden' new_rows, 'hidden' new_columns, 'hidden' value);
```

Resizes the box to dimensions new\_rows x new\_columns with default value

Resizes the box to dimensions new\_rows x new\_columns, the resize will result in a new memory block being allocated if the new dimensions are larger or smaller than the current dimensions. Reallocation or destruction of elements causes iterators and references to be invalidated. The new box is initialised with value. If new dimensions don’t change the overall size, only the view over the data (ie. the dimension sizes) are changed, elements of the box remain unchanged, however, this is unchecked. For a checked change that can only changes the dimension sizes, use box::reshape.

#### Parameters

  - `new_rows` - type: size\_type
  - `new_columns` - type: size\_type
  - `value` - type: value\_type | qualifiers: \[const, ref\]

-----

### Function `cortex::box::erase`

``` cpp
constexpr 'hidden' erase('hidden' position);
```

Erases element indicated by position

*Return values:* constexpr iterator | attribute: \[\[maybe\_unused\]\]

Erases the value of the box at position and resets it to value\_type().

#### Parameters

  - `position` - type: \[const\_iterator\]

-----

### Function `cortex::box::erase`

``` cpp
constexpr 'hidden' erase('hidden' first, 'hidden' last);
```

Erases value between first and last

*Return values:* constexpr iterator | attribute: \[\[maybe\_unused\]\]

Elements between first and last and then resets memory to value\_type()

#### Parameters

  - `first` - type: \[const\_iterator\]
  - `last` - type: \[const\_iterator\]

-----

### Function `cortex::box::clear`

``` cpp
constexpr void clear();
```

Clears the box elements

The elements of the box are destroyed and the memory is deallocated entirely. The box is however, left in a state where it could be re-initialised or destructed which is up to user descretionbx. box::resize has to be used to allocate storage for the new elements.

-----

### Function `cortex::box::reshape`

``` cpp
constexpr void reshape('hidden' new_rows, 'hidden' new_columns);
```

Reshape current box elements to new dimensions

Reshapes the current box’s dimensisons while guranteeing that now reallocation occurs. Elements are preserved.

#### Parameters

  - `new_rows` - type: size\_type
  - `new_columns` - type: size\_type

-----

### Function `cortex::box::swap`

``` cpp
void swap(box<T, Alloc>& other) noexcept;
```

Swaps two matrices of the same type.

Swaps the contents of two matrices of which they are the same type. The swap is performed by moving ownership of the matrices resources.

#### Parameters

  - `other` - type: \[box\] | qualifiers: \[ref\]

-----

### Function `cortex::box::get_allocator`

``` cpp
constexpr 'hidden' get_allocator() const noexcept;
```

Get Allocator

*Return values:* constexpr allocator\_type

Returns the allocator used by the box.

-----

### Function `cortex::box::size`

``` cpp
constexpr 'hidden' size() const noexcept;
```

Box Size

*Return values:* constexpr size\_type

Returns the overall size of the box.

-----

### Function `cortex::box::rows`

``` cpp
constexpr 'hidden' rows() const noexcept;
```

Row Size

*Return values:* constexpr size\_type

Returns the number of the rows of the box.

-----

### Function `cortex::box::columns`

``` cpp
constexpr 'hidden' columns() const noexcept;
```

Column Size

*Return values:* constexpr size\_type

Returns the the number of columns in the box.

-----

### Function `cortex::box::max_size`

``` cpp
constexpr 'hidden' max_size() const noexcept;
```

Max Box Size

*Return values:* constexpr size\_type

Returns the maximum number of elements that can be stored in the box.

-----

### Function `cortex::box::dimensions`

``` cpp
constexpr auto dimensions() const noexcept;
```

Dimensions

*Return values:* constexpr auto

Returns a structured binding of the box’s dimensions.

-----

### Function `cortex::box::is_square`

``` cpp
constexpr bool is_square() const noexcept;
```

Is Square

*Return values:* true

*Return values:* false

If the number of rows and columns are equal, the box is square.

-----

### Function `cortex::box::empty`

``` cpp
constexpr bool empty() const noexcept;
```

Empty

*Return values:* true

*Return values:* false

Checks whether the box is empty.

-----

### Function `cortex::box::data`

``` cpp
'hidden' data() noexcept;
```

Data

*Return values:* pointer

Returns the underlying data pointer.

-----

### Function `cortex::box::data`

``` cpp
'hidden' data() const noexcept;
```

Data

*Return values:* const\_pointer

Returns the underlying data pointer.

-----

### Function `cortex::box::slice`

``` cpp
constexpr std::span<value_type> slice('hidden' ridx) const;
```

Slice

*Return values:* std::span\<value\_type\>

Returns a slice of the box. The slice is std::span over the indicated row of the box. The span is a view over the underlying data.

\\exception std::out\_of\_range - if the row index is out of range of the box, the exception is thrown.

#### Parameters

  - `ridx` - type: size\_type

-----

### Function `cortex::box::operator[]`

``` cpp
constexpr std::span<value_type> operator[]('hidden' ridx);
```

Slice Operator

*Return values:* std::span\<value\_type\>

Returns a slice of the box. The slice is std::span over the indicated row of the box. The span is a view over the underlying data. Calls `box::slice`.

-----

### Function `cortex::box::at`

``` cpp
constexpr 'hidden' at('hidden' row, 'hidden' column);
```

Two Dimensional Element Access (Point Access).

*Return values:* constexpr reference

Returns a reference to the element that is at the point position (column, row) of the box.

\\exception std::out\_of\_range

#### Parameters

  - `row` - type: size\_type
  - `column` - type: size\_type

-----

### Function `cortex::box::at`

``` cpp
constexpr 'hidden' at('hidden' row, 'hidden' column) const;
```

At

*Return values:* constexpr const\_reference

Returns a reference to the element that is at the point position (column, row) of the box.

\\exception std::out\_of\_range

#### Parameters

  - `row` - type: size\_type
  - `column` - type: size\_type

-----

### Function `cortex::box::operator()`

``` cpp
constexpr 'hidden' operator()('hidden' row, 'hidden' column);
```

Point Access Operator

*Return values:* constexpr reference

Provides point access to box’s elements. Overloads the invokation operator. Utilises the at() method.

\\exception std::out\_of\_range

#### Parameters

  - `row` - type: size\_type
  - `column` - type: size\_type

-----

### Function `cortex::box::operator()`

``` cpp
constexpr 'hidden' operator()('hidden' row, 'hidden' column) const;
```

Point Access Operator

*Return values:* constexpr const\_reference

Provides point access to box’s elements. Overloads the invokation operator. Utilises the at() method.

\\exception std::out\_of\_range

#### Parameters

  - `row` - type: size\_type
  - `column` - type: size\_type

-----

### Function `cortex::box::front`

``` cpp
constexpr 'hidden' front() noexcept;
```

Front

*Return values:* constexpr reference

Returns a reference to the front element of the box.

-----

### Function `cortex::box::front`

``` cpp
constexpr 'hidden' front() const noexcept;
```

Front

*Return values:* constexpr const\_reference

Returns a reference to the front element of the box.

-----

### Function `cortex::box::back`

``` cpp
constexpr 'hidden' back() noexcept;
```

Back

*Return values:* constexpr reference

Returns a reference to the back element of the box.

-----

### Function `cortex::box::back`

``` cpp
constexpr 'hidden' back() const noexcept;
```

Back

*Return values:* constexpr const\_reference

Returns a reference to the back element of the box.

-----

### Function `cortex::box::flatten`

``` cpp
constexpr std::vector<value_type> flatten() const noexcept;
```

Flatten

*Return values:* constexpr std::vector\<value\_type\>

Creates a std::vector of the box’s elements in row major order.

-----

### Function `cortex::box::begin`

``` cpp
constexpr 'hidden' begin() noexcept;
```

Begin Iterator

*Return values:* constexpr iterator

Iterator to the beginning of the box’s data.

-----

### Function `cortex::box::begin`

``` cpp
constexpr 'hidden' begin() const noexcept;
```

Begin Iterator (const)

*Return values:* constexpr const\_iterator

Constant iterator to the beginning of the box’s data.

-----

### Function `cortex::box::cbegin`

``` cpp
constexpr 'hidden' cbegin() const noexcept;
```

Constant Begin Iterator

*Return values:* constexpr const\_iterator

Constant iterator to the beginning of the box.

-----

### Function `cortex::box::rbegin`

``` cpp
constexpr 'hidden' rbegin() noexcept;
```

Reverse Begin Iterator

*Return values:* constexpr reverse\_iterator

Iterator to the reversed beginning of the box’s data.

-----

### Function `cortex::box::rbegin`

``` cpp
constexpr 'hidden' rbegin() const noexcept;
```

Reverse Begin Iterator (const)

*Return values:* constexpr const\_reverse\_iterator

Constant iterator to the reversed beginning of the box’s data.

-----

### Function `cortex::box::crbegin`

``` cpp
constexpr 'hidden' crbegin() const noexcept;
```

Constant Reverse Begin Iterator

*Return values:* constexpr const\_reverse\_iterator

Constant iterator to the reversed beginning of the box’s data.

-----

### Function `cortex::box::end`

``` cpp
constexpr 'hidden' end() noexcept;
```

End Iterator

*Return values:* constexpr iterator

Iterator to the end of the box’s data.

-----

### Function `cortex::box::end`

``` cpp
constexpr 'hidden' end() const noexcept;
```

End Iterator (const)

*Return values:* constexpr const\_iterator

Constant iterator to the end of the box’s data.

-----

### Function `cortex::box::cend`

``` cpp
constexpr 'hidden' cend() const noexcept;
```

Constant End Iterator

*Return values:* constexpr const\_iterator

Constant iterator to the end of the box’s data.

-----

### Function `cortex::box::rend`

``` cpp
constexpr 'hidden' rend() noexcept;
```

Reverse End Iterator

*Return values:* constexpr reverse\_iterator

Iterator to the reversed end of the box’s data.

-----

### Function `cortex::box::rend`

``` cpp
constexpr 'hidden' rend() const noexcept;
```

Reverse End Iterator (const)

*Return values:* constexpr const\_reverse\_iterator

Constant iterator to the reversed end of the box’s data.

-----

### Function `cortex::box::crend`

``` cpp
constexpr 'hidden' crend() const noexcept;
```

Constant Reverse End Iterator

*Return values:* constexpr const\_reverse\_iterator

Constant iterator to the reversed end of the box’s data.

-----

### Function `cortex::box::row_begin`

``` cpp
constexpr 'hidden' row_begin('hidden' row = 0uL);
```

Row Begin Iterator

*Return values:* constexpr row\_iterator

Returns an iterator to the beginning of the indicated row.

#### Parameters

  - `row` - type: size\_type | default: 0uL

-----

### Function `cortex::box::row_begin`

``` cpp
constexpr 'hidden' row_begin('hidden' row = 0uL) const;
```

Row Begin Iterator (const)

*Return values:* constexpr const\_row\_iterator

Returns an iterator to the beginning of the indicated row.

#### Parameters

  - `row` - type: size\_type | default: 0uL

-----

### Function `cortex::box::row_cbegin`

``` cpp
constexpr 'hidden' row_cbegin('hidden' row = 0uL) const;
```

Constant Row Begin Iterator

*Return values:* constexpr const\_row\_iterator

Returns a constant iterator to the beginning of the indicated row.

#### Parameters

  - `row` - type: size\_type | default: 0uL

-----

### Function `cortex::box::row_rbegin`

``` cpp
constexpr 'hidden' row_rbegin('hidden' row = 0uL);
```

Reverse Row Begin Iterator

*Return values:* constexpr reverse\_row\_iterator

Returns a reverse iterator to the beginning of the indicated reversed row.

#### Parameters

  - `row` - type: size\_type | default: 0uL

-----

### Function `cortex::box::row_rbegin`

``` cpp
constexpr 'hidden' row_rbegin('hidden' row = 0uL) const;
```

Reverse Row Begin Iterator (const)

*Return values:* constexpr const\_reverse\_row\_iterator

Returns a constant reverse iterator to the beginning of the indicated reversed row.

#### Parameters

  - `row` - type: size\_type | default: 0uL

-----

### Function `cortex::box::row_crbegin`

``` cpp
constexpr 'hidden' row_crbegin('hidden' row = 0uL) const;
```

Constant Reverse Row Begin Iterator

*Return values:* constexpr const\_reverse\_row\_iterator

Returns a constant reverse iterator to the beginning of the indicated reversed row.

-----

### Function `cortex::box::row_end`

``` cpp
constexpr 'hidden' row_end('hidden' row = 0uL);
```

Row End Iterator

*Return values:* constexpr row\_iterator

Returns an iterator to one past the end of the row, this happens to be the first element in the next row. This is why the iterator column index is set to 0 and the row index is one plus the indicated positon.

#### Parameters

  - `row` - type: size\_type | default: 0uL

-----

### Function `cortex::box::row_end`

``` cpp
constexpr 'hidden' row_end('hidden' row = 0uL) const;
```

Row End Iterator (const)

*Return values:* constexpr const\_row\_iterator

Returns an constant iterator to one past the end of the row, this happens to be the first element in the next row. This is why the iterator column index is set to 0 and the row index is one plus the indicated positon.

#### Parameters

  - `row` - type: size\_type | default: 0uL

-----

### Function `cortex::box::row_cend`

``` cpp
constexpr 'hidden' row_cend('hidden' row = 0uL) const;
```

Constant Row End Iterator

*Return values:* constexpr const\_row\_iterator

Returns an constant iterator to one past the end of the row, this happens to be the first element in the next row. This is why the iterator column index is set to 0 and the row index is one plus the indicated positon.

#### Parameters

  - `row` - type: size\_type | default: 0uL

-----

### Function `cortex::box::row_rend`

``` cpp
constexpr 'hidden' row_rend('hidden' row = 0uL);
```

Reverse Row End Iterator

*Return values:* constexpr reverse\_row\_iterator

Returns a reverse iterator to the end of the indicated reversed row.

-----

### Function `cortex::box::row_rend`

``` cpp
constexpr 'hidden' row_rend('hidden' row = 0uL) const;
```

Reverse Row End Iterator (const)

*Return values:* constexpr const\_reverse\_row\_iterator

Returns a constant reverse iterator to the end of the indicated reversed row.

-----

### Function `cortex::box::row_crend`

``` cpp
constexpr 'hidden' row_crend('hidden' row = 0uL) const;
```

Constant Reverse Row End Iterator

*Return values:* constexpr const\_reverse\_row\_iterator

Returns a constant reverse iterator to the end of the indicated reversed row.

-----

### Function `cortex::box::column_begin`

``` cpp
constexpr 'hidden' column_begin('hidden' column = 0uL);
```

Column Begin Iterator

*Return values:* constexpr column\_iterator

Returns an iterator to the beginning of the indicated column.

#### Parameters

  - `column` - type: size\_type | default: 0uL

-----

### Function `cortex::box::column_begin`

``` cpp
constexpr 'hidden' column_begin('hidden' column = 0uL) const;
```

Column Begin Iterator (const)

*Return values:* constexpr const\_column\_iterator

Returns a constant iterator to the beginning of the indicated column.

#### Parameters

  - `column` - type: size\_type | default: 0uL

-----

### Function `cortex::box::column_cbegin`

``` cpp
constexpr 'hidden' column_cbegin('hidden' column = 0uL) const;
```

Constant Column Begin Iterator

*Return values:* constexpr const\_column\_iterator

Returns a constant iterator to the beginning of the indicated column.

#### Parameters

  - `column` - type: size\_type | default: 0uL

-----

### Function `cortex::box::column_rbegin`

``` cpp
constexpr 'hidden' column_rbegin('hidden' column = 0uL);
```

Reverse Column Begin Iterator

*Return values:* constexpr reverse\_column\_iterator

Returns a reverse iterator to the beginning of the reversed column.

#### Parameters

  - `column` - type: size\_type | default: 0uL

-----

### Function `cortex::box::column_rbegin`

``` cpp
constexpr 'hidden' column_rbegin('hidden' column = 0uL) const;
```

Reverse Column Begin Iterator (const)

*Return values:* constexpr const\_reverse\_column\_iterator

Returns a constant reverse iterator to the beginning of the indicated reversed column.

#### Parameters

  - `column` - type: size\_type | default: 0uL

-----

### Function `cortex::box::column_crbegin`

``` cpp
constexpr 'hidden' column_crbegin('hidden' column = 0uL) const;
```

Constant Reverse Column Begin Iterator

*Return values:* constexpr const\_reverse\_column\_iterator

Returns a constant reverse iterator to the beginning of the indicated reversed column.

#### Parameters

  - `column` - type: size\_type | default: 0uL

-----

### Function `cortex::box::column_end`

``` cpp
constexpr 'hidden' column_end('hidden' column = 0uL);
```

Column End Iterator

*Return values:* constexpr column\_iterator

Returns an iterator to one past the end of the column, this happens to be the first element in the next column. This is why the iterator row index is set to 0 and the column index is one plus the indicated position.

#### Parameters

  - `column` - type: size\_type | default: 0uL

-----

### Function `cortex::box::column_end`

``` cpp
constexpr 'hidden' column_end('hidden' column = 0uL) const;
```

Column End Iterator (const)

*Return values:* constexpr const\_column\_iterator

Returns a constant iterator to one past the end of the column, this happens to be the first element in the next column. This is why the iterator row index is set to 0 and the column index is one plus the indicated position.

#### Parameters

  - `column` - type: size\_type | default: 0uL

-----

### Function `cortex::box::column_cend`

``` cpp
constexpr 'hidden' column_cend('hidden' column = 0uL) const;
```

Constant Column End Iterator

*Return values:* constexpr const\_column\_iterator

Returns a constant iterator to one past the end of the column, this happens to be the first element in the next column. This is why the iterator row index is set to 0 and the column index is one plus the indicated position.

#### Parameters

  - `column` - type: size\_type | default: 0uL

-----

### Function `cortex::box::column_rend`

``` cpp
constexpr 'hidden' column_rend('hidden' column = 0uL);
```

Reverse Column End Iterator

*Return values:* constexpr reverse\_column\_iterator

Returns a reverse iterator the end of the reversed column.

#### Parameters

  - `column` - type: size\_type | default: 0uL

-----

### Function `cortex::box::column_rend`

``` cpp
constexpr 'hidden' column_rend('hidden' column = 0uL) const;
```

Reverse Column End Iterator (const)

*Return values:* constexpr const\_reverse\_column\_iterator

Returns a constant reverse iterator the end of the reversed column.

#### Parameters

  - `column` - type: size\_type | default: 0uL

-----

### Function `cortex::box::column_crend`

``` cpp
constexpr 'hidden' column_crend('hidden' column = 0uL) const;
```

Constant Reverse Column End Iterator

*Return values:* constexpr const\_reverse\_column\_iterator

Returns a constant reverse iterator the end of the reversed column.

#### Parameters

  - `column` - type: size\_type | default: 0uL

-----

### Function `cortex::box::bit_not`

``` cpp
constexpr auto bit_not() const;
```

Element-wise Bitwise Not

*Requires:* BitNot\<value\_type\>

*Return values:* constexpr auto

Performs an element-wise bitwise not operation. The box must not be empty.

\\exception std::invalid\_argument If the box is empty, std::invalid\_argument is thrown.

-----

### Function `cortex::box::transpose`

``` cpp
constexpr auto transpose();
```

Matrix Transpose

*Return values:* constexpr auto

Performs a box transpose. Uses std::copy over std::ranges::copy as the output iterator is required to be std::constructible\_v which column\_iterator doesn’t satisfy yet.

-----

### Function `cortex::box::vflip`

``` cpp
constexpr auto vflip() const;
```

Vertical Flip

*Return values:* constexpr auto

Performs a vertical flip of the box. ie. The order of the rows is reversed. If `this` box is empty, an empty box is returned with no memory allocated to it.

-----

### Function `cortex::box::hflip`

``` cpp
constexpr auto hflip() const;
```

Horizontal Flip

*Return values:* constexpr auto

Performs a horizontal flip of the box. ie. The order of the columns is reversed. If `this` box is empty, an empty box is returned with no memory allocated to it.

-----

### Function `cortex::box::rrotate`

``` cpp
constexpr auto rrotate() const;
```

Right Rotate

*Return values:* constexpr auto

Rotates the box 90 degrees clockwise. Inverts the dimension sizes of the box. If `this` box is empty, an empty box is returned with no memory allocated to it.

-----

### Function `cortex::box::lrotate`

``` cpp
constexpr auto lrotate() const;
```

Left Rotate

*Return values:* constexpr auto

Rotates the box 90 degrees counter-clockwise. Inverts the dimension sizes of the box. If `this` box is empty, an empty box is returned with no memory allocated to it.

-----

-----

### Function `std::swap`

``` cpp
template <typename T>
void swap(cortex::box<T>& x, cortex::box<T>& y) noexcept;
```

Uses std::swap to swap the contents of two matrices.

*Return values:* inline void

Swaps the contents of two matrices if they are of the same type.

\\exception std::swap is noexcept if x.swap(y) is noexcept.

#### Parameters

  - `x` - type: \[cortex::box\<T\>\] | qualifiers: \[const, ref\]
  - `y` - type: \[cortex::box\<T\>\] | qualifiers: \[const, ref\]

-----
