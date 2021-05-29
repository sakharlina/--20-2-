#include "List.h"
#include "Error.h"
#include <iostream>
using namespace std;

int main()
{
	try {
		List x(2);
		List y;
		List z(30);
		cout << x;
		int i;
		cout << "Number? "; cin >> i;
		cout << x[i] << endl;
		y = x + 3;
		cout << y;
		++z;
		cout << z;
	}
	catch (Error& e)
	{
		e.what();
	}
	return 0;
}
