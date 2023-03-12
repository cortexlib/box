# Cortex Library

[![Contributor Covenant](https://img.shields.io/badge/Contributor%20Covenant-2.1-4baaaa.svg)](CODE_OF_CONDUCT.md)
[![License](https://img.shields.io/github/license/cortexlib/box)](LICENSE)
![Current Release](https://img.shields.io/github/v/release/oraqlle/cortexlib?include_prereleases)
<!-- ![bpt Version](https://img.shields.io/badge/bpt%20version%3A-1.0.0--beta--1-blue)
![C++ Standard](https://img.shields.io/badge/C%2B%2B%20Standard-C%2B%2B20-red)
![GCC](https://img.shields.io/badge/GCC-11.1.0-yellow)
![Clang](https://img.shields.io/badge/clang-10.0.0-yellow) -->

## Welcome

A library full of random types, classes, functions and other general purpose utilities for C++.

Cortex is available from the CRS repository within [Code Bytes](https://codebytes.dev) . Head to the [Install](#install) section to get up and running.

---

## Contents

- [Cortex Library](#cortex-library)
  - [Welcome](#welcome)
  - [Contents](#contents)
  - [Features](#features)
  - [Example](#example)
  - [Install](#install)
  - [Contributing and License](#contributing-and-license)
  - [Supported and Tested Compilers](#supported-and-tested-compilers)
  - [Documentation](#documentation)

---

## Features

- Matrix - Generic, owning 2D array.
- Tensor - Generic, owning multidimensional array.
- Match Visitor - Match pattern to create conditional access to `std::variant`
- Allocator Library - A small set of allocators to offer different allocation techniques.

---

## Example

---

## Install

Add `cortexlib@0.1.2` to the 'dependencies' section of your `bpt.yaml` file. When running `bpt build`, use `--use-repo "trovepi.dev"` or `-r "trovepi.dev"` flag option to specify lookup through Trove.

---

## Contributing and License

- Refer to [CONTRIBUTING.md](CONTRIBUTING.md) for ways to contribute and support the development of cortexlib.
- The Cortex Library is under the MIT License. Refer to [LICENSE](LICENSE) for full details.
- This repository, it's contributors, maintainers and collaborators are governed by the `Contributor Covenant Code of Conduct v2.1` outlined in the [Code of Conduct](CODE_OF_CONDUCT.md) file.

---

## Supported and Tested Compilers

> Note: The `-std=c++20 must be used

- GCC-11.3.0
- Clang-15.0.6

---

## Documentation

- [Docs](/docs/README.md)
