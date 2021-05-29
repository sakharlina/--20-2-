#pragma once
#include<list>
#include<iostream>
using namespace std;

template<class T>

class List
{
	list <T> l;
	int len;
public:
	List(void);
	List(int n);
	void print_list();
	~List(void);
	T middle();
	void add_list(T el, int pos);
	void delete_list(int pos);
	void delsrednee(T el);
};

template <class T>
List<T>::List()
{
	len = 0;
}

template <class T>
List<T>::~List(void)
{

}

template <class T>
List<T>::List(int n)
{
	T a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		l.push_back(a);
	}
	len = l.size();
}

template <class T>
void List<T>::print_list()
{
	for (typename std::list<T>::iterator it = l.begin(); it != l.end(); ++it)
		cout << *it << " ";
}

template<class T>
T List<T>::middle()
{
	int a = 0; double b = 0;
	typename std::list<T>::iterator it;
	for (it = l.begin(); it != l.end(); it++)
	{
		a += (*it).first;
		b += (*it).second;
	}
	a = a / l.size();
	b = b / l.size();
	T s(a, b);
	return s;
}

template<class T>
void List<T>::add_list(T el, int pos)
{
	typename std::list<T>::iterator it = l.begin();
	advance(it, pos - 1);
	typename std::list<T> additlist;
	additlist.push_back(el);
	l.insert(it, additlist.begin(), additlist.end());
}

template<class T>
void List<T>::delete_list(int pos)
{
	typename std::list<T>::iterator it = l.begin();
	advance(it, pos - 1);
	l.erase(it);
}

template<class T>
void List<T>::delsrednee(T el)
{
	typename std::list<T>::iterator it;
	for (it = l.begin(); it != l.end(); it++)
		*it = *it - el;
}
