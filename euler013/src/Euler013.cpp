#include "Euler013.h"
#include <vector>
#include <gmpxx.h>

typedef unsigned long long int ull;

std::string stringSum10dig (std::string _input)
{
    std::vector<mpz_class> bigNumV;
    mpz_class newNum = 0;
    
    for (ull i = 0; i < _input.length(); i++)
    {
        char a = _input.at(i);
        if (a != '\n')
        {
            int num = a - 48;
            if ((num >= 0) && (num <= 10))
            {
                newNum *= 10;
                newNum += num;
            }
        } 
        else 
        {
            bigNumV.push_back(newNum);
            newNum = 0;
        }
    }
    
    if (newNum)
    {
        bigNumV.push_back(newNum);
    }
    
    
    mpz_class total = 0;
    for (auto num : bigNumV)
    {
        total += num;
    }
    
    char* retp = mpz_get_str(NULL, 10, total.get_mpz_t());
    std::string ret (retp);
    ret.resize(10);
    
    return ret;

}