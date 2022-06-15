# Header file `box.hpp`

``` cpp
#define CORTEX_BOX_H

#define lexicographical_compare_bug

namespace cortex
{
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

Two Dimensional Access To Contiguous Data

box \\author Tyler Swann (oraqlle@github.com) \\version 2.3.0 \\date 12-06-2022

\\copyright Copyright (c) 2022

### Class `cortex::box`

``` cpp
template <typename T, typename Alloc = std::allocator<T>>>
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

Copies the contents of another box into this box and returns///this. If self assignment occurs then///this is returned immediately.

#### Parameters

  - `other` - type: \[box\] | qualifiers: \[const, ref\] \\return constexpr box&

-----

### Function `cortex::box::operator=`

``` cpp
constexpr box<T, Alloc>& operator=(box<T, Alloc>&& other) noexcept;
```

Move Assignment

Moves the ownership of other’s resources to this box and leaves the other box in a default constructed state. Returns///this. If self assignment occurs then///this is returned immediately.

#### Parameters

  - `other` - type: \[box\] | qualifiers: \[move\] \\return constexpr box&

-----

### Function `cortex::box::operator=`

``` cpp
constexpr box<T, Alloc>& operator=(std::initializer_list<std::initializer_list<value_type>> list);
```

Initialiser List Assignment

Uses std::initializer\_list to create a box from an initializer list of initializer lists. Elements ownership is moved to the box’s memory.

#### Parameters

  - `list` - type: \[std::initializer\_list\<std::initializer\_list\<value\_type\>\>\] \\return constexpr box&

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

Erases the value of the box at position and resets it to value\_type().

#### Parameters

  - `position` - type: \[const\_iterator\] \\return constexpr iterator | attribute: \[\[maybe\_unused\]\]

-----

### Function `cortex::box::erase`

``` cpp
constexpr 'hidden' erase('hidden' first, 'hidden' last);
```

Erases value between first and last

Elements between first and last and then resets memory to value\_type()

#### Parameters

  - `first` - type: \[const\_iterator\]
  - `last` - type: \[const\_iterator\] \\return constexpr iterator | attribute: \[\[maybe\_unused\]\]

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

Returns the allocator used by the box.

\\return constexpr allocator\_type

-----

### Function `cortex::box::size`

``` cpp
constexpr 'hidden' size() const noexcept;
```

Box Size

Returns the overall size of the box.

\\return constexpr size\_type

-----

### Function `cortex::box::rows`

``` cpp
constexpr 'hidden' rows() const noexcept;
```

Row Size

Returns the number of the rows of the box.

\\return constexpr size\_type

-----

### Function `cortex::box::columns`

``` cpp
constexpr 'hidden' columns() const noexcept;
```

Column Size

Returns the the number of columns in the box.

\\return constexpr size\_type

-----

### Function `cortex::box::max_size`

``` cpp
constexpr 'hidden' max_size() const noexcept;
```

Max Box Size

Returns the maximum number of elements that can be stored in the box.

\\return constexpr size\_type

-----

### Function `cortex::box::dimensions`

``` cpp
constexpr auto dimensions() const noexcept;
```

Dimensions

Returns a structured binding of the box’s dimensions.

\\return constexpr auto

-----

### Function `cortex::box::is_square`

``` cpp
constexpr bool is_square() const noexcept;
```

Is Square

If the number of rows and columns are equal, the box is square.

\\return true \\return false

-----

### Function `cortex::box::empty`

``` cpp
constexpr bool empty() const noexcept;
```

Empty

Checks whether the box is empty.

\\return true \\return false

-----

### Function `cortex::box::data`

``` cpp
'hidden' data() noexcept;
```

Data

Returns the underlying data pointer.

\\return pointer

-----

### Function `cortex::box::data`

``` cpp
'hidden' data() const noexcept;
```

Data

Returns the underlying data pointer.

\\return const\_pointer

-----

### Function `cortex::box::slice`

``` cpp
constexpr std::span<value_type> slice('hidden' ridx) const;
```

Slice

Returns a slice of the box. The slice is std::span over the indicated row of the box. The span is a view over the underlying data.

\\exception std::out\_of\_range - if the row index is out of range of the box, the exception is thrown.

