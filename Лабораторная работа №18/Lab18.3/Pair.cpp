#include "Pair.h"
#include <iostream>
using namespace std;

Pair& Pair::operator=(const Pair& x)
{
	if (&x == this) return *this;
	first = x.first;
	second = x.second;
	return *this;
}

Pair& Pair::operator++()
{
	if (first > second)
		cout << first << " > " << second << endl;
	else
		cout << second << " > " << first << endl;
	first++;
	return *this;
}

Pair Pair::operator++(int)
{
	int F = first;
	double S = second;
	if (F > S)
		cout << F << " > " << S << endl;
	else
		cout << S << " > " << F << endl;
	Pair x(first, second);
	second++;
	return x;
}
Pair Pair::operator+(const Pair& x)
{
	int F = first;
	double S = second;
	if (F > S)
		cout << F << " > " << S << endl;
	else
		cout << S << " > " << F << endl;
	Pair p;
	p.first++;
	p.second++;
	return p;
}

istream& operator >> (istream& in, Pair& x)
{
	cout << "first? "; in >> x.first;
	cout << "second? "; in >> x.second;
	return in;
}

ostream& operator << (ostream& out, const Pair& x)
{
	return (out << x.first << " : " << x.second);
}
