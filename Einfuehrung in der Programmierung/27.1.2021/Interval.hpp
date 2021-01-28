#pragma once
#include <iostream>
#include <cmath>

using namespace std;

template<typename T>
class Interval {
	T lb, ub;
	public:
	Interval();
	Interval(T);
	Interval(T, T);
	T const& Lb() const;
	T const& Ub() const;
	Interval<T> operator-();
	Interval<T> operator+();
};

#include "Interval.cpp"
