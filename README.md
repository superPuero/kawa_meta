# ⛓️‍💥 **kawa::meta**
---

A lightweight, header-only C++17+ library for compile-time type name introspection and hashing.

## Features

- Extracts human-readable type names at compile time
- Computes deterministic FNV-1a hashes for types and strings
- Cross-compiler support for Clang, GCC, and MSVC
- `type_info` utility struct for name/hash pairing

## Example

```cpp
#include "kawa_meta.hpp"

constexpr auto name = kawa::meta::type_name<int>(); // "int"
constexpr auto hash = kawa::meta::type_hash<int>();

static_assert(hash == kawa::meta::string_hash("int"));
