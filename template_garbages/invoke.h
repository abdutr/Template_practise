#pragma once
#include <type_traits>
#include <utility>

template<typename Callable, typename... Args>
decltype(auto) call(Callable&& callable, Args&&... args) {
	return std::invoke(std::forward<Callable>(callable), std::forward<Args>(args)...);
}



template<typename T1, typename T2,
	typename RT = std::decay_t<decltype(true ? std::declval<T1>(): std::declval<T2>())>>
	RT max(T1 a, T2 b)
{

	return b < a ? a : b;

}

//template<typename T1, typename T2,
//
//	typename RT = std::decay_t<decltype(true? std::declval<T1>(): std::declval<T2>())>>
//
//	RT max2(T1 a, T2 b)
//
//{
//
//	return b < a ? a : b;
//
//}