#### Parameters

  - `ridx` - type: size\_type \\return std::span\<value\_type\>

-----

### Function `cortex::box::operator[]`

``` cpp
constexpr std::span<value_type> operator[]('hidden' ridx);
```

@brief Slice Operator

@details Returns a slice of the box. The slice is std::span over the indicated row of the box. The span is a view over the underlying data. Calls `box::slice`.

@param ridx @return std::span\<value\_type\>

-----

### Function `cortex::box::at`

``` cpp
constexpr 'hidden' at('hidden' row, 'hidden' column);
```

@brief Two Dimensional Element Access (Point Access).

Returns a reference to the element that is at the point position (column, row) of the box.

\\exception std::out\_of\_range

#### Parameters

  - `row` - type: size\_type \\return constexpr reference
  - `column` - type: size\_type

-----

### Function `cortex::box::at`

``` cpp
constexpr 'hidden' at('hidden' row, 'hidden' column) const;
```

At

Returns a reference to the element that is at the point position (column, row) of the box.

\\exception std::out\_of\_range

#### Parameters

  - `row` - type: size\_type \\return constexpr const\_reference
  - `column` - type: size\_type

-----

### Function `cortex::box::operator()`

``` cpp
constexpr 'hidden' operator()('hidden' row, 'hidden' column);
```

Point Access Operator

Provides point access to box’s elements. Overloads the invokation operator. Utilises the at() method.

\\exception std::out\_of\_range

#### Parameters

  - `row` - type: size\_type \\return constexpr reference
  - `column` - type: size\_type

-----

### Function `cortex::box::operator()`

``` cpp
constexpr 'hidden' operator()('hidden' row, 'hidden' column) const;
```

Point Access Operator

Provides point access to box’s elements. Overloads the invokation operator. Utilises the at() method.

\\exception std::out\_of\_range

#### Parameters

  - `row` - type: size\_type \\return constexpr const\_reference
  - `column` - type: size\_type

-----

### Function `cortex::box::front`

``` cpp
constexpr 'hidden' front() noexcept;
```

Front

Returns a reference to the front element of the box.

\\return constexpr reference

-----

### Function `cortex::box::front`

``` cpp
constexpr 'hidden' front() const noexcept;
```

Front

Returns a reference to the front element of the box.

\\return constexpr const\_reference

-----

### Function `cortex::box::back`

``` cpp
constexpr 'hidden' back() noexcept;
```

Back

Returns a reference to the back element of the box.

\\return constexpr reference

-----

### Function `cortex::box::back`

``` cpp
constexpr 'hidden' back() const noexcept;
```

Back

Returns a reference to the back element of the box.

\\return constexpr const\_reference

-----

### Function `cortex::box::flatten`

``` cpp
constexpr std::vector<value_type> flatten() const noexcept;
```

Flatten

Creates a std::vector of the box’s elements in row major order.

\\return constexpr std::vector\<value\_type\>

-----

### Function `cortex::box::begin`

``` cpp
constexpr 'hidden' begin() noexcept;
```

Begin Iterator

Iterator to the beginning of the box’s data.

\\return constexpr iterator

-----

### Function `cortex::box::begin`

``` cpp
constexpr 'hidden' begin() const noexcept;
```

Begin Iterator (const)

Constant iterator to the beginning of the box’s data.

\\return constexpr const\_iterator

-----

### Function `cortex::box::cbegin`

``` cpp
constexpr 'hidden' cbegin() const noexcept;
```

Constant Begin Iterator

Constant iterator to the beginning of the box.

\\return constexpr const\_iterator

-----

### Function `cortex::box::rbegin`

``` cpp
constexpr 'hidden' rbegin() noexcept;
```

Reverse Begin Iterator

Iterator to the reversed beginning of the box’s data.

\\return constexpr reverse\_iterator

-----

### Function `cortex::box::rbegin`

``` cpp
constexpr 'hidden' rbegin() const noexcept;
```

Reverse Begin Iterator (const)

Constant iterator to the reversed beginning of the box’s data.

\\return constexpr const\_reverse\_iterator

-----

### Function `cortex::box::crbegin`

