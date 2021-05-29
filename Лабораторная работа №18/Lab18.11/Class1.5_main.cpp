#include "Pair.h"
#include "List2.h"
#include <iostream>
#include <list>
#include <queue>
using namespace std;
int main()
{
	setlocale(0, "");
	List <Pair> l(3);
	l.print();
	Pair p = l.average();
	cout << "\nSrednee=" << endl;
	cout << "Add srednee" << endl;
	l.add(p);
	l.print();
	cout << "Введите позицию элемента, который вы хотите удалить: ";
	int pos;
	cin >> pos;
	l.del(pos);
	l.print();
	l.substr();
	l.print();
	return 0;
}
