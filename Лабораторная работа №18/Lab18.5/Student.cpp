#include "Student.h"

Student::Student(void) :Person()
{
	year = 0;
}

Student::~Student(void)
{
}

Student::Student(string N, int A, int Y) :Person(N, A)
{
	year = Y;
}

Student::Student(const Student& S)
{
	name = S.name;
	age = S.age;
	year = S.year;
}

void Student::Set_year(int Y)
{
	year = Y;
}

Student& Student::operator= (const Student& S)
{
	if (&S == this) return *this;
	name = S.name;
	age = S.age;
	year = S.year;
	return *this;
}

Student& Student::operator++()
{
	int P = year;
	P++;
	year = P;
	return *this;
}

istream& operator>> (istream& in, Student& s)
{
	cout << "Name: "; in >> s.name;
	cout << "Age: "; in >> s.age;
	cout << "Year: "; in >> s.year;
	cout << endl;
	return in;
}

ostream& operator<< (ostream& out, const Student& s)
{
	out << "\nName: " << s.name;
	out << "\nAge: " << s.age;
	out << "\nYear: " << s.year;
	out << endl;
	return out;
}

void Student::Show()
{
	cout << "\nName: " << name;
	cout << "\nAge: " << age;
	cout << "\nYear: " << year;
	cout << endl;
}
