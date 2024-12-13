#include <iostream>
#include <sstream>

using namespace std;

bool isLeapYear(int year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

int getCenturyValue(int year) {
    int century = year / 100;
    int remainder = century % 4;
    return (3 - remainder) * 2;
}

int getYearValue(int year) {
    int lastTwoDigits = year % 100;
    int leapYears = lastTwoDigits / 4;
    return lastTwoDigits + leapYears;
}

int getMonthValue(int month, int year) {
    int monthValues[] = { 0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5 };

    if (month == 1 || month == 2) {
        return monthValues[month] - (isLeapYear(year) ? 1 : 0);
    }
    return monthValues[month];
}

void getInput(int& day, int& month, int& year) {
    char delimiter;
    cout << "Enter a date (e.g., 7/4/2008): ";
    cin >> month >> delimiter >> day >> delimiter >> year;
}

string getDayOfWeek(int day, int month, int year) {
    int total = day + getMonthValue(month, year) + getYearValue(year) + getCenturyValue(year);
    int dayOfWeek = total % 7;

    switch (dayOfWeek) { //basically a if else if else statement (default being else)
    case 0: return "Sunday";
    case 1: return "Monday";
    case 2: return "Tuesday";
    case 3: return "Wednesday";
    case 4: return "Thursday";
    case 5: return "Friday";
    case 6: return "Saturday";
    default: return "";
    }
}

int main() {
    int day, month, year;
    getInput(day, month, year);
    string dayOfWeek = getDayOfWeek(day, month, year);
    cout << "The day of the week for the date " << month << "/" << day << "/" << year << " is: " << dayOfWeek << endl;
    return 0;
}
