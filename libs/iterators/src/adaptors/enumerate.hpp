// -*- C++ -*- Header compatibility <enumerate.hpp>

/**
 * \file enumerate.hpp
 * \author Tyler Swann (oraqlle@github.com)
 * \brief An adaptor for creating an iterator
 * and index pair in a for loop.
 * \version 1.0.0
 * \date 2022-04-01
 * 
 * \ingroup adaptors
 * 
 * \copyright Copyright (c) 2022
 * 
 */

#ifndef CORTEX_ENUMERATE_H
#   define CORTEX_ENUMERATE_H 1

#include <tuple>

#   if __cplusplus >= 201703L

namespace cortex
{


    /**
     * \brief Moves a container to the iterable_wrapper object. 
     * 
     * \tparam _Tp 
     * \tparam _Iterator 
     * \tparam _Iterator,
     * typename 
     * \param __iterable 
     * \param __offset 
     * \return structured binding of the containers elements and an interger offset. 
     */
    template<typename _Tp,
            typename _Iterator = decltype(std::begin(std::declval<_Tp>())),
            typename = decltype(std::end(std::declval<_Tp>()))>
    constexpr auto enumerate(_Tp& __iterable, int __start = 0, int __step = 1)
    {

        /**
         * \brief iterator wrapper for the iterable container. 
         * 
         */
        struct iterator
        {
            int m_index;
            int m_step;
            _Iterator m_iterator;

            /**
             * \brief operator!= overload for checking if an iterator is equal to another 
             * containers iterator.
             * 
             * \param other 
             * \return true 
             * \return false 
             */
            bool operator!= (const iterator& other) const { return m_iterator != other.m_iterator; }


            /**
             * \brief Invokes iterator objects operator++ and 
             * increments the index.
             * 
             */
            void operator++ () { m_index += m_step; ++m_iterator; }


            /**
             * \brief Ties the index and the iterator together in a structured binding. 
             * 
             * \return structured binding [item, elem].
             */
            auto operator* () const { return std::tie(m_index, *m_iterator); }
        }; // struct iterator


        /**
         * \brief A wrapper for a iterable container and its index offset.
         * 
         */
        struct iterable_wrapper
        {
            _Tp m_iterable;
            int m_offset;
            int m_step;

            /**
             * \brief Returns an iterator object to the first element of the container.
             * 
             * \return 
             */
            auto begin() { return iterator{ static_cast<int>(m_offset), static_cast<int>(m_step), std::begin(m_iterable) }; }


            /**
             * \brief Returns an iterator object of one past the last element of the container.
             * 
             * \return auto 
             */
            auto end() { return iterator{ static_cast<int>(m_offset), static_cast<int>(m_step), std::end(m_iterable) }; }
        }; // struct iterable_wrapper

        /**
         * \returns iterable_wrapper object with the container object and offset value
         * forwarded to wrapper. 
         * 
         */
        return iterable_wrapper{ std::forward<_Tp>(__iterable), std::forward<int>(__start), std::forward<int>(__step) };
    }



    namespace adaptors
    {

        /**
         * \brief proxy for adapting an index to an container.
         * 
         * \tparam _Tp 
         */
        template <typename _Tp, typename _Up>
        struct enumerate_proxy 
        { 
            _Tp m_start; 
            _Up m_step;
        };


        /**
         * \brief 
         * 
         * \tparam _Tp 
         * \param __offset 
         * \return index proxy object with the offset value. 
         */
        template <typename _Tp>
        auto enumerate(_Tp __offset = 0) { return enumerate_proxy<_Tp, _Tp>{__offset, static_cast<_Tp>(1)}; }


        template <typename _Tp, typename _Up>
        auto enumerate(_Tp __offset, _Up __step) { return enumerate_proxy<_Tp, _Up>{__offset, __step}; }


        /**
         * \brief operator| overload for piping the index_proxy object returnd 
         * by indexed to the enumerate function.
         * 
         * \tparam _Container 
         * \tparam _Tp 
         * \param __container 
         * \param __proxy 
         * \return constexpr auto 
         */
        template <typename _Container, typename _Tp, typename _Up>
        constexpr auto operator| (const _Container& __container, const enumerate_proxy<_Tp, _Up>& __proxy) 
        { return cortex::enumerate(__container, __proxy.m_start, __proxy.m_step); }

    } // namespace adaptors

} // namespace cortex

#   endif // __cplusplus >= 201703L

#endif // CORTEX_ENUMERATE_H