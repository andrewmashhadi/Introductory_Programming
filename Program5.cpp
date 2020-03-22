/*
Andrew Mashhadi
1825831
andrew_mashhadi@elcamino.edu
Visual Studio
Windows 10
Assignment #5
March 23, 2018
*/ 

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

int main()
{
	cout << "Welcome to El Camino College Software engineering lab." << endl;
	cout << "We will calculate average carbon footprint and corresponding fines." << endl;
	cout << "Please be ready to provide the data file name for carbon footprint in US cities." << endl;
	string outfilename;
	cout << "Please enter full path to output file: ";
	getline(cin, outfilename);
	ofstream out(outfilename);

	if (out.is_open())
	{	
		out << "Welcome to El Camino College Software engineering lab." << endl;
		out << "We will calculate average carbon footprint and corresponding fines." << endl;
		string infilename;
		cout << "Enter full path to input file. File must exist: ";
		getline(cin, infilename);
		ifstream in(infilename);
		if (in.is_open())
		{
			cout << fixed << showpoint << setprecision(2);
			out << fixed << showpoint << setprecision(2);
			int numcities = 0;
			double totalfine = 0;
			cout << "************************************************************************************************" << endl;
			out << "************************************************************************************************" << endl;
			cout << setw(30) << left << "City" << setw(30) << left << "Rounded Average Carbon FP" << setw(30) << left << "Fine <$>" << endl;
			out << setw(30) << left << "City" << setw(30) << left << "Rounded Average Carbon FP" << setw(30) << left << "Fine <$>" << endl;
			cout << "************************************************************************************************" << endl;
			out << "************************************************************************************************" << endl;
			while (in.peek() != EOF)
			{
				numcities++;
				string cityname;
				int onecarbonfp;
				int sum = 0;
				int count = 0;
				double fine = 0;
				in >> cityname;
				in >> onecarbonfp;
				while (onecarbonfp >= 0)
				{
					sum += onecarbonfp;
					count++;
					in >> onecarbonfp;
				}
				if (count > 0)
				{
					double unroundedavg = static_cast<double>(sum) / count;
					int CFPavg = static_cast<int>(unroundedavg + .5);
					if (CFPavg <= 1)
					{
						fine = 0;
					}
					else if ( CFPavg <= 3)
					{
						fine = 1000000.00;
					}
					else if ( CFPavg <= 5)
					{
						fine = 2000000.00;
					}
					else if ( CFPavg <= 7)
					{
						fine = 3000000.00;
					}
					else 
					{
						fine = 4500000.00;
					}
					cout << setw(30) << left << cityname << setw(30) << left << CFPavg << setw(30) << left << fine << endl;
					out << setw(30) << left << cityname << setw(30) << left << CFPavg << setw(30) << left << fine << endl;

				}
				else
				{
					cout << setw(30) << left << cityname << setw(50) << left << "No value available for carbon FP. Fine not calculated." << endl;
					out << setw(30) << left << cityname << setw(50) << left << "No value available for carbon FP. Fine not calculated." << endl;
				}
				totalfine += fine;
			}
			cout << "************************************************************************************************" << endl;
			out << "************************************************************************************************" << endl;
			cout << "Total number of cities in the file = " << numcities << endl;
			out << "Total number of cities in the file = " << numcities << endl;
			cout << "Total fine collected: $" << totalfine << endl;
			out << "Total fine collected: $" << totalfine << endl;
			cout << "Thank you for using El Camino College software engineering lab." << endl;
		}
		else
		{
			cout << "Failed to open input file." << endl;
		}
		in.close();
	}
	else
	{
		cout << "Failed to open or create file." << endl;
	}
	out.close();
	system("pause");
	return 0;
}