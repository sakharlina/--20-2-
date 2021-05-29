#include "Pair.h"
#include <iostream>
#include <list>
#include<algorithm>
using namespace std;

typedef list<Pair> mylist;

Pair s;
mylist make(int n)
{
	mylist l;
	for (int i = 0; i < n; i++)
	{
		cout << "first? ";
		int a; cin >> a;
		cout << "second? ";
		double b; cin >> b;
		Pair c(a, b);
		l.push_back(c);
	}
	return l;
}

void print(mylist l)
{
	mylist::iterator it = l.begin();
	for (; it != l.end(); it++)
		cout << *it << endl;
	cout << endl;

}
Pair middle(mylist l)
{
	int size = l.size();
	int a = 0; double b = 0;
	list<Pair>::iterator i;
	for (i = l.begin(); i != l.end(); i++)
	{
		a = a + (*i).first;
		b = b + (*i).second;
	}
	a = a / size;
	b = b / size;
	Pair sr(a, b);
	return sr;
}

struct Greater_s
{
	bool operator()(Pair p)
	{
		if (p > s) return true; else return false;
	}
};

struct Comp_less
{
public:
	bool operator()(Pair p1, Pair p2)
	{
		if (p1 > p2) return true;
		else return false;
	}
};
struct Equal_s
{
	bool operator()(const Pair& p)
	{
		return p == s;
	}
};

void delete_middle(Pair& k)
{
	k = k - s;
}

int main()
{
	setlocale(0, "");
	mylist l;
	int size;
	cout << "Size? ";
	cin >> size;
	l = make(size);
	print(l);
	mylist::iterator i = l.begin();
	Pair k = middle(l);
	cout << "Srednee = " << k << endl;
	int pos;
	cout << "Position? "; cin >> pos;
	advance(i, pos - 1);
	l.insert(i, k);
	print(l);
	cout << "Сортировка по убыванию: " << endl;
	l.sort(Comp_less());
	print(l);
	cout << "Сортировка по возрастанию: " << endl;
	l.sort();
	print(l);
	cout << "Какой элемент вы хотите удалить? "; cin >> s;
	l.remove_if(Equal_s());
	print(l);
	cout << "Удаление среднего" << endl;
	s = middle(l);
	for_each(l.begin(), l.end(), delete_middle);
	print(l);
}
