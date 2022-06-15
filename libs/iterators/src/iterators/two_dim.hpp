/// -*- C++ -*- Header compatibility <two_dim.hpp>

/// @file two_dim_iterator.hpp
/// @author Tyler Swann (oraqlle@github.com)
/// @brief Two Dimensional Iterator Base Class
/// @version 1.0.1
/// @date 2022-05-20
/// 
/// @ingroup %iterators
/// 
/// @copyright Copyright (c) 2022


#ifndef CORTEX_TWO_DIM_ITERATOR_HPP
#   define CORTEX_TWO_DIM_ITERATOR_HPP 1


#include <utility>
#include <type_traits>
#include <iterator>

#if __cpp_lib_three_way_comparison
#   include <compare>
#endif /// __cpp_lib_three_way_comparison

#if __cpp_concepts >= 201907L
#   include <concepts>
#endif /// __cpp_concepts >= 201907L


#   if __cplusplus >= 201402L

namespace cortex
{    
    /// @brief Two Dimensional Iterator
    ///
    /// @details The base class for a two dimensional iterator. 
    /// Constructs the underlying iterator and the given position 
    /// of the iterator and dimensions of in which it occupies.
    ///
    /// @note Potential problem incrementing or decrementing the 
    /// default constructed object as it refers to the the default
    /// constructed iterator type and causes segmentation fault on
    /// dereference.
    /// 
    /// @tparam _Iterator 
    template<typename _Iterator>
    class two_dim_iterator
    {
    protected:

        using __traits_type                     = std::iterator_traits<_Iterator>;

    public:
        using iterator_type                     = _Iterator;
        using iterator_category                 = std::bidirectional_iterator_tag;

// #if __cpp_concepts >= 201907L
//         using iterator_concept                  = std::bidirectional_iterator;
// #endif // __cpp_concepts >= 201907L

        using size_type                         = std::size_t;
        using value_type                        = typename __traits_type::value_type;
        using difference_type                   = typename __traits_type::difference_type;
        using pointer                           = typename __traits_type::pointer;
        using reference                         = typename __traits_type::reference;


    protected:
        iterator_type m_current;
        size_type m_ridx;
        size_type m_cidx;
        size_type m_rows;
        size_type m_columns;


    public:

        /// @brief Deleteted Constructors
        ///
        /// @details The move, iterator_type copy and 
        /// iterator_type move constructors and assignemnts are 
        /// deleted as these constructors are illogical for iterator 
        /// types and copying just the underlying iterator does 
        /// not give sufficitent information to the iterator. 
        ///
        constexpr two_dim_iterator(two_dim_iterator&&) = delete;
        constexpr two_dim_iterator(const iterator_type& __other) = delete;
        constexpr two_dim_iterator& operator= (two_dim_iterator&&) = delete;
        constexpr two_dim_iterator& operator= (const iterator_type&) = delete;
        constexpr two_dim_iterator& operator= (iterator_type&&) = delete;


        /// @brief Default Constructor
        ///
        /// @details Default constructor used default definition. 
        constexpr two_dim_iterator() noexcept
        : m_current(iterator_type())
        , m_ridx(size_type())
        , m_cidx(size_type())
        , m_rows(size_type())
        , m_columns(size_type())
        { }


        /// @brief Copy Constructor
        constexpr two_dim_iterator(const two_dim_iterator& __other) noexcept
        : m_current(__other.base()) 
        , m_ridx(__other.m_ridx)
        , m_cidx(__other.m_cidx)
        , m_rows(__other.m_rows)
        , m_columns(__other.m_columns)
        { }


        /// @brief Explicit Value Constructor
        /// 
        /// @details Constructs the iterator by copying and
        /// instance of the underlying iterator and the given
        /// position of the iterator and dimensions in which
        /// it occupies and can move.
        ///
        /// @param ptr type: iterator_type | qualifiers: [const, ref]
        /// @param ridx type: size_type 
        /// @param cidx type: size_type
        /// @param rows type: size_type
        /// @param columns type: size_type
        explicit constexpr two_dim_iterator(const iterator_type& ptr
                                          , size_type ridx, size_type cidx
                                          , size_type rows, size_type columns) noexcept
        : m_current(ptr)
        , m_ridx(ridx)
        , m_cidx(cidx)
        , m_rows(rows)
        , m_columns(columns)
        { }


