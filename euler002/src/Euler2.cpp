#include "Euler2.h"

ull fibEvenSum (ull _top)
{
    if (_top < 5) return 2;
    ull tlast = 1;
    ull last = 2;
    ull sum = 2;
    
    for (ull next = 3; next < _top; tlast = last, last = next, next += tlast)
    {
        if (next % 2 == 0) sum+= next;
    }
    
    return sum;    
}