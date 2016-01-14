#include <vector>

#include "Euler015.h"

ull latticePaths (ull _gridSize)
{
    if (_gridSize < 1) return 0;
    
    std::vector<ull > grid ((_gridSize + 1) * (_gridSize + 1), 0);
    
    //Borders
    ull i;
    ull j = _gridSize * (_gridSize + 1);
    
    for (i = 0; i < _gridSize; i++)
    {
        grid[j + i] = 1; 
    }
    
    i = _gridSize;
    for (j = 0; j < _gridSize; j++)
    {
        grid[j * (_gridSize +1) + i] = 1;
    }
    
    //Grid
    long long int row, column;
    for (row = _gridSize - 1; row >= 0; row--)
    {
        for (column = _gridSize -1; column >= 0; column--)
        {
            grid[row * (_gridSize +1) + column] = grid [(row+1) * (_gridSize +1) + column] + grid [row * (_gridSize +1) + (column+1)];
        }
    }
    
    return grid[0];    
}