/// -*- C++ -*- Header compatibility <column.hpp>

/// @brief Column Iterator
/// @file column.hpp
/// @author Tyler Swann (oraqlle@github.com)
/// @version 1.0.1
/// @date 2022-05-20
/// 
/// @ingroup %iterators
/// 
/// @copyright Copyright (c) 2022


#ifndef CORTEX_COLUMN_ITERATOR_HPP
#   define CORTEX_COLUMN_ITERATOR_HPP 1


#include <utility>
#include <type_traits>
#include <iterator>

#include "two_dim.hpp"

#if __cpp_lib_three_way_comparison
#   include <compare>
#endif // __cpp_lib_three_way_comparison

#if __cpp_concepts >= 201907L
#   include <concepts>
#endif // __cpp_concepts >= 201907L


#   if __cplusplus >= 201402L

namespace cortex
{    
    /// @brief Column Iterator
    ///
    /// @details A column iterator is an iterator that iterates a
    /// given two dimensional space in column order. Incrementing
    /// moves the iterator to the next item in that column and 
    /// vice versa for decrementing. Incrementing from the last item 
    /// in a column causes the iterator to jump to the first item in 
    /// the next column. Like wise, decrementing from the first item
    /// in a column causes the iterator to jump to the last item in
    /// the previous column. A column iterator is derived from the base 
    /// %cortex::two_dim_iterator. 
    /// 
    /// @tparam _Iterator 
    template<typename _Iterator>
    class column_iterator 
    : public two_dim_iterator<_Iterator>
    {
    protected:
        using _Base = two_dim_iterator<_Iterator>;

        using __traits_type                     = typename _Base::__traits_type;

    public:
        using iterator_type                     = typename _Base::iterator_type;
        using iterator_category                 = typename _Base::iterator_category;

// #if __cpp_concepts >= 201907L
//         using iterator_concept                  = typename _Base::iterator_concept;
// #endif // __cpp_concepts >= 201907L

        using size_type                         = typename _Base::size_type;
        using value_type                        = typename __traits_type::value_type;
        using difference_type                   = typename __traits_type::difference_type;
        using pointer                           = typename __traits_type::pointer;
        using reference                         = typename __traits_type::reference;

    public:


        /// @brief Default Constructor
        ///
        /// @details Constructs a column iterator with 
        /// the two_dim_iterators default constrcutor.
        constexpr column_iterator() noexcept
        : _Base()
        { }

        /// @brief Explicit Value Constructor
        /// 
        /// @details Constructs a column iterator from a reference to
        /// an iterator of the underlying iterator type, the dimensions
        /// the column iterator can move through and the current point 
        /// index the iterator points to. Calls the base class constructor.
        ///
        /// @param ptr type: iterator_type | qualifiers: [const, ref]
        /// @param ridx type: size_type
        /// @param cidx type: size_type
        /// @param rows type: size_type
        /// @param columns type: size_type
        constexpr column_iterator(const iterator_type& ptr
                                , size_type ridx, size_type cidx
                                , size_type rows, size_type columns) noexcept
        : _Base(ptr, ridx, cidx, rows, columns)
        { }


        /// @brief Pre Increment Operator
        ///
        /// @details Increments the iterator to the next item in the
        /// column. If the iterator is at the last item in the column,
        /// the iterator is set to the first item in the next column.
        /// 
        /// @return constexpr column_iterator& 
        constexpr column_iterator& operator++ () noexcept
        {
            auto old_ridx { this->m_ridx };
            auto old_cidx { this->m_cidx };

            if (this->m_ridx == this->m_rows - 1)
            {
                this->m_ridx = size_type();
                ++this->m_cidx;
            }
            else
                ++this->m_ridx;

            this->m_current += this->_M_index((this->m_ridx - old_ridx)
                                            , (this->m_cidx - old_cidx));
                        
            return *this;
        }


        /// @brief Post Increment Operator
        ///
        /// @details Increments the iterator to the next item in the
        /// column. If the iterator is at the last item in the column,
        /// the iterator is set to the first item in the next column.
        /// Returns the column iterator before the increment.
        ///
        /// @return constexpr column_iterator
        constexpr column_iterator operator++ (int) noexcept
        {
            auto old { column_iterator(*this) };

            if (this->m_ridx == this->m_rows - 1)
            {
                this->m_ridx = size_type();
                ++this->m_cidx;
            }
            else
                ++this->m_ridx;

            this->m_current += this->_M_index((this->m_ridx - old.row_index())
                                            , (this->m_cidx - old.column_index()));
            
            return old;
        }


        /// @brief Pre Decrement Operator
        ///
        /// @details Decrements the iterator to the previous item in the
        /// column. If the iterator is at the first item in the column,
        /// the iterator is set to the last item in the previous column.
        ///
        /// @return constexpr column_iterator&
        constexpr column_iterator& operator-- () noexcept
        {
            auto old_ridx { this->m_ridx };
            auto old_cidx { this->m_cidx };

            if (this->m_ridx == size_type())
            {
                this->m_ridx = this->m_rows;
                this->m_cidx--;
            }

            this->m_ridx--;

            this->m_current += this->_M_index((this->m_ridx - old_ridx)
                                            , (this->m_cidx - old_cidx));
            
            return *this;
        }


        /// @brief Post Decrement Operator
        ///
        /// @details Decrements the iterator to the previous item in the
        /// column. If the iterator is at the first item in the column,
        /// the iterator is set to the last item in the previous column.
        /// Returns the column iterator before the decrement.
        ///
        /// @return constexpr column_iterator
        constexpr column_iterator operator-- (int) noexcept
        {
            auto old { column_iterator(*this) };

            if (this->m_ridx == size_type())
            {
                this->m_ridx = this->m_rows;
                this->m_cidx--;
            }

            this->m_ridx--;

            this->m_current += this->_M_index((this->m_ridx - old.row_index())
                                            , (this->m_cidx - old.column_index()));
            
            return old;
        }


        // constexpr reference operator[] (difference_type __n) noexcept
        // {
        //     auto new_ridx { this->m_ridx + __n };
        //     auto new_cidx { this->m_cidx };

        //     if (new_ridx > this->m_rows - 1)
        //     {
        //         new_ridx %= this->m_rows;
        //         new_cidx++;
        //     }

        //     return *(this->m_current + this->_M_index((row - this->m_ridx), (col - this->m_cidx)));
        // }


        // constexpr column_iterator& operator+= (difference_type __step) noexcept
        // {
        //     auto [col, row] { this->_M_point(__step + m_rows, m_rows) };

        //     this->m_current += this->_M_index((row - this->m_ridx), (col - this->m_cidx));
        //     return *this;
        // }


        // constexpr column_iterator& operator-= (difference_type __step) noexcept
        // {
        //     auto [col, row] { this->_M_point((-__step) + m_rows, m_rows) };

        //     this->m_current += this->_M_index((row - this->m_ridx), (col - this->m_cidx));
        //     return *this;
        // }


        // constexpr column_iterator operator+ (difference_type __step) const noexcept
        // {
        //     auto [col, row] { this->_M_point(__step + m_rows, m_rows) };

        //     return column_iterator(this->m_current + this->_M_index((row - this->m_ridx), (col - this->m_cidx))
        //                          , row, col
        //                          , this->m_rows, this->m_columns);
        // }


        // constexpr column_iterator operator- (difference_type __step) const noexcept
        // {
        //     auto [col, row] { this->_M_point((-__step) + m_rows, m_rows) };

        //     return column_iterator(this->m_current + this->_M_index((row - this->m_ridx), (col - this->m_cidx))
        //                          , row, col
        //                          , this->m_rows, this->m_columns);
        // }
    }; /// class column_iterator


    
    /// @brief Addition Operator Overload.
    /// 
    /// @details Takes an offset \param __n and a %column_iterator 
    /// @param __i. Constructs a new %column_iterator by adding
    /// @param __n to \param __i.base().
    /// 
    /// @tparam _Iterator 
    /// @tparam _Container 
    /// @param __n 
    /// @param __i 
    /// @return constexpr inline column_iterator<_Iterator, _Container> 
    /// 
    /// [constexpr]
    /// [noexcept]
    
