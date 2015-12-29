#include <list>
#include <vector>
#include <algorithm>
#include "Euler5.h"

std::list<ull> primes (ull _top)
{
    std::list<ull> result;
    
    for (ull i = 3; i <= _top; i += 2)
    {
        bool found = false;
        for (ull prime : result)
        {
            if (i % prime == 0)
            {
                found = true;
                break;
            }
        }
        if (!found) result.push_back(i);
    }
    
    result.push_front(2);
    return result;
}

ull smallestMultiple (ull _top)
{
    if (_top <= 2) return _top;
    std::list<ull> lPrimes = primes (_top);
    std::vector<ull> allPrimes 
        { 
            std::make_move_iterator(std::begin(lPrimes)),
            std::make_move_iterator(std::end(lPrimes)) 
        };
    
    std::vector<ull> finalMultiples (allPrimes.size(), 0);
    
    for (ull num = 2; num <= _top; num++)
    {        
        std::vector<ull> divisors (allPrimes.size(), 0);
        
        ull actualNum = num;
        while (actualNum > 1)
        {
            for (ull a = 0; a < allPrimes.size(); a++)
            {
                if (actualNum % allPrimes[a] == 0)
                {
                    divisors[a]++;
                    actualNum /= allPrimes[a];
                }
            }
        }

        for (ull updateMul = 0; updateMul < allPrimes.size(); updateMul++)
        {
            finalMultiples[updateMul] = std::max(finalMultiples[updateMul], divisors[updateMul]);
        }       
    }
    
    ull result = 1;    
    for (ull i = 0; i < allPrimes.size(); i++)
    {
        result *= std::pow (allPrimes[i], finalMultiples [i]);
    }
    
    return result;;
}