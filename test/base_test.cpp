#include "mock_math.hpp"

namespace {
constexpr double LN_ARG = 1000;
constexpr double LN_BASE = 10;
constexpr double LN_ARG_RES = 9.5;
constexpr double LN_BASE_RES = 3.1;
constexpr double PRECISION = 10000;
}

TEST(math_base_test, log_uses_lns) {
  mock_base_math mbmath(10000);
  EXPECT_CALL(mbmath, ln(LN_ARG)).WillOnce(::testing::Return(LN_ARG_RES));
  EXPECT_CALL(mbmath, ln(LN_BASE)).WillOnce(::testing::Return(LN_BASE_RES));
  double res = mbmath.log(LN_ARG, LN_BASE);
  EXPECT_NEAR(res, LN_ARG_RES / LN_BASE_RES, 1e-6);
}
