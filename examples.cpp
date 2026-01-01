#include <iostream>

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
	using namespace kawa;
	
	std::cout << meta::type_name<meta::transform_each_t<std::remove_pointer_t, std::tuple<int*, float*>>>() << '\n';

	std::cout << meta::type_name<int>() << '\n';
	
	constexpr std::string_view name = meta::type_name<foo>();
	constexpr uint64_t hash = meta::type_hash<foo>();
	constexpr kawa::meta::type_info info(kawa::meta::construct_tag<int>{});

	static_assert(std::is_same_v<meta::function_traits<decltype(func)>::return_type, int>);

	constexpr std::string_view func2_arg_type_name = meta::type_name<meta::function_traits<decltype(func2)>::arg_at<0>>();

	std::cout << name << '\n';
	std::cout << hash << '\n';
	std::cout << info.name << '\n';
	std::cout << info.hash << '\n';
	std::cout << func2_arg_type_name << '\n';

	std::cin.get();
}																