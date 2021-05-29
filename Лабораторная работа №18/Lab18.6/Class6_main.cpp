#include "Vector.h"
#include <iostream>
using namespace std;

void main()
{
	Vector a(5);
	cout << a << endl;
	cin >> a;
	cout << a << endl;
	a[2] = 100;
	cout << a << endl;

	Vector b(10);
	cout << b << endl;
	b = a;
	cout << b << endl;

	Vector c(10);
	c = b + 100;
	cout << c << endl;
	cout << "\nThe length of a = " << a() << endl;

	cout << *(a.first()) << endl;
	Iterator i = a.first();
	++i;
	cout << *i << endl;
	for (i = a.first(); i != a.last(); ++i) cout << *i << endl;
}
