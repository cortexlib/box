/// -*- C++ -*- Header compatibility <box.hpp>

/// \brief Two Dimensional Access To Contiguous Data.
///
/// Author: Tyler Swann (oraqlle@github.com)
/// 
/// Header Version: v2.3.3
///
/// Date: 25-06-2022
///
/// License: MIT
///
/// Copyright: Copyright (c) 2022
/// \file box.hpp

#ifndef CORTEX_BOX_H
#define CORTEX_BOX_H 1

#include <concepts.hpp>
#include <iterators/column.hpp>
#include <iterators/normal.hpp>
#include <iterators/row.hpp>

#if __cplusplus >= 202002L

#include <algorithm>
#include <cassert>
#include <functional>
#include <initializer_list>
#include <memory>
#include <span>
#include <utility>
#include <vector>

#define lexicographical_compare_bug 1

namespace cortex
{
    /// \brief Box - Two Dimensional Array
    ///
    /// \group box Box
    ///
    /// \details Box is a two dimensional generic container.
    /// It aims to support expressive methods and operations
    /// that allow unique manipulation an structural access 
    /// to data.
    /// Elements are stored continguously in memory and are 
    /// layed out in a row-wise fashion.
    /// 
    /// \tparam T concept: Any
    /// \tparam Alloc default: std::allocator<T>
    template <typename T, typename Alloc = std::allocator<T>>
    class box
    {
    public:
        using value_type                            = T;
        using size_type                             = std::size_t;
        using difference_type                       = std::ptrdiff_t;

        using allocator_type                        = Alloc;
        using alloc_traits                          = typename std::allocator_traits<Alloc>;

        using reference                             = T&;
        using const_reference                       = const T&;
        using pointer                               = typename alloc_traits::pointer;
        using const_pointer                         = typename alloc_traits::pointer;

        using iterator                              = cortex::normal_iterator<pointer, box<value_type>>;
        using const_iterator                        = cortex::normal_iterator<const_pointer, box<value_type>>;
        using reverse_iterator                      = std::reverse_iterator<iterator>;
        using const_reverse_iterator                = std::reverse_iterator<const_iterator>;

        using column_iterator                       = cortex::column_iterator<iterator>;
        using const_column_iterator                 = cortex::column_iterator<const_iterator>;
        using reverse_column_iterator               = std::reverse_iterator<column_iterator>;
        using const_reverse_column_iterator         = std::reverse_iterator<const_column_iterator>;

        using row_iterator                          = cortex::row_iterator<iterator>;
        using const_row_iterator                    = cortex::row_iterator<const_iterator>;
        using reverse_row_iterator                  = std::reverse_iterator<row_iterator>;
        using const_reverse_row_iterator            = std::reverse_iterator<const_row_iterator>;

    private:
        size_type m_rows;
        size_type m_columns;

        allocator_type m_allocator;
        pointer m_start;
        pointer m_finish;

    public:

        /// \brief Default Constructor
        ///
        /// \details Default constructor for box.
        constexpr box() noexcept
        : m_rows(size_type())
        , m_columns(size_type())
        , m_allocator(allocator_type())
        , m_start(pointer())
        , m_finish(pointer())
        { }


        /// \brief Allocator Constructor
        ///
        /// \details Default Constructs a box with a
        /// given allocator.
        ///
        /// \param alloc type: allocator_type | qualifiers: {const, ref}
        constexpr explicit box(const allocator_type& alloc) noexcept
        : m_rows(size_type())
        , m_columns(size_type())
        , m_allocator(alloc)
        , m_start(pointer())
        , m_finish(pointer())
        { }


        /// \brief Size Constructor
        ///
        /// \details Constructs a box with dimensions of
        /// rows x columns. Values are default constructed 
        /// or fill constructed depending on the default 
        /// constructiblity qualification.
        ///
        /// \param cols type: size_type
        /// \param rows type: size_type
        /// \param alloc type: allocator_type | qualifiers: {const, ref}
        constexpr explicit box(size_type rows, size_type cols, const allocator_type& alloc = allocator_type())
        : m_rows(rows)
        , m_columns(cols)
        , m_allocator(alloc)
        , m_start(_M_allocate(_M_size(m_rows, m_columns)))
        , m_finish(m_start + _M_size(m_rows, m_columns))
        {
            if constexpr (std::is_default_constructible_v<value_type>)
                std::ranges::uninitialized_default_construct(*this);
            else
                std::ranges::uninitialized_fill(*this, value_type());
        }


        /// \brief Size + Value Constructor
        ///
        /// \details Constructs a box with dimensions of
        /// rows x columns. Values are constructed from 
        /// the a constant reference to a provided value.
        ///
        /// \param cols type: size_type
        /// \param rows type: size_type
        /// \param value type: value_type | qualifiers: {const, ref}
        /// \param alloc type: allocator_type | qualifiers: {const, ref}
        constexpr box(size_type rows, size_type cols, const_reference value, const allocator_type& alloc = allocator_type())
        : m_rows(rows)
        , m_columns(cols)
        , m_allocator(alloc)
        , m_start(_M_allocate(_M_size(m_rows, m_columns)))
        , m_finish(m_start + _M_size(m_rows, m_columns))
        { std::ranges::uninitialized_fill(*this, value); }


        /// \brief Copy Constructor
        ///
        /// \details Constructs a box that is a copy of
        /// another box of the same underlying type.
        ///
        /// \param other type: [box] | qualifiers: {const, ref}
        constexpr box(const box& other)
        : m_rows(other.m_rows)
        , m_columns(other.m_columns)
        , m_allocator(other.m_allocator)
        , m_start(_M_allocate(_M_size(m_rows, m_columns)))
        , m_finish(m_start + _M_size(m_rows, m_columns))
        { std::ranges::uninitialized_copy(other, *this); }


        /// \brief Copy Constructor with Alternative Allocator
        ///
        /// \details Constructs a box that is a copy of
        /// another box of the same underlying type.
        ///
        /// \param other type: [box] | qualifiers: {const, ref}
        /// \param alloc type: allocator_type | qualifiers: {const, ref}
        constexpr box(const box& other, const allocator_type& alloc)
        : m_rows(other.m_rows)
        , m_columns(other.m_columns)
        , m_allocator(alloc)
        , m_start(_M_allocate(_M_size(m_rows, m_columns)))
        , m_finish(m_start + _M_size(m_rows, m_columns))
        { std::ranges::uninitialized_copy(other, *this); }


        /// \brief Move Constructor
        ///
        /// \details Moves ownership of an existing box's
        /// resources to this box and leaves the other box
        /// in a default constructed state.
        ///
        /// \param other type: [box] | qualifiers: [move]
        constexpr box(box&& other) noexcept
        : m_rows(other.m_rows)
        , m_columns(other.m_columns)
        , m_allocator(std::move(other.m_allocator))
        , m_start(other.m_start)
        , m_finish(other.m_finish)
        {
            other.m_start = pointer();
            other.m_finish = pointer();
            other.m_allocator = allocator_type();
            other.m_rows = size_type();
            other.m_columns = size_type();
        }


        /// \brief Move Constructor with Alternative Allocator
        ///
        /// \details Moves ownership of an existing box's
        /// resources to this box and leaves the other box
        /// in a default constructed state. Uses an alternative
        /// allocator for construction of `this` box.
        ///
        /// \param other type: [box] | qualifiers: [move]
        /// \param alloc type: allocator_type | qualifiers: {const, ref}
        constexpr box(box&& other, const allocator_type& alloc) noexcept
        : m_rows(other.m_rows)
        , m_columns(other.m_columns)
        , m_allocator(alloc)
        , m_start(other.m_start)
        , m_finish(other.m_finish)
        {
            other.m_start = pointer();
            other.m_finish = pointer();
            other.m_allocator = allocator_type();
            other.m_rows = size_type();
            other.m_columns = size_type();
            other.m_size = size_type();
        }


        /// \brief Assign Copy Constructor
        ///
        /// \details Iterates from first to last and copys the
        /// elements to this box. Copy is done through the boxes
        /// begin() iterator, thus copy is done row-wise.
        ///
        /// \tparam It concept: [std::input_iterator]
        /// \param first type: [It]
        /// \param last type: [It]
        /// \param rows type: size_type
        /// \param cols type: size_type
        /// \param alloc type: allocator_type | qualifiers: {const, ref} | attribute: [[maybe_unused]]
        template <std::input_iterator It>
        constexpr box(It first, It last
                    , size_type rows, size_type cols
                    , [[maybe_unused]] const allocator_type& alloc = allocator_type())
        : m_rows(rows)
        , m_columns(cols)
        , m_allocator(alloc)
        , m_start(_M_allocate(_M_size(m_rows, m_columns)))
        , m_finish(m_start + _M_size(m_rows, m_columns))
        { std::ranges::uninitialized_copy(first, last, begin(), end()); }


        /// \brief Initialiser List Constructor
        ///
        /// \details Uses std::initializer_list to create a box
        /// from an initializer list of initializer lists. Elements
        /// ownership is moved to the box's memory.
        ///
        /// \param list type: [std::initializer_list<std::initializer_list<value_type>>] | qualifiers: {const, ref}
        /// \param alloc type: allocator_type | qualifiers: {const, ref} | attribute: [[maybe_unused]]
        constexpr box(std::initializer_list<std::initializer_list<value_type>> list
                    , [[maybe_unused]] const allocator_type& alloc = allocator_type())
        : m_rows(list.size())
        , m_columns(list.begin()->size())
        , m_allocator(alloc)
        , m_start(_M_allocate(_M_size(m_rows, m_columns)))
        , m_finish(m_start + _M_size(m_rows, m_columns))
        {
            using init_iter = typename decltype(list)::iterator;
            auto offset{ 0uL };
            for (init_iter row{list.begin()}; row != list.end(); ++row)
            {
                if (row->size() != this->m_columns)
                    throw std::invalid_argument("Columns must be all the same size");
                std::uninitialized_move_n(row->begin(), this->m_columns, m_start + offset);
                offset += this->m_columns;
            }
        }


        /// \brief Copy Assignment
        ///
        /// \details Copies the contents of another box into
        /// this box and returns///this. If self assignment occurs
        /// then///this is returned immediately.
        ///
        /// \param other type: [box] | qualifiers: {const, ref}
        /// \returns constexpr box&
        constexpr box& operator= (const box& other)
        {
            if (*this != other)
            {
                m_rows = other.m_rows;
                m_columns = other.m_columns;
                m_allocator = other.m_allocator;
                m_start = _M_allocate(_M_size(m_rows, m_columns));
                m_finish = m_start + _M_size(m_rows, m_columns);
                std::ranges::uninitialized_copy(other, *this);
            }
            return *this;
        }

        /// \brief Move Assignment
        ///
        /// \details Moves the ownership of other's resources to
        /// this box and leaves the other box in a default
        /// constructed state. Returns///this. If self assignment
        /// occurs then///this is returned immediately.
        ///
        /// \param other type: [box] | qualifiers: [move]
        /// \returns constexpr box&
        constexpr box& operator= (box&& other) noexcept
        {
            if (*this != other)
            {
                m_rows = other.m_rows;
                m_columns = other.m_columns;
                m_allocator = std::move(other.m_allocator);
                m_start = other.m_start;
                m_finish = other.m_finish;

                other.m_start = pointer();
                other.m_finish = pointer();
                other.m_allocator = allocator_type();
                other.m_rows = size_type();
                other.m_columns = size_type();
            }
            return *this;
        }

        /// \brief Initialiser List Assignment
        ///
        /// \details Uses std::initializer_list to create a box
        /// from an initializer list of initializer lists. Elements
        /// ownership is moved to the box's memory.
        ///
        /// \param list type: [std::initializer_list<std::initializer_list<value_type>>]
        /// \returns constexpr box&
        constexpr box& operator= (std::initializer_list<std::initializer_list<value_type>> list)
        {
            m_allocator = allocator_type();
            m_rows = list.size();
            m_columns = list.begin()->size();
            m_start = _M_allocate(_M_size(m_rows, m_columns));
            m_finish = m_start + _M_size(m_rows, m_columns);

            using init_iter = typename decltype(list)::iterator;
            auto offset{0uL};
            for (init_iter row{list.begin()}; row != list.end(); ++row)
            {
                if (row->size() != this->m_columns)
                    throw std::invalid_argument("Columns must be all the same size");
                std::uninitialized_move_n(row->begin(), this->m_columns, m_start + offset);
                offset += this->m_columns;
            }

            return *this;
        }

        /// \brief Destructor
        ///
        /// \details Releases the resources of this box
        /// and leaves the box in an uninitialized state.
#if __cplusplus >= 202202L
        constexpr ~box()
#else
        ~box()
#endif
        {
            if (m_start)
            {
                std::ranges::destroy(*this);
                _M_deallocate(m_start, _M_size(m_rows, m_columns));
            }

            m_rows = size_type();
            m_columns = size_type();
            m_start = pointer();
            m_finish = pointer();
            m_allocator = allocator_type();
        }


