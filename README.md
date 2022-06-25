# Cortex Library

[![Contributor Covenant](https://img.shields.io/badge/Contributor%20Covenant-2.1-4baaaa.svg)](CODE_OF_CONDUCT.md)
[![License](https://img.shields.io/github/license/cortexlib/box)](LICENSE)
![Current Release](https://img.shields.io/github/v/release/cortexlib/box)
![DDS Version](https://img.shields.io/badge/DDS%20Version-alpha--6-blue)
![C++ Standard](https://img.shields.io/badge/C%2B%2B%20Standard-C%2B%2B20-red)
![GCC](https://img.shields.io/badge/GCC-11.1.0-yellow)
![Clang](https://img.shields.io/badge/Clang-❌-yellow)

## Welcome

Welcome to the Cortex Library. A collection of various smaller component libraries that implement a variety of different features from new containers, iterators, ranges, allocators, utility tools and more.

All of the sub-libraries are contained in the [`libs/`](libs/) directory at the package/repository root. All libraries are included with the `cortexlib` package.

Cortex Library is packaged and built using the [DDS](https://dds.pizza) tool. To install DDS and go through a quick introduction, click [here](https://dds.pizza/docs/tut/index.html).

Cortex Library is available from [Trove](https://tropepi.dev). If you're already familar with DDS and Trove you can follow the instructions in the [quick add](#quick-add) section.

The bottom of this README has a full list of resources related to this package.

If you have any qustions regarding the Cortex Library, feel free to open a discussion on GitHub and I will answer as promptly as I can.

---

## Contents

- [Cortex Library](#cortex-library)
  - [Welcome](#welcome)
  - [Contents](#contents)
  - [Libraries](#libraries)
    - [Released](#released)
    - [_Comming Soon_](#comming-soon)
  - [Quick Add](#quick-add)
  - [Using Cortex's Libraries](#using-cortexs-libraries)
  - [Documentation - _Beta_](#documentation---beta)
  - [Contributing and License](#contributing-and-license)
  - [Links and Resources](#links-and-resources)
  - [Acknowledgement](#acknowledgement)
  - [Disclaimers](#disclaimers)

---

## Libraries

Here is the full list of both the released and upcomming sub-libraries available within the Cortex Library

### Released

- [Iterators Library](libs/iterators/README.md) - Includes various different types of iterators including two dimensional row and column iterators.
- [Box Library](libs/iterators/README.md) - A generic two dimensional container.
- [Concepts Library](libs/concepts/README.md) - A small library formally defining various types of concepts.

[//]: # "### In Beta"
[//]: # "- "

### _Comming Soon_

- Allocators Library - Various types of allocators to provide more custom and precise control over memory management.
- Literals Library - A unique set of literal types that allow for shorter more concise syntax.

---

## Quick Add

To add the `cortexlib` package to an existing DDS project, ensure you have [Trove](https://trovepi.dev) add to the package repo list for dds. Run the following command to check:

```sh
$ dds pkg repo ls
...

Remote 'Trove-Package-Index':
  Updates URL: https://trovepi.dev/

...
```

You should see 'Trove-Package-Index' listed as a remote similar to above.

In your `package.json5` add `cortexlib@1.0.0`* to the `depends` list element. This declares that your package is using the `cortexlib`.

*Note: ` `_`name`_`@1.0.0` means use only version 1.0.0 of a package but you can use fuzzy versioning. The related DDS docs are [here](https://dds.pizza/docs/guide/interdeps.html#compatible-range-specifiers).

---

## Using Cortex's Libraries

To use a library from from the `cortexlib` package, you have to declare it in any `library.json5` files correlated to your packages libraries. For example, to add the box library within your project, in the correlating `library.json5` file you would add:

```json5
{
    name: 'my-lib',
    uses: [
        other-package-namespace/other-lib,
        cortex/box
    ]
}
```

This will instruct DDS how to link your project together.

All sub-libraries within the `cortexlib` package are under the `cortex` package namespace (not related to a C++ namespace), thus you can add any sub-library by using th following pattern: `cortex/lib-name`.

---

## Documentation - _Beta_

The full set of documentation can be found in the [docs/](docs/) directory.

---

## Contributing and License

- Refer to [CONTRIBUTING.md](CONTRIBUTING.md) for ways to contribute and support the development of `cortex::box`.
- The Cortex Library is under the MIT License. Refer to [LICENSE](LICENSE) for full details.
- This repository, it's contributors, maintainers and collaborators are to follow the `Contributor Covenant Code of Conduct v2.1` outlined in the [Code of Conduct](CODE_OF_CONDUCT.md) file.

---

## Links and Resources

- [DDS](https://dds.pizza)
- [DDS Install Guide](https://dds.pizza/docs/tut/install.html)
- [Trove Package Index Homepage](https://trovepi.dev)
- [Cortex Library](https://github.com/cortexlib/cortexlib)
- [Creating Your Own Package](https://trovepi.dev)
- [Submitting a package for Trove](https://trovepi.dev)

---

## Acknowledgement

## Disclaimers

DDS is currently an alpha tool an thus is subject to change. As such, so is this package (as with any others). It is recommended you check the badge at the top of the this [README](#cortex-library) to see which version of DDS this package was built and tested against along with the relevent C++ standard and compiler imformation.
