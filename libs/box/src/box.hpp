/// -*- C++ -*- Header compatibility <box.hpp>

/// \brief Two Dimensional Access To Contiguous Data.
///
/// Author: Tyler Swann (oraqlle@github.com)
/// 
/// Header Version: v2.3.1
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
        /// \param alloc type: allocator_type | qualifiers: [const, ref]
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
        /// \param alloc type: allocator_type | qualifiers: [const, ref]
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
        /// \param value type: value_type | qualifiers: [const, ref]
        /// \param alloc type: allocator_type | qualifiers: [const, ref]
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
        /// \param other type: [box] | qualifiers: [const, ref]
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
        /// \param other type: [box] | qualifiers: [const, ref]
        /// \param alloc type: allocator_type | qualifiers: [const, ref]
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
        /// \param alloc type: allocator_type | qualifiers: [const, ref]
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
        /// \param alloc type: allocator_type | qualifiers: [const, ref] | attribute: [[maybe_unused]]
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
        /// \param list type: [std::initializer_list<std::initializer_list<value_type>>] | qualifiers: [const, ref]
        /// \param alloc type: allocator_type | qualifiers: [const, ref] | attribute: [[maybe_unused]]
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
        /// \param other type: [box] | qualifiers: [const, ref]
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
        /// \param value type: value_type | qualifiers: [const, ref]
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

        /// \brief Box Element-wise Addition
        ///
        /// \details Performs an element-wise addition
        /// operation between matrices. The boxes must
        /// have the same dimensions. Returns a new box
        /// with the computed values.
        ///
        /// \requires The type of this box's elements are `Addable`
        /// \requires The type of this box's elements and the type
        /// of the passed box's element types satisfy `AddableWith`.
        ///
        /// \tparam _ElemT
        /// \param other type: box<_ElemT> | qualifiers: [const, ref]
        /// \returns constexpr auto : A box whose element's type
        /// is the sum of the two input matrices element types.
        template <Addable _ElemT>
            requires AddableWith<value_type, _ElemT>
        constexpr auto 
        add(const box<_ElemT>& other) const
        {
            if (this->dimensions() != other.dimensions())
                throw std::invalid_argument("In box::add - dimensions do not match");

            box<decltype(std::declval<value_type>() + std::declval<_ElemT>())> result(this->rows(), this->columns());

            std::ranges::transform(*this, other, result.begin(), std::plus{});

            return result;
        }

        /// \brief Box Element-wise Subtraction
        ///
        /// \details Performs an element-wise subtraction
        /// operation between matrices. The boxes must
        /// have the same dimensions. Returns a new box
        /// with the computed values.
        ///
        /// \requires The type of this box's elements are `Subtractable`
        /// \requires The type of this box's elements and the type
        /// of the passed box's element types satisfy `SubtractableWith`.
        ///
        /// \tparam _ElemT
        /// \param other type: box<_ElemT> | qualifiers: [const, ref]
        /// \returns constexpr auto : A box whose element type
        /// is the difference of the two input matrices element types.
        template <Subtractable _ElemT>
            requires SubtractableWith<value_type, _ElemT>
        constexpr auto 
        sub(const box<_ElemT>& other) const
        {
            if (this->dimensions() != other.dimensions())
                throw std::invalid_argument("In box::sub - dimensions do not match");

            box<decltype(std::declval<value_type>() - std::declval<_ElemT>())> result(this->rows(), this->columns());

            std::ranges::transform(*this, other, result.begin(), std::minus{});

            return result;
        }

        /// \brief Box Element-wise Multiplication
        ///
        /// \details Performs an element-wise multiplication
        /// operation between matrices. The boxes must
        /// have the same dimensions. Returns a new box
        /// with the computed values.
        ///
        /// \requires The type of this box's elements are `Multiplicable`
        /// \requires The type of this box's elements and the type
        /// of the passed box's element types satisfy `MultiplicableWith`.
        ///
        /// \tparam _ElemT
        /// \param other type: box<_ElemT> | qualifiers: [const, ref]
        /// \returns constexpr auto : A box whose element type
        /// is the product of the two input matrices element types.
        template <Any _ElemT>
            requires MultiplicableWith<value_type, _ElemT>
        constexpr auto 
        mul(const box<_ElemT>& other) const
        {
            if (this->dimensions() != other.dimensions())
                throw std::invalid_argument("In box::mult - dimensions do not match");

            box<decltype(std::declval<value_type>() * std::declval<_ElemT>())> result(this->rows(), this->columns());

            std::ranges::transform(*this, other, result.begin(), std::multiplies{});

            return result;
        }

        /// \brief Scalar Multiplication.
        ///
        /// \details Performs an element-wise multiplication 
        /// of the box by a 'scalar' value.
        ///
        /// \requires The type of this box's elements are `MultiplicableWith`
        /// the type denoted _ScalarT.
        /// \requires The type denoted _ScalarT be `Multiplicable`.
        ///
        ///
        /// \tparam _ScalarT
        /// \param scalar type: _ScalarT | qualifiers: [const, ref]
        /// \returns constexpr auto
        template <Any _ScalarT>
            requires MultiplicableWith<value_type, _ScalarT>
        constexpr auto 
        mul(const _ScalarT& scalar) const
        {
            if (empty())
                throw std::invalid_argument("In box::mul - scalar multiplication on empty box");

            box<decltype(std::declval<value_type>() * std::declval<_ScalarT>())> result(this->rows(), this->columns());

            std::ranges::transform(*this, result.begin(), [&](auto& elem){ return elem * scalar; });

            return result;
        }

        /// \brief Box Element-wise Division
        ///
        /// \details Performs an element-wise division
        /// operation between matrices. The boxes must
        /// have the same dimensions. Returns a new box
        /// with the computed values.
        ///
        /// \requires The type of this box's elements are `Divisible`
        /// \requires The type of this box's elements and the type
        /// of the passed box's element types satisfy `DivisibleWith`.
        ///
        /// \notes When dividing two matrices, if both matrices elements
        /// are integrals, the division is performed as integer divisionbx.
        /// due to C++ rounding rules.
        ///
        /// \tparam _ElemT
        /// \param other type: box<_ElemT> | qualifiers: [const, ref]
        /// \returns constexpr auto : A box whose element type
        /// is the quotient of the two input matrices element types.
        template <Any _ElemT>
            requires DivisibleWith<value_type, _ElemT>
        constexpr auto 
        div(const box<_ElemT>& other) const
        {
            if (this->dimensions() != other.dimensions())
                throw std::invalid_argument("In box::div - dimensions do not match");

            box<decltype(std::declval<value_type>() / std::declval<_ElemT>())> result(this->rows(), this->columns());

            std::ranges::transform(*this, other, result.begin(), std::divides{});

            return result;
        }

        /// \brief Scalar Division
        ///
        /// \details Performs an element-wise division of the box
        /// by a 'scalar' value.
        ///
        /// \requires The type of this box's elements are `DivisibleWith`
        /// the type denoted _ScalarT.
        /// \requires The type denoted _ScalarT be `Divisible`.
        ///
        /// \notes When dividing two matrices, if both matrices elements
        /// are integrals, the division is performed as integer divisionbx.
        /// due to C++ rounding rules.
        ///
        /// \tparam _ScalarT
        /// \param scalar type: _ScalarT | qualifiers: [const, ref]
        /// \returns constexpr auto
        template <Any _ScalarT>
            requires DivisibleWith<value_type, _ScalarT>
        constexpr auto 
        div(const _ScalarT& scalar) const
        {
            if (empty())
                throw std::invalid_argument("In box::div - scalar division on empty box");
            if (scalar == 0)
                throw std::invalid_argument("In box::div - scalar is zero");

            box<decltype(std::declval<value_type>() / std::declval<_ScalarT>())> result(this->rows(), this->columns());

            std::ranges::transform(*this, result.begin(), [&](auto& elem){ return elem / scalar; });

            return result;
        }

        /// \brief Box Element-wise Modulus
        ///
        /// \details Performs an element-wise modulus operation
        /// between two boxes. The boxes must have the same dimensions.
        ///
        /// \exception std::invalid_argument If the dimensions of the boxes
        /// do not match, std::invalid_argument is thrown.
        ///
        /// \tparam _ElemT concept: Modulo | requires: ModuloWith<value_type, _ElemT>
        /// \param other type: box<_ElemT> | qualifiers: [const, ref]
        /// \returns constexpr auto
        template <Any _ElemT>
            requires ModuloWith<value_type, _ElemT>
        constexpr auto 
        mod(const box<_ElemT>& other) const
        {
            if (this->dimensions() != other.dimensions())
                throw std::invalid_argument("In box::mod - dimensions do not match");

            box<decltype(std::declval<value_type>() % std::declval<_ElemT>())> result(this->rows(), this->columns());

            std::ranges::transform(*this, other, result.begin(), std::modulus{});

            return result;
        }

        /// \brief Scalar Modulus
        ///
        /// \details Performs an element-wise modulus operation
        /// between all elements of the box and the scalar. The
        /// box must not be empty.
        ///
        /// \exception std::invalid_argument If the box is empty,
        /// std::invalid_argument is thrown.
        ///
        /// \tparam _ScalarT concept: Modulo | requires: ModuloWith<value_type, _ScalarT>
        /// \param scalar type: _ScalarT | qualifiers: [const, ref]
        /// \returns constexpr auto
        template <Any _ScalarT>
            requires ModuloWith<value_type, _ScalarT>
        constexpr auto 
        mod(const _ScalarT& scalar) const
        {
            if (empty())
                throw std::invalid_argument("In box::mod - scalar modulus on empty box");

            box<decltype(std::declval<value_type>() % std::declval<_ScalarT>())> result(this->rows(), this->columns());

            std::ranges::transform(*this, result.begin(), [&](auto& elem){ return elem % scalar; });

            return result;
        }

        /// \brief Box Element-wise Bitwise Xor
        ///
        /// \details Performs an element-wise bitwise Xor operation
        /// between two boxes. The boxes must have the same dimensions.
        ///
        /// \exception std::invalid_argument If the dimensions of the boxes
        /// do not match, std::invalid_argument is thrown.
        ///
        /// \tparam _ElemT concept: BitXor | requires: BitXorWith<value_type, _ElemT>
        /// \param other type: box<_ElemT> | qualifiers: [const, ref]
        /// \returns constexpr auto
        template <Any _ElemT>
            requires BitXorWith<value_type, _ElemT>
        constexpr auto 
        bit_xor(const box<_ElemT>& other) const
        {
            if (this->dimensions() != other.dimensions())
                throw std::invalid_argument("In box::bit_xor - dimensions do not match");

            box<decltype(std::declval<value_type>() ^ std::declval<_ElemT>())> result(this->rows(), this->columns());

            std::ranges::transform(*this, other, result.begin(), std::bit_xor{});

            return result;
        }

        /// \brief Scalar Bitwise Xor
        ///
        /// \details Performs an element-wise bitwise Xor operation
        /// between all elements of the box and the scalar. The
        /// box must not be empty.
        ///
        /// \exception std::invalid_argument If the box is empty,
        /// std::invalid_argument is thrown.
        ///
        /// \tparam _ScalarT concept: BitXor | requires: BitXorWith<value_type, _ScalarT>
        /// \param scalar type: _ScalarT | qualifiers: [const, ref]
        /// \returns constexpr auto
        template <Any _ScalarT>
            requires BitXorWith<value_type, _ScalarT>
        constexpr auto 
        bit_xor(const _ScalarT& scalar) const
        {
            if (empty())
                throw std::invalid_argument("In box::bit_xor - scalar bit_xor on empty box");

            box<decltype(std::declval<value_type>() ^ std::declval<_ScalarT>())> result(this->rows(), this->columns());

            std::ranges::transform(*this, result.begin(), [&](auto& elem) { return elem ^ scalar; });

            return result;
        }


        /// \brief Box Element-wise Bitwise And
        ///
        /// \details Performs an element-wise bitwise And operation
        /// between two boxes. The boxes must have the same dimensions.
        ///
        /// \exception std::invalid_argument If the dimensions of the boxes
        /// do not match, std::invalid_argument is thrown.
        ///
        /// \tparam _ElemT concept: BitAnd | requires: BitAndWith<value_type, _ElemT>
        /// \param other type: box<_ElemT> | qualifiers: [const, ref]
        /// \returns constexpr auto
        template <Any _ElemT>
            requires BitAndWith<value_type, _ElemT>
        constexpr auto 
        bit_and(const box<_ElemT>& other) const
        {
            if (this->dimensions() != other.dimensions())
                throw std::invalid_argument("In box::bit_and - dimensions do not match");

            box<decltype(std::declval<value_type>()&  std::declval<_ElemT>())> result(this->rows(), this->columns());

            std::ranges::transform(*this, other, result.begin(), std::bit_and{});

            return result;
        }

        /// \brief Scalar Bitwise And
        ///
        /// \details Performs an element-wise bitwise And operation
        /// between all elements of the box and the scalar. The
        /// box must not be empty.
        ///
        /// \exception std::invalid_argument If the box is empty,
        /// std::invalid_argument is thrown.
        ///
        /// \tparam _ScalarT concept: BitAnd | requires: BitAndWith<value_type, _ScalarT>
        /// \param scalar type: _ScalarT | qualifiers: [const, ref]
        /// \returns constexpr auto
        template <Any _ScalarT>
            requires BitAndWith<value_type, _ScalarT>
        constexpr auto 
        bit_and(const _ScalarT& scalar) const
        {
            if (empty())
                throw std::invalid_argument("In box::bit_and - scalar bit_and on empty box");

            box<decltype(std::declval<value_type>()&  std::declval<_ScalarT>())> result(this->rows(), this->columns());

            std::ranges::transform(*this, result.begin(), [&](auto& elem) { return elem & scalar; });

            return result;
        }


        /// \brief Box Element-wise Bitwise Or
        ///
        /// \details Performs an element-wise bitwise Or operation
        /// between two boxes. The boxes must have the same dimensions.
        ///
        /// \exception std::invalid_argument If the dimensions of the boxes
        /// do not match, std::invalid_argument is thrown.
        ///
        /// \tparam _ElemT concept: BitOr | requires: BitOrWith<value_type, _ElemT>
        /// \param other type: box<_ElemT> | qualifiers: [const, ref]
        /// \returns constexpr auto
        template <Any _ElemT>
            requires BitOrWith<value_type, _ElemT>
        constexpr auto 
        bit_or(const box<_ElemT>& other) const
        {
            if (this->dimensions() != other.dimensions())
                throw std::invalid_argument("In box::bit_or - dimensions do not match");

            box<decltype(std::declval<value_type>() | std::declval<_ElemT>())> result(this->rows(), this->columns());

            std::ranges::transform(*this, other, result.begin(), std::bit_or{});

            return result;
        }

        /// \brief Scalar Bitwise Or
        ///
        /// \details Performs an element-wise bitwise Or operation
        /// between all elements of the box and the scalar. The
        /// box must not be empty.
        ///
        /// \exception std::invalid_argument If the box is empty,
        /// std::invalid_argument is thrown.
        ///
        /// \tparam _ScalarT concept: BitOr | requires: BitOrWith<value_type, _ScalarT>
        /// \param scalar type: _ScalarT | qualifiers: [const, ref]
        /// \returns constexpr auto
        template <Any _ScalarT>
            requires BitOrWith<value_type, _ScalarT>
        constexpr auto 
        bit_or(const _ScalarT& scalar) const
        {
            if (empty())
                throw std::invalid_argument("In box::bit_or - scalar bit_or on empty box");

            box<decltype(std::declval<value_type>() | std::declval<_ScalarT>())> result(this->rows(), this->columns());

            std::ranges::transform(*this, result.begin(), [&](auto& elem) { return elem | scalar; });

            return result;
        }


        /// \brief Box Element-wise Left Bit-shift
        ///
        /// \details Performs an element-wise left bit-shift operation
        /// between two boxes. The boxes must have the same dimensions.
        ///
        /// \exception std::invalid_argument If the dimensions of the boxes
        /// do not match, std::invalid_argument is thrown.
        ///
        /// \tparam _ElemT concept: LeftBitShift | requires: LeftBitShiftWith<value_type, _ElemT>
        /// \param other type: box<_ElemT> | qualifiers: [const, ref]
        /// \returns constexpr auto
        template <Any _ElemT>
            requires LeftBitShiftWith<value_type, _ElemT>
        constexpr auto 
        shift_left(const box<_ElemT>& other) const
        {
            if (this->dimensions() != other.dimensions())
                throw std::invalid_argument("In box::shift_left - dimensions do not match");

            box<decltype(std::declval<value_type>() << std::declval<_ElemT>())> result(this->rows(), this->columns());

            std::ranges::transform(*this, other, result.begin(), [](auto& this_elem, auto& other_elem) { return this_elem << other_elem; });

            return result;
        }

        /// \brief Scalar Left bit-shift
        ///
        /// \details Performs an element-wise left bit-shift operation
        /// between all elements of the box and the scalar. The
        /// box must not be empty.
        ///
        /// \exception std::invalid_argument If the box is empty,
        /// std::invalid_argument is thrown.
        ///
        /// \tparam _ScalarT concept: LeftBitShift | requires: LeftBitShiftWith<value_type, _ScalarT>
        /// \param scalar type: _ScalarT | qualifiers: [const, ref]
        /// \returns constexpr auto
        template <Any _ScalarT>
            requires LeftBitShiftWith<value_type, _ScalarT>
        constexpr auto 
        shift_left(const _ScalarT& scalar) const
        {
            if (empty())
                throw std::invalid_argument("In box::shift_left - scalar shift_left on empty box");

            box<decltype(std::declval<value_type>() << std::declval<_ScalarT>())> result(this->rows(), this->columns());

            std::ranges::transform(*this, result.begin(), [&](auto& elem) { return elem << scalar; });

            return result;
        }


        /// \brief Box Element-wise Right Bit-shift
        ///
        /// \details Performs an element-wise right bit-shift operation
        /// between two boxes. The boxes must have the same dimensions.
        ///
        /// \exception std::invalid_argument If the dimensions of the boxes
        /// do not match, std::invalid_argument is thrown.
        ///
        /// \tparam _ElemT concept: RightBitShift | requires: RightBitShiftWith<value_type, _ElemT>
        /// \param other type: box<_ElemT> | qualifiers: [const, ref]
        /// \returns constexpr auto
        template <Any _ElemT>
            requires RightBitShiftWith<value_type, _ElemT>
        constexpr auto 
        shift_right(const box<_ElemT>& other) const
        {
            if (this->dimensions() != other.dimensions())
                throw std::invalid_argument("In box::shift_right - dimensions do not match");

            box<decltype(std::declval<value_type>() >> std::declval<_ElemT>())> result(this->rows(), this->columns());

            std::ranges::transform(*this, other, result.begin(), [](auto& this_elem, auto& other_elem) { return this_elem >> other_elem; });

            return result;
        }

        /// \brief Scalar Right bit-shift
        ///
        /// \details Performs an element-wise right bit-shift operation
        /// between all elements of the box and the scalar. The
        /// box must not be empty.
        ///
        /// \exception std::invalid_argument If the box is empty,
        /// std::invalid_argument is thrown.
        ///
        /// \tparam _ScalarT concept: RightBitShift | requires: RightBitShiftWith<value_type, _ScalarT>
        /// \param scalar type: _ScalarT | qualifiers: [const, ref]
        /// \returns constexpr auto
        template <Any _ScalarT>
            requires RightBitShiftWith<value_type, _ScalarT>
        constexpr auto 
        shift_right(const _ScalarT& scalar) const
        {
            if (empty())
                throw std::invalid_argument("In box::shift_right - scalar shift_right on empty box");

            box<decltype(std::declval<value_type>() >> std::declval<_ScalarT>())> result(this->rows(), this->columns());

            std::ranges::transform(*this, result.begin(), [&](auto& elem) { return elem >> scalar; });

            return result;
        }


        /// \brief Element-wise Bitwise Not
        ///
        /// \details Performs an element-wise bitwise not operation.
        /// The box must not be empty.
        ///
        /// \exception std::invalid_argument If the box is empty,
        /// std::invalid_argument is thrown.
        ///
        /// \requires BitNot<value_type>
        ///
        /// \returns constexpr auto
        constexpr auto bit_not() const
            requires BitNot<value_type>
        {
            if (empty())
                throw std::invalid_argument("In box::bit_not - bit_not on empty box");

            box<decltype(~std::declval<value_type>())> result(this->rows(), this->columns());

            std::ranges::transform(*this, result.begin(), std::bit_not{});

            return result;
        }


        /// \brief Matrix Transpose
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


        /// \brief Map
        ///
        /// \details Maps a function over the box, returning 
        /// the mapped box.
        /// 
        /// \tparam F concept: std::copy_constructible
        /// \param func type: F 
        /// \returns constexpr auto 
        template<std::copy_constructible F>
        constexpr auto
        map(F func)
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
        map(Rng&& rng, F func)
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
        map(It first, It last, F func)
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
    };

    /// \brief Compares two matrices for equality.
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
    /// \param lhs type: [box<_ElemL>] | qualifiers: [const, ref]
    /// \param rhs type: [box<_ElemR>] | qualifiers: [const, ref]
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
    /// \details Uses std::lexicographical_compare_three_way to
    /// compare the matrices and generates the !=, <, >, <=, >=
    /// operators.
    ///
    /// \tparam _ElemL
    /// \tparam _ElemR
    /// \param lhs type: [box<_ElemL>] | qualifiers: [const, ref]
    /// \param lhs type: [box<_ElemL>] | qualifiers: [const, ref]
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
    /// \details Inverts the result of a equality comparison
    /// between two matrices.
    ///
    /// \tparam _ElemL
    /// \tparam _ElemR
    /// \param lhs type: [box<_ElemL>] | qualifiers: [const, ref]
    /// \param rhs type: [box<_ElemR>] | qualifiers: [const, ref]
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
    /// \tparam _ElemL
    /// \tparam _ElemR
    /// \param lhs type: [box<_ElemL>] | qualifiers: [const, ref]
    /// \param rhs type: [box<_ElemR>] | qualifiers: [const, ref]
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
    /// \details Uses less than comparison and swaps the
    /// order of the arguments.
    ///
    /// \tparam _ElemL
    /// \tparam _ElemR
    /// \param lhs type: [box<_ElemL>] | qualifiers: [const, ref]
    /// \param rhs type: [box<_ElemR>] | qualifiers: [const, ref]
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
    /// \details Uses less than comparison and swaps the
    /// order of the arguments. If the rhs box is less
    /// than the lhs box, then the lhs box cannot
    /// be less then or equal to the rhs box.
    ///
    /// \tparam _ElemL
    /// \tparam _ElemR
    /// \param lhs type: [box<_ElemL>] | qualifiers: [const, ref]
    /// \param rhs type: [box<_ElemR>] | qualifiers: [const, ref]
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
    /// \details Inverts the result of a less than comparison
    /// between the two matrices.
    ///
    /// \tparam _ElemL
    /// \tparam _ElemR
    /// \param lhs type: [box<_ElemL>] | qualifiers: [const, ref]
    /// \param rhs type: [box<_ElemR>] | qualifiers: [const, ref]
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
    /// \tparam _ElemT
    ///
    /// \param bx type: [box<_ElemT>] | qualifiers: [const, ref]
    /// \param scalar type: [_ElemT] | qualifiers: [const, ref]
    /// \returns box<bool>
    template <typename _ElemT>
