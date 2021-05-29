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

Person& Person::operator=(const Person& p)
{
	if (&p == this) return *this;
	name = p.name;
	age = p.age;
	return *this;
}

void Person::HandleEvent(const TEvent& e)
{
	if (e.what == evMassage)
	{
		switch (e.command)
		{
		case cmGet:cout << "Name: " << Get_name() << endl;
			break;
		}
	}
}

void Person::Show()
{
	cout << "\nNAME: " << name;
	cout << "\nAGE: " << age;
}

void Person::Input()
{
	cout << "\nNAME: "; cin >> name;
	cout << "\nAGE: "; cin >> age;
}
