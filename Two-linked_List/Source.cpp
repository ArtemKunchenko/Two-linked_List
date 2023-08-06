#include<iostream>
#include "List.h"
#include "List.cpp"
using namespace std;

int main()
{
	List<int>ex;
	ex.pushBack(1);
	ex.pushBack(2);
	ex.pushBack(3);
	ex.print();
	ex.pushFront(0);
	ex.print();
	ex.pushBack(4);
	ex.print();
	ex.popFront();
	ex.print();
	ex.popBack();
	ex.print();
	ex.insert(1, 2);
	ex.print();
	cout << "Size is: " << ex.getSize() << endl;
	for (int i = 0; i < ex.getSize(); i++)
	{
		cout << "Element number " << i + 1 << " is " << ex[i] << endl;
	}
	system("pause");
	return 0;
}