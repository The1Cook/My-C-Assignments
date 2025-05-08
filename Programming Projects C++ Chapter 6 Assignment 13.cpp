// Programming Projects C++ Chapter 6 Assignment 13.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<fstream>
#include<string>
int main()
{
    using namespace std;
    string filename;
    cout << "Enter the name of the text file: ";
    getline(cin, filename);

    ifstream file(filename);
    if (!file) {
        cerr << "error no file able to open";
        return 1;
    }
    int wordCount = 0;
    string word;
    while (file >> word) {
        ++wordCount;
    }

    file.close();
    cout << "The file contains " << wordCount << " words." << endl;
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
