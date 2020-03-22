/*
Andrew Mashhadi
May 20, 2018
andrew_mashhadi@elcamino.edu
Dr. Singhal 
Windows 10
Visual Studio 
*/


#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct CreditCard {

	string CCN;
	string LastName;
	string FirstName;
	double balance;

	CreditCard()		//Default Constructor
	{
		CCN = "Credit Card Number Not Set";
		LastName = "Last Name Not Set";
		FirstName = "First Name Not Set";
		balance = 0.0;
	}

	CreditCard(string card, string last, string first, double bal)
	{
		CCN = card;
		LastName = last;
		FirstName = first;
		balance = bal;
	}
	
	//Get member functions 
	string getCreditCard()
	{
		return CCN;
	}
	string getFirstName()
	{
		return FirstName;
	}
	string getLastName()
	{
		return LastName;
	}
	string getFullName()
	{
		return FirstName + ' ' + LastName;
	}
	double getBalance()
	{
		return balance;
	}
	//Other member functions
	void ChargeToCard(double money)
	{
		double AvailableCredit = 1500 - balance;
		if (money > AvailableCredit)
		{
			cout << "Insuffiecient credit available. Charge Declined." << endl;
		}
		else
		{
			cout << "Charge Approved." << endl;
			balance += money;
		}
	}
	void makePaymentToCard(double money)
	{
		balance -= money;
	}
	void print()
	{
		cout << fixed << showpoint << setprecision(2);
		cout << "Credit Card Number: " << CCN << endl;
		cout << "Name: " << FirstName << ' ' << LastName << endl;
		cout << "Amount owed: $" << balance << endl;
		cout << "---------------------------------" << endl;
	}
};

//Functions Prototypes
void bubbleSort(CreditCard[], int, int);
int LinearSearch(CreditCard[], string, int, int);
void print(CreditCard[], int);

const int MAX = 100;

