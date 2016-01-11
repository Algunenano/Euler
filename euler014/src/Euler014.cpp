#include <vector>
#include <algorithm>

#include "Euler014.h"

ull individualChain (ull value, std::vector<ull> &calculated)
{
    if (value < 2)
    {
        return 0;
    }
    
    if (value >= calculated.size())
    {
        return 1 + individualChain((value % 2 ? value * 3 + 1 : value / 2), calculated);
    }
    
    if (calculated[value])
    {
        return calculated[value];
    }
    

    ull result = 1 + individualChain((value % 2 ? value * 3 + 1 : value / 2), calculated);
    calculated[value] = result;

    return result;
}

ull longestChain (ull _limit)
{
    std::vector<ull> calculated (_limit + 1, 0);
    
    for (ull i = 1; i <= _limit; i++)
    {
        individualChain(i, calculated);
    }
    
    auto max = std::max_element(calculated.begin(), calculated.end());
    
    return std::distance(calculated.begin(), max);
}
