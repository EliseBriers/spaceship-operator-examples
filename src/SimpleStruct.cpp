#include "SimpleStruct.h"

namespace simple_struct_old {

bool operator==(const SimpleStruct& lhs, const SimpleStruct& rhs)
{
    return lhs.value == rhs.value;
}

bool operator<(const SimpleStruct& lhs, const SimpleStruct& rhs)
{
    return lhs.value < rhs.value;
}

bool operator>(const SimpleStruct& lhs, const SimpleStruct& rhs)
{
    return rhs < lhs;
}

bool operator<=(const SimpleStruct& lhs, const SimpleStruct& rhs)
{
    return !(lhs > rhs);
}

bool operator>=(const SimpleStruct& lhs, const SimpleStruct& rhs)
{
    return !(lhs < rhs);
}
}

namespace simple_struct_new {

std::strong_ordering operator<=>(const SimpleStruct& lhs, const SimpleStruct& rhs)
{
    return lhs.value <=> rhs.value;
}

bool operator==(const SimpleStruct& lhs, const SimpleStruct& rhs)
{
    return std::is_eq(lhs <=> rhs);
}
}
