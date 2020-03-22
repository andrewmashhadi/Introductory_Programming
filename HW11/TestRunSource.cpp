#include "IntArray.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
#include <fstream>
#include <vector>

using namespace std;


int main()
{   
	int size;
	cout << "Enter length of sample array: ";
	cin >> size;
	IntArray sample(size);
	for (int j = 0; j < size; j+=2)
	{
		sample.setElement(j, j);
	}
	for (int j = 0; j < size; j++)
	{
		cout << sample.getElement(j) << '\t';
	}
	cout << endl;
	char count = ' ';
	int el;
	int val;
	while (count != 'D' && count != 'd')
	{
		cout << "Please enter the element and the value you want stored at that element: ";
		cin >> el >> val;
		sample.setElement(el, val);
		cout << "The sample array has stored " << sample.getElement(el) << " in its #" << el <<" element"<< endl;
		cout << "Press D if you are done storing values in the sample array, anything else to continue.";
		cin >> count;
	}
	cout << "The following are all the values stored in the sample array:" << endl;
	for (int j = 0; j < size; j++)
	{
		cout << sample.getElement(j) << '\t';
	}
	

	return 0;
}