        /// \brief Intialiser List Assign
        ///
        /// \details Uses std::initializer_list to reassign 
        /// values to a box. If the lists dimensions are not
        /// the same as the box's dimensions, then the box
        /// is resized to match the dimensions of the list.
        /// 
        /// \param list type: [std::initializer_list<std::initializer_list<value_type>>]
        constexpr void assign(std::initializer_list<std::initializer_list<value_type>> list)
        {
            auto new_rows { list.size() };
            auto new_columns { list.begin()->size() };

            std::ranges::destroy(*this);

            if (new_rows != m_rows || new_columns != m_columns)
            {
                if (m_start)
                    _M_deallocate(m_start, _M_size(m_rows, m_columns));
            
                m_start = _M_allocate(_M_size(new_rows, new_columns));
                m_finish = m_start + _M_size(new_rows, new_columns);
            }
            
            m_rows = new_rows;
            m_columns = new_columns;

            using init_iter = typename decltype(list)::iterator;
            auto offset{ 0uL };
            for (init_iter row{ list.begin() }; row != list.end(); ++row)
            {
                if (row->size() != this->m_columns)
                    throw std::invalid_argument("Columns must be all the same size");

                std::uninitialized_move_n(row->begin(), this->m_columns, m_start + offset);
                offset += this->m_columns;
            }
        }


        /// \brief Resizes the box to dimensions new_rows x new_columns.
        ///
        /// \details Resizes the box to dimensions new_rows x new_columns,
        /// the resize will result in a new memory block being allocated
        /// if the new dimensions are larger or smaller than the current dimensions.
        /// Reallocation or destruction of elements causes iterators and references
        /// to be invalidated. If new dimensions don't change the overall size, only
        /// the view over the data (ie. the dimension sizes) are changed, elements
        /// of the box remain unchanged, however, this is unchecked. For a checked
        /// change that can only changes the dimension sizes, use box::reshape.
        ///
        /// \param new_rows type: size_type
        /// \param new_columns type: size_type
        constexpr void resize(size_type new_rows, size_type new_columns)
        {
            auto old_size{_M_size(m_rows, m_columns)};

            if (auto new_size{_M_size(new_rows, new_columns)}; new_size > alloc_traits::max_size(m_allocator))
                throw std::length_error("Matrix resize too large");
            else
            {
                auto new_start{_M_allocate(new_size)};
                auto old_finish_pos_in_new{new_start + old_size};
                auto new_finish{new_start + new_size};

                if (old_size < new_size)
                {
                    if (m_start)
                    {
                        std::ranges::uninitialized_copy(m_start, m_finish, new_start, old_finish_pos_in_new);
                        std::ranges::uninitialized_default_construct(old_finish_pos_in_new, new_finish);
                    }
                    else
                        std::ranges::uninitialized_default_construct(new_start, new_finish);
                }
                else if (old_size > new_size)
                {
                    if (m_start)
                        std::ranges::uninitialized_copy(m_start, m_finish, new_start, new_finish);
                    else
                        std::ranges::uninitialized_default_construct(old_finish_pos_in_new, new_finish);
                }

                std::ranges::destroy(*this);
                _M_deallocate(m_start, old_size);

                m_start = new_start;
                m_finish = new_finish;
            }

            m_rows = new_rows;
            m_columns = new_columns;
        }


        /// \brief Resizes the box to dimensions new_rows x new_columns with default value
        ///
        /// \details Resizes the box to dimensions new_rows x new_columns,
        /// the resize will result in a new memory block being allocated
        /// if the new dimensions are larger or smaller than the current dimensions.
        /// Reallocation or destruction of elements causes iterators and references
        /// to be invalidated. The new box is initialised with value. If new dimensions
        /// don't change the overall size, only the view over the data (ie. the dimension
        /// sizes) are changed, elements of the box remain unchanged, however, this is
        /// unchecked. For a checked change that can only changes the dimension sizes, use
        /// box::reshape.
        ///
        /// \param new_rows type: size_type
        /// \param new_columns type: size_type
        /// \param value type: value_type | qualifiers: {const, ref}
        constexpr void resize(size_type new_rows, size_type new_columns, const_reference value)
        {
            auto old_size{_M_size(m_rows, m_columns)};

            if (auto new_size{_M_size(new_rows, new_columns)}; new_size > alloc_traits::max_size(m_allocator))
                throw std::length_error("Matrix resize too large");
            else
            {
                auto new_start{_M_allocate(new_size)};
                auto old_finish_pos_in_new{new_start + old_size};
                auto new_finish{new_start + new_size};

                if (old_size < new_size)
                {
                    if (!empty())
                    {
                        std::ranges::uninitialized_copy(m_start, m_finish, new_start, old_finish_pos_in_new);
                        std::ranges::uninitialized_fill(old_finish_pos_in_new, new_finish, value);
                    }
                    else
                        std::ranges::uninitialized_fill(new_start, new_finish, value);
                }
                else if (old_size > new_size)
                {
                    if (!empty())
                        std::ranges::uninitialized_copy(m_start, m_finish, new_start, new_finish);
                    else
                        std::ranges::uninitialized_fill(old_finish_pos_in_new, new_finish, value);
                }

                std::ranges::destroy(*this);
                _M_deallocate(m_start, old_size);

                m_start = new_start;
                m_finish = new_finish;
            }

            m_rows = new_rows;
            m_columns = new_columns;
        }


        /// \brief Erases element indicated by position
        ///
        /// \details Erases the value of the box at position
        /// and resets it to value_type().
        ///
        /// \param position type: [const_iterator]
        /// \returns constexpr iterator | attribute: [[maybe_unused]]
        [[maybe_unused]] constexpr iterator 
        erase(const_iterator position)
        {
            std::ranges::destroy_at(std::addressof(*position));
            std::ranges::uninitialized_fill(position, position + 1, value_type());

            return position;
        }


        /// \brief Erases value between first and last
        ///
        /// \details Elements between first and last and then
        /// resets memory to value_type()
        ///
        /// \param first type: [const_iterator]
        /// \param last type: [const_iterator]
        /// \returns constexpr iterator | attribute: [[maybe_unused]]
        [[maybe_unused]] constexpr iterator 
        erase(const_iterator first, const_iterator last)
        {
            std::ranges::destroy(first, last);
            std::ranges::uninitialized_fill(first, last, value_type());

            return first;
        }


        /// \brief Clears the box elements
        ///
        /// \details The elements of the box are destroyed and
        /// the memory is deallocated entirely. The box is however,
        /// left in a state where it could be re-initialised or
        /// destructed which is up to user descretionbx. box::resize
        /// has to be used to allocate storage for the new elements.
        constexpr void clear()
        {
            if (_M_size(m_rows, m_columns))
            {
                erase(begin(), end());

                _M_deallocate(m_start, _M_size(m_rows, m_columns));
                m_rows = size_type();
                m_columns = size_type();
                m_finish = m_start = pointer();
            }
        }


        /// \brief Reshape current box elements to new dimensions
        ///
        /// \details Reshapes the current box's dimensisons while
        /// guranteeing that now reallocation occurs. Elements are
        /// preserved.
        ///
        /// \param new_rows type: size_type
        /// \param new_columns type: size_type
        constexpr void reshape(size_type new_rows, size_type new_columns)
        {
            auto new_size{ _M_size(new_rows, new_columns) };

            if (new_size != _M_size(m_rows, m_columns))
                throw std::length_error("Cannot reshape box that has different total size");
            else
                resize(new_rows, new_columns);
        }


        /// \brief Swaps two matrices of the same type.
        ///
        /// \details Swaps the contents of two matrices of
        /// which they are the same type. The swap is performed
        /// by moving ownership of the matrices resources.
        ///
        /// \param other type: [box] | qualifiers: [ref]
        void swap(box& other) noexcept
        {
            box tmp = std::move(other);
            other = std::move(*this);
            *this = std::move(tmp);
        }


        /// \brief Get Allocator
        ///
        /// \details Returns the allocator used by the box.
        ///
        /// \returns constexpr allocator_type
        constexpr allocator_type get_allocator() const noexcept
        { return m_allocator; }


        /// \brief Box Size
        /// 
        /// \details Returns the overall size of the box.
        ///
        /// \returns constexpr size_type
        constexpr size_type size() const noexcept
        { return empty() ? size_type(0) : _M_size(m_rows, m_columns); }


        /// \brief Row Size
        /// 
        /// \details Returns the number of the rows of the box.
        ///
        /// \returns constexpr size_type
        constexpr size_type rows() const noexcept
        { return m_rows; }


        /// \brief Column Size
        /// 
        /// \details Returns the the number of columns in the box.
        ///
        /// \returns constexpr size_type
        constexpr size_type columns() const noexcept
        { return m_columns; }


        /// \brief Max Box Size
        /// 
        /// \details Returns the maximum number of elements that
        /// can be stored in the box.
        ///
        /// \returns constexpr size_type
        constexpr size_type max_size() const noexcept
        { return alloc_traits::max_size(m_allocator); }


        /// \brief Dimensions
        /// 
        /// \details Returns a structured binding of the box's
        /// dimensions.
        ///
        /// \returns constexpr auto
        constexpr auto dimensions() const noexcept
        { return std::tie(m_rows, m_columns); }


        /// \brief Is Square
        ///
        /// \details If the number of rows and columns 
        /// are equal, the box is square.
        ///
        /// \returns true
        /// \returns false
        constexpr bool is_square() const noexcept
        { return m_rows == m_columns; }


        /// \brief Empty
        ///
        /// \details Checks whether the box is empty.
        ///
        /// \returns true
        /// \returns false
        constexpr bool empty() const noexcept
        { return m_start == m_finish; }


        /// \brief Data
        ///
        /// \details Returns the underlying data pointer.
        ///
        /// \returns pointer
        pointer data() noexcept
        { return _M_data_ptr(m_start); }

        /// \brief Data
        /// 
        /// \details Returns the underlying data pointer.
        ///
        /// \returns const_pointer
        const_pointer data() const noexcept
        { return _M_data_ptr(m_start); }


        /// \brief Slice
        ///
        /// \details Returns a slice of the box. The slice is
        /// std::span over the indicated row of the box. The 
        /// span is a view over the underlying data.
        ///
        /// \exception std::out_of_range - if the row index is 
        /// out of range of the box, the exception is thrown.
        /// 
        /// \param ridx type: size_type
        /// \returns std::span<value_type> 
        constexpr auto
        slice(size_type ridx) const
            -> std::span<value_type>
        {
            if (ridx >= m_rows)
                throw std::out_of_range("box::slice - row index out of range");
            
            return std::span<value_type>{
                _M_data_ptr(m_start) + ridx * m_columns,
                m_columns
            };
        }


        /// \brief Slice Operator
        ///
        /// \details Returns a slice of the box. The slice is
        /// std::span over the indicated row of the box. The
        /// span is a view over the underlying data. Calls
        /// `box::slice`.
        /// 
        /// \param ridx 
        /// \returns std::span<value_type> 
        constexpr auto 
        operator[](size_type ridx)
            -> std::span<value_type>
        { return slice(ridx); }

        /// \brief Two Dimensional Element Access (Point Access).
        ///
        /// \details Returns a reference to the element that
        /// is at the point position (column, row) of the
        /// box.
        ///
        /// \exception std::out_of_range
        ///
        /// \param column type: size_type
        /// \param row type: size_type
        /// \returns constexpr reference
        constexpr reference at(size_type row, size_type column)
        {
            _M_range_check(row, column);
            return *(m_start + (m_columns * row) + column);
        }

        /// \brief At
        ///
        /// \details Returns a reference to the element that
        /// is at the point position (column, row) of the
        /// box.
        ///
        /// \exception std::out_of_range
        ///
        /// \param column type: size_type
        /// \param row type: size_type
        /// \returns constexpr const_reference
        constexpr const_reference at(size_type row, size_type column) const
        {
            _M_range_check(row, column);
            return *(m_start + (m_columns * row) + column);
        }

        /// \brief Point Access Operator
        ///
        /// \details Provides point access to box's elements.
        /// Overloads the invokation operator. Utilises the at() method.
        ///
        /// \exception std::out_of_range
        ///
        /// \param column type: size_type
        /// \param row type: size_type
        /// \returns constexpr reference
        constexpr reference operator()(size_type row, size_type column)
        { return at(row, column); }

