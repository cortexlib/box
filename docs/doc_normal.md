# Header file `normal.hpp`

``` cpp
#define CORTEX_NORMAL_ITERATOR_HPP

namespace cortex
{
    template <typename _Iterator, typename _Container>
    class normal_iterator;
}
```

Adapts a non-object iterator to an object iterator without changing its semantics.

Author: Tyler Swann (oraqlle@github.com)

Header Version: v1.1.0

Date: 25-06-2022

License: MIT

Copyright: Copyright (c) 2022

normal.hpp

### Class `cortex::normal_iterator`

``` cpp
template <typename _Iterator, typename _Container>
class normal_iterator
{
};
```

Normal Iterator

This iterator is used to adapt non-iterator objects into objects (ie. pointers). %normal\_iterator does not change the semantics of the operators of the underlying iterator of type \_Iterator.

#### Template parameters

  - `_Iterator` - The underlying type of the iterator.
  - `_Container` - Allows classes to create different types of iterators even if the \_Iterator type is the same.

-----
