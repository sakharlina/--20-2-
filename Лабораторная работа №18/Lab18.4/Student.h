#pragma once
#include "Person.h"

class Student :
    public Person
{
public:
    Student(void);
public:
    ~Student(void);
    Student(string, int, int);
    Student(const Student&);
    int Get_year() { return year; }
    Student& operator= (const Student&);
    Student& operator++();

    friend istream& operator>>(istream& in, Student& s);
    friend ostream& operator<<(ostream& out, const Student& s);

protected:
    int year;
};
