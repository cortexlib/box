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

Author: Tyler Swann (oraqlle@github.com)

Header Version: v1.0.0

Date: 25-06-2022

License: MIT

Copyright: Copyright (c) 2022

reverse.hpp

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
