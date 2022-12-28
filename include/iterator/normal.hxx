// -*- C++ -*- Header compatibility <normal.hxx>

/// \brief Adapts a non-object iterator to an object iterator
/// without changing its semantics.
///
/// Author: Tyler Swann (tyler.swann05@gmail.com)
///
/// Header Version: v1.0.0
///
/// Date: 24-12-2022
///
/// License: MIT
///
/// Copyright: Copyright (c) 2022
/// \file normal.hxx

#ifndef CORTEX_NORMAL_ITERATOR
#define CORTEX_NORMAL_ITERATOR

#include <iterator>
#include <ranges>
#include <type_traits>
#include <utility>

#if __cpp_lib_three_way_comparison
#    include <compare>
#endif  /// __cpp_lib_three_way_comparison

#if __cpp_concepts >= 201907L
#    include <concepts>
#endif  /// __cpp_concepts >= 201907L

#if __cplusplus >= 201402L

namespace cxl
{
    /// \brief Normal Iterator
    ///
    /// \details This iterator is used to adapt non-iterator
    /// objects into objects (ie. pointers). normal_iterators
    /// does not change the semantics of the operators of the
    /// underlying iterator of type Iterator.
    ///
    ///
    /// \tparam Iterator The underlying type of the iterator.
    /// \tparam Container Allows iterators to be of different
    /// type even if the Iterator type is the same.
    template<typename Iterator, typename Container>
    class normal_iterator
    {
    protected:
        Iterator current;

        using iter_traits_type = std::iterator_traits<Iterator>;

    public:
        using iterator_type = Iterator;
        using iterator_category =
            typename iter_traits_type::iterator_category;

#    if __cpp_concepts >= 201907L
        using iterator_concept = std::conditional_t<
            std::random_access_iterator<Iterator>,
            std::random_access_iterator_tag,
            std::conditional_t<
                std::bidirectional_iterator<Iterator>,
                std::bidirectional_iterator_tag,
                std::conditional_t<
                    std::forward_iterator<Iterator>,
                    std::forward_iterator_tag,
                    std::conditional_t<std::input_iterator<Iterator>,
                                       std::input_iterator_tag,
                                       std::output_iterator_tag>>>>;
#    endif  /// __cpp_concepts >= 201907L

        using value_type = typename iter_traits_type::value_type;
        using difference_type =
            typename iter_traits_type::difference_type;
        using pointer   = typename iter_traits_type::pointer;
        using reference = typename iter_traits_type::reference;

        /// \brief Default Constructor
        ///
        /// \details Initialises current to the default value of
        /// the type Iterator.
        constexpr explicit normal_iterator() noexcept
            : current(Iterator()) { }

        /// \brief Copy Constructor.
        ///
        /// \details Uses copy semantics to initialise current from
        /// another normal_iterator of the same underlying iterator
        /// type.
        ///
        /// \param other type: const normal_iterator&
        constexpr explicit normal_iterator(
            const normal_iterator& other) noexcept
            : current(other.base()) { }

        /// \brief Converting Copy Constructor.
        ///
        /// \details Uses copy semantics to initialise current from
        /// another normal_iterator from a different underlying
        /// iterator type.
        ///
        /// \tparam U
        ///
        /// \param other type: const normal_iterator<U, Container>&
        template<typename U>
#    if __cpp_lib_concepts
            requires requires {
                         !std::is_same_v<U, Iterator>&&
                             std::convertible_to<const U&, Iterator>;
                     }
#    endif
        constexpr explicit normal_iterator(
            const normal_iterator<U, Container>& other) noexcept
            : current(other.base()) {
        }

        /// \brief Iterator Copy Constructor.
        ///
        /// \details Uses copy semantics to initialise current from
        /// an object as the same type as iterator_type. Because the
        /// the underlying types must be the same, current can be
        /// directly initialised from other.
        ///
        /// \param other type: const iterator_type&
        constexpr explicit normal_iterator(
            const iterator_type& other) noexcept
            : current(other) { }

