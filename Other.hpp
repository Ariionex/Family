#pragma once
#include <iostream>

class Time
{
public:
    Time()=default;
    Time(int, int);
    Time operator+(const Time& other);
    Time& define_time(int, int);
    friend std::ostream& operator<<(std::ostream&, const Time&);
private:
    int hour_;
    int minutes_;
};
