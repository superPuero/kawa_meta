# ⛓️‍💥 **kawa::meta**

A lightweight, header-only C++17+ library for compile-time type name introspection and hashing.

## Features


- Extracts human-readable type names at compile time
- Function traits extracting
- Computes deterministic FNV-1a hashes for types and strings
- Cross-compiler support for Clang, GCC, and MSVC
- `type_info` utility struct for name/hash pairing

## Example

```cpp
#include "meta.h"

struct foo {};

int func(float&)
{
	return 42;
}

float func2(double)
{
	return 42.0f;
}

int main()
{
	namespace kmeta = kawa::meta;

	constexpr std::string_view name = kmeta::type_name<foo>();
	constexpr uint64_t hash = kmeta::type_hash<foo>();
	constexpr kawa::meta::type_info info = kmeta::type_info::create<int>();

	static_assert(std::is_same_v<kmeta::function_traits<decltype(func)>::return_type, int>);

	constexpr std::string_view func2_arg_type_name = kmeta::type_name<kmeta::function_traits<decltype(func2)>::arg_at<0>>();
}	
