/*
Andrew Mashhadi
1825831
andrew_mashhadi@elcamino.edu
Microsoft Visual Studio
Windows 10
Assignment #3
March 4, 2018
*/
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() 
{
	for (int i = 0; i < 10; i++) {
		int A;
		int B;
		int C;
		int Discriminant;
		double root1;
		double root2;
		double real;
		double complex;
		double linearSol;
		cout << scientific;
		cout << "****************************************************************************" << endl;
		cout << setw(55) << "ANDREW MASHHADI'S QUADRATIC EQUATION SOLVER" << endl;
		cout << "****************************************************************************" << endl;
		cout << "This program will provide solutions for an equation of the form\n";
		cout << setw(40) << "Ax^2 + Bx + C = 0" << endl;
		cout << "Where A,B, and C are integers, and A is not equal to zero." << endl;
		cout << "****************************************************************************" << endl;
		cout << "Enter value of A (integer only): ";
		cin >> A;
		if (A == 0)
			cout << "Caution! If leading coefficient is zero then you actually do not have a quadratic equation. You may have a linear equation."
			<< " If you wish to solve the linear equation Bx + C = 0, then please proceed." << endl;
		cout << "Enter value of B (integer only): ";
		cin >> B;
		if (A == 0 && B == 0)
			cout << "Since A and B are both zero, you actually do not have an algebraic equation." << endl;
		if (A == 0 && B != 0)
		{
			cout << "Enter value of C (integer only): ";
			cin >> C;
			linearSol = (static_cast<double>(-C) / B);
			cout << "The one solution to the linear equation is" << setw(14) << "X = " << linearSol << endl;
		}
		if (A != 0)
		{
			cout << "Enter value of C (integer only): ";
			cin >> C;
			Discriminant = (B*B) - (4 * A * C);
			if (Discriminant > 0)
			{
				root1 = (-B + sqrt(Discriminant)) / (2 * A);
				root2 = (-B - sqrt(Discriminant)) / (2 * A);
				cout << "The two real solutions are" << setw(14) << "X = " << root1 << endl;
				cout << setw(26) << "And" << setw(14) << "X = " << root2 << endl;
			}
			else if (Discriminant < 0)
			{
				real = (static_cast<double>(-B) / (2 * A));
				complex = (sqrt(abs(Discriminant)) / (2 * A));
				cout << " The two imaginary solutions are" << setw(14) << "X = " << real << " + I*(" << complex << ')' << endl;
				cout << setw(32) << "And" << setw(14) << "X = " << real << " - I*(" << complex << ')' << endl;
			}
			else if (Discriminant == 0)
			{
				real = (static_cast<double>(-B) / 2 * A);
				cout << "The one real solution is" << setw(14) << "X = " << real << endl;
			}
			else
				cout << "The values for A, B, and C must be numerical integers. Please reopen the program and start over.";
		}
		cout << "****************************************************************************" << endl;
		cout << "Thank you for using Andrew Mashhadi's Quadratic Equation Solver." << endl;
		cout << "****************************************************************************" << endl;
	}
	system("pause");
	return 0;
}
