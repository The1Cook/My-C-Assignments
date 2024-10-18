// Programming Projects for C++ Chapter 2 Assignment 7.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
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
	inflationRate /= 100;
	for (int k = 0; k < years; k += 1) {
		itemCost += itemCost * inflationRate;
	}
	cout << "Item cost after " << years << " years is $" << fixed << setprecision(2) << itemCost << endl;
}
