#pragma once
#include <iostream>
#include <string>
using namespace std;

class Iterator
{
	friend class Vector;
public:
	Iterator() { element = 0; }
	Iterator(const Iterator& it) { element = it.element; }
	bool operator==(const Iterator& it) { return element == it.element; }
	bool operator != (const Iterator& it) { return element != it.element; };
	void operator++() { ++element; }
	void operator--() { --element; }
	int& operator *() const { return *element; }
private:
	int* element;
};

class Vector
{
public:
	Vector(int n, int k = 0);
	Vector(const Vector& a);
	~Vector();
	Vector& operator=(const Vector& a);
	int& operator[] (int index);
	Vector operator+(const int k);
	int operator() ();

	friend ostream& operator<<(ostream& out, const Vector& a);
	friend istream& operator>>(istream& in, Vector& a);
	Iterator first() { return begin; }
	Iterator last() { return end; }
private:
	int size;
	int* data;
	Iterator begin;
	Iterator end;
};
