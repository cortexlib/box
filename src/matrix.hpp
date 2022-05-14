/// -*- C++ -*- Header compatibility <matrix.hpp>

/// @file matrix
/// @author Tyler Swann (oraqlle@github.com)
/// @brief Two dimensional array
/// @version 0.0.9
/// @date 2022-16-22
/// 
/// @copyright Copyright (c) 2022


#ifndef CORTEX_MATRIX_H
#   define CORTEX_MATRIX_H 1

#include <iterators/normal.hpp>
#include <concepts.hpp>

#if __cplusplus >= 202002L

#include <memory>
#include <utility>
#include <initializer_list>
#include <iostream>
#include <cassert>
#include <ranges>
#include <vector>
#include <execution>

#define lexicographical_compare_bug 1



namespace cortex
{
    /// @brief Matrix - Two Dimensional Array
    /// 
    /// @details Matrix is a two dimensional array that 
    /// stores elements sequentially in memory but is 
    /// viewed as a series of rows and columns. Matrix
    /// supports standard mathematical operations as long 
    /// as the underlying data type supports them. This is 
    /// checked at compile time through the use of concepts.
    /// 
    /// @todo Add support for iterators ✔️
    /// @todo Add support for range based for loops ✔️
    /// @todo Add support for basic arithmatic ✔️
    /// @todo Add support for matrix operations
    /// @todo Add support for operator overloads
    /// @todo Add support for std::allocator ✔️
    /// @todo Add support for std::initializer_list ✔️
    /// @todo Add support for std::swap ✔️
    /// @todo Add support for swaps of different matrix types ❌ (not possible)
    /// @todo Add support for flatten ✔️
    /// @todo Add support for assign
    /// @todo Add support for clear ✔️
    /// @todo Add support for resize ✔️
    /// @todo Add support for erase
    /// @todo Add support for reserve 🗑️ (scraped)
    /// @todo Add support for shrink_to_fit 🗑️ (scraped)
    /// @todo Add invokation operator support ✔️
    /// @todo Comparison operators between matrices ✔️
    /// @todo Comparison operators between scalars ✔️
    /// @todo Projection method
    /// @todo allocator constructors ✔️
    /// @todo use memory algorithms from ranges ✔️
    /// @todo using pointers to start and end over size ✔️
    /// @todo the reshape method
    /// 
    /// @tparam _Tp 
    template<typename _Tp, typename _Alloc = std::allocator<_Tp>>
    class matrix
    {
    public:
        using value_type                    = _Tp;
        using size_type                     = std::size_t;
        using difference_type               = std::ptrdiff_t;
        using allocator_type                = _Alloc;
        using alloc_traits                  = typename std::allocator_traits<_Alloc>;
        using reference                     = _Tp&;
        using const_reference               = const _Tp&;
        using pointer                       = typename alloc_traits::pointer;
        using const_pointer                 = typename alloc_traits::pointer;
        using iterator                      = cortex::normal_iterator<pointer, matrix<value_type>>;
        using const_iterator                = cortex::normal_iterator<const_pointer, matrix<value_type>>;
        using reverse_iterator              = std::reverse_iterator<iterator>;
        using const_reverse_iterator        = std::reverse_iterator<const_iterator>;


    protected: 
            size_type m_rows;
            size_type m_columns;

            allocator_type m_allocator;
            pointer m_start;
            pointer m_finish;

    public:

        /// @brief Default Constructor
        /// 
        /// @details Default constructor for matrix.
        constexpr matrix() noexcept
        : m_rows(size_type())
        , m_columns(size_type())
        , m_allocator(allocator_type())
        , m_start(pointer())
        , m_finish(pointer())
        { }

        
        /// @brief Allocator Constructor
        ///
        /// @details Default Constructs a matrix with a 
        /// given allocator. 
        ///
        /// @param alloc type: allocator_type | qualifiers: [const], [ref]
        constexpr explicit matrix(const allocator_type& alloc) noexcept
        : m_rows(size_type())
        , m_columns(size_type())
        , m_allocator(alloc)
        , m_start(pointer())
        , m_finish(pointer())
        { }


        /// @brief Size Constructor
        /// 
        /// @details Constructs a matrix with dimensions of 
        /// cols x rows. Values are default constructed or 
        /// fill constructed depending on the default constructiblity
        /// qualification.
        /// 
        /// @param cols type: [size_type]
        /// @param rows type: [size_type]
        /// @param alloc type: [allocator_type] | qualifiers: [const], [ref]
        constexpr explicit matrix(size_type rows, size_type cols, const allocator_type& alloc = allocator_type())
        : m_rows(rows)
        , m_columns(cols)
        , m_allocator(alloc)
        , m_start(_M_allocate(_M_size()))
        , m_finish(m_start + _M_size())
        { 
            if constexpr (std::is_default_constructible_v<value_type>)
                std::ranges::uninitialized_default_construct(*this);
            else
                std::ranges::uninitialized_fill(*this, value_type());
        }


        /// @brief Size + Value Constructor
        /// 
        /// @details Constructs a matrix with dimensions of
        /// cols x rows. Values are constructed from the a 
        /// const reference to a provided value.
        /// 
        /// @param cols type: [size_type]
        /// @param rows type: [size_type]
        /// @param value type: [value_type] | qualifiers: [const], [ref]
        /// @param alloc type: [allocator_type] | qualifiers: [const], [ref]
        constexpr matrix(size_type rows, size_type cols, const value_type& value, const allocator_type& alloc = allocator_type())
        : m_rows(rows)
        , m_columns(cols)
        , m_allocator(alloc)
        , m_start(_M_allocate(_M_size()))
        , m_finish(m_start + _M_size())
        { std::ranges::uninitialized_fill(*this, value); }


        /// @brief Copy Constructor
        /// 
        /// @details Constructs a matrix that is a copy of
        /// another matrix of the same underlying type.
        /// 
        /// @param other type: [matrix] | qualifiers: [const], [ref]
        constexpr matrix(const matrix& other)
        : m_rows(other.m_rows)
        , m_columns(other.m_columns)
        , m_allocator(other.m_allocator)
        , m_start(_M_allocate(_M_size()))
        , m_finish(m_start + _M_size())
        { std::ranges::uninitialized_copy(other, *this); }


        /// @brief Copy Constructor with Alternative Allocator
        /// 
        /// @details Constructs a matrix that is a copy of
        /// another matrix of the same underlying type.
        /// 
        /// @param other type: [matrix] | qualifiers: [const], [ref]
        /// @param alloc type: [allocator_type] | qualifiers: [const], [ref]
        constexpr matrix(const matrix& other, const allocator_type& alloc)
        : m_rows(other.m_rows)
        , m_columns(other.m_columns)
        , m_allocator(alloc)
        , m_start(_M_allocate(_M_size()))
        , m_finish(m_start + _M_size())
        { std::ranges::uninitialized_copy(other, *this); }


        /// @brief Move Constructor
        /// 
        /// @details Moves ownership of an existing matrix's
        /// resources to this matrix and leaves the other matrix
        /// in a default constructed state.
        /// 
        /// @param other type: [matrix] | qualifiers: [move]
        constexpr matrix(matrix&& other) noexcept
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


        /// @brief Move Constructor with Alternative Allocator
        /// 
        /// @details Moves ownership of an existing matrix's
        /// resources to this matrix and leaves the other matrix
        /// in a default constructed state.
        /// 
        /// @param other type: [matrix] | qualifiers: [move]
        /// @param alloc type: [allocator_type] | qualifiers: [const], [ref]
        constexpr matrix(matrix&& other, const allocator_type& alloc) noexcept
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


