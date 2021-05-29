#include "Object.h"
#include "Person.h"
#include "Student.h"
#include "Vector.h"
#include <string>
#include <iostream>
using namespace std;

void main()
{
	Vector v(4);

	Person a;
	cin >> a;
	Student b;
	cin >> b;
	++b;

	Object* t = &a;
	v.Add(t);

	t = &b;
	v.Add(t);
	cout << v << endl;
}
