#include "Other.hpp"

Time::Time(int h, int m) : hour_(h), minutes_(m)
{}

Time Time::operator+(const Time& other)
{
    Time x(0,0);
    int all;
    x.hour_=hour_+other.hour_;
    all=minutes_+other.minutes_;
    x.hour_+=all/60;
    x.minutes_+=all%60;

    return x;
}
Time& Time::define_time(int h, int m)
{
    hour_=h;
    if(m<60)
        minutes_=m;
    else
    {
        hour_+=m/60;
        minutes_=m%60;
    }
    return *this;
}

