// -*- C++ -*- Header compatibility <matrix.hxx>

/// \brief Two dimensional array data structure.
///
/// Author: Tyler Swann (tyler.swann05@gmail.com)
/// 
/// Header Version: v0.2.0
///
/// Date: 12-03-2023
///
/// License: MIT
///
/// Copyright: Copyright (c) 2022-2023
/// \file matrix.hxx

#ifndef CORTEX_MATRIX
#   define CORTEX_MATRIX

#include <iterators/normal.hxx>

#include <algorithm>
#include <compare>
#include <functional>
#include <initializer_list>
#include <memory>
#include <utility>
#include <vector>

namespace cxl
{
    /// \brief matrix - Two Dimensional Array
    ///
    /// \details A two dimensional, owning generic
    /// array. Support slicing, array based operations and
    /// multidimensional iteration and point based index.  
    /// Elements are stored continuously in memory and are 
    /// layed out in a row-wise fashion.
    /// 
    /// \tparam T
    /// \tparam Alloc default: std::allocator<T>
    template <typename T, typename Alloc = std::allocator<T>>
    class matrix
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
        using const_pointer                         = typename alloc_traits::const_pointer;

        using iterator                              = cxl::normal_iterator<pointer, matrix>;
        using const_iterator                        = cxl::normal_iterator<const_pointer, matrix>;
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
        /// \details Default constructor for matrix.
        constexpr
        matrix() noexcept
            : m_num_rows{ size_type{} }
            , m_num_columns{ size_type{} }
            , m_allocator{ allocator_type{} }
            , m_start{ pointer{} }
            , m_finish{ pointer{} }
        { }

        /// \brief Allocator Constructor
        ///
        /// \details Default Constructs a matrix with a
        /// given allocator.
        ///
        /// \param alloc type: const allocator_type&
        explicit constexpr 
        matrix(const allocator_type& alloc) noexcept
            : m_num_rows{ size_type{} }
            , m_num_columns{ size_type{} }
            , m_allocator{ alloc }
            , m_start{ pointer{} }
            , m_finish{ pointer{} }
        { }

        /// \brief Default Size Constructor
        ///
        /// \details Constructs a matrix with dimensions of
        /// num_rows x num_columns. Values are default constructed 
        /// or fill constructed depending on the default 
        /// contractibility qualification.
        ///
        /// \param num_columns type: size_type
        /// \param num_rows type: size_type
        /// \param alloc type: const allocator_type&
        explicit constexpr 
        matrix(size_type num_rows, size_type num_columns, const allocator_type& alloc = allocator_type{})
            : m_num_rows{ num_rows }
            , m_num_columns{ num_columns }
            , m_allocator{ alloc }
            , m_start{ _M_allocate(_M_size_check(num_rows, num_columns)) }
            , m_finish{ m_start + size() }
        {
            if constexpr (std::is_default_constructible_v<value_type>)
                std::ranges::uninitialized_default_construct(*this);
            else
                std::ranges::uninitialized_fill(*this, value_type{});
        }

        /// \brief Explicit Value and Size Constructor
        ///
        /// \details Constructs a matrix with dimensions of
        /// num_rows x num_columns. Values are constructed from 
        /// the a constant reference to a provided fill_value.
        ///
        /// \param num_columns type: size_type
        /// \param num_rows type: size_type
        /// \param fill_value type: value_type
        /// \param alloc type: const allocator_type&
        explicit constexpr 
        matrix(size_type num_rows, size_type num_columns, const_reference fill_value, const allocator_type& alloc = allocator_type())
            : m_num_rows{ num_rows }
            , m_num_columns{ num_columns }
            , m_allocator{ alloc }
            , m_start{ _M_allocate(_M_size_check(num_rows, num_columns)) }
            , m_finish{ m_start + size() }
        { std::ranges::uninitialized_fill(*this, fill_value); }

        /// \brief Copy Constructor
        ///
        /// \details Constructs a matrix that is a copy of
        /// another matrix of the same underlying type.
        ///
        /// \param other type: const matrix&
        constexpr
        matrix(const matrix& other)
            : m_num_rows{ other.m_num_rows }
            , m_num_columns{ other.m_num_columns}
            , m_allocator{ other.m_allocator }
            , m_start{ _M_allocate(_M_size_check(m_num_rows, m_num_columns)) }
            , m_finish{ m_start + size() }
        { std::ranges::uninitialized_copy(other, *this); }

        /// \brief Copy Constructor with Alternative Allocator
        ///
        /// \details Constructs a matrix that is a copy of
        /// another matrix of the same underlying type.
        ///
        /// \param other type: const matrix&
        /// \param alloc type: const allocator_type&
        explicit constexpr
        matrix(const matrix& other, const allocator_type& alloc)
            : m_num_rows{ other.m_num_rows }
            , m_num_columns{ other.m_num_columns }
            , m_allocator{ alloc }
            , m_start{ _M_allocate(_M_size_check(num_rows, num_columns)) }
            , m_finish{ m_start + size() }
        { std::ranges::uninitialized_copy(other, *this); }