``` cpp
constexpr 'hidden' crbegin() const noexcept;
```

Constant Reverse Begin Iterator

Constant iterator to the reversed beginning of the box’s data.

\\return constexpr const\_reverse\_iterator

-----

### Function `cortex::box::end`

``` cpp
constexpr 'hidden' end() noexcept;
```

End Iterator

Iterator to the end of the box’s data.

\\return constexpr iterator

-----

### Function `cortex::box::end`

``` cpp
constexpr 'hidden' end() const noexcept;
```

End Iterator (const)

Constant iterator to the end of the box’s data.

\\return constexpr const\_iterator

-----

### Function `cortex::box::cend`

``` cpp
constexpr 'hidden' cend() const noexcept;
```

Constant End Iterator

Constant iterator to the end of the box’s data.

\\return constexpr const\_iterator

-----

### Function `cortex::box::rend`

``` cpp
constexpr 'hidden' rend() noexcept;
```

Reverse End Iterator

Iterator to the reversed end of the box’s data.

\\return constexpr reverse\_iterator

-----

### Function `cortex::box::rend`

``` cpp
constexpr 'hidden' rend() const noexcept;
```

Reverse End Iterator (const)

Constant iterator to the reversed end of the box’s data.

\\return constexpr const\_reverse\_iterator

-----

### Function `cortex::box::crend`

``` cpp
constexpr 'hidden' crend() const noexcept;
```

Constant Reverse End Iterator

Constant iterator to the reversed end of the box’s data.

\\return constexpr const\_reverse\_iterator

-----

### Function `cortex::box::row_begin`

``` cpp
constexpr 'hidden' row_begin('hidden' row = 0uL);
```

Row Begin Iterator

Returns an iterator to the beginning of the indicated row.

#### Parameters

  - `row` - type: size\_type | default: 0uL \\return constexpr row\_iterator

-----

### Function `cortex::box::row_begin`

``` cpp
constexpr 'hidden' row_begin('hidden' row = 0uL) const;
```

Row Begin Iterator (const)

Returns an iterator to the beginning of the indicated row.

#### Parameters

  - `row` - type: size\_type | default: 0uL \\return constexpr const\_row\_iterator

-----

### Function `cortex::box::row_cbegin`

``` cpp
constexpr 'hidden' row_cbegin('hidden' row = 0uL) const;
```

Constant Row Begin Iterator

Returns a constant iterator to the beginning of the indicated row.

#### Parameters

  - `row` - type: size\_type | default: 0uL \\return constexpr const\_row\_iterator

-----

### Function `cortex::box::row_rbegin`

``` cpp
constexpr 'hidden' row_rbegin('hidden' row = 0uL);
```

Reverse Row Begin Iterator

Returns a reverse iterator to the beginning of the indicated reversed row.

#### Parameters

  - `row` - type: size\_type | default: 0uL \\return constexpr reverse\_row\_iterator

-----

### Function `cortex::box::row_rbegin`

``` cpp
constexpr 'hidden' row_rbegin('hidden' row = 0uL) const;
```

Reverse Row Begin Iterator (const)

Returns a constant reverse iterator to the beginning of the indicated reversed row.

#### Parameters

  - `row` - type: size\_type | default: 0uL \\return constexpr const\_reverse\_row\_iterator

-----

### Function `cortex::box::row_crbegin`

``` cpp
constexpr 'hidden' row_crbegin('hidden' row = 0uL) const;
```

Constant Reverse Row Begin Iterator

Returns a constant reverse iterator to the beginning of the indicated reversed row.

#### Parameters

  - `row` - \\return constexpr const\_reverse\_row\_iterator

-----

### Function `cortex::box::row_end`

``` cpp
constexpr 'hidden' row_end('hidden' row = 0uL);
```

Row End Iterator

Returns an iterator to one past the end of the row, this happens to be the first element in the next row. This is why the iterator column index is set to 0 and the row index is one plus the indicated positon.

#### Parameters

  - `row` - type: size\_type | default: 0uL \\return constexpr row\_iterator

-----

### Function `cortex::box::row_end`

``` cpp
constexpr 'hidden' row_end('hidden' row = 0uL) const;
```

Row End Iterator (const)

