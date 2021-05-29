#include "Pair.h"
#include <iostream>
using namespace std;

void main()
{
	Pair a;
	Pair b;
	Pair c;
	cin >> a;
	cin >> b;
	++a;
	cout << a << endl;
	c = (a++) + b;
	cout << "a = " << a << endl;
	cout << "b = " << b << endl;
	cout << "c = " << c << endl;
}
