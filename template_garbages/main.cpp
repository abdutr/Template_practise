#include <tuple>
#include <set>
#include <vector>

#include "max.h"
#include "stack.h"
#include "stack2.h"
#include "tree.h"
#include "variadic.h"
#include "array_printer.h"
#include "template_variables.h"
#include "perfect_forwarding.h"
#include "is_prime.h"
#include "is_prime_old.h"
#include "basic_experiments.h"
#include "invoke.h"
#include "bridge_pattern_polymorphy.h"
#include "enable_if_func.h"
#include "accumulate.h"
#include "advance.h"
#include "is_default_construbtible.h"
#include "is_default_constructible2.h"
#include "has_type.h"
#include "crtp_object_counter.h"
#include "crtp_equality_comparable.h"
#include "curious_mixin.h"
#include "mixins.h"
#include "duration.h"
#include "sqrt_old.h"

extern char const s03[] = "hi";    // external linkage
char const s11[] = "hi2";           // internal linkage
auto main()->int {
	auto ret_val = max(3, 5);
	auto ret_val2 = max2(3, 5.7);
	auto ret_val3 = max3(43, 6.7);

	auto sqr1{ square3(5) };
	auto sqr2{ square4<10>() };

	Stack<int> int_stack;
	Stack<int> int_stack2{ 2 };
	int_stack.push(3);
	int_stack.push(4);
	int_stack.push(5);

	std::cout << int_stack << std::endl;
	Stack string_stack{ "Test" };
	//string_stack.push("Hahaha");
	std::cout << square<int,5>() << std::endl;
	std::cout << square<int,25>() << std::endl;
	std::cout << square<int>() << std::endl;

	std::cout << square2<7>() << std::endl;
	static char const*  text{ "HAHAHAHA" };
	static char const  text2[]{ "HAHAHAHA" };
	print<s03>();
	print<s11>();
	//print<text>(); // Does not work
	print<text2>();
	//for (auto idx{ 0 }; idx < 1000000; ++idx) {
	TreeNode<int> tree{ 3 };
	tree.add_child(4);
	tree.add_child(5);
	tree.add_child(6);
	tree.add_child(7);

	auto child_node = tree.childs[3].get();
	child_node->add_child(8);
	child_node->add_child(9);
	child_node->add_child(10);
	//}


	print("Ahaha ", 5, std::string{ "head" });
	auto sumval = sum(3, 4, 5.9, 2u);

	Node* root = new Node{ 0 };
	root->left = new Node{ 1 };
	root->left->right = new Node{ 2 };

	Node* node = traverse(root, left, right);

	print2("Doctor", std::string{ "What is this" });
	printDoubled(7.5, std::string{ "What is this" });
	
	int x{};
	print(x);


	InitTest test;
	print(test.x, test.y);
	array_printer_test_func();

	print("Pi values");
	print(pi<int>);
	print(pi<float>);
	print(pi<double >);

	variable_temp_test<int> = 5;
	variable_temp_test<double> = 2.345;
	print(variable_temp_test<int>);
	print(variable_temp_test<double>);
	
	arr<5>[0] = 1;

	Stack2<int, std::vector> stack_v2;

	Person2 p2{ "Haha" };

	auto is5prime{ IsPrime_old<5>::value };
	auto is3prime{ IsPrime_old<3>::value };
	auto is16prime{ IsPrime_old<16>::value };

	constexpr bool new_is9prime{ IsPrime(9) };
	constexpr bool new_is13prime{ IsPrime(13) };
	constexpr bool new_is2prime{ IsPrime(2) };
	constexpr bool new_is3prime{ IsPrime(3) };
	constexpr bool new_is1prime{ IsPrime(1) };


	int arr[] ={ 1,2,3,4,5 };
	int *arr_ptr = arr;
	ref_test(arr_ptr, 5);

	call([]() {std::cout << "Haha\n"; });
	call([](std::string str) {std::cout << str << '\n'; }," XD");

	Interface interf1{ Implementation1{} };
	Interface<Implementation1> interf1_2{ Implementation1{} };
	Interface interf2{ Implementation2{} };

	interf1.operationA();
	interf2.operationA();

	//do_some_bitmagic(5);
	//do_some_bitmagic2(5);
	do_some_bitmagic(5ull);
	do_some_bitmagic2(5ull);



	std::vector<uint64_t> numbers{ 1,2,3,4,5 };
	std::vector<char> chars{ 'a','2','c','4','e'};
	int numbers2[]{ 1,2,3,4,5 };
	auto sum = problematic_accumulate(numbers.begin(), numbers.end());
	auto sum2 = accum(numbers2, numbers2 +5);
	auto sum3 = better_accumulate(chars.begin(), chars.end());
	auto sum4 = better_accumulate(numbers.begin(), numbers.end());
	auto sum5 = even_better_accumulate<char>(chars.begin(), chars.end());
	auto sum6 = even_better_accumulate<int>(numbers.begin(), numbers.end());

	auto random_access_begin_it{ numbers.begin() };
	Advance(random_access_begin_it, 3);

	std::set<int> int_set{ 1,2,3,4,5 };
	auto forward_access_begin_it{ int_set.begin() };
	Advance(forward_access_begin_it,2);

	random_access_begin_it = numbers.begin();
	forward_access_begin_it =  int_set.begin() ;
	Advance_cpp17(random_access_begin_it, 3);
	Advance_cpp17(forward_access_begin_it, 3);
	
	constexpr auto is_int_def_constructable = IsDefaultConstructible<int>::value;
	constexpr auto is_int_ref_def_constructable = IsDefaultConstructible<int&>::value;
	constexpr auto is_int_def_constructable2 = IsDefaultConstructible2<int>::value;
	constexpr auto is_int_ref_def_constructable2 = IsDefaultConstructible2<int&>::value;

	auto vector_of_char_has_size = HasSizeType<decltype(chars)>::value;
	auto arr_of_int_has_size = HasSizeType<decltype(arr)>::value;

	auto has_int_uint_has_less = HasLess_v<int, uint32_t>;
	auto has_int_string_has_less = HasLess_v<int, std::string>;

	auto is_int_contextual_bool = IsContextualBool<int>::value;
	auto is_string_contextual_bool = IsContextualBool<std::string>::value;
	auto is_init_test_contextual_bool = IsContextualBool<InitTest>::value;


	// Crtp

	auto crtp_my_string{ MyString<char>() };
	MyString<char> crtp_my_string2;
	MyString<char> crtp_my_string3;
	MyString<int> crtp_my_string4;

	auto mystring_char_count = MyString<char>::alive_object_count();
	auto mystring_int_count = MyString<int>::alive_object_count();
	auto mystring_uint16_count = MyString<uint16_t>::alive_object_count();

	SimpleClass simp_cl{ 5 };
	SimpleClass simp_cl2{ 2 };
	bool are_simp_objects_not_equal{ simp_cl != simp_cl2 };
	bool are_same_objects_not_equal{ simp_cl != simp_cl };

	// Mixin Point inheriting Label and Color
	Point<Label, Color> p(1, 2);
	auto blue_val = p.blue;
	auto point_label = p.label;

	Point2<Label2, Color2> point2(3, 4);
	auto blue_val2 = point2.blue;
	auto point_label2 = point2.label;

	using ratio1 = Ratio<3, 5>;
	using ratio2 = Ratio<2, 9>;
	using sum_temp = RatioAdd<ratio1, ratio2>;
	auto ratio_num = sum_temp::num;
	auto ratio_denom = sum_temp::denom;

	Duration<int, Ratio<3, 5>> D1{ 3 };
	Duration<int, Ratio<2, 7>> D2{ 3 };
	auto D3 = D1 + D2;
	D3.print();

	auto sqrt_of_5{ sqrt_v<5> } ;
	auto sqrt_of_9{ sqrt_v<9> } ;
	auto sqrt_of_16{ sqrt_v<16> } ;
	auto sqrt_of_20{ sqrt_v<20> } ;

	std::ignore = x;
}
