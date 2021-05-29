#pragma once
#include "Object.h"
#include "Emloyee.h"

class Tree
{
public:
	Tree(int);
public:
	~Tree(void);
	void Add();
	void Del();
	void Show();
	int operator() ();
	void HandleEvent(const TEvent& e);
protected:
	Object** begin;
	int size;
	int cur;
};
