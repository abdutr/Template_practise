#pragma once
#include <type_traits>
#include<string>
#include<iostream>
#include<map>

template< template<typename, typename> class Cont = std::map ,typename Key_type,typename Value_type>
void print_cont(Cont<Key_type, Value_type> key_value_cont) {
	static_assert(std::is_convertible_v<Key_type, std::string>, "Cant convert key type to String");
	static_assert(std::is_convertible_v<Value_type, std::string>, "Cant convert value type to String");
	for (const auto& [key, value] : key_value_cont) {
		std::cout << "Key"<< key <<  "Value" << value <<"\n" ;
	}
}


//template<typename Key_type, typename Value_type, template<typename tt1, typename tt2> class Cont = std::map<tt1, tt2,...>>
//void print_cont2(const Cont<Key_type,Value_type>& key_value_cont) {
//	static_assert(std::is_convertible_v<Key_type, std::string>, "Cant convert key type to String");
//	static_assert(std::is_convertible_v<Value_type, std::string>, "Cant convert value type to String");
//	for (const auto& [key, value] : key_value_cont) {
//		std::cout << "Key" << key << "Value" << value << "\n";
//	}
//}