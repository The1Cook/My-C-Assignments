/*
Write a program that converts from 24-hour notation to 12-hour notation.
For example, it should convert 14:25 to 2:25 PM.

The input is given as two integers. There should be at least three functions, one for input, one to do the
conversion, and one for output. Record the AM/PM information as a value of
type char, ‘A’ for AM and ‘P’ for PM. Thus, the function for doing the conversions will have a call-by-reference formal parameter of type char to record
whether it is AM or PM.

(The function will have other parameters as well.)

Include a loop that lets the user repeat this computation for new input values
again and again until the user says he or she wants to end the program.
*/

#include <iostream>
#include <string>
#include <string.h>
#include <iomanip>
void get_time(int& hour, int& minute) {
    using namespace std;
    char colon;
    cout << "What time was your call started? (use military time)" << endl;
    cin >> hour >> colon >> minute;
}
void conversion(int& hour, int& minute, char& AMPM) {
    if (hour > 11) {
        hour -= 12;
        AMPM = 'P';
    }
    else {
        AMPM = 'A';
    }
    
}
void output(int& hour, int& minute, char& AMPM) {
    using namespace std;
    if (hour == 0)
        hour = 12;
    if (minute <= 0) {
        cout << "The time converted is " << hour << ":" << minute << "0 " << AMPM << "M" << endl;
    }
    else {
        cout << "The time converted is " << hour << ":" << minute << " " << AMPM << "M" << endl;
    }
}
int main()
{
    using namespace std;
    int x = 1;
    while (x == 1) {
        int hour, minute;
        char AMPM;
        get_time(hour, minute);
        conversion(hour, minute, AMPM);
        output(hour, minute, AMPM);
        cout << "type 1 to do it again, 0 to stop" << endl;
        cin >> x;
    }

}

