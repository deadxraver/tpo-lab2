#include "math.hpp"

#include <iostream>

std::string available_functions = "sin cos ln log3 log10 log2 mega_function";

int main(int argc, char* argv[]) {
  if (argc != 6) {
    std::cerr << "Invalid arguements\nExpected:\n";
    std::cerr << argv[0] << " <method> <x_start> <step> <x_stop> <precision>\n";
    return -EINVAL;
  }
  std::string method(argv[1]);
  double x_start = std::stod(argv[2]);
  double step = std::stod(argv[3]);
  double x_stop = std::stod(argv[4]);
  double eps = std::stod(argv[5]);
  full_math fm(eps);
  double res;
  std::cout << "x;" << method << "(x)\n";
  for (double x = x_start; x <= x_stop; x += step) {
    try {
      if (method == "sin")
        res = fm.sin(x);
      else if (method == "cos")
        res = fm.cos(x);
      else if (method == "ln")
        res = fm.ln(x);
      else if (method == "sec")
        res = fm.sec(x);
      else if (method == "log3")
        res = fm.log(x, 3);
      else if (method == "log10")
        res = fm.log(x, 10);
      else if (method == "log2")
        res = fm.log(x, 2);
      else if (method == "mega_function")
        res = fm.mega_function(x);
      else {
        std::cerr << "unknown function " << method << ", available functions: " << available_functions << std::endl;
        return -EINVAL;
      }
      std::cout << x << ";" << res << std::endl;
    } catch (std::string err) {
      std::cerr << err << std::endl;
      continue;
    }
  }
  return 0;
}