        /// \brief Point Access Operator
        ///
        /// \details Provides point access to box's elements.
        /// Overloads the invokation operator. Utilises the at() method.
        ///
        /// \exception std::out_of_range
        ///
        /// \param column type: size_type
        /// \param row type: size_type
        /// \returns constexpr const_reference
        constexpr const_reference operator()(size_type row, size_type column) const
        { return at(row, column); }

        /// \brief Front
        /// 
        /// \details Returns a reference to the front element
        /// of the box.
        ///
        /// \returns constexpr reference
        constexpr reference front() noexcept
        { return *begin(); }

        /// \brief Front
        ///
        /// \details Returns a reference to the front element
        /// of the box.
        ///
        /// \returns constexpr const_reference
        constexpr const_reference front() const noexcept
        { return *begin(); }

        /// \brief Back
        ///
        /// \details Returns a reference to the back element
        /// of the box.
        ///
        /// \returns constexpr reference
        constexpr reference back() noexcept
        { return *(end() - 1); }

        /// \brief Back
        /// 
        /// \details Returns a reference to the back element
        /// of the box.
        ///
        /// \returns constexpr const_reference
        constexpr const_reference back() const noexcept
        { return *(this->end() - 1); }

        /// \brief Flatten
        ///
        /// \details Creates a std::vector of the box's elements
        /// in row major order.
        ///
        /// \returns constexpr std::vector<value_type>
        constexpr std::vector<value_type> flatten() const noexcept
        {
            std::vector<value_type> vec(_M_size(m_rows, m_columns));
            std::ranges::copy(*this, std::begin(vec));
            return vec;
        }

        /// \brief Begin Iterator
        /// 
        /// \details Iterator to the beginning of 
        /// the box's data.
        ///
        /// \returns constexpr iterator
        constexpr iterator begin() noexcept
        { return iterator(m_start); }

        /// \brief Begin Iterator (const)
        /// 
        /// \details Constant iterator to the beginning 
        /// of the box's data.
        ///
        /// \returns constexpr const_iterator
        constexpr const_iterator begin() const noexcept
        { return const_iterator(m_start); }

        /// \brief Constant Begin Iterator
        /// 
        /// \details Constant iterator to the beginning 
        /// of the box.
        ///
        /// \returns constexpr const_iterator
        constexpr const_iterator cbegin() const noexcept
        { return const_iterator(m_start); }

        /// \brief Reverse Begin Iterator
        /// 
        /// \details Iterator to the reversed beginning
        /// of the box's data.
        ///
        /// \returns constexpr reverse_iterator
        constexpr reverse_iterator rbegin() noexcept
        { return reverse_iterator(end()); }

        /// \brief Reverse Begin Iterator (const)
        /// 
        /// \details Constant iterator to the reversed 
        /// beginning of the box's data.
        ///
        /// \returns constexpr const_reverse_iterator
        constexpr const_reverse_iterator rbegin() const noexcept
        { return const_reverse_iterator(end()); }

        /// \brief Constant Reverse Begin Iterator
        ///
        /// \details Constant iterator to the reversed
        /// beginning of the box's data.
        ///
        /// \returns constexpr const_reverse_iterator
        constexpr const_reverse_iterator crbegin() const noexcept
        { return const_reverse_iterator(end()); }

        /// \brief End Iterator
        ///
        /// \details Iterator to the end of the 
        /// box's data.
        ///
        /// \returns constexpr iterator
        constexpr iterator end() noexcept
        { return iterator(m_finish); }

        /// \brief End Iterator (const)
        /// 
        /// \details Constant iterator to the 
        /// end of the box's data.
        ///
        /// \returns constexpr const_iterator
        constexpr const_iterator end() const noexcept
        { return const_iterator(m_finish); }

        /// \brief Constant End Iterator
        ///
        /// \details Constant iterator to the
        /// end of the box's data.
        ///
        /// \returns constexpr const_iterator
        constexpr const_iterator cend() const noexcept
        { return const_iterator(m_finish); }

        /// \brief Reverse End Iterator
        ///
        /// \details Iterator to the reversed end
        /// of the box's data.
        ///
        /// \returns constexpr reverse_iterator
        constexpr reverse_iterator rend() noexcept
        { return reverse_iterator(begin()); }

        /// \brief Reverse End Iterator (const)
        ///
        /// \details Constant iterator to the reversed
        /// end of the box's data.
        ///
        /// \returns constexpr const_reverse_iterator
        constexpr const_reverse_iterator rend() const noexcept
        { return const_reverse_iterator(begin()); }

        /// \brief Constant Reverse End Iterator
        ///
        /// \details Constant iterator to the reversed
        /// end of the box's data.
        ///
        /// \returns constexpr const_reverse_iterator
        constexpr const_reverse_iterator crend() const noexcept
        { return const_reverse_iterator(begin()); }

        /// \brief Row Begin Iterator
        ///
        /// \details Returns an iterator to the beginning 
        /// of the indicated row.
        ///
        /// \param row type: size_type | default: 0uL
        /// \returns constexpr row_iterator
        constexpr row_iterator row_begin(size_type row = 0uL)
        {
            _M_range_check(row, 0uL);
            return row_iterator(begin() + _M_index(row, 0uL), row, 0uL, rows(), columns());
        }

        /// \brief Row Begin Iterator (const)
        ///
        /// \details Returns an iterator to the beginning 
        /// of the indicated row.
        ///
        /// \param row type: size_type | default: 0uL
        /// \returns constexpr const_row_iterator
        constexpr const_row_iterator row_begin(size_type row = 0uL) const
        {
            _M_range_check(row, 0uL);
            return const_row_iterator(begin() + _M_index(row, 0uL), row, 0uL, rows(), columns());
        }

        /// \brief Constant Row Begin Iterator
        ///
        /// \details Returns a constant iterator to the 
        /// beginning of the indicated row.
        ///
        /// \param row type: size_type | default: 0uL
        /// \returns constexpr const_row_iterator
        constexpr const_row_iterator row_cbegin(size_type row = 0uL) const
        {
            _M_range_check(row, 0uL);
            return const_row_iterator(cbegin() + _M_index(row, 0uL), row, 0uL, rows(), columns());
        }

        /// \brief Reverse Row Begin Iterator
        ///
        /// \details Returns a reverse iterator to the 
        /// beginning of the indicated reversed row.
        ///
        /// \param row type: size_type | default: 0uL
        /// \returns constexpr reverse_row_iterator
        constexpr reverse_row_iterator row_rbegin(size_type row = 0uL)
        {
            _M_range_check(row, 0uL);
            return reverse_row_iterator(row_end(row));
        }

        /// \brief Reverse Row Begin Iterator (const)
        ///
        /// \details Returns a constant reverse iterator 
        /// to the beginning of the indicated reversed row.
        ///
        /// \param row type: size_type | default: 0uL
        /// \returns constexpr const_reverse_row_iterator
        constexpr const_reverse_row_iterator row_rbegin(size_type row = 0uL) const
        {
            _M_range_check(row, 0uL);
            return const_reverse_row_iterator(row_end(row));
        }

        /// \brief Constant Reverse Row Begin Iterator
        ///
        /// \details Returns a constant reverse iterator 
        /// to the beginning of the indicated reversed row.
        ///
        /// \param row
        /// \returns constexpr const_reverse_row_iterator
        constexpr const_reverse_row_iterator row_crbegin(size_type row = 0uL) const
        {
            _M_range_check(row, 0uL);
            return const_reverse_row_iterator(row_end(row));
        }

        /// \brief Row End Iterator
        ///
        /// \details Returns an iterator to one past the end of the
        /// row, this happens to be the first element in the next row.
        /// This is why the iterator column index is set to 0 and the
        /// row index is one plus the indicated positon.
        ///
        /// \param row type: size_type | default: 0uL
        /// \returns constexpr row_iterator
        constexpr row_iterator row_end(size_type row = 0uL)
        {
            _M_range_check(row, 0uL);
            return row_iterator(begin() + _M_index(row + 1uL, 0uL), row + 1uL, 0uL, rows(), columns());
        }

        /// \brief Row End Iterator (const)
        ///
        /// \details Returns an constant iterator to one past the
        /// end of the row, this happens to be the first element
        /// in the next row. This is why the iterator column index
        /// is set to 0 and the row index is one plus the indicated
        /// positon.
        ///
        /// \param row type: size_type | default: 0uL
        /// \returns constexpr const_row_iterator
        constexpr const_row_iterator row_end(size_type row = 0uL) const
        {
            _M_range_check(row, 0uL);
            return const_row_iterator(begin() + _M_index(row + 1uL, 0uL), row + 1uL, 0uL, rows(), columns());
        }

        /// \brief Constant Row End Iterator
        ///
        /// \details Returns an constant iterator to one past the
        /// end of the row, this happens to be the first element
        /// in the next row. This is why the iterator column index
        /// is set to 0 and the row index is one plus the indicated
        /// positon.
        ///
        /// \param row type: size_type | default: 0uL
        /// \returns constexpr const_row_iterator
        constexpr const_row_iterator row_cend(size_type row = 0uL) const
        {
            _M_range_check(row, 0uL);
            return const_row_iterator(cbegin() + _M_index(row + 1uL, 0uL), row + 1uL, 0uL, rows(), columns());
        }

        /// \brief Reverse Row End Iterator
        ///
        /// \details Returns a reverse iterator to the 
        /// end of the indicated reversed row.
        ///
        /// \param row
        /// \returns constexpr reverse_row_iterator
        constexpr reverse_row_iterator row_rend(size_type row = 0uL)
        {
            _M_range_check(row, 0uL);
            return reverse_row_iterator(row_begin(row));
        }

        /// \brief Reverse Row End Iterator (const)
        ///
        /// \details Returns a constant reverse iterator 
        /// to the end of the indicated reversed row.
        ///
        /// \param row
        /// \returns constexpr const_reverse_row_iterator
        constexpr const_reverse_row_iterator row_rend(size_type row = 0uL) const
        {
            _M_range_check(row, 0uL);
            return const_reverse_row_iterator(row_begin(row));
        }

        /// \brief Constant Reverse Row End Iterator
        ///
        /// \details Returns a constant reverse iterator 
        /// to the end of the indicated reversed row.
        ///
        /// \param row
        /// \returns constexpr const_reverse_row_iterator
        constexpr const_reverse_row_iterator row_crend(size_type row = 0uL) const
        {
            _M_range_check(row, 0uL);
            return const_reverse_row_iterator(row_begin(row));
        }

        /// \brief Column Begin Iterator
        ///
        /// \details Returns an iterator to the 
        /// beginning of the indicated column.
        ///
        /// \param column type: size_type | default: 0uL
        /// \returns constexpr column_iterator
        constexpr column_iterator column_begin(size_type column = 0uL)
        {
            _M_range_check(0uL, column);
            return column_iterator(begin() + _M_index(0uL, column), 0uL, column, rows(), columns());
        }

        /// \brief Column Begin Iterator (const)
        ///
        /// \details Returns a constant iterator to the 
        /// beginning of the indicated column.
        ///
        /// \param column type: size_type | default: 0uL
        /// \returns constexpr const_column_iterator
        constexpr const_column_iterator column_begin(size_type column = 0uL) const
        {
            _M_range_check(0uL, column);
            return const_column_iterator(cbegin() + _M_index(0uL, column), 0uL, column, rows(), columns());
        }

        /// \brief Constant Column Begin Iterator
        ///
        /// \details Returns a constant iterator to the 
        /// beginning of the indicated column.
        ///
        /// \param column type: size_type | default: 0uL
        /// \returns constexpr const_column_iterator
        constexpr const_column_iterator column_cbegin(size_type column = 0uL) const
        {
            _M_range_check(0uL, column);
            return const_column_iterator(cbegin() + _M_index(0uL, column), 0uL, column, rows(), columns());
        }

        /// \brief Reverse Column Begin Iterator
        ///
        /// \details Returns a reverse iterator to the 
        /// beginning of the reversed column.
        ///
        /// \param column type: size_type | default: 0uL
        /// \returns constexpr reverse_column_iterator
        constexpr reverse_column_iterator column_rbegin(size_type column = 0uL)
        {
            _M_range_check(0uL, column);
            return reverse_column_iterator(column_end(column));
        }

        /// \brief Reverse Column Begin Iterator (const)
        ///
        /// \details Returns a constant reverse iterator to 
        /// the beginning of the indicated reversed column.
        ///
        /// \param column type: size_type | default: 0uL
        /// \returns constexpr const_reverse_column_iterator
        constexpr const_reverse_column_iterator column_rbegin(size_type column = 0uL) const
        {
            _M_range_check(0uL, column);
            return const_reverse_column_iterator(column_cend(column));
        }

