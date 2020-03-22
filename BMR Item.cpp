#include <iostream>
using namespace std;
//15/15
int main()
{
	double Weight;
	double Height;
	int Age;
	double BMR;
	double ActivityFactor;
	double CaloriesBurned;
	cout << "Please enter your weight in pounds, then press the enter key:";
	cin >> Weight;
	cout << "Please enter your height in feet, then press the enter key:";
	cin >> Height;
	cout << "Please enter your age in years, then press the enter key:";
	cin >> Age;
	BMR = (66 + 6.2*(Weight)+152.4*(Height)-6.8*(Age));
	cout << "If you have a desk job and rarely exercise, write 1.2.\n";
	cout << "If you are lightly active, and exercise 1 to 3 days a week, write 1.375.\n";
	cout << "If you are moderately active, and exercise 3 to 5 times a week, write 1.55.\n";
	cout << "If very active, and exercise 6 to 7 times a week, write 1.725.\n";
	cout << "If extra active, and train hard in sports twice a day, write 1.9\n";
	cin >> ActivityFactor;
	CaloriesBurned = (BMR*ActivityFactor);
	cout << "Here are your results:\n";
	cout << "-----------------------\n";
	cout << "You burn about " << CaloriesBurned << " calories everyday.\n";
	cout << "If you intake more calories per day, you may wish to eat less or exercise more.\n";
	cout << "Thank you for using Andrew's daily calorie calculation program.\n";
	system("pause")
	return 0;
}