        /// @brief Copy Assignment
        /// 
        /// @param __other type: two_dim_iterator | qualifiers: [const, ref]
        /// @return constexpr two_dim_iterator& 
        constexpr two_dim_iterator& operator= (const two_dim_iterator& __other) noexcept
        { 
            m_current = __other.base();

            m_ridx = __other.m_ridx;
            m_cidx = __other.m_cidx;

            m_rows = __other.m_rows;
            m_columns = __other.m_columns;

            return *this;
        }

        
        /// @brief Deference Operator
        ///
        /// @details Dereferences the underlying iterator. 
        /// 
        /// @return reference
        constexpr reference operator* () noexcept
        { return *m_current; }


        /// @brief Deference Operator
        ///
        /// @details Dereferences the underlying iterator
        /// and returns a constant value.
        /// 
        /// @return constexpr reference 
        constexpr reference operator* () const noexcept
        { return *m_current; }


        /// @brief Indirection Operator 
        ///
        /// @details Returns a pointer to the underlying iterator.
        /// 
        /// @requires The underlying iterator must be a pointer type
        /// or support the indirectin operator itself.
        /// 
        /// @return constexpr pointer 
        constexpr pointer operator-> () noexcept
#   if __cplusplus > 201703L && __cpp_concepts >= 201907L
            requires std::is_pointer_v<iterator_type>
	     || requires(const iterator_type __i) { __i.operator->(); }
#   endif
        { return _S_to_pointer(m_current); }


        /// @brief Indirection Operator
        ///
        /// @details Returns a pointer to the underlying iterator
        /// and returns a constant value.
        ///
        /// @requires The underlying iterator must be a pointer type
        /// or support the indirectin operator itself.
        ///
        /// @return constexpr pointer
        constexpr pointer operator-> () const noexcept
#   if __cplusplus > 201703L && __cpp_concepts >= 201907L
            requires std::is_pointer_v<iterator_type>
	     || requires(const iterator_type __i) { __i.operator->(); }
#   endif
        { return _S_to_pointer(m_current); }


        /// @brief Base Iterator
        /// 
        /// @details Returns the underlying iterator. 
        /// 
        /// @return constexpr const iterator_type& 
        constexpr const iterator_type& base() const noexcept
        { return m_current; }


        /// @brief Occupied Rows
        ///
        /// @details Returns the number of rows the iterator
        /// moves through. 
        /// 
        /// @return constexpr size_type 
        constexpr size_type rows() const noexcept
        { return m_rows; }


        /// @brief Occupied Columns
        ///
        /// @details Returns the number of columns the iterator
        /// moves through.
        ///
        /// @return constexpr size_type
        constexpr size_type columns() const noexcept
        { return m_columns; }


        /// @brief Row Index
        ///
        /// @details Returns the current row index of the iterator.
        ///
        /// @return constexpr size_type
        constexpr size_type row_index() const noexcept
        { return m_ridx; }


        /// @brief Column Index
        ///
        /// @details Returns the current column index of the iterator.
        ///
        /// @return constexpr size_type
        constexpr size_type column_index() const noexcept
        { return m_cidx; }

protected:

        /// @brief Internal Index
        ///
        /// @details Returns the current offset of the iterator 
        /// from some starting posistion.
        ///
        /// @return constexpr size_type
        constexpr auto _M_index(auto row, auto column) const noexcept
            -> decltype(m_columns * row + column)
        { return m_columns * row + column;}
    
    private:

        /// @brief Pointer Retrieval
        ///
        /// @details Returns a pointer to the underlying iterator.
        ///
        /// @note This function is only available if the underlying
        /// iterator is a pointer type.
        ///
        /// @tparam _Tp
        /// @return static constexpr _Tp*
        template<typename _Tp>
	    static constexpr _Tp*
	    _S_to_pointer(_Tp* __p)
        { return __p; }


        /// @brief Pointer Retrieval
        ///
        /// @details Returns a pointer to the underlying iterator.
        ///
        /// @note This function is only available if the underlying
        /// iterator is class type and thus calls the tyoes indirection
        /// operator.
        ///
        /// @tparam _Tp
        /// @return static constexpr pointer
        template<typename _Tp>
        static constexpr pointer
	    _S_to_pointer(_Tp __t)
        { return __t.operator->(); }
    }; /// class two_dim_iterator


#if __cpp_lib_three_way_comparison /// C++20

