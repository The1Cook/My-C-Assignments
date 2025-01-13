#include <iostream>
#include <string>
#include <map>
#include <sstream>

// Function prototypes
bool isLeapYear(int year);
int getCenturyValue(int year);
int getYearValue(int year);
int getMonthValue(int month, int year);
void getInput(int& day, int& month, int& year);
bool isValidDay(int day, int month, int year);
std::string getDayOfWeek(int dayOfWeek);

int main() {
    int day, month, year;

    // Get valid input for the date
    getInput(day, month, year);

    // Calculate the values for the formula
    int centuryValue = getCenturyValue(year);
    int yearValue = getYearValue(year);
    int monthValue = getMonthValue(month, year);

    // Calculate the sum
    int total = day + monthValue + yearValue + centuryValue;

    // Compute the remainder when divided by 7
    int dayOfWeek = total % 7;

    // Get the corresponding day of the week
    std::string dayName = getDayOfWeek(dayOfWeek);

    // Output the result
    std::cout << "The day of the week is: " << dayName << std::endl;

    return 0;
}

// Function to check if the year is a leap year
bool isLeapYear(int year) {
    return (year % 400 == 0) || (year % 4 == 0 && year % 100 != 0);
}

// Function to get the century value
int getCenturyValue(int year) {
    int century = year / 100;
    int remainder = century % 4;
    return (3 - remainder) * 2;
}

// Function to get the year value
int getYearValue(int year) {
    int lastTwoDigits = year % 100;
    int leapYearAdjustment = lastTwoDigits / 4;
    return lastTwoDigits + leapYearAdjustment;
}

// Function to get the month value
int getMonthValue(int month, int year) {
    std::map<int, int> monthValues = {
        {1, (isLeapYear(year) ? 6 : 0)}, // January
        {2, (isLeapYear(year) ? 2 : 3)}, // February
        {3, 3}, // March
        {4, 6}, // April
        {5, 1}, // May
        {6, 4}, // June
        {7, 6}, // July
        {8, 2}, // August
        {9, 5}, // September
        {10, 0}, // October
        {11, 3}, // November
        {12, 5} // December
    };
    return monthValues[month];
}

// Function to check if the day is valid for the given month and year
bool isValidDay(int day, int month, int year) {
    // Days in each month for regular years
    std::map<int, int> daysInMonth = {
        {1, 31}, {2, isLeapYear(year) ? 29 : 28}, {3, 31},
        {4, 30}, {5, 31}, {6, 30}, {7, 31},
        {8, 31}, {9, 30}, {10, 31}, {11, 30}, {12, 31}
    };

    // Check if the day is valid for the given month
    if (day < 1 || day > daysInMonth[month]) {
        return false;
    }
    return true;
}

// Function to get user input in day/month/year format
void getInput(int& day, int& month, int& year) {
    std::string input;
    bool validInput = false;

    // Loop until a valid date is entered
    while (!validInput) {
        std::cout << "Enter date (day/month/year): ";
        std::getline(std::cin, input);

        // Use stringstream to parse the input
        std::stringstream ss(input);

        // Parse day, month, and year
        char slash1, slash2;
        if (ss >> day >> slash1 >> month >> slash2 >> year) {
            // Ensure input is in the correct format (day/month/year)
            if (slash1 == '/' && slash2 == '/' && year >= 1000 && year <= 9999) {
                // Check if the day is valid for the given month and year
                if (isValidDay(day, month, year)) {
                    validInput = true;  // Valid date
                }
                else {
                    std::cout << "Invalid day for the given month/year. Please try again." << std::endl;
                }
            }
            else {
                std::cout << "Invalid input format. Please enter date as day/month/year." << std::endl;
            }
        }
        else {
            std::cout << "Invalid input. Please enter date as day/month/year." << std::endl;
        }
    }
}

// Function to return the day of the week as a string
std::string getDayOfWeek(int dayOfWeek) {
    std::map<int, std::string> daysOfWeek = {
        {0, "Sunday"}, {1, "Monday"}, {2, "Tuesday"}, {3, "Wednesday"},
        {4, "Thursday"}, {5, "Friday"}, {6, "Saturday"}
    };
    return daysOfWeek[dayOfWeek];
}
