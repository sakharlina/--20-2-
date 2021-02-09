#include <iostream>
#include <string>
using namespace std;

struct Vladelec
{
	string lastname;
	string name;
	string midname;
	string numberavto;
	string tehpasport;
	string otdelenie;
};
int k = 0; // Сделали переменную k глобальной
Vladelec avto[5]; // Вынесли объявление массива за пределы функции, чтобы сделать его глобальным
Vladelec new_avto[6];
string func()
{
	string s = "";
	bool f = false;
	while ((s.length() != 6) || (f == true))

	{
		f = false;
		cin >> s;
		for (int i = 0; i < s.length(); i++)
		{
			if ((s[i] < '0') || (s[i] > '9')) //проверяем, вся ли строка состоит из цифр
				f = true;
		}
		if ((s.length() != 6) || (f == true)) //проверяем длину введенной строки
		{
			cout << "Номер техпаспорта введен некорректно. Попробуйте снова: ";
		}
	}
	return s;
}
void Input() { // Создали функцию, производящую ввод элементов массива
	for (int i = 0; i < 5; i++)
	{
		cout << "ФИО владельца: ";
		cin >> avto[i].lastname >> avto[i].name >> avto[i].midname;
		cout << "Номер автомобиля: ";
		cin >> avto[i].numberavto;
		cout << "Номер техпаспорта: ";
		avto[i].tehpasport = func();
		getline(cin, avto[i].otdelenie);
		cout << "Отделение регистрации ГАИ: ";
		getline(cin, avto[i].otdelenie);
		cout << endl << endl;
	}
}
void Newinput() { // Функция, добавляющая два новых элемента.
	cout << "Введите элементы, которые хотите добавить: " << endl;
	cout << "ФИО владельца: ";
	cin >> new_avto[k].lastname >> new_avto[k].name >> new_avto[k].midname;
	cout << "Номер автомобиля: ";
	cin >> new_avto[k].numberavto;
	cout << "Номер техпаспорта: ";
	new_avto[k].tehpasport = func();
	getline(cin, new_avto[k].otdelenie);
	cout << "Отделение регистрации ГАИ: ";
	getline(cin, avto[k].otdelenie);
	cout << endl << endl;

	cout << "ФИО владельца: ";
	cin >> new_avto[k + 1].lastname >> new_avto[k + 1].name >> new_avto[k + 1].midname;
	cout << "Номер автомобиля: ";
	cin >> new_avto[k + 1].numberavto;
	cout << "Номер техпаспорта: ";
	new_avto[k + 1].tehpasport = func();
	getline(cin, avto[k + 1].otdelenie);
	cout << "Отделение регистрации ГАИ: ";
	getline(cin, avto[k + 1].otdelenie);
	cout << endl << endl;
}
void Output(int e) {
	cout << "Обновленный список владельцев: " << endl << endl;
	for (k = 0; k < e; k++)
	{
		cout << "ФИО владельца: " << new_avto[k].lastname << " " << new_avto[k].name << " " << new_avto[k].midname << endl;
		cout << "Номер автомобиля: " << new_avto[k].numberavto << endl;
		cout << "Номер техпаспорта: " << new_avto[k].tehpasport << endl;
		cout << "Отделение регистрации ГАИ: " << new_avto[k].otdelenie << endl << endl;
	}
}


int main()
{
	system("chcp 1251>nul");
	Input(); // Вызываем функцию ввода
	int your_num;

	cout << "Введите номер владельца, данные которого нужно удалить: ";
	cin >> your_num;

	while ((your_num < 1) || (your_num > 5))
	{
		cout << "Владелец под введенным номером не найден. Введите новый номер: ";
		cin >> your_num;
	}

	your_num = your_num - 1;
	int j = 0;
	int N = 0;

	for (int i = 0; i < 5; i++)
	{
		if (i != your_num)
		{
			new_avto[j] = avto[i];
			j++;
			N++;
		}
	}
	Output(4); // Вызываем функцию вывода элементов с аргументом 4, чтобы вывести 4 элемента массива
	string your_lastname;
	cout << "Введите фамилию нужного Вам владельца: ";
	cin >> your_lastname;

	k = 0;
	while (new_avto[k].lastname != your_lastname)
	{
		k++;
	}

	cout << endl;
	for (int i = 3; i >= k; i--)
	{
		new_avto[i + 2] = new_avto[i];
	}
	Newinput(); // Вызываем функцию, добавляющую 2 элемента
	Output(6); // Выводим массив элементов

	return 0;
}
