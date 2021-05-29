#pragma once
#include <iostream>
using namespace std;

const int MAX_SIZE = 30;

class List
{
public:
	int size;
	int* begin;
public:
	List() { size = 0; begin = NULL; }
	List(int);
	List(int, int*);
	List(const List&);
	~List();
	const List& operator= (const List&);
	int operator[] (int);
	List operator+(int);
	List operator++();
	friend ostream& operator<< (ostream& out, const List& l);
	friend istream& operator>> (istream& in, const List& l);
};