    // template<typename _Iterator>
    // constexpr inline column_iterator<_Iterator>
    // operator+ (typename column_iterator<_Iterator>::difference_type __n, 
    //             const column_iterator<_Iterator>& __i)
    // noexcept
    // { 
    //     std::size_t rows { __n % __i.rows() };
    //     auto cols { __n / __i.rows() };

    //     auto offset { __i.columns()/// rows + cols };

    //     //! \bug _M_index is protected
    //     return column_iterator(__i.base() + offset
    //                        , __i.row_index() + rows, __i.column_index() + cols
    //                        , __i.rows(), __i.columns());
    // }


    /// @brief Less Than Operator
    /// 
    /// @details Performs less-than comparison of two column 
    /// iterators. A column iterator is considered less than 
    /// another firstly, if it is at a lower column index. If the
    /// column indices are equal, the column iterator is considered
    /// less than another if it is at a lower row index.
    /// 
    /// @tparam _Iterator 
    /// @param __lhs type: column_iterator<_Iterator> | qualifiers: [const, ref]
    /// @param __rhs type: column_iterator<_Iterator> | qualifiers: [const, ref]
    /// @return true 
    /// @return false 
    template<typename _Iterator>
    constexpr inline bool
    operator< (const column_iterator<_Iterator>& __lhs, 
                const column_iterator<_Iterator>& __rhs)
    noexcept
    { 
        return __lhs.column_index() < __rhs.column_index() ? true 
        : (__lhs.column_index() == __rhs.column_index() and __lhs.row_index() < __rhs.row_index()) ? true
        : false; 
    }


