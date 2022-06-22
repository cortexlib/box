/// -*- C++ -*- Header compatiability <concpets.hpp>


/// \file concepts.hpp
/// \author Tyler Swann (oraqlle@github.com)
/// \brief Some generalised concepts for use throughout
/// the Cortex Libraries
/// \version 0.1.0
/// \date 2022-05-03
/// 
/// \copyright Copyright (c) 2022
/// 



#ifndef CORTEX_CONCEPTS_H
# define CORTEX_CONCEPTS_H 1

#if __cplusplus >= 202002L && defined(__cpp_concepts)
#   include <concepts>

namespace cortex
{
    /// \brief Any Concept
    /// 
    /// \details A concept for which any type is valid.
    /// 
    /// \tparam _Tp 
    
    template<typename _Tp>
    concept Any = true;


    /// \brief None Concept
    /// 
    /// \details A concept for which no type is valid.
    /// 
    /// \tparam _Tp 
    
    template<typename _Tp>
    concept None = false;


    /// \brief Number Concept
    /// 
    /// \details Uses the standard C++20 concepts for std::integral
    /// and std::floating_point to define a concept for a type that
    /// is a number.
    /// 
    /// \tparam _Tp 
    
    template<typename _Tp>
    concept Number = std::integral<_Tp> || std::floating_point<_Tp>;

    
    /// \brief Object Concept
    /// 
    /// \details Uses the type trait std::is_object_v to define a
    /// concept for a type that is an object.
    /// 
    /// \tparam _Tp 
    
    template<typename _Tp>
    concept Object = std::is_object_v<_Tp>;
    
    
    /// \brief AddableWith Concept
    /// 
    /// \details Determines if two (potentially different) types 
    /// are within the domain of operation for the addition operation.
    /// 
    /// \tparam _Lt 
    /// \tparam _Rt 
    template<typename _Lt, typename _Rt>
    concept AddableWith = requires (_Lt __lhs, _Rt __rhs)
    { __lhs + __rhs; };


    /// \brief Addable Concept
    /// 
    /// \details Determines if a type is within the domain
    /// of operation for the addition operation.
    /// 
    /// \tparam _Tp 
    template<typename _Tp>
    concept Addable = requires (_Tp __lhs, _Tp __rhs)
    { __lhs + __rhs; };


    /// \brief SubtractableWith Concept
    /// 
    /// \details Determines if two (potentially different) types
    /// are within the domain of operation for the subtraction 
    /// operation.
    /// 
    /// \tparam _Lt 
    /// \tparam _Rt 
    template<typename _Lt, typename _Rt>
    concept SubtractableWith = requires (_Lt __lhs, _Rt __rhs)
    { __lhs - __rhs; };


    /// \brief Subtractable Concept
    /// 
    /// \details Determines if a type is within the domain
    /// of operation for the subtraction operation.
    /// 
    /// \tparam _Tp 
    template<typename _Tp>
    concept Subtractable = requires (_Tp __lhs, _Tp __rhs)
    { __lhs - __rhs; };


    /// \brief MultiplicableWith Concept
    /// 
    /// \details Determines if two (potentially different) types
    /// are within the domain of operation for the multiplication
    /// operation.
    /// 
    /// \tparam _Lt 
    /// \tparam _Rt 
    template<typename _Lt, typename _Rt>
    concept MultiplicableWith = requires (_Lt __lhs, _Rt __rhs)
    { __lhs * __rhs; };


    /// \brief Multiplicable Concept
    /// 
    /// \details Determines if a type is within the domain
    /// of operation for the multiplication operation.
    /// 
    /// \tparam _Tp 
    template<typename _Tp>
    concept Multiplicable = requires (_Tp __lhs, _Tp __rhs)
    { __lhs * __rhs; };


    /// \brief DivisibleWith Concept
    /// 
    /// \details Determines if two (potentially different) types
    /// are within the domain of operation for the division
    /// operation.
    /// 
    /// \tparam _Lt 
    /// \tparam _Rt 
    template<typename _Lt, typename _Rt>
    concept DivisibleWith = requires (_Lt __lhs, _Rt __rhs)
    { __lhs / __rhs; };


    /// \brief Divisible Concept
    /// 
    /// \details Determines if a type is within the domain
    /// of operation for the division operation.
    /// 
    /// \tparam _Tp
    template<typename _Tp>
    concept Divisible = requires (_Tp __lhs, _Tp __rhs)
    { __lhs / __rhs; };


    /// \brief ModuloWith Concept
    /// 
    /// \details Determines if two (potentially different) types
    /// are within the domain of operation for the modulus
    /// operation.
    /// 
    /// \tparam _Lt 
    /// \tparam _Rt 
    template<typename _Lt, typename _Rt>
    concept ModuloWith = requires (_Lt __lhs, _Rt __rhs)
    { __lhs % __rhs; };

    
    /// \brief Modulo Concept
    /// 
    /// \details Determines if a type is within the domain
    /// of operation for the modulus operation.
    /// 
    /// \tparam _Tp
    template<typename _Tp>
    concept Modulo = requires (_Tp __lhs, _Tp __rhs)
    { __lhs % __rhs; };


