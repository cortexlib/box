# Cortex : { box }

[![Contributor Covenant](https://img.shields.io/badge/Contributor%20Covenant-2.1-4baaaa.svg)](CODE_OF_CONDUCT.md)

Box is a two dimensional generic container. It aims to provide expressive and dynamic operations that allow for easy fast mainpulation of the data's shape. Box is available under the `cortex::` namespace.

Box is built using the [BPT/DDS](https://github.com/vector-of-bool/dds) building tool. Click [here](https://dds.pizza) view the documentation and install instructions for BPT/DDS. BPT/DDS is a command line tool for managing dependencies and building applications in C++.

Box is part of a larger library called the [Cortex Library](https://github.com/cortexlib/cortexlib). You can include box independently in your project and only install box's dependencies or you can add the larger Cortex Library. Instructions are [here] (<- add link).

---

## Features

- STL complient with valid begin and end iterators.
- Row and Column iterators allowing traversal and manipulation of discrete parts of the box.
- Scalar and Box comparison operators.
- Builtin function mapping and mapping operator overload.
- Common arithmatic and bitwise transformation methods.
- Operator overloads for arithmatic and bitwise transformations for expressive notation.
- Restructuring methods that can change the data's structure.
- Custom allocator support similar to the STL generic containers.

---

## Overview



---

## Adding Box to your BPT/DDS Project

To add Box to your project is super simple. The first thing you need to do is add the repository that hosts the package. Box along with all of the cortexlib can be found on the [Trove Package Index](https://trovepi.dev). To add, simply run:

```sh
dds pkg repo add "https://trovepi.dev"
```

This will allow BPT/DDS to find the packages host by Trove. Once you've added the repo, go to your package.json5 file within your pojects directory and add box as a dependency.

```json
{
    name: 'package',
    version: 'x.x.x',
    namespace: 'project',
    test_driver: 'Tester',
    depends: [
        'cortex-box^1.0.0'
    ]
}
```

Finally, any library that uses Box needs to declare that it is in use. This is done in you project or individual libraries library.json5 file.

```json
{
    name: 'library',
    uses: [
        cortex/box
    ]
}
```

And you all set. On the next build run, BPT/DDS with install box and build against it.

## Contributing and License

- Refer to [CONTRIBUTING.md](./CONTRIBUTING.md) for ways to contribute and support the development of `cortex::box`.

- Box is under the MIT License. Refer to [LICENSE](./LICENSE) for full details.
