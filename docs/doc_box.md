# Header file `box.hpp`

``` cpp
#define CORTEX_BOX_H

#define lexicographical_compare_bug

namespace cortex
{
    template <typename _Tp, typename _Alloc = std::allocator<_Tp>>>
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
    template <typename _Tp>
    void swap(cortex::box<_Tp>& x, cortex::box<_Tp>& y) noexcept;
}
```

### Class `cortex::box`

``` cpp
template <typename _Tp, typename _Alloc = std::allocator<_Tp>>>
class box
{
public:
    constexpr box() noexcept;

    constexpr box('hidden' const& alloc) noexcept;

    constexpr box('hidden' rows, 'hidden' cols, 'hidden' const& alloc = allocator_type());

    constexpr box('hidden' rows, 'hidden' cols, 'hidden' const& value, 'hidden' const& alloc = allocator_type());

    constexpr box(const box<_Tp, _Alloc>& other);

    constexpr box(const box<_Tp, _Alloc>& other, 'hidden' const& alloc);

    constexpr box(box<_Tp, _Alloc>&& other) noexcept;

    constexpr box(box<_Tp, _Alloc>&& other, 'hidden' const& alloc) noexcept;

    constexpr box(std::initializer_list<std::initializer_list<value_type>> list, 'hidden' const& alloc = allocator_type());

    constexpr box<_Tp, _Alloc>& operator=(const box<_Tp, _Alloc>& other);

    constexpr box<_Tp, _Alloc>& operator=(box<_Tp, _Alloc>&& other) noexcept;

    constexpr box<_Tp, _Alloc>& operator=(std::initializer_list<std::initializer_list<value_type>> list);

    constexpr void resize('hidden' new_rows, 'hidden' new_columns);

    constexpr void resize('hidden' new_rows, 'hidden' new_columns, 'hidden' const& value);

    constexpr 'hidden' erase('hidden' position);

    constexpr 'hidden' erase('hidden' first, 'hidden' last);

    constexpr void clear();

    constexpr void reshape('hidden' new_rows, 'hidden' new_columns);

    void swap(box<_Tp, _Alloc>& other) noexcept;

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

    constexpr 'hidden' operator[]('hidden' step);

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

    constexpr box<cortex::box::value_type> transpose();

private:
    constexpr 'hidden' _M_allocate('hidden' __n);

    constexpr void _M_deallocate('hidden' __p, 'hidden' __n);

    constexpr void _M_range_check('hidden' __row, 'hidden' __column) const;

    template <typename _Up>
    _Up* _M_data_ptr(_Up* __ptr) const noexcept;

    template <typename _Ptr>
    typename std::pointer_traits<_Ptr>::element_type* _M_data_ptr(_Ptr __ptr) const;
};
```

@brief Box - Two Dimensional Array

@details Box is a two dimensional array that stores elements sequentially in memory but is viewed as a series of rows and columns.

@todo Add support for iterator constructors ––––––––––––– ✔️ @todo Add other modification methods (mod, xor etc.) —————– ✔️ @todo Projection method ––––––––––––––––––––––– 🗑️ (do-able with assign) @todo Add support for single initialiser constructor —————– 🗑️ (too ambiguous for compiler) @todo Add support for assign —————————————– @todo Add support for operator overloads —————————– @todo Add flips —————————————————— @todo Add rotates ––––––––––––––––––––––––––

@tparam \_Tp

### Constructor `cortex::box::box`

``` cpp
constexpr box() noexcept;
```

@brief Default Constructor

@details Default constructor for box.

-----

### Constructor `cortex::box::box`

``` cpp
constexpr box('hidden' const& alloc) noexcept;
```

@brief Allocator Constructor

@details Default Constructs a box with a given allocator.

@param alloc type: allocator\_type | qualifiers: \[const\], \[ref\]

-----

### Constructor `cortex::box::box`

``` cpp
constexpr box('hidden' rows, 'hidden' cols, 'hidden' const& alloc = allocator_type());
```

@brief Size Constructor

@details Constructs a box with dimensions of cols x rows. Values are default constructed or fill constructed depending on the default constructiblity qualificationbx.

@param cols type: \[size\_type\] @param rows type: \[size\_type\] @param alloc type: \[allocator\_type\] | qualifiers: \[const\], \[ref\]

-----

### Constructor `cortex::box::box`

``` cpp
constexpr box('hidden' rows, 'hidden' cols, 'hidden' const& value, 'hidden' const& alloc = allocator_type());
```

@brief Size + Value Constructor

@details Constructs a box with dimensions of cols x rows. Values are constructed from the a const reference to a provided value.

@param cols type: \[size\_type\] @param rows type: \[size\_type\] @param value type: \[value\_type\] | qualifiers: \[const\], \[ref\] @param alloc type: \[allocator\_type\] | qualifiers: \[const\], \[ref\]