#if __cpluscplus >= 202002L
        requires requires(_ElemT lhsE, _ElemT rhsE)
                { { lhsE == rhsE } -> std::convertible_to<bool>; }
    constexpr inline auto
    operator== (const box<_ElemT>& bx, const _ElemT& scalar) noexcept(noexcept(std::declval<_ElemT>() == std::declval<_ElemT>()))
        -> box<bool>
#else
    inline auto
    operator== (const box<_ElemT>& bx, const _ElemT& scalar)
        -> box<bool>
#endif
    {
        box<bool> result(bx.rows(), bx.columns(), false);
        std::ranges::transform(bx, result.begin(), [&](const _ElemT& bxE)
                               { return bxE == scalar; });
        return result;
    }

    /// \brief Scalar Inequality Comparison
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
    /// \tparam _ElemT
    ///
    /// \param bx type: [box<_ElemT>] | qualifiers: [const, ref]
    /// \param scalar type: [_ElemT] | qualifiers: [const, ref]
    /// \returns box<bool>
    template <typename _ElemT>
#if __cpluscplus >= 202002L
        requires requires(_ElemT lhsE, _ElemT rhsE)
                { { lhsE != rhsE } -> std::convertible_to<bool>; }
    constexpr inline auto
    operator!= (const box<_ElemT>& bx, const _ElemT& scalar) noexcept(noexcept(std::declval<_ElemT>() != std::declval<_ElemT>()))
        -> box<bool>
