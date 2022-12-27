# Todo

---

## Contents

- [Todo](#todo)
  - [Contents](#contents)
  - [Data Structures](#data-structures)
  - [Iterators](#iterators)
  - [Literals](#literals)
  - [Allocators](#allocators)
  - [Miscellaneous](#miscellaneous)

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
  - [ ] Testing
- [ ] Tensor

## Iterators

- [x] Normal (adaptor)
  - [x] Constructors & Destructors
    - [x] Default
    - [x] Explicit Iterator Type Copy
    - [x] Explicit Converting
    - [x] Copy
    - ~~[x] Delete Move~~
    - ~~[x] Delete Iterator Type Move~~
  - [x] Assignment
    - [x] Copy
    - [x] Explicit Iterator Type
  - [x] Operators
    - [x] `*` - Dereference
    - [x] `->` - Pointer Indirection
    - [x] `++` - Increment
    - [x] `++(int)` - Increment (post)
    - [x] `--` - Decrement
    - [x] `--(int)` - Decrement (post)
    - [x] `+` - Add
    - [x] `-` - Minus
    - [x] `+=` - Add Assignment
    - [x] `-=` - Minus Assignment
    - [x] `[]` - Relative access
  - [x] Operators (non-member)
    - [x] `+` - Add
    - [x] `-` - Minus
    - [x] `==` - equal
    - [x] `!=` - unequal
    - [x] `<` - less
    - [x] `<=` - less-equal
    - [x] `>` - greater
    - [x] `>=` - greater-equal
    - [x] `<=>` - spaceship
  - [x] Misc.
    - [x] `.base()`
    - [x] `make_normal_iterator()`
    - [x] `std::iter_move()` injection
    - [x] `std::iter_swap()` injection
  - [x] Testing
  - [x] Refactor to trailing return

## Literals

- [ ] `int`
- [ ] `float`
- [ ] `double`

## Allocators

- [ ] Pool
- [ ] Linear
- [ ] Free List
- [ ] Stack

## Miscellaneous

- [x] Match Expression
  - [x] Match overload
  - [x] Support syntax sugar for match expression
    - [x] Decide final syntax (operator)
  - [x] Fallthrough type (~~otherwise~~ `_`) instead of `auto&&` (for un-retrievable values)
    - ~~[ ] Maybe use `std::any`~~
- [ ] Indices generator
- [ ] Pretty Printing
  - [ ] Support `std::formatter` for custom data structures