        /// \brief Constant Reverse Column Begin Iterator
        ///
        /// \details Returns a constant reverse iterator to 
        /// the beginning of the indicated reversed column.
        ///
        /// \param column type: size_type | default: 0uL
        /// \returns constexpr const_reverse_column_iterator
        constexpr const_reverse_column_iterator column_crbegin(size_type column = 0uL) const
        {
            _M_range_check(0uL, column);
            return const_reverse_column_iterator(column_cend(column));
        }

        /// \brief Column End Iterator
        ///
        /// \details Returns an iterator to one past the end of
        /// the column, this happens to be the first element in the
        /// next column. This is why the iterator row index is set
        /// to 0 and the column index is one plus the indicated
        /// position.
        ///
        /// \param column type: size_type | default: 0uL
        /// \returns constexpr column_iterator
        constexpr column_iterator column_end(size_type column = 0uL)
        {
            _M_range_check(0uL, column);
            return column_iterator(begin() + _M_index(0uL, column + 1uL), 0uL, column + 1uL, rows(), columns());
        }

        /// \brief Column End Iterator (const)
        ///
        /// \details Returns a constant iterator to one past the end
        /// of the column, this happens to be the first element in the
        /// next column. This is why the iterator row index is set
        /// to 0 and the column index is one plus the indicated
        /// position.
        ///
        /// \param column type: size_type | default: 0uL
        /// \returns constexpr const_column_iterator
        constexpr const_column_iterator column_end(size_type column = 0uL) const
        {
            _M_range_check(0uL, column);
            return const_column_iterator(cbegin() + _M_index(0uL, column + 1uL), 0uL, column + 1uL, rows(), columns());
        }

        /// \brief Constant Column End Iterator
        ///
        /// \details Returns a constant iterator to one past the end
        /// of the column, this happens to be the first element in the
        /// next column. This is why the iterator row index is set
        /// to 0 and the column index is one plus the indicated
        /// position.
        ///
        /// \param column type: size_type | default: 0uL
        /// \returns constexpr const_column_iterator
        constexpr const_column_iterator column_cend(size_type column = 0uL) const
        {
            _M_range_check(0uL, column);
            return const_column_iterator(cbegin() + _M_index(0uL, column + 1uL), 0uL, column + 1uL, rows(), columns());
        }

        /// \brief Reverse Column End Iterator
        ///
        /// \details Returns a reverse iterator the end of the
        /// reversed column.
        ///
        /// \param column type: size_type | default: 0uL
        /// \returns constexpr reverse_column_iterator
        constexpr reverse_column_iterator column_rend(size_type column = 0uL)
        {
            _M_range_check(0uL, column);
            return reverse_column_iterator(column_begin(column));
        }

        /// \brief Reverse Column End Iterator (const)
        ///
        /// \details Returns a constant reverse iterator the end of
        /// the reversed column.
        ///
        /// \param column type: size_type | default: 0uL
        /// \returns constexpr const_reverse_column_iterator
        constexpr const_reverse_column_iterator column_rend(size_type column = 0uL) const
        {
            _M_range_check(0uL, column);
            return const_reverse_column_iterator(column_cbegin(column));
        }

        /// \brief Constant Reverse Column End Iterator
        ///
        /// \details Returns a constant reverse iterator the end of
        /// the reversed column.
        ///
        /// \param column type: size_type | default: 0uL
        /// \returns constexpr const_reverse_column_iterator
        constexpr const_reverse_column_iterator column_crend(size_type column = 0uL) const
        {
            _M_range_check(0uL, column);
            return const_reverse_column_iterator(column_cbegin(column));
        }


        /// \brief Box Transpose
        ///
        /// \details Performs a box transpose.
        /// Uses std::copy over std::ranges::copy as the output
        /// iterator is required to be std::constructible_v which
        /// column_iterator doesn't satisfy yet.
        ///
        /// \returns constexpr auto
        constexpr auto 
        transpose()
        {
            box<value_type> result(this->columns(), this->rows());

            if (empty())
                return result;

            std::ranges::copy(*this, result.column_begin());

            return result;
        }


        /// \brief Box Map
        ///
        /// \details Maps a function over the box, returning 
        /// the mapped box.
        /// 
        /// \tparam F concept: std::copy_constructible
        /// \param func type: F 
        /// \returns constexpr auto 
        template<std::copy_constructible F>
        constexpr auto
        map(F func) const
        {

            if (empty())
                return box<std::invoke_result_t<F, value_type>>{};
            else
            {
                box<std::invoke_result_t<F, value_type>> result(this->rows(), this->columns());
                std::ranges::transform(*this, result.begin(), func);
                return result;
            }
        }


        /// \brief Map - Range 
        ///
        /// \details Maps a function over the box and another 
        /// range object, returning the mapped box. Returns an 
        /// empty box if `this` is empty.
        /// 
        /// \tparam Rng concept: std::ranges::input_range
        /// \tparam F concept: std::copy_constructible
        /// \param rng type Rng | qualifiers: [move-semantics]
        /// \param func type F
        /// \returns constexpr auto 
        template<std::ranges::input_range Rng, std::copy_constructible F>
        constexpr auto
        map(Rng&& rng, F func) const
        {
            using range_elem_t = typename std::remove_cvref_t<decltype(*std::ranges::begin(rng))>;

            if (empty())
                return box<std::invoke_result_t<F, value_type, range_elem_t>>{};
            else
            {
                box<std::invoke_result_t<F, value_type, range_elem_t>> result(this->rows(), this->columns());
                std::ranges::transform(*this, rng, result.begin(), func);
                return result;
            }
        }


        /// \brief Map - Iterator Pair
        ///
        /// \details Maps a function over the box and a range
        /// denoted by an iterator pair, returning the mapped 
        /// box. Returns an empty box if `this` is empty.
        /// 
        /// \tparam It concept: std::input_iterator
        /// \tparam F concept: std::copy_constructible
        /// \param first type: It 
        /// \param last type It
        /// \param func type: F
        /// \returns constexpr auto 
        template<std::input_iterator It, std::copy_constructible F>
        constexpr auto
        map(It first, It last, F func) const
        {
            using iterator_elem_t = typename std::remove_cvref_t<typename std::iterator_traits<It>::value_type>;

            if (empty())
                return box<std::invoke_result_t<F, value_type, iterator_elem_t>>{};
            else
            {
                box<std::invoke_result_t<F, value_type, iterator_elem_t>> result(this->rows(), this->columns());
                std::ranges::transform(this->begin(), this->end(), first, last, result.begin(), func);
                return result;
            }
        }


        /// \brief Vertical Flip
        ///
        /// \details Performs a vertical flip of the box.
        /// ie. The order of the rows is reversed. If 
        /// `this` box is empty, an empty box is returned
        /// with no memory allocated to it.
        /// 
        /// \returns constexpr auto 
        constexpr auto vflip() const
        {
            if (empty())
                return box<value_type>{};
            else
            {
                box<value_type> result(this->rows(), this->columns());

                for (auto cidx { 0u }; cidx < this->columns(); ++cidx)
                    std::ranges::copy(this->column_begin(cidx), this->column_end(cidx), result.column_rbegin(cidx));

                return result;
            }
        }

        /// \brief Horizontal Flip
        ///
        /// \details Performs a horizontal flip of the box.
        /// ie. The order of the columns is reversed. If 
        /// `this` box is empty, an empty box is returned
        /// with no memory allocated to it.
        /// 
        /// \returns constexpr auto 
        constexpr auto hflip() const
        {
            if (empty())
                return box<value_type>{};
            else
            {
                box<value_type> result(this->rows(), this->columns());
                    for (auto ridx { 0u }; ridx < this->rows(); ++ridx)
                        std::ranges::copy(this->row_begin(ridx), this->row_end(ridx), result.row_rbegin(ridx));

                return result;
            }
        }


        /// \brief Right Rotate
        ///
        /// Rotates the box 90 degrees clockwise. Inverts the 
        /// dimension sizes of the box. If `this` box is empty,
        /// an empty box is returned with no memory allocated to it.
        /// 
        /// \returns constexpr auto 
        constexpr auto rrotate() const
        {
            if (empty())
                return box<value_type>{};
            else
            {
                box<value_type> result(this->columns(), this->rows());

                for (auto cidx { 0u }; cidx < this->columns(); ++cidx)
                    std::ranges::copy(this->column_begin(cidx), this->column_end(cidx), result.row_rbegin(cidx));

                return result;
            }
        }


        /// \brief Left Rotate
        ///
        /// Rotates the box 90 degrees counter-clockwise. Inverts 
        /// the dimension sizes of the box. If `this` box is empty,
        /// an empty box is returned with no memory allocated to it.
        /// 
        /// \returns constexpr auto 
        constexpr auto lrotate() const
        {
            if (empty())
                return box<value_type>{};
            else
            {
                box<value_type> result(this->columns(), this->rows());

                for (auto ridx { 0u }; ridx < this->rows(); ++ridx)
                    std::ranges::copy(this->row_begin(ridx), this->row_end(ridx), result.column_rbegin(ridx));

                return result;
            }
        }

    private:
        /// \brief Allocates Matrix Recources
        ///
        /// \details Allocates the memory for the box
        /// using the allocator of the container. Uses
        /// std::allocator_traits to get the allocators
        /// relevant methods.
        ///
        /// \notes Default allocator is std::allocator<value_type>.
        ///
        /// \param __n type: size_type
        /// \returns constexpr pointer
        constexpr pointer _M_allocate(size_type __n)
        { return __n != 0 ? alloc_traits::allocate(m_allocator, __n) : pointer(); }

        /// \brief Dellocates Matrix Recources
        ///
        /// \details Dellocates the memory for the box
        /// using the allocator of the container. Uses
        /// std::allocator_traits to get the allocators
        /// relevant methods.
        ///
        /// \param __p type: pointer
        /// \param __n type: size_type | attribute: [[maybe_unused]]
        constexpr void _M_deallocate(pointer __p, [[maybe_unused]] size_type __n)
        {
            if (__p)
                alloc_traits::deallocate(m_allocator, __p, __n);
        }

        /// \brief Checks index's are in the bounds of the box
        ///
        /// \details Checks if __column and __row are withing
        /// the box's bounds.
        ///
        /// \exception std::out_of_range
        ///
        /// \param __column type: size_type
        /// \param __row type: size_type
        constexpr void _M_range_check(size_type __row, size_type __column) const
        {
            if (__row >= this->rows() || __column >= this->columns())
                throw std::out_of_range("box::_M_range_check - index out of range.");
        }

        constexpr size_type _M_size(size_type __rows, size_type __columns) const noexcept
        { return __rows * __columns != 0 ? __rows * __columns : std::max(__rows, __columns); }


        constexpr size_type _M_index(size_type __row, size_type __column) const noexcept
        { return __row * columns() + __column; }

        /// \brief Returns the pointer passed to it.
        ///
        /// \tparam _Up
        /// \param __ptr type: _Up*
        /// \returns _Up*
        template <typename _Up>
        _Up *_M_data_ptr(_Up *__ptr) const noexcept
        { return __ptr; }

#if __cplusplus >= 201103L

        /// \brief Returns the pointer passed to it.
        ///
        /// \details If the value given is not a builtin
        /// pointer type, a pointer is created from the
        /// underlying element type.
        ///
        /// \tparam _Ptr
        /// \param __ptr type: _Ptr
        /// \returns typename std::pointer_traits<_Ptr>::element_type*
        template <typename _Ptr>
        typename std::pointer_traits<_Ptr>::element_type *
        _M_data_ptr(_Ptr __ptr) const
        { return empty() ? nullptr : std::to_address(*__ptr); }
#else

        /// \brief Returns the given pointer
        ///
        /// \details Returns the pointer given to it is
        /// a builtin pointer type.
        ///
        /// \tparam _Up
        /// \param __ptr type: _Up*
        /// \returns _Up*
        template <typename _Up>
        _Up *_M_data_ptr(_Up *__ptr) noexcept
        {
            return __ptr;
        }
#endif // __cplusplus >= 201103L
    };  /// class box