-----

### Constructor `cortex::box::box`

``` cpp
constexpr box(const box<_Tp, _Alloc>& other);
```

@brief Copy Constructor

@details Constructs a box that is a copy of another box of the same underlying type.

@param other type: \[box\] | qualifiers: \[const\], \[ref\]

-----

### Constructor `cortex::box::box`

``` cpp
constexpr box(const box<_Tp, _Alloc>& other, 'hidden' const& alloc);
```

@brief Copy Constructor with Alternative Allocator

@details Constructs a box that is a copy of another box of the same underlying type.

@param other type: \[box\] | qualifiers: \[const\], \[ref\] @param alloc type: \[allocator\_type\] | qualifiers: \[const\], \[ref\]

-----

### Constructor `cortex::box::box`

``` cpp
constexpr box(box<_Tp, _Alloc>&& other) noexcept;
```

@brief Move Constructor

@details Moves ownership of an existing box’s resources to this box and leaves the other box in a default constructed state.

@param other type: \[box\] | qualifiers: \[move\]

-----

### Constructor `cortex::box::box`

``` cpp
constexpr box(box<_Tp, _Alloc>&& other, 'hidden' const& alloc) noexcept;
```

@brief Move Constructor with Alternative Allocator

@details Moves ownership of an existing box’s resources to this box and leaves the other box in a default constructed state.

@param other type: \[box\] | qualifiers: \[move\] @param alloc type: \[allocator\_type\] | qualifiers: \[const\], \[ref\]

-----

### Constructor `cortex::box::box`

``` cpp
constexpr box(std::initializer_list<std::initializer_list<value_type>> list, 'hidden' const& alloc = allocator_type());
```

@brief Initialiser List Constructor

@details Uses std::initializer\_list to create a box from an initializer list of initializer lists. Elements ownership is moved to the box’s memory.

@param list type: \[std::initializer\_list\<std::initializer\_list\<value\_type\>\>\] | qualifiers: \[const\], \[ref\]

-----

### Function `cortex::box::operator=`

``` cpp
constexpr box<_Tp, _Alloc>& operator=(const box<_Tp, _Alloc>& other);
```

@brief Copy Assignment

@details Copies the contents of another box into this box and returns///this. If self assignment occurs then///this is returned immediately.

@param other type: \[box\] | qualifiers: \[const\], \[ref\] @return constexpr box&

-----

### Function `cortex::box::operator=`

``` cpp
constexpr box<_Tp, _Alloc>& operator=(box<_Tp, _Alloc>&& other) noexcept;
```

@brief Move Assignment

@details Moves the ownership of other’s resources to this box and leaves the other box in a default constructed state. Returns///this. If self assignment occurs then///this is returned immediately.

@param other type: \[box\] | qualifiers: \[move\] @return constexpr box&

-----

### Function `cortex::box::operator=`

``` cpp
constexpr box<_Tp, _Alloc>& operator=(std::initializer_list<std::initializer_list<value_type>> list);
```

@brief Initialiser List Assignment

@details Uses std::initializer\_list to create a box from an initializer list of initializer lists. Elements ownership is moved to the box’s memory.

@param list type: \[std::initializer\_list\<std::initializer\_list\<value\_type\>\>\] | qualifiers: \[const\], \[ref\] @return constexpr box&

-----

### Function `cortex::box::resize`

``` cpp
constexpr void resize('hidden' new_rows, 'hidden' new_columns);
```

@brief Resizes the box to dimensions new\_rows x new\_columns.

@details Resizes the box to dimensions new\_rows x new\_columns, the resize will result in a new memory block being allocated if the new dimensions are larger or smaller than the current dimensions. Reallocation or destruction of elements causes iterators and references to be invalidated. If new dimensions don’t change the overall size, only the view over the data (ie. the dimension sizes) are changed, elements of the box remain unchanged, however, this is unchecked. For a checked change that can only changes the dimension sizes, use box::reshape.

@param new\_rows type: \[size\_type\] @param new\_columns type: \[size\_type\]

-----

### Function `cortex::box::resize`

``` cpp
constexpr void resize('hidden' new_rows, 'hidden' new_columns, 'hidden' const& value);
```

@brief Resizes the box to dimensions new\_rows x new\_columns with default value

@details Resizes the box to dimensions new\_rows x new\_columns, the resize will result in a new memory block being allocated if the new dimensions are larger or smaller than the current dimensions. Reallocation or destruction of elements causes iterators and references to be invalidated. The new box is initialised with value. If new dimensions don’t change the overall size, only the view over the data (ie. the dimension sizes) are changed, elements of the box remain unchanged, however, this is unchecked. For a checked change that can only changes the dimension sizes, use box::reshape.

@param new\_rows type: \[size\_type\] @param new\_columns type: \[size\_type\] @param value type: \[value\_type\] | qualifiers: \[const\], \[ref\]

