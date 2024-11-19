// Programming Projects for C Chapter 3 Assignment 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
// added loop and break if not in range of 0 and 999
using namespace std;
int main()
{
    int x = 1;
    
    int number = -1;
    while (x == 1)
    {
        int g = 1;
        
            cout << "Give a desired temperature ";
            

            
            
            int number;
            cin >> number;
            while (number < 0 || number > 999) {
                cout << "No try again" << endl;
                cin >> number;
            }
            cout << number << endl;

            
     
        int up = number;
        int down = number;
        while (up % 10 == 1 || up % 10 == 4 || up % 10 == 7 || (up / 10) % 10 == 1 || (up / 10) % 10 == 4 || (up / 10) % 10 == 7 || (up / 100) % 10 == 1 || (up / 100) % 10 == 4 || (up / 100) % 10 == 7) {
            up++;

        }
        while (down % 10 == 1 || down % 10 == 4 || down % 10 == 7 || (down / 10) % 10 == 1 || (down / 10) % 10 == 4 || (down / 10) % 10 == 7 || (down / 100) % 10 == 1 || (down / 100) % 10 == 4 || (down / 100) % 10 == 7) {
            down--;

        }
        cout << "The next best number up is " << up << endl;
        cout << "The next best number down is " << down << endl;
        cout << "Done yet? 1 for no, anything else for yes " << endl;
        cin >> x;

    }
}
