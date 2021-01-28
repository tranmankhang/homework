#include <iostream>
#include <cmath>

template<typename T>
Polynom<T>::Polynom(int a, std::vector<T> b){
	grad = a;
	for(int i = 0; i <= a; i++)
	{
		koeffi.push_back(b[i]);
	}
}
template<typename T>
T Polynom<T>::eval(T x){
	T calc = koeffi[0];
	for (int i = 1; i <= grad; i++)
	{
		calc += koeffi[i]*pow(x,i);
	}
	return calc;
}
template<typename T>
void Polynom<T>::print(){
	std::cout << "f(x) = " << koeffi[0];
	for (int i = 1; i <= grad; i++)
	{
		if (koeffi[i] > 0)
		{
		std::cout << " + " << koeffi[i] << " * x^" << i;
		}
		if (koeffi[i] < 0)
		{
		std::cout << " - " << -koeffi[i] << " * x^" << i;
		}
	}
	std::cout << ": ";
}

template<typename T>
Polynom<T>::~Polynom(){std::cout << "Polynom() dies" << std::endl;}
