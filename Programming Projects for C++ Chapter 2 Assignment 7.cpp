// Programming Projects for C++ Chapter 2 Assignment 7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;

int main()
{
	double itemCost;
	std::cout << "What is your item's cost? $" << endl;
	cin >> itemCost;
	double years;
	std::cout << "How many years later is it? " << endl;
	cin >> years;
	double inflationRate = 0.056;
	cout << "What is the inflation rate percent in decimal form? ";
	cin >> inflationRate;
	for (int k = 0; k < years; k += 2) {
		itemCost += itemCost * inflationRate;
	}
	cout << "Item cost after " << years << " years is $" << itemCost << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
