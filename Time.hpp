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
    bool operator==(const Time&);
    bool operator==(int);
    bool operator<(const Time&);
    bool operator<=(const Time&);
    bool operator>(const Time&);
    bool operator>=(const Time&);
    Time& define_time(int, int);
    friend std::ostream& operator<<(std::ostream&, const Time&);
private:
    int hour_;
    int minutes_;
};