        /// \brief Move Constructor
        ///
        /// \details Moves ownership of an existing Boxes
        /// resources to this matrix and leaves the other matrix
        /// in a default constructed state.
        ///
        /// \param other type: matrix&&
        constexpr
        matrix(matrix&& other) noexcept
            : m_num_rows{ other.m_num_rows }
            , m_num_columns{ other.m_num_columns }
            , m_allocator{ std::move(other.m_allocator) }
            , m_start{ other.m_start }
            , m_finish{ other.m_finish }
        {
            other.m_start = pointer{};
            other.m_finish = pointer{};
            other.m_allocator = allocator_type{};
            other.m_num_rows = size_type{};
            other.m_num_columns = size_type{};
        }

        /// \brief Move Constructor with Alternative Allocator
        ///
        /// \details Moves ownership of an existing Boxes
        /// resources to this matrix and leaves the other matrix
        /// in a default constructed state. Uses an alternative
        /// allocator for construction of `this` matrix.
        ///
        /// \param other type: matrix&&
        /// \param alloc type: const allocator_type&
        explicit constexpr 
        matrix(matrix&& other, const allocator_type& alloc) noexcept
            : m_num_rows{ other.m_num_rows }
            , m_num_columns{ other.m_num_columns }
            , m_allocator{ alloc }
            , m_start{ other.m_start }
            , m_finish{ other.m_finish }
        {
            other.m_start = pointer{};
            other.m_finish = pointer{};
            other.m_allocator = allocator_type{};
            other.m_num_rows = size_type{};
            other.m_num_columns = size_type{};
            other.m_size = size_type{};
        }

        /// \brief Initialiser List Constructor
        ///
        /// \details Uses std::initializer_list to create a matrix
        /// from an initializer list of initializer lists. Elements
        /// ownership is moved to the Boxes memory.
        ///
        /// \exception std::invalid_argument
        ///
        /// \param list type: std::initializer_list<std::initializer_list<value_type>>
        /// \param alloc type: [[maybe_unused]] const allocator_type&
        constexpr 
        matrix(std::initializer_list<std::initializer_list<value_type>> list, [[maybe_unused]] const allocator_type& alloc = allocator_type{})
            : m_num_rows{ list.size() }
            , m_num_columns{ list.begin()->size() }
            , m_allocator{ alloc }
            , m_start{ _M_allocate(_M_size_check(m_num_rows, m_num_columns)) }
            , m_finish{ m_start + size() }
        {
            auto offset{ 0uL };
            for (auto row{ list.begin() }; row != list.end(); ++row)
            {
                if (row->size() != this->m_num_columns)
                    throw std::invalid_argument("The size of the inner std::initializer_list must be same size as the number of columns in the matrix");

                std::uninitialized_move_n(row->begin(), this->m_num_columns, m_start + offset);
                offset += this->m_num_columns;
            }
        }

        /// \brief Dimension Constructor
        ///
        /// \details Constructs a matrix from the dimensions 
        /// of another. The matrix is default constructed. Takes
        /// the result of a call to `matrix::dimension()`.
        ///
        /// \param dimensions type: const std::tuple<size_type, size_type>&
        /// \param alloc type: [[maybe_unused]] const allocator_type&
        explicit constexpr 
        matrix(const std::tuple<size_type, size_type>& dimensions, [[maybe_unused]] const allocator_type& alloc = allocator_type{})
            : m_num_rows{ std::get<0>(dimensions) }
            , m_num_columns{ std::get<1>(dimensions) }
            , m_allocator{ alloc }
            , m_start{ _M_allocate(_M_size_check(m_num_rows, m_num_columns)) }
            , m_finish{ m_start + size() }
        { 
            if constexpr (std::is_default_constructible_v<value_type>)
                std::ranges::uninitialized_default_construct(*this);
            else
                std::ranges::uninitialized_fill(*this, value_type{});
        }

        /// \brief Copy Assignment
        ///
        /// \details Copies the contents of another matrix into
        /// this matrix and returns///this. If self assignment occurs
        /// then///this is returned immediately.
        ///
        /// \param other type: const matrix&
        /// \returns constexpr matrix&
        constexpr auto
        operator= (const matrix& other) 
            -> matrix&
        {
            if (*this != other)
            {
                std::ranges::destroy(*this);
                _M_deallocate(m_start, size());

                m_num_rows = other.m_num_rows;
                m_num_columns = other.m_num_columns;
                m_allocator = other.m_allocator;
                m_start = _M_allocate(_M_size_check(m_num_rows, m_num_columns));
                m_finish = m_start + size();
                std::ranges::uninitialized_copy(other, *this);
            }
            return *this;
        }

