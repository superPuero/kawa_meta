#include <iostream>

#include "meta.h"

struct foo {};

int func(float&)
{
	return 42;
}

float func2(double)
{
	return 42;
}

int main()
{
	namespace kmeta = kawa::meta;

	constexpr std::string_view name = kmeta::type_name<foo>();
	constexpr uint64_t hash = kmeta::type_hash<foo>();
	constexpr kawa::meta::type_info info = kmeta::type_info::create<int>();

	static_assert(std::is_same_v<kmeta::function_traits<decltype(func)>::return_type, int>);

	constexpr std::string_view func2_arg_type_name = kmeta::type_name<kmeta::function_traits<decltype(func2)>::arg_at<0>>();

	std::cout << name << '\n';
	std::cout << hash << '\n';
	std::cout << info.name << '\n';
	std::cout << info.hash << '\n';
	std::cout << func2_arg_type_name << '\n';

	std::cin.get();
}																