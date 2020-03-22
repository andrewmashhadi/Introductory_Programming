/*
Andrew Mashhadi
Visual Studio 
windows 10
andrew_mashhadi@elcamino.edu
5/12/18
Assignment 9
*/


#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
using namespace std;

struct BankAccount
{
	int ActNum;
	string LastName;
	string FirstName;
	double balance;

	
	//Constructor prototypes
	BankAccount();
	BankAccount(int, string, string, double);
	
	//Member function prototypes
	void print();
	int getAccountNumber();
	double getBalance();
	string getFirstName();
	string getLastName();
	string getFullName();
	void setLastName(const string &);
	void deposit(double);
	void withdraw(double);
	void print(ofstream &);    //Overloading print function

};

BankAccount::BankAccount() //Default Constructor 
{
	FirstName = "First name was not set.";
	LastName = "Last name was not set.";
	ActNum = 0;
	balance = 0.0;
}

BankAccount::BankAccount(int act, string first, string last, double bal) //explicit constructor
{
	FirstName = first;
	LastName = last;
	ActNum = act;
	balance = bal;
}

void BankAccount::print()
{
	cout << fixed << showpoint << setprecision(2);
	cout << "Name: " << FirstName << ' ' << LastName << endl;
	cout << "Account Number: " << ActNum << endl;
	cout << "Balance: $" << balance << endl;
}

int BankAccount::getAccountNumber()
{
	return ActNum;
}

double BankAccount::getBalance()
{
	return balance;
}
string BankAccount::getFirstName()
{
	return FirstName;
}
string BankAccount::getLastName()
{
	return LastName;
}
string BankAccount::getFullName()
{
	return FirstName + ' ' + LastName;
}
void BankAccount::setLastName(const string & newlast)		//To change or corect last name
{
	LastName = newlast;
}
void BankAccount::deposit(double dep)
{
	balance += dep;
	cout << "New Account Balance: $" << balance << endl;
}
void BankAccount::withdraw(double money)
{
	if (money > balance)
	{
		cout << "Invalid withdrawal amount, insuffitient balance. Withdrawal declined." << endl;
	}
	else
	{
		cout << "Withdrawal Approved." << endl;
		balance -= money;
		cout << "New Account Balance: $" << balance << endl;
	}
}

void BankAccount::print(ofstream & out)
{
	out << fixed << showpoint << setprecision(2);
	out << "Name: " << FirstName << ' ' << LastName << endl;
	out << "Account Number: " << ActNum << endl;
	out << "Balance: $" << balance << endl;
}



int main()
{

	bool done = false;
	BankAccount P1; 
	/*
	Very inmportant to place before loop, 
	will use default construcor for prints because 
	next iteration will reset constuctor 
	*/

	while (!done)
	{
		cout << fixed << showpoint << setprecision(2);
		cout << "----------------------------------------------------------------" << endl;
		cout << "---	  	 	   Menu				     ---" << endl;
		cout << "----------------------------------------------------------------" << endl;
		cout << "--- 1. Create a User Profile for your Bank Account           ---" << endl;
		cout << "--- 2. Print your Account Details to Console                 ---" << endl;
		cout << "--- 3. Print your Account Details to Output file             ---" << endl;
		cout << "--- 4. Make a Deposit                                        ---" << endl;
		cout << "--- 5. Make a withdrawal                                     ---" << endl;
		cout << "--- 6. Print your current balance to console                 ---" << endl;
		cout << "--- 7. Print account holder's full name                      ---" << endl;
		cout << "--- 8. Update your last name                                 ---" << endl;
		cout << "--- 9. Exit                                                  ---" << endl;
		cout << "----------------------------------------------------------------" << endl;
		cout << "Please enter the corresponding number to select your option: ";
		int choice;
		cin >> choice;
		bool choiceflag = (choice == 1) || (choice == 2) || (choice == 3) || (choice == 4) || (choice == 5) || (choice == 6) || (choice == 7) || (choice == 8) || (choice == 9);
		if (choiceflag)
		{

			if (choice == 1)
			{
				string first;
				string last;
				int accountnum;
				double balance;
				cout << "Please enter your first name: ";
				cin >> first;
				cout << "Please enter your last name: ";
				cin >> last;
				cout << "Please enter your account number: ";
				cin >> accountnum;
				cout << "Please enter your account balance [XX.YY]: $";
				cin >> balance;
				P1 = BankAccount(accountnum, first, last, balance);		// Calls constructor after instead of intially 
				/*
				Could initialize the explicit constructor with
				BankAccount P1(accountnum, first, last, balance)
				but P1 will only remain in scope of this if statement
				*/
				cout << "\n\n";
			}
			if (choice == 2)
			{
				P1.print();
				cout << "\n\n";
			}
			if (choice == 3)
			{
				string filepath;
				bool done2 = false;
				ofstream outfile;

				while (!done2)
				{
					cout << "Please enter the full path to file: ";
					cin.ignore(100, '\n');
					getline(cin, filepath);

					outfile.open(filepath);

					if (outfile.is_open())
					{
						cout << "File exists and is now open." << endl;
						P1.print(outfile);
						cout << "Information has been printed to attatched file." << endl;
						outfile.close();
						done2 = true;
					}
					else
					{
						cout << "File could not be found, please try again." << endl;
						
					}
					
				}
				cout << "\n\n";

			}
			if (choice == 4)
			{
				cout << "Please enter the amount you will deposit [XX.YY]: ";
				double money;
				cin >> money;
				P1.deposit(money);
				cout << "\n\n";
			}
			if (choice == 5)
			{
				cout << "Please enter the amount you want to withdraw [XX.YY]: ";
				double money;
				cin >> money;
				P1.withdraw(money);
				cout << "\n\n";
			}
			if (choice == 6)
			{
				cout << "Your current account balance is: $" << P1.getBalance() << endl;
				cout << "\n\n";
			}
			if (choice == 7)
			{
				cout << "The user's full name is: " << P1.getFullName() << endl;
				cout << "\n\n";
			}
			if (choice == 8)
			{
				string newlast;
				cout << "What is your new last name [MUST BE YOUR LEGAL LAST NAME]: ";
				cin >> newlast;
				P1.setLastName(newlast);
				cout << "Your current full name is now: " << P1.getFullName() << endl;
				cout << "\n";
			}
			if (choice == 9)
			{
				cout << "Thank you for choosing Bank Of FairyLand" << endl;
				cout << "Goodbye" << endl;
				done = true;
			}
			cout << "\n\n";
		}
		else
		{
			cout << "Please enter a number that is 1 through 9.\n\n" << endl;
		}

	}
	system("pause");
	return 0;
}