        /// \brief Move Assignment
        ///
        /// \details Moves the ownership of other's resources to
        /// this matrix and leaves the other matrix in a default
        /// constructed state. Returns///this. If self assignment
        /// occurs then///this is returned immediately.
        ///
        /// \param other type: matrix&&
        /// \returns constexpr matrix&
        constexpr auto
        operator= (matrix&& other) noexcept 
            -> matrix&
        {
            if (*this != other)
            {
                std::ranges::destroy(*this);
                _M_deallocate(m_start, size());

                m_num_rows = other.m_num_rows;
                m_num_columns = other.m_num_columns;
                m_allocator = std::move(other.m_allocator);
                m_start = other.m_start;
                m_finish = other.m_finish;

                other.m_start = pointer{};
                other.m_finish = pointer{};
                other.m_allocator = allocator_type{};
                other.m_num_rows = size_type{};
                other.m_num_columns = size_type{};
            }
            return *this;
        }

        /// \brief Initialiser List Assignment
        ///
        /// \details Uses std::initializer_list to create a matrix
        /// from an initializer list of initializer lists. Elements
        /// ownership is moved to the Boxes memory.
        ///
        /// \exception std::invalid_argument
        ///
        /// \param list type: [std::initializer_list<std::initializer_list<value_type>>]
        /// \returns constexpr matrix&
        constexpr auto
        operator= (std::initializer_list<std::initializer_list<value_type>> list) 
            -> matrix&
        {
            std::ranges::destroy(*this);
            _M_deallocate(m_start, size());

            m_allocator = allocator_type{};
            m_num_rows = list.size();
            m_num_columns = list.begin()->size();
            m_start = _M_allocate(_M_size_check(m_num_rows, m_num_columns));
            m_finish = m_start + size();

            auto offset{ 0uL };
            for (auto row{ list.begin() }; row != list.end(); ++row)
            {
                if (row->size() != this->m_num_columns)
                    throw std::invalid_argument("The size of the inner std::initializer_list must be same size as the number of columns in the matrix");

                std::uninitialized_move_n(row->begin(), this->m_num_columns, m_start + offset);
                offset += this->m_num_columns;
            }

            return *this;
        }

        /// \brief Destructor
        ///
        /// \details Releases the resources of this matrix
        /// and leaves the matrix in an uninitialized state.
#if __cplusplus >= 202202L
        constexpr
#else
        ~matrix()
#endif
        {
            if (m_start)
            {
                std::ranges::destroy(*this);
                _M_deallocate(m_start, size());
            }

            m_num_rows = size_type{};
            m_num_columns = size_type{};
            m_start = pointer{};
            m_finish = pointer{};
            m_allocator = allocator_type{};
        }

        /// \brief Initialiser List Assign
        ///
        /// \details Uses std::initializer_list to reassign 
        /// values to a matrix. If the lists dimensions are not
        /// the same as the Boxes dimensions, then the matrix
        /// is resized to match the dimensions of the list.
        ///
        /// \exception std::invalid_argument
        /// 
        /// \param list type: std::initializer_list<std::initializer_list<value_type>>
        constexpr auto
        assign(std::initializer_list<std::initializer_list<value_type>> list) 
            -> void
        {
            auto new_rows { list.size() };
            auto new_columns { list.begin()->size() };

            std::ranges::destroy(*this);

            if (new_rows != m_num_rows || new_columns != m_num_columns)
            {
                if (m_start)
                    _M_deallocate(m_start, size());
            
                m_start = _M_allocate(_M_size_check(new_rows, new_columns));
                m_finish = m_start + _M_size_check(new_rows, new_columns);
            }
            
            m_num_rows = new_rows;
            m_num_columns = new_columns;

            auto offset{ 0uL };
            for (auto row{ list.begin() }; row != list.end(); ++row)
            {
                if (row->size() != this->m_num_columns)
                    throw std::invalid_argument("The size of the inner std::initializer_list must be same size as the number of columns in the matrix");

                std::uninitialized_move_n(row->begin(), this->m_num_columns, m_start + offset);
                offset += this->m_num_columns;
            }
        }

        /// \brief Resizes the matrix memory.
        ///
        /// \details 
        ///
        /// \param new_rows type: size_type
        /// \param new_columns type: size_type
        constexpr auto 
        resize(size_type new_rows, size_type new_columns) 
            -> void
        { resize(new_rows, new_columns, value_type{}); }

        /// \brief Resizes Boxes memory
        ///
        /// \details Resizes the matrix to a new shape of new_rows x new_columns.
        /// Resizing will cause reallocation to a new memory block if the new 
        /// shape is larger or smaller than the current shape. For larger shape, 
        /// previous values are copied to the new sequential memory location 
        /// which will reshuffle the data's layout. New memory is given the 
        /// value of fill_value. A smaller resize shape will result in elements 
        /// past the new shape's sequential extent to be destroyed and deallocated.
        /// If the overall memory size remains the same, the data is only reshaped.
        ///
        /// \exception std::length_error
        ///
        /// \param new_rows type: size_type
        /// \param new_columns type: size_type
        /// \param fill_value type: const_reference
        constexpr auto 
        resize(size_type new_rows, size_type new_columns, const_reference fill_value) 
            -> void
        {
            auto old_size{ size() };
            auto new_size{ _M_size_check(new_rows, new_columns) };

            auto new_start{ _M_allocate(new_size) };
            auto new_finish{ new_start + new_size };


            if (new_size > alloc_traits::max_size(m_allocator))
                throw std::length_error("matrix resize too large");
            else
                if (old_size < new_size)
                {
                    if (auto old_finish_pos_in_new{ new_start + old_size }; m_start)
                    {
                        std::ranges::uninitialized_copy(m_start, m_finish, new_start, old_finish_pos_in_new);
                        std::ranges::uninitialized_fill(old_finish_pos_in_new, new_finish, fill_value);
                    }
                    else
                        std::ranges::uninitialized_fill(new_start, new_finish, fill_value);
                }
                else if (old_size > new_size)
                {
                    if (auto size_diff { old_size - new_size }; m_start)
                        std::ranges::uninitialized_copy(m_start, m_finish - size_diff, new_start, new_finish);
                    else
                        std::ranges::uninitialized_fill(new_start, new_finish, fill_value);
                }

            std::ranges::destroy(*this);
            _M_deallocate(m_start, old_size);
    
            m_start = new_start;
            m_finish = new_finish;

            m_num_rows = new_rows;
            m_num_columns = new_columns;
        }

