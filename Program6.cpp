/*
Andrew Mashhadi
1825831
andrew_mashhadi@elcamino.edu
Visual Studio
Windows 10
Assignment #6
4/1/18
*/

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

void greeting();
double getUserData(string &, string &, double &, bool &);
double getGrossSalary(double, double);
double getTaxWitheld(double);
double getNetSalary(double, double, bool, string &);
void printResults(string, string, double, double, double, double, double, string);
void goodbye();

int main()
{
	for (size_t i = 0; i < 7; i++) {
		cout << fixed << showpoint << setprecision(2);
		greeting();
		double payRate;
		string firstName;
		string lastName;
		bool healthPlan;
		double hours;
		hours = getUserData(firstName, lastName, payRate, healthPlan);
		double GrossSalary;
		GrossSalary = getGrossSalary(hours, payRate);
		double Taxheld;
		Taxheld = getTaxWitheld(GrossSalary);
		double NetSalary;
		string HealthPlanMessage;
		NetSalary = getNetSalary(GrossSalary, Taxheld, healthPlan, HealthPlanMessage);
		printResults(firstName, lastName, hours, payRate, GrossSalary, Taxheld, NetSalary, HealthPlanMessage);
		goodbye();
	}
	
	
	system("pause");
	return 0;
}

//*********************************************************************************************************************************
void greeting()
{
	cout << "Welcome to salary calculation program." << endl;
	cout << "In this program we will ask for the information that would allow us to process your pay check." << endl;
	cout << "We will collect information about hours worked, hourly pay rate and medical options." << endl;
	cout << "Processing will be completed in just a few minutes." << endl; 	
}

double getUserData(string & fname, string & lname, double & rate, bool & hplan)
{
	cout << "\n------------------------------------------------------------------------------------------------------\n\n";
	cout << "Please enter your first name [One word only]: ";
	cin >> fname;
	cout << "Please enter your last name [One word only]: ";
	cin >> lname;
	cout << "Please enter hours worked (positive number only): ";
	double hours;
	cin >> hours;
	cout << "Please enter your hourly rate [For example, enter\n15.23 if your hourly pay rate is $15 and 23 cents]: ";
	cin >> rate;
	cout << "Enter 1 to purchase health plan or 0 (zero) to decline: ";
	cin >> hplan; 
	return hours;
}

double getGrossSalary(double hours, double rate)
{
	double gSal;
	if (hours <= 40)
	{
		gSal = hours * rate;
	}
	else
	{
		gSal = (40 * rate) + (hours - 40) * 1.5 * rate;
	}
	return gSal;
}

double getTaxWitheld(double gSal)
{
	double tax;
	tax = .071 * gSal;
	return tax;
}

double getNetSalary(double gSal, double tax, bool hplan, string & HealthMsg)
{
	double NetSal; 
	NetSal = gSal - tax;
	if (NetSal >= 200 && hplan)
	{
		NetSal -= 200;
		HealthMsg = "Employee opted for health insurance and was successfully registered.";
	}
	else if (NetSal < 200 && hplan)
	{
		HealthMsg = "Employee opted for health insurance but was declined because of insufficient salary.";
	}
	else
	{
		HealthMsg = "Employee did not opt to register in health plan.";
	}
	return NetSal;
}

void printResults(string fname, string lname, double hoursW, double rate, double grossSal, double tax, double netsal, string hplanmsg)
{
	cout << "\n------------------------------------------------------------------------------------------------------\n\n";
	cout << "Here are the Employee Payroll details." << endl;
	cout << "Name: " << fname << " " << lname << endl;
	cout << "Hours Worked: " << hoursW << endl;
	cout << "Hourly Pay Rate: $" << rate << endl;
	cout << "Gross Salary: $" << grossSal << endl;
	cout << "Tax withheld: $" << tax << endl;
	cout << hplanmsg << endl;
	cout << "Employee net Salary: $" << netsal << endl;
}

void goodbye()
{
	cout << "\n------------------------------------------------------------------------------------------------------\n\n";
	cout << "Thank you for using the salary calculator." << endl;
	cout << "Goodbye." << endl;
}




