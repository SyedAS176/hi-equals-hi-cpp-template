#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/hello.hpp"

TEST_CASE( "tests for string compare without spaces" ) {
    REQUIRE( strcmp_case_insensitive("", "") == 0 );
    REQUIRE( strcmp_case_insensitive("hello", "world") == -1 );
    REQUIRE( strcmp_case_insensitive("ABC", "abc") == 0 );
    REQUIRE( strcmp_case_insensitive("apple", "banana") == -1 );
    REQUIRE( strcmp_case_insensitive("banana", "apple") == 1 );
}

TEST_CASE( "tests for strings with spaces" ) {
    REQUIRE( strcmp_case_insensitive("a b c", "abc", true) == 0 );
    REQUIRE( strcmp_case_insensitive("hello world", "helloworld", true) == 0 );
    REQUIRE( strcmp_case_insensitive("a  b", "ab", true) == 0 );
    REQUIRE( strcmp_case_insensitive("apple pie", "apple pie", true) == 0 );
    REQUIRE( strcmp_case_insensitive("apple pie", "apple", true) == 1 );
    REQUIRE( strcmp_case_insensitive("apple", "apple pie", true) == -1 );
}