#include "Person.h"
Person::Person(void)
{
	name = "";
	age = 0;
}

Person::~Person(void)
{
}

Person::Person(string N, int A)
{
	name = N;
	age = A;
}

Person::Person(const Person& pers)
{
	name = pers.name;
	age = pers.age;
}

void Person::Set_name(string N)
{
	name = N;
}

void Person::Set_age(int A)
{
	age = A;
}

Person& Person::operator= (const Person& p)
{
	if (&p == this) return *this;
	name = p.name;
	age = p.age;
	return *this;
}

istream& operator>> (istream& in, Person& p)
{
	cout << "Name: "; in >> p.name;
	cout << "Age: "; in >> p.age;
	cout << endl;
	return in;
}

ostream& operator<< (ostream& out, const Person& p)
{
	out << "\nName: " << p.name;
	out << "\nAge: " << p.age;
	out << endl;
	return out;
}

void Person::Show()
{
	cout << "\nName: " << name;
	cout << "\nAge: " << age;
	cout << endl;
}
