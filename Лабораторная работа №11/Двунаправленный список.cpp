#include <iostream>
using namespace std;

struct List
{
	double data;
	List* next;
	List* pred;
};


List* make(int size)
{
	if (size <= 0)
	{
		cout << "Список не может быть создан" << endl;
		return 0;
	}
	List* first, * p;
	first = NULL;
	p = new List;
	cout << "1 элемент списка: ";
	cin >> p->data;
	first = p;
	p->next = NULL;
	p->pred = NULL;
	for (int i = 2; i <= size; i++)
	{
		List* h = new List;
		List* q = p;
		p->next = h;
		p = p->next;
		cout << i << " элемент списка: ";
		cin >> p->data;
		p->next = NULL;
		p->pred = q;
	}
	return first;
}

void print(List* first)
{
	if (first == NULL)
		cout << "Список пустой" << endl;
	else {
		List* p = first;
		while (p != NULL) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << endl;
	}
}

void del(List* first)
{
	List* current = first->next;
	List* pred = first;

	while (current->next != NULL)
	{
		List* del = current;
		current = current->next;
		delete del;
		pred->next = current;
		pred = current;
		if (current->next != NULL) //проверка, остались ли ещё элементы впереди
		current = current->next;
	}
	if (pred->next == current)
	{
		delete current;
		pred->next = NULL;
	}
}


int main()
{
	setlocale(LC_ALL, "Rus");
	int size;
	cout << "Введите количество элементов: ";
	cin >> size;
	
	List* t = make(size);

	cout << "Ваш список: ";
	print(t);

	del(t);

	cout << "Список после удаления элементов: ";
	print(t);

	return 0;
}
