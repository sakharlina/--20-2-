#pragma once
#include "Object.h"
#include <string>
#include <iostream>
using namespace std;

class Person :
    public Object
{
	public:
		Person(void);
	public:
		virtual ~Person(void);
		void Show();
		Person(string, int);
		Person(const Person&);
		string Get_name() { return name; }
		int Get_age() { return age; }
		void Set_name(string);
		void Set_age(int);
		Person& operator= (const Person&);

		friend istream& operator>>(istream& in, Person& p);
		friend ostream& operator<<(ostream& out, const Person& p);
	protected:
		string name;
		int age;
};