-----

### Function `cortex::box::erase`

``` cpp
constexpr 'hidden' erase('hidden' position);
```

@brief Erases element indicated by position

@details Erases the value of the box at position and resets it to value\_type().

@param position type: \[const\_iterator\] @return constexpr iterator - attr: \[\[maybe\_unused\]\] :\>\> Returns the iterator to the erased position

-----

### Function `cortex::box::erase`

``` cpp
constexpr 'hidden' erase('hidden' first, 'hidden' last);
```

@brief Erases value between first and last

@details Elements between first and last and then resets memory to value\_type()

@param first type: \[const\_iterator\] @param last type: \[const\_iterator\] @return constexpr iterator - attr: \[\[maybe\_unused\]\] :\>\> Returns the iterator indicated the start of the erase

-----

### Function `cortex::box::clear`

``` cpp
constexpr void clear();
```

@brief Clears the box elements

@details The elements of the box are destroyed and the memory is deallocated entirely. The box is however, left in a state where it could be re-initialised or destructed which is up to user descretionbx. box::resize has to be used to allocate storage for the new elements.

-----

### Function `cortex::box::reshape`

``` cpp
constexpr void reshape('hidden' new_rows, 'hidden' new_columns);
```

@brief Reshape current box elements to new dimensions

@details Reshapes the current box’s dimensisons while guranteeing that now reallocation occurs. Elements are preserved.

@param new\_rows type: \[size\_type\] @param new\_columns type: \[size\_type\]

-----

### Function `cortex::box::swap`

``` cpp
void swap(box<_Tp, _Alloc>& other) noexcept;
```

@brief Swaps two matrices of the same type.

@details Swaps the contents of two matrices of which they are the same type. The swap is performed by moving ownership of the matrices resources.

@param other type: \[box\] | qualifiers: \[ref\]

-----

### Function `cortex::box::get_allocator`

``` cpp
constexpr 'hidden' get_allocator() const noexcept;
```

@brief Get Allocator

@details Returns the allocator used by the box.

@return constexpr allocator\_type

-----

### Function `cortex::box::size`

``` cpp
constexpr 'hidden' size() const noexcept;
```

@brief Returns the overall size of the box.

@return constexpr size\_type

-----

### Function `cortex::box::rows`

``` cpp
constexpr 'hidden' rows() const noexcept;
```

@brief Returns the number of the rows of the box.

@return constexpr size\_type

-----

### Function `cortex::box::columns`

``` cpp
constexpr 'hidden' columns() const noexcept;
```

@brief Returns the the number of columns in the box.

@return constexpr size\_type

-----

### Function `cortex::box::max_size`

``` cpp
constexpr 'hidden' max_size() const noexcept;
```

@brief Returns the maximum number of elements that can be stored in the box.

@return constexpr size\_type

-----

### Function `cortex::box::dimensions`

``` cpp
constexpr auto dimensions() const noexcept;
```

@brief Returns a structured binding of the box’s dimensions.

@return constexpr auto : (structured binding)

-----

### Function `cortex::box::is_square`

``` cpp
constexpr bool is_square() const noexcept;
```

@brief Checks whether the box is square.

@details If the number of rows and columns are equal, the box is square.

@return true @return false

-----

### Function `cortex::box::empty`

``` cpp
constexpr bool empty() const noexcept;
```

@brief Checks if the box is empty.

@return true @return false

-----

### Function `cortex::box::data`

``` cpp
'hidden' data() noexcept;
```

@brief Returns the underlying data pointer.

@return pointer

-----

### Function `cortex::box::data`

``` cpp
'hidden' data() const noexcept;
```

@brief Returns the underlying data pointer.

@return const\_pointer

-----

### Function `cortex::box::operator[]`

``` cpp
constexpr 'hidden' operator[]('hidden' step);
```

@brief Subscript Operator.

@details Returns a reference to the element that is at the position indicated by the pointer m\_data + step. Offers linear access to the box’s elements.

@param step type: \[size\_type\] @return constexpr reference

-----

### Function `cortex::box::at`

``` cpp
constexpr 'hidden' at('hidden' row, 'hidden' column);
```

@brief Two Dimensional Element Access (Point Access).

@details Returns a reference to the element that is at the point position (column, row) of the box.

@exception std::out\_of\_range

@param column type: \[size\_type\] @param row type: \[size\_type\] @return constexpr reference

-----

### Function `cortex::box::at`

``` cpp
constexpr 'hidden' at('hidden' row, 'hidden' column) const;
```

@brief Two Dimensional Element Access (Point Access).

@details Returns a reference to the element that is at the point position (column, row) of the box.

@exception std::out\_of\_range

@param column type: \[size\_type\] @param row type: \[size\_type\] @return constexpr const\_reference

-----

### Function `cortex::box::operator()`

``` cpp
constexpr 'hidden' operator()('hidden' row, 'hidden' column);
```

