#include <iostream>
#include "Person.h"
#include "Student.h"
using namespace std;

void F1(Person& p)
{
	p.Set_name("Ann");
	cout << p;
}

Person F2()
{
	Student s("Nick", 17, 2021);
	return s;
}

void main()
{
	Person a;
	cin >> a;
	cout << a;
	Person b("Alina", 18);
	cout << b;
	a = b;
	cout << a;

	Student s;
	cin >> s;
	++s;
	cout << s;

	F1(s);
	a = F2();
	cout << a;
}
