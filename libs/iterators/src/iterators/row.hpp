/// -*- C++ -*- Header compatibility <row.hpp>


/// \brief Row Iterator
///
/// Author: Tyler Swann (oraqlle@github.com)
/// 
/// Header Version: v1.0.1
///
/// Date: 25-06-2022
///
/// License: MIT
///
/// Copyright: Copyright (c) 2022
/// \file row.hpp


#ifndef CORTEX_ROW_ITERATOR_HPP
#   define CORTEX_ROW_ITERATOR_HPP 1


#include <utility>
#include <type_traits>
#include <iterator>

#include "two_dim.hpp"

#if __cpp_lib_three_way_comparison
#   include <compare>
#endif /// __cpp_lib_three_way_comparison

#if __cpp_concepts >= 201907L
#   include <concepts>
#endif /// __cpp_concepts >= 201907L


#   if __cplusplus >= 201402L

namespace cortex
{    
    /// \brief Row Iterator
    ///
    /// \details A row iterator is a iterator that iterates a
    /// given two dimensional space in row order. Incrementing
    /// moves the iterator to the next item in that row and 
    /// vice versa for decrementing. Incrementing from the last item 
    /// in a row causes the iterator to jump to the first item in 
    /// the next row. Like wise, decrementing from the first item
    /// in a row causes the iterator to jump to the last item in
    /// the previous row. A column iterator is derived from the base 
    /// %cortex::two_dim_iterator. 
    ///
    /// \tparam _Iterator
    template<typename _Iterator>
    class row_iterator
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
// #endif /// __cpp_concepts >= 201907L

        using size_type                         = typename _Base::size_type;
        using value_type                        = typename __traits_type::value_type;
        using difference_type                   = typename __traits_type::difference_type;
        using pointer                           = typename __traits_type::pointer;
        using reference                         = typename __traits_type::reference;

    public:

        /// \brief Default Constructor
        ///
        /// \details Constructs a row iterator with 
        /// the two_dim_iterators default constrcutor.
        constexpr row_iterator() noexcept
        : _Base()
        { }


        /// \brief Explicit Value Constrcutor 
        /// 
        /// \details Constructs a column iterator from a reference to
        /// an iterator of the underlying iterator type, the dimensions
        /// the column iterator can move through and the current point 
        /// index the iterator points to. Calls the base class constructor.
        ///
        /// \param ptr type: iterator_type | qualifier: [const, ref]
        constexpr row_iterator(const iterator_type& ptr
                              , size_type ridx, size_type cidx
                              , size_type row, size_type col) noexcept
        : _Base(ptr, ridx, cidx, row, col)
        {}
        

        /// \brief Pre Increment Operator
        ///
        /// \details Increments the iterator to the next item in the
        /// row. If the iterator is at the end of the row, the iterator
        /// jumps to the first item in the next row. 
        /// 
        /// \returns constexpr row_iterator& 
        constexpr row_iterator& operator++ () noexcept
        {
            auto old_ridx { this->m_ridx };
            auto old_cidx { this->m_cidx };

            if (this->m_cidx == this->m_columns - 1)
            {
                this->m_cidx = size_type();
                this->m_ridx++;
            }
            else
                this->m_cidx++;

            this->m_current += this->_M_index((this->m_ridx - old_ridx)
                                            , (this->m_cidx - old_cidx));
            
            return *this;
        }


        /// \brief Post Increment Operator
        ///
        /// \details Increments the iterator to the next item in the
        /// row. If the iterator is at the end of the row, the iterator
        /// jumps to the first item in the next row. Returns the iterator
        /// before the increment.
        /// 
        /// \returns constexpr row_iterator 
        constexpr row_iterator operator++ (int) noexcept
        {
            auto old { row_iterator(*this) };

            if (this->m_cidx == this->m_columns - 1)
            {
                this->m_cidx = size_type();
                this->m_ridx++;
            }
            else
                this->m_cidx++;

            this->m_current += this->_M_index((this->m_ridx - old.row_index())
                                            , (this->m_cidx - old.column_index()));
            
            return old;
        }


        /// \brief Pre Decrement Operator
        ///
        /// \details Decrements the iterator to the previous item in the
        /// row. If the iterator is at the first item in the row, the
        /// iterator jumps to the last item in the previous row.
        ///
        /// \returns constexpr row_iterator&
        constexpr row_iterator& operator-- () noexcept
        {
            auto old_ridx { this->m_ridx };
            auto old_cidx { this->m_cidx };

            if (this->m_cidx == size_type())
            {
                this->m_cidx = this->m_columns;
                this->m_ridx--;
            }
            
            this->m_cidx--;

            this->m_current += this->_M_index((this->m_ridx - old_ridx)
                                            , (this->m_cidx - old_cidx));
            
            return *this;
        }


