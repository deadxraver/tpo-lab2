#include "math.hpp"

#include <iostream>

int main(int argc, char* argv[]) {
  if (argc != 3) {
    std::cerr << "Invalid arguements\n";
    return -EINVAL;
  }
  double x = std::stod(argv[1]);
  double eps = std::stod(argv[2]);
  ext_math em(eps);
  try {
    std::cout << em.log(x, 10) << std::endl;
  } catch (std::string err) {
    std::cerr << err << std::endl;
    return -EINVAL;
  }
  return 0;
}
