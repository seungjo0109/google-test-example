#include <cmath>
#include <iostream>
#include <stdexcept>

#include "number_generator.hpp"

std::vector<int> GenerateNumbers(int n, int limit)
{
    std::vector<int> result;
    
    if(limit<=0){
        throw std::runtime_error("Argument must be greater than 0");
    }

    for(int i=0; i<n; i++){
        result.push_back(i % limit);
    }
    return result;
}