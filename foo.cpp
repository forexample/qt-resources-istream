#include <iostream> // std::cout
#include <string> // std::getline

#include <foo.hpp>

void foo(std::istream& stream) {
  std::string line;
  for (int i = 0; std::getline(stream, line); ++i) {
    std::cout << "line #" << i << ": " << line << std::endl;
  }
}
