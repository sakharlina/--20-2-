#include <iostream>
using namespace std;

struct List //создание структуры списка
{
	char data[15]; 
	List* next; 
};

List* input(int size) //функция ввода элементов списка
{
	if (size <= 0)
	{
		cout << "Список не может быть создан." << endl;
		return 0;
	}
	List* first, * p;
	first = NULL; //пока нет элементов, first указывает на NULL
	cout << "1 элемент списка: ";
	p = new List;
	cin >> p->data;
	first = p; //first указывает на первый элемент
	for (int i = 2; i <= size; i++)
	{
		List* h = new List;
		p->next = h;
		p = p->next;
		cout << i << " элемент списка: ";
		cin >> p->data;
		p->next = NULL;
	}
	return first;
}

void print(List* first) //функция печати списка
{
	if (first == NULL) //проверяем пуст ли список
	{
		cout << "Список пустой" << endl; 
	}
	else {
		List* p = first;
		while (p != NULL) 
		{
			cout << p->data << " "; 
			p = p->next;
		}
		cout << endl;
	}
}

void add(List*first)
{
	int num;
	cout << "Введите номер добавляемого элемента: ";
	cin >> num;
	while (num < 0)
	{
		cout << "Некорректный ввод. Попробуйте ещё раз: ";
		cin >> num;
	}

	List* a;
	a = first;
	int i = 2;
	while (i < num)
	{
		a = a->next;
		i++;
	}
	List* e = a->next;
	List* z = new List;
	a->next = z;
	z->next = e;
	cout << "Введите добавляемый элемент: ";
	cin >> z->data;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int size;
	cout << "Введите размер списка: ";
	cin >> size;

	List* t = input(size);

	cout << "Ваш список: ";
	print(t);

	add(t);

	cout << "Список после добавления элемента: ";
	print(t);

	return 0;
}
