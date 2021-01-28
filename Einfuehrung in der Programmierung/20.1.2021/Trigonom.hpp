#pragma once
#include "Function.hpp"

template<typename T>
class Trigonom: public Function<T>{
	T dog, cat, nix;
	public:
	Trigonom(T, T, T);
	~Trigonom();
	T eval(T);
	void print();
};

#include "Trigonom.cpp"
