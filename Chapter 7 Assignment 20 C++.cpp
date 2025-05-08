#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

int main() {
    int x = 0;
    while (x == 0) {
        srand(static_cast<unsigned int>(time(0)));

        ifstream inFile("input.txt");
        if (!inFile) {
            cerr << "Error opening file." << endl;
            return 1;
        }

        vector<int> age;
        vector<double> maleProb;
        vector<double> femaleProb;

        int a;
        double mProb, fProb;

        while (inFile >> a >> mProb >> fProb) {
            age.push_back(a);
            maleProb.push_back(mProb);
            femaleProb.push_back(fProb);
        }

        inFile.close();

        string sex;
        int userAge;

        cout << "Enter your sex (male/female): ";
        cin >> sex;
        transform(sex.begin(), sex.end(), sex.begin(), ::tolower); // Normalize input

        if (sex != "male" && sex != "female") {
            cout << "Invalid sex entered. Please enter 'male' or 'female'." << endl;
            return 1;
        }

        cout << "Enter your age: ";
        cin >> userAge;

        if (userAge < 0 || userAge >= static_cast<int>(maleProb.size())) {
            cout << "Invalid age entered." << endl;
            return 1;
        }

        while (userAge < 120) {
            double randNum = static_cast<double>(rand()) / RAND_MAX;
            double deathProb = (sex == "male") ? maleProb[userAge] : femaleProb[userAge];

            if (randNum <= deathProb) {
                break;
            }

            userAge++;
        }

        cout << "You are predicted to live to age " << userAge << ". Do 0 to try again." << endl;
        cin >> x;
    }
    return 0;
}
