/// -*- C++ -*- Header compatiability <reverse.hpp>

/// \brief An iterator for iterating through a container in 
/// reverse order.
/// \file reverse.hpp
/// \author Tyler Swann (oraqlle@github.com)
/// \version 1.0.0
/// \date 2022-03-31
/// 
/// \copyright Copyright (c) 2022
/// 


#ifndef CORTEX_REVERSE_ITERATOR_HPP
#   define CORTEX_REVERSE_ITERATOR_HPP 


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

    
    /// \brief Reverse Iterator 
    /// 
    /// \details This iterator applies the inverse operation to
    /// an underlying iterator of type _Iterator, thus allowing 
    /// for reversed traversel through a container.
    /// 
    /// \tparam _Iterator 
    template<typename _Iterator>
    class reverse_iterator
    {
    protected:
        _Iterator m_current;

        using __traits_type                     = typename std::iterator_traits<_Iterator>;

    public:
        using iterator_type                     = _Iterator;

#if __cpp_concepts >= 201907L
        using iterator_concept                  = std::random_access_iterator_tag;
#endif /// __cpp_concepts >= 201907L

        using iterator_category                 = typename __traits_type::iterator_category;
        using value_type                        = typename __traits_type::value_type;
        using difference_type                   = typename __traits_type::difference_type;
        using pointer                           = typename __traits_type::pointer;
        using reference                         = typename __traits_type::reference;


        
        /// \brief Default Constructor
        /// 
        /// \details Initialises m_current to the default value of 
        /// the type _Iterator. 
        /// 
        /// [constexpr]
        /// [noexcept]
        
        constexpr reverse_iterator() noexcept
        : m_current(iterator_type())
        {}
            

        
        /// \brief Copy Constructor. 
        /// 
        /// \details Uses copy semantics to initialise m_current from
        /// an object as the same type as iterator_type. Because the 
        /// the underlying types must be the same, m_current can be 
        /// directly initialised from __other.
        /// 
        /// \param __other const reference to an object of type iterator_type.
        /// 
        /// [explicit]
        /// [constexpr]
        /// [noexcept]
        
        explicit constexpr reverse_iterator(const iterator_type& __other) noexcept
        : m_current(__other) { }


        
        /// \brief Copy Constructor.
        /// 
        /// \details Uses copy semantics to initialise m_current from
        /// another %reverse_iterator object. Uses the \code {.cpp}
        /// %reverse_iterator::base()
        /// \endcode
        /// method to access __other's underlying iterator. 
        /// 
        /// \param __other const reference to a %reverse_iterator object.
        /// 
        /// [constexpr]
        /// [noexcept]
        
        constexpr reverse_iterator(const reverse_iterator& __other) noexcept
        : m_current(__other.base()) { }
        
        
        
        
        /// \brief Copy Assignment.
        /// 
        /// \details Uses copy semantics to assign m_current to the
        /// underlying iterator of __other. Uses the \code {.cpp}
        /// %reverse_iterator::base()
        /// \endcode
        /// method to access __other's underlying iterator.
        /// Returns a reference to this.
        /// 
        /// \param __other
        /// \return constexpr reverse_iterator&
        /// 
        /// [constexpr]
        /// [noexcept]
        /// [operator.assigment]
        
        constexpr reverse_iterator& operator= (const reverse_iterator& __other) noexcept
        { 
            m_current = __other.base(); 
            return *this;
        }



        
        /// \brief Copy Assignment.
        /// 
        /// \details Uses copy semantics to assign m_current to 
        /// __other. __other must be of type  terator_type.
        /// Returns a reference to this.
        /// 
        /// \param __other
        /// \return constexpr reverse_iterator&
        /// 
        /// [constexpr]
        /// [noexcept]
        /// [operator.assigment]
        
        constexpr reverse_iterator& operator= (const iterator_type& __other) noexcept
        { 
            m_current = __other; 
            return *this;
        }
        
        
        
        
        /// \brief Bool Operator Overload.
        /// 
        /// \details Returns true if m_current does not point
        /// to a valid address. Returns a boolean.
        /// 
        /// \return true 
        /// \return false 
        /// 
        /// [explicit]
        /// [constexpr]
        /// [trailing.const]
        /// [noexcept]
        
        explicit constexpr operator bool() const noexcept
        { return (m_current.base()) ? true : false; } 


        
        /// \brief Dereference Operator Overload. 
        /// 
        /// \details Creates a tempory value of type
        /// iterator_type equal to m_current. Prefix 
        /// decrements and
        /// 
        /// \return constexpr reference (T&)
        /// 
        /// [constexpr]
        /// [noexcept]
        /// [trailing.const]
        
        constexpr reference operator* () const noexcept
        { 
            iterator_type __tmp = m_current;
            return *--__tmp;
        }


        
        /// \brief Arrow Deference Operator Overload. 
        /// 
        /// \details Creates a tempory value of type
        /// iterator_type equal to m_current. Prefix 
        /// decrements is applied to the tempory variable
        /// before passing it to _S_to_pointer. The 
        /// return value of _S_to_pointer is returned 
        /// to the caller.
        /// 
        /// \requires The type _Iterator meets the conditions
        /// a being a pointer or that some variable, __t
        /// supports __t.operator->().
        /// 
        /// \return constexpr pointer (T*)
        /// 
        /// [constexpr]
        /// [noexcept]
        /// [trailing.const]
        
        constexpr pointer operator-> () const noexcept
#   if __cplusplus > 201703L && __cpp_concepts >= 201907L
        requires std::is_pointer_v<_Iterator>
        || requires(const _Iterator& __t) { __t.operator->(); }
#   endif /// __cplusplus > 201703L && __cpp_concepts >= 201907L
        {
            iterator_type __tmp = m_current;
            --__tmp;
            return _S_to_pointer(__tmp);
        }


        
        /// \brief Prefix Increment Operator Overload.
        /// 
        /// \details Applies the prefix decrement operator to
        /// m_current and returns a reference to this.
        /// 
        /// \return constexpr reverse_iterator&
        /// 
        /// [constexpr]
        /// [noexcept]
        
        constexpr reverse_iterator& operator++ () noexcept
        {
            --m_current;
            return *this;
        }


        
        /// \brief Postfix Increment Operator Overload.
        /// 
        /// \details Constructs tempory variable of type
        /// %reverse_iterator from *this and applies the 
        /// prefix decrement operator on m_current. It 
        /// then returns a newly constructed %reverse_iterator 
        /// from the tempory variable.
        /// 
        /// \return constexpr reverse_iterator
        /// 
        /// [constexpr]
        /// [noexcept] 
        
        constexpr reverse_iterator operator++ (int) noexcept
        { 
            reverse_iterator __tmp = *this; 
            --m_current;
            return __tmp;
        }


        
        /// \brief Prefix Decrement Operator Overload.
        /// 
        /// \details Applies the prefix increment operator to
        /// m_current and returns a reference to this.
        /// 
        /// \return constexpr reverse_iterator&
        /// 
        /// [constexpr]
        /// [noexcept]
        
        constexpr reverse_iterator& operator-- () noexcept
        {
            ++m_current;
            return *this;
        }


        
        /// \brief Postfix Decrement Operator Overload.
        /// 
        /// \details Constructs tempory variable of type
        /// %reverse_iterator from *this and applies the 
        /// prefix decrement operator on m_current. It 
        /// then returns a newly constructed %reverse_iterator 
        /// from the tempory variable. 
        /// 
        /// \return constexpr reverse_iterator
        /// 
        /// [constexpr]
        /// [noexcept] 
        
        constexpr reverse_iterator operator-- (int) noexcept
        { 
            reverse_iterator __tmp = *this; 
            ++m_current;
            return __tmp;
        }


        
        /// \brief Subscript Operator Overload.
        /// 
        /// \details Accesses the element at an offset to m_current's
        /// location in memory and returns a reference to the value
        /// stored at that location.
        /// 
        /// \param __n 
        /// \return constexpr reference (T&)
        /// 
        /// [constexpr]
        /// [noexcept]
        /// ![range.validation]
        
        constexpr reference& operator[] (difference_type __n) noexcept
        { return *(*this + __n); }


         
        /// \brief Additive Assignment Operator Overload. 
        ///
        /// \details Decreases the m_current's pointer value by 
        /// __step and assigns m_current the new pointer value 
        /// and returns a reference to this. 
        /// 
        /// \param __step 
        /// \return constexpr reverse_iterator&
        /// 
        /// [constexpr]
        /// [noexcept]
        
        constexpr reverse_iterator& operator+= (difference_type __step) noexcept
        {
            m_current -= __step;
            return *this;
        }


        
        /// \brief Subtraction Assignment Operator Overload. 
        ///
        /// \details Increases the m_current's pointer value by 
        /// __step and assigns m_current the new pointer value 
        /// and returns a reference to this. 
        /// 
        /// \param __step 
        /// \return constexpr reverse_iterator&
        /// 
        /// [constexpr]
        /// [noexcept]
        
        constexpr reverse_iterator& operator-= (difference_type __step) noexcept
        {
            m_current += __step;
            return *this;
        }


         
        /// \brief Addition Operator Overload.
        /// 
        /// \details Constructs a new iterator from the substitution 
        /// of m_current and __step. 
        /// 
        /// \param __step 
        /// \return constexpr reverse_iterator 
        /// 
        /// [constexpr]
        /// [noexcept]
        
        constexpr reverse_iterator operator+ (difference_type __step) const noexcept
        { return reverse_iterator(m_current - __step); }


        
        /// \brief Subtraction Operator Overload.
        /// 
        /// \details Constructs a new iterator from the addition 
        /// of m_current and __step. 
        /// 
        /// \param __step 
        /// \return constexpr reverse_iterator 
        /// 
        /// [constexpr]
        /// [noexcept]
        
        constexpr reverse_iterator operator- (difference_type __step) const noexcept
        { return reverse_iterator(m_current + __step); }


        
        /// \brief Base Member Access. 
        /// 
        /// \details Returns a raw copy of m_current.
        /// 
        /// \return constexpr iterator_type (_Iterator)
        /// 
        /// [constexpr]
        /// [noexcept]
        /// [trailing.const]
        
        constexpr iterator_type base() const noexcept
        { return m_current; }



    private:
        
        /// \brief Returns a pointer.
        /// 
        /// \tparam _Tp 
        /// \param __p 
        /// \return static constexpr _Tp* 
        /// 
        /// \noop
        /// 
        /// [static]
        /// [constexpr]
        
        template<typename _Tp>
        static constexpr _Tp* _S_to_pointer(_Tp* __p)
        { return __p; }



        
        /// \brief Returns a pointer.
        /// 
        /// \details If a object is passed, the object's arrow
        /// operator is called and the result is returned.
        /// 
        /// \tparam _Tp 
        /// \param __t 
        /// \return static constexpr _Tp* 
        /// 
        /// [static]
        /// [constexpr]
        
        template<typename _Tp>
        static constexpr pointer _S_to_pointer(_Tp __t)
        { return __t.operator->(); }

    }; /// class reverse_iterator


