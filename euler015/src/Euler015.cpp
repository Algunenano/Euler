#include <vector>

#include "Euler015.h"

ull latticePaths (ull _gridSize)
{
    if (_gridSize < 1) return 0;
    
    ull solution = 1;
    
    for (ull i = _gridSize +1; i <= _gridSize * 2; i++)
    {
        solution *= i;
        solution /= i - _gridSize;
    }
    
    return solution;
}