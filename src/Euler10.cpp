#include <list>
#include <math.h>
#include <iostream>
#include "Euler10.h"

bool isPrime (ull _num, std::list<ull>& _calculated) {
    for (ull calc : _calculated){
        if (_num % calc == 0) return false;
        if (calc > sqrt(_num)) return true;
    }
    return true;
}

ull sumPrime (ull _top) {
    if (_top <= 0 ) {
        return false; //Not calculated
    } else if (_top < 5) {
        return (_top != 4);
    }
    
    std::list<ull> calculated;
    calculated.push_back(2);
    calculated.push_back(3);
    for (ull i = 5; i <= _top; i+=2){
        if (isPrime(i, calculated)) calculated.push_back(i);
    }
    
    ull final = 0;
    for (ull calc : calculated) {
        final += calc;
//        std::cout << calc << "\n";
    }
    
    return final;   
}

