#include "Dialog.h"
#include "Object.h"
#include "Tree.h"
#include "Person.h"
#include "Emloyee.h"
void main()
{
	Person* a = new Person;
	a->Input();
	a->Show();

	Emloyee* b = new Emloyee;
	b->Input();
	b->Show();

	Tree t(10);
	t.Add();
	t.Add();
	t.Show();
	t.Del();
	cout << "\nTree size = " << t();

	Dialog D(10);
	D.Execute();
}
