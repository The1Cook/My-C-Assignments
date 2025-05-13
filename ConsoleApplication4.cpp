/*
Your time machine is capable of going forward in time up to 24 hours.
The machine is configured to jump ahead in minutes. To enter the proper
number of minutes into your machine, you would like a program that can
take a start time (in hours, minutes, and a Boolean indicating AM or PM)
and a future time (in hours, minutes, and a Boolean indicating AM or PM)
and calculate the difference in minutes between the start and future time.

 A time is specified in your program with three variables:
int hours, minutes;
bool isAM;

or example, to represent 11:50 PM, you would store:
hours = 11
minutes = 50
isAM = false;

 This means that you need six variables to store a start and future time.
 Write a program that allows the user to enter a start time and a future time.
Include a function named computeDifference that takes the six variables
as parameters that represent the start time and future time. Your function
should return, as an int, the time difference in minutes.

or example, given
a start time of 11:59 AM and a future time of 12:01 PM, your program
should compute 2 minutes as the time difference. Given a start time of
11:59 AM and a future time of 11:58 AM, your program should compute
1439 minutes as the time difference (23 hours and 59 minutes).

 You may need “AM” or “PM” from the user’s input by reading in two
character values. (Display 2.3 illustrates character input.) Characters can
be compared just like numbers. or example, if the variable a_char is of
type char, then (a_char == 'A') is a Boolean expression that evaluates to
true if a_char contains the letter A.
*/

#include <iostream>

using namespace std;

int computeDifference(int startHours, int startMinutes, bool startIsAM,
    int futureHours, int futureMinutes, bool futureIsAM) {
    // Convert start time to minutes from midnight
    int startTotalMinutes = (startHours % 12) * 60 + startMinutes;
    if (!startIsAM) {
        startTotalMinutes += 12 * 60;  // Convert PM times properly
    }

    // Convert future time to minutes from midnight
    int futureTotalMinutes = (futureHours % 12) * 60 + futureMinutes;
    if (!futureIsAM) {
        futureTotalMinutes += 12 * 60;  // Convert PM times properly
    }

    // Compute the time difference in minutes
    int difference = futureTotalMinutes - startTotalMinutes;
    if (difference < 0) {
        difference += 24 * 60;  // Handle wrap-around past midnight
    }

    return difference;
}

int main() {
    char choice;
    do {
        int startHours, startMinutes, futureHours, futureMinutes;
        char startPeriod, futurePeriod;
        bool startIsAM, futureIsAM;

        cout << "Enter start time (hours minutes AM/PM): ";
        cin >> startHours >> startMinutes >> startPeriod;
        startIsAM = (startPeriod == 'A');

        cout << "Enter future time (hours minutes AM/PM): ";
        cin >> futureHours >> futureMinutes >> futurePeriod;
        futureIsAM = (futurePeriod == 'A');

        int timeDifference = computeDifference(startHours, startMinutes, startIsAM,
            futureHours, futureMinutes, futureIsAM);

        cout << "Time difference: " << timeDifference << " minutes\n";

        cout << "Do you want to try again? (Y/N): ";
        cin >> choice;
    } while (choice == 'Y' || choice == 'y');

    cout << "Goodbye!\n";
    return 0;
}
