#include "Pair.h"
#include <iostream>
#include <map>
using namespace std;

typedef map<int, Pair> TMap;
typedef TMap::iterator it;

TMap make_map(int n)
{
    TMap m;
    Pair a;
    for (int i = 0; i < n; i++)
    {
        cin >> a;
        m.insert(make_pair(i, a));
    }
    return m;
}

void print_map(TMap& m)
{
    for (int i = 0; i < m.size(); i++)
        cout << i << "=" << m[i] << " " << endl;
}

Pair middle(TMap& m)
{
    Pair s = m[0];
    for (int i = 1; i < m.size(); i++)
        s = s + m[i];
    int n = m.size();
    return s / n;
}

void delete_middle(TMap& m, Pair& sr)
{
    int n = m.size();
    Pair el = sr;
    for (int i = 0; i < m.size(); i++)
    {
        m[i] = m[i] - el;
    }
}

int main()
{
    setlocale(0, "");
    int n;
    cout << "Введите количество элементов: "; cin >> n;
    map<int, Pair> m = make_map(n);
    print_map(m);
    Pair sr = middle(m);
    cout << "Среднее = " << sr << endl;
    int pos1;
    cout << "Введите позицию, на которую вы хотите вставить среднее значение: "; cin >> pos1;
    m.insert(make_pair(pos1, sr));
    print_map(m);
    int pos2;
    cout << "Введите позицию элемента, который вы хотите удалить: "; cin >> pos2;
    m.erase(pos2);
    print_map(m);
    cout << endl;
    delete_middle(m, sr);
    print_map(m);
}
