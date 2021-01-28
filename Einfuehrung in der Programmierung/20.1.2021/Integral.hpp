#pragma once
#include "Function.hpp"

template<typename T>
class Integral {
	virtual T computeArea(Function<T>*);
	protected:
	T x_lb, x_ub;
	public:
	int anzahl;
	Integral(int, T, T);
	~Integral();
	void print(Function<T>*);
};

#include "Integral.cpp"
