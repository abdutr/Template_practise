#pragma once
#include <type_traits>

template<typename FROM, typename TO, bool = std::is_void_v<TO>
	|| std::is_array_v<TO>
	|| std::is_function_v<TO>>
struct IsConvertibleHelper {
	using Type = std::integral_constant<bool,
		IsVoidT<TO>::value
		&& IsVoidT<FROM>::value>;
};

template <typename FROM,typename TO>
class IsConvertibleHelper {

	static void aux(TO);

	template <typename F, typename = decltype(aux(std::declval<F>()))>
	static std::true_type test(void*);

	template <typename F>
	static std::false_type test(...);

public:
	using Type = decltype(test<FROM>(nullptr));
};

template <typename FROM,typename TO>
class IsConvertible : IsConvertibleHelper<FROM,TO>::Type{};