    /// \brief Compares two matrices for equality.
    ///
    /// \group box Part of the operator set on boxes that perform comparisons. 
    ///
    /// \details Uses std::equal to compare the matrices.
    /// Takes at least O(n) where n = columns x rows = lhs.end() - lhs.begin()
    ///
    /// \requires Matrix elements support equality comparison
    /// that converts to a bool
    ///
    /// \exception Operation is has no exception iff the comparison
    /// between box elements is noexcept and std::equal is
    /// noexcept across the range
    ///
    /// \tparam _ElemL
    /// \tparam _ElemR
    /// \rparam lhsE type: [_ElemL]
    /// \rparam rhsE type: [_ElemR]
    /// \param lhs type: [box<_ElemL>] | qualifiers: {const, ref}
    /// \param rhs type: [box<_ElemR>] | qualifiers: {const, ref}
    /// \returns true
    /// \returns false
    template <typename _ElemL, typename _ElemR>
#if __cpluscplus >= 202002L
        requires requires(_ElemL lhsE, _ElemR rhsE)
    {
        {
            lhsE == rhsE
            } -> std::convertible_to<bool>;
    }
    constexpr inline bool
    operator== (const box<_ElemL>& lhs, const box<_ElemR>& rhs) noexcept(
        noexcept(std::declval<_ElemL>() == std::declval<_ElemR>())
           & &noexcept(std::ranges::equal(lhs, rhs);))
#else
    inline bool
    operator== (const box<_ElemL>& lhs, const box<_ElemR>& rhs)
#endif
    {
        if (lhs.dimensions() != rhs.dimensions())
            return false;
        return std::ranges::equal(lhs, rhs);
    }

/// Current bug with GCC-11.1 with lexicographical_compare_three_way
/// causes cortex::box to not compile. Issue: PR
/// Current bug with Clang++-12 with lexicographical_compare_three_way
/// cause cortex::box to be compared on box size over value precidence
#if __cpp_lib_three_way_comparison && !(lexicographical_compare_bug)

    /// \brief Spaceship Operator for matrices.
    ///
    /// \group box
    ///
    /// \details Uses std::lexicographical_compare_three_way to
    /// compare the matrices and generates the !=, <, >, <=, >=
    /// operators.
    ///
    /// \tparam _ElemL
    /// \tparam _ElemR
    /// \param lhs type: [box<_ElemL>] | qualifiers: {const, ref}
    /// \param lhs type: [box<_ElemL>] | qualifiers: {const, ref}
    /// \returns constexpr inline auto
    template <typename _ElemL, typename _ElemR>
    constexpr inline auto
    operator<=> (const box<_ElemL>& lhs, const box<_ElemR>& rhs)
    {
        return std::lexicographical_compare_three_way(lhs.begin(), lhs.end(), rhs.begin(), rhs.end(), std::compare_three_way{});
    }

#else // !C++20

    /// \brief Compares two matrices for inequality.
    ///
    /// \group box
    ///
    /// \details Inverts the result of a equality comparison
    /// between two matrices.
    ///
    /// \tparam _ElemL
    /// \tparam _ElemR
    /// \param lhs type: [box<_ElemL>] | qualifiers: {const, ref}
    /// \param rhs type: [box<_ElemR>] | qualifiers: {const, ref}
    /// \returns true
    /// \returns false
    template <typename _ElemL, typename _ElemR>
    inline bool
    operator!= (const box<_ElemL>& lhs, const box<_ElemR>& rhs)
    {
        return !(lhs == rhs);
    }

    /// \brief Compares if a box is lexicographically
    /// less than another.
    ///
    /// \group box
    ///
    /// \tparam _ElemL
    /// \tparam _ElemR
    /// \param lhs type: [box<_ElemL>] | qualifiers: {const, ref}
    /// \param rhs type: [box<_ElemR>] | qualifiers: {const, ref}
    /// \returns true
    /// \returns false
    template <typename _ElemL, typename _ElemR>
    inline bool
    operator< (const box<_ElemL>& lhs, const box<_ElemR>& rhs)
    {
        return std::ranges::lexicographical_compare(lhs, rhs);
    }

    /// \brief Compares if a box is lexicographically
    /// greater than another.
    ///
    /// \group box
    ///
    /// \details Uses less than comparison and swaps the
    /// order of the arguments.
    ///
    /// \tparam _ElemL
    /// \tparam _ElemR
    /// \param lhs type: [box<_ElemL>] | qualifiers: {const, ref}
    /// \param rhs type: [box<_ElemR>] | qualifiers: {const, ref}
    /// \returns true
    /// \returns false
    template <typename _ElemL, typename _ElemR>
    inline bool
    operator> (const box<_ElemL>& lhs, const box<_ElemR>& rhs)
    {
        return rhs < lhs;
    }

    /// \brief Compares if a box is lexicographically
    /// less than or equal to another.
    ///
    /// \group box
    ///
    /// \details Uses less than comparison and swaps the
    /// order of the arguments. If the rhs box is less
    /// than the lhs box, then the lhs box cannot
    /// be less then or equal to the rhs box.
    ///
    /// \tparam _ElemL
    /// \tparam _ElemR
    /// \param lhs type: [box<_ElemL>] | qualifiers: {const, ref}
    /// \param rhs type: [box<_ElemR>] | qualifiers: {const, ref}
    /// \returns true
    /// \returns false
    template <typename _ElemL, typename _ElemR>
    inline bool
    operator<= (const box<_ElemL>& lhs, const box<_ElemR>& rhs)
    {
        return !(rhs < lhs);
    }

    /// \brief Compares if a box is lexicographically
    /// greater than or equal to another.
    ///
    /// \group box
    ///
    /// \details Inverts the result of a less than comparison
    /// between the two matrices.
    ///
    /// \tparam _ElemL
    /// \tparam _ElemR
    /// \param lhs type: [box<_ElemL>] | qualifiers: {const, ref}
    /// \param rhs type: [box<_ElemR>] | qualifiers: {const, ref}
    /// \returns true
    /// \returns false
    template <typename _ElemL, typename _ElemR>
    inline bool
    operator>= (const box<_ElemL>& lhs, const box<_ElemR>& rhs)
    {
        return !(lhs < rhs);
    }

#endif // three way compare

    /// \brief Scalar Equality Comparison
    ///
    /// \group box
    ///
    /// \details Compares each value within the box to a given
    /// scalar. Creates a bit mask (or boolean mask) of the values
    /// that are equal as true and the everything else as false.
    ///
    /// \requires Comparison of scalar type and box type support
    /// equality comparison that results in a bool.
    ///
    /// \exception Operation is noexcept iff the inequlity comparison
    /// between the scalar and the box element's types is noexcept.
    ///
    /// \tparam E
    ///
    /// \param bx type: [box<E>] | qualifiers: {const, ref}
    /// \param scalar type: [E] | qualifiers: {const, ref}
    /// \returns box<bool>
    template <typename E>
#if __cpluscplus >= 202002L
        requires requires(E lhsE, E rhsE)
                { { lhsE == rhsE } -> std::convertible_to<bool>; }
    constexpr inline auto
    operator== (const box<E>& bx, const E& scalar) noexcept(noexcept(std::declval<E>() == std::declval<E>()))
        -> box<bool>
#else
    inline auto
    operator== (const box<E>& bx, const E& scalar)
        -> box<bool>
#endif
    {
        box<bool> result(bx.rows(), bx.columns(), false);
        std::ranges::transform(bx, result.begin(), [&](const E& bxE)
                               { return bxE == scalar; });
        return result;
    }

    /// \brief Scalar Inequality Comparison
    ///
    /// \group box
    ///
    /// \details Compares each value within the box to a given
    /// scalar. Creates a bit mask (or boolean mask) of the values
    /// that are inequal as true and the everything else as false.
    ///
    /// \requires Comparison of scalar type and box type support
    /// inequality comparison that results in a bool.
    ///
    /// \exception Operation is noexcept iff the inequlity comparison
    /// between the scalar and the box element's types is noexcept.
    ///
    /// \tparam E
    ///
    /// \param bx type: [box<E>] | qualifiers: {const, ref}
    /// \param scalar type: [E] | qualifiers: {const, ref}
    /// \returns box<bool>
    template <typename E>
#if __cpluscplus >= 202002L
        requires requires(E lhsE, E rhsE)
                { { lhsE != rhsE } -> std::convertible_to<bool>; }
    constexpr inline auto
    operator!= (const box<E>& bx, const E& scalar) noexcept(noexcept(std::declval<E>() != std::declval<E>()))
        -> box<bool>
#else
    inline auto
    operator!= (const box<E>& bx, const E& scalar)
        -> box<bool>
#endif
    {
        box<bool> result(bx.rows(), bx.columns(), false);
        std::ranges::transform(bx, result.begin(), [&](const E& bxE)
                               { return bxE != scalar; });
        return result;
    }

    /// \brief Scalar Less-Then Comparison
    ///
    /// \group box
    ///
    /// \details Compares each value within the box to a given
    /// scalar. Creates a bit mask (or boolean mask) of the values
    /// that are less-than as true and the everything else as false.
    ///
    /// \requires Comparison of scalar type and box type support
    /// less-than comparison that results in a bool.
    ///
    /// \exception Operation is noexcept iff the less-than comparison
    /// between the scalar and the box element's types is noexcept.
    ///
    /// \tparam E
    ///
    /// \param bx type: [box<E>] | qualifiers: {const, ref}
    /// \param scalar type: [E] | qualifiers: {const, ref}
    /// \returns box<bool>
    template <typename E>
#if __cpluscplus >= 202002L
        requires requires(E lhsE, E rhsE)
                { { lhsE < rhsE } -> std::convertible_to<bool>; }
    constexpr inline auto
    operator< (const box<E>& bx, const E& scalar) noexcept(noexcept(std::declval<E>() < std::declval<E>()))
        -> box<bool>
#else
    inline auto
    operator< (const box<E>& bx, const E& scalar)
        -> box<bool>
#endif
    {
        box<bool> result(bx.rows(), bx.columns(), false);
        std::ranges::transform(bx, result.begin(), [&](const E& bxE)
                               { return bxE < scalar; });
        return result;
    }

    /// \brief Scalar Greater-Then Comparison
    ///
    /// \group box
    ///
    /// \details Compares each value within the box to a given
    /// scalar. Creates a bit mask (or boolean mask) of the values
    /// that are greater-than as true and the everything else as false.
    ///
    /// \requires Comparison of scalar type and box type support
    /// greater-than comparison that results in a bool.
    ///
    /// \exception Operation is noexcept iff the greater-than comparison
    /// between the scalar and the box element's types is noexcept.
    ///
    /// \tparam E
    ///
    /// \param bx type: [box<E>] | qualifiers: {const, ref}
    /// \param scalar type: [E] | qualifiers: {const, ref}
    /// \returns box<bool>
    template <typename E>
#if __cpluscplus >= 202002L
        requires requires(E lhsE, E rhsE)
                { { lhsE > rhsE } -> std::convertible_to<bool>; }
    constexpr inline auto
    operator> (const box<E>& bx, const E& scalar) noexcept(noexcept(std::declval<E>() > std::declval<E>()))
        -> box<bool>
#else
    inline auto
    operator> (const box<E>& bx, const E& scalar)
        -> box<bool>
#endif
    {
        box<bool> result(bx.rows(), bx.columns(), false);
        std::ranges::transform(bx, result.begin(), [&](const E& bxE)
                               { return bxE > scalar; });
        return result;
    }

    /// \brief Scalar Less-Then-Equal Comparison
    ///
    /// \group box
    ///
    /// \details Compares each value within the box to a given
    /// scalar. Creates a bit mask (or boolean mask) of the values
    /// that are less-than-eqaul as true and the everything else as
    /// false.
    ///
    /// \requires Comparison of scalar type and box type support
    /// less-than comparison that results in a bool.
    ///
    /// \exception Operation is noexcept iff the less-than-equal comparison
    /// between the scalar and the box element's types is noexcept.
    ///
    /// \tparam E
    ///
    /// \param bx type: [box<E>] | qualifiers: {const, ref}
    /// \param scalar type: [E] | qualifiers: {const, ref}
    /// \returns box<bool>
    template <typename E>
#if __cpluscplus >= 202002L
        requires requires(E lhsE, E rhsE)
                { { lhsE <= rhsE } -> std::convertible_to<bool>; }
    constexpr inline auto
    operator<= (const box<E>& bx, const E& scalar) noexcept(noexcept(std::declval<E>() > std::declval<E>()))
        -> box<bool>
#else
    inline auto
    operator<= (const box<E>& bx, const E& scalar)
        -> box<bool>
#endif
    {
        box<bool> result(bx.rows(), bx.columns(), false);
        std::ranges::transform(bx, result.begin(), [&](const E& bxE)
                               { return bxE <= scalar; });
        return result;
    }

    /// \brief Scalar Greater-Then-Equal Comparison
    ///
    /// \group box
    ///
    /// \details Compares each value within the box to a given
    /// scalar. Creates a bit mask (or boolean mask) of the values
    /// that are greater-than-equal as true and the everything else
    /// as false.
    ///
    /// \requires Comparison of scalar type and box type support
    /// greater-than-equal comparison that results in a bool.
    ///
    /// \exception Operation is noexcept iff the greater-than-equal
    /// comparison between the scalar and the box element's types
    /// is noexcept.
    ///
    /// \tparam E
    ///
    /// \param bx type: [box<E>] | qualifiers: {const, ref}
    /// \param scalar type: [E] | qualifiers: {const, ref}
    /// \returns box<bool>
    template <typename E>
#if __cpluscplus >= 202002L
        requires requires(E lhsE, E rhsE)
                { { lhsE >= rhsE } -> std::convertible_to<bool>; }
    constexpr inline auto
    operator>= (const box<E>& bx, const E& scalar) noexcept(noexcept(std::declval<E>() > std::declval<E>()))
        -> box<bool>
#else
    inline auto
    operator>= (const box<E>& bx, const E& scalar)
        -> box<bool>
#endif
    {
        box<bool> result(bx.rows(), bx.columns(), false);
        std::ranges::transform(bx, result.begin(), [&](const E& bxE)
                               { return bxE >= scalar; });
        return result;
    }


