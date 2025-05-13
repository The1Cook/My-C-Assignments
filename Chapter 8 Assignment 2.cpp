#include <string>
#include <vector>
#include <cctype>
#include <iostream>
using namespace std;
// dont let enter return input, have end of input be a number inputed.
void sortByInsertion(string& myString) {
    for (size_t i = 1; i < myString.size(); ++i) {
        char temp = myString[i];
        size_t j = i;
        while (j > 0 && myString[j - 1] > temp) {
            myString[j] = myString[j - 1];
            --j;
        }
        myString[j] = temp;
    }
}

// Extract next word and trim delimiters
string nextWord(string& myString) {
    while (!myString.empty() && myString.find_first_of(" ,.\n") == 0)
        myString.erase(0, 1);

    size_t firstDelimiterIndex = myString.find_first_of(" ,.\n");

    string returnedWord = myString.substr(0, firstDelimiterIndex);
    if (firstDelimiterIndex != string::npos)
        myString.erase(0, firstDelimiterIndex + 1);
    else
        myString.clear();

    return returnedWord;
}

int main() {
    string myLine;
    cout << "Enter words (type a number to end input):\n";
    string totalInput;

    while (true) {
        getline(cin, myLine);

        // Trim leading spaces
        myLine.erase(0, myLine.find_first_not_of(" \t"));

        // Check if input starts with a digit
        if (!myLine.empty() && isdigit(myLine[0])) {
            break;
        }

        if (!myLine.empty()) {
            totalInput += myLine + " ";
        }
    }

    if (totalInput.empty()) {
        cout << "No input provided.\n";
        return 0;
    }

    while (!totalInput.empty() && totalInput.find_first_of(" ,.\n") == 0)
        totalInput.erase(0, 1);

    string clearedLine;
    size_t wordsNumber = 0;

    while (!totalInput.empty()) {
        string word = nextWord(totalInput);
        if (!word.empty()) {
            clearedLine += word;
            ++wordsNumber;
        }
    }

    for (char& ch : clearedLine)
        ch = tolower(ch);

    sortByInsertion(clearedLine);

    vector<string> charactersVector;
    while (!clearedLine.empty()) {
        char currentChar = clearedLine[0];
        size_t groupSize = clearedLine.find_first_not_of(currentChar);
        if (groupSize == string::npos) groupSize = clearedLine.size();

        charactersVector.push_back(clearedLine.substr(0, groupSize));
        clearedLine.erase(0, groupSize);
    }

    cout << "\nTotal Words: " << wordsNumber << endl;
    cout << "Character frequencies:\n";
    for (const string& group : charactersVector) {
        cout << group.size() << " " << group[0] << endl;
    }

    return 0;
}
