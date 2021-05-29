#include "Pair.h"
#include "List.h"
#include <iostream>
using namespace std;

int main()
{
	setlocale(0, "");
	int n;
	cout << "Введите количество элемнтов: "; cin >> n;
    List <Pair> v(n);
    v.print();
    Pair sr = v.middle();
    cout << "Среднее = " << sr << endl;
    int pos1;
    cout << "Введите позицию, на которую вы хотите вставить среднее значение: "; cin >> pos1;
    v.add(pos1, sr);
    v.print();
    int pos2;
    cout << "Введите позицию элемента, который вы хотите удалить: "; cin >> pos2;
    v.del(pos2);
    v.print();
    cout << endl;
    v.delete_middle(sr);
    v.print();
    return 0;
}
