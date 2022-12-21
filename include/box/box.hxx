/// -*- C++ -*- Header compatibility <box/box.hxx>

/// \brief Two Dimensional Access To Contiguous Data.
///
/// Author: Tyler Swann (tyler.swann05@gmail.com)
/// 
/// Header Version: v0.0.1
///
/// Date: 21-12-2022
///
/// License: MIT
///
/// Copyright: Copyright (c) 2022
/// \file box/box.hxx

#ifndef CORTEX_BOX_H
#   define CORTEX_BOX_H

#include <iterator/normal.hxx>

#if __cplusplus >= 202002L

#include <algorithm>
#include <cassert>
#include <functional>
#include <initializer_list>
#include <memory>
#include <span>
#include <utility>
#include <vector>

namespace cxl
{
    /// \brief Box - Two Dimensional Array
    ///
    /// \group box Box
    ///
    /// \details Box is a two dimensional generic container.
    /// It aims to support expressive methods and operations
    /// that allow unique manipulation an structural access 
    /// to data.
    /// Elements are stored continuously in memory and are 
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

        using iterator                              = cxl::normal_iterator<pointer, box<value_type>>;
        using const_iterator                        = cxl::normal_iterator<const_pointer, box<value_type>>;
        using reverse_iterator                      = std::reverse_iterator<iterator>;
        using const_reverse_iterator                = std::reverse_iterator<const_iterator>;

    private:
        size_type m_num_rows;
        size_type m_num_columns;

        allocator_type m_allocator;
        pointer m_start;
        pointer m_finish;

    public:

        /// \brief Default Constructor
        ///
        /// \details Default constructor for box.
        constexpr box() noexcept
        : m_num_rows(size_type())
        , m_num_columns(size_type())
        , m_allocator(allocator_type())
        , m_start(pointer())
        , m_finish(pointer())
        { }


        /// \brief Allocator Constructor
        ///
        /// \details Default Constructs a box with a
        /// given allocator.
        ///
        /// \param alloc type: {allocator_type} | qualifiers: {const, ref}
        constexpr explicit box(const allocator_type& alloc) noexcept
        : m_num_rows(size_type())
        , m_num_columns(size_type())
        , m_allocator(alloc)
        , m_start(pointer())
        , m_finish(pointer())
        { }


        /// \brief Size Constructor
        ///
        /// \details Constructs a box with dimensions of
        /// num_rows x num_columns. Values are default constructed 
        /// or fill constructed depending on the default 
        /// contractibility qualification.
        ///
        /// \param num_columns type: {size_type}
        /// \param num_rows type: {size_type}
        /// \param alloc type: {allocator_type} | qualifiers: {const, ref}
        constexpr explicit box(size_type num_rows, size_type num_columns, const allocator_type& alloc = allocator_type())
        : m_num_rows(num_rows)
        , m_num_columns(num_columns)
        , m_allocator(alloc)
        , m_start(_M_allocate(_M_size(m_num_rows, m_num_columns)))
        , m_finish(m_start + _M_size(m_num_rows, m_num_columns))
        {
            if constexpr (std::is_default_constructible_v<value_type>)
                std::ranges::uninitialized_default_construct(*this);
            else
                std::ranges::uninitialized_fill(*this, value_type());
        }


        /// \brief Size + Value Constructor
        ///
        /// \details Constructs a box with dimensions of
        /// num_rows x num_columns. Values are constructed from 
        /// the a constant reference to a provided value.
        ///
        /// \param num_columns type: {size_type}
        /// \param num_rows type: {size_type}
        /// \param value type: value_type | qualifiers: {const, ref}
        /// \param alloc type: {allocator_type} | qualifiers: {const, ref}
        constexpr box(size_type num_rows, size_type num_columns, const_reference value, const allocator_type& alloc = allocator_type())
        : m_num_rows(num_rows)
        , m_num_columns(num_columns)
        , m_allocator(alloc)
        , m_start(_M_allocate(_M_size(m_num_rows, m_num_columns)))
        , m_finish(m_start + _M_size(m_num_rows, m_num_columns))
        { std::ranges::uninitialized_fill(*this, value); }


