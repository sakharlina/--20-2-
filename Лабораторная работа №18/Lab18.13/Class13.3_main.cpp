#include "Pair.h"
#include <iostream>
#include <map>
#include <list>
#include <vector>
#include <algorithm>
using namespace std;

typedef map<int, Pair> TMap;
typedef list<Pair> List;
typedef TMap::iterator it;

Pair s;
TMap make_map(int n)
{
	TMap m;
	Pair a;
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		m.insert(make_pair(i, a));
	}
	return m;
}

void print_map(TMap m)
{
	for (int i = 0; i < m.size(); i++)
		cout << i << "=" << m[i] << " " << endl;
}

Pair middle(TMap m)
{
	Pair s = m[0];
	for (int i = 0; i < m.size(); i++)
		s = s + m[i];
	int n = m.size();
	return s / n;
}

void delete_middle(TMap& m, Pair& sr)
{
	int n = m.size();
	Pair el = sr;
	for (int i = 0; i < m.size(); i++)
	{
		m[i] = m[i] - el;
	}
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

TMap sort_done(TMap m)
{
	TMap p;
	cout << "Сортировка по убыванию:" << endl;
	vector<Pair> vec2;
	for (int a = 0; a < m.size(); a++)
	{
		Pair b = m[a];
		vec2.push_back(b);
	}
	sort(vec2.begin(), vec2.end(), Comp_less());
	for (int o = 0; o < vec2.size(); o++)
	{
		Pair z = vec2[o];
		p.insert(make_pair(o, z));
	}
	return p;
}

TMap sort_high(TMap p)
{
	cout << "Сортировка по возрастанию" << endl;
	vector<Pair> vec;
	for (int a = 0; a < p.size(); a++)
	{
		Pair b = p[a];
		vec.push_back(b);
	}
	sort(vec.begin(), vec.end());
	TMap d;
	for (int o = 0; o < vec.size(); o++)
	{
		Pair z = vec[o];
		d.insert(make_pair(o, z));
	}
	return d;
}

void delmiddle(Pair& k)
{
	k = k - s;
}

int main()
{
	setlocale(0, "");
	int n;
	cout << "Введите количество элментов: "; cin >> n;
	map<int, Pair> m = make_map(n);
	print_map(m);
	cout << endl;
	Pair sr = middle(m);
	cout << "Среднее = " << sr << endl;
	m.insert(make_pair(n, sr));
	print_map(m);
	TMap p = sort_done(m);
	print_map(p);
	TMap d = sort_high(m);
	print_map(d);
	cout << "\nКакой элемент вы хотите удалить? " << endl; cin >> s;
	TMap ma;
	list <Pair> vec;
	for (int a = 0; a < d.size(); a++)
	{
		Pair b = d[a];
		vec.push_back(b);
	}
	vec.remove_if(Equal_s());
	int ir = 0;
	for (List::iterator iter = vec.begin(); iter != vec.end(); iter++)
	{

		ma.insert(make_pair(ir, (*iter)));
		ir++;
	}
	print_map(ma);
	s = sr;
	TMap mapp;
	list <Pair> vec2;
	for (int a = 0; a < ma.size(); a++)
	{
		Pair b = d[a];
		vec2.push_back(b);
	}
	for_each(vec2.begin(), vec2.end(), delmiddle);
	int ir2 = 0;
	for (List::iterator iter = vec2.begin(); iter != vec2.end(); iter++)
	{

		mapp.insert(make_pair(ir2, (*iter)));
		ir2++;
	}
	print_map(mapp);
	return 0;
}
