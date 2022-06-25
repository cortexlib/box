# Header file `reverse.hpp`

``` cpp
#define CORTEX_REVERSE_ITERATOR_HPP

namespace cortex
{
    template <typename _Iterator>
    class reverse_iterator;
}
```

An iterator for iterating through a container in reverse order.

reverse.hpp \\author Tyler Swann (oraqlle@github.com) \\version 1.0.0 \\date 2022-03-31

\\copyright Copyright (c) 2022

### Class `cortex::reverse_iterator`

``` cpp
template <typename _Iterator>
class reverse_iterator
{
};
```

Reverse Iterator

This iterator applies the inverse operation to an underlying iterator of type \_Iterator, thus allowing for reversed traversel through a container.

-----
