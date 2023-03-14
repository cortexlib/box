// -*- C++ -*- Header compatibility <match.hxx>

/// \brief Defines a simple template overload
/// for matching variants types using a branch
/// style function selection.
///
///
/// Author: Tyler Swann (tyler.swann05@gmail.com)
///
/// Header Version: v0.1.0
///
/// Date: 24-12-2022
///
/// License: MIT
///
/// Copyright: Copyright (c) 2022-23
/// \file match.hxx

#ifndef CORTEX_MATCH
#define CORTEX_MATCH

#include <utility>
#include <variant>

#if __cpp_concepts >= 201907L
#    include <concepts>
#endif  /// __cpp_concepts >= 201907L

namespace cxl::utils
{

    /// \brief match structure
    ///
    /// \details Inherits the properties
    /// of the variadic template of
    /// invocables and interfaces the
    /// invocables `()` operators.
    ///
    /// \tparam ...Fs
    template<typename... Fs>
    struct match : Fs...
    {

        /// \brief Forward Constructor
        ///
        /// \details Consumes all function types
        /// and forwards them to the variadic constructor
        /// of the invocables.
        ///
        /// \tparam ...Ts
        ///
        /// \param ...ts
        template<class... Ts>
        explicit match(Ts&&... ts)
            : Fs { std::forward<Ts>(ts) }... { }

        /// \brief Invocation declaration
        ///
        /// \details Declares `match` to be using
        /// the invocation operators `()`.
        using Fs::operator()...;
    };

    /// \brief Template Deduction Guide
    template<typename... Fs>
    match(Fs&&...) -> match<std::remove_reference_t<Fs>...>;

    /// \brief Match Expression Notation
    ///
    /// \details Overloads `>>` to reverse the argument
    /// order of a match expression for a cleaner syntax
    /// with existing match types.
    ///
    /// \tparam ...Ts
    /// \tparam ...Fs
    /// \param var type: const std::variant<Ts...>&
    /// \param m type const match<Fs...>&
    /// \return auto
    template<typename... Ts, typename... Fs>
    constexpr auto
    operator>> (
        const std::variant<Ts...>& var,
        const match<Fs...>& m
    ) -> void
    { std::visit(m, var); }

    /// \brief Match Expression Assignment Overload
    ///
    /// \details Overloads the `>>=` operator to
    /// reverse the argument order of a match
    /// expression for a cleaner syntax with existing
    /// match types and to denote an explicit syntax
    /// for match expressions that return a value.
    ///
    /// \tparam ...Ts
    /// \tparam ...Fs
    /// \param var type: const std::variant<Ts...>&
    /// \param m type: const match<Fs...>&
    /// \return decltype(auto)
    template<typename... Ts, typename... Fs>
    constexpr auto
    operator<< (
        const std::variant<Ts...>& var,
        const match<Fs...>& m
    ) -> decltype(auto) 
    { return std::visit(m, var); }

    /// \brief Wildcard Empty Placeholder
    ///
    /// \details Names a placeholder type
    /// that can match to anything in a match
    /// expression. The value is un-retrievable
    /// from `bottom`, use `auto&& <var-name>` to have a
    /// retrievable value.
    struct match_any
    {
        template<typename T>
        explicit constexpr match_any([[maybe_unused]] T&& t) noexcept { }

        explicit constexpr match_any(const match_any&) noexcept = delete;
        explicit constexpr match_any(match_any&&) noexcept      = delete;

        constexpr auto
        operator= (const match_any&) noexcept -> match_any& = delete;

        constexpr auto
        operator= (match_any&&) noexcept -> match_any& = delete;

        constexpr ~match_any() noexcept = delete;
    };

}  // namespace cxl::utils

#endif  /// CORTEX_MATCH
