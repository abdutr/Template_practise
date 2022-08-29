#pragma once
#include <array>
template <typename T=double>
constexpr T pi{ static_cast<T>(3.14235234655125436743) };

template<typename T>
T variable_temp_test;

template<int N>
std::array<int, N> arr{};