        /// \brief Erases element indicated by position
        ///
        /// \details Erases the value of the matrix at position
        /// and resets it to value_type.
        ///
        /// \param position type: const_iterator
        /// \returns [[maybe_unused]] constexpr iterator
        [[maybe_unused]] constexpr auto 
        erase(const_iterator position) 
            -> iterator
        {
            auto pos { this->begin() + (position - this->cbegin()) };
            std::ranges::destroy_at(std::addressof(*pos));
            std::ranges::uninitialized_fill(pos, pos + 1, value_type{});

            return position;
        }

        /// \brief Erases elements between first and last
        ///
        /// \details Erases elements between first and last and then
        /// resets memory to value_type.
        ///
        /// \param first type: const_iterator
        /// \param last type: const_iterator
        /// \returns [[maybe_unused]] constexpr iterator
        [[maybe_unused]] constexpr auto
        erase(const_iterator first, const_iterator last) 
            -> iterator
        {
            const auto bgn { this->begin() };
            const auto cbgn { this->cbegin() };

            auto fst { bgn + (first - cbgn) };
            auto lst { bgn + (last - cbgn) };

            std::ranges::destroy(fst, lst);
            return std::ranges::uninitialized_fill(fst, lst, value_type{});
        }

        /// \brief Clears the matrix elements
        ///
        /// \details The elements of the matrix are destroyed and
        /// the memory is deallocated entirely. The matrix is however,
        /// left in a state where it could be re-initialised through 
        /// matrix::resize or reassignment.
        constexpr auto
        clear() 
            -> void
        {
            if (size())
            {
                erase(begin(), end());

                _M_deallocate(m_start, size());
                m_num_rows = size_type{};
                m_num_columns = size_type{};
                m_finish = pointer{};
                m_start = pointer{};
            }
        }

        /// \brief Reshape current matrix elements to new dimensions
        ///
        /// \details Reshapes the current Boxes dimensions while
        /// guaranteeing that no reallocation occurs. Elements are
        /// preserved but reordered.
        ///
        /// \exception std::length_error
        ///
        /// \param new_rows type: size_type
        /// \param new_columns type: size_type
        constexpr auto 
        reshape(size_type new_rows, size_type new_columns) 
            -> void
        {
            auto new_size{ _M_size_check(new_rows, new_columns) };

            if (new_size != size())
                throw std::length_error("Cannot reshape matrix that has different total size");
            else
                resize(new_rows, new_columns);
        }

        /// \brief Swaps two Boxes of the same type.
        ///
        /// \details Swaps the contents of two Boxes 
        /// with the same underlying value and allocator
        /// types. The swap is performed by moving ownership
        /// of the matrices resources.
        ///
        /// \param other type: matrix&
        void swap(matrix& other) noexcept
        {
            matrix tmp = std::move(other);
            other = std::move(*this);
            *this = std::move(tmp);
        }

        /// \brief Get Allocator
        ///
        /// \details Returns the allocator used by the matrix.
        ///
        /// \returns constexpr allocator_type
        constexpr auto 
        get_allocator() const noexcept 
            -> allocator_type
        { return m_allocator; }

        /// \brief matrix Size
        /// 
        /// \details Returns the overall size of the matrix.
        ///
        /// \returns constexpr size_type
        constexpr auto
        size() const noexcept
            -> size_type
        { 
            return empty() ? size_type{ 0 } 
                           : m_num_rows * m_num_columns != 0uL 
                           ? m_num_rows * m_num_columns 
                           : std::max(m_num_rows, m_num_columns);
        }

        /// \brief Number of rows 
        /// 
        /// \details Returns the number of rows of the matrix.
        ///
        /// \returns constexpr size_type
        constexpr auto
        num_rows() const noexcept 
            -> size_type
        { return m_num_rows; }

        /// \brief Number of Columns
        /// 
        /// \details Returns the number of columns of the matrix.
        ///
        /// \returns constexpr size_type
        constexpr auto
        num_columns() const noexcept 
            -> size_type
        { return m_num_columns; }

