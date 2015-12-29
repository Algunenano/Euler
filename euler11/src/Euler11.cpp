#include "Euler11.h"
#include <vector>
#include <assert.h>

std::vector<std::vector<ull>> str2UllGrid (std::string _input)
{
    std::vector<std::vector<ull>> result;
    std::vector<ull> line;
    ull accumulated = 0;
    int num;
    bool addZero = false;
    
    for (ull i = 0; i < _input.size(); i++)
    {
        char a = _input.at(i);
        num = a - 48;
        if (num >= 0 && num <= 9)
        {
            if (num == 0)
            {
                addZero = true;
            } else {
                addZero = false;
            }
            accumulated = accumulated * 10 + num;             
        } else if (a == ' ')
        {
            if ((accumulated) || addZero) {
                line.push_back(accumulated);
                accumulated = 0;
            }
        } else if (a == '\n')
        {
            if ((accumulated) || addZero)
            {
                line.push_back(accumulated);
                accumulated = 0;
            }
            if (line.size())
            {
                result.push_back(line);
                line.erase(line.begin(), line.end());
            }
       }
        
        
    }
    if ((accumulated) || addZero) line.push_back(accumulated);
    if (line.size()) result.push_back(line);
    
    ull lineSize = result.front().size();
    assert (result.size() == lineSize);
    for (auto myLine : result)
    {
        assert(myLine.size() == lineSize);
    }
    
    return result;
}

ull largestGridProduct (std::string _input, ull _digits)
{
    if (!_digits) return 0;
    
    std::vector<std::vector<ull>> inputMat = str2UllGrid(_input);
    if (inputMat.front().size() <= _digits) return 0;
    
    std::vector<std::vector<ull>> intermMat(inputMat);
    ull max = 0;
    for (auto line : inputMat)
        for (ull element : line)
            max = std::max(element, max);
    
    
    //Calculating right direction product
    for (ull step = 1; step < _digits; step++)
    {
        for (ull lines = 0; lines < inputMat.size(); lines++)
        {
            //Last right columns are ignored as they cannot be calculated
            for (ull it = 0; it < inputMat.front().size() - _digits; it++)
            {
                intermMat.at(lines).data()[it] *= inputMat.at(lines).data()[it + step];
                max = std::max(intermMat.at(lines).data()[it], max);
            }
        }
    }
    
    intermMat = inputMat;
    //Left
    for (ull step = 1; step < _digits; step++)
    {
        for (ull lines = 0; lines < inputMat.size(); lines++)
        {
            //Only the last right columns are important, as the rest has been calculated already
            for (ull it = inputMat.front().size() - 1; it > inputMat.front().size() - _digits - 1; it--)
            {
                intermMat.at(lines).data()[it] *= inputMat.at(lines).data()[it - step];
                max = std::max(intermMat.at(lines).data()[it], max);
            }
        }
    }
    
    intermMat = inputMat;
    //Down
    for (ull step = 1; step < _digits; step++)
    {
        //Ignoring last bottom rows
        for (ull lines = 0; lines < inputMat.size() - _digits; lines++)
        {
            for (ull it = 0; it < inputMat.front().size(); it++)
            {
                intermMat.at(lines).data()[it] *= inputMat.at(lines + step).data()[it];
                max = std::max(intermMat.at(lines).data()[it], max);
            }
        }
    }
    
    intermMat = inputMat;
    //Up
    for (ull step = 1; step < _digits; step++)
    {
        //Only check bottom rows
        for (ull lines = inputMat.size() - 1; lines > inputMat.size() - _digits - 1; lines--)
        {
            for (ull it = 0; it < inputMat.front().size(); it++)
            {
                intermMat.at(lines).data()[it] *= inputMat.at(lines - step).data()[it];
                max = std::max(intermMat.at(lines).data()[it], max);
            }
        }
    }
    
    intermMat = inputMat;
    //Diagonal right + bottom
    for (ull step = 1; step < _digits; step++)
    {
        //Ignore bottom rows
        for (ull lines = 0; lines < inputMat.size() - _digits; lines++)
        {
            //Ignore right columns
            for (ull it = 0; it < inputMat.front().size() - _digits; it++)
            {
                intermMat.at(lines).data()[it] *= inputMat.at(lines + step).data()[it + step];
                max = std::max(intermMat.at(lines).data()[it], max);
            }
        }
    }
    
    intermMat = inputMat;
    //Diagonal left + up
    for (ull step = 1; step < _digits; step++)
    {
        //Only check bottom rows
        for (ull lines = inputMat.size() - 1; lines > inputMat.size() - _digits - 1; lines--)
        {
            //Only check the allowed columns 
            for (ull it = _digits; it < inputMat.front().size(); it++)
            {
                intermMat.at(lines).data()[it] *= inputMat.at(lines - step).data()[it - step];
                max = std::max(intermMat.at(lines).data()[it], max);
            }
        }
        
        //Now we check the valid right columns. We also ignored the last ones as they have been
        //just calculated previously
        for (ull lines = _digits; lines < inputMat.size() - _digits; lines++)
        {
            for (ull it = inputMat.front().size() - 1; it > inputMat.front().size() - _digits - 1; it--)
            {
                intermMat.at(lines).data()[it] *= inputMat.at(lines - step).data()[it - step];
                max = std::max(intermMat.at(lines).data()[it], max);
            }
        }
    }
    
    intermMat = inputMat;
    //Diagonal top + right
    for (ull step = 1; step < _digits; step++)
    {
        //Ignore top rows
        for (ull lines = _digits; lines < inputMat.size(); lines++)
        {
            //Ignore right columns
            for (ull it = 0; it < inputMat.front().size() - _digits; it++)
            {
                intermMat.at(lines).data()[it] *= inputMat.at(lines - step).data()[it + step];
                max = std::max(intermMat.at(lines).data()[it], max);
            }
        }
    }
    
    intermMat = inputMat;
    //Diagonal bottom + left
    for (ull step = 1; step < _digits; step++)
    {
        //Only check top rows
        for (ull lines = 0; lines < _digits; lines++)
        {
            //Only check the allowed columns
            for (ull it = _digits; it < inputMat.front().size(); it++)
            {
                intermMat.at(lines).data()[it] *= inputMat.at(lines + step).data()[it - step];
                max = std::max(intermMat.at(lines).data()[it], max);
            }
        }
        
        //Now we check the valid right columns. We also ignored the last ones as they have been
        //just calculated previously
        for (ull lines = _digits; lines < inputMat.size() - _digits; lines++)
        {
            for (ull it = inputMat.front().size() - 1; it > inputMat.front().size() - _digits - 1; it--)
            {
                intermMat.at(lines).data()[it] *= inputMat.at(lines + step).data()[it - step];
                max = std::max(intermMat.at(lines).data()[it], max);
            }
        }
    }
    
    return max;
}
