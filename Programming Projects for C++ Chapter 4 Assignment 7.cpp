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

 You may need �AM� or �PM� from the user�s input by reading in two
character values. (Display 2.3 illustrates character input.) Characters can
be compared just like numbers. or example, if the variable a_char is of
type char, then (a_char == 'A') is a Boolean expression that evaluates to
true if a_char contains the letter A.
*/

#include <iostream>
#include <string>
#include <cstdlib>
int computeDifference(int sh, int sm, bool sam, int eh, int em, int eam)
{
	int startMint, endMint, finalMint;
	if (sam) {
		startMint = sh * 60 + sm;
		
	}
	else {
		startMint = sh * 60 + sm + 720;
		
	}

	if (eam) {
		endMint = eh * 60 + em;

	}
	else {
		endMint = eh * 60 + em + 720;
	}
	
	finalMint = 720 - (endMint - startMint);
	if (finalMint >= 720) {
		finalMint = endMint - startMint - 720;
	}
	
	return(abs(finalMint - 720));


}




int main()
{
	using namespace std;
	int startHours;
	int startMinutes;
	bool startAM;
	int endHours;
	int endMinutes;
	bool endAM;

	cout << "Enter your start hours, start minutes, and weather you are in AM with a true (1) or false (0), then do the same thing for your ending hours, minutes, and AM." << endl;
	cin >> startHours;
	cin >> startMinutes;
	cin >> startAM;
	cin >> endHours;
	cin >> endMinutes;
	cin >> endAM;
	cout << "The difference in minutes is " << computeDifference(startHours, startMinutes, startAM, endHours, endMinutes, endAM) << endl;
	return 0;
}