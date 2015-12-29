#include "Euler012.h"
#include <vector>

ull triangleDivisors (ull _divisors)
{
    if (_divisors == 0) return 0;
    if (_divisors == 1) return 1;

    std::vector<ull> primesV;
    primesV.push_back(2);
    ull num = 3;
    for (ull i = 3; ; num += i, i++)
    {
        //Check divisors of num
        ull check = num;
        ull div = 1;
        for (ull d : primesV)
        {
            ull factor = 0;
            while (check % d == 0)
            {
                factor++;
                check /= d;
            }
            div *= factor + 1;
            if (div >= _divisors) return num;
        }
        
        if (check != 1)
        {
            primesV.push_back(check);
        }
    }
    
    return 0;
}