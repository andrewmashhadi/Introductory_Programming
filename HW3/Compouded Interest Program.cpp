/* 
Andrew Mashhadi
1825831
andrew_mashhadi@elcamino.edu
Microsoft Visual Sudio
Windows 10
Assignemnt #2
2/27/18
*/
#include <iostream>
#include <cmath>
using namespace std;
//17/17
int main()
{
	double A;
	double p;
	double r;
	int q;
	int n;
	cout << "Hello, please input your intitial deposit or principle:";
	cin >> p;
	cout << "What is the annual interest rate in decimalized form (For example, 7.2% should be typed as .072)";
	cin >> r;
	cout << "How many times is the compounding done each year?";
	cin >> q;
	cout << "How many years will the principle be left in the account?";
	cin >> n;
	A = p * pow(1 + (r / q), n*q);
	double TotalPennies = A * 100;
	int RoundedPennies = static_cast<int>(TotalPennies + .5);
	int Dollars = RoundedPennies / 100;
	int Cents = RoundedPennies % 100;
	r = (r * 100);
	cout << "With the rate of " << r << "%," << " your total accumulation after " << n << " years, will be " << A << endl;
	cout << "You will have " << Dollars << " dollars and " << Cents << " cents" << endl;
	cout << "Thank you for using Andrew's compounded interest calculator\n Goodbye." << endl;

	system("pause");
	return 0;
}
