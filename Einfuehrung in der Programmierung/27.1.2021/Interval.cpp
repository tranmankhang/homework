#include <iostream>
#include <cmath>

using namespace std;

template<typename T>
Interval<T>::Interval(): lb(0), ub(0) {}
//constructor

template<typename T>
Interval<T>::Interval(T a): lb(a), ub(a) {}
//constructor

template<typename T>
Interval<T>::Interval(T a, T b): lb(a), ub(b) {}
//constructor

template<typename T>
T const& Interval<T>::Lb() const{
	return lb;
}
//get lb

template<typename T>
T const& Interval<T>::Ub() const{
	return ub;
}
//get ub

template<typename T>
Interval<T> Interval<T>::operator-(){
	return Interval<T> (-(this->Ub()), -this->Lb());;
}
//unary minus, member

template<typename T>
Interval<T> Interval<T>::operator+(){
	return Interval<T> (this->Lb(), this->Ub());;
}
//unary plus, member

template<typename T>
Interval<T> operator+(const Interval<T>& a, const Interval<T>& b){
	return Interval<T> (a.Lb() + b.Lb(), a.Ub() + b.Ub());	 
}
template<typename T, typename _T>
Interval<T> operator+(const Interval<T>& a, const _T& b){
	return Interval<T> (a.Lb() + b, a.Ub() + b);	 
}
template<typename T, typename _T>
Interval<T> operator+(const _T& a, const Interval<T>& b){
	return Interval<T> (a + b.Lb(), a + b.Ub());	 
}
//binary plus, non member

template<typename T>
Interval<T> operator-(const Interval<T>& a, const Interval<T>& b){
	return Interval<T> (a.Lb() - b.Ub(), a.Ub() - b.Lb());	 
}
template<typename T, typename _T>
Interval<T> operator-(const Interval<T>& a, const _T& b){
	return Interval<T> (a.Lb() - b, a.Ub() - b);	 
}
template<typename T, typename _T>
Interval<T> operator-(const _T& a, const Interval<T>& b){
	return Interval<T> (a - b.Ub(), a - b.Lb());	 
}
//binary minus, non member

template<typename T>
Interval<T> operator*(const Interval<T>& a, const Interval<T>& b){
	return Interval<T> (min(min(a.Lb()*b.Lb(), a.Lb()*b.Ub()), min(a.Ub()*b.Lb(), a.Ub()*b.Ub())), 
			     max(max(a.Lb()*b.Lb(), a.Lb()*b.Ub()), max(a.Ub()*b.Lb(), a.Ub()*b.Ub())));	 
}
template<typename T, typename _T>
Interval<T> operator*(const _T& a, const Interval<T>& b){
	return Interval<T> (min(min(a*b.Lb(), a*b.Ub()), min(a*b.Lb(), a*b.Ub())), 
			     max(max(a*b.Lb(), a*b.Ub()), max(a*b.Lb(), a*b.Ub())));	 
}
template<typename T, typename _T>
Interval<T> operator*(const Interval<T>& a, const _T& b){
	return Interval<T> (min(min(a.Lb()*b, a.Lb()*b), min(a.Ub()*b, a.Ub()*b)), 
			     max(max(a.Lb()*b, a.Lb()*b), max(a.Ub()*b, a.Ub()*b)));	 
}
//binary multiplication, non member

template<typename T>
Interval<T> operator/(const Interval<T>& a, const Interval<T>& b){
	return Interval<T> (min(min(a.Lb()*(1/b.Lb()), a.Lb()*(1/b.Ub())), min(a.Ub()*(1/b.Lb()), a.Ub()*(1/b.Ub()))), 
			     max(max(a.Lb()*(1/b.Lb()), a.Lb()*(1/b.Ub())), max(a.Ub()*(1/b.Lb()), a.Ub()*(1/b.Ub()))));	 
}
template<typename T, typename _T>
Interval<T> operator/(const _T& a, const Interval<T>& b){
	return Interval<T> (min(min(a*(1/b.Lb()), a*(1/b.Ub())), min(a*(1/b.Lb()), a*(1/b.Ub()))), 
			     max(max(a*(1/b.Lb()), a*(1/b.Ub())), max(a*(1/b.Lb()), a*(1/b.Ub()))));	 
}
template<typename T, typename _T>
Interval<T> operator/(const Interval<T>& a, const _T& b){
	return Interval<T> (min(min(a.Lb()*(1/b), a.Lb()*(1/b)), min(a.Ub()*(1/b), a.Ub()*(1/b))), 
			     max(max(a.Lb()*(1/b), a.Lb()*(1/b)), max(a.Ub()*(1/b), a.Ub()*(1/b))));	 
}
//binary division, non member

