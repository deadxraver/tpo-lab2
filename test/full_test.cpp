#include "math.hpp"

#include <gtest/gtest.h>

#include <cmath>

namespace {
constexpr double POS_VAL1 = 1;
constexpr double POS_RET1 = 0;

constexpr double POS_VAL2 = 10;
constexpr double POS_RET2 = 9.9797;

constexpr double NEG_VAL1 = 0;
constexpr double NEG_RET1 = -1;

constexpr double NEG_VAL2 = -M_PI / 4;
constexpr double NEG_RET2 = -2.5607;

constexpr double LN_INVAL = -1;

constexpr double PRECISION = 10000;
}

TEST(math_full_test, positive_values_in) {
  full_math fmath(PRECISION);
  double res;

  res = fmath.mega_function(POS_VAL1);
  EXPECT_NEAR(res, POS_RET1, 1e-6);

  res = fmath.mega_function(POS_VAL2);
  EXPECT_NEAR(res, POS_RET2, 1e-5);
}

TEST(math_full_test, negative_values_in) {
  full_math fmath(PRECISION);
  double res;

  res = fmath.mega_function(NEG_VAL1);
  EXPECT_NEAR(res, NEG_RET1, 1e-6);

  res = fmath.mega_function(NEG_VAL2);
  EXPECT_NEAR(res, NEG_RET2, 1e-4);
}

TEST(math_full_test, ln_negative_arg) {
  full_math fmath(PRECISION);
  EXPECT_THROW(fmath.ln(LN_INVAL), std::string);
}
