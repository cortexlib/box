# Todo

---

## Contents

- [Todo](#todo)
  - [Contents](#contents)
  - [Data Structures](#data-structures)
  - [Ranges and Views](#ranges-and-views)
  - [Coroutines](#coroutines)
  - [Iterators](#iterators)
  - [Allocators](#allocators)
  - [Miscellaneous](#miscellaneous)

---

## Data Structures

- [ ] Box
  - [x] Constructors & Destructors
    - [x] Default
    - [x] Explicit Allocator
    - [x] Explicit Size & Allocator
    - [x] Explicit Size, Value & Allocator
    - [x] Copy
    - [x] Copy & Allocator
    - [x] Move
    - [x] Move & Allocator
    - [x] Explicit Initialiser List (Nested)
    - [x] Explicit Shape & allocator
    - [x] Destructor
  - [x] Assignment
    - [x] Copy
    - [x] Move
    - [x] Initialiser List (Nested)
    - ~~[ ] Initialiser List [assign method] (Nested)~~
  - [ ] Element Access
    - [x] `.at()`
    - ~~[ ] `.slice()`~~
    - [ ] Operator `()`
      - [x] Operator `(x, y)`
      - [ ] Operator `(pair, pair)`
      - [ ] Operator `(pair, ::all{})`
      - [ ] Operator `(::all{}, pair)`
      - [ ] Operator `(3-tuple, 3-tuple)`
      - [ ] Operator `(3-tuple, ::all{})`
      - [ ] Operator `(::all{}, 3-tuple)`
    - [x] `.front()`
    - [x] `.back()`
    - [x] `.data()`
  - [x] Iterators
    - [x] `.begin()`
    - [x] `.cbegin()`
    - [x] `.rbegin()`
    - [x] `.crbegin()`
    - [x] `.end()`
    - [x] `.cend()`
    - [x] `.rend()`
    - [x] `.crend()`
  - [x] Modifiers
    - [x] `.clear`
    - [x] `.resize()`
    - [x] `.reshape()`
    - [x] `.swap()`
    - [x] `std::swap()` injection
    - [x] `.erase()`
    - ~~[ ] `std::erase` injection~~
  - [ ] Functional
    - [x] `.map()`
    - [ ] `.transpose()`
  - [x] Capacity
    - [x] `.empty()`
    - [x] `.size()`
    - [x] `.max_size()`
    - [x] `.shape()`
    - [x] `.is_square()`
    - [x] `.num_columns()`
    - [x] `.num_rows()`
  - [ ] Operators
    - [ ] Functional
      - [x] `||` - map
      - [ ] `/` - reduce
      - [ ] `!` - transpose
      - [ ] `+` - horizontally concatenate
      - [ ] `^` - vertically concatenate
      - [ ] `%` - dot product
    - [ ] Comparison
      - [x] `==` - equality
      - [x] `<=>` - spaceship
  - [x] Misc.
    - [x] `.get_allocator()`
  - [ ] Box View
    - [ ] Create a 2D std::view that lazily applies function calls
    - [ ] or box_map_result like types
  - [x] Testing
  - [ ] Improvements
    - [ ] Make .at() return an optional
    - [ ] Make operators return optionals
- [ ] Tensor
- [ ] Ring - Circular Buffer (_Maybe better as a repeating range adaptor or generator_)

## Ranges and Views

- [ ] Column View - Able to move through a range (<space|field>?) in a column wise manner.
- [ ] Row View - ^^

## Coroutines

- Generator coroutine

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
- [ ] Lane Iterator

~~## Literals~~

- ~~[ ] `int`~~
- ~~[ ] `float`~~
- ~~[ ] `double`~~

## Allocators

- [ ] Pool
- [ ] Linear
- [ ] Free List
- [ ] Stack

## Miscellaneous

- [ ] Support Testing CI using GitHub
- [ ] Move data structures to container sub-library
- [x] Match Expression
  - [x] Match overload
  - [x] Support syntax sugar for match expression
    - [x] Decide final syntax (operator)
  - [x] Fallthrough type (~~otherwise~~ `_`) instead of `auto&&` (for un-retrievable values)
    - ~~[ ] Maybe use `std::any`~~
- [ ] Indices generator
- [ ] Pretty Printing
  - [ ] Support `std::formatter` for custom data structures