        /// \brief Max matrix Size
        /// 
        /// \details Returns the maximum number of elements that
        /// can be stored in the matrix per the allocator.
        ///
        /// \returns constexpr size_type
        constexpr auto
        max_size() const noexcept 
            -> size_type
        { return alloc_traits::max_size(m_allocator); }

        /// \brief Dimensions
        /// 
        /// \details Returns a tuple of the Boxes shape.
        ///
        /// \returns constexpr std::tuple<size_type, size_type>
        constexpr auto 
        shape() const noexcept 
            -> std::tuple<size_type, size_type>
        { return std::make_tuple(m_num_rows, m_num_columns); }

        /// \brief Is Square Predicate
        ///
        /// \details If the number of rows and columns 
        /// are equal, the matrix is square.
        ///
        /// \returns constexpr bool
        constexpr auto
        is_square() const noexcept 
            -> bool
        { return m_num_rows == m_num_columns; }

        /// \brief Empty
        ///
        /// \details Checks whether the matrix is empty.
        ///
        /// \returns constexpr bool
        constexpr auto
        empty() const noexcept 
            -> bool
        { return m_start == m_finish; }

        /// \brief Data
        ///
        /// \details Returns the underlying data pointer.
        ///
        /// \returns pointer
        constexpr auto
        data() noexcept 
            -> pointer
        { return _M_data_ptr(m_start); }

        /// \brief Data
        /// 
        /// \details Returns the underlying data pointer.
        ///
        /// \returns const_pointer
        constexpr auto
        data() const noexcept 
            -> const_pointer 
        { return _M_data_ptr(m_start); }

        /// \brief Point based element access
        ///
        /// \details Returns a reference to the element that
        /// is at the point position (column, row) of the
        /// matrix.
        ///
        /// \param column type: size_type
        /// \param row type: size_type
        /// \returns constexpr reference
        constexpr auto
        at(size_type row, size_type column) 
            -> reference
        {
            _M_range_check(row, column);
            return *(m_start + _M_index(row, column));
        }

        /// \brief Point based element access
        ///
        /// \details Returns a reference to the element that
        /// is at the point position (column, row) of the
        /// matrix.
        ///
        /// \param column type: size_type
        /// \param row type: size_type
        /// \returns constexpr const_reference
        constexpr auto
        at(size_type row, size_type column) const 
            -> const_reference
        {
            _M_range_check(row, column);
            return *(m_start + _M_index(row, column));
        }

        /// \brief Point based element access operator
        ///
        /// \details Provides point access to Boxes elements.
        /// Overloads the invocation operator. Utilises the at() method.
        ///
        /// \param column type: size_type
        /// \param row type: size_type
        /// \returns constexpr reference
        constexpr auto
        operator() (size_type row, size_type column) 
            -> reference
        { return at(row, column); }

        /// \brief Point based element access operator
        ///
        /// \details Provides point access to Boxes elements.
        /// Overloads the invocation operator. Utilises the at() method.
        ///
        /// \param column type: size_type
        /// \param row type: size_type
        /// \returns constexpr const_reference
        constexpr auto
        operator() (size_type row, size_type column) const 
            -> const_reference 
        { return at(row, column); }

        /// \brief Front
        /// 
        /// \details Returns a reference to the front element
        /// of the matrix.
        ///
        /// \returns constexpr reference
        constexpr auto
        front() noexcept 
            -> reference
        { return *begin(); }

        /// \brief Front
        ///
        /// \details Returns a reference to the front element
        /// of the matrix.
        ///
        /// \returns constexpr const_reference
        constexpr auto
        front() const noexcept 
            -> const_reference
        { return *begin(); }

        /// \brief Back
        ///
        /// \details Returns a reference to the back element
        /// of the matrix.
        ///
        /// \returns constexpr reference
        constexpr auto
        back() noexcept 
            -> reference
        { return *(end() - 1); }

        /// \brief Back
        /// 
        /// \details Returns a reference to the back element
        /// of the matrix.
        ///
        /// \returns constexpr const_reference
        constexpr auto
        back() const noexcept 
            -> const_reference
        { return *(end() - 1); }

        /// \brief Begin Iterator
        /// 
        /// \details Iterator to the beginning of 
        /// the Boxes data.
        ///
        /// \returns constexpr iterator
        constexpr auto
        begin() noexcept 
            -> iterator
        { return iterator(m_start); }

        /// \brief Begin Iterator (const)
        /// 
        /// \details Constant iterator to the beginning 
        /// of the Boxes data.
        ///
        /// \returns constexpr const_iterator
        constexpr auto
        begin() const noexcept 
            -> const_iterator
        { return const_iterator(m_start); }

        /// \brief Constant Begin Iterator
        /// 
        /// \details Constant iterator to the beginning 
        /// of the matrix.
        ///
        /// \returns constexpr const_iterator
        constexpr auto 
        cbegin() const noexcept 
            -> const_iterator
        { return const_iterator(m_start); }

