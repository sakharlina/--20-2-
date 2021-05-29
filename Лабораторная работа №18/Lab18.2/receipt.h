#pragma once
#include <iostream>
#include <string>
using namespace std;

class Receipt
{
	int number;
	string date;
	double sum;
public:
	Receipt(); 
	Receipt(int, string, double);
	Receipt(const Receipt&); 
	~Receipt(); 
	int get_number(); 
	void set_number(int); 
	string get_date(); 
	void set_date(string); 
	double get_sum(); 
	void set_sum(double); 
	void print(); 
};
