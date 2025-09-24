#include <iostream>

#include "src/hello.hpp"

int main() {
  std::cout << hello() << std::endl;
  std::cout << strcmp_case_insensitive("", "") << std::endl;
  std::cout << strcmp_case_insensitive("hello", "world") << std::endl;
  std::cout << strcmp_case_insensitive("ABC", "abc") << std::endl;
  std::cout << strcmp_case_insensitive("world", "hello") << std::endl;

  std::cout << strcmp_case_insensitive("a b c", "abc", true) << std::endl;;
  std::cout << strcmp_case_insensitive("hello world", "helloworld", true) << std::endl;
  std::cout << strcmp_case_insensitive("a  b", "ab", true) << std::endl;
}