Returns an constant iterator to one past the end of the row, this happens to be the first element in the next row. This is why the iterator column index is set to 0 and the row index is one plus the indicated positon.

#### Parameters

  - `row` - type: size\_type | default: 0uL \\return constexpr const\_row\_iterator

-----

### Function `cortex::box::row_cend`

``` cpp
constexpr 'hidden' row_cend('hidden' row = 0uL) const;
```

Constant Row End Iterator

Returns an constant iterator to one past the end of the row, this happens to be the first element in the next row. This is why the iterator column index is set to 0 and the row index is one plus the indicated positon.

#### Parameters

  - `row` - type: size\_type | default: 0uL \\return constexpr const\_row\_iterator

-----

### Function `cortex::box::row_rend`

``` cpp
constexpr 'hidden' row_rend('hidden' row = 0uL);
```

Reverse Row End Iterator

Returns a reverse iterator to the end of the indicated reversed row.

#### Parameters

  - `row` - \\return constexpr reverse\_row\_iterator

-----

### Function `cortex::box::row_rend`

``` cpp
constexpr 'hidden' row_rend('hidden' row = 0uL) const;
```

Reverse Row End Iterator (const)

Returns a constant reverse iterator to the end of the indicated reversed row.

#### Parameters

  - `row` - \\return constexpr const\_reverse\_row\_iterator

-----

### Function `cortex::box::row_crend`

``` cpp
constexpr 'hidden' row_crend('hidden' row = 0uL) const;
```

Constant Reverse Row End Iterator

Returns a constant reverse iterator to the end of the indicated reversed row.

#### Parameters

  - `row` - \\return constexpr const\_reverse\_row\_iterator

-----

### Function `cortex::box::column_begin`

``` cpp
constexpr 'hidden' column_begin('hidden' column = 0uL);
```

Column Begin Iterator

Returns an iterator to the beginning of the indicated column.

#### Parameters

  - `column` - type: size\_type | default: 0uL \\return constexpr column\_iterator

-----

### Function `cortex::box::column_begin`

``` cpp
constexpr 'hidden' column_begin('hidden' column = 0uL) const;
```

Column Begin Iterator (const)

Returns a constant iterator to the beginning of the indicated column.

#### Parameters

  - `column` - type: size\_type | default: 0uL \\return constexpr const\_column\_iterator

-----

### Function `cortex::box::column_cbegin`

``` cpp
constexpr 'hidden' column_cbegin('hidden' column = 0uL) const;
```

Constant Column Begin Iterator

Returns a constant iterator to the beginning of the indicated column.

#### Parameters

  - `column` - type: size\_type | default: 0uL \\return constexpr const\_column\_iterator

-----

### Function `cortex::box::column_rbegin`

``` cpp
constexpr 'hidden' column_rbegin('hidden' column = 0uL);
```

Reverse Column Begin Iterator

Returns a reverse iterator to the beginning of the reversed column.

#### Parameters

  - `column` - type: size\_type | default: 0uL \\return constexpr reverse\_column\_iterator

-----

### Function `cortex::box::column_rbegin`

``` cpp
constexpr 'hidden' column_rbegin('hidden' column = 0uL) const;
```

Reverse Column Begin Iterator (const)

Returns a constant reverse iterator to the beginning of the indicated reversed column.

#### Parameters

  - `column` - type: size\_type | default: 0uL \\return constexpr const\_reverse\_column\_iterator

-----

### Function `cortex::box::column_crbegin`

``` cpp
constexpr 'hidden' column_crbegin('hidden' column = 0uL) const;
```

Constant Reverse Column Begin Iterator

Returns a constant reverse iterator to the beginning of the indicated reversed column.

#### Parameters

  - `column` - type: size\_type | default: 0uL \\return constexpr const\_reverse\_column\_iterator

-----

### Function `cortex::box::column_end`

``` cpp
constexpr 'hidden' column_end('hidden' column = 0uL);
```

Column End Iterator

Returns an iterator to one past the end of the column, this happens to be the first element in the next column. This is why the iterator row index is set to 0 and the column index is one plus the indicated position.

#### Parameters

  - `column` - type: size\_type | default: 0uL \\return constexpr column\_iterator

-----

