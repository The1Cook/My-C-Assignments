// Programming Projects for C Chapter 3 Assignment 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;
int main()
{
    cout << "Give a desired temperature ";
    char digi1 = '0';
    char digi2 = '0';
    char digi3 = '0';
 
    cin >> digi1 >> digi2 >> digi3;
    int digits[3];
        digits[0] = digi1 - '0';
        digits[1] = digi2 - '0';
        digits[2] = digi3 - '0';
    
        for (int i = 0; i < 3; i++) {
            if (digits[i] == 1 || digits[i] == 4 || digits[i] == 7)
                digits[i] += 1;
            
        
        
        }
        cout << "The next best number going up is " << digits[0] << digits[1] << digits[2] << endl;
        for (int k = 0; k < 3; k++) {
            if (digits[k] -1 == 1 || digits[k] -1 == 4 || digits[k] -1 == 7)
                digits[k] -= 2;



        }
        cout << "The next best number going down is " << digits[0] << digits[1] << digits[2] << endl;
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
