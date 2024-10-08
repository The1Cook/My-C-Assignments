// ConsoleApplication2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;
int main()
{
	int k = 0;

	//define integer
	while (k == 0) {

		//create a while loop that will continue to allow the user to keep repeating the looping information
		cout << "How many people are in the room and what is the capacity? " << endl;
			int people;
			// make user input capacity
			int capacity;
			cin >> people;
			cin >> capacity;
			if (people <= capacity) {
				cout << "You may hold the meeting" << endl;
			}
			else {
				cout << "You may not hold the meeting as it is in violation of fire regulations" << endl;
			}
		


		cout << "See it again? Type 1 if no type 0 if yes." << endl;

		//asks if the user wants to see it again if they don't it will end the loop by setting the int k to anything but 0
		cin >> k;

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
