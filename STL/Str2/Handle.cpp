#include "Vec.h"
#include "Handle.h"


// template specialization
template <>
Vec<char> *clone(const Vec<char> *ptr)
{
    return new Vec<char>(*ptr);
}