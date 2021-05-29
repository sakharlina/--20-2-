#include "Pair.h"
#include <iostream>
using namespace std;

Pair& Pair::operator=(const Pair& p)
{
	if (&p == this) return *this;
	first = p.first;
	second = p.second;
	return *this;
}

Pair& Pair::operator+(const Pair& p)
{
	int kf = first + p.first;
	double ks = second + p.second;
	Pair temp(kf, ks);
	return temp;
}

Pair Pair::operator-(const Pair& p)
{
	int temp1 = first * 100 - second * 100;
	int temp2 = p.first * 100 - p.second * 100;
	Pair t;
	t.first = (temp1 - temp2) / 100;
	t.second = (temp1 - temp2) % 100;
	return t;
}

Pair Pair::operator/(const Pair& p)
{
	int S1 = first + second;
	int S2 = p.first + p.second;
	Pair t;
	t.first = S1 / S2;
	t.second = S1 / S2;
	return t;
}

Pair Pair::operator/(const int& k)
{
	int temp = first * 100 + second * 100;
	Pair t;
	t.first = (temp / k) / 100;
	t.second = (temp / first) % 100;
	return t;
}

bool Pair::operator<(const Pair& p)
{
	if (first < p.first) return true;
	if (first == p.first && second < p.second) return true;
	return false;
}
bool Pair::operator>(const Pair& p)
{
	if (first > p.first) return true;
	if (first == p.first && second > p.second) return true;
	return false;
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
