#include "Euler012.h"
#include <vector>

ull triangleDivisors (ull _divisors)
{
    if (_divisors == 0) return 0;
    if (_divisors == 1) return 1;

    std::vector<ull> primesV (1,2);
    ull vSize = 1;
    ull* vData = primesV.data();
    
    ull num = 3;
    for (ull i = 3; ; num += i, i++)
    {
        //Check divisors of num
        ull check = num;
        ull div = 1;
        ull divisor = vData[0];
        for (ull d = 0; (divisor <= check) && (d < vSize); d++, divisor = vData[d])
        {
            if (check % divisor == 0)
            {
                ull factor = 0;
                while (check % divisor == 0)
                {
                    factor++;
                    check /= divisor;
                }
                div *= factor + 1;
                if (div >= _divisors) return num;
            }
        }
        
        if (check != 1)
        {
            primesV.push_back(check);
            vSize++;
            vData = primesV.data();
        }
    }
    
    return 0;
}