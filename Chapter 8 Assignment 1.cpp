#include <iostream>
#include <cctype>
#include <string>

using namespace std;

int main() {
    int x = 0;
    while (x == 0) {
        char next;
        string finalSentence;
        bool lastWasSpace = false;
        int charCount = 0;
        bool periodFound = false;

        cout << "Enter your sentence (max 100 characters, ending with a period):\n";

        // Read characters one by one
        while (charCount < 100 && (next = cin.get())) {
            if (next == '.') {
                periodFound = true;
                break;
            }

            if (next == '\n') next = ' ';

            if (isspace(next)) {
                if (!finalSentence.empty() && !lastWasSpace) {
                    finalSentence += ' ';
                    lastWasSpace = true;
                }
            }
            else {
                finalSentence += tolower(next);
                lastWasSpace = false;
            }

            charCount++;
        }

        // Check if input is invalid
        if (!periodFound || charCount >= 100) {
            // Discard remaining input until period or newline
            while (next != '.' && next != '\n' && cin.get(next)) {}
            cout << "\nInvalid input: must be under 100 characters and end with a period. (type okay)\n\n";
            cin.ignore(1000, '\n'); // Clear the input buffer
            continue; // Restart loop
        }

        // Clean up and print formatted sentence
        if (!finalSentence.empty() && finalSentence.back() == ' ') {
            finalSentence.pop_back();
        }

        if (!finalSentence.empty()) {
            finalSentence[0] = toupper(finalSentence[0]);
        }

        finalSentence += '.';

        cout << "\n" << finalSentence << endl;

        cout << "Want to go again? Enter 0 if yes: ";
        cin >> x;
        cin.ignore(); // Clear newline after number input
    }
    return 0;
}
