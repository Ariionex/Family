#include "Time.hpp"

Time::Time() : hour_(0), minutes_(0)
{}

Time::Time(int h, int m) 
{
    define_time(h,m);
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

Time Time::operator+(const Time& other)
{
    Time x(0,0);
    int all;
    x.hour_=hour_+other.hour_;
    all=minutes_+other.minutes_;
    x.hour_+=all/60;
    x.minutes_=all%60;
    return x;
}

Time& Time::operator+=(const Time& other)
{
    int all;
    hour_+=other.hour_;
    all=minutes_+other.minutes_;
    hour_+=all/60;
    minutes_=all%60;
    return *this;
}

Time Time::operator-(const Time& other)
{
    Time x(0,0);
    x.hour_=hour_-other.hour_;
    if(minutes_<other.minutes_ && hour_<=other.hour_)
    {
        x.hour_=0;
        x.minutes_=0;
    }
    else if(minutes_<other.minutes_ && hour_>other.hour_)
    {
        x.hour_-=1;
        x.minutes_=(minutes_+60)-other.minutes_;
    }
    else
        x.minutes_=minutes_-other.minutes_;
    return x;
}

Time& Time::operator-=(const Time& other)
{
    if(minutes_<other.minutes_ && hour_<=other.hour_)
    {
        hour_=0;
        minutes_=0;
    }
    else if(minutes_<other.minutes_ && hour_>other.hour_)
    {
        hour_-=other.hour_;
        hour_-=1;
        minutes_=(minutes_+60)-other.minutes_;
    }
    else
    {
        hour_-=other.hour_;
        minutes_-=other.minutes_;
    }
    if(hour_<0)
    {
        hour_=0;
        minutes_=0;
    }
    return *this;
}

Time& Time::operator++(int n)
{
    minutes_++;
    if(minutes_ >= 60)
    {
        hour_++;
        minutes_=0;
    }
    return *this;
}

Time& Time::operator--(int n)
{
    if(hour_== 0 && minutes_== 0)
    {
        std::cout<<"ERROR"<<std::endl;
        std::cout<<"Current time = 0:00"<<std::endl;
        std::exit(EXIT_FAILURE);
    }
    else
    {
        minutes_--;
        if(minutes_ < 0)
        {
            hour_--;
            minutes_=59;
        }
        return *this;
    }
}

bool Time::operator==(const Time& other)
{
    return (hour_==other.hour_ && minutes_==other.minutes_)? 1:0;
}

bool Time::operator==(int n)// fix it
{
    return (hour_==0 && minutes_==0)? 1:0; 
}

bool Time::operator<(const Time& other)
{
    return (hour_<other.hour_ || (hour_==other.hour_ && minutes_<other.minutes_))? 1:0;
}

bool Time::operator<=(const Time& other)
{
    if(hour_<other.hour_)
        return 1;
    else if (hour_==other.hour_ && minutes_<=other.minutes_)
        return 1;
    else
        return 0;
}

bool Time::operator>(const Time& other)
{
    return (hour_>other.hour_ || (hour_==other.hour_ && minutes_>other.minutes_))? 1:0;
}

bool Time::operator>=(const Time& other)
{
    if(hour_>other.hour_)
        return 1;
    else if (hour_==other.hour_ && minutes_>=other.minutes_)
        return 1;
    else
        return 0;
}
