#pragma once
#include <iostream>
#include <vector>

class Person
{
public:
    Person(std::string, int);
private:
    std::string name_;
    int age_;
};

using Members = std::vector<Person>;

class Family
{
public:
    Family();
    ~Family();
private:
    Members members_;
    Person *who_;
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