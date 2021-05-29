#include "Tree.h"
#include "Person.h"

Tree::~Tree(void)
{
	if (begin != 0) delete[] begin;
	begin = 0;
}

Tree::Tree(int n)
{
	begin = new Object * [n];
	cur = 0;
	size = n;
}

void Tree::Add()
{
	Object* p;
	cout << "\n\n1. Person" << endl;
	cout << "2. Emloyee" << endl;
	int num;
	cin >> num;
	if (num == 1)
	{
		Person* a = new (Person);
		a->Input();
		p = a;

		if (cur < size)
		{
			begin[cur] = p;
			cur++;
		}
	}
	else if (num == 2)
	{
		Emloyee* b = new Emloyee;
		b->Input();
		p = b;

		if (cur < size)
		{
			begin[cur] = p;
			cur++;
		}
	}
	else return;
}

void Tree::Show()
{
	if (cur == 0) cout << "Empty" << endl;
	Object** p = begin;
	for (int i = 0; i < cur; i++)
	{
		(*p)->Show();
		p++;
	}
}

int Tree::operator() ()
{
	return cur;
}

void Tree::Del()
{
	if (cur == 0) return;
	cur--;
}

void Tree::HandleEvent(const TEvent& e)
{
	if (e.what == evMassage)
	{
		Object** p = begin;
		if (e.a >= 0 && e.a <= cur)
		{
			for (int i = 0; i < e.a; i++)
				p++;
		}
		(*p)->HandleEvent(e);
	}
}
