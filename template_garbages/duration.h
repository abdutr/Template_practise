#pragma once
#include <iostream>

template<unsigned N,unsigned Denom = 1>
struct Ratio {
	constexpr static unsigned num = N;
	constexpr static unsigned denom = Denom;

	using type = Ratio<N, Denom>;
};

template<typename R1,typename R2>
struct RatioAddImpl {
	constexpr static unsigned num = R1::num * R2::denom + R2::num * R1::denom;
	constexpr static unsigned denom = R1::denom * R2::denom;

	using type = Ratio<num, denom>;
};

template<typename R1, typename R2>
using RatioAdd = typename RatioAddImpl<R1, R2>::type;

template<typename T, typename U = Ratio<1>>
struct Duration {
	using ValueType = T;
	using RatioType = U;

	ValueType val;
	
	constexpr Duration(ValueType v = ValueType{}) : val{ v } {
	}

	constexpr ValueType value() const {
		return val;
	}

	void print() {
		std::cout << val << " Ratio: " << U::num << '/' << U::denom << std::endl;
	}
};

template<typename T1,typename U1, typename T2, typename U2>
constexpr auto operator+(Duration<T1,U1> dur1, Duration<T2, U2> dur2) {

	using ratio_type = Ratio<1, RatioAdd<U1, U2>::denom >;

	auto val = dur1.val * U1::num * U2::denom + dur2.val * U2::num * U1::denom;

	return Duration<decltype(val), ratio_type>(val);

	//RatioAdd<D1::RatioType, D2::RatioType>
}