        /// \brief Reverse Begin Iterator
        /// 
        /// \details Iterator to the reversed beginning
        /// of the Boxes data.
        ///
        /// \returns constexpr reverse_iterator
        constexpr auto
        rbegin() noexcept 
            -> reverse_iterator
        { return reverse_iterator(end()); }

        /// \brief Reverse Begin Iterator (const)
        /// 
        /// \details Constant iterator to the reversed 
        /// beginning of the Boxes data.
        ///
        /// \returns constexpr const_reverse_iterator
        constexpr auto
        rbegin() const noexcept 
            -> const_reverse_iterator
        { return const_reverse_iterator(end()); }

        /// \brief Constant Reverse Begin Iterator
        ///
        /// \details Constant iterator to the reversed
        /// beginning of the Boxes data.
        ///
        /// \returns constexpr const_reverse_iterator
        constexpr auto
        crbegin() const noexcept 
            -> const_reverse_iterator
        { return const_reverse_iterator(end()); }

        /// \brief End Iterator
        ///
        /// \details Iterator to the end of the 
        /// Boxes data.
        ///
        /// \returns constexpr iterator
        constexpr auto
        end() noexcept 
            -> iterator
        { return iterator(m_finish); }

        /// \brief End Iterator (const)
        /// 
        /// \details Constant iterator to the 
        /// end of the Boxes data.
        ///
        /// \returns constexpr const_iterator
        constexpr auto
        end() const noexcept 
            -> const_iterator
        { return const_iterator(m_finish); }

        /// \brief Constant End Iterator
        ///
        /// \details Constant iterator to the
        /// end of the Boxes data.
        ///
        /// \returns constexpr const_iterator
        constexpr auto
        cend() const noexcept 
            -> const_iterator
        { return const_iterator(m_finish); }

        /// \brief Reverse End Iterator
        ///
        /// \details Iterator to the reversed end
        /// of the Boxes data.
        ///
        /// \returns constexpr reverse_iterator
        constexpr auto
        rend() noexcept 
            -> reverse_iterator
        { return reverse_iterator(begin()); }

        /// \brief Reverse End Iterator (const)
        ///
        /// \details Constant iterator to the reversed
        /// end of the Boxes data.
        ///
        /// \returns constexpr const_reverse_iterator
        constexpr auto
        rend() const noexcept 
            -> const_reverse_iterator
        { return const_reverse_iterator(begin()); }

        /// \brief Constant Reverse End Iterator
        ///
        /// \details Constant iterator to the reversed
        /// end of the Boxes data.
        ///
        /// \returns constexpr const_reverse_iterator
        constexpr auto 
        crend() const noexcept 
            -> const_reverse_iterator
        { return const_reverse_iterator(begin()); }

        /// \brief matrix Transpose
        ///
        /// \details Performs a matrix transpose.
        /// Uses std::copy over std::ranges::copy as the output
        /// iterator is required to be std::constructible_v which
        /// column_iterator doesn't satisfy yet.
        ///
        /// \returns constexpr auto
        // constexpr auto 
        // transpose()
        // {
        //     matrix<value_type> result(this->num_columns(), this->num_rows());

        //     if (empty())
        //         return result;

        //     std::ranges::copy(*this, result.column_begin());

        //     return result;
        // }

        /// \brief matrix map
        ///
        /// \details Maps a function over the matrix, returning 
        /// the mapped matrix.
        /// 
        /// \tparam F concept: std::copy_constructible
        /// \param func type: F 
        /// \returns constexpr matrix<std::invoke_result_t<F, value_type>> 
        template<std::copy_constructible F>
        constexpr auto
        map(F func) const 
            -> matrix<std::invoke_result_t<F, value_type>>
        {
            if (empty())
                return matrix<std::invoke_result_t<F, value_type>>{};
            else
            {
                matrix<std::invoke_result_t<F, value_type>> result(this->num_rows(), this->num_columns());
                std::ranges::transform(*this, result.begin(), func);
                return result;
            }
        }

        /// \brief matrix map with range 
        ///
        /// \details Maps a function over the matrix and another 
        /// range object, returning the mapped matrix. Returns an 
        /// empty matrix if `this` is empty.
        /// 
        /// \tparam Rng concept: std::ranges::input_range
        /// \tparam F concept: std::copy_constructible
        /// \param rng type Rng&&
        /// \param func type F
        /// \returns constexpr matrix<std::invoke_result_t<F, value_type, typename std::remove_cvref_t<decltype(*std::ranges::begin(rng))>>
        template<std::ranges::input_range Rng, std::copy_constructible F>
        constexpr auto
        map(Rng&& rng, F func) const 
            -> matrix<std::invoke_result_t<F, value_type, typename std::remove_cvref_t<decltype(*std::ranges::begin(rng))>>>
        {
            using range_elem_t = typename std::remove_cvref_t<decltype(*std::ranges::begin(rng))>;

            if (empty())
                return matrix<std::invoke_result_t<F, value_type, range_elem_t>>{};
            else
            {
                matrix<std::invoke_result_t<F, value_type, range_elem_t>> result(this->num_rows(), this->num_columns());
                std::ranges::transform(*this, rng, result.begin(), func);
                return result;
            }
        }

