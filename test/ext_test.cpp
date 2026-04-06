#include "mock_math.hpp"

#include <cmath>

namespace {
constexpr double POS_VAL1 = 1;
constexpr double POS_RET1 = 0;

constexpr double POS_VAL2 = 10;
constexpr double POS_LOG10_RET = 1;
constexpr double POS_LOG2_RET = 3.3219;
constexpr double POS_LOG3_RET = 2.0959;
constexpr double POS_LN_RET = 2.3026;
constexpr double POS_RET2 = 9.9797;

constexpr double NEG_VAL1 = 0; // neg branch is x <= 0
constexpr double NEG_COS_RET1 = 1;
constexpr double NEG_SIN_RET1 = 0;
constexpr double NEG_SEC_RET1 = 1;
constexpr double NEG_RET1 = -1;

constexpr double NEG_VAL2 = -M_PI / 4;
constexpr double NEG_COS_RET2 = 0.7071;
constexpr double NEG_SIN_RET2 = -0.7071;
constexpr double NEG_SEC_RET2 = 1.4142;
constexpr double NEG_RET2 = -2.5607;

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

  EXPECT_CALL(memath, log(POS_VAL2, 10)).WillOnce(::testing::Return(POS_LOG10_RET));
  EXPECT_CALL(memath, log(POS_VAL2, 2))
    .Times(2)
    .WillRepeatedly(::testing::Return(POS_LOG2_RET));
  EXPECT_CALL(memath, log(POS_VAL2, 3)).WillOnce(::testing::Return(POS_LOG3_RET));
  EXPECT_CALL(memath, ln(POS_VAL2))
    .Times(3)
    .WillRepeatedly(::testing::Return(POS_LN_RET));
  EXPECT_CALL(memath, cos(POS_VAL2)).Times(0);
  EXPECT_CALL(memath, sin(POS_VAL2)).Times(0);
  res = memath.mega_function(POS_VAL2);
  EXPECT_NEAR(res, POS_RET2, 1e-3);
}

TEST(math_ext_test, negative_values_in) {
  mock_ext_math memath(PRECISION);
  double res;
  EXPECT_CALL(memath, cos(NEG_VAL1))
    .Times(3)
    .WillRepeatedly(::testing::Return(NEG_COS_RET1));
  EXPECT_CALL(memath, sin(NEG_VAL1)).WillOnce(::testing::Return(NEG_SIN_RET1));
  EXPECT_CALL(memath, sec(NEG_VAL1)).WillOnce(::testing::Return(NEG_SEC_RET1));
  res = memath.mega_function(NEG_VAL1);
  EXPECT_NEAR(res, NEG_RET1, 1e-6);

  EXPECT_CALL(memath, cos(NEG_VAL2))
    .Times(3)
    .WillRepeatedly(::testing::Return(NEG_COS_RET2));
  EXPECT_CALL(memath, sin(NEG_VAL2)).WillOnce(::testing::Return(NEG_SIN_RET2));
  EXPECT_CALL(memath, sec(NEG_VAL2)).WillOnce(::testing::Return(NEG_SEC_RET2));
  res = memath.mega_function(NEG_VAL2);
  EXPECT_NEAR(res, NEG_RET2, 1e-4);
}

TEST(math_ext_test, only_ext_mocked) {
  mock_onlyext_math moemath(PRECISION);
  double res;
  EXPECT_CALL(moemath, log(POS_VAL2, 10)).WillOnce(::testing::Return(POS_LOG10_RET));
  EXPECT_CALL(moemath, log(POS_VAL2, 2))
    .Times(2)
    .WillRepeatedly(::testing::Return(POS_LOG2_RET));
  EXPECT_CALL(moemath, log(POS_VAL2, 3)).WillOnce(::testing::Return(POS_LOG3_RET));
  res = moemath.mega_function(POS_VAL2);
  EXPECT_NEAR(res, POS_RET2, 1e-3);

  EXPECT_CALL(moemath, sec(NEG_VAL2)).WillOnce(::testing::Return(NEG_SEC_RET2));
  res = moemath.mega_function(NEG_VAL2);
  EXPECT_NEAR(res, NEG_RET2, 1e-4);
}
