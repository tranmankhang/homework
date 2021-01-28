#include <iostream>
#include <cmath>
template<typename T>
Trigonom<T>::Trigonom(T a, T b, T c){
	dog = a;
	cat = b;
	nix = c;
}
template<typename T>
T Trigonom<T>::eval(T x){
	return dog*sin(x) + cat*cos(x) + nix;
}
template<typename T>
void Trigonom<T>::print(){
	std::cout << "f(x) = " << dog << " * sin(x) + " << cat << " * cos(x) + " << nix << ": ";
}

template<typename T>
Trigonom<T>::~Trigonom(){std::cout<< "Trigonom() dies" << std::endl;}
