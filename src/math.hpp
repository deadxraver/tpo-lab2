#pragma once

class base_math {
private:
  const double eps;
public:
  virtual double sin(double x) const;
  virtual double ln(double x) const;
  base_math(double iterations);
};

class ext_math : public base_math {
public:
  virtual double cos(double x) const;
  virtual double sec(double x) const;
  virtual double log(double x, double base) const;
  using base_math::base_math;
};
