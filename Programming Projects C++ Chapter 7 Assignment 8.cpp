// Programming Projects C++ Chapter 7 Assignment 8.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <cstring>
using namespace std;

const int ALPHABET_SIZE = 26;
void sortLettersByFrequency(char letters[], int counts[], int size) {
    for (int i = 0; i < size - 1; ++i) {
        for (int j = i + 1; j < size; ++j) {
            if (counts[j] > counts[i]) {
                swap(counts[i], counts[j]);
                swap(letters[i], letters[j]);
            }
        }
    }
}

int main() {
    char line[1000];
    char choice;

    do {
        int counts[ALPHABET_SIZE] = {};
        char letters[ALPHABET_SIZE];

        // Initialize letters array
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            letters[i] = 'a' + i;
        }

        // Get input
        cout << "Enter a line of lowercase text ending with a period: ";
        cin.getline(line, 1000);

        // Count letters until the period
        for (int i = 0; line[i] != '.' && line[i] != '\0'; ++i) {
            char c = line[i];
            if (c >= 'a' && c <= 'z') {
                counts[c - 'a']++;
            }
        }

        // Sort and display results
        sortLettersByFrequency(letters, counts, ALPHABET_SIZE);

        cout << "Letter frequencies (in descending order):\n";
        for (int i = 0; i < ALPHABET_SIZE; ++i) {
            if (counts[i] > 0) {
                cout << letters[i] << ": " << counts[i] << endl;
            }
        }

        // Ask the user if they want to try again
        cout << "\nWould you like to try again? (y/n): ";
        cin >> choice;
        cin.ignore(); 

        cout << endl;

    } while (choice == 'y' || choice == 'Y');

    cout << "Program ended." << endl;

    return 0;
}
