#include <vector>
#include "Polynom.hpp"
#include "Trigonom.hpp"
#include "Riemann.hpp"
#include "Montecarlo.hpp"

using namespace std;

typedef double TYPE;

int main() {

  vector<TYPE> p(4);
  p[0] = 3.0;
  p[1] = 0.0;
  p[2] = 0.7;
  p[3] = -1.2;
  int degree = 3;
  TYPE a = 0.2, b = 0.8, c = 2.4;
  int n = 10000;
  TYPE x_lb = 0.0, x_ub = 4.0, y_lb = -80, y_ub = 8.0;

  auto f0 = Polynom<TYPE>(degree, p);
  auto f1 = Trigonom<TYPE>(a, b, c);
  Function<TYPE> *F[2];
  F[0] = &f0;
  F[1] = &f1;
  auto i0 = Riemann<TYPE>(n, x_lb, x_ub);
  auto i1 = Montecarlo<TYPE>(n, x_lb, x_ub, y_lb, y_ub);
  Integral<TYPE> *I[2];
  I[0] = &i0;
  I[1] = &i1;

  for (int f = 0; f < 2; f++) {
    for (int i = 0; i < 2; i++) {
      I[i]->print(F[f]);
    }
  }
  return 0;
}
