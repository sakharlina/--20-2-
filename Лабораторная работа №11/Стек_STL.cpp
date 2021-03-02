#include <iostream>
#include <stack>
using namespace std;

int n;
char a, b;
stack<char> st;
stack<char> st2;

void print(stack<char> st)
{
	int p = st.size();
	if (p == 0) cout << "Стек пуст";
	else {
		for (int i = 0; i < p; i++)
		{
			cout << st.top() << " ";
			st.pop();
		}
	}
	cout << endl;
}

void add()
{
	int num;
	cout << "Введите номер добавляемого элемента: ";
	cin >> num;
	while (num < 0)
	{
		cout << "Некорректный ввод. Попробуйте ещё раз: ";
		cin >> num;
	}
	for (int i = 0; i < n - num + 1; i++)
	{
		st2.push(st.top());
		st.pop();
	}
	cout << "Введите добавляемый элемент: ";
	cin >> a;
	st.push(a);
	for (int i = 0; i < n - num + 1; i++)
	{
		st.push(st2.top());
		st2.pop();
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Введите количество элементов в стеке: ";
	cin >> n;
	cout << "Введите элементы стека: ";
	for (int i = 0; i < n; i++)
	{
		cin >> a;
		st.push(a);
	}

	cout << "Введенный стек: ";
	print(st);

	add();

	cout << "Стек после добавления: ";
	print(st);

	return 0;
}