#if __cpp_lib_three_way_comparison /// C++20

    
    /// \brief Equality Operator Overload.
    /// 
    /// \details Performs an equality comparison of two 
    /// %reverse_iterator's whose _Iterator types can be 
    /// different but of they share the same _Container 
    /// type. 
    /// 
    /// \requires \code {.cpp}
    /// { __lhsI == __rhsI } -> bool
    /// \endcode
    /// That the underlying _Iterator types are equality comparable.
    /// 
    /// \exception \code {.cpp}
    /// code noexcept (noexcept(__lhs.base() == __rhs.base()))
    /// \endcode
    /// Ensures that the comparison of __lhs.base() and 
    /// __rhs.base() is noexcept.
    /// 
    /// \note _IteratorL can equal _IteratorR.
    /// 
    /// \tparam _IteratorL 
    /// \tparam _IteratorR 
    /// \tparam _Container 
    /// \param __lhs 
    /// \param __rhs 
    /// \return constexpr true
    /// \return constexpr false
    /// 
    /// [constexpr]
    /// [noexcept.noexcept-clause]
    
    template<typename _IteratorL, typename _IteratorR>
        requires requires (_IteratorL __lhsI, _IteratorR __rhsI)
        { { __lhsI == __rhsI } -> std::convertible_to<bool>; }
    constexpr bool 
    operator== (const reverse_iterator<_IteratorL>& __lhs, 
                    const reverse_iterator<_IteratorR>& __rhs) 
        noexcept (noexcept(__lhs.base() == __rhs.base()))
    { return __lhs.base() == __rhs.base(); }



    
    /// \brief Spaceship Operator Overload.
    /// 
    /// \details Performs a 3-way comparison of two 
    /// %reverse_iterator's whose _Iterator types can be 
    /// different but of they share the same _Container 
    /// type. 
    /// 
    /// \exception \code {.cpp}
    /// code noexcept (noexcept(__lhs.base() <=> __rhs.base()))
    /// \endcode
    /// Ensures that the 3-way comparison of __lhs.base() and 
    /// __rhs.base() is noexcept.
    /// 
    /// \note _IteratorL can equal _IteratorR.
    /// 
    /// \tparam _IteratorL 
    /// \tparam _IteratorR 
    /// \tparam _Container 
    /// \param __lhs 
    /// \param __rhs 
    /// \return constexpr auto of [std::strong_ordering]
    ///                         : [std::weak_ordering]
    ///                         : [std::partial_ordering]
    /// 
    /// [constexpr]
    /// [noexcept.noexcept-clause]
    
    template<typename _IteratorL, typename _IteratorR>
    constexpr auto
    operator<=> (const reverse_iterator<_IteratorL>& __lhs, 
                 const reverse_iterator<_IteratorR>& __rhs)
        noexcept (noexcept(__lhs.base() <=> __rhs.base()))
    { return __lhs.base() <=> __rhs.base(); }


