
#include "Compare.hpp"

bool Compare::operator()(const int lhs, const int rhs) const
{
    return (lhs % 97) < (rhs % 97);
}