        /// \brief Copy Assignment.
        ///
        /// \details Uses copy semantics to initialise current from
        /// another normal_iterator from the same underlying iterator
        /// type. Returns a reference to this.
        ///
        /// \param other type: const normal_iterator&
        constexpr auto
        operator= (const normal_iterator& other) noexcept
            -> normal_iterator& {
            current = other.base();
            return *this;
        }

        /// \brief Converting Copy Assignment.
        ///
        /// \details Uses copy semantics to initialise current from
        /// another normal_iterator from the same underlying iterator
        /// type. Returns a reference to this.
        ///
        /// \param other type: const normal_iterator<U>&
        ///
        /// \returns normal_iterator<U, Container>&
        template<typename U>
#    if __cpp_lib_concepts
            requires requires {
                         !std::is_same_v<U, Iterator>&&
                             std::convertible_to<const U&, Iterator>;
                     }
#    endif
        constexpr auto
        operator= (
            const normal_iterator<U, Container>& other) noexcept
            -> normal_iterator<U, Container>& {
            current = other.base();
            return *this;
        }

        /// \brief Copy Assignment.
        ///
        /// \details Uses copy semantics to assign current to
        /// other. other must be of type iterator_type.
        /// Returns a reference to this.
        ///
        /// \param other type: const iterator_type&
        /// \returns normal_iterator&
        constexpr auto
        operator= (const iterator_type& other) noexcept
            -> normal_iterator& {
            current = other;
            return *this;
        }

        /// \brief Dereference Operator Overload.
        ///
        /// \details Dereferences current and returns a
        /// reference of the value to the caller.
        ///
        /// \returns reference
        constexpr auto
        operator* () noexcept -> reference {
            return *current;
        }

        /// \brief Dereference Operator Overload.
        ///
        /// \details Dereferences current and returns a
        /// reference of the value to the caller.
        ///
        /// \returns reference
        constexpr auto
        operator* () const noexcept -> reference {
            return *current;
        }

        /// \brief Arrow Deference Operator Overload.
        ///
        /// \details Returns a pointer of current, this
        /// allows for access to the internal members if
        /// current is a class or object type through
        /// "indirection chaining".
        ///
        /// \returns pointer
        constexpr auto
        operator->() noexcept -> pointer
#    if __cplusplus > 201703L && __cpp_concepts >= 201907L
            requires std::is_pointer_v<iterator_type> ||
            requires (const iterator_type i) { i.operator->(); }
#    endif
        {
            return _S_to_pointer(current);
        }

        /// \brief Arrow Deference Operator Overload.
        ///
        /// \details Returns a pointer of current, this
        /// allows for access to the internal members if
        /// current is a class or object type through
        /// "indirection chaining".
        ///
        /// \returns pointer
        constexpr auto
        operator->() const noexcept -> pointer
#    if __cplusplus > 201703L && __cpp_concepts >= 201907L
            requires std::is_pointer_v<iterator_type> ||
            requires (const iterator_type i) { i.operator->(); }
#    endif
        {
            return _S_to_pointer(current);
        }

        /// \brief Prefix Increment Operator Overload.
        ///
        /// \details Applies the prefix increment operator to
        /// current and returns a reference to this.
        ///
        /// \returns normal_iterator&
        constexpr auto
        operator++ () noexcept -> normal_iterator& {
            ++current;
            return *this;
        }

        /// \brief Postfix Increment Operator Overload.
        ///
        /// \details Constructs a new iterator from current
        /// while applying the postfix increment operator on
        /// Construction. This effectively increments current
        /// for this while creating a new iterator with its
        /// current equal to the last value of this current.
        ///
        /// \returns normal_iterator
        constexpr auto
        operator++ (int) noexcept -> normal_iterator {
            return normal_iterator(current++);
        }

        /// \brief Prefix Decrement Operator Overload.
        ///
        /// \details Applies the prefix decrement operator to
        /// current and returns a reference to this.
        ///
        /// \returns normal_iterator&
        constexpr auto
        operator-- () noexcept -> normal_iterator& {
            --current;
            return *this;
        }

        /// \brief Postfix Decrement Operator Overload.
        ///
        /// \details Constructs a new iterator from current
        /// while applying the postfix decrement operator on
        /// construction. This effectively decrements current
        /// for this while creating a new iterator with its
        /// current equal to the last value of this current.
        ///
        /// \returns normal_iterator
        constexpr auto
        operator-- (int) noexcept -> normal_iterator {
            return normal_iterator(current--);
        }

