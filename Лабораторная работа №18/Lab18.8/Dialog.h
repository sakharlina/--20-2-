#pragma once
#include "Tree.h"
#include "Event.h"

class Dialog:
public Tree
{
public:
	Dialog(int);
public:
	virtual ~Dialog(void);
	virtual void GetEvent(TEvent& event);
	virtual int Execute();
	virtual void HandleEvent(TEvent& event);
	virtual void ClearEvent(TEvent& event);
	int Valid();
	void EndExec();
protected:
	int EndState;
};
