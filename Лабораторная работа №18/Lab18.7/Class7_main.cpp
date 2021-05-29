#include "Pair.h"
#include "List.h"
#include <iostream>
using namespace std;

void main()
{
	cout << "SPISOK:\n";
	List<int>A(5, 0);
	cin >> A;
	cout << A << endl;

	List<int>B(10, 1);
	cout << B << endl;

	B = A;
	cout << B << endl;
	cout << A[2] << endl;
	cout << "size = " << A() << endl;
	B = A + 10;
	cout << B << endl;

	Pair p1;
	cin >> p1;
	cout << p1;

	int k;
	cout << "\nk? "; cin >> k;
	Pair tmp(k, k);
	Pair p2;
	p2 = p1 + tmp;
	cout << p2;
	Pair p3;
	cin >> p3;
	cout << p3 << endl;

	List<Pair>C(5, p3);
	cin >> C;
	cout << C << endl;

	List<Pair>D(10, p3);
	cout << D << endl;

	D = C;
	cout << D << endl;
	cout << C[2] << endl;
	cout << "size = " << C() << endl;

	D = C + p3;
	cout << D << endl;
}
