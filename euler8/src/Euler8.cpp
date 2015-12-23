#include "Euler8.h"
#include <vector>

std::vector<ull> str2Int (std::string _input)
{
    std::vector<ull> uVec;
    
    for (ull i = 0; i < _input.size(); i++)
    {
        char a = _input.at(i);
        int num = a - 48;
        if (num >= 0 && num <= 9)
        {
            uVec.push_back(atoll(&a));
        }
    }
    
    return uVec;
}

ull largestProduct (std::string _input, ull _digits)
{
    if (_digits == 0) return 0;
    
    std::vector<ull> inputDigits = str2Int(_input);
    std::vector<ull> finalProduct (inputDigits);
    std::vector<ull> prevProduct (inputDigits);
    
    for (ull i = 1; i < _digits; i++)
    {
        finalProduct.data()[0] = 0;
        for (ull s = 1; s < prevProduct.size(); s++)
        {
            finalProduct.data()[s] = inputDigits.at(s) * prevProduct.at(s - 1);
        }
        prevProduct = finalProduct;
    }
    
    ull max = 0;
    for (ull i = 0; i < finalProduct.size(); i++)
    {
        max = std::max(max, finalProduct.at(i));
    }
    
    return max;
}