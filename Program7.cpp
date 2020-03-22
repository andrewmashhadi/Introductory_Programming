/*
Andrew Mashhadi
CS1 Assignment #7
Visual Studio 
andrew_mashhadi@elcamino.edu
Windows 10 
4/13/28
*/


#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
using namespace std;

void openFile(ifstream &, const string &);				// const allows to pass large data by reference (less data stored) but without mutations 
int fillQuestionsArray(string[], ifstream &);
int fillAnswerKeyArray(char[], ifstream &);
void fillResponseArray(const string[], char[], int);
int GradeResponses(const char[], const char[], int);
void printAnswersAndResponses(const string[], const char[], const char[]);

const int MAX = 20;
int main()
{
	cout << "Welcome to the Driving Test Program" << endl;
	string questions[MAX];
	char answers[MAX];
	char responses[MAX];
	ifstream in;
	openFile(in, "questions");
	int numqel = fillQuestionsArray(questions, in);
	in.close();
	openFile(in, "answers");
	int numael = fillAnswerKeyArray(answers, in);
	if (numqel == numael)
	{
		fillResponseArray(questions, responses, numqel);
		int correct = GradeResponses(answers, responses, numqel);
		int wrong;
		wrong = MAX - correct;
		double grade;
		grade = 100 * (static_cast<double>(correct) / MAX);
		cout << "\n\nYou scored " << correct << " out of 20 points." << endl;
		if (grade >= 90)
		{
			cout << "You passed with an A.\nCongrats!" << endl;
		}
		else if (grade >= 80)
		{
			cout << "You passed with a B.\nGood Job!" << endl;
		}
		else if (grade >= 70)
		{
			cout << "You passed with a C.\nBe careful on the road!" << endl;
		}
		else if (grade >= 60)
		{
		cout << "You recieved a D.\nConsider studying more before you drive." << endl;
		}
		else
		{
			cout << "You failed. Please review your answers." << endl;
		}
		printAnswersAndResponses(questions, answers, responses);
	}
	else
	{
		cout << "Questions and answers are out of order. Please restart program\nand try again." << endl;
	}
	in.close();
	system("pause");
	return 0;
}

/*********************************************************************************************************************/

void printAnswersAndResponses(const string questions[], const char answers[], const char responses[])
{
	int element = 0;
	cout << "Now we will give a summary of all questions, answers, and your responses.\n\n" << endl;
	while (element < MAX)
	{
		cout << questions[element] << endl << endl;
		cout << "Correct answer = " << answers[element] << endl;
		cout << "Your answer = " << responses[element] << endl;
		if (answers[element] == responses[element])
		{
			cout << "You answered this question correctly." << endl;
		}
		else
		{
			cout << "You answered this question incorectly." << endl;
		}
		element++;
		system("pause");
		
	}
}

int GradeResponses(const char answers[], const char responses[], int numqel)
{
	int correct = 0;
	for (int element = 0; element < numqel; element++)
	{
		if (answers[element] == responses[element]) 
		{
			correct++;
		}
	}
	return correct;	
}

void fillResponseArray(const string questions[], char responses[], int numqel)
{
	cout << "\n\n                            *** Driver's License Practice Exam ***       \n\n" << endl;
	cout << "Please answer the quesions as asked. Questions are multiple choice." << endl;
	cout << "Enter correct letter response out of A, B, C, D." << endl;
	for (int element = 0; element < numqel; element++)
	{
		cout << "\n\n" << questions[element] << '\n' << endl;
		cout << "Please choose your answer : ";
		cin >> responses[element];
		responses[element] = toupper(responses[element]);
	}
}

int fillAnswerKeyArray(char answers[], ifstream & in)
{
	int element = 0;
	while ((in.peek() != EOF) && (element < MAX))
	{
		in >> answers[element];
		element++;
	}
	return element;
}

int fillQuestionsArray(string questions[], ifstream & in)
{
	int element = 0; 
	while ((in.peek() != EOF) && (element < MAX))
	{
		// Additional method using nested loop instead
		/*
		string line;
		while (in.peek() != '$' && in.peek() != EOF)
		{
			getline(in, line);
			questions[element] += line;
			questions[element] += '\n';	
		}	
		in.ignore('$');
		element++;
		*/

		getline(in, questions[element],'$');           // '$' is the delimiter, this stops the getline once reached 
		element++;
	}
	return element;
}

void openFile(ifstream & in, const string & msg)
{
	bool done = false;
	while (!done)
	{
		cout << "Please enter the input file containing the " << msg << ":" << endl;
		string file;
		getline(cin, file);
		in.open(file);

		if (in.is_open())
		{
			if (in.peek() != EOF)
			{
				done = true;
			}
			else
			{
				cout << "There is no data in this file." << endl;
			}
		}
		else
		{
			cout << "Can't open file." << endl;
		}
	}
	cout << "This file exists, and has data in it." << endl;
}