        /// \brief Copy Constructor
        ///
        /// \details Constructs a box that is a copy of
        /// another box of the same underlying type.
        ///
        /// \param other type: {box} | qualifiers: {const, ref}
        constexpr box(const box& other)
        : m_num_rows(other.m_num_rows)
        , m_num_columns(other.m_num_columns)
        , m_allocator(other.m_allocator)
        , m_start(_M_allocate(_M_size(m_num_rows, m_num_columns)))
        , m_finish(m_start + _M_size(m_num_rows, m_num_columns))
        { std::ranges::uninitialized_copy(other, *this); }


        /// \brief Copy Constructor with Alternative Allocator
        ///
        /// \details Constructs a box that is a copy of
        /// another box of the same underlying type.
        ///
        /// \param other type: {box} | qualifiers: {const, ref}
        /// \param alloc type: {allocator_type} | qualifiers: {const, ref}
        constexpr box(const box& other, const allocator_type& alloc)
        : m_num_rows(other.m_num_rows)
        , m_num_columns(other.m_num_columns)
        , m_allocator(alloc)
        , m_start(_M_allocate(_M_size(m_num_rows, m_num_columns)))
        , m_finish(m_start + _M_size(m_num_rows, m_num_columns))
        { std::ranges::uninitialized_copy(other, *this); }


        /// \brief Move Constructor
        ///
        /// \details Moves ownership of an existing box's
        /// resources to this box and leaves the other box
        /// in a default constructed state.
        ///
        /// \param other type: {box} | qualifiers: {move}
        constexpr box(box&& other) noexcept
        : m_num_rows(other.m_num_rows)
        , m_num_columns(other.m_num_columns)
        , m_allocator(std::move(other.m_allocator))
        , m_start(other.m_start)
        , m_finish(other.m_finish)
        {
            other.m_start = pointer();
            other.m_finish = pointer();
            other.m_allocator = allocator_type();
            other.m_num_rows = size_type();
            other.m_num_columns = size_type();
        }


        /// \brief Move Constructor with Alternative Allocator
        ///
        /// \details Moves ownership of an existing box's
        /// resources to this box and leaves the other box
        /// in a default constructed state. Uses an alternative
        /// allocator for construction of `this` box.
        ///
        /// \param other type: {box} | qualifiers: {move}
        /// \param alloc type: {{allocator_type}} | qualifiers: {const, ref}
        constexpr box(box&& other, const allocator_type& alloc) noexcept
        : m_num_rows(other.m_num_rows)
        , m_num_columns(other.m_num_columns)
        , m_allocator(alloc)
        , m_start(other.m_start)
        , m_finish(other.m_finish)
        {
            other.m_start = pointer();
            other.m_finish = pointer();
            other.m_allocator = allocator_type();
            other.m_num_rows = size_type();
            other.m_num_columns = size_type();
            other.m_size = size_type();
        }


        /// \brief Assign Copy Constructor
        ///
        /// \details Iterates from first to last and copys the
        /// elements to this box. Copy is done through the boxes
        /// begin() iterator, thus copy is done row-wise.
        ///
        /// \tparam It concept: {std::input_iterator}
        /// \param first type: {It}
        /// \param last type: {It}
        /// \param num_rows type: {size_type}
        /// \param num_columns type: {size_type}
        /// \param alloc type: {allocator_type} | qualifiers: {const, ref} | attribute: [[maybe_unused]]
        template <std::input_iterator It>
        constexpr box(It first, It last
                    , size_type num_rows, size_type num_columns
                    , [[maybe_unused]] const allocator_type& alloc = allocator_type())
        : m_num_rows(num_rows)
        , m_num_columns(num_columns)
        , m_allocator(alloc)
        , m_start(_M_allocate(_M_size(m_num_rows, m_num_columns)))
        , m_finish(m_start + _M_size(m_num_rows, m_num_columns))
        { std::ranges::uninitialized_copy(first, last, begin(), end()); }


