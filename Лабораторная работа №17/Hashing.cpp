#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct List 
{
	string fio;
	string birth;
	long long number;
	int passport;
	List* next;
};

void input(List* info, int n)
{
	for (int i = 0; i < n; i++) 
	{
		cout << endl;
		cin.get();
		cout << "Введите полное имя: ";
		getline(cin, info[i].fio);
		cout << "Введите дату рождения: ";
		getline(cin, info[i].birth);
		cout << "Введите номер телефона: ";
		cin >> info[i].number;
		cout << "Введите номер паспорта: ";
		cin >> info[i].passport;
	}
}

void hashing(List* info, int n, List* info_base)
{
	for (int i = 0; i < n; i++) 
	{
		info_base[i].passport = 0;
	}
	int c = 0;
	double A = 0.0000015;
	for (int i = 0; i < n; i++) 
	{
		int id = n * (info[i].passport * A - int(info[i].passport * A / 1));
		if (info_base[id].passport == 0)
		{
			info_base[id].fio = info[i].fio;
			info_base[id].birth = info[i].birth;
			info_base[id].number = info[i].number;
			info_base[id].passport = info[i].passport;
			info_base[id].next = NULL;
		}
		else 
		{
			c++;
			List* element = new List;
			List* p = &info_base[id];
			while (p->next != NULL) 
			{
				p = p->next;
			}
			element->birth = info[i].birth;
			element->fio = info[i].fio;
			element->number = info[i].number;
			element->passport = info[i].passport;
			p->next = element;
			element->next = NULL;
		}
	}
	cout << endl;
	cout << "Количество коллизий: " << c << endl;
}

void find(List* info_base, int n)
{
	int key;
	cout << "Введите номер паспорта: ";
	cin >> key;
	double A = 0.0000015;
	int id = n * (key * A - int(key * A / 1));
	if (info_base[id].passport == key)
	{
		cout << endl;
		cout << "ФИО: ";
		cout << info_base[id].fio << endl;
		cout << "Дата рождения: ";
		cout << info_base[id].birth << endl;
		cout << "Номер телефона: ";
		cout << info_base[id].number << endl;
		cout << "Номер паспорта: ";
		cout << info_base[id].passport << endl;
		cout << endl;
	}
	else if (info_base[id].passport != key && info_base[id].next != NULL)
	{
		List* p = info_base[id].next;
		bool f = true;
		while (p != NULL && f) 
		{
			if (p->passport == key) 
			{
				cout << endl;
				cout << "ФИО: ";
				cout << p->fio << endl;
				cout << "Дата рождения: ";
				cout << p->birth << endl;
				cout << "Номер телефона: ";
				cout << p->number << endl;
				cout << "Номер пасспорта: ";
				cout << p->passport << endl;
				cout << endl;
				f = false;
			}
			p = p->next;
		}
	}
	else 
	{ 
		cout << "Элемент с заданным номером паспорта не найден"; 
	}
}

int main()
{
	system("chcp 1251>nul");
	int n;
	cout << "Введите количество элементов: ";
	cin >> n;
	while (n < 1)
	{
		cout << "Некорректный ввод. Попробуйте еще раз: ";
		cin >> n;
	}
	List* info = new List[n];
	List* info_base = new List[n];
	input(info, n);
	hashing(info, n, info_base);
	find(info_base, n);
}
