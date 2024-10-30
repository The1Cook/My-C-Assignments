// Programming projects for C++ Chapter 3 Assignment 13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int k = 999;
    while (true) {
        

        int d = int(log10(k) + 1);
        int thousandsP = floor(k / 1000);
        int hundredsP = floor((k - thousandsP * 1000) / 100);
        int tensP = floor((k - thousandsP * 1000 - hundredsP * 100) / 10);
        int onesP = floor(k - thousandsP * 1000 - hundredsP * 100 - tensP * 10);
        
        if (d == 4 && thousandsP != hundredsP && thousandsP != tensP && thousandsP != onesP && hundredsP != tensP && hundredsP != onesP && tensP != onesP && thousandsP == tensP * 3 && k % 2 != 0 && thousandsP + hundredsP + tensP + onesP == 27) {
            break;
        }
        else {
            k++;
        }
    }
    cout << "The riddler is hiding at " << k << " Batman!!!" << endl;
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
