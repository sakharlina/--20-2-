#include "List.h"
#include "Pair.h"
#include<iostream>
using namespace std;
void main()
{
	List<Pair>mylist(5);
	mylist.print_list();
	Pair s = mylist.middle();
	cout << "\nSrednee = " << s;
	int  pos;
	cout << "\n\nPOSITION? "; cin >> pos;
	mylist.add_list(s, pos);
	mylist.print_list();
	int  pos1;
	cout << "\n\nNUMBER? "; cin >> pos1;
	mylist.delete_list(pos1);
	mylist.print_list();
	cout << endl;
	mylist.delsrednee(s);
	mylist.print_list();
}