    /// @brief Map Operator
    ///
    /// \group box
    ///
    /// \details Maps a function over the elements of a box
    /// and returns a new box with the mapped values. 
    /// 
    /// @tparam E concept: Any
    /// @tparam F concept: std::copy_constructible
    /// @param bx type: box<E> | qualifiers: {const, ref}
    /// @param f type: F
    /// @return constexpr auto 
    template<Any E, std::copy_constructible F>
    constexpr auto
    operator|| (const box<E>& bx, F f)
    { return bx.map(f); }


    /// \brief Addition Operator
    ///
    /// \group box
    ///
    /// \detail Operator overload for `+` operator.
    /// Calls lx `map` function with the `+` operator
    /// and rx as the other input range.
    /// 
    /// \tparam L concept: concept: Addable
    /// \tparam R concept: concept: Addable
    /// \param lx type: box<L> | qualifiers: {const, ref}
    /// \param rx type: box<R> | qualifiers: {const, ref}
    /// \returns constexpr auto 
    template<Addable L, Addable R>
        requires AddableWith<L, R>
    constexpr auto
    operator+ (const box<L>& lx, const box<R>& rx)
    { return lx.map(rx, std::plus{}); }


    /// \brief Additon Assignment Operator
    ///
    /// \group box
    ///
    /// \details Operator overload for `+=` operator.
    /// Uses `+` operator on lx and rx and assigns the 
    /// result to lx.
    ///
    /// \notes The left-hand-side box is mutable.
    /// \notes The left-hand-side boxes type but be
    /// able to to store the resulting type of the
    /// call to `add`.
    ///
    /// \exception std::invalid_argument Throw if the left-hand-side
    /// box cannot store the operations resulting type.
    /// 
    /// \tparam L concept: concept: Addable
    /// \tparam R concept: concept: Addable
    /// \param lx type: box<L> | qualifiers: {ref}
    /// \param rx type: box<R> | qualifiers: {const, ref}
    /// \returns constexpr void
    template<Addable L, Addable R>
        requires AddableWith<L, R>
    constexpr void
    operator+= (box<L>& lx, const box<R>& rx) 
    { 
        if constexpr (!std::same_as<std::invoke_result_t<std::plus<void>, L, R>, L>)
            throw std::invalid_argument("operator+=: left-hand-side box type cannot store the resulting type.");
        else
            lx = lx + rx;
    }


    /// \brief Subtraction Operator
    ///
    /// \group box
    ///
    /// \detail Operator overload for `-` operator.
    /// Calls lx `map` function with the `-` operator
    /// and rx as the other input range.
    /// 
    /// \tparam L concept: Subtractable
    /// \tparam R concept: Subtractable
    /// \param lx type: box<L> | qualifiers: {const, ref}
    /// \param rx type: box<R> | qualifiers: {const, ref}
    /// \returns constexpr auto 
    template<Subtractable L, Subtractable R>
        requires SubtractableWith<L, R>
    constexpr auto
    operator- (const box<L>& lx, const box<R>& rx)
    { return lx.map(rx, std::minus{}); }


    /// \brief Subtraction Assignment Operator
    ///
    /// \group box
    ///
    /// \details Operator overload for `-=` operator.
    /// Uses `-` operator on lx and rx and assigns the 
    /// result to lx.
    ///
    /// \notes The left-hand-side box is mutable.
    /// \notes The left-hand-side boxes type but be
    /// able to to store the resulting type of the
    /// call to `sub`.
    ///
    /// \exception std::invalid_argument Throw if the left-hand-side
    /// box cannot store the operations resulting type.
    /// 
    /// \tparam L concept: concept: Subtractable
    /// \tparam R concept: concept: Subtractable
    /// \param lx type: box<L> | qualifiers: [ref]
    /// \param rx type: box<R> | qualifiers: {const, ref}
    /// \returns constexpr void
    template<Subtractable L, Subtractable R>
        requires SubtractableWith<L, R>
    constexpr void
    operator-= (box<L>& lx, const box<R>& rx) 
    { 
        if constexpr (!std::same_as<std::invoke_result_t<std::minus<void>, L, R>, L>)
            throw std::invalid_argument("operator-=: left-hand-side box type cannot store the resulting type.");
        else
            lx = lx - rx;
    }


    /// \brief Multiplication Operator
    ///
    /// \group box
    ///
    /// \detail Operator overload for `*` operator.
    /// Calls lx `map` function with the `*` operator
    /// and rx as the other input range.
    /// 
    /// \tparam L concept: Multiplicable
    /// \tparam R concept: Multiplicable
    /// \param lx type: box<L> | qualifiers: {const, ref}
    /// \param rx type: box<R> | qualifiers: {const, ref}
    /// \returns constexpr auto 
    template<Multiplicable L, Multiplicable R>
        requires MultiplicableWith<L, R>
    constexpr auto
    operator* (const box<L>& lx, const box<R>& rx)
    { return lx.map(rx, std::multiplies{}); }


    /// \brief Multiplication Operator
    ///
    /// \group box
    ///
    /// \details Operator overload for `*` operator.
    /// Calls lx `map` function with the `*` operator
    /// and captures sx by reference in the lambda.
    /// 
    /// \tparam E concept: Any
    /// \tparam S concept: Any
    /// \param bx type: box<E> | qualifiers: {const, ref}
    /// \param sx type: S | qualifiers: {const, ref}
    /// \returns constexpr auto 
    template<Any E, Any S>
        requires MultiplicableWith<E, S>
    constexpr auto
    operator* (const box<E>& bx, const S& sx)
    { return bx.map([&](const auto& elem){ return elem * sx; }); }


    /// \brief Multiplication Operator
    ///
    /// \group box
    ///
    /// \details Operator overload for `*` operator.
    /// Calls lx `map` function with the `*` operator
    /// and captures sx by reference in the lambda.
    /// 
    /// \tparam S concept: Any
    /// \tparam E concept: Any
    /// \param sx type: S | qualifiers: {const, ref}
    /// \param bx type: box<E> | qualifiers: {const, ref}
    /// \returns constexpr auto 
    template<Any S, Any E>
        requires MultiplicableWith<S, E>
    constexpr auto
    operator* (const S& sx, const box<E>& bx)
    { return bx.map([&](const auto& elem){ return sx * elem; }); }


    /// \brief Multiplication Assignment Operator
    ///
    /// \group box
    ///
    /// \detail Operator overload for `*=` operator.
    /// Uses `*` operator on lx and rx and assigns the 
    /// result to lx.
    ///
    /// \notes The left-hand-side box is mutable.
    /// \notes The left-hand-side boxes type must be
    /// able to to store the resulting type of the
    /// call to `mul`.
    ///
    /// \exception std::invalid_argument Throw if the left-hand-side
    /// box cannot store the operations resulting type.
    /// 
    /// \tparam L concept: concept: Any
    /// \tparam R concept: concept: Any
    /// \param lx type: box<L> | qualifiers: {const, ref}
    /// \param rx type: box<R> | qualifiers: {const, ref}
    /// \returns requires constexpr 
    template<Any L, Any R>
        requires MultiplicableWith<L, R>
    constexpr void
    operator*= (box<L>& lx, const box<R>& rx)
    {
        if constexpr (!std::same_as<std::invoke_result_t<std::multiplies<void>, L, R>, L>)
            throw std::invalid_argument("operator*=: left-hand-side box type cannot store the resulting type.");
        else
            lx = lx * rx;
    }


    /// \brief Multiplication Assignment Operator
    ///
    /// \group box
    /// 
    /// \details Operator overload for `*=` operator.
    /// Uses `*` operator on lx and rx and assigns the 
    /// result to lx.
    ///
    /// \notes The left-hand-side box is mutable.
    /// \notes The left-hand-side boxes type must be
    /// able to to store the resulting type of the
    ///
    /// \exception std::invalid_argument Throw if the left-hand-side
    /// box cannot store the operations resulting type.
    ///
    /// \tparam E concept: Any
    /// \tparam S concept: Any
    /// \param bx type: box<E> | qualifiers: {const, ref}
    /// \param sx type: S | qualifiers: {const, ref}
    /// \returns requires constexpr 
    template<Any E, Any S>
        requires MultiplicableWith<E, S>
    constexpr void
    operator*= (box<E>& bx, const S& sx)
    {
        if constexpr (!std::same_as<std::invoke_result_t<std::multiplies<void>, E, S>, E>)
            throw std::invalid_argument("operator*=: left-hand-side box type cannot store the resulting type.");
        else
            bx = bx * sx;
    }


    /// \brief Division Operator
    ///
    /// \group box
    ///
    /// \detail Operator overload for `/` operator.
    /// Calls lx `map` function with the `/` operator
    /// and rx as the other input range.
    /// 
    /// \tparam L concept: concept: Divisible
    /// \tparam R concept: concept: Divisible
    /// \param lx type: box<L> | qualifiers: {const, ref}
    /// \param rx type: box<R> | qualifiers: {const, ref}
    /// \returns constexpr auto 
    template<Divisible L, Divisible R>
        requires DivisibleWith<L, R>
    constexpr auto
    operator/ (const box<L>& lx, const box<R>& rx)
    { return lx.map(rx, std::divides{}); }


    /// \brief Division Operator
    ///
    /// \group box
    ///
    /// \details Operator overload for `/` operator.
    /// Calls lx `map` function with the `*` operator
    /// and captures sx by reference in the lambda.
    /// 
    /// \tparam E concept: Any
    /// \tparam S concept: Any
    /// \param bx type: box<E> | qualifiers: {const, ref}
    /// \param sx type: S | qualifiers: {const, ref}
    /// \returns constexpr auto 
    template<Any E, Any S>
        requires DivisibleWith<E, S>
    constexpr auto
    operator/ (const box<E>& bx, const S& sx)
    { return bx.map([&](const auto& elem){ return elem / sx; }); }


    /// \brief Division Assignment Operator
    ///
    /// \group box
    ///
    /// \detail Operator overload for `/=` operator.
    /// Uses `/` operator on lx and rx and assigns the 
    /// result to lx.
    ///
    /// \notes The left-hand-side box is mutable.
    /// \notes The left-hand-side boxes type must be
    /// able to to store the resulting type of the
    /// call to `div`.
    ///
    /// \exception std::invalid_argument Throw if the left-hand-side
    /// box cannot store the operations resulting type.
    /// 
    /// \tparam L concept: concept: Any
    /// \tparam R concept: concept: Any
    /// \param lx type: box<L> | qualifiers: {const, ref}
    /// \param rx type: box<R> | qualifiers: {const, ref}
    /// \returns constexpr auto 
    template<Any L, Any R>
        requires DivisibleWith<L, R>
    constexpr void
    operator/= (box<L>& lx, const box<R>& rx)
    {
        if constexpr (!std::same_as<std::invoke_result_t<std::divides<void>, L, R>, L>)
            throw std::invalid_argument("operator/=: left-hand-side box type cannot store the resulting type.");
        else
            lx = lx / rx;
    }


    /// \brief Division Assignment Operator
    ///
    /// \group box
    /// 
    /// \details Operator overload for `/=` operator.
    /// Uses `/` operator on lx and rx and assigns the 
    /// result to lx.
    ///
    /// \notes The left-hand-side box is mutable.
    /// \notes The left-hand-side boxes type must be
    /// able to to store the resulting type of the
    ///
    /// \exception std::invalid_argument Throw if the left-hand-side
    /// box cannot store the operations resulting type.
    ///
    /// \tparam E concept: Any
    /// \tparam S concept: Any
    /// \param bx type: box<E> | qualifiers: {const, ref}
    /// \param sx type: S | qualifiers: {const, ref}
    /// \returns requires constexpr 
    template<Any E, Any S>
        requires DivisibleWith<E, S>
    constexpr void
    operator/= (box<E>& bx, const S& sx)
    {
        if constexpr (!std::same_as<std::invoke_result_t<std::divides<void>, E, S>, E>)
            throw std::invalid_argument("operator/=: left-hand-side box type cannot store the resulting.");
        else
            bx = bx / sx;
    }


