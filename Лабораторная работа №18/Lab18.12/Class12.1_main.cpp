#include<iostream>
#include<map>
using namespace std;

typedef map<int, int> TMap;
typedef TMap::iterator it;

TMap make_map(int n)
{
	TMap m;
	int a;
	for (int i = 0; i < n; i++)
	{
		cout << "Введите число: ";
		cin >> a;
		m.insert(make_pair(i, a));
	}
	return m;
}

void print_map(TMap m)
{
	for (int i = 0; i < m.size(); i++)
	{
		cout << i << " : " << m[i] << " " << endl;
	}
}

int middle(TMap v)
{
	int s = 0;
	for (int i = 0; i < v.size(); i++)
		s += v[i];
	int n = v.size();
	return s / n;
}

void delete_middle(TMap& v, int sr)
{
	for (int i = 0; i < v.size(); i++)
	{
		v[i] = v[i] - sr;
	}
}

void main()
{
	setlocale(0, "");
	int n;
	cout << "Введите количество элементов: "; cin >> n;
	TMap m = make_map(n);
	print_map(m);
	int el = middle(m);
	cout << "Среднее = " << el << endl;
	m.insert(make_pair(n, el));
	print_map(m);
	int pos;
	cout << "Введите позицию элемента, который вы хотите удалить: "; cin >> pos;
	m.erase(pos);
	cout << endl;
	print_map(m);
	delete_middle(m, el);
	cout << endl;
	print_map(m);
}