### Function `cortex::box::column_end`

``` cpp
constexpr 'hidden' column_end('hidden' column = 0uL) const;
```

Column End Iterator (const)

Returns a constant iterator to one past the end of the column, this happens to be the first element in the next column. This is why the iterator row index is set to 0 and the column index is one plus the indicated position.

#### Parameters

  - `column` - type: size\_type | default: 0uL \\return constexpr const\_column\_iterator

-----

### Function `cortex::box::column_cend`

``` cpp
constexpr 'hidden' column_cend('hidden' column = 0uL) const;
```

Constant Column End Iterator

Returns a constant iterator to one past the end of the column, this happens to be the first element in the next column. This is why the iterator row index is set to 0 and the column index is one plus the indicated position.

#### Parameters

  - `column` - type: size\_type | default: 0uL \\return constexpr const\_column\_iterator

-----

### Function `cortex::box::column_rend`

``` cpp
constexpr 'hidden' column_rend('hidden' column = 0uL);
```

Reverse Column End Iterator

Returns a reverse iterator the end of the reversed column.

#### Parameters

  - `column` - type: size\_type | default: 0uL \\return constexpr reverse\_column\_iterator

-----

### Function `cortex::box::column_rend`

``` cpp
constexpr 'hidden' column_rend('hidden' column = 0uL) const;
```

Reverse Column End Iterator (const)

Returns a constant reverse iterator the end of the reversed column.

#### Parameters

  - `column` - type: size\_type | default: 0uL \\return constexpr const\_reverse\_column\_iterator

-----

### Function `cortex::box::column_crend`

``` cpp
constexpr 'hidden' column_crend('hidden' column = 0uL) const;
```

Constant Reverse Column End Iterator

Returns a constant reverse iterator the end of the reversed column.

#### Parameters

  - `column` - type: size\_type | default: 0uL \\return constexpr const\_reverse\_column\_iterator

-----

### Function `cortex::box::bit_not`

``` cpp
constexpr auto bit_not() const;
```

Element-wise Bitwise Not

*Requires:* BitNot\<value\_type\>

Performs an element-wise bitwise not operation. The box must not be empty.

\\exception std::invalid\_argument If the box is empty, std::invalid\_argument is thrown.

\\return constexpr auto

-----

### Function `cortex::box::transpose`

``` cpp
constexpr auto transpose();
```

Matrix Transpose

Performs a box transpose. Uses std::copy over std::ranges::copy as the output iterator is required to be std::constructible\_v which column\_iterator doesn’t satisfy yet.

\\return constexpr auto

-----

### Function `cortex::box::vflip`

``` cpp
constexpr auto vflip() const;
```

Vertical Flip

Performs a vertical flip of the box. ie. The order of the rows is reversed. If `this` box is empty, an empty box is returned with no memory allocated to it.

\\return constexpr auto

-----

### Function `cortex::box::hflip`

``` cpp
constexpr auto hflip() const;
```

Horizontal Flip

Performs a horizontal flip of the box. ie. The order of the columns is reversed. If `this` box is empty, an empty box is returned with no memory allocated to it.

\\return constexpr auto

-----

### Function `cortex::box::rrotate`

``` cpp
constexpr auto rrotate() const;
```

Right Rotate

Rotates the box 90 degrees clockwise. Inverts the dimension sizes of the box. If `this` box is empty, an empty box is returned with no memory allocated to it.

\\return constexpr auto

-----

### Function `cortex::box::lrotate`

``` cpp
constexpr auto lrotate() const;
```

Left Rotate

Rotates the box 90 degrees counter-clockwise. Inverts the dimension sizes of the box. If `this` box is empty, an empty box is returned with no memory allocated to it.

\\return constexpr auto

-----

-----

### Function `cortex::operator==`

``` cpp
template <typename _ElemL, typename _ElemR>
bool operator==(box<_ElemL> const& lhs, box<_ElemR> const& rhs);
```

Compares two matrices for equality.

*Requires:* Matrix elements support equality comparison that converts to a bool

Uses std::equal to compare the matrices. Takes at least O(n) where n = columns x rows = lhs.end() - lhs.begin()

\\exception Operation is has no exception iff the comparison between box elements is noexcept and std::equal is noexcept across the range