    /// @brief Equality Operator Overload.
    /// 
    /// @details Performs an equality comparison of two 
    /// %two_dim_iterator's whose _Iterator types can be 
    /// different but of they share the same _Container 
    /// type. 
    /// 
    /// @requires 
    /// That the underlying _Iterator types are equality comparable.
    /// @code {.cpp}
    /// { __lhsI == __rhsI } -> bool
    /// @endcode
    /// 
    /// @exception 
    /// Ensures that __lhs.base() == __rhs.base() is noexcept.
    /// 
    /// @note _IteratorL can equal _IteratorR.
    /// 
    /// @tparam _IteratorL 
    /// @tparam _IteratorR 
    /// @tparam _Container 
    /// @param __lhs 
    /// @param __rhs 
    /// @return constexpr true
    /// @return constexpr false
    /// 
    /// [constexpr]
    /// [noexcept.noexcept-clause]
    template<typename _IteratorL, typename _IteratorR>
        requires requires (_IteratorL __lhsI, _IteratorR __rhsI)
        { { __lhsI == __rhsI } -> std::convertible_to<bool>; }
    constexpr bool 
    operator== (const two_dim_iterator<_IteratorL>& __lhs, 
                    const two_dim_iterator<_IteratorR>& __rhs) 
        noexcept (noexcept(__lhs.base() == __rhs.base()))
    { return __lhs.base() == __rhs.base(); }



    /// @brief Spaceship Operator Overload.
    /// 
    /// @details Performs a 3-way comparison of two 
    /// %two_dim_iterator's whose _Iterator types can be 
    /// different but of they share the same _Container 
    /// type. 
    /// 
    /// @exception @code {.cpp}
    /// code noexcept (noexcept(__lhs.base() <=> __rhs.base()))
    /// @endcode
    /// Ensures that the 3-way comparison of __lhs.base() and 
    /// __rhs.base() is noexcept.
    /// 
    /// @note _IteratorL can equal _IteratorR.
    /// 
    /// @tparam _IteratorL 
    /// @tparam _IteratorR 
    /// @tparam _Container 
    /// @param __lhs 
    /// @param __rhs 
    /// @return constexpr auto of [std::strong_ordering]
    ///                         : [std::weak_ordering]
    ///                         : [std::partial_ordering]
    /// 
    /// [constexpr]
    /// [noexcept.noexcept-clause]
    template<typename _IteratorL, typename _IteratorR>
    constexpr auto
    operator<=> (const two_dim_iterator<_IteratorL>& __lhs, 
                 const two_dim_iterator<_IteratorR>& __rhs)
        noexcept (noexcept(__lhs.base() <=> __rhs.base()))
    { return std::compare_three_way{}(__lhs.base(), __rhs.base()); }


#else // ! C++20


    /// @brief Equality Operator Overload.
    /// 
    /// @details Performs an equality comparison of two 
    /// %two_dim_iterator's whose _Iterator types can be
    /// different but of they share the same _Container
    /// type. 
    /// 
    /// @tparam _IteratorL 
    /// @tparam _IteratorR 
    /// @tparam _Container 
    /// @param __lhs 
    /// @param __rhs 
    /// @return constexpr inline true
    /// @return constexpr inline false
    /// 
    /// [constexpr]
    /// [noexcept]
    template<typename _IteratorL, typename _IteratorR>
    constexpr inline bool
    operator== (const two_dim_iterator<_IteratorL>& __lhs, 
                const two_dim_iterator<_IteratorR>& __rhs)
        noexcept
    { return __lhs.base() == __rhs.base(); }


    /// @brief Equality Operator Overload.
    /// 
    /// @details Performs an equality comparison of two 
    /// %two_dim_iterator's whose _Iterator types and 
    /// _Container type are the same. 
    /// 
    /// @tparam _Iterator
    /// @tparam _Container 
    /// @param __lhs type: two_dim_iterator<_Iterator> | qualifier: [const, ref]
    /// @param __rhs type: two_dim_iterator<_Iterator> | qualifier: [const, ref]
    /// @return constexpr inline true
    /// @return constexpr inline false
    template<typename _Iterator>
    constexpr inline bool
    operator== (const two_dim_iterator<_Iterator>& __lhs, 
                const two_dim_iterator<_Iterator>& __rhs)
        noexcept
    { return __lhs.base() == __rhs.base(); } 


    /// @brief Inequality Operator Overload.
    /// 
    /// @details Performs an equality comparison of two 
    /// %two_dim_iterator's whose _Iterator types can be
    /// different but of they share the same _Container
    /// type.  
    /// 
    /// @tparam _IteratorL
    /// @tparam _IteratorR
    /// @tparam _Container 
    /// @param __lhs 
    /// @param __rhs 
    /// @return constexpr inline true
    /// @return constexpr inline false
    template<typename _IteratorL, typename _IteratorR>
    constexpr inline bool
    operator!= (const two_dim_iterator<_IteratorL>& __lhs, 
                const two_dim_iterator<_IteratorR>& __rhs)
    noexcept
    { return __lhs.base() != __rhs.base(); }


