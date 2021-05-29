#include <iostream>
#include <string>
using namespace std;

int n;
string key, line;

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

int BM_search(List* users, string key, string line)
{
	int str, substr;
	str = line.size();
	substr = key.size();
	if (str != 0 && substr != 0 && str >= substr)
	{
		int i, p;
		int b[256];
		for (i = 0; i < 256; i++)
		{
			b[i] = substr; 
		}
		for (i = substr - 2; i >= 0; i--) 
		{
			if (b[int((unsigned char)key[i])] == substr) 
			{
				b[int((unsigned char)key[i])] = substr - i - 1;
			}
		}
		p = substr - 1; 
		while (p < str)
		{
			if (key[substr - 1] != line[p])
			{
				p += b[int((unsigned char)line[p])]; 
			}
			else
			{
				for (i = substr - 1; i >= 0; i--)
				{
					if (key[i] != line[p - substr + i + 1])
					{
						p += b[int((unsigned char)line[p - substr + i + 1])]; 
						break;
					}
					else if (i == 0)
					{
						string tmp;
						tmp = tmp + line[p + 1];
						int i = 2;
						while (p + i < str && line[p + i] != ' ') 
						{
							tmp = tmp + line[p + i];
							i++;
						}
						return stoi(tmp);
					}
				}
			}
		}
	}
	return -1;
}

void KMP_search(List* users, string key, string line)
{
	int lenline = line.size();
	int lenkey = key.size();

	int* array = new int[lenkey];
	array[0] = 0;
	int i = 1;
	int j = 0;
	for (int v = 0; v < lenkey; v++)
	{
		if (key[i] == key[j])
		{
			array[i] = j + 1; i++; j++;
		}
		else if (j == 0)
		{
			array[i] = 0;
			i++;
		}
		else
		{
			j = array[j - 1];
		}
	}
	cout << endl;
	cout << "Префикс функция:";
	for (int i = 0; i < lenkey; i++)
	{
		cout << " " << array[i];
	}
	cout << endl;
	int index_line = 0;
	int index_key = 0;
	int o = 0;
	while (index_line < lenline)
	{
		if (line[index_line] == key[index_key])
		{
			index_line++;
			index_key++;
			if (index_key == lenkey)
			{
				string tmp;
				tmp = tmp + line[index_line];
				int i = 1;

				while (index_line < lenline && (line[index_line + 1] != ' '))
				{
					tmp = tmp + line[index_line + i];
					index_line++;
				}
				cout << "Номер элемента с введенным ФИО : " << stoi(tmp);
			}
		}

		if (line[index_line] != key[index_key])
		{
			if (index_key == 0)
			{
				index_line++;
			}
			else
			{
				index_key = array[index_key - 1];
			}
		}
	}
}

int main()
{
	setlocale(0, "");
	int num;

	cout << "Введите количество записей: ";
	cin >> n;
	while (n < 1)
	{
		cout << "Некорректный ввод. Попробуйте ещё раз: ";
		cin >> n;
	}

	users = new List[n];
	input(users);

	cin.get();
	cout << endl;
	cout << "Введите ФИО, которое Вы ищете: ";
	getline(cin, key);

	string line;
	for (int i = 1; i <= n; i++)
	{
		line = line + users[i - 1].fio + to_string(i) + " ";
	}

	cout << endl;
	cout << "Выберите, с помощью какого метода будет осуществлять поиск: " << endl << endl;
	cout << "1. Метод поиска Бойера-Мура" << endl;
	cout << "2. Метод поиска Кнута-Морриса-Пратта" << endl;
	cout << "Ваш выбор: "; cin >> num;
	switch (num)
	{
	case 1:
	{
		int element = BM_search(users, key, line);

		if (element != -1)
			cout << "Номер элемента с введенным ФИО : " << element << endl;
		else
			cout << "Элемент с введенным ФИО не найден" << endl;

		break;
	}
	case 2:
	{
		KMP_search(users, key, line);
		break;
	}
	default: cout << "Выбор некорректный"; break;
	}

	return 0;
}
