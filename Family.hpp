#pragma once
#include <iostream>
#include <vector>
#include <memory>
#include "Time.hpp"
#include <unistd.h>

class Person
{
public:
    Person()=default;
    Person(std::string, int);
    Person(std::string, int, int, int);
    bool busy();
    void show_time();
    void show_time2();
    Time& decrement_time();
    std::string get_name();
    virtual void sleep();
    virtual void eat();
    virtual void walk();
private:
    std::string name_;
    int age_;
    Time time_;
};

using S_ptr = std::shared_ptr<Person>;
using Members = std::vector<S_ptr>;

class Family
{
public:
    Family();
    ~Family()=default;
    void make_it_happen();
    int random_number(int);
    void random_action(int);
    void performing_tasks();
private:
    Members members_;
    Members busy_people_;
    S_ptr who_;
};

class Parent : public Person 
{
public:
    Parent()=default;
    Parent(std::string, int); 
    Parent(std::string, int, int, int);
private:
};

class Child : public Person 
{
public:
    Child()=default;
    Child(std::string, int);
    Child(std::string, int, int, int);
private:
};