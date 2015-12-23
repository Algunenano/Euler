#include "Euler6.h"

ull sumSquareDiff (ull _top)
{
    ull sqsum = 0;
    ull sumsq = 0;
    
    for (ull i = 1; i <= _top; i++)
    {
        sqsum += i*i;
        sumsq += i;
    }
    
    sumsq *= sumsq;
    
    return sumsq - sqsum;    
}
