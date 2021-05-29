#pragma once
#include <iostream>
using namespace std;

class Pair
{
	int first;
	double second;
public:
	Pair() { first = 0, second = 0; };
	Pair(int f, double s) { first = f, second = s; };
	Pair(const Pair& x) { first = x.first, second = x.second; };
	~Pair() {};
	int get_first() { return first; };
	double get_second() { return second; };
	void set_first(int f) { first = f; }
	void set_second(double s) { second = s; }
	Pair& operator=(const Pair&);
	Pair& operator++(); 
	Pair operator++(int); 
	Pair operator+(const Pair&);

	friend istream& operator >> (istream& in, Pair& x);
	friend ostream& operator << (ostream& out, const Pair& x);
};