template<typename T>
Interval<T> operator+=(Interval<T>& a, const Interval<T>& b){
	a = Interval<T> (a.Lb() + b.Lb(), a.Ub() + b.Ub());
	return a;	 
}
template<typename T, typename _T>
Interval<T> operator+=(const Interval<T>& a, const _T& b){
	a = Interval<T> (a.Lb() + b, a.Ub() + b);
	return a;	 
}
template<typename T, typename _T>
Interval<T> operator+=(const _T& a, const Interval<T>& b){
	a = Interval<T> (a + b.Lb(), a + b.Ub());
	return a;	 
}
//binary incremental, non member


template<typename T>
Interval<T> operator-=(const Interval<T>& a, const Interval<T>& b){
	a = Interval<T> (a.Lb() - b.Ub(), a.Ub() - b.Lb());
	return a;	 
}
template<typename T, typename _T>
Interval<T> operator-=(const Interval<T>& a, const _T& b){
	a = Interval<T> (a.Lb() - b, a.Ub() - b);
	return a;	 
}
template<typename T, typename _T>
Interval<T> operator-=(const _T& a, const Interval<T>& b){
	a = Interval<T> (a - b.Ub(), a - b.Lb());
	return a;	 
}
//binary decremental, non member

template<typename T>
Interval<T> operator*=(const Interval<T>& a, const Interval<T>& b){
	a = Interval<T> (min(min(a.Lb()*b.Lb(), a.Lb()*b.Ub()), min(a.Ub()*b.Lb(), a.Ub()*b.Ub())), 
			     max(max(a.Lb()*b.Lb(), a.Lb()*b.Ub()), max(a.Ub()*b.Lb(), a.Ub()*b.Ub())));
	return a;	 
}
template<typename T, typename _T>
Interval<T> operator*=(const _T& a, const Interval<T>& b){
	a = Interval<T> (min(min(a*b.Lb(), a*b.Ub()), min(a*b.Lb(), a*b.Ub())), 
			     max(max(a*b.Lb(), a*b.Ub()), max(a*b.Lb(), a*b.Ub())));
	return a;	 
}
template<typename T, typename _T>
Interval<T> operator*=(const Interval<T>& a, const _T& b){
	a = Interval<T> (min(min(a.Lb()*b, a.Lb()*b), min(a.Ub()*b, a.Ub()*b)), 
			     max(max(a.Lb()*b, a.Lb()*b), max(a.Ub()*b, a.Ub()*b)));	
	return a;
}
//binary multiplikamental, non member

template<typename T>
Interval<T> operator/=(const Interval<T>& a, const Interval<T>& b){
	a = Interval<T> (min(min(a.Lb()*(1/b.Lb()), a.Lb()*(1/b.Ub())), min(a.Ub()*(1/b.Lb()), a.Ub()*(1/b.Ub()))), 
			     max(max(a.Lb()*(1/b.Lb()), a.Lb()*(1/b.Ub())), max(a.Ub()*(1/b.Lb()), a.Ub()*(1/b.Ub()))));	
	return a; 
}
template<typename T, typename _T>
Interval<T> operator/=(const _T& a, const Interval<T>& b){
	a = Interval<T> (min(min(a*(1/b.Lb()), a*(1/b.Ub())), min(a*(1/b.Lb()), a*(1/b.Ub()))), 
			     max(max(a*(1/b.Lb()), a*(1/b.Ub())), max(a*(1/b.Lb()), a*(1/b.Ub()))));	 
	return a;
}
template<typename T, typename _T>
Interval<T> operator/=(const Interval<T>& a, const _T& b){
	a = Interval<T> (min(min(a.Lb()*(1/b), a.Lb()*(1/b)), min(a.Ub()*(1/b), a.Ub()*(1/b))), 
			     max(max(a.Lb()*(1/b), a.Lb()*(1/b)), max(a.Ub()*(1/b), a.Ub()*(1/b))));	 
	return a; 
}
//binary divisionamental, non member

template<typename T>
ostream& operator<<(ostream& s, const Interval<T>& i){
	s << "Lower bound: " << i.Lb() << "  Upper bound: " << i.Ub();
	return s;
//ostream, non member
}