        /// \brief Subscript Operator Overload.
        ///
        /// \details Accesses the element at an offset to current's
        /// location in memory and returns a reference to the value
        /// stored at that location.
        ///
        /// \param n type: difference_type
        /// \returns reference
        constexpr auto
        operator[] (difference_type n) noexcept -> reference {
            return current[n];
        }

        /// \brief Additive Assignment Operator Overload.
        ///
        /// \details Increases the current's pointer value by
        /// step and assigns current the new pointer value
        /// and returns a reference to this.
        ///
        /// \param step
        /// \returns normal_iterator&
        constexpr auto
        operator+= (difference_type step) noexcept
            -> normal_iterator& {
            current += step;
            return *this;
        }

        /// \brief Subtraction Assignment Operator Overload.
        ///
        /// \details Decreases the current's pointer value by
        /// step and assigns current the new pointer value
        /// and returns a reference to this.
        ///
        /// \param step
        /// \returns normal_iterator&
        constexpr auto
        operator-= (difference_type step) noexcept
            -> normal_iterator& {
            current -= step;
            return *this;
        }

        /// \brief Addition Operator Overload.
        ///
        /// \details Constructs a new iterator from the addition
        /// of current and step.
        ///
        /// \param step
        /// \returns normal_iterator
        constexpr auto
        operator+ (difference_type step) const noexcept
            -> normal_iterator {
            return normal_iterator(current + step);
        }

        /// \brief Subtraction Operator Overload.
        ///
        /// \details Constructs a new iterator from the subtraction
        /// of current and step.
        ///
        /// \param step
        /// \returns normal_iterator
        constexpr auto
        operator- (difference_type step) const noexcept
            -> normal_iterator {
            return normal_iterator(current - step);
        }

        /// \brief Base Member Access.
        ///
        /// \details Returns a raw copy of current.
        ///
        /// \returns iterator_type
        constexpr const auto
        base() const noexcept -> iterator_type {
            return current;
        }

    private:
        /// \brief Smart pointer indirection adaptor
        ///
        /// \details Adds support for smart pointers
        /// to be adapted into normal_iterator by manually
        /// calling operator-> for smart pointers.
        /// This is the regular pointer overload making
        /// it a no-op.
        ///
        /// \tparam P Possible pointer to object
        ///
        /// \param ptr type: P
        ///
        /// \returns  P*
        template<typename P>
        static constexpr auto
        _S_to_pointer(P* ptr) -> P* {
            return ptr;
        }

        /// \brief Smart pointer indirection adaptor
        ///
        /// \details Adds support for smart pointers
        /// to be adapted into normal_iterator by manually
        /// calling operator-> for smart pointers.
        /// This is the smart pointer overload.
        ///
        /// \tparam P
        ///
        /// \param obj type: P
        ///
        /// \returns pointer
        template<typename P>
        static constexpr auto
        _S_to_pointer(P obj) -> pointer {
            return obj.operator->();
        }

    };  /// class normal_iterator

#    if __cpp_lib_three_way_comparison  /// C++20

    /// \brief Equality Operator Overload.
    ///
    /// \details Performs an equality comparison of two
    /// normal_iterators whose iterator_types can be
    /// different but of they share the same Container
    /// type.
    ///
    /// \notes IterL can equal IterR.
    ///
    /// \tparam IterL
    /// \tparam IterR
    /// \tparam Container
    /// \param lhs type: const normal_iterator<IterL, Container>&
    /// \param rhs type: const normal_iterator<IterR, Container>&
    /// \returns bool
    template<typename IterL, typename IterR, typename Container>
        requires requires (IterL lhsI, IterR rhsI) {
                     { lhsI == rhsI } -> std::convertible_to<bool>;
                 }
    constexpr auto
    operator== (const normal_iterator<IterL, Container>& lhs,
                const normal_iterator<IterR, Container>&
                    rhs) noexcept(noexcept(lhs.base() == rhs.base()))
        -> bool {
        return lhs.base() == rhs.base();
    }

