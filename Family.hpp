#pragma once
#include <iostream>
#include <vector>
#include <memory>

class Person
{
public:
    Person(std::string, int);
    virtual std::string get_name();
    virtual void sleep();
    virtual void eat();
    virtual void walk();
private:
    std::string name_;
    int age_;
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
    void random_action(S_ptr, int);
private:
    Members members_;
    S_ptr who_;
};

class Parent : public Person 
{
public:
    Parent(std::string, int);
private:
};

class Child : public Person 
{
public:
    Child(std::string, int);
private:
};