#### Template parameters

  - `_ElemR` - \\rparam lhsE type: \[\_ElemL\] \\rparam rhsE type: \[\_ElemR\]

#### Parameters

  - `lhs` - type: \[box\<\_ElemL\>\] | qualifiers: \[const, ref\]
  - `rhs` - type: \[box\<\_ElemR\>\] | qualifiers: \[const, ref\] \\return true \\return false

-----

### Function `cortex::operator!=`

``` cpp
template <typename _ElemL, typename _ElemR>
bool operator!=(box<_ElemL> const& lhs, box<_ElemR> const& rhs);
```

Compares two matrices for inequality.

Inverts the result of a equality comparison between two matrices.

#### Parameters

  - `lhs` - type: \[box\<\_ElemL\>\] | qualifiers: \[const, ref\]
  - `rhs` - type: \[box\<\_ElemR\>\] | qualifiers: \[const, ref\] \\return true \\return false

-----

### Function `cortex::operator<`

``` cpp
template <typename _ElemL, typename _ElemR>
bool operator<(box<_ElemL> const& lhs, box<_ElemR> const& rhs);
```

Compares if a box is lexicographically less than another.

#### Parameters

  - `lhs` - type: \[box\<\_ElemL\>\] | qualifiers: \[const, ref\]
  - `rhs` - type: \[box\<\_ElemR\>\] | qualifiers: \[const, ref\] \\return true \\return false

-----

### Function `cortex::operator>`

``` cpp
template <typename _ElemL, typename _ElemR>
bool operator>(box<_ElemL> const& lhs, box<_ElemR> const& rhs);
```

Compares if a box is lexicographically greater than another.

Uses less than comparison and swaps the order of the arguments.

#### Parameters

  - `lhs` - type: \[box\<\_ElemL\>\] | qualifiers: \[const, ref\]
  - `rhs` - type: \[box\<\_ElemR\>\] | qualifiers: \[const, ref\] \\return true \\return false

-----

### Function `cortex::operator<=`

``` cpp
template <typename _ElemL, typename _ElemR>
bool operator<=(box<_ElemL> const& lhs, box<_ElemR> const& rhs);
```

Compares if a box is lexicographically less than or equal to another.

Uses less than comparison and swaps the order of the arguments. If the rhs box is less than the lhs box, then the lhs box cannot be less then or equal to the rhs box.

#### Parameters

  - `lhs` - type: \[box\<\_ElemL\>\] | qualifiers: \[const, ref\]
  - `rhs` - type: \[box\<\_ElemR\>\] | qualifiers: \[const, ref\] \\return true \\return false

-----

### Function `cortex::operator>=`

``` cpp
template <typename _ElemL, typename _ElemR>
bool operator>=(box<_ElemL> const& lhs, box<_ElemR> const& rhs);
```

Compares if a box is lexicographically greater than or equal to another.

Inverts the result of a less than comparison between the two matrices.

#### Parameters

  - `lhs` - type: \[box\<\_ElemL\>\] | qualifiers: \[const, ref\]
  - `rhs` - type: \[box\<\_ElemR\>\] | qualifiers: \[const, ref\] \\return true \\return false

-----

### Function `cortex::operator==`

``` cpp
template <typename _ElemT>
box<bool> operator==(box<_ElemT> const& bx, _ElemT const& scalar);
```

Scalar Equality Comparison

*Requires:* Comparison of scalar type and box type support equality comparison that results in a bool.

Compares each value within the box to a given scalar. Creates a bit mask (or boolean mask) of the values that are equal as true and the everything else as false.

\\exception Operation is noexcept iff the inequlity comparison between the scalar and the box element’s types is noexcept.

#### Parameters

  - `bx` - type: \[box\<\_ElemT\>\] | qualifiers: \[const, ref\]
  - `scalar` - type: \[\_ElemT\] | qualifiers: \[const, ref\] \\return box\<bool\>

-----

### Function `cortex::operator!=`

``` cpp
template <typename _ElemT>
box<bool> operator!=(box<_ElemT> const& bx, _ElemT const& scalar);
```

Scalar Inequality Comparison

