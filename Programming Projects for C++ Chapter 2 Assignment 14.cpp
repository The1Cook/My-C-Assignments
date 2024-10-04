// Programming Projects for C++ Chapter 2 Assignment 14.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
Write a program that calculates the total grade for N classroom exercises
as a percentage. The user should input the value for N followed by each of
the N scores and totals. Calculate the overall percentage (sum of the total
points earned divided by the total points possible) and output it as a percentage. Sample input and output is shown below.
*/

#include <iostream>
#include <array>
#include <vector>
using namespace std;


int main()
{
    int exercises;
    cout << "How many exercises to input? ";
    cin >> exercises;
    double score;
    double total;
    double overallScore = 0;
    double overallTotal = 0;

    for (exercises; exercises > 0; exercises--) {
        cout << "Score recieved for exercise " << exercises << ": ";
            cin >> score;
            cout << "Total points possible: ";
            cin >> total;
            overallScore += score;
            overallTotal += total;
    }
   
    cout << "Your total is " << overallScore << " out of " << overallTotal << ", or " << (overallScore / overallTotal) * 100 << "%.";

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
