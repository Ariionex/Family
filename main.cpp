#include <iostream>
#include "Family.hpp"
#include "Time.hpp"

int main()
{
    Family family;
    while(true)
    {
        family.make_it_happen();
        family.performing_tasks();
        sleep(1);
    }
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
