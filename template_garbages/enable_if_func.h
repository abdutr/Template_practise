#pragma once
#include <type_traits>

template <typename T,typename = std::enable_if_t<std::is_same_v<T,uint64_t>>>
T do_some_bitmagic(T number) {
	return number;
}

template <typename T>
std::enable_if_t<std::is_same_v<T, uint64_t>,T> do_some_bitmagic2(T number) {
	return number;
}   