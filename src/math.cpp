#include "math.hpp"

#include <cmath>
#include <string>

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
  if (x <= 0)
    throw std::string("recieved x <= 0 in ln");
  int k = 0;
  for (; x >= 2; x /= 2, ++k);
  for (; x < 1; x *= 2, --k);
  x -= 1;
  double term = x;
  double res = term;
  for (int i = 2; i <= eps; ++i) {
    term *= -x;
    res += term / i;
  }
  return res + k * M_LN2;
}
