#pragma once
#include "Integral.hpp"

template<typename T>
class Riemann: public Integral<T>{
	public:
	T computeArea(Function<T>*);
	Riemann(int, T, T);
	~Riemann();
};	

#include "Riemann.cpp"
