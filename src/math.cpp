#include "math.hpp"

#include <cmath>

double base_math::sin(double x, int eps) const {
  while (x >= M_PI) {
    x -= 2 * M_PI;
  }
  while (x <= -M_PI) {
    x += 2 * M_PI;
  }
  double term = x;
  double res = term;
  for (int k = 1; k < eps; ++k) {
    term *= -x * x / ((2 * k) * (2 * k + 1));
    res += term;
  }
  return res;
}

double base_math::ln(double x, int eps) const {
  return 0; // TODO: 
}
