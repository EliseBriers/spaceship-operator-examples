#include "SimpleStruct.h"
#include "catch2/catch_amalgamated.hpp"

#include <cmath>
#include <compare>
#include <complex>
#include <numeric>
#include <optional>
#include <string_view>
#include <vector>

namespace tests {

// ╔═══════════════════════╗
// ║ Simple Struct Compare ║
// ╚═══════════════════════╝
namespace simple_struct_test {
    namespace old_compare {

        using namespace simple_struct_old;
        namespace old_compare_test {
            TEST_CASE("SimpleStruct Compare using old system.", "[SimpleStruct]")
            {
                const SimpleStruct simpleStructA { 5 };
                const SimpleStruct simpleStructB { 5 };
                const SimpleStruct simpleStructC { 7 };

                REQUIRE(simpleStructA == simpleStructB);
                REQUIRE(simpleStructA != simpleStructC);

                REQUIRE(simpleStructA < simpleStructC);
                REQUIRE(simpleStructC > simpleStructA);

                REQUIRE(simpleStructA <= simpleStructB);
                REQUIRE(simpleStructA >= simpleStructB);
                REQUIRE(simpleStructA <= simpleStructC);
            }
        }
    }
    namespace new_compare {
        using namespace simple_struct_new;
        TEST_CASE("SimpleStruct Compare using new system.", "[SimpleStruct]")
        {
            const SimpleStruct simpleStructA { 5 };
            const SimpleStruct simpleStructB { 5 };
            const SimpleStruct simpleStructC { 7 };

            REQUIRE(simpleStructA == simpleStructB);
            REQUIRE(simpleStructA != simpleStructC);

            REQUIRE(simpleStructA < simpleStructC);
            REQUIRE(simpleStructC > simpleStructA);

            REQUIRE(simpleStructA <= simpleStructB);
            REQUIRE(simpleStructA >= simpleStructB);
            REQUIRE(simpleStructA <= simpleStructC);
        }

        TEST_CASE("SimpleStruct Compare using spaceship operator and comparing to 0.", "[SimpleStruct]")
        {
            const SimpleStruct simpleStructA { 5 };
            const SimpleStruct simpleStructB { 5 };
            const SimpleStruct simpleStructC { 7 };

            const std::strong_ordering compareAB { simpleStructA <=> simpleStructB };
            const std::strong_ordering compareAC { simpleStructA <=> simpleStructC };
            const std::strong_ordering compareCA { simpleStructC <=> simpleStructA };

            REQUIRE(compareAB == 0);
            REQUIRE(compareAC < 0);
            REQUIRE(compareCA > 0);
        }

        TEST_CASE("SimpleStruct Compare using spaceship operator and using std functions to test the result.", "[SimpleStruct]")
        {
            const SimpleStruct simpleStructA { 5 };
            const SimpleStruct simpleStructB { 5 };
            const SimpleStruct simpleStructC { 7 };

            const std::strong_ordering compareAB { simpleStructA <=> simpleStructB };
            const std::strong_ordering compareAC { simpleStructA <=> simpleStructC };
            const std::strong_ordering compareCA { simpleStructC <=> simpleStructA };

            REQUIRE(std::is_eq(compareAB));
            REQUIRE(std::is_lt(compareAC));
            REQUIRE(std::is_gt(compareCA));
        }
    }
}

// ╔═════════════════════════════╗
// ║ Basic <=> Operator Examples ║
// ╚═════════════════════════════╝
TEST_CASE("Spaceship operator on int results in strong ordering.", "[std::strong_ordering]")
{
    const int numA { 5 };
    const int numB { 5 };
    const int numC { 7 };

    const std::strong_ordering compareAB { numA <=> numB };
    const std::strong_ordering compareAC { numA <=> numC };

    REQUIRE(compareAB == std::strong_ordering::equal);
    REQUIRE(compareAC == std::strong_ordering::less);
}

TEST_CASE("Spaceship ordering on string yields strong ordering.", "[std::strong_ordering]")
{
    const std::string stringA { "Hello there." };
    const std::string stringB { "Hello there." };

    const auto compareAB { stringA <=> stringB };
    const auto compareAA { stringA <=> stringA };

    REQUIRE(std::is_eq(compareAB));
    REQUIRE(std::is_eq(compareAA));
}

TEST_CASE("Spaceship operator on float results in weak_ordering.", "[std::partial_ordering]")
{
    const float numA { 5.F };
    const float numB { 5.F };
    const float numC { 7.F };

    const std::partial_ordering compareAB { numA <=> numB };
    const std::partial_ordering compareAC { numA <=> numC };

    REQUIRE(compareAB == std::partial_ordering::equivalent);
    REQUIRE(compareAC == std::partial_ordering::less);
}

TEST_CASE("Spaceship operator on float results in -0.F and 0.F being equivalent.", "[std::partial_ordering]")
{
    const float numA { 0.F };
    const float numB { -0.F };

    const std::partial_ordering compareAB { numA <=> numB };

    const bool aSignBit { std::signbit(numA) };
    const bool bSignBit { std::signbit(numB) };

    REQUIRE(compareAB == std::partial_ordering::equivalent);
    REQUIRE(aSignBit != bSignBit);
}

TEST_CASE("Spaceship operator on float can handle special cases such as NaN.", "[std::partial_ordering]")
{
    const float numA { NAN };
    const float numB { NAN };
    const float numC { 7.F };

    const std::partial_ordering compareAB { numA <=> numB };
    const std::partial_ordering compareAC { numA <=> numC };

    REQUIRE(compareAB == std::partial_ordering::unordered);
    REQUIRE(compareAC == std::partial_ordering::unordered);
}
} // namespace tests
