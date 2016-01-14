#include "Euler016.h"
#include <gmpxx.h>

ull powerDigitSum (ull _power)
{
    mpz_class powNum;
    mpz_pow_ui(powNum.get_mpz_t(), mpz_class(2).get_mpz_t(), _power);

    char* retp = mpz_get_str(NULL, 10, powNum.get_mpz_t());
    
    ull solution = 0;
    uint size = strlen(retp);
    for (uint i = 0; i < size; i++)
    {
        solution += retp[i];
    }
    
    solution -= '0' * size;
    
    return solution;
}