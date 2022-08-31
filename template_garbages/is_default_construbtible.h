#pragma once
#include <type_traits>

template<typename,typename = std::void_t<>>
struct IsDefaultConstructible : std::false_type {

};

template<typename T>
struct IsDefaultConstructible<T,std::void_t<decltype(T())>> : std::true_type {

};