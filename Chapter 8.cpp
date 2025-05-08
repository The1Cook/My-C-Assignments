#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

vector<string> split(const string& target, const string& delimiter) {
    vector<string> toBeReturned;
    size_t start = 0, end;
    while ((end = target.find(delimiter, start)) != string::npos) {
        toBeReturned.push_back(target.substr(start, end - start));
        start = end + delimiter.length();
    }
    toBeReturned.push_back(target.substr(start));
    return toBeReturned;
}

vector<vector<vector<string>>> racersDataExtractor(const vector<string>& lines) {
    vector<vector<vector<string>>> result(3, vector<vector<string>>(3));
    for (size_t j = 0; j < 3; ++j) {
        for (size_t i = 0; i < 3; ++i)
            result[j][i] = split(lines[i + 3 * j], ",");

        if (j > 0) {
            for (size_t k1 = 0; k1 < 3; ++k1) {
                for (size_t k2 = 0; k2 < 3; ++k2) {
                    if (result[j][k1][1] == result[j - 1][k2][1]) {
                        swap(result[j][k1], result[j][k2]);
                    }
                }
            }
        }
    }
    return result;
}

int main() {
    fstream myData("racerdata.dat");
    if (!myData) {
        cout << "I couldn't find \"racerdata.dat\" in the current directory.\n";
        system("pause");
        return 1;
    }

    string myFileString;
    char next;
    while (myData.get(next)) myFileString += next;

    string startTime = myFileString.substr(0, myFileString.find("\n"));
    string dataLines = myFileString.substr(myFileString.find("\n") + 1);
    vector<string> dataLinesVect = split(dataLines, "\n");

    vector<vector<vector<string>>> racersData = racersDataExtractor(dataLinesVect);

    cout << "Enter the racer's ID:\t";
    string racerID; cin >> racerID;

    int racerNumber = -1;
    for (size_t i = 0; i < 3; ++i)
        if (racersData[0][i][1] == racerID) racerNumber = i;

    if (racerNumber < 0) {
        cout << "\nInvalid ID.\n";
        system("pause");
        return 1;
    }

    auto timeToMinutes = [](const string& timeStr) {
        vector<string> parts = split(timeStr, " ");
        return stod(parts[0]) * 60 + stod(parts[1]) + stod(parts[2]) / 60.0;
        };

    double t0 = timeToMinutes(racersData[0][racerNumber][2]);
    double t1 = timeToMinutes(racersData[1][racerNumber][2]);
    double t2 = timeToMinutes(racersData[2][racerNumber][2]);

    cout << "The racer's overall finish is " << racersData[2][racerNumber][2]
        << "\nRace split time (min/mile) for split 1: " << (t1 - t0) / 7.0
        << "\nRace split time (min/mile) for split 2: " << (t2 - t1) / 6.1
        << "\nOverall race time (minutes): " << (t2 - t0)
        << "\nOverall pace (min/mile): " << (t2 - t0) / 13.1 << endl;

    return 0;
}
