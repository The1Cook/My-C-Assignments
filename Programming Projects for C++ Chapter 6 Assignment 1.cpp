#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function to process the input file and generate personalized letters.
void generatePersonalizedLetters(ifstream& inputFile, ofstream& outputFile) {
    string line;
    string firstName, lastName;

    while (getline(inputFile, line)) {
        size_t pos = 0;

        // Loop to find all occurrences of "#N#"
        while ((pos = line.find("#N#", pos)) != string::npos) {
            
            cout << "Please enter the first name: ";
            cin >> firstName;
            cout << "Please enter the last name: ";
            cin >> lastName;
            line.replace(pos, 3, firstName + " " + lastName);
            pos += (firstName.length() + lastName.length() + 1);
        }

        
        outputFile << line << endl;
    }
}

int main() {
    string inputFileName, outputFileName;

    cout << "Enter the name of the input file: ";
    cin >> inputFileName;

    cout << "Enter the name of the output file: ";
    cin >> outputFileName;

    
    ifstream inputFile(inputFileName);
    if (!inputFile) {
        cerr << "Error opening input file!" << endl;
        return 1;
    }

    // Open the output file for writing
    ofstream outputFile(outputFileName);
    if (!outputFile) {
        cerr << "Error opening output file!" << endl;
        return 1;
    }

    // Generate the personalized letters
    generatePersonalizedLetters(inputFile, outputFile);

    // Close the files
    inputFile.close();
    outputFile.close();

    cout << "Personalized letters have been generated in " << outputFileName << endl;

    return 0;
}
