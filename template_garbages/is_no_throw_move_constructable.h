#pragma once
#include <type_traits>

template<typename T,typename = std::void_t<>>
struct IsNoThrowMoveConstructible : std::false_type{};

template<typename T>
struct IsNoThrowMoveConstructible<T, std::void_t<decltype(T(std::declval<T>()))>> : std::bool_constant<noexcept(T(std::declval<T>()))> {};