#else
    inline auto
    operator!= (const box<_ElemT>& bx, const _ElemT& scalar)
        -> box<bool>
#endif
    {
        box<bool> result(bx.rows(), bx.columns(), false);
        std::ranges::transform(bx, result.begin(), [&](const _ElemT& bxE)
                               { return bxE != scalar; });
        return result;
    }

    /// \brief Scalar Less-Then Comparison
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
    /// \tparam _ElemT
    ///
    /// \param bx type: [box<_ElemT>] | qualifiers: [const, ref]
    /// \param scalar type: [_ElemT] | qualifiers: [const, ref]
    /// \returns box<bool>
    template <typename _ElemT>
#if __cpluscplus >= 202002L
        requires requires(_ElemT lhsE, _ElemT rhsE)
                { { lhsE < rhsE } -> std::convertible_to<bool>; }
    constexpr inline auto
    operator< (const box<_ElemT>& bx, const _ElemT& scalar) noexcept(noexcept(std::declval<_ElemT>() < std::declval<_ElemT>()))
        -> box<bool>
#else
    inline auto
    operator< (const box<_ElemT>& bx, const _ElemT& scalar)
        -> box<bool>
#endif
    {
        box<bool> result(bx.rows(), bx.columns(), false);
        std::ranges::transform(bx, result.begin(), [&](const _ElemT& bxE)
                               { return bxE < scalar; });
        return result;
    }

    /// \brief Scalar Greater-Then Comparison
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
    /// \tparam _ElemT
    ///
    /// \param bx type: [box<_ElemT>] | qualifiers: [const, ref]
    /// \param scalar type: [_ElemT] | qualifiers: [const, ref]
    /// \returns box<bool>
    template <typename _ElemT>
