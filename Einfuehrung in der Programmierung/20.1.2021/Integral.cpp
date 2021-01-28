#include <iostream>
template<typename T>
T Integral<T>::computeArea(Function<T> *func){return 0;}

template<typename T>
Integral<T>::Integral(int n, T a, T b){
	x_lb = a;
	x_ub = b;
	anzahl = n;
}
template<typename T>
void Integral<T>::print(Function<T> *func){
	std::cout << "Int. ";
	func->print();
	std::cout << computeArea(func) << std::endl;
}

template<typename T>
Integral<T>::~Integral(){std::cout << "Integral() dies" << std::endl;}


