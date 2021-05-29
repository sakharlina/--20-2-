#pragma once
#include <iostream>
#include <queue>
#include <list>
using namespace std;

template<class T>
class List 
{
	priority_queue<T> q;
	int len;
public:
	List();
	List(int n);
	List(const List<T>&);
	void print();
	T average();
	void add(T k);
	void del(int);
	void substr();
	int operator()() { return len; }
};

template<class T>
list<T> copy_queue_to_list(priority_queue<T> q) {
	list<T> l;
	while (!q.empty()) {
		l.push_back(q.top());
		q.pop();
	}
	return l;
}

template<class T>
priority_queue<T> copy_list_to_queue(list<T> l) {
	priority_queue<T> q;
	typename list<T>::iterator it = l.begin();
	for (; it != l.end(); it++)
		q.push(*it);
	return q;
}

template<class T>
List<T>::List() {
	len = 0;
}

template<class T>
List<T>::List(int n) {
	T a;
	for (int i = 0; i < n; i++) {
		cin >> a;
		q.push(a);
	}
	len = q.size();
}

template<class T>
List<T>::List(const List<T>& l) {
	len = l.len;
	list<T> list = copy_queue_to_list(l.q);
	q = copy_list_to_queue(list);
}

template<class T>
void List<T>::print() {
	list<T> list = copy_queue_to_list(q);
	while (!q.empty()) {
		cout << q.top() << " ";
		q.pop();
	}
	cout << endl;
	q = copy_list_to_queue(list);
}

template<class T>
T List<T>::average() {
	list<T> list = copy_queue_to_list(q);
	int n = 1;
	T sum = q.top();
	q.pop();
	while (!q.empty()) {
		sum = sum + q.top();
		q.pop();
		n++;
	}
	q = copy_list_to_queue(list);
	return sum / n;
}

template<class T>
void List<T>::add(T k) {
	list<T> list;
	T t;
	q.push(k);
	while (!q.empty())
	{
		t = q.top();
		list.push_back(t);
		q.pop();
	}
	q = copy_list_to_queue(list);
}

template<class T>
void List<T>::del(int pos) {
	list<T> L = copy_queue_to_list(q);
	typename list<T>::iterator it1 = L.begin();
	advance(it1, pos);
	L.erase(it1);
	q = copy_list_to_queue(L);
}

template<class T>
void List<T>::substr() {
	T a = average();
	list<T> L = copy_queue_to_list(q);
	typename list<T>::iterator it;
	it = L.begin();
	for (; it != L.end(); it++)
	{
		*it = *it - a;
	}
	q = copy_list_to_queue(L);
}