        /// \brief Map - Iterator Pair
        ///
        /// \details Maps a function over the matrix and a range
        /// denoted by an iterator pair, returning the mapped 
        /// matrix. Returns an empty matrix if `this` is empty.
        /// 
        /// \tparam It concept: std::input_iterator
        /// \tparam Sn concept: std::sentinel_for<It>
        /// \tparam F concept: std::copy_constructible
        /// \param first type: It 
        /// \param last type Sn
        /// \param func type: Fn
        /// \returns constexpr matrix<std::invoke_result_t<F, value_type, typename std::remove_cvref_t<typename std::iterator_traits<It>::value_type>>>
        template<std::input_iterator It, std::sentinel_for<It> Sn, std::copy_constructible Fn>
        constexpr auto
        map(It first, Sn last, Fn func) const 
            -> matrix<std::invoke_result_t<Fn, value_type, typename std::remove_cvref_t<typename std::iterator_traits<It>::value_type>>>
        {
            using iterator_elem_t = typename std::remove_cvref_t<typename std::iterator_traits<It>::value_type>;

            if (empty())
                return matrix<std::invoke_result_t<Fn, value_type, iterator_elem_t>>{};
            else
            {
                matrix<std::invoke_result_t<Fn, value_type, iterator_elem_t>> result(this->num_rows(), this->num_columns());
                std::ranges::transform(this->begin(), this->end(), first, last, result.begin(), func);
                return result;
            }
        }

        /// \brief Vertical Flip
        ///
        /// \details Performs a vertical flip of the matrix.
        /// ie. The order of the num_rows is reversed. If 
        /// `this` matrix is empty, an empty matrix is returned
        /// with no memory allocated to it.
        /// 
        /// \returns constexpr auto 
        // constexpr auto vflip() const
        // {
        //     if (empty())
        //         return matrix<value_type>{};
        //     else
        //     {
        //         matrix<value_type> result(this->num_rows(), this->num_columns());

        //         for (auto cidx { 0u }; cidx < this->num_columns(); ++cidx)
        //             std::ranges::copy(this->column_begin(cidx), this->column_end(cidx), result.column_rbegin(cidx));

        //         return result;
        //     }
        // }

        /// \brief Horizontal Flip
        ///
        /// \details Performs a horizontal flip of the matrix.
        /// ie. The order of the num_columns is reversed. If 
        /// `this` matrix is empty, an empty matrix is returned
        /// with no memory allocated to it.
        /// 
        /// \returns constexpr auto 
        // constexpr auto hflip() const
        // {
        //     if (empty())
        //         return matrix<value_type>{};
        //     else
        //     {
        //         matrix<value_type> result(this->num_rows(), this->num_columns());
        //             for (auto ridx { 0u }; ridx < this->num_rows(); ++ridx)
        //                 std::ranges::copy(this->row_begin(ridx), this->row_end(ridx), result.row_rbegin(ridx));

        //         return result;
        //     }
        // }

        /// \brief Right Rotate
        ///
        /// Rotates the matrix 90 degrees clockwise. Inverts the 
        /// dimension sizes of the matrix. If `this` matrix is empty,
        /// an empty matrix is returned with no memory allocated to it.
        /// 
        /// \returns constexpr auto 
        // constexpr auto rrotate() const
        // {
        //     if (empty())
        //         return matrix<value_type>{};
        //     else
        //     {
        //         matrix<value_type> result(this->num_columns(), this->num_rows());

        //         for (auto cidx { 0u }; cidx < this->num_columns(); ++cidx)
        //             std::ranges::copy(this->column_begin(cidx), this->column_end(cidx), result.row_rbegin(cidx));

        //         return result;
        //     }
        // }

        /// \brief Left Rotate
        ///
        /// Rotates the matrix 90 degrees counter-clockwise. Inverts 
        /// the dimension sizes of the matrix. If `this` matrix is empty,
        /// an empty matrix is returned with no memory allocated to it.
        /// 
        /// \returns constexpr auto 
        // constexpr auto lrotate() const
        // {
        //     if (empty())
        //         return matrix<value_type>{};
        //     else
        //     {
        //         matrix<value_type> result(this->num_columns(), this->num_rows());

        //         for (auto ridx { 0u }; ridx < this->num_rows(); ++ridx)
        //             std::ranges::copy(this->row_begin(ridx), this->row_end(ridx), result.column_rbegin(ridx));

        //         return result;
        //     }
        // }

    private:
        /// \brief Allocates memory for matrix
        ///
        /// \details Allocates the memory for the matrix
        /// using the allocator of the container. Uses
        /// std::allocator_traits to get the allocators
        /// relevant methods.
        ///
        /// \param n type: size_type
        /// \returns constexpr pointer
        constexpr auto
        _M_allocate(size_type n) 
            -> pointer
        { return n != 0 ? alloc_traits::allocate(m_allocator, n) : pointer{}; }

