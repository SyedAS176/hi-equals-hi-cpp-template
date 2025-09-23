#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/hello.hpp"

TEST_CASE( "tests for string compare" ) {
    REQUIRE( strcmp_case_insensitive("", "") == 0 );
    REQUIRE( strcmp_case_insensitive("hello", "world") == -1 );
    REQUIRE( strcmp_case_insensitive("ABC", "abc") == 0);
}