int main()
{
	//instructor code
	CreditCard CC1("56738", "JONES", "JIM", 0);
	CC1.ChargeToCard(200.99);
	CreditCard CC2("12345", "ASHLEY", "ADAM", 0);
	CC2.ChargeToCard(2000.000);
	CreditCard CC3("34567", "MAPOS", "BERTHA", 0);
	CC3.ChargeToCard(800.91);
	CreditCard CC4("98765", "BRAVE", "LISA", 0);
	CC4.ChargeToCard(1001.23);
	CreditCard CC5("23413", "NILLY", "WILLY", 0);
	CC5.ChargeToCard(700.00);
	CreditCard CC6("67895", "QUIRK", "JILL", 0);
	CC6.ChargeToCard(1400.91);

	CreditCard CardArray[MAX];
	CardArray[0] = CC1;
	CardArray[1] = CC2;
	CardArray[2] = CC3;
	CardArray[3] = CC4;
	CardArray[4] = CC5;
	CardArray[5] = CC6;
	int len = 6;      //number of accounts
	//end instructor code

	bool done = false;
	while (!done)
	{
		cout << "**********************************************************************" << endl;
		cout << "*                                MENU                                *" << endl;
		cout << "**********************************************************************" << endl;
		cout << "* 1) Print credit card list in its current state to console.         *" << endl;
		cout << "* 2) Sort credit card list based on last name.                       *" << endl;
		cout << "* 3) Sort credit card list based on credit card number.              *" << endl;
		cout << "* 4) Sort credit list based on balance                               *" << endl;
		cout << "* 5) Search credit card list based on custumer last name.            *" << endl;
		cout << "* 6) Search credit list based on credit card number.                 *" << endl;
		cout << "* 7) Exit.                                                           *" << endl;
		cout << "**********************************************************************" << endl;
		cout << "Enter the number corresponding to the option you want: ";
		int response;
		cin >> response;
		bool optionflag = (response == 1) || (response == 2) || (response == 3) || (response == 4) || (response == 5) || (response == 6) || (response == 7);
		if (optionflag)
		{
			if (response == 1)
			{
				print(CardArray, len);
			}
			else if (response == 2)
			{
				bubbleSort(CardArray, len, 1);
			}
			else if (response == 3)
			{
				bubbleSort(CardArray, len, 2);
			}
			else if (response == 4)
			{
				bubbleSort(CardArray, len, 3);
			}
			else if (response == 5)
			{
				cout << "Enter the last name of the customer you are looking for: ";
				string namesearched;
				cin >> namesearched;
				for (int i = 0; i < static_cast<signed>(namesearched.length()); i++)
				{
					namesearched[i] = toupper(namesearched[i]);
				}

				int position = LinearSearch(CardArray, namesearched, len, 1);
				if (position >= 0)
				{
					cout << "Credit card was found. The information will be presented below." << endl;
					cout << "***************************************************************" << endl;
					CardArray[position].print();
				}
				else
				{
					cout << "Last name was not found in data base." << endl;
				}
			}
			else if (response == 6)
			{
				cout << "Enter the credit card number you are looking for: ";
				string cardsearched;
				cin >> cardsearched;
				int position = LinearSearch(CardArray, cardsearched, len, 2);
				if (position >= 0)
				{
					cout << "Credit card was found. The information will be presented below." << endl;
					cout << "***************************************************************" << endl;
					CardArray[position].print();
				}
				else
				{
					cout << "Last name was not found." << endl;
				}
			}
			else if (response == 7)
			{
				cout << "Thank you. Goodbye." << endl;
				done = true;
			}
		}
		else
		{
			cout << "Invalid entry. Please re-enter the number corresponding to the option you want:";
			cin >> response;
		}
		
	}
	system("pause");
	return 0;
}
int LinearSearch(CreditCard CardArray[], string searched, int len, int flag) 
{
	if (flag == 1)
	{
		int index = 0;
		int position = -1;
		bool found = false;
		while (index < len && !found)
		{
			if (CardArray[index].LastName == searched)
			{
				found = true;
				position = index;
			}
			index++;
		}
		return position;
	}
	else if (flag == 2)
	{

		int index = 0;
		int position = -1;
		bool found = false;
		while (index < len && !found)
		{
			if (CardArray[index].CCN == searched)
			{
				found = true;
				position = index;
			}
			index++;
		}
		return position;
	}
	
}


void print(CreditCard Account[], int len)
{
	for (int i = 0; i < len; i++)
	{
		Account[i].print();
	}
}
void bubbleSort(CreditCard Account[], int len, int flag)
{
	if (flag == 1)      //Sort by Last Name
	{	
		bool swap;
		string temp;
		do
		{
			swap = false;
			for (int count = 0; count < (len - 1); count++)
			{
				if (Account[count].LastName > Account[count + 1].LastName)
				{
					temp = Account[count].LastName;
					Account[count].LastName = Account[count + 1].LastName;
					Account[count + 1].LastName = temp;
					swap = true;
				}
			}
		} while (swap);

	}
	else if (flag == 2)	    //Sort by Card Number
	{
		bool swap;
		string temp;
		do
		{
			swap = false;
			for (int count = 0; count < (len - 1); count++)
			{
				if (Account[count].CCN > Account[count + 1].CCN)
				{
					temp = Account[count].CCN;
					Account[count].CCN = Account[count + 1].CCN;
					Account[count + 1].CCN = temp;
					swap = true;
				}
			}
		} while (swap);

	}
	else                    //Sort by balance
	{
		bool swap;
		double temp;
		do
		{
			swap = false;
			for (int count = 0; count < (len - 1); count++)
			{
				if (Account[count].balance > Account[count + 1].balance)
				{
					temp = Account[count].balance;
					Account[count].balance = Account[count + 1].balance;
					Account[count + 1].balance = temp;
					swap = true;
				}
			}
		} while (swap);

	}
}
