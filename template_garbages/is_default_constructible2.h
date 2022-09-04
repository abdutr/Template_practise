#pragma once
#include <type_traits>

template <typename T>
struct IsDefaultConstructibleHelper {
private:
	template<typename >
	static std::false_type test(...);

	template<typename U,typename = decltype(U())>
	static std::true_type test(void*);

public:
	//constexpr bool value = decltype(test<T>(nullptr)) :value;
	using type = decltype(test<T>(nullptr));
};

template<typename T>
struct IsDefaultConstructible2 : IsDefaultConstructibleHelper<T>::type {

};