@brief Point Access Operator.

@details Provides point access to box’s elements. Overloads the invokation operator. Utilises the at() method.

@exception std::out\_of\_range

@param column type: \[size\_type\] @param row type: \[size\_type\] @return constexpr reference

-----

### Function `cortex::box::operator()`

``` cpp
constexpr 'hidden' operator()('hidden' row, 'hidden' column) const;
```

@brief Point Access Operator.

@details Provides point access to box’s elements. Overloads the invokation operator. Utilises the at() method.

@exception std::out\_of\_range

@param column type: \[size\_type\] @param row type: \[size\_type\] @return constexpr const\_reference

-----

### Function `cortex::box::front`

``` cpp
constexpr 'hidden' front() noexcept;
```

@brief Returns a reference to the front element of the box.

@return constexpr reference

-----

### Function `cortex::box::front`

``` cpp
constexpr 'hidden' front() const noexcept;
```

@brief Returns a reference to the front element of the box.

@return constexpr const\_reference

-----

### Function `cortex::box::back`

``` cpp
constexpr 'hidden' back() noexcept;
```

@brief Returns a reference to the back element of the box.

@return constexpr reference

-----

### Function `cortex::box::back`

``` cpp
constexpr 'hidden' back() const noexcept;
```

@brief Returns a reference to the back element of the box.

@return constexpr const\_reference

-----

### Function `cortex::box::flatten`

``` cpp
constexpr std::vector<value_type> flatten() const noexcept;
```

@brief Flattens the box into a std::vector.

@details Creates a vector of the box’s elements in row major order.

@return constexpr std::vector\<value\_type\>

-----

### Function `cortex::box::begin`

``` cpp
constexpr 'hidden' begin() noexcept;
```

@brief Iterator to the beginning of the box.

@return constexpr iterator

-----

### Function `cortex::box::begin`

``` cpp
constexpr 'hidden' begin() const noexcept;
```

@brief Constant iterator to the beginning of the box.

@return constexpr const\_iterator

-----

### Function `cortex::box::cbegin`

``` cpp
constexpr 'hidden' cbegin() const noexcept;
```

@brief Constant iterator to the beginning of the box.

@return constexpr const\_iterator

-----

### Function `cortex::box::rbegin`

``` cpp
constexpr 'hidden' rbegin() noexcept;
```

@brief Reverse iterator to the end of the box.

@return constexpr reverse\_iterator

-----

### Function `cortex::box::rbegin`

``` cpp
constexpr 'hidden' rbegin() const noexcept;
```

@brief Constant reverse iterator to the end of the box.

@return constexpr const\_reverse\_iterator

-----

### Function `cortex::box::crbegin`

``` cpp
constexpr 'hidden' crbegin() const noexcept;
```

@brief Constant reverse iterator to the end of the box.

@return constexpr const\_reverse\_iterator

-----

### Function `cortex::box::end`

``` cpp
constexpr 'hidden' end() noexcept;
```

@brief Iterator to the end of the box.

@return constexpr iterator

-----

### Function `cortex::box::end`

``` cpp
constexpr 'hidden' end() const noexcept;
```

@brief Constant iterator to the end of the box.

@return constexpr const\_iterator

-----

### Function `cortex::box::cend`

``` cpp
constexpr 'hidden' cend() const noexcept;
```

@brief Constant iterator to the end of the box.

@return constexpr const\_iterator

-----

### Function `cortex::box::rend`

``` cpp
constexpr 'hidden' rend() noexcept;
```

@brief Reverse iterator to the beginning of the box.

@return constexpr reverse\_iterator

-----

### Function `cortex::box::rend`

``` cpp
constexpr 'hidden' rend() const noexcept;
```

@brief Constant reverse iterator to the beginning of the box.

@return constexpr const\_reverse\_iterator

-----

### Function `cortex::box::crend`

``` cpp
constexpr 'hidden' crend() const noexcept;
```

@brief Constant reverse iterator to the beginning of the box.

@return constexpr const\_reverse\_iterator

-----

### Function `cortex::box::row_begin`

``` cpp
constexpr 'hidden' row_begin('hidden' row = 0uL);
```

@brief Row Begin Iterator

@details Returns an iterator to the beginning of the row.

@param row type: size\_type | default: 0uL @return constexpr row\_iterator

-----

### Function `cortex::box::row_begin`

``` cpp
constexpr 'hidden' row_begin('hidden' row = 0uL) const;
```

@brief Row Begin Iterator (const)

@details Returns an iterator to the beginning of the row.

@param row type: size\_type | default: 0uL @return constexpr const\_row\_iterator

-----

### Function `cortex::box::row_cbegin`

``` cpp
constexpr 'hidden' row_cbegin('hidden' row = 0uL) const;
```

@brief Constant Row Begin Iterator