    /// \brief Spaceship Operator Overload.
    ///
    /// \details Performs a 3-way comparison of two
    /// normal_iterators whose iterator_types can be
    /// different but of they share the same Container
    /// type.
    ///
    /// \notes IterL can equal IterR.
    ///
    /// \tparam IterL
    /// \tparam IterR
    /// \tparam Container
    ///
    /// \param lhs type: const normal_iterator<IterL, Container>&
    /// \param rhs type: const normal_iterator<IterR, Container>&
    /// \returns std::weak_ordering
    template<typename IterL, typename IterR, typename Container>
        requires std::three_way_comparable_with<IterL, IterR,
                                                std::weak_ordering>
    constexpr auto
    operator<=> (const normal_iterator<IterL, Container>& lhs,
                 const normal_iterator<IterR, Container>&
                     rhs) noexcept(noexcept(lhs.base() <=>
                                            rhs.base()))
        -> std::weak_ordering {
        return lhs.base() <=> rhs.base();
    }

#    else  /// __cpp_lib_three_way_comparison -> C++20

    /// \brief Equality Operator Overload.
    ///
    /// \details Performs an equality comparison of two
    /// normal_iterator whose iterator_type can be
    /// different but of they share the same Container
    /// type.
    ///
    /// \tparam IterL
    /// \tparam IterR
    /// \tparam Container
    ///
    /// \param lhs type: const normal_iterator<IterL, Container>&
    /// \param rhs type: const normal_iterator<IterR, Container>&
    /// \returns bool
    template<typename IterL, typename IterR, typename Container>
    constexpr inline auto
    operator== (const normal_iterator<IterL, Container>& lhs,
                const normal_iterator<IterR, Container>&
                    rhs) noexcept(noexcept(lhs.base() == rhs.base()))
        -> bool {
        return lhs.base() == rhs.base();
    }

    /// \brief Equality Operator Overload.
    ///
    /// \details Performs an equality comparison of two
    /// normal_iterator whose iterator_type and
    /// Container type are the same.
    ///
    /// \tparam Iterator
    /// \tparam Container
    ///
    /// \param lhs type: const normal_iterator<Iterator, Container>&
    /// \param rhs type: const normal_iterator<Iterator, Container>&
    /// \returns bool
    template<typename Iterator, typename Container>
    constexpr inline auto
    operator== (const normal_iterator<Iterator, Container>& lhs,
                const normal_iterator<Iterator, Container>&
                    rhs) noexcept(noexcept(lhs.base() == rhs.base()))
        -> bool {
        return lhs.base() == rhs.base();
    }

    /// \brief Inequality Operator Overload.
    ///
    /// \details Performs an equality comparison of two
    /// normal_iterator whose iterator_type can be
    /// different but of they share the same Container
    /// type.
    ///
    /// \tparam IterL
    /// \tparam IterR
    /// \tparam Container
    ///
    /// \param lhs type: const normal_iterator<IterL, Container>&
    /// \param rhs type: const normal_iterator<IterR, Container>&
    /// \returns bool
    template<typename IterL, typename IterR, typename Container>
    constexpr inline auto
    operator!= (const normal_iterator<IterL, Container>& lhs,
                const normal_iterator<IterR, Container>&
                    rhs) noexcept(noexcept(lhs.base() != rhs.base()))
        -> bool {
        return lhs.base() != rhs.base();
    }

    /// \brief Inequality Operator Overload.
    ///
    /// \details Performs an inequality comparison of two
    /// normal_iterator whose iterator_type and
    /// Container type are the same.
    ///
    /// \tparam Iterator
    /// \tparam Container
    ///
    /// \param lhs type: const normal_iterator<Iterator, Container>&
    /// \param rhs type: const normal_iterator<Iterator, Container>&
    /// \returns bool
    template<typename Iterator, typename Container>
    constexpr inline auto
    operator!= (const normal_iterator<Iterator, Container>& lhs,
                const normal_iterator<Iterator, Container>&
                    rhs) noexcept(noexcept(lhs.base() != rhs.base()))
        -> bool {
        return lhs.base() != rhs.base();
    }