#if __cpluscplus >= 202002L
        requires requires(_ElemT lhsE, _ElemT rhsE)
                { { lhsE > rhsE } -> std::convertible_to<bool>; }
    constexpr inline auto
    operator> (const box<_ElemT>& bx, const _ElemT& scalar) noexcept(noexcept(std::declval<_ElemT>() > std::declval<_ElemT>()))
        -> box<bool>
#else
    inline auto
    operator> (const box<_ElemT>& bx, const _ElemT& scalar)
        -> box<bool>
#endif
    {
        box<bool> result(bx.rows(), bx.columns(), false);
        std::ranges::transform(bx, result.begin(), [&](const _ElemT& bxE)
                               { return bxE > scalar; });
        return result;
    }

    /// \brief Scalar Less-Then-Equal Comparison
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
    /// \tparam _ElemT
    ///
    /// \param bx type: [box<_ElemT>] | qualifiers: [const, ref]
    /// \param scalar type: [_ElemT] | qualifiers: [const, ref]
    /// \returns box<bool>
    template <typename _ElemT>
#if __cpluscplus >= 202002L
        requires requires(_ElemT lhsE, _ElemT rhsE)
                { { lhsE <= rhsE } -> std::convertible_to<bool>; }
    constexpr inline auto
    operator<= (const box<_ElemT>& bx, const _ElemT& scalar) noexcept(noexcept(std::declval<_ElemT>() > std::declval<_ElemT>()))
        -> box<bool>
#else
    inline auto
    operator<= (const box<_ElemT>& bx, const _ElemT& scalar)
        -> box<bool>
#endif
    {
        box<bool> result(bx.rows(), bx.columns(), false);
        std::ranges::transform(bx, result.begin(), [&](const _ElemT& bxE)
                               { return bxE <= scalar; });
        return result;
    }

    /// \brief Scalar Greater-Then-Equal Comparison
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
    /// \tparam _ElemT
    ///
    /// \param bx type: [box<_ElemT>] | qualifiers: [const, ref]
    /// \param scalar type: [_ElemT] | qualifiers: [const, ref]
    /// \returns box<bool>
    template <typename _ElemT>
#if __cpluscplus >= 202002L
        requires requires(_ElemT lhsE, _ElemT rhsE)
                { { lhsE >= rhsE } -> std::convertible_to<bool>; }
    constexpr inline auto
    operator>= (const box<_ElemT>& bx, const _ElemT& scalar) noexcept(noexcept(std::declval<_ElemT>() > std::declval<_ElemT>()))
        -> box<bool>
#else
    inline auto
    operator>= (const box<_ElemT>& bx, const _ElemT& scalar)
        -> box<bool>
