#include "Receipt.h"
#include <iostream>
#include <string>
using namespace std;

Receipt::Receipt()
{
	number = 0;
	date = "";
	sum = 0;
	cout << "Конструктор без параметра для объекта " << this << endl;
}

Receipt::Receipt(int N, string K, double S)
{
	number = N;
	date = K;
	sum = S;
	cout << "Конструктор с параметром для объекта " << this << endl;
}

Receipt::Receipt(const Receipt& t)
{
	number = t.number;
	date = t.date;
	sum = t.sum;
	cout << "Конструктор копирования для объекта " << this << endl;
}

Receipt::~Receipt()
{
	cout << "Деструктор для объекта " << this << endl;
}

int Receipt::get_number()
{
	return number;
}

string Receipt::get_date()
{
	return date;
}

double Receipt::get_sum()
{
	return sum;
}

void Receipt::set_number(int N)
{
	number = N;
}

void Receipt::set_date(string K)
{
	date = K;
}

void Receipt::set_sum(double S)
{
	sum = S;
}

void Receipt::print()
{
	cout << endl << "КВИТАНЦИЯ" << endl;
	cout << "Номер: " << number << endl;
	cout << "Дата: " << date << endl;
	cout << "Сумма: " << sum << endl;
}
