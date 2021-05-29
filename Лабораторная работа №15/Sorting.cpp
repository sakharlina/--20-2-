#include <iostream>
#include <string>
using namespace std;

struct List
{
	string spec;
	int count;
};

List* students;

void input(List* students, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << endl;
		cin.get();
		cout << "Введите специальность: ";
		getline(cin, students[i].spec);
		cout << "Введите количество студентов: ";
		cin >> students[i].count;

		while (students[i].count < 0)
		{
			cout << "Некорректный ввод. Попробуйте ещё раз: ";
			cin >> students[i].count;
		}
	}
}

void output(List* students, int n)
{
	cout << endl;
	cout << "Отсортированный список: " << endl;
	for (int i = 0; i < n; i++)
	{
		cout << students[i].spec << ": " << students[i].count << endl;
	}
}

void shell_sort(List* students, int n)
{
	int j, tmp1;
	string tmp2;
	for (int step = n / 2; step > 0; step /= 2) 
	{
		for (int i = step; i < n; i++)
		{
			tmp1 = students[i].count;
			tmp2 = students[i].spec;
			for (j = i; j >= step; j -= step)
			{
				if (tmp1 < students[j - step].count)
				{
					students[j].count = students[j - step].count;
					students[j].spec = students[j - step].spec;
				}
				else break;
			}
			students[j].count = tmp1;
			students[i].spec = tmp2;
		}
	}
}

void hoar_sort(List* students, int first, int last)
{
	int i = first; int j = last;
	int item = students[(first + last) / 2].count;
	while (i <= j)
	{
		while (students[i].count < item && i < last) i++;
		while (item < students[j].count && j > first) j--;
		if (i <= j)
		{
			List tmp = students[i];
			students[i] = students[j];
			students[j] = tmp;
			i++;
			j--;
		}
	}
	if (first < j) hoar_sort(students, first, j);
	if (i < last) hoar_sort(students, i, last);
}

int main()
{
	system("chcp 1251>nul");
	int n, num;
	cout << "Введите количество элементов: ";
	cin >> n;
	while (n < 1)
	{
		cout << "Некорректный ввод. Попробуйте ещё раз: ";
		cin >> n;
	}
	students = new List[n];
	input(students, n);

	cout << endl;
	cout << "Выберите метод сортировки: " << endl << endl;
	cout << "1. Сортировка методом Шелла." << endl;
	cout << "2. Сортировка методом Хоара." << endl;
	cout << "Ваш выбор: "; cin >> num;
	switch (num)
	{
	case 1:
	{
		shell_sort(students, n);
		output(students, n);
		break;
	}
	case 2:
	{
		int first = 0; int last = n - 1;
		hoar_sort(students, first, last);
		output(students, n);
		break;
	}
	default: cout << "Выбор некорректный."; break;
	}

	return 0;
}
