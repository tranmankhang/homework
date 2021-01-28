#pragma once

template<typename T>
class Function {
	public:
	virtual T eval(T);
	virtual void print();
	virtual ~Function();
};

#include "Function.cpp"
