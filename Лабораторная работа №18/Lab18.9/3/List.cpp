#include "List.h"
#include "Error.h"

List::List(int s) 
{
	if (s > MAX_SIZE) throw MaxSizeError();
	size = s;
	begin = new int[s];
	for (int i = 0; i < size; i++)
		begin[i] = 0;
}

List::List(const List& l)
{
	size = l.size;
	begin = new int[size];
	for (int i = 0; i < size; i++)
		begin[i] = l.begin[i];
}

List::~List() {
	if (begin != 0) delete[] begin;
}

List::List(int s, int* mas) 
{
	if (s > MAX_SIZE) throw MaxSizeError();
	size = s;
	begin = new int[size];
	for (int i = 0; i < size; i++)
		begin[i] = mas[i];
}

const List& List::operator= (const List& l) 
{
	if (this == &l) return *this;
	if (begin != 0) delete[]begin;
	size = l.size;
	begin = new int[size];
	for (int i = 0; i < size; i++)
		begin[i] = l.begin[i];
	return *this;
}

ostream& operator<< (ostream& out, const List& l) 
{
	if (l.size == 0) out << "Empty\n";
	else {
		for (int i = 0; i < l.size; i++)
			out << l.begin[i] << " ";
		out << endl;
	}
	return out;
}

istream& operator>> (istream& in, List& l) 
{
	for (int i = 0; i < l.size; i++) 
	{
		cout << ">";
		in >> l.begin[i];
	}
	return in;
}

int List::operator[] (int i) {
	if (i < 0) throw IndexError1();
	if (i >= size) throw IndexError2();
	return begin[i];
}

List List:: operator+ (int k)
{
	for (int i = 0; i < size; i++) 
	{
		begin[i] += k;
	}
	return *this;
}

List List::operator++ () 
{
	if (size == MAX_SIZE) throw MaxSizeError();
	List temp(size, begin);
	delete[]begin;
	size++;
	begin = new int[size];
	int k;
	cout << "Введите число: ";
	cin >> k;
	begin[size - 1] = k;
	for (int i = 0; i < size - 1; i++)
		begin[i] = temp.begin[i];
	return *this;
}
