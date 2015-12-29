#include "Euler1.h"

ull sumMultiples35 (ull _top)
{
    ull sum = 0;
    for (ull i = 3; i < _top; i++)
    {
        if (i % 3 == 0)
        {
            sum += i;
        } else if (i % 5 == 0)
        {
            sum += i;
        }
    }
    
    return sum;
}