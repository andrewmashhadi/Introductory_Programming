/*
Andrew Mashhadi
1825831
andrew_mashhadi@elcamino.edu
Visual Studio
Windows 10
Assignment #4
3/15/18
*/

#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

const double BasePayFactory = 800.00;
const double BasePayOffice = 1000.00;
const double BasePayManage = 1500.00;

int main()
{
	cout << "Please enter your first and last name: ";
	string name;
	getline(cin, name);
	cout << "Hello " << name << '!' << endl;
	cout << "Welcome to Badwater Brewery's paymaster express.\nWe will be using your emplyee data to determine your gross pay." << endl;
	cout << "Please enter your single letter emplyee code (S for Factory, O for Office, M for managment): " << endl;
	char Ecode;
	cin >> Ecode;
	bool flagbasecode = (Ecode == 'S') || (Ecode == 'O') || (Ecode == 'M');
	cout << "Please enter your employee ID number:" << endl;
	int IDnum;
	cin >> IDnum;
	cout << "Depending on your job description, a percentage of your base pay will be added to your total payment." << endl;
	cout << "Please enter your job classification code (Enter 1, 2, or 3): " << endl;
	int Jcode;
	cin >> Jcode;
	bool flagjobcode = (Jcode == 1) || (Jcode == 2) || (Jcode == 3);
	cout << "How many years have you been with the Badwater Brewery (Enter whole number of years, no more than 50 years)? "<<endl;
	int Yserv;
	cin >> Yserv;
	bool flagyserv = (Yserv >= 0) && (Yserv <= 50);
	cout << "Depending on your level of education, a certain percentage of your basepay will be added to your total payment." << endl;
	cout << "What is your highest level of education?" << endl;
	cout << "For High School, enter 1. For Junior college, enter 2. For University, enter 3. For Graduate school, enter 4.\n";
	int Edcode;
	cin >> Edcode;
	bool flagedcode = (Edcode == 1) || (Edcode == 2) || (Edcode == 3) || (Edcode == 4);
	string jobdescript;
	double basepay = 0;
	double grosspay = 0;
	if (flagbasecode && flagjobcode && flagyserv && flagedcode)
	{
		if (Ecode == 'S')
		{
			jobdescript = "Factory Worker";
			basepay = BasePayFactory;
		}
		else if (Ecode == 'o')
		{
			jobdescript = "Office Worker";
			basepay = BasePayOffice;
		}
		else
		{
			jobdescript = "Management";
			basepay = BasePayManage;
		}
		if (Jcode == 1)
		{
			grosspay = 1.05*basepay;
		}
		else if (Jcode == 2)
		{
			grosspay = 1.10*basepay;
		}
		else
		{
			grosspay = 1.20*basepay;
		}
		if (Yserv <= 10)
		{
			grosspay = grosspay + .05 * basepay;
		}
		else 
		{
			grosspay = grosspay + (.05 *basepay) + (Yserv - 10)*.01 *basepay;
		}
		if (Edcode == 1)
		{
			grosspay = grosspay;
		}
		else if (Edcode == 2)
		{
			grosspay = grosspay + (.05 * basepay);
		}
		else if (Edcode == 3)
		{
			grosspay = grosspay + (.12 * basepay);
		}
		else
		{
			grosspay = grosspay + (.2 * basepay);
		}		
		cout << fixed << showpoint << setprecision(2);
		cout << "******************************************************************************************************" << endl;
		cout << setw(20) << left << "Name" << setw(20) << left << "ID#" << setw(20) << left << "Job Type" << setw(20) << left << "Gross Salary" << endl;
		cout << setw(20) << left << name << setw(20) << left << IDnum << setw(20) << left << jobdescript << '$' << setw(19) << left << grosspay << endl;
		cout << "******************************************************************************************************" << endl;
	}
	else
	{
		cout << "CAUTION! One or more of your codes were entered incorrectly." << endl;
		if (!flagbasecode)
		{
			cout << "Invalid employee code was entered. Please restart program." << endl;
		}
		if (!flagjobcode)
		{
			cout << "Invalid job code was entered. Please restart program." << endl;
		}
		if (!flagyserv)
		{
			cout << "Invalid years of service was entered. Please restart program. " << endl;
		}
		if (!flagedcode)
		{
			cout << "Invalid educational code was entered. Please restart program." << endl;
		}
	}
	cout << "Thank you for using Badwater Brewery's paymaster express. Goodbye." << endl;
	system("pause");
		return 0;
}
