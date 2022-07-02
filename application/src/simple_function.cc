#include "simple_function.hpp"

#include <cmath>
#include <cstring>
#include <iostream>
#include <stdexcept>


bool IsPositive(int x)
{
    return x >= 0;
}

int CountPositives(std::vector<int> const& input_vector)
{
    return std::count_if(input_vector.begin(), input_vector.end(), IsPositive);
}

void ToUpper(char* input_string)
{
    for(int i=0; i<strlen(input_string); i++){
        input_string[i] = toupper(input_string[i]);
    }
}

double CustomSqrt(double input)
{
    if(input < 0){
        // std::cout << "Exception thrown\n";
        throw std::runtime_error("Negative argument!");
    }
    return sqrt(input);
}