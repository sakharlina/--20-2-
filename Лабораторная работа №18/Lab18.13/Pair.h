#pragma once
#include <iostream>
using namespace std;
class Pair
{
public:
	int first;
	double second;
public:
	Pair() { first = 0, second = 0.0; };
	Pair(int f, double s) { first = f, second = s; };
	Pair(const Pair& p) { first = p.first, second = p.second; };
	~Pair() {};
	int get_first() { return first; };
	double get_second() { return second; };
	void set_first(int f) { first = f; }
	void set_second(double s) { second = s; }
	
	Pair& operator=(const Pair&);
	Pair operator+(const Pair&);
	Pair operator-(const Pair&);
	Pair operator/(const int&);
	friend bool operator< (const Pair&, const Pair&);
	friend bool operator> (const Pair&, const Pair&);
	friend bool operator==(const Pair&, const Pair&);

	friend istream& operator >> (istream&, Pair&);
	friend ostream& operator << (ostream&, const Pair&);
};
