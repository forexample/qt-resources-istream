#include <iostream> // std::cout
#include <string> // std::getline
#include <fstream> // std::ofstream

#include <foo.hpp>

void foo(std::istream& stream) {
  std::ofstream file("output.png", std::ios::binary);
  file << stream.rdbuf();
}
