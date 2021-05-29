#include "Receipt.h"
#include <iostream>
#include <string>
using namespace std;

Receipt return_receipt()
{
	int N;
	string K;
	double S;
	cout << endl;
	cout << "Введите номер квитанции: ";
	cin >> N;
	cin.get();
	cout << "Введите дату: ";
	getline(cin, K);
	cout << "Введите сумму: ";
	cin >> S;
	Receipt R(N, K, S);
    return R;
}

void print_receipt(Receipt R)
{
	R.print();
}

void main()
{
	setlocale(0, "");
	Receipt R1;
	R1.print();

	Receipt R2(55312, "03.05.21", 335.7);
	R2.print();

	Receipt R3 = R2;
	R3.set_number(55312);
	R3.set_date("03.05.21");
	R3.set_sum(335.7);

	print_receipt(R3);

	R1 = return_receipt();
	R1.print();
}
