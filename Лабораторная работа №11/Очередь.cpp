#include <iostream>
using namespace std;

int n;
struct Queue
{
	double data;
	Queue* next;
};

Queue* make(int n, Queue*& first, Queue*& last)
{
	if (n <= 0)
	{
		cout << "Очередь не может быть создана" << endl;
		return 0;
	}
    Queue* p = new Queue;
	double a;
	cin >> a;
	p->data = a;
	p->next = NULL;
	first = p;
	last = p;
	for (int i = 2; i <= n; i++)
	{
		Queue* h = new Queue;
		cin >> a;
		h->data = a;
		h->next = p;
		last = h;
		p = last;
	}
	return first;
}

void print(Queue* last)
{
	Queue* p = last;
	while (p != NULL)
	{
		cout << p->data << " ";
		p = p->next;
	}
	cout << endl;
}

void del(Queue* last)
{
	Queue* current = last->next;
	Queue* pred = last;

	while (current->next != NULL)
	{
		Queue* del = current;
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
	cout << "Введите количество элементов очереди: ";
	cin >> n;
	
	Queue* first, * last; //указатели на первый и последний элементы очереди

	make(n, first, last);

	cout << "Введенная очередь: ";
	print(last);

	del(last);

	cout << "Очередь после удаления: ";
	print(last);
	return 0;
}
