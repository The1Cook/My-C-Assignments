// Programming Projects for C++ Chapter 3 Assignment 1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <array>
#include <vector>
#include <cctype>
#include <cstring>
using namespace std;

int main()
{
    int hour;
    int minute;
    char colon;
    char firstLetta;
    char secondLetta;
    int length;

    cout << "What time was your call started? (use military time)" << endl;
    cin >> hour >> colon >> minute;
    cout << "What day of the week was your call (Use the first letter and the second letter to describe) " << endl;
    cin >> firstLetta >> secondLetta;
    firstLetta = tolower(firstLetta);
    secondLetta = tolower(secondLetta);
    string theStringOne(1, firstLetta);
    string theStringTwo(1, secondLetta);
    string theActualString = theStringOne + theStringTwo;
    cout << "How long was your call in minutes?" << endl;
    cin >> length;

    if () {
    }

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
