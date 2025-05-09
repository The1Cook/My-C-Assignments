#include <iostream>
#include <string>
using namespace std;

int main() {
    string first, middle, last;

    cout << "Enter your full name: ";
    cin >> first;

    // Try to get next two parts
    string next;
    cin >> next;

    // Check if there's another part after "next"
    if (cin.peek() == ' ') {
        // There is a middle name/initial and a last name
        middle = next;
        cin >> last;
    }
    else {
        // Only a last name
        middle = "";
        last = next;
    }

    // Build the output
    cout << last << ", " << first;

    // Handle middle initial
    if (!middle.empty()) {
        cout << " " << middle[0] << ".";
    }

    cout << endl;

    return 0;
}
