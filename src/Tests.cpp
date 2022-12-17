#include "Fraction.h"
#include "SimpleStruct.h"
#include "catch2/catch_amalgamated.hpp"

#include <cmath>
#include <compare>
#include <complex>
#include <iostream>
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

    namespace default_compare {
        using namespace simple_struct_default;
        TEST_CASE("SimpleStruct Compare using default new system.", "[SimpleStruct]")
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

        TEST_CASE("SimpleStruct Compare using default spaceship operator and comparing to 0.", "[SimpleStruct]")
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

        TEST_CASE("SimpleStruct Compare using default spaceship operator and using std functions to test the result.", "[SimpleStruct]")
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
TEST_CASE("Spaceship operator smaller than 0", "[std::strong_ordering]")
{
    const int numA { 5 };
    const int numB { 7 };

    const std::strong_ordering compared { numA <=> numB };

    REQUIRE(compared < 0);
}

TEST_CASE("Spaceship operator equal to 0", "[std::strong_ordering]")
{
    const int numA { 5 };
    const int numB { 5 };

    const std::strong_ordering compared { numA <=> numB };

    REQUIRE(compared == 0);
}

TEST_CASE("Spaceship operator greater than 0", "[std::strong_ordering]")
{
    const int numA { 7 };
    const int numB { 5 };

    const std::strong_ordering compared { numA <=> numB };

    REQUIRE(compared > 0);
}

TEST_CASE("Spaceship operator is_lt", "[std::strong_ordering]")
{
    const int numA { 5 };
    const int numB { 7 };

    const std::strong_ordering compared { numA <=> numB };

    REQUIRE(std::is_lt(compared));
}

TEST_CASE("Spaceship operator is_eq", "[std::strong_ordering]")
{
    const int numA { 5 };
    const int numB { 5 };

    const std::strong_ordering compared { numA <=> numB };

    REQUIRE(std::is_eq(compared));
}

TEST_CASE("Spaceship operator is_gt", "[std::strong_ordering]")
{
    const int numA { 7 };
    const int numB { 5 };

    const std::strong_ordering compared { numA <=> numB };

    REQUIRE(std::is_gt(compared));
}

TEST_CASE("Spaceship operator on int results in strong ordering.", "[std::strong_ordering]")
{
    const int numA { 5 };
    const int numB { 5 };
    const int numC { 7 };

    const std::strong_ordering compareAB { numA <=> numB };
    const std::strong_ordering compareAC { numA <=> numC };
    const std::strong_ordering compareCA { numC <=> numA };

    REQUIRE(std::is_eq(compareAB)); //   ==
    REQUIRE(std::is_neq(compareAC)); //  !=
    REQUIRE(std::is_lt(compareAC)); //   <
    REQUIRE(std::is_gt(compareCA)); //   >
    REQUIRE(std::is_lteq(compareAC)); // <=
    REQUIRE(std::is_gteq(compareCA)); // >=
}

TEST_CASE("Spaceship ordering on string yields strong ordering.", "[std::strong_ordering]")
{
    const std::string stringA { "Hello there." };
    const std::string stringB { "Hello there." };

    const std::strong_ordering compareAB { stringA <=> stringB };

    REQUIRE(std::is_eq(compareAB));
    REQUIRE(stringA.c_str() != stringB.c_str());
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

    REQUIRE(std::is_eq(compareAB));
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

TEST_CASE("NaN returns false when compared to itself.", "[std::weak_ordering]")
{
    const float example { NAN };

    REQUIRE(example != example);
}

// ╔══════════╗
// ║ Fraction ║
// ╚══════════╝
namespace test_fraction {
    using namespace fraction;
    TEST_CASE("Basic Fraction Compare Example 1", "[Fraction]")
    {
        const Fraction fractionA { 2, 6 };
        const Fraction fractionB { 1, 2 };

        REQUIRE(fractionA < fractionB);
    }

    TEST_CASE("Basic Fraction Compare Example 2", "[Fraction]")
    {
        const Fraction fractionA { 2, 6 };
        const Fraction fractionB { 1, 3 };

        REQUIRE(fractionA == fractionB);
    }

    TEST_CASE("Basic Fraction Compare Example 3", "[Fraction]")
    {
        const Fraction fractionA { 2, 6 };
        const Fraction fractionB { 1, 4 };

        REQUIRE(fractionA > fractionB);
    }

    bool CheckCompare(const Fraction& lhs, const Fraction& rhs)
    {
        const float resultLhs { static_cast<float>(lhs.numerator) / static_cast<float>(lhs.denominator) };
        const float resultRhs { static_cast<float>(rhs.numerator) / static_cast<float>(rhs.denominator) };

        const std::partial_ordering compareFloats { resultLhs <=> resultRhs };
        const std::weak_ordering compareFractions { lhs <=> rhs };

        return std::is_eq(compareFloats) == std::is_eq(compareFractions)
            && std::is_lt(compareFloats) == std::is_lt(compareFractions)
            && std::is_gt(compareFloats) == std::is_gt(compareFractions);
    }

    TEST_CASE("Brute Force Testing", "[Fraction]")
    {
        const auto numerators0 { GENERATE(0U, 1U, 2U, 3U, 4U, 5U) };
        const auto numerators1 { GENERATE(0U, 1U, 2U, 3U, 4U, 5U) };

        const auto denominators0 { GENERATE(1U, 2U, 3U, 4U, 5U) };
        const auto denominators1 { GENERATE(1U, 2U, 3U, 4U, 5U) };

        REQUIRE(CheckCompare({ numerators0, denominators0 }, { numerators1, denominators1 }));
    }
}
} // namespace tests