#else /// ! C++20


    
    /// \brief Equality Operator Overload.
    /// 
    /// \details Performs an equality comparison of two 
    /// %reverse_iterator's whose _Iterator types can be
    /// different but of they share the same _Container
    /// type. 
    /// 
    /// \tparam _IteratorL 
    /// \tparam _IteratorR 
    /// \tparam _Container 
    /// \param __lhs 
    /// \param __rhs 
    /// \return constexpr inline true
    /// \return constexpr inline false
    /// 
    /// [constexpr]
    /// [noexcept]
    
    template<typename _IteratorL, typename _IteratorR>
    constexpr inline bool
    operator== (const reverse_iterator<_IteratorL>& __lhs, 
                const reverse_iterator<_IteratorR>& __rhs)
    noexcept
    { return __lhs.base() == __rhs.base(); }



    
    /// \brief Equality Operator Overload.
    /// 
    /// \details Performs an equality comparison of two 
    /// %reverse_iterator's whose _Iterator types and 
    /// _Container type are the same. 
    /// 
    /// \tparam _Iterator
    /// \tparam _Container 
    /// \param __lhs 
    /// \param __rhs 
    /// \return constexpr inline true
    /// \return constexpr inline false
    /// 
    /// [constexpr]
    /// [noexcept]
    
    template<typename _Iterator>
    constexpr inline bool
    operator== (const reverse_iterator<_Iterator>& __lhs, 
                const reverse_iterator<_Iterator>& __rhs)
    noexcept
    { return __lhs.base() == __rhs.base(); } 



    
    /// \brief Inequality Operator Overload.
    /// 
    /// \details Performs an equality comparison of two 
    /// %reverse_iterator's whose _Iterator types can be
    /// different but of they share the same _Container
    /// type.  
    /// 
    /// \tparam _IteratorL
    /// \tparam _IteratorR
    /// \tparam _Container 
    /// \param __lhs 
    /// \param __rhs 
    /// \return constexpr inline true
    /// \return constexpr inline false
    /// 
    /// [constexpr]
    /// [noexcept]
    
    template<typename _IteratorL, typename _IteratorR>
    constexpr inline bool
    operator!= (const reverse_iterator<_IteratorL>& __lhs, 
                const reverse_iterator<_IteratorR>& __rhs)
    noexcept
    { return __lhs.base() != __rhs.base(); }



    
    /// \brief Inequality Operator Overload.
    /// 
    /// \details Performs an inequality comparison of two 
    /// %reverse_iterator's whose _Iterator types and 
    /// _Container type are the same. 
    /// 
    /// \tparam _Iterator
    /// \tparam _Container 
    /// \param __lhs 
    /// \param __rhs 
    /// \return constexpr inline true
    /// \return constexpr inline false
    /// 
    /// [constexpr]
    /// [noexcept]
    
    template<typename _Iterator>
    constexpr inline bool
    operator!= (const reverse_iterator<_Iterator>& __lhs, 
                const reverse_iterator<_Iterator>& __rhs)
    noexcept
    { return __lhs.base() != __rhs.base(); }



    
    /// \brief Less-than Operator Overload.
    /// 
    /// \details Performs an less-than comparison of two 
    /// %reverse_iterator's whose _Iterator types can be
    /// different but of they share the same _Container
    /// type. 
    /// 
    /// \tparam _IteratorL 
    /// \tparam _IteratorR 
    /// \tparam _Container 
    /// \param __lhs 
    /// \param __rhs 
    /// \return constexpr inline true
    /// \return constexpr inline false
    /// 
    /// [constexpr]
    /// [noexcept]
    
    template<typename _IteratorL, typename _IteratorR>
    constexpr inline bool
    operator< (const reverse_iterator<_IteratorL>& __lhs, 
                const reverse_iterator<_IteratorR>& __rhs)
    noexcept
    { return __lhs.base() < __rhs.base(); }



    
    /// \brief Less-than Operator Overload.
    /// 
    /// \details Performs an less-than comparison of two 
    /// %reverse_iterator's whose _Iterator types and 
    /// _Container type are the same. 
    /// 
    /// \tparam _Iterator
    /// \tparam _Container 
    /// \param __lhs 
    /// \param __rhs 
    /// \return constexpr inline true
    /// \return constexpr inline false
    /// 
    /// [constexpr]
    /// [noexcept]
    
    template<typename _Iterator>
    constexpr inline bool
    operator< (const reverse_iterator<_Iterator>& __lhs, 
                const reverse_iterator<_Iterator>& __rhs)
    noexcept
    { return __lhs.base() < __rhs.base(); }



    
    /// \brief Greater-than Operator Overload.
    /// 
    /// \details Performs an greater-than comparison of two 
    /// %reverse_iterator's whose _Iterator types can be
    /// different but of they share the same _Container
    /// type. 
    /// 
    /// \tparam _IteratorL 
    /// \tparam _IteratorR 
    /// \tparam _Container 
    /// \param __lhs 
    /// \param __rhs 
    /// \return constexpr inline true
    /// \return constexpr inline false
    /// 
    /// [constexpr]
    /// [noexcept]
    
    template<typename _IteratorL, typename _IteratorR>
    constexpr inline bool
    operator> (const reverse_iterator<_IteratorL>& __lhs, 
                const reverse_iterator<_IteratorR>& __rhs)
    noexcept
    { return __lhs.base() > __rhs.base(); }



    
    /// \brief Greater-than Operator Overload.
    /// 
    /// \details Performs an greater-than comparison 
    /// of two %reverse_iterator's whose _Iterator types 
    /// and _Container type are the same. 
    /// 
    /// \tparam _Iterator
    /// \tparam _Container 
    /// \param __lhs 
    /// \param __rhs 
    /// \return constexpr inline true
    /// \return constexpr inline false
    /// 
    /// [constexpr]
    /// [noexcept]
    
    template<typename _Iterator>
    constexpr inline bool
    operator> (const reverse_iterator<_Iterator>& __lhs, 
                const reverse_iterator<_Iterator>& __rhs)
    noexcept
    { return __lhs.base() > __rhs.base(); }



    
    /// \brief Less-than-or-Equal Operator Overload.
    /// 
    /// \details Performs an less-than-or-equal comparison 
    /// of two %reverse_iterator's whose _Iterator types can 
    /// be different but of they share the same _Container
    /// type. 
    /// 
    /// \tparam _IteratorL 
    /// \tparam _IteratorR 
    /// \tparam _Container 
    /// \param __lhs 
    /// \param __rhs 
    /// \return constexpr inline true
    /// \return constexpr inline false
    /// 
    /// [constexpr]
    /// [noexcept]
    
    template<typename _IteratorL, typename _IteratorR>
    constexpr inline bool
    operator<= (const reverse_iterator<_IteratorL>& __lhs, 
                const reverse_iterator<_IteratorR>& __rhs)
    noexcept
    { return __lhs.base() <= __rhs.base(); }



    
    /// \brief Less-than-or-Equal Operator Overload.
    /// 
    /// \details Performs an less-than-or-equal comparison 
    /// of two %reverse_iterator's whose _Iterator types and 
    /// _Container type are the same. 
    /// 
    /// \tparam _Iterator
    /// \tparam _Container 
    /// \param __lhs 
    /// \param __rhs 
    /// \return constexpr inline true
    /// \return constexpr inline false
    /// 
    /// [constexpr]
    /// [noexcept]
    
    template<typename _Iterator>
    constexpr inline bool
    operator<= (const reverse_iterator<_Iterator>& __lhs, 
                const reverse_iterator<_Iterator>& __rhs)
    noexcept
    { return __lhs.base() <= __rhs.base(); }



    
    /// \brief Greater-than-or-Equal Operator Overload.
    /// 
    /// \details Performs an greater-than-or-equal comparison 
    /// of two %reverse_iterator's whose _Iterator types can 
    /// be different but of they share the same _Container
    /// type. 
    /// 
    /// \tparam _IteratorL 
    /// \tparam _IteratorR 
    /// \tparam _Container 
    /// \param __lhs 
    /// \param __rhs 
    /// \return constexpr inline true
    /// \return constexpr inline false
    /// 
    /// [constexpr]
    /// [noexcept]
    
    template<typename _IteratorL, typename _IteratorR>
    constexpr inline bool
    operator>= (const reverse_iterator<_IteratorL>& __lhs, 
                const reverse_iterator<_IteratorR>& __rhs)
    noexcept
    { return __lhs.base() >= __rhs.base(); }



    
    /// \brief Greater-than-or-Equal Operator Overload.
    /// 
    /// \details Performs an greater-than-or-equal comparison 
    /// of two %reverse_iterator's whose _Iterator types and 
    /// _Container type are the same. 
    /// 
    /// \tparam _Iterator
    /// \tparam _Container 
    /// \param __lhs 
    /// \param __rhs 
    /// \return constexpr inline true
    /// \return constexpr inline false
    /// 
    /// [constexpr]
    /// [noexcept]
    
    template<typename _Iterator>
    constexpr inline bool
    operator>= (const reverse_iterator<_Iterator>& __lhs, 
                const reverse_iterator<_Iterator>& __rhs)
    noexcept
    { return __lhs.base() >= __rhs.base(); }


