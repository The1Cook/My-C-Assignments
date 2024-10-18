// Programming Projects for C Chapter 3 Assignment 3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;
std::string convertToRoman(int year) {
    // Define the Roman numeral values and their corresponding symbols. 
    const pair<int, string> romanNumerals[] = {
        {1000, "M"}, {900, "CM"}, {500, "D"}, {400, "CD"},
        {100, "C"}, {90, "XC"}, {50, "L"}, {40, "XL"},
        {10, "X"}, {9, "IX"}, {5, "V"}, {4, "IV"}, {1, "I"}
    };
    string roman;
    //goes through ever number individually input, if the first number is bigger than the year, than the roman numeral
    // correlating to it is added, this is done until the method no longer sees any acceptable numerals to input
    for (const auto& numeral : romanNumerals) {
        while (year >= numeral.first) {
            roman += numeral.second;
            year -= numeral.first;
        }
    }
    return roman;
}
int main() {
    while (true) {
        int year;

        cout << "Enter a year: ";
        cin >> year;

        string romanNumeral = convertToRoman(year);
        cout << "The year " << year << " in Roman numerals is: " << romanNumeral << std::endl;
        cout << "Are you done? y for yes n for no." << endl;
        char a;
        cin >> a;
        if (a == 'y') {
            break;
        }
        else {
            cout << "Okay, from the top. " << endl;
        }
        
    }
        return 0;
    
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
