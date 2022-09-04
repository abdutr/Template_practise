#pragma once
#include <type_traits>

template<typename ,typename = std::void_t<>>
struct HasSizeType: std::false_type {};

template <typename T>
struct HasSizeType<T, std::void_t<typename T::size_type> > : std::true_type{};

template<typename left,typename right, typename = std::void_t<>>
struct HasLess : std::false_type {};

template<typename left, typename right>
struct HasLess<left,right,std::void_t<decltype(std::declval<left>() < std::declval<right>())>> : std::true_type {};

template<typename left, typename right>
constexpr auto HasLess_v = HasLess<left, right>::value;

template<typename T, typename = std::void_t<>>
struct IsContextualBool : std::false_type {};

template<typename T>
struct IsContextualBool<T, std::void_t<decltype(std::declval<T>() ? 0 : 1)>> : std::true_type {};  // Trick is ? operator

