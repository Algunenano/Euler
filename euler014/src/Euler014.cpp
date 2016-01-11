#include <vector>
#include <algorithm>

#include "Euler014.h"

ull individualChain (const ull _value, std::vector<ull> &_calculated, const ull _size)
{
    if (_value < 2)
    {
        return 0;
    }
    
    if (_value >= _size)
    {
        return 1 + individualChain((_value % 2 ? _value * 3 + 1 : _value / 2), _calculated, _size);
    }
    
    if (_calculated[_value])
    {
        return _calculated[_value];
    }
    

    ull result = 1 + individualChain((_value % 2 ? _value * 3 + 1 : _value / 2), _calculated, _size);
    _calculated[_value] = result;

    return result;
}

ull longestChain (ull _limit)
{
    std::vector<ull> calculated (_limit + 1, 0);
    
    for (ull i = 1; i <= _limit; i++)
    {
        individualChain(i, calculated, calculated.size());
    }
    
    auto max = std::max_element(calculated.begin(), calculated.end());
    
    return std::distance(calculated.begin(), max);
}
