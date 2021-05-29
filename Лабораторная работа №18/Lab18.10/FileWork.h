#pragma once
#include "Pair.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int MakeFile(const char* f_name)
{
	fstream stream(f_name, ios::out|ios::trunc);
	if (!stream) return -1;
	int n;
	Pair p;
	cout << "N? "; cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> p;
		stream << p << "\n";
	}
	stream.close();
	return n;
}

int PrintFile(const char* f_name)
{
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	Pair p; int i = 0;
	while (stream >> p)
	{
		cout << p << "\n";
		i++;
	}
	stream.close();
	return i;
}

int DeleteFile(const char* f_name, Pair& s)
{
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	int i = 0; Pair p;
	while (stream >> p)
	{
		if (stream.eof()) break;
		i++;
		if (!(p > s)) temp << p;
	}
	stream.close(); temp.close();
	remove(f_name);
	rename("temp", f_name);
	return i;
}

int AddFile(const char* f_name, int k, int n)
{
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	Pair p; 
	int i = 0, f = 0;
	while (stream >> p)
	{
		if (stream.eof()) break;
		i++;
		while (i > n && k > 0)
		{
			Pair pp;
			cin >> pp;
			temp << pp;
			k--;
			f = 1;
			i++;
		}
		temp << p;
	}
	stream.close(); temp.close();
	remove(f_name);
	rename("temp", f_name);
	return f;
}

int AddEnd(const char* f_name, int k)
{
	fstream stream(f_name, ios::app);
	if (!stream) return -1;
	for (int i = k; i > 0; i--)
	{
		Pair pp;
		cin >> pp;
		stream << pp;
	}
	return 0;
}

int ChangeFile(const char* f_name, int k, int l)
{
	fstream temp("temp", ios::out);
	fstream stream(f_name, ios::in);
	if (!stream) return -1;
	Pair p; int i = 0, c = 0;
	while (stream >> p)
	{
		if (stream.eof()) break;
		i++;
		if (p.first = k)
		{
			cout << p << " - is changing...";
			p.first += l;
			c++;
		}
	    temp << p;
	}
	stream.close(); temp.close();
	remove(f_name);
	rename("temp", f_name);
	return c;
}
