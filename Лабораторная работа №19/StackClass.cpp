#include <iostream>
using namespace std;

int a;
class Stack
{
public:
	struct mystack
	{
		int data;
		mystack* pred;
	};
	mystack* top;

public:
	Stack();
	~Stack();
	void make(int n);
	void print();
	void add();
};

Stack::Stack()
{
	top = NULL;
}

Stack::~Stack()
{
	mystack* p = new mystack;
	while (top != NULL)
	{
		p = top;
		top = top->pred;
		delete p;
	}
	delete top;
}

 void Stack::make(int n)
{
	if (n <= 0)
	{
		cout << "Стек не может быть создан";
	}
	mystack* p = new mystack;
	cin >> a;
	p->data = a;
	p->pred = NULL;
	top = p;
	for (int i = 2; i <= n; i++)
	{
		mystack* h = new mystack;
		cin >> a;
		h->data = a;
		h->pred = top;
		top = h;
	}
}

void Stack::print()
{
	if (top == NULL) cout << "Стек пуст" << endl;
	else {
		mystack* p = top;
		while (p != NULL)
		{
			cout << p->data << " ";
			p = p->pred;
		}
		cout << endl;
	}
}

void Stack::add()
{
	int num;
	cout << "Введите номер добавляемого элемента: ";
	cin >> num;
	while (num < 0)
	{
		cout << "Некорректный ввод. Попробуйте ещё раз: ";
		cin >> num;
	}

	mystack* a;
	a = top;
	int i = 2;
	while (i < num)
	{
		a = a->pred;
		i++;
	}
	mystack* e = a->pred;
	mystack* z = new mystack;
	a->pred = z;
	z->pred = e;
	cout << "Введите добавляемый элемент: ";
	cin >> z->data;
}

int main()
{
	setlocale(0, "");
	int n;
	cout << "Введите количество элементов в стеке: ";
	cin >> n;

	Stack s;

	s.make(n);

	cout << "Введенный стек: ";
	s.print();

	s.add();

	cout << "Стек после добавления: ";
	s.print();

	return 0;
}
