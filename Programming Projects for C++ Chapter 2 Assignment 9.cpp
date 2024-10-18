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
    cout << "Enter ten whole numbers! Can be Negative or Positive! " << endl;
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
