#pragma once
#include "Person.h"

class Emloyee :
    public Person
{
public:
    Emloyee(void);
public:
    ~Emloyee(void);
    void Show();
    void Input();
    Emloyee(string, int, string, float);
    Emloyee(const Emloyee&);
    string Get_post() { return post; }
    float Get_wages() { return wages; }
    void Set_post(string);
    void Set_wages(float);
    Emloyee& operator=(const Emloyee&);
protected:
    string post;
    float wages;
};
