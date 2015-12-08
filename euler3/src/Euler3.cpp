#include "Euler3.h"
#include <algorithm>

ull largestPrimeFactor (ull _num)
{
    if (_num <= 3) return _num;
    if (_num % 2 == 0) return (largestPrimeFactor(_num / 2));
    
    ull sq = sqrt (_num);
    if (sq * sq == _num) return largestPrimeFactor(sq);
    if (sq % 2 == 0) sq--;
    
    ull maxPrime = 0;
    for (ull i = sq; i > 3; i -= 2)
    {
        if (_num % i == 0) maxPrime = std::max(largestPrimeFactor(i), maxPrime);
    }   
    if (maxPrime) return maxPrime;
    
    return _num;
}
