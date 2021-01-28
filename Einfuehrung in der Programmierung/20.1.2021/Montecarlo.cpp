#include<random>
#include<iostream>
template<typename T>
T Montecarlo<T>::computeArea(Function<T> *func){
	std::uniform_real_distribution<T> distribution_x(Integral<T>::x_lb, Integral<T>::x_ub);
  	std::uniform_real_distribution<T> distribution_y(y_lb, y_ub);
	int m=0;
  	T x, y_mc;
  	for (int i = 0; i < Integral<T>::anzahl; i++) 
	{
    		x = distribution_x(generator);
    		y_mc = distribution_y(generator);
    		if(func->eval(x)>=0)
		{
    			if (y_mc <= func->eval(x) && y_mc >= 0)
			{
      				m++;
    			}
		} else
		{
			if (y_mc >= func->eval(x) && y_mc < 0)
			{
      				m--;
    			}
		}
  	}
	return (static_cast<T>(m) / Integral<T>::anzahl) * (Integral<T>::x_ub - Integral<T>::x_lb) * (y_ub -y_lb);
}
template<typename T>
Montecarlo<T>::Montecarlo(int n, T a, T b, T c, T d): Integral<T>(n,a,b), y_lb(c), y_ub(d) {
}

template<typename T>
Montecarlo<T>::~Montecarlo(){std::cout << "Montecarlo() dies" << std::endl;}
