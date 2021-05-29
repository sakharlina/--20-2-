#include "Emloyee.h"

Emloyee::Emloyee(void):Person()
{
	post = "";
	wages = 0;
}

Emloyee::~Emloyee(void)
{
}

Emloyee::Emloyee(string N, int A, string P, float W):Person(N, A)
{
	post = P;
	wages = W;
}

Emloyee::Emloyee(const Emloyee& E)
{
	name = E.name;
	age = E.age;
	post = E.post;
	wages = E.wages;
}

void Emloyee::Set_post(string P)
{
	post = P;
}

void Emloyee::Set_wages(float W)
{
	wages = W;
}

Emloyee& Emloyee::operator=(const Emloyee& e)
{
	if (&e == this) return *this;
	name = e.name;
	age = e.age;
	post = e.post;
	wages = e.wages;
	return *this;
}

void Emloyee::Show()
{
	cout << "\nNAME: " << name;
	cout << "\nAGE: " << age;
	cout << "\nPOST: " << post;
	cout << "\nWAGES: " << wages;
}

void Emloyee::Input()
{
	cout << "\nNAME: "; cin >> name;
	cout << "\nAGE: "; cin >> age;
	cout << "\nPOST: "; cin >> post;
	cout << "\nWAGES: "; cin >> wages;
}