    /// @brief Inequality Operator Overload.
    /// 
    /// @details Performs an inequality comparison of two 
    /// %two_dim_iterator's whose _Iterator types and 
    /// _Container type are the same. 
    /// 
    /// @tparam _Iterator
    /// @tparam _Container 
    /// @param __lhs 
    /// @param __rhs 
    /// @return constexpr inline true
    /// @return constexpr inline false
    template<typename _Iterator>
    constexpr inline bool
    operator!= (const two_dim_iterator<_Iterator>& __lhs, 
                const two_dim_iterator<_Iterator>& __rhs)
    noexcept
    { return __lhs.base() != __rhs.base(); }


    /// @brief Less-than Operator Overload.
    /// 
    /// @details Performs an less-than comparison of two 
    /// %two_dim_iterator's whose _Iterator types can be
    /// different but of they share the same _Container
    /// type. 
    /// 
    /// @tparam _IteratorL 
    /// @tparam _IteratorR 
    /// @tparam _Container 
    /// @param __lhs 
    /// @param __rhs 
    /// @return constexpr inline true
    /// @return constexpr inline false
    template<typename _IteratorL, typename _IteratorR>
    constexpr inline bool
    operator< (const two_dim_iterator<_IteratorL>& __lhs, 
                const two_dim_iterator<_IteratorR>& __rhs)
    noexcept
    { return __lhs.base() < __rhs.base(); }


    /// @brief Less-than Operator Overload.
    /// 
    /// @details Performs an less-than comparison of two 
    /// %two_dim_iterator's whose _Iterator types and 
    /// _Container type are the same. 
    /// 
    /// @tparam _Iterator
    /// @tparam _Container 
    /// @param __lhs 
    /// @param __rhs 
    /// @return constexpr inline true
    /// @return constexpr inline false
    template<typename _Iterator>
    constexpr inline bool
    operator< (const two_dim_iterator<_Iterator>& __lhs, 
                const two_dim_iterator<_Iterator>& __rhs)
    noexcept
    { return __lhs.base() < __rhs.base(); }


    /// @brief Greater-than Operator Overload.
    /// 
    /// @details Performs an greater-than comparison of two 
    /// %two_dim_iterator's whose _Iterator types can be
    /// different but of they share the same _Container
    /// type. 
    /// 
    /// @tparam _IteratorL 
    /// @tparam _IteratorR 
    /// @tparam _Container 
    /// @param __lhs 
    /// @param __rhs 
    /// @return constexpr inline true
    /// @return constexpr inline false
    template<typename _IteratorL, typename _IteratorR>
    constexpr inline bool
    operator> (const two_dim_iterator<_IteratorL>& __lhs, 
                const two_dim_iterator<_IteratorR>& __rhs)
    noexcept
    { return __lhs.base() > __rhs.base(); }


    /// @brief Greater-than Operator Overload.
    /// 
    /// @details Performs an greater-than comparison 
    /// of two %two_dim_iterator's whose _Iterator types 
    /// and _Container type are the same. 
    /// 
    /// @tparam _Iterator
    /// @tparam _Container 
    /// @param __lhs 
    /// @param __rhs 
    /// @return constexpr inline true
    /// @return constexpr inline false
    template<typename _Iterator>
    constexpr inline bool
    operator> (const two_dim_iterator<_Iterator>& __lhs, 
                const two_dim_iterator<_Iterator>& __rhs)
    noexcept
    { return __lhs.base() > __rhs.base(); }


    /// @brief Less-than-or-Equal Operator Overload.
    /// 
    /// @details Performs an less-than-or-equal comparison 
    /// of two %two_dim_iterator's whose _Iterator types can 
    /// be different but of they share the same _Container
    /// type. 
    /// 
    /// @tparam _IteratorL 
    /// @tparam _IteratorR 
    /// @tparam _Container 
    /// @param __lhs 
    /// @param __rhs 
    /// @return constexpr inline true
    /// @return constexpr inline false
    template<typename _IteratorL, typename _IteratorR>
    constexpr inline bool
    operator<= (const two_dim_iterator<_IteratorL>& __lhs, 
                const two_dim_iterator<_IteratorR>& __rhs)
    noexcept
    { return __lhs.base() <= __rhs.base(); }


