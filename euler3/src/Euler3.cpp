#include "Euler3.h"
#include <algorithm>

ull largestPrimeFactor (ull _num)
{
    ull res = _num;
    for (ull i = 2; i <= _num;){
            if(_num % i == 0){
                    res = i;
                    _num = _num/i;
            } else {
                i++;
            }
    }
    
    return res;
}