    /// \brief Less-than Operator Overload.
    ///
    /// \details Performs an less-than comparison of two
    /// normal_iterator whose iterator_type can be
    /// different but of they share the same Container
    /// type.
    ///
    /// \tparam IterL
    /// \tparam IterR
    ///
    /// \tparam Container
    /// \param lhs type: const normal_iterator<IterL, Container>&
    /// \param rhs type: const normal_iterator<IterR, Container>&
    /// \returns bool
    template<typename IterL, typename IterR, typename Container>
    constexpr inline auto
    operator<(const normal_iterator<IterL, Container>& lhs,
              const normal_iterator<IterR, Container>&
                  rhs) noexcept(noexcept(lhs.base() < rhs.base()))
        -> bool {
        return lhs.base() < rhs.base();
    }

    /// \brief Less-than Operator Overload.
    ///
    /// \details Performs an less-than comparison of two
    /// normal_iterator whose iterator_type and
    /// Container type are the same.
    ///
    /// \tparam Iterator
    /// \tparam Container
    ///
    /// \param lhs type: const normal_iterator<Iterator, Container>&
    /// \param rhs type: const normal_iterator<Iterator, Container>&
    /// \returns bool
    template<typename Iterator, typename Container>
    constexpr inline auto
    operator<(const normal_iterator<Iterator, Container>& lhs,
              const normal_iterator<Iterator, Container>&
                  rhs) noexcept(noexcept(lhs.base() < rhs.base()))
        -> bool {
        return lhs.base() < rhs.base();
    }

    /// \brief Greater-than Operator Overload.
    ///
    /// \details Performs an greater-than comparison of two
    /// normal_iterator whose iterator_type can be
    /// different but of they share the same Container
    /// type.
    ///
    /// \tparam IterL
    /// \tparam IterR
    /// \tparam Container
    ///
    /// \param lhs type: const normal_iterator<IterL, Container>&
    /// \param rhs type: const normal_iterator<IterR, Container>&
    /// \returns bool
    template<typename IterL, typename IterR, typename Container>
    constexpr inline auto
    operator> (const normal_iterator<IterL, Container>& lhs,
               const normal_iterator<IterR, Container>&
                   rhs) noexcept(noexcept(lhs.base() > rhs.base()))
        -> bool {
        return lhs.base() > rhs.base();
    }

    /// \brief Greater-than Operator Overload.
    ///
    /// \details Performs an greater-than comparison
    /// of two normal_iterator whose iterator_type
    /// and Container type are the same.
    ///
    /// \tparam Iterator
    /// \tparam Container
    ///
    /// \param lhs type: const normal_iterator<Iterator, Container>&
    /// \param rhs type: const normal_iterator<Iterator, Container>&
    /// \returns bool
    template<typename Iterator, typename Container>
    constexpr inline auto
    operator> (const normal_iterator<Iterator, Container>& lhs,
               const normal_iterator<Iterator, Container>&
                   rhs) noexcept(noexcept(lhs.base() > rhs.base()))
        -> bool {
        return lhs.base() > rhs.base();
    }

    /// \brief Less-than-or-Equal Operator Overload.
    ///
    /// \details Performs an less-than-or-equal comparison
    /// of two normal_iterator whose iterator_type can
    /// be different but of they share the same Container
    /// type.
    ///
    /// \tparam IterL
    /// \tparam IterR
    /// \tparam Container
    ///
    /// \param lhs type: const normal_iterator<IterL, Container>&
    /// \param rhs type: const normal_iterator<IterR, Container>&
    /// \returns bool
    template<typename IterL, typename IterR, typename Container>
    constexpr inline auto
    operator<= (const normal_iterator<IterL, Container>& lhs,
                const normal_iterator<IterR, Container>&
                    rhs) noexcept(noexcept(lhs.base() <= rhs.base()))
        -> bool {
        return lhs.base() <= rhs.base();
    }

    /// \brief Less-than-or-Equal Operator Overload.
    ///
    /// \details Performs an less-than-or-equal comparison
    /// of two normal_iterator whose iterator_type and
    /// Container type are the same.
    ///
    /// \tparam Iterator
    /// \tparam Container
    ///
    /// \param lhs type: const normal_iterator<Iterator, Container>&
    /// \param rhs type: const normal_iterator<Iterator, Container>&
    /// \returns bool
    template<typename Iterator, typename Container>
    constexpr inline auto
    operator<= (const normal_iterator<Iterator, Container>& lhs,
                const normal_iterator<Iterator, Container>&
                    rhs) noexcept(noexcept(lhs.base() <= rhs.base()))
        -> bool {
        return lhs.base() <= rhs.base();
    }

