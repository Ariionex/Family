#include "Family.hpp"
#include <iostream>
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
    who_=members_[random_number(members_.size()-1)];
    int options = 2;
    random_action(who_,random_number(options));
}
int Family::random_number(int max_num)
{
    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(0, max_num);
    int result=uniform_dist(e1);
    return result;
}
void Family::random_action(S_ptr ptr, int choice)
{
    switch (choice)
    {
    case 0:
        std::cout<<ptr->get_name()<<" -> ";
        ptr->sleep();
        break;
    case 1:
        std::cout<<ptr->get_name()<<" -> ";;
        ptr->eat();
        break;
    case 2:
        std::cout<<ptr->get_name()<<" -> ";;
        ptr->walk();
        break;
    default:
        break;
    }
}
void Person::sleep()
{std::cout<<__FUNCTION__<<std::endl;}
void Person::eat()
{std::cout<<__FUNCTION__<<std::endl;}
void Person::walk()
{std::cout<<__FUNCTION__<<std::endl;}

std::string Person::get_name() {return this->name_;}

Person::Person(std::string name, int age) 
            :name_(name), 
             age_(age)
{}

Parent::Parent(std::string name, int age) : Person(name, age){}

Child::Child(std::string name, int age): Person(name, age){}