#ifndef FRACTION_H
#define FRACTION_H

#include <compare>
namespace fraction {

struct Fraction {
    unsigned numerator;
    unsigned denominator;
};

std::weak_ordering operator<=>(const Fraction& lhs, const Fraction& rhs);
bool operator==(const Fraction& lhs, const Fraction& rhs);

}

#endif // !FRACTION_H
