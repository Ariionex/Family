#include <iostream>
#include "Family.hpp"
#include "Time.hpp"

int main()
{   

return 0;
}

std::ostream& operator<<(std::ostream& out, const Time& t)
{
    if(t.minutes_<10)
        out<<t.hour_<<":0"<<t.minutes_;
    else
        out<<t.hour_<<":"<<t.minutes_;
    return out;
}
