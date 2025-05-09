#include <iostream>
#include <string>
#include <sstream>
#include <cctype>
using namespace std;

bool isValidTime(const string& timeStr, int& hours, int& minutes, string& meridiem) {
    size_t colonPos = timeStr.find(':');
    size_t spacePos = timeStr.find(' ');

    // Check basic format
    if (colonPos == string::npos || spacePos == string::npos || colonPos > spacePos) {
        return false;
    }

    try {
        hours = stoi(timeStr.substr(0, colonPos));
        minutes = stoi(timeStr.substr(colonPos + 1, spacePos - colonPos - 1));
        meridiem = timeStr.substr(spacePos + 1);

        // Normalize meridiem
        for (char& c : meridiem) c = toupper(c);
    }
    catch (...) {
        return false;
    }

    // Check valid ranges
    if (hours < 1 || hours > 12 || minutes < 0 || minutes > 59)
        return false;

    if (meridiem != "AM" && meridiem != "PM")
        return false;

    return true;
}

string militaryHours(const string& ordinaryTime) {
    int hours, minutes;
    string meridiem;

    if (!isValidTime(ordinaryTime, hours, minutes, meridiem)) {
        return "Invalid input format.";
    }

    // Convert hours
    if (meridiem == "AM") {
        if (hours == 12) hours = 0;
    }
    else { // PM
        if (hours != 12) hours += 12;
    }

    // Format result with leading zeros
    stringstream result;
    result << (hours < 10 ? "0" : "") << hours
        << (minutes < 10 ? "0" : "") << minutes
        << " hours";

    return result.str();
}

int main() {
    string input;

    while (true) {
        cout << "Enter time in format (e.g., '1:15 PM') or type 'exit' to quit:\n> ";
        getline(cin, input);

        if (input == "exit" || input == "EXIT")
            break;

        cout << "Military time: " << militaryHours(input) << "\n\n";
    }

    cout << "Program ended.\n";
    return 0;
}
