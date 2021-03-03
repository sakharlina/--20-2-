#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int n;
string key; 

struct List
{
	string fio;
	string data;
	long long number;
};

List* users;

void input(List* users)
{
	for (int i = 0; i < n; i++)
	{
		cout << endl;
		cin.get();
		cout << "Полное имя: ";
		getline(cin, users[i].fio);
		cout << "Дата рождения: ";
		getline(cin, users[i].data);
		cout << "Номер телефона: ";
		cin >> users[i].number;
	}
}

void output(List* users)
{
	cout << endl;
	cout << "Список после сортровки по возрастанию: " << endl << endl;
	for (int i = 0; i < n; i++)
	{
		cout << "Полное имя: " << users[i].fio << endl;
		cout << "Дата рождения: " << users[i].data << endl;
		cout << "Номер телефона: " << users[i].number << endl;
		cout << endl;
	}
}

void line_search(List* users, string key)
{
	int k = -1;
	for (int i = 0; i < n; i++)
	{
		if (users[i].fio == key) k = i;
	}
	cout << endl;
	if (k != -1) cout << "Номер элемента с введенным ФИО: " << k + 1;
	else cout << "Элемент с введенным ФИО не найден";
}

void sort_arr(List* users) 
{
	for (int i = 0; i < n - 1; i++) 
	{
		for (int j = n - 1; j >= (i + 1); j--)
		{
			if (users[j - 1].number > users[j].number) 
			{
				List users_sort = users[j];
				users[j] = users[j - 1];
				users[j - 1] = users_sort;
			}
		}
	}
}

int interpol_search(List* users, long long int key_number)
{
	int mid, left = 0, right = n - 1;
	while (users[left].number <= key_number && users[right].number >= key_number)
	{
		mid = left + ((key_number - users[left].number) * (right - left)) / (users[right].number - users[left].number);
		if (users[mid].number < key_number) left = mid + 1;
		else if (users[mid].number > key_number) right = mid - 1;
		else return mid;
	}
	if (users[left].number == key_number) return left;
	else return -1;
}

void straight_search(List* users, string key)
{
	string line;
	for (int i = 1; i <= n; i++)
	{
		line = line  + to_string(i) + users[i - 1].fio;
	}
	int str, substr, res = -1;

	str = line.size();
	substr = key.size();
	if (str != 0 && substr != 0)
	{
		for (int i = 0; i < str - substr + 1; i++)
		{
			for (int j = 0; j < substr; j++)
			{
				if (key[j] != line[i + j]) break;
				else if (j == substr - 1)
	            {
					res = i;
		            break;
	            }
			}
		}
		if (res != -1) cout << "Номер элемента с введенным ФИО: " << line[res - 1];
		else cout << "Элемент с введенным ФИО не найден";
	}
}

int main()
{
	system("chcp 1251>nul");
	int num, a;
	cout << "Выберите действие: " << endl;
	cout << "1. Открыть файл." << endl;
	cout << "2. Ввести список вручную." << endl;
	cout << "Ваш выбор: "; cin >> a;
	switch (a)
	{
	case 1:
	{
		int count = 0;
		string row;
		ifstream input;
		input.open("База данных.txt");
		while (!input.eof())
		{
			count++;
			getline(input, row);
		}
		n = count / 4;
		users = new List[n];
		input.close();
		input.open("База данных.txt");
		int i = 0;
		while (!input.eof())
		{
			getline(input, users[i].fio);
			getline(input, users[i].data);
			input >> users[i].number;
			getline(input, row);
			getline(input, row);
			i++;
		}
		input.close();
		cout << "Список загружен." << endl << endl;
		break;
	}
	case 2:
	{
		cout << "Введите количество записей: ";
		cin >> n;
		while (n < 1)
		{
			cout << "Некорректный ввод. Попробуйте ещё раз: ";
			cin >> n;
		}

		users = new List[n];
		input(users);
	}
	default: cout << "Выбор некорректный"; break;
	}

	cout << endl;
	cout << "Выберите, с помощью какого метода будет осуществлять поиск: " << endl << endl;
	cout << "1. Линейный поиск" << endl;
	cout << "2. Интерполяционный поиск" << endl;
	cout << "3. Прямой поиск подстроки в строке" << endl;
	cout << "Ваш выбор: "; cin >> num;
	switch (num)
	{
	case 1:
	{
		cin.get();
		cout << endl;
		cout << "Введите ФИО, которое Вы ищете: ";
		getline(cin, key);

		line_search(users, key);
		break;
	}
	case 2:
	{
		long long key_number;
		cout << endl;
		cout << "Введите номер телефона, который Вы ищете: ";
		cin >> key_number;

		sort_arr(users);
		output(users);
		int element = interpol_search(users, key_number);

		if (element != -1)
			cout << "Номер элемента с введенным номером: " << element + 1 << endl;
		else
			cout << "Элемент с введенным номером не найден" << endl;
		break;
	}
	case 3:
	{
		cin.get();
		cout << endl;
		cout << "Введите ФИО, которое Вы ищете: ";
		getline(cin, key);

		straight_search(users, key);
		break;
	}
	default: cout << "Выбор некорректный"; break;
	}
	
	return 0;
}