@details Returns a constant iterator to the beginning of the row.

@param row type: size\_type | default: 0uL @return constexpr const\_row\_iterator

-----

### Function `cortex::box::row_rbegin`

``` cpp
constexpr 'hidden' row_rbegin('hidden' row = 0uL);
```

@brief Reverse Row Begin Iterator

@details Returns a reverse iterator to the beginning of the reversed row.

@param row type: size\_type | default: 0uL @return constexpr reverse\_row\_iterator

-----

### Function `cortex::box::row_rbegin`

``` cpp
constexpr 'hidden' row_rbegin('hidden' row = 0uL) const;
```

@brief Reverse Row Begin Iterator (const)

@details Returns a constant reverse iterator to the beginning of the reversed row.

@param row type: size\_type | default: 0uL @return constexpr const\_reverse\_row\_iterator

-----

### Function `cortex::box::row_crbegin`

``` cpp
constexpr 'hidden' row_crbegin('hidden' row = 0uL) const;
```

@brief Constant Reverse Row Begin Iterator

@details Returns a constant reverse iterator to the beginning of the reversed row.

@param row @return constexpr const\_reverse\_row\_iterator

-----

### Function `cortex::box::row_end`

``` cpp
constexpr 'hidden' row_end('hidden' row = 0uL);
```

@brief Row End Iterator

@details Returns an iterator to one past the end of the row, this happens to be the first element in the next row. This is why the iterator column index is set to 0 and the row index is one plus the indicated positon.

@param row type: size\_type | default: 0uL @return constexpr row\_iterator

-----

### Function `cortex::box::row_end`

``` cpp
constexpr 'hidden' row_end('hidden' row = 0uL) const;
```

@brief Row End Iterator (const)

@details Returns an constant iterator to one past the end of the row, this happens to be the first element in the next row. This is why the iterator column index is set to 0 and the row index is one plus the indicated positon.

@param row type: size\_type | default: 0uL @return constexpr const\_row\_iterator

-----

### Function `cortex::box::row_cend`

``` cpp
constexpr 'hidden' row_cend('hidden' row = 0uL) const;
```

@brief Constant Row End Iterator

@details Returns an constant iterator to one past the end of the row, this happens to be the first element in the next row. This is why the iterator column index is set to 0 and the row index is one plus the indicated positon.

@param row type: size\_type | default: 0uL @return constexpr const\_row\_iterator

-----

### Function `cortex::box::row_rend`

``` cpp
constexpr 'hidden' row_rend('hidden' row = 0uL);
```

@brief Reverse Row End Iterator

@details Returns a reverse iterator to the end of the reversed row.

@param row @return constexpr reverse\_row\_iterator

-----

### Function `cortex::box::row_rend`

``` cpp
constexpr 'hidden' row_rend('hidden' row = 0uL) const;
```

@brief Reverse Row End Iterator (const)

@details Returns a constant reverse iterator to the end of the reversed row.

@param row @return constexpr const\_reverse\_row\_iterator

-----

### Function `cortex::box::row_crend`

``` cpp
constexpr 'hidden' row_crend('hidden' row = 0uL) const;
```

@brief Constant Reverse Row End Iterator

@details Returns a constant reverse iterator to the end of the reversed row.

@param row @return constexpr const\_reverse\_row\_iterator

-----

### Function `cortex::box::column_begin`

``` cpp
constexpr 'hidden' column_begin('hidden' column = 0uL);
```

@brief Column Begin Iterator

@details Returns an iterator to the beginning of the column.

@param column type: size\_type | default: 0uL @return constexpr column\_iterator

-----

### Function `cortex::box::column_begin`

``` cpp
constexpr 'hidden' column_begin('hidden' column = 0uL) const;
```

@brief Column Begin Iterator (const)

@details Returns a constant iterator to the beginning of the column.

@param column type: size\_type | default: 0uL @return constexpr const\_column\_iterator

-----

### Function `cortex::box::column_cbegin`

``` cpp
constexpr 'hidden' column_cbegin('hidden' column = 0uL) const;
```

@brief Constant Column Begin Iterator

@details Returns a constant iterator to the beginning of the column.

@param column type: size\_type | default: 0uL @return constexpr const\_column\_iterator

-----

### Function `cortex::box::column_rbegin`

``` cpp
constexpr 'hidden' column_rbegin('hidden' column = 0uL);
```

@brief Reverse Column Begin Iterator

@details Returns a reverse iterator to the beginning of the reversed column.

@param column type: size\_type | default: 0uL @return constexpr reverse\_column\_iterator

-----

### Function `cortex::box::column_rbegin`

``` cpp
constexpr 'hidden' column_rbegin('hidden' column = 0uL) const;
```

@brief Reverse Column Begin Iterator (const)

@details Returns a constant reverse iterator to the beginning of the reversed column.

@param column type: size\_type | default: 0uL @return constexpr const\_reverse\_column\_iterator

