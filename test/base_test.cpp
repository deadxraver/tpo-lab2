#include "mock_math.hpp"

namespace {
constexpr double ARG = 1000;
constexpr double BASE = 10;
constexpr double ARG_RES = 9.5;
constexpr double BASE_RES = 3.1;
constexpr double PRECISION = 10000;
}

TEST(math_test, log_uses_lns) {
  mock_base_math mbmath(10000);
  EXPECT_CALL(mbmath, ln(ARG)).WillOnce(::testing::Return(ARG_RES));
  EXPECT_CALL(mbmath, ln(BASE)).WillOnce(::testing::Return(BASE_RES));
  double res = mbmath.log(ARG, BASE);
  EXPECT_NEAR(res, ARG_RES / BASE_RES, 1e-6);
}
