#pragma once
#include <type_traits>
template<typename T>
T& max(T&& a, T&& b) {
	return b > a ? b : a;
}

template<typename T1,typename T2>
auto max2(T1 a, T2 b) {
	return b > a ? b : a;
}

template<typename T1, typename T2,typename RT = std::common_type_t<T1,T2>>
RT max3(T1 a, T2 b) {
	return b > a ? b : a;
}

template<typename T>
constexpr T square3(T val) {
	return val * val;
}

template<auto val, typename Type = decltype(val) >
constexpr Type square4() {
	return val * val;
}