-----

### Function `cortex::box::column_crbegin`

``` cpp
constexpr 'hidden' column_crbegin('hidden' column = 0uL) const;
```

@brief Constant Reverse Column Begin Iterator

@details Returns a constant reverse iterator to the beginning of the reversed column.

@param column type: size\_type | default: 0uL @return constexpr const\_reverse\_column\_iterator

-----

### Function `cortex::box::column_end`

``` cpp
constexpr 'hidden' column_end('hidden' column = 0uL);
```

@brief Column End Iterator

@details Returns an iterator to one past the end of the column, this happens to be the first element in the next column. This is why the iterator row index is set to 0 and the column index is one plus the indicated position.

@param column type: size\_type | default: 0uL @return constexpr column\_iterator

-----

### Function `cortex::box::column_end`

``` cpp
constexpr 'hidden' column_end('hidden' column = 0uL) const;
```

@brief Column End Iterator (const)

@details Returns a constant iterator to one past the end of the column, this happens to be the first element in the next column. This is why the iterator row index is set to 0 and the column index is one plus the indicated position.

@param column type: size\_type | default: 0uL @return constexpr const\_column\_iterator

-----

### Function `cortex::box::column_cend`

``` cpp
constexpr 'hidden' column_cend('hidden' column = 0uL) const;
```

@brief Constant Column End Iterator

@details Returns a constant iterator to one past the end of the column, this happens to be the first element in the next column. This is why the iterator row index is set to 0 and the column index is one plus the indicated position.

@param column type: size\_type | default: 0uL @return constexpr const\_column\_iterator

-----

### Function `cortex::box::column_rend`

``` cpp
constexpr 'hidden' column_rend('hidden' column = 0uL);
```

@brief Reverse Column End Iterator

@details Returns a reverse iterator the end of the reversed column.

@param column type: size\_type | default: 0uL @return constexpr reverse\_column\_iterator

-----

### Function `cortex::box::column_rend`

``` cpp
constexpr 'hidden' column_rend('hidden' column = 0uL) const;
```

@brief Reverse Column End Iterator (const)

@details Returns a constant reverse iterator the end of the reversed column.

@param column type: size\_type | default: 0uL @return constexpr const\_reverse\_column\_iterator

-----

### Function `cortex::box::column_crend`

``` cpp
constexpr 'hidden' column_crend('hidden' column = 0uL) const;
```

@brief Constant Reverse Column End Iterator

@details Returns a constant reverse iterator the end of the reversed column.

@param column type: size\_type | default: 0uL @return constexpr const\_reverse\_column\_iterator

-----

### Function `cortex::box::bit_not`

``` cpp
constexpr auto bit_not() const;
```

@brief Element-wise Bitwise Not

@details Performs an element-wise bitwise not operation. The box must not be empty.

@exception std::invalid\_argument If the box is empty, std::invalid\_argument is thrown.

@    requires BitNot\<value\_type\>

@return constexpr auto

-----

### Function `cortex::box::transpose`

``` cpp
constexpr box<cortex::box::value_type> transpose();
```

@brief Matrix Transpose

@details Performs a box transpose. Uses std::copy over std::ranges::copy as the output iterator is required to be std::constructible\_v which column\_iterator doesn’t satisfy yet.

@return constexpr box\<value\_type\>

-----

### Function `cortex::box::_M_allocate`

``` cpp
constexpr 'hidden' _M_allocate('hidden' __n);
```

@brief Allocates Matrix Recources

@details Allocates the memory for the box using the allocator of the container. Uses std::allocator\_traits to get the allocators relevant methods.

@note Default allocator is std::allocator\<value\_type\>.

@param \_\_n type: \[size\_type\] @return constexpr pointer

-----

### Function `cortex::box::_M_deallocate`

``` cpp
constexpr void _M_deallocate('hidden' __p, 'hidden' __n);
```

@brief Dellocates Matrix Recources

@details Dellocates the memory for the box using the allocator of the container. Uses std::allocator\_traits to get the allocators relevant methods.

@note Default allocator is std::allocator\<value\_type\>.

@param \_\_p type: \[pointer\] @param \_\_n type: \[size\_type\] | attr: \[\[maybe\_unused\]\]

-----

### Function `cortex::box::_M_range_check`

``` cpp
constexpr void _M_range_check('hidden' __row, 'hidden' __column) const;
```

@brief Checks index’s are in the bounds of the box

@details Checks if \_\_column and \_\_row are withing the box’s bounds.

@exception std::out\_of\_range

@param \_\_column type: \[size\_type\] @param \_\_row type: \[size\_type\]

-----

### Function `cortex::box::_M_data_ptr`

``` cpp
template <typename _Up>
_Up* _M_data_ptr(_Up* __ptr) const noexcept;
```

@brief Returns the pointer passed to it.

