#pragma once
#include "Function.hpp"
#include <vector>

template<typename T>
class Polynom: public Function<T> {
	int grad;
	std::vector<T> koeffi;
	public:
	Polynom(int, std::vector<T>);
	~Polynom();
	T eval(T);
	void print();
};

#include "Polynom.cpp"
