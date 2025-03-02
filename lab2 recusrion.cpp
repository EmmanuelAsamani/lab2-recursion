// labrefresher.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <cctype>
#include <string>
using namespace std;


double recursiveSum1(int n) {
	double sum = 0.0;
	// Base case: if n is 1, return the first term
	if (n == 1) {
		cout << "1";
		return 1.0;
	}
	else {
		// Recursive case: add the current term and call the function for the remaining terms
		sum = 1.0 / (n - 1 + n) + recursiveSum1(n - 1);
		cout << "sum = " << sum << endl;
	}
	return sum;
}
int recursiveSum2(int n) {
	int sum = 0;
	if (n == 1) {
		cout << "1";
		return 1;
	}
	else {
		// Recursive case: add n^2 and call the function for (n-1)
		sum = n * n + recursiveSum2(n - 1);
		cout << "sum = " << sum << endl;
	}
	return sum;
}

void printMenu() {
	cout << "welcome to menu \n";
	cout << "select number for menu options\n";
	cout << "1 = option1 \n";
	cout << "2 = option2\n";
	cout << "x = quit program\n";
}

char readMenuOption() {
	char menuOption;
	cout << "choose option > ";
	cin >> menuOption;
	return menuOption;
}

bool validateMenuOption(char menuOption) {

	if (isdigit(menuOption)) {
		cout << "The character is a digit.\n";
		return true;
	}
	else {
		cout << "The character is not a digit.\n";
		return false;
	}

}

void functionExecute(char menuOption) {
	switch (menuOption) {
	case '1':
	{
		cout << " enter number\n" << flush;
		int number;
		cin >> number;
		 recursiveSum1(number);
		break;
	}
	case '2':
	{
		cout << "enter number for Sum2\n" << flush;
		int number;
		cin >> number;
		int sum2 = recursiveSum2(number);
		cout << "sum = " << sum2 << endl;
		break;
	}
	default:
		cout << "invalid menu option.";
	}

}

int main()
{
	char running = ' ';

	while (running != 'x') {
		printMenu();
		char userInput = readMenuOption();
		bool validationResult = validateMenuOption(userInput);
		if (validationResult) {
			functionExecute(userInput);
		}
		else {
			cout << "validation failed.";
		}
		running = userInput;
	}
	return 0;
}

