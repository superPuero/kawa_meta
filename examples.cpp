#include <iostream>

#include "meta.h"

struct foo {};

int main()
{
	constexpr std::string_view name = kawa::meta::type_name<foo>();
	constexpr uint64_t hash = kawa::meta::type_hash<foo>();
	constexpr kawa::meta::type_info info = kawa::meta::type_info::create<int>();

	std::cout << name << '\n';
	std::cout << hash << '\n';
	std::cout << info.name << '\n';
	std::cout << info.hash << '\n';
}																