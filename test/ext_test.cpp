#include "mock_math.hpp"

#include <cmath>

namespace {
constexpr double POS_VAL1 = 1;
constexpr double POS_RET1 = 0;

constexpr double PRECISION = 10000;
}

TEST(math_ext_test, positive_values_in) {
  mock_ext_math memath(PRECISION);
  EXPECT_CALL(memath, log(POS_VAL1, 10)).WillOnce(::testing::Return(POS_RET1));
  EXPECT_CALL(memath, log(POS_VAL1, 2))
    .Times(2)
    .WillRepeatedly(::testing::Return(POS_RET1));
  EXPECT_CALL(memath, log(POS_VAL1, 3)).WillOnce(::testing::Return(POS_RET1));
  EXPECT_CALL(memath, ln(POS_VAL1))
    .Times(3)
    .WillRepeatedly(::testing::Return(POS_RET1));
  EXPECT_CALL(memath, cos(POS_VAL1)).Times(0);
  EXPECT_CALL(memath, sin(POS_VAL1)).Times(0);
  double res = memath.mega_function(POS_VAL1);
  EXPECT_NEAR(res, POS_RET1, 1e-6);
}
