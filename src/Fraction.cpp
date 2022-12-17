#include "Fraction.h"
#include <cassert>
#include <cmath>

namespace fraction {

std::weak_ordering operator<=>(const Fraction& lhs, const Fraction& rhs)
{
    assert(lhs.denominator != 0);
    assert(rhs.denominator != 0);

    const unsigned valueA { lhs.numerator * rhs.denominator };
    const unsigned valueB { rhs.numerator * lhs.denominator };

    return valueA <=> valueB;
}

bool operator==(const Fraction& lhs, const Fraction& rhs)
{
    return std::is_eq(lhs <=> rhs);
}
}
