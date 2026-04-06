#pragma once

#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "math.hpp"

class mock_base_math : public full_math {
public:
  using full_math::full_math;
  MOCK_METHOD(double, sin, (double x), (override, const));
  MOCK_METHOD(double, cos, (double x), (override, const));
  MOCK_METHOD(double, ln, (double x), (override, const));
};

class mock_ext_math : public mock_base_math {
public:
  using mock_base_math::mock_base_math;
  MOCK_METHOD(double, sec, (double x), (override, const));
  MOCK_METHOD(double, log, (double x, double base), (override, const));
};