    /// \brief BitXorWith Concept
    ///
    /// \details Determines if two (potentially different) types
    /// are within the domain of operation for the bitwise
    /// `exclusive-or` (`xor`) operation. 
    /// 
    /// \tparam _Lt 
    /// \tparam _Rt 
    template<typename _Lt, typename _Rt>
    concept BitXorWith = requires (_Lt __lhs, _Rt __rhs)
    { __lhs ^ __rhs; };

    
    /// \brief BitXor Concept
    ///
    /// \details Determines if a type is withinthe domain
    /// of operation for the bitwise `exclusive-or` (`xor`) 
    /// operation. 
    /// 
    /// \tparam _Tp 
    template<typename _Tp>
    concept BitXor = requires (_Tp __lhs, _Tp __rhs)
    { __lhs ^ __rhs; };


    /// \brief BitAndWith Concept
    ///
    /// \details Determines if two (potentially different) types
    /// are within the domain of operation for the bitwise
    /// `and` operation. 
    /// 
    /// \tparam _Lt 
    /// \tparam _Rt 
    template<typename _Lt, typename _Rt>
    concept BitAndWith = requires (_Lt __lhs, _Rt __rhs)
    { __lhs & __rhs; };

    
    /// \brief BitAnd Concept
    ///
    /// \details Determines if a type is withinthe domain
    /// of operation for the bitwise `and` operation. 
    /// 
    /// \tparam _Tp 
    template<typename _Tp>
    concept BitAnd = requires (_Tp __lhs, _Tp __rhs)
    { __lhs & __rhs; };


    /// \brief BitOrWith Concept
    ///
    /// \details Determines if two (potentially different) types
    /// are within the domain of operation for the bitwise
    /// `or` operation. 
    /// 
    /// \tparam _Lt 
    /// \tparam _Rt 
    template<typename _Lt, typename _Rt>
    concept BitOrWith = requires (_Lt __lhs, _Rt __rhs)
    { __lhs | __rhs; };

    
    /// \brief BitOr Concept
    ///
    /// \details Determines if a type is withinthe domain
    /// of operation for the bitwise `or` operation. 
    /// 
    /// \tparam _Tp 
    template<typename _Tp>
    concept BitOr = requires (_Tp __lhs, _Tp __rhs)
    { __lhs | __rhs; };


    /// \brief LeftBitShiftWith Concept
    ///
    /// \details Determines if two (potentially different) types
    /// are within the domain of operation for the bitwise
    /// `or` operation. 
    /// 
    /// \tparam _Lt 
    /// \tparam _Rt 
    template<typename _Lt, typename _Rt>
    concept LeftBitShiftWith = requires (_Lt __lhs, _Rt __rhs)
    { __lhs << __rhs; };

    
    /// \brief LeftBitShift Concept
    ///
    /// \details Determines if a type is withinthe domain
    /// of operation for the `left bitwise shift` operation. 
    /// 
    /// \tparam _Tp 
    template<typename _Tp>
    concept LeftBitShift = requires (_Tp __lhs, _Tp __rhs)
    { __lhs << __rhs; };


    /// \brief RightBitShiftWith Concept
    ///
    /// \details Determines if two (potentially different) types
    /// are within the domain of operation for the bitwise
    /// `or` operation. 
    /// 
    /// \tparam _Lt 
    /// \tparam _Rt 
    template<typename _Lt, typename _Rt>
    concept RightBitShiftWith = requires (_Lt __lhs, _Rt __rhs)
    { __lhs >> __rhs; };

    
    /// \brief RightBitShift Concept
    ///
    /// \details Determines if a type is withinthe domain
    /// of operation for the `right bitwise shift` operation. 
    /// 
    /// \tparam _Tp 
    template<typename _Tp>
    concept RightBitShift = requires (_Tp __lhs, _Tp __rhs)
    { __lhs >> __rhs; };


    /// \brief BitNot Concept
    ///
    /// \details Checks if a type is within the domain of
    /// operation for the bitwise `not` operation. 
    /// 
    /// \tparam _Tp 
    template<typename _Tp>
    concept BitNot = requires (_Tp __val)
    { ~__val; };

    
    /// \brief Subscriptible Concept
    /// 
    /// \details Determines if a type is within the domain
    /// of operation for the increment operation.
    /// 
    /// \tparam _Tp
    template<typename _Container, typename _Index>
    concept Subscriptible = 
    requires 
    {
        requires Object<_Container> 
                || std::is_array_v<_Container>
                || std::is_pointer_v<_Container>;
    }
    && requires (_Container __container, _Index __index)
    { __container[__index]; };


    /// \brief Invokable
    ///
    /// \details Determines if function type is invokable.
    /// Utilises the template meta-programming struct 
    /// std::is_invokable_v 
    /// 
    /// \tparam _Func 
    /// \tparam _Arg 
    template<typename _Func, typename... _Arg>
    concept Invocable = std::is_invocable_v<_Func, _Arg...>;

} // namespace cortex

#endif // __cplusplus < 202002L && __cpp_concepts

#endif // CORTEX_CONCEPTS_H