        /// \brief Deallocates memory for matrix
        ///
        /// \details Deallocates the memory for the matrix
        /// using the allocator of the container. Uses
        /// std::allocator_traits to get the allocators
        /// relevant methods.
        ///
        /// \param ptr type: pointer
        /// \param n type: [[maybe_unused]] size_type
        constexpr auto
        _M_deallocate(pointer ptr, [[maybe_unused]] size_type n) 
            -> void
        {
            if (ptr)
                alloc_traits::deallocate(m_allocator, ptr, n);
        }

        /// \brief Checks index's are in the bounds of the matrix
        ///
        /// \details Checks if column and row are withing
        /// the Boxes bounds.
        ///
        /// \exception std::out_of_range
        ///
        /// \param column type: size_type
        /// \param row type: size_type
        constexpr auto
        _M_range_check(size_type row, size_type column) const 
            -> void
        {
            if (row >= m_num_rows || column >= m_num_columns)
                throw std::out_of_range("matrix::_M_range_check - index out of range.");
        }

        constexpr auto
        _M_size_check(size_type row, size_type column) const
            -> size_type
        { 
            if (row == 0uL)
                throw std::invalid_argument{ "BoxView::_M_size_check - row size cannot be zero" };
            else if (column == 0uL)
                throw std::invalid_argument{ "BoxView::_M_size_check - column size cannot be zero" };
            else
                return row * column;
        }

        constexpr auto
        _M_index(size_type row, size_type column) const noexcept 
            -> size_type
        { return row * m_num_columns + column; }

        /// \brief Returns the pointer passed to it.
        ///
        /// \tparam U
        /// \param ptr type: U*
        /// \returns U*
        template <typename U>
        constexpr auto
        _M_data_ptr(U* ptr) const noexcept 
            -> U*
        { return ptr; }

#if __cplusplus >= 201103L
        /// \brief Returns the pointer passed to it.
        ///
        /// \details If the fill_value given is not a builtin
        /// pointer type, a pointer is created from the
        /// underlying element type.
        ///
        /// \tparam Ptr
        /// \param ptr type: Ptr
        /// \returns typename std::pointer_traits<Ptr>::element_type*
        template <typename Ptr>
        constexpr auto
        _M_data_ptr(Ptr ptr) const 
            -> typename std::pointer_traits<Ptr>::element_type*
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
        constexpr auto
        _M_data_ptr(U* ptr) noexcept 
            -> U*
        { return ptr; }
#endif  //< __cplusplus >= 201103L
    
    };  //< class matrix

    /// \brief Compares two Boxes for equality.
    ///
    /// \details Uses std::equal to compare the Boxes.
    ///
    /// \tparam ElemL
    /// \tparam ElemR
    /// \rparam lhsE type: ElemL
    /// \rparam rhsE type: ElemR
    /// \param lhs type: const matrix<ElemL>&
    /// \param rhs type: const matrix<ElemR>&
    /// \returns constexpr inline bool
    template <typename ElemL, typename ElemR>
        requires requires(ElemL lhsE, ElemR rhsE) {
            { lhsE == rhsE } -> std::convertible_to<bool>;
        }
    constexpr inline auto
    operator== (const matrix<ElemL>& lhs, const matrix<ElemR>& rhs) noexcept(
        noexcept(std::declval<ElemL>() == std::declval<ElemR>())
           && noexcept(std::ranges::equal(lhs, rhs))) -> bool
    {
        if (lhs.shape() != rhs.shape())
            return false;
        return std::ranges::equal(lhs, rhs);
    }

    /// \brief Spaceship Operator for matrix
    ///
    /// \details Uses std::lexicographical_compare_three_way to
    /// compare the Boxes and generates the !=, <, >, <=, >=
    /// operators.
    ///
    /// \tparam ElemL
    /// \tparam ElemR
    /// \param lhs type: const matrix<ElemL>&
    /// \param lhs type: const matrix<ElemR>&
    /// \returns constexpr inline auto
    template <typename ElemL, typename ElemR>
    constexpr inline auto
    operator<=> (const matrix<ElemL>& lhs, const matrix<ElemR>& rhs)
    { return std::lexicographical_compare_three_way(lhs.begin(), lhs.end(), rhs.begin(), rhs.end(), std::compare_three_way{}); }

    /// \brief Map Operator
    ///
    /// \details Maps a function over the elements of a matrix
    /// and returns a new matrix with the mapped values. 
    /// 
    /// \tparam E
    /// \tparam F concept: std::copy_constructible
    /// \param bx type: const matrix<E>&
    /// \param f type: F
    /// \return constexpr auto 
    template<typename E, std::copy_constructible F>
    constexpr auto
    operator|| (const matrix<E>& bx, F f) noexcept
        -> matrix<std::invoke_result_t<F, E>>
    { return bx.map(f); }

}  //< namespace cxl

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
    /// \param x type: const cxl::matrix<T>&
    /// \param y type: const cxl::matrix<T>&
    template <typename T>
    constexpr inline auto
    swap(cxl::matrix<T>& x, cxl::matrix<T>& y) 
        noexcept( noexcept(x.swap(y)) ) -> void
    { x.swap(y); }
}

#endif  //< CORTEX_MATRIX_H