    /// @brief Less-than-or-Equal Operator Overload.
    /// 
    /// @details Performs an less-than-or-equal comparison 
    /// of two %two_dim_iterator's whose _Iterator types and 
    /// _Container type are the same. 
    /// 
    /// @tparam _Iterator
    /// @tparam _Container 
    /// @param __lhs 
    /// @param __rhs 
    /// @return constexpr inline true
    /// @return constexpr inline false
    template<typename _Iterator>
    constexpr inline bool
    operator<= (const two_dim_iterator<_Iterator>& __lhs, 
                const two_dim_iterator<_Iterator>& __rhs)
    noexcept
    { return __lhs.base() <= __rhs.base(); }


    /// @brief Greater-than-or-Equal Operator Overload.
    /// 
    /// @details Performs an greater-than-or-equal comparison 
    /// of two %two_dim_iterator's whose _Iterator types can 
    /// be different but of they share the same _Container
    /// type. 
    /// 
    /// @tparam _IteratorL 
    /// @tparam _IteratorR 
    /// @tparam _Container 
    /// @param __lhs 
    /// @param __rhs 
    /// @return constexpr inline true
    /// @return constexpr inline false
    template<typename _IteratorL, typename _IteratorR>
    constexpr inline bool
    operator>= (const two_dim_iterator<_IteratorL>& __lhs, 
                const two_dim_iterator<_IteratorR>& __rhs)
    noexcept
    { return __lhs.base() >= __rhs.base(); }


    /// @brief Greater-than-or-Equal Operator Overload.
    /// 
    /// @details Performs an greater-than-or-equal comparison 
    /// of two %two_dim_iterator's whose _Iterator types and 
    /// _Container type are the same. 
    /// 
    /// @tparam _Iterator
    /// @tparam _Container 
    /// @param __lhs 
    /// @param __rhs 
    /// @return constexpr inline true
    /// @return constexpr inline false
    template<typename _Iterator>
    constexpr inline bool
    operator>= (const two_dim_iterator<_Iterator>& __lhs, 
                const two_dim_iterator<_Iterator>& __rhs)
    noexcept
    { return __lhs.base() >= __rhs.base(); }


#endif // __cpp_lib_three_way_comparison



    /**
     * @brief Difference Operator Overload.
     * 
     * @details Performs a difference operation between 
     * two %two_dim_iterator's whose _Iterator types can 
     * be different but share the same _Container type.
     * 
     * @tparam _IteratorL 
     * @tparam _IteratorR
     * @tparam _Container 
     * @param __lhs 
     * @param __rhs 
     * @if __cplusplus >= 201103L
     * @return constexpr inline auto -> decltype(__lhs.base() - __rhs.base())
     * @ifnot __cplusplus >= 201103L
     * @return inline typename two_dim_iterator<_IteratorL, _Container>::difference_type
     * @endif
     * 
     * [constexpr]
     * [noexcept]
     */
//     template<typename _IteratorL, typename _IteratorR>
// #if __cplusplus >= 201103L // C++11  
//     constexpr inline auto
//     operator- (const two_dim_iterator<_IteratorL>& __lhs, 
//                 const two_dim_iterator<_IteratorR>& __rhs) 
//         noexcept
//         -> decltype(__lhs.base() - __rhs.base())
// #else // ! C++11
//     inline typename two_dim_iterator<_IteratorL>::difference_type
//     operator- (const two_dim_iterator<_IteratorL>& __lhs, 
//                 const two_dim_iterator<_IteratorR>& __rhs) 
// #endif // __cplusplus >= 201103L
//     { return __lhs.base() - __rhs.base(); }



    /**
     * @brief Difference Operator Overload.
     * 
     * @details Performs a difference operation between
     * two %two_dim_iterator's whose _Iterator types and
     * _Container type are the same.
     * 
     * @tparam _Iterator 
     * @tparam _Container 
     * @param __lhs 
     * @param __rhs 
     * @return constexpr inline typename two_dim_iterator<_Iterator, _Container>::difference_type 
     * 
     * [constexpr]
     * [noexcept]
     */
    // template<typename _Iterator>
    // constexpr inline typename two_dim_iterator<_Iterator>::difference_type
    // operator- (const two_dim_iterator<_Iterator>& __lhs, 
    //             const two_dim_iterator<_Iterator>& __rhs)
    // noexcept
    // { return __lhs.base() - __rhs.base(); }
} // namespace cortex


#   endif // __cplusplus >= 201402L

#endif // CORTEX_TWO_DIM_ITERATOR_HPP