#include <iostream>
using namespace std;

char a;
struct Stack
{
	char data;
	Stack* pred;
};

Stack* make(int n)
{
	if (n <= 0)
	{
		cout << "Стек не может быть создан";
		return 0;
	}
	Stack* top, * p;
	top = NULL;
	p = new Stack;
	cin >> a;
	p->data = a;
	p->pred = NULL;
	top = p;
	for (int i = 2; i <= n; i++)
	{
		Stack* h = new Stack;
		cin >> a;
		h->data = a;
		h->pred = top;
		top = h;
	}
	return top;
}

void print(Stack* top)
{
	if (top == NULL) cout << "Стек пуст" << endl;
	else {
		Stack* p = top;
		while (p != NULL)
		{
			cout << p->data << " ";
			p = p->pred;
		}
		cout << endl;
	}
}

void add(Stack* top)
{
	int num;
	cout << "Введите номер добавляемого элемента: ";
	cin >> num;
	while (num < 0)
	{
		cout << "Некорректный ввод. Попробуйте ещё раз: ";
		cin >> num;
	}

	Stack* a;
	a = top;
	int i = 2;
	while (i < num)
	{
		a = a->pred;
		i++;
	}
	Stack* e = a->pred;
	Stack* z = new Stack;
	a->pred = z;
	z->pred = e;
	cout << "Введите добавляемый элемент: ";
	cin >> z->data;
}

int main()
{
	setlocale(LC_ALL, "Rus");
	int n;
	cout << "Введите количество элементов в стеке: ";
	cin >> n;
	
	Stack* t = make(n);

	cout << "Введенный стек: ";
	print(t);

	add(t);

	cout << "Стек после добавления: ";
	print(t);

	return 0;
}
