#pragma once

class base_math {
public:
  virtual double sin(double x, int eps) const;
  virtual double ln(double x, int eps) const;
};
