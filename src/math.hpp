#pragma once

class base_math {
public:
  virtual double sin(double x, int eps) const;
  virtual double ln(double x, int eps) const;
};

class ext_math : public base_math {
public:
  virtual double cos(double x, int eps) const;
  virtual double sec(double x, int eps) const;
  virtual double log(double x, double base, int eps) const;
};
