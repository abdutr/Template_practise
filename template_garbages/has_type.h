#pragma once
#include <type_traits>

template<typename ,typename = std::void_t<>>
struct HasSizeType: std::false_type {};

template <typename T>
struct HasSizeType<T, std::void_t<typename T::size_type> > : std::true_type{};
