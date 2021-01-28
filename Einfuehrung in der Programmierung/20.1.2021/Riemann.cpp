#include<iostream>

template<typename T>
T Riemann<T>::computeArea(Function<T> *func){
	T y;
  	T step;
  	T sum_rect;
  	step = (Integral<T>::x_ub - Integral<T>::x_lb) / Integral<T>::anzahl;
  	sum_rect = 0;
  	for (int i = 0; i < Integral<T>::anzahl; i++) 
	{
	    	y = func->eval(Integral<T>::x_lb+(0.5+i)*step);
	    	sum_rect += y*step;
  	}
  	return sum_rect;
}

template<typename T>
Riemann<T>::Riemann(int n, T a, T b): Integral<T>(n, a, b){
}

template<typename T>
Riemann<T>::~Riemann(){std::cout << "Riemann() dies" << std::endl;}
