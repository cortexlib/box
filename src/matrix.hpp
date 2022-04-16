// -*- C++ -*- Header compatibility <matrix.hpp>
/**
 * @file matrix
 * @author Tyler Swann (oraqlle@github.com)
 * @brief Two dimensional array
 * @version 0.0.1
 * @date 2022-16-22
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef CORTEX_MATRIX_H
#   define CORTEX_MATRIX_H 1

#include <iterators/normal.hpp>
#include <concepts.hpp>

#if __cplusplus >= 201703L

#include <memory>
#include <utility>
#include <iterator>
#include <initializer_list>
#include <cassert>



namespace cortex
{
    template<typename _Tp>
    class matrix
    {
    public:
        using value_type                    = _Tp;
        using size_type                     = std::size_t;
        using difference_type               = std::ptrdiff_t;
        using reference                     = _Tp&;
        using const_reference               = const _Tp&;
        using pointer                       = _Tp*;
        using const_pointer                 = const _Tp*;
        using iterator                      = cortex::normal_iterator<pointer, matrix<value_type>>;
        using const_iterator                = cortex::normal_iterator<const_pointer, matrix<value_type>>;
        using reverse_iterator              = std::reverse_iterator<iterator>;
        using const_reverse_iterator        = std::reverse_iterator<const_iterator>;


    protected: 
            size_type m_columns;
            size_type m_rows;

            size_type m_size;

            pointer m_data;

    public:

        matrix()
        : m_columns(size_type())
        , m_rows(size_type())
        , m_size(size_type())
        , m_data(pointer())
        { }

        matrix(size_type cols, size_type rows)
        : m_columns(cols)
        , m_rows(rows)
        , m_size(cols * rows != 0 ? cols * rows : std::max(cols, rows))
        , m_data(_M_allocate(m_size))
        { 
            if constexpr (std::is_default_constructible_v<value_type>)
                std::uninitialized_default_construct_n(m_data, m_size);
            else
                std::uninitialized_fill_n(m_data, m_size, value_type());
        }

        matrix(size_type cols, size_type rows, const value_type& value)
        : m_columns(cols)
        , m_rows(rows)
        , m_size(cols * rows != 0 ? cols * rows : std::max(cols, rows))
        , m_data(_M_allocate(m_size))
        { std::uninitialized_fill_n(m_data, m_size, value); }

        matrix(const matrix& other)
        : m_columns(other.m_columns)
        , m_rows(other.m_rows)
        , m_size(other.m_size)
        , m_data(_M_allocate(m_size))
        { std::uninitialized_copy_n(other.m_data, m_size, m_data); }

        matrix(matrix&& other) noexcept
        : m_columns(other.m_columns)
        , m_rows(other.m_rows)
        , m_size(other.m_size)
        , m_data(other.m_data)
        { 
            other.m_data = pointer();
            other.m_columns = size_type();
            other.m_rows = size_type();
            other.m_size = size_type(); 
        }

        matrix& operator=(const matrix& other)
        {
            m_columns = other.m_columns;
            m_rows = other.m_rows;
            m_size = other.m_size;
            m_data = _M_allocate(m_size);
            std::uninitialized_copy_n(other.m_data, m_size, m_data);

            return *this;
        }

        matrix& operator=(matrix&& other) noexcept
        {
            m_columns = other.m_columns;
            m_rows = other.m_rows;
            m_size = other.m_size;
            m_data = other.m_data;

            other.m_data = pointer();
            other.m_columns = size_type();
            other.m_rows = size_type();
            other.m_size = size_type();

            return *this;
        }

        ~matrix()
        {
            if (m_data != pointer())
                std::destroy_n(m_data, m_size);

            
            if (m_data != pointer())
                _M_deallocate(m_data, m_size);

            m_columns = size_type();
            m_rows = size_type();
            m_size = size_type();
        }

        constexpr size_type size() const noexcept
        { return m_size; }

        constexpr size_type row_size() const noexcept
        { return m_rows; } 

        constexpr size_type column_size() const noexcept
        { return m_columns; }

        constexpr size_type max_size() const noexcept
        { return m_size; }

        constexpr auto dimensions() const noexcept
        { return std::tie(m_columns, m_rows); }

        constexpr bool empty() const noexcept
        { return m_size == 0; }

        constexpr pointer data() const noexcept
        { return m_data; }

        /**
         * @brief 
         * 
         * @todo Change to be the access of two dimensions
         * 
         * @param index 
         * @return constexpr reference 
         */
        constexpr reference operator[](size_type index)
        { return *(m_data + index); }


    private:

        pointer _M_allocate(size_type __n)
        { return __n != 0 ? static_cast<pointer>(::operator new(__n * sizeof(value_type))) : pointer(); }

        void _M_deallocate(pointer __p, size_type __n)
        { ::operator delete(__p); }
    };
} // namespace cortex

#endif // __cplusplus >= 201703L

#endif // CORTEX_MATRIX_H