    /// @brief Greater Than Operator Overload
    ///
    /// @details Performs greater-than comparison of two column
    /// iterators. A column iterator is considered greater than
    /// another firstly, if it is at a higher column index. If the
    /// column indices are equal, the column iterator is considered
    /// greater than another if it is at a higher row index. 
    /// 
    /// @tparam _Iterator 
    /// @param __lhs type: column_iterator<_Iterator> | qualifiers: [const, ref]
    /// @param __rhs type: column_iterator<_Iterator> | qualifiers: [const, ref]
    /// @return true 
    /// @return false 
    template<typename _Iterator>
    constexpr inline bool
    operator> (const column_iterator<_Iterator>& __lhs, 
                const column_iterator<_Iterator>& __rhs)
    noexcept
    { 
        return __lhs.column_index() > __rhs.column_index() ? true 
        : (__lhs.column_index() == __rhs.column_index() and __lhs.row_index() > __lhs.row_index()) ? true
        : false;
    }


    /// @brief Less Than or Equal Operator
    ///
    /// @details Performs less-than-or-equal comparison of two column
    /// iterators. A column iterator is considered less than or equal
    /// to another firstly, if they compare equal, secondly if they
    /// compare less than.
    ///
    /// @tparam _Iterator
    /// @param __lhs type: column_iterator<_Iterator> | qualifiers: [const, ref]
    /// @param __rhs type: column_iterator<_Iterator> | qualifiers: [const, ref]
    /// @return true
    /// @return false
    template<typename _Iterator>
    constexpr inline bool
    operator<= (const column_iterator<_Iterator>& __lhs, 
                const column_iterator<_Iterator>& __rhs)
    noexcept
    {
        return __lhs == __rhs ? true
        : __lhs < __rhs ? true
        : false;
    }


    /// @brief Greater Than or Equal Operator
    ///
    /// @details Performs greater-than-or-equal comparison of two column
    /// iterators. A column iterator is considered greater than or equal
    /// to another firstly, if they compare equal, secondly if they
    /// compare greater than.
    /// 
    /// @tparam _Iterator 
    /// @param __lhs type: column_iterator<_Iterator> | qualifiers: [const, ref]
    /// @param __rhs type: column_iterator<_Iterator> | qualifiers: [const, ref]
    /// @return true 
    /// @return false 
    template<typename _Iterator>
    constexpr inline bool
    operator>= (const column_iterator<_Iterator>& __lhs, 
                const column_iterator<_Iterator>& __rhs)
    noexcept
    {
        return __lhs == __rhs ? true
        : __lhs > __rhs ? true
        : false;
    }


//     
//     /// @brief Makes a new %column_iterator.
//     /// 
//     /// @details An adaptor for turning STL container iterators 
//     /// into %column_iterators.
//     /// 
//     /// @code {.cpp}
//     /// auto it = make_column_iterator<std::container>(c.begin()); 
//     /// @endcode 
//     /// 
//     /// @tparam _Container 
//     /// @param __i 
//     /// @return constexpr auto -> column_iterator<typename _Container::iterator, _Container>
//     /// 
//     /// [constexpr]
//     /// [noexcept]
//     
//     template<typename _Container>
//     constexpr auto
//     make_column(typename _Container::iterator __i)
//     noexcept
//         -> column_iterator<typename _Container::iterator>
//     { return column_iterator<typename _Container::iterator, _Container>(__i); }



//     
//     /// @brief Makes a new %column_iterator.
//     /// 
//     /// @details An adaptor for making C-style array pointers 
//     /// into %column_iterators.
//     /// 
//     /// @code {.cpp}
//     /// auto it =  make_normal<int*, int[]>(arr);
//     /// @endcode
//     /// 
//     /// @tparam _Iterator 
//     /// @tparam _Container 
//     /// @param __i 
//     /// @return constexpr auto -> column_iterator<_Iterator, _Container> 
//     /// 
//     /// [constexpr]
//     /// [noexcept]
//     
//     template<typename _Iterator, typename _Container>
//     constexpr auto
//     make_column(_Iterator __i)
//     noexcept
//         -> column_iterator<_Iterator, _Container>
//     { return column_iterator<_Iterator, _Container>(__i); }


// #   if __cplusplus >= 201703L // C++17
//     
//     /// @brief Makes a new %column_iterator.
//     /// 
//     /// @details An adaptor for making STL container iterators
//     /// into %column_iterators using C++17 type deduction.
//     /// 
//     /// @code {.cpp}
//     /// auto it = make_normal(c, c.begin());
//     /// @endcode
//     /// 
//     /// @note \param __c has the attribute [[maybe_unused]]
//     /// 
//     /// @tparam _Container 
//     /// @tparam _Iterator 
//     /// @param __c 
//     /// @param __i 
//     /// @return constexpr auto -> column_iterator<_Iterator, _Container> 
//     /// 
//     /// [constexpr]
//     /// [noexcept]
//     
//     template<typename _Container, typename _Iterator>
//     constexpr auto
//     make_column([[maybe_unused]] const _Container& __c, _Iterator __i)
//     noexcept
//         -> column_iterator<_Iterator, _Container>
//     { return column_iterator<_Iterator, _Container>(__i); }
// 
// #   endif // __cplusplus >= 201703L

} // namespace cortex


#   endif // __cplusplus >= 201402L

#endif // CORTEX_COLUMN_ITERATOR_HPP