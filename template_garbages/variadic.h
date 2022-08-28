#pragma once
#include <iostream>

void print() {}

template<typename T,typename... Types>
void print(T firstArg, Types... args) {
	std::cout << firstArg << std::endl;
	print(args...);
}

template <typename... Types>
auto sum(Types... args) {
	return (... + args);
}


struct Node {

	int value;

	Node* left;

	Node* right;

	Node(int i = 0) : value(i), left(nullptr), right(nullptr) {

	}

};

auto left = &Node::left;

auto right = &Node::right;

template<typename T,typename... TP>
Node* traverse(T np, TP... paths) {

	return (np ->* ... ->* paths); // np ->* paths1 ->* paths2 …

}

// This works but has drawbacks:
// Return type is assumed string
// You need new string creation, inefficient
//template<typename T>
//std::string AddSpaceNewline(T &arg) {
//	return arg + std::string{ " " };
//}

template<typename T>
class AddSpace
{
private:
	T const& ref;                  // refer to argument passed in constructor
public:
	AddSpace(T const& r) : ref(r) {
	}
	friend std::ostream& operator<< (std::ostream& os, AddSpace<T> s) {
		return os << s.ref << ' ';   // output passed argument and a space
	}

};


template<typename... Types>
void print2(Types const& ... args)
{
	//(std::cout << ... << AddSpaceNewline(args)) <<'\n';
	(std::cout << ... << AddSpace(args)) <<'\n'; // C++17
	//(std::cout << ... << AddSpace<Types>(args)) <<'\n'; // C++ < 17
}

template<typename... Types>
void printDoubled(Types const&... args) {
	return print2(args + args...);
}



template<typename... Types>
void func(Types&... input) {
	std::ignore = input;
}

template<typename T,typename... TN>
constexpr bool is_homogenous(T, TN...) {
	return (std::is_same_v<T, TN> && ...);  
	// (pack op ...) -> std::is_same_v<T, T1> && (std::is_same_v<T1, T2> && (std::is_same_v<T2, T3> && ...))
	//			 or?? : std::is_same_v<T, T1> && (std::is_same_v<T , T2> && (std::is_same_v<T , T3> && ...))
}

template<typename C, typename... Idx>
void printElems(C const& coll, Idx... idx)
{
	print(coll[idx]...);
}

struct InitTest {
	int x;
	int y{};
};