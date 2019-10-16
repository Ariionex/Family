#include "Family.hpp"

Family::Family()
{
    who_=nullptr;
    members_.emplace_back(Parent("Adam",30));
    members_.emplace_back(Parent("Aleksandra",29));
    members_.emplace_back(Child("Alicja",2));
    members_.emplace_back(Child("Anna",1));
}
Family::~Family()
{
    delete who_;
    who_=nullptr;
}

Person::Person(std::string name, int age) 
            :name_(name), 
             age_(age)
{}

Parent::Parent(std::string name, int age) : Person(name, age){}

Child::Child(std::string name, int age): Person(name, age){}