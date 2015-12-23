#include "Euler9.h"

// a^2 + b^2 = c^2
// a + b + c = _sum
// returns a * b * c || 0
ull pytagTripletProduct (ull _sum)
{    
    
    for (ull a = 1; a < _sum / 3; a++)
    {
        for (ull b = a + 1; b < _sum * 2 / 3; b++)
        {
            ull c = _sum - a - b;
            if (a*a + b*b == c*c) return (a*b*c);
        }
    }
    
    return 0;
}