        /// \brief Post Decrement Operator
        ///
        /// \details Decrements the iterator to the previous item in the
        /// row. If the iterator is at the first item in the row, the
        /// iterator jumps to the last item in the previous row. Returns
        /// the iterator before the decrement.
        ///
        /// \returns constexpr row_iterator
        constexpr row_iterator operator-- (int) noexcept
        {
            auto old { row_iterator(*this) };

            if (this->m_cidx == size_type())
            {
                this->m_cidx = this->m_columns;
                this->m_ridx--;
            }
            
            this->m_cidx--;

            this->m_current += this->_M_index((this->m_ridx - old.row_index())
                                            , (this->m_cidx - old.column_index()));
            
            return old;
        }


        /// constexpr reference operator[] (difference_type __n) noexcept
        /// {
        ///     size_type cols { __n / this->m_columns };
        ///     auto rows { __n % this->m_columns };

        ///     return *(this->m_current + this->_M_access(rows, cols));
        /// }


        /// constexpr row_iterator& operator+= (difference_type __step) noexcept
        /// {
        ///     size_type cols { __step / this->m_columns };
        ///     auto rows { __step % this->m_columns };

        ///     this->m_current += this->_M_access(rows, cols);
        ///     return *this;
        /// }


        /// constexpr row_iterator& operator-= (difference_type __step) noexcept
        /// {
        ///     size_type cols { __step / this->m_columns };
        ///     auto rows { __step % this->m_columns };

        ///     this->m_current -= this->_M_access(rows, cols);
        ///     return *this;
        /// }


        /// constexpr row_iterator operator+ (difference_type __step) const noexcept
        /// {
        ///     size_type cols { __step / this->m_columns };
        ///     auto rows { __step % this->m_columns };

        ///     return row_iterator(this->m_current + this->_M_access(rows, cols), this->m_ridx + rows, this->m_cidx + cols, this->m_rows, this->m_columns);
        /// }


        /// constexpr row_iterator operator- (difference_type __step) const noexcept
        /// {
        ///     size_type cols { __step / this->m_columns };
        ///     auto rows { __step % this->m_columns };

        ///     return row_iterator(this->m_current - this->_M_access(rows, cols), this->m_ridx + rows, this->m_cidx + cols, this->m_rows, this->m_columns);
        /// }

    }; /// class row_iterator


    
    /// \brief Addition Operator Overload.
    /// 
    /// \details Takes an offset \param __n and a %row_iterator 
    /// \param __i. Constructs a new %row_iterator by adding
    /// \param __n to \param __i.base().
    /// 
    /// \tparam _Iterator 
    /// \tparam _Container 
    /// \param __n 
    /// \param __i 
    /// \returns constexpr inline row_iterator<_Iterator, _Container> 
    /// 
    /// [constexpr]
    /// [noexcept]
   
    /// template<typename _Iterator>
    /// constexpr inline row_iterator<_Iterator>
    /// operator+ (typename row_iterator<_Iterator>::difference_type __n, 
    ///             const row_iterator<_Iterator>& __i)
    /// noexcept
    /// { 
    ///     std::size_t cols { __n / __i.columns() };
    ///     auto rows { __n % __i.columns() };

    ///     auto offset { __i.columns()/// rows + cols };

    ///     return row_iterator(__i.base() + offset
    ///                        , __i.row_index() + rows, __i.column_index() + cols
    ///                        , __i.rows(), __i.columns());
    /// }


    /// \brief Less Than Operator
    ///
    /// \details Performs less-than comparison of two row 
    /// iterators. A row iterator is considered less than  another 
    /// firstly, if it is at a lower row index. If the row indices 
    /// are equal, the row iterator is considered less than another 
    /// if it is at a lower column index. 
    /// 
    /// \tparam _Iterator 
    /// \param __lhs type: row_iterator<_Iterator> | qualifier: [const, ref]
    /// \param __rhs type: row_iterator<_Iterator> | qualifier: [const, ref]
    /// \returns true 
    /// \returns false 
    template<typename _Iterator>
    constexpr inline bool
    operator< (const row_iterator<_Iterator>& __lhs, 
                const row_iterator<_Iterator>& __rhs)
    noexcept
    { 
        return __lhs.row_index() < __rhs.row_index() ? true 
        : __lhs.row_index() == __rhs.row_index() and __lhs.column_index() < __rhs.column_index() ? true
        : false; 
    }


    /// \brief Greater Than Operator
    ///
    /// \details Performs greater-than comparison of two row
    /// iterators. A row iterator is considered greater than
    /// another firstly, if it is at a higher row index. If the
    /// row indices are equal, the row iterator is considered
    /// greater than another if it is at a higher column index.
    /// 
    /// \tparam _Iterator 
    /// \param __lhs type: row_iterator<_Iterator> | qualifier: [const, ref]
    /// \param __rhs type: row_iterator<_Iterator> | qualifier: [const, ref]
    /// \returns true 
    /// \returns false 
    template<typename _Iterator>
    constexpr inline bool
    operator> (const row_iterator<_Iterator>& __lhs, 
                const row_iterator<_Iterator>& __rhs)
    noexcept
    { 
        return __lhs.row_index() > __rhs.row_index() ? true 
        : __lhs.row_index() == __rhs.row_index() and __lhs.column_index() > __rhs.column_index() ? true
        : false;
    }


    /// \brief Less Than or Equal Operator
    ///
    /// \details Performs less-than-or-equal comparison of two row
    /// iterators. A row iterator is considered less than or equal
    /// to another firstly, if they compare equal, secondly if they
    /// compare less than.
    /// 
    /// \tparam _Iterator 
    /// \param __lhs type: row_iterator<_Iterator> | qualifier: [const, ref]
    /// \param __rhs type: row_iterator<_Iterator> | qualifier: [const, ref]
    /// \returns true 
    /// \returns false 
    template<typename _Iterator>
    constexpr inline bool
    operator<= (const row_iterator<_Iterator>& __lhs, 
                const row_iterator<_Iterator>& __rhs)
    noexcept
    {
        return __lhs == __rhs ? true
        : __lhs < __rhs ? true
        : false;
    }


    /// \brief Greater Than or Equal Operator
    ///
    /// \details Performs greater-than-or-equal comparison of two row
    /// iterators. A row iterator is considered greater than or equal
    /// to another firstly, if they compare equal, secondly if they
    /// compare greater than. 
    /// 
    /// \tparam _Iterator 
    /// \param __lhs 
    /// \param __rhs 
    /// \returns true 
    /// \returns false 
    template<typename _Iterator>
    constexpr inline bool
    operator>= (const row_iterator<_Iterator>& __lhs, 
                const row_iterator<_Iterator>& __rhs)
    noexcept
    {
        return __lhs == __rhs ? true
        : __lhs > __rhs ? true
        : false;
    }


