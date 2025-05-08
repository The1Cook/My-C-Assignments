#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

int main() {
    
    string actualPIN = "12345";  

    //Create and fill array with random numbers (1-3)
    int numMap[10];
    int x = 0;
    while (x == 0) {
        srand(time(0));  // Seed for randomness

        for (int i = 0; i < 10; ++i) {
            numMap[i] = rand() % 3 + 1;  // Random number between 1 and 3
        }

        cout << "PIN:  ";
        for (int i = 0; i < 10; ++i) {
            cout << i;
        }
        cout << endl;

        cout << "NUM:  ";
        for (int i = 0; i < 10; ++i) {
            cout << numMap[i];
        }
        cout << endl;

        //input based on NUM values
        string userInput;
        cout << "Enter the response: ";
        cin >> userInput;

        //Generate expected response from actual PIN
        string expectedResponse = "";
        for (char digit : actualPIN) {
            int pinDigit = digit - '0';
            expectedResponse += to_string(numMap[pinDigit]);
        }
        if (userInput == expectedResponse) {
            cout << "Access granted." << endl;
        }
        else {
            cout << "Access denied." << endl;
        }

        cout << "try again? 1 if no 0 if yes" << endl;
        cin >> x;
    }
    return 0;
}
