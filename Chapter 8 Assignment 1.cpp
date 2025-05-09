#include <iostream>
#include <cctype>
#include <string>

using namespace std;

int main() {
    char next;
    string finalSentence;
    bool lastWasSpace = false;
    int charCount = 0;

    cout << "Enter your sentence (max 100 characters, ending with a period):\n";

    // Read characters one by one
    while ((next = cin.get()) != '.' && charCount < 100) {
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

    // get rid of extra space
    if (!finalSentence.empty() && finalSentence.back() == ' ') {
        finalSentence.pop_back();
    }

    // Capitalize first letter if sentence isn't empty
    if (!finalSentence.empty()) {
        finalSentence[0] = toupper(finalSentence[0]);
    }

    finalSentence += '.';

    cout << "\n" << finalSentence << endl;

    return 0;
}
