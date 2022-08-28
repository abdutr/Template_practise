#pragma once
#include <string>

class Person {

public:
	std::string name;

	template<typename T,typename = std::enable_if_t<std::is_convertible_v<T,std::string>>>
	Person(T&& arg) :name{ std::forward<T>(arg) } {};

	//Person(Person const& P) {
	//	name = P.name;
	//}

	Person(Person const volatile& P) = delete;

	template<typename T,typename = std::enable_if_t<std::is_convertible_v<T,std::string>>>
	Person(T const& p) {

	}
};

class Person2 {

public:
	std::string name;

	template<typename T>
	requires std::is_convertible_v<T,std::string>
	Person2(T&& arg) :name{ std::forward<T>(arg) } {};

	//Person(Person const& P) {
	//	name = P.name;
	//}

	Person2(Person2 const volatile& P) = delete;

	//template<typename T>
	//requires std::is_convertible_v<T, Person2 >
	Person2(Person const& p) {

	}
};