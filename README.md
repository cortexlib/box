# Cortex

<a href="CODE_OF_CONDUCT.md"><img src="https://img.shields.io/badge/Contributor%20Covenant-2.1-4baaaa.svg" alt="Contributor Covenant"></a>
<a href="LICENSE"><img src="https://img.shields.io/github/license/oraqlle/cortexlib" alt="License"></a>
<img src="https://img.shields.io/github/v/release/oraqlle/cortexlib?include_prereleases" alt="Current Release">

A library of general purpose types, classes, functions, algorithms, utilities and other components for C++.

---

## Contents

- [Cortex](#cortex)
  - [Contents](#contents)
  - [Development Status](#development-status)
  - [Install](#install)
  - [Contributing and License](#contributing-and-license)
  - [Supported Compilers](#supported-compilers)
  - [Features](#features)
    - [Containers](#containers)
      - [List of Containers](#list-of-containers)
    - [Iterators](#iterators)
      - [List of Iterators](#list-of-iterators)
    - [Utilities](#utilities)
      - [List of Utilities](#list-of-utilities)

## Development Status

Cortex is pretty unstable and currently undergoes regular changes. It also has limited testing meaning that meaning it could break. There is no promise for long-term support and may evolve without regard to backwards compatibility. That being said I do plan to stabilise the library more with time.

## Install

Cortex is available from the [CodeBytes](https://codebytes.netlify.app) CRS repository. Simply add `cortexlib@0.2.0` to the 'dependencies' section of your `bpt.yaml` file. When running `bpt build`, use `--use-repo "codebytes.netlify.app"` or `-r "codebytes.netlify.app"` flag option to specify lookup through CodeBytes.

Cortex is broken down into three separate sub-libraries. These being:

- **containers/. . .**
- **iterators/. . .**
- **utilities/. . .**

To use any component from these library simply `#include` the relevant header prefixed with the library eg. `#include <data_structures/matrix.hxx>`

## Contributing and License

- Refer to [CONTRIBUTING.md](CONTRIBUTING.md) for ways to contribute and support the development of Cortex.
- Cortex is under the MIT License. Refer to [LICENSE](LICENSE) for full details.
- This repository, it's contributors, maintainers and collaborators are governed by the `Contributor Covenant Code of Conduct v2.1` outlined in the [Code of Conduct](CODE_OF_CONDUCT.md) file.

## Supported Compilers

> Note: The `-std=c++20 must be used

- GCC-11.3.0
- Clang-15.0.6

---

## Features

Cortex is a library with a bunch of random components from different data structures and algorithms to concurrency tools and general utilities. Everything in Cortex is kept within the `cxl` namespace.

### Containers

Cortex features a few unique, general purpose container types designed to compliment the existing C++ standard library containers and algorithms.

#### List of Containers

- `cxl::matrix` - Generic, owning 2D array.
- `cxl::tensor` - Generic, owning multidimensional array (in dev).

### Iterators

Iterators library is designed to compliment the containers library and offer different traversal patterns across various data structures.

#### List of Iterators

- `cxl::normal_iterator` - A iterator that adapts non-object iterators (pointers) into object iterators while keeping the original entities semantics.

### Utilities

Cortex's utilities library contains various general purpose utility objects and types.

#### List of Utilities

- `cxl::utils::match` - A visitor object type allowing for conditional access to a `std::variant`.
- `cxl::utils::match_any` - A type which acts as the base fallthrough match for a match expression.
