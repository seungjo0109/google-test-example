#pragma once

class Validator
{
public:
    Validator(int low, int high);
    bool InRange(int value_to_test);
private:
    int low_, high_;
};