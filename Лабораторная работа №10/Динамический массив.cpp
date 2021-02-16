#include <iostream>
#include <string>
using namespace std;

int main()
{
	system("chcp 1251>nul");
	int n;
	int k, num;

	cout << "Введите количество строк: ";
	cin >> n;

	while (n < 1)
	{
		cout << "Введите значение корректно: ";
		cin >> n;
	}

	string* array = new string[n]; //динамическое выделение памяти для массива

	cout << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Строка " << i + 1 << ": ";
		getline(cin, array[i], '.');
	}

	cout << endl;
	cout << "Введите номер строки, с которой начнется удаление: ";
	cin >> num;
	while ((num < 1) || (num > n))
	{
		cout << "Введите значение корректно: ";
		cin >> num;
	}

	cout << "Введите количество удаляемых строк: ";
	cin >> k;
	while ((k < 0) || (k > n))
	{
		cout << "Введите значение корректно: ";
		cin >> k;
	}

	if (num + k > n) cout << "Часть строк, которые необходимо удалить, не содержатся в массиве.";

	int i = 0;
	int m = n - k;
	string* new_array = new string[m]; //динамическое выделение памяти под второй массив

	for (int j = 0; j < n; j++)
	{
		if ((j < num - 1) || (j > num + k - 2))
		{
			new_array[i] = array[j];
			i++;
		}
	}

	cout << endl;
	for (int j = 0; j < m; j++) cout << "Строка" << j + 1 << ": " << new_array[j] << endl;

	delete[] array;
	return 0;
}
