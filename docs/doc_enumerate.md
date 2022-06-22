# Header file `enumerate.hpp`

``` cpp
#define CORTEX_ENUMERATE_H

namespace cortex
{
    template <typename _Tp, typename _Iterator = decltype(std::begin(std::declval<_Tp>())), typename = decltype(std::end(std::declval<_Tp>()))>
    constexpr auto enumerate(_Tp& __iterable, int __start = 0, int __step = 1);

    namespace adaptors
    {
        template <typename _Tp, typename _Up>
        struct enumerate_proxy;

        template <typename _Tp>
        auto enumerate(_Tp __offset = 0);

        template <typename _Container, typename _Tp, typename _Up>
        constexpr auto operator|(_Container const& __container, enumerate_proxy<_Tp, _Up> const& __proxy);
    }
}
```

An adaptor for creating an iterator and index pair in a for loop.

enumerate.hpp \\author Tyler Swann (oraqlle@github.com) \\version 1.0.0 \\date 2022-04-01

\\ingroup adaptors

\\copyright Copyright (c) 2022

### Function `cortex::enumerate`

``` cpp
template <typename _Tp, typename _Iterator = decltype(std::begin(std::declval<_Tp>())), typename = decltype(std::end(std::declval<_Tp>()))>
constexpr auto enumerate(_Tp& __iterable, int __start = 0, int __step = 1);
```

Moves a container to the iterable\_wrapper object.

-----

### Struct `cortex::adaptors::enumerate_proxy`

``` cpp
template <typename _Tp, typename _Up>
struct enumerate_proxy
{
};
```

proxy for adapting an index to an container.

-----

### Function `cortex::adaptors::enumerate`

``` cpp
template <typename _Tp>
auto enumerate(_Tp __offset = 0);
```

#### Parameters

  - `__offset` - \\return index proxy object with the offset value.

-----

### Function `cortex::adaptors::operator|`

``` cpp
template <typename _Container, typename _Tp, typename _Up>
constexpr auto operator|(_Container const& __container, enumerate_proxy<_Tp, _Up> const& __proxy);
```

operator| overload for piping the index\_proxy object returnd by indexed to the enumerate function.

#### Parameters

  - `__proxy` - \\return constexpr auto

-----
