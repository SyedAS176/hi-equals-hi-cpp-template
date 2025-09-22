#include <iostream>

#include "src/hello.hpp"

int main() {
  std::cout << hello() << std::endl;
  std::cout << string_compare("hello", "world") << std::endl;
}
