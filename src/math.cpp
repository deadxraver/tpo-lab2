#include "math.hpp"

#include <cmath>
#include <string>

base_math::base_math(double iterations) : eps(iterations) {}

double base_math::sin(double x) const {
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

double base_math::ln(double x) const {
  if (x <= 0)
    throw std::string("ln: recieved x <= 0 in ln");
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

double ext_math::cos(double x) const {
  return std::pow(1 - std::pow(sin(x), 2), 0.5);
}

double ext_math::sec(double x) const {
  double cos_val = cos(x);
  if (cos_val == 0)
    throw std::string("sec: cos(x) should not be 0");
  return 1 / cos_val;
}

double ext_math::log(double x, double base) const {
  return ln(x) / ln(base);
}

double full_math::mega_function(double x) const {
  if (x <= 0) {
    return (((std::pow(std::pow(cos(x), 2), 2) + sin(x)) / cos(x)) - (sec(x) + std::pow(cos(x), 2)));
  }
  return ((((std::pow(log(x, 10), 3) * log(x, 2)) * log(x, 2)) - ((log(x, 3) + ln(x)) + ln(x))) * ln(x));
}
