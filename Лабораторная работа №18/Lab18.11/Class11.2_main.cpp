#include "Pair.h"
#include <iostream>
#include <list>
#include <iterator>
#include<cstdlib>
using namespace std;

typedef list<Pair> mylist;

mylist make_list(int n)
{
	mylist l;
	Pair b;
	for (int i = 0; i < n; i++)
	{
		int a; double b;
		cout << "first? "; cin >> a;
		cout << "second? "; cin >> b;
		Pair c(a, b);
		l.push_back(c);
	}
	return l;
}

void print_list(mylist l)
{
	copy(l.begin(), l.end(), ostream_iterator<Pair>(cout, "\n"));
}

Pair middle(mylist l, int size)
{
	int a = 0; double b = 0;
	list<Pair>::iterator it;
	for (it = l.begin(); it != l.end(); it++)
	{
		a = a + (*it).first;
		b = b + (*it).second;
	}
	a = a / size;
	b = b / size;
	Pair s(a, b);
	return s;
}

void add_list(mylist& l, Pair el, int k)
{
	list<Pair>::iterator it = l.begin();
	advance(it, k - 1);
	list<Pair>additlist;
	additlist.push_back(el);
	l.insert(it, additlist.begin(), additlist.end());
}

void delete_list(mylist& l, int pos)
{
	list<Pair>::iterator it = l.begin();
	advance(it, pos - 1);
	l.erase(it);
}

void delsrednee(mylist& l, Pair s)
{
	list<Pair>::iterator it;
	for (it = l.begin(); it != l.end(); it++)
	{
		*it = *it - s;
	}
}

void main()
{
	try
	{
		list<Pair> l;
		list<Pair>::iterator li = l.begin();
		int size;
		cout << "SIZE? "; cin >> size;
		l = make_list(size);
		print_list(l);
		Pair element = middle(l, size);
		cout << "\nSrednee = " << element << endl;
		int pos;
		cout << "\nPOSITION? "; cin >> pos;
		if (pos > l.size()) throw 1;
		add_list(l, element, pos);
		print_list(l);
		int pos2;
		cout << "\nNUMBER? "; cin >> pos2;
		delete_list(l, pos2);
		print_list(l);
		delsrednee(l, element);
		cout << endl;
		print_list(l);
	}
	catch (int)
	{
		cout << "Error!";
	}
}