        /// \brief Initialiser List Constructor
        ///
        /// \details Uses std::initializer_list to create a box
        /// from an initializer list of initializer lists. Elements
        /// ownership is moved to the box's memory.
        ///
        /// \param list type: [std::initializer_list<std::initializer_list<value_type>>] | qualifiers: {const, ref}
        /// \param alloc type: {allocator_type} | qualifiers: {const, ref} | attribute: [[maybe_unused]]
        constexpr box(std::initializer_list<std::initializer_list<value_type>> list
                    , [[maybe_unused]] const allocator_type& alloc = allocator_type())
        : m_num_rows(list.size())
        , m_num_columns(list.begin()->size())
        , m_allocator(alloc)
        , m_start(_M_allocate(_M_size(m_num_rows, m_num_columns)))
        , m_finish(m_start + _M_size(m_num_rows, m_num_columns))
        {
            using init_iter = typename decltype(list)::iterator;
            auto offset{ 0uL };
            for (init_iter row{list.begin()}; row != list.end(); ++row)
            {
                if (row->size() != this->m_num_columns)
                    throw std::invalid_argument("Columns must be all the same size");
                std::uninitialized_move_n(row->begin(), this->m_num_columns, m_start + offset);
                offset += this->m_num_columns;
            }
        }


        /// \brief Dimension Constructor
        ///
        /// \details Constructs a box from the dimensions 
        /// of another. The box is default constructed. Takes
        /// the result of a call to `box::dimension()`.
        ///
        /// \param dimensions type: {std::tuple<size_type, size_type>} | qualifiers: {const, ref}
        /// \param alloc type: {allocator_type} | qualifiers: {const, ref} | attribute: [[maybe_unused]]
        constexpr box(const std::tuple<size_type, size_type>& dimensions
                     , [[maybe_unused]] const allocator_type& alloc = allocator_type())
        : m_num_rows(std::get<0>(dimensions))
        , m_num_columns(std::get<1>(dimensions))
        , m_allocator(alloc)
        , m_start(_M_allocate(_M_size(m_num_rows, m_num_columns)))
        , m_finish(m_start + _M_size(m_num_rows, m_num_columns))
        { 
            if constexpr (std::is_default_constructible_v<value_type>)
                std::ranges::uninitialized_default_construct(*this);
            else
                std::ranges::uninitialized_fill(*this, value_type());
        }


