#include <iostream>
#include <list>
#include <iterator>
using namespace std;

list<double> mylist; //создание двунаправленного списка

int n;
double t;

void make(int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << i+1 << " элемент списка: ";
		cin >> t[i];
		mylist.push_back(t[i]); //вводим элементы t в список, начиная с конца
	}
}

void del()
{
	int i = 0;
	while (i < n)
	{
		if (i % 2 == 0) mylist.remove(t[i + 1]);
		i++;
	}
}


int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Введите количество элементов: ";
	cin >> n;
	while (n <= NULL)
	{
		cout << "Список не может быть создан";
		return 0;
	}

	make(n);

	cout << "Ваш список: ";
	copy(mylist.begin(), mylist.end(), ostream_iterator<double>(cout, " "));

	del();

	cout << endl;
	cout << "Список после удаления элементов: ";
	copy(mylist.begin(), mylist.end(), ostream_iterator<double>(cout, " "));

	return 0;
}
