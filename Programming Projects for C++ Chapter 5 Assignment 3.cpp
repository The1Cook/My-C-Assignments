// make the given program use 12 hour time instead of 24 hour time










/*
Write a program that requests the current time and a waiting time as two
integers for the number of hours and the number of minutes to wait. The
program then outputs what the time will be after the waiting period.

Use 24-hour notation for the times. Include a loop that lets the user repeat this
calculation for additional input values until the user says she or he wants
to end the program




*/


#include <iostream>
void get_times(int& hour, int& min, int& wait) {
    using namespace std;
    char colon;
    char AMPM;
    cout << "here with no spaces between time and AM/PM: " << endl;
    cin >> hour >> colon >> min >> AMPM >> colon;
    cout << "How long to wait?" << endl;
    cin >> wait;
    if (AMPM == 'P') {
        min += 720;
    }
}
void hAM_wait(int& h, int& m, int& wait) {

    m += (h * 60 + wait);
    while (m >= 1440) {
        m -= 1440;
    }
    
}
void output(int& m) {
    using namespace std;
    if (m >= 720) {
        if (m >= 9) {
            cout << "The time it ends at is " << ((m / 60) - 12) << ":" << m % 60 << " PM" << endl;
        }
        else {
            cout << "The time it ends at is " << ((m / 60) - 12) << ":0" << m % 60 << " PM" << endl;
        }
    }
    else {
        if (m >= 9) {
            cout << "The time it ends at is " << ((m / 60) - 12) << ":" << m % 60 << " AM" << endl;
        }
        else {
            cout << "The time it ends at is " << ((m / 60) - 12) << ":0" << m % 60 << " AM" << endl;
        }
    }
}
int main()
{
    using namespace std;
    int x = 1;
    int hour, min, wait;
    while (x == 1) {
        cout << "Give start time" << endl;
        get_times(hour, min, wait);
        hAM_wait(hour, min, wait);
        output(min);
        cout << "press 1 to do it again, 0 for exit." << endl;
        cin >> x;
    }
}


