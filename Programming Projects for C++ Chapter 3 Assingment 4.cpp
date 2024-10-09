// Programming Projects for C++ Chapter 3 Assingment 4.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
Write a program that scores a blackjack hand. In blackjack, a player receives
from two to five cards. The cards 2 through 10 are scored as 2 through
10 points each. The face cards—jack, queen, and king—are scored as 10
points. The goal is to come as close to a score of 21 as possible without
going over 21. Hence, any score over 21 is called “busted.” The ace can
count as either 1 or 11, whichever is better for the user. For example, an
ace and a 10 can be scored as either 11 or 21. Since 21 is a better score, this
hand is scored as 21. An ace and two 8s can be scored as either 17 or 27.
Since 27 is a “busted” score, this hand is scored as 17.


 The user is asked how many cards she or he has, and the user responds with
one of the integers 2, 3, 4, or 5. The user is then asked for the card values. Card
values are 2 through 10, jack, queen, king, and ace. A good way to handle
input is to use the type char so that the card input 2, for example, is read as the
character '2', rather than as the number 2. Input the values 2 through 9 as the
characters '2' through '9'. Input the values 10, jack, queen, king, and ace as
the characters 't', 'j', 'q', 'k', and 'a'. (Of course, the user does not type in
the single quotes.) Be sure to allow upper- as well as lowercase letters as input.
 After reading in the values, the program should convert them from character values to numeric card scores, taking special care for aces. The output is
either a number between 2 and 21 (inclusive) or the word Busted. You are
likely to have one or more long multiway branches that use a switch statement or nested if-else statement. Your program should include a loop that
lets the user repeat this calculation until the user says she or he is done


*/

#include <iostream>
#include <array>
#include <string.h>

using namespace std;

int main()
{
    std::cout << "How many cards do you have? (from 2-5)" << endl;
    int cards = 0;
    while (cards > 5 || cards < 2)
    {
        cin >> cards;
    }

    char nameCard[] = {0};
    char cardName;
    std::cout << "Enter what cards you have (j for jake, q for queen, etc.)" << endl;
    for (int i = 0; i < cards; i++) {
        cin >> nameCard[i];
        
    }
    int overall = 0;
    int ifAce = 0;
    for (int k = 0; k < cards; k++) {
        if (tolower(nameCard[k]) == 'j' || tolower(nameCard[k]) == 'k' || tolower(nameCard[k]) == 'q' || tolower(nameCard[k]) == 't') {
            overall += 10;
        }
        else if (tolower(nameCard[k]) == 'a') {
            cout << "One or eleven for your ace? " << endl;
            cin >> ifAce;
            overall += ifAce;
        }
        else {
            overall += (nameCard[k] - '0');
        
        }
    }
    if (overall <= 21) {
        cout << "Your score was " << overall << endl;
    }
    else {
        cout << "busted!" << endl;
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
