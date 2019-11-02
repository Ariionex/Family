#include "Family.hpp"
#include <random>

Family::Family()
{
    members_.emplace_back(new Parent("Adam",30));
    members_.emplace_back(new Parent("Aleksandra",29));
    members_.emplace_back(new Child("Alicja",2));
    members_.emplace_back(new Child("Anna",1));
}

void Family::make_it_happen()
{
    if(busy_people_.size()>=members_.size())
        return;
    else
    {
        int options = 2;
        who_=members_[random_number(members_.size()-1)];
        while(who_->busy())
                who_=members_[random_number(members_.size()-1)];
        random_action(random_number(options));
        busy_people_.emplace_back(who_);
    }
}

void Family::performing_tasks()
{
    for(auto it=busy_people_.begin(); it!=busy_people_.end();)
    {
        Person & some = *(*it);
        if(some.busy())
            some.decrement_time();
        else
        {
            it=busy_people_.erase(it);
            it--;
        }
        it++;
    }    
}

int Family::random_number(int max_num)
{
    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(0, max_num);
    int result=uniform_dist(e1);
    return result;
}

void Family::random_action(int choice)
{
    switch (choice)
    {
    case 0:
        std::cout<<who_->get_name()<<" -> ";
        who_->sleep();
        break;
    case 1:
        std::cout<<who_->get_name()<<" -> ";
        who_->eat();
        break;
    case 2:
        std::cout<<who_->get_name()<<" -> ";
        who_->walk();
        break;
    default:
        break;
    }
}
void Person::sleep()
{
    std::cout<<__FUNCTION__<<std::endl;
    Time t(0,20);
    time_+=t;
    show_time();
}
void Person::eat()
{
    std::cout<<__FUNCTION__<<std::endl;
    Time t(0,5);
    time_+=t;
    show_time();
}
void Person::walk()
{
    std::cout<<__FUNCTION__<<std::endl;
    Time t(0,10);
    time_+=t;
    show_time();
}

bool Person::busy() {return (time_ == 0)? 0:1;}

void Person::show_time() 
{
    std::cout<<"Dodano ["<<time_<<"] czasu."<<std::endl;
}

void Person::show_time2()
{
    std::cout<<"Pozostalo <<<"<<time_<<">>> czasu."<<std::endl;
}

Time& Person::decrement_time() {return time_--;}

std::string Person::get_name() {return this->name_;}

Person::Person(std::string name, int age, int hour, int minutes) 
            :name_(name),
             age_(age),
             time_(hour, minutes)
{}

Person::Person(std::string name, int age) 
            :name_(name),
             age_(age),
             time_(0, 0)
{}

Parent::Parent(std::string name, int age, int hour, int minutes) 
            : Person(name, age, hour, minutes)
{}

Parent::Parent(std::string name, int age) 
            : Person(name, age)
{}

Child::Child(std::string name, int age, int hour, int minutes)
            : Person(name, age, hour, minutes)
{}

Child::Child(std::string name, int age) 
            : Person(name, age)
{}
