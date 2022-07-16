# Cortex Library

[![Contributor Covenant](https://img.shields.io/badge/Contributor%20Covenant-2.1-4baaaa.svg)](CODE_OF_CONDUCT.md)
[![License](https://img.shields.io/github/license/cortexlib/box)](LICENSE)
![Current Release](https://img.shields.io/github/v/release/oraqlle/cortexlib)
![bpt Version](https://img.shields.io/badge/bpt%20version%3A-1.0.0--beta--1-blue)
![C++ Standard](https://img.shields.io/badge/C%2B%2B%20Standard-C%2B%2B20-red)
![GCC](https://img.shields.io/badge/GCC-11.1.0-yellow)
![Clang](https://img.shields.io/badge/clang-12.0.0-yellow)

## Welcome

Welcome to the Cortex Library. A collection of various smaller component libraries that implement a variety of different features from new containers, iterators, ranges, allocators, utility tools and more for C++20.

All of the sub-libraries are contained in the [`libs/`](libs/) directory at the package/repository root. All libraries are included with the `cortexlib` package.

Cortex Library is packaged and built using the [bpt](https://bpt.pizza) tool. To install bpt and go through a quick introduction, click [here](https://bpt.pizza/docs/latest/tut/install.html).

Cortex Library is available from [Trove](https://tropepi.dev) CRS repoository. Head to the [quick add](#quick-add) section for details to add `cortexlib`.

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
  - [Quick Start](#quick-start)
    - [Adding to _bpt.yaml_](#adding-to-bptyaml)
    - [Add Trove to Lookup](#add-trove-to-lookup)
  - [Documentation - _Beta_](#documentation---beta)
  - [Contributing and License](#contributing-and-license)
  - [Links and Resources](#links-and-resources)
    - [bpt](#bpt)
    - [Trove Package Index](#trove-package-index)
    - [Source Code](#source-code)
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
- Combinator Library - Combinator Patterns in C++

---

## Quick Start

To add the `cortexlib` package to an existing bpt project, you'll need to ensure that bpt knows to use it and knows where to find it.

### Adding to _bpt.yaml_

Adding cortex to yor project is simple. Simply add `cortexlib@`_`x.x.x`_` ` to the dependencies section of your projects ` `_`bpt.yaml`_` ` file.

If your project has multiple libraries and they use `cortexlib`, you'll have to declare in the ` `_`bpt.yaml`_` ` that those libraries uses use `cortexlib`. Information on libraries and bpt's library dependency management, look [here](https://bpt.pizza/docs/latest/guide/libraries.html).

For information on the ` `_`bpt.yaml`_` ` file's structure, take a look at the official documentation [here](https://bpt.pizza/docs/latest/guide/projects.html#the-project-bpt-yaml-file).

### Add Trove to Lookup

To ensure bpt knows where to look for `cortexlib` you'll need to use the `--use-repo=<`_`repo-URL`_`>` command with bpt's build command.

Cortexlib is hosted on the Trove Package Index. It's repository for URL is: [https://trovepi.dev](https://trovepi.dev). ANd example build command would be:

```sh
bpt build -t :c++20:gcc-11 --use-repo="https://trovepi.dev"
```

Note: You have to use the `--use-repo=`_`repo-URL`_` ` sub-command with every run of the build so the bpt know where to look.

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

Links to related tools and documentation of bpt, TrovePI and `cortexlib`'s source.

### bpt

- [bpt](https://bpt.pizza)
- [bpt Install Guide](https://bpt.pizza/docs/latest/tut/install.html)
- ['Hello World!' from bpt](https://bpt.pizza/docs/latest/tut/hello-world.html)
- [bpt.yaml](https://bpt.pizza/docs/latest/guide/projects.html#the-project-bpt-yaml-file)

### Trove Package Index

- [Trove Package Index Homepage](https://trovepi.dev)
- [Creating Your Own Project Package](https://trovepi.dev)
- [Submitting a package for Trove](https://trovepi.dev)

### Source Code

- [Cortex Library](https://github.com/cortexlib/cortexlib)
- [Documentation](https://github.com/cortexlib/cortexlib)

---

## Acknowledgement

## Disclaimers

bpt is currently an beta tool an thus is subject to change. As such, so is this package (as with any others). It is recommended you check the badge at the top of the this [README](#cortex-library) to see which version of bpt this package was built and tested against along with the relevent C++ standard and compiler imformation.
