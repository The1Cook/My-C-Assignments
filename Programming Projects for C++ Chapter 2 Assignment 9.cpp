// Programming Projects for C++ Chapter 2 Assignment 9.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
Write a program that reads in ten whole numbers and that outputs the
sum of all the numbers greater than zero, the sum of all the numbers less
than zero (which will be a negative number or zero), and the sum of all
the numbers, whether positive, negative, or zero. The user enters the ten
numbers just once each and the user can enter them in any order. Your
program should not ask the user to enter the positive numbers and the
negative numbers separately.
*/

#include <iostream>
using namespace std;
int main()
{
    int one;
    int two;
    int three;
    int four;
    int five;
    int six;
    int seven;
    int eight;
    int nine;
    int ten;
    cout << "Enter five whole numbers! Can be Negative or Positive! " << endl;
    cin >> one;
    cin >> two;
    cin >> three;
    cin >> four;
    cin >> five;
    cin >> six;
    cin >> seven;
    cin >> eight;
    cin >> nine;
    cin >> ten;
    int added = 0;
    int subtracted = 0;
    int total = 0;
    int array[10] = { one, two, three, four, five, six, seven, eight, nine, ten };
    for (int i = 0; i < 10; i++) {
        total += array[i];
        if (array[i] >= 0)
            added += array[i];
        if (array[i] <= 0)
            subtracted += array[i];
    }
    cout << "All postives added: " << added << endl;
    cout << "All Negatives added: " << subtracted << endl;
    cout << "total: " << total << endl;


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
