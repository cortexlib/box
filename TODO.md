# Todo

---

## Contents

- [Todo](#todo)
  - [Contents](#contents)
  - [Data Structures](#data-structures)
  - [Iterators](#iterators)
  - [Literals](#literals)
  - [Allocators](#allocators)
  - [Misc.](#misc)

---

## Data Structures

- [ ] Box
  - [ ] Constructors & Destructors
    - [ ] Default
    - [ ] Explicit Allocator
    - [ ] Explicit Size & Allocator
    - [ ] Explicit Size, Value & Allocator
    - [ ] Copy
    - [ ] Copy & Allocator
    - [ ] Move
    - [ ] Move & Allocator
    - [ ] Explicit Initialiser List (Nested)
    - [ ] Explicit Shape & allocator
    - [ ] Destructor
  - [ ] Assignment
    - [ ] Copy
    - [ ] Move
    - [ ] Initialiser List (Nested)
    - [ ] Initialiser List [assign method] (Nested)
  - [ ] Element Access
    - [ ] `.at()`
    - [ ] `.slice()`
    - [ ] Operator `()`
      - [ ] Operator `(pair, pair)`
      - [ ] Operator `(pair, ::all{})`
      - [ ] Operator `(::all{}, pair)`
      - [ ] Operator `(3-tuple, 3-tuple)`
      - [ ] Operator `(3-tuple, ::all{})`
      - [ ] Operator `(::all{}, 3-tuple)`
    - [ ] `.front()`
    - [ ] `.back()`
    - [ ] `.data()`
  - [ ] Iterators
    - [ ] `.begin()`
    - [ ] `.cbegin()`
    - [ ] `.rbegin()`
    - [ ] `.crbegin()`
    - [ ] `.end()`
    - [ ] `.cend()`
    - [ ] `.rend()`
    - [ ] `.crend()`
  - [ ] Modifiers
    - [ ] `.clear`
    - [ ] `.resize()`
    - [ ] `.reshape()`
    - [ ] `.swap()`
    - [ ] `std::swap()` injection
    - [ ] `.erase()`
    - [ ] `std::erase` injection
    - [ ] `.map()`
    - [ ] `.transpose()`
  - [ ] Capacity
    - [ ] `.empty()`
    - [ ] `.size()`
    - [ ] `.max_size()`
    - [ ] `.shape()`
    - [ ] `.is_square()`
    - [ ] `.num_columns()`
    - [ ] `.num_rows()`
  - [ ] Operators
    - [ ] `||` - map
    - [ ] `/` - reduce
    - [ ] `!` - transpose
    - [ ] `+` - horizontally concatenate
    - [ ] `^` - vertically concatenate
    - [ ] `%` - dot product
    - [ ] `==` - equality
    - [ ] `<=>` - spaceship
  - [ ] Misc.
    - [ ] `.get_allocator()`
- [ ] Tensor

## Iterators

- [ ] Normal (adaptor)
  - [ ] Constructors & Destructors
    - [ ] Default
    - [ ] Explicit Iterator Type
    - [ ] Copy
  - [ ] Assignment
    - [ ] Copy
    - [ ] Explicit Iterator Type
  - [ ] Operators
    - [ ] `*` - Dereference
    - [ ] `->` - Pointer Indirection
    - [ ] `++` - Increment
    - [ ] `++(int)` - Increment (post)
    - [ ] `--` - Decrement
    - [ ] `--(int)` - Decrement (post)
    - [ ] `+` - Add
    - [ ] `-` - Minus
    - [ ] `+=` - Add Assignment
    - [ ] `-=` - Minus Assignment
    - [ ] `[]` - Relative access
  - [ ] Operators (non-member)
    - [ ] `+` - Add
    - [ ] `-` - Minus
    - [ ] `==` - equal
    - [ ] `!=` - unequal
    - [ ] `<` - less
    - [ ] `<=` - less-equal
    - [ ] `>` - greater
    - [ ] `=>` - greater-equal
    - [ ] `<=>` - spaceship
  - [ ] Misc.
    - [ ] `.base()`
    - [ ] `make_normal_iterator()`
    - [ ] `std::iter_move()` injection
    - [ ] `std::iter_swap()` injection

## Literals

- [ ] `int`
- [ ] `float`
- [ ] `double`

## Allocators

- [ ] Pool
- [ ] Linear
- [ ] Free List
- [ ] Stack

## Misc.

- [ ] Match Expression
- [ ] Indices generator
