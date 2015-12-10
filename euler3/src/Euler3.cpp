#include "Euler3.h"
#include <algorithm>

ull largestPrimeFactor (ull _num)
{
    if (_num <= 3) return _num;
    if (_num % 2 == 0) return (largestPrimeFactor(_num / 2));
    
    ull sq = sqrt(_num);
    if (sq * sq == _num)
    {
        return largestPrimeFactor(sq);
    }
    
    ull top = _num / 3;
    if (top % 2 == 0) top--;
    
    ull maxPrime = 0;
    for (ull i = 3; i <= top && (maxPrime == 0 || i <= sq); i += 2)
    {
        if (_num % i == 0) {
            if (i > sq) {
                maxPrime = std::max(largestPrimeFactor(i), maxPrime);
            } else {
                maxPrime = std::max(largestPrimeFactor(_num / i), maxPrime);
            }
        }
    }
    if (maxPrime) return maxPrime;
    
    return _num;
}
