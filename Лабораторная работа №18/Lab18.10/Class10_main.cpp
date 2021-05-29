#include "Pair.h"
#include <iostream>
#include <fstream>
#include <string>
#include "FileWork.h"
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

	Pair p;
	int flag, num;
	char file_name[30];
	do
	{
		cout << "\n1. Make file\n";
		cout << "2. Print file\n";
		cout << "3. Delete record from file\n";
		cout << "4. Add record to file\n";
		cout << "5. Change record in file\n";
		cout << "0. Exit\n";
		cin >> num;
		if (num != 0)
		{
			cout << "File name? "; cin >> file_name;
		}
		switch (num)
		{
		case 1: 
		{
			flag = MakeFile(file_name);
			if (flag < 0) cout << "Can't make file";
			break;
		}
		case 2:
		{
			flag = PrintFile(file_name);
			if (flag == 0) cout << "Empty file\n";
			if (flag < 0) cout << "Can't read file\n";
			break;
		}
		case 3: 
		{
			Pair s; 
			cout << "Input pair: "; cin >> s;
			flag = DeleteFile(file_name, s);
			if (flag < 0) cout << "Can't read file";
			break;
		}
		case 4: 
		{
			int k, n;
			cout << "K? "; cin >> k;
			cout << "N? "; cin >> n;
			flag = AddFile(file_name, k, n);
			if (flag < 0) cout << "Can't read file";
			if (flag == 0) AddEnd(file_name, n);
			break;
		}
		case 5: 
			int l, k;
			cout << "K? "; cin >> k;
			cout << "L? "; cin >> l;
			flag = ChangeFile(file_name, k, l);
			if (flag < 0) cout << "Can't read file";
			if (flag == 0) cout << "Not such record";
			break;
		}
	} while (num != 0);
}