@tparam \_Up @param \_\_ptr type: \[\_Up\*\] @return \_Up\*

-----

### Function `cortex::box::_M_data_ptr`

``` cpp
template <typename _Ptr>
typename std::pointer_traits<_Ptr>::element_type* _M_data_ptr(_Ptr __ptr) const;
```

@brief Returns the pointer passed to it.

@details If the value given is not a builtin pointer type, a pointer is created from the underlying element type.

@tparam \_Ptr @param \_\_ptr type: \[\_Ptr\] @return typename std::pointer\_traits\<\_Ptr\>::element\_type\*

-----

-----

### Function `cortex::operator==`

``` cpp
template <typename _ElemL, typename _ElemR>
bool operator==(box<_ElemL> const& lhs, box<_ElemR> const& rhs);
```

@brief Compares two matrices for equality.

@details Uses std::equal to compare the matrices. Takes at least O(n) where n = columns x rows = lhs.end() - lhs.begin()

@    requires Matrix elements support equality comparison that converts to a bool

@exception Operation is has no exception iff the comparison between box elements is noexcept and std::equal is noexcept across the range

@tparam \_ElemL @tparam \_ElemR @rparam lhsE type: \[\_ElemL\] @rparam rhsE type: \[\_ElemR\] @param lhs type: \[box\<\_ElemL\>\] | qualifiers: \[const\], \[ref\] @param rhs type: \[box\<\_ElemR\>\] | qualifiers: \[const\], \[ref\] @return true @return false

-----

### Function `cortex::operator!=`

``` cpp
template <typename _ElemL, typename _ElemR>
bool operator!=(box<_ElemL> const& lhs, box<_ElemR> const& rhs);
```

@brief Compares two matrices for inequality.

@details Inverts the result of a equality comparison between two matrices.

@tparam \_ElemL @tparam \_ElemR @param lhs type: \[box\<\_ElemL\>\] | qualifiers: \[const\], \[ref\] @param rhs type: \[box\<\_ElemR\>\] | qualifiers: \[const\], \[ref\] @return true @return false

-----

### Function `cortex::operator<`

``` cpp
template <typename _ElemL, typename _ElemR>
bool operator<(box<_ElemL> const& lhs, box<_ElemR> const& rhs);
```

@brief Compares if a box is lexicographically less than another.

@tparam \_ElemL @tparam \_ElemR @param lhs type: \[box\<\_ElemL\>\] | qualifiers: \[const\], \[ref\] @param rhs type: \[box\<\_ElemR\>\] | qualifiers: \[const\], \[ref\] @return true @return false

-----

### Function `cortex::operator>`

``` cpp
template <typename _ElemL, typename _ElemR>
bool operator>(box<_ElemL> const& lhs, box<_ElemR> const& rhs);
```

@brief Compares if a box is lexicographically greater than another.

@details Uses less than comparison and swaps the order of the arguments.

@tparam \_ElemL @tparam \_ElemR @param lhs type: \[box\<\_ElemL\>\] | qualifiers: \[const\], \[ref\] @param rhs type: \[box\<\_ElemR\>\] | qualifiers: \[const\], \[ref\] @return true @return false

-----

### Function `cortex::operator<=`

``` cpp
template <typename _ElemL, typename _ElemR>
bool operator<=(box<_ElemL> const& lhs, box<_ElemR> const& rhs);
```

@brief Compares if a box is lexicographically less than or equal to another.

@details Uses less than comparison and swaps the order of the arguments. If the rhs box is less than the lhs box, then the lhs box cannot be less then or equal to the rhs box.

@tparam \_ElemL @tparam \_ElemR @param lhs type: \[box\<\_ElemL\>\] | qualifiers: \[const\], \[ref\] @param rhs type: \[box\<\_ElemR\>\] | qualifiers: \[const\], \[ref\] @return true @return false

-----

### Function `cortex::operator>=`

``` cpp
template <typename _ElemL, typename _ElemR>
bool operator>=(box<_ElemL> const& lhs, box<_ElemR> const& rhs);
```

@brief Compares if a box is lexicographically greater than or equal to another.

@details Inverts the result of a less than comparison between the two matrices.

@tparam \_ElemL @tparam \_ElemR @param lhs type: \[box\<\_ElemL\>\] | qualifiers: \[const\], \[ref\] @param rhs type: \[box\<\_ElemR\>\] | qualifiers: \[const\], \[ref\] @return true @return false

-----

### Function `cortex::operator==`

``` cpp
template <typename _ElemT>
box<bool> operator==(box<_ElemT> const& bx, _ElemT const& scalar);
```

@brief Scalar Equality Comparison

@details Compares each value within the box to a given scalar. Creates a bit mask (or boolean mask) of the values that are equal as true and the everything else as false.

@    requires Comparison of scalar type and box type support equality comparison that results in a bool.

