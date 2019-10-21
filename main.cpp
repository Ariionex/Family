#include <iostream>
#include "Family.hpp"
#include "Other.hpp"

int main()
{   
    
    Time c;
    c.define_time(0,70);
    std::cout<<c<<std::endl;
    //Family family;
    //family.make_it_happen();
    
return 0;
}

std::ostream& operator<<(std::ostream& out, const Time& t)
{
    out<<t.hour_<<":"<<t.minutes_;
    return out;
}
