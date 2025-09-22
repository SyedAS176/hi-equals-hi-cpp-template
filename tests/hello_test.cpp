#include <catch2/catch_test_macros.hpp>
#include <catch2/benchmark/catch_benchmark.hpp>
#include <catch2/benchmark/catch_constructor.hpp>
#include <catch2/generators/catch_generators_range.hpp>

#include "../src/hello.hpp"

TEST_CASE( "tests for string compare" ) {
    REQUIRE( string_compare("", "") == -1 );
    REQUIRE( string_compare("hello", "world") == -1 );
    REQUIRE( string_compare("ABC", "abc") == -1);
}
