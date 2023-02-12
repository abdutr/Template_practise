#pragma once
#include <iterator>

template<typename it>
auto problematic_accumulate(it begin, it  end) {
	using it_value_type = typename std::iterator_traits<it>::value_type;
	it_value_type total{};
	while (begin != end) {
		total += *begin;
		++begin;
	}

	return total;
}

// Simple pointer accumulate
template<typename T>
T accum(T const* beg, T const* end)
{
	T total{};  // assume this actually creates a zero value

	while (beg != end) {
		total += *beg;
		++beg;
	}
	return total;
}

// This could cause overflow but we will be fine for that
template<typename T>
struct AccumulatorTraits {
	using AccumulationType = T;
};

template<>
struct AccumulatorTraits<char> {
	using AccumulationType = int;
};

template <typename T>
using AccumulatorTraits_t = typename AccumulatorTraits<T>::AccumulationType;

template<typename it>
auto better_accumulate(it begin, it  end) {
	using it_value_type = std::iterator_traits<it>::value_type;
	AccumulatorTraits_t<it_value_type> total{};
	while (begin != end) {
		total += *begin;
		++begin;
	}

	return total;
}

template<typename it,typename RealRT= AccumulatorTraits<typename std::iterator_traits<it>::value_type>::AccumulationType>
auto even_better_accumulate(it begin, it  end) {
	RealRT total{};
	while (begin != end) {
		total += *begin;
		++begin;
	}

	return total;
}

// Allows user to just call  even_better_accumulate<char>(begin_it,end_it)
// instead of even_better_accumulate<decltype(begin_it),char>(....)
template<typename RealRT,typename it = void>
auto even_better_accumulate(it&& begin, it&&  end) {
	return even_better_accumulate<it, RealRT>(std::forward<it>(begin),std::forward<it>(end));
}