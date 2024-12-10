// Programming Projects for C++Chapter 4 Assignment 5.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
To maintain one’s body weight, an adult human needs to consume enough
calories daily to (1) meet the basal metabolic rate (energy required to
breathe, maintain body temperature, etc.), (2) account for physical activity
such as exercise, and (3) account for the energy required to digest the food
that is being eaten. or an adult that weighs P pounds, we can estimate
these caloric requirements using the following formulas:
 A. Basal metabolic rate: Calories required = 70 * (P / 2.2)0.756
 B. Physical activity: Calories required = 0.0385 * Intensity * P * Minutes
ere, Minutes is the number of minutes spent during the physical activity,
and Intensity is a number that estimates the intensity of the activity. ere
are some sample numbers for the range of values:

   Activity          Intensity
Running 10 mph          17
Running 6 mph           10
Basketball              8
Walking 1 mph           1

Energy to digest food: calories required = TotalCaloriesConsumed * 0.1
 In other words, 10 percent of the calories we consume goes towards digestion.
 
 
 
 Write a function that computes the calories required for the basal metabolic
rate, taking as input a parameter for the person’s weight. 

Write another function that computes the calories required for physical activity, taking as
input parameters for the intensity, weight, and minutes spent exercising.

 Use these functions in a program that inputs a person’s weight, an estimate
for the intensity of physical activity, the number of minutes spent performing 
the physical activity, and the number of calories in one serving of your
favorite food. 

The program should then calculate and output how many
servings of that food should be eaten per day to maintain the person’s current 
weight at the specified activity level. The computation should include
the energy that is required to digest food. 

*/

#include <iostream>
#include <math.h>
#include <stdio.h>

double basal_metabolic_rate(double P);
double physical_activity(double P, double minutes, double intensity);
double energy_to_digest(double totalCalConsumed);
int main()
{
    using namespace std;
    //double basal_metabolic_rate(double P)
    //double physical_activity(double P, double minutes, double intensity)
    //double energy_to_digest(double totalCalConsumed)
    double P = 0;
    double intensity = 0;
    double minutes = 0;
    double favFood = 0;

    cout << "Enter your weight" << endl;
    cin >> P;
    cout << "Enter your favorite food calorie count" << endl;
    cin >> favFood;
    cout << "Let's try to excercise those calories off, how long do you excercise for in minutes?" << endl;
    cin >> minutes;
    cout << "Enter the intesity of your excercise (for ex the intesity for running 1 mph is 1 and for 10 it's 17)" << endl;
    cin >> intensity;
    cout << "Your metabolic rate is " << basal_metabolic_rate(P) << endl;
    cout << "Your physical activity was " << physical_activity(P, minutes, intensity) << endl;
    cout << "Your energy you need in order to digest your favorite food is " << energy_to_digest(favFood) << endl;
    
    double totalCalConsumed = physical_activity(P, minutes, intensity) + basal_metabolic_rate(P);

    cout << "That means it will take " <<  (totalCalConsumed + energy_to_digest((totalCalConsumed)))/favFood << " of your fav food to sustain your activity level of " << physical_activity(P, minutes, intensity) << " and your weight of " << P << " pounds." << endl;
    
}
double basal_metabolic_rate(double P)
{
    return(70*pow((P/22), 0.756));
}
double physical_activity(double P, double minutes, double intensity)
{
    return(0.0385 * intensity * P * minutes);
}
double energy_to_digest(double totalCalConsumed)
{
    return(totalCalConsumed*0.1);
}