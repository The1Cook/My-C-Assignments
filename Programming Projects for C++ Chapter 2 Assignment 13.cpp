// Programming Projects for C++ Chapter 2 Assignment 13.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
The Harris–Benedict equation estimates the number of calories your body
needs to maintain your weight if you do no exercise. This is called your
basal metabolic rate, or BMR.
The formula for the calories needed for a woman to maintain her weight is
BMR = 655 + (4.3 × weight in pounds) + (4.7 × height in inches) –
(4.7 × age in years)
The formula for the calories needed for a man to maintain his weight is
BMR = 66 + (6.3 × weight in pounds) + (12.9 × height in inches) –
(6.8 × age in years)


A typical chocolate bar will contain around 230 calories. Write a program
that allows the user to input his or her weight in pounds, height in
inches, age in years, and the character M for male and F for female. The
program should then output the number of chocolate bars that should
be consumed to maintain one’s weigt
*/

#include <iostream>
#include <string>
using namespace std;
int main()
{
    double age;
    char man;
    double weight;
    double chocholate = 230;
    double height;
    double BMR;
    cout << "What is your sex? M for Male F for Female: " << endl;
    cin >> man;
    cout << "What is your age in years (do not be exact to the month or day)? " << endl;
    cin >> age;
    cout << "What is your weight in pounds? " << endl;
    cin >> weight;
    cout << "What is your height in inches? " << endl;
    cin >> height;
    if (man == 'F') 
        BMR = 655 + (4.3 * weight) + (4.7 * height) - (6.8 * age);
    
    if (man == 'M')
        BMR = 66 + (6.3 * weight) + (12.9 * height) - (6.8 * age);
    
    double needed = BMR / chocholate;
    cout << "You need to eat " << needed << " chocholate bars to maintain your weight based on your metabolic rate. " << endl;
    

}