#endif
    {
        box<bool> result(bx.rows(), bx.columns(), false);
        std::ranges::transform(bx, result.begin(), [&](const _ElemT& bxE)
                               { return bxE >= scalar; });
        return result;
    }


    /// \brief Addition Operator
    ///
    /// \detail Operator overload for `+` operator.
    /// Calls lx `add` method on rx and returns 
    /// the result. 
    /// 
    /// \tparam _LxT 
    /// \tparam _RxT 
    /// \param lx type: box<_LxT> | qualifiers: [const, ref]
    /// \param rx type: box<_RxT> | qualifiers: [const, ref]
    /// \returns constexpr auto 
    template<Addable _LxT, Addable _RxT>
        requires AddableWith<_LxT, _RxT>
    constexpr auto
    operator+ (const box<_LxT>& lx, const box<_RxT>& rx)
    { return lx.add(rx); }


    /// \brief Additon Assignment Operator
    ///
    /// \details Operator overload for `+=` operator.
    /// Calls lx `add` method on rx and assigns the result 
    /// to lx.
    ///
    /// \notes The left-hand-side box is mutable.
    /// \notes The left-hand-side boxes type but be
    /// able to to store the resulting type of the
    /// call to `add`.
    ///
    /// \exception std::invalid_argument Thrown if the left-hand-side
    /// box cannot store the resulting type of the call to `add`.
    /// 
    /// \tparam _LxT concept: Addable
    /// \tparam _RxT concept: Addable
    /// \param lx type: box<_LxT> | qualifiers: [ref]
    /// \param rx type: box<_RxT> | qualifiers: [const, ref]
    /// \returns constexpr void
    template<Addable _LxT, Addable _RxT>
        requires AddableWith<_LxT, _RxT>
    constexpr void
    operator+= (box<_LxT>& lx, const box<_RxT>& rx) 
    { 
        if constexpr (!std::same_as<decltype(std::declval<box<_LxT>>().add(std::declval<box<_RxT>>())), box<_LxT>>)
            throw std::invalid_argument("operator+=: left-hand-side box type cannot store the resulting type of the call to `add`.");
        else
            lx = lx.add(rx);
    }


    /// \brief Subtraction Operator
    ///
    /// \detail Operator overload for `-` operator.
    /// Calls lx `sub` method on rx and returns 
    /// the result. 
    /// 
    /// \tparam _LxT 
    /// \tparam _RxT 
    /// \param lx type: box<_LxT> | qualifiers: [const, ref]
    /// \param rx type: box<_RxT> | qualifiers: [const, ref]
    /// \returns constexpr auto 
    template<Subtractable _LxT, Subtractable _RxT>
        requires SubtractableWith<_LxT, _RxT>
    constexpr auto
    operator- (const box<_LxT>& lx, const box<_RxT>& rx)
    { return lx.sub(rx); }


    /// \brief Subtraction Assignment Operator
    ///
    /// \details Operator overload for `-=` operator.
    /// Calls lx `sub` method on rx and assigns the result 
    /// to lx.
    ///
    /// \notes The left-hand-side box is mutable.
    /// \notes The left-hand-side boxes type but be
    /// able to to store the resulting type of the
    /// call to `sub`.
    ///
    /// \exception std::invalid_argument Thrown if the left-hand-side
    /// box cannot store the resulting type of the call to `sub`.
    /// 
    /// \tparam _LxT concept: Subtractable
    /// \tparam _RxT concept: Subtractable
    /// \param lx type: box<_LxT> | qualifiers: [ref]
    /// \param rx type: box<_RxT> | qualifiers: [const, ref]
    /// \returns constexpr void
    template<Subtractable _LxT, Subtractable _RxT>
        requires SubtractableWith<_LxT, _RxT>
    constexpr void
    operator-= (box<_LxT>& lx, const box<_RxT>& rx) 
    { 
        if constexpr (!std::same_as<decltype(std::declval<box<_LxT>>().sub(std::declval<box<_RxT>>())), box<_LxT>>)
            throw std::invalid_argument("operator-=: left-hand-side box type cannot store the resulting type of the call to `sub`.");
        else
            lx = lx.sub(rx);
    }


    /// \brief Multiplication Operator
    ///
    /// \detail Operator overload for `*` operator.
    /// Calls lx `mul` method on rx and returns
    /// the resulting box.
    /// 
    /// \tparam _LxT concept: Any
    /// \tparam _RxT concept: Any
    /// \param lx type: box<_LxT> | qualifiers: [const, ref]
    /// \param rx type: box<_RxT> | qualifiers: [const, ref]
    /// \returns constexpr auto 
    template<Any _LxT, Any _RxT>
        requires MultiplicableWith<_LxT, _RxT>
    constexpr auto
    operator* (const box<_LxT>& lx, const box<_RxT>& rx)
    { return lx.mul(rx); }


    /// \brief Multiplication Operator
    ///
    /// \details Operator overload for `*` operator.
    /// Calls bx `mul` method on scalar sx and returns
    /// the resulting box.
    /// 
    /// \tparam _ElemT concept: Any
    /// \tparam _ScalarT concept: Any
    /// \param bx type: box<_ElemT> | qualifiers: [const, ref]
    /// \param sx type: _ScalarT | qualifiers: [const, ref]
    /// \returns requires constexpr 
    template<Any _ElemT, Any _ScalarT>
        requires MultiplicableWith<_ElemT, _ScalarT>
    constexpr auto
    operator* (const box<_ElemT>& bx, const _ScalarT& sx)
    { return bx.mul(sx); }


    /// \brief Multiplication Operator
    ///
    /// \details Operator overload for `*` operator.
    /// Calls bx `mul` method on scalar sx and returns
    /// the resulting box.
    /// 
    /// \tparam _ScalarT concept: Any
    /// \tparam _ElemT concept: Any
    /// \param sx type: _ScalarT | qualifiers: [const, ref]
    /// \param bx type: box<_ElemT> | qualifiers: [const, ref]
    /// \returns requires constexpr 
    template<Any _ScalarT, Any _ElemT>
        requires MultiplicableWith<_ScalarT, _ElemT>
    constexpr auto
    operator* (const _ScalarT& sx, const box<_ElemT>& bx)
    { return bx.mul(sx); }


    /// \brief Multiplication Assignment Operator
    ///
    /// \detail Operator overload for `*=` operator.
    /// Calls lx `mul` method on rx and assigns the result
    /// to lx.
    ///
    /// \notes The left-hand-side box is mutable.
    /// \notes The left-hand-side boxes type must be
    /// able to to store the resulting type of the
    /// call to `mul`.
    /// 
    /// \tparam _LxT concept: Any
    /// \tparam _RxT concept: Any
    /// \param lx type: box<_LxT> | qualifiers: [const, ref]
    /// \param rx type: box<_RxT> | qualifiers: [const, ref]
    /// \returns requires constexpr 
    template<Any _LxT, Any _RxT>
        requires MultiplicableWith<_LxT, _RxT>
    constexpr void
    operator*= (box<_LxT>& lx, const box<_RxT>& rx)
    {
        if constexpr (!std::same_as<decltype(std::declval<box<_LxT>>().mul(std::declval<box<_RxT>>())), box<_LxT>>)
            throw std::invalid_argument("operator*=: left-hand-side box type cannot store the resulting type of the call to `mul`.");
        else
            lx = lx.mul(rx);
    }


    /// \brief Multiplication Assignment Operator
    /// 
    /// \details Operator overload for `*=` operator.
    /// Calls bx `mul` method on scalar sx and assigns 
    /// the result to bx.
    ///
    /// \notes The left-hand-side box is mutable.
    /// \notes The left-hand-side boxes type must be
    /// able to to store the resulting type of the
    ///
    /// \tparam _ElemT concept: Any
    /// \tparam _ScalarT concept: Any
    /// \param bx type: box<_ElemT> | qualifiers: [const, ref]
    /// \param sx type: _ScalarT | qualifiers: [const, ref]
    /// \returns requires constexpr 
    template<Any _ElemT, Any _ScalarT>
        requires MultiplicableWith<_ElemT, _ScalarT>
    constexpr void
    operator*= (box<_ElemT>& bx, const _ScalarT& sx)
    {
        if constexpr (!std::same_as<decltype(std::declval<box<_ElemT>>().mul(std::declval<_ScalarT>())), box<_ElemT>>)
            throw std::invalid_argument("operator*=: left-hand-side box type cannot store the resulting type of the call to `mul`.");
        else
            bx = bx.mul(sx);
    }


    /// \brief Division Operator
    ///
    /// \detail Operator overload for `/` operator.
    /// Calls lx `div` method on rx and returns
    /// the resulting box.
    /// 
    /// \tparam _LxT concept: Any
    /// \tparam _RxT concept: Any
    /// \param lx type: box<_LxT> | qualifiers: [const, ref]
    /// \param rx type: box<_RxT> | qualifiers: [const, ref]
    /// \returns constexpr auto 
    template<Any _LxT, Any _RxT>
        requires DivisibleWith<_LxT, _RxT>
    constexpr auto
    operator/ (const box<_LxT>& lx, const box<_RxT>& rx)
    { return lx.div(rx); }


    /// \brief Division Operator
    ///
    /// \details Operator overload for `/` operator.
    /// Calls bx `div` method on scalar sx and returns
    /// the resulting box.
    /// 
    /// \tparam _ElemT concept: Any
    /// \tparam _ScalarT concept: Any
    /// \param bx type: box<_ElemT> | qualifiers: [const, ref]
    /// \param sx type: _ScalarT | qualifiers: [const, ref]
    /// \returns requires constexpr 
    template<Any _ElemT, Any _ScalarT>
        requires DivisibleWith<_ElemT, _ScalarT>
    constexpr auto
    operator/ (const box<_ElemT>& bx, const _ScalarT& sx)
    { return bx.div(sx); }


    /// \brief Division Assignment Operator
    ///
    /// \detail Operator overload for `/=` operator.
    /// Calls lx `div` method on rx and assigns the result
    /// to lx.
    ///
    /// \notes The left-hand-side box is mutable.
    /// \notes The left-hand-side boxes type must be
    /// able to to store the resulting type of the
    /// call to `div`.
    /// 
    /// \tparam _LxT concept: Any
    /// \tparam _RxT concept: Any
    /// \param lx type: box<_LxT> | qualifiers: [const, ref]
    /// \param rx type: box<_RxT> | qualifiers: [const, ref]
    /// \returns requires constexpr 
    template<Any _LxT, Any _RxT>
        requires DivisibleWith<_LxT, _RxT>
    constexpr void
    operator/= (box<_LxT>& lx, const box<_RxT>& rx)
    {
        if constexpr (!std::same_as<decltype(std::declval<box<_LxT>>().div(std::declval<box<_RxT>>())), box<_LxT>>)
            throw std::invalid_argument("operator*=: left-hand-side box type cannot store the resulting type of the call to `div`.");
        else
            lx = lx.div(rx);
    }


    /// \brief Division Assignment Operator
    /// 
    /// \details Operator overload for `/=` operator.
    /// Calls bx `div` method on scalar sx and assigns 
    /// the result to bx.
    ///
    /// \notes The left-hand-side box is mutable.
    /// \notes The left-hand-side boxes type must be
    /// able to to store the resulting type of the
    ///
    /// \tparam _ElemT concept: Any
    /// \tparam _ScalarT concept: Any
    /// \param bx type: box<_ElemT> | qualifiers: [const, ref]
    /// \param sx type: _ScalarT | qualifiers: [const, ref]
    /// \returns requires constexpr 
    template<Any _ElemT, Any _ScalarT>
        requires DivisibleWith<_ElemT, _ScalarT>
    constexpr void
    operator/= (box<_ElemT>& bx, const _ScalarT& sx)
    {
        if constexpr (!std::same_as<decltype(std::declval<box<_ElemT>>().div(std::declval<_ScalarT>())), box<_ElemT>>)
            throw std::invalid_argument("operator*=: left-hand-side box type cannot store the resulting type of the call to `div`.");
        else
            bx = bx.div(sx);
    }


    /// \brief Modulo Operator
    ///
    /// \detail Operator overload for `%` operator.
    /// Calls lx `mod` method on rx and returns
    /// the resulting box.
    /// 
    /// \tparam _LxT concept: Any
    /// \tparam _RxT concept: Any
    /// \param lx type: box<_LxT> | qualifiers: [const, ref]
    /// \param rx type: box<_RxT> | qualifiers: [const, ref]
    /// \returns constexpr auto 
    template<Any _LxT, Any _RxT>
        requires ModuloWith<_LxT, _RxT>
    constexpr auto
    operator% (const box<_LxT>& lx, const box<_RxT>& rx)
    { return lx.mod(rx); }


    /// \brief Modulo Operator
    ///
    /// \details Operator overload for `%` operator.
    /// Calls bx `mod` method on scalar sx and returns
    /// the resulting box.
    /// 
    /// \tparam _ElemT concept: Any
    /// \tparam _ScalarT concept: Any
    /// \param bx type: box<_ElemT> | qualifiers: [const, ref]
    /// \param sx type: _ScalarT | qualifiers: [const, ref]
    /// \returns requires constexpr 
    template<Any _ElemT, Any _ScalarT>
        requires ModuloWith<_ElemT, _ScalarT>
    constexpr auto
    operator% (const box<_ElemT>& bx, const _ScalarT& sx)
    { return bx.mod(sx); }


    /// \brief Modulo Assignment Operator
    ///
    /// \detail Operator overload for `%=` operator.
    /// Calls lx `mod` method on rx and assigns the result
    /// to lx.
    ///
    /// \notes The left-hand-side box is mutable.
    /// \notes The left-hand-side boxes type must be
    /// able to to store the resulting type of the
    /// call to `mod`.
    /// 
    /// \tparam _LxT concept: Any
    /// \tparam _RxT concept: Any
    /// \param lx type: box<_LxT> | qualifiers: [const, ref]
    /// \param rx type: box<_RxT> | qualifiers: [const, ref]
    /// \returns requires constexpr 
    template<Any _LxT, Any _RxT>
        requires ModuloWith<_LxT, _RxT>
    constexpr void
    operator%= (box<_LxT>& lx, const box<_RxT>& rx)
    {
        if constexpr (!std::same_as<decltype(std::declval<box<_LxT>>().mod(std::declval<box<_RxT>>())), box<_LxT>>)
            throw std::invalid_argument("operator*=: left-hand-side box type cannot store the resulting type of the call to `mod`.");
        else
            lx = lx.mod(rx);
    }


    /// \brief Modulo Assignment Operator
    /// 
    /// \details Operator overload for `%=` operator.
    /// Calls bx `mod` method on scalar sx and assigns 
    /// the result to bx.
    ///
    /// \notes The left-hand-side box is mutable.
    /// \notes The left-hand-side boxes type must be
    /// able to to store the resulting type of the
    ///
    /// \tparam _ElemT concept: Any
    /// \tparam _ScalarT concept: Any
    /// \param bx type: box<_ElemT> | qualifiers: [const, ref]
    /// \param sx type: _ScalarT | qualifiers: [const, ref]
    /// \returns requires constexpr 
    template<Any _ElemT, Any _ScalarT>
        requires ModuloWith<_ElemT, _ScalarT>
    constexpr void
    operator%= (box<_ElemT>& bx, const _ScalarT& sx)
    {
        if constexpr (!std::same_as<decltype(std::declval<box<_ElemT>>().mod(std::declval<_ScalarT>())), box<_ElemT>>)
            throw std::invalid_argument("operator*=: left-hand-side box type cannot store the resulting type of the call to `mod`.");
        else
            bx = bx.mod(sx);
    }


    /// \brief Bit And Operator
    ///
    /// \detail Operator overload for `&` operator.
    /// Calls lx `bit_and` method on rx and returns
    /// the resulting box.
    /// 
    /// \tparam _LxT concept: Any
    /// \tparam _RxT concept: Any
    /// \param lx type: box<_LxT> | qualifiers: [const, ref]
    /// \param rx type: box<_RxT> | qualifiers: [const, ref]
    /// \returns constexpr auto 
    template<Any _LxT, Any _RxT>
        requires BitAndWith<_LxT, _RxT>
    constexpr auto
    operator& (const box<_LxT>& lx, const box<_RxT>& rx)
    { return lx.bit_and(rx); }


    /// \brief Bit And Operator
    ///
    /// \details Operator overload for `&` operator.
    /// Calls bx `bit_and` method on scalar sx and returns
    /// the resulting box.
    /// 
    /// \tparam _ElemT concept: Any
    /// \tparam _ScalarT concept: Any
    /// \param bx type: box<_ElemT> | qualifiers: [const, ref]
    /// \param sx type: _ScalarT | qualifiers: [const, ref]
    /// \returns requires constexpr 
    template<Any _ElemT, Any _ScalarT>
        requires BitAndWith<_ElemT, _ScalarT>
    constexpr auto
    operator& (const box<_ElemT>& bx, const _ScalarT& sx)
    { return bx.bit_and(sx); }


    /// \brief Bit And Operator
    ///
    /// \details Operator overload for `&` operator.
    /// Calls bx `bit_and` method on scalar sx and returns
    /// the resulting box.
    /// 
    /// \tparam _ScalarT concept: Any
    /// \tparam _ElemT concept: Any
    /// \param sx type: _ScalarT | qualifiers: [const, ref]
    /// \param bx type: box<_ElemT> | qualifiers: [const, ref]
    /// \returns requires constexpr 
    template<Any _ScalarT, Any _ElemT>
        requires BitAndWith<_ScalarT, _ElemT>
    constexpr auto
    operator& (const _ScalarT& sx, const box<_ElemT>& bx)
    { return bx.bit_and(sx); }


    /// \brief Bit And Assignment Operator
    ///
    /// \detail Operator overload for `&=` operator.
    /// Calls lx `bit_and` method on rx and assigns the result
    /// to lx.
    ///
    /// \notes The left-hand-side box is mutable.
    /// \notes The left-hand-side boxes type must be
    /// able to to store the resulting type of the
    /// call to `bit_and`.
    /// 
    /// \tparam _LxT concept: Any
    /// \tparam _RxT concept: Any
    /// \param lx type: box<_LxT> | qualifiers: [const, ref]
    /// \param rx type: box<_RxT> | qualifiers: [const, ref]
    /// \returns requires constexpr 
    template<Any _LxT, Any _RxT>
        requires BitAndWith<_LxT, _RxT>
    constexpr void
    operator&= (box<_LxT>& lx, const box<_RxT>& rx)
    {
        if constexpr (!std::same_as<decltype(std::declval<box<_LxT>>().bit_and(std::declval<box<_RxT>>())), box<_LxT>>)
            throw std::invalid_argument("operator&=: left-hand-side box type cannot store the resulting type of the call to `bit_and`.");
        else
            lx = lx.bit_and(rx);
    }


    /// \brief Bit And Assignment Operator
    /// 
    /// \details Operator overload for `*=` operator.
    /// Calls bx `bit_and` method on scalar sx and assigns 
    /// the result to bx.
    ///
    /// \notes The left-hand-side box is mutable.
    /// \notes The left-hand-side boxes type must be
    /// able to to store the resulting type of the
    ///
    /// \tparam _ElemT concept: Any
    /// \tparam _ScalarT concept: Any
    /// \param bx type: box<_ElemT> | qualifiers: [const, ref]
    /// \param sx type: _ScalarT | qualifiers: [const, ref]
    /// \returns requires constexpr 
    template<Any _ElemT, Any _ScalarT>
        requires BitAndWith<_ElemT, _ScalarT>
    constexpr void
    operator&= (box<_ElemT>& bx, const _ScalarT& sx)
    {
        if constexpr (!std::same_as<decltype(std::declval<box<_ElemT>>().bit_and(std::declval<_ScalarT>())), box<_ElemT>>)
            throw std::invalid_argument("operator*=: left-hand-side box type cannot store the resulting type of the call to `bit_and`.");
        else
            bx = bx.bit_and(sx);
    }


    /// \brief Bit Or Operator
    ///
    /// \detail Operator overload for `*` operator.
    /// Calls lx `bit_or` method on rx and returns
    /// the resulting box.
    /// 
    /// \tparam _LxT concept: Any
    /// \tparam _RxT concept: Any
    /// \param lx type: box<_LxT> | qualifiers: [const, ref]
    /// \param rx type: box<_RxT> | qualifiers: [const, ref]
    /// \returns constexpr auto 
    template<Any _LxT, Any _RxT>
        requires BitOrWith<_LxT, _RxT>
    constexpr auto
    operator| (const box<_LxT>& lx, const box<_RxT>& rx)
    { return lx.bit_or(rx); }


    /// \brief Bit Or Operator
    ///
    /// \details Operator overload for `*` operator.
    /// Calls bx `bit_or` method on scalar sx and returns
    /// the resulting box.
    /// 
    /// \tparam _ElemT concept: Any
    /// \tparam _ScalarT concept: Any
    /// \param bx type: box<_ElemT> | qualifiers: [const, ref]
    /// \param sx type: _ScalarT | qualifiers: [const, ref]
    /// \returns requires constexpr 
    template<Any _ElemT, Any _ScalarT>
        requires BitOrWith<_ElemT, _ScalarT>
    constexpr auto
    operator| (const box<_ElemT>& bx, const _ScalarT& sx)
    { return bx.bit_or(sx); }


    /// \brief Bit Or Operator
    ///
    /// \details Operator overload for `*` operator.
    /// Calls bx `bit_or` method on scalar sx and returns
    /// the resulting box.
    /// 
    /// \tparam _ScalarT concept: Any
    /// \tparam _ElemT concept: Any
    /// \param sx type: _ScalarT | qualifiers: [const, ref]
    /// \param bx type: box<_ElemT> | qualifiers: [const, ref]
    /// \returns requires constexpr 
    template<Any _ScalarT, Any _ElemT>
        requires BitOrWith<_ScalarT, _ElemT>
    constexpr auto
    operator| (const _ScalarT& sx, const box<_ElemT>& bx)
    { return bx.bit_or(sx); }


    /// \brief Bit Or Assignment Operator
    ///
    /// \detail Operator overload for `*=` operator.
    /// Calls lx `bit_or` method on rx and assigns the result
    /// to lx.
    ///
    /// \notes The left-hand-side box is mutable.
    /// \notes The left-hand-side boxes type must be
    /// able to to store the resulting type of the
    /// call to `bit_or`.
    /// 
    /// \tparam _LxT concept: Any
    /// \tparam _RxT concept: Any
    /// \param lx type: box<_LxT> | qualifiers: [const, ref]
    /// \param rx type: box<_RxT> | qualifiers: [const, ref]
    /// \returns requires constexpr 
    template<Any _LxT, Any _RxT>
        requires BitOrWith<_LxT, _RxT>
    constexpr void
    operator|= (box<_LxT>& lx, const box<_RxT>& rx)
    {
        if constexpr (!std::same_as<decltype(std::declval<box<_LxT>>().bit_or(std::declval<box<_RxT>>())), box<_LxT>>)
            throw std::invalid_argument("operator*=: left-hand-side box type cannot store the resulting type of the call to `bit_or`.");
        else
            lx = lx.bit_or(rx);
    }


    /// \brief Bit Or Assignment Operator
    /// 
    /// \details Operator overload for `*=` operator.
    /// Calls bx `bit_or` method on scalar sx and assigns 
    /// the result to bx.
    ///
    /// \notes The left-hand-side box is mutable.
    /// \notes The left-hand-side boxes type must be
    /// able to to store the resulting type of the
    ///
    /// \tparam _ElemT concept: Any
    /// \tparam _ScalarT concept: Any
    /// \param bx type: box<_ElemT> | qualifiers: [const, ref]
    /// \param sx type: _ScalarT | qualifiers: [const, ref]
    /// \returns requires constexpr 
    template<Any _ElemT, Any _ScalarT>
        requires BitOrWith<_ElemT, _ScalarT>
    constexpr void
    operator|= (box<_ElemT>& bx, const _ScalarT& sx)
    {
        if constexpr (!std::same_as<decltype(std::declval<box<_ElemT>>().bit_or(std::declval<_ScalarT>())), box<_ElemT>>)
            throw std::invalid_argument("operator*=: left-hand-side box type cannot store the resulting type of the call to `bit_or`.");
        else
            bx = bx.bit_or(sx);
    }


    /// \brief Bit Xor Operator
    ///
    /// \detail Operator overload for `^` operator.
    /// Calls lx `bit_xor` method on rx and returns
    /// the resulting box.
    /// 
    /// \tparam _LxT concept: Any
    /// \tparam _RxT concept: Any
    /// \param lx type: box<_LxT> | qualifiers: [const, ref]
    /// \param rx type: box<_RxT> | qualifiers: [const, ref]
    /// \returns constexpr auto 
    template<Any _LxT, Any _RxT>
        requires BitXorWith<_LxT, _RxT>
    constexpr auto
    operator^ (const box<_LxT>& lx, const box<_RxT>& rx)
    { return lx.bit_xor(rx); }


    /// \brief Bit Xor Operator
    ///
    /// \details Operator overload for `^` operator.
    /// Calls bx `bit_xor` method on scalar sx and returns
    /// the resulting box.
    /// 
    /// \tparam _ElemT concept: Any
    /// \tparam _ScalarT concept: Any
    /// \param bx type: box<_ElemT> | qualifiers: [const, ref]
    /// \param sx type: _ScalarT | qualifiers: [const, ref]
    /// \returns requires constexpr 
    template<Any _ElemT, Any _ScalarT>
        requires BitXorWith<_ElemT, _ScalarT>
    constexpr auto
    operator^ (const box<_ElemT>& bx, const _ScalarT& sx)
    { return bx.bit_xor(sx); }


    /// \brief Bit Xor Operator
    ///
    /// \details Operator overload for `^` operator.
    /// Calls bx `bit_xor` method on scalar sx and returns
    /// the resulting box.
    /// 
    /// \tparam _ScalarT concept: Any
    /// \tparam _ElemT concept: Any
    /// \param sx type: _ScalarT | qualifiers: [const, ref]
    /// \param bx type: box<_ElemT> | qualifiers: [const, ref]
    /// \returns requires constexpr 
    template<Any _ScalarT, Any _ElemT>
        requires BitXorWith<_ScalarT, _ElemT>
    constexpr auto
    operator^ (const _ScalarT& sx, const box<_ElemT>& bx)
    { return bx.bit_xor(sx); }


    /// \brief Bit Xor Assignment Operator
    ///
    /// \detail Operator overload for `^=` operator.
    /// Calls lx `bit_xor` method on rx and assigns the result
    /// to lx.
    ///
    /// \notes The left-hand-side box is mutable.
    /// \notes The left-hand-side boxes type must be
    /// able to to store the resulting type of the
    /// call to `bit_xor`.
    /// 
    /// \tparam _LxT concept: Any
    /// \tparam _RxT concept: Any
    /// \param lx type: box<_LxT> | qualifiers: [const, ref]
    /// \param rx type: box<_RxT> | qualifiers: [const, ref]
    /// \returns requires constexpr 
    template<Any _LxT, Any _RxT>
        requires BitXorWith<_LxT, _RxT>
    constexpr void
    operator^= (box<_LxT>& lx, const box<_RxT>& rx)
    {
        if constexpr (!std::same_as<decltype(std::declval<box<_LxT>>().bit_xor(std::declval<box<_RxT>>())), box<_LxT>>)
            throw std::invalid_argument("operator*=: left-hand-side box type cannot store the resulting type of the call to `bit_xor`.");
        else
            lx = lx.bit_xor(rx);
    }


    /// \brief Bit Xor Assignment Operator
    /// 
    /// \details Operator overload for `^=` operator.
    /// Calls bx `bit_xor` method on scalar sx and assigns 
    /// the result to bx.
    ///
    /// \notes The left-hand-side box is mutable.
    /// \notes The left-hand-side boxes type must be
    /// able to to store the resulting type of the
    ///
    /// \tparam _ElemT concept: Any
    /// \tparam _ScalarT concept: Any
    /// \param bx type: box<_ElemT> | qualifiers: [const, ref]
    /// \param sx type: _ScalarT | qualifiers: [const, ref]
    /// \returns requires constexpr 
    template<Any _ElemT, Any _ScalarT>
        requires BitXorWith<_ElemT, _ScalarT>
    constexpr void
    operator^= (box<_ElemT>& bx, const _ScalarT& sx)
    {
        if constexpr (!std::same_as<decltype(std::declval<box<_ElemT>>().bit_xor(std::declval<_ScalarT>())), box<_ElemT>>)
            throw std::invalid_argument("operator*=: left-hand-side box type cannot store the resulting type of the call to `bit_xor`.");
        else
            bx = bx.bit_xor(sx);
    }


    /// \brief Left Bit Shift Operator
    ///
    /// \detail Operator overload for `<<` operator.
    /// Calls lx `shift_left` method on rx and returns
    /// the resulting box.
    /// 
    /// \tparam _LxT concept: Any
    /// \tparam _RxT concept: Any
    /// \param lx type: box<_LxT> | qualifiers: [const, ref]
    /// \param rx type: box<_RxT> | qualifiers: [const, ref]
    /// \returns constexpr auto 
    template<Any _LxT, Any _RxT>
        requires LeftBitShiftWith<_LxT, _RxT>
    constexpr auto
    operator<< (const box<_LxT>& lx, const box<_RxT>& rx)
    { return lx.shift_left(rx); }


    /// \brief Left Bit Shift Operator
    ///
    /// \details Operator overload for `<<` operator.
    /// Calls bx `shift_left` method on scalar sx and returns
    /// the resulting box.
    /// 
    /// \tparam _ElemT concept: Any
    /// \tparam _ScalarT concept: Any
    /// \param bx type: box<_ElemT> | qualifiers: [const, ref]
    /// \param sx type: _ScalarT | qualifiers: [const, ref]
    /// \returns requires constexpr 
    template<Any _ElemT, Any _ScalarT>
        requires LeftBitShiftWith<_ElemT, _ScalarT>
    constexpr auto
    operator<< (const box<_ElemT>& bx, const _ScalarT& sx)
    { return bx.shift_left(sx); }


    /// \brief Left Bit Shift Assignment Operator
    ///
    /// \detail Operator overload for `<<=` operator.
    /// Calls lx `shift_left` method on rx and assigns the result
    /// to lx.
    ///
    /// \notes The left-hand-side box is mutable.
    /// \notes The left-hand-side boxes type must be
    /// able to to store the resulting type of the
    /// call to `shift_left`.
    /// 
    /// \tparam _LxT concept: Any
    /// \tparam _RxT concept: Any
    /// \param lx type: box<_LxT> | qualifiers: [const, ref]
    /// \param rx type: box<_RxT> | qualifiers: [const, ref]
    /// \returns requires constexpr 
    template<Any _LxT, Any _RxT>
        requires LeftBitShiftWith<_LxT, _RxT>
    constexpr void
    operator<<= (box<_LxT>& lx, const box<_RxT>& rx)
    {
        if constexpr (!std::same_as<decltype(std::declval<box<_LxT>>().shift_left(std::declval<box<_RxT>>())), box<_LxT>>)
            throw std::invalid_argument("operator*=: left-hand-side box type cannot store the resulting type of the call to `shift_left`.");
        else
            lx = lx.shift_left(rx);
    }


    /// \brief Left Bit Shift Assignment Operator
    /// 
    /// \details Operator overload for `<<=` operator.
    /// Calls bx `shift_left` method on scalar sx and assigns 
    /// the result to bx.
    ///
    /// \notes The left-hand-side box is mutable.
    /// \notes The left-hand-side boxes type must be
    /// able to to store the resulting type of the
    ///
    /// \tparam _ElemT concept: Any
    /// \tparam _ScalarT concept: Any
    /// \param bx type: box<_ElemT> | qualifiers: [const, ref]
    /// \param sx type: _ScalarT | qualifiers: [const, ref]
    /// \returns requires constexpr 
    template<Any _ElemT, Any _ScalarT>
        requires LeftBitShiftWith<_ElemT, _ScalarT>
    constexpr void
    operator<<= (box<_ElemT>& bx, const _ScalarT& sx)
    {
        if constexpr (!std::same_as<decltype(std::declval<box<_ElemT>>().shift_left(std::declval<_ScalarT>())), box<_ElemT>>)
            throw std::invalid_argument("operator*=: left-hand-side box type cannot store the resulting type of the call to `shift_left`.");
        else
            bx = bx.shift_left(sx);
    }


    /// \brief Right Bit Shift Operator
    ///
    /// \detail Operator overload for `>>` operator.
    /// Calls lx `shift_right` method on rx and returns
    /// the resulting box.
    /// 
    /// \tparam _LxT concept: Any
    /// \tparam _RxT concept: Any
    /// \param lx type: box<_LxT> | qualifiers: [const, ref]
    /// \param rx type: box<_RxT> | qualifiers: [const, ref]
    /// \returns constexpr auto 
    template<Any _LxT, Any _RxT>
        requires RightBitShiftWith<_LxT, _RxT>
    constexpr auto
    operator>> (const box<_LxT>& lx, const box<_RxT>& rx)
    { return lx.shift_right(rx); }


    /// \brief Right Bit Shift Operator
    ///
    /// \details Operator overload for `>>` operator.
    /// Calls bx `shift_right` method on scalar sx and returns
    /// the resulting box.
    /// 
    /// \tparam _ElemT concept: Any
    /// \tparam _ScalarT concept: Any
    /// \param bx type: box<_ElemT> | qualifiers: [const, ref]
    /// \param sx type: _ScalarT | qualifiers: [const, ref]
    /// \returns requires constexpr 
    template<Any _ElemT, Any _ScalarT>
        requires RightBitShiftWith<_ElemT, _ScalarT>
    constexpr auto
    operator>> (const box<_ElemT>& bx, const _ScalarT& sx)
    { return bx.shift_right(sx); }


    /// \brief Right Bit Shift Assignment Operator
    ///
    /// \detail Operator overload for `>>=` operator.
    /// Calls lx `shift_right` method on rx and assigns the result
    /// to lx.
    ///
    /// \notes The right-hand-side box is mutable.
    /// \notes The right-hand-side boxes type must be
    /// able to to store the resulting type of the
    /// call to `shift_right`.
    /// 
    /// \tparam _LxT concept: Any
    /// \tparam _RxT concept: Any
    /// \param lx type: box<_LxT> | qualifiers: [const, ref]
    /// \param rx type: box<_RxT> | qualifiers: [const, ref]
    /// \returns requires constexpr 
    template<Any _LxT, Any _RxT>
        requires RightBitShiftWith<_LxT, _RxT>
    constexpr void
    operator>>= (box<_LxT>& lx, const box<_RxT>& rx)
    {
        if constexpr (!std::same_as<decltype(std::declval<box<_LxT>>().shift_right(std::declval<box<_RxT>>())), box<_LxT>>)
            throw std::invalid_argument("operator*=: right-hand-side box type cannot store the resulting type of the call to `shift_right`.");
        else
            lx = lx.shift_right(rx);
    }


    /// \brief Right Bit Shift Assignment Operator
    /// 
    /// \details Operator overload for `>>=` operator.
    /// Calls bx `shift_right` method on scalar sx and assigns 
    /// the result to bx.
    ///
    /// \notes The right-hand-side box is mutable.
    /// \notes The right-hand-side boxes type must be
    /// able to to store the resulting type of the
    ///
    /// \tparam _ElemT concept: Any
    /// \tparam _ScalarT concept: Any
    /// \param bx type: box<_ElemT> | qualifiers: [const, ref]
    /// \param sx type: _ScalarT | qualifiers: [const, ref]
    /// \returns requires constexpr 
    template<Any _ElemT, Any _ScalarT>
        requires RightBitShiftWith<_ElemT, _ScalarT>
    constexpr void
    operator>>= (box<_ElemT>& bx, const _ScalarT& sx)
    {
        if constexpr (!std::same_as<decltype(std::declval<box<_ElemT>>().shift_right(std::declval<_ScalarT>())), box<_ElemT>>)
            throw std::invalid_argument("operator*=: right-hand-side box type cannot store the resulting type of the call to `shift_right`.");
        else
            bx = bx.shift_right(sx);
    }


    /// \brief Bitwise Not Operator
    ///
    /// \details Operator overload for `~` operator.
    /// Calls bx `bit_not` method and returns the 
    /// resulting box. 
    /// 
    /// \tparam _ElemT : concept: BitNot
    /// \param bx type: box<_ElemT> | qualifiers: [const, ref]
    /// \returns constexpr auto 
    template<BitNot _ElemT>
    constexpr auto
    operator~ (box<_ElemT> bx)
    { return bx.bit_not(); }


    /// \brief Transpose Operator
    ///
    /// \details Operator overload for `!` operator.
    /// Calls bx `transpose` method and returns the
    /// resulting box. 
    /// 
    /// \tparam _ElemT concept: Any
    /// \param bx type: box<_ElemT> | qualifiers: [const, ref]
    /// \returns constexpr auto 
    template<Any _ElemT>
    constexpr auto
    operator! (box<_ElemT> bx)
    { return bx.transpose(); }


    template<Any _ElemT, std::copy_constructible F>
    constexpr auto
    operator|| (box<_ElemT> bx, F f)
    { return bx.map(f); }

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
    /// \param x type: [cortex::box<T>] | qualifiers: [const, ref]
    /// \param y type: [cortex::box<T>] | qualifiers: [const, ref]
    /// \returns inline void
    template <typename T>
    inline void swap(cortex::box<T>& x, cortex::box<T>& y) noexcept
    { x.swap(y); }
}

#endif // __cplusplus >= 201703L

#endif // CORTEX_BOX_H