//     
//     /// \brief Makes a new %row_iterator.
//     /// 
//     /// \details An adaptor for turning STL container iterators 
//     /// into %row_iterators.
//     /// 
//     /// \code {.cpp}
//     /// auto it = make_row_iterator<std::container>(c.begin()); 
//     /// \endcode 
//     /// 
//     /// \tparam _Container 
//     /// \param __i 
//     /// \returns constexpr auto -> row_iterator<typename _Container::iterator, _Container>
//     /// 
//     /// [constexpr]
//     /// [noexcept]
//    
//     template<typename _Container>
//     constexpr auto
//     make_column(typename _Container::iterator __i)
//     noexcept
//         -> row_iterator<typename _Container::iterator>
//     { return row_iterator<typename _Container::iterator, _Container>(__i); }



//     
//     /// \brief Makes a new %row_iterator.
//     /// 
//     /// \details An adaptor for making C-style array pointers 
//     /// into %row_iterators.
//     /// 
//     /// \code {.cpp}
//     /// auto it =  make_normal<int*, int[]>(arr);
//     /// \endcode
//     /// 
//     /// \tparam _Iterator 
//     /// \tparam _Container 
//     /// \param __i 
//     /// \returns constexpr auto -> row_iterator<_Iterator, _Container> 
//     /// 
//     /// [constexpr]
//     /// [noexcept]
//    
//     template<typename _Iterator, typename _Container>
//     constexpr auto
//     make_column(_Iterator __i)
//     noexcept
//         -> row_iterator<_Iterator, _Container>
//     { return row_iterator<_Iterator, _Container>(__i); }


// #   if __cplusplus >= 201703L /// C++17
//     
//     /// \brief Makes a new %row_iterator.
//     /// 
//     /// \details An adaptor for making STL container iterators
//     /// into %row_iterators using C++17 type deduction.
//     /// 
//     /// \code {.cpp}
//     /// auto it = make_normal(c, c.begin());
//     /// \endcode
//     /// 
//     /// \notes \param __c has the attribute [[maybe_unused]]
//     /// 
//     /// \tparam _Container 
//     /// \tparam _Iterator 
//     /// \param __c 
//     /// \param __i 
//     /// \returns constexpr auto -> row_iterator<_Iterator, _Container> 
//     /// 
//     /// [constexpr]
//     /// [noexcept]
//    
//     template<typename _Container, typename _Iterator>
//     constexpr auto
//     make_column([[maybe_unused]] const _Container& __c, _Iterator __i)
//     noexcept
//         -> row_iterator<_Iterator, _Container>
//     { return row_iterator<_Iterator, _Container>(__i); }
// 
// #   endif /// __cplusplus >= 201703L

} /// namespace cortex


#   endif /// __cplusplus >= 201402L

#endif /// CORTEX_ROW_ITERATOR_HPP