    /// \brief Greater-than-or-Equal Operator Overload.
    ///
    /// \details Performs an greater-than-or-equal comparison
    /// of two normal_iterator whose iterator_type can
    /// be different but of they share the same Container
    /// type.
    ///
    /// \tparam IterL
    /// \tparam IterR
    /// \tparam Container
    ///
    /// \param lhs type: const normal_iterator<IterL, Container>&
    /// \param rhs type: const normal_iterator<IterR, Container>&
    /// \returns bool
    template<typename IterL, typename IterR, typename Container>
    constexpr inline auto
    operator>= (const normal_iterator<IterL, Container>& lhs,
                const normal_iterator<IterR, Container>&
                    rhs) noexcept(noexcept(lhs.base() >= rhs.base()))
        -> bool {
        return lhs.base() >= rhs.base();
    }

    /// \brief Greater-than-or-Equal Operator Overload.
    ///
    /// \details Performs an greater-than-or-equal comparison
    /// of two normal_iterator whose iterator_type and
    /// Container type are the same.
    ///
    /// \tparam Iterator
    /// \tparam Container
    ///
    /// \param lhs type: const normal_iterator<Iterator, Container>&
    /// \param rhs type: const normal_iterator<Iterator, Container>&
    /// \returns bool
    template<typename Iterator, typename Container>
    constexpr inline bool
    operator>= (const normal_iterator<Iterator, Container>& lhs,
                const normal_iterator<Iterator, Container>&
                    rhs) noexcept(noexcept(lhs.base() >= rhs.base()))
        ->bool {
        return lhs.base() >= rhs.base();
    }

#    endif  /// __cpp_lib_three_way_comparison

    /// \brief Difference Operator Overload.
    ///
    /// \details Performs a difference operation between
    /// two normal_iterator whose iterator_type can
    /// be different but share the same Container type.
    ///
    /// \tparam IterL
    /// \tparam IterR
    /// \tparam Container
    ///
    /// \param lhs type: const normal_iterator<IterL, Container>&
    /// \param rhs type: const normal_iterator<IterR, Container>&
    /// \if __cplusplus >= 201103L
    /// \returns decltype(lhs.base() - rhs.base())
    /// \ifnot __cplusplus >= 201103L
    /// \returns typename normal_iterator<IterL,
    /// Container>::difference_type \endif
    template<typename IterL, typename IterR, typename Container>
#    if __cplusplus >= 201103L  /// C++11
    constexpr inline auto
    operator- (const normal_iterator<IterL, Container>& lhs,
               const normal_iterator<IterR, Container>&
                   rhs) noexcept(noexcept(lhs.base() - rhs.base()))
        -> decltype(lhs.base() - rhs.base())
#    else   /// ! C++11
    inline typename normal_iterator<IterL, Container>::difference_type
    operator- (const normal_iterator<IterL, Container>& lhs,
               const normal_iterator<IterR, Container>& rhs)
#    endif  /// __cplusplus >= 201103L
    {
        return lhs.base() - rhs.base();
    }

    /// \brief Difference Operator Overload.
    ///
    /// \details Performs a difference operation between
    /// two normal_iterator whose iterator_type and
    /// Container type are the same.
    ///
    /// \tparam Iterator
    /// \tparam Container
    ///
    /// \param lhs type: const normal_iterator<Iterator, Container>&
    /// \param rhs type: const normal_iterator<Iterator, Container>&
    /// \returns constexpr inline typename normal_iterator<Iterator,
    /// Container>::difference_type
    template<typename Iterator, typename Container>
#    if __cplusplus >= 201103L  /// C++11
    constexpr inline auto
    operator- (const normal_iterator<Iterator, Container>& lhs,
               const normal_iterator<Iterator, Container>&
                   rhs) noexcept(noexcept(lhs.base() - rhs.base()))
        -> decltype(lhs.base() - rhs.base())
#    else   /// ! C++11
    inline
        typename normal_iterator<Iterator, Container>::difference_type
        operator- (const normal_iterator<Iterator, Container>& lhs,
                   const normal_iterator<Iterator, Container>& rhs)
#    endif  /// __cplusplus >= 201103L
    {
        return lhs.base() - rhs.base();
    }

