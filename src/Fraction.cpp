#include "Fraction.h"
#include <cmath>

namespace fraction {

std::weak_ordering operator<=>(const Fraction& lhs, const Fraction& rhs)
{
    if (lhs.denominator == 0 && rhs.denominator == 0) {
        return std::weak_ordering::equivalent;
    }
    if (lhs.denominator == 0) {
        return std::weak_ordering::greater;
    }
    if (rhs.denominator == 0) {
        return std::weak_ordering::less;
    }

    const unsigned valueA { lhs.numerator * rhs.denominator };
    const unsigned valueB { rhs.numerator * lhs.denominator };

    return valueA <=> valueB;
}

bool operator==(const Fraction& lhs, const Fraction& rhs)
{
    return std::is_eq(lhs <=> rhs);
}
}
