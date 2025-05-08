#include <iostream>
#include <cstring>
#include <cctype>
using namespace std;

const int MAX_DIGITS = 9;

int hexCharToInt(char c) {
    if (isdigit(c)) return c - '0';
    else if (c >= 'a' && c <= 'f') return 10 + (c - 'a');
    else return -1;  // invalid
}

char intToHexChar(int n) {
    if (n < 10) return '0' + n;
    else return 'a' + (n - 10);
}

void reverseArray(char arr[], int len) {
    for (int i = 0; i < len / 2; i++) {
        char temp = arr[i];
        arr[i] = arr[len - i - 1];
        arr[len - i - 1] = temp;
    }
}

void addHex(char hex1[], char hex2[]) {
    int len1 = strlen(hex1);
    int len2 = strlen(hex2);
    reverseArray(hex1, len1);
    reverseArray(hex2, len2);

    char result[MAX_DIGITS + 2] = {}; // +1 for possible carry, +1 for null terminator
    int carry = 0, i = 0;

    for (; i < MAX_DIGITS + 1; ++i) {
        int digit1 = (i < len1) ? hexCharToInt(hex1[i]) : 0;
        int digit2 = (i < len2) ? hexCharToInt(hex2[i]) : 0;
        int sum = digit1 + digit2 + carry;

        if (sum >= 16) {
            carry = 1;
            sum -= 16;
        }
        else {
            carry = 0;
        }

        result[i] = intToHexChar(sum);
    }

    if (carry) {
        cout << "Addition Over-flow" << endl;
        return;
    }

    // Remove leading zeros and reverse the result
    while (i > 1 && result[i - 1] == '0') --i;
    result[i] = '\0';
    reverseArray(result, i);
    cout << "Result: " << result << endl;
}

int main() {
    char hex1[MAX_DIGITS + 1], hex2[MAX_DIGITS + 1];
    char choice;

    do {
        cout << "Enter first hexadecimal number (up to 10 digits): ";
        cin >> hex1;
        cout << "Enter second hexadecimal number (up to 10 digits): ";
        cin >> hex2;

        // Validate input
        bool valid = true;
        for (int i = 0; hex1[i] && valid; ++i)
            if (!isdigit(hex1[i]) && (hex1[i] < 'a' || hex1[i] > 'f')) valid = false;
        for (int i = 0; hex2[i] && valid; ++i)
            if (!isdigit(hex2[i]) && (hex2[i] < 'a' || hex2[i] > 'f')) valid = false;

        if (!valid) {
            cout << "Invalid hexadecimal input. Use digits 0-9 and letters a-f." << endl;
        }
        else {
            addHex(hex1, hex2);
        }

        cout << "Do you want to add another pair? (y/n): ";
        cin >> choice;
    } while (choice == 'y' || choice == 'Y');

    return 0;
}
