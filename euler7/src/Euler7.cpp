#include "Euler7.h"
#include <list>

ull primeN (ull _top)
{
    if (_top == 0) return 1;
    if (_top == 1) return 2; //We are avoiding checking for multiples of 2
    
    std::list<ull> primes;
    ull size = 1;
    
    for (ull i = 3; size != _top; i+= 2)
    {
        bool found = false;
        for (ull prime : primes)
        {
            if (i % prime == 0)
            {
                found = true;
                break;
            }
        }
        if (!found)
        {
            primes.push_back(i);
            size++;
        }        
    }
    
    return primes.back();
}