@exception Operation is noexcept iff the inequlity comparison between the scalar and the box element’s types is noexcept.

@tparam \_ElemT

@param bx type: \[box\<\_ElemT\>\] | qualifiers: \[const\], \[ref\] @param scalar type: \[\_ElemT\] | qualifiers: \[const\], \[ref\] @return box\<bool\>

-----

### Function `cortex::operator!=`

``` cpp
template <typename _ElemT>
box<bool> operator!=(box<_ElemT> const& bx, _ElemT const& scalar);
```

@brief Scalar Inequality Comparison

@details Compares each value within the box to a given scalar. Creates a bit mask (or boolean mask) of the values that are inequal as true and the everything else as false.

@    requires Comparison of scalar type and box type support inequality comparison that results in a bool.

@exception Operation is noexcept iff the inequlity comparison between the scalar and the box element’s types is noexcept.

@tparam \_ElemT

@param bx type: \[box\<\_ElemT\>\] | qualifiers: \[const\], \[ref\] @param scalar type: \[\_ElemT\] | qualifiers: \[const\], \[ref\] @return box\<bool\>

-----

### Function `cortex::operator<`

``` cpp
template <typename _ElemT>
box<bool> operator<(box<_ElemT> const& bx, _ElemT const& scalar);
```

@brief Scalar Less-Then Comparison

@details Compares each value within the box to a given scalar. Creates a bit mask (or boolean mask) of the values that are less-than as true and the everything else as false.

@    requires Comparison of scalar type and box type support less-than comparison that results in a bool.

@exception Operation is noexcept iff the less-than comparison between the scalar and the box element’s types is noexcept.

@tparam \_ElemT

@param bx type: \[box\<\_ElemT\>\] | qualifiers: \[const\], \[ref\] @param scalar type: \[\_ElemT\] | qualifiers: \[const\], \[ref\] @return box\<bool\>

-----

### Function `cortex::operator>`

``` cpp
template <typename _ElemT>
box<bool> operator>(box<_ElemT> const& bx, _ElemT const& scalar);
```

@brief Scalar Greater-Then Comparison

@details Compares each value within the box to a given scalar. Creates a bit mask (or boolean mask) of the values that are greater-than as true and the everything else as false.

@    requires Comparison of scalar type and box type support greater-than comparison that results in a bool.

@exception Operation is noexcept iff the greater-than comparison between the scalar and the box element’s types is noexcept.

@tparam \_ElemT

@param bx type: \[box\<\_ElemT\>\] | qualifiers: \[const\], \[ref\] @param scalar type: \[\_ElemT\] | qualifiers: \[const\], \[ref\] @return box\<bool\>

-----

### Function `cortex::operator<=`

``` cpp
template <typename _ElemT>
box<bool> operator<=(box<_ElemT> const& bx, _ElemT const& scalar);
```

@brief Scalar Less-Then-Equal Comparison

@details Compares each value within the box to a given scalar. Creates a bit mask (or boolean mask) of the values that are less-than-eqaul as true and the everything else as false.

@    requires Comparison of scalar type and box type support less-than comparison that results in a bool.

@exception Operation is noexcept iff the less-than-equal comparison between the scalar and the box element’s types is noexcept.

@tparam \_ElemT

@param bx type: \[box\<\_ElemT\>\] | qualifiers: \[const\], \[ref\] @param scalar type: \[\_ElemT\] | qualifiers: \[const\], \[ref\] @return box\<bool\>

-----

### Function `cortex::operator>=`

``` cpp
template <typename _ElemT>
box<bool> operator>=(box<_ElemT> const& bx, _ElemT const& scalar);
```

@brief Scalar Greater-Then-Equal Comparison

@details Compares each value within the box to a given scalar. Creates a bit mask (or boolean mask) of the values that are greater-than-equal as true and the everything else as false.

@    requires Comparison of scalar type and box type support greater-than-equal comparison that results in a bool.

@exception Operation is noexcept iff the greater-than-equal comparison between the scalar and the box element’s types is noexcept.

@tparam \_ElemT

@param bx type: \[box\<\_ElemT\>\] | qualifiers: \[const\], \[ref\] @param scalar type: \[\_ElemT\] | qualifiers: \[const\], \[ref\] @return box\<bool\>

-----

### Function `std::swap`

``` cpp
template <typename _Tp>
void swap(cortex::box<_Tp>& x, cortex::box<_Tp>& y) noexcept;
```

@brief Uses std::swaps to swap the contents of two matrices.

@details Swaps the contents of two matrices if they are of the same type.

@exception std::swap is noexcept if x.swap(y) is noexcept.

@tparam \_Tp @param \_\_x type: \[cortex::box\<\_Tp\>\] | qualifiers: \[const\], \[ref\] @param \_\_y type: \[cortex::box\<\_Tp\>\] | qualifiers: \[const\], \[ref\] @return inline void

-----
