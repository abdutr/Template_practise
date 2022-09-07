#pragma once
template<int Num,int Low = 1,int High = Num>
struct sqrt_old{
	constexpr static auto mid = (High + Low +1) / 2;
	constexpr static auto value = Num < mid* mid ? sqrt_old<Num, Low, mid - 1>::value :
		sqrt_old<Num, mid, High>::value;
};

template<int Num, int Converged>
struct sqrt_old<Num,Converged,Converged> {
	constexpr static auto value = Converged;
};

template<int Num>
constexpr auto sqrt_v = sqrt_old<Num>::value;