    /// \brief Modulo Operator
    ///
    /// \group box
    ///
    /// \detail Operator overload for `%` operator.
    /// Calls lx `map` function with the `%` operator
    /// and rx as the other input range.
    /// 
    /// \tparam L concept: concept: Modulo
    /// \tparam R concept: concept: Modulo
    /// \param lx type: box<L> | qualifiers: {const, ref}
    /// \param rx type: box<R> | qualifiers: {const, ref}
    /// \returns constexpr auto 
    template<Modulo L, Modulo R>
        requires ModuloWith<L, R>
    constexpr auto
    operator% (const box<L>& lx, const box<R>& rx)
    { return lx.map(rx, std::modulus{}); }


    /// \brief Modulo Operator
    ///
    /// \group box
    ///
    /// \details Operator overload for `%` operator.
    /// Calls lx `map` function with the `%` operator
    /// and captures sx by reference in the lambda.
    /// 
    /// \tparam E concept: Any
    /// \tparam S concept: Any
    /// \param bx type: box<E> | qualifiers: {const, ref}
    /// \param sx type: S | qualifiers: {const, ref}
    /// \returns constexpr auto
    template<Any E, Any S>
        requires ModuloWith<E, S>
    constexpr auto
    operator% (const box<E>& bx, const S& sx)
    { return bx.map([&](const auto& elem){ return elem % sx; }); }


    /// \brief Modulo Assignment Operator
    ///
    /// \group box
    ///
    /// \detail Operator overload for `%=` operator.
    /// Uses `%` operator on lx and rx and assigns the 
    /// result to lx.
    ///
    /// \notes The left-hand-side box is mutable.
    /// \notes The left-hand-side boxes type must be
    /// able to to store the resulting type of the
    /// call to `mod`.
    ///
    /// \exception std::invalid_argument Throw if the left-hand-side
    /// box cannot store the operations resulting type.
    /// 
    /// \tparam L concept: concept: Any
    /// \tparam R concept: concept: Any
    /// \param lx type: box<L> | qualifiers: {const, ref}
    /// \param rx type: box<R> | qualifiers: {const, ref}
    /// \returns requires constexpr 
    template<Any L, Any R>
        requires ModuloWith<L, R>
    constexpr void
    operator%= (box<L>& lx, const box<R>& rx)
    {
        if constexpr (!std::same_as<std::invoke_result_t<std::modulus<void>, L, R>, L>)
            throw std::invalid_argument("operator%=: left-hand-side box type cannot store the resulting type.");
        else
            lx = lx % rx;
    }


    /// \brief Modulo Assignment Operator
    ///
    /// \group box
    /// 
    /// \details Operator overload for `%=` operator.
    /// Uses `%` operator on lx and rx and assigns the 
    /// result to lx.
    ///
    /// \notes The left-hand-side box is mutable.
    /// \notes The left-hand-side boxes type must be
    /// able to to store the resulting type of the
    ///
    /// \exception std::invalid_argument Throw if the left-hand-side
    /// box cannot store the operations resulting type.
    ///
    /// \tparam E concept: Any
    /// \tparam S concept: Any
    /// \param bx type: box<E> | qualifiers: {const, ref}
    /// \param sx type: S | qualifiers: {const, ref}
    /// \returns requires constexpr 
    template<Any E, Any S>
        requires ModuloWith<E, S>
    constexpr void
    operator%= (box<E>& bx, const S& sx)
    {
        if constexpr (!std::same_as<std::invoke_result_t<std::modulus<void>, E, S>, E>)
            throw std::invalid_argument("operator%=: left-hand-side box type cannot store the resulting type.");
        else
            bx = bx % sx;
    }


    /// \brief Bit And Operator
    ///
    /// \group box
    ///
    /// \detail Operator overload for `&` operator.
    /// Calls lx `map` function with the `&` operator
    /// and captures sx by reference in the lambda.
    /// 
    /// \tparam L concept: concept: BitAnd
    /// \tparam R concept: concept: BitAnd
    /// \param lx type: box<L> | qualifiers: {const, ref}
    /// \param rx type: box<R> | qualifiers: {const, ref}
    /// \returns constexpr auto 
    template<BitAnd L, BitAnd R>
        requires BitAndWith<L, R>
    constexpr auto
    operator& (const box<L>& lx, const box<R>& rx)
    { return lx.map(rx, std::bit_and{}); }


    /// \brief Bit And Operator
    ///
    /// \group box
    ///
    /// \details Operator overload for `&` operator.
    /// Calls bx `bit_and` method on scalar sx and returns
    /// the resulting box.
    /// 
    /// \tparam E concept: Any
    /// \tparam S concept: Any
    /// \param bx type: box<E> | qualifiers: {const, ref}
    /// \param sx type: S | qualifiers: {const, ref}
    /// \returns constexpr auto 
    template<Any E, Any S>
        requires BitAndWith<E, S>
    constexpr auto
    operator& (const box<E>& bx, const S& sx)
    { return bx.map([&](const auto& elem){ return elem & sx; }); }


    /// \brief Bit And Operator
    ///
    /// \group box
    ///
    /// \details Operator overload for `&` operator.
    /// Calls lx `map` function with the `&` operator
    /// and captures sx by reference in the lambda.
    /// 
    /// \tparam S concept: Any
    /// \tparam E concept: Any
    /// \param sx type: S | qualifiers: {const, ref}
    /// \param bx type: box<E> | qualifiers: {const, ref}
    /// \returns constexpr auto 
    template<Any S, Any E>
        requires BitAndWith<S, E>
    constexpr auto
    operator& (const S& sx, const box<E>& bx)
    { return bx.map([&](const auto& elem){ return sx & elem; }); }


    /// \brief Bit And Assignment Operator
    ///
    /// \group box
    ///
    /// \detail Operator overload for `&=` operator.
    /// Uses `&` operator on lx and rx and assigns the 
    /// result to lx.
    ///
    /// \notes The left-hand-side box is mutable.
    /// \notes The left-hand-side boxes type must be
    /// able to to store the resulting type of the
    /// call to `bit_and`.
    ///
    /// \exception std::invalid_argument Throw if the left-hand-side
    /// box cannot store the operations resulting type.
    /// 
    /// \tparam L concept: concept: Any
    /// \tparam R concept: concept: Any
    /// \param lx type: box<L> | qualifiers: {const, ref}
    /// \param rx type: box<R> | qualifiers: {const, ref}
    /// \returns requires constexpr 
    template<Any L, Any R>
        requires BitAndWith<L, R>
    constexpr void
    operator&= (box<L>& lx, const box<R>& rx)
    {
        if constexpr (!std::same_as<std::invoke_result_t<std::bit_and<void>, L, R>, L>)
            throw std::invalid_argument("operator&=: left-hand-side box type cannot store the resulting type.");
        else
            lx = lx & rx;
    }


    /// \brief Bit And Assignment Operator
    ///
    /// \group box
    /// 
    /// \details Operator overload for `&=` operator.
    /// Uses `&` operator on lx and rx and assigns the 
    /// result to lx.
    ///
    /// \notes The left-hand-side box is mutable.
    /// \notes The left-hand-side boxes type must be
    /// able to to store the resulting type of the
    ///
    /// \exception std::invalid_argument Throw if the left-hand-side
    /// box cannot store the operations resulting type.
    ///
    /// \tparam E concept: Any
    /// \tparam S concept: Any
    /// \param bx type: box<E> | qualifiers: {const, ref}
    /// \param sx type: S | qualifiers: {const, ref}
    /// \returns requires constexpr 
    template<Any E, Any S>
        requires BitAndWith<E, S>
    constexpr void
    operator&= (box<E>& bx, const S& sx)
    {
        if constexpr (!std::same_as<std::invoke_result_t<std::bit_and<void>, E, S>, E>)
            throw std::invalid_argument("operator&=: left-hand-side box type cannot store the resulting type.");
        else
            bx = bx & sx;
    }


    /// \brief Bit Or Operator
    ///
    /// \group box
    ///
    /// \detail Operator overload for `|` operator.
    /// Calls lx `map` method on rx and returns 
    /// the result. 
    /// 
    /// \tparam L concept: concept: BitOr
    /// \tparam R concept: concept: BitOr
    /// \param lx type: box<L> | qualifiers: {const, ref}
    /// \param rx type: box<R> | qualifiers: {const, ref}
    /// \returns constexpr auto 
    template<BitOr L, BitOr R>
        requires BitOrWith<L, R>
    constexpr auto
    operator| (const box<L>& lx, const box<R>& rx)
    { return lx.map(rx, std::bit_or{}); }


    /// \brief Bit Or Operator
    ///
    /// \group box
    ///
    /// \details Operator overload for `|` operator.
    /// Calls lx `map` function with the `|` operator
    /// and captures sx by reference in the lambda.
    /// 
    /// \tparam E concept: Any
    /// \tparam S concept: Any
    /// \param bx type: box<E> | qualifiers: {const, ref}
    /// \param sx type: S | qualifiers: {const, ref}
    /// \returns constexpr auto 
    template<Any E, Any S>
        requires BitOrWith<E, S>
    constexpr auto
    operator| (const box<E>& bx, const S& sx)
    { return bx.map([&](const auto& elem){ return elem | sx; }); }


    /// \brief Bit Or Operator
    ///
    /// \group box
    ///
    /// \details Operator overload for `|` operator.
    /// Calls lx `map` function with the `|` operator
    /// and captures sx by reference in the lambda.
    /// 
    /// \tparam S concept: Any
    /// \tparam E concept: Any
    /// \param sx type: S | qualifiers: {const, ref}
    /// \param bx type: box<E> | qualifiers: {const, ref}
    /// \returns requires constexpr 
    template<Any S, Any E>
        requires BitOrWith<S, E>
    constexpr auto
    operator| (const S& sx, const box<E>& bx)
    { return bx.map([&](const auto& elem){ return sx | elem; }); }


    /// \brief Bit Or Assignment Operator
    ///
    /// \group box
    ///
    /// \detail Operator overload for `|=` operator.
    /// Uses `|` operator on lx and rx and assigns the 
    /// result to lx.
    ///
    /// \notes The left-hand-side box is mutable.
    /// \notes The left-hand-side boxes type must be
    /// able to to store the resulting type of the
    /// call to `bit_or`.
    ///
    /// \exception std::invalid_argument Throw if the left-hand-side
    /// box cannot store the operations resulting type.
    /// 
    /// \tparam L concept: concept: Any
    /// \tparam R concept: concept: Any
    /// \param lx type: box<L> | qualifiers: {const, ref}
    /// \param rx type: box<R> | qualifiers: {const, ref}
    /// \returns requires constexpr 
    template<Any L, Any R>
        requires BitOrWith<L, R>
    constexpr void
    operator|= (box<L>& lx, const box<R>& rx)
    {
        if constexpr (!std::same_as<std::invoke_result_t<std::bit_or<void>, L, R>, L>)
            throw std::invalid_argument("operator|=: left-hand-side box type cannot store the resulting type.");
        else
            lx = lx | rx;
    }


    /// \brief Bit Or Assignment Operator
    ///
    /// \group box
    /// 
    /// \details Operator overload for `|=` operator.
    /// Uses `|` operator on lx and rx and assigns the 
    /// result to lx.
    ///
    /// \notes The left-hand-side box is mutable.
    /// \notes The left-hand-side boxes type must be
    /// able to to store the resulting type of the
    ///
    /// \exception std::invalid_argument Throw if the left-hand-side
    /// box cannot store the operations resulting type.
    ///
    /// \tparam E concept: Any
    /// \tparam S concept: Any
    /// \param bx type: box<E> | qualifiers: {const, ref}
    /// \param sx type: S | qualifiers: {const, ref}
    /// \returns requires constexpr 
    template<Any E, Any S>
        requires BitOrWith<E, S>
    constexpr void
    operator|= (box<E>& bx, const S& sx)
    {
        if constexpr (!std::same_as<std::invoke_result_t<std::bit_or<void>, E, S>, E>)
            throw std::invalid_argument("operator|=: left-hand-side box type cannot store the resulting type.");
        else
            bx = bx | sx;
    }


    /// \brief Bit Xor Operator
    ///
    /// \group box
    ///
    /// \detail Operator overload for `^` operator.
    /// Calls lx `map` method on rx and returns 
    /// the result. 
    /// 
    /// \tparam L concept: concept: BitXor
    /// \tparam R concept: concept: BitXor
    /// \param lx type: box<L> | qualifiers: {const, ref}
    /// \param rx type: box<R> | qualifiers: {const, ref}
    /// \returns constexpr auto 
    template<BitXor L, BitXor R>
        requires BitXorWith<L, R>
    constexpr auto
    operator^ (const box<L>& lx, const box<R>& rx)
    { return lx.map(rx, std::bit_xor{}); }


