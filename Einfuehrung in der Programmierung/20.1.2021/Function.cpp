#include<iostream>
template<typename T>
T Function<T>::eval(T x) {return 0;}

template<typename T>
void Function<T>::print() {}

template<typename T>
Function<T>::~Function(){std::cout<< "Function() dies" << std::endl;}

