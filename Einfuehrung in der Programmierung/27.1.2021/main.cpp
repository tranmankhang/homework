#include <iostream>
#include <cmath>
#include "Interval.hpp"

using namespace std;

int main() {
  Interval<double> x1(2,9);
  cout << x1 << endl;
  Interval<double> x2(-2,5);
  cout << x2 << endl;
  Interval<double> x3 = -x2;
  cout << x3 << endl;
  Interval<double> x4 = 4;
  cout << x4 << endl;
  cout << (x1 += x4) << endl;
  Interval<double> x5;
  x5 = (6.0-x1*x3-x2*(3+x2))/x4;
  cout << x5 << endl;
}

