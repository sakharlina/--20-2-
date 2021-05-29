#include <iostream>
#include <list>
#include <iterator>
#include <cstdlib>
using namespace std;

typedef list<int> mylist;

mylist make_list(int n)
{
	mylist l;
	for (int i = 0; i < n; i++)
	{
		int a = rand() % 100 + 1;
		l.push_back(a);
	}
	return l;
}

void print_list(mylist l)
{
	copy(l.begin(), l.end(), ostream_iterator<int>(cout, " "));
}

int middle(mylist l)
{
	int s = 0;
	list<int>::iterator it;
	for (it = l.begin(); it != l.end(); it++)
		s += *it;
	s /= l.size();
	return s;
}

void add_list(mylist& l, int sred, int pos)
{

	list<int>::iterator it = l.begin();
	advance(it, pos - 1);
	list<int> list2;
	list2.push_back(sred);
	l.insert(it, list2.begin(), list2.end());
}

void del_list(mylist& l, int num, int n)
{
	list<int>::iterator it = l.begin();
	advance(it, num - 1);
	l.erase(it);
}

void main()
{
	try
	{
		list<int> l;
		list<int>::iterator li = l.begin();
		int n;
		cout << "SIZE? "; cin >> n;
		l = make_list(n);
		print_list(l);
		int sred = middle(l);
		cout << "\nSrednee = " << sred;
		int pos;
		cout << "\nPosition? "; cin >> pos;
		if (pos > l.size()) throw 1;
		add_list(l, sred, pos);
		print_list(l);
		int num;
		cout << "\nNUMBER? "; cin >> num;
		del_list(l, num, n);
		print_list(l);
	}
	catch (int)
	{
		cout << "Error!";
	}
}
