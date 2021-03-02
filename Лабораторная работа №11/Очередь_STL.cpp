#include <iostream>
#include <queue>
#include <iterator>
using namespace std;

int n;
queue<double> qu;
double* arr;
double* new_arr;

void print(queue<double> qu)
{
	int p = qu.size();
	arr = new double[n];
	for (int i = 0; i < p; i++)
	{
		arr[i] = qu.front();
		cout << qu.front() << " ";
		qu.pop();
	}
	for (int i = 0; i < p; i++)
		qu.push(arr[i]);
	cout << endl;
}

void del() 
{
	int z;
	if (n % 2 == 0) z = n / 2;
	else z = n / 2 + 1;
	new_arr = new double[z];
	int i = 0;
	while (!qu.empty())
	{
		new_arr[i++] = qu.front();
		qu.pop();
		if (!qu.empty()) qu.pop();
	}
	for (int i = 0; i < z; i++)
		qu.push(new_arr[i]);
}

int main()
{
	setlocale(LC_ALL, "Rus");
	cout << "Введите количество элементов очереди: ";
	cin >> n;
	
	for (int i = 0; i < n; i++)
	{
		double a;
		cin >> a;
		qu.push(a);
	}

	cout << "Введенная очередь: ";
	print(qu);

	del();

	cout << "Очередь после удаления: ";
	print(qu);
	return 0;
}
