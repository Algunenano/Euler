#include <list>

#include "Euler4.h"
#include <cmath>

bool isPalindrome (ull _num)
{
    if (_num < 10) return true;
    std::list<ull> digits;
    
    int rest;
    while (_num != 0)
    {
        rest = _num % 10;
        digits.push_back(rest);
        _num = (_num -  rest) / 10;
    }
    
    while (digits.size() > 1)
    {
        if (digits.front() != digits.back()) return false;
        digits.pop_front();
        digits.pop_back();

    }
    
    return true;
}

ull largestPalindromeProduct (ull _digits)
{    
    ull bottom = std::pow (10, _digits - 1);
    ull top = bottom * 10 - 1;
    ull result = 0;
    
    for (ull big = (top - (top % 11)); big >= bottom; big -= 11) //All palindromes are 11*sth
    {
        if (big * top < result) break;
        
        for (ull low = top; low != bottom; low--) {
            ull aux = big * low;
            if (aux < result) break;
            if (isPalindrome(aux)) {
                result = aux;
            }
        }
    }
    
    return result;
}
