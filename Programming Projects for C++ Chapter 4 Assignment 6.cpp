// Programming Projects for C++ Chapter 4 Assignment 6.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string.h>
#include <string>
#include <cctype>
#include <iomanip>
double vending_machine(char m, double t);
int main()
{
    int x = 1;
    while (x == 1) {
        using namespace std;
        char money;
        double total = 0;
        double change = 0;
        cout << "Put the money in the machine for a deep fried twinkie (gross btw). Type D for doller, q for quarter, d for dime and n for nickel" << endl;
        while (total < 3.5) {
            cin >> money;
            cout << "Added " << fixed << money << setprecision(2) << endl;
            total += vending_machine(money, total);
            cout << "total " << fixed << total << setprecision(2) << endl;
            if (total == 3.5)
                break;
        }
        if (total > 3.5) {
            change = total - 3.5;
            cout << "You have achieved your twinkie! Here is your " << fixed << change << setprecision(2) << " dollers and cents in change!" << endl;
        }
        else {
            cout << "You have achieved your twinkie!" << endl;
        }
        cout << "If you are done, type 0, type 1 if not." << endl;
        cin >> x;
    }
}
double vending_machine(char m, double t)
{
    if (m == 'D') {
        t = 1;
    }
    else if (tolower(m) == 'q') {
        t = .25;
    }
    else if (m == 'd') {
        t = .1;
    }
    else if (tolower(m) == 'n') {
        t = 0.05;
    }
    else {
        t -= 0;
    }
    return (t);
}
