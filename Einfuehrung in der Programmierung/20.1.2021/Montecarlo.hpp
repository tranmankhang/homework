#pragma once
#include <random>
#include "Integral.hpp"

template<typename T>
class Montecarlo: public Integral<T>{
	std::default_random_engine generator;
	T computeArea(Function<T>*);
	T y_lb, y_ub; 
	public:
	Montecarlo(int, T, T, T, T);
	~Montecarlo();
};

#include "Montecarlo.cpp"

