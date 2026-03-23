#include "math.hpp"

#include <iostream>

int main(int argc, char* argv[]) {
  if (argc != 3) {
    std::cerr << "Invalid arguements\n";
    return -EINVAL;
  }
  double x = std::stod(argv[1]);
  double eps = std::stod(argv[2]);
  base_math bm;
  std::cout << bm.ln(x, eps) << std::endl;
  return 0;
}
