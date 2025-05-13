#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

vector<string> split(const string& target, const string& delimiter) {
    vector<string> result;
    size_t start = 0, end = 0;
    while ((end = target.find(delimiter, start)) != string::npos) {
        result.push_back(target.substr(start, end - start));
        start = end + delimiter.length();
    }
    result.push_back(target.substr(start));
    return result;
}

vector<vector<vector<string>>> extractRacerData(const vector<string>& lines) {
    vector<vector<vector<string>>> data;
    size_t numLines = lines.size();

    for (size_t j = 0; j < 3; ++j) {
        data.emplace_back();
        for (size_t i = 0; i < 3; ++i) {
            size_t index = i + 3 * j;
            if (index < numLines) {
                data[j].push_back(split(lines[index], ","));
            }
            else {
                data[j].push_back(vector<string>());  // Avoid out-of-range access
            }
        }

        if (j > 0) {
            vector<string> temp;
            for (size_t k1 = 0; k1 < 3; ++k1) {
                for (size_t k2 = 0; k2 < 3; ++k2) {
                    if (data[j][k1].size() > 1 && data[j - 1][k2].size() > 1 &&
                        data[j][k1][1] == data[j - 1][k2][1]) {
                        temp = data[j][k1];
                        data[j][k1] = data[j][k2];
                        data[j][k2] = temp;
                    }
                }
            }
        }
    }
    return data;
}

void detectCheaters(const vector<vector<vector<string>>>& racersData) {
    cout << "\nSuspicious racers:\n";

    for (size_t i = 0; i < 3; ++i) {
        if (racersData[0].size() <= i || racersData[0][i].size() < 3) continue;

        string racerID = racersData[0][i][1];

        vector<string> startTime = split(racersData[0][i][2], " ");
        vector<string> secondTime, thirdTime;

        if (racersData[1].size() > i && racersData[1][i].size() >= 3)
            secondTime = split(racersData[1][i][2], " ");

        if (racersData[2].size() > i && racersData[2][i].size() >= 3)
            thirdTime = split(racersData[2][i][2], " ");

        if (startTime.size() < 3 || secondTime.size() < 3 || thirdTime.size() < 3) {
            cout << "Racer ID " << racerID << " is flagged for missing a checkpoint.\n";
            continue;
        }

        double startMin = stod(startTime[0]) * 60 + stod(startTime[1]) + stod(startTime[2]) / 60;
        double secondMin = stod(secondTime[0]) * 60 + stod(secondTime[1]) + stod(secondTime[2]) / 60;
        double thirdMin = stod(thirdTime[0]) * 60 + stod(thirdTime[1]) + stod(thirdTime[2]) / 60;

        double split1Pace = (secondMin - startMin) / 7;
        double split2Pace = (thirdMin - secondMin) / 6.1;
        double overallPace = (thirdMin - startMin) / 13.1;

        if (split1Pace < 4.5 || split2Pace < 4.5) {
            cout << "Racer ID " << racerID << " is flagged for suspiciously fast splits.\n";
        }
    }
}

int main() {
    fstream myData("racerdata.dat");
    if (!myData) {
        cout << "Error: \"racerdata.dat\" not found in the current directory.\n";
        return 1;
    }

    string fileContent, line;
    while (getline(myData, line)) {
        fileContent += line + "\n";
    }

    vector<string> dataLines = split(fileContent, "\n");

    if (dataLines.empty()) {
        cout << "Error: No data found in \"racerdata.dat\".\n";
        return 1;
    }

    vector<vector<vector<string>>> racersData = extractRacerData(dataLines);
    detectCheaters(racersData);

    return 0;
}
