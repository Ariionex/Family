#pragma once
#include <iostream>

class Time
{
public:
    Time();
    Time(int, int);
    Time operator+(const Time&);
    Time& operator+=(const Time&);
    Time operator-(const Time&);
    Time& operator-=(const Time&);
    Time& operator++(int);
    Time& operator--(int);
    Time& define_time(int, int);
    friend std::ostream& operator<<(std::ostream&, const Time&);
private:
    int hour_;
    int minutes_;
};