        /// @brief Initialiser List Constructor
        ///
        /// @details Uses std::initializer_list to create a matrix 
        /// from an initializer list of initializer lists. Elements 
        /// ownership is moved to the matrix's memory.
        ///
        /// @param init_list type: [std::initializer_list<std::initializer_list<value_type>>] | qualifiers: [const], [ref]
        constexpr matrix(std::initializer_list<std::initializer_list<value_type>> list
                        , const allocator_type& alloc = allocator_type())
        : m_rows(list.size())
        , m_columns(list.begin()->size())
        , m_allocator(alloc)
        , m_start(_M_allocate(_M_size()))
        , m_finish(m_start + _M_size())
        {
            using init_iter = typename decltype(list)::iterator;
            auto offset { 0UL };
            for (init_iter row { list.begin() }; row not_eq list.end(); ++row)
            {
                if (row->size() not_eq this->m_columns)
                    throw std::invalid_argument("Columns must be all the same size");
                std::uninitialized_move_n(row->begin(), this->m_columns, m_start + offset);
                offset += this->m_columns;
            }
        }


        /// @brief Copy Assignment
        /// 
        /// @details Copies the contents of another matrix into
        /// this matrix and returns///this. If self assignment occurs
        /// then///this is returned immediately.
        /// 
        /// @param other type: [matrix] | qualifiers: [const], [ref]
        /// @return constexpr matrix& 
        constexpr matrix& operator=(const matrix& other)
        {
            if (*this != other)
            {
                m_rows = other.m_rows;
                m_columns = other.m_columns;
                m_allocator = other.m_allocator;
                m_start = _M_allocate(_M_size());
                m_finish = m_start + _M_size();
                std::ranges::uninitialized_copy(other, *this);
            }
            return *this;
        }


        /// @brief Move Assignment
        /// 
        /// @details Moves the ownership of other's resources to
        /// this matrix and leaves the other matrix in a default
        /// constructed state. Returns///this. If self assignment 
        /// occurs then///this is returned immediately.
        /// 
        /// @param other type: [matrix] | qualifiers: [move]
        /// @return constexpr matrix&
        constexpr matrix& operator=(matrix&& other) noexcept
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


        /// @brief Initialiser List Assignment
        ///
        /// @details Uses std::initializer_list to create a matrix 
        /// from an initializer list of initializer lists. Elements 
        /// ownership is moved to the matrix's memory.
        ///
        /// @param list type: [std::initializer_list<std::initializer_list<value_type>>] | qualifiers: [const], [ref]
        /// @return constexpr matrix&
        constexpr matrix& operator= (std::initializer_list<std::initializer_list<value_type>> list)
        {   
            m_allocator = allocator_type();
            m_rows = list.size();
            m_columns = list.begin()->size();
            m_start = _M_allocate(_M_size());
            m_finish = m_start + _M_size();

            using init_iter = typename decltype(list)::iterator;
            auto offset { 0UL };
            for (init_iter row { list.begin() }; row not_eq list.end(); ++row)
            {
                if (row->size() not_eq this->m_columns)
                    throw std::invalid_argument("Columns must be all the same size");
                std::uninitialized_move_n(row->begin(), this->m_columns, m_start + offset);
                offset += this->m_columns;
            }

            return *this;
        }

        
        /// @brief Destructor
        /// 
        /// @details Releases the resources of this matrix
        /// and leaves the matrix in an uninitialized state. 
    #if __cplusplus >= 202202L
        constexpr ~matrix()
    #else
        ~matrix()
    #endif
        {
            if (m_start)
            {
                std::ranges::destroy(*this);
                _M_deallocate(m_start, _M_size());
            }

            m_rows = size_type();
            m_columns = size_type();
            m_start = pointer();
            m_finish = pointer();
            m_allocator = allocator_type();
        }


        /// @brief Reserves a new memory block for the matrix
        /// 
        /// @details Reserves a new matrix of dimensions new_columns
        /// by new_rows. 
        /// If the new dimensions are smaller than the
        /// current dimensions, no change is made to the matrix's 
        /// capacity but the matrix's dimensions are set to the new 
        /// dimensional values. This effects the access bounds of the 
        /// matrix. 
        /// If the new dimensions are larger than the current dimensions,
        /// then the matrix's capacity is increased to the new capacity 
        /// and the matrix bounds are adjusted accordingly.
        /// A call to matrix::reserve does not preserve the position of the
        /// elements stored within and merely copies the elements to the new 
        /// allocated buffer. 
        /// This means all elements shift to the front of the buffer and the 
        /// new available elements are at the back of the buffer. 
        /// 
        /// matrix::reserve makes no garuntee that the
        /// the order is preserved of elements in the matrix after
        /// it has been called.
        /// 
        /// @todo Ensure that the element's order is preserved. 
        /// 
        /// @param new_columns type: [size_type] 
        /// @param new_rows type: [size_type]
        // constexpr void reserve(size_type new_rows, size_type new_columns)
        // {
        //     auto new_capacity = new_rows * new_columns != 0 ? new_rows * new_columns : std::max(new_rows, new_columns);

        //     if (new_capacity > m_capacity)
        //     {
        //         auto new_data = _M_allocate(new_capacity);

        //         if constexpr (std::is_move_constructible_v<value_type>)                    
        //             std::uninitialized_move_n(m_data, m_size, new_data);
        //         else
        //             std::uninitialized_copy_n(m_data, m_size, new_data);

        //         std::destroy_n(m_data, m_capacity);
        //         _M_deallocate(m_data, m_capacity);


        //         m_data = new_data;
        //         m_capacity = new_capacity;
        //         m_rows = new_rows;
        //         m_columns = new_columns;
        //     }
        // }