        /// \brief Copy Assignment
        ///
        /// \details Copies the contents of another box into
        /// this box and returns///this. If self assignment occurs
        /// then///this is returned immediately.
        ///
        /// \param other type: {box} | qualifiers: {const, ref}
        /// \returns constexpr box&
        constexpr box& operator= (const box& other)
        {
            if (*this != other)
            {
                m_num_rows = other.m_num_rows;
                m_num_columns = other.m_num_columns;
                m_allocator = other.m_allocator;
                m_start = _M_allocate(_M_size(m_num_rows, m_num_columns));
                m_finish = m_start + _M_size(m_num_rows, m_num_columns);
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
        /// \param other type: {box} | qualifiers: {move}
        /// \returns constexpr box&
        constexpr box& operator= (box&& other) noexcept
        {
            if (*this != other)
            {
                m_num_rows = other.m_num_rows;
                m_num_columns = other.m_num_columns;
                m_allocator = std::move(other.m_allocator);
                m_start = other.m_start;
                m_finish = other.m_finish;

                other.m_start = pointer();
                other.m_finish = pointer();
                other.m_allocator = allocator_type();
                other.m_num_rows = size_type();
                other.m_num_columns = size_type();
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
            m_num_rows = list.size();
            m_num_columns = list.begin()->size();
            m_start = _M_allocate(_M_size(m_num_rows, m_num_columns));
            m_finish = m_start + _M_size(m_num_rows, m_num_columns);

            using init_iter = typename decltype(list)::iterator;
            auto offset{0uL};
            for (init_iter row{list.begin()}; row != list.end(); ++row)
            {
                if (row->size() != this->m_num_columns)
                    throw std::invalid_argument("Columns must be all the same size");
                std::uninitialized_move_n(row->begin(), this->m_num_columns, m_start + offset);
                offset += this->m_num_columns;
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
                _M_deallocate(m_start, _M_size(m_num_rows, m_num_columns));
            }

            m_num_rows = size_type();
            m_num_columns = size_type();
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

            if (new_rows != m_num_rows || new_columns != m_num_columns)
            {
                if (m_start)
                    _M_deallocate(m_start, _M_size(m_num_rows, m_num_columns));
            
                m_start = _M_allocate(_M_size(new_rows, new_columns));
                m_finish = m_start + _M_size(new_rows, new_columns);
            }
            
            m_num_rows = new_rows;
            m_num_columns = new_columns;

            using init_iter = typename decltype(list)::iterator;
            auto offset{ 0uL };
            for (init_iter row{ list.begin() }; row != list.end(); ++row)
            {
                if (row->size() != this->m_num_columns)
                    throw std::invalid_argument("Columns must be all the same size");

                std::uninitialized_move_n(row->begin(), this->m_num_columns, m_start + offset);
                offset += this->m_num_columns;
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
        /// \param new_rows type: {size_type}
        /// \param new_columns type: {size_type}
        constexpr void resize(size_type new_rows, size_type new_columns)
        {
            auto old_size{_M_size(m_num_rows, m_num_columns)};

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

            m_num_rows = new_rows;
            m_num_columns = new_columns;
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
        /// \param new_rows type: {size_type}
        /// \param new_columns type: {size_type}
        /// \param value type: value_type | qualifiers: {const, ref}
        constexpr void resize(size_type new_rows, size_type new_columns, const_reference value)
        {
            auto old_size{_M_size(m_num_rows, m_num_columns)};

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

            m_num_rows = new_rows;
            m_num_columns = new_columns;
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
            if (_M_size(m_num_rows, m_num_columns))
            {
                erase(begin(), end());

                _M_deallocate(m_start, _M_size(m_num_rows, m_num_columns));
                m_num_rows = size_type();
                m_num_columns = size_type();
                m_finish = m_start = pointer();
            }
        }


        /// \brief Reshape current box elements to new dimensions
        ///
        /// \details Reshapes the current box's dimensions while
        /// guaranteeing that now reallocation occurs. Elements are
        /// preserved.
        ///
        /// \param new_rows type: {size_type}
        /// \param new_columns type: {size_type}
        constexpr void reshape(size_type new_rows, size_type new_columns)
        {
            auto new_size{ _M_size(new_rows, new_columns) };

            if (new_size != _M_size(m_num_rows, m_num_columns))
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
        /// \param other type: {box} | qualifiers: [ref]
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
        { return empty() ? size_type(0) : _M_size(m_num_rows, m_num_columns); }


        /// \brief Row Size
        /// 
        /// \details Returns the number of the num_rows of the box.
        ///
        /// \returns constexpr size_type
        constexpr size_type num_rows() const noexcept
        { return m_num_rows; }


        /// \brief Column Size
        /// 
        /// \details Returns the the number of num_columns in the box.
        ///
        /// \returns constexpr size_type
        constexpr size_type num_columns() const noexcept
        { return m_num_columns; }


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
            -> std::pair<size_type, size_type>
        { return std::pair{m_num_rows, m_num_columns}; }


        /// \brief Is Square
        ///
        /// \details If the number of num_rows and num_columns 
        /// are equal, the box is square.
        ///
        /// \returns true
        /// \returns false
        constexpr bool is_square() const noexcept
        { return m_num_rows == m_num_columns; }


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

        /// \brief Two Dimensional Element Access (Point Access).
        ///
        /// \details Returns a reference to the element that
        /// is at the point position (column, row) of the
        /// box.
        ///
        /// \exception std::out_of_range
        ///
        /// \param column type: {size_type}
        /// \param row type: {size_type}
        /// \returns constexpr reference
        constexpr reference at(size_type row, size_type column)
        {
            _M_range_check(row, column);
            return *(m_start + (m_num_columns * row) + column);
        }

        /// \brief At
        ///
        /// \details Returns a reference to the element that
        /// is at the point position (column, row) of the
        /// box.
        ///
        /// \exception std::out_of_range
        ///
        /// \param column type: {size_type}
        /// \param row type: {size_type}
        /// \returns constexpr const_reference
        constexpr const_reference at(size_type row, size_type column) const
        {
            _M_range_check(row, column);
            return *(m_start + (m_num_columns * row) + column);
        }

        /// \brief Point Access Operator
        ///
        /// \details Provides point access to box's elements.
        /// Overloads the invocation operator. Utilises the at() method.
        ///
        /// \exception std::out_of_range
        ///
        /// \param column type: {size_type}
        /// \param row type: {size_type}
        /// \returns constexpr reference
        constexpr reference operator()(size_type row, size_type column)
        { return at(row, column); }

        /// \brief Point Access Operator
        ///
        /// \details Provides point access to box's elements.
        /// Overloads the invocation operator. Utilises the at() method.
        ///
        /// \exception std::out_of_range
        ///
        /// \param column type: {size_type}
        /// \param row type: {size_type}
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


        /// \brief Box Transpose
        ///
        /// \details Performs a box transpose.
        /// Uses std::copy over std::ranges::copy as the output
        /// iterator is required to be std::constructible_v which
        /// column_iterator doesn't satisfy yet.
        ///
        /// \returns constexpr auto
        // constexpr auto 
        // transpose()
        // {
        //     box<value_type> result(this->num_columns(), this->num_rows());

        //     if (empty())
        //         return result;

        //     std::ranges::copy(*this, result.column_begin());

        //     return result;
        // }


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
                box<std::invoke_result_t<F, value_type>> result(this->num_rows(), this->num_columns());
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
                box<std::invoke_result_t<F, value_type, range_elem_t>> result(this->num_rows(), this->num_columns());
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
                box<std::invoke_result_t<F, value_type, iterator_elem_t>> result(this->num_rows(), this->num_columns());
                std::ranges::transform(this->begin(), this->end(), first, last, result.begin(), func);
                return result;
            }
        }


        /// \brief Vertical Flip
        ///
        /// \details Performs a vertical flip of the box.
        /// ie. The order of the num_rows is reversed. If 
        /// `this` box is empty, an empty box is returned
        /// with no memory allocated to it.
        /// 
        /// \returns constexpr auto 
        // constexpr auto vflip() const
        // {
        //     if (empty())
        //         return box<value_type>{};
        //     else
        //     {
        //         box<value_type> result(this->num_rows(), this->num_columns());

        //         for (auto cidx { 0u }; cidx < this->num_columns(); ++cidx)
        //             std::ranges::copy(this->column_begin(cidx), this->column_end(cidx), result.column_rbegin(cidx));

        //         return result;
        //     }
        // }

        /// \brief Horizontal Flip
        ///
        /// \details Performs a horizontal flip of the box.
        /// ie. The order of the num_columns is reversed. If 
        /// `this` box is empty, an empty box is returned
        /// with no memory allocated to it.
        /// 
        /// \returns constexpr auto 
        // constexpr auto hflip() const
        // {
        //     if (empty())
        //         return box<value_type>{};
        //     else
        //     {
        //         box<value_type> result(this->num_rows(), this->num_columns());
        //             for (auto ridx { 0u }; ridx < this->num_rows(); ++ridx)
        //                 std::ranges::copy(this->row_begin(ridx), this->row_end(ridx), result.row_rbegin(ridx));

        //         return result;
        //     }
        // }


        /// \brief Right Rotate
        ///
        /// Rotates the box 90 degrees clockwise. Inverts the 
        /// dimension sizes of the box. If `this` box is empty,
        /// an empty box is returned with no memory allocated to it.
        /// 
        /// \returns constexpr auto 
        // constexpr auto rrotate() const
        // {
        //     if (empty())
        //         return box<value_type>{};
        //     else
        //     {
        //         box<value_type> result(this->num_columns(), this->num_rows());

        //         for (auto cidx { 0u }; cidx < this->num_columns(); ++cidx)
        //             std::ranges::copy(this->column_begin(cidx), this->column_end(cidx), result.row_rbegin(cidx));

        //         return result;
        //     }
        // }


        /// \brief Left Rotate
        ///
        /// Rotates the box 90 degrees counter-clockwise. Inverts 
        /// the dimension sizes of the box. If `this` box is empty,
        /// an empty box is returned with no memory allocated to it.
        /// 
        /// \returns constexpr auto 
        // constexpr auto lrotate() const
        // {
        //     if (empty())
        //         return box<value_type>{};
        //     else
        //     {
        //         box<value_type> result(this->num_columns(), this->num_rows());

        //         for (auto ridx { 0u }; ridx < this->num_rows(); ++ridx)
        //             std::ranges::copy(this->row_begin(ridx), this->row_end(ridx), result.column_rbegin(ridx));

        //         return result;
        //     }
        // }

    private:
        /// \brief Allocates `Box` Resources
        ///
        /// \details Allocates the memory for the box
        /// using the allocator of the container. Uses
        /// std::allocator_traits to get the allocators
        /// relevant methods.
        ///
        /// \notes Default allocator is std::allocator<value_type>.
        ///
        /// \param n type: {size_type}
        /// \returns constexpr pointer
        constexpr pointer _M_allocate(size_type n)
        { return n != 0 ? alloc_traits::allocate(m_allocator, n) : pointer(); }

        /// \brief Deallocates `Box` Resources
        ///
        /// \details Deallocates the memory for the box
        /// using the allocator of the container. Uses
        /// std::allocator_traits to get the allocators
        /// relevant methods.
        ///
        /// \param ptr type: pointer
        /// \param n type: {size_type} | attribute: [[maybe_unused]]
        constexpr void _M_deallocate(pointer ptr, [[maybe_unused]] size_type n)
        {
            if (ptr)
                alloc_traits::deallocate(m_allocator, ptr, n);
        }

        /// \brief Checks index's are in the bounds of the box
        ///
        /// \details Checks if column and row are withing
        /// the box's bounds.
        ///
        /// \exception std::out_of_range
        ///
        /// \param column type: {size_type}
        /// \param row type: {size_type}
        constexpr void _M_range_check(size_type row, size_type column) const
        {
            if (row >= this->num_rows() || column >= this->num_columns())
                throw std::out_of_range("box::_M_range_check - index out of range.");
        }

        constexpr size_type _M_size(size_type num_rows, size_type num_columns) const noexcept
        { return num_rows * num_columns != 0 ? num_rows * num_columns : std::max(num_rows, num_columns); }


        constexpr size_type _M_index(size_type row, size_type column) const noexcept
        { return row * num_columns() + column; }

        /// \brief Returns the pointer passed to it.
        ///
        /// \tparam U
        /// \param ptr type: U*
        /// \returns U*
        template <typename U>
        U* _M_data_ptr(U* ptr) const noexcept
        { return ptr; }

#if __cplusplus >= 201103L

        /// \brief Returns the pointer passed to it.
        ///
        /// \details If the value given is not a builtin
        /// pointer type, a pointer is created from the
        /// underlying element type.
        ///
        /// \tparam Ptr
        /// \param ptr type: Ptr
        /// \returns typename std::pointer_traits<Ptr>::element_type*
        template <typename Ptr>
        typename std::pointer_traits<Ptr>::element_type*
        _M_data_ptr(Ptr ptr) const
        { return empty() ? nullptr : std::to_address(*ptr); }
#else

        /// \brief Returns the given pointer
        ///
        /// \details Returns the pointer given to it is
        /// a builtin pointer type.
        ///
        /// \tparam U
        /// \param ptr type: U*
        /// \returns U*
        template <typename U>
        U* _M_data_ptr(U* ptr) noexcept
        {
            return ptr;
        }
#endif // __cplusplus >= 201103L
    
    };  /// class box

    /// \brief Compares two matrices for equality.
    ///
    /// \group box Part of the operator set on boxes that perform comparisons. 
    ///
    /// \details Uses std::equal to compare the matrices.
    /// Takes at least O(n) where n = num_columns x num_rows = lhs.end() - lhs.begin()
    ///
    /// \requires Matrix elements support equality comparison
    /// that converts to a bool
    ///
    /// \exception Operation is has no exception iff the comparison
    /// between box elements is noexcept and std::equal is
    /// noexcept across the range
    ///
    /// \tparam ElemL
    /// \tparam ElemR
    /// \rparam lhsE type: [ElemL]
    /// \rparam rhsE type: [ElemR]
    /// \param lhs type: [box<ElemL>] | qualifiers: {const, ref}
    /// \param rhs type: [box<ElemR>] | qualifiers: {const, ref}
    /// \returns true
    /// \returns false
    template <typename ElemL, typename ElemR>
#if __cpluscplus >= 202002L
        requires requires(ElemL lhsE, ElemR rhsE)
    {
        {
            lhsE == rhsE
            } -> std::convertible_to<bool>;
    }
    constexpr inline bool
    operator== (const box<ElemL>& lhs, const box<ElemR>& rhs) noexcept(
        noexcept(std::declval<ElemL>() == std::declval<ElemR>())
           & &noexcept(std::ranges::equal(lhs, rhs);))
#else
    inline bool
    operator== (const box<ElemL>& lhs, const box<ElemR>& rhs)
#endif
    {
        if (lhs.dimensions() != rhs.dimensions())
            return false;
        return std::ranges::equal(lhs, rhs);
    }

/// Current bug with GCC-11.1 with lexicographical_compare_three_way
/// causes cxl::box to not compile. Issue: PR
/// Current bug with Clang++-12 with lexicographical_compare_three_way
/// cause cxl::box to be compared on box size over value precidence
#if __cpp_lib_three_way_comparison && !(lexicographical_compare_bug)

    /// \brief Spaceship Operator for matrices.
    ///
    /// \group box
    ///
    /// \details Uses std::lexicographical_compare_three_way to
    /// compare the matrices and generates the !=, <, >, <=, >=
    /// operators.
    ///
    /// \tparam ElemL
    /// \tparam ElemR
    /// \param lhs type: [box<ElemL>] | qualifiers: {const, ref}
    /// \param lhs type: [box<ElemL>] | qualifiers: {const, ref}
    /// \returns constexpr inline auto
    template <typename ElemL, typename ElemR>
    constexpr inline auto
    operator<=> (const box<ElemL>& lhs, const box<ElemR>& rhs)
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
    /// \tparam ElemL
    /// \tparam ElemR
    /// \param lhs type: [box<ElemL>] | qualifiers: {const, ref}
    /// \param rhs type: [box<ElemR>] | qualifiers: {const, ref}
    /// \returns true
    /// \returns false
    template <typename ElemL, typename ElemR>
    inline bool
    operator!= (const box<ElemL>& lhs, const box<ElemR>& rhs)
    {
        return !(lhs == rhs);
    }

    /// \brief Compares if a box is lexicographically
    /// less than another.
    ///
    /// \group box
    ///
    /// \tparam ElemL
    /// \tparam ElemR
    /// \param lhs type: [box<ElemL>] | qualifiers: {const, ref}
    /// \param rhs type: [box<ElemR>] | qualifiers: {const, ref}
    /// \returns true
    /// \returns false
    template <typename ElemL, typename ElemR>
    inline bool
    operator< (const box<ElemL>& lhs, const box<ElemR>& rhs)
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
    /// \tparam ElemL
    /// \tparam ElemR
    /// \param lhs type: [box<ElemL>] | qualifiers: {const, ref}
    /// \param rhs type: [box<ElemR>] | qualifiers: {const, ref}
    /// \returns true
    /// \returns false
    template <typename ElemL, typename ElemR>
    inline bool
    operator> (const box<ElemL>& lhs, const box<ElemR>& rhs)
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
    /// \tparam ElemL
    /// \tparam ElemR
    /// \param lhs type: [box<ElemL>] | qualifiers: {const, ref}
    /// \param rhs type: [box<ElemR>] | qualifiers: {const, ref}
    /// \returns true
    /// \returns false
    template <typename ElemL, typename ElemR>
    inline bool
    operator<= (const box<ElemL>& lhs, const box<ElemR>& rhs)
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
    /// \tparam ElemL
    /// \tparam ElemR
    /// \param lhs type: [box<ElemL>] | qualifiers: {const, ref}
    /// \param rhs type: [box<ElemR>] | qualifiers: {const, ref}
    /// \returns true
    /// \returns false
    template <typename ElemL, typename ElemR>
    inline bool
    operator>= (const box<ElemL>& lhs, const box<ElemR>& rhs)
    {
        return !(lhs < rhs);
    }

#endif // three way compare


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
    template<typename E, std::copy_constructible F>
    constexpr auto
    operator|| (const box<E>& bx, F f)
    { return bx.map(f); }

} // namespace cxl



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
    /// \param x type: [cxl::box<T>] | qualifiers: {const, ref}
    /// \param y type: [cxl::box<T>] | qualifiers: {const, ref}
    /// \returns inline void
    template <typename T>
    inline void swap(cxl::box<T>& x, cxl::box<T>& y) noexcept
    { x.swap(y); }
}

#endif // __cplusplus >= 201703L

#endif // CORTEX_BOX_H