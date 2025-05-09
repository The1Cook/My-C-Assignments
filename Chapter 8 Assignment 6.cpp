#include <iostream>
#include <string>
#include <cctype>
using namespace std;

string maskNumbers(const string& line) {
    string result;
    size_t i = 0;

    while (i < line.size()) {
        if (isdigit(line[i])) {
            // Check if this digit is part of a word
            bool partOfWord = false;

            if (i > 0 && isalpha(line[i - 1])) partOfWord = true;
            if (i + 1 < line.size() && isalpha(line[i + 1])) partOfWord = true;

            if (partOfWord) {
                // Preserve digit inside word
                result += line[i];
                i++;
            }
            else {
                // Replace entire numeric sequence with x's
                while (i < line.size() && isdigit(line[i])) {
                    result += 'x';
                    i++;
                }
            }
        }
        else {
            result += line[i];
            i++;
        }
    }

    return result;
}

int main() {
    string input;
    char again;

    do {
        cout << "Enter your line of text:\n";
        getline(cin, input);

        string masked = maskNumbers(input);
        cout << "Masked result:\n" << masked << endl;

        cout << "\nWould you like to try again? (y/n): ";
        cin >> again;
        cin.ignore(); // Clear newline

    } while (again == 'y' || again == 'Y');

    cout << "Program ended." << endl;
    return 0;
}