*Requires:* Comparison of scalar type and box type support inequality comparison that results in a bool.

Compares each value within the box to a given scalar. Creates a bit mask (or boolean mask) of the values that are inequal as true and the everything else as false.

\\exception Operation is noexcept iff the inequlity comparison between the scalar and the box element’s types is noexcept.

#### Parameters

  - `bx` - type: \[box\<\_ElemT\>\] | qualifiers: \[const, ref\]
  - `scalar` - type: \[\_ElemT\] | qualifiers: \[const, ref\] \\return box\<bool\>

-----

### Function `cortex::operator<`

``` cpp
template <typename _ElemT>
box<bool> operator<(box<_ElemT> const& bx, _ElemT const& scalar);
```

Scalar Less-Then Comparison

*Requires:* Comparison of scalar type and box type support less-than comparison that results in a bool.

Compares each value within the box to a given scalar. Creates a bit mask (or boolean mask) of the values that are less-than as true and the everything else as false.

\\exception Operation is noexcept iff the less-than comparison between the scalar and the box element’s types is noexcept.

#### Parameters

  - `bx` - type: \[box\<\_ElemT\>\] | qualifiers: \[const, ref\]
  - `scalar` - type: \[\_ElemT\] | qualifiers: \[const, ref\] \\return box\<bool\>

-----

### Function `cortex::operator>`

``` cpp
template <typename _ElemT>
box<bool> operator>(box<_ElemT> const& bx, _ElemT const& scalar);
```

Scalar Greater-Then Comparison

*Requires:* Comparison of scalar type and box type support greater-than comparison that results in a bool.

Compares each value within the box to a given scalar. Creates a bit mask (or boolean mask) of the values that are greater-than as true and the everything else as false.

\\exception Operation is noexcept iff the greater-than comparison between the scalar and the box element’s types is noexcept.

#### Parameters

  - `bx` - type: \[box\<\_ElemT\>\] | qualifiers: \[const, ref\]
  - `scalar` - type: \[\_ElemT\] | qualifiers: \[const, ref\] \\return box\<bool\>

-----

### Function `cortex::operator<=`

``` cpp
template <typename _ElemT>
box<bool> operator<=(box<_ElemT> const& bx, _ElemT const& scalar);
```

Scalar Less-Then-Equal Comparison

*Requires:* Comparison of scalar type and box type support less-than comparison that results in a bool.

Compares each value within the box to a given scalar. Creates a bit mask (or boolean mask) of the values that are less-than-eqaul as true and the everything else as false.

\\exception Operation is noexcept iff the less-than-equal comparison between the scalar and the box element’s types is noexcept.

#### Parameters

  - `bx` - type: \[box\<\_ElemT\>\] | qualifiers: \[const, ref\]
  - `scalar` - type: \[\_ElemT\] | qualifiers: \[const, ref\] \\return box\<bool\>

-----

### Function `cortex::operator>=`

``` cpp
template <typename _ElemT>
box<bool> operator>=(box<_ElemT> const& bx, _ElemT const& scalar);
```

Scalar Greater-Then-Equal Comparison

*Requires:* Comparison of scalar type and box type support greater-than-equal comparison that results in a bool.

Compares each value within the box to a given scalar. Creates a bit mask (or boolean mask) of the values that are greater-than-equal as true and the everything else as false.

\\exception Operation is noexcept iff the greater-than-equal comparison between the scalar and the box element’s types is noexcept.

#### Parameters

  - `bx` - type: \[box\<\_ElemT\>\] | qualifiers: \[const, ref\]
  - `scalar` - type: \[\_ElemT\] | qualifiers: \[const, ref\] \\return box\<bool\>

-----

### Function `std::swap`

``` cpp
template <typename T>
void swap(cortex::box<T>& x, cortex::box<T>& y) noexcept;
```

Uses std::swaps to swap the contents of two matrices.

Swaps the contents of two matrices if they are of the same type.

\\exception std::swap is noexcept if x.swap(y) is noexcept.

#### Parameters

  - `x` - type: \[cortex::box\<T\>\] | qualifiers: \[const, ref\]
  - `y` - type: \[cortex::box\<T\>\] | qualifiers: \[const, ref\] \\return inline void

-----
