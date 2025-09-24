#include <iostream>

#include "src/hello.hpp"


int main() {

  std::cout << hello() << std::endl; //Just saying hello

  std::cout << strcmp_case_insensitive("", "") << std::endl;
  std::cout << strcmp_case_insensitive("hello", "world") << std::endl;
  std::cout << strcmp_case_insensitive("ABC", "abc") << std::endl;
  std::cout << strcmp_case_insensitive("world", "hello") << std::endl;

  std::cout << strcmp_case_insensitive("a b c", "abc", true) << std::endl;
  std::cout << strcmp_case_insensitive("hello world", "helloworld", true) << std::endl;
  std::cout << strcmp_case_insensitive("a  b", "ab", true) << std::endl;

  std::cout << strcmp_case_insensitive("beans", "beans", 4) << std::endl;
  std::cout << strcmp_case_insensitive("beans", "beans cool", 4) << std::endl;
  std::cout << strcmp_case_insensitive("apple", "banana", 10) << std::endl;
  std::cout << strcmp_case_insensitive("apple pie", "banana bread", 5) << std::endl;
  std::cout << strcmp_case_insensitive("apple pie", "banana pie", 5) << std::endl;

  std::cout << strcmp_case_insensitive("abc10", "abc9") << std::endl;
  std::cout << strcmp_case_insensitive("appl", "apple") << std::endl;
  std::cout << strcmp_case_insensitive("apple", "appl") << std::endl;

  return 0;
}