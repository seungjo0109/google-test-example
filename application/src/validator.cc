#include <stdexcept>

#include "validator.hpp"


Validator::Validator(int low, int high): low_(low), high_(high)
{

}

bool Validator::InRange(int value_to_test)
{
    return low_ <= value_to_test && value_to_test <= high_;
}