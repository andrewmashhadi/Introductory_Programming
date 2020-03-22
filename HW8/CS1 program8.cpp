/*
Andrew Mashhadi
Computer Science 1
andrew_mashahdi@elcamino.edu
Visual Studio 
Windows 10 
Assignment #8 
5/2/18
*/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
using namespace std;

struct Quiz
{
	char key;
	string question;
	char response;
};


void openInputFile(ifstream &, const string &);
int fillQuestions(Quiz [], ifstream &);
int fillAnswerKeys(Quiz [], ifstream &);
void fillResponses(Quiz [], int);
int gradeResponses(const Quiz [], int);
void printAnswersAndResponses(const Quiz [], int);

const int MAX = 20;

int main()
{
	cout << "Welcome to the Driving Test Program" << endl;
	Quiz qz[MAX];
	ifstream input;
	openInputFile(input, "questions");
	int queslen = fillQuestions(qz, input);
	input.close();
	openInputFile(input, "answers");
	int keylen = fillAnswerKeys(qz, input);
	
	
	if (keylen == queslen)
	{
		fillResponses(qz, queslen);
		int correct = gradeResponses(qz, keylen);
		int wrong;
		wrong = MAX - correct;
		double grade = 100 * (static_cast<double>(correct) / MAX);
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
			cout << "You passed with a D.\nConsider studying a little more before hitting the roads" << endl;
		}
		else
		{
			cout << "You failed.\nPlease review your answers below.\n" << endl;
		}
		printAnswersAndResponses(qz, queslen);

	}
	else
	{
		cout << "Questions and answers are out of order. Please restart program\nand try again." << endl;
	}
	input.close();
	return 0;
}

void openInputFile(ifstream & input, const string & msg)
{
	bool done = false;
	while (!done)
	{
		cout << "Please enter the input file containing the " << msg << ":" << endl;
		string file;
		getline(cin, file);
		input.open(file);

		if (input.is_open())
		{
			if (input.peek() != EOF)
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
int fillAnswerKeys(Quiz qz[], ifstream & input)
{
	 int len = 0;
	 while ((input.peek() != EOF) && (len < MAX))
	 {
		 input >> qz[len].key;
		 len++;
	 }
	 return len;
}
int fillQuestions(Quiz qz[], ifstream & input)
 {
	 int len = 0;
	 while ((input.peek() != EOF) && (len < MAX))
	 {
		 getline(input, qz[len].question, '$');
		 len++;
	 }
	 return len;
 }
void fillResponses(Quiz qz[], int queslen)
 {
	 cout << "\n\n                            *** Driver's License Practice Exam ***       \n\n" << endl;
	 cout << "Please answer the quesions as asked. Questions are multiple choice." << endl;
	 cout << "Enter correct letter response out of A, B, C, D." << endl;
	 for (int element = 0; element < queslen; element++)
	 {
		 cout << "\n\n" << qz[element].question << '\n' << endl;
		 cout << "Please choose your answer : ";
		 cin >> qz[element].response;
		 qz[element].response = toupper(qz[element].response);
	 }
 }
int gradeResponses(const Quiz qz[], int keylen)
{
	int correct = 0;
	for (int element = 0; element < keylen; element++)
	{
		if (qz[element].key == qz[element].response)
		{
			correct++;
		}
	}
	return correct;
}
void printAnswersAndResponses(const Quiz qz[], int len)
{
	int element = 0;
	cout << "Now we will give a summary of all questions, answers, and your responses." << endl;
	while (element < len)
	{
		cout << qz[element].question << endl << endl;
		cout << "Correct Answer: " << qz[element].key<< endl;
		cout << "Your answer: " << qz[element].response << endl;
		if (qz[element].key == qz[element].response)
		{
			cout << "You answered this question correctly." << endl;
		}
		else
		{
			cout << "You answered this question incorrectly." << endl;
		}
		element++;
		system("pause");
	}
}

