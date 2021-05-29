#include "Pair.h"

Pair& Pair::operator=(const Pair& p)
{
	if (&p == this) return *this;
	first = p.first;
	second = p.second;
	return *this;
}

Pair Pair::operator+(const Pair& p)
{
	Pair tmp;
	tmp.first = first + p.first;
	tmp.second = first + p.second;
	return tmp;
}

Pair Pair::operator-(const Pair& p)
{
	Pair tmp;
	tmp.first = first - p.first;
	tmp.second = second - p.second;
	return tmp;
}

Pair Pair::operator/(const int& t)
{
	Pair tmp;
	tmp.first = first / t;
	tmp.second = second / t;
	return tmp;
}

bool operator<(const Pair& p1, const Pair& p2)
{
	return p1.first < p2.first;
}
bool operator>(const Pair& p1, const Pair& p2)
{
	return p1.first > p2.first;
}

bool operator== (const Pair& p1, const Pair& p2)
{
	if (p1.first == p2.first && p1.second == p2.second)
		return true;
	else return false;
}

istream& operator >> (istream& in, Pair& p)
{
	cout << "first? "; in >> p.first;
	cout << "second? "; in >> p.second;
	return in;
}

ostream& operator << (ostream& out, const Pair& p)
{
	return (out << p.first << " : " << p.second);
}
