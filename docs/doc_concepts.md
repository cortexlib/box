# Header file `concepts.hpp`

``` cpp
#define CORTEX_CONCEPTS_H

namespace cortex
{
    template <typename _Tp>concept Any = true;

    template <typename _Tp>concept None = false;

    template <typename _Tp>concept Number = std::integral<_Tp> || std::floating_point<_Tp>;

    template <typename _Tp>concept Object = std::is_object_v<_Tp>;

    template <typename _Lt, typename _Rt>concept AddableWith = requires(_Lt __lhs, _Rt __rhs){__lhs+__rhs;};

    template <typename _Tp>concept Addable = requires(_Tp __lhs, _Tp __rhs){__lhs+__rhs;};

    template <typename _Lt, typename _Rt>concept SubtractableWith = requires(_Lt __lhs, _Rt __rhs){__lhs-__rhs;};

    template <typename _Tp>concept Subtractable = requires(_Tp __lhs, _Tp __rhs){__lhs-__rhs;};

    template <typename _Lt, typename _Rt>concept MultiplicableWith = requires(_Lt __lhs, _Rt __rhs){__lhs*__rhs;};

    template <typename _Tp>concept Multiplicable = requires(_Tp __lhs, _Tp __rhs){__lhs*__rhs;};

    template <typename _Lt, typename _Rt>concept DivisibleWith = requires(_Lt __lhs, _Rt __rhs){__lhs / __rhs;};

    template <typename _Tp>concept Divisible = requires(_Tp __lhs, _Tp __rhs){__lhs / __rhs;};

    template <typename _Lt, typename _Rt>concept ModuloWith = requires(_Lt __lhs, _Rt __rhs){__lhs % __rhs;};

    template <typename _Tp>concept Modulo = requires(_Tp __lhs, _Tp __rhs){__lhs % __rhs;};

    template <typename _Lt, typename _Rt>concept BitXorWith = requires(_Lt __lhs, _Rt __rhs){__lhs ^ __rhs;};

    template <typename _Tp>concept BitXor = requires(_Tp __lhs, _Tp __rhs){__lhs ^ __rhs;};

    template <typename _Lt, typename _Rt>concept BitAndWith = requires(_Lt __lhs, _Rt __rhs){__lhs&__rhs;};

    template <typename _Tp>concept BitAnd = requires(_Tp __lhs, _Tp __rhs){__lhs&__rhs;};

    template <typename _Lt, typename _Rt>concept BitOrWith = requires(_Lt __lhs, _Rt __rhs){__lhs | __rhs;};

    template <typename _Tp>concept BitOr = requires(_Tp __lhs, _Tp __rhs){__lhs | __rhs;};

    template <typename _Lt, typename _Rt>concept LeftBitShiftWith = requires(_Lt __lhs, _Rt __rhs){__lhs<<__rhs;};

    template <typename _Tp>concept LeftBitShift = requires(_Tp __lhs, _Tp __rhs){__lhs<<__rhs;};

    template <typename _Lt, typename _Rt>concept RightBitShiftWith = requires(_Lt __lhs, _Rt __rhs){__lhs>>__rhs;};

    template <typename _Tp>concept RightBitShift = requires(_Tp __lhs, _Tp __rhs){__lhs>>__rhs;};

    template <typename _Tp>concept BitNot = requires(_Tp __val){~__val;};

    template <typename _Container, typename _Index>concept Subscriptible = requires{requires Object<_Container> || std::is_array_v<_Container> || std::is_pointer_v<_Container>;} && requires(_Container __container, _Index __index){__container[__index];};

    template <typename _Func, typename..._Arg>concept Invocable = std::is_invocable_v<_Func, _Arg...>;
}
```

Some generalised concepts for use throughout the Cortex Library

Author: Tyler Swann (oraqlle@github.com)

Header Version: v1.0.1

Date: 25-06-2022

License: MIT

Copyright: Copyright (c) 2022

concepts.hpp

### Unexposed entity `cortex::AddableWith`

``` cpp
template <typename _Lt, typename _Rt>concept AddableWith = requires(_Lt __lhs, _Rt __rhs){__lhs+__rhs;};
```

AddableWith Concept

Determines if two (potentially different) types are within the domain of operation for the addition operation.

-----

### Unexposed entity `cortex::Addable`

``` cpp
template <typename _Tp>concept Addable = requires(_Tp __lhs, _Tp __rhs){__lhs+__rhs;};
```

Addable Concept

Determines if a type is within the domain of operation for the addition operation.

-----

### Unexposed entity `cortex::SubtractableWith`

``` cpp
template <typename _Lt, typename _Rt>concept SubtractableWith = requires(_Lt __lhs, _Rt __rhs){__lhs-__rhs;};
```

SubtractableWith Concept

Determines if two (potentially different) types are within the domain of operation for the subtraction operation.

-----

### Unexposed entity `cortex::Subtractable`

``` cpp
template <typename _Tp>concept Subtractable = requires(_Tp __lhs, _Tp __rhs){__lhs-__rhs;};
```

Subtractable Concept

Determines if a type is within the domain of operation for the subtraction operation.

-----

### Unexposed entity `cortex::MultiplicableWith`

``` cpp
template <typename _Lt, typename _Rt>concept MultiplicableWith = requires(_Lt __lhs, _Rt __rhs){__lhs*__rhs;};
```

MultiplicableWith Concept

Determines if two (potentially different) types are within the domain of operation for the multiplication operation.

-----

### Unexposed entity `cortex::Multiplicable`

``` cpp
template <typename _Tp>concept Multiplicable = requires(_Tp __lhs, _Tp __rhs){__lhs*__rhs;};
```

