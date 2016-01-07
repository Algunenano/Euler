#include <new>
#include <iostream>

#include "Euler014.h"

ull individualChain (ull value)
{
    if (value < 2)
    {
        return 0;
    }
    
    if (value % 2 == 0)
    {
        return 1+individualChain(value/2);
    }

    return 1+individualChain(value * 3 +1);
}


ull longestChain (ull _limit)
{
    ull maxChain = 0;
    ull maxNum = 0;
    
    for (ull i = 1; i <= _limit; i++)
    {
        ull myChain = individualChain(i);
        if (myChain > maxChain)
        {
            maxChain = myChain;
            maxNum = i;
        }
    }
    
    return maxNum;
}
