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
#include <iomanip>
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
   
    cout << "Your total is " << overallScore << " out of " << overallTotal << ", or " << fixed << setprecision(2) << (overallScore / overallTotal) * 100 << "%.";

}