Multiplicable Concept

Determines if a type is within the domain of operation for the multiplication operation.

-----

### Unexposed entity `cortex::DivisibleWith`

``` cpp
template <typename _Lt, typename _Rt>concept DivisibleWith = requires(_Lt __lhs, _Rt __rhs){__lhs / __rhs;};
```

DivisibleWith Concept

Determines if two (potentially different) types are within the domain of operation for the division operation.

-----

### Unexposed entity `cortex::Divisible`

``` cpp
template <typename _Tp>concept Divisible = requires(_Tp __lhs, _Tp __rhs){__lhs / __rhs;};
```

Divisible Concept

Determines if a type is within the domain of operation for the division operation.

-----

### Unexposed entity `cortex::ModuloWith`

``` cpp
template <typename _Lt, typename _Rt>concept ModuloWith = requires(_Lt __lhs, _Rt __rhs){__lhs % __rhs;};
```

ModuloWith Concept

Determines if two (potentially different) types are within the domain of operation for the modulus operation.

-----

### Unexposed entity `cortex::Modulo`

``` cpp
template <typename _Tp>concept Modulo = requires(_Tp __lhs, _Tp __rhs){__lhs % __rhs;};
```

Modulo Concept

Determines if a type is within the domain of operation for the modulus operation.

-----

### Unexposed entity `cortex::BitXorWith`

``` cpp
template <typename _Lt, typename _Rt>concept BitXorWith = requires(_Lt __lhs, _Rt __rhs){__lhs ^ __rhs;};
```

BitXorWith Concept

Determines if two (potentially different) types are within the domain of operation for the bitwise `exclusive-or` (`xor`) operation.

-----

### Unexposed entity `cortex::BitXor`

``` cpp
template <typename _Tp>concept BitXor = requires(_Tp __lhs, _Tp __rhs){__lhs ^ __rhs;};
```

BitXor Concept

Determines if a type is withinthe domain of operation for the bitwise `exclusive-or` (`xor`) operation.

-----

### Unexposed entity `cortex::BitAndWith`

``` cpp
template <typename _Lt, typename _Rt>concept BitAndWith = requires(_Lt __lhs, _Rt __rhs){__lhs&__rhs;};
```

BitAndWith Concept

Determines if two (potentially different) types are within the domain of operation for the bitwise `and` operation.

-----

### Unexposed entity `cortex::BitAnd`

``` cpp
template <typename _Tp>concept BitAnd = requires(_Tp __lhs, _Tp __rhs){__lhs&__rhs;};
```

BitAnd Concept

Determines if a type is withinthe domain of operation for the bitwise `and` operation.

-----

### Unexposed entity `cortex::BitOrWith`

``` cpp
template <typename _Lt, typename _Rt>concept BitOrWith = requires(_Lt __lhs, _Rt __rhs){__lhs | __rhs;};
```

BitOrWith Concept

Determines if two (potentially different) types are within the domain of operation for the bitwise `or` operation.

-----

### Unexposed entity `cortex::BitOr`

``` cpp
template <typename _Tp>concept BitOr = requires(_Tp __lhs, _Tp __rhs){__lhs | __rhs;};
```

BitOr Concept

Determines if a type is withinthe domain of operation for the bitwise `or` operation.

-----

### Unexposed entity `cortex::LeftBitShiftWith`

``` cpp
template <typename _Lt, typename _Rt>concept LeftBitShiftWith = requires(_Lt __lhs, _Rt __rhs){__lhs<<__rhs;};
```

LeftBitShiftWith Concept

Determines if two (potentially different) types are within the domain of operation for the bitwise `or` operation.

-----

### Unexposed entity `cortex::LeftBitShift`

``` cpp
template <typename _Tp>concept LeftBitShift = requires(_Tp __lhs, _Tp __rhs){__lhs<<__rhs;};
```

LeftBitShift Concept

Determines if a type is withinthe domain of operation for the `left bitwise shift` operation.

-----

### Unexposed entity `cortex::RightBitShiftWith`

``` cpp
template <typename _Lt, typename _Rt>concept RightBitShiftWith = requires(_Lt __lhs, _Rt __rhs){__lhs>>__rhs;};
```

RightBitShiftWith Concept

Determines if two (potentially different) types are within the domain of operation for the bitwise `or` operation.

-----

### Unexposed entity `cortex::RightBitShift`

``` cpp
template <typename _Tp>concept RightBitShift = requires(_Tp __lhs, _Tp __rhs){__lhs>>__rhs;};
```

RightBitShift Concept

Determines if a type is withinthe domain of operation for the `right bitwise shift` operation.

-----

### Unexposed entity `cortex::BitNot`

``` cpp
template <typename _Tp>concept BitNot = requires(_Tp __val){~__val;};
```

BitNot Concept

Checks if a type is within the domain of operation for the bitwise `not` operation.

-----

### Unexposed entity `cortex::Subscriptible`

``` cpp
template <typename _Container, typename _Index>concept Subscriptible = requires{requires Object<_Container> || std::is_array_v<_Container> || std::is_pointer_v<_Container>;} && requires(_Container __container, _Index __index){__container[__index];};
```

Subscriptible Concept

Determines if a type is within the domain of operation for the increment operation.

-----

### Unexposed entity `cortex::Invocable`

``` cpp
template <typename _Func, typename..._Arg>concept Invocable = std::is_invocable_v<_Func, _Arg...>;
```

Invokable

Determines if function type is invokable. Utilises the template meta-programming struct std::is\_invokable\_v

-----
