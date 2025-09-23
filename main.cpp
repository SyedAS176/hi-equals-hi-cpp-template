#include <iostream>

#include "src/hello.hpp"

int main() {
  std::cout << hello() << std::endl;
  std::cout << strcmp_case_insensitive("", "") << std::endl;
  std::cout << strcmp_case_insensitive("hello", "world") << std::endl;
  std::cout << strcmp_case_insensitive("ABC", "abc") << std::endl;
  std::cout << strcmp_case_insensitive("world", "hello") << std::endl;
}