#endif /// __cpp_lib_three_way_comparison



    
    /// \brief Difference Operator Overload.
    /// 
    /// \details Performs a difference operation between 
    /// two %reverse_iterator's whose _Iterator types can 
    /// be different but share the same _Container type.
    /// 
    /// \tparam _IteratorL 
    /// \tparam _IteratorR
    /// \tparam _Container 
    /// \param __lhs 
    /// \param __rhs 
    /// \if __cplusplus >= 201103L
    /// \return constexpr inline auto -> decltype(__lhs.base() - __rhs.base())
    /// \ifnot __cplusplus >= 201103L
    /// \return inline typename reverse_iterator<_IteratorL, _Container>::difference_type
    /// \endif
    /// 
    /// [constexpr]
    /// [noexcept]
    
    template<typename _IteratorL, typename _IteratorR>
#if __cplusplus >= 201103L /// C++11  
    constexpr inline auto
    operator- (const reverse_iterator<_IteratorL>& __lhs, 
                const reverse_iterator<_IteratorR>& __rhs) 
        noexcept
        -> decltype(__lhs.base() - __rhs.base())
#else /// ! C++11
    inline typename reverse_iterator<_IteratorL, _Container>::difference_type
    operator- (const reverse_iterator<_IteratorL, _Container>& __lhs, 
                const reverse_iterator<_IteratorR, _Container>& __rhs) 
