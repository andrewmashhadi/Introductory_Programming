#include "IntArray.h"
#include <iostream>

using namespace std;


IntArray::IntArray(int n)
{
	intlist = new int[n];
	num_el = n;
	for (int i = 0; i < n; i++)
	{
		intlist[i] = 0;
	}
}

IntArray::~IntArray()
{
	delete[] intlist;
}
bool IntArray::isValidElm(int n)
{
	if ((n < 0 || n >= num_el)) 
	{
		return true;
	}
	else
	{
		return false;
	}

}
void IntArray::setElement(int &elm, int val)
{
	while (isValidElm(elm))
	{
		cout << "ERROR: Invalid entry, must be between -1 and "<<num_el<<"\nTry again:";
		cin >> elm;
	}
	*(intlist + elm) = val;
}
int IntArray::getElement(int elm)
{
	while (elm < 0 || elm >= num_el)
	{
		cout << "ERROR: Invalid entry, must be between -1 and " << num_el << "\nTry again:";
		cin >> elm;
	}
	return intlist[elm];
}



