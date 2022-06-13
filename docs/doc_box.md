# Header file `box.hpp`

``` cpp
#define CORTEX_BOX_H

#define lexicographical_compare_bug

namespace cortex
{
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

### Function `cortex::operator==`

``` cpp
template <typename _ElemL, typename _ElemR>
bool operator==(box<_ElemL> const& lhs, box<_ElemR> const& rhs);
```

@brief Compares two matrices for equality.

@details Uses std::equal to compare the matrices. Takes at least O(n) where n = columns x rows = lhs.end() - lhs.begin()

@requires Matrix elements support equality comparison that converts to a bool

@exception Operation is has no exception iff the comparison between box elements is noexcept and std::equal is noexcept across the range

@tparam \_ElemL @tparam \_ElemR @rparam lhsE type: \[\_ElemL\] @rparam rhsE type: \[\_ElemR\] @param lhs type: \[box\<\_ElemL\>\] | qualifiers: \[const, ref\] @param rhs type: \[box\<\_ElemR\>\] | qualifiers: \[const, ref\] @return true @return false

-----

### Function `cortex::operator!=`

``` cpp
template <typename _ElemL, typename _ElemR>
bool operator!=(box<_ElemL> const& lhs, box<_ElemR> const& rhs);
```

@brief Compares two matrices for inequality.

@details Inverts the result of a equality comparison between two matrices.

@tparam \_ElemL @tparam \_ElemR @param lhs type: \[box\<\_ElemL\>\] | qualifiers: \[const, ref\] @param rhs type: \[box\<\_ElemR\>\] | qualifiers: \[const, ref\] @return true @return false

-----

### Function `cortex::operator<`

``` cpp
template <typename _ElemL, typename _ElemR>
bool operator<(box<_ElemL> const& lhs, box<_ElemR> const& rhs);
```

@brief Compares if a box is lexicographically less than another.

@tparam \_ElemL @tparam \_ElemR @param lhs type: \[box\<\_ElemL\>\] | qualifiers: \[const, ref\] @param rhs type: \[box\<\_ElemR\>\] | qualifiers: \[const, ref\] @return true @return false

-----

### Function `cortex::operator>`

``` cpp
template <typename _ElemL, typename _ElemR>
bool operator>(box<_ElemL> const& lhs, box<_ElemR> const& rhs);
```

@brief Compares if a box is lexicographically greater than another.

@details Uses less than comparison and swaps the order of the arguments.

@tparam \_ElemL @tparam \_ElemR @param lhs type: \[box\<\_ElemL\>\] | qualifiers: \[const, ref\] @param rhs type: \[box\<\_ElemR\>\] | qualifiers: \[const, ref\] @return true @return false

-----

### Function `cortex::operator<=`

``` cpp
template <typename _ElemL, typename _ElemR>
bool operator<=(box<_ElemL> const& lhs, box<_ElemR> const& rhs);
```

@brief Compares if a box is lexicographically less than or equal to another.

@details Uses less than comparison and swaps the order of the arguments. If the rhs box is less than the lhs box, then the lhs box cannot be less then or equal to the rhs box.

@tparam \_ElemL @tparam \_ElemR @param lhs type: \[box\<\_ElemL\>\] | qualifiers: \[const, ref\] @param rhs type: \[box\<\_ElemR\>\] | qualifiers: \[const, ref\] @return true @return false

-----

### Function `cortex::operator>=`

``` cpp
template <typename _ElemL, typename _ElemR>
bool operator>=(box<_ElemL> const& lhs, box<_ElemR> const& rhs);
```

@brief Compares if a box is lexicographically greater than or equal to another.

@details Inverts the result of a less than comparison between the two matrices.

@tparam \_ElemL @tparam \_ElemR @param lhs type: \[box\<\_ElemL\>\] | qualifiers: \[const, ref\] @param rhs type: \[box\<\_ElemR\>\] | qualifiers: \[const, ref\] @return true @return false

-----

### Function `cortex::operator==`

``` cpp
template <typename _ElemT>
box<bool> operator==(box<_ElemT> const& bx, _ElemT const& scalar);
```

@brief Scalar Equality Comparison

@details Compares each value within the box to a given scalar. Creates a bit mask (or boolean mask) of the values that are equal as true and the everything else as false.

@requires Comparison of scalar type and box type support equality comparison that results in a bool.

@exception Operation is noexcept iff the inequlity comparison between the scalar and the box element’s types is noexcept.

@tparam \_ElemT

@param bx type: \[box\<\_ElemT\>\] | qualifiers: \[const, ref\] @param scalar type: \[\_ElemT\] | qualifiers: \[const, ref\] @return box\<bool\>

-----

### Function `cortex::operator!=`

``` cpp
template <typename _ElemT>
box<bool> operator!=(box<_ElemT> const& bx, _ElemT const& scalar);
```

@brief Scalar Inequality Comparison

@details Compares each value within the box to a given scalar. Creates a bit mask (or boolean mask) of the values that are inequal as true and the everything else as false.

@requires Comparison of scalar type and box type support inequality comparison that results in a bool.

@exception Operation is noexcept iff the inequlity comparison between the scalar and the box element’s types is noexcept.

@tparam \_ElemT

@param bx type: \[box\<\_ElemT\>\] | qualifiers: \[const, ref\] @param scalar type: \[\_ElemT\] | qualifiers: \[const, ref\] @return box\<bool\>

-----

### Function `cortex::operator<`

``` cpp
template <typename _ElemT>
box<bool> operator<(box<_ElemT> const& bx, _ElemT const& scalar);
```

@brief Scalar Less-Then Comparison

@details Compares each value within the box to a given scalar. Creates a bit mask (or boolean mask) of the values that are less-than as true and the everything else as false.

@requires Comparison of scalar type and box type support less-than comparison that results in a bool.

@exception Operation is noexcept iff the less-than comparison between the scalar and the box element’s types is noexcept.

@tparam \_ElemT

@param bx type: \[box\<\_ElemT\>\] | qualifiers: \[const, ref\] @param scalar type: \[\_ElemT\] | qualifiers: \[const, ref\] @return box\<bool\>

-----

### Function `cortex::operator>`

``` cpp
template <typename _ElemT>
box<bool> operator>(box<_ElemT> const& bx, _ElemT const& scalar);
```

@brief Scalar Greater-Then Comparison

@details Compares each value within the box to a given scalar. Creates a bit mask (or boolean mask) of the values that are greater-than as true and the everything else as false.

@requires Comparison of scalar type and box type support greater-than comparison that results in a bool.

@exception Operation is noexcept iff the greater-than comparison between the scalar and the box element’s types is noexcept.

@tparam \_ElemT

@param bx type: \[box\<\_ElemT\>\] | qualifiers: \[const, ref\] @param scalar type: \[\_ElemT\] | qualifiers: \[const, ref\] @return box\<bool\>

-----

### Function `cortex::operator<=`

``` cpp
template <typename _ElemT>
box<bool> operator<=(box<_ElemT> const& bx, _ElemT const& scalar);
```

@brief Scalar Less-Then-Equal Comparison

@details Compares each value within the box to a given scalar. Creates a bit mask (or boolean mask) of the values that are less-than-eqaul as true and the everything else as false.

@requires Comparison of scalar type and box type support less-than comparison that results in a bool.

@exception Operation is noexcept iff the less-than-equal comparison between the scalar and the box element’s types is noexcept.

@tparam \_ElemT

@param bx type: \[box\<\_ElemT\>\] | qualifiers: \[const, ref\] @param scalar type: \[\_ElemT\] | qualifiers: \[const, ref\] @return box\<bool\>

-----

### Function `cortex::operator>=`

``` cpp
template <typename _ElemT>
box<bool> operator>=(box<_ElemT> const& bx, _ElemT const& scalar);
```

@brief Scalar Greater-Then-Equal Comparison

@details Compares each value within the box to a given scalar. Creates a bit mask (or boolean mask) of the values that are greater-than-equal as true and the everything else as false.

@requires Comparison of scalar type and box type support greater-than-equal comparison that results in a bool.

@exception Operation is noexcept iff the greater-than-equal comparison between the scalar and the box element’s types is noexcept.

@tparam \_ElemT

@param bx type: \[box\<\_ElemT\>\] | qualifiers: \[const, ref\] @param scalar type: \[\_ElemT\] | qualifiers: \[const, ref\] @return box\<bool\>

-----

### Function `std::swap`

``` cpp
template <typename T>
void swap(cortex::box<T>& x, cortex::box<T>& y) noexcept;
```

@brief Uses std::swaps to swap the contents of two matrices.

@details Swaps the contents of two matrices if they are of the same type.

@exception std::swap is noexcept if x.swap(y) is noexcept.

@tparam T @param x type: \[cortex::box\<T\>\] | qualifiers: \[const, ref\] @param y type: \[cortex::box\<T\>\] | qualifiers: \[const, ref\] @return inline void

-----
