#include "mock_math.hpp"

#include <cmath>

namespace {
constexpr double LN_ARG = 1000;
constexpr double LN_BASE = 10;
constexpr double LN_ARG_RES = 9.5;
constexpr double LN_BASE_RES = 3.1;

constexpr double COS_ARG = M_PI;
constexpr double COS_RES = 1;

constexpr double PRECISION = 10000;
}

TEST(math_base_test, log_uses_lns) {
  mock_base_math mbmath(PRECISION);
  EXPECT_CALL(mbmath, ln(LN_ARG)).WillOnce(::testing::Return(LN_ARG_RES));
  EXPECT_CALL(mbmath, ln(LN_BASE)).WillOnce(::testing::Return(LN_BASE_RES));
  EXPECT_CALL(mbmath, cos(LN_BASE)).Times(0);
  double res = mbmath.log(LN_ARG, LN_BASE);
  EXPECT_NEAR(res, LN_ARG_RES / LN_BASE_RES, 1e-6);
}

TEST(math_base_test, sec_uses_cos) {
  mock_base_math mbmath(PRECISION);
  EXPECT_CALL(mbmath, cos(COS_ARG)).WillOnce(::testing::Return(COS_RES));
  EXPECT_CALL(mbmath, ln(COS_ARG)).Times(0);
  double res = mbmath.sec(COS_ARG);
  EXPECT_NEAR(res, 1 / COS_RES, 1e-6);
}