        /// @brief Resizes the matrix to dimensions new_rows x new_columns.
        ///
        /// @details Resizes the matrix to dimensions new_rows x new_columns, 
        /// the resize will result in a new memory block being allocated
        /// if the new dimensions are larger or smaller than the current dimensions. 
        /// Reallocation or destruction of elements causes iterators and references 
        /// to be invalidated. If new dimensions don't change the overall size, only
        /// the view over the data (ie. the dimension sizes) are changed, elements 
        /// of the matrix remain unchanged, however, this is unchecked. For a checked  
        /// change that can only changes the dimension sizes, use matrix::reshape. 
        /// 
        /// @param new_rows type: [size_type]
        /// @param new_columns type: [size_type]
        constexpr void resize(size_type new_rows, size_type new_columns)
        {
            auto old_size { _M_size() };
            auto new_size { new_rows * new_columns != 0 ? new_rows * new_columns : std::max(new_rows, new_columns) };

            if (new_size > alloc_traits::max_size(m_allocator))
                throw std::length_error("Matrix resize too large");
            else
            {
                auto new_start { _M_allocate(new_size) };
                auto old_finish_pos_in_new { new_start + old_size };
                auto new_finish { new_start + new_size };

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


        /// @brief Resizes the matrix to dimensions new_rows x new_columns with default value
        ///
        /// @details Resizes the matrix to dimensions new_rows x new_columns, 
        /// the resize will result in a new memory block being allocated
        /// if the new dimensions are larger or smaller than the current dimensions. 
        /// Reallocation or destruction of elements causes iterators and references 
        /// to be invalidated. The new matrix is initialised with value. If new dimensions 
        /// don't change the overall size, only the view over the data (ie. the dimension 
        /// sizes) are changed, elements of the matrix remain unchanged, however, this is 
        /// unchecked. For a checked change that can only changes the dimension sizes, use 
        /// matrix::reshape. 
        /// 
        /// @param new_rows type: [size_type]
        /// @param new_columns type: [size_type]
        /// @param value type: [value_type] | qualifiers: [const], [ref]
        constexpr void resize(size_type new_rows, size_type new_columns, const value_type& value)
        {
            auto old_size { _M_size() };
            auto new_size { new_rows * new_columns != 0 ? new_rows * new_columns : std::max(new_rows, new_columns) };

            if (new_size > alloc_traits::max_size(m_allocator))
                throw std::length_error("Matrix resize too large");
            else
            {
                auto new_start { _M_allocate(new_size) };
                auto old_finish_pos_in_new { new_start + old_size };
                auto new_finish { new_start + new_size };

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

        /// @brief Erases element indicated by position
        ///
        /// @details Erases the value of the matrix at position
        /// and resets it to value_type().
        /// 
        /// @param position type: [const_iterator]
        /// @return constexpr iterator - attr: [[maybe_unused]] 
        /// :>> Returns the iterator to the erased position 
        [[maybe_unused]] constexpr iterator erase(const_iterator position)
        {
            // auto pos { begin() + (position - cbegin()) };

            std::ranges::destroy_at(std::addressof(*position));
            std::ranges::uninitialized_fill(position, position + 1, value_type());

            return position;
        }

        /// @brief Erases value between first and last
        /// 
        /// @details Elements between first and last and then
        /// resets memory to value_type() 
        /// 
        /// @param first type: [const_iterator]
        /// @param last type: [const_iterator]
        /// @return constexpr iterator - attr: [[maybe_unused]] 
        /// :>> Returns the iterator indicated the start of the erase 
        [[maybe_unused]] constexpr iterator erase(const_iterator first, const_iterator last)
        {
            // auto start { begin() + (first - cbegin()) };
            // auto finish { begin() + (last - cbegin()) };

            std::ranges::destroy(first, last);
            std::ranges::uninitialized_fill(first, last, value_type());

            return first;
        }


        /// @brief Clears the matrix elements
        /// 
        /// @details The elements of the matrix are destroyed and
        /// the memory is deallocated entirely. The matrix is however,
        /// left in a state where it could be re-initialised or 
        /// destructed which is up to user descretion. matrix::resize
        /// has to be used to allocate storage for the new elements.
        constexpr void clear()
        {
            if (_M_size())
            {
                erase(begin(), end());

                _M_deallocate(m_start, _M_size());
                m_rows = size_type();
                m_columns = size_type();
                m_finish = m_start = pointer();
            }
        }


        /// @brief Reshape current matrix elements to new dimensions
        ///
        /// @details Reshapes the current matrix's dimensisons while 
        /// guranteeing that now reallocation occurs. Elements are 
        /// preserved.
        /// 
        /// @param new_rows type: [size_type]
        /// @param new_columns type: [size_type]
        constexpr void reshape(size_type new_rows, size_type new_columns)
        {
            auto new_size { new_rows * new_columns != 0 ? new_rows * new_columns : std::max(new_rows, new_columns) };

            if (new_size != _M_size())
                throw std::length_error("Cannot reshape matrix that has different total size");
            else
                resize(new_rows, new_columns);
        }


        /// @brief Swaps two matrices of the same type.
        /// 
        /// @details Swaps the contents of two matrices of 
        /// which they are the same type. The swap is performed
        /// by moving ownership of the matrices resources. 
        /// 
        /// @param other type: [matrix] | qualifiers: [ref]
        void swap(matrix& other) noexcept
        {
            matrix tmp = std::move(other);
            other = std::move(*this);
           *this = std::move(tmp);
        }



        constexpr allocator_type get_allocator() const noexcept
        { return m_allocator; }
        

        /// @brief Returns the overall size of the matrix.
        /// 
        /// @return constexpr size_type
        constexpr size_type size() const noexcept
        { return empty() ? size_type(0) : _M_size(); }


        /// @brief Returns the number of the rows of the matrix.
        /// 
        /// @return constexpr size_type
        constexpr size_type row_size() const noexcept
        { return m_rows; } 


        /// @brief Returns the the number of columns in the matrix.
        /// 
        /// @return constexpr size_type
        constexpr size_type column_size() const noexcept
        { return m_columns; }


        /// @brief Returns the maximum number of elements that
        /// can be stored in the matrix.
        /// 
        /// @return constexpr size_type 
        constexpr size_type max_size() const noexcept
        { return alloc_traits::max_size(m_allocator); }


        /// @brief Returns a structured binding of the matrix's 
        /// dimensions.
        /// 
        /// @return constexpr auto : (structured binding)
        constexpr auto dimensions() const noexcept
        { return std::tie(m_columns, m_rows); }


        /// @brief Checks whether the matrix is square.
        /// 
        /// @details If the number of rows and columns are equal,
        /// the matrix is square.
        /// 
        /// @return true 
        /// @return false
        constexpr bool is_square() const noexcept
        { return m_rows == m_columns; }


        /// @brief Checks if the matrix is empty.
        /// 
        /// @return true 
        /// @return false
        constexpr bool empty() const noexcept
        { return m_start == m_finish; }


        /// @brief Returns the underlying data pointer.
        /// 
        /// @return pointer 
        pointer data() noexcept
        { return _M_data_ptr(m_start); }


        /// @brief Returns the underlying data pointer.
        /// 
        /// @return const_pointer
        const_pointer data() const noexcept
        { return _M_data_ptr(m_start); }


        /// @brief Subscript Operator.
        /// 
        /// @details Returns a reference to the element that 
        /// is at the position indicated by the pointer 
        /// m_data + step. Offers linear access to the matrix's
        /// elements.
        /// 
        /// @param step type: [size_type]
        /// @return constexpr reference
        constexpr reference operator[](size_type step) 
        { return *(m_start + step); }


        /// @brief Two Dimensional Element Access (Point Access).
        /// 
        /// @details Returns a reference to the element that
        /// is at the point position (column, row) of the 
        /// matrix. 
        /// 
        /// @exception std::out_of_range
        /// 
        /// @param column type: [size_type]
        /// @param row type: [size_type]
        /// @return constexpr reference
        constexpr reference at(size_type row, size_type column)
        { 
            _M_range_check(row, column);
            return *(m_start + (m_columns * row) + column);
        }


        /// @brief Two Dimensional Element Access (Point Access).
        /// 
        /// @details Returns a reference to the element that
        /// is at the point position (column, row) of the 
        /// matrix.  
        /// 
        /// @exception std::out_of_range
        /// 
        /// @param column type: [size_type]
        /// @param row type: [size_type]
        /// @return constexpr const_reference 
        constexpr const_reference at(size_type row, size_type column) const
        { 
            _M_range_check(row, column);
            return *(m_start + (m_columns * row) + column); 
        }


        /// @brief Point Access Operator.
        /// 
        /// @details Provides point access to matrix's elements.
        /// Overloads the invokation operator. Utilises the at() method. 
        /// 
        /// @exception std::out_of_range
        /// 
        /// @param column type: [size_type]
        /// @param row type: [size_type]
        /// @return constexpr reference
        constexpr reference operator() (size_type row, size_type column) 
        { return this->at(row, column); }


        /// @brief Point Access Operator.
        /// 
        /// @details Provides point access to matrix's elements.
        /// Overloads the invokation operator. Utilises the at() method. 
        /// 
        /// @exception std::out_of_range 
        /// 
        /// @param column type: [size_type]
        /// @param row type: [size_type]
        /// @return constexpr const_reference 
        constexpr const_reference operator() (size_type row, size_type column) const
        { return this->at(row, column); }


        /// @brief Returns a reference to the front element 
        /// of the matrix. 
        /// 
        /// @return constexpr reference 
        constexpr reference front() noexcept
        { return *(this->begin()); }


        /// @brief Returns a reference to the front element 
        /// of the matrix.
        /// 
        /// @return constexpr const_reference
        constexpr const_reference front() const noexcept
        { return *(this->begin()); }


        /// @brief Returns a reference to the back element 
        /// of the matrix.
        /// 
        /// @return constexpr reference
        constexpr reference back() noexcept
        { return *(this->end() - 1); }


        /// @brief Returns a reference to the back element 
        /// of the matrix.
        /// 
        /// @return constexpr const_reference
        constexpr const_reference back() const noexcept
        { return *(this->end() - 1); }


        /// @brief Flattens the matrix into a std::vector.
        /// 
        /// @details Creates a vector of the matrix's elements
        /// in row major order.
        /// 
        /// @return constexpr std::vector<value_type>
        constexpr std::vector<value_type> flatten() noexcept
        {
            std::vector<value_type> vec(_M_size());
            std::ranges::copy(*this, std::begin(vec));
            return vec;
        }


        /// @brief Iterator to the beginning of the matrix. 
        /// 
        /// @return constexpr iterator
        constexpr iterator begin() noexcept
        { return iterator(m_start); }


        /// @brief Constant iterator to the beginning of the matrix.
        /// 
        /// @return constexpr const_iterator
        constexpr const_iterator begin() const noexcept
        { return const_iterator(m_start); }


        /// @brief Constant iterator to the beginning of the matrix.
        /// 
        /// @return constexpr const_iterator
        constexpr const_iterator cbegin() const noexcept
        { return const_iterator(m_start); }


        /// @brief Reverse iterator to the end of the matrix.
        /// 
        /// @return constexpr reverse_iterator
        constexpr reverse_iterator rbegin() noexcept
        { return reverse_iterator(end()); }


        /// @brief Constant reverse iterator to the end of the matrix.
        /// 
        /// @return constexpr const_reverse_iterator 
        constexpr const_reverse_iterator rbegin() const noexcept
        { return const_reverse_iterator(end()); }


        /// @brief Constant reverse iterator to the end of the matrix.
        /// 
        /// @return constexpr const_reverse_iterator
        constexpr const_reverse_iterator crbegin() const noexcept
        { return const_reverse_iterator(end()); }


        /// @brief Iterator to the end of the matrix.
        /// 
        /// @return constexpr iterator 
        constexpr iterator end() noexcept
        { return iterator(m_finish); }

        
        /// @brief Constant iterator to the end of the matrix.
        /// 
        /// @return constexpr const_iterator
        constexpr const_iterator end() const noexcept
        { return const_iterator(m_finish); }


        /// @brief Constant iterator to the end of the matrix.
        /// 
        /// @return constexpr const_iterator
        constexpr const_iterator cend() const noexcept
        { return const_iterator(m_finish); }


        /// @brief Reverse iterator to the beginning of the matrix.
        /// 
        /// @return constexpr reverse_iterator 
        constexpr reverse_iterator rend() noexcept
        { return reverse_iterator(begin()); }


        /// @brief Constant reverse iterator to the beginning of the matrix.
        /// 
        /// @return constexpr const_reverse_iterator 
        constexpr const_reverse_iterator rend() const noexcept
        { return const_reverse_iterator(begin()); }


        /// @brief Constant reverse iterator to the beginning of the matrix.
        /// 
        /// @return constexpr const_reverse_iterator
        constexpr const_reverse_iterator crend() const noexcept
        { return const_reverse_iterator(begin()); }


        /// @brief Adds the elements of one matrix by another.
        ///
        /// @details Performs an element-wise addition 
        /// between matrices. Matrices are `Addable` iff the 
        /// type of this matrix's elements satisfies the 
        /// concept of `Addable` and satisfies the concept
        /// `AddableWith` with type of the elemnts of the 
        /// passed matrix. A new matrix is created and returned. 
        ///
        /// @requires The type of this matrix's elements are `Addable` 
        /// @requires The type of this matrix's elements and the type
        /// of the passed matrix's element types satisfy `AddableWith`.
        /// 
        /// @tparam _ElemT 
        /// @param other type: matrix<_ElemT> | qualifiers: [const], [ref] 
        /// @return constexpr auto : A matrix whose element's type 
        /// is the sum of the two input matrices element types. 
        template<Addable _ElemT>
            requires AddableWith<value_type, _ElemT>
        constexpr auto add(const matrix<_ElemT>& other)
            -> matrix<decltype(std::declval<value_type>() + std::declval<_ElemT>())>
        {
            if (this->dimensions() != other.dimensions())
                throw std::invalid_argument("In matrix::add - dimensions do not match");

            matrix<decltype(std::declval<value_type>() + std::declval<_ElemT>())> result(this->row_size(), this->column_size());

            std::ranges::transform(*this, other, result.begin(), std::plus{});

            return result;
        }


        /// @brief Substracts the elements of one matrix from another.
        ///
        /// @details Performs an element-wise subtraction 
        /// between matrices. Matrices are `Subtractable` 
        /// iff the type of this matrix's elements satisfies 
        /// the concept of `Subtractable` and satisfies the 
        /// concept `SubtractableWith` with type of the elemnts 
        /// of the passed matrix. A new matrix is created and 
        /// returned. 
        ///
        /// @requires The type of this matrix's elements are `Subtractable` 
        /// @requires The type of this matrix's elements and the type
        /// of the passed matrix's element types satisfy `SubtractableWith`.
        /// 
        /// @tparam _ElemT 
        /// @param other type: matrix<_ElemT> | qualifiers: [const], [ref] 
        /// @return constexpr auto : A matrix whose element type 
        /// is the difference of the two input matrices element types.
        template<Subtractable _ElemT>
            requires SubtractableWith<value_type, _ElemT>
        constexpr auto sub(const matrix<_ElemT>& other)
            -> matrix<decltype(std::declval<value_type>() - std::declval<_ElemT>())>
        {
            if (this->dimensions() != other.dimensions())
                throw std::invalid_argument("In matrix::sub - dimensions do not match");

            matrix<decltype(std::declval<value_type>() - std::declval<_ElemT>())> result(this->row_size(), this->column_size());

            std::ranges::transform(*this, other, result.begin(), std::minus{});

            return result;
        }


        /// @brief Multiplies the elements of one matrix by another..
        ///
        /// @details Performs an element-wise multiplication 
        /// between matrices. Matrices are `Multiplicible` 
        /// iff the type of this matrix's elements satisfies 
        /// the concept of `Multiplicable` and satisfies the 
        /// concept `MultiplicableWith` with type of the elemnts 
        /// of the passed matrix. A new matrix is created and 
        /// returned. 
        ///
        /// @requires The type of this matrix's elements are `Multiplicable` 
        /// @requires The type of this matrix's elements and the type
        /// of the passed matrix's element types satisfy `MultiplicableWith`.
        /// 
        /// @tparam _ElemT 
        /// @param other type: matrix<_ElemT> | qualifiers: [const], [ref] 
        /// @return constexpr auto : A matrix whose element type 
        /// is the product of the two input matrices element types.
        template<Multiplicable _ElemT>
            requires MultiplicableWith<value_type, _ElemT>
        constexpr auto mul(const matrix<_ElemT>& other)
            -> matrix<decltype(std::declval<value_type>() * std::declval<_ElemT>())>
        {
            if (this->dimensions() != other.dimensions())
                throw std::invalid_argument("In matrix::mult - dimensions do not match");

            matrix<decltype(std::declval<value_type>() * std::declval<_ElemT>())> result(this->row_size(), this->column_size());

            std::ranges::transform(*this, other, result.begin(), std::multiplies{});

            return result;
        }


        /// @brief Scalar Matrix Multiplication.
        ///
        /// @details Performs an element-wise multiplication of the matrix
        /// by a 'scalar' value. 
        ///
        /// @requires The type of this matrix's elements are `MultiplicableWith`
        /// the type denoted _ScalarT. 
        /// @requires The type denoted _ScalarT be `Multiplicable`.
        ///
        /// 
        /// @tparam _ScalarT 
        /// @param scalar type: _ScalarT | qualifiers: [const], [ref]
        /// @return matrix<decltype(std::declval<value_type>() * std::declval<_ScalarT>())> 
        template<Multiplicable _ScalarT>
            requires MultiplicableWith<value_type, _ScalarT>
        constexpr auto mul(const _ScalarT& scalar)
            -> matrix<decltype(std::declval<value_type>() * std::declval<_ScalarT>())>
        {
            if (empty())
                throw std::invalid_argument("In matrix::mul - scalar multiplication on empty matrix");

            matrix<decltype(std::declval<value_type>() * std::declval<_ScalarT>())> result(this->row_size(), this->column_size());

            std::ranges::transform(*this, result.begin(), [&](auto& elem) { return elem * scalar; });

            return result;
        }


        /// @brief Divides the elements of one matrix by another.
        ///
        /// @details Performs an element-wise division 
        /// between matrices. Matrices are `Divisible` 
        /// iff the type of this matrix's elements satisfies 
        /// the concept of `Divisible` and satisfies the 
        /// concept `MultiplicibleWith` with type of the elemnts 
        /// of the passed matrix. A new matrix is created and 
        /// returned. 
        ///
        /// @requires The type of this matrix's elements are `Divisible` 
        /// @requires The type of this matrix's elements and the type
        /// of the passed matrix's element types satisfy `DivisibleWith`.
        ///
        /// @note When dividing two matrices, if both matrices elements 
        /// are integrals, the division is performed as integer division.
        /// due to C++ rounding rules.
        /// 
        /// @tparam _ElemT 
        /// @param other type: matrix<_ElemT> | qualifiers: [const], [ref] 
        /// @return constexpr auto : A matrix whose element type 
        /// is the quotient of the two input matrices element types.
        template<Divisible _ElemT>
            requires DivisibleWith<value_type, _ElemT>
        constexpr auto div(const matrix<_ElemT>& other)
            -> matrix<decltype(std::declval<value_type>() / std::declval<_ElemT>())>
        {
            if (this->dimensions() != other.dimensions())
                throw std::invalid_argument("In matrix::div - dimensions do not match");

            matrix<decltype(std::declval<value_type>() / std::declval<_ElemT>())> result(this->row_size(), this->column_size());

            std::ranges::transform(*this, other, result.begin(), std::divides{});

            return result;
        }


        /// @brief Scalar Matrix Division
        ///
        /// @details Performs an element-wise division of the matrix
        /// by a 'scalar' value. 
        ///
        /// @requires The type of this matrix's elements are `DivisibleWith`
        /// the type denoted _ScalarT. 
        /// @requires The type denoted _ScalarT be `Divisible`.
        ///
        /// @note When dividing two matrices, if both matrices elements 
        /// are integrals, the division is performed as integer division.
        /// due to C++ rounding rules.
        /// 
        /// @tparam _ScalarT 
        /// @param scalar type: _ScalarT | qualifiers: [const], [ref]
        /// @return matrix<decltype(std::declval<value_type>() / std::declval<_ScalarT>())> 
        template<Divisible _ScalarT>
            requires DivisibleWith<value_type, _ScalarT>
        constexpr auto div(const _ScalarT& scalar)
            -> matrix<decltype(std::declval<value_type>() / std::declval<_ScalarT>())>
        {
            if (empty())
                throw std::invalid_argument("In matrix::div - scalar division on empty matrix");
            if (scalar == 0)
                throw std::invalid_argument("In matrix::div - scalar is zero");

            matrix<decltype(std::declval<value_type>() / std::declval<_ScalarT>())> result(this->row_size(), this->column_size());

            std::ranges::transform(*this, result.begin(), [&](auto& elem) { return elem / scalar; });

            return result;
        }

        /// @brief Matrix Transpose
        ///
        /// @details Performs a matrix transpose.
        /// 
        /// @return constexpr matrix<value_type> 
        constexpr matrix<value_type> transpose()
        {
            matrix<value_type> result(this->column_size(), this->row_size());

            for (auto row { 0u }; row < this->row_size(); ++row)
                for (auto col { 0u }; col < this->column_size(); ++col)
                    result.at(col, row) = this->at(row, col);
            return result;
        }


        /// @brief Matrix Determinate
        ///
        /// @details Returns the determinate of the matrix. 
        ///
        /// @exception std::invalid_argument Thrown if the matrix is 
        /// not a square matrix.
        /// @exception std::invalid_argument Thrown if the matrix is 
        /// empty.
        /// @exception std::invalid_argument Thrown if the matrix is 
        /// not a 2x2 matrix.
        /// 
        /// @note Only 2x2 matrices work for now
        /// 
        /// @return constexpr auto 
        // constexpr auto det()
        // {
        //     static_assert(Number<value_type>, "In matrix::det - value_type of matrix must satisfy cortex::Number");

        //     if (not is_square())
        //         throw std::invalid_argument("In matrix::det - matrix is not square");

        //     if (dimensions() == std::tuple(size_type(0), size_type(0)))
        //         throw std::invalid_argument("In matrix::det - matrix is empty");
            
        //     if (dimensions() == std::tuple(size_type(1), size_type(1)))
        //         return at(0, 0);

        //     if (dimensions() not_eq std::tuple(size_type(2), size_type(2)))
        //         throw std::invalid_argument("In matrix::det - matrix is not 2x2");
        //     else
        //         return at(0, 0) * at(1, 1) - at(0, 1) * at(1, 0) };
        // }


        // constexpr auto adjugate()
        // {
        //     if (not is_square())
        //         throw std::invalid_argument("In matrix::adjugate - matrix is not square");

        //     if (dimensions() == std::tuple(size_type(0), size_type(0)))
        //         throw std::invalid_argument("In matrix::adjugate - matrix is empty");
            
        //     if (dimensions() == std::tuple(size_type(1), size_type(1)))
        //         throw std::invalid_argument("In matrix::adjugate - matrix has one element");

        //     if (dimensions() not_eq std::tuple(size_type(2), size_type(2)))
        //         throw std::invalid_argument("In matrix::adjugate - matrix is not 2x2");
        //     else
        //         return matrix<value_type> { { at(1, 1), -at(1, 0) }
        //                                   , { -at(0, 1), at(0, 0) } };
        // }


        // /// @brief Matrix Inversion
        // ///
        // /// @details Inverts a matrix by dividing elements by the
        // /// determinate.
        // ///
        // /// @exception noexcept iff call to matrix::det() is noexcept
        // ///
        // /// @return constexpr auto
        // constexpr auto inverse()
        //     noexcept( noexcept(this->det()) )
        // { 
        //     auto determinate { det() }

        //     if determinate not_eq 0
        //         return adjugate().div(determinate);
        //     else
        //         throw std::invalid_argument("matrix::inverse - Non inversible matrix, determinate is 0");
        // }


        /// @brief Dot Product (Matrix Multiplication)
        ///
        /// @details Performs a matrix multiplication between two matrices.
        /// The left matrix must have the same number of columns as the
        /// right matrix has rows. This is a naive algorithm that takes
        /// O(n^3) time and O(n^2) auxilary space. 
        ///
        /// @requires The type of the passed matrix's element types 
        /// must be `AddableWith` the type of this matrix's elements.
        /// @requires The type of the passed matrix's element types 
        /// must be `MultiplicableWith` the type of this matrix's elements.
        ///
        /// @exception std::invalid_argument if the number of columns of the left matrix
        /// is not equal to the number of rows of the right matrix.
        /// 
        /// @tparam _ElemT 
        /// @param other 
        /// @return matrix<decltype(std::declval<value_type>() * std::declval<_ElemT>())> 
        template<typename _ElemT>
            requires AddableWith<value_type, _ElemT>
                  && MultiplicableWith<value_type, _ElemT> 
        constexpr auto dot(const matrix<_ElemT>& other)
            -> matrix<decltype(std::declval<value_type>() * std::declval<_ElemT>())>
        {
            if (this->column_size() != other.row_size())
                throw std::invalid_argument("In matrix::dot - The number of columns of this matrix must equal the number of rows of the other matrix");

            using out_type = decltype(std::declval<value_type>() * std::declval<_ElemT>());
            matrix<out_type> result(this->row_size(), other.column_size(), out_type());
            
            for (auto this_row { 0u }; this_row < this->row_size(); ++this_row)
                for (auto other_col { 0u }; other_col < other.column_size(); ++other_col)
                    for (auto this_col { 0u }; this_col < this->column_size(); ++this_col)
                        result.at(this_row, other_col) += this->at(this_row, this_col) * other.at(this_col, other_col);

            return result;
        }


    private:

        /// @brief Allocates Matrix Recources
        /// 
        /// @details Allocates the memory for the matrix 
        /// using the allocator of the container. Uses 
        /// std::allocator_traits to get the allocators
        /// relevant methods. 
        ///
        /// @note Default allocator is std::allocator<value_type>.
        /// 
        /// @param __n type: [size_type]
        /// @return constexpr pointer 
        constexpr pointer _M_allocate(size_type __n)
        { return __n != 0 ? alloc_traits::allocate(m_allocator, __n) : pointer(); }


        /// @brief Dellocates Matrix Recources
        /// 
        /// @details Dellocates the memory for the matrix 
        /// using the allocator of the container. Uses 
        /// std::allocator_traits to get the allocators
        /// relevant methods. 
        ///
        /// @note Default allocator is std::allocator<value_type>.
        /// 
        /// @param __p type: [pointer]
        /// @param __n type: [size_type] | attr: [[maybe_unused]]
        constexpr void _M_deallocate(pointer __p, [[maybe_unused]] size_type __n)
        { 
            if (__p)
                alloc_traits::deallocate(m_allocator, __p, __n);
        }


        /// @brief Checks index's are in the bounds of the matrix
        /// 
        /// @details Checks if __column and __row are withing 
        /// the matrix's bounds. 
        /// 
        /// @exception std::out_of_range
        /// 
        /// @param __column type: [size_type]
        /// @param __row type: [size_type]
        constexpr void _M_range_check(size_type __row, size_type __column) const
        {
            if (__row >= this->row_size() or __column >= this->column_size())
                throw std::out_of_range("matrix::_M_range_check - index out of range.");
        }


        constexpr size_type _M_size() const noexcept
        { return m_rows * m_columns != 0 ? m_rows * m_columns : std::max(m_rows, m_columns); }    


        /// @brief Returns the pointer passed to it.
        /// 
        /// @tparam _Up 
        /// @param __ptr type: [_Up*]
        /// @return _Up* 
        template<typename _Up>
        _Up* _M_data_ptr(_Up* __ptr) const noexcept
        { return __ptr; }

#if __cplusplus >= 201103L

        /// @brief Returns the pointer passed to it.
        /// 
        /// @details If the value given is not a builtin 
        /// pointer type, a pointer is created from the 
        /// underlying element type.
        /// 
        /// @tparam _Ptr
        /// @param __ptr type: [_Ptr]
        /// @return typename std::pointer_traits<_Ptr>::element_type*
        template<typename _Ptr>
        typename std::pointer_traits<_Ptr>::element_type* 
        _M_data_ptr(_Ptr __ptr) const
        { return empty() ? nullptr : std::to_address(*__ptr); }
#else

        /// @brief Returns the given pointer
        /// 
        /// @details Returns the pointer given to it is 
        /// a builtin pointer type.
        /// 
        /// @tparam _Up 
        /// @param __ptr type: [_Up*] 
        /// @return _Up*
        template<typename _Up>
        _Up* _M_data_ptr(_Up* __ptr) noexcept
        { return __ptr; }
#endif // __cplusplus >= 201103L

    };

    /// @brief Compares two matrices for equality.
    ///
    /// @details Uses std::equal to compare the matrices.
    /// Takes at least O(n) where n = columns x rows = lhs.end() - lhs.begin()
    ///
    /// @requires Matrix elements support equality comparison
    /// that converts to a bool
    ///
    /// @exception Operation is has no exception iff the comparison
    /// between matrix elements is noexcept and std::equal is
    /// noexcept across the range
    ///
    /// @tparam _ElemL
    /// @tparam _ElemR
    /// @rparam lhsE type: [_ElemL]
    /// @rparam rhsE type: [_ElemR]
    /// @param lhs type: [matrix<_ElemL>] | qualifiers: [const], [ref]
    /// @param rhs type: [matrix<_ElemR>] | qualifiers: [const], [ref]
    /// @return true
    /// @return false
    template<typename _ElemL, typename _ElemR>
#if __cpluscplus >= 202002L 
        requires requires (_ElemL lhsE, _ElemR rhsE)
        { { lhsE == rhsE } -> std::convertible_to<bool>; }
    constexpr inline bool
    operator== (const matrix<_ElemL>& lhs, const matrix<_ElemR>& rhs)
        noexcept ( 
               noexcept (std::declval<_ElemL>() == std::declval<_ElemR>()) 
            && noexcept (std::ranges::equal(lhs, rhs);)
        )
#else
    inline bool
    operator== (const matrix<_ElemL>& lhs, const matrix<_ElemR>& rhs)
#endif 
    { 
        if (lhs.dimensions() not_eq rhs.dimensions())
            return false;
        return std::ranges::equal(lhs, rhs); 
    }

/// Current bug with GCC-11.1 with lexicographical_compare_three_way
/// causes cortex::matrix to not compile. Issue: PR
/// Current bug with Clang++-12 with lexicographical_compare_three_way
/// cause cortex::matrix to be compared on matrix size over value precidence
#if __cpp_lib_three_way_comparison && !(lexicographical_compare_bug)

    /// @brief Spaceship Operator for matrices.
    ///
    /// @details Uses std::lexicographical_compare_three_way to 
    /// compare the matrices and generates the !=, <, >, <=, >=
    /// operators.
    /// 
    /// @tparam _ElemL 
    /// @tparam _ElemR 
    /// @param lhs type: [matrix<_ElemL>] | qualifiers: [const], [ref]
    /// @param lhs type: [matrix<_ElemL>] | qualifiers: [const], [ref]
    /// @return constexpr inline auto
    template<typename _ElemL, typename _ElemR>
    constexpr inline auto
    operator<=> (const matrix<_ElemL>& lhs, const matrix<_ElemR>& rhs)
    { 
        return std::lexicographical_compare_three_way(lhs.begin(), lhs.end()
                                                  , rhs.begin(), rhs.end()
                                                  , std::compare_three_way{}); 
    }

#else // !C++20

    /// @brief Compares two matrices for inequality.
    ///
    /// @details Inverts the result of a equality comparison
    /// between two matrices.
    /// 
    /// @tparam _ElemL 
    /// @tparam _ElemR 
    /// @param lhs type: [matrix<_ElemL>] | qualifiers: [const], [ref]
    /// @param rhs type: [matrix<_ElemR>] | qualifiers: [const], [ref]
    /// @return true 
    /// @return false 
    template<typename _ElemL, typename _ElemR>
    inline bool
    operator!= (const matrix<_ElemL>& lhs, const matrix<_ElemR>& rhs)
    { return !(lhs == rhs); }


    /// @brief Compares if a matrix is lexicographically 
    /// less than another. 
    /// 
    /// @tparam _ElemL 
    /// @tparam _ElemR 
    /// @param lhs type: [matrix<_ElemL>] | qualifiers: [const], [ref]
    /// @param rhs type: [matrix<_ElemR>] | qualifiers: [const], [ref]
    /// @return true 
    /// @return false 
    template<typename _ElemL, typename _ElemR>
    inline bool
    operator< (const matrix<_ElemL>& lhs, const matrix<_ElemR>& rhs)
    { 
        return std::ranges::lexicographical_compare(lhs, rhs); 
    }


    /// @brief Compares if a matrix is lexicographically
    /// greater than another.
    ///
    /// @details Uses less than comparison and swaps the
    /// order of the arguments. 
    /// 
    /// @tparam _ElemL 
    /// @tparam _ElemR 
    /// @param lhs type: [matrix<_ElemL>] | qualifiers: [const], [ref]
    /// @param rhs type: [matrix<_ElemR>] | qualifiers: [const], [ref]
    /// @return true 
    /// @return false 
    template<typename _ElemL, typename _ElemR>
    inline bool
    operator> (const matrix<_ElemL>& lhs, const matrix<_ElemR>& rhs)
    { return rhs < lhs; }


    /// @brief Compares if a matrix is lexicographically
    /// less than or equal to another. 
    ///
    /// @details Uses less than comparison and swaps the
    /// order of the arguments. If the rhs matrix is less
    /// than the lhs matrix, then the lhs matrix cannot
    /// be less then or equal to the rhs matrix.  
    /// 
    /// @tparam _ElemL 
    /// @tparam _ElemR 
    /// @param lhs type: [matrix<_ElemL>] | qualifiers: [const], [ref]
    /// @param rhs type: [matrix<_ElemR>] | qualifiers: [const], [ref]
    /// @return true 
    /// @return false 
    template<typename _ElemL, typename _ElemR>
    inline bool
    operator<= (const matrix<_ElemL>& lhs, const matrix<_ElemR>& rhs)
    { return !(rhs < lhs); }


    /// @brief Compares if a matrix is lexicographically
    /// greater than or equal to another.
    ///
    /// @details Inverts the result of a less than comparison
    /// between the two matrices. 
    /// 
    /// @tparam _ElemL 
    /// @tparam _ElemR 
    /// @param lhs type: [matrix<_ElemL>] | qualifiers: [const], [ref]
    /// @param rhs type: [matrix<_ElemR>] | qualifiers: [const], [ref]
    /// @return true 
    /// @return false 
    template<typename _ElemL, typename _ElemR>
    inline bool
    operator>= (const matrix<_ElemL>& lhs, const matrix<_ElemR>& rhs)
    { return !(lhs < rhs); }

#endif // three way compare


    /// @brief Scalar Equality Comparison 
    /// 
    /// @details Compares each value within the matrix to a given
    /// scalar. Creates a bit mask (or boolean mask) of the values 
    /// that are equal as true and the everything else as false.
    ///
    /// @requires Comparison of scalar type and matrix type support 
    /// equality comparison that results in a bool.
    ///
    /// @exception Operation is noexcept iff the inequlity comparison 
    /// between the scalar and the matrix element's types is noexcept.
    ///
    /// @tparam _ElemT 
    ///
    /// @param mtx type: [matrix<_ElemT>] | qualifiers: [const], [ref]
    /// @param scalar type: [_ElemT] | qualifiers: [const], [ref]
    /// @return matrix<bool> 
    template<typename _ElemT>
#if __cpluscplus >= 202002L 
        requires requires (_ElemT lhsE, _ElemT rhsE)
        { { lhsE == rhsE } -> std::convertible_to<bool>; }
    constexpr inline auto
    operator== (const matrix<_ElemT>& mtx, const _ElemT& scalar)
        noexcept ( noexcept ( std::declval<_ElemT>() == std::declval<_ElemT>() ) )
        -> matrix<bool>
#else
    inline auto
    operator== (const matrix<_ElemT>& mtx, const _ElemT& scalar)
        -> matrix<bool>
#endif 
    { 
        matrix<bool> result(mtx.row_size(), mtx.column_size(), false);
        std::ranges::transform(mtx, result.begin(), [&](const _ElemT& mtxE) { return mtxE == scalar; });
        return result;
    }


    /// @brief Scalar Inequality Comparison 
    /// 
    /// @details Compares each value within the matrix to a given
    /// scalar. Creates a bit mask (or boolean mask) of the values 
    /// that are inequal as true and the everything else as false.
    ///
    /// @requires Comparison of scalar type and matrix type support 
    /// inequality comparison that results in a bool.
    ///
    /// @exception Operation is noexcept iff the inequlity comparison 
    /// between the scalar and the matrix element's types is noexcept.
    ///
    /// @tparam _ElemT 
    ///
    /// @param mtx type: [matrix<_ElemT>] | qualifiers: [const], [ref]
    /// @param scalar type: [_ElemT] | qualifiers: [const], [ref]
    /// @return matrix<bool>
    template<typename _ElemT>
#if __cpluscplus >= 202002L 
        requires requires (_ElemT lhsE, _ElemT rhsE)
        { { lhsE != rhsE } -> std::convertible_to<bool>; }
    constexpr inline auto
    operator!= (const matrix<_ElemT>& mtx, const _ElemT& scalar)
        noexcept ( noexcept ( std::declval<_ElemT>() != std::declval<_ElemT>() ) )
        -> matrix<bool>
#else
    inline auto
    operator!= (const matrix<_ElemT>& mtx, const _ElemT& scalar)
        -> matrix<bool>
#endif 
    { 
        matrix<bool> result(mtx.row_size(), mtx.column_size(), false);
        std::ranges::transform(mtx, result.begin(), [&](const _ElemT& mtxE) { return mtxE != scalar; });
        return result;
    }


    /// @brief Scalar Less-Then Comparison 
    /// 
    /// @details Compares each value within the matrix to a given
    /// scalar. Creates a bit mask (or boolean mask) of the values 
    /// that are less-than as true and the everything else as false.
    ///
    /// @requires Comparison of scalar type and matrix type support 
    /// less-than comparison that results in a bool.
    ///
    /// @exception Operation is noexcept iff the less-than comparison 
    /// between the scalar and the matrix element's types is noexcept.
    ///
    /// @tparam _ElemT 
    ///
    /// @param mtx type: [matrix<_ElemT>] | qualifiers: [const], [ref]
    /// @param scalar type: [_ElemT] | qualifiers: [const], [ref]
    /// @return matrix<bool> 
    template<typename _ElemT>
#if __cpluscplus >= 202002L 
        requires requires (_ElemT lhsE, _ElemT rhsE)
        { { lhsE < rhsE } -> std::convertible_to<bool>; }
    constexpr inline auto
    operator< (const matrix<_ElemT>& mtx, const _ElemT& scalar)
        noexcept ( noexcept ( std::declval<_ElemT>() < std::declval<_ElemT>() ) )
        -> matrix<bool>
#else
    inline auto
    operator< (const matrix<_ElemT>& mtx, const _ElemT& scalar)
        -> matrix<bool>
#endif 
    { 
        matrix<bool> result(mtx.row_size(), mtx.column_size(), false);
        std::ranges::transform(mtx, result.begin(), [&](const _ElemT& mtxE) { return mtxE < scalar; });
        return result;
    }


    /// @brief Scalar Greater-Then Comparison 
    /// 
    /// @details Compares each value within the matrix to a given
    /// scalar. Creates a bit mask (or boolean mask) of the values 
    /// that are greater-than as true and the everything else as false.
    ///
    /// @requires Comparison of scalar type and matrix type support 
    /// greater-than comparison that results in a bool.
    ///
    /// @exception Operation is noexcept iff the greater-than comparison 
    /// between the scalar and the matrix element's types is noexcept.
    ///
    /// @tparam _ElemT 
    ///
    /// @param mtx type: [matrix<_ElemT>] | qualifiers: [const], [ref]
    /// @param scalar type: [_ElemT] | qualifiers: [const], [ref]
    /// @return matrix<bool> 
    template<typename _ElemT>
#if __cpluscplus >= 202002L 
        requires requires (_ElemT lhsE, _ElemT rhsE)
        { { lhsE > rhsE } -> std::convertible_to<bool>; }
    constexpr inline auto
    operator> (const matrix<_ElemT>& mtx, const _ElemT& scalar)
        noexcept ( noexcept ( std::declval<_ElemT>() > std::declval<_ElemT>() ) )
        -> matrix<bool>
#else
    inline auto
    operator> (const matrix<_ElemT>& mtx, const _ElemT& scalar)
        -> matrix<bool>
#endif 
    { 
        matrix<bool> result(mtx.row_size(), mtx.column_size(), false);
        std::ranges::transform(mtx, result.begin(), [&](const _ElemT& mtxE) { return mtxE > scalar; });
        return result;
    }


    /// @brief Scalar Less-Then-Equal Comparison 
    /// 
    /// @details Compares each value within the matrix to a given
    /// scalar. Creates a bit mask (or boolean mask) of the values 
    /// that are less-than-eqaul as true and the everything else as 
    /// false.
    ///
    /// @requires Comparison of scalar type and matrix type support 
    /// less-than comparison that results in a bool.
    ///
    /// @exception Operation is noexcept iff the less-than-equal comparison 
    /// between the scalar and the matrix element's types is noexcept.
    ///
    /// @tparam _ElemT 
    ///
    /// @param mtx type: [matrix<_ElemT>] | qualifiers: [const], [ref]
    /// @param scalar type: [_ElemT] | qualifiers: [const], [ref]
    /// @return matrix<bool> 
    template<typename _ElemT>
#if __cpluscplus >= 202002L 
        requires requires (_ElemT lhsE, _ElemT rhsE)
        { { lhsE <= rhsE } -> std::convertible_to<bool>; }
    constexpr inline auto
    operator<= (const matrix<_ElemT>& mtx, const _ElemT& scalar)
        noexcept ( noexcept ( std::declval<_ElemT>() > std::declval<_ElemT>() ) )
        -> matrix<bool>
#else
    inline auto
    operator<= (const matrix<_ElemT>& mtx, const _ElemT& scalar)
        -> matrix<bool>
#endif 
    { 
        matrix<bool> result(mtx.row_size(), mtx.column_size(), false);
        std::ranges::transform(mtx, result.begin(), [&](const _ElemT& mtxE) { return mtxE <= scalar; });
        return result;
    }


    /// @brief Scalar Greater-Then-Equal Comparison 
    /// 
    /// @details Compares each value within the matrix to a given
    /// scalar. Creates a bit mask (or boolean mask) of the values 
    /// that are greater-than-equal as true and the everything else 
    /// as false.
    ///
    /// @requires Comparison of scalar type and matrix type support 
    /// greater-than-equal comparison that results in a bool.
    ///
    /// @exception Operation is noexcept iff the greater-than-equal 
    /// comparison between the scalar and the matrix element's types 
    /// is noexcept.
    ///
    /// @tparam _ElemT 
    ///
    /// @param mtx type: [matrix<_ElemT>] | qualifiers: [const], [ref]
    /// @param scalar type: [_ElemT] | qualifiers: [const], [ref]
    /// @return matrix<bool> 
    template<typename _ElemT>
#if __cpluscplus >= 202002L 
        requires requires (_ElemT lhsE, _ElemT rhsE)
        { { lhsE >= rhsE } -> std::convertible_to<bool>; }
    constexpr inline auto
    operator>= (const matrix<_ElemT>& mtx, const _ElemT& scalar)
        noexcept ( noexcept ( std::declval<_ElemT>() > std::declval<_ElemT>() ) )
        -> matrix<bool>
#else
    inline auto
    operator>= (const matrix<_ElemT>& mtx, const _ElemT& scalar)
        -> matrix<bool>
#endif 
    { 
        matrix<bool> result(mtx.row_size(), mtx.column_size(), false);
        std::ranges::transform(mtx, result.begin(), [&](const _ElemT& mtxE) { return mtxE >= scalar; });
        return result;
    }

} // namespace cortex

namespace std
{   
    /// @brief Uses std::swaps to swap the contents of two matrices. 
    ///
    /// @details Swaps the contents of two matrices if they are of 
    /// the same type.
    ///
    /// @exception std::swap is noexcept if __x.swap(__y) is noexcept.
    /// 
    /// @tparam _Tp 
    /// @param __x type: [cortex::matrix<_Tp>] | qualifiers: [const], [ref]
    /// @param __y type: [cortex::matrix<_Tp>] | qualifiers: [const], [ref]
    /// @return inline void
    template<typename _Tp>
    inline void swap(cortex::matrix<_Tp>& x, cortex::matrix<_Tp>& y)
        noexcept( noexcept(x.swap(y)) )
    { x.swap(y); }
}

#endif // __cplusplus >= 201703L

#endif // CORTEX_MATRIX_H