    /// \brief Bit Xor Operator
    ///
    /// \group box
    ///
    /// \details Operator overload for `^` operator.
    /// Calls lx `map` function with the `^` operator
    /// and captures sx by reference in the lambda.
    /// 
    /// \tparam E concept: Any
    /// \tparam S concept: Any
    /// \param bx type: box<E> | qualifiers: {const, ref}
    /// \param sx type: S | qualifiers: {const, ref}
    /// \returns requires constexpr 
    template<Any E, Any S>
        requires BitXorWith<E, S>
    constexpr auto
    operator^ (const box<E>& bx, const S& sx)
    { return bx.map([&](const auto& elem){ return elem ^ sx; }); }


    /// \brief Bit Xor Operator
    ///
    /// \group box
    ///
    /// \details Operator overload for `^` operator.
    /// Calls lx `map` function with the `^` operator
    /// and captures sx by reference in the lambda.
    /// 
    /// \tparam S concept: Any
    /// \tparam E concept: Any
    /// \param sx type: S | qualifiers: {const, ref}
    /// \param bx type: box<E> | qualifiers: {const, ref}
    /// \returns requires constexpr 
    template<Any S, Any E>
        requires BitXorWith<S, E>
    constexpr auto
    operator^ (const S& sx, const box<E>& bx)
    { return bx.map([&](const auto elem){ return sx ^ elem; }); }


    /// \brief Bit Xor Assignment Operator
    ///
    /// \group box
    ///
    /// \detail Operator overload for `^=` operator.
    /// Uses `^` operator on lx and rx and assigns the 
    /// result to lx.
    ///
    /// \notes The left-hand-side box is mutable.
    /// \notes The left-hand-side boxes type must be
    /// able to to store the resulting type of the
    /// call to `bit_xor`.
    ///
    /// \exception std::invalid_argument Throw if the left-hand-side
    /// box cannot store the operations resulting type.
    /// 
    /// \tparam L concept: concept: Any
    /// \tparam R concept: concept: Any
    /// \param lx type: box<L> | qualifiers: {const, ref}
    /// \param rx type: box<R> | qualifiers: {const, ref}
    /// \returns requires constexpr 
    template<Any L, Any R>
        requires BitXorWith<L, R>
    constexpr void
    operator^= (box<L>& lx, const box<R>& rx)
    {
        if constexpr (!std::same_as<std::invoke_result_t<std::bit_xor<void>, L, R>, L>)
            throw std::invalid_argument("operator^=: left-hand-side box type cannot store the resulting type.");
        else
            lx = lx ^ rx;
    }


    /// \brief Bit Xor Assignment Operator
    ///
    /// \group box
    /// 
    /// \details Operator overload for `^=` operator.
    /// Uses `^` operator on lx and rx and assigns the 
    /// result to lx.
    ///
    /// \notes The left-hand-side box is mutable.
    /// \notes The left-hand-side boxes type must be
    /// able to to store the resulting type of the
    ///
    /// \exception std::invalid_argument Throw if the left-hand-side
    /// box cannot store the operations resulting type.
    ///
    /// \tparam E concept: Any
    /// \tparam S concept: Any
    /// \param bx type: box<E> | qualifiers: {const, ref}
    /// \param sx type: S | qualifiers: {const, ref}
    /// \returns requires constexpr 
    template<Any E, Any S>
        requires BitXorWith<E, S>
    constexpr void
    operator^= (box<E>& bx, const S& sx)
    {
        if constexpr (!std::same_as<std::invoke_result_t<std::bit_xor<void>, E, S>, E>)
            throw std::invalid_argument("operator^=: left-hand-side box type cannot store the resulting type.");
        else
            bx = bx ^ sx;
    }


    /// \brief Left Bit Shift Operator
    ///
    /// \group box
    ///
    /// \detail Operator overload for `<<` operator.
    /// Calls lx `map` method on rx and returns 
    /// the result. 
    /// 
    /// \tparam L concept: concept: LeftBitShift
    /// \tparam R concept: concept: LeftBitShift
    /// \param lx type: box<L> | qualifiers: {const, ref}
    /// \param rx type: box<R> | qualifiers: {const, ref}
    /// \returns constexpr auto 
    template<LeftBitShift L, LeftBitShift R>
        requires LeftBitShiftWith<L, R>
    constexpr auto
    operator<< (const box<L>& lx, const box<R>& rx)
    { return lx.map(rx, [](const auto& le, const auto& re){ return le << re; }); }


    /// \brief Left Bit Shift Operator
    ///
    /// \group box
    ///
    /// \details Operator overload for `<<` operator.
    /// Calls lx `map` function with the `<<` operator
    /// and captures sx by reference in the lambda.
    /// 
    /// \tparam E concept: Any
    /// \tparam S concept: Any
    /// \param bx type: box<E> | qualifiers: {const, ref}
    /// \param sx type: S | qualifiers: {const, ref}
    /// \returns requires constexpr 
    template<Any E, Any S>
        requires LeftBitShiftWith<E, S>
    constexpr auto
    operator<< (const box<E>& bx, const S& sx)
    { return bx.map([&](const auto& elem){ return elem << sx; }); }


    /// \brief Left Bit Shift Assignment Operator
    ///
    /// \group box
    ///
    /// \detail Operator overload for `<<=` operator.
    /// Uses `<<` operator on lx and rx and assigns the 
    /// result to lx.
    ///
    /// \notes The left-hand-side box is mutable.
    /// \notes The left-hand-side boxes type must be
    /// able to to store the resulting type of the
    /// call to `shift_left`.
    ///
    /// \exception std::invalid_argument Throw if the left-hand-side
    /// box cannot store the operations resulting type.
    /// 
    /// \tparam L concept: concept: Any
    /// \tparam R concept: concept: Any
    /// \param lx type: box<L> | qualifiers: {const, ref}
    /// \param rx type: box<R> | qualifiers: {const, ref}
    /// \returns requires constexpr 
    template<Any L, Any R>
        requires LeftBitShiftWith<L, R>
    constexpr void
    operator<<= (box<L>& lx, const box<R>& rx)
    {
        if constexpr (!std::same_as<decltype(std::declval<L>() << std::declval<R>()), L>)
            throw std::invalid_argument("operator<<=: left-hand-side box type cannot store the resulting type.");
        else
            lx = lx << rx;
    }


    /// \brief Left Bit Shift Assignment Operator
    ///
    /// \group box
    /// 
    /// \details Operator overload for `<<=` operator.
    /// Uses `<<` operator on lx and rx and assigns the 
    /// result to lx.
    ///
    /// \notes The left-hand-side box is mutable.
    /// \notes The left-hand-side boxes type must be
    /// able to to store the resulting type of the
    ///
    /// \exception std::invalid_argument Throw if the left-hand-side
    /// box cannot store the operations resulting type.
    ///
    /// \tparam E concept: Any
    /// \tparam S concept: Any
    /// \param bx type: box<E> | qualifiers: {const, ref}
    /// \param sx type: S | qualifiers: {const, ref}
    /// \returns requires constexpr 
    template<Any E, Any S>
        requires LeftBitShiftWith<E, S>
    constexpr void
    operator<<= (box<E>& bx, const S& sx)
    {
        if constexpr (!std::same_as<decltype(std::declval<E>() << std::declval<S>()), E>)
            throw std::invalid_argument("operator<<=: left-hand-side box type cannot store the resulting type.");
        else
            bx = bx << sx;
    }


    /// \brief Right Bit Shift Operator
    ///
    /// \group box
    ///
    /// \detail Operator overload for `>>` operator.
    /// Calls lx `map` method on rx and returns 
    /// the result. 
    ///
    /// \exception std::invalid_argument Throw if the left-hand-side
    /// box cannot store the operations resulting type.
    /// 
    /// \tparam L concept: concept: RightBitShift
    /// \tparam R concept: concept: RightBitShift
    /// \param lx type: box<L> | qualifiers: {const, ref}
    /// \param rx type: box<R> | qualifiers: {const, ref}
    /// \returns constexpr auto 
    template<RightBitShift L, RightBitShift R>
        requires RightBitShiftWith<L, R>
    constexpr auto
    operator>> (const box<L>& lx, const box<R>& rx)
    { return lx.map(rx, [](const auto& le, const auto& re){ return le >> re; }); }


    /// \brief Right Bit Shift Operator
    ///
    /// \group box
    ///
    /// \details Operator overload for `>>` operator.
    /// Calls lx `map` function with the `>>` operator
    /// and captures sx by reference in the lambda.
    /// 
    /// \tparam E concept: Any
    /// \tparam S concept: Any
    /// \param bx type: box<E> | qualifiers: {const, ref}
    /// \param sx type: S | qualifiers: {const, ref}
    /// \returns requires constexpr 
    template<Any E, Any S>
        requires RightBitShiftWith<E, S>
    constexpr auto
    operator>> (const box<E>& bx, const S& sx)
    { return bx.map([&](const auto& elem){ return elem >> sx; }); }


    /// \brief Right Bit Shift Assignment Operator
    ///
    /// \group box
    ///
    /// \detail Operator overload for `>>=` operator.
    /// Uses `>>` operator on lx and rx and assigns the 
    /// result to lx.
    ///
    /// \notes The right-hand-side box is mutable.
    /// \notes The right-hand-side boxes type must be
    /// able to to store the resulting type of the
    /// call to `shift_right`.
    ///
    /// \exception std::invalid_argument Throw if the left-hand-side
    /// box cannot store the operations resulting type.
    /// 
    /// \tparam L concept: concept: Any
    /// \tparam R concept: concept: Any
    /// \param lx type: box<L> | qualifiers: {const, ref}
    /// \param rx type: box<R> | qualifiers: {const, ref}
    /// \returns requires constexpr 
    template<Any L, Any R>
        requires RightBitShiftWith<L, R>
    constexpr void
    operator>>= (box<L>& lx, const box<R>& rx)
    {
        if constexpr (!std::same_as<decltype(std::declval<L>() >> std::declval<R>()), L>)
            throw std::invalid_argument("operator>>=: right-hand-side box type cannot store the resulting type.");
        else
            lx = lx >> rx;
    }


    /// \brief Right Bit Shift Assignment Operator
    ///
    /// \group box
    /// 
    /// \details Operator overload for `>>=` operator.
    /// Uses `>>` operator on lx and rx and assigns the 
    /// result to lx.
    ///
    /// \notes The right-hand-side box is mutable.
    /// \notes The right-hand-side boxes type must be
    /// able to to store the resulting type of the
    ///
    /// \exception std::invalid_argument Throw if the left-hand-side
    /// box cannot store the operations resulting type.
    ///
    /// \tparam E concept: Any
    /// \tparam S concept: Any
    /// \param bx type: box<E> | qualifiers: {const, ref}
    /// \param sx type: S | qualifiers: {const, ref}
    /// \returns requires constexpr 
    template<Any E, Any S>
        requires RightBitShiftWith<E, S>
    constexpr void
    operator>>= (box<E>& bx, const S& sx)
    {
        if constexpr (!std::same_as<decltype(std::declval<E>() >> std::declval<S>()), E>)
            throw std::invalid_argument("operator>>=: right-hand-side box type cannot store the resulting type.");
        else
            bx = bx >> sx;
    }


    /// \brief Bitwise Not Operator
    ///
    /// \group box
    ///
    /// \details Operator overload for `~` operator.
    /// Calls bx `bit_not` method and returns the 
    /// resulting box. 
    /// 
    /// \tparam E concept: BitNot
    /// \param bx type: box<E> | qualifiers: {const, ref}
    /// \returns constexpr auto 
    template<BitNot E>
    constexpr auto
    operator~ (const box<E>& bx)
    { return bx.map(std::bit_not{}); }


    /// \brief Transpose Operator
    ///
    /// \group box
    ///
    /// \details Operator overload for `!` operator.
    /// Calls bx `transpose` method and returns the
    /// resulting box. 
    /// 
    /// \tparam E concept: Any
    /// \param bx type: box<E> | qualifiers: {const, ref}
    /// \returns constexpr auto 
    template<Any E>
    constexpr auto
    operator! (box<E> bx)
    { return bx.transpose(); }

} // namespace cortex



namespace std
{
    /// \brief Uses std::swap to swap the contents of two matrices.
    ///
    /// \details Swaps the contents of two matrices if they are of
    /// the same type.
    ///
    /// \exception std::swap is noexcept if x.swap(y) is noexcept.
    ///
    /// \tparam T
    /// \param x type: [cortex::box<T>] | qualifiers: {const, ref}
    /// \param y type: [cortex::box<T>] | qualifiers: {const, ref}
    /// \returns inline void
    template <typename T>
    inline void swap(cortex::box<T>& x, cortex::box<T>& y) noexcept
    { x.swap(y); }
}

#endif // __cplusplus >= 201703L

#endif // CORTEX_BOX_H