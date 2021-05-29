#include <iostream>
#include "fraction.h"
using namespace std;

void fraction::Init(int F, double S) 
{
	while (F < 0 || S < 0) 
	{
		cin >> F;
		cin >> S;
	}
	first = F;
	second = S;
}

void fraction::Read()
{
	cout << "\nfirst? ";
	cin >> first;
	while (first < 0) 
	{
		cin >> first;
	}
	cout << "\nsecond? ";
	cin >> second;
	while (second < 0) 
	{
		cin >> first;
	}
}

void fraction::Show()
{
	cout << "\nfirst = " << first;
	cout << "\nsecond = " << second;
	cout << endl;
}

double fraction::Multiplic()
{
	return first * second;
}
