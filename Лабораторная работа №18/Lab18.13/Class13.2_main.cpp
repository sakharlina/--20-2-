#include "Pair.h"
#include <iostream>
#include <functional>
#include <queue>
#include <list>
#include <algorithm>
using namespace std;

typedef queue<Pair> mylist;
typedef list<Pair> List;

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
		l.push(c);
	}
	return l;
}

void print(mylist l)
{
	while (!l.empty())
	{
		cout << l.front() << ' ';
		l.pop();
	}
	cout << '\n';
}

List copy_queue_to_list(mylist& s)
{
	List a;
	while (!s.empty())
	{
		a.push_back(s.front());
		s.pop(); 
	}
	return a;
}

mylist copy_list_to_queue(List& a)
{
	mylist s;
	for (List::iterator iter = a.begin(); iter != a.end(); iter++)
	{
		s.push((*iter));
	}
	return s;
}

Pair middle(mylist l)
{
	List s = copy_queue_to_list(l);
	int a = 0; double b = 0;
	list<Pair>::iterator i;
	for (i = s.begin(); i != s.end(); i++)
	{
		a = a + (*i).first;
		b = b + (*i).second;
	}
	int size = s.size();
	a = a / size;
	b = b / size;
	Pair p(a, b);
	return p;
}

void add(mylist& l, Pair& k)
{
	l.push(k);
}

struct Greater_s
{
	bool operator()(Pair p)
	{
		if (p > s) return true; 
		else return false;
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

void delmiddle(Pair& k)
{
	k = k - s;
}

void sort_high(mylist& l)
{
	List lis = copy_queue_to_list(l);
	List::iterator i = lis.begin();
	lis.sort();
	l = copy_list_to_queue(lis);
}

void sort_done(mylist& l)
{
	List lis = copy_queue_to_list(l);
	List::iterator i = lis.begin();
	lis.sort(Comp_less());
	l = copy_list_to_queue(lis);
}

void del(mylist& l, Pair& s)
{
	List lis = copy_queue_to_list(l);
	lis.remove_if(Equal_s());
	l = copy_list_to_queue(lis);
}

void delete_middle(mylist& l, Pair& sr)
{
	List lis = copy_queue_to_list(l);
	for_each(lis.begin(), lis.end(), delmiddle);
	l = copy_list_to_queue(lis);

}

int main()
{
	setlocale(0, "");
	mylist l;
	int size;
	cout << "Size? "; cin >> size;
	l = make(size);
	print(l);
	Pair k = middle(l);
	cout << "Srednee = " << k << endl;
	add(l, k);
	print(l);
	cout << "Сортировка по убыванию:" << endl;
	sort_done(l);
	print(l);
	cout << "Сортировка по возрастанию:" << endl;
	sort_high(l);
	print(l);
	cout << "Какой элемент вы хотите удалить?"; cin >> s;
	del(l, s);
	print(l);
	cout << "Удаление среднего" << endl;
	s = middle(l);
	delete_middle(l, s);
	print(l);
}
