#pragma once
#include<iostream>
#include<map>
using namespace std;

template<class T>

class List
{
	map<int, T> v;
	int len;
public:
	List(void);
	List(int n);
	~List(void);
	void print();
	T middle();
	void add(int n, T el);
	void del(int nom);
	void delete_middle(T sr);
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
		v[i] = a;
	}
	len = v.size();
}

template <class T>
void List<T>::print()
{
	for (int i = 0; i < v.size(); i++)
		cout << i << " = " << v[i] << " " << endl;
	cout << endl;
}

template <class T>
T List<T>::middle()
{
	Pair s = v[0];
	for (int i = 1; i < v.size(); i++)
		s = s + v[i];
	int n = v.size();
	return s / n;
}

template <class T>
void List<T>::add(int n, T el)
{
	v.insert(make_pair(n, el));
}

template <class T>
void List<T>::del(int nom)
{
	v.erase(nom);
}

template <class T>
void List<T>::delete_middle(T sr)
{
	for (int i = 0; i < v.size(); i++)
		v[i] = v[i] - sr;
}
