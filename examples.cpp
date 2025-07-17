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

#include <tuple>
#include <utility>
#include <type_traits>

template <typename Tuple, template <typename> class Transform>
constexpr auto transfrom_tuple_impl()
{
	return[]<size_t... I>(std::index_sequence<I...>)
	{
		return std::make_tuple(Transform<std::tuple_element_t<I, Tuple>>{}...);
	}(std::make_index_sequence<std::tuple_size_v<Tuple>>{});
}

template <typename Tuple>
struct transform_tuple
{
	template<template <typename> class Transform>
	using with = decltype(transfrom_tuple_impl<Tuple, Transform>());
};


struct Foo
{
	int x;
};

constexpr Foo f(42);
constexpr int v = f.x;

int main()
{
	using namespace kawa::meta;

	std::cout << type_name<transform_tuple<std::tuple<int*, float*>>::with<std::remove_pointer_t>>() << '\n';

	std::cout << type_name<int>() << '\n';

	constexpr std::string_view name = type_name<foo>();
	constexpr uint64_t hash = type_hash<foo>();
	constexpr kawa::meta::type_info info = kawa::meta::type_info::create<int>();

	static_assert(std::is_same_v<function_traits<decltype(func)>::return_type, int>);

	constexpr std::string_view func2_arg_type_name = type_name<function_traits<decltype(func2)>::arg_at<0>>();

	std::cout << name << '\n';
	std::cout << hash << '\n';
	std::cout << info.name << '\n';
	std::cout << info.hash << '\n';
	std::cout << func2_arg_type_name << '\n';

	std::cin.get();
}																