    /// \brief Addition Operator Overload.
    ///
    /// \details Takes an offset \param n and a normal_iterators
    /// \param i. Constructs a new normal_iterators by adding
    /// \param n to \param i.base().
    ///
    /// \tparam Iterator
    /// \tparam Container
    ///
    /// \param n type: normal_iterator<Iterator,
    /// Container>::difference_type \param i type: const
    /// normal_iterator<Iterator, Container>& i \returns constexpr
    /// inline normal_iterator<Iterator, Container>
    template<typename Iterator, typename Container>
    constexpr inline auto
    operator+ (typename normal_iterator<Iterator,
                                        Container>::difference_type n,
               const normal_iterator<Iterator, Container>& i) noexcept
        -> normal_iterator<Iterator, Container> {
        return normal_iterator<Iterator, Container>(i.base() + n);
    }

    /// \brief Makes a new normal_iterator.
    ///
    /// \details An adaptor for turning STL container iterators
    /// into normal_iterators.
    ///
    /// \tparam Container
    ///
    /// \param i type: Container::iterator
    /// \returns normal_iterator<typename Container::iterator,
    /// Container>
    template<typename Container>
    constexpr auto
    make_normal_iterator(typename Container::iterator i) noexcept
        -> normal_iterator<typename Container::iterator, Container> {
        return normal_iterator<typename Container::iterator,
                               Container>(i);
    }

    /// \brief Makes a new normal_iterators.
    ///
    /// \details An adaptor for making slice pointers
    /// into normal_iterators.
    ///
    /// \tparam Iterator
    /// \tparam Container
    ///
    /// \param i type: Iterator
    /// \returns normal_iterator<Iterator, Container>
    template<typename Iterator, typename Container>
    constexpr auto
    make_normal_iterator(Iterator i) noexcept
        -> normal_iterator<Iterator, Container> {
        return normal_iterator<Iterator, Container>(i);
    }

}  // namespace cxl

namespace std
{

    /// \brief rvalue cast
    /// \tparam Iter
    ///
    /// \details Casts the underlying iterator to
    /// its rvalue reference type.
    ///
    /// \param i type: const cxl::normal_iterator<Iterator,
    /// Container>& \return std::iter_rvalue_reference_t<Iterator>
    template<typename Iterator, typename Container>
    constexpr auto
    iter_move(const cxl::normal_iterator<Iterator, Container>& i) noexcept(
        is_nothrow_copy_constructible_v<Iterator>&& noexcept(
            ranges::iter_move(declval<Iterator&>())))
        -> iter_rvalue_reference_t<Iterator> {
        return ranges::iter_move(i.base());
    }

    /// \brief Swaps iterator objects
    ///
    /// \details Swaps objects pointed to by the underlying iterator
    ///
    /// \tparam Iterator
    /// \tparam Iter2 concept: std::indirectly_swappable<Iterator>
    /// \tparam Container
    ///
    /// \param x type: const cxl::normal_iterator<Iterator,
    /// Container>& \param y type: const cxl::normal_iterator<Iter2,
    /// Container>&
    template<typename Iterator,
             std::indirectly_swappable<Iterator> Iter2,
             typename Container>
    constexpr auto
    iter_swap(
        const cxl::normal_iterator<Iterator, Container>& x,
        const cxl::normal_iterator<Iter2, Container>&
            y) noexcept(std::
                            is_nothrow_copy_constructible_v<
                                Iterator>&& std::
                                is_nothrow_copy_constructible_v<Iter2>&& noexcept(
                                    ranges::iter_swap(
                                        std::declval<Iterator&>(),
                                        std::declval<Iter2&>())))
        -> void {
        ranges::iter_swap(x.base(), y.base());
    }

}  // namespace std

#endif  /// __cplusplus >= 201402L

#endif  /// CORTEX_NORMAL_ITERATOR