#endif /// __cplusplus >= 201103L
    { return __lhs.base() - __rhs.base(); }



    
    /// \brief Difference Operator Overload.
    /// 
    /// \details Performs a difference operation between
    /// two %reverse_iterator's whose _Iterator types and
    /// _Container type are the same.
    /// 
    /// \tparam _Iterator 
    /// \tparam _Container 
    /// \param __lhs 
    /// \param __rhs 
    /// \return constexpr inline typename reverse_iterator<_Iterator, _Container>::difference_type 
    /// 
    /// [constexpr]
    /// [noexcept]
    
    template<typename _Iterator>
    constexpr inline typename reverse_iterator<_Iterator>::difference_type
    operator- (const reverse_iterator<_Iterator>& __lhs, 
                const reverse_iterator<_Iterator>& __rhs)
        noexcept
    { return __lhs.base() - __rhs.base(); }



    
    /// \brief Addition Operator Overload.
    /// 
    /// \details Takes an offset \param __n and a %reverse_iterator 
    /// \param __i. Constructs a new %reverse_iterator by adding
    /// \param __n to \param __i.base().
    /// 
    /// \tparam _Iterator 
    /// \tparam _Container 
    /// \param __n 
    /// \param __i 
    /// \return constexpr inline reverse_iterator<_Iterator, _Container> 
    /// 
    /// [constexpr]
    /// [noexcept]
    
    template<typename _Iterator>
    constexpr inline reverse_iterator<_Iterator>
    operator+ (typename reverse_iterator<_Iterator>::difference_type __n, 
                const reverse_iterator<_Iterator>& __i)
    noexcept
    { return reverse_iterator<_Iterator>(__i.base() - __n); }



    
    /// \brief Makes a new %reverse_iterator.
    /// 
    /// \details An adaptor for turning STL container iterators 
    /// into %reverse_iterators.
    /// 
    /// \code {.cpp}
    /// auto it = make_reverse_iterator<std::container>(c.begin()); 
    /// \endcode 
    /// 
    /// \tparam _Container 
    /// \param __i 
    /// \return constexpr auto -> reverse_iterator<typename _Container::iterator, _Container>
    /// 
    /// [constexpr]
    /// [noexcept]
    
    template<typename _Container>
    constexpr auto
    make_reverse(typename _Container::iterator __i)
    noexcept
        -> reverse_iterator<typename _Container::iterator>
    { return reverse_iterator<typename _Container::iterator>(__i); }



    
    /// \brief Makes a new %reverse_iterator.
    /// 
    /// \details An adaptor for making C-style array pointers 
    /// into %reverse_iterators.
    /// 
    /// \code {.cpp}
    /// auto it =  make_normal<int*, int[]>(arr);
    /// \endcode
    /// 
    /// \tparam _Iterator 
    /// \tparam _Container 
    /// \param __i 
    /// \return constexpr auto -> reverse_iterator<_Iterator, _Container> 
    /// 
    /// [constexpr]
    /// [noexcept]
    
    template<typename _Iterator>
    constexpr auto
    make_reverse(_Iterator __i)
    noexcept
        -> reverse_iterator<_Iterator>
    { return reverse_iterator<_Iterator>(__i); }



#   if __cplusplus >= 201703L /// C++17
    
    /// \brief Makes a new %reverse_iterator.
    /// 
    /// \details An adaptor for making STL container iterators
    /// into %reverse_iterators using C++17 type deduction.
    /// 
    /// \code {.cpp}
    /// auto it = make_normal(c, c.begin());
    /// \endcode
    /// 
    /// \note \param __c has the attribute [[maybe_unused]]
    /// 
    /// \tparam _Container 
    /// \tparam _Iterator 
    /// \param __c 
    /// \param __i 
    /// \return constexpr auto -> reverse_iterator<_Iterator, _Container> 
    /// 
    /// [constexpr]
    /// [noexcept]
    
    template<typename _Container, typename _Iterator>
    constexpr auto
    make_reverse([[maybe_unused]] const _Container& __c, _Iterator __i)
    noexcept
        -> reverse_iterator<_Iterator>
    { return reverse_iterator<_Iterator>(__i); }

#   endif /// __cplusplus >= 201703L
} /// namespace reverse_iterator

#   endif /// __cplusplus >= 201402L

#endif /// CORTEX_REVERSE_ITERATOR_HPP