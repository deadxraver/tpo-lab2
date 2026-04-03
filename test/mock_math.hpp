#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "math.hpp"

class mock_math : public full_math {
public:
  using full_math::full_math;
  MOCK_METHOD(double, sin, (double x), (override, const));
  MOCK_METHOD(double, cos, (double x), (override, const));
  MOCK_METHOD(double, ln, (double x), (override, const));
};
