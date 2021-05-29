#include "Pair.h"

Pair::Pair()
{
	first = 0;
	second = 0;
}

Pair::Pair(int F, double S)
{
	first = F;
	second = S;
}

Pair::Pair(const Pair& p)
{
	first = p.first;
	second = p.second;
}

Pair Pair::operator=(const Pair& p)
{
	if (&p == this) return *this;
	first = p.first;
	second = p.second;
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

Pair::~Pair()
{
}

ostream& operator<<(ostream& out, const Pair& p)
{
	out << p.first << " : " << p.second << "\n";
	return out;
}

istream& operator>>(istream& in, Pair& p)
{
	cout << "first? "; cin >> p.first;
	cout << "second? "; cin >> p.second;
	return in;
}

fstream& operator>>(fstream& fin, Pair& p)
{
	fin >> p.first;
	fin >> p.second;
	return fin;
}

fstream& operator<<(fstream& fout, const Pair& p)
{
	fout << p.first << "\n" << p.second << "\n";
	return fout;
}
