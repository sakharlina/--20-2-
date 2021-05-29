#include <iostream>
#include "fraction.h"
using namespace std;

fraction make_fraction(int F, double S)
{
	fraction t;
	t.Init(F, S);
	return t;
}

int main()
{
	fraction A;
	fraction B;
	A.Init(2, 5.0);
	B.Read();
	A.Show();
	B.Show();
	cout << "A.Multiplic(" << A.first << ", " << A.second << ") = " << A.Multiplic() << endl;
	cout << "B.Multiplic(" << B.first << ", " << B.second << ") = " << B.Multiplic() << endl;

	fraction* X = new fraction;
	X->Init(5, 3.0);
	X->Show();
	X->Multiplic();
	cout << "X.Multiplic(" << X->first << ", " << X->second << ") = " << X->Multiplic() << endl;

    fraction mas[3];
    for (int i = 0; i < 3; i++)
        mas[i].Read();
    for (int i = 0; i < 3; i++)
        mas[i].Show();
    for (int i = 0; i < 3; i++) 
    {
        mas[i].Multiplic();
        cout << "mas[" << i << "].Summa(" << mas[i].first << ", " << mas[i].second << ") = ";
        cout << mas[i].Multiplic() << endl;
    }

    fraction* p_mas = new fraction[3];
    for (int i = 0; i < 3; i++)
        p_mas[i].Read();
    for (int i = 0; i < 3; i++)
        p_mas[i].Show();
    for (int i = 0; i < 3; i++) 
    {
        p_mas[i].Multiplic();
        cout << "p_mas[" << i << "].Summa(" << p_mas[i].first << ", " << p_mas[i].second << ") = ";
        cout << p_mas[i].Multiplic() << endl;
    }

    double y;
    int z;

    cout << "first? ";
    cin >> y;
    cout << "second? ";
    cin >> z;

    fraction F = make_fraction(y, z);
    F.Show();

    return 0;
}
