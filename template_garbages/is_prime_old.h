#pragma once

template<unsigned p,unsigned d>
struct DoIsPrime {
	static constexpr  bool value = (p % d != 0) && DoIsPrime<p, d - 1>::value;
};

template<unsigned p>
struct DoIsPrime<p,2> {
	static constexpr  bool value = (p % 2 != 0) ;
};


template <unsigned d>
struct IsPrime_old {
	static constexpr  bool value = DoIsPrime<d, d / 2>::value;
};

template <>
struct IsPrime_old<0> {
	static constexpr  bool value = false;
};

template <>
struct IsPrime_old<1> {
	static constexpr  bool value = false;
};

template <>
struct IsPrime_old<2> {
	static constexpr  bool value = true;
};

template <>
struct IsPrime_old<3> {
	static constexpr  bool value = true;
};

template <unsigned d>
constexpr bool IsPrime_old_v = IsPrime_old<d>::value;